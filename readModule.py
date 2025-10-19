import os
import sys
import time
import board
import pandas as pd
from mpu6050 import mpu6050
import paho.mqtt.client as mqtt
import json

sensor = mpu6050(0x68)

HOST = 'localhost'

sensor_data = {"X": 0, "Y": 0, "Z": 0}

INTERVAL = 2

client = mqtt.Client()

next_reading = time.time()

client.connect(HOST, 1883, 60)

client.loop_start()


def read_sensor_data():
    accelerometer_data = sensor.get_accel_data()
    return accelerometer_data

try:
    while True:
        accel_data = sensor.get_accel_data()
        print("Accelerometer Data: ")
        print("X: " + str(accel_data['x']))
        print("Y: " + str(accel_data['y']))
        print("Z: " + str(accel_data['z']))  
        sensor_data["X"] = accel_data['x']
        sensor_data["Y"] = accel_data['y']
        sensor_data["Z"] = accel_data['z']

        df = pd.DataFrame([sensor_data])
        df.to_csv('output.csv', mode='a', header=not os.path.exists('output.csv'), index=False)
 
        client.publish("readAcc/Gait Accelerometer Values", json.dumps(sensor_data), 1)
        next_reading += INTERVAL
        sleep_time = next_reading-time.time()
        if sleep_time > 0:
            time.sleep(sleep_time)
except KeyboardInterrupt:
    pass

client.loop_stop()
client.disconnect()
