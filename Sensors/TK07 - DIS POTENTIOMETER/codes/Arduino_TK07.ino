/*
 * TK07-DIS POTENTIOMETER - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK07-DIS POTENTIOMETER module to control LED brightness
 * - Rotate potentiometer to adjust LED brightness
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Rotate potentiometer to adjust LED brightness
 */

// Pin number: change this to match your wiring
#define POT_PIN A0     // Arduino analog input pin connected to SIGNAL (e.g. A0)
#define LED_PIN 6      // Arduino digital pin connected to LED (must be PWM pin, e.g. D6)

void setup() {
  // Initialize pin modes
  pinMode(POT_PIN, INPUT);   // Set potentiometer pin as input (to read analog value)
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output (to control LED brightness)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Digital potentiometer LED brightness control program started");
  Serial.println("Rotate potentiometer to adjust LED brightness");
}

void loop() {
  // Read potentiometer analog value (0-1023)
  int potValue = analogRead(POT_PIN);  // Read analog value: 0 = minimum, 1023 = maximum
  
  // Map potentiometer value (0-1023) to LED brightness (0-255)
  int brightness = map(potValue, 0, 1023, 0, 255);
  
  // Use PWM to control LED brightness
  analogWrite(LED_PIN, brightness);
  
  // Convert analog value to voltage value (0-5V)
  float voltage = potValue * (5.0 / 1023.0);
  
  // Display values in Serial Monitor
  Serial.print("Potentiometer value: ");
  Serial.print(potValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print("V | LED brightness: ");
  Serial.println(brightness);
  
  // Delay 100 milliseconds to avoid reading too fast
  delay(100);
}
