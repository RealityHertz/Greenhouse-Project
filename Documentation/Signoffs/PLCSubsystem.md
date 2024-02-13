# *Detail Design: PLC Subsystem*

## **Function of the Subsystem:**
The function of this subsystem is to receive data from the various sensors and relay that information to the HMI display. This system will also send commands to the various subsystems to change behaviors according to the PLC code.

## **Constraints:**

|Segment|Number|Constraint Description|
|--------|-|-------------------------------------------------|
|PLC|1|The PLC scan time shall be able to scan fast enough to accommodate the desired sampling rate for all subsystem sensors. These sensors will be sending data every 5 minutes|
|PLC|2|Communication Bandwidth shall be sufficient enough to handle all data from sensors simultaneously|
|PLC|3|Maximum Data Latency shall be low enough to allow for data to process on a 5-minute cycle|
|PLC|4|The PLC shall be required to have an input voltage of 20.0 and 28.0 VDC and a current of at least 140mA to operate within a specific voltage range to ensure compatibility with the power supply system of the overall automation setup. By specifying the input voltage range of 20.0 to 28.0 VDC, we ensure that the PLC can be powered by the C0-01AC without risk of damage or malfunction [4]|
|PLC|5|PLC shall be able to operate in 30% to 95% relative non–condensing humidity to ensure its suitability for deployment in greenhouse environmental conditions without risking damage due to moisture [2]|
|PLC|6|PLC shall be able to input data from at least 4 Arduino Nano 33 IoT and output to 1 HMI|

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
  2. The Automation Direct C2-03CPU functions on a Bluetooth frequency of 2.4 GHz. This is more than sufficient to handle the connection between the PLC and the various subsystem sensors.
  3. The Automation Direct C2-03CPU has a Bluetooth linespeed of 260 kbps. This is fast enough to process the data transfer between plc and sensors within the 5-minute cycles.
  4. The CLICK C0-01AC will supply the PLC with a constant output range of 23-35V with an 85-264 input voltage. It will also output a current of 1.3A with an over-current protection system with automatic recovery at 1.6A. This power supply also has an overvoltage protection system of 27.6V clamped by a zener diode. This power supply holds the same temperature and humidity requirements as the PLC as well. [4]
  5. The ambient humidity specifications in the PLC Datasheet show that when operating and non-condensing the relative humidity the PLC can handle is 30% to 95%. [2] This falls within our range for the greenhouse, with 80% being optimal for plant growth. [3] The PLC will also be able to monitor the humidity through communication with the Temperature/Humidity Subsystem's sensor to alert if the humidity is falling or rising to an unsafe range.
  6. We will utilize the Greenhouse Wifi along with Arduino onboard IoT (Internet of Things) technology and MQTT (Message Queuing Telemetry Transport) protocol to have communication between all Arduino devices and the PLC. Through the CLICK CPU v3.0 Application and an additional RP-SMA antenna plug directly connected to the PLC, we can establish connections with up to 8 additional IoT devices. The PLC, by default, supports one HMI (Human-Machine Interface), but it can be configured in the CLICK CPU to have more interfaces as needed. The primary focus will be on using IoT capabilities for communication with multiple Arduino Nano 33 IoT devices. This approach ensures reliable communication between the PLC and the Arduino devices within the greenhouse environment. [1]
     
**Power Supply for PLC**
- The CLICK C0-01 AC will be the source used to power the PLC system, which has the ability to supply between 100-240 VAC. This supply gives a 1.3A and 25V DC source which is more than capable of supporting the PLC even with all I/O ports being used. The maximum start-up time is 1000ms, which allows plenty of time for the PLC to receive and send data to and from the other sub-systems. The humidity range allows up to 95% humidity which is ideal for the supply being used inside of a greenhouse. 
 
**HMI to PLC**
- We will use the PLC and code in "Ladder" to allow the ports to be read and sent to the HMI. The HMI then has the C-more Micro Programming Software that can be used to design and simulate the code to be used on the HMI to correctly display and customize the buttons. Here is the template to allow for communication between PLC and HMI.

![PLC Port Code](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/LadderLogicForPLC.PNG)

## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|CLICK PLUS|PLC|Automation Direct|C2-03CPU|1|$205.00|$205.00|
|STRIDE|WiFi/Bluetooth Antenna|Automation Direct|SE-ANT250|1|$50.50|$50.50
|CLICK|Power Supply|Automation Direct|C0-01AC|1|$63.00|$63.00|



**References**

[1] AutomationDirect, "Click PLCs - CLICK PLUS Features," AutomationDirect, https://www.automationdirect.com/clickplcs/clickplus/features.

[2] AutomationDirect, "C20xCPU - CPU Module for C2000 Series PLCs," AutomationDirect, https://cdn.automationdirect.com/static/specs/c20xcpu.pdf.

[3] Atlas Scientific, "Ideal Greenhouse Temperature and Humidity," Atlas Scientific Blog, https://atlas-scientific.com/blog/ideal-greenhouse-temperature-and-humidity/#:~:text=Ideal%20Humidity%20For%20Greenhouses&text=The%20optimal%20relative%20humidity%20level,growth%20and%20lower%20quality%20yield.
