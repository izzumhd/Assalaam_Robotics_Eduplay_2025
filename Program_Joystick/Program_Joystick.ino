#define BLYNK_TEMPLATE_ID "Masukkan TEMPLATE ID disini"
#define BLYNK_TEMPLATE_NAME "Masukkan TEMPLATE NAME disini"
#define AUTH_TOKEN "Masukkan AUTH TOKEN disini"
#define NAMA_WIFI "Masukkan Nama Wifi Disini"
#define PASSWORD "Masukkan Password Wifi Disini"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>

#define ENA 5
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define ENB 10

int a, b, c, d;
int Speed = 255;
int Speed2 = 150;

char auth[] = AUTH_TOKEN;
char ssid[] = NAMA_WIFI;
char pass[] = PASSWORD;

void setup() {
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Blynk.begin(auth, ssid, pass);
  Serial.println("Terhubung ke BLYNK");
}

BLYNK_WRITE(V0) {
  a = param.asInt();
}
BLYNK_WRITE(V1) {
  b = param.asInt();
}
BLYNK_WRITE(V2) {
  c = param.asInt();
}
BLYNK_WRITE(V3) {
  d = param.asInt();
}

void loop() {
  Blynk.run();
  soccercar();
}

void soccercar() {
  if (a == 1 && c == 1) serongKiri();
  else if (a == 1 && d == 1) serongKanan();
  else if (a == 1) jalanMaju();
  else if (b == 1) jalanMundur();
  else if (c == 1) belokKiri();
  else if (d == 1) belokKanan();
  else berhenti();
}

void jalanMaju() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("MAJU");
}

void jalanMundur() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("MUNDUR");
}

void belokKiri() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("KIRI");
}

void belokKanan() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("KANAN");
}

void serongKiri() {
  analogWrite(ENA, Speed2);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("SERONG KIRI");
}

void serongKanan() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed2);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("SERONG KANAN");
}

void berhenti() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("STOP");
}
