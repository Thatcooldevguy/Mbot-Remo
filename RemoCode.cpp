// RemoTV Controler for mbot
// Code used: Dan's handler,mblock init things
// compiled and published by sticks
// helpers: H2020,Dan,Brooke
// ver 1.0.0-beta
//for firmware: latest


// start
// Created by mblock START

#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);
void move(int direction, int speed) {
  int leftSpeed = 0;
  int rightSpeed = 0;
  if(direction == 1) {
    leftSpeed = speed;
    rightSpeed = speed;
  } else if(direction == 2) {
    leftSpeed = -speed;
    rightSpeed = -speed;
  } else if(direction == 3) {
    leftSpeed = -speed;
    rightSpeed = speed;
  } else if(direction == 4) {
    leftSpeed = speed;
    rightSpeed = -speed;
  }
  motor_9.run((9) == M1 ? -(leftSpeed) : (leftSpeed));
  motor_10.run((10) == M1 ? -(rightSpeed) : (rightSpeed));
}

//delay code (some wired thing)
//void _delay(float seconds) {
//  long endTime = millis() + seconds * 1000;
//  while(millis() < endTime) _loop();
//}

// this is motor moves 1,f 2,b 3,r 4,l
// num = sec delay, so code before _delay 1 is forward
//  move(1, 50 / 100.0 * 255);
//  _delay(1);
//  move(1, 0);
//  move(2, 50 / 100.0 * 255);
//  _delay(2);
//  move(2, 0);
//  move(4, 50 / 100.0 * 255);
//  _delay(3);
//  move(4, 0);
//  move(3, 50 / 100.0 * 255);
//  _delay(4);
//  move(3, 0);


// created by mblock STOP

//custom code (by dan) START
String inData;

void STOP() {
  motor_9.run(0);
  motor_10.run(0);

}

void setup(){
  Serial.begin(9600);
}

void loop()
{
   while (Serial.available() > 0)
    {

    char recieved = Serial.read();
    inData += recieved;

    switch (recieved) {
      case 'f':
         move(1, 100 / 100.0 * 255);
         delay(500);
         STOP();
       break;

       case 'b':
         move(1, 0);
         move(2, 100 / 100.0 * 255);
         delay(500);
         STOP();

       break;

       case 'r':
         move(4, 0);
         move(4, 100 / 100.0 * 255);
         delay(500);
         STOP();
       break;

       case 'l':
         move(2, 0);
         move(3, 100 / 100.0 * 255);
         delay(500);
         STOP();
       break;
     default:
       delay(1);
    }
    inData = "";
  }
}
//custom code (by dan) END

//end 
