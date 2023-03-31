#include <Blynk.h>

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
//digital light
#include <Wier.h>
#include <BH1750FVI.h>


#define BLYNK_PRINT Serial
#define DHTTYPE DHT22
#define DHTPIN D4
//photoresistor sensor
//int lampvalue = 0;
unit8_t ADDRESSPIN = 15;
BH1750FVI::eDeviceAddress_t DEVICEADDRESS = BH1750FVI :: k_DevAdress_L;
BH1750FVI::eDeviceMode_t DEVICEMODE = BH1750FVI :: k_DevModecontHighRes;
BH1750FVI LightSensor(ADDRESSPIN, DEVICEADDRESS, DEVICEMODE);//create light sensor instance
//soil moisture
const int sensor_pin = A0; 
//blynk confug blynk auth token
char auth[] = "your token";
BlynkTimer timer;
//wifi config
char ssid[] = "your wifi name";//wifi ssid
char pass[] = "your wifi password";


DHT dht(DHTPIN, DHTTYPE, 15);

void setup() {
  Serial.print("START===============");
  //pinMode(Sensor, INPUT);
  LightSensor.begin();
  Serial.print(auth);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  Serial.begin(115200);
}

void loop() {
  Blynk.run();

  //soil moisture
  /*
  float moisture_percentage;
  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );
  Serial.print("Soil Moisture = ");
  Serial.print(moisture_percentage);
  Serial.println("%");
*/
  //photoresistor test
 // pinMode(D2, OUTPUT);
  lampvalue = analogRead(A0);
  uint16_t lux = LightSensor.GetLightIntensity();
  Serial.println("Light = %d lulx",lux)

  //humidity
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("Humind: ");
  Serial.println(humid);

  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, humid);
  delay(1000);

}
