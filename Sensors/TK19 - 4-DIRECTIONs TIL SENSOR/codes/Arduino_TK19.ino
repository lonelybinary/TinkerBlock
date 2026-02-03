/*
 * TK19-4-DIRECTIONs TIL SENSOR - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK19-4-DIRECTIONs TIL SENSOR module
 * - Detect tilt status in four directions: up, down, left, right
 * - Display tilt direction in Serial Monitor
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 * 3. Tilt the sensor module and observe Serial output
 */

// Pin number: change these to match your wiring
#define A_PIN 2      // Arduino digital pin connected to A (as common, output LOW)
#define B_PIN 3      // Arduino digital pin connected to B (INPUT_PULLUP, detect direction B)
#define C_PIN 4      // Arduino digital pin connected to C (INPUT_PULLUP, detect direction C)
#define D_PIN 5      // Arduino digital pin connected to D (INPUT_PULLUP, detect direction D)

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  // Initialize pin modes
  pinMode(A_PIN, OUTPUT);        // Set A pin as output (as common)
  pinMode(B_PIN, INPUT_PULLUP);  // Set B pin as INPUT_PULLUP (detect direction B tilt)
  pinMode(C_PIN, INPUT_PULLUP);  // Set C pin as INPUT_PULLUP (detect direction C tilt)
  pinMode(D_PIN, INPUT_PULLUP);  // Set D pin as INPUT_PULLUP (detect direction D tilt)
  
  // Set A pin to LOW (as common/ground)
  digitalWrite(A_PIN, LOW);
  
  Serial.println("4-direction tilt sensor program started");
  Serial.println("Detecting tilt status in four directions");
  Serial.println("A pin as common (LOW), B/C/D pins detect tilt (LOW=tilt)");
}

void loop() {
  // Read tilt status of three directions
  // When B/C/D pins read LOW, it means tilt detected in corresponding direction
  int bState = digitalRead(B_PIN);   // Read B pin: LOW(0) = direction B tilt, HIGH(1) = no tilt
  int cState = digitalRead(C_PIN);   // Read C pin: LOW(0) = direction C tilt, HIGH(1) = no tilt
  int dState = digitalRead(D_PIN);   // Read D pin: LOW(0) = direction D tilt, HIGH(1) = no tilt
  
  // Detect and output tilt direction
  bool tilted = false;  // Flag to mark if tilt is detected
  
  if (bState == LOW) {
    Serial.println("Detected: Direction B tilt");
    tilted = true;
  }
  
  if (cState == LOW) {
    Serial.println("Detected: Direction C tilt");
    tilted = true;
  }
  
  if (dState == LOW) {
    Serial.println("Detected: Direction D tilt");
    tilted = true;
  }
  
  // If no direction is tilted, show level status
  if (!tilted) {
    Serial.println("Level");
  }
  
  // Display all pin states (for debugging)
  Serial.print("State: B=");
  Serial.print(bState);
  Serial.print("(LOW=tilt), C=");
  Serial.print(cState);
  Serial.print("(LOW=tilt), D=");
  Serial.print(dState);
  Serial.println("(LOW=tilt)");
  
  Serial.println("---");
  
  // Delay 100 milliseconds to avoid output too fast
  delay(100);
}
