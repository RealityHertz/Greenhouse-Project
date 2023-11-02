# Detail Design: Water and Nutrient Controller
## Function of the Subsystem:
The function of this subsystem is to monitor the concentration of nutrients in the soil,
the pH balance of the soil, the hydration level of the soil, the level of water in the water tanks,
fill a local reservoir with water for manual watering and regulate the plant watering cycle. This 
subsystem will use an array of sensors to detect the level of water in the tanks as well as the 
hydration, pH balance, and nutrient concentration of the soil and relay that information to the 
communications application via Bluetooth connection. This system will also use a pump and a 
timer to fill a local reserve tank and regulate the watering cycle of plants.
## Constraints:
**•	Arduino Nano 33 BLE:**

-	The communication between the sensors and PLC must be wireless. This will save time and money on wiring, while also allowing the system to be scalable.
-	The transfer of data between the sensors and the Arduino must be nearly instantaneous for accurate and reliable monitoring of the CO2 and NO2 levels in the atmosphere.
-	BLE (Bluetooth Low Energy) is lower in cost than the classic Bluetooth as BLE is currently rising in use and has market competition. BLE decreases the distance a signal can be transmitted, but the signals transmitted through the greenhouse will not be far. The use of BLE allows for a cost-efficient alternative compared to classic Bluetooth.

**•	Soil NPK Sensor:**

-	This sensor shall be able to accurately measure the concentrations of nitrogen, phosphorous and potassium within the soil.
-	The sensor shall have a low response time to report the concentrations quickly.
-	The sensor shall be able to work around a moist environment.
-	The sensor shall be able to be placed directly into the soil for optimum measurement.

**•	Soil Hygrometer:**

-	The sensor shall be able to accurately measure and relay the current moisture content of the soil to the Arduino BLE.
-	The sensor shall have a low response time for quick and accurate measurements.

**•	Soil pH Sensor:**

-	The sensor shall be able to accurately measure and report the pH balance of the soil.
-	The sensor shall have a low response time for quick measurements.

**•	555 Timer:**

-	The timer shall be able to accurately time the electrical pulses to the Arduino for maximum power efficiency.
-	This timer shall allow for the user to conserve energy and power by ensuring that all sensors and pumps are not active around the clock.
## Buildable Schematic
![Nutrient Schematic](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Nutrient%20Schematic.png)
## Analysis
**•	Power Supply for Nano 33 BLE:**

-	Pin 15 of the Nano 33 BLE will be connected to the voltage output pin of the LM7805 voltage regulator that will be attached to the 555 timer.
-	Pin 14 of the Nano 33 BLE will be connected to ground from the LM7805.
  
**•	Power Supply for Uxcell MAX458:**

-	The Vin pin of the MAX458 will be connected to the 5V output of the Nano 33 BLE.
-	The ground pin of the MAX458 will be connected to the pin 19 ground of the Nano 33 BLE.
  
**•	Power Supply for ANGGREK RS485:**

-	The Vin of the ANGGREK will be connected to the 3.3V output of the Nano 33 BLE through a voltage multiplier to produce an input voltage of 13.2V.
-	The ground pin of the ANGGREK will be connected to the Nano 33 BLE ground Pin 19.
-	The ANGGREK will have an operational input voltage of 12-24V.
-	The ANGGREK has 5 pins that will be inserted into the soil to conduct measurements.
-	Outputs signals in RS485.
  
**•	Communication for ANGGREK RS485:**

-	The ANGGREK will send its RS485 signal to the MAX485 TTL interface via the a and b connection pins which then sends the information to pins 16 and 17 of the Nano 33 BLE.
-	The ANGGREK has a response time of less than 1 second.
  
**•	NPK Concentrations in Soil:**

-	The ANGGREK can measure nutrient concentrations in soil in ranges from 0-1999 mg/kg.
-	The ANGGREK measures nutrient concentrations with ±2%.
  
**•	PH of Soil:**

-	The ANGGREK can measure the pH of soil within a range of 3-9pH.
-	The accuracy is ±0.3pH.
  
**•	Soil Hydration:**

-	The ANGGREK can measure soil hydration in a range of 0-100%.
-	The accuracy is ±3% for 0-53% hydration and ±5% for 53-100%.

## Bill of Materials 
| Brand/Manufacturer | Part Name | Supplier | Part/Model Number | Quantity | Units | Unit Cost | Cost |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| Arduino | Blue-tooth board | Arduino | Nano 33 BLE | 1 | 1 | $26.30 | $26.30 |
| ANGGREK | Soil NPK Sensor | Walmart | ANGGREK RS485 | 1 | 1 | $78.51 | $78.51 |
| Uxcell | RS495 Instrument Interface Module | Amazon | MAX485 TTL | 1 | 1 | $6.99 | $6.99 |
| LAMPVPATH | 4 AA Battery Holder | Amazon | B07L9M6VZK | 1 | 2 | $7.49 | $7.49 |
| Duracell | AA Batteries | Amazon | DURMN1500B10Z | 1 | 10 | $8.79 | $8.79 |
| onsemi | 555 chip | DigiKey | NCV1455BDR2G | 3 | 3 | $0.62 | $1.86 |
| onsemi | Voltage Regulator | DigiKey | MC7805ABTG | 1 | 1 | $0.76 | 0.76 |
| NTE Electronics, Inc. | Diode | DigiKey | 3845-1N4148-ND | 10 | 10 | $0.05 | $0.50 |
