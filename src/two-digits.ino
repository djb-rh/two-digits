#include <neopixel.h>
#include <Seven_Segment_Pixel.h>
#include <clickButton.h>

// Which pin on the Arduino is connected the NeoPixel display connected to?
#define PIN D0

// How many NeoPixels are in the seven segment display total?
#define NUMPIXELS 56

// How many digits are in the display?
#define DIGITS 2

// How may pixels per segement are there?
#define PIXPERSEG 4

// How many delimeters are in the display?
#define NUMDELIMS 0

// How may pixels per delimeter are there?
#define PIXPERDELIM 0

// When we instatiate a display object we supply the number of digits in the
// custom built display, as well as the number of pixels per segment.
// Additionally we pass the ususal Adafruit_NeoPixel arguments for object
// instatiation.

Seven_Segment_Pixel display1 =
    Seven_Segment_Pixel(DIGITS, PIXPERSEG, NUMDELIMS, PIXPERDELIM, NUMPIXELS,
                        PIN, WS2812B);

int increment = 1;

int count = 0;

// int R1 = D1;
// int S1 = A0;

int buttonModePin = A0;
int buttonDownPin = A1;
int buttonUpPin = A2;

ClickButton buttonMode(buttonModePin, LOW, CLICKBTN_PULLUP);
ClickButton buttonDown(buttonDownPin, LOW, CLICKBTN_PULLUP);
ClickButton buttonUp(buttonUpPin, LOW, CLICKBTN_PULLUP);

int buttonModeClicks = 0;
int buttonDownClicks = 0;
int buttonUpClicks = 0;

void setup() {
//  pinMode(R1, OUTPUT);
//  digitalWrite(R1, LOW);
  display1.begin(); // This function calls Adafruit_NeoPixel begin();

  pinMode(buttonModePin, INPUT_PULLUP);
  pinMode(buttonDownPin, INPUT_PULLUP);
  pinMode(buttonUpPin, INPUT_PULLUP);

  buttonMode.debounceTime = 20;
  buttonMode.multiclickTime = 250;
  buttonMode.longClickTime = 1000;

  buttonDown.debounceTime = 20;
  buttonDown.multiclickTime = 250;
  buttonDown.longClickTime = 1000;

  buttonUp.debounceTime = 20;
  buttonUp.multiclickTime = 250;
  buttonUp.longClickTime = 1000;

// Set initial count to zero, this code goes away when we start using EPROM and it's set
  display1.updateDigit(1, 0, 255, 0, 0);
  display1.updateDigit(2, 0, 255, 0, 0);

}

void loop() {
  
  buttonMode.Update();
  buttonDown.Update();
  buttonUp.Update();

// count up
  if(buttonDown.clicks != 0) buttonDownClicks = buttonDown.clicks;
  if (buttonDownClicks == 1) {
	if (count) count--;
  }

// count down
  if(buttonUp.clicks != 0) buttonUpClicks = buttonUp.clicks;
  if (buttonUpClicks == 1) {
        // add code here to stop at 99
	count++;
  }

// reset to zero
  if(buttonMode.clicks != 0) buttonModeClicks = buttonMode.clicks;
  if(buttonMode.clicks == -1) count = 0;
		
	
// write the current count
  display1.updateDigit(1, count % 10, 255, 0, 0);
  display1.updateDigit(2, (count / 10) % 10, 255, 0, 0);
  display1.show();

// reset the buttons
  buttonDownClicks = 0;
  buttonUpClicks = 0;
  buttonModeClicks = 0;

}
