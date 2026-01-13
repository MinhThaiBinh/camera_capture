import paho.mqtt.client as mqtt
import time

client = mqtt.Client()
client.username_pw_set("congminh_broker", "congminh_broker")
try:
    client.connect("192.168.7.103", 1884)
    print("Connected to broker")
    client.publish("/camera/trigger", "Test message from script", qos=1, retain=True)
    client.loop()
    print("Published test message")
    time.sleep(1)
    client.disconnect()
    print("Disconnected")
except Exception as e:
    print(f"Error: {e}")
