# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK03 - TRAFFIC LIGHT module on a Raspberry Pi Pico 2 to simulate traffic light behavior.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

- **GND** → Raspberry Pi Pico 2 GND
- **RED** → Raspberry Pi Pico 2 GPIO 0 (or the pin you set as `RED_PIN` in code)
- **YELLOW** → Raspberry Pi Pico 2 GPIO 1 (or the pin you set as `YELLOW_PIN` in code)
- **GREEN** → Raspberry Pi Pico 2 GPIO 2 (or the pin you set as `GREEN_PIN` in code)
- **NC** → Leave unconnected

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change this to match your wiring
RED_PIN = 0     # RED pin connected to GPIO (e.g. GPIO 0)
YELLOW_PIN = 1  # YELLOW pin connected to GPIO (e.g. GPIO 1)
GREEN_PIN = 2   # GREEN pin connected to GPIO (e.g. GPIO 2)

# Create pin objects
red = Pin(RED_PIN, Pin.OUT)      # Set RED pin as output (to control LED on/off)
yellow = Pin(YELLOW_PIN, Pin.OUT)  # Set YELLOW pin as output
green = Pin(GREEN_PIN, Pin.OUT)    # Set GREEN pin as output

# Initialize: all LEDs off
red.off()
yellow.off()
green.off()

print("Traffic light program started")

# Main loop: runs forever
while True:
    # Red light on (5 seconds)
    red.on()
    yellow.off()
    green.off()
    print("Red light on - stop")
    time.sleep(5)
    
    # Green light on (5 seconds)
    red.off()
    yellow.off()
    green.on()
    print("Green light on - go")
    time.sleep(5)
    
    # Yellow light on (2 seconds)
    red.off()
    yellow.on()
    green.off()
    print("Yellow light on - warning")
    time.sleep(2)
    
    # Loop back to red light
```

## Effect

![Effect](images/TK03-pico.gif)


## Code Walkthrough

**Lines 1–2: Imports**

```python
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)
```

- **`machine.Pin`:** Used to control Pico GPIO pins.
- **`time`:** Provides `sleep()` and other time-related functions.

**Lines 5–7: Pin definition**

```python
RED_PIN = 0     # RED pin connected to GPIO (e.g. GPIO 0)
YELLOW_PIN = 1  # YELLOW pin connected to GPIO (e.g. GPIO 1)
GREEN_PIN = 2   # GREEN pin connected to GPIO (e.g. GPIO 2)
```

- **`RED_PIN`:** GPIO number for RED LED. Change this if you use another pin.
- **`YELLOW_PIN`:** GPIO number for YELLOW LED. Change this if you use another pin.
- **`GREEN_PIN`:** GPIO number for GREEN LED. Change this if you use another pin.

**Lines 10–12: Create pin objects**

```python
red = Pin(RED_PIN, Pin.OUT)      # Set RED pin as output (to control LED on/off)
yellow = Pin(YELLOW_PIN, Pin.OUT)  # Set YELLOW pin as output
green = Pin(GREEN_PIN, Pin.OUT)    # Set GREEN pin as output
```

- **`Pin(RED_PIN, Pin.OUT)`:** Set red LED pin as output to control LED on/off.
- **`Pin(YELLOW_PIN, Pin.OUT)`:** Set yellow LED pin as output.
- **`Pin(GREEN_PIN, Pin.OUT)`:** Set green LED pin as output.

**Lines 15–20: Initialization**

```python
# Initialize: all LEDs off
red.off()
yellow.off()
green.off()

print("Traffic light program started")
```

- **`red.off()`, `yellow.off()`, `green.off()`:** Turn off all LEDs during initialization, ensuring the program starts from a known state.
- **`print(...)`:** Print program start message to terminal.

**Lines 22–36: Main loop**

```python
while True:
    # Red light on (5 seconds)
    red.on()
    yellow.off()
    green.off()
    print("Red light on - stop")
    time.sleep(5)
    
    # Green light on (5 seconds)
    red.off()
    yellow.off()
    green.on()
    print("Green light on - go")
    time.sleep(5)
    
    # Yellow light on (2 seconds)
    red.off()
    yellow.on()
    green.off()
    print("Yellow light on - warning")
    time.sleep(2)
```

- **`while True`:** Infinite loop; the program keeps running.
- **Red light phase:** `red.on()` turns on red light, turns off other lights, waits 5 seconds, indicates stop.
- **Green light phase:** `green.on()` turns on green light, turns off other lights, waits 5 seconds, indicates go.
- **Yellow light phase:** `yellow.on()` turns on yellow light, turns off other lights, waits 2 seconds, indicates warning.
- **`print(...)`:** Print current traffic light status to terminal.
- **`time.sleep(5)` and `time.sleep(2)`:** Control the duration of each traffic light phase.
