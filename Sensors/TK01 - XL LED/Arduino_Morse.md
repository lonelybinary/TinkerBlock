# Arduino Uno R3 – Morse Code Example

## Goal

This example uses the TK01-XL LED to send Morse code: you set a string (e.g. `"SOS"`), and the LED flashes it in a loop with a 2-second pause between repeats. It covers string definition, macros for Morse patterns, `loop()` with `for`, and helper functions for dot/dash timing.

## Wiring

- **GND** → Arduino Uno R3 GND  
- **SIGNAL** → Arduino Uno R3 D3 (or the digital pin you set as `LED_PIN` in code)  
- **NC** → Leave unconnected  

## Code

Full code is in `codes/Arduino_TK01_Morse.ino`. Summary of the main parts:

```cpp
#define LED_PIN 3
const char MESSAGE[] = "SOS";   // Edit this: A–Z, 0–9, space

// Morse patterns as macros (e.g. MORSE_A ".-", MORSE_S "...", MORSE_O "---")
#define MORSE_A ".-"
#define MORSE_S "..."
#define MORSE_O "---"
// ... MORSE_B to MORSE_Z, MORSE_0 to MORSE_9

const int DOT_MS = 200;           // 1 unit
const int DASH_MS = DOT_MS * 3;  // 3 units
const int LETTER_GAP_MS = DOT_MS * 3;
const int WORD_GAP_MS = DOT_MS * 7;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Morse - loop, 2s pause between repeats");
}

void loop() {
  for (unsigned int i = 0; i < sizeof(MESSAGE) - 1; i++) {
    char c = MESSAGE[i];
    if (c == ' ') {
      delay(WORD_GAP_MS);
      Serial.println(" [space]");
    } else {
      sendMorseChar(c);
      delay(LETTER_GAP_MS);
    }
  }
  Serial.println("Done");
  delay(2000);  // 2 seconds before next repeat
}
```

Helper functions: `ledOn(ms)` / `ledOff(ms)`, `sendDot()` / `sendDash()`, `sendMorsePattern(".-")`, and `sendMorseChar(c)` that uses the `MORSE_*` macros in a `switch`.

## Code Walkthrough

**Pin and message**

- **`LED_PIN`:** Digital pin connected to TK01 SIGNAL. Change if you use another pin.  
- **`MESSAGE[]`:** The string to send in Morse. Only A–Z, 0–9, and space are supported; change it (e.g. `"SOS"`, `"HELLO"`) to send different text.

**Morse macros**

- **`MORSE_A` … `MORSE_Z`, `MORSE_0` … `MORSE_9`:** Each macro is a string of dots (`.`) and dashes (`-`). For example `MORSE_S "..."`, `MORSE_O "---"`. The code uses them in `sendMorseChar()` so the LED flashes the correct pattern per character.

**Timing constants**

- **`DOT_MS`:** Length of one “dot” (e.g. 200 ms).  
- **`DASH_MS`:** Length of one “dash” (3 × dot).  
- **`ELEMENT_GAP_MS`:** Pause between dot/dash inside one letter.  
- **`LETTER_GAP_MS`:** Pause between letters.  
- **`WORD_GAP_MS`:** Pause for a space (between words).

**setup()**

- Runs once: set `LED_PIN` as output, start Serial at 9600, and print that the program is running in a loop with 2 s pause.

**loop()**

- **`for (i = 0; i < sizeof(MESSAGE) - 1; i++)`:** Walk each character of `MESSAGE` (excluding the terminating `'\0'`).  
- **`c == ' '`:** If space, wait `WORD_GAP_MS` and print ` [space]`.  
- **Else:** Call `sendMorseChar(c)` to flash the letter/digit, then wait `LETTER_GAP_MS`.  
- After the whole string: print `"Done"`, then **`delay(2000)`** so there is a 2-second pause before the next repeat.

**Helper functions**

- **`sendDot()` / `sendDash()`:** Turn LED on for dot/dash duration, then off for element gap.  
- **`sendMorsePattern(pattern)`:** For each character in the string, call `sendDot()` or `sendDash()`.  
- **`sendMorseChar(c)`:** Convert to uppercase, then `switch (c)` and call `sendMorsePattern(MORSE_X)` with the right macro (e.g. `MORSE_S`, `MORSE_O`). Unknown characters are ignored.

## Usage

1. Set **`MESSAGE`** to the text you want (e.g. `"SOS"`, `"HELLO"`).  
2. Upload the sketch to Arduino Uno R3.  
3. Open Serial Monitor at 9600 baud to see which character is being sent.  
4. LED will flash the message in Morse, then pause 2 seconds and repeat.
