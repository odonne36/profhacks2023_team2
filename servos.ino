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


void setup() {
  // put your setup code here, to run once:
  servobase.attach(3);
  servobase.write(90);

  servoarm.attach(5);
  servoarm.write(90);

  servorotate.attach(6);
  servorotate.write(90);

Serial.begin(9600);
pinMode(7,OUTPUT);  //Trig
pinMode(8,INPUT);   //Echo
}

void loop() {




  // put your main code here, to run repeatedly:

  servoarm.write(120);  // Go down to bowl level
  delay(2000);
  servorotate.write(45);  //Turn spoon back
  delay(2000);
  servorotate.write(5);  // Turn spoon back upright
  delay(2000);

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
  servobase.write(60);
  delay(7000);  //Move spoon to mouth and wait for 7s


  //Reset all to inital position and start again
  servobase.write(5);
  servoarm.write(5);
  servorotate.write(5);
  delay(5000);
}
