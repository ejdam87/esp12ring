#include "led_ring.hpp"
#include "animations.hpp"


volatile bool change = false;
volatile int program = 0;

// Create a NeoPixel object
Adafruit_NeoPixel strip(NUM_PIXELS, LR_PIN, NEO_GRB + NEO_KHZ800);

ICACHE_RAM_ATTR void change_color()
{
  change = true;
}

void setup() {
    Serial.begin(9600); // serial communication for debugging

    pinMode(JS, INPUT_PULLUP); // pullup not to let the pin floating
    attachInterrupt(digitalPinToInterrupt(JS), change_color, FALLING); // handle button click

    // Initialize the NeoPixel strip
    strip.begin();
    strip.show();  // Initialize all pixels to 'off'
}

void loop()
{

  if (change)
  {
    change = false;
    program = (program + 1) % NUM_PROGRAMS;
  }

  if (program == 0)
  {
    transition();
  }
  else if (program == 1)
  {
    random_fade();
  }
  else if (program == 2)
  {
    running_dot();
  }
  else
  {
    rainbow_cycle();
  }
}
