void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("dog");
  Bean.setLed(100,100,0);
  Bean.sleep(1000);
}
