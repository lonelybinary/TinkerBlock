"""
TK42-LM75 TEMPERATURE SENSOR - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK42-LM75 TEMPERATURE SENSOR module.

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
LM75_ADDRESS = 0x48  # LM75 I2C address (usually 0x48)
SDA_PIN = 0          # GPIO connected to SDA (e.g. GPIO 0)
SCL_PIN = 1          # GPIO connected to SCL (e.g. GPIO 1)

# Create I2C object
i2c = I2C(0, sda=Pin(SDA_PIN), scl=Pin(SCL_PIN), freq=100000)  # Create I2C object, frequency 100kHz

# Main loop: runs forever
while True:
    # Read temperature value (read 2 bytes from register 0x00)
    data = i2c.readfrom_mem(LM75_ADDRESS, 0x00, 2)  # Read 2 bytes from address 0x00
    
    # LM75 returned data: data[0] is high byte (MSB), data[1] is low byte (LSB)
    # Combine into 16-bit temperature value (high byte first, big-endian)
    tempRaw = (data[0] << 8) | data[1]
    
    # Convert to actual temperature (unit: Celsius)
    # LM75 temperature value is 11-bit signed number, unit is 0.125°C
    # Method: Keep consistent with Arduino version, directly shift right by 5 bits
    # Note: Python's right shift for signed numbers performs sign extension
    # First convert unsigned number to signed number (if highest bit is 1)
    if tempRaw & 0x8000:
        tempRaw_signed = tempRaw - 0x10000
    else:
        tempRaw_signed = tempRaw
    
    # Shift right by 5 bits to get 11-bit temperature value, then multiply by 0.125
    temperature = (tempRaw_signed >> 5) * 0.125
    
    # Display temperature on terminal
    print("Temperature: {:.2f}°C".format(temperature))
    
    # Delay 1 second to avoid reading too fast
    time.sleep(1)
