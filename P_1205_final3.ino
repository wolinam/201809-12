#include <SoftwareSerial.h>

//#define PRT_DIST
//#define PRT_SENSOR
//#define PRT_CMD

//적외선
int s1 = 11;
int s2 = 8;
int s3 = 12;

int a = digitalRead(s1);
int b = digitalRead(s2);
int c = digitalRead(s3);

//모터
int lm1 = 4;
int lm2 = 5;
int rm1 = 6;
int rm2 = 7;
int ena1 = 9;
int ena2 = 10;

//블루투스
int RX = 3;
int TX = 2;
SoftwareSerial BTSerial(TX, RX);

//초음파
int trig = 13;
int echo = A0;

//피에조
int piezo = A1;
int freq = 1000;

void setup() {

  analogWrite(ena1, 140);
  analogWrite(ena2, 140);

  for (int i = 4; i <= 7; i++) {
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
  BTSerial.begin(9600);
}


void loop() {
  //초음파
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
    Serial.println("Shit! Stones!");
  }


#ifdef PRT_DIST
  //거리출력
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
#endif



  //라인트레이서

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
        motor_control(0, 1, 0, 0);
        Serial.println("left");
        break;

      case'R':
        motor_control(0, 0, 0, 1);
        Serial.println("right");
        break;

      case'S':
        motor_control(0, 0, 0, 0);
        Serial.println("stop");
        break;

      case'A':
        Serial.println("auto mode");
        Serial.print("s = ");
        Serial.print(a);
        Serial.print(" ");
        Serial.print(b);
        Serial.print(" ");
        Serial.println(c);
        delay(400);

        if ((a == 0) && (b == 0) && (c == 0) /*&& (d == 0) && (e == 0)*/) {
          motor_control(0, 1, 0, 1);
          Serial.println("STOP");
        }
        if ((a == 1) && (b == 0) && (c == 0) ) {

          motor_control(0, 0, 1, 0);
          Serial.println("RIGHT");
        }
        if ((a == 0) && (b == 0) && (c == 1)) {

          motor_control(1, 0, 0, 0);
          Serial.println("LEFT");
        }
        if ((a == 0) && (b == 1) && (c == 0)) {

          motor_control(1, 0, 1, 0);
          Serial.println("GO");
        }
        if ((a == 1) && (b == 1) && (c == 0)) {

          motor_control(0, 0, 1, 0);
          Serial.println("GO");
        }
        if ((a == 0) && (b == 1) && (c == 1)) {
          delay(10);
          motor_control(1, 0, 0, 0);
          Serial.println("GO");
        }
        if ((a == 1) && (b == 1) && (c == 1)) {
          delay(10);
          motor_control(1, 0, 1, 0);
          Serial.println("GO");
        }
        if ((a == 1) && (b == 0) && (c == 1)) {
          delay(10);
          motor_control(1, 0, 1, 0);
          Serial.println("GO");
        }
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


