"""
TK12-NTC THERMISTOR - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK12-NTC THERMISTOR module.

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
"""

# Import required modules
from machine import Pin, ADC  # GPIO control and ADC
import time                   # For delay (time.sleep)
import math                   # Math functions (log)

# Pin number: change this to match your wiring
TEMP_PIN = 26  # GPIO connected to SIGNAL (e.g. GPIO 26, must be ADC-capable pin)

# NTC thermistor parameters (adjust according to actual module specifications)
VCC = 3.3           # Supply voltage (V)
R0 = 10000.0        # NTC resistance at 25°C (Ω), usually 10KΩ
T0 = 25.0 + 273.15  # Reference temperature (Kelvin), 25°C = 298.15K
BETA = 3950.0       # Beta value (according to NTC specifications, common value is 3950, try 3435 or 4100 if temperature is inaccurate)
R_SERIES = 10000.0  # Pull-up resistor value (Ω), usually 10KΩ
TEMP_OFFSET = 0.0   # Temperature offset (°C), for calibration, set to negative if temperature is high, positive if low

# Create ADC object
temp = ADC(Pin(TEMP_PIN))  # Set temperature sensor pin as ADC mode (to read analog signal)

print("NTC thermistor program started")
print("Using Beta equation to calculate temperature")

# Main loop: runs forever
while True:
    # Read analog input value (0-65535)
    sensor_value = temp.read_u16()
    
    # Convert analog value to voltage (0-3.3V)
    voltage = sensor_value * (VCC / 65535.0)
    
    # Calculate NTC thermistor resistance
    # Using voltage divider formula: Vout = VCC * R_NTC / (R_SERIES + R_NTC)
    # Derived: R_NTC = R_SERIES * Vout / (VCC - Vout)
    if voltage > 0 and voltage < VCC:
        r_ntc = R_SERIES * voltage / (VCC - voltage)
    else:
        # If voltage is out of range, use default value
        r_ntc = R0
    
    # Calculate temperature using Beta equation (Kelvin)
    # T = 1 / (1/T0 + (1/BETA) * ln(R/R0))
    if r_ntc > 0 and r_ntc < 1000000.0:  # Limit resistance range to avoid abnormal values
        ln_r = math.log(r_ntc / R0)
        temperature_k = 1.0 / (1.0 / T0 + (1.0 / BETA) * ln_r)
    else:
        temperature_k = T0  # If calculation is abnormal, use reference temperature
    
    # Convert to Celsius and apply offset
    temperature = temperature_k - 273.15 + TEMP_OFFSET
    
    # Limit temperature range (avoid abnormal values)
    if temperature < -50.0:
        temperature = -50.0
    if temperature > 150.0:
        temperature = 150.0
    
    # Print temperature value
    print(f"Temperature: {temperature:.2f} °C")
    
    time.sleep(1)  # Wait 1 second before reading again
