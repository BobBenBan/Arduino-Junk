#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

#define PIN 17
#define builtInRing
#ifdef builtInRing
Adafruit_NeoPixel ring = Adafruit_NeoPixel(10, 17);
#else
Adafruit_NeoPixel ring = Adafruit_NeoPixel(12, PIN);
#endif
uint8_t const trailmin = 1;
uint8_t const trailmax = 140;
uint8_t const trailstp = trailmax/15;
uint8_t const trailhlt = 20;
void sp(uint8_t p, uint32_t c) {
#ifdef builtInRing
  if (p == 5 || p == 11)return;
  if (p > 5)p--;
#endif
  ring.setPixelColor(p, c);
}
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
int16_t trail[12];
void showPix(uint8_t pix) {
  uint8_t prevpix = 0;
#ifdef builtInRing
  if (pix == 5)
    pix = (rpix > 5) ? 6 : 4;
  else if (pix == 11)
    pix = (rpix > 11) ? 0 : 10;
#endif
  uint8_t h = (pix / 3) * 3;
  for (uint8_t i = 0; i < 3; i++) {
    if (trail[h + i] < trailhlt) trail[h + i] = trailhlt;
  }
  trail[pix] = trailmax;
  for (uint8_t i = 0; i < 12; i++) {
    sp(i, wheel(i, trail[i])) ;
    if (trail[i] > trailmin) trail[i] -= trailstp;
    if (trail[i] < trailmin) trail[i] = trailmin;
  }
  ring.show();
}
void setup() {
  CircuitPlayground.begin();
  ring.begin();
  /*/
    Serial.begin(9600);
    while (!Serial);//*/
  memset(&trail, trailmin, 12);
}
void loop() {
  uint8_t pix = accelPix();
  showPix(pix);
  delay(10);
}

