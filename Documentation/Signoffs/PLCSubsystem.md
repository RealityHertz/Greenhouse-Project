# *Detail Design: PLC Subsystem*

## **Function of the Subsystem:**
The function of this subsystem is to recieve data from the various sensors and relay that information to the hmi display. This system will also send commands to the various subsystems to change behaviors according to the plc code.

## **Constraints:**

|Segment|Number|Contraint Description|
|--------|-|-------------------------------------------------|
|PLC|1|The PLC scan time shall be able to scan fast enough to accommodate the desired sampling rate for all subsystem sensors. These sensors will be sending data every 5 minutes.|
|PLC|2|Communication Bandwidth shall sufficient enough to handle all data from sensors simultaneously|
|PLC|3|Maximum Data Latency shall be low enough to allow for data to process on a 5 minute cycle|
|PLC|4|Power|
|PLC|5|PLC shall be able to operate in 30% to 95% relative non–condensing humidity|
|PLC|6|PLC shall handle errors and alert when sensors are not in the correct set range|
|PLC|7|PLC shall be able to input data from at least 4 Arduino Nano 33 IoT and 1 HMI|

## **Buildable Schematic:**

![]()

*Figure 1.*

![PLC Subsystem](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PLC%202D%20Model.png)

*Figure 2. PLC 2D Model*

![]()

*Figure 3.*

## **Analysis:**

**PLC**
  1. The Automation Direct C2-03CPU has a scan time of < 1 ms and a contact execution of < 0.2 µs. This is more than sufficient to keep track of the sensor's data being sent every 5 minutes.
  2. 2
  3. 3
  4. 4
  5. 5
  6. 6
  7. Through the CLICK CPU v3.0 Application and an additional RP-SMA antenna plug that directly connects to the PLC, we will be able to setup and see up to 8 additional BLE or IOT devices. This PLC comes standard allowing one HMI, but can be manipulated in the CLICK CPU to allow for more. Futhermore, devices can use microB-USB or RS-232 for a direct communication. Finally, this PLC allows for communication over WiFi or direct connect Ethernet (RJ45). All of these methods allow for us to communicate to the multiple Arduino Nano 33 IoT, but the priority is to use the BLE or IoT features for communication. [1]
  - **Power Supply for PLC**
    - 

    - 
**HMI**

  4. 
  
  5. 
- **Communication for PLC and Ardiuno IOT's**

  - 
  - 
  - 
  - 

## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|CLICK PLUS|PLC|Automation Direct|C2-03CPU|1|$205.00|$205.00|





**References**

[1] AutomationDirect, "Click PLCs - CLICK PLUS Features," AutomationDirect, https://www.automationdirect.com/clickplcs/clickplus/features.
