#include <EYW.h>
#include <Servo.h>
#include <Wire.h>

EYW::Altimeter myaltimeter;
EYW::RangeFinder proximity;
int distance = 0;
EYW::Camera Sebastian; //because I can
float current_height=0;


void setup() {

Serial.begin(9600);
proximity.begin();
proximity.alarm();
proximity.calibrate(10);



Sebastian.begin();
Sebastian.calibrate();
Sebastian.alarm(1,800,500);
Sebastian.beginTimer(1000); //allows time for descent



Serial.begin(9600);
myaltimeter.begin();
myaltimeter.calibrate(100);
myaltimeter.alarm();

}


void loop() {
  current_height = myaltimeter.getHeightAvg (10);
  
  if (Sebastian.timerExpired()==true && current_height >= 4)
  {
    Sebastian.getPicture(); //take maximum amount of pictures within the general time frame
    Sebastian.beginTimer(5000); //allow a small pause between takes
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



if (current_height>1)
  {
    myaltimeter.alarm(6,2000,500);
  }
}

