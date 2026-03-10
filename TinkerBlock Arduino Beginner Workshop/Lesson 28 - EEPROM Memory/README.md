# Lesson 28 - EEPROM Memory

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK31 EEPROM** module, jumper wires (or breadboard). **First use of I2C:** read/write EEPROM with **Wire** library; **outcome:** write a value (e.g. 123) to EEPROM, power off and on, read from the same address—data is still there, proving it survives power loss.

---

## 1. What is I2C?

**I2C (Inter-Integrated Circuit)** is a protocol that uses two wires to connect multiple devices; good for sensors, memory, etc.

- **SDA:** data line  
- **SCL:** clock line  
- Each I2C device has an **address**; the host selects which device to talk to  
- On Arduino Uno, I2C pins are fixed: **SDA=A4, SCL=A5**

This lesson uses I2C to read/write the EEPROM module (data survives power off); Lesson 32 matrix keypad also uses I2C.

---

## 2. Wiring

Connect TK31 EEPROM to Arduino (I2C):

- **GND** → Arduino GND  
- **VCC** → Arduino 5V  
- **SDA** → Arduino A4 (I2C data)  
- **SCL** → Arduino A5 (I2C clock)  
- **NC** leave unconnected

![TK31 wiring diagram](images/wiring_diagram-1.png)

**Note:** On Arduino Uno, I2C is fixed: SDA=A4, SCL=A5.

---

## 3. New sketch

1. Arduino IDE: File → **New** (or Ctrl/Cmd + N) to create a blank sketch  
2. Confirm board and port are selected (same as Lesson 01)  
3. **Type** the code below into the default `setup()` and `loop()` yourself  

---

## 4. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Include library, start I2C, write data to EEPROM; runs once.  
- **`loop()`**: Keep repeating “read from EEPROM → print to serial → wait → repeat”.

Upload, power off and on, and you’ll see the value you stored—that’s “non-volatile.”

---

## 5. Code to write

**Type** the code below at the top of the file and in `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
// Read/write TK31 EEPROM over I2C: write then read, verify data survives power loss
#include <Wire.h>

#define EEPROM_ADDR 0x50   // TK31 I2C address (7-bit), often 0x50

void setup() {
  Wire.begin();            // Init I2C (uses A4 SDA, A5 SCL)
  Serial.begin(9600);
  
  writeEEPROM(0, 123);     // Write byte 123 to address 0
  Serial.println("Data written to EEPROM");
  delay(100);              // Short wait; EEPROM needs time to write
}

void loop() {
  byte data = readEEPROM(0);   // Read one byte from address 0
  Serial.print("Read from EEPROM: ");
  Serial.println(data);
  delay(2000);
}

// Write one byte to address: I2C sends "device addr + addr high + addr low + data"
void writeEEPROM(int address, byte data) {
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write(address >> 8);    // 16-bit address: high byte first
  Wire.write(address & 0xFF);  // then low byte
  Wire.write(data);            // then data
  Wire.endTransmission();      // end transfer; device starts write
  delay(5);                    // EEPROM write takes a few ms
}

// Read one byte from address: send address, then request 1 byte
byte readEEPROM(int address) {
  byte data = 0;
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write(address >> 8);
  Wire.write(address & 0xFF);
  Wire.endTransmission();       // end address send
  Wire.requestFrom(EEPROM_ADDR, 1);  // request 1 byte from device
  if (Wire.available()) {
    data = Wire.read();
  }
  return data;
}
```

---

### Program notes

**Overall idea:** TK31 is I2C EEPROM; each location has a 16-bit address. Write: send “device addr + 2-byte address + data” over I2C; read: send “device addr + address”, then request 1 byte and get it with `Wire.read()`. In `setup()` we write once; in `loop()` we read and print; after power cycle the value is still 123.

**Why 2-byte address:** EEPROM has many locations, so address is 16-bit: send high byte `address >> 8`, then low byte `address & 0xFF`. Some modules use 1-byte address; check the datasheet.

**Delay after write:** EEPROM needs a few ms to finish writing; without delay an immediate read might return the old value; 5 ms is enough.

| Code | In this lesson |
|------|----------------|
| **`#include <Wire.h>`** | I2C library: begin, beginTransmission, write, requestFrom, read, etc. |
| **`Wire.begin()`** | Init I2C master; Uno uses A4(SDA), A5(SCL) |
| **`Wire.beginTransmission(EEPROM_ADDR)`** | Start write to device 0x50 |
| **`Wire.write(address >> 8)` / `address & 0xFF`** | Send 16-bit address as high then low byte |
| **`Wire.endTransmission()`** | End write; device then performs write |
| **`Wire.requestFrom(addr, 1)`** | Request 1 byte from device; data goes to buffer |
| **`Wire.read()`** | Read one byte from buffer; call when available() is true |

---

## 6. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. **Open Serial Monitor** (Tools → Serial Monitor, baud 9600)  
4. You should see “Data written to EEPROM” then the read value (123)  
5. **Test persistence:** Disconnect power, power on again; the value should still be there  

**Expected result:** As in the figure.

![EEPROM effect](images/TK31-uno.gif)

Proceed to Lesson 29.

---

*TinkerBlock Arduino Beginner Workshop — Lesson 28*
