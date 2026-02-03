# Function

This module is a collision sensor module that can detect collisions or vibrations. When the module is subjected to collision or vibration, it outputs a HIGH signal, suitable for making collision avoidance devices, vibration alarms, and other applications.

# Appearance

| ![Front](images/TK17-F.png) | ![Back](images/TK17-B.png) | ![Side](images/TK17-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has a collision detection element and a 4-pin header interface. Each pin can be identified by the silkscreen (text printed next to the pin).

# Pinout

- **GND** (negative): Like the negative terminal (-) of a battery, connect to the control board's GND
- **VCC** (positive): Like the positive terminal (+) of a battery, connect to the control board's 3.3V or 5V (this module supports both 3.3V and 5V)
- **NC** (no connection): No actual circuit connection, included for unified interface, can be left unconnected
- **SIGNAL** (signal output): Collision detection output pin, connect to the control board's digital pin (e.g. Arduino D2 or Pico GPIO 0)
  - Outputs HIGH (HIGH/1) when collision is detected
  - Outputs LOW (LOW/0) when no collision is detected

# Features

- Collision detection: Outputs HIGH when collision or vibration is detected
- Operating voltage: 3.3V or 5V
- Adjustable sensitivity: Module has a sensitivity adjustment potentiometer

# Quick Wiring

1. GND → Control board GND
2. VCC → Control board 3.3V or 5V
3. SIGNAL → Control board digital pin (use the pin defined in your program)
