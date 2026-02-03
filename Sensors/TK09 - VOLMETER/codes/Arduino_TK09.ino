/*
 * TK09-VOLMETER - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK09-VOLMETER voltage detection module
 * - Module can scale 0-25V voltage to 0-5V for MCU reading
 * - Read scaled voltage signal and calculate original voltage (0-25V)
 * 
 * Wiring (Important!):
 * - Module VCC pin: Connect to Arduino 5V (module power supply)
 * - Module GND pin: Connect to Arduino GND (module power supply)
 * - Module SIG pin: Connect to Arduino A0 (ADC input)
 * - Voltage being measured: Positive terminal to module VCC pin, negative terminal to module GND pin
 * 
 * Wiring instructions:
 * 1. Connect module VCC and GND to Arduino 5V and GND first (power the module)
 * 2. Connect positive terminal of voltage being measured to module VCC pin (shared with Arduino 5V)
 * 3. Connect negative terminal of voltage being measured to module GND pin (shared with Arduino GND)
 * 4. Connect module SIG pin to Arduino A0 (read scaled voltage)
 * 
 * Note: Do NOT connect voltage being measured directly to Arduino ADC pin! Must use module voltage divider!
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Observe voltage value changes (0-25V)
 */

// Pin number: change this to match your wiring
#define VOLTAGE_PIN A0  // Arduino analog input pin connected to SIG output (e.g. A0)

// Voltage divider ratio: adjust according to actual measurement
// If connecting 5V shows 25V, it means ADC read 5V, may need to adjust this ratio
// Default value is 5.0 (1:5 voltage divider), modify this value if measurement is inaccurate
const float VOLTAGE_DIVIDER_RATIO = 5.0;  // Voltage divider ratio

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Voltage detection module program started");
  Serial.println("Reading scaled voltage signal and calculating original voltage (0-25V)");
}

void loop() {
  // Read analog input value (0-1023)
  int sensorValue = analogRead(VOLTAGE_PIN);  // Read scaled voltage signal value
  
  // Convert analog value to voltage (0-5V)
  float voltage = sensorValue * (5.0 / 1023.0);  // Arduino analog input range is 0-1023, corresponding to 0-5V
  
  // Multiply scaled voltage by divider ratio to get original voltage
  float originalVoltage = voltage * VOLTAGE_DIVIDER_RATIO;
  
  // Print debug information
  Serial.print("ADC value: ");
  Serial.print(sensorValue);
  Serial.print(" | Scaled voltage: ");
  Serial.print(voltage, 3);
  Serial.print("V | Original voltage: ");
  Serial.print(originalVoltage, 3);
  Serial.println("V");
  
  delay(500);  // Wait 0.5 seconds before reading again
}
