#include <SoftwareSerial.h>

//#define PRT_DIST
//#define PRT_SENSOR
#define PRT_CMD

#define AUTO 1
#define PASSIVE 2
#define NONE 0

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

//블루투스
int RX = 3;
int TX = 2;
SoftwareSerial BTSerial(TX, RX);

//초음파
int trig = 13;
int echo = A0;

//피에조
int piezo = 0;
int freq = 1000;

int prev_cmd = 3;
int recv_cmd = NONE;

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
  for (int i = 5; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
  Serial.begin(9600); //시리얼
  BTSerial.begin(9600);
}


void loop() {
  //초음파

  //int a, b, c;
  void go_line_trace(), go_rc_car();

  if ( recv_cmd != prev_cmd ) {
    prev_cmd = recv_cmd;
    Serial.println(recv_cmd - '0');
  }
#ifdef PRT_DIST
  //거리출력
  Serial.print("Duration: ");
  Serial.println(duration);
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
#endif




  //recv_cmd = NONE;
  if (BTSerial.available()) {
    recv_cmd = BTSerial.read();
  }


  if ( recv_cmd == (AUTO + '0') )
    go_line_trace();
  else if ( recv_cmd == (PASSIVE + '0') )
    go_rc_car();
  else
    motor_control(0, 0, 0, 0);
}

//라인트레이서
void go_rc_car()
{
  if (BTSerial.available()) {
    switch (BTSerial.read()) {
      case'F':
        motor_control(0, 1, 0, 1);
        Serial.println("go");
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
}

void go_line_trace()
{
  int a, b, c;
  void stop_obstacle();
  //적외선센서 입력값 저장
  a = digitalRead(s1);
  b = digitalRead(s2);
  c = digitalRead(s3);

  /*a = 20;
    b = 900;
    c = 20;*/

#ifdef PRT_SENSOR
  Serial.print("s1 =");
  Serial.println(a);
  //delay(100);
  Serial.print("s2 =");
  Serial.println(b);
  //delay(100);
  Serial.print("s3 =");
  Serial.println(c);
  //delay(1000);
#endif
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


void stop_obstacle()
{
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
}

