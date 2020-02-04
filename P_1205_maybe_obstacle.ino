#include <SoftwareSerial.h>

//적외선
int s1 = 11;
int s2 = 8;
int s3 = 12;

//모터
int lm1 = 4;
int lm2 = 5;
int rm1 = 6;
int rm2 = 7;
int ena1 = 9;
int ena2 = 10;


void setup() {

  analogWrite(ena1, 70);
  analogWrite(ena2, 70);

  for (int i = 4; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  for (int j = 11; j <= 12; j++) {
    pinMode(j, INPUT);
  }
  pinMode(8, INPUT);
  Serial.begin(9600); //시리얼
}

void loop() {
  
  motor_control(1,0,0,0);
  motor_control(1,0,1,0);
  delay(700);
  motor_control(0,0,0,1);
  motor_control(1,0,1,0);
  delay(700);
}

void motor_control(int j1, int j2, int j3, int j4) {
  digitalWrite(lm1, j1);
  digitalWrite(lm2, j2);
  digitalWrite(rm1, j3);
  digitalWrite(rm2, j4);
}


