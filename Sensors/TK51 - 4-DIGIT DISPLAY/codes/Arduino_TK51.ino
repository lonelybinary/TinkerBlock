/*
 * TK51-4-DIGIT DISPLAY - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK51-4-DIGIT DISPLAY module
 * - Cycle through 0-9 (all 4 digits display same number: 0000, 1111, 2222...9999)
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Observe the 4-digit display effect
 * 
 * Note: Requires TM1637 library
 * Installation: Tools → Manage Libraries → Search "TM1637" → Install
 */

#include <TM1637Display.h>

// Pin number: change these to match your wiring
#define CLK_PIN 2   // Arduino digital pin connected to CLOCK (e.g. D2)
#define DIO_PIN 3   // Arduino digital pin connected to DATA (e.g. D3)

// Create TM1637 display object
TM1637Display display(CLK_PIN, DIO_PIN);

void setup() {
  // Set display brightness (0-7, 7 is brightest)
  display.setBrightness(7);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("4-digit display module program started");
  Serial.println("Cycling through 0-9 (all 4 digits display same number)");
}

void loop() {
  // Cycle through 0-9 (all 4 digits display same number)
  for (int i = 0; i < 10; i++) {
    // Display number: 0 displays as 0000, 1 displays as 1111, 2 displays as 2222...9 displays as 9999
    // showNumberDecEx second parameter is dot display, third parameter is leading zero
    display.showNumberDecEx(i * 1111, 0, false);
    
    Serial.print("Display number: ");
    Serial.println(i);
    
    delay(1000);  // Switch number every second
  }
}
