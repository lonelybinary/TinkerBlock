"""
TK57-LINE TRACKER - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK57-LINE TRACKER module to control LED
- LED on when black line detected, LED off when white line detected

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
3. Place sensor on black or white line and observe LED state
"""

# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
TRACKER_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1        # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)

# Create pin objects
tracker = Pin(TRACKER_PIN, Pin.IN)  # Set line tracker pin as input (to read detection state)
led = Pin(LED_PIN, Pin.OUT)         # Set LED pin as output (to control LED on/off)

print("Line tracker program started")
print("LED on when black line detected, LED off when white line detected")

# Main loop: runs forever
while True:
    # Read line tracker state
    trackerState = tracker.value()   # Read sensor pin level: 1=black line detected (HIGH), 0=white line detected (LOW)
    
    # Control LED based on detection state
    if trackerState == 1:
        # Black line detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Black line detected - LED on")
    else:
        # White line detected: turn LED off
        led.off()                # Output LOW, LED off
        print("White line detected - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
