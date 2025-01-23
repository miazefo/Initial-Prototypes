#include <MPR121.h>
#include <Wire.h>

#define numElectrodes 12
int val = 0;
int sensorValue = 0;

void setup() {
  Serial.begin( 9600 );
  Wire.begin();

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
  if ( MPR121.getTouchData( 8 ) ) {
    Serial.println( " - Touching 8" );
  } else {
    Serial.println( " - Not Touching" );
  }

   if ( MPR121.getTouchData( 2 ) ) {
    Serial.println( " - Touching 2" );
  } else {
    Serial.println( " - Not Touching" );
  }
}