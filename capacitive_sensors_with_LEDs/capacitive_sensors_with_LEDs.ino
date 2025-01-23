#include <CapacitiveSensor.h>
#include <MPR121.h>
#include <Wire.h>

#define numElectrodes 12
// int val = 0;
// int sensorValue = 0;
int led = 8;
int newLed = 9;
int newNewLed = 10;
int newNewNewLed = 11;

void setup() {
  Serial.begin( 9600 );
  Wire.begin();
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  pinMode (11,OUTPUT);

  // Setup MPR121
  MPR121.begin( 0x5A );
  MPR121.setInterruptPin( 4 );
  MPR121.setTouchThreshold( 40 );
  MPR121.setReleaseThreshold( 20 );
}

void loop() {
  // Check for new data
  MPR121.updateTouchData();
  MPR121.updateFilteredData();
 //sensorValue = (MPR121.getTouchData(electrode));
 
  // Get an analog proximity value
  //Serial.println( MPR121.getFilteredData( 1 ) );

  // Get a touched/not touched value
  if ( MPR121.getTouchData( 2 ) ) {
    Serial.println( " - Touching 2" );
    digitalWrite(10,HIGH);
   // digitalWrite(8,LOW);
  } else {
    Serial.println( " - Not Touching 2" );
    digitalWrite(10,LOW);
   // digitalWrite(8,HIGH);
  }

   if ( MPR121.getTouchData( 6 ) ) {
    Serial.println( " - Touching 6" );
    digitalWrite(9,HIGH);
    //digitalWrite(8,LOW);
  } else {
    Serial.println( " - Not Touching 6" );
    digitalWrite(9,LOW);
    //digitalWrite(8,HIGH);
  }

  if ( MPR121.getTouchData( 8 ) ) {
    Serial.println( " - Touching 8" );
    digitalWrite(8,HIGH);
  } else {
    Serial.println( " - Not Touching 8" );
    digitalWrite(8,LOW);
  }

  if ( MPR121.getTouchData( 11 ) ) {
    Serial.println( " - Touching 11" );
    digitalWrite(11,HIGH);
   // digitalWrite(8,LOW);
  } else {
    Serial.println( " - Not Touching 11" );
    digitalWrite(11,LOW);
    //digitalWrite(8,HIGH);
  }
  delay(100);
}