# Overview

The **TK50 Ultrasonic Sensor** is a versatile module engineered for accurate distance measurement. It operates within a voltage range of 2.8V to 5.5V, with a typical current draw of 2-3mA at 5V.

Unlike traditional ultrasonic sensors that are limited to GPIO mode, our innovative TK50 design supports multiple interfaces, including **GPIO, UART, I2C, and 1-WIRE**. It features a measurement cycle time of 50ms in GPIO mode and 100ms in UART/I2C modes, along with a minimal **blind zone of 2-3cm**. Built for reliable operation in demanding conditions, it performs across a broad temperature range: -40°C to 90°C (operating) and -50°C to 100°C (storage).

## Optimal Distance & Accuracy

While the TK50 can theoretically measure up to 400 cm, its **recommended and most reliable operating range is between 2 cm and 200-300 cm (2 to 3 meters)**.

- **Minimum Distance (2 cm):** Objects closer than 2 cm fall within the sensor's "blind spot." At these very short distances, the echo can return before the sensor finishes transmitting, leading to inaccurate or erratic readings.
- **Accuracy at Closer Ranges:** For distances between 2 cm and 100 cm, the TK50 is highly accurate, often achieving a resolution of around 0.3 cm and an accuracy within ±1 cm.
- **Performance at Longer Distances:** Beyond 2-3 meters, the sensor's accuracy and reliability may decrease. As sound waves spread and echoes weaken, detecting a clear return signal becomes more challenging, especially with targets that aren't flat, large, or perpendicular to the sensor. This can result in fluctuating or occasional erroneous readings.

**In summary:**

- **Minimum Reliable Distance:** 2 cm
- **Maximum Recommended Distance:** 200-300 cm (2 to 3 meters)
- **Absolute Maximum (Ideal Conditions):** 400 cm (4 meters)

# TK50 vs. HC-SR04: A Clear Advantage

The **HC-SR04** has long been the market's most common ultrasonic sensor. However, the **TK50 Ultrasonic Sensor** offers significant advancements, especially for modern microcontroller projects.

The TK50 utilizes a newer, **low-power IC**, allowing it to operate seamlessly with both **5V and 3.3V microcontrollers**. This is a critical improvement, as the HC-SR04 is **unable to run directly on 3.3V MCUs** like the ESP32 and Raspberry Pi Pico without additional voltage level shifting. The TK50 solves this compatibility challenge right out of the box.

Beyond voltage flexibility, the TK50 also boasts **four versatile operating modes** (GPIO, I2C, UART, and 1-Wire) compared to the HC-SR04's single GPIO mode. Furthermore, as part of the TinkerBlock Series, all TK50 sensors are **lead-free** and built with a high-quality immersion gold process for enhanced reliability.

Here's a quick comparison:


| Features         | TK50 | HC-SR04 |     |
| ---------------- | ---- | ------- | --- |
| **Voltage 3.3V** | ✓    | X       |     |
| **Voltage 5V**   | ✓    | ✓       |     |
| **GPIO Mode**    | ✓    | ✓       |     |
| **I2C Mode**     | ✓    | X       |     |
| **UART Mode**    | ✓    | X       |     |
| **1-Wire Mode**  | ✓    | X       |     |
| **Lead-Free**    | ✓    | X       |     |


# Schematic Diagram



# Mode Selection

The TK50 sensor operates in **GPIO Mode** by default. To select a different interface, simply solder **Jumper 1** and **Jumper 2** according to the configurations in the table below. "Short" indicates that the jumper pads should be soldered to close the circuit.




| Mode   | Jumper 1 | Jumper 2 |
| ------ | -------- | -------- |
| GPIO   | Open     | Open     |
| I2C    | Short    | Open     |
| UART   | Open     | Short    |
| 1-Wire | Short    | Short    |


# Pinout


