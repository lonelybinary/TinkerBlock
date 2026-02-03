# Arduino Uno R3 Example

## Goal

This example shows how to use the TK59 - PIEZO SENSOR module on an Arduino Uno R3 to read pressure intensity.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 A0
- **NC** → Not connected (leave floating)

## Code

```cpp
// Pin number: change this to match your wiring
#define PIEZO_PIN A0  // Arduino analog input pin connected to SIGNAL (e.g. A0)

void setup() {
  // Initialize pin mode
  pinMode(PIEZO_PIN, INPUT);   // Set piezoelectric sensor pin as input (to read analog value)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Piezoelectric sensor program started");
  Serial.println("Read pressure intensity value and output via serial");
}

void loop() {
  // Read piezoelectric sensor analog value (0-1023)
  int sensorValue = analogRead(PIEZO_PIN);  // Read sensor pin analog value: 0=no pressure, 1023=maximum pressure
  
  // Convert analog value to voltage value (0-5V)
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Output intensity value
  Serial.print("Pressure intensity: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.println("V");
  
  delay(100);  // Brief delay to avoid reading too fast
}
```

## Effect

![Effect](images/TK59-uno.gif)

![Effect](images/TK59-uno.jpg)


## Code Walkthrough

**Line 2: Pin definition**

```cpp
#define PIEZO_PIN A0  // Arduino analog input pin connected to SIGNAL (e.g. A0)
```

- **`PIEZO_PIN`:** The Arduino analog input pin connected to piezoelectric sensor SIGNAL. Change this if you use another pin.

**Lines 4–12: Initialization (setup function)**

```cpp
void setup() {
  // Initialize pin mode
  pinMode(PIEZO_PIN, INPUT);   // Set piezoelectric sensor pin as input (to read analog value)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Piezoelectric sensor program started");
  Serial.println("Read pressure intensity value and output via serial");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`pinMode(PIEZO_PIN, INPUT)`:** Set piezoelectric sensor pin as input to read analog value.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`Serial.println(...)`:** Print program start message and instructions to Serial Monitor.

**Lines 14–30: Main loop (loop function)**

```cpp
void loop() {
  // Read piezoelectric sensor analog value (0-1023)
  int sensorValue = analogRead(PIEZO_PIN);  // Read sensor pin analog value: 0=no pressure, 1023=maximum pressure
  
  // Convert analog value to voltage value (0-5V)
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Output intensity value
  Serial.print("Pressure intensity: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.println("V");
  
  delay(100);  // Brief delay to avoid reading too fast
}
```

- **`loop()`:** Runs repeatedly.
- **`analogRead(PIEZO_PIN)`:** Read sensor pin analog value (0-1023), 0 means no pressure, 1023 means maximum pressure.
- **`sensorValue * (5.0 / 1023.0)`:** Convert analog value (0-1023) to voltage value (0-5V).
- **`Serial.print(...)` and `Serial.println(...)`:** Print pressure intensity and voltage value to Serial Monitor (voltage value with 3 decimal places).
- **`delay(100)`:** Wait 100 milliseconds before reading again to avoid reading too fast and control output frequency.
