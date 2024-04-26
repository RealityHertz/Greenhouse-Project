# Autonomous Greenhouse Project

## Executive Summary

With this project Team 2 proposes to create a greenhouse that can wirelessly and autonomously detect soil moisture, pH level, and nutrient level as well as carbon dioxide and nitrogen monoxide in the greenhouse's atmosphere along with the greenhouse's temperature and humidity. The greenhouse will also be able to autonomously detect the water level of an exterior water source and fill said reservoir when the level is too low as well as running a timed watering cycle for the plants. 


## Capabilities

This version of the project will be able to accurately measure the levels of nitrogen, phosphorus, and potassium in the greenhouse soil as well as the temperature, humidity, carbon dioxide, and nitrogen monoxide levels in the atmosphere. The project will also be able to detect the water level of an external reservoir that will alert when low and be able to refill when the alert is sent.


## Salient Outcomes

### 1. Soil Moisture, pH, and Nutrient Level Detection
- **Outcome:** Develop a system that provides real-time data on soil conditions, allowing for precise adjustments to watering schedules and nutrient applications. This could lead to optimized plant growth and reduced resource waste.

### 2. Atmospheric Monitoring (CO2 and NO2 Levels)
- **Outcome:** Implement sensors that continuously monitor and log the levels of CO2 and NO2. This data could be used to adjust ventilation, maintaining optimal air quality for plant health.

### 3. Temperature and Humidity Control
- **Outcome:** Create a responsive system that adjusts internal temperature and humidity based on preset thresholds. This could help in maintaining a stable environment that promotes plant health and productivity.

### 4. Water Level Monitoring and Reservoir Refilling
- **Outcome:** Design an automated system that detects low water levels in an external reservoir and alerts for manual intervention. This ensures a consistent water supply for the greenhouse, crucial for plant survival and growth.

### 5. Adjustable Lighting System
- **Outcome:** Implement a lighting system that can adjust the duration of grow light exposure based on Human-Machine Interface (HMI) inputs. This allows for flexible light management tailored to the growth stages and needs of different plant

### Documentation and Sign-offs
For detailed outcomes and progress on these subsystems, refer to the specific documentation and sign-offs provided in the project's [Documentation/Signoffs folder](https://github.com/RealityHertz/Greenhouse-Project/tree/main/Documentation/Signoffs). This folder contains detailed reports and approval documents that outline the performance and expectations for each subsystem.

## Project Demonstration & Images

[Demonstration Videos](https://github.com/RealityHertz/Greenhouse-Project/tree/main/Documentation/Images/Team2_Experimental_Videos)

### Lighting System Images

![Lighting Housing](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Lighting_Housing.png)

- The above image shows the housing for the lighting system as it is closed and being tested.

![Grow Lights Off](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Grow_Lights_Off.png)

- This image shows the lighting system's grow lights when they are powered off.

![Grow Lights On](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Grow_Lights_On.png)

- This shows the grow lights while powered on.

![Lighting Implementation](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Lighting_Implementation.jpg)

- This image shows the lighting system being implemented and tested within the greenhouse setting of the Hyder-Burks facility.

### PLC and HMI Images

![HMI](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/HMI_Photo.png)

- This shows the HMI as it rests within the PLC housing and is being tested.

![PLC Ethernet Hub](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PLC_HMI_Ethernet.png)

- This image shows the ethernet hub that connects the PLC and HMI to an outside source for pushing of code and testing while powered on.

![PLC RS232 Translator](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PLC_RS232.png) 

- The image above shows the RS232 to TTL translator module that allows the PLC to communicated with the Arduino pictured to allow for sending of commands and recieving of data.

### Water Level System Images

![Water Level Image](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Water_Level_Photo.png)

- Pictured above is the breadboard containing the water level sensor and the Arduino Nano 33 IoT for the water level sensor as it is being tested.

### CO2 and NO2 System Images

![CO2 and NO2 Image](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CO2_NO2_Photo.png)

- The above image shows the breadboard containing the carbon dioxide and nitrogen dioxide sensors for the CO2 and NO2 system as well as their connected Arduino. The nitrogen dioxide sensor is the green sensor pictured in the center of the image directly above the Arduino while the carbon dioxide sensor is the gold sensor located on the right hand side of the board.

### Temperature and Humidity System Images

![Temp and Humidity Image](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Temp%20Photo.png)

- Pictured above is the temperature and humidity system with the transmitting Arduino pictured on the left of the board and the sensor itself pictured on the right as the small black box surrounded by wires.

### Nutrient System Images

![Nutrient Image](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Nutrient%20photo.jpg)

- This image shows the nutrient monitoring system as it is being implemented in a pot of soil picturing the sensor placed in the soil, the Arduino for sending and recieving data and finally the MAX485 to TTL translator which is pictured on the far right of the board.

## About Us

### Team


Team 2 is a 5 member Capstone Design Project Team at Tennessee Technological University who began Version 1 of the Greenhouse Automation Project in the Fall semester of 2023. The group members are Robert Jones, Jared Hooker, Jaxson Billings, Bryan Rhoton, and Grant Hooper. All members contributed to the C02 and N02 Monitoring System.

![Noah Headshot](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Noah%20Jones%20Headshot.jpg)
- **Robert Jones**
  - Electrical Engineering Major
  - Hardware
  - Controls
  - Lighting Control System
 
![Bryan Headshot](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Bryan_Rhoton_Headshot_resize.jpg)
- **Bryan Rhoton**
  - Computer Engineering Major
  - Soil Detection System

![Jared Headshot](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Jared%20Hooker%20Headshot.jpg)
- **Jared Hooker**
  - Electrical Engineering Major
  - Controls
  - Temperature & Humidity Monitoring System

![Jaxson Headshot](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Jaxson%20Billings%20Headshot.jpg)
- **Jaxson Billings**
  - Computer Engineering Major
  - Programming
  - Communication and Display Subsystem

![Grant Headshot](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Grant%20Hooper%20Headshot.jpg)
- **Grant Hooper**
  - Electrical Engineer
  - Controls
  - Water Level Monitoring System

### Faculty Supervisor

The faculty advisor for the project is Jesse Roberts.

### Stakeholders

The customer for this project is the Agricultural Department at Tennessee Technological University. A scalable version of this design would be useful for agricultural researchers, farmers, and/or urban growers.

### Recognitions

Team 2 would like to recognize the sponsor for this project, EOSYS. They have worked closely with the group to help provide feedback, troubleshoot, and brainstorm ideas for the project. 

## Repo Organization

### [Reports](https://github.com/RealityHertz/Greenhouse-Project/tree/main/Reports)

Finalized reports can be found by going to the Reports folder or by clicking the link above.

### [Documentation](https://github.com/RealityHertz/Greenhouse-Project/tree/main/Documentation)

Group documentation can be found by going to the Documentation folder or by clicking the link above.

### [Software](https://github.com/RealityHertz/Greenhouse-Project/tree/main/Software)

Software can be found by going to the Software folder or by clicking the link above.
