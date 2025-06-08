#pragma once

#include <Adafruit_NeoPixel.h>

// --- LED ring pin(s)
#define LR_PIN D2         // Define the pin connected to the NeoPixel data line
// ---

// --- Joystick pin(s)
#define JS D3
// ---

#define NUM_PIXELS 24     // Number of pixels in the NeoPixel ring
#define NUM_PROGRAMS 4    // Number of animation programs

extern Adafruit_NeoPixel strip;
extern volatile bool change;
