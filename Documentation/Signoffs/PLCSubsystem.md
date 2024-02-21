# *Detail Design: PLC Subsystem*

## **Function of the Subsystem:**
The function of this subsystem is to receive data from the various sensors and relay that information to the HMI display. This system will also send commands to the various subsystems to change behaviors according to the PLC code.

## **Constraints:**

|Segment|Number|Constraint Description|
|--------|-|-------------------------------------------------|
|PLC|1|The PLC scan time shall be able to scan fast enough to accommodate the desired sampling rate for all subsystem sensors. These sensors will be sending data every 5 minutes|
|PLC|2|The PLC shall have a compatible communication ports to allow for avaliable programming|
|PLC|3|The PLC shall be able to operate in 30% to 95% relative non–condensing humidity to ensure its suitability for deployment in greenhouse environmental conditions without risking damage due to moisture [2]|
|PLC|4|The PLC shall be able to input data from at least 4 Arduino Nano 33 IoT and output to 1 HMI|
|PLC|5|The PLC shall be able to log data every hour for at least 1 month|
|Power Supply|6|The power supply  shall incorporate overcurrent protection and overvoltage protection to provide protection mechanisms for safeguarding connected equipment and ensuring the reliability of the power distribution system|

## **Buildable Schematic:**

![PLC Design](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADPLCSubsystemSchematic.jpg)

*Figure 1. PLC Subsystem Design*

![PLC Subsystem](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PLC%202D%20Model.png)

*Figure 2. PLC 2D Model*

![PLC Power Supply](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PLCPowerSupply2DCAD.PNG)

*Figure 3. PLC Power Supply 2D Model*

## **Analysis:**

**PLC**
  1. The Automation Direct C2-03CPU has a scan time of < 1 ms and a contact execution of < 0.2 µs. This is more than sufficient to keep track of the sensor's data being sent every 5 minutes.
  2. The Automation Direct C2-03CPU is able to communicate through USB to USB to allow for programs to be installed. [2]
  3. The ambient humidity specifications in the PLC Datasheet show that when operating and non-condensing the relative humidity the PLC can handle is 30% to 95%. [2] This falls within our range for the greenhouse, with 80% being optimal for plant growth. [3] The PLC will also be able to monitor the humidity through communication with the Temperature/Humidity Subsystem's sensor to alert if the humidity is falling or rising to an unsafe range.
  4. We will utilize the Greenhouse Wifi (Tennessee Technological University EagleNet Wifi) along with Arduino onboard IoT (Internet of Things) protocol to have communication between all Arduino devices and the PLC. Through the CLICK CPU v3.0 Application and an additional RP-SMA antenna plug directly connected to the PLC, we can establish connections with up to 8 additional IoT devices. [1] The PLC, by default, supports one HMI (Human-Machine Interface), but it can be configured in the CLICK CPU to have more interfaces as needed. The primary focus will be on using IoT capabilities for communication with multiple Arduino Nano 33 IoT devices. This approach ensures reliable communication between the PLC and the Arduino devices within the greenhouse environment. [1]
  5. The utilization of CLICK programming features with the PLC offers a solution for data logging requirements. By leveraging trigger bits in the ladder logic, CSV files containing data can be systematically generated and stored onto a micro SD card connected to the PLC. With a maximum file limit of 999 files and a data save interval set at every hour, calculations reveal that this setup enables the logging of data for an approximate duration of 41.625 days before reaching file capacity. This approach underscores the efficiency and reliability of the PLC subsystem, ensuring seamless data acquisition and storage over extended periods exceeding our 1 month minimum timeline. [4]
  6. In the system design the C0-01AC model power supply integrates essential protection features to ensure the safety of connected equipment. The power supply includes overcurrent protection with automatic recovery, activated at a threshold of 0.65 A, safeguarding against excessive current draw. Additionally, the system has overvoltage protection, by a Zener diode, which clamps voltage spikes at 27.6 V. These protective measures are fundamental in decreasing risks from electrical faults and keeping an uninterrupted operation from the power distribution system.
     
**Power Supply for PLC**
- The CLICK C0-01 AC will be the source used to power the PLC system, which has the ability to supply between 100-240 VAC. This supply gives a 1.3A and 25V DC source which is more than capable of supporting the PLC even with all I/O ports being used. The maximum start-up time is 1000ms, which allows plenty of time for the PLC to receive and send data to and from the other sub-systems. The humidity range allows up to 95% humidity which is ideal for the supply being used inside of a greenhouse. 
 
**HMI to PLC**
- We will use the PLC and code in "Ladder" to allow the ports to be read and sent to the HMI. The HMI then has the C-more Micro Programming Software that can be used to design and simulate the code to be used on the HMI to correctly display and customize the buttons. Here is the template to allow for communication between PLC and HMI.

![PLC Port Code](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/LadderLogicForPLC.PNG)

## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|CLICK PLUS|PLC|Automation Direct|C2-03CPU|1|$205.00|$205.00|
|STRIDE|WiFi/Bluetooth Antenna|Automation Direct|SE-ANT250|1|$50.50|$50.50|
|CLICK|Power Supply|Automation Direct|C0-01AC|1|$63.00|$63.00|
|SanDisk|MicroSD|Amazon|SanDisk Ultra microSDHC 32GB|1|$7.65|$7.65|
|BIGtec|Wifi Extender|Amazon|2024 Release WiFi Extender Signal Booster for Home|1|$24.99|$24.99|



**References**

[1] AutomationDirect, "Click PLCs - CLICK PLUS Features," AutomationDirect, https://www.automationdirect.com/clickplcs/clickplus/features.

[2] AutomationDirect, "C20xCPU - CPU Module for C2000 Series PLCs," AutomationDirect, https://cdn.automationdirect.com/static/specs/c20xcpu.pdf.

[3] Atlas Scientific, "Ideal Greenhouse Temperature and Humidity," Atlas Scientific Blog, https://atlas-scientific.com/blog/ideal-greenhouse-temperature-and-humidity/#:~:text=Ideal%20Humidity%20For%20Greenhouses&text=The%20optimal%20relative%20humidity%20level,growth%20and%20lower%20quality%20yield.

[4] AutomationDirect, "CLICK PLC Data Logging | Do-more Designer 2.0.2 Logger", AutomationDirect, https://www.automationdirect.com/videos/video?videoToPlay=rkgwh-HfNKo
