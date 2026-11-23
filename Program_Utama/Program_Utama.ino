#define BLYNK_TEMPLATE_ID "Masukkan TEMPLATE ID disini"
#define BLYNK_TEMPLATE_NAME "Masukkan TEMPLATE NAME disini"
#define BLYNK_AUTH_TOKEN "Paste AUTH TOKEN disini"

#define NAMA_WIFI "Masukkan NAMA WIFI disini"
#define PASSWORD "Masukkan PASSWORD disini"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo gripper;

#define ENA 5
#define IN1 2
#define IN2 1
#define IN3 6
#define IN4 4
#define ENB 3
#define PIN_SERVO 10

int a = 0, b = 0, c = 0, d = 0; 
int SpeedA = 255;  // Kecepatan Motor Kiri (0 - 255)
int SpeedB = 255;  // Kecepatan Motor Kanan (0 - 255)
int Speed2 = 230;  // Kecepatan saat serong

int posBuka = 20;   // Sudut Gripper Buka
int posTutup = 120; // Sudut Gripper Tutup

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = NAMA_WIFI;
char pass[] = PASSWORD;

enum Gerakan { BERHENTI, MAJU, MUNDUR, KIRI, KANAN, SERONG_KIRI, SERONG_KANAN, SERONG_MUNDUR_KIRI, SERONG_MUNDUR_KANAN };
Gerakan gerakanTerakhir = BERHENTI;

void setup() {
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  berhenti();

  gripper.attach(PIN_SERVO);
  gripper.write(posBuka);

  Wire.begin(8, 9);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("NAMA TIM");
  lcd.setCursor(5, 1);
  lcd.print("RR UMS");

  Serial.println("\n--- Menghubungkan ke WiFi & BLYNK ---");
  Blynk.begin(auth, ssid, pass);
  Serial.println(">>> Terhubung ke BLYNK! Siap digunakan <<<");

  WiFi.setSleep(false);
  // Optimasi daya pancar sinyal WiFi ke 15dBm
  WiFi.setTxPower(WIFI_POWER_15dBm);
}

// sesuaikan datastream: a: Maju (V0), b: Mundur (V1), c: Kiri (V2), d: Kanan (V3)
BLYNK_WRITE(V0) {
  a = param.asInt(); // Maju
}
BLYNK_WRITE(V1) {
  b = param.asInt(); // Mundur
}
BLYNK_WRITE(V2) {
  c = param.asInt(); // Kiri
}
BLYNK_WRITE(V3) {
  d = param.asInt(); // Kanan
}
BLYNK_WRITE(V4) {
  int statusGripper = param.asInt(); // Gripper (0: Buka, 1: Tutup)
  if (statusGripper == 1) {
    gripper.write(posTutup);
  } else {
    gripper.write(posBuka);
  }
}

void loop() {
  // Failsafe: Hanya jalankan kontrol jika terhubung ke Blynk.
  // Jika koneksi terputus, robot otomatis berhenti.
  if (Blynk.connected()) {
    Blynk.run();
    soccercar();
  } else {
    if (gerakanTerakhir != BERHENTI) {
      berhenti();
    }
    a = b = c = d = 0;
  }
  delay(2);
}

void soccercar() {
  if (a > 0 && b > 0) berhenti();
  else if (a > 0 && c > 0) serongKiri();
  else if (a > 0 && d > 0) serongKanan();
  else if (b > 0 && c > 0) serongMundurKiri();
  else if (b > 0 && d > 0) serongMundurKanan();
  else if (a > 0) jalanMaju();
  else if (b > 0) jalanMundur();
  else if (c > 0) belokKiri();
  else if (d > 0) belokKanan();
  else berhenti();
}

void jalanMaju() {
  analogWrite(ENA, SpeedA);
  analogWrite(ENB, SpeedB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  if (gerakanTerakhir != MAJU) {
    Serial.println("[GERAK] MAJU");
    gerakanTerakhir = MAJU;
  }
}

void jalanMundur() {
  analogWrite(ENA, SpeedA);
  analogWrite(ENB, SpeedB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  if (gerakanTerakhir != MUNDUR) {
    Serial.println("[GERAK] MUNDUR");
    gerakanTerakhir = MUNDUR;
  }
}

void belokKiri() {
  analogWrite(ENA, SpeedA);
  analogWrite(ENB, SpeedB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  if (gerakanTerakhir != KIRI) {
    Serial.println("[GERAK] BELOK KIRI");
    gerakanTerakhir = KIRI;
  }
}

void belokKanan() {
  analogWrite(ENA, SpeedA);
  analogWrite(ENB, SpeedB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  if (gerakanTerakhir != KANAN) {
    Serial.println("[GERAK] BELOK KANAN");
    gerakanTerakhir = KANAN;
  }
}

void serongKiri() {
  analogWrite(ENA, Speed2);
  analogWrite(ENB, SpeedB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  if (gerakanTerakhir != SERONG_KIRI) {
    Serial.println("[GERAK] SERONG KIRI");
    gerakanTerakhir = SERONG_KIRI;
  }
}

void serongKanan() {
  analogWrite(ENA, SpeedA);
  analogWrite(ENB, Speed2);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  if (gerakanTerakhir != SERONG_KANAN) {
    Serial.println("[GERAK] SERONG KANAN");
    gerakanTerakhir = SERONG_KANAN;
  }
}

void serongMundurKiri() {
  analogWrite(ENA, Speed2);
  analogWrite(ENB, SpeedB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  if (gerakanTerakhir != SERONG_MUNDUR_KIRI) {
    Serial.println("[GERAK] SERONG MUNDUR KIRI");
    gerakanTerakhir = SERONG_MUNDUR_KIRI;
  }
}

void serongMundurKanan() {
  analogWrite(ENA, SpeedA);
  analogWrite(ENB, Speed2);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  if (gerakanTerakhir != SERONG_MUNDUR_KANAN) {
    Serial.println("[GERAK] SERONG MUNDUR KANAN");
    gerakanTerakhir = SERONG_MUNDUR_KANAN;
  }
}

void berhenti() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  if (gerakanTerakhir != BERHENTI) {
    Serial.println("[GERAK] STOP");
    gerakanTerakhir = BERHENTI;
  }
}

/*

  Notes:
  kalo ada yg mau ditanyakan, ada error, dsb. bisa tanya ke grup program ;)
  
*/