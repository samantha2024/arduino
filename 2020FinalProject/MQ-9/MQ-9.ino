//MQ-9:偵測CO
#define MQPin A0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  float MQVolt = 0.0, MQValue = 0.0;
  MQValue = analogRead(MQPin);  //>200:CO 濃度太高 ->buzzer叫
  MQVolt = MQValue / 1024 * 5.0;  //0.1-0.4V:, 4V:Max

}
