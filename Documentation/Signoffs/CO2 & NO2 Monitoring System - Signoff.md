<a name="br1"></a> 

**Detail Design: CO and NO Sensor**

**2**

**2**

**Funcꢀon of the Subsystem:**

The funcꢀon of this subsystem is to relay the CO and NO levels to the Arduino via their

2

2

respecꢀve sensors. The subsystem will use a series of sensors to transfer the percentage levels

of CO and NO in the air to the Arduino. The sensors will constantly monitor the changes of the

2

2

carbon dioxide and nitrogen dioxide levels in the greenhouse’s atmosphere and will wirelessly

report these numbers and changes to the Arduino via Bluetooth.

**Constraints:**

•

**Carbon Dioxide Sensor – MH-Z19B**

o MH-Z19B needs between 4.5-5.5V and at least 20mA to operate eﬃciently.

o The sensor must turn on every 5 minutes to measure the amount of carbon

dioxide present in the greenhouse.

o Must alert when above or below 400-2000ppm to ensure proper plant growth.

**Arduino Nano 33 BLE**

•

o The communicaꢀon between the sensors and PLC must be wireless. This will save

ꢀme and money on wiring, while also allowing the system to be scalable.

o The transfer of data between the sensors and the Arduino must be nearly

instantaneous for accurate and reliable monitoring of the CO and NO levels in

2

2

the atmosphere.



<a name="br2"></a> 

o BLE (Bluetooth Low Energy) is lower in cost than the classic Bluetooth as BLE is

currently rising in use and has market compeꢀꢀon. BLE decreases the distance a

signal can be transmiꢁed, but the signals transmiꢁed through the greenhouse

will not be far. The use of BLE allows for a cost-eﬃcient alternaꢀve compared to

classic Bluetooth.

•

**Nitrogen Dioxide Sensor – MIKROE-3700**

o MIKROE-3700 needs between 3.3-5V to operate eﬃciently.

o The sensor must turn on every 5 minutes to measure the amount of nitrogen

dioxide present in the greenhouse.

o Must alert when above Nitrogen Dioxide level exceeds 5 ppm.

**Silicon Conformal Coaꢀng**

•

o Service temperature range of -40-200℃

o Resisꢀvity of 3.5 x 1013 Ω·cm

o Drying ꢀme of 15 minutes for 2 coats

**Buildable Schemaꢀc:**



<a name="br3"></a> 

*Figure 1. Wiring Schemaꢀc for Power to Sensors*



<a name="br4"></a> 

*Figure 2. Arduino Nano 33 BLE Board Topology*

**Analysis:**

•

**Power Supply for Arduino Nano 33 BLE**

o The power used will need to supply 5 volts to the Pin 15 on the Nano 33 BLE.

o The Pin 14 on the Nano 33 BLE will need to be connected to the ground from the

power supply.

•

**Power Supply for MH-Z19B**

o The MH-Z19B will use Pin 4 connected to the Nano 33 BLE’s Pin 12 supplying 5

volts to the sensor.

o MH-Z19B’s Pin 3 will be used as its ground and shall be connected to the Nano 33

BLE’s Pin 19, compleꢀng the power circuit, and powering the sensor.

o The working voltage will be 4.5 ~ 5.5 V DC

o Average Current < 20mA with a 5V power supply

o Peak Current 150 mA with a 5V power supply

o Response Time of T<sub>90</sub> < 120 s

o Working Humidity of 0 ~ 95% RH (No condensaꢀon)

**Communicaꢀon for MH-Z19B**

•

o MH-Z19B will use Pin 5 for UART (Rx) TTL Level data input which will be

connected to the Nano 33 BLE’s Pin 17 which is used as an USART Digital Rx

o MH-Z19B will use Pin 6 for UART (Tx) TTL Level data input which will be

connected to the Nano 33 BLE’s Pin 16 which is used as an USART Digital Tx



<a name="br5"></a> 

o The Carbon Dioxide detecꢀon range consists of opꢀons 400~2000ppm,

400~5000ppm, or 400~10,000ppm. It has an accuracy of ±(50ppm+5% reading

value)

o PWM Output consists of the following:

