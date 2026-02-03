# Arduino Uno R3 Example

## Goal

This example shows how to use the TK41 - MAGNETIC SWITCH module on an Arduino Uno R3 to detect magnetic fields.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 D2
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change this to match your wiring
#define REED_PIN 2   // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13   // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(REED_PIN, INPUT);   // Set magnetic switch pin as input (to read detection state)
  pinMode(LED_PIN, OUTPUT);   // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Magnetic switch program started");
  Serial.println("LED on when magnetic field detected, LED off when no magnetic field");
}

void loop() {
  // Read magnetic switch state
  int reedState = digitalRead(REED_PIN);  // Read switch pin level: HIGH(1) = magnetic field detected, LOW(0) = no magnetic field
  
  // Control LED based on detection state
  if (reedState == HIGH) {
    // Magnetic field detected: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Magnetic field detected - LED on");
  } else {
    // No magnetic field detected: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("No magnetic field detected - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
```

## Effect

![Effect](images/TK41-uno.gif)


## Code Walkthrough

**Line 2–3: Pin definition**

```cpp
#define REED_PIN 2   // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13   // LED pin (Arduino built-in LED on pin 13, or external LED)
```

- **`REED_PIN`:** The Arduino digital pin connected to magnetic switch (reed switch) SIGNAL. Change this if you use another pin.
- **`LED_PIN`:** The Arduino digital pin connected to LED (Arduino built-in LED on pin 13, or external LED).

**Line 5–15: Initialization (setup function)**

```cpp
void setup() {
  // Initialize pin modes
  pinMode(REED_PIN, INPUT);   // Set magnetic switch pin as input (to read detection state)
  pinMode(LED_PIN, OUTPUT);   // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Magnetic switch program started");
  Serial.println("LED on when magnetic field detected, LED off when no magnetic field");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`pinMode(REED_PIN, INPUT)`:** Set magnetic switch pin as input to read detection state.
- **`pinMode(LED_PIN, OUTPUT)`:** Set LED pin as output to control LED on/off.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`Serial.println(...)`:** Print program start message and instructions to Serial Monitor.

**Line 17–33: Main loop (loop function)**

```cpp
void loop() {
  // Read magnetic switch state
  int reedState = digitalRead(REED_PIN);  // Read switch pin level: HIGH(1) = magnetic field detected, LOW(0) = no magnetic field
  
  // Control LED based on detection state
  if (reedState == HIGH) {
    // Magnetic field detected: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Magnetic field detected - LED on");
  } else {
    // No magnetic field detected: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("No magnetic field detected - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
```

- **`loop()`:** Runs repeatedly.
- **`digitalRead(REED_PIN)`:** Read switch pin level, HIGH(1) means magnetic field detected (reed switch closed), LOW(0) means no magnetic field (reed switch open).
- **`if (reedState == HIGH)`:** Check if magnetic field is detected; if detected, execute LED on operation.
- **`digitalWrite(LED_PIN, HIGH)`:** Output HIGH to turn LED on.
- **`digitalWrite(LED_PIN, LOW)`:** Output LOW to turn LED off.
- **`Serial.println(...)`:** Print detection state and LED status to Serial Monitor.
- **`delay(100)`:** Wait 100 milliseconds before reading again to avoid reading too fast and reduce CPU usage.
