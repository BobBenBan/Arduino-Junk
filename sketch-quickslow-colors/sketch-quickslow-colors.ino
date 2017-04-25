int delmax = 300;
int delmin = 3;
double chigh = 1.05;
double clow = 0.98;
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
double d = clow;
double del = delmax;
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
  del = del * d;
   if(del < delmin) {
      d = chigh;
   }
   if(del > delmax) {
      d = clow;
  }
}
