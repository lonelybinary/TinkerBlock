"""
TK41-MAGNETIC SWITCH - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK41-MAGNETIC SWITCH module to control LED
- LED on when magnetic field detected, LED off when no magnetic field detected

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
3. Bring magnet close to sensor and observe LED state
"""

# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
REED_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1     # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)

# Create pin objects
reed = Pin(REED_PIN, Pin.IN)   # Set magnetic switch pin as input (to read detection state)
led = Pin(LED_PIN, Pin.OUT)    # Set LED pin as output (to control LED on/off)

print("Magnetic switch program started")
print("LED on when magnetic field detected, LED off when no magnetic field")

# Main loop: runs forever
while True:
    # Read magnetic switch state
    reedState = reed.value()   # Read switch pin level: 1 = magnetic field detected (HIGH), 0 = no magnetic field (LOW)
    
    # Control LED based on detection state
    if reedState == 1:
        # Magnetic field detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Magnetic field detected - LED on")
    else:
        # No magnetic field detected: turn LED off
        led.off()                # Output LOW, LED off
        print("No magnetic field detected - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
