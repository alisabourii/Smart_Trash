#include <Servo.h>
Servo s;
int trig = 2;
int echo = 3;
void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  s.attach(5);
  pinMode(trig,OUTPUT);  pinMode(echo,INPUT);}

void loop() {
  Serial.println(distance());
  if(distance() <= 15){
    digitalWrite(4,1); s.write(0); delay(3000);}
  s.write(90);
  digitalWrite(4,0);}

int distance(){
  digitalWrite(trig,1); delay(10);
  digitalWrite(trig,0);
  int time = pulseIn(echo,1);
  int dis = (time/2)/28.97;
  return dis;}