# Experimentation Assignment

## Subsystems and Constraints

### 1. Lighting Subsystem
   - Constraint 1: The lights must be able to shine for a minimum of 2 hours per day.
      - The lights are set to be on for a minimum of 2 hours per day.
   - Constraint 2: The distance of the lights from the plants will have to be fully adjustable as the plants grow upward toward the lights.
      - The lights are powerful enough to keep from having to move them as the plants grow, but they are connected to a 10-foot cord that can move up and down.
   - Constraint 3: The HMI must give the user the ability to adjust how long the lights are on per day.
      - This must be between 2 and 6 hours, based on the current weather conditions or any other factors that may reduce UV light on the plants. The HMI is not functioning to allow for change to the lights on and off cycle but can be changed manually through the micro-USB port. 

### 2. CO2 and NO2 Subsystem
   - CO2 Constraint 1: MH-Z19B needs between 4.5-5.5V and at least 20mA to operate eﬃciently.
      - The soldered 5 volt pin (Pin 12) on the Arduino Nano 33 IoT supplies it with around 5.0V with a little variance to 4.9 to 5.1V.
   - CO2 Constraint 2: The sensor must turn on every 5 minutes to measure the amount of carbon dioxide present in the greenhouse.
     - Sensor code contains the WatchDog.sleep sleep mode function from the Adafruit SleepyDog library to cycle the system into sleep mode, reducing the operating current from 18mA to 6mA, every 5 minutes. The function itself only sleeps for 16 seconds, but when put into a for-loop with 19 iterations we meet our constraint of 5 minutes.
   - CO2 Constraint 3: Must alert the communications applications when above or below 400-2000 ppm to ensure proper plant growth.
      - The sensor correctly reads in the sensor data, but on a slightly higher level. For example, 400 ppm is represented as 40000 with the library we are using. That data is then checked to be above or below 40000 to 200000. If it is not within this range, a boolean true is sent over BLE. If it is within this range then the boolean remains false.
      - An experiment was ran with 20 iterations. The experiment was ran inside of a household room at normal temperature. The expected CO2 ppm is between 300-400ppm in a household. The table below shows the data gathered.
    
![C02 Graph](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CO2graph.png)

*Figure 1. Carbon Dioxide Levels for the MH-Z19B Sensor*

| Iterations | Carbon Dioxide (ppm) |
|------------|----------------------|
| 1          | 343.04               |
| 2          | 344.14               |
| 3          | 343.13               |
| 4          | 344.14               |
| 5          | 343.62               |
| 6          | 343.11               |
| 7          | 343.66               |
| 8          | 342.73               |
| 9          | 343.04               |
| 10         | 343.44               |
| 11         | 342.72               |
| 12         | 343.46               |
| 13         | 343.29               |
| 14         | 343.04               |
| 15         | 343.76               |
| 16         | 342.98               |
| 17         | 343.43               |
| 18         | 344.12               |
| 19         | 343.35               |
| 20         | 343.04               | 

   - NO2 Constraint 1: MIKROE-3700 needs between 3.3-5V to operate efficiently.
      - The MIKROE-3700's Vcc pin is connected directly to the 3.3V pin (Pin 2) on the Arduino Nano 33 IoT which supplies the 3.3V required.
   - NO2 Constraint 2: Must alert when above Nitrogen Dioxide level exceeds 9 ppb.
      - The MIKROE-3700 does alert when levels are not in the correct range. However, the NO2 sensor readings are not correct. The sensor sends data over via SPI, but then received by the Arduino, it only outputs 0 or 65535.00. It is believed that this is the sensor's way of sending the minimum or maximum value allowed. Obviously, this is not the data expected. The current MIKROE-3700 documentation is not very in depth and does not give information on how to receive the 12-bit ADC that is supposed to be sent and received. There also are no libraries for the MIKROE-3700 for the Arduino Nano 33 IoT, so we can't see how the sensor is being read this way either. 

