# Lesson 19 - Vibration Motor

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK30 Vibration Motor** module, jumper wires (or breadboard). Learn to control the motor with **`digitalWrite()`** or **`analogWrite()`**; **outcome:** motor vibrates 0.5 s, stops 0.5 s, repeat; optional PWM for strength.

---

## 1. Wiring

Connect TK30 Vibration Motor to Arduino:

- **GND** → Arduino GND  
- **VCC** → Arduino 5V  
- **SIGNAL** → Arduino D3 (PWM pin for speed control)  
- **NC** leave unconnected

![TK30 wiring diagram](../../Sensors/TK30%20-%20Vibration%20Motor/images/wiring_diagram-1.webp)

---

## 2. New sketch

1. Arduino IDE: File → **New** (or Ctrl/Cmd + N) to create a blank sketch  
2. Confirm board and port are selected (same as Lesson 01)  
3. **Type** the code below into the default `setup()` and `loop()` yourself  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Tell the board “pin 3 for motor”; start serial (optional); runs once.  
- **`loop()`**: Keep repeating “motor on → wait → motor off → wait → repeat”.

After uploading the motor will vibrate then stop in a loop; for strength control try the PWM code in the comments.

---

## 4. Code to write

**Type** the code below line by line into `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
#define MOTOR_PIN 3   // Vibration motor on D3

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);   // D3 output for motor (PWM for speed)
  Serial.begin(9600);
  Serial.println("Vibration motor program started");
}

void loop() {
  // Method 1: digitalWrite (on/off only)
  digitalWrite(MOTOR_PIN, HIGH);   // Vibrate
  Serial.println("Motor vibrating...");
  delay(500);
  
  digitalWrite(MOTOR_PIN, LOW);    // Stop
  Serial.println("Motor stopped");
  delay(500);
  
  // Method 2: analogWrite for speed (optional, uncomment to try)
  // analogWrite(MOTOR_PIN, 128);   // 50% speed
  // delay(500);
  // analogWrite(MOTOR_PIN, 255);   // 100% speed
  // delay(500);
  // analogWrite(MOTOR_PIN, 0);     // Stop
  // delay(500);
}
```

---

### Program notes

**Overall idea:** Motor on PWM pin: `digitalWrite(HIGH/LOW)` = on/off; `analogWrite(0–255)` = vibration strength (higher duty cycle = stronger). This lesson uses digitalWrite for on/off loop; optionally try the analogWrite lines for speed control.

| Code | In this lesson |
|------|----------------|
| **`digitalWrite(MOTOR_PIN, HIGH/LOW)`** | On/off vibration, no speed steps |
| **`analogWrite(MOTOR_PIN, 128)`** | PWM: 0=off, 255=full, in-between=weaker |

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. Feel TK30: vibrate 0.5 s, stop 0.5 s, repeat  
4. Try yourself:
   - Uncomment method 2 and use `analogWrite()` to control strength  
   - Change `delay()` to change on/off time  

**Expected result:** As in the figure.

![Vibration motor effect](../../Sensors/TK30%20-%20Vibration%20Motor/images/TK30-uno.webp)

Proceed to Lesson 20.

---

## 6. Common issues

| Symptom | What to do |
|---------|------------|
| Motor not vibrating | Check TK30 wiring GND→GND, VCC→5V, SIGNAL→D3 |
| Too weak | Try `analogWrite(MOTOR_PIN, 255)` for max strength |

---

*TinkerBlock Arduino Beginner Workshop — Lesson 19*