| Pin  | Function  | GPIO    | UART | I2C | 1-Wire |
| ---- | --------- | ------- | ---- | --- | ------ |
| GND  | Ground    |         |      |     |        |
| VCC  | 3.3v / 5v |         |      |     |        |
| Echo |           | Echo    | TX   | SDA | NC     |
| Trig |           | Trigger | RX   | SCL | Data   |


# Dimensions



# Sample Code

To get started, please install the necessary library from GitHub in your Arduino IDE. After installation, compile and upload the provided code to your board.

[https://github.com/Alash-electronics/AlashUltrasonic](https://github.com/Alash-electronics/AlashUltrasonic)

## GPIO Mode

**GPIO is the sensor's default mode.** To use it, simply leave both Jumper 1 and Jumper 2 open.



```cpp
#include <AlashUltrasonic.h>

// GPIO pins
const uint8_t TRIGGER_PIN = 2;
const uint8_t ECHO_PIN = 3;

AlashUltrasonic sensorGPIO(TRIGGER_PIN, ECHO_PIN);

void setup() {
	Serial.begin(9600);
	sensorGPIO.begin();
}

void loop() {
	float distance = sensorGPIO.getDistance();
	Serial.print("Distance (GPIO): ");
	Serial.print(distance);
	Serial.println(" cm");
	delay(1000);
}
```

## UART Mode

To activate **UART mode**, you should **leave Jumper 1 open and short Jumper 2**.



```cpp
#include <AlashUltrasonic.h>

const uint8_t RX_PIN = 3;
const uint8_t TX_PIN = 2;  

AlashUltrasonic sensorUART(RX_PIN, TX_PIN, true); 
// (Echo_TX_SDA, Trig_RX_SCL_I/O, isUART?)

void setup() {
	Serial.begin(9600);
	sensorUART.begin();
}

void loop() {
	float distanceUART = sensorUART.getDistance();
	Serial.print("Distance (UART): ");
	Serial.print(distanceUART);
	Serial.println(" cm");
	delay(1000);
}
```

## I2C Mode

To activate **I2C mode**, you should **short Jumper 1 and leave Jumper 2 open**.



```cpp
#include <AlashUltrasonic.h>

const uint8_t I2C_ADDRESS = 0x57; // I2C address
AlashUltrasonic sensorI2C(I2C_ADDRESS);

void setup() {
	Serial.begin(9600);
	sensorI2C.begin();
}

void loop() {
	float distance = sensorI2C.getDistance();
	Serial.print("Distance (I2C): ");
	Serial.print(distance);
	Serial.println(" cm");
	delay(1000);
}
```

## One-Wire

To activate **One-Wire mode**, simply **short both Jumper 1 and Jumper 2**.



```cpp
#include <AlashUltrasonic.h>

const uint8_t ONE_WIRE_PIN = 5; // 1-Wire pin
AlashUltrasonic sensorOneWire(ONE_WIRE_PIN, true);

void setup() {
	Serial.begin(9600);
	sensorOneWire.begin();
}
  
void loop() {
	float distance = sensorOneWire.getDistance();
	Serial.print("Distance (1-Wire): ");
	Serial.print(distance);
	Serial.println(" cm");
	delay(1000);
}

```

# Support

If you encounter any issues, please go to [https://lonelybinary.com](https://lonelybinary.com)  and click the Support button located in the bottom right corner. Our team is ready to assist you.

[Technical Support](https://lonelybinary.com)

# Thank You

Thank you for choosing TinkerBlock to fuel your passion for STEM! Whether you’re a student diving into coding, an educator shaping future innovators, a hobbyist bringing your vision to life, or a business seeking cutting-edge solutions, TinkerBlock empowers you to create, learn, and innovate. 

**For school orders, wholesale inquiries, or custom business solutions, please contact us to discuss your specific needs.**

[office@lonelybinary.com](office@lonelybinary.com)

> **Unleash Your Creativity with TinkerBlock – Where Coding Meets the Real World!**

