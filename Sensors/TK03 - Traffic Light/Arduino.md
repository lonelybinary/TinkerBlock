# Arduino Uno R3 Example

## Goal

This example shows how to use the TK03 - TRAFFIC LIGHT module on an Arduino Uno R3 to simulate traffic light behavior.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **GND** → Arduino Uno R3 GND
- **RED** → Arduino Uno R3 D2
- **YELLOW** → Arduino Uno R3 D3
- **GREEN** → Arduino Uno R3 D4
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change this to match your wiring
#define RED_PIN 2     // RED pin connected to Arduino digital pin (e.g. D2)
#define YELLOW_PIN 3  // YELLOW pin connected to Arduino digital pin (e.g. D3)
#define GREEN_PIN 4   // GREEN pin connected to Arduino digital pin (e.g. D4)

void setup() {
  // Set LED pins as output (to control LED on/off)
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  // Initialize: all LEDs off
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  
  Serial.println("Traffic light program started");
}

void loop() {
  // Red light on (5 seconds)
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("Red light on - stop");
  delay(5000);
  
  // Green light on (5 seconds)
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  Serial.println("Green light on - go");
  delay(5000);
  
  // Yellow light on (2 seconds)
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("Yellow light on - warning");
  delay(2000);
  
  // Loop back to red light
}
```

## Effect

![Effect](images/TK03-uno.gif)


## Code Walkthrough

**Line 2–4: Pin definition**

```cpp
#define RED_PIN 2     // RED pin connected to Arduino digital pin (e.g. D2)
#define YELLOW_PIN 3  // YELLOW pin connected to Arduino digital pin (e.g. D3)
#define GREEN_PIN 4   // GREEN pin connected to Arduino digital pin (e.g. D4)
```

- **`RED_PIN`:** The Arduino digital pin connected to RED LED. Change this if you use another pin.
- **`YELLOW_PIN`:** The Arduino digital pin connected to YELLOW LED. Change this if you use another pin.
- **`GREEN_PIN`:** The Arduino digital pin connected to GREEN LED. Change this if you use another pin.

**Line 6–21: Initialization (setup function)**

```cpp
void setup() {
  // Set LED pins as output (to control LED on/off)
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  // Initialize: all LEDs off
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  
  Serial.println("Traffic light program started");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`pinMode(RED_PIN, OUTPUT)`:** Set red LED pin as output to control LED on/off.
- **`pinMode(YELLOW_PIN, OUTPUT)`:** Set yellow LED pin as output to control LED on/off.
- **`pinMode(GREEN_PIN, OUTPUT)`:** Set green LED pin as output to control LED on/off.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`digitalWrite(..., LOW)`:** Initialize all LEDs to off state, ensuring all lights are off when the program starts.
- **`Serial.println("Traffic light program started")`:** Print program start message to the Serial Monitor.

**Line 23–46: Main loop (loop function)**

```cpp
void loop() {
  // Red light on (5 seconds)
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("Red light on - stop");
  delay(5000);
  
  // Green light on (5 seconds)
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  Serial.println("Green light on - go");
  delay(5000);
  
  // Yellow light on (2 seconds)
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("Yellow light on - warning");
  delay(2000);
}
```

- **`loop()`:** Runs repeatedly.
- **Red light phase:**
  - **`digitalWrite(RED_PIN, HIGH)`:** Output HIGH to turn red light on.
  - **`digitalWrite(YELLOW_PIN, LOW)`, `digitalWrite(GREEN_PIN, LOW)`:** Output LOW to turn yellow and green lights off.
  - **`Serial.println("Red light on - stop")`:** Print status message to the Serial Monitor.
  - **`delay(5000)`:** Wait 5000 milliseconds (5 seconds).
- **Green light phase:**
  - **`digitalWrite(GREEN_PIN, HIGH)`:** Output HIGH to turn green light on.
  - **`digitalWrite(RED_PIN, LOW)`, `digitalWrite(YELLOW_PIN, LOW)`:** Output LOW to turn red and yellow lights off.
  - **`Serial.println("Green light on - go")`:** Print status message to the Serial Monitor.
  - **`delay(5000)`:** Wait 5000 milliseconds (5 seconds).
- **Yellow light phase:**
  - **`digitalWrite(YELLOW_PIN, HIGH)`:** Output HIGH to turn yellow light on.
  - **`digitalWrite(RED_PIN, LOW)`, `digitalWrite(GREEN_PIN, LOW)`:** Output LOW to turn red and green lights off.
  - **`Serial.println("Yellow light on - warning")`:** Print status message to the Serial Monitor.
  - **`delay(2000)`:** Wait 2000 milliseconds (2 seconds).
- **Loop:** The program loops back to the red light phase, forming a complete traffic light cycle.
