# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK30 - VIBRATION MOTOR module on a Raspberry Pi Pico 2 to control vibration.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change this to match your wiring
MOTOR_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)

# Create pin object
motor = Pin(MOTOR_PIN, Pin.OUT)  # Set motor pin as output (to control motor vibration)

print("Vibration motor program started")

# Main loop: runs forever
while True:
    # Vibrate for 0.5 seconds
    motor.on()                 # Output HIGH to start vibration
    print("Motor vibrating...")
    time.sleep(0.5)            # Wait 0.5 seconds
    
    # Stop for 0.5 seconds
    motor.off()                # Output LOW to stop vibration
    print("Motor stopped")
    time.sleep(0.5)            # Wait 0.5 seconds
```

## Effect

![Effect](images/TK30-pico.gif)


## Code Walkthrough

**Lines 1–2: Imports**

```python
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)
```

- **`machine.Pin`:** Used to control Pico GPIO pins.
- **`time`:** Provides `sleep()` and other time-related functions.

**Line 5: Pin definition**

```python
MOTOR_PIN = 0  # GPIO connected to SIGNAL (e.g. GPIO 0)
```

- **`MOTOR_PIN = 0`:** GPIO number for vibration motor SIGNAL. Change this if you use another pin.

**Line 8: Create pin object**

```python
motor = Pin(MOTOR_PIN, Pin.OUT)  # Set motor pin as output (to control motor vibration)
```

- **`Pin(MOTOR_PIN, Pin.OUT)`:** Set motor pin as output to control motor vibration.

**Lines 13–22: Main loop**

```python
while True:
    # Vibrate for 0.5 seconds
    motor.on()                 # Output HIGH to start vibration
    print("Motor vibrating...")
    time.sleep(0.5)            # Wait 0.5 seconds
    
    # Stop for 0.5 seconds
    motor.off()                # Output LOW to stop vibration
    print("Motor stopped")
    time.sleep(0.5)            # Wait 0.5 seconds
```

- **`while True`:** Infinite loop; the program keeps running.
- **`motor.on()`:** Output HIGH to start vibration motor.
- **`motor.off()`:** Output LOW to stop vibration motor.
- **`print(...)`:** Print motor status to terminal.
- **`time.sleep(0.5)`:** Wait 0.5 seconds to control vibration and stop duration.
