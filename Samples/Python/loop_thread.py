import numpy as np
import cv2
import threading
from threading import Timer
from ctypes import *
#call API to query image
dll=cdll.LoadLibrary("libJHCap.so")
dll.CameraInit(0)
dll.CameraSetResolution(0, 0, 0, 0)
dll.CameraSetContrast.argtypes = [ c_int, c_double ]
dll.CameraSetContrast(0, 1.15)
dll.CameraSetFrameRate.argtypes = [ c_int, c_bool, c_double ]
dll.CameraSetFrameRate(0, True, 10.0)
buflen = c_int()
width = c_int()
height = c_int()
dll.CameraGetImageSize(0, byref(width), byref(height))
dll.CameraGetImageBufferSize(0, byref(buflen), 0x4)
inbuf = create_string_buffer(buflen.value)
# cv2.namedWindow("s")

count = 0
term = 0
def printFps():
	global t, count, term
	print(f"FPS count: {count}")
	count = 0
	if term==0:
		t=Timer(1,printFps)
		t.start()

def capFunc(threadName, delay):
	global count,term
	print(f"Thread {threadName} started")
	while term == 0:
		ret = dll.CameraQueryImage(0, inbuf, byref(buflen), 0x104)
		if ret == 0:
			arr= np.frombuffer(inbuf, np.uint8)
			img=np.reshape(arr, (height.value, width.value, 3))
			# cv2.imshow("s", img)
			if count == 0:
				cv2.imwrite(f"thread_test_{threadName}.bmp", img)
				print(f"Saved thread_test_{threadName}.bmp")
			count=count+1

		# key=cv2.waitKey(2) #change parameter according to frame rate, wait time = 1000/fps
		# if (key&0xff) == 27: #press ESC on image window to terminate the loop
		# 	term = 1			
		# 	break
	

try:
	t1 = threading.Thread(target=capFunc, args=("Cap0", 2))
	t1.start()
	# thread.start_new_thread(capFunc, ("Cap1", 4))
	# thread.start_new_thread(capFunc, ("Cap2", 6))
except:
	print("thread start error")

t = Timer(1, printFps)
t.start()

import time
time.sleep(3)
term = 1
print("Stopping threads...")
# cv2.destroyWindow("s")


