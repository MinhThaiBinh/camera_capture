import numpy as np
import time
import cv2
from ctypes import *
#call API to query image
dll=cdll.LoadLibrary("libJHCap.so")
dll.CameraInit(0)
dll.CameraSetResolution(0, 0, 0, 0)
dll.CameraSetContrast.argtypes = [ c_int, c_double ]
dll.CameraSetContrast(0, 1.15)
dll.CameraSetExposure(0, 3000)
dll.CameraSetTimeout(0, 3000)
dll.CameraSetSnapMode(0, 0x01)
buflen = c_int()
width = c_int()
height = c_int()
dll.CameraGetImageSize(0, byref(width), byref(height))
dll.CameraGetImageBufferSize(0, byref(buflen), 0x4)
inbuf = create_string_buffer(buflen.value)
# cv2.namedWindow("s")
print("Capturing one frame and saving to clearshot_test.bmp...")
while 1:
	dll.CameraClearHostBuffer(0)
	ret = dll.CameraQueryImage(0, inbuf, byref(buflen), 0x104)
	print(f"CameraQueryImage ret: {ret}")
	if ret != 0:
		continue
	arr= np.frombuffer(inbuf, np.uint8)
	img=np.reshape(arr, (height.value, width.value, 3))
	# cv2.imshow("s", img)
	cv2.imwrite("clearshot_test.bmp", img)
	print("Saved clearshot_test.bmp. Exiting.")
	break
	key=cv2.waitKey(333300) #change parameter according to frame rate, wait time = 1000/fps
	if (key&0xff) == 27: #press ESC on image window to terminate the loop
		break
# cv2.destroyWindow("s")
