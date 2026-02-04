/*
 * TK41-MAGNETIC SWITCH - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK41-MAGNETIC SWITCH module to control LED
 * - LED on when magnetic field detected, LED off when no magnetic field detected
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Bring magnet close to sensor and observe LED state
 */

// Pin number: change this to match your wiring
#define REED_PIN 2   // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13   // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(REED_PIN, INPUT);   // Set magnetic switch pin as input (to read detection state)
  pinMode(LED_PIN, OUTPUT);   // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Magnetic switch program started");
  Serial.println("LED on when magnetic field detected, LED off when no magnetic field");
}

void loop() {
  // Read magnetic switch state
  int reedState = digitalRead(REED_PIN);  // Read switch pin level: HIGH(1) = magnetic field detected, LOW(0) = no magnetic field
  
  // Control LED based on detection state
  if (reedState == HIGH) {
    // Magnetic field detected: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Magnetic field detected - LED on");
  } else {
    // No magnetic field detected: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("No magnetic field detected - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
