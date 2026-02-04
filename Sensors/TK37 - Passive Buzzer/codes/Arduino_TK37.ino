/*
 * TK37-PASSIVE BUZZER - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK37-PASSIVE BUZZER module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

// Pin number: change this to match your wiring
#define BUZZER_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D3)

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Passive buzzer program started");
}

void loop() {
  // Play scale: Do Re Mi Fa Sol La Si
  // C4=262Hz, D4=294Hz, E4=330Hz, F4=349Hz, G4=392Hz, A4=440Hz, B4=494Hz
  
  int notes[] = {262, 294, 330, 349, 392, 440, 494};  // Scale frequencies
  String noteNames[] = {"Do", "Re", "Mi", "Fa", "Sol", "La", "Si"};  // Note names
  
  for (int i = 0; i < 7; i++) {
    tone(BUZZER_PIN, notes[i]);  // Play sound at specified frequency
    Serial.print("Playing: ");
    Serial.print(noteNames[i]);
    Serial.print(" (");
    Serial.print(notes[i]);
    Serial.println(" Hz)");
    delay(500);  // Each note plays for 0.5 seconds
  }
  
  noTone(BUZZER_PIN);  // Stop playing
  Serial.println("Playback complete, waiting 0.5 seconds before repeating");
  delay(500);
}
