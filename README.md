# two-digits

## A Particle project named two-digits

This the software to control a two digit device created by using NeoPixels to create two seven segment displays. It also uses three buttons, an
up, down, and mode button.

Currently all it does is let you "keep score." That's the only mode. It boots at zero and the up button moves the counter up one, the down
button goes down.  Holding the Mode button for one second resets to zero.

Ultimately, short presses of the mode button will cycle through the various modes. The intention is for there to be many modes:

- counter
- show current time in hours
- show current time minutes
- show current time seconds
- and maybe some kind of countdown timer

The hardware this runs on is the Particle Photon, though other Particle devices should work and it should be relatively easy to 
also make this work on an Arduino. It uses the clickButton library for the buttons and the NeoPixel library for the dots. 

Here's what my device looks like:

![Image of Front](https://github.com/djb-rh/two-digits/tree/main/images/front.jpg)
