# ESP32S3_TK15 — IR Decoder (ESP32-S3)

Decodes infrared remote signals with the TK15 module. Unlike the basic
[Arduino_TK15](../Arduino_TK15) detection example, this identifies the remote
**protocol** and prints the decoded **address**, **command**, and a friendly
**button name** for every press.

## Library

- **IRremote** by Armin Joachimsmeyer (v4.x or newer) —
  *Tools → Manage Libraries → search "IRremote"*.

## Wiring

| TK15 module | ESP32-S3 |
| ----------- | -------- |
| VCC         | 3.3V     |
| GND         | GND      |
| SIGNAL      | GPIO 3   |
| NC          | (leave unconnected) |

> **GPIO 3 note:** GPIO 3 is a strapping pin on the ESP32-S3. It works fine as an
> IR input here, but if you ever see boot issues, move SIGNAL to a plain GPIO
> (e.g. 4, 5, 6) and update `IR_PIN`.

## How to use

1. Install the IRremote library.
2. Select your ESP32-S3 board and the correct port, then upload.
3. Open **Serial Monitor** at **115200 baud**.
4. Point a remote at the module and press buttons.

## Expected output

```
----------------------------------------
Protocol=Samsung Address=0xE Command=0x46 Raw-Data=0xB9460E0E 32 bits LSB first
Protocol: Samsung
Address : 0xE
Command : 0x46
Button  : Enter
```

## Button map

The `getButtonName()` lookup is filled in for one Samsung remote:

| Command | Button       | Command | Button       |
| ------- | ------------ | ------- | ------------ |
| `0x0C`  | Power On/Off | `0x5B`  | Back         |
| `0x0F`  | Source       | `0x11`  | Option       |
| `0x0D`  | Mute         | `0x14`  | Volume Up    |
| `0x42`  | Up           | `0x15`  | Volume Down  |
| `0x43`  | Down         | `0x9C`  | Search       |
| `0x44`  | Left         | `0xB2`  | Red          |
| `0x45`  | Right        | `0xB3`  | Green        |
| `0x46`  | Enter        | `0xB4`  | Blue         |
| `0x78`  | Home         |         |              |

To adapt it to **your** remote, run the sketch, note the `Command` value each
button prints, and edit the `case` values in `getButtonName()`.

## Why the Address sometimes changes (0xE vs 0xE0F)

For a given remote, the **address is fixed** (it identifies the device) and only
the **command** changes per button. If the address occasionally flips (e.g. `0xE`
→ `0xE0F`), that is a single-bit read error from a weak/noisy signal — the repeat
frame in the example above (`...0E0F`) differs from the clean frame (`...0E0E`) by
exactly one bit. Get closer, aim at the receiver, and use fresh batteries to keep
it stable. In code, prefer matching on **command** (it stays correct even when the
address wobbles).

## Next step

Turn these codes into real actions — see [MacController](../MacController), which
uses this same decoder to drive a Mac over Bluetooth.
