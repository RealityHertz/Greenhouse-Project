<a name="br1"></a> 

# *Detail Design: Lighting Control*
## **Team Members: Robert Jones**
## **Function of the Subsystem:**
The function of this subsystem is to have grow lights shine on the plants to help them in their growing process. The system will allow the full-spectrum light operating hours to be adjustable via the PLC and the programmable buttons on the HMI. The system will be controlled by an Arduino which is connected to the Programmable Logic Controller (PLC) subsystem to tell the lights when to turn on and off. 
- **Lighting Timing**

	During a plant's photosynthesis process, they require between 12 and 16 hours a day of full spectrum light. On an average day, a plant inside of the greenhouse will only receive around 10 hours per day. [4] To combat this, the light must be able to shine for a minimum of 2 hours per day.
- **Light Intensity**

	Most plants need between 200-400 µmol/m²/s of light intensity to help to achieve optimal plant growth. [1] To achieve this measure of success, the distance of the light from the plant will have to be fully adjustable as the plant grows upward toward the light.
- **Light Control**

	To make the lights controllable for the user, the HMI must give the user the ability to adjust how long the light is on per day. This must be between 2 and 6 hours, based on the current weather conditions or any other factors that may reduce UV light on the plants.  
	

## **Buildable Schematic:**
![Lighting Control Schematic](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADLightingGrowSubsystem.jpg)
*Figure 1. Buildable Schematic*

![Relay Diagram](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/RelayDiagram.png)

*Figure 2. Relay Diagram*

## **Analysis:**
- **Lighting Spectrum:**
	The system uses a full-spectrum light bulb which mimics UV rays from the sun. This light will allow the plants to achieve optimal growth even when sunlight is not apparent.
- **Power Supply for Arduino Nano 33 IoT:**
	The power will be USB from a 110-volt wall outlet and will supply 5 volts to the Pin 15 on the Nano 33 IoT. The Pin 14 on the Nano 33 IoT will need to be connected to the ground from the USB ground wire.
	The USB cable and plug used have a max current of 1 amp and 2 amp respectively. This will allow for a safe current supply to the board.
- **Power Supply for Grow Bulbs:**
	The Arduino 33 Iot has the ability to output 5V and a maximum current of 1 A with the bulb needing 5W. A relay will be placed in the circuit as well to control the main voltage using the Nano IoT.[5]
- **Light Intensity:**
  	During the first 2 weeks of a plant's life, the light is most beneficial when it is around 6 inches away. After this period, the light needs to be 12 inches away. To achieve this, the light will be hung from a small chain and S-hook to be fully adjustable.
- **Control:**
	
  
## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Geekstory|5V Relay Module|Amazon|SRD-05VDC-SL-C|1|$11.99|$11.99|
|Yanmis|Full Spectrum Grow Light|Amazon|Grow Light|1|$10.00|$10.00|
|Askcable|50ft AWG Cable|Amazon|Copper Wire|1|$17.99|$17.99|
|Arduino|Bluetooth Board|Amazon|Nano 33 IoT|1|$29.99|$29.99|
|New orange heart|Waterproof Bulb Socket|Amazon|E26|1|$9.99|$9.99|

## **References:**
[1]
H. Chen et al., “Competition for Light Interception in Cotton Populations of Different Densities,” Agronomy, vol. 11, no. 1, p. 176, Jan. 2021, doi: 10.3390/agronomy11010176. [Online]. Available: http://dx.doi.org/10.3390/agronomy11010176

[2]
How to Use Red and Blue Grow Lights | Described in 7 Steps. 22 Mar. 2023, lightow.com/how-to-use-red-and-blue-grow-lights/. Accessed 12 Feb. 2024.

[3]
“Growing Ferns.” Extension.uga.edu, extension.uga.edu/publications/detail.html?number=B737#:~:text=Depending%20on%20the%20kind%20of%20fern%2C%20it%20may. Accessed 12 Feb. 2024.
‌

[4]
Everbeam. “How Long to Leave UV Light on Plants: A Guide to Optimal Exposure Time.” Everbeam, shopeverbeam.com/blogs/news/how-long-to-leave-uv-light-on-plants-a-guide-to-optimal-exposure-time#:~:text=The%20distance%20between%20the%20plants%20and%20the%20grow. Accessed 13 Feb. 2024.


[5]
Cruz, Terenz Jomar Dela. “How to Power Light Bulbs Using an Arduino with a Relay Module.” IoT Tech Trends, 19 Oct. 2022, www.iottechtrends.com/use-relay-module-with-arduino/.
