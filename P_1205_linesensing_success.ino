#include <SoftwareSerial.h>

//적외선
int s1 = 11;
int s2 = 8;
int s3 = 12;
/*int s4=
int s5=*/

//모터
int lm1 = 4;
int lm2 = 5;
int rm1 = 6;
int rm2 = 7;
int ena1 = 9;
int ena2 = 10;


void setup() {

  analogWrite(ena1, 220);
  analogWrite(ena2, 220);

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

  //적외선센서 입력값 저장
  int a = digitalRead(s1);
  int b = digitalRead(s2);
  int c = digitalRead(s3);
/*  int d = digitalRead(s4);
  int e = digitalRead(s5);
*/

  Serial.print("s =");
  Serial.print(a);
  Serial.print(" ");
  Serial.print(b);
  Serial.print(" ");
  Serial.println(c);
  

  
  //라인트레이서
  if ((a == 0) && (b == 0) && (c == 0) /*&& (d == 0) && (e == 0)*/) {
    motor_control(0, 1, 0, 1);
    //Serial.println("STOP");
  }
  if ((a == 1) && (b == 0) && (c == 0) ) {
    
    motor_control(0, 0, 1, 0);
    //Serial.println("RIGHT");
  }
  if ((a == 0) && (b == 0) && (c == 1)) {
    
    motor_control(1, 0, 0, 0);
    //Serial.println("LEFT");
  }
  if ((a == 0) && (b == 1) && (c == 0)) {
    
    motor_control(1, 0, 1, 0);
    // Serial.println("GO");
  }
  if ((a == 1) && (b == 1) && (c == 0)) {
    
    motor_control(0, 0, 1, 0);
    //Serial.println("GO");
  }
  if ((a == 0) && (b == 1) && (c == 1)) {
    delay(10);
    motor_control(1, 0, 0, 0);
    //Serial.println("GO");
  }
 if ((a == 1) && (b == 1) && (c == 1)) {
    delay(10);
    motor_control(1, 0, 1, 0);
    //Serial.println("GO");
  }
}

void motor_control(int j1, int j2, int j3, int j4) {
  digitalWrite(lm1, j1);
  digitalWrite(lm2, j2);
  digitalWrite(rm1, j3);
  digitalWrite(rm2, j4);
}
