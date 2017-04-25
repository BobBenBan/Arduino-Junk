#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 6
#define NUMPIXELS 16
#define colnum 3
int colors[colnum][3] = {
  {255,0,0},
  {0,255,0},
  {0,0,255}
};
int ind = 0;
Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  ring.begin();
  ring.setBrightness(32);
  ring.show();
}

void loop() {
  ind = (ind+1)%colnum;
  uint32_t runner = ring.Color(colors[ind][0],colors[ind][1],colors[ind][2]);
  for(int i=0;i<ring.numPixels();i++){
    ring.setPixelColor(i, runner);
    ring.show();
    delay(50);
  }

}
