# Lesson 14 - Knock Sensor

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK28 Knock Sensor** module, **TinkerBlock TK01 XL LED** module, jumper wires (or breadboard). Learn the **knock sensor**; **outcome:** tap the module and the LED turns on; stop and it turns off.

---

## 1. Wiring

- **TK28 Knock Sensor:** VCC → 5V, GND → GND, SIGNAL → D2, NC leave unconnected  
- **TK01 LED:** GND → GND, SIGNAL → D13

![TK28 + LED wiring diagram](../../Sensors/TK28%20-%20Knock%20Sensor/images/wiring_diagram-1.webp)

---

## 2. New sketch

1. Arduino IDE: File → **New** (or Ctrl/Cmd + N) to create a blank sketch  
2. Confirm board and port are selected (same as Lesson 01)  
3. **Type** the code below into the default `setup()` and `loop()` yourself  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Tell the board “pin 2 for reading the knock sensor, pin 13 for the LED”; runs once.  
- **`loop()`**: Keep repeating “read pin 2 → if knock detected then LED on, else LED off → short delay”.

Tap the module and the LED turns on; stop tapping and it turns off. Upload and try it.

---

## 4. Code to write

**Type** the code below line by line into `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
#define KNOCK_PIN 2    // Knock sensor on D2
#define LED_PIN 13     // LED on D13

void setup() {
  pinMode(KNOCK_PIN, INPUT);   // D2 input, read knock sensor
  pinMode(LED_PIN, OUTPUT);    // D13 output, control LED
}

void loop() {
  int state = digitalRead(KNOCK_PIN);   // HIGH=knock, LOW=no knock

  if (state == HIGH) {
    digitalWrite(LED_PIN, HIGH);   // Knock detected: LED on
  } else {
    digitalWrite(LED_PIN, LOW);    // No knock: LED off
  }
  delay(100);   // 100 ms
}
```

---

### Program notes

**Overall idea:** Like the collision sensor: digital input on D2; when knocked/vibrated TK28 outputs HIGH, so LED on; otherwise off.

| Code | In this lesson |
|------|----------------|
| **`digitalRead(KNOCK_PIN)`** | Read knock state: knock=HIGH, no=LOW |
| **`if (state == HIGH)`** | If knock then LED on, else off |

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. **Knock detection:**
   - Tap the TK28 module: TK01 LED should turn on  
   - Stop tapping: LED should turn off  
4. Try different tap strengths and observe when it triggers  

**Expected result:**

![Knock sensor effect](../../Sensors/TK28%20-%20Knock%20Sensor/images/TK28-uno.webp)

Proceed to Lesson 15.

---

## 6. Common issues

| Symptom | What to do |
|---------|------------|
| LED does not turn on when tapping | Check TK28 wiring VCC→5V, GND→GND, SIGNAL→D2; TK01 SIGNAL→D13, GND→GND; try tapping harder |
| LED always on | TK28 may be detecting continuous vibration; stop vibration and try again |

---

*TinkerBlock Arduino Beginner Workshop — Lesson 14*
