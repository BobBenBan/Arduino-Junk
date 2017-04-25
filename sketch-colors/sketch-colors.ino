int del = 300;
int delof = 0;
int pins[] = {6,9,10,7};
int a = 8;
int s = 4;
byte colors[8][4] = {
  {LOW,LOW,LOW,LOW},
  {HIGH,LOW,LOW,HIGH},
  {LOW,HIGH,LOW,LOW},
  {LOW,LOW,HIGH,HIGH},
  {HIGH,HIGH,LOW,LOW},
  {LOW,HIGH,HIGH,HIGH},
  {HIGH,LOW,HIGH,LOW},
  {HIGH,HIGH,HIGH,HIGH},
};

int ind = 0;
void setup() {
int i;
for(i = 0; i < s; i= i+1)pinMode(pins[i],OUTPUT);
}
void loop() {
  ind = ind + 1;
  if (ind == a) ind = 0;
  int i;
  for(i = 0; i < s; i = i+1) digitalWrite(pins[i],colors[ind][i]);
  delay(del);
  for(i = 0; i < s; i = i+1) digitalWrite(pins[i],LOW);
  delay(delof);
  del = del * 0.995;
  if(del < 1) del = 300;
}
