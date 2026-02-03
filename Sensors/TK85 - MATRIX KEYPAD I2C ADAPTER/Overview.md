# Function

This module is a matrix keypad adapter module that converts matrix keypads to I2C interface. By reading key states through I2C interface, it simplifies wiring and saves control board pins. Can be used to make password locks, calculators, remote controls, and other applications.

# Appearance

| ![Front](images/TK85-F.png) | ![Back](images/TK85-B.png) | ![Side](images/TK85-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has a matrix keypad interface and a 4-pin header interface. Each pin can be identified by the silkscreen (text printed next to the pin).

# Pinout

- **GND** (negative): Like the negative terminal (-) of a battery, connect to the control board's GND
- **VCC** (positive): Like the positive terminal (+) of a battery, connect to the control board's 3.3V or 5V (this module supports both 3.3V and 5V)
- **SDA** (data line): I2C data line, connect to the control board's SDA pin (e.g. Arduino A4 or Pico GPIO 0)
- **SCL** (clock line): I2C clock line, connect to the control board's SCL pin (e.g. Arduino A5 or Pico GPIO 1)

# Features

- I2C interface: Uses I2C communication protocol, only needs 2 wires
- Saves pins: Does not require multiple digital pins
- Operating voltage: 3.3V or 5V
- Supports multiple matrix keypads: 4x4, 3x4, etc.

# Quick Wiring

1. GND → Control board GND
2. VCC → Control board 3.3V or 5V
3. SDA → Control board SDA pin
4. SCL → Control board SCL pin
