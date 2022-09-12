#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "RELAY 2 CHANNEL"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPass";

// PIN A0
BLYNK_WRITE(V1){
  if(param.asInt() == HIGH){
    digitalWrite(16, LOW);
  } else digitalWrite(16, HIGH);
}

// PIN A1
BLYNK_WRITE(V2){
  if(param.asInt() == HIGH){
    digitalWrite(5, HIGH);
  } else digitalWrite(5, LOW);
}
void setup()
{
  // Debug console
  Serial.begin(9600);
  delay(100);
  pinMode(16,OUTPUT);
  pinMode(5,OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
