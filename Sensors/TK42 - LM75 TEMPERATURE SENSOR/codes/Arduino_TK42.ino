/*
 * TK42-LM75 TEMPERATURE SENSOR - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK42-LM75 TEMPERATURE SENSOR module.
 * 
 * Wiring:
 * - SDA → Arduino A4 (I2C data line)
 * - SCL → Arduino A5 (I2C clock line)
 * - VCC → Arduino 5V
 * - GND → Arduino GND
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Include Wire library for I2C communication
// Arduino Uno R3 I2C pins are fixed: SDA=A4, SCL=A5
#include <Wire.h>

// LM75 I2C address (usually 0x48)
#define LM75_ADDRESS 0x48

void setup() {
  // Start I2C communication
  Wire.begin();
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}

void loop() {
  // Read temperature value
  Wire.beginTransmission(LM75_ADDRESS);
  Wire.write(0x00);  // Temperature register address
  Wire.endTransmission();
  
  // Read 2 bytes of data
  Wire.requestFrom(LM75_ADDRESS, 2);
  if(Wire.available() >= 2) {
    int highByte = Wire.read();      // High byte
    int lowByte = Wire.read();        // Low byte
    
    // Combine into 16-bit temperature value
    int tempRaw = (highByte << 8) | lowByte;
    
    // Convert to actual temperature (unit: Celsius)
    // LM75 temperature value is 11-bit, highest bit is sign bit
    float temperature = (tempRaw >> 5) * 0.125;
    
    // Display temperature on Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
  }
  
  // Delay 1 second to avoid reading too fast
  delay(1000);
}
