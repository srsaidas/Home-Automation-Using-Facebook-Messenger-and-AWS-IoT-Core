#include "DHT.h"
#include <Wire.h>  
 #define SLAVE_ADDRESS 0x08   // Define the i2c address



#define DHTPIN 2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
String temp1="";
float t, h;

 void setup()
 {
 Serial.begin(9600);
 Wire.begin(SLAVE_ADDRESS);
 dht.begin(); 
Wire.onRequest(sendData); 

}

void loop()
 {
 h = dht.readHumidity();
  // Read temperature as Celsius (the default)
 t = dht.readTemperature();
 temp1 = String(h)+String(t);
 Serial.print(temp1);

 delay(2000);

}

void sendData()

{
Wire.write(temp1.c_str());

}
