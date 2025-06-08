#include "animations.hpp"

void transition()
{
  int led = 0;
  int channels[3] = {0, 0, 0};

  for (int i = 0; i < 10; i++)
  {
    int j = random(3);
    int op = random(2);

    for (; op == 0 ? channels[j] < 256 : channels[j] >= 0; op == 0 ? channels[j] += 5 : channels[j] -= 5)
    {
      if (change)
      {
        return;
      }
      strip.setPixelColor( led, strip.Color(channels[0], channels[1], channels[2]) );
      led = (led + 1) % NUM_PIXELS;
      strip.show();
      delay(20);
    }
    channels[j] = op == 0 ? 255 : 0;
  }
}

void random_fade()
{
  int r = random(256);
  int g = random(256);
  int b = random(256);

  while (r > 0 || g > 0 || b > 0)
  {
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++)
    {
      strip.setPixelColor( pixel, strip.Color(r, g, b) );
      if (change)
      {
        return;
      }
    }
    strip.show();
    delay(50);

    if (r > 0)
    {
      r--;
    }
    if (g > 0)
    {
      g--;
    }
    if (b > 0)
    {
      b--;
    }
  }
}

void running_dot()
{

  int channels[3] = {0, 0, 0};
  for (int i = 0; i < 3; i++)
  {
    channels[i] = random(256);
  }

  for (int i = 0; i < NUM_PIXELS; i++)
  {
    if (change)
    {
      return;
    }

    strip.setPixelColor( i, strip.Color(channels[0], channels[1], channels[2]) );
    strip.show();
    delay(100);
    strip.setPixelColor( i, strip.Color(0, 0, 0) );
    strip.show();
  }
}

// Rainbow effect
void rainbow_cycle() {
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < NUM_PIXELS; j++) {
      if (change)
      {
        return;
      }
      strip.setPixelColor(j, wheel((j + i) & 255));
    }
    strip.show();
    delay(50);
  }
}

uint32_t wheel(byte wheel_pos) {
  if (wheel_pos < 85) {
    return strip.Color(wheel_pos * 3, 255 - wheel_pos * 3, 0);
  } else if (wheel_pos < 170) {
    wheel_pos -= 85;
    return strip.Color(255 - wheel_pos * 3, 0, wheel_pos * 3);
  } else {
    wheel_pos -= 170;
    return strip.Color(0, wheel_pos * 3, 255 - wheel_pos * 3);
  }
}
