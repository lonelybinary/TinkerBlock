# Function

This module is an NTC thermistor module that can measure ambient temperature. The higher the temperature, the higher the output voltage value. It can be used to make thermometers, temperature alarms, and other applications.

# Appearance

| ![Front](images/TK12-F.png) | ![Back](images/TK12-B.png) | ![Side](images/TK12-S.png) |
| :-----------------------: | :-----------------------: | :-----------------------: |
|          **Front**          |          **Back**          |          **Side**          |

The module has an NTC thermistor and a 4-pin header. You can identify each pin by the silkscreen (text printed next to the pins).

# Pinout

- **GND** (negative): Connect to the controller board's GND (like the negative terminal of a battery).
- **VCC** (positive): Connect to the controller board's 3.3V or 5V (This module supports 3.3V and 5V).
- **NC** (no connect): Not connected in the circuit; left for a unified interface. Can be left unconnected.
- **SIGNAL** (output): Temperature output pin. Connect to an analog input pin on the controller (e.g. Arduino A0 or Pico GPIO 26).
  - Higher temperature outputs higher voltage
  - Lower temperature outputs lower voltage

# Features

- Temperature detection: Can measure ambient temperature
- Analog output: Outputs continuously variable voltage signals
- Operating voltage: 3.3 V or 5 V

# Quick Wiring (3 steps)

1. GND → controller board GND
2. VCC → controller board 3.3V or 5V
3. SIGNAL → controller board analog input pin (use the pin number defined in your code)
