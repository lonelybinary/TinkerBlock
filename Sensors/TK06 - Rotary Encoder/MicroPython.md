# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK06 - ROTARY ENCODER module on a Raspberry Pi Pico 2 to control LED brightness by rotating the encoder knob.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

- **VCC** → Raspberry Pi Pico 2 3.3V or 5V
- **GND** → Raspberry Pi Pico 2 GND
- **CLOCK** → Raspberry Pi Pico 2 GPIO 3 (or the pin you set as `CLOCK_PIN` in code)
- **DATA** → Raspberry Pi Pico 2 GPIO 4 (or the pin you set as `DATA_PIN` in code)
- **BTN** → Raspberry Pi Pico 2 GPIO 2 (or the pin you set as `BTN_PIN` in code, optional)
- **NC** → Leave unconnected

## Code

```python
# Import required modules
from machine import Pin, PWM  # GPIO control and PWM
import time                    # For delay (time.sleep)

# Pin number: change this to match your wiring
CLOCK_PIN = 3   # CLOCK pin connected to GPIO (e.g. GPIO 3)
DATA_PIN = 4    # DATA pin connected to GPIO (e.g. GPIO 4)
BTN_PIN = 2     # BTN pin connected to GPIO (e.g. GPIO 2)
LED_PIN = 6     # LED pin connected to GPIO (must be PWM-capable pin, e.g. GPIO 6)

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
print("Press button to toggle LED on/off")

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
```

## Effect

![Effect](images/TK06-pico.gif)


## Code Walkthrough

**Lines 1–2: Imports**

```python
from machine import Pin, PWM  # GPIO control and PWM
import time                    # For delay (time.sleep)
```

- **`machine.Pin`:** Used to control Pico GPIO pins.
- **`machine.PWM`:** Used to control Pico PWM output.
- **`time`:** Provides `sleep()` and other time-related functions.

**Lines 5–8: Pin definition**

```python
CLOCK_PIN = 3   # CLOCK pin connected to GPIO (e.g. GPIO 3)
DATA_PIN = 4    # DATA pin connected to GPIO (e.g. GPIO 4)
BTN_PIN = 2     # BTN pin connected to GPIO (e.g. GPIO 2)
LED_PIN = 6     # LED pin connected to GPIO (must be PWM-capable pin, e.g. GPIO 6)
```

- **`CLOCK_PIN`:** GPIO number for rotary encoder CLOCK. Change this if you use another pin.
- **`DATA_PIN`:** GPIO number for rotary encoder DATA. Change this if you use another pin.
- **`BTN_PIN`:** GPIO number for rotary encoder button. Change this if you use another pin.
- **`LED_PIN`:** GPIO number for LED (must be PWM-capable pin). Change this if you use another pin.

**Lines 11–14: Create pin objects**

```python
clock = Pin(CLOCK_PIN, Pin.IN, Pin.PULL_UP)  # CLOCK pin, input mode, enable pull-up resistor
data = Pin(DATA_PIN, Pin.IN, Pin.PULL_UP)    # DATA pin, input mode, enable pull-up resistor
btn = Pin(BTN_PIN, Pin.IN, Pin.PULL_UP)      # BTN pin, input mode, enable pull-up resistor
led = PWM(Pin(LED_PIN))                      # LED pin, PWM mode
```

- **`Pin(CLOCK_PIN, Pin.IN, Pin.PULL_UP)`:** Set CLOCK pin as input with pull-up resistor enabled.
- **`Pin(DATA_PIN, Pin.IN, Pin.PULL_UP)`:** Set DATA pin as input with pull-up resistor enabled.
- **`Pin(BTN_PIN, Pin.IN, Pin.PULL_UP)`:** Set BTN pin as input with pull-up resistor enabled.
- **`PWM(Pin(LED_PIN))`:** Create PWM object for LED pin.

**Line 17: Configure PWM frequency**

```python
led.freq(1000)
```

- **`freq(1000)`:** Set PWM frequency to 1000 Hz.

**Lines 20–23: Variable initialization**

```python
last_clock_state = clock.value()  # Last CLOCK pin state
last_btn_state = btn.value()      # Last BTN pin state
brightness = 32768                 # LED brightness value (0-65535, corresponds to 0-100%)
led_enabled = True                 # LED switch state
```

- **`last_clock_state`:** Save last CLOCK pin state to detect state changes.
- **`last_btn_state`:** Save last BTN pin state to detect button press.
- **`brightness`:** LED brightness value (0-65535, corresponds to 0-100%), initial value is 32768 (50%).
- **`led_enabled`:** LED switch state, initial value is True (on).

**Lines 26–29: Print start message**

```python
print("Rotary encoder LED brightness control program started")
print("Rotate clockwise to increase brightness, counterclockwise to decrease")
print("Press button to toggle LED on/off")
```

- **`print(...)`:** Print program start message and instructions to terminal.

**Lines 32–60: Main loop**

```python
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
```

- **`while True`:** Infinite loop; the program keeps running.
- **`clock.value()`:** Read CLOCK pin state to detect rotary encoder rotation.
- **`if current_clock_state != last_clock_state`:** Detect CLOCK pin state change.
- **`if current_clock_state == 0`:** When CLOCK becomes LOW, read DATA pin to determine rotation direction.
- **`data.value()`:** Read DATA pin state, 0 (LOW) means clockwise rotation, 1 (HIGH) means counterclockwise rotation.
- **`brightness = min(65535, brightness + 5136)`:** Increase brightness when rotating clockwise, maximum is 65535.
- **`brightness = max(0, brightness - 5136)`:** Decrease brightness when rotating counterclockwise, minimum is 0.
- **`led.duty_u16(brightness)`:** Use PWM to control LED brightness (0-65535).
- **`btn.value()`:** Read button pin state.
- **`if current_btn_state == 0 and last_btn_state == 1`:** Detect button falling edge (press).
- **`led_enabled = not led_enabled`:** Toggle LED switch state.
- **`print(...)`:** Print rotation direction and brightness information to terminal.
- **`time.sleep(0.2)`:** Debounce delay 200 milliseconds to avoid false triggers.
