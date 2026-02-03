"""
TK15-IR RECEIVER - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK15-IR RECEIVER module.

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
IR_PIN = 0     # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 25   # Pico built-in LED pin (GPIO 25, or external LED)

# Create pin objects
ir = Pin(IR_PIN, Pin.IN)    # Set IR pin as input (to read IR signal)
led = Pin(LED_PIN, Pin.OUT)  # Set LED pin as output (to control LED on/off)

# Main loop: runs forever
while True:
    # Read IR receiver state
    irState = ir.value()   # Read IR pin level: 0 = signal received (LOW), 1 = no signal (HIGH)
    
    # Control LED based on IR state
    if irState == 0:
        # IR signal received: turn LED on and print message
        led.on()                     # Output HIGH, LED on
        print("IR signal received!")    # Display message in terminal
    else:
        # No signal received: turn LED off
        led.off()                    # Output LOW, LED off
    
    # Delay 10 milliseconds to avoid reading too fast
    time.sleep_ms(10)
