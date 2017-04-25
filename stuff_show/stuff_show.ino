#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_NeoPixel.h>
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, 6, NEO_GRB + NEO_KHZ800);
void setupSensor() {
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
}
sensor_t s[4] = {};
signed int[3][3]
int getv(int pixel, sensor_t& s, int num) {
  
}
void setup() {
  Serial.begin(9600);
  if (!lsm.begin()) Serial.print("uhh");
  pixels.begin();
  pixels.show();
}
void loop() {
  lsm.read();
  lsm.getSensor(&s[0],&s[1],&s[2],&s[3]);
  getv(2,s[0].acceleration);
  getv(7,s[1].magnetic);
  getv(12,s[2].gyro);
}

