# Arduino Uno R3 Example

## Goal

This example shows how to use the TK15 - IR RECEIVER module on an Arduino Uno R3 to detect infrared signals.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 D3
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change this to match your wiring
#define IR_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13  // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(IR_PIN, INPUT);    // Set IR pin as input (to read IR signal)
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}

void loop() {
  // Read IR receiver state
  int irState = digitalRead(IR_PIN);  // Read IR pin level: LOW(0) = signal received, HIGH(1) = no signal
  
  // Control LED based on IR state
  if(irState == LOW) {
    // IR signal received: turn LED on and print message
    digitalWrite(LED_PIN, HIGH);  // Output HIGH to turn LED on
    Serial.println("IR signal received!");  // Display message in Serial Monitor
  } else {
    // No signal received: turn LED off
    digitalWrite(LED_PIN, LOW);   // Output LOW to turn LED off
  }
  
  // Delay 10 milliseconds to avoid reading too fast
  delay(10);
}
```

## Effect

![Effect](images/TK15-uno.gif)


## Code Walkthrough

**Line 2–3: Pin definition**

```cpp
#define IR_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13  // LED pin (Arduino built-in LED on pin 13, or external LED)
```

- **`IR_PIN`:** The Arduino digital pin connected to IR receiver SIGNAL. Change this if you use another pin.
- **`LED_PIN`:** The Arduino digital pin connected to LED (Arduino built-in LED on pin 13, or external LED).

**Line 5–12: Initialization (setup function)**

```cpp
void setup() {
  // Initialize pin modes
  pinMode(IR_PIN, INPUT);    // Set IR pin as input (to read IR signal)
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`pinMode(IR_PIN, INPUT)`:** Set IR pin as input to read IR signal.
- **`pinMode(LED_PIN, OUTPUT)`:** Set LED pin as output to control LED on/off.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.

**Line 14–30: Main loop (loop function)**

```cpp
void loop() {
  // Read IR receiver state
  int irState = digitalRead(IR_PIN);  // Read IR pin level: LOW(0) = signal received, HIGH(1) = no signal
  
  // Control LED based on IR state
  if(irState == LOW) {
    // IR signal received: turn LED on and print message
    digitalWrite(LED_PIN, HIGH);  // Output HIGH to turn LED on
    Serial.println("IR signal received!");  // Display message in Serial Monitor
  } else {
    // No signal received: turn LED off
    digitalWrite(LED_PIN, LOW);   // Output LOW to turn LED off
  }
  
  // Delay 10 milliseconds to avoid reading too fast
  delay(10);
}
```

- **`loop()`:** Runs repeatedly.
- **`digitalRead(IR_PIN)`:** Read IR pin level, LOW(0) means signal received, HIGH(1) means no signal.
- **`if(irState == LOW)`:** Check if IR signal is received; if received, execute LED on operation.
- **`digitalWrite(LED_PIN, HIGH)`:** Output HIGH to turn LED on.
- **`digitalWrite(LED_PIN, LOW)`:** Output LOW to turn LED off.
- **`Serial.println("IR signal received!")`:** Print IR signal received message to Serial Monitor.
- **`delay(10)`:** Wait 10 milliseconds before reading again to avoid reading too fast and reduce CPU usage.
