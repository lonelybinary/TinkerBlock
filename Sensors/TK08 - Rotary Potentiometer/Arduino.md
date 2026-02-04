# Arduino Uno R3 Example

## Goal

This example shows how to use the TK08 - ROTARY POTENTIOMETER module on an Arduino Uno R3 to control LED brightness by rotating the potentiometer knob.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 A0 (or the analog pin you set as `POT_PIN` in code)
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change this to match your wiring
#define POT_PIN A0   // SIGNAL pin connected to Arduino analog input pin (e.g. A0)
#define LED_PIN 9    // LED pin (must use PWM pin, e.g. D9)

void setup() {
  // Initialize pin modes
  pinMode(POT_PIN, INPUT);   // Set potentiometer pin as input (to read analog value)
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output (to control LED brightness)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Rotary potentiometer program started");
  Serial.println("Rotate potentiometer to adjust LED brightness");
}

void loop() {
  // Read potentiometer analog value (0-1023)
  int potValue = analogRead(POT_PIN);  // Read potentiometer pin value: 0 = leftmost, 1023 = rightmost, 512 = middle
  
  // Map potentiometer value (0-1023) to LED brightness (0-255)
  int brightness = map(potValue, 0, 1023, 0, 255);
  
  // Use PWM to control LED brightness
  analogWrite(LED_PIN, brightness);
  
  // Print potentiometer value and LED brightness
  Serial.print("Potentiometer value: ");
  Serial.print(potValue);
  Serial.print(" | LED brightness: ");
  Serial.println(brightness);
  
  delay(100);  // Brief delay to avoid reading too fast
}
```

## Effect

![Effect](images/TK08-uno.gif)


## Code Walkthrough

**Line 2–3: Pin definition**

```cpp
#define POT_PIN A0   // SIGNAL pin connected to Arduino analog input pin (e.g. A0)
#define LED_PIN 9    // LED pin (must use PWM pin, e.g. D9)
```

- **`POT_PIN`:** The Arduino analog input pin connected to rotary potentiometer SIGNAL. Change this if you use another pin.
- **`LED_PIN`:** The Arduino digital pin connected to LED (must be PWM pin). Change this if you use another pin.

**Line 5–15: Initialization (setup function)**

```cpp
void setup() {
  // Initialize pin modes
  pinMode(POT_PIN, INPUT);   // Set potentiometer pin as input (to read analog value)
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output (to control LED brightness)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Rotary potentiometer program started");
  Serial.println("Rotate potentiometer to adjust LED brightness");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`pinMode(POT_PIN, INPUT)`:** Set potentiometer pin as input to read analog value.
- **`pinMode(LED_PIN, OUTPUT)`:** Set LED pin as output to control LED brightness.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`Serial.println(...)`:** Print program start message and instructions to the Serial Monitor.

**Line 17–34: Main loop (loop function)**

```cpp
void loop() {
  // Read potentiometer analog value (0-1023)
  int potValue = analogRead(POT_PIN);  // Read potentiometer pin value: 0 = leftmost, 1023 = rightmost, 512 = middle
  
  // Map potentiometer value (0-1023) to LED brightness (0-255)
  int brightness = map(potValue, 0, 1023, 0, 255);
  
  // Use PWM to control LED brightness
  analogWrite(LED_PIN, brightness);
  
  // Print potentiometer value and LED brightness
  Serial.print("Potentiometer value: ");
  Serial.print(potValue);
  Serial.print(" | LED brightness: ");
  Serial.println(brightness);
  
  delay(100);  // Brief delay to avoid reading too fast
}
```

- **`loop()`:** Runs repeatedly.
- **`analogRead(POT_PIN)`:** Read potentiometer analog value (0-1023), 0 means leftmost, 1023 means rightmost, 512 means middle.
- **`map(potValue, 0, 1023, 0, 255)`:** Map potentiometer value (0-1023) to LED brightness (0-255) for PWM control.
- **`analogWrite(LED_PIN, brightness)`:** Use PWM to control LED brightness (0-255).
- **`Serial.print(...)` and `Serial.println(...)`:** Print potentiometer value and LED brightness to the Serial Monitor.
- **`delay(100)`:** Wait 100 milliseconds before reading again to avoid reading too fast and control output frequency.
