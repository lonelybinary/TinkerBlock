"""
TK01-XL LED - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK01-XL LED module.

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
LED_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)

# Create pin object
led = Pin(LED_PIN, Pin.OUT)  # Set pin as output (to control LED on/off)

# Main loop: runs forever
while True:
    # Blink: turn LED on
    led.on()                 # Output HIGH, LED on
    print("LED on")          # Print to terminal
    time.sleep(1)            # Wait 1 second

    led.off()                # Output LOW, LED off
    print("LED off")         # Print to terminal
    time.sleep(1)             # Wait 1 second
