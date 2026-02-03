/*
 * TK03-TRAFFIC LIGHT - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK03-TRAFFIC LIGHT module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change these to match your wiring
#define RED_PIN 2     // Arduino digital pin connected to RED (e.g. D2)
#define YELLOW_PIN 3  // Arduino digital pin connected to YELLOW (e.g. D3)
#define GREEN_PIN 4   // Arduino digital pin connected to GREEN (e.g. D4)

void setup() {
  // Set LED pins as output (to control LED on/off)
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  // Initialize: all LEDs off
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  
  Serial.println("Traffic light program started");
}

void loop() {
  // Red light on (5 seconds)
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("Red light on - Stop");
  delay(5000);
  
  // Green light on (5 seconds)
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  Serial.println("Green light on - Go");
  delay(5000);
  
  // Yellow light on (2 seconds)
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("Yellow light on - Warning");
  delay(2000);
  
  // Loop back to red light
}
