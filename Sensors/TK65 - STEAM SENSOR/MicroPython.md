# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK65 - STEAM SENSOR module on a Raspberry Pi Pico 2 to read steam intensity.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Import required modules
from machine import Pin, ADC  # GPIO control and ADC
import time                   # For delay (time.sleep)

# Pin number: change this to match your wiring
STEAM_PIN = 26   # GPIO connected to SIGNAL (e.g. GPIO 26, must be ADC pin)

# Create ADC object
steam = ADC(Pin(STEAM_PIN))  # Set steam sensor pin as ADC mode (to read analog signal)

# Filtering and change detection variables
lastValue = -1  # Previous value
CHANGE_THRESHOLD = 100  # Change threshold, only output if change exceeds this value

print("Steam sensor program started")
print("Reading analog value, higher value indicates higher steam concentration")
print("Only output when value changes significantly (reduce noise interference)")

# Main loop: runs forever
while True:
    # Multiple samples and average to reduce noise
    sum_value = 0
    for i in range(5):
        sum_value += steam.read_u16()
        time.sleep_us(100)
    steamValue = sum_value // 5  # Calculate average
    
    # Only output when value changes significantly (reduce random output in stable state)
    if lastValue == -1:
        # First reading, output directly
        print(f"Steam sensor value: {steamValue}")
        lastValue = steamValue
    else:
        # Calculate change amount
        change = abs(steamValue - lastValue)
        if change >= CHANGE_THRESHOLD:
            print(f"Steam sensor value: {steamValue} (change: {change})")
            lastValue = steamValue
    
    # Delay 200 milliseconds to avoid output too fast
    time.sleep_ms(200)
```

## Effect

![Effect](images/TK65-pico.jpg)

![Effect](images/TK65-pico-uart.png)


## Code Walkthrough

**Lines 1–2: Imports**

```python
from machine import Pin, ADC  # GPIO control and ADC
import time                   # For delay (time.sleep)
```

- **`machine.Pin`:** Used to control Pico GPIO pins.
- **`machine.ADC`:** Used to read analog signals.
- **`time`:** Provides `sleep()` and other time-related functions.

**Line 5: Pin definition**

```python
STEAM_PIN = 26   # GPIO connected to SIGNAL (e.g. GPIO 26, must be ADC pin)
```

- **`STEAM_PIN`:** GPIO number for steam sensor SIGNAL (must be ADC pin). Change this if you use another pin.

**Line 8: Create ADC object**

```python
steam = ADC(Pin(STEAM_PIN))  # Set steam sensor pin as ADC mode (to read analog signal)
```

- **`ADC(Pin(STEAM_PIN))`:** Create ADC object for reading analog signals.

**Lines 11–12: Define variables**

```python
lastValue = -1  # Previous value
CHANGE_THRESHOLD = 100  # Change threshold, only output if change exceeds this value
```

- **`lastValue`:** Stores previous sensor reading, initial value is -1 (indicates first reading).
- **`CHANGE_THRESHOLD`:** Change threshold, only output when sensor value changes exceed 100, used to reduce noise interference.

**Lines 18–40: Main loop**

```python
while True:
    # Multiple samples and average to reduce noise
    sum_value = 0
    for i in range(5):
        sum_value += steam.read_u16()
        time.sleep_us(100)
    steamValue = sum_value // 5  # Calculate average
    
    # Only output when value changes significantly (reduce random output in stable state)
    if lastValue == -1:
        # First reading, output directly
        print(f"Steam sensor value: {steamValue}")
        lastValue = steamValue
    else:
        # Calculate change amount
        change = abs(steamValue - lastValue)
        if change >= CHANGE_THRESHOLD:
            print(f"Steam sensor value: {steamValue} (change: {change})")
            lastValue = steamValue
    
    # Delay 200 milliseconds to avoid output too fast
    time.sleep_ms(200)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`for i in range(5)`:** Loop 5 times for sampling, calculate average to reduce noise interference.
- **`steam.read_u16()`:** Read ADC analog value (0-65535).
- **`time.sleep_us(100)`:** Delay 100 microseconds between each sample to ensure stable sampling.
- **`sum_value // 5`:** Calculate average of 5 samples.
- **`abs(steamValue - lastValue)`:** Calculate absolute difference between current value and previous value.
- **`if change >= CHANGE_THRESHOLD`:** Only output when change exceeds threshold to avoid frequent output in stable state.
- **`print(f"...")`:** Print sensor value and change amount to terminal.
- **`time.sleep_ms(200)`:** Wait 200 milliseconds before reading again to control output frequency.
