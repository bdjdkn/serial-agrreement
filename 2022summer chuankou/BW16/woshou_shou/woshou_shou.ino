void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  String com="";
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  while(1)
  {
    if(Serial.available()>0)
    {
       com=char(Serial.read());
       if(com=="O")
        {
            Serial.print("K");
             digitalWrite(11,LOW);
            break;
        }
    }
   
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
