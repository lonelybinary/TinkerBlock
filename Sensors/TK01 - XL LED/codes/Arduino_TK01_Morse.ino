/*
 * TK01-XL LED - Morse Code "TK01" Demo (Arduino Uno R3)
 *
 * Description:
 * Uses LED on/off to display Morse code for "TK01". Sends once on power-up then stops.
 * Morse timing: dot (·) = short flash, dash (–) = long flash; 1 unit between elements, 3 units between letters.
 *
 * Wiring:
 * Change LED_PIN below to match your wiring.
 *
 * Usage:
 * 1. Upload to Arduino Uno R3
 * 2. Open Serial Monitor (9600) to see the character being sent
 */

#define LED_PIN 3  // Connect to TK01 SIGNAL; change to match your wiring

// Time units (ms): 1 dot = 1 unit, 1 dash = 3 units
const int DOT_MS = 200;             // Dot (short) duration
const int DASH_MS = DOT_MS * 3;     // Dash (long) duration
const int ELEMENT_GAP_MS = DOT_MS;  // Gap between dot/dash in same letter
const int LETTER_GAP_MS = DOT_MS * 3; // Gap between letters
const int WORD_GAP_MS = DOT_MS * 7;  // Optional pause after sending (for single-shot)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("TK01 Morse - sending once");
  // Send T, K, 0, 1 in Morse (once)
  sendMorseChar('T');
  delay(LETTER_GAP_MS);
  sendMorseChar('K');
  delay(LETTER_GAP_MS);
  sendMorseChar('0');
  delay(LETTER_GAP_MS);
  sendMorseChar('1');
  Serial.println("Done");
}

void loop() {
  // Send once; idle after that
  delay(1000);
}

// Turn LED on for given milliseconds
void ledOn(int ms) {
  digitalWrite(LED_PIN, HIGH);
  delay(ms);
}

// Turn LED off for given milliseconds
void ledOff(int ms) {
  digitalWrite(LED_PIN, LOW);
  delay(ms);
}

// Send one dot
void sendDot() {
  ledOn(DOT_MS);
  ledOff(ELEMENT_GAP_MS);
}

// Send one dash
void sendDash() {
  ledOn(DASH_MS);
  ledOff(ELEMENT_GAP_MS);
}

// Send Morse for given character (T, K, 0, 1 only)
void sendMorseChar(char c) {
  Serial.print("Sending: ");
  Serial.println(c);

  switch (c) {
    case 'T':
    case 't':
      sendDash();
      break;
    case 'K':
    case 'k':
      sendDash();
      sendDot();
      sendDash();
      break;
    case '0':
      sendDash();
      sendDash();
      sendDash();
      sendDash();
      sendDash();
      break;
    case '1':
      sendDot();
      sendDash();
      sendDash();
      sendDash();
      sendDash();
      break;
    default:
      break;
  }
}
