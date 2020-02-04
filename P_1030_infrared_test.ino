// 적외선 장애물 감지 센서는 적외선을 이용해서 앞에 장애물이 있는지 확인하는 센서입니다.
// 적외선 장애물 감지 센서는 디지털 3번 핀으로 설정합니다.
int infrared1  = 8;
int infrared2  = 9;
// LED는 디지털 6번핀으로 설정합니다.


// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.
// 변수를 선언하거나 초기화를 위한 코드를 포함합니다.
void setup() {
  // 적외선 장애물 감지 센서 핀을 INPUT으로 설정합니다.
  pinMode(infrared1, INPUT);
  pinMode(infrared2, INPUT);
  // LED 핀을 OUTPUT으로 설정합니다.
  

  // 적외선 장애물 감지 센서의 상태를 확인하기 위하여 시리얼 통신의 속도를 설정합니다.
  Serial.begin(9600);
}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행됩니다.
void loop() {
  // 적외선 감지 센서 부터 센서값을 읽습니다.
  // 감지되면 0, 감지되지 않으면 1이 나옵니다.
  int state1 = digitalRead(infrared1);
  int state2 = digitalRead(infrared2);

  // 측정된 센서값을 시리얼 모니터에 출력합니다.
  Serial.print("Infrared1 =");
  Serial.println(state1);
  Serial.print("Infrared2 =");
  Serial.println(state2);

  
 
}
