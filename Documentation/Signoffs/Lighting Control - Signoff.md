<a name="br1"></a> 

# *Detail Design: Lighting Control*
## **Team Members: Robert Jones**
## **Function of the Subsystem:**
The function of this subsystem is to have grow lights shine on the plants to help them in their growing process. The subsystem will use a series of LEDs to do this. A photocell will be connected to the system to 
## **Constraints:**
- Lighting Spectrum
	Each type of plant grown in the greenhouse needs slightly different colors for optimal growth. Therefore, the light must be able to conform to all kinds of plants. Typically, this is 400-500nm for blue light and 600-700nm for red light.
- Light Intensity
	Most plants need between 200-400 µmol/m²/s of light intensity. To achieve this measure of success, the distance of the light from the plant will have to be adjusted. 
## **Buildable Schematic:**
![Lighting Control Schematic](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/rnjones42.JPG)
## **Analysis:**
- Power Supply and Connection for Photocell:
	The ground from the Wall-Wart will feed into Pin 1 (black) on the photocell, the voltage out feeds into Pin 2 (white), and Pin 3 (red) will connect to the voltage in on the LED lights.
- Wall-Wart:
	The Wall-Wart will take in the 110V from the outlet and step it down to 12V to power the photocell.
## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Lulukee|Photocell|Amazon|095MTW82J|1|$9.99|$9.99|
|Novelty Place|Led Bulbs|Walmart|UV LED Diode Lights|3(Each Color)|$10.95|$10.95|

## **References:**
[1]
H. Chen et al., “Competition for Light Interception in Cotton Populations of Different Densities,” Agronomy, vol. 11, no. 1, p. 176, Jan. 2021, doi: 10.3390/agronomy11010176. [Online]. Available: http://dx.doi.org/10.3390/agronomy11010176
