"""
TK31-EEPROM MODULE - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK31-EEPROM MODULE module.

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
"""

# Import required modules
from machine import Pin, I2C  # GPIO control and I2C
import time                   # For delay (time.sleep)

# Define I2C pins
SDA_PIN = 0  # GPIO connected to SDA (e.g. GPIO 0)
SCL_PIN = 1  # GPIO connected to SCL (e.g. GPIO 1)

# EEPROM address (usually 0x50)
EEPROM_ADDR = 0x50

# Create I2C object
i2c = I2C(0, sda=Pin(SDA_PIN), scl=Pin(SCL_PIN), freq=100000)

print("EEPROM module program started")

# Write data function
def write_eeprom(address, data):
    # EEPROM requires 16-bit address, needs to be split into high and low bytes
    addr_high = (address >> 8) & 0xFF  # Address high byte
    addr_low = address & 0xFF          # Address low byte
    # Manually send address and data
    i2c.writeto(EEPROM_ADDR, bytes([addr_high, addr_low, data]))
    time.sleep(0.01)  # Wait for write to complete

# Read data function
def read_eeprom(address):
    # EEPROM requires 16-bit address, needs to be split into high and low bytes
    addr_high = (address >> 8) & 0xFF  # Address high byte
    addr_low = address & 0xFF           # Address low byte
    # Write address first
    i2c.writeto(EEPROM_ADDR, bytes([addr_high, addr_low]))
    # Then read data
    data = i2c.readfrom(EEPROM_ADDR, 1)
    return data[0]

# Write data
write_eeprom(0, 123)  # Write data 123 to address 0
print("Data written to EEPROM")

time.sleep(0.1)  # Wait for write to complete

# Main loop: runs forever
while True:
    # Read data
    data = read_eeprom(0)  # Read data from address 0
    print(f"Data read from EEPROM: {data}")
    
    time.sleep(2)  # Wait 2 seconds
