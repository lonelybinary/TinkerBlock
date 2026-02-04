# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK28 - TAP SENSOR module on a Raspberry Pi Pico 2 to detect taps.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
TAP_PIN = 0     # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1     # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)

# Create pin objects
tap = Pin(TAP_PIN, Pin.IN)   # Set tap sensor pin as input (to read detection state)
led = Pin(LED_PIN, Pin.OUT)  # Set LED pin as output (to control LED on/off)

print("Tap sensor program started")
print("LED on when tap detected, LED off when no tap")

# Main loop: runs forever
while True:
    # Read tap sensor state
    tapState = tap.value()   # Read sensor pin level: 1 = tap (HIGH), 0 = no tap (LOW)
    
    # Control LED based on detection state
    if tapState == 1:
        # Tap detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Tap detected - LED on")
    else:
        # No tap detected: turn LED off
        led.off()                # Output LOW, LED off
        print("No tap detected - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

## Effect

![Effect](images/TK28-pico.gif)


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
TAP_PIN = 0     # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1     # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)
```

- **`TAP_PIN = 0`:** GPIO number for tap sensor SIGNAL. Change this if you use another pin.
- **`LED_PIN = 1`:** GPIO number for LED (GPIO 1, or external LED, Pico built-in LED is GPIO 25).

**Lines 9–10: Create pin objects**

```python
tap = Pin(TAP_PIN, Pin.IN)   # Set tap sensor pin as input (to read detection state)
led = Pin(LED_PIN, Pin.OUT)  # Set LED pin as output (to control LED on/off)
```

- **`Pin(TAP_PIN, Pin.IN)`:** Set tap sensor pin as input to read detection state.
- **`Pin(LED_PIN, Pin.OUT)`:** Set LED pin as output to control LED on/off.

**Lines 13–14: Print start message**

```python
print("Tap sensor program started")
print("LED on when tap detected, LED off when no tap")
```

- **`print(...)`:** Print program start message and instructions to terminal.

**Lines 17–29: Main loop**

```python
while True:
    # Read tap sensor state
    tapState = tap.value()   # Read sensor pin level: 1 = tap (HIGH), 0 = no tap (LOW)
    
    # Control LED based on detection state
    if tapState == 1:
        # Tap detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Tap detected - LED on")
    else:
        # No tap detected: turn LED off
        led.off()                # Output LOW, LED off
        print("No tap detected - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`tap.value()`:** Read tap sensor pin level, returns 1 when tap is detected (HIGH), 0 when no tap (LOW).
- **`if tapState == 1`:** Check if tap is detected; if detected, execute LED on operation.
- **`led.on()`:** Output HIGH, LED on.
- **`led.off()`:** Output LOW, LED off.
- **`print(...)`:** Print detection state and LED status to terminal.
- **`time.sleep_ms(100)`:** Wait 100 milliseconds before reading again to avoid reading too fast.
