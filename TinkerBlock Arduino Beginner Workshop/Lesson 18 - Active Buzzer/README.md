# Lesson 18 - Active Buzzer

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK36 Active Buzzer** module, jumper wires (or breadboard). Learn to control the active buzzer with **`digitalWrite()`** and **`const`**; **outcome:** buzzer on 0.5 s, off 0.5 s, repeat.

---

## 1. Wiring

Connect TK36 Active Buzzer to Arduino:

- **GND** → Arduino GND  
- **VCC** → Arduino 5V  
- **SIGNAL** → Arduino D3  
- **NC** leave unconnected

![TK36 wiring diagram](../../Sensors/TK36%20-%20Active%20Buzzer/images/wiring_diagram-1.webp)

---

## 2. New sketch

1. Arduino IDE: File → **New** (or Ctrl/Cmd + N) to create a blank sketch  
2. Confirm board and port are selected (same as Lesson 01)  
3. **Type** the code below into the default `setup()` and `loop()` yourself  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Tell the board “pin 3 for buzzer”; start serial (optional); runs once.  
- **`loop()`**: Keep repeating “buzzer on → wait → buzzer off → wait → repeat”.

The result is on–off cycles; active buzzer has fixed pitch, no tuning.

---

## 4. Code to write

**Type** the code below line by line into `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
#define BUZZER_PIN 3   // Buzzer on D3
const int DURATION = 500;   // Duration in milliseconds

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);   // D3 output for buzzer
  Serial.begin(9600);
  Serial.println("Active buzzer program started");
}

void loop() {
  // Buzzer on
  digitalWrite(BUZZER_PIN, HIGH);
  Serial.println("Buzzer on");
  delay(DURATION);
  
  // Buzzer off
  digitalWrite(BUZZER_PIN, LOW);
  Serial.println("Buzzer off");
  delay(DURATION);
}
```

---

### Program notes

**Overall idea:** Active buzzer has internal oscillator; HIGH = on, LOW = off; use `digitalWrite`. `const int DURATION` holds on/off time (ms) so you can change it in one place. `const` is like `#define` but typed; good for constants.

| Code | In this lesson |
|------|----------------|
| **`digitalWrite(BUZZER_PIN, HIGH/LOW)`** | HIGH = on, LOW = off; active buzzer has no frequency control |
| **`const int DURATION = 500`** | Constant in ms; change here to change on/off time |

**`const` vs `#define`:**
- **`#define DURATION 500`**: Preprocessor replacement before compile  
- **`const int DURATION = 500`**: Real variable with type checking, safer. Prefer `const` for constants  

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. Listen to TK36: on 0.5 s, off 0.5 s, repeat  
4. Try yourself:
   - Change `DURATION` to change on/off time  
   - Try fast on/off (e.g. `delay(100)`) for a “beep-beep”  

**Expected result:** As in the figure.

![Active buzzer effect](../../Sensors/TK36%20-%20Active%20Buzzer/images/TK36-uno.webp)

Proceed to Lesson 19.

---

## 6. Common issues

| Symptom | What to do |
|---------|------------|
| Buzzer silent | Check TK36 wiring GND→GND, VCC→5V, SIGNAL→D3 |
| Active vs passive | Active: on/off only (fixed tone); passive: can play different frequencies |

---

*TinkerBlock Arduino Beginner Workshop — Lesson 18*
