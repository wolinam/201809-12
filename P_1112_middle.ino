#include <SoftwareSerial.h>

//#define PRT_DIST
//#define PRT_SENSOR
//#define PRT_CMD

//적외선
int s1 = A0;
int s2 = A2;
int s3 = A1;

//모터
int lm1 = 5;
int lm2 = 6;
int rm1 = 9;
int rm2 = 10;

//초음파
int trig = 11;
int echo = A5;

//피에조
int piezo = 13;
int freq = 1000;

void setup() {
  for (int i = 9; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(11, OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A5, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600); //시리얼
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
  if (distance <= 17) {
    motor_control(0, 30, 0, 30);
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
  delay(500);
  Serial.print("s2 =");
  Serial.println(b);
  delay(500);
  Serial.print("s3 =");
  Serial.println(c);
  delay(500);
#endif

  //라인트레이서
  if (distance > 17) {
    
  
  if ((a<110) && (b <110) && (c<110)) {
    
    motor_control(0, 150, 0, 150);
#ifdef PRT_CMD
    Serial.println("BACK");
    #endif
  }
  if ((a >920) && (b>920) && (c < 135)) {
    
    motor_control(215, 0, 0, 100);
  #ifdef PRT_CMD
  Serial.println("RIGHT");
  #endif
  }
  if ((a >920) && (b<135) && (c < 135)) {
    
    motor_control(215, 0, 0, 100);
  #ifdef PRT_CMD
  Serial.println("RIGHT");
  #endif
  }
  if ((a <135) && (b>920) && (c >920)) {
    
    motor_control(0, 100, 215, 0);
    #ifdef PRT_CMD
    Serial.println("LEFT");
    #endif
  }
  if ((a <135) && (b<135) && (c >920)) {
    
    motor_control(0, 100, 215, 0);
    #ifdef PRT_CMD
    Serial.println("LEFT");
    #endif
  }
  if ((a<150) && (b>920) && (c<150)) {
   
    motor_control(215, 0, 215, 0);
    #ifdef PRT_CMD
    Serial.println("GO");
    #endif
  }
  }

}

void motor_control(int j1, int j2, int j3, int j4) {
  analogWrite(lm1, j1);
  analogWrite(lm2, j2);
  analogWrite(rm1, j3);
  analogWrite(rm2, j4);
}
