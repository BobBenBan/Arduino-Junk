#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, 6, NEO_GRB + NEO_KHZ800);
void sparkleSimple(Adafruit_NeoPixel pixels, uint32_t color, int onDuration ,int unfrequency, long duration, int delays){
  int on[NUMPIXELS] = {};
  long been = 0;
  for(int i=0;i<NUMPIXELS;i++){
    on[i] = false;
    pixels.setPixelColor(i,0);
  }
  pixels.show();
  while (been < duration){
    for(int i=0;i<NUMPIXELS;i++){
      if(on[i] != 0){
        on[i]-= delays;;
        if(on[i] <= 0) {
          pixels.setPixelColor(i,0);
          on[i] = 0;
        }
      }
      else{
        if(random(0,unfrequency) == 0){
          on[i] = onDuration;
          pixels.setPixelColor(i,pixels.Color(random(0,255),random(0,255),random(0,255)));
        }
      }
    }
    delay(delays);
    pixels.show();
    been += delays;
    Serial.println(been);
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pixels.begin();
  pixels.setBrightness(64);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  sparkleSimple(pixels,pixels.Color(255,255,0),50,20,10000,10);
}
