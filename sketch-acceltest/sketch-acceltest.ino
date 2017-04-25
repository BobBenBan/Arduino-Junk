#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>  // not used in this demo but required!

// i2c
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();

// You can also use software SPI
//Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0(13, 12, 11, 10, 9);
// Or hardware SPI! In this case, only CS pins are passed in
//Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0(10, 9);

void setupSensor()
{
  // 1.) Set the accelerometer range
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_6G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_8G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_16G);

  // 2.) Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_8GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_12GAUSS);

  // 3.) Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_2000DPS);
}
long s[9] = {0,0,0,0,0,0,0,0,0};
void setup()
{
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif
  Serial.begin(250000);
  Serial.println("LSM raw read demo");

  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    while (1);
  }
  while (!Serial.available());

  for (int i = 0; i < 20; i ++) {
    lsm.read();
    s[0] += (long)lsm.accelData.x;
    s[1] += (long)lsm.accelData.y;
    s[2] += (long)lsm.accelData.z;
    s[3] += (long)lsm.magData.x;
    s[4] += (long)lsm.magData.y;
    s[5] += (long)lsm.magData.z;
    s[6] += (long)lsm.gyroData.x;
    s[7] += (long)lsm.gyroData.y;
    s[8] += (long)lsm.gyroData.z;
    delay(200);
  }
  for (int i = 0; i < 9; i ++){
    s[i] /= 20;
    Serial.println(s[i]);
  }
}
void loop()
{
  lsm.read();
  /*
  Serial.print("Accel X: "); Serial.print((int)lsm.accelData.x-s[0]); Serial.print(" ");
  Serial.print("Y: "); Serial.print((int)lsm.accelData.y-s[1]);       Serial.print(" ");
  Serial.print("Z: "); Serial.println((int)lsm.accelData.z-s[2]);     Serial.print(" ");
  Serial.print("Mag X: "); Serial.print((int)lsm.magData.x-s[3]);     Serial.print(" ");
  Serial.print("Y: "); Serial.print((int)lsm.magData.y-s[4]);         Serial.print(" ");
  Serial.print("Z: "); Serial.println((int)lsm.magData.z-s[5]);       Serial.print(" ");
  Serial.print("Gyro X: "); Serial.print((int)lsm.gyroData.x-s[6]);   Serial.print(" ");
  Serial.print("Y: "); Serial.print((int)lsm.gyroData.y-s[7]);        Serial.print(" ");
  Serial.print("Z: "); Serial.println((int)lsm.gyroData.z-s[8]);      Serial.println(" ");
  Serial.print("Temp: "); Serial.print((int)lsm.temperature);    Serial.println(" ");
  */
  Serial.println((int)lsm.accelData.z-s[2]);
  delay(200);
  
}
