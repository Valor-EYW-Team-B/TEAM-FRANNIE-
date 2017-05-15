#include <EYW.h>
#include <Servo.h>
#include <Wire.h>

EYW::Camera Sebastian; //because I can

int butt=2;
int led=4;
int speak=5;

void setup() {
Sebastian.begin(butt,led,speak);
Sebastian.calibrate();
Sebastian.alarm(1,800,500); //high frequency to make it noticeable
Sebastian.beginTimer(3000); //allows time for descent
}

void loop() {
if (Sebastian.timerExpired()==true||Sebastian.buttonPressed()==true)
{
  Sebastian.getPicture(1,1); //take maximum amount of pictures within the general time frame
  Sebastian.beginTimer(500); //allow a small pause between takes
}
}
