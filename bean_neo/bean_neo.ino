#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16,5,NEO_GRB + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
  pixels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  pixels.setPixelColor(15,255,0,0);
  pixels.show();
  Bean.sleep(100);
  pixels.setPixelColor(15,255,0,0);
  pixels.show();
  Bean.sleep(100);
}
