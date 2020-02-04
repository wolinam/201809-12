#include <SoftwareSerial.h>

int s1 = 2;
int s2 = 3;
int s3 = 13;

int lm1 = 4;
int lm2 = 5;
int lm3 = 8;
int lm4 = 9;
int rm1 = 6;
int rm2 = 7;
int rm3 = 10;
int rm4 = 11;

int trig = 12;
int echo = A5;
//int piezo = 13;
int freq = 1000;

void setup() {
  for(int i = 2; i<=13; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(A5,INPUT);
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
  delay(300);
  if((digitalRead(s1)==HIGH)||(digitalRead(s2)==HIGH)||(digitalRead(s3)==HIGH)){
    motor_control(1,0,1,0);
    motor_control2(1,0,1,0);
    Serial.println("STOP");
  }
  if((digitalRead(s1)==HIGH)&&(digitalRead(s2)==LOW)&&(digitalRead(s3)==LOW)){
    motor_control(1,0,0,1);
    motor_control2(1,0,0,1);
    Serial.println("LEFT");
  }
  if((digitalRead(s1)==LOW)&&(digitalRead(s2)==LOW)&&(digitalRead(s3)==HIGH)){
    motor_control(0,1,1,0);
    motor_control2(0,1,1,0);
    Serial.println("RIGHT");
  }
  if((digitalRead(s1)==HIGH)&&(digitalRead(s2)==LOW)&&(digitalRead(s3)==HIGH)){
    motor_control(1,0,1,0);
    motor_control2(1,0,1,0);
    Serial.println("GO");
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


