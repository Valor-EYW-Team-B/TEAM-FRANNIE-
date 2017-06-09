#include <EYW.h>



EYW::Altimeter myaltimeter;
EYW::RangeFinder myRangeFinder;
<<<<<<< HEAD:Actual Drop/Picture_every_2_seconds_and_alarm/Picture_every_2_seconds_and_alarm.ino

=======
>>>>>>> origin/master:Everything/RampEverythingTest/RampEverythingTest.ino
EYW::Camera PServo;

float current_height = 0;
<<<<<<< HEAD:Actual Drop/Picture_every_2_seconds_and_alarm/Picture_every_2_seconds_and_alarm.ino

=======
bool altimeterheight= false;
>>>>>>> origin/master:Everything/RampEverythingTest/RampEverythingTest.ino
int distance = 0;

void setup() {

Serial.begin(9600);

myaltimeter.alarm(3, 700, 150);
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


<<<<<<< HEAD:Actual Drop/Picture_every_2_seconds_and_alarm/Picture_every_2_seconds_and_alarm.ino
  distance = myRangeFinder.getDistance();
  Serial.print("Current Distance:");
  Serial.println(distance);


  
  if (distance < 50){
  myRangeFinder.alarm(4, 100, 500);
 
=======

if (current_height > 1) {
  myaltimeter.alarm(2, 1500, 4000);
}



if (current_height >= 1 && current_height <= 3) {
  altimeterheight= true;
>>>>>>> origin/master:Everything/RampEverythingTest/RampEverythingTest.ino
}

  PServo.motor.write(60);
  delay(2000);
  PServo.motor.write(0);
  delay(500);
  PServo.motor.write(60);

<<<<<<< HEAD:Actual Drop/Picture_every_2_seconds_and_alarm/Picture_every_2_seconds_and_alarm.ino


}

=======
if (current_height > 1 && altimeterheight==true && current_height > 2.5) {
  PServo.getPicture();
  PServo.beginTimer(3000);
}


if (current_height < 1) {
  distance = myRangeFinder.getDistance();
  Serial.print("Current Distance:");
  Serial.println(distance);
}

if (distance < 20){
  myRangeFinder.alarm(3, 300, 200);
 
}
>>>>>>> origin/master:Everything/RampEverythingTest/RampEverythingTest.ino

