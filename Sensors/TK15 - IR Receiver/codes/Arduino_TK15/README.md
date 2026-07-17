# Arduino_TK15 — Basic IR Detection (Arduino Uno R3)

The simplest example: detect **whether** an infrared signal is arriving and blink
the on-board LED while it is. It does **not** decode which button was pressed —
for that, see the [ESP32S3_TK15](../ESP32S3_TK15) decoder example.

## Wiring

| TK15 module | Arduino Uno R3 |
| ----------- | -------------- |
| VCC         | 5V             |
| GND         | GND            |
| SIGNAL      | D3             |
| NC          | (leave unconnected) |

The SIGNAL pin idles HIGH and pulses LOW while an IR signal is being received.

## How to use

1. Open `Arduino_TK15.ino` in the Arduino IDE.
2. Select **Tools → Board → Arduino Uno** and the correct port.
3. Upload.
4. Open **Serial Monitor** at **9600 baud**.
5. Point any IR remote at the module and press a button.

## Expected output

```
IR signal received!
IR signal received!
```

The built-in LED (pin 13) turns on while a signal is detected and off otherwise.

## Notes

- This sketch reads the pin directly with `digitalRead()`; it reacts to *any* IR
  activity, so fluorescent/LED lighting or sunlight can occasionally trigger it.
- To read the actual remote codes (protocol, address, command), use the
  [ESP32S3_TK15](../ESP32S3_TK15) example, which decodes the signal with the
  IRremote library.
- Change `IR_PIN` at the top of the sketch if you wire SIGNAL to a different pin.