### 3. Temperature and Humidity Subsystem
   - Constraint 1: The sensor shall have 2.5-5.5 V to operate correctly. The sensor is given the constant voltage of 3.3V from Pin 2 on the Arduino Nano 33 IoT
   - Constraint 2: Sensor uses 3.2mW when on, and 0 W when in sleep mode. We tested the voltage multiple times and received a voltage range of 3.2-3.4 volts every time. We also tested for current and received measurements between 1.0-1.1 mA. If we calculate power by multipling voltage by current, we see that we have a range of 3.2-3.74 mW. When it sleep mode the power uses 0 watts.
   - Constraint 3: Temperature range of 0-50°C (32-122°F) and humidity range of 20-90%. While testing in a room temperature environment, we see a range of +- 2 degrees Celsius maximum and a range of +- 1%rH. For our testing, we were in a room that was 20 degrees Celsius and a humidity of 41 %rH. Here is the data set we got for 18 trials.

![Temperature Graph](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/TemperatureGraph.png)

*Figure 2. Temperature Graph Values for DHT20 Sensor*

| Iterations | Temperature values (Celsius) |
|------------|------------------------------|
| 1          | 19.40                        |
| 2          | 19.26                        |
| 3          | 19.56                        |
| 4          | 19.55                        |
| 5          | 20.49                        |
| 6          | 19.44                        |
| 7          | 19.80                        |
| 8          | 20.79                        |
| 9          | 21.01                        |
| 10         | 20.27                        |
| 11         | 19.11                        |
| 12         | 19.99                        |
| 13         | 19.45                        |
| 14         | 20.89                        |
| 15         | 19.75                        |
| 16         | 19.12                        |
| 17         | 19.11                        |
| 18         | 19.05                        |


We find that the sum over the count is 356.04/18 which equals 19.78. Next, we will show the data gathered by the humidity sensor.

![Humidity Graph](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/HumidityGraph.png)

*Figure 3. Humidity Graph Values for DHT20 Sensor*

| Iterations | Humidity values (%rH) |
|------------|-----------------------|
| 1          | 40.59                 |
| 2          | 41.58                 |
| 3          | 40.84                 |
| 4          | 41.56                 |
| 5          | 40.05                 |
| 6          | 41.94                 |
| 7          | 40.30                 |
| 8          | 40.83                 |
| 9          | 40.47                 |
| 10         | 40.47                 |
| 11         | 40.49                 |
| 12         | 41.88                 |
| 13         | 41.33                 |
| 14         | 40.42                 |
| 15         | 41.67                 |
| 16         | 41.06                 |
| 17         | 40.00                 |
| 18         | 41.18                 |

   We find that the sum over the count is 736.66/18 which equals roughly 40.93.
     
   - Constraint 4: Sampling period of greater than or equal to 2 seconds, so it is set to be 10 seconds to allow for extra time. We added the Arduino libraries "delay()" function, which allows for input of an integer which is understood to be in milliseconds,  with a value of 10000 to allow for 10 extra seconds to achieve this.

### 4. Water Level Subsystem
   - Constraint 1:  The transfer of data between the sensors and the Arduino must be below 3 seconds for accurate and reliable monitoring of water level. After Testing we got the following data:

![Water Level Graph](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/WaterLevelGraph.png)

*Figure 4. Water Level Graph Values for the Sensor*

