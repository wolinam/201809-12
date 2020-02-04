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

//초음파
int trig = 13;
int echo = A0;

//피에조
int piezo = 2;
int freq = 1000;

int led = 3;

void setup() {

  analogWrite(ena1, 210);
  analogWrite(ena2, 210);

  for (int i = 3; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  for (int j = 11; j <= 12; j++) {
    pinMode(j, INPUT);
  }
  pinMode(8, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  Serial.begin(9600); //시리얼
}


void loop() {
  //초음파

  int a1 = digitalRead(s1);
  int a2 = digitalRead(s2);
  int a3 = digitalRead(s3);

  Serial.print("s = ");
  Serial.print(a1);
  Serial.print(" ");
  Serial.print(a2);
  Serial.print(" ");
  Serial.println(a3);



  if ((a1 == 0) && (a2 == 0) && (a3 == 0)) {
    analogWrite(9, 140);
    analogWrite(10, 140);
    motor_control(0, 1, 0, 1);
    Serial.println("STOP");
  }
  if ((a1 == 1) && (a2 == 0) && (a3 == 0) ) {

    motor_control(0, 0, 1, 0);
    Serial.println("RIGHT");
  }
  if ((a1 == 0) && (a2 == 0) && (a3 == 1)) {

    motor_control(1, 0, 0, 0);
    Serial.println("LEFT");
  }
  if ((a1 == 0) && (a2 == 1) && (a3 == 0)) {

    motor_control(1, 0, 1, 0);
    Serial.println("GO");
  }
  if ((a1 == 1) && (a2 == 1) && (a3 == 0)) {

    motor_control(0, 0, 1, 0);
    Serial.println("GO");
  }
  if ((a1 == 0) && (a2 == 1) && (a3 == 1)) {
    motor_control(1, 0, 0, 0);
    Serial.println("GO");
  }
  if ((a1 == 1) && (a2 == 1) && (a3 == 1)) {
    motor_control(1, 0, 1, 0);
    Serial.println("GO");
  }
  if ((a1 == 1) && (a2 == 0) && (a3 == 1)) {
    motor_control(1, 0, 1, 0);
    Serial.println("GO");
  }

  float duration, distance;
  //int a, b, c;
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  //거리계산
  duration = pulseIn(echo, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;


  //장애물감지 후 멈춤
  if (distance <= 30) {
    motor_control(0, 0, 0, 0);
    digitalWrite(3, HIGH);
    tone(piezo, freq);
    delay(500);
    Serial.println("Shit! Stones!");
  }
  else {
    void line();
    digitalWrite(3, LOW);
    delay(1000);
    noTone(2);



  }
}

void motor_control(int j1, int j2, int j3, int j4) {
  digitalWrite(lm1, j1);
  digitalWrite(lm2, j2);
  digitalWrite(rm1, j3);
  digitalWrite(rm2, j4);
}

void line() {

  int a1 = digitalRead(s1);
  int a2 = digitalRead(s2);
  int a3 = digitalRead(s3);

  Serial.print("s = ");
  Serial.print(a1);
  Serial.print(" ");
  Serial.print(a2);
  Serial.print(" ");
  Serial.println(a3);
  //delay(400);


  if ((a1 == 0) && (a2 == 0) && (a3 == 0)) {
    analogWrite(9, 140);
    analogWrite(10, 140);
    motor_control(0, 1, 0, 1);
    Serial.println("STOP");
  }
  if ((a1 == 1) && (a2 == 0) && (a3 == 0) ) {

    motor_control(0, 0, 1, 0);
    Serial.println("RIGHT");
  }
  if ((a1 == 0) && (a2 == 0) && (a3 == 1)) {

    motor_control(1, 0, 0, 0);
    Serial.println("LEFT");
  }
  if ((a1 == 0) && (a2 == 1) && (a3 == 0)) {

    motor_control(1, 0, 1, 0);
    Serial.println("GO");
  }
  if ((a1 == 1) && (a2 == 1) && (a3 == 0)) {

    motor_control(0, 0, 1, 0);
    Serial.println("GO");
  }
  if ((a1 == 0) && (a2 == 1) && (a3 == 1)) {
    motor_control(1, 0, 0, 0);
    Serial.println("GO");
  }
  if ((a1 == 1) && (a2 == 1) && (a3 == 1)) {
    motor_control(1, 0, 1, 0);
    Serial.println("GO");
  }
  if ((a1 == 1) && (a2 == 0) && (a3 == 1)) {
    motor_control(1, 0, 1, 0);
    Serial.println("GO");
  }
}


