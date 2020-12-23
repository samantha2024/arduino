//電池電量
#define measure A2
int v1 = 0, voltage = 0;

void setup() {
  //使用外部參考電壓
  analogReference(EXTERNAL);
  pinMode(controlPin, OUTPUT);
}

void loop() {
  v1 = analogRead(measure);
  voltage = 3 * (5 * v1 / 1024);

}
