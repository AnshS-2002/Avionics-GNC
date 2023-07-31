import RPi.GPIO as GPIO
from time import sleep

#GPIO mode setup
GPIO.setmode(GPIO.BOARD)
motor_pin=18
initial_duty_cycle=0

#GPIO and PWM setup 
GPIO.setup(motor_pin,GPIO.OUT)
pwm_motor=GPIO.PWM(motor_pin,1000)
pwm_motor.start(initial_duty_cycle)

try:
    while(1):
        DC=input("enter duty cycle(0-100): ")
        if(DC>100):
            DC=100
        pwm_motor.ChangeDutyCycle(DC)
except KeyboardInterrupt:
    print("motor control stopped")
    pwm_motor.stop()
    GPIO.cleanup()
