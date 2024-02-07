# *Detail Design: Temperature and Humidity Control*
## **Team 2 - Greenhouse Project**
### *Team Members: Jared Hooker and Noah Jones*

## **Function of the Subsystem:**
The function of this subsystem is to measure the temperature and the humidity levels in the greenhouse. The DHT11 sensor will measure both values, then relay the information to the Arduino Nano 33 BLE device. 

## **Constraints:**

- **Arduino Nano 33 IoT**
  1. The communication between the Arduino and the PLC must be wireless. This will allow for the system to be scalable, meaning that the greenhouse can be expanded to add more zones if needed.
  2. The data transfer from the sensors to the Arduino must be below 5 seconds to allow an adequate amount of time before the Arduino returns to its sleep mode.
  3. The Arduino shall be able to wirelessly transmit the data to the PLC in a cost effective way.

- **DHT11 Temperature & Humidity Sensor**
  1. The sensor shall have 3.5-5.5 V to operate correctly.
  2. Sensor has 0.3 mA when on, and 150 μA when in sleep mode.
  3. Temperature range of 0-50°C (32-122°F) and humidity range of 20-90%.
  4. Sampling period of greater than or equal to 2 seconds, so it is set to be 10 seconds to allow for extra time.
  5. Sensor must alert the communications application when temperature is below 60°F and when the relative humdity is below 50%.

## **Buildable Schematic:**
![Buildable Schematic Temperature & Humidity Monitoring](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADTemperatureHumiditySubsystem.jpg)
## **Analysis:**
- **Arduino Nano 33 IoT**
  1. The power supply will be four AA batteries. Each battery contains 1.1-1.5 volts, which will give the Arduino the required 5 volts.
  2. The Arduino will turn on for 10 seconds once every 5 minutes. This can be done using functions from the Arduino-Libraries Github [1]. By instructing the Arduino to go into sleep mode using the LowPower.sleep() function, the desired time range can be achieved.
  3. Using Bluetooth Low Energy (BLE) allows for a cost efficient manner to transmit data throughout the greenhouse. A disadvantage of BLE is the decreased distance that information can be transmitted. Most BLE devices can trasmit/recieve data at a max rate of 50 meters [2]. However, the distance between the Arduino and the PLC will only be 15 feet, or 4.57 meters.
 
- **DHT11 Temperature & Humidity Sensor**
    1. The DHT11 temperature and humidity sensor is powered by the Arduino. An output voltage of 5 V is sent to the DHT11 via the Arduino.. The power consumed
    2. The DHT11 does not consume much power at all from the batteries. The amount of power from the DHT11 and Arduino are as follows:
       - AA batteries supply 1.5V and 3500mAh each. P = (1.5V*3500mAh) * 4 batteries = 21Wh
       - Arduino uses 5V and 28mA while in the "on" mode. P = (5V * 28mA) * (120s/3600s) = 4.67mWh.
       - Sensor uses 0.3mA while on, and 150μA while off. P = (5V * 0.3mA) * (120s/3600s) + (5V * 150μA) * (3480s/3600s) = 0.775mWh
       - Total power consumed: P = 4.67mWh + 0.775mWh = 5.445mWh. 21Wh/mWh = 3,857 hours or 5.4 months.
    3. The temperature and humidity ranges are ideal for greenhouses. When speaking to the greenhouse coordinator, the temperature ranges from 60-85°, and humidity ranges from 50-80% in this specific greenhouse. Anything greater than or less than these ranges shall send an alert to the communications app to notify the manager that something abnormal is occuring in the greenhouse. 
    4. The DHT11 must be on for at least 2 seconds in order to detect the temperature and humidity, as well as send the data to the Arduino. By leaving the Arduino on for 10 seconds, the sensor will have a sufficient amount of time to measure and transmit the data.

 - **Communication for DHT11**
     1. The DHT11's pin 2 will be used as the Single Bus Format Data Out which will then be connected to the Arduino via pin 26. Pin 26 is used as a Digital Input, which will allow for the Arduino to read in the data from the sensor. The data format will be 8bit integral RH data + 8bit decimal RH data + 8bit integral T data + 8bit decimal T data + 8bit check sum. If the data transmission is right, the check-sum should be the last 8bit of "8bit integral RH data + 8bit decimal RH data + 8bit integral T data + 8bit decimal T data. For a total of 40 bits transmitted.
    
## **Bill of Materials:**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Songhe|Temperature and Humidity Sensor|Amazon|DHT11|5 (Pack)|$1.58|$7.88|
|Arduino|Bluetooth Board|Arduino|Nano 33 IOT|1|$26.30|$26.30|
|LAMPVPATH|4 AA Battery Holder|Amazon|B07L9M6VZK|1|$7.49|$7.49|
|Duracell|AA Batteries|Amazon|DURMN1500B10Z|1|$8.79|$8.79|


## **References:**
[1]  “Arduino Low Power - Arduino Reference,” www.arduino.cc, Nov. 08, 2023). ‌https://www.arduino.cc/reference/en/libraries/arduino-low-power/

[2] “Advantages of BLE (Bluetooth Low Energy) | disadvantages of BLE (Bluetooth Low Energy),” www.rfwireless-world.com. https://www.rfwireless-world.com/Terminology/Advantages-and-Disadvantages-of-BLE-Bluetooth-Low-Energy.html
‌
