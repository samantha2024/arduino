//DHT
#include <DHT.h>
#define DhtPin 8
#define DhtType DHT11 //我忘了是11還是22
DHT dht(DhtPin, DhtType);
DHT sensor;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  Serial.print("Temperature Celcius = ");
  Serial.print(dht.readTemperature());
  Serial.println(" C");

  Serial.print("Humidity = ");
  Serial.print(dht.readHumidity());
  Serial.println("%");

  delay(500);
}
