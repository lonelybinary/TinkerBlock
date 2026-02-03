# Function

This module is a line tracker sensor module that can detect black or white lines on the ground. Works on infrared reflection principle. When a black line is detected, it outputs HIGH; when a white line is detected, it outputs LOW. Suitable for making line-following robots, path detection, and other applications.

# Appearance

| ![Front](images/TK57-F.png) | ![Back](images/TK57-B.png) | ![Side](images/TK57-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has an infrared transmitter-receiver pair and a 4-pin header interface. Each pin can be identified by the silkscreen (text printed next to the pin).

# Pinout

- **GND** (negative): Like the negative terminal (-) of a battery, connect to the control board's GND
- **VCC** (positive): Like the positive terminal (+) of a battery, connect to the control board's 3.3V or 5V (this module supports both 3.3V and 5V)
- **NC** (no connection): No actual circuit connection, included for unified interface, can be left unconnected
- **SIGNAL** (signal output): Line tracking detection output pin, connect to the control board's digital pin (e.g. Arduino D2 or Pico GPIO 0)
  - Outputs HIGH (HIGH/1) when black line is detected
  - Outputs LOW (LOW/0) when white line is detected (or no black line detected)

# Features

- Infrared reflection detection: Detects black lines through infrared light reflection
- Digital output: Directly outputs HIGH/LOW levels, easy to use
- Operating voltage: 3.3V or 5V
- Suitable for making line-following robots

# Quick Wiring

1. GND → Control board GND
2. VCC → Control board 3.3V or 5V
3. SIGNAL → Control board digital pin (use the pin defined in your program)
