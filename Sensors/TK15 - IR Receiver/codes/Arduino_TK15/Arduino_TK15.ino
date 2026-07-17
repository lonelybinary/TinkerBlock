/*
 * TK15-IR RECEIVER - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK15-IR RECEIVER module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change this to match your wiring
#define IR_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13  // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(IR_PIN, INPUT);    // Set IR pin as input (to read IR signal)
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}

void loop() {
  // Read IR receiver state
  int irState = digitalRead(IR_PIN);  // Read IR pin level: LOW(0) = signal received, HIGH(1) = no signal
  
  // Control LED based on IR state
  if(irState == LOW) {
    // IR signal received: turn LED on and print message
    digitalWrite(LED_PIN, HIGH);  // Output HIGH to turn LED on
    Serial.println("IR signal received!");  // Display message in Serial Monitor
  } else {
    // No signal received: turn LED off
    digitalWrite(LED_PIN, LOW);   // Output LOW to turn LED off
  }
  
  // Delay 10 milliseconds to avoid reading too fast
  delay(10);
}
