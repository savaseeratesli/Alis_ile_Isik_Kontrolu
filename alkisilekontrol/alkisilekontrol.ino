#include <Arduino.h>

int rolePin=4;
int soundPin=A0;
bool roleDurum=false;

void setup() 
{
  pinMode(rolePin,OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  int value=analogRead(soundPin);

  Serial.println(value);
  //Her alkış yaptığımızda çalışması için geçmesi
  //gereken değer
  if(value>90)
  {
    if(roleDurum==false)//İlk akış yak
    {
      roleDurum=true;
      digitalWrite(rolePin,HIGH);
      delay(3000);
    }
    
    else//İkinci alkış kapat
    {
      roleDurum=false;
      digitalWrite(rolePin,LOW);
      delay(3000);   
    }
  }
  
}
