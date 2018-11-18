
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
}
int i=0;
void loop() {
  // put your main code here, to run repeatedly:
  
  tone(5,i+=10,100);
  Serial.println(i);
  delay(100);
  while(Serial.available());
}
