#define PIN_A1 4//left wheel
#define PIN_B1 5//left wheel
#define PIN_A2 6//right wheel
#define PIN_B2 7//right wheel

char val;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_A1,OUTPUT);
  pinMode(PIN_A2,OUTPUT);
  pinMode(PIN_B1,OUTPUT);
  pinMode(PIN_B2,OUTPUT);
  Serial.println("Arduino RC Car is ready to start");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()){
    val=Serial.read();
    if(val=='4'){//left
      Serial.println("left");
      left();
    }
    else if(val=='6') {//right
      Serial.println("right");
      right();
    }
    else if(val=='8'){//forward
      Serial.println("forward");
      forward();
    }
    else if(val=='2'){//backward
      Serial.println("forward");
      forward();
    }
    else if(val=='0'){//stop
      Serial.println("stop");
      stop();
    }
    
  }

}

void forward(){
  digitalWrite(PIN_A1,HIGH);
  digitalWrite(PIN_B1,LOW);
  digitalWrite(PIN_A2,HIGH);
  digitalWrite(PIN_B2,LOW);
}

void backward() {
  digitalWrite(PIN_A1,LOW);
  digitalWrite(PIN_B1,HIGH);
  digitalWrite(PIN_A2,LOW);
  digitalWrite(PIN_B2,HIGH);
}

void left(){
  digitalWrite(PIN_A1,LOW);
  digitalWrite(PIN_B1,HIGH);
  digitalWrite(PIN_A2,LOW);
  digitalWrite(PIN_B2,HIGH);
}

void right(){
  digitalWrite(PIN_A1,HIGH);
  digitalWrite(PIN_B1,LOW);
  digitalWrite(PIN_A2,LOW);
  digitalWrite(PIN_B2,HIGH);
}

void stop(){
  digitalWrite(PIN_A1,LOW);
  digitalWrite(PIN_B1,LOW);
  digitalWrite(PIN_A2,LOW);
  digitalWrite(PIN_B2,LOW);
}


