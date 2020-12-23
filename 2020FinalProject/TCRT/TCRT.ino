//TCRT
#define Tcrt_LPin A2
#define TCRT_RPin A3
int Tcrt_LValue = 0, Tcrt_RValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Tcrt_LPin, INPUT);
  pinMode(Tcrt_RPin, INPUT);
}

void loop() {
  //黑色>700, 白色40~80
  Tcrt_LValue = analogRead(Tcrt_LPin);
  Tcrt_RValue = analogRead(Tcrt_RPin);
  
  Serial.print("Tcrt_LValue");
  Serial.println(Tcrt_LValue);

  Serial.print("Tcrt_RValue");
  Serial.println(Tcrt_RValue);
  delay(500);
}
