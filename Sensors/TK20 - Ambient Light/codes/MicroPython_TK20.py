"""
TK20-AMBIENT LIGHT - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK20-AMBIENT LIGHT module.

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
"""

# Import required modules
from machine import Pin, ADC  # GPIO control and analog input
import time                   # For delay (time.sleep)

# Pin number: change this to match your wiring
LIGHT_PIN = 26  # GPIO connected to SIGNAL (e.g. GPIO 26, must be ADC-capable pin)

# Create analog input object
light = ADC(Pin(LIGHT_PIN))  # Create ADC object to read analog value

# Main loop: runs forever
while True:
    # Read ambient light sensor analog value (0-65535)
    lightValue = light.read_u16()  # Read analog value: 0 = darkest, 65535 = brightest
    
    # Convert analog value to voltage (0-3.3V)
    voltage = lightValue * (3.3 / 65535.0)
    
    # Display values in terminal
    print("Light value: {} | Voltage: {:.2f}V".format(lightValue, voltage))
    
    # Judge light intensity
    if lightValue > 30000:
        print("Bright")
    elif lightValue > 10000:
        print("Moderate")
    else:
        print("Dark")
    
    # Delay 100 milliseconds to avoid printing too fast
    time.sleep_ms(100)
