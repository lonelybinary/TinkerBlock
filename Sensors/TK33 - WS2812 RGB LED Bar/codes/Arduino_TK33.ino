/*
 * TK33-WS2812 LED - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK33-WS2812 LED module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Include FastLED library for controlling WS2812 LEDs
#include <FastLED.h>

// Pin number and LED count: change these to match your wiring
#define PIN 6        // Arduino digital pin connected to DATA (e.g. D6)
#define NUMPIXELS 5  // Number of LEDs (this module has 5 LEDs)

// Create color array to store color values for each LED
CRGB leds[NUMPIXELS];

void setup() {
  // Initialize WS2812 LEDs
  FastLED.addLeds<WS2812, PIN, GRB>(leds, NUMPIXELS);
  // WS2812: LED type
  // PIN: Data pin (pin 6)
  // GRB: Color order is Green-Red-Blue (WS2812 standard)
  // leds: Color array
  // NUMPIXELS: Number of LEDs (5)
  
  // Set brightness to 50 (range 0-255, 0=off, 255=brightest)
  // 50 is about 20% brightness, visible effect without being too bright
  FastLED.setBrightness(50);
}

void loop() {
  // Rainbow gradient effect: make each LED display different colors, forming a flowing rainbow
  for(int i=0; i<NUMPIXELS; i++) {
    // Calculate hue value (color type) for each LED
    // i * 256 / NUMPIXELS: Give each LED a different starting color, forming rainbow distribution
    // millis() / 20: Increment over time, making rainbow flow (larger number = slower flow)
    // % 256: Ensure hue value cycles within 0-255 range
    int hue = ((i * 256 / NUMPIXELS) + (millis() / 20)) % 256;
    
    // Set LED color (HSV to RGB)
    // CHSV: FastLED library HSV color function
    // hue: Hue value (0-255), controls color (0=red, 85=green, 170=blue, 255=red)
    // 255: Maximum saturation (most vivid color)
    // 255: Maximum brightness (already controlled to 50 by setBrightness())
    leds[i] = CHSV(hue, 255, 255);
  }
  
  // Send all colors to LEDs at once (update together to avoid flickering)
  FastLED.show();
  
  // Delay 10 milliseconds to control animation speed (smaller number = faster flow)
  delay(10);
}
