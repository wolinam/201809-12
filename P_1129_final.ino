#include <SoftwareSerial.h>

//#define PRT_DIST
//#define PRT_SENSOR
//#define PRT_CMD



//모터
int lm1 = 8;
int lm2 = 9;
int ENA = 10;
int rm1 = 3;
int rm2 = 4;

//피에조
int piezo = 13;
int freq = 1000;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600); //시리얼
}

void loop() {
  //라인트레이서
  analogWrite(10,255);
  if (Serial.available()) {
    switch (Serial.read()) {
      case'F':
        motor_control(1, 0, 1, 0);
        Serial.println("go");
        break;

      case'B':
        motor_control(0, 1, 0, 1);
        Serial.println("back");
        break;

      case'L':
        motor_control(0, 1, 1, 0);
        Serial.println("left");
        break;

      case'R':
        motor_control(1, 0, 0, 1);
        Serial.println("right");
        break;

      case'S':
        motor_control(0, 0, 0, 0);
        Serial.println("stop");
        break;
  }
}
}

void motor_control(int j1, int j2, int j3, int j4) {
  digitalWrite(lm1, j1);
  digitalWrite(lm2, j2);
  digitalWrite(rm1, j3);
  digitalWrite(rm2, j4);
}

