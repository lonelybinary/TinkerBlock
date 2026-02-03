/*
 * TK29-ADC MODULE - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK29-ADC MODULE module
 * - Connect TK20-AMBIENT LIGHT module to TK29
 * - Read TK29's ANA (analog value) and DIG (digital value)
 * - Output read values via serial
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change these to match your wiring
#define DIG_PIN 2   // Arduino digital pin connected to DIG (e.g. D2)
#define ANA_PIN A0  // Arduino analog input pin connected to ANA (e.g. A0)

void setup() {
  // Initialize pin modes
  pinMode(DIG_PIN, INPUT);   // Set DIG pin as input (to read digital output)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("TK29-ADC MODULE program started");
  Serial.println("Reading ANA (analog value) and DIG (digital value)");
}

void loop() {
  // Read analog input value (0-1023)
  int ana = analogRead(ANA_PIN);
  
  // Read digital output value
  int dig = digitalRead(DIG_PIN);
  
  // Serial output ANA and DIG values
  Serial.print("ANA: ");
  Serial.print(ana);
  Serial.print(" | DIG: ");
  Serial.println(dig);
  
  delay(100);  // Delay 100 milliseconds to avoid output too fast
}
