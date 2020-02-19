void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(4, 1);//最長腳，永遠設於1
  analogWrite(5, 255);//綠燈
  analogWrite(6, 255);//藍燈
  analogWrite(3, 255);//紅燈
}

void loop() {
  //255為1，0為0
  //1為高電位，0為低電位
  //有PWM訊號才能寫analogWrite
  for (int i = 3; i <= 6; i++) {
    if (i != 4) {
      light(i);
      dark(i);
    }
  }
}
void light(int j) {//j為腳位
  for (int i = 255; i >= 0; i--) {//漸亮
    analogWrite(j, i);
    delay(5);
  }
}
void dark(int j) {
  for (int i = 0; i <= 255; i++) {//漸暗
    analogWrite(j, i);
    delay(5);
  }
}
