# Arduino Uno R3 Example

## Goal

This example shows how to use the TK96 - MECHANICAL KEY AND LED module on an Arduino Uno R3 to detect key presses and control LED.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 D2
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change this to match your wiring
#define BUTTON_PIN 2   // Arduino digital pin connected to BUTTON (e.g. D2)
#define LED_PIN 13     // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Set button pin as input mode, enable internal pull-up resistor
  pinMode(LED_PIN, OUTPUT);           // Set LED pin as output mode (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Mechanical key program started");
  Serial.println("LED on when key pressed, LED off when key released");
}

void loop() {
  // Read button state
  int buttonState = digitalRead(BUTTON_PIN);  // Read button pin level: LOW(0)=pressed, HIGH(1)=released
  
  // Control LED based on button state
  if (buttonState == LOW) {
    // Key pressed: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Key pressed - LED on");
  } else {
    // Key released: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("Key released - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
```

## Effect

![Effect](images/TK96-uno.gif)


## Code Walkthrough

**Lines 2–3: Pin definition**

```cpp
#define BUTTON_PIN 2   // Arduino digital pin connected to BUTTON (e.g. D2)
#define LED_PIN 13     // LED pin (Arduino built-in LED on pin 13, or external LED)
```

- **`BUTTON_PIN`:** The Arduino digital pin connected to button SIGNAL. Change this if you use another pin.
- **`LED_PIN`:** The Arduino digital pin connected to LED (built-in LED pin, or external LED).

**Lines 5–15: Initialization (setup function)**

```cpp
void setup() {
  // Initialize pin modes
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Set button pin as input mode, enable internal pull-up resistor
  pinMode(LED_PIN, OUTPUT);           // Set LED pin as output mode (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Mechanical key program started");
  Serial.println("LED on when key pressed, LED off when key released");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`pinMode(BUTTON_PIN, INPUT_PULLUP)`:** Set BUTTON_PIN as INPUT_PULLUP mode, enable internal pull-up resistor. Pin is HIGH when key not pressed, LOW when pressed.
- **`pinMode(LED_PIN, OUTPUT)`:** Set LED_PIN as OUTPUT mode to control LED on/off.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`Serial.println(...)`:** Print program start message and instructions to Serial Monitor.

**Lines 17–33: Main loop (loop function)**

```cpp
void loop() {
  // Read button state
  int buttonState = digitalRead(BUTTON_PIN);  // Read button pin level: LOW(0)=pressed, HIGH(1)=released
  
  // Control LED based on button state
  if (buttonState == LOW) {
    // Key pressed: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Key pressed - LED on");
  } else {
    // Key released: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("Key released - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
```

- **`loop()`:** Runs repeatedly.
- **`digitalRead(BUTTON_PIN)`:** Read BUTTON_PIN level, LOW(0) means key pressed, HIGH(1) means key released (due to INPUT_PULLUP, pressed is LOW).
- **`if (buttonState == LOW)`:** Check if key is pressed; if pressed, execute LED on operation.
- **`digitalWrite(LED_PIN, HIGH)`:** Set LED_PIN to HIGH, turn LED on.
- **`digitalWrite(LED_PIN, LOW)`:** Set LED_PIN to LOW, turn LED off.
- **`Serial.println(...)`:** Print button state and LED status to Serial Monitor.
- **`delay(100)`:** Wait 100 milliseconds before reading again to avoid reading too fast and reduce CPU usage.
