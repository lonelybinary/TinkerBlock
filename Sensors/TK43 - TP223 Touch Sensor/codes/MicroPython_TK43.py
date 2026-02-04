"""
TK43-TP223 TOUCH SENSOR - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK43-TP223 TOUCH SENSOR module to control LED
- LED on when touch sensor is touched, LED off when not touched

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
3. Touch the sensor and observe LED state
"""

# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
TOUCH_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1      # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)

# Create pin objects
touch = Pin(TOUCH_PIN, Pin.IN)   # Set touch sensor pin as input (to read detection state)
led = Pin(LED_PIN, Pin.OUT)      # Set LED pin as output (to control LED on/off)

print("Touch sensor program started")
print("LED on when touch sensor is touched, LED off when not touched")

# Main loop: runs forever
while True:
    # Read touch sensor state
    touchState = touch.value()   # Read sensor pin level: 1=touched (HIGH), 0=not touched (LOW)
    
    # Control LED based on detection state
    if touchState == 1:
        # Touch sensor touched: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Touch sensor - LED on")
    else:
        # Not touched: turn LED off
        led.off()                # Output LOW, LED off
        print("Not touched - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
