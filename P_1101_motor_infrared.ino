#include<SoftwareSerial.h>
/*definningInputs*/
int infrared1  = 12;
int infrared2  = 13;

/*definningOutputs*/
#define LM1 4  //left  motor
#define LM2 5 //left motor
#define RM1 6 //right motor
#define RM2 7//right motor
#define LM3 8// left motor
#define LM4 9//left motor
#define RM3 10//right motor
#define RM4 11//right motor

void motor_control(int i1, int i2, int i3,int i4){
  digitalWrite(LM1,i1);
  digitalWrite(LM2,i2);
  digitalWrite(RM1,i3);
  digitalWrite(RM2,i4);
}

void motor_control2(int j1,int j2, int j3, int j4) {
  digitalWrite(LM3,j1);
  digitalWrite(LM4,j2);
  digitalWrite(RM3,j3);
  digitalWrite(RM4,j4);
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(infrared1, INPUT);
  pinMode(infrared2, INPUT);
  for(int i=4;i<=11;i++)
    pinMode(i,OUTPUT);
  
}


void loop() {
  // put your main code here, to run repeatedly:
  int state1 = digitalRead(infrared1);
  int state2 = digitalRead(infrared2);
  if((state1==0)&&(state2==0))//Condition_1 stop
  {
    motor_control(0,0,0,0);
    Serial.println("1");
    
  }

  else if((state1==1)&&(state2==1)) //CONDITION-2 FORWARD
  {
    motor_control(1,1,1,1);
    motor_control2(0,0,0,0);
    Serial.println("2");
  }

  else if((state1==1)&&(state2==0))
  {
    motor_control(0,1,0,1);
    Serial.println("4");
  }
  }
