void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  long long n = millis();
    Serial.println(analogRead(0));
}
