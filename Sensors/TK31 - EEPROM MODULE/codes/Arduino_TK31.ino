/*
 * TK31-EEPROM MODULE - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK31-EEPROM MODULE module.
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

// Note: This program requires the Wire library (included with Arduino)
// Arduino Uno R3 I2C pins are fixed: SDA=A4, SCL=A5
#include <Wire.h>  // I2C communication library

// EEPROM address (usually 0x50)
#define EEPROM_ADDR 0x50

void setup() {
  // Start I2C communication
  Wire.begin();
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("EEPROM module program started");
  
  // Write data
  writeEEPROM(0, 123);  // Write data 123 to address 0
  Serial.println("Data written to EEPROM");
  
  delay(100);  // Wait for write to complete
}

void loop() {
  // Read data
  int data = readEEPROM(0);  // Read data from address 0
  Serial.print("Data read from EEPROM: ");
  Serial.println(data);
  
  delay(2000);  // Wait 2 seconds
}

// Write EEPROM function
void writeEEPROM(int address, byte data) {
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write((int)(address >> 8));    // Address high byte
  Wire.write((int)(address & 0xFF));  // Address low byte
  Wire.write(data);                   // Write data
  Wire.endTransmission();
  delay(5);  // Wait for write to complete
}

// Read EEPROM function
byte readEEPROM(int address) {
  byte data = 0;
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write((int)(address >> 8));    // Address high byte
  Wire.write((int)(address & 0xFF));  // Address low byte
  Wire.endTransmission();
  Wire.requestFrom(EEPROM_ADDR, 1);  // Request 1 byte of data
  if (Wire.available()) {
    data = Wire.read();
  }
  return data;
}
