//changable variables
int delayOn = 0;
int delayPauseMax = 500;
int delayPauseMin = 0;
int changeResolution = 300;
double speedMax = 0.2;
double speedMin = 0.1;
int pixelBrightness = 64;
//these divided by 10
double speedFactorMax = 30;
double speedFactorMin = 10;
//neopixel setups
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 6
#define NUMPIXELS 16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//a number to assist with smooth flowing stuffs
double speedNum = changeResolution / 2 / (speedMax - speedMin);
//where all the data about the colro is stored:
double pixelsData[NUMPIXELS][9] = {};
//some funtions:
//sets on 1 pixel
void setrgb(double data[], double pixelNum) {
  //array to store some values
  int rgba[3] = {};
  int speedAt = data[6]/changeResolution;
  //for all the rgb components
  for (int i = 0; i < 3; i++) {
    //math
    rgba[i] = (data[i] * (1 - speedAt)) + (data[i+3] * speedAt) + 0.5;
    //Serial.println(rgba[i]);
  }
  pixels.setPixelColor(pixelNum,rgba[0],rgba[1],rgba[2]);
}
void setup() {
  //Serial
  /*
  while(!Serial) Serial.begin(9600);//*/
  //random seed, analogRead(0) creates weird values different every time
  randomSeed(analogRead(0));
  //initial values for data
  for (int i = 0; i < NUMPIXELS; i++) {
    for (int j = 0; j < 6; j++) pixelsData[i][j] = random(256);
    pixelsData[i][6] = random(changeResolution);
    pixelsData[i][7] = random(speedFactorMin,speedFactorMax);
    pixelsData[i][8] = 0;
  }
  pixels.begin();
  pixels.setBrightness(pixelBrightness);
}

void loop() {
  for (int i = 0; i < NUMPIXELS; i++) {
    setrgb(pixelsData[i],i);
    pixelsData[i][7] += pixelsData[i][8]*(speedMax-(abs(pixelsData[i][7]-127)/speedNum));
    if(pixelsData[i][7] >= changeResolution){
      for(int j = 0; j < 3; i++) pixelsData[i][j] = pixelsData[i][j+3];
      for(int j = 3; j < 6; i++) pixelsData[i][j] = random(256);
      pixelsData[i][6] = 0;
      pixelsData[i][8] = random(delayPauseMin,delayPauseMax);
    }
  }
}
