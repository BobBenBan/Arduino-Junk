int pins[] = {6,9,10};
void setup() {
  // put your setup code here, to run once:
  
  for(int i = 0; i < 4; i++)pinMode(pins[i],OUTPUT);
}
int aa[] = {255,30,60};
void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 3; i++)analogWrite(pins[i],aa[i]);
}
