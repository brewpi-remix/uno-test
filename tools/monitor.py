#!/usr/bin/env python3

import serial
import sys


COM = '/dev/ttyACM0'
BAUD = 9600

ser = serial.Serial(COM, BAUD, timeout=.1)

print('Waiting for device')
print(ser.name)

# check args
if("-m" in sys.argv or "--monitor" in sys.argv):
    monitor = True
else:
    monitor = False

while True:
    # Capture serial output as a decoded string
    val = str(ser.readline().decode(encoding="cp437").strip('\r\n'))
    # print()
    if(monitor == True):
        print(val, end="\r", flush=True)
