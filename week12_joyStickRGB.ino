#include <Arduino.h>

// Pin assignments for the RGB LED
const int redPin = 9;    // Red LED pin 
const int greenPin = 10; // Green LED pin
const int bluePin = 11;  // Blue LED pin

// Pin assignments for the joystick
const int joyXPin = A0;  // Joystick horizontal axis (X)
const int joyYPin = A1;  // Joystick vertical axis (Y)
const int joyButtonPin = 7;  // Joystick button

int currentChannel = 0;  // Variable to keep track of the current color channel (0 = Red, 1 = Green, 2 = Blue)
int lastButtonState = HIGH;  // Variable to store the previous state of the joystick button

// Initial values for the RGB channels, starting at neutral (mid-range)
int redValue = 128;
int greenValue = 128;
int blueValue = 128;

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate

  // Set the RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // Set the joystick button pin as input with an internal pull-up resistor
  pinMode(joyButtonPin, INPUT_PULLUP);
}

void loop() {
  // Read the current state of the joystick button
  int buttonState = digitalRead(joyButtonPin);

  // Check if the button was just pressed (transition from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Cycle through the color channels: Red -> Green -> Blue
    currentChannel = (currentChannel + 1) % 3;
    delay(200);  // Debounce delay to prevent multiple triggers
  }
  
  // Update the last button state for the next loop iteration
  lastButtonState = buttonState;

  // Read the joystick position for the X and Y axes
  int joyXValue = analogRead(joyXPin);
  int joyYValue = analogRead(joyYPin);

  // Map the joystick position to change the intensity of the current color channel
  if (currentChannel == 0) {
    // Adjust the red channel value based on joystick movement
    redValue = constrain(redValue + map(joyXValue, 0, 1023, -5, 5) + map(joyYValue, 0, 1023, -5, 5), 0, 255);
  } else if (currentChannel == 1) {
    // Adjust the green channel value based on joystick movement
    greenValue = constrain(greenValue + map(joyXValue, 0, 1023, -5, 5) + map(joyYValue, 0, 1023, -5, 5), 0, 255);
  } else if (currentChannel == 2) {
    // Adjust the blue channel value based on joystick movement
    blueValue = constrain(blueValue + map(joyXValue, 0, 1023, -5, 5) + map(joyYValue, 0, 1023, -5, 5), 0, 255);
  }

  // Output the color values to the LED
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  // Print the current RGB values to the Serial Monitor for debugging
  Serial.print("Red: ");
  Serial.print(redValue);
  Serial.print("\tGreen: ");
  Serial.print(greenValue);
  Serial.print("\tBlue: ");
  Serial.println(blueValue);

  delay(100);  // Small delay to smooth out changes and update the serial monitor
}
