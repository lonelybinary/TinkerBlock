# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK70 - LINEAR HALL EFFECT SENSOR module on a Raspberry Pi Pico 2 to read magnetic field strength.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Import required modules
from machine import Pin, ADC  # GPIO control and ADC
import time                   # For delay (time.sleep)

# Pin number: change this to match your wiring
HALL_PIN = 26  # GPIO connected to SIGNAL (e.g. GPIO 26, must be ADC pin)

# Create ADC object
hall = ADC(Pin(HALL_PIN))  # Set Hall sensor pin as ADC mode (to read analog signal)

print("Linear Hall sensor program started")
print("Reading magnetic field strength value and output via serial")

# Main loop: runs forever
while True:
    # Read Hall sensor analog value (0-65535)
    sensor_value = hall.read_u16()  # Read sensor pin analog value: 0=no magnetic field, 65535=strong magnetic field
    
    # Convert analog value to voltage value (0-3.3V)
    voltage = sensor_value * (3.3 / 65535.0)
    
    # Output strength value
    print(f"Magnetic field strength: {sensor_value} | Voltage: {voltage:.3f}V")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

## Effect

![Effect](images/TK70-pico.gif)

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
HALL_PIN = 26  # GPIO connected to SIGNAL (e.g. GPIO 26, must be ADC pin)
```

- **`HALL_PIN`:** GPIO number for linear Hall sensor SIGNAL (must be ADC pin). Change this if you use another pin.

**Line 8: Create ADC object**

```python
hall = ADC(Pin(HALL_PIN))  # Set Hall sensor pin as ADC mode (to read analog signal)
```

- **`ADC(Pin(HALL_PIN))`:** Create ADC object for reading analog signals.

**Lines 13–25: Main loop**

```python
while True:
    # Read Hall sensor analog value (0-65535)
    sensor_value = hall.read_u16()  # Read sensor pin analog value: 0=no magnetic field, 65535=strong magnetic field
    
    # Convert analog value to voltage value (0-3.3V)
    voltage = sensor_value * (3.3 / 65535.0)
    
    # Output strength value
    print(f"Magnetic field strength: {sensor_value} | Voltage: {voltage:.3f}V")
    
    # Delay 100 milliseconds to avoid reading too fast
    time.sleep_ms(100)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`hall.read_u16()`:** Read ADC analog value (0-65535), 0 means no magnetic field, 65535 means strong magnetic field.
- **`sensor_value * (3.3 / 65535.0)`:** Convert analog value (0-65535) to voltage value (0-3.3V).
- **`print(f"...")`:** Print magnetic field strength and voltage value to terminal.
- **`time.sleep_ms(100)`:** Wait 100 milliseconds before reading again to avoid reading too fast.
