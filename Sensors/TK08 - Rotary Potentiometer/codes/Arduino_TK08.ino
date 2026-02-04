/*
 * TK08-ROTARY POTENTIOMETER - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK08-ROTARY POTENTIOMETER module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change this to match your wiring
#define POT_PIN A0   // Arduino analog input pin connected to SIGNAL (e.g. A0)
#define LED_PIN 9    // LED pin (must use PWM pin, e.g. D9)

void setup() {
  // Initialize pin modes
  pinMode(POT_PIN, INPUT);   // Set potentiometer pin as input (to read analog value)
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output (to control LED brightness)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Rotary potentiometer program started");
  Serial.println("Rotate potentiometer to adjust LED brightness");
}

void loop() {
  // Read potentiometer analog value (0-1023)
  int potValue = analogRead(POT_PIN);  // Read potentiometer pin value: 0 = leftmost, 1023 = rightmost, 512 = middle
  
  // Map potentiometer value (0-1023) to LED brightness (0-255)
  int brightness = map(potValue, 0, 1023, 0, 255);
  
  // Use PWM to control LED brightness
  analogWrite(LED_PIN, brightness);
  
  // Print potentiometer value and LED brightness
  Serial.print("Potentiometer value: ");
  Serial.print(potValue);
  Serial.print(" | LED brightness: ");
  Serial.println(brightness);
  
  delay(100);  // Brief delay to avoid reading too fast
}
