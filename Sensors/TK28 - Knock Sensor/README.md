# Function

This module is a tap sensor module that can detect taps or vibrations. When the module is subjected to a tap or vibration, it outputs a HIGH signal. Can be used to make tap switches, vibration alarms, and other applications.

# Appearance

| ![Front](images/TK28-F.png) | ![Back](images/TK28-B.png) | ![Side](images/TK28-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has a vibration detection element and a 4-pin header interface. Each pin can be identified by the silkscreen (text printed next to the pin).

# Pinout

- **GND** (negative): Like the negative terminal (-) of a battery, connect to the control board's GND
- **VCC** (positive): Like the positive terminal (+) of a battery, connect to the control board's 3.3V or 5V (this module supports both 3.3V and 5V)
- **NC** (no connection): No actual circuit connection, included for unified interface, can be left unconnected
- **SIGNAL** (signal output): Tap detection output pin, connect to the control board's digital pin (e.g. Arduino D2 or Pico GPIO 0)
  - Outputs HIGH (HIGH/1) when tap is detected
  - Outputs LOW (LOW/0) when no tap is detected

# Features

- Tap detection: Outputs HIGH when tap or vibration is detected
- Operating voltage: 3.3V or 5V
- High sensitivity: Can detect slight taps

# Quick Wiring

1. GND → Control board GND
2. VCC → Control board 3.3V or 5V
3. SIGNAL → Control board digital pin (use the pin defined in your program)
