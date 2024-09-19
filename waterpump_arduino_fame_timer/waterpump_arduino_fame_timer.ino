#define water_pump 2                                      // 2번 핀을 water_pump라고 지정
#define flame_sensor 4                                    // 4번 핀을 flame_sensor라고 지정

boolean on_off = LOW, flame = HIGH;
int second = 0;

void setup() {
  Serial.begin(9600);
  pinMode(water_pump,OUTPUT);                             // 워터펌프(2번)핀을 출력핀으로 지정
  pinMode(flame_sensor,INPUT);                            // 불꽃센서(4번)핀을 입력핀으로 지정
}

void loop() {
  on_off = digitalRead(water_pump);                       // on_off 변수에 워터펌프 동작 상태를 받아옵니다.

  if(on_off == LOW){                                      // 워터펌프가 동작 중이지 않을 때,
    flame = digitalRead(flame_sensor);                    // flame 변수에 불꽃 감지 센서의 값을 받아옵니다.
    Serial.println(flame);
  
    if(flame == LOW){                                     // 불꽃이 감지되었을 경우, 워터펌프 동작
      digitalWrite(water_pump,HIGH);
    }else {                                               // 불꽃이 감지되지 않을 경우, 워터펌프 중지
      digitalWrite(water_pump,LOW);
    }
  }else if(on_off == HIGH){                               // 워터펌프가 동작 중일 때,
    second++;                                             // 1초씩 카운트
    delay(1000);
    Serial.println(second);
    if(second >= 60){                                     // 1분이 카운트 되었을 때,
      digitalWrite(water_pump,LOW);                       // 워터펌프 동작 중지
      second = 0;                                         // 카운트한 초값 초기화
    }
  }
  
  delay(100);
}
