# Function

This module is a potentiometer module that can adjust resistance value and output analog voltage signals. By rotating the potentiometer knob, you can change the output voltage value. It can be used to control LED brightness, servo angle, volume, and more.

# Appearance

| ![Front](images/TK07-F.png) | ![Back](images/TK07-B.png) | ![Side](images/TK07-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has a rotatable potentiometer knob and a 4-pin header. You can identify each pin by the silkscreen (text printed next to the pins).

# Pinout

- **GND** (negative): Connect to the controller board's GND (like the negative terminal of a battery).
- **VCC** (positive): Connect to the controller board's 3.3V or 5V (This module supports 3.3V and 5V).
- **NC** (no connect): Not connected in the circuit; left for a unified interface. Can be left unconnected.
- **SIGNAL** (output): Analog voltage output pin. Connect to an analog input pin on the controller (e.g. Arduino A0 or Pico GPIO 26).
  - Output voltage range: 0V to VCC (3.3V or 5V)
  - Rotating the knob can change the output voltage value

# Features

- Analog output: Outputs continuously variable voltage signals
- Operating voltage: 3.3 V or 5 V
- Adjustable range: 0 to maximum voltage

# Quick Wiring (3 steps)

1. GND → controller board GND
2. VCC → controller board 3.3V or 5V
3. SIGNAL → controller board analog input pin (use the pin number defined in your code)
