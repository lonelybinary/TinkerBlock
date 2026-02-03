# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK61 - PHOTOELECTRIC SWITCH module on a Raspberry Pi Pico 2 to detect objects and control LED.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change this to match your wiring
PHOTO_SWITCH_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1           # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)

# Create pin objects
photo_switch = Pin(PHOTO_SWITCH_PIN, Pin.IN)  # Set photoelectric switch pin as input (to read detection state)
led = Pin(LED_PIN, Pin.OUT)                    # Set LED pin as output (to control LED on/off)

print("Photoelectric switch program started")
print("LED on when object blocks light, LED off when no object detected")

# Main loop: runs forever
while True:
    # Read photoelectric switch state
    switch_state = photo_switch.value()  # Read sensor pin level: 1=object detected (HIGH), 0=no object (LOW)
    
    # Control LED based on detection state
    if switch_state == 1:
        # Object blocks light: turn LED on and print message
        led.on()            # Output HIGH, LED on
        print("Object blocks light - LED on")
    else:
        # No object detected: turn LED off
        led.off()           # Output LOW, LED off
        print("No object detected - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

## Effect

![Effect](images/TK61-pico.gif)


## Code Walkthrough

**Lines 1–2: Imports**

```python
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)
```

- **`machine.Pin`:** Used to control Pico GPIO pins.
- **`time`:** Provides `sleep()` and other time-related functions.

**Lines 5–6: Pin definition**

```python
PHOTO_SWITCH_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1           # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)
```

- **`PHOTO_SWITCH_PIN = 0`:** GPIO number for photoelectric switch SIGNAL. Change this if you use another pin.
- **`LED_PIN = 1`:** GPIO number for LED (GPIO 1, or external LED, Pico built-in LED is GPIO 25).

**Lines 15–31: Main loop**

```python
while True:
    # Read photoelectric switch state
    switch_state = photo_switch.value()  # Read sensor pin level: 1=object detected (HIGH), 0=no object (LOW)
    
    # Control LED based on detection state
    if switch_state == 1:
        # Object blocks light: turn LED on and print message
        led.on()            # Output HIGH, LED on
        print("Object blocks light - LED on")
    else:
        # No object detected: turn LED off
        led.off()           # Output LOW, LED off
        print("No object detected - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`photo_switch.value()`:** Read photoelectric switch pin level, returns 1 when object blocks light (HIGH), 0 when no object detected (LOW).
- **`if switch_state == 1`:** Check if object blocks light; if detected, execute LED on operation.
- **`led.on()`:** Output HIGH, LED on.
- **`led.off()`:** Output LOW, LED off.
- **`print(...)`:** Print detection state and LED status to terminal.
- **`time.sleep_ms(100)`:** Wait 100 milliseconds before reading again to avoid reading too fast.
