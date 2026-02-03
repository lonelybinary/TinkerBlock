"""
TK51-4-DIGIT DISPLAY - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK51-4-DIGIT DISPLAY module
- Cycle through 0-9 (all 4 digits display same number: 0000, 1111, 2222...9999)

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save both tm1637.py and this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
3. Observe the 4-digit display effect

Note: Requires tm1637.py driver file
Installation: Copy tm1637.py file to Pico (same directory as main program)
"""

from machine import Pin
import time

# Pin number: change these to match your wiring
CLK_PIN = 0   # GPIO connected to CLOCK (e.g. GPIO 0)
DIO_PIN = 1   # GPIO connected to DATA (e.g. GPIO 1)

# Import tm1637 library
try:
    from tm1637 import TM1637
    # Create TM1637 display object
    display = TM1637(CLK_PIN, DIO_PIN)
    display.brightness(7)  # Set brightness (0-7, 7 is brightest)
    HAS_LIB = True
    print("TM1637 driver loaded successfully")
except ImportError:
    print("Error: tm1637 library not found")
    print("Please copy tm1637.py file to Pico (same directory as main program)")
    HAS_LIB = False
except Exception as e:
    print(f"Error: Failed to initialize TM1637 - {e}")
    HAS_LIB = False

if HAS_LIB:
    print("4-digit display module program started")
    print("Cycling through 0-9 (all 4 digits display same number)")
    print()
    
    # Main loop: runs forever
    while True:
        # Cycle through 0-9 (all 4 digits display same number)
        for i in range(10):
            # Display number: 0 displays as 0000, 1 displays as 1111, 2 displays as 2222...9 displays as 9999
            display.number(i * 1111)
            print(f"Display number: {i}")
            time.sleep(1)  # Switch number every second
else:
    print("Program cannot run, please install tm1637.py driver file first")
