struct datapack
{
  byte head[3];
  byte datalength;
  byte dataown[255];
  byte checkbit;
  byte tail[3];
}
void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);digitalWrite(10,HIGH);
  String com="";
  Serial.begin(115200);
  while(Serial.available()<1)
  {
    Serial.print("O");
    delay(1);
  }
  com+=char(Serial.read());
  delay(2);
  if(com=="K")
  {
    digitalWrite(10,LOW);
  }
} 
void loop() {
  // put your main code here, to run repeatedly:

}
