# Arduino Uno R3 Example

## Goal

This example shows how to use the TK95 - EXTREME BRIGHT DUAL LEDS module on an Arduino Uno R3 to control dual-color LED brightness.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **GND** → Arduino Uno R3 GND
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change these to match your wiring
#define WARM_PIN 2   // Arduino PWM pin connected to 3000K (e.g. D3)
#define COLD_PIN 3   // Arduino PWM pin connected to 6500K (e.g. D5)

void setup() {
  // Set LED pins as output mode
  pinMode(WARM_PIN, OUTPUT);
  pinMode(COLD_PIN, OUTPUT);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}

void loop() {
  // Warm white (3000K brightest, 6500K off)
  analogWrite(WARM_PIN, 255);   // Warm white brightest
  analogWrite(COLD_PIN, 0);      // Cool white off
  Serial.println("Warm white");
  delay(2000);
  
  // Cool white (3000K off, 6500K brightest)
  analogWrite(WARM_PIN, 0);
  analogWrite(COLD_PIN, 255);
  Serial.println("Cool white");
  delay(2000);
  
  // Mixed light (both LEDs on, color temperature in middle)
  analogWrite(WARM_PIN, 128);   // Warm white medium brightness
  analogWrite(COLD_PIN, 128);    // Cool white medium brightness
  Serial.println("Mixed light");
  delay(2000);
}
```

## Effect

![Effect](images/TK95-uno.gif)


## Code Walkthrough

**Lines 2–3: Pin definition**

```cpp
#define WARM_PIN 2   // Arduino PWM pin connected to 3000K (e.g. D3)
#define COLD_PIN 3   // Arduino PWM pin connected to 6500K (e.g. D5)
```

- **`WARM_PIN`:** The Arduino PWM pin connected to warm white (3000K) LED. Change this if you use another pin.
- **`COLD_PIN`:** The Arduino PWM pin connected to cool white (6500K) LED. Change this if you use another pin.

**Lines 5–10: Initialization (setup function)**

```cpp
void setup() {
  // Set LED pins as output mode
  pinMode(WARM_PIN, OUTPUT);
  pinMode(COLD_PIN, OUTPUT);
  
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`pinMode(WARM_PIN, OUTPUT)`:** Set WARM_PIN as OUTPUT mode to control warm white LED (3000K).
- **`pinMode(COLD_PIN, OUTPUT)`:** Set COLD_PIN as OUTPUT mode to control cool white LED (6500K).
- **`Serial.begin(9600)`:** Start serial at 9600 baud.

**Lines 12–31: Main loop (loop function)**

```cpp
void loop() {
  // Warm white (3000K brightest, 6500K off)
  analogWrite(WARM_PIN, 255);   // Warm white brightest
  analogWrite(COLD_PIN, 0);      // Cool white off
  Serial.println("Warm white");
  delay(2000);
  
  // Cool white (3000K off, 6500K brightest)
  analogWrite(WARM_PIN, 0);
  analogWrite(COLD_PIN, 255);
  Serial.println("Cool white");
  delay(2000);
  
  // Mixed light (both LEDs on, color temperature in middle)
  analogWrite(WARM_PIN, 128);   // Warm white medium brightness
  analogWrite(COLD_PIN, 128);    // Cool white medium brightness
  Serial.println("Mixed light");
  delay(2000);
}
```

- **`loop()`:** Runs repeatedly.
- **Warm white stage:** `analogWrite(WARM_PIN, 255)` sets warm white (3000K) brightest, `analogWrite(COLD_PIN, 0)` sets cool white (6500K) off, displays warm white effect.
- **Cool white stage:** `analogWrite(WARM_PIN, 0)` sets warm white off, `analogWrite(COLD_PIN, 255)` sets cool white brightest, displays cool white effect.
- **Mixed light stage:** `analogWrite(WARM_PIN, 128)` and `analogWrite(COLD_PIN, 128)` set both LEDs to medium brightness (128), displays mixed light effect (color temperature in middle).
- **`Serial.println(...)`:** Print current light color type to Serial Monitor.
- **`delay(2000)`:** Wait 2000 milliseconds (2 seconds) before switching to next light color effect, controls switching frequency.
