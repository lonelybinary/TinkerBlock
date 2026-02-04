"""
TK17-COLLISION SENSOR - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK17-COLLISION SENSOR module.

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
COLLISION_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1         # Pico built-in LED pin (GPIO 25, or external LED)

# Create pin objects
collision = Pin(COLLISION_PIN, Pin.IN)   # Set collision pin as input (to read collision state)
led = Pin(LED_PIN, Pin.OUT)              # Set LED pin as output (to control LED on/off)

# Main loop: runs forever
while True:
    # Read collision sensor state
    collisionState = collision.value()   # Read collision pin level: 1 = collision (HIGH), 0 = no collision (LOW)
    
    # Control LED based on collision state
    if collisionState == 1:
        # Collision detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Collision detected!")    # Display message in terminal
    else:
        # No collision detected: turn LED off
        led.off()                # Output LOW, LED off
    
    # Delay 50 milliseconds to avoid reading too fast (give sensor stabilization time, prevent false triggers)
    time.sleep_ms(50)
