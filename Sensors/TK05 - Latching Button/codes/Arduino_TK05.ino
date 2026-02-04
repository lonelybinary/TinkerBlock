/*
 * TK05-LOCK BUTTON - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK05-LOCK BUTTON module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change this to match your wiring
#define BUTTON_PIN 2  // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13    // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(BUTTON_PIN, INPUT);   // Set button pin as input (to read button state)
  pinMode(LED_PIN, OUTPUT);     // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Lock button switch program started");
  Serial.println("Press button to lock, LED stays on; press again to unlock, LED off");
}

void loop() {
  // Read button state
  int buttonState = digitalRead(BUTTON_PIN);  // Read button pin level: HIGH(1) = locked, LOW(0) = unlocked
  
  // Control LED based on button state
  if (buttonState == HIGH) {
    // Button locked: LED stays on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Button locked - LED on");
  } else {
    // Button unlocked: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("Button unlocked - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
