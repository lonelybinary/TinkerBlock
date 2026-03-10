# Lesson 45 - Final Project: Free Integration

**This lesson uses:** Arduino UNO R3 board, **any modules from previous lessons**, jumper wires (or breadboard). **Final project:** combine what you learned into one project; **outcome:** choose a theme (e.g. smart lamp, temp/humidity alarm, remote LED), finish wiring, code, and test—wrap up the course.

---

## 1. Project goal

Pick a theme and combine several modules into one project, for example:
- **Smart home controller:** button control, temp/humidity display, LED indicator  
- **Game controller:** joystick, LED feedback, buzzer sound  
- **Environment station:** multiple sensors, TFT display, data logging  

---

## 2. Project ideas

**Project 1: Smart lamp**
- Modules: potentiometer (brightness), RGB LED, button (on/off)  
- Features: potentiometer sets brightness, button switches color  

**Project 2: Temp/humidity alarm**
- Modules: DHT11, buzzer, LED  
- Features: alarm when temperature or humidity is out of range  

**Project 3: Remote LED**
- Modules: IR receiver, RGB LED, button  
- Features: remote controls LED color and brightness  

---

## 3. Project steps

1. **Choose a theme:** Pick a project you like  
2. **Choose modules:** Match modules to the functions you want  
3. **Design behavior:** Plan the flow of the project  
4. **Write code:** Use what you learned in earlier lessons  
5. **Test and debug:** Test each part and fix issues  
6. **Improve:** Add features and polish  

Below is a “smart lamp” example: knob for brightness, button for color; type it in and then change it to your own idea.

---

## 4. Code example (smart lamp)

```cpp
// Example: Smart lamp — potentiometer for brightness, button to change color (white/red/green/blue)
#define POT_PIN A0
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6
#define BUTTON_PIN 2

int brightness = 128;
int colorMode = 0;  // 0=white, 1=red, 2=green, 3=blue

void setup() {
  pinMode(RED_PIN, OUTPUT);     // RGB PWM
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);   // Button to change color
}

void loop() {
  // Read potentiometer for brightness
  int potVal = analogRead(POT_PIN);
  brightness = map(potVal, 0, 1023, 0, 255);
  
  // Button: change color
  if (digitalRead(BUTTON_PIN) == LOW) {
    colorMode = (colorMode + 1) % 4;
    delay(200);
  }
  
  // Set RGB by color mode
  switch (colorMode) {
    case 0:  // White
      analogWrite(RED_PIN, brightness);
      analogWrite(GREEN_PIN, brightness);
      analogWrite(BLUE_PIN, brightness);
      break;
    case 1:  // Red
      analogWrite(RED_PIN, brightness);
      analogWrite(GREEN_PIN, 0);
      analogWrite(BLUE_PIN, 0);
      break;
    case 2:  // Green
      analogWrite(RED_PIN, 0);
      analogWrite(GREEN_PIN, brightness);
      analogWrite(BLUE_PIN, 0);
      break;
    case 3:  // Blue
      analogWrite(RED_PIN, 0);
      analogWrite(GREEN_PIN, 0);
      analogWrite(BLUE_PIN, brightness);
      break;
  }
  
  delay(50);
}
```

---

### Program notes

**Overall idea:** Example is a “smart lamp”: potentiometer maps to `brightness` for PWM; button cycles `colorMode` (0–3); `switch (colorMode)` sets RGB for white/red/green/blue. Uses analog input, digital input, PWM, `map`, edge detection, and `switch`.

**About the switch statement**

The example uses **`switch`** to run different code depending on `colorMode`: `switch (colorMode)` means “check the value of colorMode”; **`case 0:`**, **`case 1:`** etc. run when the value is 0, 1, …; **`break;`** exits the switch (without it execution falls through to the next case). This is clearer than many `if (colorMode == 0) ... else if (colorMode == 1) ...`.

| Code | In this lesson |
|------|----------------|
| **`switch (colorMode)`** | Jump to the matching case by value |
| **`case 0:`** / **`case 1:`** etc. | When value is 0, 1, 2, 3, run that block |
| **`break;`** | Leave the current case; without it the next case runs too |

---

## 5. Hands-on

1. **Choose a theme:** Based on your interest  
2. **Design behavior:** Plan what the project should do  
3. **Write code:** Use skills from earlier lessons  
4. **Test:** Test each part step by step  
5. **Improve:** Add features and refine the project  

**Project outcome:**

A complete Arduino project that does what you designed.

---

## 6. Summary

With this final project you have:
- Learned basic Arduino programming  
- Used many sensors and modules  
- Combined modules into full projects  
- Gained the ability to build your own Arduino projects  

Congratulations on finishing the TinkerBlock Arduino Beginner Workshop!

---

*TinkerBlock Arduino Beginner Workshop — Lesson 45*
