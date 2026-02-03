# Function

This module is an LM75 temperature sensor module that can measure ambient temperature. It communicates with the control board through the I2C interface, allowing precise temperature readings. Can be used to make temperature monitoring systems, temperature alarms, and other applications.

# Appearance

| ![Front](images/TK42-F.png) | ![Back](images/TK42-B.png) | ![Side](images/TK42-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has a temperature sensor chip and a 4-pin header interface. Each pin can be identified by the silkscreen (text printed next to the pin).

# Pinout

- **GND** (negative): Like the negative terminal (-) of a battery, connect to the control board's GND
- **VCC** (positive): Like the positive terminal (+) of a battery, connect to the control board's 3.3V or 5V (this module supports both 3.3V and 5V)
- **SDA** (data line): I2C data line, connect to the control board's SDA pin (Arduino Uno A4 or Pico GPIO 0)
- **SCL** (clock line): I2C clock line, connect to the control board's SCL pin (Arduino Uno A5 or Pico GPIO 1)

# Features

- Temperature detection: Can measure ambient temperature (-55°C to +125°C)
- I2C interface: Uses I2C communication protocol
- Operating voltage: 3.3V or 5V
- High accuracy: High temperature measurement accuracy

# Quick Wiring

1. GND → Control board GND
2. VCC → Control board 3.3V or 5V
3. SDA → Control board SDA pin
4. SCL → Control board SCL pin
