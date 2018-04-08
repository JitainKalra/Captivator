#include <NewPing.h>

#include <NewPing.h>

int trig1=2;
int echo1=3;
int trig2=5;
int echo2=6;
int maxd=200;

NewPing sonar1(trig1,echo1,maxd);
NewPing sonar2(trig2,echo2,maxd);

int uS,dist1,dist2;

String s1="LAT:28.5349@LON:77.0558/";
String s2="LAT:28.6570@LON:77.1115/";

void setup() {
Serial.begin(9600);
}

unsigned char flag,flag2=0;

void loop() {
uS=sonar1.ping();
dist1=uS/US_ROUNDTRIP_CM;

uS=sonar2.ping();
dist2=uS/US_ROUNDTRIP_CM;


if(dist1==0)
    dist1=200;
if(dist2==0)
    dist2=200;



if(dist1>=16&&dist1<24 && flag!=1)
   {
    
    delay(3000);
    uS=sonar1.ping();
    dist1=uS/US_ROUNDTRIP_CM;
    if(dist1>=16&&dist1<24 && flag!=1)
    {
      Serial.println("A#25!Ais25%");
      Serial.println(s1); flag=1;  
       
    }
   }

if(dist1>=9&&dist1<16 && flag!=2)
   {
    
    delay(3000);
    uS=sonar1.ping();
    dist1=uS/US_ROUNDTRIP_CM;
    if(dist1>=9&&dist1<16 && flag!=2)
    {
      Serial.println("A#50!Ais50%");
      Serial.println(s1);
      flag=2;  
      
    }
   }


if(dist1>=2&&dist1<9 && flag!=3)
   { 
    
    delay(3000);
    uS=sonar1.ping();
    dist1=uS/US_ROUNDTRIP_CM;
    if(dist1>=2&&dist1<9 && flag!=3)
    {
      Serial.println("A#75!Ais75%");
      Serial.println(s1);
      flag=3;
    }
    
   }








if(dist2>=16&&dist2<24 && flag2!=1)
   {
    Serial.println("B#25!Bis25%");
    delay(3000);
    uS=sonar2.ping();
    dist2=uS/US_ROUNDTRIP_CM;
    if(dist2>=16&&dist2<24 && flag2!=1)
    {
      Serial.println("B#25!Bis25%");
      Serial.println(s2); flag2=1;  
       
    }
   }

if(dist2>=9&&dist2<16 && flag2!=2)
   {
    
    delay(3000);
    uS=sonar2.ping();
    dist2=uS/US_ROUNDTRIP_CM;
    if(dist2>=9&&dist2<16 && flag2!=2)
    {
      Serial.println("B#50!Bis50%");
      Serial.println(s2);
      flag2=2;  
      
    }
   }


if(dist2>=2&&dist2<9 && flag2!=3)
   { 
    
    delay(3000);
    uS=sonar2.ping();
    dist2=uS/US_ROUNDTRIP_CM;
    if(dist2>=2&&dist2<9 && flag2!=3)
    {
      Serial.println("B#75!Bis75%");
      Serial.println(s2);
      flag2=3;
    }
    
   }

delay(200);
}
