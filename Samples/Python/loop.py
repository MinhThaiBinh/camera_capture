import numpy as np
import cv2
from ctypes import *
#call API to query image
dll=cdll.LoadLibrary("libJHCap.so")
dll.CameraInit(0)
dll.CameraSetResolution(0, 0, 0, 0)
dll.CameraSetContrast.argtypes = [ c_int, c_double ]
dll.CameraSetContrast(0, 1.15)
buflen = c_int()
width = c_int()
height = c_int()
dll.CameraGetImageSize(0, byref(width), byref(height))
dll.CameraGetImageBufferSize(0, byref(buflen), 0x4)
inbuf = create_string_buffer(buflen.value)
cv2.namedWindow("Camera Stream", cv2.WINDOW_NORMAL) # Mở cửa sổ hiển thị
print("Đang hiển thị stream... Nhấn ESC tại cửa sổ ảnh để thoát.")

while 1:
    ret = dll.CameraQueryImage(0, inbuf, byref(buflen), 0x104)
    if ret == 0:
        arr = np.frombuffer(inbuf, np.uint8)
        img = np.reshape(arr, (height.value, width.value, 3))
        cv2.imshow("Camera Stream", img) # Hiển thị ảnh lên màn hình
    
    key = cv2.waitKey(1) # Đợi 1ms để cập nhật khung hình
    if (key & 0xff) == 27: # Nhấn ESC để thoát
        break

cv2.destroyAllWindows()
