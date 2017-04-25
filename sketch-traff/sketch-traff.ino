#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS,PIN,NEO_GRB + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  pixels.setBrightness(64);
}
void setall(uint32_t c){
  for(int i = 0; i < NUMPIXELS; i++) pixels.setPixelColor(i,c);
  pixels.show();
}
void loop() {
  // put your main code here, to run repeatedly:
  setall(pixels.Color(0,255,0));
  delay(7000);
  setall(pixels.Color(255,255,0));
  delay(2000);
  setall(pixels.Color(255,0,0));
  delay(6000);
}
