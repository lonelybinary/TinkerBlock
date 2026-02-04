/*
 * TK06-ROTARY ENCODER - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK06-ROTARY ENCODER module to control LED brightness
 * - Rotary encoder: rotate clockwise to increase LED brightness, counterclockwise to decrease
 * - Encoder button: press to toggle LED on/off state
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Rotate encoder knob to adjust LED brightness
 * 4. Press encoder button to toggle LED switch
 */

// Pin number: change these to match your wiring
#define CLOCK_PIN 4   // Arduino digital pin connected to CLOCK (e.g. D4)
#define DATA_PIN 5    // Arduino digital pin connected to DATA (e.g. D5)
#define BTN_PIN 3     // Arduino digital pin connected to BTN (e.g. D3)
#define LED_PIN 6     // Arduino digital pin connected to LED (must be PWM pin, e.g. D6)

// Variables
int lastClockState = HIGH;  // Last CLOCK pin state
int lastBtnState = HIGH;    // Last BTN pin state
int brightness = 128;       // LED brightness value (0-255)
bool ledEnabled = true;     // LED switch state

void setup() {
  // Initialize pin modes
  pinMode(CLOCK_PIN, INPUT_PULLUP);  // Set CLOCK pin as input, enable internal pull-up resistor
  pinMode(DATA_PIN, INPUT_PULLUP);   // Set DATA pin as input, enable internal pull-up resistor
  pinMode(BTN_PIN, INPUT_PULLUP);    // Set BTN pin as input, enable internal pull-up resistor
  pinMode(LED_PIN, OUTPUT);           // Set LED pin as output
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  // Read initial state
  lastClockState = digitalRead(CLOCK_PIN);
  lastBtnState = digitalRead(BTN_PIN);
  
  // Set initial LED brightness
  analogWrite(LED_PIN, brightness);
  
  Serial.println("Rotary encoder LED brightness control program started");
  Serial.println("Rotate clockwise to increase brightness, counterclockwise to decrease");
  Serial.println("Press button to toggle LED switch");
}

void loop() {
  // Read current CLOCK pin state
  int currentClockState = digitalRead(CLOCK_PIN);
  
  // Detect CLOCK pin state change (from HIGH to LOW)
  if (currentClockState != lastClockState) {
    if (currentClockState == LOW) {
      // When CLOCK becomes LOW, read DATA pin state to determine rotation direction
      int dataState = digitalRead(DATA_PIN);
      
      if (dataState == LOW) {
        // DATA is LOW, clockwise rotation, increase brightness
        brightness = min(255, brightness + 20);
        Serial.print("Clockwise rotation, brightness: ");
        Serial.println(brightness);
      } else {
        // DATA is HIGH, counterclockwise rotation, decrease brightness
        brightness = max(0, brightness - 20);
        Serial.print("Counterclockwise rotation, brightness: ");
        Serial.println(brightness);
      }
      
      // Update LED brightness (if LED is enabled)
      if (ledEnabled) {
        analogWrite(LED_PIN, brightness);
      }
    }
    
    // Update last state
    lastClockState = currentClockState;
  }
  
  // Detect button press (detect falling edge)
  int currentBtnState = digitalRead(BTN_PIN);
  if (currentBtnState == LOW && lastBtnState == HIGH) {
    // Toggle LED switch state
    ledEnabled = !ledEnabled;
    
    if (ledEnabled) {
      analogWrite(LED_PIN, brightness);
      Serial.print("LED on, brightness: ");
      Serial.println(brightness);
    } else {
      analogWrite(LED_PIN, 0);
      Serial.println("LED off");
    }
    
    delay(200);  // Debounce delay
  }
  lastBtnState = currentBtnState;
}
