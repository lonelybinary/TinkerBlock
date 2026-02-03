# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK41 - MAGNETIC SWITCH module on a Raspberry Pi Pico 2 to detect magnetic fields.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
REED_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1     # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)

# Create pin objects
reed = Pin(REED_PIN, Pin.IN)   # Set magnetic switch pin as input (to read detection state)
led = Pin(LED_PIN, Pin.OUT)    # Set LED pin as output (to control LED on/off)

print("Magnetic switch program started")
print("LED on when magnetic field detected, LED off when no magnetic field")

# Main loop: runs forever
while True:
    # Read magnetic switch state
    reedState = reed.value()   # Read switch pin level: 1 = magnetic field detected (HIGH), 0 = no magnetic field (LOW)
    
    # Control LED based on detection state
    if reedState == 1:
        # Magnetic field detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Magnetic field detected - LED on")
    else:
        # No magnetic field detected: turn LED off
        led.off()                # Output LOW, LED off
        print("No magnetic field detected - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

## Effect

![Effect](images/TK41-pico.gif)


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
REED_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1     # LED pin (GPIO 1, or external LED, Pico built-in LED is GPIO 25)
```

- **`REED_PIN = 0`:** GPIO number for magnetic switch SIGNAL. Change this if you use another pin.
- **`LED_PIN = 1`:** GPIO number for LED (GPIO 1, or external LED, Pico built-in LED is GPIO 25).

**Lines 9–10: Create pin objects**

```python
reed = Pin(REED_PIN, Pin.IN)   # Set magnetic switch pin as input (to read detection state)
led = Pin(LED_PIN, Pin.OUT)    # Set LED pin as output (to control LED on/off)
```

- **`Pin(REED_PIN, Pin.IN)`:** Set magnetic switch pin as input to read detection state.
- **`Pin(LED_PIN, Pin.OUT)`:** Set LED pin as output to control LED on/off.

**Lines 13–14: Print start message**

```python
print("Magnetic switch program started")
print("LED on when magnetic field detected, LED off when no magnetic field")
```

- **`print(...)`:** Print program start message and instructions to terminal.

**Lines 17–31: Main loop**

```python
while True:
    # Read magnetic switch state
    reedState = reed.value()   # Read switch pin level: 1 = magnetic field detected (HIGH), 0 = no magnetic field (LOW)
    
    # Control LED based on detection state
    if reedState == 1:
        # Magnetic field detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Magnetic field detected - LED on")
    else:
        # No magnetic field detected: turn LED off
        led.off()                # Output LOW, LED off
        print("No magnetic field detected - LED off")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`reed.value()`:** Read magnetic switch pin level, returns 1 when magnetic field is detected (HIGH), 0 when no magnetic field (LOW).
- **`if reedState == 1`:** Check if magnetic field is detected; if detected, execute LED on operation.
- **`led.on()`:** Output HIGH, LED on.
- **`led.off()`:** Output LOW, LED off.
- **`print(...)`:** Print detection state and LED status to terminal.
- **`time.sleep_ms(100)`:** Wait 100 milliseconds before reading again to avoid reading too fast.
