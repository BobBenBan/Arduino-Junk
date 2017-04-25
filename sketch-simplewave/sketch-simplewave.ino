void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<500;i++){
    Serial.println(analogRead(0));
  }
  Serial.println(1200);
  Serial.println(0);
}
