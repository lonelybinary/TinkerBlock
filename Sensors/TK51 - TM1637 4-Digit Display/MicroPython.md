# Raspberry Pi Pico 2 Example

## Goal

This example shows how to use the TK51 - 4-DIGIT DISPLAY module on a Raspberry Pi Pico 2 to display numbers.

## Wiring

![Wiring diagram](images/wiring_diagram_pico2-1.png)

## Code

```python
from machine import Pin
import time

# Pin number: change these to match your wiring
CLK_PIN = 0   # GPIO connected to CLOCK (e.g. GPIO 0)
DIO_PIN = 1   # GPIO connected to DATA (e.g. GPIO 1)

# Import tm1637 library
try:
    from tm1637 import TM1637
    # Create TM1637 display object
    display = TM1637(CLK_PIN, DIO_PIN)
    display.brightness(7)  # Set brightness (0-7, 7 is brightest)
    HAS_LIB = True
    print("TM1637 driver loaded successfully")
except ImportError:
    print("Error: tm1637 library not found")
    print("Please copy tm1637.py file to Pico (same directory as main program)")
    HAS_LIB = False
except Exception as e:
    print(f"Error: Failed to initialize TM1637 - {e}")
    HAS_LIB = False

if HAS_LIB:
    print("4-digit display module program started")
    print("Cycling through 0-9 (all 4 digits display same number)")
    print()
    
    # Main loop: runs forever
    while True:
        # Cycle through 0-9 (all 4 digits display same number)
        for i in range(10):
            # Display number: 0 displays as 0000, 1 displays as 1111, 2 displays as 2222...9 displays as 9999
            display.number(i * 1111)
            print(f"Display number: {i}")
            time.sleep(1)  # Switch number every second
else:
    print("Program cannot run, please install tm1637.py driver file first")
```

## Effect

![Effect](images/TK51-pico.gif)


## Code Walkthrough

**Lines 1–2: Imports**

```python
from machine import Pin
import time
```

- **`machine.Pin`:** Used to control Pico GPIO pins.
- **`time`:** Provides `sleep()` and other time-related functions.

**Lines 5–6: Pin definition**

```python
CLK_PIN = 0   # GPIO connected to CLOCK (e.g. GPIO 0)
DIO_PIN = 1   # GPIO connected to DATA (e.g. GPIO 1)
```

- **`CLK_PIN = 0`:** GPIO number for CLOCK pin. Change this if you use another pin.
- **`DIO_PIN = 1`:** GPIO number for DATA pin. Change this if you use another pin.

**Lines 8–21: Library import and initialization**

```python
try:
    from tm1637 import TM1637
    # Create TM1637 display object
    display = TM1637(CLK_PIN, DIO_PIN)
    display.brightness(7)  # Set brightness (0-7, 7 is brightest)
    HAS_LIB = True
    print("TM1637 driver loaded successfully")
except ImportError:
    print("Error: tm1637 library not found")
    print("Please copy tm1637.py file to Pico (same directory as main program)")
    HAS_LIB = False
except Exception as e:
    print(f"Error: Failed to initialize TM1637 - {e}")
    HAS_LIB = False
```

- **`from tm1637 import TM1637`:** Import TM1637 library for controlling TM1637-driven displays.
- **`TM1637(CLK_PIN, DIO_PIN)`:** Create TM1637 display object using specified CLK and DIO pins.
- **`display.brightness(7)`:** Set brightness (0-7, 7 is brightest).
- **Error handling:** If library is not found or initialization fails, print error message and set `HAS_LIB = False`.

**Lines 23–35: Main loop**

```python
if HAS_LIB:
    print("4-digit display module program started")
    print("Cycling through 0-9 (all 4 digits display same number)")
    print()
    
    # Main loop: runs forever
    while True:
        # Cycle through 0-9 (all 4 digits display same number)
        for i in range(10):
            # Display number: 0 displays as 0000, 1 displays as 1111, 2 displays as 2222...9 displays as 9999
            display.number(i * 1111)
            print(f"Display number: {i}")
            time.sleep(1)  # Switch number every second
else:
    print("Program cannot run, please install tm1637.py driver file first")
```

- **`while True`:** Infinite loop; the program keeps running.
- **`for i in range(10)`:** Loop through 0-9, display one number per loop.
- **`display.number(i * 1111)`:** Display number on 4-digit display, `i * 1111` makes all 4 digits display the same number (e.g., 1111 displays as 1111, 2222 displays as 2222).
- **`print(f"...")`:** Print current displayed number to terminal.
- **`time.sleep(1)`:** Wait 1 second before switching to next number.
