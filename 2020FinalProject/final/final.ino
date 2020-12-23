//整合全部
//超音波*3
#define trig_FPin 7
#define echo_FPin 8
#define trig_BPin 11
#define echo_BPin 12
#define trig_GPin A2
#define echo_GPin A3
float duration_F = 0.0, duration_B = 0.0, duration_G = 0.0;
float cm_F = 0.0, cm_B = 0.0, cm_G = 0.0;
/*float total = 0.0, average = 0.0;
  int  Ultrasound[arrayNumber];
*/

//伺服馬達*2
#include <Servo.h>
Servo myservo_F;
Servo myservo_B;
#define SM_F 9
#define SM_B 10


void setup() {
  Serial.begin(9600);
  //超音波*3
  pinMode(trig_FPin, OUTPUT);
  pinMode(echo_FPin, OUTPUT);
  pinMode(trig_BPin, OUTPUT);
  pinMode(echo_BPin, OUTPUT);
  pinMode(trig_GPin, OUTPUT);
  pinMode(echo_GPin, OUTPUT);
  /*  for (int thisIndex = 0; ThisIndex < arrayNumber ; thisIndex++) {
      Ultrasound[thisIndex] = 0;  //array初始值為0
    }
  */

  //伺服馬達*2
  myservo.attach(SM_F);
  myservo.attach(SM_B);
  myservo_F.write(90);
  myservo_B.write(90);
}

void ultrasound_F() { //偵測前方距離
  digitalWrite(trig_FPin, LOW);
  delayMicroseconds(5);
  digitalWrite(echo_FPin, HIGH);  //Trig高電位,持續5s
  delayMicroseconds(10);
  digitalWrite(trig_FPin, HIGH);

  pinMode(echo_FPin, INPUT);  //讀取echo電位
  duration_F = pulseIn(echo_FPin, HIGH);  //收到高電位的時間

  cm_F = (duration_F / 2) / 29.1;
  /*
    缺Smmoothing

    total = total - readings[readIndex];   // 減掉最後一次的讀數
    readings[readIndex] = analogRead(inputPin);   // 讀取感測器讀數
    total = total + readings[readIndex];   // 將讀取資料加總
    readIndex = readIndex + 1;   // 到下一個陣列置
    if (readIndex >= numReadings) {   // 如果到了陣列最後的位置
    readIndex = 0;   // 則回到開頭位置
    }
    average = total / numReadings;   // 計算平均
    Serial.println(average);
    delay(1);

  */
  Serial.pri0ntln(cm_F); //這裡接伺服馬達的code
  float R = 0.0, L = 0.0;
  if (cm_F <= 3) {
    myservo.write(30);
    R = (duration_F / 2) / 29.1;
    if (R >= 6) {
      //右轉
    }
    myservo.write(150);
    L = (duration_F / 2) / 29.1;
    if (L >= 6) {
      //左轉
    }
    else {
      //後退
    }
  }



  delay(250);
}

void ultrasound_B() { //偵測後方距離
  digitalWrite(trig_BPin, LOW);
  delayMicroseconds(5);
  digitalWrite(echo_BPin, HIGH);  //Trig高電位,持續5s
  delayMicroseconds(10);
  digitalWrite(trig_BPin, HIGH);

  pinMode(echo_BPin, INPUT);  //讀取echo電位
  duration_B = pulseIn(echo_BPin, HIGH);  //收到高電位的時間

  cm_B = (duration_B / 2) / 29.1;
  /*
    缺Smmoothing

    total = total - readings[readIndex];   // 減掉最後一次的讀數
    readings[readIndex] = analogRead(inputPin);   // 讀取感測器讀數
    total = total + readings[readIndex];   // 將讀取資料加總
    readIndex = readIndex + 1;   // 到下一個陣列置
    if (readIndex >= numReadings) {   // 如果到了陣列最後的位置
    readIndex = 0;   // 則回到開頭位置
    }
    average = total / numReadings;   // 計算平均
    Serial.println(average);
    delay(1);

  */
  Serial.println(cm_B); //這裡接伺服馬達的code

  float R = 0.0, L = 0.0;
  if (cm_B <= 3) {
    myservo.write(30);
    R = (duration_B / 2) / 29.1;
    if (R >= 6) {
      //左轉
    }
    myservo.write(150);
    L = (duration_B / 2) / 29.1;
    if (L >= 6) {
      //右轉
    }
    else {
      //前進
    }
    delay(250);
  }

  void ultrasound_G() { //偵測垃圾量
    digitalWrite(trig_GPin, LOW);
    delayMicroseconds(5);
    digitalWrite(echo_GPin, HIGH);  //Trig高電位,持續5s
    delayMicroseconds(10);
    digitalWrite(trig_GPin, HIGH);

    pinMode(echo_GPin, INPUT);  //讀取echo電位
    duration_G = pulseIn(echo_GPin, HIGH);  //收到高電位的時間

    cm_G = (duration_G / 2) / 29.1;
    /*
      缺Smmoothing

      total = total - readings[readIndex];   // 減掉最後一次的讀數
      readings[readIndex] = analogRead(inputPin);   // 讀取感測器讀數
      total = total + readings[readIndex];   // 將讀取資料加總
      readIndex = readIndex + 1;   // 到下一個陣列置
      if (readIndex >= numReadings) {   // 如果到了陣列最後的位置
      readIndex = 0;   // 則回到開頭位置
      }
      average = total / numReadings;   // 計算平均
      Serial.println(average);
      delay(1);

    */
    Serial.println(cm_G);
    delay(250);
  }
  void loop() {
  }
