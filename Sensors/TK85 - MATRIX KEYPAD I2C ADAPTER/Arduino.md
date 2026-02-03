# Arduino Uno R3 Example

## Goal

This example shows how to use the TK85 - MATRIX KEYPAD I2C ADAPTER module on an Arduino Uno R3 to read keypad input.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SDA** → Arduino Uno R3 A4 (I2C data line)
- **SCL** → Arduino Uno R3 A5 (I2C clock line)
- **NC** → Leave unconnected

## Code

```cpp
// Include Wire library for I2C communication
// Arduino Uno R3 I2C pins are fixed: SDA=A4, SCL=A5
#include <Wire.h>

// I2C address of matrix keypad adapter module (check module documentation, usually 0x20 or 0x21)
#define KEYPAD_ADDRESS 0x20

// Keypad mapping (4x4 matrix keypad)
char keymap[16] = "DCBA#9630852*741";

// Debounce variables
uint8_t stableKey = 16;   // 16 = NoKey
uint8_t stableCount = 0;
uint8_t lastKeypadKey = 16;

// Function declaration
int readKeypad();

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Matrix keypad test");
  Serial.println("Press keys to see key code output");
}

void loop() {
  int key = readKeypad();
  
  if (key >= 0) {
    Serial.print("Key pressed: number=");
    Serial.print(key);
    
    if (key < 16) {
      Serial.print(", character='");
      Serial.print(keymap[key]);
      Serial.print("'");
    }
    Serial.println();
  }
  
  delay(50);
}

// Read matrix keypad
int readKeypad() {
  uint8_t currentKey = 16;
  uint8_t raw = 0xFF;
  bool found = false;

  // Mode A: rows = lower 4 bits (P0..P3), columns = upper 4 bits (P4..P7)
  for (uint8_t col = 0; col < 4 && !found; col++) {
    uint8_t out = (uint8_t)(0xFF & ~(1 << (4 + col)));
    Wire.beginTransmission(KEYPAD_ADDRESS);
    Wire.write(out);
    if (Wire.endTransmission() != 0) {
      continue;
    }
    delayMicroseconds(200);
    
    Wire.requestFrom(KEYPAD_ADDRESS, 1);
    if (Wire.available()) {
      raw = Wire.read();
      uint8_t rows = raw & 0x0F;
      if (rows != 0x0F) {
        for (uint8_t row = 0; row < 4; row++) {
          if (!(rows & (1 << row))) {
            currentKey = row * 4 + col;
            found = true;
            break;
          }
        }
      }
    }
  }

  // Mode B: rows = upper 4 bits (P4..P7), columns = lower 4 bits (P0..P3)
  if (!found) {
    for (uint8_t col = 0; col < 4 && !found; col++) {
      uint8_t out = (uint8_t)(0xFF & ~(1 << col));
      Wire.beginTransmission(KEYPAD_ADDRESS);
      Wire.write(out);
      if (Wire.endTransmission() != 0) {
        continue;
      }
      delayMicroseconds(200);
      
      Wire.requestFrom(KEYPAD_ADDRESS, 1);
      if (Wire.available()) {
        raw = Wire.read();
        uint8_t rows = (raw >> 4) & 0x0F;
        if (rows != 0x0F) {
          for (uint8_t row = 0; row < 4; row++) {
            if (!(rows & (1 << row))) {
              currentKey = row * 4 + col;
              found = true;
              break;
            }
          }
        }
      }
    }
  }

  // Restore all high
  Wire.beginTransmission(KEYPAD_ADDRESS);
  Wire.write(0xFF);
  Wire.endTransmission();
        
  // Debounce: need to read the same key twice consecutively to consider it pressed
  if (currentKey < 16) {
    if (currentKey == stableKey) {
      if (stableCount < 255) stableCount++;
    } else {
      stableKey = currentKey;
      stableCount = 1;
    }

    if (stableCount >= 2 && currentKey != lastKeypadKey) {
      lastKeypadKey = currentKey;
      return currentKey;
    }
  } else {
    stableKey = 16;
    stableCount = 0;
    if (lastKeypadKey != 16) {
      lastKeypadKey = 16;
    }
  }
  
  return -1;
}
```

## Effect

![Effect](images/TK85-uno.jpg)

![Effect](images/TK85-uno-uart.png)


