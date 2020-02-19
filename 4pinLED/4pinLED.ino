void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  digitalWrite(3, 1);//紅燈
  digitalWrite(4, 1);//最長腳，永遠設於1
  digitalWrite(5, 1);//綠燈
  digitalWrite(6, 1);//藍燈
}