▪

▪

▪

▪

Cycle of 1004ms±5%

Cycle start high level output of 2ms, theoreꢀcally.

Middle Cycle of 1000ms±5%

Cycle end high level output of 2ms, theoreꢀcally.

•

**CO and NO Levels**

**2**

**2**

o The average concentraꢀon of CO<sub>2</sub> found in the atmosphere is around 400 parts

per million (ppm), but greenhouses oꢂen produce greater concentraꢀons. This is

due to a greater plant yield at higher levels. [1]

o According to the CDC, anything over 5ppm is considered dangerous for an

extended period of ꢀme. [2]



<a name="br6"></a> 

•

**Power Supply for MIKROE-3700**

o The MIKROE-3700 will use Pin 10 connected to the Nano 33 BLE’s Pin 2 as a 3.3V

power supply. This will run through a 10k ohm and 20k ohm voltage divider to

ensure the voltage level is brought down.

o MIKROE-3700’s Pin 8 will be connected to the Nano 33 BLE’s Pin 19 as a ground

to complete the power circuit and be able to supply the 3.3V needed.

o The measurement range has a minimum of 0ppm and a maximum of 10ppm.

o The response ꢀme is 200s.

o Operaꢀng Humidity Range is 5 ~ 95% RH (No condensaꢀon).

**Communicaꢀon for MIKROE-3700**

•

o The MIKROE-3700’s Pin 5 will be used as a SPI Data Out connected to the Nano

33 BLE’s Pin 30 which is used as a Digital SPI MISO.

o The MIKROE-3700’s Pin 4 will be used as a SPI Clock connected to the Nano 33

BLE’s Pin 11 which is used as a signal sent to mimic a clock and when to grab the

data.

**Bill of Materials:**

**Brand/**

**Part**

**Supplier Part/Model Quanꢀty Units Unit Cost**

**Number Cost**

**Manufacturer Name**



<a name="br7"></a> 

MikroElektronika

MiZOELEC

NO<sub>2</sub>

Sensor

CO2

DigiKey

Amazon

Arduino

DigiKey

1471-MIKROE-

3700-ND

1

1

1

1

1

1

1

1

$39.00 $39.00

$35.00 $35.00

$26.30 $26.30

$23.94 $23.94

MH-Z19B

Sensor

Blue-tooth

board

Arduino

Nano 33 BLE

MG Chemicals

Silicon

422C-55MLCA

Conformal

Coaꢀng

4 AA

LAMPVPATH

Duracell

Amazon

Amazon

B07L9M6VZK

1

1

2

$7.49 $7.49

$8.79 $8.79

Baꢁery

Holder

AA

DURMN1500B1

0Z

10

Baꢁeries

555 Chip

Voltage

Regulator

Diode

onsemi

onsemi

DigiKey

DigiKey

NCV1455BDR2G

MC7805ABTG

3

1

3

1

$0.62 $1.86

$0.76 $0.76

NTE Electronics,

Inc.

DigiKey

10

10

$0.05 $0.50

3845-1N4148-

ND



<a name="br8"></a> 

**References**

[1] “Nitrification and Maintenance in Media Bed Aquaponics - Oklahoma State

University,” *extension.okstate.edu*, Oct. 15, 2021[.](https://extension.okstate.edu/fact-sheets/nitrification-and-maintenance-in-media-bed-aquaponics.html)[ ](https://extension.okstate.edu/fact-sheets/nitrification-and-maintenance-in-media-bed-aquaponics.html)[https://extension.okstate.edu/fact-](https://extension.okstate.edu/fact-sheets/nitrification-and-maintenance-in-media-bed-aquaponics.html)

[sheets/nitrification-and-maintenance-in-media-bed-aquaponics.html](https://extension.okstate.edu/fact-sheets/nitrification-and-maintenance-in-media-bed-aquaponics.html)

[2] “CDC - Immediately Dangerous to Life or Health Concentrations (IDLH): Nitrogen

dioxide - NIOSH Publications and Products,” *www.cdc.gov*, Nov. 02, 2018.

<https://www.cdc.gov/niosh/idlh/10102440.html>

