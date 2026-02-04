# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK64 - INRARED RECEIVER module on a Raspberry Pi Pico 2 to receive infrared signals.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Note: This program requires micropython-ir library
# Installation: Copy ir.py file to Pico

# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change this to match your wiring
IR_RX_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)

# Create pin object
ir_rx = Pin(IR_RX_PIN, Pin.IN)  # Set infrared receiver pin as input mode

print("Infrared receiver program started")
print("Waiting to receive infrared signal...")

# Variables
last_state = 1  # Previous pin state (default HIGH)

# Main loop: runs forever
while True:
    # Read pin state
    current_state = ir_rx.value()
    
    # Detect signal change (HIGH to LOW indicates signal received)
    if current_state == 0 and last_state == 1:
        print("Infrared signal detected")
        # Note: Complete decoding requires micropython-ir library
        # This is just simple signal change detection
    
    # Update previous state
    last_state = current_state
    
    time.sleep(0.01)  # Brief delay
```

## Effect

![Effect](images/TK64-pico.gif)


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
IR_RX_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)
last_state = 1  # Previous pin state (default HIGH)
```

- **`IR_RX_PIN = 0`:** GPIO number for infrared receiver SIGNAL. Change this if you use another pin.
- **`last_state = 1`:** Previous pin state (default HIGH).

**Lines 19–33: Main loop**

```python
while True:
    # Read infrared receiver state
    current_state = ir_rx.value()  # Read pin level: 0=signal received (LOW), 1=no signal (HIGH)
    
    # Detect falling edge (HIGH to LOW), indicates infrared signal received
    if current_state == 0 and last_state == 1:
        print("Infrared signal detected")
        last_state = current_state
        time.sleep(0.01)  # Brief delay to avoid repeated detection
    else:
        last_state = current_state
    
    time.sleep(0.01)  # Brief delay to avoid detection too fast
```

- **`while True`:** Infinite loop; the program keeps running.
- **`ir_rx.value()`:** Read infrared receiver pin level, returns 0 when signal received (LOW), 1 when no signal (HIGH).
- **`if current_state == 0 and last_state == 1`:** Detect falling edge (HIGH to LOW), indicates infrared signal received.
- **`last_state = current_state`:** Update previous state for next detection.
- **`print(...)`:** Print infrared signal reception message to terminal.
- **`time.sleep(0.01)`:** Wait 10 milliseconds before reading again to avoid detection too fast and repeated detection.
