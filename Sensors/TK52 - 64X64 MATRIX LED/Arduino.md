# Arduino Uno R3 Example

## Goal

This example shows how to use the TK52 - 64X64 MATRIX LED module on an Arduino Uno R3 to display various patterns.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **GND** → Arduino Uno R3 GND
- **NC** → Leave unconnected

## Code

```cpp
#include <LedControl.h>

// Pin number: change these to match your wiring
// Demo program uses: DIN=3, CLK=4, CS=2
// If using hardware SPI: DIN=11(MOSI), CLK=13(SCK), CS=10
// If using software SPI: can use any digital pins
#define CS_PIN 2    // Arduino digital pin connected to CS (demo uses D2)
#define DIN_PIN 3   // Arduino digital pin connected to DIN (demo uses D3)
#define CLK_PIN 4   // Arduino digital pin connected to CLK (demo uses D4)

// 8×8 matrix LED configuration (using MAX7219 driver, LedControl library supports software SPI)
// Note: If 64×64 matrix LED, consists of 64 8×8 modules, need to change number of devices to 64
// LedControl constructor: LedControl(dataPin, clockPin, csPin, numDevices)
LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);  // Single 8×8 module

// Pattern data (8×8 dot matrix, each pattern 8 bytes)
// Heart pattern
const byte heartPattern[8] = {
  0b00000000,
  0b01100110,
  0b11111111,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000
};

// Triangle pattern
const byte trianglePattern[8] = {
  0b00000000,
  0b00010000,
  0b00111000,
  0b01111100,
  0b11111110,
  0b01111100,
  0b00111000,
  0b00010000
};

// Square pattern
const byte squarePattern[8] = {
  0b11111111,
  0b10000001,
  0b10000001,
  0b10000001,
  0b10000001,
  0b10000001,
  0b10000001,
  0b11111111
};

// Circle pattern
const byte circlePattern[8] = {
  0b00111100,
  0b01111110,
  0b11000011,
  0b10000001,
  0b10000001,
  0b11000011,
  0b01111110,
  0b00111100
};

// Star pattern
const byte starPattern[8] = {
  0b00011000,
  0b00111100,
  0b01111110,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000,
  0b00000000
};

// Arrow pattern
const byte arrowPattern[8] = {
  0b00001000,
  0b00011100,
  0b00111110,
  0b01111111,
  0b00011100,
  0b00011100,
  0b00011100,
  0b00000000
};

// Smile pattern
const byte smilePattern[8] = {
  0b00111100,
  0b01000010,
  0b10100101,
  0b10000001,
  0b10100101,
  0b10011001,
  0b01000010,
  0b00111100
};

// Pattern array for easy looping
const byte* patterns[] = {
  heartPattern,      // 0: Heart
  trianglePattern,   // 1: Triangle
  squarePattern,     // 2: Square
  circlePattern,     // 3: Circle
  starPattern,       // 4: Star
  arrowPattern,      // 5: Arrow
  smilePattern       // 6: Smile
};

const char* patternNames[] = {
  "Heart",
  "Triangle",
  "Square",
  "Circle",
  "Star",
  "Arrow",
  "Smile"
};

const int patternCount = 7;  // Number of patterns

// Reverse byte bit order (fix mirror display issue)
byte reverseByte(byte b) {
  byte result = 0;
  for (int i = 0; i < 8; i++) {
    result <<= 1;
    result |= (b & 1);
    b >>= 1;
  }
  return result;
}

// Display pattern
void displayPattern(const byte* pattern) {
  // Clear display
  lc.clearDisplay(0);
  
  // Display pattern (reference demo program implementation)
  // Reverse byte bit order to fix mirror display issue
  for (int i = 0; i < 8; i++) {
    byte reversedByte = reverseByte(pattern[i]);
    lc.setRow(0, i, reversedByte);
  }
}

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  delay(100);
  
  Serial.println("8×8 matrix LED program started");
  Serial.println("Cycling through various patterns: Heart, Triangle, Square, Circle, Star, Arrow, Smile");
  
  // Initialize matrix LED (LedControl library)
  lc.shutdown(0, false);  // Wake up module 0
  lc.setIntensity(0, 8);  // Set brightness (0-15)
  lc.clearDisplay(0);     // Clear display
  delay(500);
}

void loop() {
  // Cycle through all patterns
  for (int i = 0; i < patternCount; i++) {
    displayPattern(patterns[i]);
    Serial.print("Display pattern: ");
    Serial.println(patternNames[i]);
    delay(1000);  // Switch pattern every second
  }
}
```

## Effect

![Effect](images/TK52-uno.gif)


