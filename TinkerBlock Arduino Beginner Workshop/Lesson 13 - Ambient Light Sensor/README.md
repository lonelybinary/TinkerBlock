# Lesson 13 - Ambient Light Sensor

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK20 Ambient Light** module, jumper wires (or breadboard). Learn to read light with **analog input**; **outcome:** serial shows light value (0–1023)—cover light and value drops, shine light and value rises.

---

## 1. Wiring

Connect TK20 Ambient Light to Arduino:

- **GND** → Arduino GND  
- **VCC** → Arduino 5V  
- **SIGNAL** → Arduino A0  
- **NC** leave unconnected

![TK20 wiring diagram](../../Sensors/TK20%20-%20Ambient%20Light/images/wiring_diagram-1.webp)

---

## 2. New sketch

1. Arduino IDE: File → **New** (or Ctrl/Cmd + N) to create a blank sketch  
2. Confirm board and port are selected (same as Lesson 01)  
3. **Type** the code below into the default `setup()` and `loop()` yourself  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Start the serial port (to see values on the computer); runs once.  
- **`loop()`**: Keep repeating “read A0 → store in variable → print to serial → short delay”.

After the code runs, cover the sensor or shine a light and the serial light value will change.

---

## 4. Code to write

**Type** the code below line by line into `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
#define LIGHT_PIN A0   // Light sensor on A0

void setup() {
  Serial.begin(9600);   // Start serial, baud 9600
  Serial.println("Ambient light sensor program started");
}

void loop() {
  int val = analogRead(LIGHT_PIN);   // Read A0, store in val (0-1023)
  
  Serial.print("Light: ");
  Serial.println(val);   // Print val (higher = brighter)
  
  delay(200);   // 200 ms
}
```

---

### Program notes

**Overall idea:** A0 reads the LDR voltage divider; stronger light changes resistance and voltage; ADC 0–1023, higher means brighter. Print to serial for observation.

| Code | In this lesson |
|------|----------------|
| **`analogRead(LIGHT_PIN)`** | Read A0; 0=darkest, 1023=brightest |
| **`int val`** | Holds raw light value |
| **`Serial.println(val)`** | Print to serial to compare cover vs shine |

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. **Open Serial Monitor** (Tools → Serial Monitor, baud 9600)  
4. **Watch the Serial Monitor:**
   - Cover the TK20 module: light value decreases  
   - Shine a phone flashlight on it: light value increases  
   - In normal light: value in the middle range  
5. Try different lighting and observe the values  

**Expected result:**

Serial monitor shows:
```
Ambient light sensor program started
Light: 512
Light: 523
Light: 678
Light: 890
Light: 234
...
```

**Note:** TK27 Analog MIC Sensor works similarly (analog sensor); you can try it on your own.

Proceed to Lesson 14.

---

## 6. Common issues

| Symptom | What to do |
|---------|------------|
| Serial monitor shows nothing | Ensure `Serial.begin(9600)` is in setup(); set Serial Monitor baud to 9600 |
| Light value does not change | Check TK20 wiring GND→GND, VCC→5V, SIGNAL→A0; try covering or shining light on the module |

---

*TinkerBlock Arduino Beginner Workshop — Lesson 13*
