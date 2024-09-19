#include <OneWire.h>                                      // DS18B20 온도센서 사용을 위한 라이브러리
#include <DallasTemperature.h>                            // 라이브러리 설치 필요

#define water_pump 2                                      // 2번 핀을 water_pump라고 지정
#define ONE_WIRE_BUS 3                                    // 3번 핀을 ONE_WIRE_BUS라고 지정

OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);

boolean on_off = LOW;
int second = 0;
float temp = 0, before_temp = 0;

void setup() {
  Serial.begin(9600);
  pinMode(water_pump,OUTPUT);                             // 워터펌프(2번)핀을 출력핀으로 지정
  sensors.begin();                                        // 온도 센서 제어
}

void loop() {
  on_off = digitalRead(water_pump);                       // on_off 변수에 워터펌프가 동작중인지에 대한 값 저장
    
  if(on_off == LOW){                                      // 워터펌프가 동작 중이지 않을 때,
    sensors.requestTemperatures();
    temp = sensors.getTempCByIndex(0);                    // temp 변수에 온도 센서값 저장
    Serial.print(temp);                                   // 현재 온도 값, 이전 온도 값 출력
    Serial.print(" 'C, /");
    Serial.print(before_temp);
    Serial.println(" 'C");
  
    if(temp == -127.00) temp = before_temp;               // 튀는 값 방지용으로 이전 온도 값 저장
    
    if(temp >= 28.00){                                    // 온도 값이 특정 값보다 높을 시 워터펌프 동작
      digitalWrite(water_pump,HIGH);
    }else{                                                // 온도 값이 특정 값보다 낮을 때 워터펌프 동작 정지
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
  
  before_temp = temp;
}
