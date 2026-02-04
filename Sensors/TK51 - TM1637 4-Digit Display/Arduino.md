# Arduino Uno R3 Example

## Goal

This example shows how to use the TK51 - 4-DIGIT DISPLAY module on an Arduino Uno R3 to display numbers.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **NC** → Leave unconnected

## Code

```cpp
#include <TM1637Display.h>

// Pin number: change these to match your wiring
#define CLK_PIN 2   // Arduino digital pin connected to CLOCK (e.g. D2)
#define DIO_PIN 3   // Arduino digital pin connected to DATA (e.g. D3)

// Create TM1637 display object
TM1637Display display(CLK_PIN, DIO_PIN);

void setup() {
  // Set display brightness (0-7, 7 is brightest)
  display.setBrightness(7);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("4-digit display module program started");
  Serial.println("Cycling through 0-9 (all 4 digits display same number)");
}

void loop() {
  // Cycle through 0-9 (all 4 digits display same number)
  for (int i = 0; i < 10; i++) {
    // Display number: 0 displays as 0000, 1 displays as 1111, 2 displays as 2222...9 displays as 9999
    // showNumberDecEx second parameter is dot display, third parameter is leading zero
    display.showNumberDecEx(i * 1111, 0, false);
    
    Serial.print("Display number: ");
    Serial.println(i);
    
    delay(1000);  // Switch number every second
  }
}
```

## Effect

![Effect](images/TK51-uno.gif)


## Code Walkthrough

**Line 1: Include library**

```cpp
#include <TM1637Display.h>
```

- **`#include <TM1637Display.h>`:** Include TM1637Display library for controlling TM1637-driven 4-digit displays (need to install this library first).

**Lines 3–4: Pin definition**

```cpp
#define CLK_PIN 2   // Arduino digital pin connected to CLOCK (e.g. D2)
#define DIO_PIN 3   // Arduino digital pin connected to DATA (e.g. D3)
```

- **`CLK_PIN`:** TM1637 CLOCK pin connected to Arduino D2 digital pin. Change this if you use another pin.
- **`DIO_PIN`:** TM1637 DATA pin connected to Arduino D3 digital pin. Change this if you use another pin.

**Line 7: Create display object**

```cpp
TM1637Display display(CLK_PIN, DIO_PIN);
```

- **`TM1637Display display(CLK_PIN, DIO_PIN)`:** Create TM1637 display object using specified CLK and DIO pins.

**Lines 9–18: Initialization (setup function)**

```cpp
void setup() {
  // Set display brightness (0-7, 7 is brightest)
  display.setBrightness(7);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("4-digit display module program started");
  Serial.println("Cycling through 0-9 (all 4 digits display same number)");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`display.setBrightness(7)`:** Set display brightness (0-7, 7 is brightest).
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`Serial.println(...)`:** Print program start message and instructions to Serial Monitor.

**Lines 20–33: Main loop (loop function)**

```cpp
void loop() {
  // Cycle through 0-9 (all 4 digits display same number)
  for (int i = 0; i < 10; i++) {
    // Display number: 0 displays as 0000, 1 displays as 1111, 2 displays as 2222...9 displays as 9999
    // showNumberDecEx second parameter is dot display, third parameter is leading zero
    display.showNumberDecEx(i * 1111, 0, false);
    
    Serial.print("Display number: ");
    Serial.println(i);
    
    delay(1000);  // Switch number every second
  }
}
```

- **`loop()`:** Runs repeatedly.
- **`for (int i = 0; i < 10; i++)`:** Loop through 0-9, display one number per loop.
- **`display.showNumberDecEx(i * 1111, 0, false)`:** Display number, `i * 1111` makes all 4 digits display the same number (0 displays as 0000, 1 displays as 1111, and so on), second parameter is dot display (0 means no dot), third parameter is leading zero (false means no leading zero).
- **`Serial.print(...)` and `Serial.println(...)`:** Print current displayed number to Serial Monitor.
- **`delay(1000)`:** Wait 1000 milliseconds (1 second) before switching to next number to control display switching frequency.
