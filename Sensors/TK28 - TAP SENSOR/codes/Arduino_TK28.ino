/*
 * TK28-TAP SENSOR - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK28-TAP SENSOR module to control LED
 * - LED on when tap detected, LED off when no tap detected
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Tap the sensor and observe LED state
 */

// Pin number: change this to match your wiring
#define TAP_PIN 2      // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13     // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(TAP_PIN, INPUT);   // Set tap sensor pin as input (to read detection state)
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Tap sensor program started");
  Serial.println("LED on when tap detected, LED off when no tap");
}

void loop() {
  // Read tap sensor state
  int tapState = digitalRead(TAP_PIN);  // Read sensor pin level: HIGH(1) = tap, LOW(0) = no tap
  
  // Control LED based on detection state
  if (tapState == HIGH) {
    // Tap detected: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Tap detected - LED on");
  } else {
    // No tap detected: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("No tap detected - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
