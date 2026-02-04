# Arduino Uno R3 Example

## Goal

This example shows how to use the TK62 - TILT SENSOR module on an Arduino Uno R3 to detect tilt and control LED.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 D2
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change this to match your wiring
#define TILT_PIN 2     // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13     // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(TILT_PIN, INPUT);   // Set tilt sensor pin as input (to read detection state)
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Tilt sensor program started");
  Serial.println("LED on when tilt detected, LED off when level");
}

void loop() {
  // Read tilt sensor state
  int tiltState = digitalRead(TILT_PIN);  // Read sensor pin level: HIGH(1)=tilt, LOW(0)=level
  
  // Control LED based on detection state
  if (tiltState == HIGH) {
    // Tilt detected: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Tilt detected - LED on");
  } else {
    // Level state: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("Level state - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
```

## Effect

![Effect](images/TK62-uno.gif)


## Code Walkthrough

**Lines 2–3: Pin definition**

```cpp
#define TILT_PIN 2     // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13     // LED pin (Arduino built-in LED on pin 13, or external LED)
```

- **`TILT_PIN`:** The Arduino digital pin connected to tilt sensor SIGNAL. Change this if you use another pin.
- **`LED_PIN`:** The Arduino digital pin connected to LED (Arduino built-in LED on pin 13, or external LED).

**Lines 5–15: Initialization (setup function)**

```cpp
void setup() {
  // Initialize pin modes
  pinMode(TILT_PIN, INPUT);   // Set tilt sensor pin as input (to read detection state)
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Tilt sensor program started");
  Serial.println("LED on when tilt detected, LED off when level");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`pinMode(TILT_PIN, INPUT)`:** Set tilt sensor pin as input to read detection state.
- **`pinMode(LED_PIN, OUTPUT)`:** Set LED pin as output to control LED on/off.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`Serial.println(...)`:** Print program start message and instructions to Serial Monitor.

**Lines 17–33: Main loop (loop function)**

```cpp
void loop() {
  // Read tilt sensor state
  int tiltState = digitalRead(TILT_PIN);  // Read sensor pin level: HIGH(1)=tilt, LOW(0)=level
  
  // Control LED based on detection state
  if (tiltState == HIGH) {
    // Tilt detected: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Tilt detected - LED on");
  } else {
    // Level state: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("Level state - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
```

- **`loop()`:** Runs repeatedly.
- **`digitalRead(TILT_PIN)`:** Read sensor pin level, HIGH(1) means tilt detected, LOW(0) means level.
- **`if (tiltState == HIGH)`:** Check if tilt is detected; if detected, execute LED on operation.
- **`digitalWrite(LED_PIN, HIGH)`:** Output HIGH to turn LED on.
- **`digitalWrite(LED_PIN, LOW)`:** Output LOW to turn LED off.
- **`Serial.println(...)`:** Print detection state and LED status to Serial Monitor.
- **`delay(100)`:** Wait 100 milliseconds before reading again to avoid reading too fast and reduce CPU usage.
