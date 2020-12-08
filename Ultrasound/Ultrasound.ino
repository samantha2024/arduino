//超音波
int trigPin = 12, echoPin = 11;
int index = 0, arrayNumber = 5;
float duration = 0.0, cm = 0.0, total = 0.0, average = 0.0;
int  Ultrasound[arrayNumber];

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, OUTPUT);

  for (int thisIndex = 0; ThisIndex < arrayNumber ; thisIndex++) {
    Ultrasound[thisIndex] = 0;  //array初始值為0
  }
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(echoPin, HIGH);  //Trig高電位,持續5s
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);

  pinMode(echoPin, INPUT);  //讀取echo電位
  duration = pulseIn(echoPin, HIGH);  //收到高電位的時間

  cm = (duration / 2) / 29.1;
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
  Serial.println(cm); //這裡接伺服馬達的code
  delay(250);
}
