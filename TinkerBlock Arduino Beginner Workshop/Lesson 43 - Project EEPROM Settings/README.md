# Lesson 43 - Project: EEPROM Settings

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK31 EEPROM** module, **TinkerBlock TK04 Push Button** module, **TinkerBlock TK01 XL LED** module, jumper wires (or breadboard). **Project:** save LED on/off state in EEPROM; **outcome:** button toggles LED and writes state to EEPROM; after power off and on, state is read from EEPROM and LED is restored.

---

## 1. Project goal

Build a settings-save system:
- Press button: change LED state and save to EEPROM  
- Power on again: read last state from EEPROM and restore LED  

---

## 2. Wiring

- **TK31 EEPROM:** GND → GND, VCC → 5V, SDA → A4, SCL → A5  
- **TK04 Button:** VCC → 5V, GND → GND, SIGNAL → D2  
- **TK01 LED:** GND → GND, SIGNAL → D13  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Include library, init, read last state from EEPROM, restore LED; runs once.  
- **`loop()`**: Keep repeating “detect button → change state → save to EEPROM → wait → repeat”.

Button changes LED state and it is stored in EEPROM; after power cycle the LED returns to the last state.

---

## 4. Code to write

**Type** the code below at the top of the file and in `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
// EEPROM save LED state: button toggles and writes; on power-up read and restore
#include <Wire.h>
#define EEPROM_ADDR 0x50   // TK31 I2C address
#define BUTTON_PIN 2
#define LED_PIN 13

int lastButtonState = HIGH;
bool ledState = false;

void setup() {
  Wire.begin();   // I2C init (SDA=A4, SCL=A5)
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  
  // Read last state from EEPROM
  byte savedState = readEEPROM(0);
  ledState = (savedState == 1);
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
  
  Serial.print("Restored: LED ");
  Serial.println(ledState ? "on" : "off");
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  
  // Button press (HIGH -> LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;   // Toggle LED
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    
    // Save to EEPROM
    writeEEPROM(0, ledState ? 1 : 0);
    
    Serial.print("Saved: LED ");
    Serial.println(ledState ? "on" : "off");
    
    delay(200);
  }
  
  lastButtonState = buttonState;   // For edge detection
  delay(50);   // Debounce
}

void writeEEPROM(int address, byte data) {   // I2C write one byte
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write(address >> 8);
  Wire.write(address & 0xFF);
  Wire.write(data);
  Wire.endTransmission();
  delay(5);
}

byte readEEPROM(int address) {   // I2C read one byte
  byte data = 0;
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write(address >> 8);
  Wire.write(address & 0xFF);
  Wire.endTransmission();
  Wire.requestFrom(EEPROM_ADDR, 1);
  if (Wire.available()) {
    data = Wire.read();
  }
  return data;
}
```

---

### Program notes

**Overall idea:** In `setup()` read one byte from EEPROM address 0; if 1 then `ledState=true` and LED on, else off. In `loop()` detect button edge (HIGH→LOW), toggle `ledState` and `writeEEPROM(0, ledState?1:0)`; on next power-up `readEEPROM(0)` restores. Review L28 I2C EEPROM read/write.

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. **Test:**
   - Press button: LED state changes and is saved to EEPROM  
   - Power off and on: LED restores to last state  
4. Try yourself: save more settings (e.g. brightness, color)  

**Expected result:** After power cycle, LED restores to the last saved state.

Proceed to Lesson 44.

---

*TinkerBlock Arduino Beginner Workshop — Lesson 43*
