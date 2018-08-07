#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 1000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip.begin();
  strip.show(); // Initialize all pixels to ‘off’
}

void loop() {
  int r = 255;
  int g = 96;
  int b = 5;
  for(int x = 0; x <4; x++)
  {
    int flicker = random(0,60);
    int r1 = r-flicker;
    int g1 = g-flicker;
    int b1 = b-flicker;
    if(g1<0) g1=0;
    if(r1<0) r1=0;
    if(b1<0) b1=0;
    strip.setPixelColor(x,r1,g1, b1);
  }
  strip.show();
  delay(random(50,150));
}
