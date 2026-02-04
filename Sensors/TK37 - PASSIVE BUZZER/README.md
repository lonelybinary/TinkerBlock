# Function

This module is a passive buzzer module that can be controlled through programming to emit sounds of different frequencies. By changing the frequency of the input signal, it can emit sounds of different pitches. Can be used to make music players, alarms, alert sounds, and other applications.

# Appearance

| ![Front](images/TK37-F.png) | ![Back](images/TK37-B.png) | ![Side](images/TK37-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has a passive buzzer and a 4-pin header interface. Each pin can be identified by the silkscreen (text printed next to the pin).

# Pinout

- **GND** (negative): Like the negative terminal (-) of a battery, connect to the control board's GND
- **VCC** (positive): Like the positive terminal (+) of a battery, connect to the control board's 3.3V or 5V (this module supports both 3.3V and 5V)
- **NC** (no connection): No actual circuit connection, included for unified interface, can be left unconnected
- **SIGNAL** (signal input): Pin to control buzzer, connect to the control board's digital pin (e.g. Arduino D3 or Pico GPIO 0)
  - Requires square wave signals of different frequencies to emit sound
  - Higher frequency = higher pitch
  - Lower frequency = lower pitch

# Features

- Passive buzzer: Requires external signal to drive and emit sound
- Adjustable pitch: Can emit different pitches by changing frequency
- Operating voltage: 3.3V or 5V
- Suitable for making music players, alarms, and other applications

# Quick Wiring

1. GND → Control board GND
2. VCC → Control board 3.3V or 5V
3. SIGNAL → Control board digital pin (use the pin defined in your program)
