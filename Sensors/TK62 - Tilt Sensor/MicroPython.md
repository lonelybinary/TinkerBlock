# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK62 - TILT SENSOR module on a Raspberry Pi Pico 2 to detect tilt and control LED.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
TILT_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1     # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)

# Create pin objects
tilt = Pin(TILT_PIN, Pin.IN)   # Set tilt sensor pin as input (to read detection state)
led = Pin(LED_PIN, Pin.OUT)    # Set LED pin as output (to control LED on/off)

print("Tilt sensor program started")
print("LED on when tilt detected, LED off when level")

# Main loop: runs forever
while True:
    # Read tilt sensor state
    tiltState = tilt.value()   # Read sensor pin level: 1=tilt (HIGH), 0=level (LOW)
    
    # Control LED based on detection state
    if tiltState == 1:
        # Tilt detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Tilt detected - LED on")
    else:
        # Level state: turn LED off
        led.off()                # Output LOW, LED off
        print("Level state - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

## Effect

![Effect](images/TK62-pico.gif)


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
TILT_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1     # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)
```

- **`TILT_PIN = 0`:** GPIO number for tilt sensor SIGNAL. Change this if you use another pin.
- **`LED_PIN = 1`:** GPIO number for LED (GPIO 1, or external LED, Pico built-in LED is GPIO 25).

**Lines 15–31: Main loop**

```python
while True:
    # Read tilt sensor state
    tiltState = tilt.value()   # Read sensor pin level: 1=tilt (HIGH), 0=level (LOW)
    
    # Control LED based on detection state
    if tiltState == 1:
        # Tilt detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Tilt detected - LED on")
    else:
        # Level state: turn LED off
        led.off()                # Output LOW, LED off
        print("Level state - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`tilt.value()`:** Read tilt sensor pin level, returns 1 when tilt detected (HIGH), 0 when level (LOW).
- **`if tiltState == 1`:** Check if tilt is detected; if detected, execute LED on operation.
- **`led.on()`:** Output HIGH, LED on.
- **`led.off()`:** Output LOW, LED off.
- **`print(...)`:** Print tilt state and LED status to terminal.
- **`time.sleep_ms(100)`:** Wait 100 milliseconds before reading again to avoid reading too fast.
