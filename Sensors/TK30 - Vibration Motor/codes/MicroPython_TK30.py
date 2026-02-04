"""
TK30-VIBRATION MOTOR - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK30-VIBRATION MOTOR module.

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
"""

# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change this to match your wiring
MOTOR_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)

# Create pin object
motor = Pin(MOTOR_PIN, Pin.OUT)  # Set motor pin as output (to control motor vibration)

print("Vibration motor program started")

# Main loop: runs forever
while True:
    # Vibrate for 0.5 seconds
    motor.on()                 # Output HIGH to start vibration
    print("Motor vibrating...")
    time.sleep(0.5)            # Wait 0.5 seconds
    
    # Stop for 0.5 seconds
    motor.off()                # Output LOW to stop vibration
    print("Motor stopped")
    time.sleep(0.5)            # Wait 0.5 seconds
