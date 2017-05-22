#include <EYW.h>

EYW::RangeFinder proximity;
int distance = 0;





void setup() {
  Serial.begin(9600);
proximity.begin();
proximity.alarm();
proximity.calibrate(10);

}

void loop() {
  distance = proximity.getDistance();
  Serial.print("Current Distance:");
  Serial.println(distance);


  if (distance <200) {
    proximity.alarm(2,2000,100);
  }

}
