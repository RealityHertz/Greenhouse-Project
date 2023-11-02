 Detail Design: Water Sensor
Function of the Subsystem:
The function of this subsystem is to relay the water levels to the Arduino via their respective sensors. The subsystem will use a sensor to determine whether the water reservoir is empty or not. If the reservoir is low on water, it will send data to the PLC for it to be refilled. The system is also able to be turned off for the user to manually water the plants.
Constraints:
•	Arduino Nano 33 BLE 
o	The communication between the sensors and PLC must be wireless. This will save time and money on wiring, while also allowing the system to be scalable.
o	The transfer of data between the sensors and the Arduino must be nearly instantaneous for accurate and reliable monitoring of the CO2 and NO2 levels in the atmosphere.
o	BLE (Bluetooth Low Energy) is lower in cost than the classic Bluetooth as BLE is currently rising in use and has market competition. BLE decreases the distance a signal can be transmitted, but the signals transmitted through the greenhouse will not be far. The use of BLE allows for a cost-efficient alternative compared to classic Bluetooth.
•	Silicon Conformal Coating
o	Service temperature range of -40-200℃ 
o	Resistivity of 3.5 x 1013 Ω·cm
o	Drying time of 15 minutes for 2 coats
Buildable Schematic:
 
Figure 1. Wiring Schematic for Power to Sensor 
Figure 2. Arduino Nano 33 BLE Board Topology
Analysis:
•	Power Supply for Arduino Nano 33 BLE
o	The power used will need to supply 5 volts to the Pin 15 on the Nano 33 BLE.
o	The Pin 14 on the Nano 33 BLE will need to be connected to the ground from the power supply.
o	The switch needs to be able to the turn off the power to the Arduino
•	Power Supply for M8
o	The M8 will connect to the Nano 33 BLE’s Pin 12 supplying 5 volts to the sensor, and the Nano 33 BLE’s pin 3 for ground to complete the circuit.
o	The working voltage will be 4.5 ~ 5.5 V DC
o	Average Current < 20 mA with a 5 V power supply
o	Peak Current 150 mA with a 5 V power supply
•	Communication for M8
o	PWM Output consists of the following:
	Cycle of 1004 ms 5%
	Cycle starts high level output of 2 ms, theoretically.
	Middle Cycle of 1000 ms 5%
	Cycle end high level output of 2ms, theoretically.
 
•	Water Levels
o	The float sensor will float on the water and send a signal to the Arduino 33 BLE saying whether the water level is low or not.
Bill of Materials:
Brand/
Manufacturer	Part Name	Supplier	Part/Model Number	Quantity	Units	Unit Cost	Cost
Gikfun	Water Level Sensor	Amazon	M8	1	1	$9.88	$9.88
Arduino	Blue-tooth board	Arduino	Nano 33 BLE	1	1	$26.30	$26.30
MG Chemicals	Silicon Conformal Coating	DigiKey	422C-55MLCA	1	1	$23.94	$23.94
LAMPVPATH	4 AA Battery Holder	Amazon	B07L9M6VZK	1	2	$7.49	$7.49
Duracell	AA Batteries	Amazon	DURMN1500B10Z	1	10	$8.79	$8.79







