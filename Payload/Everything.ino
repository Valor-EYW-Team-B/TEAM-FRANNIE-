#include <EYW.h>
#include <Servo.h>
#include <Wire.h>

EYW::Altimeter myaltimeter;
EYW::RangeFinder proximity;
int distance = 0;
EYW::Camera CServo; //because I can
float current_height=0;


void setup() {
  
Serial.begin(9600);
proximity.begin();
proximity.alarm();
proximity.calibrate(10);}



CServo.begin();
CServo.calibrate();
CServo.alarm(); 
CServo.beginTimer(10000); //allows time for descent



Serial.begin(9600);
myaltimeter.begin();
myaltimeter.calibrate(100);
myaltimeter.alarm();

}


void loop() {
  current_height = myaltimeter. getHeightAvg (20);
  if (CServo.timerExpired()==true && current_height >= 4)
  
    distance = proximity.getDistance();  
    Serial.print("Current Distance:");
    Serial.println(distance);


  
if (distance <200) {
  proximity.alarm(2,2000,100);
  }



CServo.getPicture(); //take maximum amount of pictures within the general time frame
CServo.beginTimer(500); //allow a small pause between takes


current_height = myaltimeter.getHeightAvg(20);
Serial.print("Current Height: ");
Serial.println(current_height);



if (current_height>1)
  {
    myaltimeter.alarm(6,2000,500);
  }
}
