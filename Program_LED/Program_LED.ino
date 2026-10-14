#define BLYNK_TEMPLATE_ID   "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "Template Name"
#define BLYNK_AUTH_TOKEN    "YourAuthToken"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "NamaWiFi";
char pass[] = "PasswordWiFi";

const int LED_PIN = 8;

BLYNK_WRITE(V0) {
  int ledButton = param.asInt();
  
  digitalWrite(LED_PIN, ledButton);
  
  Serial.print("Status Switch V0: ");
  Serial.println(ledButton == 1 ? "HIGH" : "LOW");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}