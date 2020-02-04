int trig = 8;
int echo = A0;
int piezo = 13;
int freq = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, OUTPUT);
  pinMode(piezo, OUTPUT);
}

void loop() {
  float duration, distance;
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);

  duration=pulseIn(echoPin, HIGH);
  distance=((float)(340*duration)/10000)/2;

  if(distance<=30){
    tone(piezo,freq);
  }
  else{
    noTone(piezo);
  }
  Serial.print("Duration: ");
  Serial.println(duration);
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
}
