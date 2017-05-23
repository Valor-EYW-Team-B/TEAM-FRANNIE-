// test from Jerry
#include <EYW.h>
#include <Servo.h>
#include <Wire.h>

EYW::Altimeter myaltimeter;
EYW::RangeFinder proximity;
int distance = 0;
EYW::Camera Sebastian;
float current_height = 0;


void setup() {

Serial.begin(9600);
proximity.begin();
proximity.alarm();
proximity.calibrate(10);



Sebastian.begin();
Sebastian.calibrate();
Sebastian.alarm(1,800,500);
Sebastian.beginTimer(1000);



Serial.begin(9600);
myaltimeter.begin();
myaltimeter.calibrate(100);
myaltimeter.alarm();

}


void loop() {
  current_height = myaltimeter.getHeightAvg (30);
  
  if (Sebastian.timerExpired()==true && current_height >= 3)
  {
    Sebastian.getPicture();
    Sebastian.beginTimer(1000);
  }

    distance = proximity.getDistance();
    Serial.print("Current Distance:");
    Serial.println(distance);



if (distance <200) {
  proximity.alarm(6 ,2000,100);
  }



current_height = myaltimeter.getHeightAvg(20);
Serial.print("Current Height:");
Serial.println(current_height);



if (current_height>3)
  {
    myaltimeter.alarm(6,2000,500);
  }
}
