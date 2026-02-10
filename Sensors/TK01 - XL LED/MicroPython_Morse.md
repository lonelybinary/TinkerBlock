# Raspberry Pi Pico 2 – Morse Code Example

## Goal

This example uses the TK01-XL LED to send Morse code: you set a string (e.g. `"SOS"`), and the LED flashes it in a loop with a 2-second pause between repeats. It covers string definition, a Morse dictionary, loops, and helper functions for dot/dash timing in MicroPython.

## Wiring

- **GND** → Raspberry Pi Pico 2 GND  
- **SIGNAL** → Raspberry Pi Pico 2 GPIO 0 (or the pin you set as `LED_PIN` in code)  
- **NC** → Leave unconnected  

## Code

Full code is in `codes/MicroPython_TK01_Morse.py`. Summary of the main parts:

```python
from machine import Pin
import time

LED_PIN = 0
MESSAGE = "SOS"   # Edit this: A–Z, 0–9, space

DOT_MS = 200
DASH_MS = DOT_MS * 3
ELEMENT_GAP_MS = DOT_MS
LETTER_GAP_MS = DOT_MS * 3
WORD_GAP_MS = DOT_MS * 7

MORSE = {
    'A': '.-',   'B': '-...', 'C': '-.-.', 'D': '-..',  'E': '.',    'F': '..-.',
    'G': '--.',  'H': '....', 'I': '..',   'J': '.---', 'K': '-.-',  'L': '.-..',
    'M': '--',   'N': '-.',   'O': '---',  'P': '.--.', 'Q': '--.-', 'R': '.-.',
    'S': '...',  'T': '-',    'U': '..-',  'V': '...-', 'W': '.--',  'X': '-..-',
    'Y': '-.--', 'Z': '--..',
    '0': '-----', '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....',
    '6': '-....', '7': '--...', '8': '---..', '9': '----.',
}

led = Pin(LED_PIN, Pin.OUT)

def send_dot():
    led.on()
    time.sleep(DOT_MS / 1000.0)
    led.off()
    time.sleep(ELEMENT_GAP_MS / 1000.0)

def send_dash():
    led.on()
    time.sleep(DASH_MS / 1000.0)
    led.off()
    time.sleep(ELEMENT_GAP_MS / 1000.0)

def send_morse_char(c):
    c = c.upper()
    if c not in MORSE:
        return
    for sym in MORSE[c]:
        send_dot() if sym == '.' else send_dash()

def main():
    print("Morse - loop, 2s pause between repeats")
    while True:
        for c in MESSAGE:
            if c == ' ':
                time.sleep(WORD_GAP_MS / 1000.0)
                print(" [space]")
            else:
                send_morse_char(c)
                time.sleep(LETTER_GAP_MS / 1000.0)
        print("Done")
        time.sleep(2)

if __name__ == "__main__":
    main()
```

## Code Walkthrough

**Pin and message**

- **`LED_PIN = 0`:** GPIO connected to TK01 SIGNAL. Change if you use another pin.  
- **`MESSAGE = "SOS"`:** The string to send in Morse. Only A–Z, 0–9, and space are used; change it (e.g. `"HELLO"`) to send different text.

**Timing**

- **`DOT_MS`:** Length of one dot in ms (e.g. 200).  
- **`DASH_MS`:** Dash length (3 × dot).  
- **`ELEMENT_GAP_MS`:** Pause between dot/dash in one letter.  
- **`LETTER_GAP_MS`:** Pause between letters.  
- **`WORD_GAP_MS`:** Pause for a space.  
- Delays use `time.sleep(ms / 1000.0)` because `sleep()` takes seconds.

**MORSE dictionary**

- **`MORSE`:** Maps each letter and digit to a string of `.` and `-`. For example `'S': '...'`, `'O': '---'`. Used in `send_morse_char()` to flash the correct pattern.

**send_dot() / send_dash()**

- Turn LED on for dot or dash duration, then off for the element gap. All times are converted from ms to seconds for `time.sleep()`.

**send_morse_char(c)**

- **`c = c.upper()`:** Treat lower- and uppercase the same.  
- **`if c not in MORSE: return`:** Ignore unsupported characters.  
- **`for sym in MORSE[c]`:** For each `.` or `-` in the pattern, call `send_dot()` or `send_dash()`.

**main()**

- **`while True`:** Loop forever.  
- **`for c in MESSAGE`:** For each character, if it’s a space, sleep `WORD_GAP_MS` and print ` [space]`; otherwise call `send_morse_char(c)` and then sleep `LETTER_GAP_MS`.  
- After sending the whole string: print `"Done"`, then **`time.sleep(2)`** for a 2-second pause before the next repeat.

## Usage

1. Set **`MESSAGE`** to the text you want (e.g. `"SOS"`, `"HELLO"`).  
2. Save the script to Raspberry Pi Pico 2 and run it.  
3. Watch the terminal to see which character is being sent.  
4. LED will flash the message in Morse, then pause 2 seconds and repeat.
