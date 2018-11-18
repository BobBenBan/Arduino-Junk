uint16_t store[10000];
int t;
void setup() {
  
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
   t = micros();

  for (int i = 0; i < 10000; i++) //mimicing actual application, stores in array
    store[i] = analogRead(A0);
  t = micros()-t;
  Serial.print("Took ");
  Serial.print(t);
  Serial.println(" micros to take 10000 samples");
  Serial.print("or about ");
  Serial.print(10000000.0/t*1000);
  Serial.println(" htz");
  memset(store, 0, sizeof(store));
  delay(2000);
  
}
