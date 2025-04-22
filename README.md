# Sensors Codes for Water Parameters

This repository contains Arduino codes for three water parameter sensors (pH, TDS, and Turbidity) designed to work with the Arduino Uno using the Arduino IDE. Each file corresponds to a specific sensor and provides the logic to measure and process sensor data.

## Table of Contents
1. [Features](#features)
2. [Installation](#installation)
3. [Libraries Required](#libraries-required)
4. [Code Overview](#code-overview)
5. [Usage](#usage)
6. [Contributing](#contributing)
7. [License](#license)

---

## Features
- Compatible with Arduino Uno.
- Simple and modular code for pH, TDS, and Turbidity sensors.
- Calibration factors included for accurate sensor measurements.
- Provides easy-to-read sensor values via Serial Monitor.

---

## Installation
Follow these steps to set up and use the repository:

1. **Download the Repository**:
   - Clone the repository to your local machine using Git:
     ```bash
     git clone https://github.com/Coco-Vera/sensors-codes.git
     ```
   - Alternatively, download the repository as a ZIP file and extract it.

2. **Install the Arduino IDE**:
   - Download and install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).

3. **Open the Code**:
   - Navigate to the file corresponding to the sensor you wish to use (`PH.ino`, `TDS.ino`, or `Turbidity.ino`).
   - Open the `.ino` file in the Arduino IDE.

4. **Connect Arduino Uno**:
   - Connect your Arduino Uno to your computer via USB.

5. **Upload the Code**:
   - Select your Arduino board and port from the **Tools** menu.
   - Click on the upload button in the Arduino IDE to upload the code to your Arduino Uno.

---

## Libraries Required
No external libraries are required for the provided code. All functionality relies on standard Arduino functions. Ensure that your Arduino IDE is installed and configured correctly.

---

## Code Overview
### Common Pin Definitions
All three sensor codes share the following pin configuration:
- **pH Sensor**: Connected to `A0`
- **TDS Sensor**: Connected to `A1`
- **Turbidity Sensor**: Connected to `A2`
- **Pump Relay**: Controlled via pin `7`
- **Valve 1 Relay**: Controlled via pin `8`
- **Valve 2 Relay**: Controlled via pin `9`

### Calibration Factors
- **TDS Factor**: `1.256`
- **pH Calibration**: `-1.57 * Voltage + 17.825`
- **Turbidity Calibration**: `-1120.4 * Voltage² + 5742.3 * Voltage - 4352.9`

### Sensor Files
1. **`PH.ino`**:
   - Reads data from the pH sensor.
   - Converts analog voltage to pH value using the equation:
     ```c++
     pHValue = -1.57 * Voltage + 17.825;
     ```

2. **`TDS.ino`**:
   - Reads data from the TDS sensor.
   - Calculates Total Dissolved Solids (TDS) value using the average voltage and a polynomial equation:
     ```c++
     tdsValue = (133.42 * pow(Voltage, 3)
                 - 255.86 * pow(Voltage, 2)
                 + 857.39 * Voltage) * 1.256;
     ```

3. **`Turbidity.ino`**:
   - Reads data from the turbidity sensor.
   - Converts analog voltage to turbidity value (in NTU) using the equation:
     ```c++
     turbidityValue = -1120.4 * sq(Voltage) + 5742.3 * Voltage - 4352.9;
     ```

---

## Usage
1. Open the `.ino` file for the sensor you want to use in the Arduino IDE.
2. Follow the wiring instructions for each sensor:
   - Connect the sensor output pin to the specified analog input pin on the Arduino Uno.
   - Connect other sensor pins (e.g., VCC, GND) as per the sensor's datasheet.
3. Upload the code to your Arduino Uno.
4. Open the **Serial Monitor** in the Arduino IDE to view real-time sensor readings.
