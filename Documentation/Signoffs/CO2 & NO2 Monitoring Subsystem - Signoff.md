<a name="br1"></a> 

# *Detail Design: CO2 and NO2 Sensor*

## **Function of the Subsystem:**

  The function of this subsystem is to relay the CO2 and NO2 levels to the Arduino via their respective sensors. The subsystem will use a series of sensors to transfer the percentage levels of CO and NO in the air to the Arduino. The sensors will constantly monitor the changes of the carbon dioxide and nitrogen dioxide levels in the greenhouse’s atmosphere and will wirelessly report these numbers and changes to the Arduino via Bluetooth.

## **Constraints:**

- **Carbon Dioxide Sensor – MH-Z19B**
  - MH-Z19B needs between 4.5-5.5V and at least 20mA to operate eﬃciently.
  - The sensor must turn on every 5 minutes to measure the amount of carbon
    dioxide present in the greenhouse.
  - Must alert the communications applications when above or below 400-2000ppm to ensure proper plant growth.

- **Arduino Nano 33 BLE**
  - The communication between the sensors and PLC must be wireless. This will save time and money on wiring, while also allowing the system to be scalable.
  - The transfer of data between the sensors and the Arduino must be nearly instantaneous for accurate and reliable monitoring of the CO and NO levels in the atmosphere.
  - BLE (Bluetooth Low Energy) is lower in cost than the classic Bluetooth as BLE is currently rising in use and has market competition. BLE decreases the distance a signal can be transmitted, but the signals transmitted through the greenhouse will not be far. The use of BLE allows for a cost-eﬃcient alternative compared to classic Bluetooth.


- **Nitrogen Dioxide Sensor – MIKROE-3700**
  - MIKROE-3700 needs between 3.3-5V to operate efficiently.
  - The sensor must turn on every 5 minutes to measure the amount of nitrogen dioxide present in the greenhouse.
  - Must alert when above Nitrogen Dioxide level exceeds 5 ppm. [2]

- **Silicon Conformal Coating**
  - Service temperature range of -40-200℃
  - Resistivity of 3.5 x 1013 Ω·cm
  - Drying time of 15 minutes for 2 coats

## **Buildable Schematic:**

![Buildable Schematic CO2 and NO2](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Buildable%20Schematic%20Co2.jpg)

*Figure 1. Wiring Schematic for Power to Sensors*

![Arduino Nano 33](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/ArduinoNano33.png)

*Figure 2. Arduino Nano 33 BLE Board Topology*

## **Analysis:**

- **Power Supply for Arduino Nano 33 BLE**
  - The power used will need to supply 5 volts to the Pin 15 on the Nano 33 BLE.
  - The Pin 14 on the Nano 33 BLE will need to be connected to the ground from the power supply.

- **Power Supply for MH-Z19B**
  - The MH-Z19B will use Pin 4 connected to the Nano 33 BLE’s Pin 12 supplying 5 volts to the sensor.
  - MH-Z19B’s Pin 3 will be used as its ground and shall be connected to the Nano 33 BLE’s Pin 19, completing the power circuit, and powering the sensor.
  - The working voltage will be 4.5 ~ 5.5 V DC
  - Average Current < 20mA with a 5V power supply
  - Peak Current 150 mA with a 5V power supply
  - Response Time of T<sub>90</sub> < 120 s
  - Working Humidity of 0 ~ 95% RH (No condensation)

- **Communication for MH-Z19B**
  - MH-Z19B will use Pin 5 for UART (Rx) TTL Level data input which will be connected to the Nano 33 BLE’s Pin 17 which is used as an USART Digital Rx
  - MH-Z19B will use Pin 6 for UART (Tx) TTL Level data input which will be connected to the Nano 33 BLE’s Pin 16 which is used as an USART Digital Tx
  - The Carbon Dioxide detection range consists of options 400-2000ppm, 400-5000ppm, or 400-10,000ppm. It has an accuracy of ±(50ppm+5% reading value)
  - PWM Output consists of the following:
    - Cycle of 1004ms±5%
    - Cycle start high level output of 2ms, theoretically.
    - Middle Cycle of 1000ms±5%
    - Cycle end high level output of 2ms, theoretically.

  ![PWM Graph](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PPM.png)

- **CO2 and NO2 Levels**
  - The average concentration of CO<sub>2</sub> found in the atmosphere is around 400 parts per million (ppm), but greenhouses often produce greater concentrations. This is due to a greater plant yield at higher levels. [1]
  - According to the CDC, anything over 5ppm is considered dangerous for an extended period of time. [2]

- **Power Supply for MIKROE-3700**
  - The MIKROE-3700 will use Pin 10 connected to the Nano 33 BLE’s Pin 2 as a 3.3V power supply. This will run through a 10k ohm and 20k ohm voltage divider to ensure the voltage level is brought down.
  - MIKROE-3700’s Pin 8 will be connected to the Nano 33 BLE’s Pin 19 as a ground to complete the power circuit and be able to supply the 3.3V needed.
  - The measurement range has a minimum of 0ppm and a maximum of 10ppm.
  - The response time is 200s.
  - Operating Humidity Range is 5 ~ 95% RH (No condensation).

- **Communication for MIKROE-3700**
  - The MIKROE-3700’s Pin 5 will be used as a SPI Data Out connected to the Nano 33 BLE’s Pin 30 which is used as a Digital SPI MISO.
  - The MIKROE-3700’s Pin 4 will be used as a SPI Clock connected to the Nano 33 BLE’s Pin 11 which is used as a signal sent to mimic a clock and when to grab the data.

## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|MikroElektronika|NO2 Sensor|DigiKey|1471-MIKROE-3700-ND|1|$39.00|$39.00|
|MiZOELEC|CO2 Sensor|Amazon|MH-Z19B|1|$35.00|$35.00|
|Arduino|Bluetooth Board|Arduino|Nano 33 BLE|1|$26.30|$26.30|
|MG Chemicals|Silicon Conformal Coating|DigiKey|422C-55MLCA|1|$23.94|$23.94|
|LAMPVPATH|4 AA Battery Holder|Amazon|B07L9M6VZK|1|$7.49|$7.49|
|Duracell|AA Batteries|Amazon|DURMN1500B10Z|1|$8.79|$8.79|
|onsemi|Voltage Regulator|DigiKey|MC7805ABTG|1|$0.76|$0.76|
|onsemi|555 Chip|DigiKey|NCV1455BDR2G|3|$0.62|$1.86|
|NTE Electronics, Inc.|Diode|DigiKey|3845-1N4148-ND|10|$.05|$0.50|

**References**

[1] “Nitrification and Maintenance in Media Bed Aquaponics - Oklahoma State
University,” *extension.okstate.edu*, Oct. 15, 2021[.](https://extension.okstate.edu/fact-sheets/nitrification-and-maintenance-in-media-bed-aquaponics.html)[ ](https://extension.okstate.edu/fact-sheets/nitrification-and-maintenance-in-media-bed-aquaponics.html)[https://extension.okstate.edu/fact-](https://extension.okstate.edu/fact-sheets/nitrification-and-maintenance-in-media-bed-aquaponics.html)
[sheets/nitrification-and-maintenance-in-media-bed-aquaponics.html](https://extension.okstate.edu/fact-sheets/nitrification-and-maintenance-in-media-bed-aquaponics.html)

[2] “CDC - Immediately Dangerous to Life or Health Concentrations (IDLH): Nitrogen
dioxide - NIOSH Publications and Products,” *www.cdc.gov*, Nov. 02, 2018.
<https://www.cdc.gov/niosh/idlh/10102440.html>