## Code Walkthrough

**Lines 1–3: Include library**

```cpp
// Include Wire library for I2C communication
// Arduino Uno R3 I2C pins are fixed: SDA=A4, SCL=A5
#include <Wire.h>
```

- **`#include <Wire.h>`:** Include Wire library for I2C communication (Arduino Uno R3 I2C pins are fixed: SDA=A4, SCL=A5).

**Line 5: Define I2C address**

```cpp
// I2C address of matrix keypad adapter module (check module documentation, usually 0x20 or 0x21)
#define KEYPAD_ADDRESS 0x20
```

- **`KEYPAD_ADDRESS`:** I2C address of matrix keypad adapter module (check module documentation, usually 0x20 or 0x21).

**Lines 7–9: Define keypad mapping**

```cpp
// Keypad mapping (4x4 matrix keypad)
char keymap[16] = "DCBA#9630852*741";
```

- **`keymap[16]`:** Character mapping array for 4×4 matrix keypad, 16 characters corresponding to 16 keys (D, C, B, A, #, 9, 6, 3, 0, 8, 5, 2, *, 7, 4, 1).

**Lines 11–13: Define debounce variables**

```cpp
// Debounce variables
uint8_t stableKey = 16;   // 16 = NoKey
uint8_t stableCount = 0;
uint8_t lastKeypadKey = 16;
```

- **`stableKey`:** Current stable key number (16 means no key).
- **`stableCount`:** Stability count for debouncing (need to read the same key twice consecutively to consider it pressed).
- **`lastKeypadKey`:** Previously detected key number, used to avoid repeated output.

**Line 15: Function declaration**

```cpp
// Function declaration
int readKeypad();
```

- **`readKeypad()`:** Function declaration to read matrix keypad keys.

**Lines 17–23: Initialization (setup function)**

```cpp
void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Matrix keypad test");
  Serial.println("Press keys to see key code output");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`Wire.begin()`:** Initialize I2C communication.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`Serial.println(...)`:** Print program start message and instructions to Serial Monitor.

**Lines 25–33: Main loop (loop function)**

```cpp
void loop() {
  int key = readKeypad();
  
  if (key >= 0) {
    Serial.print("Key pressed: number=");
    Serial.print(key);
    
    if (key < 16) {
      Serial.print(", character='");
      Serial.print(keymap[key]);
      Serial.print("'");
    }
    Serial.println();
  }
  
  delay(50);
}
```

- **`loop()`:** Runs repeatedly.
- **`readKeypad()`:** Call function to read matrix keypad keys, returns key number (0-15) or -1 (no key).
- **`if (key >= 0)`:** Check if key press detected.
- **`if (key < 16)`:** Check if key number is in valid range (0-15), if yes then display corresponding character.
- **`keymap[key]`:** Get corresponding character based on key number.
- **`Serial.print(...)` and `Serial.println(...)`:** Print key number and character to Serial Monitor.
- **`delay(50)`:** Wait 50 milliseconds before reading again to avoid reading too fast and control output frequency.

**Lines 35–119: Read matrix keypad function (readKeypad function)**

```cpp
// Read matrix keypad
int readKeypad() {
  // ... scanning logic for Mode A and Mode B ...
  // ... debounce logic ...
  return -1;
}
```

- **`readKeypad()` function:** Function to read matrix keypad keys, returns key number (0-15) or -1 (no key).
- **Mode A and Mode B:** Try two different row-column configurations to adapt to different keypad connection methods.
- **`Wire.beginTransmission(KEYPAD_ADDRESS)`:** Start I2C transmission, specify I2C address of matrix keypad adapter module.
- **`Wire.write(out)`:** Write data to I2C device, set column output (pull one column low).
- **`Wire.requestFrom(KEYPAD_ADDRESS, 1)`:** Request to read 1 byte of data from I2C device.
- **`raw & 0x0F` and `(raw >> 4) & 0x0F`:** Extract row data (lower 4 bits or upper 4 bits).
- **`row * 4 + col`:** Calculate key number (row number × 4 + column number).
- **Debounce logic:** Need to read the same key twice consecutively to consider it pressed, avoid false triggers.
- **`return currentKey`:** Return detected key number.
- **`return -1`:** If no key detected or key unstable, return -1.