| Time Stamp    | Distance (cm) |
|---------------|---------------|
| 17:06:02.247  | 100.35        |
| 17:06:03.464  | 100.32        |
| 17:06:04.681  | 100.33        |
| 17:06:05.902  | 100.56        |
| 17:06:07.110  | 100.27        |
| 17:06:08.320  | 100.39        |
| 17:06:09.539  | 100.40        |
| 17:06:10.789  | 100.20        |
| 17:06:11.971  | 100.32        |
| 17:06:13.192  | 100.23        |
| 17:06:14.411  | 100.32        |
| 17:06:15.654  | 100.44        |
| 17:06:16.862  | 100.27        |
| 17:06:18.075  | 100.56        |
| 17:06:19.288  | 100.37        |
| 17:06:20.493  | 100.50        |
| 17:06:21.889  | 100.50        |
| 17:06:23.102  | 100.13        |
| 17:06:24.320  | 100.42        |
| 17:06:25.534  | 100.56        |
| 17:06:26.753  | 100.54        |
| 17:06:27.972  | 100.25        |
| 17:06:29.190  | 100.67        |
| 17:06:30.398  | 100.49        |
| 17:06:31.618  | 100.35        |
| 17:06:32.820  | 100.95        |
| 17:06:34.061  | 100.37        |
| 17:06:35.282  | 100.39        |
| 17:06:36.494  | 100.16        |
| 17:06:37.713  | 100.44        |
| 17:06:38.932  | 100.91        |
| 17:06:40.143  | 100.35        |
| 17:06:41.364  | 100.76        |
| 17:06:42.577  | 100.50        |
| 17:06:43.794  | 100.49        |
| 17:06:45.010  | 100.27        |
| 17:06:46.217  | 100.39        |
| 17:06:47.430  | 100.56        |
| 17:06:48.649  | 100.37        |
| 17:06:49.868  | 100.50        |
| 17:06:51.088  | 100.50        |
| 17:06:52.307  | 100.13        |
| 17:06:53.524  | 100.42        |
| 17:06:54.744  | 100.56        |
| 17:06:55.926  | 100.54        |
| 17:06:57.168  | 100.25        |
| 17:06:58.378  | 100.67        |
| 17:06:59.597  | 100.49        |
| 17:07:00.811  | 100.35        |
| 17:07:02.029  | 100.95        |
| 17:07:03.242  | 100.37        |
| 17:07:04.459  | 100.39        |
| 17:07:05.669  | 100.16        |
| 17:07:06.888  | 100.44        |
| 17:07:08.100  | 100.91        |
| 17:07:09.315  | 100.35        |
| 17:07:10.551  | 100.95        |
| 17:07:11.750  | 100.37        |
| 17:07:12.964  | 100.39        |
| 17:07:14.203  | 100.16        |
| 17:07:15.420  | 100.44        |
| 17:07:16.646  | 100.91        |
| 17:07:17.827  | 100.35        |
| 17:07:19.043  | 100.88        |
| 17:07:20.281  | 101.29        |
| 17:07:21.477  | 101.13        |
| 17:07:22.707  | 101.17        |
| 17:07:23.906  | 101.10        |
| 17:07:25.151  | 100.71        |
| 17:07:26.363  | 101.05        |
| 17:07:28.001  | 101.13        |
| 17:07:29.269  | 101.17        |
| 17:07:30.514  | 100.84        |
| 17:07:31.751  | 101.20        |
| 17:07:32.961  | 101.01        |
| 17:07:34.194  | 101.25        |
| 17:07:35.433  | 100.98        |
| 17:07:36.686  | 101.17        |
| 17:07:37.984  | 101.22        |
| 17:07:39.222  | 101.17        |
| 17:07:40.471  | 100.84        |
| 17:07:41.753  | 101.05        |
| 17:07:43.048  | 101.10        |
| 17:07:44.246  | 101.12        |
| 17:07:45.496  | 100.89        |
| 17:07:46.785  | 100.96        |
| 17:07:48.002  | 101.03        |
| 17:07:49.239  | 101.07        |
| 17:07:50.484  | 100.66        |
| 17:07:51.708  | 100.66        |
| 17:07:52.920  | 101.20        |
| 17:07:54.129  | 101.17        |
| 17:07:55.354  | 101.01        |
| 17:07:56.604  | 101.18        |
| 17:07:57.809  | 101.12        |
| 17:07:59.044  | 101.00        |
| 17:08:00.240  | 100.84        |
| 17:08:01.467  | 101.17        |
| 17:08:02.673  | 101.08        |
| 17:08:03.912  | 100.86        |
| 17:08:05.130  | 101.07        |
| 17:08:06.325  | 101.12        |
| 17:08:07.532  | 100.91        |
| 17:08:08.781  | 101.07        |
| 17:08:10.009  | 101.20        |
| 17:08:11.347  | 101.13        |
| 17:08:12.562  | 100.83        |
| 17:08:13.827  | 101.00        |
| 17:08:15.034  | 100.57        |
| 17:08:16.258  | 101.29        |
| 17:08:17.458  | 101.25        |
| 17:08:18.678  | 100.79        |
| 17:08:19.895  | 100.84        |
| 17:08:21.110  | 100.98        |

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

   - Average Distance
      - Average distance = Sum of all Distances / Number of readings
      - Average distance =  11365.74 / 113 = 100.58 cm
      - The sensor was set to 100 cm above the ground. Therefore it was off by 0.58 cm

   - Constraint 2: Must be able to accurately sense when water level drops below 1/3 of the max to signal more water is needed to be added to the reservoir.
        - The sensor reads the data correctly, but struggles to change the water level distance from the ground at a consistent rate. For example, if the ground is 100 cm away and we drastically reduce the water level, the sensor does not read the change in water level accurately.

   - Constraint 3: Must be durable enough to continue function while wet for an indefinite amount of time.
        - Sensor is waterproof and can withstand the harsh conditions of the environment it is placed in, which in this case includes constantly being close to the water.

   - Constraint 4: Must be cheap and easily replaceable in the chance the user requires a new sensor.
        - Sensor is $12.99, while maintaining a high quality and accuracy in a cost effective price range.

