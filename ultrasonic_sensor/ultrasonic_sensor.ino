#include <NewPing.h>
#define TRIGGER_PIN 5
#define ECHO_PIN 4
#define MAX_DISTANCE 100


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  
Serial.println("Ping: ");
Serial.println(sonar.ping_cm());
Serial.println("cm");
delay(50);
}
