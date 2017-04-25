#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 16
#define PIN 6
Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
uint8_t getComp(uint32_t color, uint8_t comp) {
  return ((uint8_t*)((void*)&color))[comp];
}

void setAll(uint32_t color) {
  for (int i = 0; i < ring.numPixels(); i++) ring.setPixelColor(i, color);
  ring.show();
}
void resetPixels() {
  setAll(0);
}

void loneRunner(uint32_t color, int delayTime = 100, uint8_t times = 1) {
  for (int j = 0; j < times; j++)for (int i = 0; i < ring.numPixels(); i++) {
      ring.setPixelColor(i, color);
      ring.show();
      delay(delayTime);
      ring.setPixelColor(i, 0);
    }
  resetPixels();
}
void wipe(uint32_t color, int delayTime = 50) {
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, color);
    ring.show();
    delay(delayTime);
  }
}
uint8_t grade(float v2, float v1, float v) {
  return floor(v1 * v + v2 * (1.0 - v));
}
uint32_t getGradient(uint32_t colors[], int sizes, uint8_t pos) {
  float num = pos / 255.0 * sizes;
  int gnum = floor(num);//bgr
  int nnum = (gnum + 1) % sizes;
  float anum = num - gnum;
  ////Serial.print(getComp(colors[gnum],2));
  ////Serial.print(' ');
  ////Serial.print(getComp(colors[nnum],2));
  ////Serial.print(' ');
  ////Serial.print(num);
  ////Serial.print(' ');
  ////Serial.println(grade(getComp(colors[gnum],2),getComp(colors[nnum],2),anum));
  return ring.Color(grade(getComp(colors[gnum], 2), getComp(colors[nnum], 2), anum),
                    grade(getComp(colors[gnum], 1), getComp(colors[nnum], 1), anum),
                    grade(getComp(colors[gnum], 0), getComp(colors[nnum], 0), anum));
}
void setGradient(uint32_t gradeint[], int num, int delayTime = 3000) {
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, getGradient(gradeint, num, 255 / ring.numPixels()*i));
  }
  ring.show();
  delay(delayTime);
  resetPixels();
}
void gradientRunner(uint32_t gradient[], int num, int delayTime = 100, int times = 1) {
  for (int j = 0; j < times; j++)for (int i = 0; i < ring.numPixels(); i++) {
      ring.setPixelColor(i, getGradient(gradient, num, 255 / ring.numPixels()*i));
      ring.show();
      delay(delayTime);
      ring.setPixelColor(i, 0);
    }
  resetPixels();
}
void gradientWipe(uint32_t gradient[], int num, int delayTime = 50) {
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, getGradient(gradient, num, 255 / ring.numPixels()*i));
    ring.show();
    delay(delayTime);
  }
}
void gradientFlow(uint32_t gradient[], int num, int delayTime = 20, int times = 255) {
  for (int i = 0; i < times; i++) {
    setAll(getGradient(gradient, num, 255 / times * i));
    delay(delayTime);
  }
}
void gradientRotate(uint32_t gradeint[], int num, int rep = 1, int delayTime = 20, int times = 255) {
  for (int k = 0; k < rep; k ++) {
    for (int i = 0; i < times; i ++) {
      for (int j = 0; j < ring.numPixels(); j++) {
        ring.setPixelColor(j, getGradient(gradeint, num, (int)(255 / ring.numPixels()*j + 255 - (255 / times * i)) % 255));

      }
      ring.show();
      delay(delayTime);
    }
  }
}
void setup() {
  ////Serial.begin(9600);
  //while(!Serial);
  ring.begin();
  ring.setBrightness(64);
}
uint32_t rainbow[3] = {
  ring.Color(255, 0, 0),
  ring.Color(0, 255, 0),
  ring.Color(0, 0, 255)
};
uint32_t poke[2] = {
  ring.Color(255, 255, 255),
  ring.Color(255, 0, 0)
};
uint32_t bl[2] = {
  ring.Color(220,220,255),
  ring.Color(50,50,255)
};
void loop() {
  /*loneRunner(ring.Color(255, 128, 64), 100, 3);
  wipe(ring.Color(255, 0, 0));
  wipe(ring.Color(0, 255, 0));
  wipe(ring.Color(255, 0, 128));
  gradientFlow(rainbow, 3);
  gradientRunner(rainbow, 3, 100, 3);
  for (int i = 0; i < 2; i ++) {
    gradientWipe(poke, 2);
    gradientWipe(rainbow, 3);
  }*/
  gradientFlow(bl,2,40,255);
  /*
  gradientRotate(rainbow, 3, 3, 0, 255);

  gradientRotate(poke, 2);
  */
}
