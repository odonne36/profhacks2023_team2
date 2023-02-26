/**
Code adapted from:

Dejan Nedelkovski,
www.HowToMechatronics.com

            &

https://docs.arduino.cc/learn/electronics/servo-motors

**/

#include <Servo.h>
int dist;
double time;

Servo servobase;
Servo servoarm;
Servo servorotate;
Servo spoontilt;

void setup() {
  // put your setup code here, to run once:
  servobase.attach(3);
  servobase.write(0);

  servoarm.attach(5);
  servoarm.write(0);

  servorotate.attach(6);
  servorotate.write(0);

  spoontilt.attach(9);
  spoontilt.write(0);


Serial.begin(9600);
pinMode(7,OUTPUT);  //Trig
pinMode(8,INPUT);   //Echo
}

void loop() {




  // put your main code here, to run repeatedly:

for (int i =0; i < 120; i++) {
  servoarm.write(i);  // Go down to bowl level
  delay(10);
}
  delay(2000);
  for (int i =0; i < 45; i++) {
  spoontilt.write(i); //Tilt spoon down
  servorotate.write(i);  //Turn spoon back
  delay(10);
  }
  delay(2000);
  for (int i =0;i <90;i++) {
  servorotate.write(i);  // Turn spoon back upright
  spoontilt.write(i);    //Tilt spoon up
  delay(10);
  }
  delay(2000);

//Polling ultrasonic sensor
digitalWrite(7,LOW);
delayMicroseconds(2);
digitalWrite(7,HIGH);
delayMicroseconds(10);
time = pulseIn(8,HIGH);

dist = time * 0.0133 / 2; //Inches
int x=120;
while (dist > 6 & x > 50) {
  x -= 5;
servoarm.write(x);  // Raise arm until in range of face
delay(500);

digitalWrite(7,LOW);
delayMicroseconds(2);
digitalWrite(7,HIGH);
delayMicroseconds(10);
time = pulseIn(8,HIGH);

dist = time * 0.0133 / 2; //Inches
}
  delay(2000);
  for (int i = 0; i < 60;i++) {
  servobase.write(i); //Move spoon to mouth and wait for 7s
  delay(15);
  }
  delay(7000);  


  //Reset all to inital position and start again
  
  servobase.write(5);
  servoarm.write(5);
  servorotate.write(5);
  delay(5000);
}
