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
String name= Serial.readString();
Serial.println(name);

//100 milliseconds
if(name=="1\n"){
LEDBlink();
}

if(name.equals("2\n")){
LEDBlink();
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
