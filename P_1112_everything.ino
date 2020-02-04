#include <SoftwareSerial.h>
//블루투스
int tx = 0;
int rx = 1;
SoftwareSerial BTSerial(tx, rx);

//적외선
int s1 = 2;
int s2 = 3;
int s3 = 13;

//모터
int lm1 = 4;
int lm2 = 5;
int lm3 = 8;
int lm4 = 9;
int rm1 = 6;
int rm2 = 7;
int rm3 = 10;
int rm4 = 11;

//초음파
int trig = 12;
int echo = A5;

//피에조
//int piezo = 13;
int freq = 1000;

void setup() {
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A5, INPUT);
  Serial.begin(9600); //시리얼통신
  BTSerial.begin(9600);
}

void loop() {
  //초음파
  float duration, distance;
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  //거리계산
  duration = pulseIn(echo, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;

  //장애물감지 후 멈춤
  if (distance <= 30) {
    motor_control(0, 0, 0, 0);
    motor_control2(0, 0, 0, 0);
  }

  //거리출력
  Serial.print("Duration: ");
  Serial.println(duration);
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(300);

 //적외선센서 입력값 저장
  int a = digitalRead(s1);
  int b = digitalRead(s2);
  int c = digitalRead(s3);

 /* //블루투스
  if (Serial.available()) {
    switch (Serial.read()) {
      case 'F':
        motor_control(1, 0, 1, 0);
        motor_control2(1, 0, 1, 0);
        break;
      case 'B':
        motor_control(0, 1, 0, 1);
        motor_control2(0, 1, 0, 1);
        break;
      case 'L':
        motor_control(0, 1, 1, 0);
        motor_control2(0, 1, 1, 0);
        break;
      case 'R':
        motor_control(1, 0, 0, 1);
        motor_control2(1, 0, 0, 1);
        break;
      case 'S':
        motor_control(0, 0, 0, 0);
        motor_control2(0, 0, 0, 0);
        break;
      default:
        break;
    }
  }
}
  else {*/
    //라인트레이서
    if ((a == HIGH) || (b == HIGH) || (c == HIGH)) {
      motor_control(1, 0, 1, 0);
      motor_control2(1, 0, 1, 0);
      Serial.println("STOP");
    }
    if ((a == HIGH) && (b == LOW) && (c == LOW)) {
      motor_control(1, 0, 0, 1);
      motor_control2(1, 0, 0, 1);
      Serial.println("RIGHT");
    }
    if ((a == LOW) && (b == LOW) && (c == HIGH)) {
      motor_control(0, 1, 1, 0);
      motor_control2(0, 1, 1, 0);
      Serial.println("LEFT");
    }
    if ((a == HIGH) && (b == LOW) && (c == HIGH)) {
      motor_control(1, 0, 1, 0);
      motor_control2(1, 0, 1, 0);
      Serial.println("GO");
    }
    else {
      motor_control(1, 0, 1, 0);
      motor_control2(1, 0, 1, 0);
      Serial.println("I don't know");
    }
  
}

void motor_control(int j1, int j2, int j3, int j4) {
  digitalWrite(lm1, j1);
  digitalWrite(lm2, j2);
  digitalWrite(rm1, j3);
  digitalWrite(rm2, j4);
}
void motor_control2(int k1, int k2, int k3, int k4) {
  digitalWrite(lm3, k1);
  digitalWrite(lm4, k2);
  digitalWrite(rm3, k3);
  digitalWrite(rm4, k4);
}


