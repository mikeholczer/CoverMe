import RPi.GPIO as GPIO
import time
import os
import random
 
GPIO.setmode(GPIO.BCM)
 
enable_pin = 18
coil_A_1_pin = 4
coil_A_2_pin = 17
coil_B_1_pin = 23
coil_B_2_pin = 24

red = 25
green = 22
 
GPIO.setup(enable_pin, GPIO.OUT)
GPIO.setup(coil_A_1_pin, GPIO.OUT)
GPIO.setup(coil_A_2_pin, GPIO.OUT)
GPIO.setup(coil_B_1_pin, GPIO.OUT)
GPIO.setup(coil_B_2_pin, GPIO.OUT)
GPIO.setup(red, GPIO.OUT)
GPIO.setup(green, GPIO.OUT)
 
GPIO.output(enable_pin, 1)
 
def forward(delay, steps):
  GPIO.output(green, 1)  
  for i in range(0, steps):
    setStep(1, 0, 1, 0)
    time.sleep(delay)
    setStep(0, 1, 1, 0)
    time.sleep(delay)
    setStep(0, 1, 0, 1)
    time.sleep(delay)
    setStep(1, 0, 0, 1)
    time.sleep(delay)
  GPIO.output(green, 0)
 
def backwards(delay, steps):  
  GPIO.output(green, 1)
  for i in range(0, steps):
    setStep(1, 0, 0, 1)
    time.sleep(delay)
    setStep(0, 1, 0, 1)
    time.sleep(delay)
    setStep(0, 1, 1, 0)
    time.sleep(delay)
    setStep(1, 0, 1, 0)
    time.sleep(delay)
  GPIO.output(green, 0)
 
  
def setStep(w1, w2, w3, w4):
  GPIO.output(coil_A_1_pin, w1)
  GPIO.output(coil_A_2_pin, w2)
  GPIO.output(coil_B_1_pin, w3)
  GPIO.output(coil_B_2_pin, w4)
 

def RCtime (RCpin):
        reading = 0
        GPIO.setup(RCpin, GPIO.OUT)
        GPIO.output(RCpin, GPIO.LOW)
        time.sleep(0.1)

        GPIO.setup(RCpin, GPIO.IN)
        # This takes about 1 millisecond per loop cycle
        while (GPIO.input(RCpin) == GPIO.LOW):
                reading += 1
        return reading

while True:
        if RCtime(18) > 500:
			GPIO.output(red, 0)
			if random.randrange(1,10) < 2:
				forward(10 / 1000.0, 10)
			else:
				backwards(10 / 1000.0, 10)
        else:
                GPIO.output(red, 1)





#delay = raw_input("Delay between steps (milliseconds)?")
#steps = raw_input("How many steps forward? ")
#forward(int(delay) / 1000.0, int(steps))
#steps = raw_input("How many steps backwards? ")
#backwards(int(delay) / 1000.0, int(steps))
#GPIO.cleanup()
