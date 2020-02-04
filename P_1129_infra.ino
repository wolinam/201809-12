  int a = A1;
  void setup() {
    pinMode(a,INPUT);
    Serial.begin(9600);
  }
  void loop(){
  int b = analogRead(a);
  Serial.print("s1 =");
  Serial.println(b);
  delay(500);
  }
