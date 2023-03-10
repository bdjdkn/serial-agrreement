#define head0 0x7d
#define head1 0x00
#define head2 0x7d 
#define tail0 0x7f
#define tail1 0x00
#define tail2 0x7f
#define head_right  3
#define head_wrong  2
#define head_place_wrong 1
#define datalength_right 1
#define datalength_wrong 0
#define dataown_right 1
#define dataown_right 0
#define tail_right  3
#define tail_wrong  2
//#define tail_place_wrong 1
#define checkbit_right 1
#define checkbit_wrong 0
struct datapack
{
  byte head[3];
  byte datalength;
  byte dataown[255];
  byte checkbit;
  byte tail[3];
};
//struct can not move.if move must test address
datapack d1;
byte current_byte;
byte *hand;
int head_flag;
int tail_flag;
int datalength_flag;
int dataown_flag;
int dataown_count;
int checkbit_flag;
int count=0;
datapack data_init()
{
  for(int i=0;i<3;i++)
  {
    d1.head[i]=0x00;
    d1.tail[i]=0x00;
  }
  d1.datalength=0x00;
  d1.checkbit=0x00;
  for(int i=0;i<255;i++)
  {
    d1.dataown[i]=0x00;
  }
  current_byte=0x00;
  hand=&d1.head[0];
  head_flag=0;
  datalength_flag=0;
  dataown_flag=0;
  tail_flag=0;
  dataown_count=0;
  checkbit_flag=0;
}
int all_init()
{
  data_init();
  while(Serial.read()!=-1)
  {}
  
}
int judge_head()
{
  if(hand==&d1.head[2])
  {
    if(d1.head[0]==head0&&d1.head[1]==head1&&d1.head[2]==head2)
    {
      return head_right;
    }
    else return head_wrong;
  }
  else return head_place_wrong;
}
int judge_tail()
{
  if(*hand==tail2&&*(hand-1)==tail1&&*(hand-2)==tail0)
  {
    return tail_right;
  }
  else return tail_wrong;
/*
  if(hand==&d1.tail[2])
  {
    if(d1.tail[0]==tail0&&d1.tail[1]==tail1&&d1.tail[2]==tail2)
    {
      return tail_right;
    }
    else return tail_wrong;
  }
  else return tail_place_wrong;
*/
}
int check_data_correct()
{
  //if(int(d1.datalength)==//how to check dataown numb is right)  
}
int head_wrong_deal()
{

}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
 // Serial1.begin(115200);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  String com="";
  while(1)
  {
    if(Serial.available()>0)
    {
       com=char(Serial.read());
       if(com=="O")
        {
            Serial.print("K");
             digitalWrite(11,HIGH);
            break;
        }
    }
   
  }
  Serial1.println("n");
}



void loop() {
  // put your main code here, to run repeatedly:
  
  data_init();
  
  while(1)
  {
    while(Serial.available()==0)//wait read
    {}    
    current_byte=Serial.read();
    *hand=current_byte;
    head_flag=judge_head();
    tail_flag=judge_tail();
    
//    if(checkbit_flag==checkbit_right)
//    {
//      
//    }
    if(count==500)
    {
      digitalWrite(12,HIGH);
      Serial1.println("m");
    }
    if(tail_flag==tail_right)
    {
      digitalWrite(10,HIGH);
      count++;
      break;
    }
    if(dataown_flag==dataown_right)
    {
      dataown_count++;
    }
    if(dataown_count==int(d1.datalength))
    {
      hand=&d1.dataown[254];
      checkbit_flag=checkbit_right;      
    }
    if(datalength_flag==datalength_right)
    {
      dataown_flag=dataown_right;
    }
    if(head_flag==head_wrong)
    {
      head_wrong_deal();
    }
    if(head_flag==head_right)
    {
      datalength_flag=datalength_right;
    }
    else datalength_flag=datalength_wrong;//if head has error,how to deal with
    hand++;
//    if(current_byte==head1)
//    {
//      d1.head[0]=current_byte;
//      cuurent_byte=Serial.read();
//      if(current_byte==head2)
//      {
//        d1.head[1]=current_byte;
//        cuurent_byte=Serial.read();
//        if(current_byte==head3)
//        {
//         d1.head[2]=current_byte;
//        }
//      }
//    }
  }
//  if(check_data_correct()==)
   /* 
   Serial1.begin(115200);  
   for(int i=0;i<int(d1.datalength);i++)
   {
    Serial1.println(int(d1.dataown[i]));
   }
   Serial1.end();
   */
}
