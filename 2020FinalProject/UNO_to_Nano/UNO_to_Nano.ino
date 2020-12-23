//UNO 傳 Nano
#include <Wire.h> //插入I2C函式庫<Wire> 

void setup(){ 
Wire.begin(); //I2C位址與連線設定，主端不用設 
} 

void loop(){ 
Wire.beginTransmission(3); //開始傳送，指定給從端3號 
Wire.write("hello \n"); //寫入訊息 hello \n 
Wire.endTransmission(); //結束通訊 
} 
