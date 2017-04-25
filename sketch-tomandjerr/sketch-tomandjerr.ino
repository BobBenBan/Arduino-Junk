#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 6
#define NUMPIXELS 16
#define COLNUM 3
int behind = 2;
Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  ring.begin();
  ring.show();
}

void loop() {
  uint32_t tom = ring.Color(127, 64, 64);
  uint32_t jer = ring.Color(64,64,127);
  for (int i = 0; i < NUMPIXELS; i++) {
    int nexti = (i + 2) % NUMPIXELS;
    ring.setPixelColor(i, tom);
    ring.setPixelColor(nexti, jer);
    ring.show();
    delay(100);
    ring.setPixelColor(nexti, 0);
    ring.setPixelColor(i, 0);
  }
}
