/* Seven Segment Pixel library example code: counting
Counts from 0 up the null character and back down using random colors on
a whole display.
created 2017
by Peter Hartmann
This example code is in the public domain.
<https://blog.hartmanncomputer.com>
*/

#include <neopixel.h>
#include <Seven_Segment_Pixel.h>

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

int delayval = 500; // delay for half a second

int increment = 1;

int count = 0;

int R1 = D1;
int S1 = A0;
int val = 0;

void setup() {
  pinMode(R1, OUTPUT);
  digitalWrite(R1, LOW);
  pinMode(S1, INPUT_PULLUP);
  display1.begin(); // This function calls Adafruit_NeoPixel begin();
}

void loop() {
  
  val = digitalRead(S1);
  digitalWrite(R1, val);

  display1.updateDigit(1, count % 10, 255, 0, 0);
  display1.updateDigit(2, (count / 10) % 10, 255, 0, 0);
  display1.show();
  count = count + increment;

  if (count == 0 || count == 100) {
    increment = -increment;
  }

  delay(delayval);
}
