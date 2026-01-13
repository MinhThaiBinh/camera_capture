import time

import numpy as np
import cv2
from ctypes import *


class ISPParam(Structure):
    _fields_ = [
		("ccm0", c_double),
		("ccm1", c_double),
		("ccm2", c_double),
		("ccm3", c_double),
		("ccm4", c_double),
		("ccm5", c_double),
		("ccm6", c_double),
		("ccm7", c_double),
		("ccm8", c_double),
        ("gamma", c_double),
		("saturation", c_double),
        ("contrast", c_double),
        ("red_gain", c_double),
        ("green_gain", c_double),
        ("blue_gain", c_double),
		("black", c_int),
		("rotate", c_bool),
        ("mirror_x", c_bool),
        ("mirror_y", c_bool),
        ("enhancement", c_bool),
		("fpn", c_bool),
		("denoise", c_bool),
    ]


def printErrorCode():
    errorCode = c_int()
    dll.CameraGetLastError(byref(errorCode))
    print(errorCode)


param = ISPParam(gamma=1.9, contrast=1.0, saturation=1.0, black=14, red_gain=1.43, green_gain=1.0, blue_gain=1.5, rotate=False,
mirror_x=True, mirror_y=False, enhancement=False, fpn=False, denoise=False)

# call API to query image
dll=cdll.LoadLibrary("libJHCap.so")
print("load")
print(param)
dll.CameraInitVirtual(5, 0x3650, pointer(param))
virtualBufferSize = c_int()
width = c_int(2448)
height = c_int(2048)
dll.CameraGetISPImageBufferSize(5, byref(virtualBufferSize), width, height, 0x104)
virtualBuffer = create_string_buffer(virtualBufferSize.value)
print(virtualBufferSize.value)
data = np.load('test.npz')
bs = data['arr'].tobytes()
rawBuffer = create_string_buffer(bs, len(bs))

rawArray = np.frombuffer(rawBuffer, np.uint8)
rawImage = np.reshape(rawArray, (height.value, width.value, 1))
rawImage.tofile('test.raw')

ret = dll.CameraISP(5, byref(rawBuffer), byref(virtualBuffer), width, height, 0x104)
print(ret)
virtualArray = np.frombuffer(virtualBuffer, np.uint8)
virtualImage = np.reshape(virtualArray, (height.value, width.value, 3))

cv2.imwrite('test2.jpg', virtualImage)
