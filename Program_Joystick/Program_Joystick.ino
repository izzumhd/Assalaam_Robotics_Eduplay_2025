#define BLYNK_TEMPLATE_ID "Masukkan TEMPLATE ID disini"
#define BLYNK_TEMPLATE_NAME "Masukkan TEMPLATE NAME disini"
#define BLYNK_AUTH_TOKEN "Paste AUTH TOKEN disini"

#define NAMA_WIFI "Masukkan Nama Wifi Disini"
#define PASSWORD "Masukkan Password Wifi Disini"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ============================================================================
// PILIHAN KONFIGURASI PIN (PILIH SALAH SATU SESUAI WIRING ROBOT KALIAN)
// ============================================================================
#define WIRING_MANUAL
// #define WIRING_PCB_SHIELD

#if defined(WIRING_PCB_SHIELD)
  const int enA = 4;
  const int in1 = 3;
  const int in2 = 2;
  const int in3 = 1;
  const int in4 = 0;
  const int enB = 21;
#else
  const int enA = 3;
  const int in1 = 2;
  const int in2 = 1;
  const int in3 = 4;
  const int in4 = 5;
  const int enB = 6;
#endif

int x = 0, y = 0;
unsigned long lastPrintTime = 0;

BLYNK_WRITE(V0) {
  x = param[0].asInt();  // Joystick X
}

BLYNK_WRITE(V1) {
  y = param[0].asInt();  // Joystick Y
}

void motor(int A, int B) {
  analogWrite(enA, abs(A));
  digitalWrite(in1, A > 0);
  digitalWrite(in2, A < 0);

  analogWrite(enB, abs(B));
  digitalWrite(in3, B > 0);
  digitalWrite(in4, B < 0);
}

void setup() {
  Serial.begin(115200);

  for (int p : {in1, in2, in3, in4, enA, enB}) pinMode(p, OUTPUT);
  motor(0, 0); // Pastikan motor mati saat startup

  Serial.println("\n--- Menghubungkan ke WiFi & BLYNK ---");
  Blynk.begin(BLYNK_AUTH_TOKEN, NAMA_WIFI, PASSWORD);
  Serial.println(">>> Ready & Terhubung ke BLYNK! <<<");

  WiFi.setSleep(false);
}

void loop() {
  if (Blynk.connected()) {
    Blynk.run();

    // Deadband untuk mencegah motor berdengung saat joystick di tengah
    int joyX = (abs(x) < 40) ? 0 : x;
    int joyY = (abs(y) < 40) ? 0 : y;

    int spdL = map(joyY - joyX, -1023, 1023, -255, 255);
    int spdR = map(joyY + joyX, -1023, 1023, -255, 255);

    motor(spdL, spdR);

    // Cetak debug setiap 200ms non-blocking (tanpa delay agar Blynk tidak lag)
    if (millis() - lastPrintTime >= 200) {
      lastPrintTime = millis();
      Serial.print("X: "); Serial.print(x);
      Serial.print(" | Y: "); Serial.print(y);
      Serial.print(" | L: "); Serial.print(spdL);
      Serial.print(" | R: "); Serial.print(spdR);
      Serial.print(" | DirL: "); Serial.print((spdL > 0) ? "↑" : (spdL < 0) ? "↓" : "■");
      Serial.print(" | DirR: "); Serial.println((spdR > 0) ? "↑" : (spdR < 0) ? "↓" : "■");
    }
  } else {
    motor(0, 0);
    x = 0;
    y = 0;
  }
}
