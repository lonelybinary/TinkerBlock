# Arduino Uno R3 Example

## Goal

This example shows how to use the TK30 - VIBRATION MOTOR module on an Arduino Uno R3 to control vibration.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 D3
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change this to match your wiring
#define MOTOR_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D3)

void setup() {
  // Set motor pin as output (to control motor vibration)
  pinMode(MOTOR_PIN, OUTPUT);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Vibration motor program started");
}

void loop() {
  // Vibrate for 0.5 seconds
  digitalWrite(MOTOR_PIN, HIGH);  // Output HIGH to start vibration
  Serial.println("Motor vibrating...");
  delay(500);                     // Wait 0.5 seconds
  
  // Stop for 0.5 seconds
  digitalWrite(MOTOR_PIN, LOW);   // Output LOW to stop vibration
  Serial.println("Motor stopped");
  delay(500);                     // Wait 0.5 seconds
}
```

## Effect

![Effect](images/TK30-uno.gif)


## Code Walkthrough

**Line 2: Pin definition**

```cpp
#define MOTOR_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D3)
```

- **`MOTOR_PIN`:** The Arduino digital pin connected to vibration motor SIGNAL. Change this if you use another pin.

**Line 4–10: Initialization (setup function)**

```cpp
void setup() {
  // Set motor pin as output (to control motor vibration)
  pinMode(MOTOR_PIN, OUTPUT);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Vibration motor program started");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`pinMode(MOTOR_PIN, OUTPUT)`:** Set motor pin as output to control motor vibration.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`Serial.println(...)`:** Print program start message to Serial Monitor.

**Line 12–25: Main loop (loop function)**

```cpp
void loop() {
  // Vibrate for 0.5 seconds
  digitalWrite(MOTOR_PIN, HIGH);  // Output HIGH to start vibration
  Serial.println("Motor vibrating...");
  delay(500);                     // Wait 0.5 seconds
  
  // Stop for 0.5 seconds
  digitalWrite(MOTOR_PIN, LOW);   // Output LOW to stop vibration
  Serial.println("Motor stopped");
  delay(500);                     // Wait 0.5 seconds
}
```

- **`loop()`:** Runs repeatedly.
- **`digitalWrite(MOTOR_PIN, HIGH)`:** Output HIGH to start vibration motor.
- **`digitalWrite(MOTOR_PIN, LOW)`:** Output LOW to stop vibration motor.
- **`Serial.println(...)`:** Print motor status to Serial Monitor.
- **`delay(500)`:** Wait 500 milliseconds (0.5 seconds) to control vibration and stop duration.
