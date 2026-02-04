/*
 * TK12-NTC THERMISTOR - Arduino Uno R3 Example
 * 
 * Description:
 * This sketch demonstrates how to use the TK12-NTC THERMISTOR module.
 * 
 * Wiring:
 * Change the pin definition in code to match your wiring.
 * 
 * Usage:
 * 1. Upload this sketch to Arduino Uno R3
 * 2. Open Serial Monitor (9600 baud) to see output
 */

#include <math.h>  // For math functions (log)

// Pin number: change this to match your wiring
#define TEMP_PIN A0  // Arduino analog input pin connected to SIGNAL (e.g. A0)

// NTC thermistor parameters (adjust according to actual module specifications)
const float VCC = 5.0;           // Supply voltage (V)
const float R0 = 10000.0;        // NTC resistance at 25°C (Ω), usually 10KΩ
const float T0 = 25.0 + 273.15;  // Reference temperature (Kelvin), 25°C = 298.15K
const float BETA = 3950.0;       // Beta value (according to NTC specifications, common value is 3950, try 3435 or 4100 if temperature is inaccurate)
const float R_SERIES = 10000.0;  // Pull-up resistor value (Ω), usually 10KΩ, adjust if temperature is inaccurate
const float TEMP_OFFSET = 0.0;   // Temperature offset (°C), for calibration, set to negative if temperature is high, positive if low

void setup() {
  // Start serial for debugging (9600 baud)
  Serial.begin(9600);
  
  Serial.println("NTC thermistor program started");
  Serial.println("Using Beta equation to calculate temperature");
}

void loop() {
  // Read analog input value (0-1023)
  int sensorValue = analogRead(TEMP_PIN);
  
  // Convert analog value to voltage (0-5V)
  float voltage = sensorValue * (VCC / 1023.0);
  
  // Calculate NTC thermistor resistance
  // Using voltage divider formula: Vout = VCC * R_NTC / (R_SERIES + R_NTC)
  // Derived: R_NTC = R_SERIES * Vout / (VCC - Vout)
  float rNTC = 0.0;
  if (voltage > 0 && voltage < VCC) {
    rNTC = R_SERIES * voltage / (VCC - voltage);
  } else {
    // If voltage is out of range, use default value
    rNTC = R0;
  }
  
  // Calculate temperature using Beta equation (Kelvin)
  // T = 1 / (1/T0 + (1/BETA) * ln(R/R0))
  float temperatureK = 0.0;
  if (rNTC > 0 && rNTC < 1000000.0) {  // Limit resistance range to avoid abnormal values
    float lnR = log(rNTC / R0);
    temperatureK = 1.0 / (1.0 / T0 + (1.0 / BETA) * lnR);
  } else {
    temperatureK = T0;  // If calculation is abnormal, use reference temperature
  }
  
  // Convert to Celsius and apply offset
  float temperature = temperatureK - 273.15 + TEMP_OFFSET;
  
  // Limit temperature range (avoid abnormal values)
  if (temperature < -50.0) temperature = -50.0;
  if (temperature > 150.0) temperature = 150.0;
  
  // Print temperature value
  Serial.print("Temperature: ");
  Serial.print(temperature, 2);
  Serial.println(" °C");
  
  delay(1000);  // Wait 1 second before reading again
}
