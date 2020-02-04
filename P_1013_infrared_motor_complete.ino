#include <SoftwareSerial.h>

int ls = 3;
int rs = 12;

int lm1 = 4;
int lm2 = 5;
int lm3 = 6;
int lm4 = 7;
int rm1 = 8;
int rm2 = 9;
int rm3 = 10;
int rm4 = 11;

void setup() {
  for(int i = 4; i<=11; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  if((digitalRead(LS)==HIGH)&&(digitalRead(RS)==HIGH)){
    motor_control(0,0,0,0);
    motor_control2(0,0,0,0);
    Serial.println("2");
  }
  if((digitalRead(LS)==LOW)&&(digitalRead(RS)==HIGH)){
    motor_control(1,0,1,0);
    motor_control2(1,0,1,0);
    Serial.println("3");
  }
  if((digitalRead(LS)==HIGH)&&(digitalRead(RS)==LOW)){
    motor_control(0,1,0,1);
    motor_control2(0,1,0,1);
    Serial.println("4");
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
}

