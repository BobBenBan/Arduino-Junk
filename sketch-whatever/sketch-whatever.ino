int pins[] = {6,9,10};
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i<3;i++)pinMode(pins[i],OUTPUT);
  randomSeed(107);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<3;i++)analogWrite(pins[i],random(255));
  delay(100);
}
