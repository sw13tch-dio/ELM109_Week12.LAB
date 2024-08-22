# ELM109_Week12.LAB
 Learn how to control an RGB LED using a joystick, allowing for dynamic color mixing based on user input.

ELM-109 Tech Programming
Week 12
LAB – Color Control with a Joystick
"RGB LED Control Using a Joystick"
Interactive Color Mixing with an RGB LED and Joystick
________________________________________
Objective:
In this lab, you will learn how to control the color of an RGB LED using a joystick. By cycling through the Red, Green, and Blue color channels with a button press and adjusting the intensity of each color using the joystick, you will be able to mix and create a wide range of colors. This lab will help you understand how to read analog inputs, process them, and control digital outputs with Arduino.
________________________________________
Equipment:
•	1 x Breadboard
•	1 x Arduino UNO R3
•	1 x USB Type-B to USB cable (for programming and power)
•	Male to Male Jumper Wires
•	Male to Female Jumper Wires
•	1 x RGB LED Module (Common Cathode)
•	1 x Joystick Module
________________________________________
Setup:
1.	Power and Ground Setup:
o	Connect the Arduino’s 5V pin to the + power rail on the breadboard using a jumper wire.
o	Connect the Arduino’s GND pin to the - ground rail on the breadboard using a jumper wire.
2.	RGB LED Module Connection:
o	Place the RGB LED module onto the breadboard, running parallel to the power rails.
o	Connect the GND pin of the RGB LED module to the - ground rail on the breadboard.
o	Connect the R pin of the module to pin 9 on the Arduino (Red LED control).
o	Connect the G pin of the module to pin 10 on the Arduino (Green LED control).
o	Connect the B pin of the module to pin 11 on the Arduino (Blue LED control).
3.	Joystick Module Connection:
o	Connect the VCC pin of the joystick module to the + power rail on the breadboard.
o	Connect the GND pin of the joystick module to the - ground rail on the breadboard.
o	Connect the X pin of the joystick module to the A0 pin on the Arduino.
o	Connect the Y pin of the joystick module to the A1 pin on the Arduino.
o	Connect the SW (Switch) pin of the joystick module to pin 7 on the Arduino.
________________________________________
Procedure:
1.	Programming the Arduino:
o	Open the Arduino IDE on your computer.
o	Write or copy the provided code into the IDE.
o	Verify the code to check for errors.
o	Upload the code to the Arduino.
2.	Running the Experiment:
o	Once the code is uploaded, the RGB LED should start with a neutral color (a mix of red, green, and blue).
o	Use the joystick to control the intensity of the selected color channel. Move the joystick up or down to adjust the intensity.
o	Press the joystick button to cycle through the Red, Green, and Blue channels.
o	Observe how the color of the LED changes as you adjust the intensity of each channel.
3.	Observations:
o	Record how the RGB LED responds to different joystick movements.
o	Experiment with different color combinations by adjusting the intensity of each channel.
4.	Conclusion:
o	Discuss how the joystick input was used to control the RGB LED. How did the cycling of color channels contribute to creating various colors?
o	Consider how this setup could be modified to create a more complex color-mixing interface or be adapted for other applications, such as controlling other types of outputs.
________________________________________
Troubleshooting Tips:
•	No Color Change: If the LED doesn’t change color when the joystick is moved, check the wiring connections for the joystick module, particularly the X, Y, and SW pins.
•	Incorrect Colors: If the colors appear incorrect or reversed (e.g., green instead of red), the R, G, and B pins on the RGB LED module might be mapped incorrectly. Double-check the wiring and ensure the pins correspond to the correct colors on the module.
•	No Response from Joystick Button: If pressing the joystick button doesn’t cycle through the color channels, verify that the SW pin is connected to pin 7 on the Arduino and that the button is functioning correctly.
•	LED Too Bright/Dull: If the LED appears too bright or dull, check the analogWrite values being sent to the R, G, and B pins. Adjust the mapping if necessary to better suit the LED's brightness range.

