#define water_pump 2                // 2번 핀을 water_pump라고 지정

int second = 0;

void setup() {
  Serial.begin(9600);
  pinMode(water_pump,OUTPUT);       // 워터펌프(2번)핀을 출력핀으로 지정

}

void loop() {
  digitalWrite(water_pump,HIGH);    // 워터펌프 동작 시작
  delay(1000);                      // 1초 대기
  second++;                         // 1초 카운트
  if(second >= 60) {                // 1분이 카운트 되었을 때,
    digitalWrite(water_pump,LOW);   // 워터펌프 동작 중지
    delay(5000);
    second = 0;                     // 카운트한 초값 초기화
  }
}
