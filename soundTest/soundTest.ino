uint16_t store[32];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  memset(store,0,sizeof(store));
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<32;i++)store[i] = analogRead(9);
  for(int i=0;i<32;i++) Serial.println(store[i]);
}
