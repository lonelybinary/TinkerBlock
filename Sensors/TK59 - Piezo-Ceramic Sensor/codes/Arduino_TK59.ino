/*
 * TK59-PIEZO SENSOR - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK59-PIEZO SENSOR module
 * - Read pressure intensity value and output via serial
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Tap the sensor and observe intensity value changes
 */

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
