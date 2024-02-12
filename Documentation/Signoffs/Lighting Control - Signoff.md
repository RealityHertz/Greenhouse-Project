<a name="br1"></a> 

# *Detail Design: Lighting Control*
## **Team Members: Robert Jones**
## **Function of the Subsystem:**
The function of this subsystem is to have grow lights shine on the plants to help them in their growing process. There will be two sets of lights, one red and the other blue. The system will be controlled by an Arduino which is connected to the Programmable Logic Controller (PLC) subsystem to tell the lights when to turn on and off. 
- **Lighting Spectrum**

	During a plant's growing process, shining different colored lights can help speed up their different phases. Typically, the two colors for optimal growth are red and blue, which have a wavelength of 400-500nm for blue light and 600-700nm for red light.[1] Blue light is best for the seed and budding phase of a plant's life red light is most beneficial during the bloom phase.[2]
- **Light Intensity**

	Most plants need between 200-400 µmol/m²/s of light intensity. These levels help to achieve optimal plant growth. To achieve this measure of success, the distance of the light from the plant will have to be adjusted based on their specific needs.[1]
## **Buildable Schematic:**
![Lighting Control Schematic](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADLightingSubsystem.jpg)
## **Analysis:**
- **Lighting Spectrum:**
	The system has two sets of lights, the red light produces a wavelength of 660nm and the blue light produces a wavelength of 475nm. These are both well within the acceptable ranges needed for optimal growth.
- **Power Supply for Arduino Nano 33 IoT:**
	The power will be USB from a 110-volt wall outlet and will supply 5 volts to the Pin 15 on the Nano 33 IoT. The Pin 14 on the Nano 33 IoT will need to be connected to the ground from the USB ground wire.
	The USB cable and plug used have a max current of 1 amp and 2 amp respectively. This will allow for a safe current supply to the board.
- **Power Supply for Grow Bulbs:**
	The Arduino 33 Iot has the ability to output 5V with the bulb needing 9W. A relay will be placed in the circuit as well to control the main voltage using the Nano IoT. 
- **Light Intensity:**
  	To ensure that the plants are achieving the most optimal benefits from the lights, the red light will be placed 2 feet away from the top of the plant and the blue light at 6 inches. [2]
- **Control:**
	To control which lights are on, the PLC will be used to switch them back and forth. For the first two months of the plant's life, the blue light will be used while it is in the budding phase. After 2 months, the red light will turn on for the remainder of its life. [3]
  
## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Geekstory|5V Relay Module|Amazon|SRD-05VDC-SL-C|1|$11.99|$11.99|
|Un-Edison|Blue Led Bulbs|Amazon|Seed Starting Bulb|2 pack|$20.54|$20.54|
|Un-Edison|Red Led Bulbs|Amazon|Flowering Bulb|1|$13.00|$13.00|
|Askcable|50ft AWG Cable|Amazon|Copper Wire|1|$17.99|$17.99|

## **References:**
[1]
H. Chen et al., “Competition for Light Interception in Cotton Populations of Different Densities,” Agronomy, vol. 11, no. 1, p. 176, Jan. 2021, doi: 10.3390/agronomy11010176. [Online]. Available: http://dx.doi.org/10.3390/agronomy11010176

[2]
How to Use Red and Blue Grow Lights | Described in 7 Steps. 22 Mar. 2023, lightow.com/how-to-use-red-and-blue-grow-lights/. Accessed 12 Feb. 2024.

[3]
“Growing Ferns.” Extension.uga.edu, extension.uga.edu/publications/detail.html?number=B737#:~:text=Depending%20on%20the%20kind%20of%20fern%2C%20it%20may. Accessed 12 Feb. 2024.
‌

[4]
Cruz, Terenz Jomar Dela. “How to Power Light Bulbs Using an Arduino with a Relay Module.” IoT Tech Trends, 19 Oct. 2022, www.iottechtrends.com/use-relay-module-with-arduino/.
