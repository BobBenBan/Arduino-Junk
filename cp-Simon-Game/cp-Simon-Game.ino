#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

#define PIN 17
#define builtInRing
#ifdef builtInRing
Adafruit_NeoPixel ring = Adafruit_NeoPixel(10, 17);
#else
Adafruit_NeoPixel ring = Adafruit_NeoPixel(12, PIN);
#endif
uint8_t const lMin = 1;
uint8_t const lSel = 160;
uint8_t const lDim = lSel / 15;
uint8_t const lSec = 50;
uint8_t const lFls = 255;
//x10ms
int const wPly = 8;
int const wShow = 30;
int const wBtn = 50;
int const wWro = 10;
int const freq[4] = {440,550,660,783};
float const freqMult = 1.33;
void sp(uint8_t p, uint32_t c) {
#ifdef builtInRing
  if (p == 5 || p == 11)return;
  if (p > 5)p--;
#endif
  ring.setPixelColor(p, c);
}
//lights managment
float rpix;
uint8_t accelPix() {
  rpix = 8 - atan2(CircuitPlayground.motionX(), CircuitPlayground.motionY()) / 3.141592654 * 6;
  if (rpix > 12)rpix -= 12;
  return round(rpix) % 12;
}
uint32_t wheel(uint8_t p, uint8_t t) {
  uint8_t v = 255 * t;
  if (p < 3) return ring.Color(t, 0, 0);
  if (p < 6) return ring.Color(0, 0, t);
  if (p < 9) return ring.Color(0, t, 0);
  return ring.Color(t, t, 0);
}
int16_t lit[12];
void sec(uint8_t s, uint8_t b) {
  s *= 3;
  for (uint8_t i = 0; i < 3; i++) {
    if (lit[s + i] < b) lit[s + i] = b;
  }
}
void showPix() {
  for (uint8_t i = 0; i < 12; i++) {
    sp(i, wheel(i, lit[i])) ;
    if (lit[i] > lMin) lit[i] -= lDim;
    if (lit[i] < lMin) lit[i] = lMin;
  }
  ring.show();
}
//game parts
uint8_t prev[255];
uint8_t len = 0;
uint8_t now = 0;
uint8_t cor = 0;
uint8_t stage = 0;
/* 0: Idle
   1: Play
   2: Show
   3: Player
   4: lose
*/
bool tap = false;
uint8_t wait = 0;
void goWait(int tim) {
  wait = tim;
}
void next() {
  prev[len] = random(4);
  len++;
  stage = 2;
  goWait(wBtn);
}
void sound(int htz){
  tone(5,htz,100);
}
void setup() {
  //*
  randomSeed(analogRead(A4));
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_2_G);
  ring.begin();
  /*/
    Serial.begin(9600);
    while (!Serial);//*/
  memset(&lit, lMin, 12);
}
void loop() {
  uint8_t pix = accelPix();
  if (wait) {
    wait--;
  }
  else switch (stage) {
      case 0:
        //sec(pix/3*3, lSec);
        lit[pix] = lSel;
        if (CircuitPlayground.leftButton() || CircuitPlayground.rightButton()) stage = 1;
        break;
        case 1: 
          sound(freq[(now%4)]*((now%8)<4?freqMult:1));
          sec(now%4,lFls);
          goWait(wPly);
          now++;
          if(now==16) {
            now = 0;
            next();
          }
        break;
      case 2:
        sec(prev[now], lFls);
        sound(freq[prev[now]]*freqMult);
        now++;
        if (now == len) {
          now = 0;
          stage = 3;
        }
        goWait(wShow);
        break;
      case 3:
        sec(pix / 3, lSec);

#ifdef builtInRing
        if (pix == 5)
          pix = (rpix > 5) ? 6 : 4;
        else if (pix == 11)
          pix = (rpix > 11) ? 0 : 10;
#endif
        lit[pix] = lSel;
        if (CircuitPlayground.leftButton() || CircuitPlayground.rightButton()) {
          if (!tap) {
            tap = true;
            if (pix / 3 == prev[now]) {
              sound(freq[prev[now]]);
              sec(prev[now], lFls);
              now++;
              if (now == len) {
                now = 0;
                goWait(wBtn);
                next();
              }
            } else {
              stage = 4;
              cor = now;
              now = 0;
              len = 0;
            }
          }
        } else tap = false;
        break;
      case 4:
        sec(prev[cor], lFls);
        sound(freq[prev[cor]]*2);
        now++;
        goWait(wWro);
        if (now == 5) {
          stage = 0;
          now = 0;
        }
        break;
        
    }
  showPix();
  delay(10);
}

