# Arduino Uno R3 Example

## Goal

This example shows how to use the TK19 - 4-DIRECTIONs TIL SENSOR module on an Arduino Uno R3 to detect tilt in four directions.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change these to match your wiring
#define A_PIN 2      // Arduino digital pin connected to A (as common, output LOW)
#define B_PIN 3      // Arduino digital pin connected to B (INPUT_PULLUP, detect direction B)
#define C_PIN 4      // Arduino digital pin connected to C (INPUT_PULLUP, detect direction C)
#define D_PIN 5      // Arduino digital pin connected to D (INPUT_PULLUP, detect direction D)

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  // Initialize pin modes
  pinMode(A_PIN, OUTPUT);        // Set A pin as output (as common)
  pinMode(B_PIN, INPUT_PULLUP);  // Set B pin as INPUT_PULLUP (detect direction B tilt)
  pinMode(C_PIN, INPUT_PULLUP);  // Set C pin as INPUT_PULLUP (detect direction C tilt)
  pinMode(D_PIN, INPUT_PULLUP);  // Set D pin as INPUT_PULLUP (detect direction D tilt)
  
  // Set A pin to LOW (as common/ground)
  digitalWrite(A_PIN, LOW);
  
  Serial.println("4-direction tilt sensor program started");
  Serial.println("Detecting tilt status in four directions");
  Serial.println("A pin as common (LOW), B/C/D pins detect tilt (LOW=tilt)");
}

void loop() {
  // Read tilt status of three directions
  // When B/C/D pins read LOW, it means tilt detected in corresponding direction
  int bState = digitalRead(B_PIN);   // Read B pin: LOW(0) = direction B tilt, HIGH(1) = no tilt
  int cState = digitalRead(C_PIN);   // Read C pin: LOW(0) = direction C tilt, HIGH(1) = no tilt
  int dState = digitalRead(D_PIN);   // Read D pin: LOW(0) = direction D tilt, HIGH(1) = no tilt
  
  // Detect and output tilt direction
  bool tilted = false;  // Flag to mark if tilt is detected
  
  if (bState == LOW) {
    Serial.println("Detected: Direction B tilt");
    tilted = true;
  }
  
  if (cState == LOW) {
    Serial.println("Detected: Direction C tilt");
    tilted = true;
  }
  
  if (dState == LOW) {
    Serial.println("Detected: Direction D tilt");
    tilted = true;
  }
  
  // If no direction is tilted, show level status
  if (!tilted) {
    Serial.println("Level");
  }
  
  // Display all pin states (for debugging)
  Serial.print("State: B=");
  Serial.print(bState);
  Serial.print("(LOW=tilt), C=");
  Serial.print(cState);
  Serial.print("(LOW=tilt), D=");
  Serial.print(dState);
  Serial.println("(LOW=tilt)");
  
  Serial.println("---");
  
  // Delay 100 milliseconds to avoid output too fast
  delay(100);
}
```

## Effect

![Effect](images/TK19-uno.gif)


## Code Walkthrough

**Line 2–5: Pin definition**

```cpp
#define A_PIN 2      // Arduino digital pin connected to A (as common, output LOW)
#define B_PIN 3      // Arduino digital pin connected to B (INPUT_PULLUP, detect direction B)
#define C_PIN 4      // Arduino digital pin connected to C (INPUT_PULLUP, detect direction C)
#define D_PIN 5      // Arduino digital pin connected to D (INPUT_PULLUP, detect direction D)
```

- **`A_PIN`:** The Arduino digital pin connected to A (as common, output LOW). Change this if you use another pin.
- **`B_PIN`:** The Arduino digital pin connected to B (INPUT_PULLUP, detect direction B tilt). Change this if you use another pin.
- **`C_PIN`:** The Arduino digital pin connected to C (INPUT_PULLUP, detect direction C tilt). Change this if you use another pin.
- **`D_PIN`:** The Arduino digital pin connected to D (INPUT_PULLUP, detect direction D tilt). Change this if you use another pin.

**Line 7–23: Initialization (setup function)**

```cpp
void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  // Initialize pin modes
  pinMode(A_PIN, OUTPUT);        // Set A pin as output (as common)
  pinMode(B_PIN, INPUT_PULLUP);  // Set B pin as INPUT_PULLUP (detect direction B tilt)
  pinMode(C_PIN, INPUT_PULLUP);  // Set C pin as INPUT_PULLUP (detect direction C tilt)
  pinMode(D_PIN, INPUT_PULLUP);  // Set D pin as INPUT_PULLUP (detect direction D tilt)
  
  // Set A pin to LOW (as common/ground)
  digitalWrite(A_PIN, LOW);
  
  Serial.println("4-direction tilt sensor program started");
  Serial.println("Detecting tilt status in four directions");
  Serial.println("A pin as common (LOW), B/C/D pins detect tilt (LOW=tilt)");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`pinMode(A_PIN, OUTPUT)`:** Set A pin as output (as common).
