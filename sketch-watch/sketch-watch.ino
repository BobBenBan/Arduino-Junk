#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 16
#define FiveSeconds 5000
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
uint8_t rTime[3] = {7, 57, 8};
uint8_t sTime[3] = {0, 0, 0};
uint8_t dv[3] = {255, 127, 255};
uint8_t ord[3] = {0, 1, 2};
uint8_t c = 0;
long selfT = 0;
void changeCh(int n){
  if(n == 3) return;
  changeComp(sTime[n],ord[n],0);
  sTime[n] = (sTime[n]+11)%12;
  changeComp(sTime[n],ord[n],dv[ord[n]]);
  if(sTime[n] == 11)changeCh(n+1);
}
void changeComp(int n, uint8_t comp, uint8_t v) {
  uint32_t col = pixels.getPixelColor(n);
  void *p = &col;
  ((uint8_t*)p)[comp] = v;
  pixels.setPixelColor(n,col);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  Serial.println("hey");
  pixels.setBrightness(64);
  pixels.begin();
  selfT = millis();
  showTime();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - selfT >= FiveSeconds) {
    changeCh(0);
  selfT += second;
  }
}


