# Function

This module is an EEPROM module that can store data, and the data will not be lost even after power is turned off. It communicates with the control board through the I2C interface, allowing read and write operations. Can be used to store configuration information, counter values, user settings, and other data.

# Appearance

| ![Front](images/TK31-F.png) | ![Back](images/TK31-B.png) | ![Side](images/TK31-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has an EEPROM chip and a 4-pin header interface. Each pin can be identified by the silkscreen (text printed next to the pin).

# Pinout

- **GND** (negative): Like the negative terminal (-) of a battery, connect to the control board's GND
- **VCC** (positive): Like the positive terminal (+) of a battery, connect to the control board's 3.3V or 5V (this module supports both 3.3V and 5V)
- **SDA** (data line): I2C data line, connect to the control board's SDA pin (Arduino Uno A4 or Pico GPIO 0)
- **SCL** (clock line): I2C clock line, connect to the control board's SCL pin (Arduino Uno A5 or Pico GPIO 1)

# Features

- Data storage: Can store data, data persists after power loss
- I2C interface: Uses I2C protocol for communication
- Operating voltage: 3.3V or 5V
- Suitable for storing configuration information, counter values, and other data

# Quick Wiring

1. GND → Control board GND
2. VCC → Control board 3.3V or 5V
3. SDA → Control board SDA pin
4. SCL → Control board SCL pin
