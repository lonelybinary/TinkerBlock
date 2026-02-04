/*
 * TK43-TP223 TOUCH SENSOR - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK43-TP223 TOUCH SENSOR module to control LED
 * - LED on when touch sensor is touched, LED off when not touched
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Touch the sensor and observe LED state
 */

// Pin number: change this to match your wiring
#define TOUCH_PIN 2      // Arduino digital pin connected to SIGNAL (e.g. D2)
#define LED_PIN 13       // LED pin (Arduino built-in LED on pin 13, or external LED)

void setup() {
  // Initialize pin modes
  pinMode(TOUCH_PIN, INPUT);   // Set touch sensor pin as input (to read detection state)
  pinMode(LED_PIN, OUTPUT);    // Set LED pin as output (to control LED on/off)
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Touch sensor program started");
  Serial.println("LED on when touch sensor is touched, LED off when not touched");
}

void loop() {
  // Read touch sensor state
  int touchState = digitalRead(TOUCH_PIN);  // Read sensor pin level: HIGH(1)=touched, LOW(0)=not touched
  
  // Control LED based on detection state
  if (touchState == HIGH) {
    // Touch sensor touched: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Touch sensor - LED on");
  } else {
    // Not touched: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("Not touched - LED off");
  }
  
  delay(100);  // Brief delay to avoid reading too fast
}
