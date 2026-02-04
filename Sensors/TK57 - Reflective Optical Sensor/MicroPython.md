# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK57 - LINE TRACKER module on a Raspberry Pi Pico 2 to detect lines and control LED.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
TRACKER_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1        # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)

# Create pin objects
tracker = Pin(TRACKER_PIN, Pin.IN)  # Set line tracker pin as input (to read detection state)
led = Pin(LED_PIN, Pin.OUT)         # Set LED pin as output (to control LED on/off)

print("Line tracker program started")
print("LED on when black line detected, LED off when white line detected")

# Main loop: runs forever
while True:
    # Read line tracker state
    trackerState = tracker.value()   # Read sensor pin level: 1=black line detected (HIGH), 0=white line detected (LOW)
    
    # Control LED based on detection state
    if trackerState == 1:
        # Black line detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Black line detected - LED on")
    else:
        # White line detected: turn LED off
        led.off()                # Output LOW, LED off
        print("White line detected - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

## Effect

![Effect](images/TK57-pico.gif)


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
TRACKER_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1        # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)
```

- **`TRACKER_PIN = 0`:** GPIO number for line tracker SIGNAL. Change this if you use another pin.
- **`LED_PIN = 1`:** GPIO number for LED (GPIO 1, or external LED, Pico built-in LED is GPIO 25).

**Lines 15–31: Main loop**

```python
while True:
    # Read line tracker state
    trackerState = tracker.value()   # Read sensor pin level: 1=black line detected (HIGH), 0=white line detected (LOW)
    
    # Control LED based on detection state
    if trackerState == 1:
        # Black line detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Black line detected - LED on")
    else:
        # White line detected: turn LED off
        led.off()                # Output LOW, LED off
        print("White line detected - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`tracker.value()`:** Read line tracker pin level, returns 1 when black line is detected (HIGH), 0 when white line is detected (LOW).
- **`if trackerState == 1`:** Check if black line is detected; if detected, execute LED on operation.
- **`led.on()`:** Output HIGH, LED on.
- **`led.off()`:** Output LOW, LED off.
- **`print(...)`:** Print detection state and LED status to terminal.
- **`time.sleep_ms(100)`:** Wait 100 milliseconds before reading again to avoid reading too fast.