### 5. Nutrient Subsystem
   - Constraint 1: Must have an operational voltage between 4.5V and 30V.
        - Sensor and translator operate with a voltage of 6V supplied from the battery pack which is well within the range of required voltages.
   - Constraint 2: Sensors must turn on every 5 minutes to provide soil NPK, pH and moisture information.
        - Sensor code contains the WatchDog.sleep sleep mode function from the Adafruit SleepyDog library to cycle the system into sleep mode, reducing the operating current from 18mA to 6mA, every 5 minutes. The function itself only sleeps for 16 seconds, but when put into a for-loop with 19 iterations we meet our constraint of 5 minutes.
    
![NPK Sleep Mode](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/NPK%20Sleep%20Mode.png)

*Figure 5. Sleep Mode Function Code for NPK Sensor*

   - Constraint 3: Must accurately measure soil moisture in a range of 0-100% to allow for optimum plant growth with ±3% to ±5% accuracy.
      -  The data below shows that the sensor will send moisture data for for the first few iterations and then will cease communication with the arduino.
   - Constraint 4: Must accurately measure nitrogen levels in the soil within a range of 50-300 mg/kg to allow for optimum plant growth with no more than ±10% accuracy.
      - The data below shows that the sensor communicates the levels of nitrogen in the soil with the arduino with a small degree of accuracy with only a few readings being outside the normal range of 10-50 mg/kg 
   - Constraint 5: Must accurately measure phosphorus levels in the soil within a range of 5-90 mg/kg with no more than ±10% accuracy.
      - The data below shows that the sensor sends phosphorus data to the arduino but there is very little accuracy in the readings with most readings being outside the normal range of 200-1500 mg/kg. 
   - Constraint 6: Must accurately measure potassium levels in the soil within a range of 50-240 mg/kg with no more than ±10% accuracy.
      - The data below shows that sensor sends data for potassium readings but is not accurate since almost no readings are within the normal range, additionally the sensor stopped communicating data for potassium at iteration 14 indicated by the sudden jump to 255 mg/kg which was most likely caused by the sensor being subjected to direct sunlight.
   - Constraint 7: Must accurately measure soil pH levels within a range of 5-8.5pH with an accuracy of ±0.01 pH to ±0.5 pH.
      - The data below shows that the sensor will not communicate pH data with the arduino which is caused by the lack of documentation on the sensor's register addressing for the values of the readings.

