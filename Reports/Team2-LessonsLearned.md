# Team 2 Lessons Learned

## Member and Individual Lessons Learned/Classes Applied

### Noah Jones

- What went well:
    - For me, the main thing that went well was providing power to the lighting, PLC, and HMI subsystems. After realizing that using an extension cord was our best option during the building of the lighting system, it was easy to duplicate for the other two systems.
- What did not go well:
- Problems:
- What would you do differently?
- Best Practices:
- Words of wisdom:
- New knowledge or skills:

### Grant Hooper

- What went well:
- What did not go well:
- Problems:
- What would you do differently?
- Best Practices:
- Words of wisdom:
- New knowledge or skills:

### Jared Hooker

- What went well:
- What did not go well:
- Problems:
- What would you do differently?
- Best Practices:
- Words of wisdom:
- New knowledge or skills:

### Jaxson Billings

- What went well:
    - What went well was the construction and overall the programming of all Arduino's. BLE advertising and receiving addresses, serviceUUIDs, CharacteristicUUIDs, Attributes, and Values all worked phenomenally with both the peripheral and central Arduino's. Wiring of the circuits, getting everything the correct voltage to each component,  and getting them on solderless breadboards also went well.
- What did not go well:
    - What did not go well was the interface and protocols used with most sensors. Many of the components bought had very poor documentation and not much information about use. Also, getting the PLC to recieve RS232 seemed like an easy enough task, but time ran low and we were not able to figure out the correct connection/ladder logic.
- Problems:
    - The problems we incountered were libraries not being compatiable with the board manager used for the Arduino Nano 33 IoT, the PLC signaling it was receiving via RS232 but not took in the data, the NO2 sensor only ever sent high or low depending on if it was receiving enough voltage, and  the Arduino's digital set pin HIGH worked a minority of the time.
- What would you do differently?
    - If I could do thing differently, I would make sure that 100% of the sensors bought had solid data sheets, as well as documentation and compatiable libraries with the Arduino being used. I would also think about switching away from the Arduino Nano 33 IoT because most sensors are made for other older Arduino's and are not compatiable with the SAMD Board Manager. I would better utilize the example projects given whenever a library is downloaded. I would order better solderless breadboards to allow for connections and less finicky voltages.
- Best Practices:
    - I've picked up some valuable practices, like thoroughly making sure code is written to be reusable and well documented, researching topics before committing to ideas, carefully reviewing datasheets or product documentation, ensuring products align with my specific requirements before making commitments, and not hesitating to ask numerous questions, even if it means reaching out to the product manufacturer.
- Words of wisdom:
    - Do all your research. Have full confidence in what you are buying and know before hand how it is going to be programmed, what tools may be needed, how the connections will be not only theoretically but realistically.
- New knowledge or skills:
    - I learned more from this class then almost every other class I have taken. It bettered my skills in C, thought me how to truly make connections on a system without relying on soldered breadboards, as well as how to use Arduino IDE.

### Bryan Rhoton

- What went well:
    - For my part of the project what went well was the construction and testing of my system. As we tested we learned that the register address values I was using were wrong and I had to go back and fix them as best I could through trial and error. Another part of the process that went well for me was the coding of the system and being able to assist my teammates in the coding, construction and connection identification of their systems.
- What did not go well:
    - What did not go well for me was the design aspect of my system. Not only having to search the internet for what felt like days on end to find a sensor that would fit within our constraints and budget but also to find an adequate voltage regulator that would do exactly what we wanted it to.
- Problems:
    - One unanticipated problem that occured was the delay of my sensor being shipped and another was the unavailability of tbe voltage regulator that we had originally intended to use. Yet another problem was the lack of adequate documentation and datasheets for the sensor and other components of my system making it incredibly difficult to accurately code and test. One final problem that occured for my system was that the regulators we ordered, not the originals we had planned to order but a replacement, did not output voltage as they were meant to when connected to power the regultor would simply do nothing no matter how many configurations and tests we attempted the regulators simply would not output voltage.
- What would you do differently?
    - Personally what I would do differently would be to research npk sensors and voltage regulators much more in depth before I had begun to design with them. The lack of documentation and reliable sensors available make it difficult to make constraints for this kind of system let alone deliver on them so more research before hand would have been incredibly helpful.
- Best Practices:
    - Some best practices I learned were to always fully research a topic before you commit to the idea, always fully read the datasheet or documentation of products you plan to use, ensure products fit your specific needs before commiting to them and ask as many questions as needed even if you have to contact the manufactuer of the product you plan on using.
- Words of wisdom:
    - My words of wisdom would be to conduct research on your proposed problem, project or system before you commit to it. Ensure that there is adequate documentation for whatever you choose to do so you don't have to essentially make it up as you go along and research along the way.
- New knowledge or skills:
    - In capstone I increased my knowledge base of Arduino coding and libraries. I learned the very basic idea of BLE communication and functionality. I also learned very basic knowledge of how plcs and hmis work and are operated. Finally I learned an immense amount about the operation of and calculations for voltage regulators and their different functions.
