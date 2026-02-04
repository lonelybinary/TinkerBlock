"""
TK05-LOCK BUTTON - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK05-LOCK BUTTON module.

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
BUTTON_PIN = 2   # GPIO connected to SIGNAL (e.g. GPIO 2)
LED_PIN = 25     # Pico built-in LED pin (GPIO 25, or external LED)

# Create pin objects
button = Pin(BUTTON_PIN, Pin.IN)   # Set button pin as input (to read button state)
led = Pin(LED_PIN, Pin.OUT)        # Set LED pin as output (to control LED on/off)

# Variables
last_button_state = button.value()  # Last button state
led_state = False                  # LED current state (False = off, True = on)

print("Lock button switch program started")
print("Press button to lock, LED stays on; press again to unlock, LED off")

# Main loop: runs forever
while True:
    # Read button state
    current_button_state = button.value()  # Read button pin level: 1 = locked (HIGH), 0 = unlocked (LOW)
    
    # Detect button state change (detect rising or falling edge)
    if current_button_state != last_button_state:
        # Button state changed
        if current_button_state == 1:
            # Button locked: toggle LED state
            led_state = not led_state  # Toggle LED state
            
            if led_state:
                led.on()                 # Output HIGH, LED on
                print("Button locked - LED on")
            else:
                led.off()                # Output LOW, LED off
                print("Button unlocked - LED off")
        
        # Update last state
        last_button_state = current_button_state
        time.sleep(0.2)  # Debounce delay
    
    time.sleep(0.05)  # Brief delay to avoid reading too fast
