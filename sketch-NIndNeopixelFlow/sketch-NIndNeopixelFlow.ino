//neopixel setups
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 17
#define NUMPIXELS 12

//changable variables
int delayOn = 0;
int pauseMax = 70;
int pauseMin = 20;
int changeResolution = 300;
float sigmoidBounds = 5;
//to be changed :
float speedMax = 4.0;
float speedMin = 2.0;
//----------------
int pixelBrightness = 64;
//these will be divided by 10, issues with random();
int speedFactorMax = 30;
int speedFactorMin = 10;


float sigmoid(float changeVal) {
  float v = -(2 * changeVal / changeResolution - 1) * sigmoidBounds;
  return 1 / (1 + exp(v));
}

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//a number to assist with smooth flowing stuffs
//fun with classes
class aPixel {
    //member variables
    int nowColor[3];
    int toColor[3];
    float change;
    float speedFactor;
    bool paused;
    int pauseTime;
  public:
    //set beginning values
    aPixel() {
      //random colors
      for (int i = 0; i < 3; i++) {
        nowColor[i] = random(256);
        toColor[i] = random(256);
      }
      //random otherstuffs
      change = random(changeResolution);
      speedFactor = (float)random(speedFactorMin, speedFactorMax) / 10;
      pauseTime = random(pauseMin, pauseMax);
      paused = (bool)random(0, 2);
    }
    //updates values
    int chVal(int pixNum) {
       setColor(pixNum);
      //Serial.print(pixelNumber);
      //Serial.print(':');
      if (paused) {
        //if paused: do mat
        //Serial.print("paused ");
        //Serial.print(pauseTime);
        /*SERIALS*///spaces -= 2;
        /*SERIALS*///calSpaces(pauseTime);
        pauseTime -= 1;
        if (pauseTime <= 0)
          paused = false;
      }
      else {
        change += speedFactor;
        if (change > changeResolution) next();
      }
    }
    //private:
    void setColor(int pixNum) {
      int rgba[3] = {};
      float changeNum = sigmoid(change);
      //math to find things
      for (int i = 0; i < 3; i++) {
        rgba[i] = (nowColor[i] * (1 - changeNum)) + toColor[i] * changeNum + 0.5f;
        /*SERIALS*///int temp = rgba[i];
        //Serial.print(temp);
        //Serial.print(' ');
        /*SERIALS*///calSpaces(temp);
      }
      pixels.setPixelColor(pixNum, rgba[0], rgba[1], rgba[2]);
    }
    void next() {
      for (int i = 0; i < 3; i++) {
        nowColor[i] = toColor[i];
        toColor[i] = random(256);
      }
      change = 0;
      speedFactor = (float)random(speedFactorMin, speedFactorMax) / 10;
      paused = true;
      pauseTime = random(pauseMin, pauseMax);
    }
};
aPixel data[NUMPIXELS];
aPixel* pixel[NUMPIXELS];
void setup() {
  /*SERIALS*///while (!Serial) //Serial.begin(9600);
  pixels.begin();
  pixels.setBrightness(pixelBrightness);
  randomSeed(analogRead(0));
  for (int i = 0; i < NUMPIXELS; i++) {
    data[i] = aPixel();
    pixel[i] = &data[i];
    //pixel[i] = &data[0];
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < NUMPIXELS; i++) {
    //spaces = printSpace;
    pixel[i]->chVal(i);
    /*SERIALS*///for (int i = 0; i < spaces; i++)//Serial.print(' ');
  }
  //Serial.println();
  pixels.show();
  delay(delayOn);
}
