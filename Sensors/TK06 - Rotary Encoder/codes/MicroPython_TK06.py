"""
TK06-ROTARY ENCODER - Raspberry Pi Pico 2 Example

Description:
This script demonstrates how to use the TK06-ROTARY ENCODER module to control LED brightness
- Rotary encoder: rotate clockwise to increase LED brightness, counterclockwise to decrease
- Encoder button: press to toggle LED on/off state

Wiring:
Change the pin definition in code to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script and check terminal output
3. Rotate encoder knob to adjust LED brightness
4. Press encoder button to toggle LED switch
"""

# Import required modules
from machine import Pin, PWM  # GPIO control and PWM
import time                    # For delay (time.sleep)

# Pin number: change these to match your wiring
CLOCK_PIN = 3   # GPIO connected to CLOCK (e.g. GPIO 3)
DATA_PIN = 4    # GPIO connected to DATA (e.g. GPIO 4)
BTN_PIN = 2     # GPIO connected to BTN (e.g. GPIO 2)
LED_PIN = 6     # GPIO connected to LED (must be PWM-capable pin, e.g. GPIO 6)

# Create pin objects
clock = Pin(CLOCK_PIN, Pin.IN, Pin.PULL_UP)  # CLOCK pin, input mode, enable pull-up resistor
data = Pin(DATA_PIN, Pin.IN, Pin.PULL_UP)    # DATA pin, input mode, enable pull-up resistor
btn = Pin(BTN_PIN, Pin.IN, Pin.PULL_UP)      # BTN pin, input mode, enable pull-up resistor
led = PWM(Pin(LED_PIN))                      # LED pin, PWM mode

# Configure PWM frequency (1000 Hz)
led.freq(1000)

# Variables
last_clock_state = clock.value()  # Last CLOCK pin state
last_btn_state = btn.value()      # Last BTN pin state
brightness = 32768                 # LED brightness value (0-65535, corresponds to 0-100%)
led_enabled = True                 # LED switch state

# Set initial LED brightness
led.duty_u16(brightness)

print("Rotary encoder LED brightness control program started")
print("Rotate clockwise to increase brightness, counterclockwise to decrease")
print("Press button to toggle LED switch")

# Main loop: runs forever
while True:
    # Read current CLOCK pin state
    current_clock_state = clock.value()
    
    # Detect CLOCK pin state change (from HIGH to LOW)
    if current_clock_state != last_clock_state:
        if current_clock_state == 0:  # LOW = 0
            # When CLOCK becomes LOW, read DATA pin state to determine rotation direction
            data_state = data.value()
            
            if data_state == 0:  # LOW = 0
                # DATA is LOW, clockwise rotation, increase brightness
                brightness = min(65535, brightness + 5136)  # Increase by about 8% each time
                print(f"Clockwise rotation, brightness: {brightness}")
            else:  # HIGH = 1
                # DATA is HIGH, counterclockwise rotation, decrease brightness
                brightness = max(0, brightness - 5136)  # Decrease by about 8% each time
                print(f"Counterclockwise rotation, brightness: {brightness}")
            
            # Update LED brightness (if LED is enabled)
            if led_enabled:
                led.duty_u16(brightness)
        
        # Update last state
        last_clock_state = current_clock_state
    
    # Detect button press (detect falling edge)
    current_btn_state = btn.value()
    if current_btn_state == 0 and last_btn_state == 1:  # From HIGH to LOW
        # Toggle LED switch state
        led_enabled = not led_enabled
        
        if led_enabled:
            led.duty_u16(brightness)
            print(f"LED on, brightness: {brightness}")
        else:
            led.duty_u16(0)
            print("LED off")
        
        time.sleep(0.2)  # Debounce delay
    
    last_btn_state = current_btn_state
