# Arduino Uno R3 Example

## Goal

This example shows how to use the TK63 - INFRARED TRANSMITTER module on an Arduino Uno R3 to transmit infrared signals.

## Wiring

![Wiring diagram](images/wiring_diagram-1.png)

- **VCC** → Arduino Uno R3 5V
- **GND** → Arduino Uno R3 GND
- **SIGNAL** → Arduino Uno R3 D3
- **NC** → Leave unconnected

## Code

```cpp
// Pin number: change this to match your wiring
#define IR_TX_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D3, recommended to use PWM-capable pin)

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Infrared transmitter program started");
  Serial.println("Transmitting infrared signal...");
}

void loop() {
  // Transmit infrared signal (38kHz modulation)
  // Note: Arduino Uno can use tone() function to generate 38kHz frequency
  // But IRremote library is more recommended for infrared communication
  
  // Simple example: rapid switching to simulate transmission (IRremote library recommended for actual applications)
  for (int i = 0; i < 100; i++) {
    digitalWrite(IR_TX_PIN, HIGH);
    delayMicroseconds(13);  // 38kHz period is about 26 microseconds, HIGH for 13 microseconds
    digitalWrite(IR_TX_PIN, LOW);
    delayMicroseconds(13);
  }
  
  Serial.println("Infrared signal transmitted");
  delay(1000);  // Wait 1 second before transmitting again
}
```

## Effect

![Effect](images/TK63-uno.gif)


## Code Walkthrough

**Line 2: Pin definition**

```cpp
#define IR_TX_PIN 3  // Arduino digital pin connected to SIGNAL (e.g. D3, recommended to use PWM-capable pin)
```

- **`IR_TX_PIN`:** The Arduino digital pin connected to infrared transmitter SIGNAL (recommended to use PWM-capable pin to use `tone()` function to generate 38kHz modulated signal).

**Lines 4–10: Initialization (setup function)**

```cpp
void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("Infrared transmitter program started");
  Serial.println("Transmitting infrared signal...");
}
```

- **`setup()`:** Runs once when the Arduino starts.
- **`Serial.begin(9600)`:** Start serial at 9600 baud.
- **`Serial.println(...)`:** Print program start message and instructions to Serial Monitor.

**Lines 12–28: Main loop (loop function)**

```cpp
void loop() {
  // Transmit infrared signal (38kHz modulation)
  // Note: Arduino Uno can use tone() function to generate 38kHz frequency
  // But IRremote library is more recommended for infrared communication
  
  // Simple example: rapid switching to simulate transmission (IRremote library recommended for actual applications)
  for (int i = 0; i < 100; i++) {
    digitalWrite(IR_TX_PIN, HIGH);
    delayMicroseconds(13);  // 38kHz period is about 26 microseconds, HIGH for 13 microseconds
    digitalWrite(IR_TX_PIN, LOW);
    delayMicroseconds(13);
  }
  
  Serial.println("Infrared signal transmitted");
  delay(1000);  // Wait 1 second before transmitting again
}
```

- **`loop()`:** Runs repeatedly.
- **`for (int i = 0; i < 100; i++)`:** Loop 100 times to generate 38kHz modulated signal (38kHz is the standard carrier frequency for infrared communication).
- **`digitalWrite(IR_TX_PIN, HIGH)`:** Output HIGH to turn on infrared transmission.
- **`delayMicroseconds(13)`:** Wait 13 microseconds (38kHz period is about 26 microseconds, HIGH for 13 microseconds, LOW for 13 microseconds).
- **`digitalWrite(IR_TX_PIN, LOW)`:** Output LOW to turn off infrared transmission.
- **`Serial.println("Infrared signal transmitted")`:** Print infrared signal transmitted message to Serial Monitor.
- **`delay(1000)`:** Wait 1000 milliseconds (1 second) before transmitting again to control transmission frequency.
- **Note:** For actual applications, IRremote library is more recommended for infrared communication, which can send standard format infrared codes.
