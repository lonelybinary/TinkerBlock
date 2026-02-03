# TK97 - LOGIC LEVEL CONVERTER Code Instructions

## Important Note

**This module (TK97 - LOGIC LEVEL CONVERTER) itself does not require code.**

TK97 is a logic level converter module, mainly used for bidirectional conversion between 3.3V and 5V logic levels. It is a hardware auxiliary module and does not require programming.

## Usage Scenario

TK97 module is mainly used together with **TK89 - 1.8INCH TFT ST7735** screen module.

### Why TK97 is Needed?

TK89 screen module's operating voltage is **3.3V**, while Arduino Uno R3 and other development boards' logic level is **5V**. If 5V devices are directly connected to 3.3V devices, the 3.3V device may be damaged.

TK97 logic level converter module can:
- Convert Arduino Uno R3's 5V signals to 3.3V, safely drive TK89 screen
- Convert TK89 screen's 3.3V signals to 5V, allow Arduino Uno R3 to read correctly

### How to Use

1. **Hardware Connection**:
   - Connect TK97 module's OUT side (3.3V side) to TK89 screen
   - Connect TK97 module's IN side (5V side) to Arduino Uno R3
   - For specific wiring methods, please refer to TK89 module's wiring diagram

2. **Code Writing**:
   - **No code needs to be written for TK97**
   - Directly use **TK89 module's example code**
   - TK97 automatically completes level conversion, completely transparent to code

## Example Code Location

TK89 screen module's example code is located at:
- **Arduino Example**: `../TK89 - 1.8INCH TFT ST7735/Arduino.md`
- **MicroPython Example**: `../TK89 - 1.8INCH TFT ST7735/MicroPython.md`

## Summary

- ✅ TK97 is a hardware auxiliary module, no programming needed
- ✅ Used together with TK89 screen module to achieve level conversion
- ✅ Use TK89's example code, TK97 works automatically
- ❌ This module's codes folder being empty is normal, as no code is needed
