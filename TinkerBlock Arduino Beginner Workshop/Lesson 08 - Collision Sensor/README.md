# Lesson 08 - Collision Sensor

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK17 Collision Sensor** module, **TinkerBlock TK01 XL LED** module, jumper wires (or breadboard). Learn the **collision sensor**. **Outcome:** when you tap or bump the module the LED turns on; when you stop, it turns off.

---

## 1. Wiring

- **TK17 collision sensor:** VCC → 5V, GND → GND, SIGNAL → D2, NC leave unconnected  
- **TK01 LED:** GND → GND, SIGNAL → D13

![TK17 + LED wiring diagram](../../Sensors/TK17%20-%20Collision%20Sensor/images/wiring_diagram-1.webp)

---

## 2. New sketch

1. Arduino IDE: File → **New** (or Ctrl/Cmd + N) to create a blank sketch  
2. Confirm board and port are selected (same as Lesson 01)  
3. **Type** the code below into the default `setup()` and `loop()` yourself  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Tell the board “pin 2 for reading the collision sensor, pin 13 for the LED”; runs once.  
- **`loop()`**: Keep repeating “read pin 2 → if collision detected then LED on, else LED off → short delay”.

Type the code, upload, tap the module and the LED turns on; stop and it turns off—that’s how collision detection is used.

---

## 4. Code to write

**Type** the code below line by line into `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
// Collision sensor on D2, LED on D13: output HIGH on collision/vibration, LED on
#define COLLISION_PIN 2
#define LED_PIN 13

void setup() {
  pinMode(COLLISION_PIN, INPUT);   // D2 read collision sensor
  pinMode(LED_PIN, OUTPUT);        // D13 control LED
}

void loop() {
  int state = digitalRead(COLLISION_PIN);   // TK17 is HIGH on collision/vibration

  if (state == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(50);   // short delay is enough since we read often
}
```

---

### Program notes

**Overall idea:** Same as button and touch: digital input on D2; LED on when HIGH, off when LOW. TK17 outputs HIGH when it detects collision or vibration; the module may have a sensitivity trimmer.

| Code | In this lesson |
|------|----------------|
| **`digitalRead(COLLISION_PIN)`** | Read sensor output: collision/vibration=HIGH, otherwise=LOW |
| **`if (state == HIGH)`** | If triggered then LED on, else off |
| **`delay(50)`** | Short delay for both response and stability |

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. **Collision detection:**
   - Tap or bump the TK17 module: TK01 LED should turn on  
   - Stop: LED should turn off  
4. (Optional) The TK17 module may have a sensitivity trimmer; you can turn it to adjust sensitivity  

**Expected result:**

![Collision sensor effect](../../Sensors/TK17%20-%20Collision%20Sensor/images/TK17-uno.webp)

**Note:** TK18 Hall Effect Sensor and TK41 Reed Switch work similarly (magnetic sensing); you can try them on your own.

Proceed to Lesson 09.

---

## 6. Common issues

| Symptom | What to do |
|---------|------------|
| LED does not turn on after collision | Check TK17 wiring VCC→5V, GND→GND, SIGNAL→D2; check TK01 SIGNAL→D13, GND→GND; try adjusting the sensitivity trimmer on TK17 |
| LED always on | TK17 may be seeing constant vibration; try turning the sensitivity trimmer down |

---

*TinkerBlock Arduino Beginner Workshop — Lesson 08*
