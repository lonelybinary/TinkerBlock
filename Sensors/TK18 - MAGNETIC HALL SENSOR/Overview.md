# Function

This module is a magnetic Hall sensor module that can detect magnetic field strength. When a magnetic field is detected (such as when a magnet approaches), it outputs HIGH; when no magnetic field is detected, it outputs LOW. Suitable for making magnetic detection, position detection, speed detection, and other applications.

# Appearance

| ![Front](images/TK18-F.png) | ![Back](images/TK18-B.png) | ![Side](images/TK18-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has a Hall sensor chip and a 4-pin header interface. Each pin can be identified by the silkscreen (text printed next to the pin).

# Pinout

- **GND** (negative): Like the negative terminal (-) of a battery, connect to the control board's GND
- **VCC** (positive): Like the positive terminal (+) of a battery, connect to the control board's 3.3V or 5V (this module supports both 3.3V and 5V)
- **NC** (no connection): No actual circuit connection, included for unified interface, can be left unconnected
- **SIGNAL** (signal output): Magnetic field detection output pin, connect to the control board's digital pin (e.g. Arduino D2 or Pico GPIO 0)
  - Outputs HIGH (HIGH/1) when magnetic field is detected
  - Outputs LOW (LOW/0) when no magnetic field is detected

# Features

- Magnetic field detection: Can detect magnet proximity
- Digital output: Directly outputs HIGH/LOW levels, easy to use
- Operating voltage: 3.3V or 5V
- Suitable for making magnetic detection, position detection, and other applications

# Quick Wiring

1. GND → Control board GND
2. VCC → Control board 3.3V or 5V
3. SIGNAL → Control board digital pin (use the pin defined in your program)
