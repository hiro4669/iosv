import serial
import time

ser = serial.Serial('/dev/cu.usbmodem142101', 9600, timeout = 1)


while True:
    data: bytes = ser.read();
    if len(data) > 0:
        break

int_data = int.from_bytes(data, 'big')
print(data)
print("data1 = {}".format(int_data)) # Dを読む

time.sleep(0.5)

ser.write(bytes([65])) # aを書く
time.sleep(0.5)
data: bytes = ser.read() # bを読む

int_data = int.from_bytes(data, 'big')
print(data)
print(len(data))
print("data2 = {}".format(int_data))
time.sleep(0.5)
data: bytes = ser.read() # Eを読む
print(data)
time.sleep(0.5)
ser.write(bytes([67])) # cを書く
time.sleep(0.5)
data: bytes = ser.read() # d
print(data)

#ser.close()
