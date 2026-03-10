# Lesson 03 - Digital Input: Button

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK04 Push Button** module, **TinkerBlock TK01 XL LED** module, jumper wires (or breadboard). Use the button as **digital input**; learn to combine `digitalRead()` with `digitalWrite()`. **Outcome:** press the button and the LED turns on; release and it turns off.

---

## 1. Wiring

- **TK04 button:** VCC → 5V, GND → GND, SIGNAL → D2, NC leave unconnected  
- **TK01 LED:** GND → GND, SIGNAL → D13 (in code **13** is this pin; button uses **2**)

Wire the button and LED as in the diagram below.

![TK04 + LED wiring diagram](images/wiring_diagram-1.png)

---

## 2. New sketch

1. Arduino IDE: File → **New** (or Ctrl/Cmd + N) to create a blank sketch  
2. Confirm board and port are selected (same as Lesson 01)  
3. **Type** the code below into the default `setup()` and `loop()` yourself  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Tell the board “pin 2 is for reading the button, pin 13 is for the LED”; runs once.  
- **`loop()`**: Keep repeating “read pin 2 to get state → **use if to decide**: if state means ‘pressed’ then turn LED on, **else** turn LED off → short delay (debounce)”.  
- **if** chooses which block runs depending on whether the condition is true or false, so the program can react to the button.

---

## 4. Code to write

**Type** the code below line by line into `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
// Button on D2, LED on D13: read button state, on when pressed, off when released
#define BUTTON_PIN 2    // button SIGNAL to D2
#define LED_PIN 13      // LED SIGNAL to D13

void setup() {
  pinMode(BUTTON_PIN, INPUT);   // D2 as input, to read button
  pinMode(LED_PIN, OUTPUT);     // D13 as output, to control LED
}

void loop() {
  int state = digitalRead(BUTTON_PIN);   // TK04 is HIGH when pressed, LOW when released

  if (state == HIGH) {                   // condition true means button pressed
    digitalWrite(LED_PIN, HIGH);          // pressed: LED on
  } else {
    digitalWrite(LED_PIN, LOW);           // released: LED off
  }
  delay(100);   // short delay to reduce mis-triggers from mechanical bounce (simple debounce)
}
```

**About if and else**

- **What is a condition**  
  A condition is something that can be true or false. Here `state == HIGH` is a condition: when state equals HIGH the condition is **true**, otherwise **false**.  
  Note: **two equals `==` means “compare for equality”**; one `=` is assignment. Writing `if (state = HIGH)` is a logic error.

- **if (condition) { ... }**  
  When the condition in parentheses is **true**, run the code in the curly braces; if false, skip that block and see if there is an else.

- **else { ... }**  
  Must come right after an if. When the if condition is **false**, the code in the else block runs. So **each time only one** of the if block or else block runs, never both.

- **In this lesson**  
  `state == HIGH` means “button pressed”. So: when pressed the if block runs (LED on); when released the else block runs (LED off).

Once that’s clear, type the code in; press the button and the LED turns on, release and it turns off—you’ll see if-else in action.

| Code | In this lesson |
|------|----------------|
| **`#define BUTTON_PIN 2`** | Use a constant name for the button pin so you only change one place when wiring changes |
| **`pinMode(BUTTON_PIN, INPUT)`** | Set the button pin as **input** to read the level (TK04 pressed=HIGH, released=LOW) |
| **`pinMode(LED_PIN, OUTPUT)`** | Set the LED pin as **output** to control on/off |
| **`digitalRead(BUTTON_PIN)`** | Read the current level of the button pin; returns HIGH or LOW |
| **`digitalWrite(LED_PIN, HIGH/LOW)`** | Control LED on or off |
| **`state == HIGH`** | **Condition**: is state equal to HIGH? Two equals `==` means “compare for equality” (not assignment `=`) |
| **`if (state == HIGH) { ... }`** | If the condition is true (button pressed), run the block (LED on); if false, skip and see else |
| **`else { ... }`** | If the if condition is false (button released), run the else block (LED off); only one of if or else runs each time |
| **`delay(100)`** | Wait 100 ms after each read before the next loop, to reduce multiple triggers from mechanical bounce (simple debounce) |

---

### Program notes

**Overall idea:** In `loop()` we first read the level on D2 with `digitalRead` (HIGH or LOW); then `if (state == HIGH)` — if true, LED on; else LED off. Use two equals `==` for comparison; one `=` is assignment and will cause wrong behavior.

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. **Button controls LED:** When you press TK04, TK01 turns on; when you release, it turns off  

**Expected result:**

![Button controls LED effect](images/TK04-uno.gif)

Proceed to Lesson 04 (or the first module lesson).

---

## 6. Common issues

| Symptom | What to do |
|---------|------------|
| LED does not follow button | Check TK04 wiring VCC→5V, GND→GND, SIGNAL→D2; check TK01 SIGNAL→D13, GND→GND |

---

*TinkerBlock Arduino Beginner Workshop — Lesson 03*
