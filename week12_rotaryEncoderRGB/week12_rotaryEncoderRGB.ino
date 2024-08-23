#include <Arduino.h>

// Pin assignments for the RGB LED
const int redPin = 9;    // Red LED pin
const int greenPin = 10; // Green LED pin
const int bluePin = 11;  // Blue LED pin

// Pin assignments for the rotary encoder
const int clkPin = 2;    // CLK pin of the rotary encoder
const int dtPin = 3;     // DT pin of the rotary encoder
const int swPin = 7;     // SW pin of the rotary encoder (button)

int currentChannel = 0;  // Variable to keep track of the current color channel (0 = Red, 1 = Green, 2 = Blue)
int lastButtonState = HIGH;  // Variable to store the previous state of the rotary encoder button
int lastClkState = HIGH;     // Variable to store the last state of the CLK pin

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
  
  // Set the rotary encoder pins as inputs
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);  // Enable internal pull-up resistor for the button
  
  // Initial state for the LED
  updateLED();
}

void loop() {
  // Read the current state of the rotary encoder button
  int buttonState = digitalRead(swPin);

  // Check if the button was just pressed (transition from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Cycle through the color channels: Red -> Green -> Blue
    currentChannel = (currentChannel + 1) % 3;
    delay(200);  // Debounce delay to prevent multiple triggers
  }

  // Update the last button state for the next loop iteration
  lastButtonState = buttonState;

  // Read the current state of the CLK pin
  int clkState = digitalRead(clkPin);

  // If the CLK state changes, adjust the color intensity
  if (clkState != lastClkState) {
    // Determine the direction of rotation
    if (digitalRead(dtPin) != clkState) {
      // Clockwise rotation - increase the intensity of the current color channel
      adjustColor(5);
    } else {
      // Counterclockwise rotation - decrease the intensity of the current color channel
      adjustColor(-5);
    }
  }

  // Update the last CLK state for the next loop iteration
  lastClkState = clkState;

  delay(50);  // Small delay to smooth out changes and update the serial monitor
}

// Function to adjust the intensity of the current color channel
void adjustColor(int amount) {
  switch (currentChannel) {
    case 0:
      redValue = constrain(redValue + amount, 0, 255);
      break;
    case 1:
      greenValue = constrain(greenValue + amount, 0, 255);
      break;
    case 2:
      blueValue = constrain(blueValue + amount, 0, 255);
      break;
  }
  updateLED();
}

// Function to update the RGB LED with the current color values
void updateLED() {
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
}
