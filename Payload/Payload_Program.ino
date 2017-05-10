#include <EYW.h>
#include <Servo.h>
#include <Wire.h>

EYW::Camera Sebastian;

int butt=2;
int led=4;
int speak=5;

void setup() {
Sebastian.begin(butt,led,speak);
Sebastian.calibrate();
Sebastian.alarm(1,267,500);
Sebastian.beginTimer(3000);

}

void loop() {
if (Sebastian.timerExpired()==true||Sebastian.buttonPressed()==true)
{
  Sebastian.getPicture();
  Sebastian.beginTimer(5000);
}
}
