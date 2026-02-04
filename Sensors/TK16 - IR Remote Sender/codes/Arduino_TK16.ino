/*
 * TK16-IR REMOTE SENSOR - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK16-IR REMOTE SENSOR module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Note: This program requires the IRremote library
// Installation: Tools → Manage Libraries → Search "IRremote" → Install

#include <IRremote.h>  // Import IR transmission library

// Pin number: change this to match your wiring
#define IR_TX_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D3)

// Create IR transmitter object
IRsend irsend(IR_TX_PIN);

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("IR remote transmitter program started");
  Serial.println("Transmitting IR signal every 2 seconds");
}

void loop() {
  // Send NEC format IR code (example)
  irsend.sendNEC(0xFF00FF, 32);  // Send NEC format IR code, 0xFF00FF is IR code value, 32 is bit count
  Serial.println("IR signal transmitted");
  delay(2000);  // Wait 2 seconds before transmitting again
}
