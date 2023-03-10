void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float a=123.321;
  byte b[4];
  byte *c;
  c=(byte*)&a;
  for(int i=0;i<4;i++)
  {
    b[i]=*c;
    c++;
  }
  float m=1157.342;
  m=*((float*)b);
  Serial.println(m);
}
