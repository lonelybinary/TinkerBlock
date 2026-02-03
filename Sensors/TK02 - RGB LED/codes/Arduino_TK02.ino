/*
 * TK02-RGB LED - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK02-RGB LED module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change these to match your wiring
#define RED_PIN 3    // Arduino PWM pin connected to RED (e.g. D3)
#define GREEN_PIN 5  // Arduino PWM pin connected to GREEN (e.g. D5)
#define BLUE_PIN 6   // Arduino PWM pin connected to BLUE (e.g. D6)

void setup() {
  // Set RGB pins as output
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}

void loop() {
  // Red
  analogWrite(RED_PIN, 255);    // Red at maximum brightness
  analogWrite(GREEN_PIN, 0);    // Green off
  analogWrite(BLUE_PIN, 0);     // Blue off
  Serial.println("Red");
  delay(1000);
  
  // Green
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 0);
  Serial.println("Green");
  delay(1000);
  
  // Blue
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 255);
  Serial.println("Blue");
  delay(1000);
  
  // White (all colors at maximum brightness)
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 255);
  Serial.println("White");
  delay(1000);
}
