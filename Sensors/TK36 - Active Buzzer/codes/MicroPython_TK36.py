"""
TK36-ACTIVE BUZZER - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK36-ACTIVE BUZZER module.

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
BUZZER_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)

# Create Pin object, set as output mode
buzzer = Pin(BUZZER_PIN, Pin.OUT)

print("Active buzzer program started")

# Main loop: runs forever
while True:
    # Buzzer on for 0.5 seconds
    buzzer.on()  # Turn on buzzer
    print("Buzzer on")
    time.sleep(0.5)  # Wait 0.5 seconds
    
    # Buzzer off for 0.5 seconds
    buzzer.off()  # Turn off buzzer
    print("Buzzer off")
    time.sleep(0.5)  # Wait 0.5 seconds
