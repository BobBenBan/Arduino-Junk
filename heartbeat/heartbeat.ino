int LED = 11;

float LEDbrightness = 0;
bool brightnessUp = true;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (brightnessUp) {
    LEDbrightness += 0.2;
    analogWrite(LED, round(LEDbrightness));
    if (LEDbrightness >= 100)  {

      brightnessUp = false;

    }
  }
  else {
    LEDbrightness -= 0.2;
    analogWrite(LED, round(LEDbrightness));
    if (LEDbrightness <= 1) {

      brightnessUp = true;
    }

  }

  delayMicroseconds(2000);
}
