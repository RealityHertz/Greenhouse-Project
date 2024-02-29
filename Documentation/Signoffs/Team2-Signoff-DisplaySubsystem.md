# *Detail Design: Communications Application*

## **Function of the Subsystem:**

The Display Subsystem is responsible for receiving input data from various sensors within the greenhouse, such as nutrient levels, humidity, temperature, CO2, and NO2 levels. This subsystem collects this data obtained by the Programmable Logic Controller (PLC) and relays it to the HMI (Human-Machine Interface) for display and monitoring purposes. Its primary function is to ensure the efficient handling of sensor data and present it on the HMI within the greenhouse. This subsystem serves as an intermediary, utilizing the data received and transmitting it to the visualization interface for greenhouse workers. The HMI displays real-time sensor readings, aiding in informed decision-making. Additionally, it highlights any sensors indicating measurements outside the acceptable range, providing alerts for immediate attention. The focus of this subsystem is to efficiently relay real-time sensor data in an easily understandable format on the HMI, enabling quick comprehension of the information.

## **Constraints:**

|Segment|Number|Constraint Description|
|--------|-|-------------------------------------------------|
|HMI|1|The HMI shall be capable of receiving and displaying sensor data from various sources within the greenhouse, including nutrient levels, humidity, temperature, CO2, and NO2 levels.|
|HMI|2|Communication between the HMI and PLC must be robust and reliable to ensure real-time monitoring of sensor data.|
|HMI|3|The HMI shall have sufficient screen resolution and clarity to display sensor readings in an easily understandable format, including any alerts or notifications.|
|HMI|4|Power supply for the HMI shall provide stable wattage at 1.05W to ensure uninterrupted operation of the display system.|

## **Buildable Schematic:**

![HMI Design](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADHMISubsystemSchematic.jpg)

*Figure 1. HMI Subsystem Design*

![HMI 2D Model](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/HMI2DModel.PNG)

*Figure 2. HMI 2D Model*

## **Analysis:**

**HMI**
1. **Capability to Display Sensor Data**: The EA3-S3ML HMI is specifically designed to receive and display sensor data from various sources from the C2-03CPU PLC. With its customizable graphical interface and support for multiple data formats, including integers from the PLC, it ensures that all sensor readings are accurately presented to greenhouse workers in real-time. [1]

2. **Robust Communication with PLC**: The communication between the HMI and PLC will be established via ethernet cable connections, ensuring a robust and reliable data link. By using dedicated ethernet ports on both the HMI and PLC, we will see seamless communication, meeting the requirements for real-time monitoring of sensor data. [1]

3. **Screen Resolution and Clarity**: The HMI boasts a display with 128 x 64 pixel resolution, allowing for the easy visualization of sensor readings, alerts, and notifications. Through the C-more Micro Programming Software, the graphical elements on the HMI can be customized to ensure that all information is presented in a clear and understandable format, meeting the demands for effective decision-making. This HMI is capable of allowing up to 999 screens each with different customization options for the buttons. It has 10 lines by 32 characters to be used to ensure clarity. [1]

4. **Stable Power Supply**: To ensure uninterrupted operation, the HMI will be powered by a stable power supply at 1.05W provided by the ethernet port on the PLC. [1]

**HMI Mounting**
![HMI Mounting](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/HMIMounting.jpg)

## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|C-more Micro|HMI|Automation Direct|EA3-S3ML|1|$280.00|$280.00|
|Automation Direct|RJ12 Cable|Automation Direct|DV-1000CBL|1|$23.00|$23.00|

**References**

[1] AutomationDirect, "C-more Micro Operator Interface Panels," AutomationDirect, https://www.automationdirect.com/c-moremicro/ea3-series.


[2] M. Margolis and M. Fisher, "Chapter 4: Sensing the World," O'Reilly Media, 2011. [Online]. Available: 
<https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html> 
Accessed on: October 31, 2023.
