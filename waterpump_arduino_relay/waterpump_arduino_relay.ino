#define water_pump 2               // 2번 핀을 water_pump라고 지정

void setup() {
  pinMode(water_pump,OUTPUT);      // 워터펌프(2번)핀을 출력핀으로 지정
}

void loop() {
  digitalWrite(water_pump,HIGH);   // 워터펌프 동작 시작
  delay(1000);
  digitalWrite(water_pump,LOW);    // 워터펌프 동작 중지
  delay(1000);
}
