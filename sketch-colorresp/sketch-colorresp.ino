#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>  // not used in this demo but required!


Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();
#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 16
long s[3] = {0, 0, 0};
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, 6, NEO_GRB + NEO_KHZ800);
void setupSensor()
{
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);

  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);

  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
}
void setup()
{
  Serial.begin(500000);
  if (!lsm.begin())
  {
    while (1);
  }
  for (int i = 0; i < 20; i ++) {
    lsm.read();
    s[0] += (long)lsm.accelData.x;
    s[1] += (long)lsm.accelData.y;
    s[2] += (long)lsm.accelData.z;
    delay(50);
  }
  for (int i = 0; i < 3; i ++) {
    s[i] /= 20;
    Serial.println(s[i]);
  }
  pixels.begin();
}
void loop()
{
  lsm.read();
  for(int i = 0; i < 16 ; i +=3)
  pixels.setPixelColor(i, pixels.Color((int)(abs(((double)lsm.accelData.x) - s[0]) / 50000 * 255) , 0, 0));
  for(int i = 1; i < 16 ; i +=3)
  pixels.setPixelColor(i, pixels.Color(0, (int)(abs(((double)lsm.accelData.y) - s[1]) / 50000 * 255) , 0));
  for(int i = 2; i < 16 ; i +=3)
  pixels.setPixelColor(i, pixels.Color(0, 0, (int)(abs(((double)lsm.accelData.z) - s[2]) / 50000 * 255)));
  pixels.show();
  delay(50);

}
