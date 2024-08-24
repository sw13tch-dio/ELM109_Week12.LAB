# ELM109_Week12.LAB
 Learn how to control an RGB LED using a rotary encoder, allowing for dynamic color mixing based on user input.

ELM-109 Tech Programming
Week 12
LAB – Color Control with a Rotary Encoder

"Color Mixer with Rotary Encoder"
Interactive Color Mixing Using a Rotary Encoder

Equipment:
•	1 x Breadboard
•	1 x Arduino UNO R3
•	1 x USB Type-B to USB cable (for programming and power)
•	Male to Male Jumper Wires
•	Male to Female Jumper Wires
•	1 x RGB LED Module (color mixing capable)
•	1 x Rotary Encoder Module

Objective:
In this lab, you will control an RGB LED using a rotary encoder. The rotary encoder will allow you to cycle through the red, green, and blue color channels, adjusting the intensity of each color individually. This lab will help you understand how to use a rotary encoder to interact with Arduino outputs, providing precise control over a multicolored LED.

Setup:
1.	Power and Ground Setup:
o	Connect the Arduino’s 5V pin to the + power rail on the breadboard using a jumper wire.
o	Connect the Arduino’s GND pin to the - ground rail on the breadboard using a jumper wire.
2.	RGB LED Connection:
o	Place the RGB LED module onto the breadboard.
o	Connect the common pin (cathode) to the - ground rail on the breadboard.
o	Connect the red pin of the RGB LED to pin 9 on the Arduino.
o	Connect the green pin of the RGB LED to pin 10 on the Arduino.
o	Connect the blue pin of the RGB LED to pin 11 on the Arduino.
3.	Rotary Encoder Connection:
o	Connect the GND pin of the rotary encoder to the - ground rail on the breadboard.
o	Connect the + (VCC) pin of the rotary encoder to the + power rail on the breadboard.
o	Connect the CLK pin of the rotary encoder to pin 2 on the Arduino.
o	Connect the DT pin of the rotary encoder to pin 3 on the Arduino.
o	Connect the SW pin of the rotary encoder to pin 7 on the Arduino (used to switch between color channels).

Procedure:
1.	Programming the Arduino:
o	Open the Arduino IDE on your computer.
o	Write or copy the provided code into the IDE.
o	Verify the code to check for errors.
o	Upload the code to the Arduino.
2.	Running the Experiment:
o	Once the code is uploaded, the RGB LED should start with a neutral color (e.g., white or mid-level RGB values).
o	Rotate the rotary encoder to adjust the intensity of the selected color channel (red, green, or blue).
o	Press the rotary encoder knob (SW pin) to cycle through the color channels. Each press will change the selected channel, allowing you to adjust a different color.

4.	Observations:
o	Record how the RGB LED color changes as you rotate the encoder.
o	Observe how pressing the rotary encoder knob changes the selected color channel, allowing you to mix colors interactively.

6.	Conclusion:
o	Discuss how the rotary encoder provided precise control over the color channels.
o	Consider how this method of control could be used in other applications, such as adjusting the brightness of a display or tuning values in a menu.

Troubleshooting Tips:
•	If the RGB LED doesn’t light up: Ensure that the common pin (anode or cathode) is correctly connected to power or ground.
•	If the colors don’t change as expected: Double-check the connections for the red, green, and blue pins on the RGB LED and ensure they match the corresponding Arduino pins.
•	If the rotary encoder doesn’t change the color: Verify that the CLK and DT pins are connected to the correct Arduino pins and that the SW pin is properly connected for switching channels.
•	Check for reversed color mapping: If the colors appear incorrect (e.g., turning red when you adjust green), check the code and ensure the correct pins are mapped to the right colors.

Additional Challenges (Optional):
•	Add a visual indicator: Connect an additional LED to indicate which color channel is currently selected.

