# Lesson 42 - Project: Joystick Control

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK94 Five-Direction Joystick** module, **TinkerBlock TK01 XL LED**, **TK37 Passive Buzzer** (optional), jumper wires (or breadboard). **Project:** joystick direction and button control LED and buzzer; **outcome:** up = LED on, down = LED off, left = low tone, right = high tone, press = buzzer off; serial prints current action.

---

## 1. Project goal

Build a joystick control system:
- Up: LED on (or play high note)  
- Down: LED off (or play low note)  
- Left/Right: RGB LED different colors  
- Press: buzzer on  

---

## 2. Wiring

- **TK94 Five-Direction Joystick:** VCC → 5V, GND → GND, SIGNAL → A0  
- **TK01 LED:** GND → GND, SIGNAL → D13  
- **TK37 Passive Buzzer:** GND → GND, VCC → 5V, SIGNAL → D3  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Init pins, start serial; runs once.  
- **`loop()`**: Keep repeating “read joystick → decide direction → set output → wait → repeat”.

Up = LED on, down = LED off, left = low tone, right = high tone, press = buzzer off—one joystick does it all.

---

## 4. Code to write

**Type** the code below into `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
// Joystick: up/down = LED, left/right = pitch, press = stop buzzer
#define JOYSTICK_PIN A0
#define LED_PIN 13
#define BUZZER_PIN 3

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Joystick control started");
}

void loop() {
  int val = analogRead(JOYSTICK_PIN);   // Different ranges = direction
  if (val >= 100 && val <= 130) {
    // Up: LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Up - LED on");
  } else if (val >= 450 && val <= 470) {
    // Down: LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("Down - LED off");
  } else if (val >= 270 && val <= 290) {
    // Left: low tone
    tone(BUZZER_PIN, 262);
    Serial.println("Left - low");
  } else if (val >= 1000 && val <= 1024) {
    // Right: high tone
    tone(BUZZER_PIN, 523);
    Serial.println("Right - high");
  } else if (val >= 180 && val <= 190) {
    // Press: stop buzzer
    noTone(BUZZER_PIN);
    Serial.println("Press - stop");
  } else {
    noTone(BUZZER_PIN);   // Center/other: stop buzzer
  }
  delay(200);   // Poll interval
}
```

---

### Program notes

**Overall idea:** Same as L34: read joystick on A0 and use value ranges for direction. Here: up/down control LED, left/right use `tone` for different pitch, press and center call `noTone`. Calibrate ranges to your module.

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. **Use the joystick:**
   - Up: LED on  
   - Down: LED off  
   - Left: buzzer low tone  
   - Right: buzzer high tone  
   - Press: buzzer off  
4. Try yourself: add RGB LED colors for directions  

**Expected result:**

Serial monitor:
```
Joystick control started
Up - LED on
Down - LED off
Left - low
Right - high
Press - stop
...
```
LED and buzzer respond to joystick.

Proceed to Lesson 43.

---

*TinkerBlock Arduino Beginner Workshop — Lesson 42*
