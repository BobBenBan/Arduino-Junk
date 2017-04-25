#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN 6
#define NUMPIXELS 16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 50;
void setup() {
  // put your setup code here, to run once:
  pixels.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
  int i = random(NUMPIXELS);
  pixels.setPixelColor(i, pixels.Color(random(100),random(100),random(100)));
  pixels.show();
  delay(delayval);
}
