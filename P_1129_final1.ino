#include <SoftwareSerial.h>

#define PRT_DIST
#define PRT_SENSOR
#define PRT_CMD

//적외선
int s1 = A1;
int s2 = A2;
int s3 = A3;

//모터
int lm1 = 5;
int lm2 = 6;
int rm1 = 7;
int rm2 = 8;
int ena1 = 9;
int ena2 = 10;

//블루투스
int RX = 3;
int TX = 2;
SoftwareSerial BTSerial(TX, RX);

//초음파
int trig = 12;
int echo = A0;

//피에조
int piezo = 13;
int freq = 1000;

void setup() {
  for (int i = 5; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  //pinMode(A4, INPUT);
  //pinMode(A5, INPUT);
  Serial.begin(9600); //시리얼
  BTSerial.begin(9600);
}

void loop() {
  //초음파
  float duration, distance;
  int a, b, c;
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  //거리계산
  duration = pulseIn(echo, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;

  //장애물감지 후 멈춤
  if (distance <= 30) {
    motor_control(0, 0, 0, 0);
  }

#ifdef PRT_DIST
  //거리출력
  Serial.print("Duration: ");
  Serial.println(duration);
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
#endif

  //적외선센서 입력값 저장
  a = analogRead(s1);
  b = analogRead(s2);
  c = analogRead(s3);

#ifdef PRT_SENSOR
  Serial.print("s1 =");
  Serial.println(a);
  delay(1000);
  Serial.print("s2 =");
  Serial.println(b);
  delay(1000);
  Serial.print("s3 =");
  Serial.println(c);
  delay(1000);
#endif

  //라인트레이서

  if (Serial.available()) {
    switch ((Serial.read()) {
      case'F':
        motor_control(0, 1, 0, 1);
        //  Serial.println("go");
        break;

      case'B':
        motor_control(1, 0, 1, 0);
        // Serial.println("back");
        break;

      case'L':
        motor_control(0, 0, 0, 1);
        // Serial.println("left");
        break;
      case'R':
        motor_control(0, 1, 0, 0);
        //Serial.println("right");
        break;

      case'S':
        motor_control(0, 0, 0, 0);
        //Serial.println("stop");
        break;
    }
  }


  //in white
  if ((a < 150) && (b < 150) && (c < 150)) {
    motor_control(0, 0, 0, 0);
#ifdef PRT_CMD
    Serial.println("stop");
#endif
  }


  //right
  if ((a < 150) && (b > 500) && (c >500)) {
    motor_control(0, 1, 0, 0);
#ifdef PRT_CMD
    Serial.println("RIGHT");
#endif
  }


  //left
  if ((a >500) && (b > 500) && (c <150)) {
    motor_control(0, 0, 0, 1);
#ifdef PRT_CMD
    Serial.println("LEFT");
#endif
  }


  //go
  if ((a >400) && (b >400) && (c >400)) {
    motor_control(0, 1, 0, 1);
#ifdef PRT_CMD
    Serial.println("GO");
#endif
  }

  if ((a <150) && (b >500) && (c <150)) {
    motor_control(0, 1, 0, 1);
    Serial.println("go");
  }
}
void motor_control(int j1, int j2, int j3, int j4) {
  digitalWrite(lm1, j1);
  digitalWrite(lm2, j2);
  digitalWrite(rm1, j3);
  digitalWrite(rm2, j4);
  analogWrite(10, 255);
  analogWrite(9, 255);
}


