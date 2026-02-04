# Function

This module is a photoelectric switch module that can detect whether an object blocks light. When an object blocks light, the module outputs a HIGH signal. Can be used to make counters, automatic doors, object detection, and other applications.

# Appearance

| ![Front](images/TK61-F.png) | ![Back](images/TK61-B.png) | ![Side](images/TK61-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has a photoelectric switch element (including infrared transmitter and receiver) and a 4-pin header interface. Each pin can be identified by the silkscreen (text printed next to the pin).

# Pinout

- **GND** (negative): Like the negative terminal (-) of a battery, connect to the control board's GND
- **VCC** (positive): Like the positive terminal (+) of a battery, connect to the control board's 3.3V or 5V (this module supports both 3.3V and 5V)
- **NC** (no connection): No actual circuit connection, included for unified interface, can be left unconnected
- **SIGNAL** (signal output): Detection output pin, connect to the control board's digital pin (e.g. Arduino D2 or Pico GPIO 0)
  - Outputs HIGH (HIGH/1) when object blocks light
  - Outputs LOW (LOW/0) when no object detected

# Features

- Object detection: Detects whether an object blocks light
- Operating voltage: 3.3V or 5V
- Adjustable sensitivity: Module has sensitivity adjustment potentiometer
- Suitable for making counters, automatic doors, and other applications

# Quick Wiring

1. GND → Control board GND
2. VCC → Control board 3.3V or 5V
3. SIGNAL → Control board digital pin (use the pin defined in your program)
