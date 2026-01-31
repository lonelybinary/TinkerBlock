# Arduino Uno R3 Example

## Goal

This example shows how to blink the TK01-XL LED on an Arduino Uno R3 and covers basic Arduino structure (setup, loop), digital output, serial print, and delay.

## Wiring

- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 D13 (or the digital pin you set as `LED_PIN` in code)
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change this to match your wiring
#define LED_PIN 13  // Arduino digital pin connected to SIGNAL (e.g. D13)

void setup() {
  // Set LED pin as output (to control on/off)
  pinMode(LED_PIN, OUTPUT);

  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}

void loop() {
  // Blink: turn LED on
  digitalWrite(LED_PIN, HIGH);  // Output HIGH to turn LED on
  Serial.println("LED on");
  delay(1000);                  // Wait 1 second

  digitalWrite(LED_PIN, LOW);   // Output LOW to turn LED off
  Serial.println("LED off");
  delay(1000);                  // Wait 1 second
}
```

# Code Walkthrough

**Line 1: Pin definition**

```cpp
#define LED_PIN 13  // Arduino digital pin connected to SIGNAL (e.g. D13)
```

- **`LED_PIN 13`:** The Arduino digital pin connected to SIGNAL. Change this if you use another pin.

**Lines 3–7: Initialization (setup)**

```cpp
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`pinMode(LED_PIN, OUTPUT)`:** Set the LED pin as output.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.

**Lines 9–16: Main loop (loop)**

```cpp
void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED on");
  delay(1000);

  digitalWrite(LED_PIN, LOW);
  Serial.println("LED off");
  delay(1000);
}
```

- **`loop()`:** Runs repeatedly.
- **`digitalWrite(LED_PIN, HIGH)`:** Turn LED on (output HIGH).
- **`Serial.println("LED on")`:** Print to the Serial Monitor.
- **`delay(1000)`:** Wait 1 second.
- **`digitalWrite(LED_PIN, LOW)`:** Turn LED off (output LOW).
