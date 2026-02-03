"""
TK29-ADC MODULE - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK29-ADC MODULE module
- Connect TK20-AMBIENT LIGHT module to TK29
- Read TK29's ANA (analog value) and DIG (digital value)
- Output read values via serial

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
"""

# Import required modules
from machine import Pin, ADC  # GPIO control and ADC
import time                   # For delay (time.sleep)

# Pin number: change these to match your wiring
DIG_PIN = 0   # GPIO connected to DIG (e.g. GPIO 0)
ANA_PIN = 26  # GPIO connected to ANA (e.g. GPIO 26, must be ADC-capable pin)

# Create pin objects
dig = Pin(DIG_PIN, Pin.IN)        # Set DIG pin as input (to read digital output)
ana = ADC(Pin(ANA_PIN))           # Set ANA pin as ADC mode (to read analog input)

print("TK29-ADC MODULE program started")
print("Reading ANA (analog value) and DIG (digital value)")

# Main loop: runs forever
while True:
    # Read analog input value (0-65535)
    ana_value = ana.read_u16()
    
    # Read digital output value
    dig_value = dig.value()
    
    # Serial output ANA and DIG values
    print(f"ANA: {ana_value} | DIG: {dig_value}")
    
    time.sleep_ms(100)  # Delay 100 milliseconds to avoid output too fast
