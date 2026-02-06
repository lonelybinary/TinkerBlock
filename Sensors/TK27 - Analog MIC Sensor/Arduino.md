# Arduino Uno R3 Example

## Goal

This example shows how to use the TK27 - ANALOG MIC SENSOR module on an Arduino Uno R3 to detect sound intensity.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 A0
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change this to match your wiring
#define MIC_PIN A0  // Arduino analog input pin connected to SIGNAL (e.g. A0)

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}

void loop() {
  // Read microphone sensor analog value (0-1023)
  int micValue = analogRead(MIC_PIN);  // Read analog value: 0 = quietest, 1023 = loudest
  
  // Convert analog value to voltage (0-5V)
  float voltage = micValue * (5.0 / 1023.0);
  
  // Display values in Serial Monitor
  Serial.print("Sound value: ");
  Serial.print(micValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.println("V");
  
  // Judge sound intensity
  if(micValue > 500) {
    Serial.println("Very loud");
  } else if(micValue > 200) {
    Serial.println("Moderate");
  } else {
    Serial.println("Very quiet");
  }
  
  // Delay 100 milliseconds to avoid printing too fast
  delay(100);
}
```

## Effect

![Effect](images/TK27-uno.jpg)


## Code Walkthrough

**Line 2: Pin definition**

```cpp
#define MIC_PIN A0  // Arduino analog input pin connected to SIGNAL (e.g. A0)
```

- **`MIC_PIN`:** The Arduino analog input pin connected to analog microphone sensor SIGNAL. Change this if you use another pin.

**Line 4–7: Initialization (setup function)**

```cpp
void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.

**Line 9–34: Main loop (loop function)**

```cpp
void loop() {
  // Read microphone sensor analog value (0-1023)
  int micValue = analogRead(MIC_PIN);  // Read analog value: 0 = quietest, 1023 = loudest
  
  // Convert analog value to voltage (0-5V)
  float voltage = micValue * (5.0 / 1023.0);
  
  // Display values in Serial Monitor
  Serial.print("Sound value: ");
  Serial.print(micValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.println("V");
  
  // Judge sound intensity
  if(micValue > 500) {
    Serial.println("Very loud");
  } else if(micValue > 200) {
    Serial.println("Moderate");
  } else {
    Serial.println("Very quiet");
  }
  
  // Delay 100 milliseconds to avoid printing too fast
  delay(100);
}
```

- **`loop()`:** Runs repeatedly.
- **`analogRead(MIC_PIN)`:** Read microphone sensor analog value (0-1023), 0 means quietest, 1023 means loudest.
- **`micValue * (5.0 / 1023.0)`:** Convert analog value (0-1023) to voltage value (0-5V).
- **`if(micValue > 500)`:** Judge sound intensity; if greater than 500, display "Very loud".
- **`else if(micValue > 200)`:** If sound value is between 200-500, display "Moderate".
- **`else`:** If sound value is less than 200, display "Very quiet".
- **`Serial.print(...)` and `Serial.println(...)`:** Print sound value, voltage value, and sound status to Serial Monitor.
- **`delay(100)`:** Wait 100 milliseconds before reading again to avoid printing too fast and control output frequency.
