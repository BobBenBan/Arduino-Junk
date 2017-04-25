#include <PixelSimulator.h>
PixelSimulator a(4,true,5);
void setup() {
  // put your setup code here, to run once:
  a.begin();
  a.setPixelColor(2,254,170,0);
  a.show();
  a.delayT(1000);
  a.setPixelColor(3,255,255,0);
  a.show();
}

void loop() {
  // put your main code here, to run repeatedly:
}
