<a name="br1"></a> 

# *Detail Design: Lighting Control*
## **Team Members: Robert Jones**
## **Function of the Subsystem:**
The function of this subsystem is to have grow lights shine on the plants to help them in their growing process. The system will allow the full-spectrum light operating hours to be adjustable via the PLC and the programmable buttons on the HMI. The system will be controlled by an Arduino which is connected to the Programmable Logic Controller (PLC) subsystem to tell the lights when to turn on and off. 
## **Constraints:**
- **Lighting Timing**

	During a plant's photosynthesis process, they require between 12 and 16 hours a day of full spectrum light. On an average day, a plant inside of the greenhouse will only receive around 10 hours per day. [1] To combat this, the lights must be able to shine for a minimum of 2 hours per day.
- **Light Intensity**

	Most plants need between 200-400 µmol/m²/s of light intensity to help to achieve optimal plant growth. [2] To achieve this measure of success, the distance of the lights from the plants will have to be fully adjustable as the plants grow upward toward the lights.
- **Light Control**

	To make the lights controllable for the user, the HMI must give the user the ability to adjust how long the lights are on per day. This must be between 2 and 6 hours, based on the current weather conditions or any other factors that may reduce UV light on the plants.  
	

## **Buildable Schematic:**
![Lighting Control Schematic](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADLightingSubsystemSchematic.jpg)
*Figure 1. Buildable Schematic*

![Relay Diagram](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/RelayDiagram.png)

*Figure 2. Relay Diagram*

## **Analysis:**
- **Lighting Spectrum:**
	The system uses four full-spectrum light bulbs which mimic UV rays from the sun. These lights will allow the plants to achieve optimal growth even when sunlight is not apparent.
- **Power Supply for Arduino Nano 33 IoT:**
	The power will be USB from a 110-volt wall outlet and will supply 5 volts to the Pin 15 on the Nano 33 IoT. The Pin 14 on the Nano 33 IoT will need to be connected to the ground from the USB ground wire.
	The USB cable and plug used have a max current of 1 amp and 2 amp respectively. This will allow for a safe current supply to the board.
- **Power Supply for Grow Bulbs:**
	The Arduino 33 Iot only has the ability to output 5V and a maximum current of 1 A with the bulbs needing 100W. A relay will be placed in the circuit to control the main power while still allowing the Nano IoT to control the lights.[3] From the outlet, the power will be run through an extension cord to a NEMA 4x enclosure which will house a 15A circuit breaker and relay. NEMA 4x was chosen due to its ability to keep out dust and direct sprays from water. A 15 amp breaker will meet the needs of the circuit to protect the components based on: P=IV = 400W=I*120, therefore, the current is 3.33 amps which is below the rating of the 15 amp breaker. 14 gauge extension cords will be ran from the relay to the lights. This will allow for safe power transfer due to the maximum amperage rating on the wire being 15 amps.[6] The positive wire of the extension cord, which is from the 120V wall outlet, will go into the breaker which will then come out of the other side of the breaker and into the common pin of the relay. The neutral wire will go straight to the extension cord which is connected to the lights, which allows for the unused power from the lights to return to the power supply. The ground wire will be grounded inside the box and also go to the lights, this is to ensure that the circuit will be shorted if there were to be a loose neutral or hot wire in the box. The bulbs will screw into an aluminum reflector lamp which will plug into the extension cord.
- **Light Intensity:**
  	To give the plants the needed light intensity of 200-400 µmol/m²/s the distance from the top of the plant to the light must be calculated. Using the formula, Irradiance = Power/4π(r)^2, where P is equal to 100 watts for the bulb and r is equal to the distance of 5.5 feet from the top of the plant, the irradiance is equal to 318 µmol/m²/s. This is well within the range needed for cotton plants. [4] To achieve this, the lights will be hung from a small chain and S-hook to be fully adjustable.
- **Control:**
  	To regulate the timing of light activation and deactivation, the HMI subsystem will feature four programmable buttons. These buttons will enable users to adjust the duration for which the lights remain on and off, allowing for hour-by-hour increments in both directions. For instance, if the preset timing is 2 hours for light activation and 8 hours for deactivation, the buttons will facilitate incremental adjustments, allowing users to increase or decrease each timing by one hour as needed. To add further capabilities, a photocell will be added to the PLC to tell the system if it is day or night. This will in turn allow the PLC to know when the light should start the cycle that has been set by the user.
  
## **Bill of Materials:**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Geekstory|5V Relay Module|Amazon|SRD-05VDC-SL-C|2|$11.99|$23.98|
|Highydro|Full Spectrum Grow Light|Amazon|Grow Light|4|$20.99|$83.96|
|Arduino|Bluetooth Board|Amazon|Nano 33 IoT|2|$29.99|$59.98|
|VIVOSUN|4 Pack Lamp Aluminum Reflector E26|Amazon|B07H8G6PKX|1|$29.69|$29.69|
|DIHOOL|15 Amp Circuit Breaker|Amazon|B0BFF6CX2X|1|$12.78|$25.56|
|AIRIC|Cable Glands|Amazon|NPT 1/4" 20 Pieces|2|$13.99|$27.98|
|TOCRETOARE|NEMA 4x Enclosure|Amazon|12x10x6" Box|1|$49.99|$49.99|
|HONDERSON|10ft 14-3 Extension Cord|Amazon|3 Prong SJTW Heavy Duty Extension Cable|1|$12.19|$12.99|
|Maximm|30ft 14 Gauge Extension Cord with Multiple Outlets|Amazon|B0BT56KZCR|2|$32.99|$65.98|
|Leviton|Straight Blade Rubber Plug|Amazon|000-515PR-000|2|$7.25|$14.50|

## **References:**

[1]
Everbeam. “How Long to Leave UV Light on Plants: A Guide to Optimal Exposure Time.” Everbeam, shopeverbeam.com/blogs/news/how-long-to-leave-uv-light-on-plants-a-guide-to-optimal-exposure-time#:~:text=The%20distance%20between%20the%20plants%20and%20the%20grow. Accessed 13 Feb. 2024.


[2]
H. Chen et al., “Competition for Light Interception in Cotton Populations of Different Densities,” Agronomy, vol. 11, no. 1, p. 176, Jan. 2021, doi: 10.3390/agronomy11010176. [Online]. Available: http://dx.doi.org/10.3390/agronomy11010176
‌

[3]
Cruz, Terenz Jomar Dela. “How to Power Light Bulbs Using an Arduino with a Relay Module.” IoT Tech Trends, 19 Oct. 2022, www.iottechtrends.com/use-relay-module-with-arduino/.

[4]
How Close Should Grow Lights Be to Plants? 22 Apr. 2023, theindoornursery.com/blog/how-close-should-grow-lights-be-to-plants/#:~:text=In%20general%2C%20grow%20lights%20for%20mature%20plants%20should. Accessed 13 Feb. 2024.

[5]
Vanorio, Ame. “Growing Cotton: A Complete Guide on How to Plant, Grow, & Harvest Cotton.” MorningChores, 24 July 2019, morningchores.com/growing-cotton/.

[6]
National Electrical Code Basics: Sizing and protecting branch-circuit conductors - technical articles. EEPower. (n.d.). https://eepower.com/technical-articles/national-electrical-code-basics-sizing-and-protecting-branch-circuit-conductors 
