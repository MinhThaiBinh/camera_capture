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
JPEG_QUALITY = 75 

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
client.connect(MQTT_BROKER, MQTT_PORT)
client.loop_start()



try:
    print("\n--- HỆ THỐNG SẴN SÀNG (Nhấn ENTER để chụp) ---")
    while True:
        input("\n[Ready] ")
        start_process = time.time()
        
        # TỐI ƯU 1: Xóa sạch buffer cũ trước khi trigger ảnh mới
        # Điều này cực kỳ quan trọng trên Pi 4 để tránh lỗi ret != 0
        dll.CameraQueryImage(0, inbuf, byref(buflen), 0x104)

        success = False
        for attempt in range(1, 5): # Tăng lên 4 lần thử
            # TỐI ƯU 2: Kích hoạt Trigger
            dll.CameraTriggerShot(0)
            
            # TỐI ƯU 3: Đợi cảm biến quét xong (Exposure time + Transfer time)
            # Với 5MP, thời gian này không nên dưới 200ms
            time.sleep(0.3) 
            
            ret = dll.CameraQueryImage(0, inbuf, byref(buflen), 0x104)
            if ret == 0:
                success = True
                break
            else:
                print(f"Thử lại {attempt}/4... (Mã lỗi: {ret})")
                time.sleep(0.2) # Nghỉ thêm nếu lỗi

        if not success:
            print("Lỗi: Không lấy được ảnh từ Camera. Đang thử Reset phần mềm...")
            # Thay vì sys.exit, hãy thử Init lại nhẹ nhàng
            dll.CameraInit(0)
            continue

        # TỐI ƯU 4: Xử lý mảng và nén
        arr = np.frombuffer(inbuf, np.uint8)
        img = np.reshape(arr, (height.value, width.value, 3))

        # Nén trực tiếp trên RAM
        result, encimg = cv2.imencode(".jpg", img, [int(cv2.IMWRITE_JPEG_QUALITY), JPEG_QUALITY])

        if result:
            img_b64 = base64.b64encode(encimg).decode('utf-8')
            
            # TỐI ƯU 5: Gửi MQTT không đồng bộ nhưng có kiểm soát
            publish_info = client.publish(MQTT_TOPIC, img_b64, qos=1)
            # Không cần wait_for_publish() nếu bạn không cần tốc độ cực cao, 
            # nhưng trên Pi 4 nên để để đảm bảo không nghẽn mạng
            publish_info.wait_for_publish(timeout=2.0)
            
            print(f"==> OK! {len(img_b64)/1024:.1f} KB | Time: {time.time() - start_process:.2f}s")

except KeyboardInterrupt:
    print("\nĐang dừng...")
finally:
    client.loop_stop()
    client.disconnect()