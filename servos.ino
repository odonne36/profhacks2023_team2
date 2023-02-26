/**
***************************************
Code adapted from:

Dejan Nedelkovski,
www.HowToMechatronics.com

            &

https://docs.arduino.cc/learn/electronics/servo-motors


***************************************
**/


//NOTE: place arm to right of user
#include <Servo.h>
int dist;
double time;

Servo servobase;
Servo servoarm;
//Servo servorotate;
Servo spoontilt;

void setup() {
  // put your setup code here, to run once:
  servobase.attach(3);
  servobase.write(45); // 0 is to right if standing behind arm

  servoarm.attach(5);
  servoarm.write(90); //180 is pointing up

  //servorotate.attach(6);
  //servorotate.write(0);

  spoontilt.attach(9);
  spoontilt.write(100); // 0 is facing toward ground


Serial.begin(9600);
pinMode(7,OUTPUT);  //Trig
pinMode(8,INPUT);   //Echo
}

void loop() {




  // put your main code here, to run repeatedly:

for (int i =90; i < 20; i--) {
  servoarm.write(i);  // Go down to bowl level
  delay(50);
}
  delay(2000);
  for (int j =100; j < 45; j--) {
  spoontilt.write(j); //Tilt spoon down
  //servorotate.write(i);  //Turn spoon back
  delay(70);
  }
  delay(2000);

   for (int k =45;k <60;k++) {
     servobase.write(k);  //Scoop
     delay(50);
   }
   delay(250);


  for (int m =45;m <90;m++) {
  //servorotate.write(m);  // Turn spoon back upright
  spoontilt.write(m);    //Tilt spoon up
  delay(50);
  }
  delay(2000);

for (int z = 100; z < 20; z--) {
servoarm.write(z);  // Raise arm until in range of face
delay(100);
}


  delay(2000);
  for (int n = 60; n < 90;n++) {
  servobase.write(n); //Move spoon to mouth and wait for 7s
  delay(70);
  }
  delay(7000);  


  //Reset all to inital position and start again
  
  servobase.write(45);
  servoarm.write(90);
  spoontilt.write(80);
  //servorotate.write(0);
  delay(2000);
}
