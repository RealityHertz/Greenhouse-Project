# Experimentation Assignment

## Subsystems and Constraints

1. Lighting Subsystem
   - Constraint 1: The lights must be able to shine for a minimum of 2 hours per day. The lights are set to be on for a minimum of 2 hours per day.
   - Constraint 2: The distance of the lights from the plants will have to be fully adjustable as the plants grow upward toward the lights. The lights are powerful enough to keep from having to move them as the plants grow, but they are connected to a 10-foot cord that can move up and down.
   - Constraint 3: The HMI must give the user the ability to adjust how long the lights are on per day. This must be between 2 and 6 hours, based on the current weather conditions or any other factors that may reduce UV light on the plants. The HMI is not functioning to allow for change to the lights on and off cycle but can be changed manually through the micro-USB port. 

2. CO2 and NO2 Subsystem
   - CO2 Constraint 1: MH-Z19B needs between 4.5-5.5V and at least 20mA to operate eﬃciently.
      - The soldered 5 volt pin (Pin 12) on the Arduino Nano 33 IoT supplies it with around 5.0V with a little variance to 4.9 to 5.1V.
   - CO2 Constraint 2: The sensor must turn on every 5 minutes to measure the amount of carbon dioxide present in the greenhouse.
      - - Sensor code contains the WatchDog.sleep sleep mode function from the Adafruit SleepyDog library to cycle the system into sleep mode, reducing the operating current from 18mA to 6mA, every 5 minutes. The function itself only sleeps for 16 seconds, but when put into a for-loop with 19 iterations we meet our constraint of 5 minutes.
   - CO2 Constraint 3: Must alert the communications applications when above or below 400-2000 ppm to ensure proper plant growth.
      - The sensor correctly reads in the sensor data, but on a slightly higher level. For example, 400 ppm is represented as 40000 with the library we are using. That data is then checked to be above or below 40000 to 200000. If it is not within this range, a boolean true is sent over BLE. If it is within this range then the boolean remains false.
    
   - NO2 Constraint 1: MIKROE-3700 needs between 3.3-5V to operate efficiently.
      - The MIKROE-3700's Vcc pin is connected directly to the 3.3V pin (Pin 2) on the Arduino Nano 33 IoT which supplies the 3.3V required.
   - NO2 Constraint 2: Must alert when above Nitrogen Dioxide level exceeds 9 ppb.
      - The MIKROE-3700 does alert when levels are not in the correct range. However, the NO2 sensor readings are not correct. The sensor sends data over via SPI, but then received by the Arduino, it only outputs 0 or 65535.00. It is believed that this is the sensor's way of sending the minimum or maximum value allowed. Obviously, this is not the data expected. The current MIKROE-3700 documentation is not very in depth and does not give information on how to receive the 12-bit ADC that is supposed to be sent and received. There also are no libraries for the MIKROE-3700 for the Arduino Nano 33 IoT, so we can't see how the sensor is being read this way either. 

3. Temperature and Humidity Subsystem
   - Constraint 1: The sensor shall have 2.5-5.5 V to operate correctly. The sensor is given the constant voltage of 3.3V from Pin 2 on the Arduino Nano 33 IoT
   - Constraint 2: Sensor uses 3.2mW when on, and 0 W when in sleep mode. We tested the voltage multiple times and received a voltage range of 3.2-3.4 volts every time. We also tested for current and received measurements between 1.0-1.1 mA. If we calculate power by multipling voltage by current, we see that we have a range of 3.2-3.74 mW. When it sleep mode the power uses 0 watts.
   - Constraint 3: Temperature range of 0-50°C (32-122°F) and humidity range of 20-90%. While testing in a room temperature environment, we see a range of +- 2 degrees Celsius maximum and a range of +- 1%rH. For our testing, we were in a room that was 20 degrees Celsius and a humidity of 41 %rH. Here is the data set we got for 18 trials. 

       - Temperature values: 19.40, 19.26, 19.56, 19.55, 20.49, 19.44, 19.80, 20.79, 21.01, 20.27, 19.11, 19.99, 19.45, 20.89, 19.75, 19.12, 19.11, 19.05

         We find that the sum over the count is 356.04/18 which equals 19.78. Next, we will show the data gathered by the humidity sensor.

        - Humidity values: 40.59, 41.58, 40.84, 41.56, 40.05, 41.94, 40.30, 40.83, 40.47, 40.47, 40.49, 41.88, 41.33, 40.42, 41.67, 41.06, 40.00, 41.18
       
          We find that the sum over the count is 736.66/18 which equals roughly 40.93.
     
   - Constraint 4: Sampling period of greater than or equal to 2 seconds, so it is set to be 10 seconds to allow for extra time. We added the Arduino libraries "delay()" function, which allows for input of an integer which is understood to be in milliseconds,  with a value of 10000 to allow for 10 extra seconds to achieve this.

