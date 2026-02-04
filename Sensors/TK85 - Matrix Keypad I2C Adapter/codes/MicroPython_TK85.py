"""
TK85-MATRIX KEYPAD I2C ADAPTER - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK85-MATRIX KEYPAD I2C ADAPTER module

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
"""

# Import required modules
from machine import Pin, I2C  # GPIO control and I2C communication
import time                   # For delay (time.sleep)

# Define I2C address and pins
KEYPAD_ADDRESS = 0x20  # I2C address of matrix keypad adapter module (check module documentation, usually 0x20 or 0x21)
SDA_PIN = 0            # GPIO connected to SDA (e.g. GPIO 0)
SCL_PIN = 1            # GPIO connected to SCL (e.g. GPIO 1)

# Create I2C object
i2c = I2C(0, sda=Pin(SDA_PIN), scl=Pin(SCL_PIN), freq=100000)  # Create I2C object, frequency 100kHz

# Keypad mapping (4x4 matrix keypad)
keymap = "DCBA#9630852*741"

# Debounce variables
stable_key = 16   # 16 = NoKey
stable_count = 0
last_keypad_key = 16

def read_keypad():
    """Read matrix keypad
    Returns: -1 means no key, 0-15 means key number
    """
    current_key = 16  # 0..15 or 16(NoKey)
    found = False
    
    # Mode A: rows = lower 4 bits (P0..P3), columns = upper 4 bits (P4..P7)
    for col in range(4):
        if found:
            break
        # Pull all high (quasi-input), pull one column low
        out = 0xFF & ~(1 << (4 + col))
        try:
            i2c.writeto(KEYPAD_ADDRESS, bytes([out]))
            time.sleep_us(200)
            
            data = i2c.readfrom(KEYPAD_ADDRESS, 1)
            raw = data[0]
            rows = raw & 0x0F
            if rows != 0x0F:
                for row in range(4):
                    if not (rows & (1 << row)):
                        current_key = row * 4 + col
                        found = True
                        break
        except:
            continue
    
    # Mode B: rows = upper 4 bits (P4..P7), columns = lower 4 bits (P0..P3)
    if not found:
        for col in range(4):
            if found:
                break
            out = 0xFF & ~(1 << col)
            try:
                i2c.writeto(KEYPAD_ADDRESS, bytes([out]))
                time.sleep_us(200)
                
                data = i2c.readfrom(KEYPAD_ADDRESS, 1)
                raw = data[0]
                rows = (raw >> 4) & 0x0F
                if rows != 0x0F:
                    for row in range(4):
                        if not (rows & (1 << row)):
                            current_key = row * 4 + col
                            found = True
                            break
            except:
                continue
    
    # Restore all high
    try:
        i2c.writeto(KEYPAD_ADDRESS, bytes([0xFF]))
    except:
        pass
    
    # Debounce: need to read the same key twice consecutively to consider it pressed
    global stable_key, stable_count, last_keypad_key
    
    if current_key < 16:
        if current_key == stable_key:
            if stable_count < 255:
                stable_count += 1
        else:
            stable_key = current_key
            stable_count = 1

        if stable_count >= 2 and current_key != last_keypad_key:
            last_keypad_key = current_key
            return current_key
    else:
        stable_key = 16
        stable_count = 0
        if last_keypad_key != 16:
            last_keypad_key = 16
    
    return -1

print("Matrix keypad test")
print("Press keys to see key code output")

# Main loop: runs forever
while True:
    key = read_keypad()
    
    if key >= 0:
        print("Key pressed: number={}, character='{}'".format(key, keymap[key]))
    
    time.sleep_ms(50)
