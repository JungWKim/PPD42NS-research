import serial
import RPi.GPIO as gpio
import time

gpio.setwarnings(False)
gpio.setmode(gpio.BCM)

print("measuring start")

ser = serial.Serial("/dev/ttyACM0", 9600)

while True:
	line = ser.readline().decode('utf-8')
	print(line)
