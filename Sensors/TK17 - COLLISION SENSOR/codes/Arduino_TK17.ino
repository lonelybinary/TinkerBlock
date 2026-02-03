/*
 * TK17-COLLISION SENSOR - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK17-COLLISION SENSOR module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change this to match your wiring
#define COLLISION_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 5       // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(COLLISION_PIN, INPUT);   // Set collision pin as input (to read collision state)
  pinMode(LED_PIN, OUTPUT);        // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}

void loop() {
  // Read collision sensor state
  int collisionState = digitalRead(COLLISION_PIN);  // Read collision pin level: HIGH(1) = collision, LOW(0) = no collision
  
  // Control LED based on collision state
  if(collisionState == HIGH) {
    // Collision detected: turn LED on and print message
    digitalWrite(LED_PIN, HIGH);  // Output HIGH to turn LED on
    Serial.println("Collision detected!");  // Display message in Serial Monitor
  } else {
    // No collision detected: turn LED off
    digitalWrite(LED_PIN, LOW);   // Output LOW to turn LED off
  }
  
  // Delay 50 milliseconds to avoid reading too fast (give sensor stabilization time, prevent false triggers)
  delay(50);
}
