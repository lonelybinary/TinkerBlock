# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK15 - IR RECEIVER module on a Raspberry Pi Pico 2 to detect infrared signals.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Import required modules
from machine import Pin  # GPIO control
import time              # For delay (time.sleep)

# Pin number: change these to match your wiring
IR_PIN = 0     # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 25   # Pico built-in LED pin (GPIO 25, or external LED)

# Create pin objects
ir = Pin(IR_PIN, Pin.IN)    # Set IR pin as input (to read IR signal)
led = Pin(LED_PIN, Pin.OUT)  # Set LED pin as output (to control LED on/off)

# Main loop: runs forever
while True:
    # Read IR receiver state
    irState = ir.value()   # Read IR pin level: 0 = signal received (LOW), 1 = no signal (HIGH)
    
    # Control LED based on IR state
    if irState == 0:
        # IR signal received: turn LED on and print message
        led.on()                     # Output HIGH, LED on
        print("IR signal received!")    # Display message in terminal
    else:
        # No signal received: turn LED off
        led.off()                    # Output LOW, LED off
    
    # Delay 10 milliseconds to avoid reading too fast
    time.sleep_ms(10)
```

## Effect

![Effect](images/TK15-pico.gif)


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
IR_PIN = 0     # GPIO connected to SIGNAL (e.g. GPIO 0)
LED_PIN = 25   # Pico built-in LED pin (GPIO 25, or external LED)
```

- **`IR_PIN = 0`:** GPIO number for IR SIGNAL. Change this if you use another pin.
- **`LED_PIN = 25`:** GPIO number for LED (Pico built-in LED is GPIO 25, or external LED).

**Lines 13–28: Main loop**

```python
while True:
    # Read IR receiver state
    irState = ir.value()   # Read IR pin level: 0 = signal received (LOW), 1 = no signal (HIGH)
    
    # Control LED based on IR state
    if irState == 0:
        # IR signal received: turn LED on and print message
        led.on()                     # Output HIGH, LED on
        print("IR signal received!")    # Display message in terminal
    else:
        # No signal received: turn LED off
        led.off()                    # Output LOW, LED off
    
    # Delay 10 milliseconds to avoid reading too fast
    time.sleep_ms(10)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`ir.value()`:** Read IR pin level, returns 0 when signal is received (LOW), 1 when no signal (HIGH).
- **`if irState == 0`:** Check if IR signal is received; if received, execute LED on operation.
- **`led.on()`:** Output HIGH, LED on.
- **`led.off()`:** Output LOW, LED off.
- **`print(...)`:** Print IR signal reception status to terminal.
- **`time.sleep_ms(10)`:** Wait 10 milliseconds before reading again to avoid reading too fast.
