//changable variables
int delayOn = 0;
int pauseMax = 50;
int pauseMin = 25;
int changeResolution = 600;
//to be changed :
double speedMax = 5.0;
double speedMin = 2.5;
//----------------
int pixelBrightness = 1;
//these will be divided by 10, issues with random();
int speedFactorMax = 30;
int speedFactorMin = 10;
//stuff to do with printing.
int printSpace = 7;
//neopixel setups
/*
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 6
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
*/
#define NUMPIXELS 30
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "C:\Users\Benjamin\Documents\Arduino\C++S\PlatformRunPixelSimulator.h"
//a number to assist with smooth flowing stuffs
PixelSimulator pixels(NUMPIXELS,false,5000);
double speedNum = changeResolution / 2 / (speedMax - speedMin);
int pixNumC = 0;
int spaces = 6;
void calSpaces(int num) {
  while (num >= 10) {
    num /= 10;
    spaces--;
  }
}
int random(int min, int max){
	return rand() % (max-min+1)+min;
}
int random(int Max){
	return rand() % Max;
}
//fun with classes? <this took tutorials!
class aPixel {
    //member variables
    int nowColor[3];
    int toColor[3];
    double change;
    double speedFactor;
    bool paused;
    int pauseTime;
    int pixelNumber;
  public:
    //setbeginning values
    void beginVal() {
      //random colors
      for (int i = 0; i < 3; i++) {
        nowColor[i] = random(256);
        toColor[i] = random(256);
      }
      //random otherstuffs
      change = random(changeResolution);
      speedFactor = (double)random(speedFactorMin, speedFactorMax) / 10;
      pauseTime = random(pauseMin, pauseMax);
      paused = (bool)random(0, 2);
      pixelNumber = pixNumC;
      pixNumC++;
    }
    //updates values
    int chVal() {
      //Serial.print(pixelNumber);
      //Serial.print(':');
      if (paused) {
        //if paused: do math an
        //Serial.print("paused ");
        //Serial.print(pauseTime);
        /*SERIALS*///spaces -= 2;
        /*SERIALS*///calSpaces(pauseTime);
        pauseTime -= 1;
        if (pauseTime <= 0)
          paused = false;
      }
      else {
        setColor();
        change += speedFactor * (speedMax - (abs(change - 127) / speedNum));
        if (change > changeResolution) next();
      }
    }
    //private:
    void setColor() {
      int rgba[3] = {};
      double changeNum = (double)change / changeResolution;
      //math to find things
      for (int i = 0; i < 3; i++) {
        rgba[i] = (nowColor[i] * (1 - changeNum)) + toColor[i] * changeNum + 0.5;
        /*SERIALS*///int temp = rgba[i];
        //Serial.print(temp);
        //Serial.print(' ');
        /*SERIALS*///calSpaces(temp);
      }
      pixels.setPixelColor(pixelNumber, rgba[0], rgba[1], rgba[2]);
    }
    void next() {
      for (int i = 0; i < 3; i++)nowColor[i] = toColor[i];
      for (int i = 0; i < 3; i++)toColor[i] = random(256);
      change = 0;
      speedFactor = (double)random(speedFactorMin, speedFactorMax) / 10;
      paused = true;
      pauseTime = random(pauseMin, pauseMax);
    }
};
aPixel data[NUMPIXELS];
void setup() {
  /*SERIALS*///while (!Serial) //Serial.begin(9600);
  pixels.begin();
  pixels.setBrightness(pixelBrightness);
  for (int i = 0; i < NUMPIXELS; i++) data[i].beginVal();
}
void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < NUMPIXELS; i++) {
    spaces = printSpace;
    data[i].chVal();
    /*SERIALS*///for (int i = 0; i < spaces; i++)//Serial.print(' ');
  }
  //Serial.println();
  pixels.show();
  pixels.delayT(10);
}
int main(){
	setup();
	while (true) loop();
	return 0;
}
