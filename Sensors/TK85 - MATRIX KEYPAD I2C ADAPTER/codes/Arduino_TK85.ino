/*
 * TK85-MATRIX KEYPAD I2C ADAPTER - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK85-MATRIX KEYPAD I2C ADAPTER module
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

// I2C address of matrix keypad adapter module (check module documentation, usually 0x20 or 0x21)
#define KEYPAD_ADDRESS 0x20

// Keypad mapping (4x4 matrix keypad)
char keymap[16] = "DCBA#9630852*741";

// Debounce variables
uint8_t stableKey = 16;   // 16 = NoKey
uint8_t stableCount = 0;
uint8_t lastKeypadKey = 16;

// Function declaration
int readKeypad();

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Matrix keypad test");
  Serial.println("Press keys to see key code output");
}

void loop() {
  int key = readKeypad();
  
  if (key >= 0) {
    Serial.print("Key pressed: number=");
    Serial.print(key);
    
    if (key < 16) {
      Serial.print(", character='");
      Serial.print(keymap[key]);
      Serial.print("'");
    }
    Serial.println();
  }
  
  delay(50);
}

// Read matrix keypad
int readKeypad() {
  uint8_t currentKey = 16;
  uint8_t raw = 0xFF;
  bool found = false;

  // Mode A: rows = lower 4 bits (P0..P3), columns = upper 4 bits (P4..P7)
  for (uint8_t col = 0; col < 4 && !found; col++) {
    uint8_t out = (uint8_t)(0xFF & ~(1 << (4 + col)));
    Wire.beginTransmission(KEYPAD_ADDRESS);
    Wire.write(out);
    if (Wire.endTransmission() != 0) {
      continue;
    }
    delayMicroseconds(200);
    
    Wire.requestFrom(KEYPAD_ADDRESS, 1);
    if (Wire.available()) {
      raw = Wire.read();
      uint8_t rows = raw & 0x0F;
      if (rows != 0x0F) {
        for (uint8_t row = 0; row < 4; row++) {
          if (!(rows & (1 << row))) {
            currentKey = row * 4 + col;
            found = true;
            break;
          }
        }
      }
    }
  }

  // Mode B: rows = upper 4 bits (P4..P7), columns = lower 4 bits (P0..P3)
  if (!found) {
    for (uint8_t col = 0; col < 4 && !found; col++) {
      uint8_t out = (uint8_t)(0xFF & ~(1 << col));
      Wire.beginTransmission(KEYPAD_ADDRESS);
      Wire.write(out);
      if (Wire.endTransmission() != 0) {
        continue;
      }
      delayMicroseconds(200);
      
      Wire.requestFrom(KEYPAD_ADDRESS, 1);
      if (Wire.available()) {
        raw = Wire.read();
        uint8_t rows = (raw >> 4) & 0x0F;
        if (rows != 0x0F) {
          for (uint8_t row = 0; row < 4; row++) {
            if (!(rows & (1 << row))) {
              currentKey = row * 4 + col;
              found = true;
              break;
            }
          }
        }
      }
    }
  }

  // Restore all high
  Wire.beginTransmission(KEYPAD_ADDRESS);
  Wire.write(0xFF);
  Wire.endTransmission();
        
  // Debounce: need to read the same key twice consecutively to consider it pressed
  if (currentKey < 16) {
    if (currentKey == stableKey) {
      if (stableCount < 255) stableCount++;
    } else {
      stableKey = currentKey;
      stableCount = 1;
    }

    if (stableCount >= 2 && currentKey != lastKeypadKey) {
      lastKeypadKey = currentKey;
      return currentKey;
    }
  } else {
    stableKey = 16;
    stableCount = 0;
    if (lastKeypadKey != 16) {
      lastKeypadKey = 16;
    }
  }
  
  return -1;
}
