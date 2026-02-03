"""
TK27-ANALOG MIC SENSOR - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK27-ANALOG MIC SENSOR module.

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
MIC_PIN = 26  # GPIO connected to SIGNAL (e.g. GPIO 26, must be ADC-capable pin)

# Create analog input object
mic = ADC(Pin(MIC_PIN))  # Create ADC object to read analog value

# Main loop: runs forever
while True:
    # Read microphone sensor analog value (0-65535)
    micValue = mic.read_u16()  # Read analog value: 0 = quietest, 65535 = loudest
    
    # Convert analog value to voltage (0-3.3V)
    voltage = micValue * (3.3 / 65535.0)
    
    # Display values in terminal
    print("Sound value: {} | Voltage: {:.2f}V".format(micValue, voltage))
    
    # Judge sound intensity
    if micValue > 30000:
        print("Very loud")
    elif micValue > 10000:
        print("Moderate")
    else:
        print("Very quiet")
    
    # Delay 100 milliseconds to avoid printing too fast
    time.sleep_ms(100)