4. Water Level Subsystem
   - Constraint 1:  The transfer of data between the sensors and the Arduino must be below 3 seconds for accurate and reliable monitoring of water level. After Testing we got the following data:
        - Total time elapsed:
             - Start time: 17:06:02.247
             - End time: 17:08:21.110
             - Convert both times to milliseconds:
             - Start time in milliseconds: 61562247 ms
             - End time in milliseconds: 61761110 ms
             - Total time elapsed: 61761110 ms - 61562247 ms = 198863 ms
             - Number of intervals between readings: 114 readings, so 114 - 1 = 113 intervals.
             - Average time per reading:
             - Average time = Total time elapsed / Number of intervals
             - Average time = 198863 ms / 113 = 1760.56 ms

   - Constraint 2: Must be able to accurately sense when water level drops below 1/3 of the max to signal more water is needed to be added to the reservoir.
        - The sensor reads the data correctly, but struggles to change the water level distance from the ground at a consistent rate. For example, if the ground is 100 cm away and we drastically reduce the water level, the sensor does not read the change in water level accurately.

   - Constraint 3: Must be durable enough to continue function while wet for an indefinite amount of time.
        - Sensor is waterproof and can withstand the harsh conditions of the environment it is placed in, which in this case includes constantly being close to the water.

   - Constraint 4: Must be cheap and easily replaceable in the chance the user requires a new sensor.
        - Sensor is $12.99, while maintaining a high quality and accuracy in a cost effective price range.

5. Nutrient Subsystem
   - Constraint 1: Must have an operational voltage between 4.5V and 30V.
        - Sensor and translator operate with a voltage of 6V supplied from the battery pack which is well within the range of required voltages.
   - Constraint 2: Sensors must turn on every 5 minutes to provide soil NPK, pH and moisture information.
        - Sensor code contains the WatchDog.sleep sleep mode function from the Adafruit SleepyDog library to cycle the system into sleep mode, reducing the operating current from 18mA to 6mA, every 5 minutes. The function itself only sleeps for 16 seconds, but when put into a for-loop with 19 iterations we meet our constraint of 5 minutes.
   - Constraint 3: Must accurately measure soil moisture in a range of 0-100% to allow for optimum plant growth with ±3% to ±5% accuracy.
   - Constraint 4: Must accurately measure nitrogen levels in the soil within a range of 50-300 mg/kg to allow for optimum plant growth with no more than ±10% accuracy.
   - Constraint 5: Must accurately measure phosphorus levels in the soil within a range of 5-90 mg/kg with no more than ±10% accuracy.
   - Constraint 6: Must accurately measure potassium levels in the soil within a range of 50-240 mg/kg with no more than ±10% accuracy.
   - Constraint 7: Must accurately measure soil pH levels within a range of 5-8.5pH with an accuracy of ±0.01 pH to ±0.5 pH.
        - For constraints 3 through 7, there was no datasheet and very little documentation on the sensor itself so the register addresses for the sensor values were not able to be found. Despite this limitation we used the register values of a similar sensor and were still unable to get the sensor to communicate with the arduino. The sensor will however send a constant value of 255 for all measures.

6. HMI Subsystem
   - Constraint 1: The HMI shall be capable of receiving and displaying sensor data from various sources within the greenhouse, including nutrient levels, humidity, temperature, CO2, and NO2 levels.
   - Constraint 2: Communication between the HMI and PLC must be robust and reliable to ensure real-time monitoring of sensor data.
   - Constraint 3: The HMI shall have sufficient screen resolution and clarity to display sensor readings in an easily understandable format, including any alerts or notifications.
   - Constraint 4: Power supply for the HMI shall provide stable wattage at 1.05W to ensure uninterrupted operation of the display system.

7. PLC Subsystem
   - Constraint 1: The PLC scan time shall be able to scan fast enough to accommodate the desired sampling rate for all subsystem sensors. These sensors will be sending data every 5 minutes.
   - Constraint 2: The PLC shall have compatible communication ports to allow for available programming.
   - Constraint 3: The PLC shall be able to operate in 30% to 95% relative non–condensing humidity to ensure its suitability for deployment in greenhouse environmental conditions without risking damage due to moisture.
   - Constraint 4: The PLC shall be able to input data from at least 3 Arduino Nano 33 IoT.
   - Constraint 5: The PLC shall be able to log data every hour for at least 1 month.
   - Constraint 6: The power supply shall incorporate overcurrent protection and overvoltage protection to provide protection mechanisms for safeguarding connected equipment and ensuring the reliability of the power distribution system.