![Moisture Graph](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/MoistureGraph.png)

*Figure 6. Mositure Graph Values for NPK Sensor*

![Nitrogen Graph](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/NitroGraph.png)

*Figure 7. Nitrogen Graph Values for NPK Sensor*

![Phosphorus Graph](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PhopGraph.png)

*Figure 8. Phosphorus Graph Values for NPK Sensor*

![Potassium Graph](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PotaGraph.png)

*Figure 9. Potassium Graph Values for NPK Sensor*

![Soil pH](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/pHGraph.png)

*Figure 10. Soil pH Graph Values for NPK Sensor*

### 6. HMI Subsystem
   - Constraint 1: The HMI shall be capable of receiving and displaying sensor data from various sources within the greenhouse, including nutrient levels, humidity, temperature, CO2, and NO2 levels.
        - HMI is able to connect to the PLC and display any value in the PLC with the associated address.
   - Constraint 2: Communication between the HMI and PLC must be robust and reliable to ensure real-time monitoring of sensor data.
        - HMI is able to display the one second timer in the PLC toggling on and off while running.
   - Constraint 3: The HMI shall have sufficient screen resolution and clarity to display sensor readings in an easily understandable format, including any alerts or notifications.
        - HMI has characters large enough to be able to be read clearly
   - Constraint 4: Power supply for the HMI shall provide stable wattage at 1.05W to ensure uninterrupted operation of the display system.
        - The HMI is safely provided power via the C0-01AC power supply.

### 7. PLC Subsystem
   - Constraint 1: The PLC scan time shall be able to scan fast enough to accommodate the desired sampling rate for all subsystem sensors.
      - These sensors will be sending data every 5 minutes. The PLC is able to scan fast enough to recieve data every 5 minutes.
   - Constraint 2: The PLC shall have compatible communication ports to allow for available programming.
        - The PLC has multiple ports including the Ethernet and micro USB ports for programming. 
   - Constraint 3: The PLC shall be able to operate in 30% to 95% relative non–condensing humidity to ensure its suitability for deployment in greenhouse environmental conditions without risking damage due to moisture.
      - PLC is operating in a weather-proof panel box.
   - Constraint 4: The PLC shall be able to input data from at least 3 Arduino Nano 33 IoT.
      - The subsystem has been designed where 5 other arduino's addressed are searched for by one central Arduino. All cases have been successful when searching and finding all online and transmitting Arduinos. The central Arduino then fills in a "value" buffer with the attributes of each peripheral. The addresses are searched for in a specific order and the buffer has a size of 5, allowing for the new data from the Arduino's to overwrite the previous data from the same Arduino. This is then sent to a TTL-RS232 converter. The converter is hooked up to a RS232 cord that communicates to the PLC. The PLC does receive this data, as the receive light on the PLC lights up whenever we try to transmit. An oscciloscope can also be used by hooking up the probe to the RX/TX pin and reads in spikes up voltages whenever we transmit. However, the PLC Ladder Logic has not been completed and does not receive and store the data. 
   - Constraint 5: The PLC shall be able to log data every hour for at least 1 month.
      - Once the PLC Ladder Logic is completed and stores the data in the Addresses specified, the .csv file can be set to store at specifed amount of time. This is the data-logging feature on the AutomationDirect CLICK Programming Tool. The PLC also has an SD Card that these .csv files can be saved on. The PLC can have up to 99999 .csv files saved before it deletes the oldest and saves it's new data. This is ready to be implemented when the PLC correctly stores data in the "Data View".
   - Constraint 6: The power supply shall incorporate overcurrent protection and overvoltage protection to provide protection mechanisms for safeguarding connected equipment and ensuring the reliability of the power distribution system.
        - The C0-01AC power suuply provides the required protections for overcurrent and overvoltage.
