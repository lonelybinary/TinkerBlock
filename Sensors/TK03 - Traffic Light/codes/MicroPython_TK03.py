"""
TK03-TRAFFIC LIGHT - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK03-TRAFFIC LIGHT module.

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
"""

# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
RED_PIN = 0     # GPIO connected to RED (e.g. GPIO 0)
YELLOW_PIN = 1  # GPIO connected to YELLOW (e.g. GPIO 1)
GREEN_PIN = 2   # GPIO connected to GREEN (e.g. GPIO 2)

# Create pin objects
red = Pin(RED_PIN, Pin.OUT)      # Set RED pin as output (to control LED on/off)
yellow = Pin(YELLOW_PIN, Pin.OUT)  # Set YELLOW pin as output
green = Pin(GREEN_PIN, Pin.OUT)    # Set GREEN pin as output

# Initialize: all LEDs off
red.off()
yellow.off()
green.off()

print("Traffic light program started")

# Main loop: runs forever
while True:
    # Red light on (5 seconds)
    red.on()
    yellow.off()
    green.off()
    print("Red light on - Stop")
    time.sleep(5)
    
    # Green light on (5 seconds)
    red.off()
    yellow.off()
    green.on()
    print("Green light on - Go")
    time.sleep(5)
    
    # Yellow light on (2 seconds)
    red.off()
    yellow.on()
    green.off()
    print("Yellow light on - Warning")
    time.sleep(2)
    
    # Loop back to red light
