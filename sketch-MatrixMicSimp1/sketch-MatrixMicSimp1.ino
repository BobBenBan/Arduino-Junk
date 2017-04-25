#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel M = Adafruit_NeoPixel(256, 6, NEO_GRB + NEO_KHZ800);
uint8_t p[32] = {};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  M.begin();
  M.setBrightness(32);
  M.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 256; i++) {
    M.setPixelColor(i,0);
  }
  for (int i = 31; i > 0; i--) {
    p[i] = p[i - 1];
  }
  p[0] = round((float)analogRead(0) * 7.0 / 1023.0);
  for (int i = 0; i < 32; i++) {
    M.setPixelColor((i * 8 + (i % 2 == 1 ? 7 - p[i] : p[i])), 0, 0, 255);
  }
  M.show();
}
