#include <WiFi.h>
#include <secrets.h>

#include <WiFiClientSecure.h>   // for https://
#include <HTTPClient.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  connectWiFi();
}

void connectWiFi() {
  //ssid and pw imported from secrets.h:
  WiFi.begin(ssid, pw);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Wifi connecting to "); 
    Serial.print(ssid); 
    Serial.print(" with Status ");
    Serial.print(WiFi.status());
    Serial.println(" ...");
    delay(500);
  }

  Serial.print("Connected to Wifi ");
  Serial.println(ssid);

  firebaseLogin();
}


void firebaseLogin() {
  WiFiClientSecure client;
  client.setInsecure();

  String url = "https://identitytoolkit.googleapis.com/v1/accounts:signInWithPassword?key=" + String(apiKey);

  HTTPClient http;
  http.begin(client, url);
  http.addHeader("Content-Type", "application/json");

  String body = String("{\"email\":\"") + eMail + "\",\"password\":\"" + pwd + "\",\"returnSecureToken\": true }";

  int code = http.POST(body);
  String response = http.getString();
  http.end();
  Serial.println(code);
  Serial.println(response);

}

void printSignalQuality(int rssi) {
  if (rssi > -60){
    Serial.println("My Signal Strength is Great :)");
  }
  else if (rssi > -75){
    Serial.println("My Signal Strength is Okay :p");
  }
  else{
    Serial.println("My Signal Strength is Weak :(");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi Lost! Reconnecting...");
    connectWiFi();
  }

  Serial.println("------------------");
  Serial.print("Hi I Am ESP32 and my local IP is ");
  Serial.println(WiFi.localIP());

  int wifi_signal_strength = WiFi.RSSI();

  printSignalQuality(wifi_signal_strength);

  Serial.println("------------------");
  delay(2000);
}
