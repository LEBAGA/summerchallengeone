//////////Written by LEBAGA CASTEN DOBGIMA/////
///////ORANGE SUMMER CHALLENGE///
#include "DHT.h"

#define DHTPIN 4     // Digital pin connected to the DHT, DHT must be disconnected during program upload.
#define DHTTYPE DHT11   // DHT 11 used

DHT OrangeDHT(DHTPIN, DHTTYPE);//creating Instance of DHT sensor class
//initialise RGB LED pins: WITH RGB WE HAVE 3 COMMUNICATION PINS RED, GREEN AND BLUE. I MADE USE OF JUST THE RED AND GREEN
int LED1RED=5;
int LED1GREEN=6;
int LED2RED=7;
int LED2GREEN=8;
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test!"));
 pinMode(LED1RED, OUTPUT);
 pinMode(LED1GREEN, OUTPUT);
 pinMode(LED2RED, OUTPUT);
 pinMode(LED2GREEN, OUTPUT);
  OrangeDHT.begin();//trigger the dht densor to start sensing
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  float humidity = OrangeDHT.readHumidity();//read humidity value from sensor
  // Read temperature as Celsius (the default)
  float temperature =OrangeDHT.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
//printing result on the serial monitor
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature);
  Serial.print(F("°C "));
  //comparison for LED indications.
  if(temperature>30){
   digitalWrite(LED1RED, HIGH); 
   digitalWrite(LED1GREEN, LOW);  
  }//if temperature greater than 30 degree celcuis RED gets to shine from RGB1
  else{
     digitalWrite(LED1RED, LOW); 
   digitalWrite(LED1GREEN, HIGH);
  }//else green shines from RGB1
  if(humidity>50){
   digitalWrite(LED2RED, HIGH); 
   digitalWrite(LED2GREEN, LOW);  
  }//if humidity greater than 50% RED gets to shine from RGB2
  else{
     digitalWrite(LED2RED, LOW); 
   digitalWrite(LED2GREEN, HIGH);
  }//else green shines from RGB2
}