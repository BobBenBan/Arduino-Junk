#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, 6, NEO_GRB + NEO_KHZ800);
void sparkle(Adafruit_NeoPixel pixels, uint8_t r,uint8_t g,uint8_t b, unsigned int unfrequency, unsigned long duration, unsigned int delays) {

  int16_t val[NUMPIXELS] = {};
  for (int i = 0; i < pixels.numPixels(); i++) val[i] = 256;
  long t = 0;
  while (t < duration) {
    for (int i = 0; i < pixels.numPixels(); i++) {
      if(val[i] == 256){
        if(random(0,unfrequency)== 0)
          val[i] = -255;
      } else {
        int temp = 255 - abs(++val[i]);
        pixels.setPixelColor(i,r*temp,g*temp,b*temp);
        delete &temp;
      }
    }
    delay(delays);
    t += delays;
  }
  delete &t;
  delete[] val;
}
void setup() {
  // put your setup code here, to run once:
  sparkle(pixels, 255, 170 ,0, 4, 5000, 20);
}

void loop() {
  // put your main code here, to run repeatedly:

}
