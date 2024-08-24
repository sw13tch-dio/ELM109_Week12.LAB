#include <Arduino.h>

// Pin assignments for the RGB LED
const int redPin = 9;    // Red LED pin
const int greenPin = 10; // Green LED pin
const int bluePin = 11;  // Blue LED pin

// Pin assignments for the rotary encoder
const int clkPin = 2;   // Clock pin
const int dtPin = 3;    // Data pin
const int btnPin = 4;   // Button pin (to switch between channels)

// Variables to store the current color channel and previous states
int currentChannel = 0;  // 0 = Red, 1 = Green, 2 = Blue
int lastClkState = LOW;
int lastBtnState = HIGH;

// Initial values for the RGB channels
int redValue = 128;
int greenValue = 128;
int blueValue = 128;

// Flags to track if changes occurred
bool rgbChanged = true;
bool channelChanged = true;

void setup() {
    Serial.begin(9600);  // Initialize serial communication at 9600 baud rate

    // Set the RGB LED pins as outputs
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    // Set the rotary encoder pins as inputs
    pinMode(clkPin, INPUT);
    pinMode(dtPin, INPUT);
    pinMode(btnPin, INPUT_PULLUP); // Button pin with internal pull-up resistor

    // Initialize the LED with a neutral color
    updateLED();
}

void loop() {
    // Read the current state of the button and clock pin
    int clkState = digitalRead(clkPin);
    int btnState = digitalRead(btnPin);

    // Handle button press to change color channels
    if (btnState == LOW && lastBtnState == HIGH) {
        currentChannel = (currentChannel + 1) % 3;  // Cycle through channels
        channelChanged = true;
    }
    lastBtnState = btnState;

    // Handle rotary encoder movement to adjust the current channel's value
    if (clkState != lastClkState) {
        if (digitalRead(dtPin) == clkState) { // Check the direction
            adjustColor(10);  // Increase value (clockwise)
        } else {
            adjustColor(-10);   // Decrease value (counterclockwise)
        }
        rgbChanged = true; // Mark RGB as changed
    }
    lastClkState = clkState;

    // Print only if a change occurred
    if (rgbChanged || channelChanged) {
        updateLED();

        // Print the current RGB values to the serial monitor
        Serial.print("Red: ");
        Serial.print(redValue);
        Serial.print("\tGreen: ");
        Serial.print(greenValue);
        Serial.print("\tBlue: ");
        Serial.println(blueValue);

        if (channelChanged) {
            Serial.print("Switched to channel: ");
            Serial.println(currentChannel == 0 ? "Red" : currentChannel == 1 ? "Green" : "Blue");
            channelChanged = false;
        }

        rgbChanged = false; // Reset the flag
    }
}

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
}

void updateLED() {
    // Output the current RGB values to the LED
    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
}
