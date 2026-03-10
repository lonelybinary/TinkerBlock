# Lesson 31 - I2C Temperature LM75

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK42 LM75** module, jumper wires (or breadboard). Use **Wire** library for **I2C** to read LM75 temperature; **outcome:** serial continuously shows temperature (°C); warming the sensor makes the value rise.

---

## 1. What is I2C?

**I2C (Inter-Integrated Circuit)** is a protocol using two wires (SDA data, SCL clock) to connect multiple devices.

- **SDA:** data line  
- **SCL:** clock line  
- On Arduino Uno, I2C pins are fixed: **SDA=A4, SCL=A5**

---

## 2. Wiring

Connect TK42 LM75 to Arduino (I2C):

- **GND** → Arduino GND  
- **VCC** → Arduino 5V  
- **SDA** → Arduino A4 (I2C data)  
- **SCL** → Arduino A5 (I2C clock)  
- **NC** leave unconnected

![TK42 wiring diagram](images/wiring_diagram-1.png)

---

## 3. New sketch

1. Arduino IDE: File → **New** (or Ctrl/Cmd + N) to create a blank sketch  
2. Confirm board and port are selected (same as Lesson 01)  
3. **Type** the code below into the default `setup()` and `loop()` yourself  

---

## 4. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Include library, start I2C, start serial; runs once.  
- **`loop()`**: Keep repeating “read temperature over I2C → print to serial → wait → repeat”.

Two wires (SDA, SCL) read temperature; serial will show LM75 °C about once per second.

---

## 5. Code to write

**Type** the code below at the top of the file and in `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
// Read LM75 temperature register over I2C; combine two bytes and convert to °C
#include <Wire.h>

#define LM75_ADDRESS 0x48   // LM75 I2C address (7-bit)

void setup() {
  Wire.begin();   // I2C init (SDA=A4, SCL=A5)
  Serial.begin(9600);
  Serial.println("I2C temperature sensor started");
}

void loop() {
  Wire.beginTransmission(LM75_ADDRESS);
  Wire.write(0x00);   // Temperature register address
  Wire.endTransmission();
  Wire.requestFrom(LM75_ADDRESS, 2);   // Request 2 bytes
  if (Wire.available() >= 2) {
    int highByte = Wire.read();
    int lowByte = Wire.read();
    int tempRaw = (highByte << 8) | lowByte;   // 16-bit raw
    float temperature = (tempRaw >> 5) * 0.125;  // LM75: upper 11 bits, 0.125°C per step
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
  }
  delay(1000);   // Update every second
}
```

---

### Program notes

**Overall idea:** LM75 stores temperature in register 0x00 as 2 bytes. Send register address, then request 2 bytes; high byte first, combine to 16-bit; upper 11 bits are temperature (0.125°C per step), so `(tempRaw >> 5) * 0.125` gives °C.

| Code | In this lesson |
|------|----------------|
| **`Wire.write(0x00)`** | Select register (temperature register) |
| **`Wire.requestFrom(LM75_ADDRESS, 2)`** | Request 2 bytes from device |
| **`(highByte << 8) \| lowByte`** | Combine to 16-bit (signed) raw value |
| **`(tempRaw >> 5) * 0.125`** | LM75 format: shift right 5, multiply by 0.125 for °C |

---

## 6. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. **Open Serial Monitor** (Tools → Serial Monitor, baud 9600)  
4. Watch serial: current temperature in °C  
5. Warm the sensor with your hand and see the value change  

**Expected result:**

![LM75 temperature on serial](images/TK42-uno.jpg)

Serial monitor:
```
I2C temperature sensor started
Temperature: 25.3°C
Temperature: 25.4°C
Temperature: 26.1°C
...
```

Proceed to Lesson 32.

---

*TinkerBlock Arduino Beginner Workshop — Lesson 31*
