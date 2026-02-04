"""
TK08-ROTARY POTENTIOMETER - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK08-ROTARY POTENTIOMETER module to control LED brightness
- Rotate potentiometer to adjust LED brightness

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
3. Rotate potentiometer to adjust LED brightness
"""

# Import required modules
from machine import Pin, ADC, PWM  # GPIO control, analog input and PWM
import time                         # For delay (time.sleep)

# Pin number: change this to match your wiring
POT_PIN = 26  # GPIO connected to SIGNAL (e.g. GPIO 26, must be ADC-capable pin)
LED_PIN = 6   # GPIO connected to LED (must be PWM-capable pin, e.g. GPIO 6)

# Create ADC and PWM objects
pot = ADC(Pin(POT_PIN))  # Create ADC object to read analog value
led = PWM(Pin(LED_PIN))  # Create PWM object to control LED brightness

# Configure PWM frequency (1000 Hz)
led.freq(1000)

print("Rotary potentiometer LED brightness control program started")
print("Rotate potentiometer to adjust LED brightness")

# Main loop: runs forever
while True:
    # Read potentiometer analog value (0-65535)
    potValue = pot.read_u16()  # Read potentiometer pin value: 0 = leftmost, 65535 = rightmost, 32768 = middle
    
    # Map potentiometer value (0-65535) to LED brightness (0-65535)
    # Use potentiometer value directly as LED brightness value
    brightness = potValue
    
    # Use PWM to control LED brightness
    led.duty_u16(brightness)
    
    # Convert analog value to voltage value (0-3.3V)
    voltage = potValue * (3.3 / 65535.0)
    
    # Display values in terminal
    print("Potentiometer value: {} | Voltage: {:.2f}V | LED brightness: {}".format(potValue, voltage, brightness))
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
