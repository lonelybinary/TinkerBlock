/*
 * TK27-ANALOG MIC SENSOR - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK27-ANALOG MIC SENSOR module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

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
