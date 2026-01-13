import numpy as np
import cv2
from ctypes import *
#call API to query image
dll=cdll.LoadLibrary("libJHCap.so")
ret = dll.CameraInit(0)
print(f"CameraInit ret: {ret}")
if ret != 0:
    print("Failed to initialize camera. Is it connected?")
    exit(1)

dll.CameraSetResolution(0, 0, 0, 0)
dll.CameraSetContrast.argtypes = [ c_int, c_double ]
dll.CameraSetContrast(0, 1.15)
dll.CameraSetSnapMode(0, 2);
buflen = c_int()
width = c_int()
height = c_int()
dll.CameraGetImageSize(0, byref(width), byref(height))
print(f"Image size: {width.value}x{height.value}")
dll.CameraGetImageBufferSize(0, byref(buflen), 0x4)
print(f"Buffer length: {buflen.value}")
inbuf = create_string_buffer(buflen.value)
# cv2.namedWindow("s")
print("press ESC to exit, other key to shot one image.")
while 1:
	ret = dll.CameraTriggerShot(0);
	print(f"CameraTriggerShot ret: {ret}")
	ret = dll.CameraQueryImage(0, inbuf, byref(buflen), 0x104)
	print(f"CameraQueryImage ret: {ret}")
	if ret != 0:
		print(f"Failed to query image. Error code: {ret}")
		break
	arr= np.frombuffer(inbuf, np.uint8)
	print(f"Array size: {arr.size}")
	if arr.size == 0:
		print("Empty array from buffer.")
		break
	img=np.reshape(arr, (height.value, width.value, 3))
	# cv2.imshow("s", img)
	cv2.imwrite("shot.bmp", img)
	print("Image saved to shot.bmp. Exiting...")
	break
	key=cv2.waitKey(33000) #change parameter according to frame rate, wait time = 1000/fps
	if (key&0xff) == 27: #press ESC on image window to terminate the loop
		break
# cv2.destroyWindow("s")
