#include <EYW.h>
#include <Wire.h>
#include <Servo.h>



EYW::Altimeter myaltimeter;
EYW::RangeFinder myRangeFinder;

EYW::Camera PServo;
float current_height = 0;

int distance = 0;

void setup() {

Serial.begin(9600);

myaltimeter.begin();
myaltimeter.calibrate(200);
myaltimeter.alarm(1, 200, 2000);


myRangeFinder.begin();
myRangeFinder.alarm(2, 1000, 1000);
myRangeFinder.calibrate(10);


PServo.begin();
PServo.calibrate();
PServo.alarm(1,800,1000);
PServo.motor.write(60);
}

void loop () {

current_height = myaltimeter.getHeightAvg (30); 
Serial.print("Current Height:");
Serial.println(current_height);


  distance = myRangeFinder.getDistance();
  Serial.print("Current Distance:");
  Serial.println(distance);


  
  if (distance < 50){
  myRangeFinder.alarm(4, 100, 500);
 
}

  PServo.motor.write(60);
  delay(2000);
  PServo.motor.write(0);
  delay(500);
  PServo.motor.write(60);



}