## Code Walkthrough

**Line 1: Include library**

```cpp
#include <LedControl.h>
```

- **`#include <LedControl.h>`:** Include LedControl library for controlling MAX7219-driven matrix LEDs (need to install this library first).

**Lines 3–7: Pin definition**

```cpp
#define CS_PIN 2    // Arduino digital pin connected to CS (demo uses D2)
#define DIN_PIN 3   // Arduino digital pin connected to DIN (demo uses D3)
#define CLK_PIN 4   // Arduino digital pin connected to CLK (demo uses D4)
```

- **`CS_PIN`:** MAX7219 CS pin connected to Arduino D2 (demo uses D2, if using hardware SPI then use D10). Change this if you use another pin.
- **`DIN_PIN`:** MAX7219 DIN pin connected to Arduino D3 (demo uses D3, if using hardware SPI then use D11/MOSI). Change this if you use another pin.
- **`CLK_PIN`:** MAX7219 CLK pin connected to Arduino D4 (demo uses D4, if using hardware SPI then use D13/SCK). Change this if you use another pin.

**Line 11: Create LedControl object**

```cpp
LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);  // Single 8×8 module
```

- **`LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1)`:** Create LedControl object using software SPI, 1 indicates single 8×8 module (if 64×64 matrix LED, consists of 64 8×8 modules, need to change to 64).

**Lines 13–115: Define pattern data**

```cpp
// Pattern data (8×8 dot matrix, each pattern 8 bytes)
// Heart pattern
const byte heartPattern[8] = {
  // ... 8 bytes of data
};
// ... other patterns
```

- **Pattern data:** Defines 7 8×8 dot matrix patterns (Heart, Triangle, Square, Circle, Star, Arrow, Smile), each pattern consists of 8 bytes, each byte represents one row (8 pixels).

**Lines 117–139: Define pattern array and names**

```cpp
const byte* patterns[] = { ... };
const char* patternNames[] = { ... };
const int patternCount = 7;
```

- **`patterns[]`:** Pattern array for easy looping display.
- **`patternNames[]`:** Pattern name array, corresponding to each pattern's name.
- **`patternCount`:** Number of patterns (7).

**Lines 141–149: Reverse byte function**

```cpp
byte reverseByte(byte b) {
  // ... reverse byte bit order
}
```

- **`reverseByte()` function:** Reverse byte bit order to fix mirror display issue.

**Lines 151–162: Display pattern function**

```cpp
void displayPattern(const byte* pattern) {
  lc.clearDisplay(0);
  for (int i = 0; i < 8; i++) {
    byte reversedByte = reverseByte(pattern[i]);
    lc.setRow(0, i, reversedByte);
  }
}
```

- **`displayPattern()` function:** Function to display specified pattern.
- **`lc.clearDisplay(0)`:** Clear display.
- **`reverseByte(pattern[i])`:** Reverse byte bit order to fix mirror display issue.
- **`lc.setRow(0, i, reversedByte)`:** Set row i display data.

**Lines 164–177: Initialization (setup function)**

```cpp
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  delay(100);
  
  Serial.println("8×8 matrix LED program started");
  Serial.println("Cycling through various patterns: Heart, Triangle, Square, Circle, Star, Arrow, Smile");
  
  // Initialize matrix LED (LedControl library)
  lc.shutdown(0, false);  // Wake up module 0
  lc.setIntensity(0, 8);  // Set brightness (0-15)
  lc.clearDisplay(0);     // Clear display
  delay(500);
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`lc.shutdown(0, false)`:** Wake up module 0 (false means not shutdown, i.e., wake up).
- **`lc.setIntensity(0, 8)`:** Set brightness (0-15, 8 is medium brightness).
- **`lc.clearDisplay(0)`:** Clear display.
- **`Serial.println(...)`:** Print program start message and instructions to Serial Monitor.

**Lines 179–187: Main loop (loop function)**

```cpp
void loop() {
  // Cycle through all patterns
  for (int i = 0; i < patternCount; i++) {
    displayPattern(patterns[i]);
    Serial.print("Display pattern: ");
    Serial.println(patternNames[i]);
    delay(1000);  // Switch pattern every second
  }
}
```

- **`loop()`:** Runs repeatedly.
- **`for (int i = 0; i < patternCount; i++)`:** Loop through all patterns (7 patterns).
- **`displayPattern(patterns[i])`:** Display pattern i.
- **`Serial.print(...)` and `Serial.println(...)`:** Print current displayed pattern name to Serial Monitor.
- **`delay(1000)`:** Wait 1000 milliseconds (1 second) before switching to next pattern to control switching frequency.
