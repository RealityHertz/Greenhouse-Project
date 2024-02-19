# *Detail Design: Temperature and Humidity Control*
## **Team 2 - Greenhouse Project**
### *Team Members: Jared Hooker and Noah Jones*

## **Function of the Subsystem:**
The function of this subsystem is to measure the temperature and the humidity levels in the greenhouse. The DHT20 sensor will measure both values, then relay the information to the Arduino Nano 33 BLE device. 

## **Constraints:**

- **Arduino Nano 33 IoT**
  1. The communication between the Arduino and the PLC must be wireless. This will allow for the system to be scalable, meaning that the greenhouse can be expanded to add more zones if needed.
  2. The data transfer from the sensors to the Arduino must be below 5 seconds to allow an adequate amount of time before the Arduino returns to its sleep mode.
  3. The Arduino shall be able to wirelessly transmit the data to the PLC in a cost effective way.

- **DHT20 Temperature & Humidity Sensor**
  1. The sensor shall have 2.5-5.5 V to operate correctly.
  2. Sensor has 3.2mW when on, and 0 W when in sleep mode.
  3. Temperature range of 0-50°C (32-122°F) and humidity range of 20-90%.
  4. Sampling period of greater than or equal to 2 seconds, so it is set to be 10 seconds to allow for extra time.

## **Buildable Schematic:**
![Buildable Schematic Temperature & Humidity Monitoring](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADTemperatureHumiditySubsystem.jpg)
## **Analysis:**
- **Arduino Nano 33 IoT**
  1. The power supply will be four AA batteries. Each battery contains 1.1-1.5 volts, which will give the Arduino the required 5 volts.
  2. The Arduino will turn on for 10 seconds once every 5 minutes. This can be done using functions from the Arduino-Libraries Github [1]. By instructing the Arduino to go into sleep mode using the LowPower.sleep() function, the desired time range can be achieved.
  3. Using Bluetooth Low Energy (BLE) allows for a cost efficient manner to transmit data throughout the greenhouse. A disadvantage of BLE is the decreased distance that information can be transmitted. Most BLE devices can trasmit/recieve data at a max rate of 50 meters [2]. However, the distance between the Arduino and the PLC will only be 15 feet, or 4.57 meters.
 
- **DHT20 Temperature & Humidity Sensor**
    1. The DHT20 temperature and humidity sensor is powered by the Arduino. An output voltage of 5 V is sent to the DHT20 via the Arduino.
    2. The DHT20 does not consume much power at all from the batteries. The amount of power from the DHT20 and Arduino are as follows:
       - AA batteries supply 1.5V and 3500mAh each. P = (1.5V*3500mAh) * 4 batteries = 21Wh
       - Arduino uses 5V and 28mA while in the "on" mode. P = (5V * 28mA) * (120s/3600s) = 4.67mWh.
       - Sensor uses 3.2mW while on, and 0W while off. P = (3.2mW) * (120s/3600s) + (0) * (3480s/3600s) = 0.1mWh
       - Total power consumed: P = 4.67mWh + 0.1mWh = 4.68mWh. 21Wh/4.68mWh = 4487.2 hours or 6.23 months.
    3. The temperature and humidity ranges are ideal for greenhouses. When speaking to the greenhouse coordinator, the temperature ranges from 60-85°, and humidity ranges from 50-80% in this specific greenhouse. The goal for this subsystem is to send an alert to the PLC to notify the manager when the temperature or humidity is out of these specific ranges. 
    4. The DHT20 must be on for at least 2 seconds in order to detect the temperature and humidity, as well as send the data to the Arduino. By leaving the Arduino on for 10 seconds, the sensor will have a sufficient amount of time to measure and transmit the data.
    5. Once the readings are sent from the sensor to the Arduino, the temperature automatically goes back to its low power consumption mode, where 0 W are used.

 - **Communication for DHT20**
     1. The DHT20 follows inter-integrated circuit (I2C) protocol to communicate with the Arduino 33 IoT. I2C is supported on all Arduino boards. [3]
    
## **Bill of Materials:**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Adafruit|Temperature and Humidity Sensor|Adafruit|DHT20|2|$4.50|$9.00|
|Arduino|Bluetooth Board|Arduino|Nano 33 IOT|1|$26.30|$26.30|
|LAMPVPATH|4 AA Battery Holder|Amazon|B07L9M6VZK|1|$7.49|$7.49|
|Duracell|AA Batteries|Amazon|DURMN1500B10Z|1|$8.79|$8.79|


## **References:**
[1]  “Arduino Low Power - Arduino Reference,” www.arduino.cc, Nov. 08, 2023). ‌https://www.arduino.cc/reference/en/libraries/arduino-low-power/

[2] “Advantages of BLE (Bluetooth Low Energy) | disadvantages of BLE (Bluetooth Low Energy),” www.rfwireless-world.com. https://www.rfwireless-world.com/Terminology/Advantages-and-Disadvantages-of-BLE-Bluetooth-Low-Energy.html

[3] [1]Arduino.cc, 2024. https://docs.arduino.cc/learn/communication/wire/
