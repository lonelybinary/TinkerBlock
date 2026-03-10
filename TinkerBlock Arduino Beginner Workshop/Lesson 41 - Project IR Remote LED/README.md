# Lesson 41 - Project: IR Remote LED

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK15 IR Receiver** module, **TinkerBlock TK01 XL LED** (or **TK02**), jumper wires (or breadboard). **Project:** control LED with IR remote; **outcome:** one IR code (e.g. 0xFF00FF) turns LED on, another (e.g. 0xFF8080) turns it off; serial prints received code and action.

---

## 1. Project goal

Build an IR remote LED system:
- Receive IR remote signals  
- Control LED state based on different keys  

---

## 2. Wiring

- **TK15 IR Receiver:** GND → GND, VCC → 5V, SIGNAL → D3  
- **TK01 LED:** GND → GND, SIGNAL → D13  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Include library, create IR object, init pins, start serial; runs once.  
- **`loop()`**: Keep repeating “receive IR → decide key → control LED → wait → repeat”.

Point the remote at the receiver and press a key to turn the LED on or off; serial prints the IR code so you can change the codes in code to match your remote.

---

## 4. Code to write

**Type** the code below at the top of the file and in `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
// IR remote LED: specific code = on/off; print code to serial
#include <IRremote.h>
#define IR_PIN 3    // IR receiver on D3
#define LED_PIN 13  // LED on D13

IRrecv irrecv(IR_PIN);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  irrecv.enableIRIn();   // Start IR receive
  Serial.begin(9600);
  Serial.println("IR remote LED started");
}

void loop() {
  if (irrecv.decode()) {   // One IR frame received
    unsigned long code = irrecv.decodedIRData.decodedRawData;
    
    Serial.print("Received IR code: ");
    Serial.println(code, HEX);
    
    // Control LED by code (example: 0xFF00FF on, 0xFF8080 off)
    if (code == 0xFF00FF) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED on");
    } else if (code == 0xFF8080) {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED off");
    }
    
    irrecv.resume();   // Ready for next frame
  }
  delay(100);
}
```

---

### Program notes

**Overall idea:** When `irrecv.decode()` is true, get the IR code from `decodedRawData`; use `if (code == 0xFF00FF)` etc. to control LED on/off; then `irrecv.resume()` for the next frame. Read your remote’s codes from serial first, then put them in the code.

| Code | In this lesson |
|------|----------------|
| **`decodedIRData.decodedRawData`** | Decoded IR code (e.g. 0xFF00FF) for comparison |
| **`if (code == 0xFF00FF)`** | Match “on” key and turn LED on; change code to match your remote |
| **`irrecv.resume()`** | Must call after handling a frame to keep receiving |

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. **Open Serial Monitor** (Tools → Serial Monitor, baud 9600)  
4. **Point remote at TK15:**
   - Press different keys and watch the IR codes on serial  
   - Change the code values in the sketch to match your remote  
   - Test LED on/off  
5. Try yourself: add more keys, e.g. control RGB LED colors  

**Expected result:** IR remote controls LED on/off.

Proceed to Lesson 42.

---

*TinkerBlock Arduino Beginner Workshop — Lesson 41*
