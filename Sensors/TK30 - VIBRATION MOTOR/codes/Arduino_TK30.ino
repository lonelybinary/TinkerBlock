/*
 * TK30-VIBRATION MOTOR - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK30-VIBRATION MOTOR module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change this to match your wiring
#define MOTOR_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D3)

void setup() {
  // Set motor pin as output (to control motor vibration)
  pinMode(MOTOR_PIN, OUTPUT);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Vibration motor program started");
}

void loop() {
  // Vibrate for 0.5 seconds
  digitalWrite(MOTOR_PIN, HIGH);  // Output HIGH to start vibration
  Serial.println("Motor vibrating...");
  delay(500);                     // Wait 0.5 seconds
  
  // Stop for 0.5 seconds
  digitalWrite(MOTOR_PIN, LOW);   // Output LOW to stop vibration
  Serial.println("Motor stopped");
  delay(500);                     // Wait 0.5 seconds
}
