# DHT Series

In this chapter, we will explore Digital Humidity and Temperature (DHT) sensors, which are essential components for measuring environmental conditions in electronic projects. We'll cover three popular variants: DHT11, DHT20, and DHT22.

Temperature and humidity measurements are crucial for many applications, from simple home weather stations to complex industrial monitoring systems. These sensors provide digital outputs that can be easily integrated with microcontrollers and other electronic devices.

You will learn the following in this chapter:
- How different DHT sensors work and their specifications
- Understanding temperature measurements and unit conversions
- How humidity is measured and interpreted
- The internal workings of DHT sensors

# DHT Sensors

The name **DHT** stands for **Digital Humidity and Temperature** sensor.  DHT11, DHT20, and DHT22 are small sensors that measure **temperature** and **humidity**. They are often used in DIY electronics projects, home automation, and weather monitoring.

## DHT11


The **DHT11** is a basic temperature and humidity sensor that measures temperatures between 0°C and 50°C and humidity levels from 20% to 90%. It provides data using a single-wire digital protocol. While it offers lower accuracy compared to more advanced sensors like the DHT22, it’s suitable for simple projects like monitoring indoor temperature and humidity. It’s commonly used in beginner electronics and DIY projects where high precision is not critical.

## DHT22


The **DHT22** is a more advanced temperature and humidity sensor compared to the DHT11, offering a wider measurement range and higher accuracy. It measures temperatures from -40°C to 80°C and humidity levels from 0% to 100%, making it suitable for a broader range of environments.  The DHT22 provides data through a single-wire digital protocol, offering reliable performance for projects that require higher precision, such as weather stations or greenhouse monitoring. 

## DHT20


The **DHT20** is an advanced temperature and humidity sensor that offers higher accuracy and a wider measurement range compared to the DHT11 and DHT22. It measures temperatures from -40°C to 80°C and humidity levels from 0% to 100%, with improved precision and stability. Unlike the DHT11 and DHT22, the DHT20 uses an **I²C interface** for data communication, allowing for faster and more reliable data transfer. This makes it a great choice for projects requiring precise environmental monitoring, such as weather stations or indoor climate control systems.

## Comparison of DHT Sensors

Below is a detailed comparison of their features, specifications, and applications:

| Feature              | DHT11              | DHT20                  | DHT22 (AM2302)     |
| -------------------- | ------------------ | ---------------------- | ------------------ |
| Temperature Range    | 0 to 50°C          | -40 to 80°C            | -40 to 80°C        |
| Temperature Accuracy | ±2°C               | ±0.5°C                 | ±0.5°C             |
| Humidity Range       | 20% to 90% RH      | 0% to 100% RH          | 0% to 100% RH      |
| Humidity Accuracy    | ±5% RH             | ±3% RH                 | ±2% RH             |
| Operating Voltage    | 3V - 5.5V          | 2.2V - 5.5V            | 3V - 5.5V          |
| Communication        | One-wire (Digital) | I2C (Digital)          | One-wire (Digital) |
| Sampling Rate        | 1 Hz (1 sec)       | 5 Hz (0.2 sec)         | 0.5 Hz (2 sec)     |
| Power Consumption    | Low                | Very Low               | Low                |
| Price                | Cheapest           | Higher                 | Higher             |
| Application          | Basic DIY, Hobby   | Precise Industrial Use | Weather Monitoring |
# Temperature

The **DHT11** works only between **0 to 50°C**, while **DHT20 and DHT22** can handle **-40 to 80°C**.

This means **DHT11 is not suitable** for:
- **Cold places** (like winter or a fridge)
- **Very hot environments** (like extreme summer heat)

If you need a sensor for **freezing or very hot conditions**, use **DHT20 or DHT22** instead.

## Celsius (°C) 

**Celsius** is used in most of the world because it aligns with the **metric system**, making it easier for scientific use and international communication.  

The Celsius scale is based on **water’s freezing and boiling points** at **standard atmospheric pressure**:

- **0°C** = freezing point of water
- **100°C** = boiling point of water

## Fahrenheit (°F)

**Fahrenheit** was historically used in the **United States** because it was designed to be more practical for everyday life, with smaller increments between degrees, which made it easier to estimate temperature differences.

The Fahrenheit scale was designed to use specific **reference points**:

-  **32°F** = freezing point of water
-  **212°F** = boiling point of water


# Humidity
## Relative Humidity (RH)

Relative humidity is the amount of **water vapor** in the air **compared to the maximum amount the air can hold at a given temperature**. It is expressed as a **percentage (%RH)**.

## What Does Higher RH Mean?

When **RH (Relative Humidity) reaches 100%**, the air is **full of moisture** and **can’t hold any more water vapor**. This can cause **fog, dew, or rain**, depending on where it happens.

• **Near the ground** → Fog or dew may form.
• **In the clouds** → If the moisture turns into droplets, it can lead to **rain or snow**.

If the temperature **drops**, the extra moisture in the air **turns into tiny water droplets**, creating **fog, dew, or even rain**.

# How DHT Sensor works

Inside a DHT sensor, there are three main parts: **a humidity sensor**, **a temperature sensor** and **a MCU**.

**Humidity Sensor**
The **humidity sensor** works with a special material that **absorbs water** from the air. When it absorbs water, it changes its electrical properties, which the sensor uses to calculate the **humidity level**.

**Temperature Sensor**
The **temperature sensor** uses a small device called a **thermistor**. As the temperature changes, the **resistance** of the thermistor also changes, which helps the sensor measure the temperature.

**Microcontroller (MCU)**
Inside the sensor, there is a **tiny microcontroller**. It takes the **raw data** from both the humidity and temperature sensors, converts it into **digital data**, and sends it out. For **DHT11** and **DHT22**, the data is sent using a **single-wire digital protocol**. The **DHT20** uses **I²C** communication, which is faster and more reliable.

# **Working Process**

1. **Power-Up**:
	The sensor is powered via a voltage source (typically 3.3V or 5V).

2. **Sensing**:
	The humidity sensor measures capacitance changes.
	The temperature sensor measures resistance changes.

3. **Data Conversion**:
	The internal ADC converts the analog measurements into digital data.

4. **Data Transmission**:
	The MCU formats and transmits the data via the specified protocol (single-wire or I²C).

By integrating all these components into a single package, DHT sensors provide a compact and user-friendly solution for temperature and humidity sensing.
# Summary

This chapter provides a comprehensive understanding of DHT sensors, their capabilities in measuring temperature and humidity, and how they operate internally. 

The concepts covered here are fundamental for environmental monitoring and can be applied in various projects, from simple home automation to complex industrial applications.