# *Detail Design: PLC Subsystem*

## **Function of the Subsystem:**
The function of this subsystem is to recieve data from the various sensors and relay that information to the hmi display. This system will also send commands to the various subsystems to change behaviors according to the PLC code.

## **Constraints:**

|Segment|Number|Contraint Description|
|--------|-|-------------------------------------------------|
|PLC|1|The PLC scan time shall be able to scan fast enough to accommodate the desired sampling rate for all subsystem sensors. These sensors will be sending data every 5 minutes.|
|PLC|2|Communication Bandwidth shall sufficient enough to handle all data from sensors simultaneously|
|PLC|3|Maximum Data Latency shall be low enough to allow for data to process on a 5 minute cycle|
|PLC|4|The PLC shall be required to have an input voltage of 20.0 and 28.0 VDC and a current of at least 140mA|
|PLC|5|PLC shall be able to operate in 30% to 95% relative non–condensing humidity|
|PLC|6|PLC shall handle errors and alert when sensors are not in the correct set range|
|PLC|7|PLC shall be able to input data from at least 4 Arduino Nano 33 IoT and 1 HMI|

## **Buildable Schematic:**

![PLC Design](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADPLCSubsystemDrawing.jpg)

*Figure 1. PLC Subsystem Design*

![PLC Subsystem](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PLC%202D%20Model.png)

*Figure 2. PLC 2D Model*

![PLC Power Supply](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PLCPowerSupply2DCAD.PNG)

*Figure 3. PLC Power Supply 2D Model*

## **Analysis:**

**PLC**
  1. The Automation Direct C2-03CPU has a scan time of < 1 ms and a contact execution of < 0.2 µs. This is more than sufficient to keep track of the sensor's data being sent every 5 minutes.
  2. The Automation Direct C2-03CPU functions on a bluetooth frequency of 2.4 GHz. This is more than sufficient to handle the connection between the PLC and the various subsystem sensors.
  3. The Automation Direct C2-03CPU has a bluetooth linespeed of 260 kbps. This is fast enough to process the data transfer between plc and sensors within the 5 minute cycles.
  4. The CLICK C0-01AC will supply the PLC with a constant output range of 23-35V with a 85-264 input voltage. It will also output a current of 1.3A with a over current protection system with automatic recovery at 1.6A. This power supply also has a over voltage protection system of 27.6V clamped by a zener diode. This power supply holds the same temperature and humidity requirements as the PLC as well. [4]
  5. The ambient humidity specifications in the PLC Datasheet show that when operating and non-condensing the relative humidity the PLC can handle is 30% to 95%. [2] This falls within our range for the greenhouse, with 80% being optimal for plant growth. [3] The PLC will also be able to monitor the humidity through communication with the Temperature/Humidity Subsystem's sensor to alert if the humidity is falling or rising to an unsafe range.
  6. The PLC is equipped with an internal diagnostic as well as a system error log to keep track of errors produced by the sensors within the system. 
  7. Through the CLICK CPU v3.0 Application and an additional RP-SMA antenna plug that directly connects to the PLC, we will be able to setup and see up to 8 additional BLE or IOT devices. This PLC comes standard allowing one HMI, but can be manipulated in the CLICK CPU to allow for more. Futhermore, devices can use microB-USB or RS-232 for a direct communication. Finally, this PLC allows for communication over WiFi or direct connect Ethernet (RJ45). All of these methods allow for us to communicate to multiple Arduino Nano 33 IoTs, but the priority is to use the BLE or IoT features for communication. [1]
  - **Power Supply for PLC**
    - 

    - 
**HMI to PLC**
- To enable sensor data monitoring on the EA3-S3ML-RN, establish a connection between the EA3-S3ML-RN HMI and the C2-03CPU PLC. Physically connect the device to the PLC input modules via the Automation Direct PLC RJ12 port. Program the C2-03CPU to read sensor data, creating tags with appropriate data types, in our integers. Configure communication settings, ensuring matching IP addresses and protocols between the HMI and PLC. In the HMI project, import or manually configure tags corresponding to the PLC program, designing screens to display sensor data using graphical elements. Download the HMI project to the EA3-S3ML-RN, run the PLC program, and troubleshoot any communication errors. Document the configuration for future reference and conduct periodic maintenance checks. This process ensures efficient monitoring of sensor data through the HMI. The HMI has up to 99 different screens, with each screen being able to reconfigure the 5 push buttons to do different operations. We can use these screens and buttons to have navigation between the sensor data. Finally, we have a alert system and light for when certain thresholds are met and when manual labor is required in the greenhouse to fix potential problems.

![HMI Design](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADHMISubsystemDrawing.jpg)

![HMI 2D Model](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/HMI2DModel.PNG)

- We will use the PLC and code in "Ladder" to allow the ports to be read and sent to the HMI. The HMI then has the C-more Micro Programming Software that can be used to design and simulate the code to be used on the HMI to correctly display and customize the buttons. Here is the template to allow for the communication between PLC and HMI.

![PLC Port Code](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/LadderLogicForPLC.PNG)

## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|CLICK PLUS|PLC|Automation Direct|C2-03CPU|1|$205.00|$205.00|
|STRIDE|WiFi/Bluetooth Antenna|Automation Direct|SE-ANT250|1|$50.50|$50.50
|CLICK|Power Supply|Automation Direct|C0-01AC|1|$63.00|$63.00|
|C-more Micro|HMI|Automation Direct|EA3-S3ML-RN|1|$146.00|$146.00|
|Automation Direct|RJ12 Cable|Automation Direct|DV-1000CBL|1|$23.00|$23.00|



**References**

[1] AutomationDirect, "Click PLCs - CLICK PLUS Features," AutomationDirect, https://www.automationdirect.com/clickplcs/clickplus/features.

[2] AutomationDirect, "C20xCPU - CPU Module for C2000 Series PLCs," AutomationDirect, https://cdn.automationdirect.com/static/specs/c20xcpu.pdf.

[3] Atlas Scientific, "Ideal Greenhouse Temperature and Humidity," Atlas Scientific Blog, https://atlas-scientific.com/blog/ideal-greenhouse-temperature-and-humidity/#:~:text=Ideal%20Humidity%20For%20Greenhouses&text=The%20optimal%20relative%20humidity%20level,growth%20and%20lower%20quality%20yield.

[4] AutomationDirect, "CLICK Series Power Supplies User Manual," AutomationDirect, https://cdn.automationdirect.com/static/specs/clickpower.pdf.
