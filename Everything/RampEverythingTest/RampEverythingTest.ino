#include <EYW.h>



EYW::Altimeter myaltimeter;
EYW::RangeFinder myRangeFinder;
EYW::Camera PServo;

float current_height = 0;
bool altimeterheight= false;
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

}


void loop() {
  current_height = myaltimeter.getHeightAvg (30);
  
Serial.print("Current Height:");
Serial.println(current_height);



if (current_height > 1) {
  myaltimeter.alarm(2, 1500, 4000);
}



if (current_height >= 1 && current_height <= 3) {
  altimeterheight= true;
}


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


}
