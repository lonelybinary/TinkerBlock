# Lesson 38 - Project: Temperature Humidity Display

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK38 DHT11** module, Serial Monitor (or **TinkerBlock TK51 TM1637 4-Digit Display**), jumper wires (or breadboard). **Project:** read temperature and humidity and display; **outcome:** serial shows temperature and humidity continuously, or 4-digit display shows temperature (integer).

---

## 1. Project goal

Build a temperature and humidity display:
- Read DHT11 temperature and humidity  
- Show on Serial Monitor (or on 4-digit display)

---

## 2. Wiring

**Option 1: Serial display**
- **TK38 DHT11:** GND → GND, VCC → 5V, DATA → D2

**Option 2: 4-digit display**
- **TK38 DHT11:** GND → GND, VCC → 5V, DATA → D2  
- **TK51 TM1637:** GND → GND, VCC → 5V, CLK → D3, DIO → D4

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Include library, init sensor and display, start serial; runs once.  
- **`loop()`**: Keep repeating “read temp/humidity → display → wait → repeat”.

Option 1: see temp/humidity on serial. Option 2: temperature on 4-digit display. Pick one and you have a small project.

---

## 4. Code to write

**Option 1: Serial display**

```cpp
// Option 1: DHT11 temp/humidity → serial
#include <DHT.h>
#define DHTPIN 2        // DHT11 DATA on D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();   // Init DHT
  Serial.println("Temp/humidity display started");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("°C | Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  delay(2000);   // Update every 2 s
}
```

**Option 2: 4-digit display**

```cpp
// Option 2: DHT11 temperature → 4-digit display
#include <DHT.h>
#include <TM1637Display.h>
#define DHTPIN 2
#define DHTTYPE DHT11
#define CLK_PIN 3   // TM1637 CLK
#define DIO_PIN 4   // TM1637 DIO

DHT dht(DHTPIN, DHTTYPE);
TM1637Display display(CLK_PIN, DIO_PIN);

void setup() {
  dht.begin();
  display.setBrightness(7);   // Display brightness 0-7
}

void loop() {
  float temperature = dht.readTemperature();
  display.showNumberDec((int)temperature);   // Integer part only
  delay(2000);
}
```

---

### Program notes

**Overall idea:** Option 1 uses DHT library to read temp/humidity and `Serial.print` to output. Option 2 adds TM1637 and `display.showNumberDec((int)temperature)` for temperature integer. If you don’t have DHT11, you can use Lesson 27 NTC for temperature and show on serial or display.

---

## 5. Hands-on

1. Choose Option 1 or Option 2  
2. After entering the code, click **Verify** (✓) to compile  
3. Click **Upload** (→) to upload to the board  
4. Watch the display: current temperature and humidity  
5. Try yourself: add humidity on display, switch display, etc.  

**Expected result:**

Option 1 (serial) example:
```
Temp/humidity display started
Temp: 25.30°C | Humidity: 60.00%
Temp: 25.40°C | Humidity: 59.80%
...
```
Option 2: 4-digit display shows temperature integer; serial can still print both.

Proceed to Lesson 39.

---

*TinkerBlock Arduino Beginner Workshop — Lesson 38*
