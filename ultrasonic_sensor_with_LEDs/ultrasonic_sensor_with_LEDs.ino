#include <NewPing.h>
#define TRIGGER_PIN 5
#define ECHO_PIN 4
#define MAX_DISTANCE 50

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// int led = 11;
// int newLed = 10;
// int newNewLed = 9;
// int newNewNewLed = 8;
int led = 0;
int newLed = 0;
int newNewLed = 0;
int newNewNewLed = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode (11, OUTPUT);
pinMode (10, OUTPUT);
pinMode (9,OUTPUT);
pinMode (8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Ping: ");
Serial.println(sonar.ping_cm());
Serial.println("cm");
delay(50);

if(sonar.ping_cm()==50){
  digitalWrite(11,HIGH);
}else{ digitalWrite(11,LOW);
}
if(sonar.ping_cm()==40){
digitalWrite(10,HIGH);
}else{ digitalWrite(10,LOW);
}
if(sonar.ping_cm()==30){
  digitalWrite(9,HIGH);
}else{ digitalWrite(9,LOW);
}
if(sonar.ping_cm()==20){
  digitalWrite(8,HIGH);
}else{ digitalWrite(8,LOW);
}

}
