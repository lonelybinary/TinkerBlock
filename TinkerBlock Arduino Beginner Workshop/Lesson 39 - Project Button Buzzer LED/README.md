# Lesson 39 - Project: Button Buzzer LED

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK04 Push Button** module, **TinkerBlock TK36 Active Buzzer** (or **TK37**), **TinkerBlock TK01 XL LED** (or **TK02**), jumper wires (or breadboard). **Project:** one button controls LED and buzzer; **outcome:** press = LED on and buzzer on, release = LED off and buzzer off.

---

## 1. Project goal

Build a button control system:
- Press: LED on, buzzer on  
- Release: LED off, buzzer off  

---

## 2. Wiring

- **TK04 Button:** VCC → 5V, GND → GND, SIGNAL → D2  
- **TK36 Active Buzzer:** VCC → 5V, GND → GND, SIGNAL → D3  
- **TK01 LED:** GND → GND, SIGNAL → D13  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Tell the board “D2 = button, D3 = buzzer, D13 = LED”; runs once.  
- **`loop()`**: Keep repeating “read button → if pressed then LED on + buzzer on, else LED off + buzzer off → wait → repeat”.

One button drives both outputs: press = both on, release = both off.

---

## 4. Code to write

**Type** the code below into `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
#define BUTTON_PIN 2   // Button on D2
#define BUZZER_PIN 3   // Buzzer on D3
#define LED_PIN 13     // LED on D13

void setup() {
  pinMode(BUTTON_PIN, INPUT);   // D2 read button
  pinMode(BUZZER_PIN, OUTPUT);  // D3 buzzer
  pinMode(LED_PIN, OUTPUT);     // D13 LED
}

void loop() {
  int state = digitalRead(BUTTON_PIN);   // Pressed=HIGH, released=LOW
  if (state == HIGH) {
    digitalWrite(LED_PIN, HIGH);      // Pressed: LED on
    digitalWrite(BUZZER_PIN, HIGH);   // Pressed: buzzer on
  } else {
    digitalWrite(LED_PIN, LOW);       // Released: LED off
    digitalWrite(BUZZER_PIN, LOW);    // Released: buzzer off
  }
  delay(100);   // Debounce
}
```

---

### Program notes

**Overall idea:** Read button; in the same `if (state == HIGH)` set both LED and buzzer HIGH, in `else` both LOW—press = both on, release = both off. Review digital input and multiple digital outputs.

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. **Test:**
   - Press: LED on, buzzer on  
   - Release: LED off, buzzer off  
4. Try yourself:
   - Use passive buzzer (TK37) and `tone()` for a melody  
   - Use RGB LED (TK02) for different colors  

**Expected result:** When you press the button, LED and buzzer turn on.

Proceed to Lesson 40.

---

*TinkerBlock Arduino Beginner Workshop — Lesson 39*
