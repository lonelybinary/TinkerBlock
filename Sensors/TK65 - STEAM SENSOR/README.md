# Function

This module is a steam sensor module that can detect water vapor or humidity in the environment. When water vapor is detected, the module outputs a HIGH signal. Can be used to make humidity alarms, steam detectors, and other applications.

# Appearance

| ![Front](images/TK65-F.png) | ![Back](images/TK65-B.png) | ![Side](images/TK65-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has a steam sensor element and a 4-pin header interface. Each pin can be identified by the silkscreen (text printed next to the pin).

# Pinout

- **GND** (negative): Like the negative terminal (-) of a battery, connect to the control board's GND
- **VCC** (positive): Like the positive terminal (+) of a battery, connect to the control board's 3.3V or 5V (this module supports both 3.3V and 5V)
- **NC** (no connection): No actual circuit connection, included for unified interface, can be left unconnected
- **SIGNAL** (signal output): Steam detection output pin, connect to the control board's digital pin (e.g. Arduino D2 or Pico GPIO 0)
  - Outputs HIGH (HIGH/1) when steam detected
  - Outputs LOW (LOW/0) when no steam detected

# Features

- Steam detection: Outputs HIGH when water vapor detected
- Operating voltage: 3.3V or 5V
- Adjustable sensitivity: Module has sensitivity adjustment potentiometer

# Quick Wiring

1. GND → Control board GND
2. VCC → Control board 3.3V or 5V
3. SIGNAL → Control board digital pin (use the pin defined in your program)
