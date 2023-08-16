#include <Servo.h>
Servo s;

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define WIRE Wire
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &WIRE);

int trig = 2;
int echo = 3;
void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Connecting to SSID\n'adafruit':");
  display.print("connected!");
  display.println("IP: 10.0.1.23");
  display.println("Sending val #0");
  display.setCursor(0,0);
  display.display(); // actually display all of the above


  pinMode(4, OUTPUT);
  s.attach(5);
  pinMode(trig,OUTPUT);  pinMode(echo,INPUT);}

void loop() {
  Serial.println(distance());
  if(distance() <= 15){
    Show("Open");
    s.write(0);
    delay(3000);
    }
  s.write(90);
  Show("Close");

  delay(100);
  yield();
  display.display();
  }

int distance(){
  digitalWrite(trig,1); delay(10);
  digitalWrite(trig,0);
  int time = pulseIn(echo,1);
  int dis = (time/2)/28.97;
  return dis;}

void Show(String i){
  display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(30,10);
  display.print(i);
  display.setCursor(0,0);
  display.display(); // actually display all of the above
}