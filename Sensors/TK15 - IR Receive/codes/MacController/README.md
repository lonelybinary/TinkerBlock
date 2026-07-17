# MacController — IR Remote → Bluetooth Mac Controller (ESP32-S3)

Turns the ESP32-S3 into a **Bluetooth (BLE) keyboard + media remote** for a Mac.
It receives infrared signals from a remote on GPIO 3, then re-sends the matching
keystrokes to your Mac over Bluetooth — control your Mac from across the room.

Built on the [ESP32S3_TK15](../ESP32S3_TK15) decoder; here the decoded commands
are mapped to Mac actions and sent as BLE HID reports.

## Libraries

| Library | Where |
| ------- | ----- |
| **IRremote** (v4.x+) | Library Manager → "IRremote" |
| **NimBLE-Arduino** (v2.x) | Library Manager → "NimBLE-Arduino" |

> This sketch talks to the BLE HID stack **directly through NimBLE** and does
> **not** use the "ESP32-BLE-Keyboard" library — that library only supports the
> old NimBLE 1.x API and will not compile on ESP32 core 3.x.

## Wiring

| TK15 module | ESP32-S3 |
| ----------- | -------- |
| VCC         | 3.3V     |
| GND         | GND      |
| SIGNAL      | GPIO 3   |
| NC          | (leave unconnected) |

## Button → Mac action

| Remote button | Mac action        | Keys / media       |
| ------------- | ----------------- | ------------------ |
| Power On/Off  | Lock screen       | ⌘⌃Q                |
| Source        | Switch app        | ⌘Tab               |
| Mute          | Mute              | media              |
| Up/Down/Left/Right | Move selection | ↑ ↓ ← →           |
| Enter         | Return            | ⏎                  |
| Home          | Mission Control   | ⌃↑                 |
| Back          | Back / exit       | Esc                |
| Option        | Toggle Full Screen| ⌘⌃F                |
| Volume Up/Down| Volume            | media              |
| Search        | Spotlight         | ⌘Space             |
| Red           | Play/Pause        | media              |
| Green         | Previous track    | media              |
| Blue          | Next track        | media              |

Arrows and volume **auto-repeat** while held; every other key fires once per press.

## How to use

1. Install the two libraries above.
2. Select your ESP32-S3 board and port, then upload.
3. Open **Serial Monitor** at **115200 baud** — you'll see `waiting to pair`.
4. On the Mac: **System Settings → Bluetooth**, pair **"ESP32 IR Remote"**.
5. Point the remote at the module and press buttons.

## Serial debug output

`#define DEBUG 1` (default) prints a full dump of every IR frame — useful when
adapting the sketch to a new remote. Set it to `0` for quiet operation.

```
---------------- IR frame ----------------
Protocol : Samsung
Address  : 0xE
Command  : 0x46
Raw-Data : 0xB9460E0E
Repeat   : no
Button   : Enter
Action   : Return
BLE      : sent to Mac
```

## Customizing

- **Different remote?** Run [ESP32S3_TK15](../ESP32S3_TK15) (or read the debug
  output here), note each button's `Command`, and edit the `CMD_*` `#define`s.
- **Different actions?** Edit `handleButton()` — keyboard keys use `sendKey()`,
  media keys use `sendConsumer()`. `getActionName()` is just the debug label.
- **Repeat behaviour?** Edit `allowsRepeat()` to choose which held keys auto-repeat.

## How it works

- **Two HID reports** are advertised: a **Keyboard** report (Report ID 1) for
  arrows/Enter/Esc/shortcuts, and a **Consumer Control** report (Report ID 2) for
  media keys — Mac volume/mute/play/next/prev arrive on the Consumer page, not the
  keyboard page.
- Matching is done on the **command** only, because the decoded address can flip
  between `0xE`/`0xE0F` on repeat frames (a single-bit read wobble) while the
  command stays stable.

## Troubleshooting pairing

macOS treats a BLE keyboard as a trusted input device, so it must be bonded. The
sketch enables "just works" bonding (no passkey). If you re-flash and the Mac
won't reconnect, remove **"ESP32 IR Remote"** from the Mac's Bluetooth list and
pair again — the bonding keys change on each fresh pair.
