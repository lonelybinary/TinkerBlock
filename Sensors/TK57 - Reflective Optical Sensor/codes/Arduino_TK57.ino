/*
 * TK57-LINE TRACKER - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK57-LINE TRACKER module to control LED
 * - LED on when black line detected, LED off when white line detected
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Place sensor on black or white line and observe LED state
 */

// Pin number: change this to match your wiring
#define TRACKER_PIN 2  // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13     // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(TRACKER_PIN, INPUT);  // Set line tracker pin as input (to read detection state)
  pinMode(LED_PIN, OUTPUT);     // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Line tracker program started");
  Serial.println("LED on when black line detected, LED off when white line detected");
}

void loop() {
  // Read line tracker state
  int trackerState = digitalRead(TRACKER_PIN);  // Read sensor pin level: HIGH(1)=black line detected, LOW(0)=white line detected
  
  // Control LED based on detection state
  if (trackerState == HIGH) {
    // Black line detected: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Black line detected - LED on");
  } else {
    // White line detected: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("White line detected - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
