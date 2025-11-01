
  # Assalaam Robotics Eduplay 2025 x Robot Research UMS
    
  <a href="https://ibb.co.com/Kj2XXzsV"><img src="https://i.ibb.co.com/Kj2XXzsV/pamflet1.jpg" alt="pamflet1" border="0"></a>
    
  ## Getting Started (English)
  #### Download the Arduino IDE
  * Download the Arduino IDE from [ Arduino Website](https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.6_Windows_64bit.exe)
  * Run the .exe file to install it

  #### Set up the Arduino IDE
  1. Download the main zip file(Links below).
  2. Extract the `Program_Utama.zip`(or `Program_Joystick.zip` if you used that) and open the folder.
  3. There are subfolders there, open one of these and open the `.ino` file.
  4. From Arduino IDE, open the tab file then preferences
  5. Scroll down until found `Additional board manager URLs`
  6. Write down a new line with:

    https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
  7. Go Back to workspace, open the Boards Manager on the left side
  8. Search for `esp32` by `Espressif` and download the latest version
  9. Open tab `Tools`, Choose **Boards** > **esp32** > **ESP32C3 Dev Module** (if it doesn't exist, Go back to step 4)

  #### Coding
  10. Get the `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, and `AUTH_TOKEN` from [blynk Website](https://www.blynk.io/)
  11. Change the first and second lines of code to your template id and name,  
  * Change this two lines:   
```cpp
#define BLYNK_TEMPLATE_ID "Masukkan TEMPLATE ID disini"
#define BLYNK_TEMPLATE_NAME "Masukkan TEMPLATE NAME disini"
```
  * the result will looks like:
```cpp
#define BLYNK_TEMPLATE_ID "TMPL6EC4r43si"
#define BLYNK_TEMPLATE_NAME "AssalaamTest"
```
  12. Change the `AUTH_TOKEN` in this code,
  * in this line:
```cpp
#define AUTH_TOKEN "Paste AUTH TOKEN disini"
```
  *   change the `Paste AUTH TOKEN disini` to your auth token from blynk > devices,  
  13. Input your WiFi name and Password, in this two line:
```cpp
#define NAMA_WIFI "Masukkan NAMA WIFI disini"
#define PASSWORD "Masukkan PASSWORD disini"
```
  *   input your mobile wifi name and password (it will not consume any mobile data)
  14. Click the compile button on the top left Arduino IDE
  15. If there are no existing errors messages, then continue to the uploading section
  
  #### Uploading
  16. Connect the laptop to ESP32 C3 using a type C cable
  17. Go to tab `Tools` then `Port`, Choose the existing COM (it depends on your laptop, generally it says COMx(ESP32 Family Device))
  18. Click the Upload button
  19. Wait for the Upload to be done
  20. if it can't be uploaded, go back to step 9, change the board `ESP32C3 Dev Module` to `Adafruit QT Py ESP32-C3`
  21. All's good, Your robot is on duty
    
  *If there is a problem, ask to ur bro to fix it*

## Petunjuk untuk Memulai (Bahasa Indonesia)

### Unduh Arduino IDE
- 📥 Unduh **Arduino IDE** dari [Situs Resmi Arduino](https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.6_Windows_64bit.exe)  
- ⚙️ Jalankan file `.exe` untuk menginstalnya di laptop kamu

---

### Siapkan Arduino IDE
1. 📦 **Unduh file utama ZIP** (tautan tersedia di bawah).  
2. 🗂️ Ekstrak file `Program_Utama.zip`(atau `Program_Joystick.zip` jika kamu pakai itu) lalu buka foldernya.  
3. 📁 Di dalamnya ada subfolder, buka folder tersebut dan buka file `.ino` menggunakan Arduino IDE.  
4. ⚙️ Dari Arduino IDE, buka **File > Preferences (Preferensi)**.  
5. 🔽 Gulir ke bawah sampai menemukan bagian `Additional Board Manager URLs`.  
6. 📝 Tambahkan baris baru berisi:

    ```
    https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
    ```
7. 🧭 Kembali ke workspace, buka **Boards Manager** di sisi kiri.  
8. 🔍 Cari `esp32` dari **Espressif** dan unduh versi terbaru.  
9. 🧩 Buka **Tools > Board**, pilih **esp32 > ESP32C3 Dev Module**  
   (kalau belum muncul, ulangi langkah 4–6).

---

### Penulisan Kode Program
10. 🌐 Dapatkan `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, dan `AUTH_TOKEN` dari [Situs Blynk](https://www.blynk.io/).  
11. ✏️ Ganti dua baris pertama kode dengan template ID dan nama kamu:  

    ```cpp
    #define BLYNK_TEMPLATE_ID "Masukkan TEMPLATE ID disini"
    #define BLYNK_TEMPLATE_NAME "Masukkan TEMPLATE NAME disini"
    ```
    💡 Setelah diubah nanti akan terlihat seperti ini:
    ```cpp
    #define BLYNK_TEMPLATE_ID "TMPL6EC4r43si"
    #define BLYNK_TEMPLATE_NAME "AssalaamRobot"
    ```

12. 🔑 Ganti bagian `AUTH_TOKEN`:
    ```cpp
    #define AUTH_TOKEN "Paste AUTH TOKEN disini"
    ```
    → ubah `"Paste AUTH TOKEN disini"` jadi token kamu dari **Blynk > Devices**  

13. 📶 Masukkan nama dan kata sandi WiFi:
    ```cpp
    #define NAMA_WIFI "Masukkan NAMA WIFI disini"
    #define PASSWORD "Masukkan PASSWORD disini"
    ```
    💬 Gunakan hotspot HP kamu — tenang, nggak bakal ngambil kuota.  

14. 🧠 Klik tombol **✅ Compile** di kiri atas Arduino IDE.  
15. ✅ Kalau tidak ada pesan error, lanjut ke langkah berikutnya!

---

### Mengunggah Program ke ESP32
16. 🔌 Hubungkan laptop ke **ESP32-C3** pakai kabel **Type-C**.  
17. ⚙️ Buka **Tools > Port**, lalu pilih port COM yang sesuai  
    *(biasanya tertulis seperti: `COMx (ESP32 Family Device)`)*  
18. ⏫ Klik tombol **Upload (⭱)**.  
19. ⏳ Tunggu proses upload selesai.  
20. ⚠️ Kalau gagal upload, ulangi langkah ke 9 dan ubah board ke  
    **Adafruit QT Py ESP32-C3**.  
21. 🎉 Selesai! Robot kamu siap bertugas 💪🤖

*jika terdapat pesan error atau ada kebingungan, silahkan tanya kakak-kakak yang bertugas*

---

🧾 **Catatan Tambahan:**
- Pastikan koneksi internet stabil saat pertama kali download **Board Espressif**.  
- Kalau error `Permission denied` muncul di Windows, jalankan Arduino IDE sebagai **Administrator**.  
- Simpan semua file `.ino` dalam satu folder yang sama.  

---

✨ *Dibuat dengan ❤️ oleh team Assalaam Robotics Eduplay 2025*


  ## Download Release(s)
  * [Program_Utama.zip](https://github.com/izzumhd/Assalaam_Robotics_Eduplay_2025/releases/download/v1.0.1/Program_Utama.zip)  
  * [Program_Joystick.zip](https://github.com/izzumhd/Assalaam_Robotics_Eduplay_2025/releases/download/v1.0.1/Program_Joystick.zip)
  * Modul Pembelajaran (pdf)
  
  ## Library
  library blynk download dari arduino ide :)  
  atau jika ingin [install manual disini](https://github.com/blynkkk/blynk-library/releases/tag/v1.3.2)
  
  ## About
  | **Nama file** | **Keterangan** |
  |:----------|:-----------|
  | `Program_Utama` | Program utama dasar dengan button sebagai kontrol utama |
  | `Program_Joystick` | Program dengan joystick sebagai kontrol utama(optional) |

  *October 30th, 2025. Regards*  
  *izzumhdh*
