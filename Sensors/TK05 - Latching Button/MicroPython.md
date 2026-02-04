# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK05 - LOCK BUTTON module on a Raspberry Pi Pico 2 to detect button lock/unlock states. It covers GPIO input, state detection, conditional statements, loops, delay, and print in MicroPython.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

- **VCC** → Raspberry Pi Pico 2 3.3V or 5V
- **GND** → Raspberry Pi Pico 2 GND
- **SIGNAL** → Raspberry Pi Pico 2 GPIO 2 (or the pin you set as `BUTTON_PIN` in code)
- **NC** → Leave unconnected

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change this to match your wiring
BUTTON_PIN = 2   # SIGNAL pin connected to GPIO (e.g. GPIO 2)
LED_PIN = 25     # Pico built-in LED pin (GPIO 25, or external LED)

# Create pin objects
button = Pin(BUTTON_PIN, Pin.IN)   # Set button pin as input (to read button state)
led = Pin(LED_PIN, Pin.OUT)        # Set LED pin as output (to control LED on/off)

# Variables
last_button_state = button.value()  # Last button state
led_state = False                  # LED current state (False = off, True = on)

print("Lock button switch program started")
print("Press button to lock, LED stays on; press again to unlock, LED off")

# Main loop: runs forever
while True:
    # Read button state
    current_button_state = button.value()  # Read button pin level: 1 = locked (HIGH), 0 = unlocked (LOW)
    
    # Detect button state change (detect rising or falling edge)
    if current_button_state != last_button_state:
        # Button state changed
        if current_button_state == 1:
            # Button locked: toggle LED state
            led_state = not led_state  # Toggle LED state
            
            if led_state:
                led.on()                 # Output HIGH, LED on
                print("Button locked - LED on")
            else:
                led.off()                # Output LOW, LED off
                print("Button unlocked - LED off")
        
        # Update last state
        last_button_state = current_button_state
        time.sleep(0.2)  # Debounce delay
    
    time.sleep(0.05)  # Brief delay to avoid reading too fast
```

## Effect

![Effect](images/TK05-pico.gif)


## Code Walkthrough

**Lines 1–2: Imports**

```python
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)
```

- **`machine.Pin`:** Used to control Pico GPIO pins.
- **`time`:** Provides `sleep()` and other time-related functions.

**Lines 6–7: Pin definition**

```python
BUTTON_PIN = 2   # SIGNAL pin connected to GPIO (e.g. GPIO 2)
LED_PIN = 25     # Pico built-in LED pin (GPIO 25, or external LED)
```

- **`BUTTON_PIN`:** GPIO number for button SIGNAL. Change this if you use another pin.
- **`LED_PIN`:** GPIO number for LED (Pico built-in LED is GPIO 25, or external LED).

**Lines 10–11: Create pin objects**

```python
button = Pin(BUTTON_PIN, Pin.IN)   # Set button pin as input (to read button state)
led = Pin(LED_PIN, Pin.OUT)        # Set LED pin as output (to control LED on/off)
```

- **`Pin(BUTTON_PIN, Pin.IN)`:** Set button pin as input to read button state.
- **`Pin(LED_PIN, Pin.OUT)`:** Set LED pin as output to control LED on/off.

**Lines 14–15: Variable initialization**

```python
last_button_state = button.value()  # Last button state
led_state = False                  # LED current state (False = off, True = on)
```

- **`last_button_state`:** Save last button state to detect state changes (rising or falling edge).
- **`led_state`:** Save current LED state to toggle LED on/off (False = off, True = on).

**Lines 17–18: Print start message**

```python
print("Lock button switch program started")
print("Press button to lock, LED stays on; press again to unlock, LED off")
```

- **`print(...)`:** Print program start message and instructions to terminal.

**Lines 21–43: Main loop**

```python
while True:
    # Read button state
    current_button_state = button.value()  # Read button pin level: 1 = locked (HIGH), 0 = unlocked (LOW)
    
    # Detect button state change (detect rising or falling edge)
    if current_button_state != last_button_state:
        # Button state changed
        if current_button_state == 1:
            # Button locked: toggle LED state
            led_state = not led_state  # Toggle LED state
            
            if led_state:
                led.on()                 # Output HIGH, LED on
                print("Button locked - LED on")
            else:
                led.off()                # Output LOW, LED off
                print("Button unlocked - LED off")
        
        # Update last state
        last_button_state = current_button_state
        time.sleep(0.2)  # Debounce delay
    
    time.sleep(0.05)  # Brief delay to avoid reading too fast
```

- **`while True`:** Infinite loop; the program keeps running.
- **`button.value()`:** Read button pin level, returns 1 when locked (HIGH), 0 when unlocked (LOW).
- **`if current_button_state != last_button_state`:** Detect if button state changed, used to detect rising or falling edge.
- **`if current_button_state == 1`:** Check if button is locked; if locked, toggle LED state.
- **`led_state = not led_state`:** Toggle LED state (invert), implement lock/unlock toggle function.
- **`led.on()`:** Output HIGH, LED on.
- **`led.off()`:** Output LOW, LED off.
- **`print(...)`:** Print button state and LED status to terminal.
- **`last_button_state = current_button_state`:** Update last state for next detection.
- **`time.sleep(0.2)`:** Debounce delay 200 milliseconds to avoid false triggers.
- **`time.sleep(0.05)`:** Wait 50 milliseconds before reading again to avoid reading too fast and reduce CPU usage.
