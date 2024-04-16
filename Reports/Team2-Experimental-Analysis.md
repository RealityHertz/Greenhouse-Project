# Experimentation Assignment

## Subsystems and Constraints

1. Lighting Subsystem
   - Constraint 1:
   - Constraint 2:
   - Constraint 3:
   - Constraint 4:
   - Constraint 5:

2. CO2 and NO2 Subsystem
   - Constraint 1:
   - Constraint 2:
   - Constraint 3:
   - Constraint 4:
   - Constraint 5:

3. Temperature and Humidity Subsystem
   - Constraint 1:
   - Constraint 2:
   - Constraint 3:
   - Constraint 4:
   - Constraint 5:

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
        - The sensor reads in the data correctly, but struggles to change the water level distance from the ground at a consistent rate. For example, if the ground is 100cm away and we drastically reduce the water level, the sensor does not read the change in water level accurately.

   - Constraint 3: Must be durable enough to continue function while wet for an indefinite amount of time.
        - Sensor is waterproof and can withstand the harsh conditions of the environment it is placed in, which in this case includes constantly being close to the water.

   - Constraint 4: Must be cheap and easily replacable in the chance the user requires a new sensor.
        - Sensor is $12.99, while maintaining a high quality and accuracy in a cost effective price range.

5. NPK Subsystem
   - Constraint 1: Must have an operational voltage between 4.5V and 30V.
        -Sensor and translator operate with a voltage of 6V supplied from the battery pack which is well within the range of required voltages.
   - Constraint 2: Sensor must turn on every 5 minutes to provide soil NPK, pH and moisture information.
   - Constraint 3: Must accurately measure soil moisture in a range of 0-100% to allow for optimum plant growth with ±3% to ±5% accuracy.
   - Constraint 4: Must accurately measure nitrogen levels in the soil within a range of 50-300mg/kg to allow for optimum plant growth with no more than ±10% accuracy.
   - Constraint 5: Must accurately measure phosphorous levels in the soil within a range of 5-90mg/kg with no more than ±10% accuracy.
   - Constraint 6: Must accurately measure potassium levels in the soil within a range of 50-240mg/kg with no more than ±10% accuracy.
   - Constraint 7: Must accurately measure soil pH levels within a range of 5-8.5pH with an accuracy of ±0.01 pH to ±0.5 pH.

6. HMI Subsystem
   - Constraint 1:
   - Constraint 2:
   - Constraint 3:
   - Constraint 4:
   - Constraint 5:

7. PLC Subsystem
   - Constraint 1:
   - Constraint 2:
   - Constraint 3:
   - Constraint 4:
   - Constraint 5:
