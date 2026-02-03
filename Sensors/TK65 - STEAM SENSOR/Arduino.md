# Arduino Uno R3 Example

## Goal

This example shows how to use the TK65 - STEAM SENSOR module on an Arduino Uno R3 to read steam intensity.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 A0
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change this to match your wiring
#define STEAM_PIN A0   // Arduino analog input pin connected to SIGNAL (e.g. A0)

// Filtering and change detection variables
int lastValue = -1;  // Previous value
const int CHANGE_THRESHOLD = 10;  // Change threshold, only output if change exceeds this value

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Steam sensor program started");
  Serial.println("Reading analog value, higher value indicates higher steam concentration");
  Serial.println("Only output when value changes significantly (reduce noise interference)");
}

void loop() {
  // Multiple samples and average to reduce noise
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += analogRead(STEAM_PIN);
    delayMicroseconds(100);
  }
  int steamValue = sum / 5;  // Calculate average
  
  // Only output when value changes significantly (reduce random output in stable state)
  if (lastValue == -1) {
    // First reading, output directly
    Serial.print("Steam sensor value: ");
    Serial.println(steamValue);
    lastValue = steamValue;
  } else {
    // Calculate change amount
    int change = abs(steamValue - lastValue);
    if (change >= CHANGE_THRESHOLD) {
      Serial.print("Steam sensor value: ");
      Serial.print(steamValue);
      Serial.print(" (change: ");
      Serial.print(change);
      Serial.println(")");
      lastValue = steamValue;
    }
  }
  
  // Delay 200 milliseconds to avoid output too fast
  delay(200);
}
```

## Effect

![Effect](images/TK65-uno.jpg)

![Effect](images/TK65-uno-uart.png)


## Code Walkthrough

**Line 2: Pin definition**

```cpp
#define STEAM_PIN A0   // Arduino analog input pin connected to SIGNAL (e.g. A0)
```

- **`STEAM_PIN`:** The Arduino analog input pin connected to steam sensor SIGNAL. Change this if you use another pin.

**Lines 4–5: Define variables**

```cpp
int lastValue = -1;  // Previous value
const int CHANGE_THRESHOLD = 10;  // Change threshold, only output if change exceeds this value
```

- **`lastValue`:** Stores previous sensor reading, initial value is -1 (indicates first reading).
- **`CHANGE_THRESHOLD`:** Change threshold, only output when sensor value changes exceed 10, used to reduce noise interference.

**Lines 7–15: Initialization (setup function)**

```cpp
void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Steam sensor program started");
  Serial.println("Reading analog value, higher value indicates higher steam concentration");
  Serial.println("Only output when value changes significantly (reduce noise interference)");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`Serial.println(...)`:** Print program start message and instructions to Serial Monitor.

**Lines 17–47: Main loop (loop function)**

```cpp
void loop() {
  // Multiple samples and average to reduce noise
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += analogRead(STEAM_PIN);
    delayMicroseconds(100);
  }
  int steamValue = sum / 5;  // Calculate average
  
  // Only output when value changes significantly (reduce random output in stable state)
  if (lastValue == -1) {
    // First reading, output directly
    Serial.print("Steam sensor value: ");
    Serial.println(steamValue);
    lastValue = steamValue;
  } else {
    // Calculate change amount
    int change = abs(steamValue - lastValue);
    if (change >= CHANGE_THRESHOLD) {
      Serial.print("Steam sensor value: ");
      Serial.print(steamValue);
      Serial.print(" (change: ");
      Serial.print(change);
      Serial.println(")");
      lastValue = steamValue;
    }
  }
  
  // Delay 200 milliseconds to avoid output too fast
  delay(200);
}
```

- **`loop()`:** Runs repeatedly.
- **`for (int i = 0; i < 5; i++)`:** Loop 5 times for sampling, calculate average to reduce noise interference and improve measurement stability.
- **`analogRead(STEAM_PIN)`:** Read STEAM_PIN analog value (0-1023), higher value indicates higher steam concentration.
- **`delayMicroseconds(100)`:** Delay 100 microseconds between each sample to ensure stable sampling.
- **`sum / 5`:** Calculate average of 5 samples to reduce noise interference.
- **`if (lastValue == -1)`:** Check if first reading, if yes then output directly.
- **`abs(steamValue - lastValue)`:** Calculate absolute difference between current value and previous value.
- **`if (change >= CHANGE_THRESHOLD)`:** Only output when change exceeds threshold (10) to avoid frequent output in stable state and reduce noise interference.
- **`Serial.print(...)` and `Serial.println(...)`:** Print steam sensor value and change amount to Serial Monitor.
- **`delay(200)`:** Wait 200 milliseconds before reading again to avoid output too fast and control output frequency.
