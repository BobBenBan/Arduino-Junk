int delayval = 0;
int delaypause = 100;
//double speedmax = 0.3;
//double speedmin = 0.1;
double acceln = 1.005;
double accelo = 0.05;
double accel = accelo;
//double speedad = 127/(speedmax-speedmin);
double colorside = 255.00;
int rgbprevious[3] = {};
int rgbnext[3] = {255, 255, 255};

int pins[3] = {6,9,10};
//*
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 8
#define NUMPIXELS 1
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//*/
void setup() {
  /*
    while(!//Serial)
    //Serial.begin(9600);//*/
  randomSeed(analogRead(0));
  for(int i = 0;i<3;i++)pinMode(pins[i],OUTPUT);
  //pixels.begin();
  //pixels.setBrightness(63);
}
void loop() {
  setrgb(rgbprevious, rgbnext, colorside);
  colorside += accel;
  if (colorside < 127)accel *= acceln; else accel /= acceln;
  //Serial.print(colorside);
  //Serial.print(' ');
  //Serial.println(accel);
  if (colorside >= 255) {
    digitalWrite(7, HIGH);
    colorside = 0.00;
    for (int i = 0; i < 3; i++)rgbprevious[i] = rgbnext[i];
    for (int i = 0; i < 3; i++)rgbnext[i] = random(255);
    delay(delaypause);
    accel = accelo;
  }
  else digitalWrite(7, LOW);
  delay(delayval);
  //*/
}
void setrgb(int prgb[], int nrgb[], double sides) {
  int rgba[3] = {};
  double lsides = sides / 255.00;
  int ttt = 0;
  for (int i = 0; i < 3; i++) {
    double temp = (prgb[i] * (1 - lsides)) + (nrgb[i] * lsides);
    rgba[i] = temp;
    //Serial.println(rgba[i]);
    //ttt += o;
  }
  int r = rgba[0];
  int g = rgba[1];
  int b = rgba[2];
  //*for (int i = 0; i < NUMPIXELS; i++) {
    //pixels.setPixelColor(i, pixels.Color(r, g, b));
  //}
  pixels.show();//*/
  
  //Serial.println(ttt);
  //Serial.println();
}