- **`pinMode(B_PIN, INPUT_PULLUP)`:** Set B pin as INPUT_PULLUP (detect direction B tilt).
- **`pinMode(C_PIN, INPUT_PULLUP)`:** Set C pin as INPUT_PULLUP (detect direction C tilt).
- **`pinMode(D_PIN, INPUT_PULLUP)`:** Set D pin as INPUT_PULLUP (detect direction D tilt).
- **`digitalWrite(A_PIN, LOW)`:** Set A pin to LOW (as common/ground) for tilt detection.
- **`Serial.println(...)`:** Print program start message and instructions to Serial Monitor.

**Line 25–68: Main loop (loop function)**

```cpp
void loop() {
  // Read tilt status of three directions
  // When B/C/D pins read LOW, it means tilt detected in corresponding direction
  int bState = digitalRead(B_PIN);   // Read B pin: LOW(0) = direction B tilt, HIGH(1) = no tilt
  int cState = digitalRead(C_PIN);   // Read C pin: LOW(0) = direction C tilt, HIGH(1) = no tilt
  int dState = digitalRead(D_PIN);   // Read D pin: LOW(0) = direction D tilt, HIGH(1) = no tilt
  
  // Detect and output tilt direction
  bool tilted = false;  // Flag to mark if tilt is detected
  
  if (bState == LOW) {
    Serial.println("Detected: Direction B tilt");
    tilted = true;
  }
  
  if (cState == LOW) {
    Serial.println("Detected: Direction C tilt");
    tilted = true;
  }
  
  if (dState == LOW) {
    Serial.println("Detected: Direction D tilt");
    tilted = true;
  }
  
  // If no direction is tilted, show level status
  if (!tilted) {
    Serial.println("Level");
  }
  
  // Display all pin states (for debugging)
  Serial.print("State: B=");
  Serial.print(bState);
  Serial.print("(LOW=tilt), C=");
  Serial.print(cState);
  Serial.print("(LOW=tilt), D=");
  Serial.print(dState);
  Serial.println("(LOW=tilt)");
  
  Serial.println("---");
  
  // Delay 100 milliseconds to avoid output too fast
  delay(100);
}
```

- **`loop()`:** Runs repeatedly.
- **`digitalRead(B_PIN)`、`digitalRead(C_PIN)`、`digitalRead(D_PIN)`:** Read tilt status of three directions, LOW(0) means tilt detected in corresponding direction, HIGH(1) means no tilt.
- **`bool tilted = false`:** Flag to mark if tilt is detected, used to determine if any direction is tilted.
- **`if (bState == LOW)`、`if (cState == LOW)`、`if (dState == LOW)`:** Check if each direction is tilted; if detected, print corresponding direction info and set tilted to true.
- **`if (!tilted)`:** If no direction is tilted, show level status.
- **`Serial.print(...)` and `Serial.println(...)`:** Print tilt direction and all pin states to Serial Monitor (for debugging).
- **`delay(100)`:** Wait 100 milliseconds before reading again to avoid output too fast and control output frequency.
