#define BLYNK_TEMPLATE_ID "Masukkan TEMPLATE ID disini"
#define BLYNK_TEMPLATE_NAME "Masukkan TEMPLATE NAME disini"

#define AUTH_TOKEN "Paste AUTH TOKEN disini"
#define NAMA_WIFI "Masukkan Nama Wifi Disini"
#define PASSWORD "Masukkan Password Wifi Disini"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define ENA 3
#define IN1 2
#define IN2 1
#define IN3 6
#define IN4 4
#define ENB 5

int a, b, c, d;
int SpeedA = 255;
int SpeedB = 200;
int Speed2 = 200;

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

BLYNK_WRITE(V2) {
  a = param.asInt();
}
BLYNK_WRITE(V3) {
  b = param.asInt();
}
BLYNK_WRITE(V4) {
  c = param.asInt();
}
BLYNK_WRITE(V5) {
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
  analogWrite(ENA, SpeedA);
  analogWrite(ENB, SpeedB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("MAJU");
}

void jalanMundur() {
  analogWrite(ENA, SpeedA);
  analogWrite(ENB, SpeedB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("MUNDUR");
}

void belokKanan() {
  analogWrite(ENA, Speed2);
  analogWrite(ENB, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("KIRI");
}

void belokKiri() {
  analogWrite(ENA, 0);
  analogWrite(ENB, Speed2);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("KANAN");
}

void serongKiri() {
  analogWrite(ENA, Speed2);
  analogWrite(ENB, SpeedA);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("SERONG KIRI");
}

void serongKanan() {
  analogWrite(ENA, SpeedA);
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
