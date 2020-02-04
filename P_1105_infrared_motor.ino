#include <SoftwareSerial.h>

int ls = 3;
int rs = 12;

int lm1 = 4;
int lm2 = 5;
int lm3 = 8;
int lm4 = 9;
int rm1 = 6;
int rm2 = 7;
int rm3 = 10;
int rm4 = 11;

int trig = 13;
int echo = A0;
//int piezo = 13;
int freq = 1000;

void setup() {
  for(int i = 3; i<=13; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  float duration, distance;
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);

  duration=pulseIn(echo, HIGH);
  distance=((float)(340*duration)/10000)/2;

  if(distance<=30){
    motor_control(0,0,0,0);
    motor_control2(0,0,0,0);
  }
  
   Serial.print("Duration: ");
  Serial.println(duration);
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
  if((digitalRead(ls)==HIGH)&&(digitalRead(rs)==HIGH)){
    motor_control(1,0,1,0);
    motor_control2(1,0,1,0);
    Serial.println("2");
  }
  if((digitalRead(ls)==LOW)&&(digitalRead(rs)==HIGH)){
    motor_control(0,1,1,0);
    motor_control2(0,1,1,0);
    Serial.println("3");
  }
  if((digitalRead(ls)==HIGH)&&(digitalRead(rs)==LOW)){
    motor_control(1,0,0,1);
    motor_control2(1,0,0,1);
    Serial.println("4");
  }
  if((digitalRead(ls)==LOW)&&(digitalRead(rs)==LOW)){
    motor_control(1,0,1,0);
    motor_control2(1,0,1,0);
    Serial.println("1");
  }
}
void motor_control(int j1, int j2, int j3, int j4){
  digitalWrite(lm1, j1);
  digitalWrite(lm2, j2);
  digitalWrite(rm1, j3);
  digitalWrite(rm2, j4);
}
void motor_control2(int k1, int k2, int k3, int k4){
  digitalWrite(lm3, k1);
  digitalWrite(lm4, k2);
  digitalWrite(rm3, k3);
  digitalWrite(rm4, k4);
}


