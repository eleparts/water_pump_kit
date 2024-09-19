#define water_pump 2                                      // 2번 핀을 water_pump라고 지정
#define flame_sensor 4                                    // 4번 핀을 flame_sensor라고 지정

void setup() {
  Serial.begin(9600);
  pinMode(water_pump,OUTPUT);                             // 워터펌프(2번)핀을 출력핀으로 지정
  pinMode(flame_sensor,INPUT);                            // 불꽃센서(4번)핀을 입력핀으로 지정
}

void loop() {
  int flame = digitalRead(flame_sensor);                  // flame 변수에 불꽃 감지 센서의 값을 받아옵니다.
  
  if(flame == 0) {                                        // 불꽃이 감지되었을 경우, 워터펌프 동작
    digitalWrite(water_pump,HIGH);
  }else {                                                 // 불꽃이 감지되지 않을 경우, 워터펌프 중지
    digitalWrite(water_pump,LOW);
  }
  
  delay(100);
}
