#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup(){
  Serial.begin(9600); // init serial to print info
  pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
     pinMode(4, OUTPUT);
      pinMode(3, OUTPUT);
  
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = "); // print temp 
  Serial.println(DHT.temperature);
  Serial.print("Humidity = "); // print humidity 
  Serial.println(DHT.humidity);
  int temp1 = DHT.humidity;
  int thrshld = 49 ;
  if (temp1 > thrshld) // If humidity rises, turn fan until it drops
  {
       digitalWrite(6, HIGH); // Green led on
       digitalWrite(5, LOW);
       digitalWrite(4, LOW);
       digitalWrite(3, HIGH);  //Fan on     
   }
   else // do nothing
   {    
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH); // Red led on
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);  
   }
   delay(2000);
 

} //voidloop

