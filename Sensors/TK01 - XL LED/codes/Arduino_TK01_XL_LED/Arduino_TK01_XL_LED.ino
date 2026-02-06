/*
 * TK01-XL LED - Arduino Uno R3 Example
 *
 * Description:
 * This sketch demonstrates how to use the TK01-XL LED module.
 *
 * Wiring:
 * Change the pin definition in code to match your wiring.
 *
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change this to match your wiring
#define LED_PIN 13  // Arduino digital pin connected to SIGNAL (e.g. D13)

void setup() {
  // Set LED pin as output (to control on/off)
  pinMode(LED_PIN, OUTPUT);

  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}

void loop() {
  // Blink: turn LED on
  digitalWrite(LED_PIN, HIGH);  // Output HIGH to turn LED on
  Serial.println("LED on");
  delay(1000);                  // Wait 1 second

  digitalWrite(LED_PIN, LOW);   // Output LOW to turn LED off
  Serial.println("LED off");
  delay(1000);                  // Wait 1 second
}
