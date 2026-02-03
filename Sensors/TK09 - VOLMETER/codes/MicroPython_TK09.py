"""
TK09-VOLMETER - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK09-VOLMETER voltage detection module
- Module can scale 0-16.5V voltage to 0-3.3V for MCU reading
- Read scaled voltage signal and calculate original voltage (0-16.5V)

Wiring:
- GPIO 26: SIG output pin connected to Pico ADC pin (e.g. GPIO 26)
- VCC: Connect to Pico 3.3V and positive terminal of voltage being measured (up to 16.5V)
- GND: Connect to Pico GND and negative terminal of voltage being measured

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
3. Observe voltage value changes (0-16.5V)
"""

# Import required modules
from machine import Pin, ADC  # GPIO control and ADC
import time                   # For delay (time.sleep)

# Pin number: change this to match your wiring
VOLTAGE_PIN = 26  # GPIO connected to SIG output (e.g. GPIO 26, must be ADC-capable pin)

# Create ADC object
voltage_adc = ADC(Pin(VOLTAGE_PIN))  # Set voltage detection output pin as ADC mode (to read analog signal)

print("Voltage detection module program started")
print("Reading scaled voltage signal and calculating original voltage (0-16.5V)")

# Main loop: runs forever
while True:
    # Read analog input value (0-65535)
    sensor_value = voltage_adc.read_u16()  # Read scaled voltage signal value
    
    # Convert analog value to voltage (0-3.3V)
    voltage = sensor_value * (3.3 / 65535.0)  # Pico analog input range is 0-65535, corresponding to 0-3.3V
    
    # Multiply scaled voltage by 5 to get original voltage (module scales voltage by 5x)
    original_voltage = voltage * 5.0  # Multiply by 5 to get original voltage (0-16.5V)
    
    # Print voltage value
    print(f"Scaled voltage: {voltage:.3f}V | Original voltage: {original_voltage:.3f}V")
    
    time.sleep(0.5)  # Wait 0.5 seconds before reading again
