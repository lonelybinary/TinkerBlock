# Lesson 04 - Traffic Light

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK03 Traffic Light** module, jumper wires (or breadboard). Control three LEDs in sequence; learn **multi-pin digital output** and **`#define`**. **Outcome:** red on 5 s → green on 5 s → yellow on 2 s, then repeat.

---

## 1. Wiring

Connect TK03 Traffic Light to Arduino (three LEDs to D2, D3, D4; in code use **2, 3, 4** for these pins):

- **GND** → Arduino GND  
- **RED** → Arduino D2  
- **YELLOW** → Arduino D3  
- **GREEN** → Arduino D4  
- **NC** — leave unconnected

![TK03 wiring diagram](../../Sensors/TK03%20-%20Traffic%20Light/images/wiring_diagram-1.webp)

---

## 2. New sketch

1. Arduino IDE: File → **New** (or Ctrl/Cmd + N) to create a blank sketch  
2. Confirm board and port are selected (same as Lesson 01)  
3. **Type** the code below into the default `setup()` and `loop()` yourself  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Tell the board “pins 2, 3, 4 are for the LEDs”; runs once.  
- **`loop()`**: Keep repeating “red on 5 s → green on 5 s → yellow on 2 s → back to red”.

Type the code below and the red, green, and yellow LEDs will take turns like a traffic light.

---

## 4. Code to write

**Type** the code below line by line into `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
// Traffic light: red(D2), yellow(D3), green(D4) on in sequence, others off
#define RED_PIN 2      // red to D2
#define YELLOW_PIN 3   // yellow to D3
#define GREEN_PIN 4    // green to D4

void setup() {
  pinMode(RED_PIN, OUTPUT);     // red / yellow / green all outputs
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  // Red on 5 s, yellow and green off
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  delay(5000);

  // Green on 5 s, red and yellow off
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  delay(5000);

  // Yellow on 2 s, red and green off
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  delay(2000);
}
```

---

### Program notes

**Overall idea:** Three pins for three LEDs; in `loop()` follow the order red → green → yellow, only one HIGH at a time and the others LOW, then `delay` to hold each phase. Use `#define` to name the pin numbers so you only change one place when wiring changes and the code is easier to read.

| Code | In this lesson |
|------|----------------|
| **`#define RED_PIN 2`** | Macro: give 2 the name RED_PIN, replaced at compile time; makes red/yellow/green pins clear |
| **`pinMode(RED_PIN, OUTPUT)`** | Set that pin as output so digitalWrite can control that LED |
| **`digitalWrite(RED_PIN, HIGH)`** | That pin high, that LED on; **LOW** turns it off |
| **Only one on at a time** | In each phase set the other two LOW first, then the current one HIGH, so only one is on |
| **`delay(5000)`** | Pause 5000 ms (5 s) before the next phase; controls how long each light is on |

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. Watch TK03 Traffic Light: red 5 s → green 5 s → yellow 2 s, then repeat  
4. Change `delay(5000)` to `delay(2000)` and upload again; observe the change  

**Expected result:**

![Traffic light effect](../../Sensors/TK03%20-%20Traffic%20Light/images/TK03-uno.webp)

Proceed to Lesson 05.

---

## 6. Common issues

| Symptom | What to do |
|---------|------------|
| No light after upload | Check wiring GND, RED→D2, YELLOW→D3, GREEN→D4; confirm board and port |
| Compile error | Check brackets and semicolons are paired; **no semicolon after `#define`** (`#define RED_PIN 2` is correct, `#define RED_PIN 2;` is wrong) |
| Wrong order | Check the order in `loop()`: red → green → yellow |

---

*TinkerBlock Arduino Beginner Workshop — Lesson 04*
