# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK20 - AMBIENT LIGHT module on a Raspberry Pi Pico 2 to detect ambient light intensity.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
# Import required modules
from machine import Pin, ADC  # GPIO control and analog input
import time                   # For delay (time.sleep)

# Pin number: change this to match your wiring
LIGHT_PIN = 26  # GPIO connected to SIGNAL (e.g. GPIO 26, must be ADC-capable pin)

# Create analog input object
light = ADC(Pin(LIGHT_PIN))  # Create ADC object to read analog value

# Main loop: runs forever
while True:
    # Read ambient light sensor analog value (0-65535)
    lightValue = light.read_u16()  # Read analog value: 0 = darkest, 65535 = brightest
    
    # Convert analog value to voltage (0-3.3V)
    voltage = lightValue * (3.3 / 65535.0)
    
    # Display values in terminal
    print("Light value: {} | Voltage: {:.2f}V".format(lightValue, voltage))
    
    # Judge light intensity
    if lightValue > 30000:
        print("Bright")
    elif lightValue > 10000:
        print("Moderate")
    else:
        print("Dark")
    
    # Delay 100 milliseconds to avoid printing too fast
    time.sleep_ms(100)
```

## Effect

![Effect](images/TK20-pico.jpg)

![Effect](images/TK20-pico1.jpg)


## Code Walkthrough

**Lines 1–2: Imports**

```python
from machine import Pin, ADC  # GPIO control and analog input
import time                   # For delay (time.sleep)
```

- **`machine.Pin`:** Used to control Pico GPIO pins.
- **`machine.ADC`:** Used to read analog signals.
- **`time`:** Provides `sleep()` and other time-related functions.

**Line 5: Pin definition**

```python
LIGHT_PIN = 26  # GPIO connected to SIGNAL (e.g. GPIO 26, must be ADC-capable pin)
```

- **`LIGHT_PIN = 26`:** GPIO number for ambient light sensor SIGNAL (must be ADC-capable pin). Change this if you use another pin.

**Line 8: Create analog input object**

```python
light = ADC(Pin(LIGHT_PIN))  # Create ADC object to read analog value
```

- **`ADC(Pin(LIGHT_PIN))`:** Create ADC object to read analog value.

**Lines 11–27: Main loop**

```python
while True:
    # Read ambient light sensor analog value (0-65535)
    lightValue = light.read_u16()  # Read analog value: 0 = darkest, 65535 = brightest
    
    # Convert analog value to voltage (0-3.3V)
    voltage = lightValue * (3.3 / 65535.0)
    
    # Display values in terminal
    print("Light value: {} | Voltage: {:.2f}V".format(lightValue, voltage))
    
    # Judge light intensity
    if lightValue > 30000:
        print("Bright")
    elif lightValue > 10000:
        print("Moderate")
    else:
        print("Dark")
    
    # Delay 100 milliseconds to avoid printing too fast
    time.sleep_ms(100)
```

- **`while True`:** Infinite loop; the program keeps running.
- **`light.read_u16()`:** Read ADC analog value (0-65535), 0 means darkest, 65535 means brightest.
- **`lightValue * (3.3 / 65535.0)`:** Convert analog value (0-65535) to voltage value (0-3.3V).
- **`if lightValue > 30000`:** Judge light intensity; if greater than 30000, output "Bright".
- **`elif lightValue > 10000`:** If greater than 10000, output "Moderate".
- **`else`:** Otherwise output "Dark".
- **`print(...)`:** Print light value, voltage value, and status to terminal.
- **`time.sleep_ms(100)`:** Wait 100 milliseconds before reading again to avoid printing too fast.
