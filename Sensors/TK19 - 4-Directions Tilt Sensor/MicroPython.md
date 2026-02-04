# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK19-4-DIRECTIONs TIL SENSOR module on a Raspberry Pi Pico 2 to detect tilt in four directions.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

- **VCC** → Raspberry Pi Pico 2 3.3V or 5V
- **GND** → Raspberry Pi Pico 2 GND
- **A** → Raspberry Pi Pico 2 GPIO 0 (or the pin you set as `A_PIN` in code)
- **B** → Raspberry Pi Pico 2 GPIO 1 (or the pin you set as `B_PIN` in code)
- **C** → Raspberry Pi Pico 2 GPIO 2 (or the pin you set as `C_PIN` in code)
- **D** → Raspberry Pi Pico 2 GPIO 3 (or the pin you set as `D_PIN` in code)

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
A_PIN = 0      # GPIO connected to A (as common, output LOW)
B_PIN = 1      # GPIO connected to B (INPUT_PULLUP, detect direction B)
C_PIN = 2      # GPIO connected to C (INPUT_PULLUP, detect direction C)
D_PIN = 3      # GPIO connected to D (INPUT_PULLUP, detect direction D)

# Create pin objects
a = Pin(A_PIN, Pin.OUT)              # Set A pin as output (as common)
b = Pin(B_PIN, Pin.IN, Pin.PULL_UP)  # Set B pin as INPUT_PULLUP (detect direction B tilt)
c = Pin(C_PIN, Pin.IN, Pin.PULL_UP)  # Set C pin as INPUT_PULLUP (detect direction C tilt)
d = Pin(D_PIN, Pin.IN, Pin.PULL_UP)  # Set D pin as INPUT_PULLUP (detect direction D tilt)

# Set A pin to LOW (as common/ground)
a.off()  # Output LOW

print("4-direction tilt sensor program started")
print("Detecting tilt status in four directions")
print("A pin as common (LOW), B/C/D pins detect tilt (0=tilt)")

# Main loop: runs forever
while True:
    # Read tilt status of three directions
    # When B/C/D pins read 0 (LOW), it means tilt detected in corresponding direction
    b_state = b.value()   # Read B pin: 0 = direction B tilt (LOW), 1 = no tilt (HIGH)
    c_state = c.value()   # Read C pin: 0 = direction C tilt (LOW), 1 = no tilt (HIGH)
    d_state = d.value()   # Read D pin: 0 = direction D tilt (LOW), 1 = no tilt (HIGH)
    
    # Detect and output tilt direction
    tilted = False  # Flag to mark if tilt is detected
    
    if b_state == 0:
        print("Detected: Direction B tilt")
        tilted = True
    
    if c_state == 0:
        print("Detected: Direction C tilt")
        tilted = True
    
    if d_state == 0:
        print("Detected: Direction D tilt")
        tilted = True
    
    # If no direction is tilted, show level status
    if not tilted:
        print("Level")
    
    # Display all pin states (for debugging)
    print(f"State: B={b_state}(0=tilt), C={c_state}(0=tilt), D={d_state}(0=tilt)")
    print("---")
    
    # Delay 100 milliseconds to avoid output too fast
    time.sleep_ms(100)
```

## Effect

![Effect](images/TK19-pico.gif)


## Code Walkthrough

**Lines 1–2: Imports**

```python
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)
```

- **`machine.Pin`:** Used to control Pico GPIO pins.
- **`time`:** Provides `sleep_ms()` and other time-related functions.

**Lines 5–8: Pin definition**

```python
A_PIN = 0      # GPIO connected to A (as common, output LOW)
B_PIN = 1      # GPIO connected to B (INPUT_PULLUP, detect direction B)
C_PIN = 2      # GPIO connected to C (INPUT_PULLUP, detect direction C)
D_PIN = 3      # GPIO connected to D (INPUT_PULLUP, detect direction D)
```

- **`A_PIN = 0`:** GPIO number for A pin, as common output LOW. Change this if you use another pin.
- **`B_PIN = 1`、`C_PIN = 2`、`D_PIN = 3`:** GPIO numbers for B/C/D pins, used to detect tilt. Change these if you use other pins.

**Lines 11–14: Create pin objects**

```python
a = Pin(A_PIN, Pin.OUT)              # Set A pin as output (as common)
b = Pin(B_PIN, Pin.IN, Pin.PULL_UP)  # Set B pin as INPUT_PULLUP (detect direction B tilt)
c = Pin(C_PIN, Pin.IN, Pin.PULL_UP)  # Set C pin as INPUT_PULLUP (detect direction C tilt)
d = Pin(D_PIN, Pin.IN, Pin.PULL_UP)  # Set D pin as INPUT_PULLUP (detect direction D tilt)
```

- **`Pin(A_PIN, Pin.OUT)`:** Set A pin as output, as common.
- **`Pin(B_PIN, Pin.IN, Pin.PULL_UP)`:** Set B/C/D pins as INPUT_PULLUP, used to detect tilt.

**Line 17: Set common pin**

```python
a.off()  # Output LOW
```

- **`a.off()`:** Output LOW from A pin, as common/ground.

**Lines 20–22: Print start message**

```python
print("4-direction tilt sensor program started")
print("Detecting tilt status in four directions")
print("A pin as common (LOW), B/C/D pins detect tilt (0=tilt)")
```

- **`print(...)`:** Print program start message and instructions to terminal.

**Lines 25–47: Main loop**

```python
while True:
    # Read tilt status of three directions
    # When B/C/D pins read 0 (LOW), it means tilt detected in corresponding direction
    b_state = b.value()   # Read B pin: 0 = direction B tilt (LOW), 1 = no tilt (HIGH)
    c_state = c.value()   # Read C pin: 0 = direction C tilt (LOW), 1 = no tilt (HIGH)
    d_state = d.value()   # Read D pin: 0 = direction D tilt (LOW), 1 = no tilt (HIGH)
    
    # Detect and output tilt direction
    tilted = False  # Flag to mark if tilt is detected
    
    if b_state == 0:
        print("Detected: Direction B tilt")
        tilted = True
    
    if c_state == 0:
        print("Detected: Direction C tilt")
        tilted = True
    
    if d_state == 0:
        print("Detected: Direction D tilt")
        tilted = True
    
    # If no direction is tilted, show level status
    if not tilted:
        print("Level")
    
    # Display all pin states (for debugging)
    print(f"State: B={b_state}(0=tilt), C={c_state}(0=tilt), D={d_state}(0=tilt)")
    print("---")
    
    # Delay 100 milliseconds to avoid output too fast
    time.sleep_ms(100)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`b.value()`、`c.value()`、`d.value()`:** Read B/C/D pin levels, returns 0 when tilt is detected (LOW), 1 when no tilt (HIGH).
- **`if b_state == 0`:** Check if direction B tilt is detected.
- **`tilted = True`:** Mark that tilt is detected.
- **`if not tilted`:** If no direction is tilted, show level status.
- **`print(f"State: ...")`:** Use f-string to format and print pin states.
- **`time.sleep_ms(100)`:** Wait 100 milliseconds before reading again to avoid output too fast.
