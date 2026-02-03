"""
TK37-PASSIVE BUZZER - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK37-PASSIVE BUZZER module.

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
BUZZER_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)

# Create PWM object
buzzer = PWM(Pin(BUZZER_PIN))

print("Passive buzzer program started")

# Main loop: runs forever
while True:
    # Play scale: Do Re Mi Fa Sol La Si
    # C4=262Hz, D4=294Hz, E4=330Hz, F4=349Hz, G4=392Hz, A4=440Hz, B4=494Hz
    
    notes = [262, 294, 330, 349, 392, 440, 494]  # Scale frequencies
    note_names = ["Do", "Re", "Mi", "Fa", "Sol", "La", "Si"]  # Note names
    
    for i in range(7):
        buzzer.freq(notes[i])      # Set frequency
        buzzer.duty_u16(32767)     # Set duty cycle to 50% (32767 is half of 65535)
        print(f"Playing: {note_names[i]} ({notes[i]} Hz)")
        time.sleep(0.5)            # Each note plays for 0.5 seconds
    
    buzzer.duty_u16(0)            # Stop playing (duty cycle = 0)
    print("Playback complete, waiting 0.5 seconds before repeating")
    time.sleep(0.5)
