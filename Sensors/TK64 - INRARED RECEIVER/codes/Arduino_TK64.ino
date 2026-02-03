/*
 * TK64-INRARED RECEIVER - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK64-INRARED RECEIVER module
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Note: This program requires IRremote library
// Installation: Tools → Manage Libraries → Search "IRremote" → Install

#include <IRremote.h>  // Import infrared receiver library

// Pin number: change this to match your wiring
#define IR_RX_PIN 2  // Arduino digital pin connected to SIGNAL (e.g. D2)

// Create infrared receiver object
IRrecv irrecv(IR_RX_PIN);
decode_results results;  // Store decoding results

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  // Start infrared reception
  irrecv.enableIRIn();
  
  Serial.println("Infrared receiver program started");
  Serial.println("Waiting to receive infrared signal...");
}

void loop() {
  // Check if infrared signal received
  if (irrecv.decode(&results)) {
    // Signal received, print decoding results
    Serial.print("Infrared signal received, decoded value: 0x");
    Serial.println(results.value, HEX);  // Display in hexadecimal
    
    // Identify common infrared remote codes
    switch(results.value) {
      case 0xFF00FF:  // Example: a button on a remote
        Serial.println("Button 1 pressed");
        break;
      case 0xFF807F:  // Example: another button on a remote
        Serial.println("Button 2 pressed");
        break;
      default:
        Serial.println("Unknown button");
        break;
    }
    
    // Continue receiving next signal
    irrecv.resume();
  }
  
  delay(100);  // Brief delay
}
