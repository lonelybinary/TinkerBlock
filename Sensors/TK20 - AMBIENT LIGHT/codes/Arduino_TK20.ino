/*
 * TK20-AMBIENT LIGHT - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK20-AMBIENT LIGHT module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change this to match your wiring
#define LIGHT_PIN A0  // Arduino analog input pin connected to SIGNAL (e.g. A0)

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}

void loop() {
  // Read ambient light sensor analog value (0-1023)
  int lightValue = analogRead(LIGHT_PIN);  // Read analog value: 0 = darkest, 1023 = brightest
  
  // Convert analog value to voltage (0-5V)
  float voltage = lightValue * (5.0 / 1023.0);
  
  // Display values in Serial Monitor
  Serial.print("Light value: ");
  Serial.print(lightValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.println("V");
  
  // Judge light intensity
  if(lightValue > 500) {
    Serial.println("Bright");
  } else if(lightValue > 200) {
    Serial.println("Moderate");
  } else {
    Serial.println("Dark");
  }
  
  // Delay 100 milliseconds to avoid printing too fast
  delay(100);
}
