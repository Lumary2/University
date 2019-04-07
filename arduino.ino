//addresses the ledPin of the Arduino
const int ledPin=13;
int delayPeriod=1000;

void setup() {
  //define how many bits per seconds are send
  Serial.begin(9600);
  //defines that we want to use the ledPin as an output
  pinMode(ledPin,OUTPUT);

}

void loop() {
Serial.println("how many times shall I blink?");
while(Serial.available()==0)  
  {  
      
  } 
String name= Serial.readString();
Serial.println(name);

for(int i=0;i<name.toInt();i++){
  LEDBlink();
}


}

void LEDBlink(){
  digitalWrite(ledPin,HIGH);
//light stays on for 100 millisec
delay(delayPeriod);
//turn led off
digitalWrite(ledPin,LOW);
delay(delayPeriod);
}

