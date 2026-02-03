/*
 * TK62-TILT SENSOR - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK62-TILT SENSOR module to control LED
 * - LED on when tilt detected, LED off when level
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Tilt the sensor module and observe LED state
 */

// Pin number: change this to match your wiring
#define TILT_PIN 2     // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13     // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(TILT_PIN, INPUT);   // Set tilt sensor pin as input (to read detection state)
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Tilt sensor program started");
  Serial.println("LED on when tilt detected, LED off when level");
}

void loop() {
  // Read tilt sensor state
  int tiltState = digitalRead(TILT_PIN);  // Read sensor pin level: HIGH(1)=tilt, LOW(0)=level
  
  // Control LED based on detection state
  if (tiltState == HIGH) {
    // Tilt detected: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Tilt detected - LED on");
  } else {
    // Level state: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("Level state - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
