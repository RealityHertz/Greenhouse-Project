<a name="br1"></a> 

# *Detail Design: Lighting Control*
## **Team Members: Robert Jones**
## **Function of the Subsystem:**
The function of this subsystem is to have grow lights shine on the plants to help them in their growing process. There will be two sets of lights, one red and the other blue. The system will be controlled by an Arduino which is connected to the PLC subsystem to tell the lights when to turn on and off. 
- Lighting Spectrum
	Each type of plant grown in the greenhouse needs slightly different colors for optimal growth. Therefore, the light must be able to conform to all kinds of plants. Typically, this is 400-500nm for blue light and 600-700nm for red light.[1]
- Light Intensity
	Most plants need between 200-400 µmol/m²/s of light intensity. These levels help to achieve optimal plant growth. To achieve this measure of success, the distance of the light from the plant will have to be adjusted based on their specific needs.[1]
## **Buildable Schematic:**
![Lighting Control Schematic](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADLightingSubsystem.jpg)
## **Analysis:**
- Lighting Spectrum and Height:
	The system has two sets of lights, the red light produces a wavelength of 660nm and the blue light produces a wavelength of 475nm. These are both well within the acceptable ranges needed for optimal growth.
- Power Supply for Grow Bulbs:
	The Arduino 33 Iot has the ability to output 5V with the bulb needing 9W.
- 

## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Lulukee|Photocell|Amazon|095MTW82J|1|$10.99|$10.99|
|Novelty Place|Led Bulbs|Walmart|UV LED Diode Lights|1 pack (100)|$10.95|$10.95|
|ALITOVE|Wall-Wart|Amazon|ALT-1205|1|$11.99|$11.99|

## **References:**
[1]
H. Chen et al., “Competition for Light Interception in Cotton Populations of Different Densities,” Agronomy, vol. 11, no. 1, p. 176, Jan. 2021, doi: 10.3390/agronomy11010176. [Online]. Available: http://dx.doi.org/10.3390/agronomy11010176
