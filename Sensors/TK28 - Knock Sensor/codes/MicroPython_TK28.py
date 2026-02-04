"""
TK28-TAP SENSOR - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK28-TAP SENSOR module to control LED
- LED on when tap detected, LED off when no tap detected

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
3. Tap the sensor and observe LED state
"""

# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
TAP_PIN = 0     # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1     # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)

# Create pin objects
tap = Pin(TAP_PIN, Pin.IN)   # Set tap sensor pin as input (to read detection state)
led = Pin(LED_PIN, Pin.OUT)  # Set LED pin as output (to control LED on/off)

print("Tap sensor program started")
print("LED on when tap detected, LED off when no tap")

# Main loop: runs forever
while True:
    # Read tap sensor state
    tapState = tap.value()   # Read sensor pin level: 1 = tap (HIGH), 0 = no tap (LOW)
    
    # Control LED based on detection state
    if tapState == 1:
        # Tap detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Tap detected - LED on")
    else:
        # No tap detected: turn LED off
        led.off()                # Output LOW, LED off
        print("No tap detected - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
