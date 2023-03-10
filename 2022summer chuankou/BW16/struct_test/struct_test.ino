struct datapack
{
  byte head[3];
  byte datalength;
  byte dataown[255];
  byte checkbit;
  byte tail[3];
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  datapack d1;
  Serial.println(sizeof(d1));
  datapack *d;
  d=&d1;
  Serial.print("d的地址 ");
  Serial.println(int(d));
  byte *dd;
  dd=&d1.dataown[254];
   Serial.print("dataown的地址 ");
  Serial.println(int(dd));
  dd=&d1.checkbit;
   Serial.print("checkbit的地址 ");
  Serial.println(int(dd));
  dd=&d1.tail[0];
  Serial.print("tail0的地址 ");
  Serial.println(int(dd));
  dd=dd+1;
  Serial.print("d+1的地址 ");
  Serial.println(int(dd));
}
