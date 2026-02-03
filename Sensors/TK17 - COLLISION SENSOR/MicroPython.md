# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK17 - COLLISION SENSOR module on a Raspberry Pi Pico 2 to detect collisions.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
COLLISION_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1         # Pico built-in LED pin (GPIO 25, or external LED)

# Create pin objects
collision = Pin(COLLISION_PIN, Pin.IN)   # Set collision pin as input (to read collision state)
led = Pin(LED_PIN, Pin.OUT)              # Set LED pin as output (to control LED on/off)

# Main loop: runs forever
while True:
    # Read collision sensor state
    collisionState = collision.value()   # Read collision pin level: 1 = collision (HIGH), 0 = no collision (LOW)
    
    # Control LED based on collision state
    if collisionState == 1:
        # Collision detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Collision detected!")    # Display message in terminal
    else:
        # No collision detected: turn LED off
        led.off()                # Output LOW, LED off
    
    # Delay 50 milliseconds to avoid reading too fast (give sensor stabilization time, prevent false triggers)
    time.sleep_ms(50)
```

## Effect

![Effect](images/TK17-pico.gif)


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
COLLISION_PIN = 0    # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 1         # Pico built-in LED pin (GPIO 25, or external LED)
```

- **`COLLISION_PIN = 0`:** GPIO number for collision SIGNAL. Change this if you use another pin.
- **`LED_PIN = 1`:** GPIO number for LED (Pico built-in LED is GPIO 25, or external LED).

**Lines 9–10: Create pin objects**

```python
collision = Pin(COLLISION_PIN, Pin.IN)   # Set collision pin as input (to read collision state)
led = Pin(LED_PIN, Pin.OUT)              # Set LED pin as output (to control LED on/off)
```

- **`Pin(COLLISION_PIN, Pin.IN)`:** Set collision pin as input to read collision state.
- **`Pin(LED_PIN, Pin.OUT)`:** Set LED pin as output to control LED on/off.

**Lines 13–25: Main loop**

```python
while True:
    # Read collision sensor state
    collisionState = collision.value()   # Read collision pin level: 1 = collision (HIGH), 0 = no collision (LOW)
    
    # Control LED based on collision state
    if collisionState == 1:
        # Collision detected: turn LED on and print message
        led.on()                 # Output HIGH, LED on
        print("Collision detected!")    # Display message in terminal
    else:
        # No collision detected: turn LED off
        led.off()                # Output LOW, LED off
    
    # Delay 50 milliseconds to avoid reading too fast (give sensor stabilization time, prevent false triggers)
    time.sleep_ms(50)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`collision.value()`:** Read collision pin level, returns 1 when collision is detected (HIGH), 0 when no collision (LOW).
- **`if collisionState == 1`:** Check if collision is detected; if detected, execute LED on operation.
- **`led.on()`:** Output HIGH, LED on.
- **`led.off()`:** Output LOW, LED off.
- **`print(...)`:** Print collision detection status to terminal.
- **`time.sleep_ms(50)`:** Wait 50 milliseconds before reading again to avoid reading too fast, give sensor stabilization time, prevent false triggers.
