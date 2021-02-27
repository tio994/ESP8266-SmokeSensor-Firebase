#include <FirebaseESP8266.h>  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>
int gas = A0;

#define FIREBASE_HOST " "
#define FIREBASE_AUTH " "
#define WIFI_SSID " "
#define WIFI_PASSWORD " "

FirebaseData firebaseData;
void setup() {
  pinMode(gas, INPUT);
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                 
  Serial.print("Mengkoneksikan Ke : ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Terkoneksi");
    delay(100);
}



Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
 
  int analogSensor = analogRead(gas);
  Firebase.setFloat(firebaseData, "Data",analogSensor);
  Serial.print("Tekanan Gas : ");
  Serial.println(analogSensor);
 
  delay(4000);
}
