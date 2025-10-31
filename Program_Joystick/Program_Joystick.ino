#define BLYNK_TEMPLATE_ID "Masukkan TEMPLATE ID disini"
#define BLYNK_TEMPLATE_NAME "Masukkan TEMPLATE NAME disini"

#define AUTH_TOKEN "Paste AUTH TOKEN disini"
#define NAMA_WIFI "Masukkan Nama Wifi Disini"
#define PASSWORD "Masukkan Password Wifi Disini"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

const int enA = 1;
const int in1 = 2;
const int in2 = 3;
const int enB = 4;
const int in3 = 5;
const int in4 = 6;

int x = 0, y = 0;

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
  Blynk.begin(AUTH_TOKEN, NAMA_WIFI, PASSWORD);

  for (int p : {in1, in2, in3, in4, enA, enB}) pinMode(p, OUTPUT);

  Serial.println("Ready!");
}

void loop() {
  Blynk.run();

  int spdL = map(y - x, -1023, 1023, -255, 255);
  int spdR = map(y + x, -1023, 1023, -255, 255);

  motor(spdL, spdR);

  Serial.print("X: "); Serial.print(x);
  Serial.print(" | Y: "); Serial.print(y);
  Serial.print(" | L: "); Serial.print(spdL);
  Serial.print(" | R: "); Serial.print(spdR);
  Serial.print(" | DirL: "); Serial.print((spdL > 0) ? "↑" : (spdL < 0) ? "↓" : "■");
  Serial.print(" | DirR: "); Serial.println((spdR > 0) ? "↑" : (spdR < 0) ? "↓" : "■");
  delay(100);
}
