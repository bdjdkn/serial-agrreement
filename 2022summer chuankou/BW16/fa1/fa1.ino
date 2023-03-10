struct datapacket
{
  byte head[3];
  byte datalength;
  byte dataown[255];
  byte checkbit;
  byte tail[3];
};
byte endpacket[254];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  //start shake hands
  while(1)//Query the status of the receiving end
  {
    Serial.print("O");
  //  Serial.flush();
    String com="";
    com=char(Serial.read());
    if(com=="K")
    {
      digitalWrite(12,HIGH);//red light on,Shake hands success
      break;
    } 
  }
}
datapacket UART_init(datapacket d1)
{
  while(Serial.read()!=-1)//empty RX cache
  {
  }
  d1.head[0]=0x7d;
  d1.head[1]=0x00;
  d1.head[2]=0x7d;
  d1.tail[0]=0x7f;
  d1.tail[1]=0x00;
  d1.tail[2]=0x7f;

  //test
  
  d1.datalength=8;
  byte m[8];
  for(int i=0;i<int(d1.datalength);i++)
  {
//    double s=sin(i);
//        m=byte(s);
      d1.dataown[i]=byte(i);
  }
  d1.checkbit=4;
  return d1;
}
int pack(datapacket d2)
{
  for(int i=0;i<d2.datalength;i++)
  {
    endpacket[i+4]=d2.dataown[i];    
  }
  endpacket[d2.datalength+5]=d2.tail[0];
  endpacket[d2.datalength+6]=d2.tail[1];
  endpacket[d2.datalength+7]=d2.tail[2];
  endpacket[0]=d2.head[0];
  endpacket[1]=d2.head[1];
  endpacket[2]=d2.head[2];
  endpacket[3]=d2.datalength;
  endpacket[d2.datalength+4]=d2.checkbit;
}
void loop() {
  // put your main code here, to run repeatedly:
  datapacket d1;
  d1=UART_init(d1);
  pack(d1);
//  Serial.availableForWrite();
  Serial.write(endpacket,d1.datalength+8);
  Serial.flush();

}
