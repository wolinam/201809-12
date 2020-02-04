int analoglnPin=A0;
int analogOutPin=9;
int sensorValue=0;
int outputValue=0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  sensorValue=analogRead(analoglnPin);
  outputValue=map(sensorValue,0,1023,255,0);

  if(outputValue<80) outputValue=0;

  analogWrite(analogOutPin, outputValue);
  Serial.print("sensor=");
  Serial.print(sensorValue);
  Serial.print("output=");
  Serial.println(outputValue);

  delay(1000);
}

