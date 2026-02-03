/*
 * TK36-ACTIVE BUZZER - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK36-ACTIVE BUZZER module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change this to match your wiring
#define BUZZER_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D3)

void setup() {
  // Initialize pin mode
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Active buzzer program started");
}

void loop() {
  // Buzzer on for 0.5 seconds
  digitalWrite(BUZZER_PIN, HIGH);  // Turn on buzzer
  Serial.println("Buzzer on");
  delay(500);  // Wait 0.5 seconds
  
  // Buzzer off for 0.5 seconds
  digitalWrite(BUZZER_PIN, LOW);   // Turn off buzzer
  Serial.println("Buzzer off");
  delay(500);  // Wait 0.5 seconds
}
