"""
TK02-RGB LED - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK02-RGB LED module.

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
"""

# Import required modules
from machine import Pin, PWM  # GPIO control and PWM
import time                   # For delay (time.sleep)

# Pin number: change these to match your wiring
RED_PIN = 1    # GPIO connected to RED (e.g. GPIO 1, must be PWM-capable pin)
GREEN_PIN = 2  # GPIO connected to GREEN (e.g. GPIO 2)
BLUE_PIN = 3   # GPIO connected to BLUE (e.g. GPIO 3)

# Create PWM objects
red = PWM(Pin(RED_PIN))
green = PWM(Pin(GREEN_PIN))
blue = PWM(Pin(BLUE_PIN))

# Set PWM frequency (1000 Hz)
red.freq(1000)
green.freq(1000)
blue.freq(1000)

# Main loop: runs forever
while True:
    # Red
    red.duty_u16(65535)    # Red at maximum brightness (65535 is max value)
    green.duty_u16(0)       # Green off
    blue.duty_u16(0)        # Blue off
    print("Red")
    time.sleep(1)
    
    # Green
    red.duty_u16(0)
    green.duty_u16(65535)
    blue.duty_u16(0)
    print("Green")
    time.sleep(1)
    
    # Blue
    red.duty_u16(0)
    green.duty_u16(0)
    blue.duty_u16(65535)
    print("Blue")
    time.sleep(1)
    
    # White (all colors at maximum brightness)
    red.duty_u16(65535)
    green.duty_u16(65535)
    blue.duty_u16(65535)
    print("White")
    time.sleep(1)
