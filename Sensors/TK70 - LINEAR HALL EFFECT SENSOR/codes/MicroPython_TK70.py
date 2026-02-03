"""
TK70-LINEAR HALL EFFECT SENSOR - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK70-LINEAR HALL EFFECT SENSOR module
- Read magnetic field strength value and output via serial

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
3. Bring magnet close to sensor and observe strength value changes
"""

# Import required modules
from machine import Pin, ADC  # GPIO control and ADC
import time                   # For delay (time.sleep)

# Pin number: change this to match your wiring
HALL_PIN = 26  # GPIO connected to SIGNAL (e.g. GPIO 26, must be ADC pin)

# Create ADC object
hall = ADC(Pin(HALL_PIN))  # Set Hall sensor pin as ADC mode (to read analog signal)

print("Linear Hall sensor program started")
print("Reading magnetic field strength value and output via serial")

# Main loop: runs forever
while True:
    # Read Hall sensor analog value (0-65535)
    sensor_value = hall.read_u16()  # Read sensor pin analog value: 0=no magnetic field, 65535=strong magnetic field
    
    # Convert analog value to voltage value (0-3.3V)
    voltage = sensor_value * (3.3 / 65535.0)
    
    # Output strength value
    print(f"Magnetic field strength: {sensor_value} | Voltage: {voltage:.3f}V")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
