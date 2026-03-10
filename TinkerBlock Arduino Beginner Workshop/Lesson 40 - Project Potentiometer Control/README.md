# Lesson 40 - Project: Potentiometer Control

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK08 Rotary Potentiometer** module, **TinkerBlock TK02 RGB LED** or **TK37**, jumper wires (or breadboard). **Project:** use potentiometer to control output; **outcome:** knob controls LED brightness (or buzzer pitch), serial shows potentiometer value and brightness/frequency.

---

## 1. Project goal

Build a potentiometer control system:
- Turn potentiometer: control LED brightness (or buzzer pitch)  
- Higher potentiometer value → brighter LED (or higher pitch)  

---

## 2. Wiring

**Option 1: LED brightness**
- **TK08 Potentiometer:** GND → GND, VCC → 5V, SIGNAL → A0  
- **TK02 RGB LED:** GND → GND, RED → D3, GREEN → D5, BLUE → D6  

**Option 2: Buzzer pitch**
- **TK08 Potentiometer:** GND → GND, VCC → 5V, SIGNAL → A0  
- **TK37 Passive Buzzer:** GND → GND, VCC → 5V, SIGNAL → D3  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Start serial (optional); runs once.  
- **`loop()`**: Keep repeating “read potentiometer → convert to brightness/pitch → set output → wait → repeat”.

Option 1: knob sets LED brightness. Option 2: knob sets buzzer frequency. Pick one and the knob “controls” the output.

---

## 4. Code to write

**Option 1: LED brightness**

```cpp
// Option 1: Potentiometer → LED brightness
#define POT_PIN A0
#define LED_PIN 3    // PWM pin

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potVal = analogRead(POT_PIN);
  int brightness = map(potVal, 0, 1023, 0, 255);   // Map to 0-255
  analogWrite(LED_PIN, brightness);
  Serial.print("Pot: ");
  Serial.print(potVal);
  Serial.print(" | Brightness: ");
  Serial.println(brightness);
  delay(50);
}
```

**Option 2: Buzzer pitch**

```cpp
// Option 2: Potentiometer → buzzer frequency
#define POT_PIN A0
#define BUZZER_PIN 3

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potVal = analogRead(POT_PIN);
  int frequency = map(potVal, 0, 1023, 200, 2000);   // Map to 200-2000 Hz
  tone(BUZZER_PIN, frequency);
  Serial.print("Pot: ");
  Serial.print(potVal);
  Serial.print(" | Freq: ");
  Serial.println(frequency);
  delay(50);
}
```

---

### Program notes

**Overall idea:** `analogRead` gives 0–1023; use `map(value, 0, 1023, outMin, outMax)` to map to brightness 0–255 or frequency 200–2000 Hz, then `analogWrite` or `tone`. Review analog input controlling PWM/pitch.

| Code | In this lesson |
|------|----------------|
| **`map(potVal, 0, 1023, 0, 255)`** | Linear map 0–1023 to 0–255 for analogWrite brightness |
| **`map(potVal, 0, 1023, 200, 2000)`** | Map to 200–2000 Hz for tone pitch |

---

## 5. Hands-on

1. Choose Option 1 or Option 2  
2. After entering the code, click **Verify** (✓) to compile  
3. Click **Upload** (→) to upload to the board  
4. **Turn the potentiometer:**
   - Option 1: LED brightness follows potentiometer  
   - Option 2: Buzzer pitch follows potentiometer  
5. Try yourself: control different colors on RGB LED  

**Expected result:** Turning the potentiometer changes LED brightness or buzzer pitch.

Proceed to Lesson 41.

---

*TinkerBlock Arduino Beginner Workshop — Lesson 40*
