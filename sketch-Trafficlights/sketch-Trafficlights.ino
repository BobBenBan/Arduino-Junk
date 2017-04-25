void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(6,HIGH);
}
void loop() {
  //green
  delay(random(10000,15000));
  //red
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  delay(random(10000,15000));
  //yellow
  analogWrite(9,120);
  digitalWrite(6,HIGH);
  delay(3000);
  digitalWrite(9,LOW);
}
