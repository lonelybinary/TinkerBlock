# Lesson 44 - Project: TFT Sensor Display

**This lesson uses:** Arduino UNO R3 board, **TinkerBlock TK89 1.8'' TFT** module, **TinkerBlock TK38 DHT11** module, jumper wires (or breadboard). **Project:** show sensor data on TFT; **outcome:** screen refreshes periodically with current temperature and humidity (Temp: xxC, Humi: xx%).

---

## 1. Project goal

Build a sensor display system:
- Read DHT11 temperature and humidity  
- Show temperature and humidity on the TFT screen  

---

## 2. Wiring

- **TK89 TFT:** GND → GND, VCC → 5V, CS → D10, RST → D8, DC → D9, MOSI → D11, SCK → D13, LED → 3.3V or 5V  
- **TK38 DHT11:** GND → GND, VCC → 5V, DATA → D2  

---

## 3. Program structure

Same as last lesson: two fixed blocks `setup()` and `loop()`.

- **`setup()`**: Include libraries, init display and sensor; runs once.  
- **`loop()`**: Keep repeating “read sensor → show on screen → wait → repeat”.

Temp and humidity are shown on the TFT and refresh every few seconds.

---

## 4. Code to write

**Type** the code below at the top of the file and in `setup()` and `loop()` (do not copy-paste; typing it yourself helps you remember):

```cpp
// TFT shows DHT11 temp/humidity; refresh every 2 s
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <DHT.h>
#define CS_PIN 10   // TFT SPI CS
#define RST_PIN 8
#define DC_PIN 9
#define DHTPIN 2    // DHT11 DATA
#define DHTTYPE DHT11

Adafruit_ST7735 tft = Adafruit_ST7735(CS_PIN, DC_PIN, RST_PIN);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(2);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  tft.fillScreen(ST7735_BLACK);   // Clear before redraw to avoid ghosting
  tft.setCursor(10, 10);
  tft.print("Temp: ");
  tft.print(temperature);
  tft.println("C");
  tft.setCursor(10, 40);
  tft.print("Humi: ");
  tft.print(humidity);
  tft.println("%");
  delay(2000);   // Update every 2 s
}
```

---

### Program notes

**Overall idea:** DHT reads temp/humidity; TFT uses `fillScreen` to clear then `setCursor` + `print` for "Temp: xx" and "Humi: xx", refresh every 2 s. This example uses Adafruit_ST7735; if you use Arduino_GFX (e.g. L24) replace the library and init, logic is the same.

---

## 5. Hands-on

1. After entering the code, click **Verify** (✓) to compile  
2. Click **Upload** (→) to upload to the board  
3. Watch TK89 TFT: current temperature and humidity  
4. Try yourself: add more sensor data (e.g. light, voltage)  

**Expected result:** TFT shows current temp/humidity and other sensor data.

Proceed to Lesson 45.

---

*TinkerBlock Arduino Beginner Workshop — Lesson 44*
