"""
TK16-IR REMOTE SENSOR - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK16-IR REMOTE SENSOR module.

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
"""

# Import required modules
from machine import Pin, PWM  # GPIO control and PWM
import time                   # For delay (time.sleep)

# Pin number: change this to match your wiring
IR_TX_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)

# Create PWM object
ir_tx = PWM(Pin(IR_TX_PIN))

# Set PWM frequency to 38kHz (common IR remote frequency)
ir_tx.freq(38000)

print("IR remote transmitter program started")
print("Transmitting IR signal every 2 seconds")

# Main loop: runs forever
while True:
    # Transmit IR signal (38kHz modulation)
    ir_tx.duty_u16(32767)     # Set duty cycle to 50% (32767 is half of 65535)
    time.sleep(0.1)           # Transmit for 100 milliseconds
    
    # Stop transmission
    ir_tx.duty_u16(0)         # Set duty cycle to 0%, stop transmission
    time.sleep(2)             # Wait 2 seconds before transmitting again
    
    print("IR signal transmitted")
