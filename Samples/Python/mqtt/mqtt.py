import numpy as np
import time
import cv2
from ctypes import *
import paho.mqtt.client as mqtt
import base64
import sys

# --- Cấu hình ---
MQTT_BROKER = "192.168.1.134"
MQTT_PORT = 1884
MQTT_TOPIC = "/camera/trigger"
TRIGGER_TOPIC = "topic/sensor/counter"
JPEG_QUALITY = 75 

# Biến cờ trigger
is_triggered = False

def on_connect(client, userdata, flags, rc):
    print(f"MQTT Connected (code {rc})")
    client.subscribe(TRIGGER_TOPIC)

def on_message(client, userdata, msg):
    global is_triggered
    if msg.topic == TRIGGER_TOPIC:
        print(f"--> Trigger message received: {msg.topic}")
        is_triggered = True

# --- Khởi tạo Camera ---
try:
    dll = cdll.LoadLibrary("libJHCap.so")
    dll.CameraReset(0)
    time.sleep(0.5) # Đợi phần cứng reset
    
    if dll.CameraInit(0) != 0:
        print("Lỗi kết nối Camera!")
        sys.exit(1)

    dll.CameraSetResolution(0, 0, 0, 0)
    dll.CameraSetContrast.argtypes = [c_int, c_double]
    dll.CameraSetContrast(0, 1.15)
    dll.CameraSetSnapMode(0, 2)
    # NSX khuyên dùng delay để ổn định điện áp cảm biến khi trigger
    dll.CameraSetDelay(0, 200) 

    buflen = c_int()
    width = c_int()
    height = c_int()
    dll.CameraGetImageSize(0, byref(width), byref(height))
    dll.CameraGetImageBufferSize(0, byref(buflen), 0x4)
    inbuf = create_string_buffer(buflen.value)
    print(f"Camera Ready: {width.value}x{height.value}")
except Exception as e:
    print(f"Lỗi khởi tạo: {e}"); sys.exit(1)

# --- MQTT ---
client = mqtt.Client()
client.username_pw_set("congminh_broker", "congminh_broker")
client.on_connect = on_connect
client.on_message = on_message
client.connect(MQTT_BROKER, MQTT_PORT)
client.loop_start()

try:
    print(f"\n--- HỆ THỐNG SẴN SÀNG (Đợi trigger từ {TRIGGER_TOPIC}) ---")
    while True:
        if not is_triggered:
            time.sleep(0.01)
            continue
            
        is_triggered = False
        start_process = time.time()
        
        # TỐI ƯU 1: Xóa sạch buffer cũ trước khi trigger ảnh mới
        dll.CameraQueryImage(0, inbuf, byref(buflen), 0x104)

        success = False
        for attempt in range(1, 5): 
            dll.CameraTriggerShot(0)
            time.sleep(0.3) 
            
            ret = dll.CameraQueryImage(0, inbuf, byref(buflen), 0x104)
            if ret == 0:
                success = True
                break
            else:
                print(f"Thử lại {attempt}/4... (Mã lỗi: {ret})")
                time.sleep(0.2) 

        if not success:
            print("Lỗi: Không lấy được ảnh từ Camera. Đang thử Reset phần mềm...")
            dll.CameraInit(0)
            continue

        # TỐI ƯU 4: Xử lý mảng và nén
        arr = np.frombuffer(inbuf, np.uint8)
        img = np.reshape(arr, (height.value, width.value, 3))

        # Nén trực tiếp trên RAM
        result, encimg = cv2.imencode(".jpg", img, [int(cv2.IMWRITE_JPEG_QUALITY), JPEG_QUALITY])

        if result:
            img_b64 = base64.b64encode(encimg).decode('utf-8')
            publish_info = client.publish(MQTT_TOPIC, img_b64, qos=1)
            publish_info.wait_for_publish(timeout=2.0)
            print(f"==> OK! {len(img_b64)/1024:.1f} KB | Time: {time.time() - start_process:.2f}s")

except KeyboardInterrupt:
    print("\nĐang dừng...")
finally:
    client.loop_stop()
    client.disconnect()
