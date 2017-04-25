#include <Adafruit_CircuitPlayground.h>
#define cp CircuitPlayground
uint8_t const trailmin = 1;
uint8_t const trailmax = 10;
void sp(uint8_t p, uint8_t r, uint8_t g, uint8_t b) {
  cp.setPixelColor(p, r,g,b);
}
uint8_t accelPix() {
  float rpix = 8 - atan2(cp.motionX(), cp.motionY()) / 3.141592654 * 6;
  if (rpix >= 12)rpix -= 12;
  uint8_t pix = round(rpix) % 12;
  if (pix == 5)
    pix = (rpix > 5) ? 5 : 4;
  else if (pix == 11)
    pix = (rpix > 11) ? 0 : 9;
  else if (pix > 5)pix--;
  return pix;
}
void showWheel(uint8_t p, uint8_t t) {
  uint8_t c[] = {2, 3, 4, 5, 6, 8, 9, 10, 11, 0};
  int l = c[p];
  if (l < 3) {
    sp(p, 85 * l * t / trailmax, 255 * t / trailmax, 0); return;
  }
  l -= 3;
  if (l < 3) {
    sp(p, (255 - 85 * l) * t / trailmax, (255 - 85 * l) * t / trailmax, 85 * l * t / trailmax); return;
  }
  l -= 3;
  if (l < 3) {
    sp(p, 85 * l * t / trailmax, 0, (255 - 85 * l) * t / trailmax); return;
  }
  l -= 3;
  sp(p, (255 - 85 * l) * t / trailmax, 85 * l * t / trailmax, 0);
}
uint8_t trail[10];
void showPix() {
  for (uint8_t i = 0; i < 10; i++) {
    showWheel(i, trail[i]);
    if (trail[i] > trailmin)trail[i]--;
  }
}
uint8_t prevpix = 0;
void setup() {
  cp.begin();
  Serial.begin(9600);
  while (!Serial);
  memset(&trail, trailmin, 10);
}
void loop() {
  uint8_t pix = accelPix();
  trail[pix] = trailmax;
  prevpix = pix;
  showPix();
  delay(10);
}

