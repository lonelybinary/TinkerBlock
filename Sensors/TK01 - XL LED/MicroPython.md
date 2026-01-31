# Raspberry Pi Pico 2 Example

## Goal

This example shows how to blink the TK01-XL LED on a Raspberry Pi Pico 2 and covers GPIO output, loops, delay, and print in MicroPython.

## Wiring

- **GND** → Raspberry Pi Pico 2 GND
- **SIGNAL** → Raspberry Pi Pico 2 GPIO 0 (or the pin you set as `LED_PIN` in code)
- **NC** → Leave unconnected

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change this to match your wiring
LED_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)

# Create pin object
led = Pin(LED_PIN, Pin.OUT)  # Set pin as output (to control LED on/off)

# Main loop: runs forever
while True:
    # Blink: turn LED on
    led.on()                 # Output HIGH, LED on
    print("LED on")          # Print to terminal
    time.sleep(1)             # Wait 1 second

    led.off()                # Output LOW, LED off
    print("LED off")         # Print to terminal
    time.sleep(1)             # Wait 1 second
```

# Code Walkthrough

**Lines 1–14: Docstring**

- Describes function, wiring, and usage. Does not affect execution.

**Lines 16–17: Imports**

```python
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)
```

- **`machine.Pin`:** Used to control Pico GPIO pins.
- **`time`:** Provides `sleep()` and other time-related functions.

**Lines 19–23: Pin definition and object**

```python
LED_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)
led = Pin(LED_PIN, Pin.OUT)  # Set pin as output
```

- **`LED_PIN = 0`:** GPIO number for SIGNAL. Change this if you use another pin.
- **`Pin(LED_PIN, Pin.OUT)`:** Set the pin as output to control the LED.

**Lines 25–34: Main loop**

```python
while True:
    led.on()
    print("LED on")
    time.sleep(1)

    led.off()
    print("LED off")
    time.sleep(1)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`led.on()`:** Output HIGH, LED on.
- **`led.off()`:** Output LOW, LED off.
- **`time.sleep(1)`:** Delay 1 second.
