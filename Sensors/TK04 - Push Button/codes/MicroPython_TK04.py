"""
TK04-PUSH BUTTON - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK04-PUSH BUTTON module.

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
BUTTON_PIN = 0   # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 25     # Pico built-in LED pin (GPIO 25, or external LED)

# Create pin objects
button = Pin(BUTTON_PIN, Pin.IN)   # Set button pin as input (to read button state)
led = Pin(LED_PIN, Pin.OUT)        # Set LED pin as output (to control LED on/off)

print("Push button module program started")

# Main loop: runs forever
while True:
    # Read button state
    button_state = button.value()  # Read button pin level: 1 = pressed (HIGH), 0 = released (LOW)
    
    # Control LED based on button state
    if button_state == 1:
        # Button pressed: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Button pressed!")        # Display message in terminal
    else:
        # Button released: turn LED off
        led.off()                # Output LOW, LED off
    
    time.sleep(0.05)  # Brief delay to avoid reading too fast
