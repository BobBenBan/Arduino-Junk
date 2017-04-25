#include <Adafruit_NeoPixel.h> //include library

#ifdef __AVR__
#include <avr/power.h>  //make gemma work
#endif

#define PIN 1 //Neopixels are on Pin 1

#define NUMPIXELS 16 //16 Neopixels

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //initialize pixels

uint32_t Wheel(byte WheelPos) { //when given number fron 0-255, gives colors that are a rainbow
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void rainbowWipes(int delayVal, int times) {
  for (int i = 0; i < NUMPIXELS * times; i++) { //will loop for every pixel, "times" times
    pixels.setPixelColor(i % NUMPIXELS /* which pixel */, Wheel(255.0 / (NUMPIXELS * times) * i)); // this is the position in the wheel, that determines the color
    pixels.show(); //show on ring
    delay(delayVal); // delay
  }
}
void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  pixels.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  rainbowWipes(50,5);
}
