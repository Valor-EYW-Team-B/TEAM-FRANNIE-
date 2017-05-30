#include <EYW.h>
#include <Wire.h>
#include <Servo.h>



EYW::Altimeter myaltimeter;
EYW::RangeFinder proximity;
int distance = 0;
EYW::Camera Sebastian;
float current_height = 0;
bool altimeterheight= false;

void setup() {

Serial.begin(9600);
proximity.begin();
proximity.alarm(6, 500, 1000);
proximity.calibrate(10);



Sebastian.begin();
Sebastian.calibrate();
Sebastian.alarm(1,800,1000);
Sebastian.beginTimer(1000);



Serial.begin(9600);
myaltimeter.begin();
myaltimeter.calibrate(100);
myaltimeter.alarm(3, 200, 2000);



}


void loop() {
  current_height = myaltimeter.getHeightAvg (30);
  
Serial.print("Current Height:");
Serial.println(current_height);



if (current_height > 3) {
  myaltimeter.alarm(2, 1500, 4000);
}



if (current_height >= 40 && current_height <= 50) {
  altimeterheight= true;
}


if (current_height >= 30 && altimeterheight==true && current_height <= 40) {
  Sebastian.getPicture();
  Sebastian.beginTimer(3000);
}


if (current_height < 2) {
  proximity.getDistance();
  Serial.print("Current Distance:");
  Serial.println(distance);
}

if (distance < 500){
  proximity.alarm(10, 100, 500);
  delay(300);
}


}
