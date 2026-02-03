/*
 * TK61-PHOTOELECTRIC SWITCH - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK61-PHOTOELECTRIC SWITCH module to control LED
 * - LED on when object blocks light, LED off when no object detected
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Block sensor light and observe LED state
 */

// Pin number: change this to match your wiring
#define PHOTO_SWITCH_PIN 2  // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13          // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(PHOTO_SWITCH_PIN, INPUT);   // Set photoelectric switch pin as input (to read detection state)
  pinMode(LED_PIN, OUTPUT);           // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Photoelectric switch program started");
  Serial.println("LED on when object blocks light, LED off when no object detected");
}

void loop() {
  // Read photoelectric switch state
  int switchState = digitalRead(PHOTO_SWITCH_PIN);  // Read sensor pin level: HIGH(1)=object detected, LOW(0)=no object
  
  // Control LED based on detection state
  if (switchState == HIGH) {
    // Object blocks light: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Object blocks light - LED on");
  } else {
    // No object detected: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("No object detected - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
