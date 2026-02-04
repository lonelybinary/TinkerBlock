# Function

This module is a tilt sensor module that can detect the tilt state of the module. When the module tilts to a certain angle, it outputs a HIGH signal. Can be used to make tilt alarms, level detectors, and other applications.

# Appearance

| ![Front](images/TK62-F.png) | ![Back](images/TK62-B.png) | ![Side](images/TK62-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has a tilt detection element and a 4-pin header interface. Each pin can be identified by the silkscreen (text printed next to the pin).

# Pinout

- **GND** (negative): Like the negative terminal (-) of a battery, connect to the control board's GND
- **VCC** (positive): Like the positive terminal (+) of a battery, connect to the control board's 3.3V or 5V (this module supports both 3.3V and 5V)
- **NC** (no connection): No actual circuit connection, included for unified interface, can be left unconnected
- **SIGNAL** (signal output): Tilt detection output pin, connect to the control board's digital pin (e.g. Arduino D2 or Pico GPIO 0)
  - Outputs HIGH (HIGH/1) when tilt detected
  - Outputs LOW (LOW/0) when no tilt detected

# Features

- Tilt detection: Outputs HIGH when tilt detected
- Operating voltage: 3.3V or 5V
- High sensitivity: Can detect slight tilts

# Quick Wiring

1. GND → Control board GND
2. VCC → Control board 3.3V or 5V
3. SIGNAL → Control board digital pin (use the pin defined in your program)
