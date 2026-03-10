# TinkerBlock Arduino Beginner Workshop — Course Index

This course has **45 lessons**, from environment setup to integrated projects, progressing from basics to advanced. Each lesson includes: wiring → program structure → code → hands-on. Syntax is tied to the current module, with 1–2 new concepts per lesson.

---

## Course Index

| # | Topic | Modules Used | Content / Syntax |
|---|--------|--------------|------------------|
| 01 | [Arduino IDE Installation & Setup](Lesson%2001%20-%20Installing%20Arduino%20IDE/) | — | Board, port, CH340 driver, first upload |
| 02 | [First Program: Blink](Lesson%2002%20-%20First%20Program%20Blink/) | TK01 XL LED | setup / loop, pinMode, digitalWrite, delay |
| 03 | [Digital Input: Button](Lesson%2003%20-%20Digital%20Input%20Button/) | TK04 Button, TK01 LED | digitalRead, if / else, digital input |
| 04 | [Traffic Light](Lesson%2004%20-%20Traffic%20Light/) | TK03 Traffic Light | Multi-pin digital output, #define |
| 05 | [Serial Monitor Debugging](Lesson%2005%20-%20Serial%20Monitor%20Debugging/) | TK04, TK01 | Serial.begin, Serial.print / println, serial monitor |
| 06 | [RGB LED](Lesson%2006%20-%20RGB%20LED/) | TK02 RGB LED | Three digital outputs, #define |
| 07 | [Latching Button](Lesson%2007%20-%20Latching%20Button/) | TK05 Latch button, TK01 | Digital input, state hold |
| 08 | [Collision Sensor](Lesson%2008%20-%20Collision%20Sensor/) | TK17 Collision, TK01 | digitalRead, collision detection |
| 09 | [Touch Sensor](Lesson%2009%20-%20Touch%20Sensor/) | TK43 Touch, TK01 | Digital input, capacitive touch |
| 10 | [Tilt Sensor](Lesson%2010%20-%20Tilt%20Sensor/) | TK62 Tilt, TK01 | Digital input, tilt detection |
| 11 | [Potentiometers](Lesson%2011%20-%20Potentiometers/) | TK08 Potentiometer, TK01 (opt), TK07 (opt) | analogRead, int, Serial print, A0 / 0–1023 |
| 12 | [NTC Thermistor](Lesson%2012%20-%20NTC%20Thermistor/) | TK12 NTC | Analog input, voltage conversion |
| 13 | [Ambient Light Sensor](Lesson%2013%20-%20Ambient%20Light%20Sensor/) | TK20 Light | analogRead, light value |
| 14 | [Knock Sensor](Lesson%2014%20-%20Knock%20Sensor/) | TK28 Knock, TK01 | Digital input, knock detection |
| 15 | [Multiple Sensors with Serial](Lesson%2015%20-%20Multiple%20Sensors%20with%20Serial/) | TK08, TK04, TK01 | Multiple variables, Serial print, multi-sensor |
| 16 | [PWM Fading LED](Lesson%2016%20-%20PWM%20Fading%20LED/) | TK01 | PWM, analogWrite, for loop, 0–255, breathing LED |
| 17 | [Passive Buzzer](Lesson%2017%20-%20Passive%20Buzzer/) | TK37 Passive buzzer | tone, noTone, frequency and pitch |
| 18 | [Active Buzzer](Lesson%2018%20-%20Active%20Buzzer/) | TK36 Active buzzer | digitalWrite, const |
| 19 | [Vibration Motor](Lesson%2019%20-%20Vibration%20Motor/) | TK30 Vibration motor | digitalWrite / analogWrite, PWM speed |
| 20 | [RGB Color Mixing](Lesson%2020%20-%20RGB%20Color%20Mixing/) | TK02 RGB LED | analogWrite x3, PWM color mixing |
| 21 | [TM1637 4-Digit Display](Lesson%2021%20-%20TM1637%204-Digit%20Display/) | TK51 TM1637 | Library install, TM1637Display, showNumberDec |
| 22 | [Matrix LED](Lesson%2022%20-%20Matrix%20LED/) | TK52 Matrix | LedControl, arrays, setRow |
| 23 | [Custom Functions](Lesson%2023%20-%20Custom%20Functions/) | TK01 (or TK02/TK03) | void function, reuse logic |
| 24 | [1.8" TFT Display](Lesson%2024%20-%201.8%20Inch%20TFT%20Display/) | TK89 1.8" TFT | Arduino_GFX, fillScreen, setCursor, println |
| 25 | [WS2812 RGB LED Bar](Lesson%2025%20-%20WS2812%20RGB%20LED%20Bar/) | TK33 WS2812 bar | FastLED, CRGB, addLeds, show |
| 26 | [IR Communication](Lesson%2026%20-%20IR%20Communication/) | TK15 IR receiver, TK16 IR sender | IRremote, IRrecv / IRsend, decode, sendNEC |
| 27 | [NTC Thermistor Temperature](Lesson%2027%20-%20NTC%20Thermistor%20Temperature/) | TK12 NTC | Analog input, Beta equation, temperature, math.h |
| 28 | [EEPROM Memory](Lesson%2028%20-%20EEPROM%20Memory/) | TK31 EEPROM | Wire, I2C, read/write EEPROM, non-volatile |
| 29 | [ADC Concept](Lesson%2029%20-%20ADC%20Concept/) | TK29 (opt) or concept only | analogRead vs digitalRead, 0–1023, 10-bit ADC |
| 30 | [Rotary Encoder](Lesson%2030%20-%20Rotary%20Encoder/) | TK06 Encoder, TK01 | CLK/DATA edges, direction, button, brightness |
| 31 | [I2C Temperature LM75](Lesson%2031%20-%20I2C%20Temperature%20LM75/) | TK42 LM75 | Wire, I2C read register, temperature |
| 32 | [I2C Matrix Keypad](Lesson%2032%20-%20I2C%20Matrix%20Keypad/) | TK85 I2C keypad | I2C, PCF8574, scan, keymap |
| 33 | [Steam Sensor](Lesson%2033%20-%20Steam%20Sensor/) | TK65 Steam | Analog input, steam value 0–1023 |
| 34 | [Joystick](Lesson%2034%20-%20Joystick/) | TK94 Joystick, TK01 | Analog input, direction and button |
| 35 | [Voltmeter](Lesson%2035%20-%20Voltmeter/) | TK09 Voltmeter | Analog input, voltage conversion |
| 36 | [Piezo Sensor](Lesson%2036%20-%20Piezo%20Sensor/) | TK59 Piezo | Analog input, pressure/vibration |
| 37 | [Extreme Bright Dual LEDs](Lesson%2037%20-%20Extreme%20Bright%20Dual%20LEDs/) | TK95 Dual LED | Two PWM, warm/cool white, color temp |
| 38 | [Project: Temperature & Humidity Display](Lesson%2038%20-%20Project%20Temperature%20Humidity%20Display/) | TK38 DHT11, serial or TK51 | DHT library, read T/H, serial or display |
| 39 | [Project: Button, Buzzer & LED](Lesson%2039%20-%20Project%20Button%20Buzzer%20LED/) | TK04, TK36/TK37, TK01/TK02 | Multi output, button control |
| 40 | [Project: Potentiometer Control](Lesson%2040%20-%20Project%20Potentiometer%20Control/) | TK08, TK02 or TK37 | Analog in → output, map, brightness or tone |
| 41 | [Project: IR Remote LED](Lesson%2041%20-%20Project%20IR%20Remote%20LED/) | TK15 IR receiver, TK01/TK02 | IR decode, key code, control LED |
| 42 | [Project: Joystick Control](Lesson%2042%20-%20Project%20Joystick%20Control/) | TK94, TK01, TK37 (opt) | Joystick direction/button, LED + buzzer |
| 43 | [Project: EEPROM Settings](Lesson%2043%20-%20Project%20EEPROM%20Settings/) | TK31, TK04, TK01 | EEPROM read/write, save state, restore on boot |
| 44 | [Project: TFT Sensor Display](Lesson%2044%20-%20Project%20TFT%20Sensor%20Display/) | TK89 TFT, TK38 DHT11 | TFT + DHT, show T/H on screen |
| 45 | [Final Project: Integration](Lesson%2045%20-%20Final%20Project%20Integration/) | Any previous modules | Choose theme, wiring and code, integration |

---

## Notes

- **Modules**: Each lesson lists the main TinkerBlock modules used (e.g. TK01, TK04); optional modules are marked with “optional” or in parentheses.
- **Syntax**: Introduced step by step per lesson—e.g. #define, Serial, variables, for, libraries, I2C, custom functions—explained in the corresponding lesson with the module.
- **Lesson structure**: Modules used in this lesson → wiring (with diagram) → new sketch → program structure → code to write → hands-on → common issues (optional).
- **Module details**: Wiring and examples are under `Sensors/TKxx - ModuleName/` (README, Arduino.md, images).
