"""
TK19-4-DIRECTIONs TIL SENSOR - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK19-4-DIRECTIONs TIL SENSOR module
- Detect tilt status in four directions: up, down, left, right
- Display tilt direction in terminal

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
3. Tilt the sensor module and observe terminal output
"""

# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
A_PIN = 0      # GPIO connected to A (as common, output LOW)
B_PIN = 1      # GPIO connected to B (INPUT_PULLUP, detect direction B)
C_PIN = 2      # GPIO connected to C (INPUT_PULLUP, detect direction C)
D_PIN = 3      # GPIO connected to D (INPUT_PULLUP, detect direction D)

# Create pin objects
a = Pin(A_PIN, Pin.OUT)              # Set A pin as output (as common)
b = Pin(B_PIN, Pin.IN, Pin.PULL_UP)  # Set B pin as INPUT_PULLUP (detect direction B tilt)
c = Pin(C_PIN, Pin.IN, Pin.PULL_UP)  # Set C pin as INPUT_PULLUP (detect direction C tilt)
d = Pin(D_PIN, Pin.IN, Pin.PULL_UP)  # Set D pin as INPUT_PULLUP (detect direction D tilt)

# Set A pin to LOW (as common/ground)
a.off()  # Output LOW

print("4-direction tilt sensor program started")
print("Detecting tilt status in four directions")
print("A pin as common (LOW), B/C/D pins detect tilt (0=tilt)")

# Main loop: runs forever
while True:
    # Read tilt status of three directions
    # When B/C/D pins read 0 (LOW), it means tilt detected in corresponding direction
    b_state = b.value()   # Read B pin: 0 = direction B tilt (LOW), 1 = no tilt (HIGH)
    c_state = c.value()   # Read C pin: 0 = direction C tilt (LOW), 1 = no tilt (HIGH)
    d_state = d.value()   # Read D pin: 0 = direction D tilt (LOW), 1 = no tilt (HIGH)
    
    # Detect and output tilt direction
    tilted = False  # Flag to mark if tilt is detected
    
    if b_state == 0:
        print("Detected: Direction B tilt")
        tilted = True
    
    if c_state == 0:
        print("Detected: Direction C tilt")
        tilted = True
    
    if d_state == 0:
        print("Detected: Direction D tilt")
        tilted = True
    
    # If no direction is tilted, show level status
    if not tilted:
        print("Level")
    
    # Display all pin states (for debugging)
    print(f"State: B={b_state}(0=tilt), C={c_state}(0=tilt), D={d_state}(0=tilt)")
    print("---")
    
    # Delay 100 milliseconds to avoid output too fast
    time.sleep_ms(100)
