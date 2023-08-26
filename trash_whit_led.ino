#include <Servo.h>

Servo s;

int echo = 5;
int trig = 6;

int LED = 3;

void setup() {
  Serial.begin(9600);
  s.attach(2);
  pinMode(LED, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

}

void loop() {
  s.write(90);
  digitalWrite(LED, 0);

   Serial.println(distance());
   if(distance() < 15){
      digitalWrite(LED,1);
      s.write(0);
      delay(4000);
      }
}

int distance(){
  digitalWrite(trig,1);delay(10);
  digitalWrite(trig,0);

  int time = pulseIn(echo,1);
  int dis = (time/2)/27.98;
  return dis;
}

