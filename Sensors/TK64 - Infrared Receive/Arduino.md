# Arduino Uno R3 Example

## Goal

This example shows how to use the TK64 - INRARED RECEIVER module on an Arduino Uno R3 to receive infrared signals.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 D2
- **NC** → Leave unconnected

## Code

```cpp
// Note: This program requires IRremote library
// Installation: Tools → Manage Libraries → Search "IRremote" → Install

#include <IRremote.h>  // Import infrared receiver library

// Pin number: change this to match your wiring
#define IR_RX_PIN 2  // Arduino digital pin connected to SIGNAL (e.g. D2)

// Create infrared receiver object
IRrecv irrecv(IR_RX_PIN);
decode_results results;  // Store decoding results

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  // Start infrared reception
  irrecv.enableIRIn();
  
  Serial.println("Infrared receiver program started");
  Serial.println("Waiting to receive infrared signal...");
}

void loop() {
  // Check if infrared signal received
  if (irrecv.decode(&results)) {
    // Signal received, print decoding results
    Serial.print("Infrared signal received, decoded value: 0x");
    Serial.println(results.value, HEX);  // Display in hexadecimal
    
    // Identify common infrared remote codes
    switch(results.value) {
      case 0xFF00FF:  // Example: a button on a remote
        Serial.println("Button 1 pressed");
        break;
      case 0xFF807F:  // Example: another button on a remote
        Serial.println("Button 2 pressed");
        break;
      default:
        Serial.println("Unknown button");
        break;
    }
    
    // Continue receiving next signal
    irrecv.resume();
  }
  
  delay(100);  // Brief delay
}
```

## Effect

![Effect](images/TK64-uno.gif)


## Code Walkthrough

**Lines 1–3: Include library**

```cpp
// Note: This program requires IRremote library
// Installation: Tools → Manage Libraries → Search "IRremote" → Install

#include <IRremote.h>  // Import infrared receiver library
```

- **`#include <IRremote.h>`:** Include IRremote library for infrared reception (need to install first: Tools → Manage Libraries → Search "IRremote" → Install).

**Line 5: Pin definition**

```cpp
#define IR_RX_PIN 2  // Arduino digital pin connected to SIGNAL (e.g. D2)
```

- **`IR_RX_PIN`:** The Arduino digital pin connected to infrared receiver SIGNAL. Change this if you use another pin.

**Lines 8–9: Create infrared receiver object**

```cpp
// Create infrared receiver object
IRrecv irrecv(IR_RX_PIN);
decode_results results;  // Store decoding results
```

- **`IRrecv irrecv(IR_RX_PIN)`:** Create infrared receiver object using specified pin to receive infrared signals.
- **`decode_results results`:** Store decoding results, used to save received infrared code value.

**Lines 11–22: Initialization (setup function)**

```cpp
void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  // Start infrared reception
  irrecv.enableIRIn();
  
  Serial.println("Infrared receiver program started");
  Serial.println("Waiting to receive infrared signal...");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`irrecv.enableIRIn()`:** Start infrared reception, begin listening for infrared signals.
- **`Serial.println(...)`:** Print program start message and instructions to Serial Monitor.

**Lines 24–50: Main loop (loop function)**

```cpp
void loop() {
  // Check if infrared signal received
  if (irrecv.decode(&results)) {
    // Signal received, print decoding results
    Serial.print("Infrared signal received, decoded value: 0x");
    Serial.println(results.value, HEX);  // Display in hexadecimal
    
    // Identify common infrared remote codes
    switch(results.value) {
      case 0xFF00FF:  // Example: a button on a remote
        Serial.println("Button 1 pressed");
        break;
      case 0xFF807F:  // Example: another button on a remote
        Serial.println("Button 2 pressed");
        break;
      default:
        Serial.println("Unknown button");
        break;
    }
    
    // Continue receiving next signal
    irrecv.resume();
  }
  
  delay(100);  // Brief delay
}
```

- **`loop()`:** Runs repeatedly.
- **`irrecv.decode(&results)`:** Check if infrared signal received and decode, returns true if received, decoding result stored in `results`.
- **`results.value`:** Stores decoded infrared code value (hexadecimal format).
- **`Serial.print(...)` and `Serial.println(results.value, HEX)`:** Print decoded value to Serial Monitor (displayed in hexadecimal).
- **`switch(results.value)`:** Identify which button based on decoded value, `case 0xFF00FF` and `case 0xFF807F` are example button codes (can be modified according to actual remote).
- **`irrecv.resume()`:** Continue receiving next signal, must be called after processing current signal, otherwise cannot receive next signal.
- **`delay(100)`:** Wait 100 milliseconds before checking again to avoid checking too fast and reduce CPU usage.
