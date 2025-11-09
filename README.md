
  # Assalaam Robotics Eduplay 2025 x Robot Research UMS
  ## Tutorial & Panduan mengenai Robot Soccer
    
  <img src="Common Files/Pamflet.jpg" alt="" width="250">
    
  # SILAHKAN DIBACA dan DIPERHATIKAN  
  Setelah melakukan perakitan, Untuk mensetting robot soccer ini hal yang selanjutnya dilakukan adalah mengisi program pada ESP32c3 (Mikrokontroller), ini dilakukan supaya robot dapat dikontrol menggunakan Handphone. Oleh karenanya maka penting untuk membaca dan memahami langkah langkah berikut ini secara berurutan supaya robot dapat lancar untuk dimainkan. Goodluck!  

---

## Daftar isi
* [Petunjuk Untuk Memulai](#Petunjuk-untuk-Memulai)
  - [Siapkan BLYNK](#Siapkan-BLYNK)
  - [Siapkan Arduino IDE](#Siapkan-Arduino-IDE)
  - [Siapkan Program Utama](#Siapkan-Program-Utama)
  - [Penulisan Kode Program(Coding)](#Penulisan-Kode-Program)
  - [Upload program ke ESP32](#Upload-Program-ke-ESP32)
* [Getting Started(English)](#Getting-Started(English))
* [Download Release(s)](#Download-Releases)
* [Library](#Library)
* [About File](#About-File)

---

## Petunjuk untuk Memulai

### Siapkan BLYNK
1. Buka Blynk Website: [www.blynk.io](https://www.blynk.io/) dan silahkan login dengan akun kalian
    <img src="Common Files/BLYNK_1.png" alt="" width="600">  
    > **Note:** Jika belum pernah melakukan login, Maka klik Create New Account lalu masukkan akun google kalian.  
    > Setelah itu cek Gmail, nantinya kamu akan dapat email seperti ini:  
    > <img src="Common Files/BLYNK_1b.png" alt="" width="400">  
    > buka email itu dan click **Complete Setup**  
    > <img src="Common Files/BLYNK_1c.png" alt="" width="400">  
2. Setelah berhasil login, maka tampilannya akan seperti ini  
    <img src="Common Files/BLYNK_2.png" alt="" width="600">
3. Masuk ke Menu **Developer zone**, Lalu buat template baru dengan klik **New Template**  
    <img src="Common Files/BLYNK_3.png" alt="" width="600">
4. Isi nama template(bebas mau diisi apa saja, contoh disini saya isi BumbleBee), Hardware diisi ESP32 dan Connection Type diisi WiFi, Lalu klik done  
    <img src="Common Files/BLYNK_4.png" alt="" width="600">
5. Copy teks bertuliskan `#define BLYNK_TEMPLATE_ID "TMPL6iBc4WRAE" #define BLYNK_TEMPLATE_NAME "BumbleBee"` seperti pada gambar, lalu simpan ke notepad  
    <img src="Common Files/BLYNK_5.png" alt="" width="600">  
    * Simpan sementara teks tersebut ke notepad seperti gambar di bawah ini   
    <img src="Common Files/BLYNK_5b.png" alt="" width="500">

    > catatan: Notepad adalah aplikasi windows terpisah, bisa kamu buka sendiri lewat start menu dan cari *Notepad*
6. Masih di **Developer Zone**, Pergi ke menu **Datastream**, lalu klik **New Datastream** dan pilih **Virtual pin** (seperti pada gambar dibawah)  
    <img src="Common Files/BLYNK_6.png" alt="" width="600">
7. Set pin ke V2(seperti pada gambar), nilai Min diisi 0, nilai Max diisi 1, dan default value diisi 0. lalu klik Create  
    <img src="Common Files/BLYNK_7.png" alt="" width="600">
8. Pergi ke Menu **Devices**, klik **New Devices** di pojok kanan, Lalu pilih **From Template**  
    <img src="Common Files/BLYNK_8.png" alt="" width="600">
9. Pilih Template berdasarkan nama yang kamu buat tadi, lalu klik **Create**   
    <img src="Common Files/BLYNK_9.png" alt="" width="600">
10. Kembali ke menu **Devices**, Copy Auth Token seperti pada gambar dibawah ini ke notepad(bersama teks pada poin 5).  
    <img src="Common Files/BLYNK_11.png" alt="" width="600">
    * Paste teks tersebut ke notepad, Kamu akan punya 3 baris kode seperti ini:  
    <img src="Common Files/BLYNK_11b.png" alt="" width="500">

    > di dalam notepad kurang lebih isinya akan seperti ini:  
    > ```
    > #define BLYNK_TEMPLATE_ID "TMPL6iBc4WRAE"
    > #define BLYNK_TEMPLATE_NAME "BumbleBee"
    > qSrTZTjHB0xKkP3VBRrdWi0C8EhdV3bY
    > ```
    > Baris Pertama adalah template id  
    > Baris Kedua adalah template name  
    > Baris Ketiga adalah Auth token  
    > Penting: 3 baris teks tersebut akan digunakan dalam bagian *Penulisan Kode Program*  
    >
11. Buka Aplikasi Blynk yang sudah terinstall di Handphone-mu, jika belum ada silahkan install di PlayStore(Android) atau AppStore(iOS).  
12. Login seperti biasa dengan akun yang sama saat login di website blynk.  
13. Pilih template yang tadi dibuat, lalu klik tombol/ikon kunci pas di atas tampilan  
    <img src="Common Files/HP1.jpg" alt="" width="200"> <img src="Common Files/HP2.jpg" alt="" width="200">
14. Ketuk ikon seperti yang ditunjuk pada gambar dibawah ini lalu pilih Create Virtual Pin Datastream  
    <img src="Common Files/new/hp1.jpg" alt="" width="200"> <img src="Common Files/new/hp2.jpg" alt="" width="200"> 
15. Atur Virtual Pin Number ke V2 **(Virtual Pin Number 2)**, Data type Integer, Min 0, Max 1, Default Value 0, dan kasih Nama 'Gerak Maju'(ikuti seperti pada gambar dibawah)  
    <img src="Common Files/new/hp3.jpg" alt="" width="200"> <img src="Common Files/HP8.jpg" alt="" width="200"> 
16. Kembali ke template settings, pilih Create New, Atur Virtual Pin Number ke V3 **(Virtual Pin Number 3)**, Data type Integer, Min 0, Max 1, Default Value 0, dan kasih Nama 'Gerak Mundur'(ikuti seperti pada gambar dibawah)  
    <img src="Common Files/new/hp4.jpg" alt="" width="200"> <img src="Common Files/new/hp5.jpg" alt="" width="200"> 
17. Kembali lagi ke template settings, Create New lagi, Atur Virtual Pin Number ke V4 **(Virtual Pin Number 4)**, Data type Integer, Min 0, Max 1, Default Value 0, dan kasih Nama 'Belok ke Kiri'(ikuti seperti pada gambar dibawah)  
    <img src="Common Files/new/hp6.jpg" alt="" width="200"> <img src="Common Files/new/hp7.jpg" alt="" width="200"> 
18. Kembali ke template settings lagi, Create New, Atur Virtual Pin Number ke V5 **(Virtual Pin Number 5)**, Data type Integer, Min 0, Max 1, Default Value 0, dan kasih Nama 'Belok ke Kanan'(ikuti seperti pada gambar dibawah)  
    <img src="Common Files/new/hp8.jpg" alt="" width="200"> <img src="Common Files/new/hp9.jpg" alt="" width="200"> 
19. Setelah membuat 4 Datastream seperti ini, lalu kembali ke settings utama dan ketuk ikon plus ( + )  
    <img src="Common Files/new/hp10.jpg" alt="" width="200"> <img src="Common Files/new/hp11.jpg" alt="" width="200"> 
20. Pilih Button, lalu tampilannya akan menjadi seperti ini   
    <img src="Common Files/new/hp12.jpg" alt="" width="200"> <img src="Common Files/new/hp12b.jpg" alt="" width="200"> 
21. Ulangi langkah tersebut 4 kali untuk mendapatkan 4 tombol dan atur tata letaknya seperti ini(Ketuk dan tahan tombol untuk menggesernya)  
    <img src="Common Files/new/hp13.jpg" alt="" width="200"> <img src="Common Files/new/hp14.jpg" alt="" width="200"> 
22. Ketuk tombol yang paling atas untuk masuk ke pengaturan tombol, Pilih Choose datastream lalu pilih `Gerak Maju[V2]`, lalu kembali ke utama     
    <img src="Common Files/new/hp15.jpg" alt="" width="200"> <img src="Common Files/new/hp16.jpg" alt="" width="200"> 
24. Ulangi langkah tersebut pada tombol lainnya dengan memasangkan sisanya ke Gerak Mundur, Belok ke Kiri, dan Belok ke Kanan, menjadi seperti seperti gambar ke-2  
    <img src="Common Files/new/hp17.jpg" alt="" width="200"> <img src="Common Files/new/hp17b.jpg" alt="" width="200"> 
25. (Opsional) Kamu bisa mengubah tampilan menjadi Landscape(HP miring) jika ingin sensasi kontrol seperti video game, cukup tukar saja posisi tombolnya menjadi seperti ini   
    <img src="Common Files/new/hp18.jpg" alt="" width="500">  
26. (Opsional) Jika ingin mengubah desain tombol menjadi seperti ini juga bisa(ubah pada menu **Design**)
    <img src="Common Files/new/hp19.jpg" alt="" width="500">
27. Jika semua sudah selesai dan siap, Saatnya lanjut ke tahap berikutnya.  

### Siapkan Arduino IDE
- Unduh **Arduino IDE** dari [Situs Resmi Arduino](https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.6_Windows_64bit.exe)  
- Jalankan file `.exe` untuk menginstalnya di laptop kamu

### Siapkan Program Utama
1. **Unduh file utama ZIP**, [klik disini untuk mendownload](https://github.com/izzumhd/Assalaam_Robotics_Eduplay_2025/releases/download/v1.0.1/Program_Utama.zip), atau bisa download di menu Release(s) dibawah.  
2. Ekstrak file `Program_Utama.zip`(atau `Program_Joystick.zip` jika kamu pakai itu) lalu buka foldernya.  
3. Di dalamnya ada subfolder, buka folder tersebut dan buka file `.ino` menggunakan Arduino IDE.  
4. Dari Arduino IDE, buka **File > Preferences (Preferensi)**.  
5. Gulir ke bawah sampai menemukan bagian `Additional Board Manager URLs`.  
6. Tambahkan baris baru berisi:

    ```
    https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
    ```
7. Kembali ke workspace, buka **Boards Manager** di sisi kiri.  
8. Cari `esp32` dari **Espressif** dan unduh versi terbaru.  
9. Buka **Tools > Board**, pilih **esp32 > ESP32C3 Dev Module**  
   (kalau belum muncul, ulangi langkah 4–6).

### Penulisan Kode Program
10. Buka Notepad, Pastikan kamu sudah dapat `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, dan `AUTH_TOKEN` dari langkah bagian pertama(blynk)
    Yang kurang lebih isinya 3 baris kode seperti ini:
    ```
    #define BLYNK_TEMPLATE_ID "TMPL6iBc4WRAE"
    #define BLYNK_TEMPLATE_NAME "BumbleBee"
    qSrTZTjHB0xKkP3VBRrdWi0C8EhdV3bY
    ```
12. Pada Arduino IDE, Ganti/masukkan dua baris pertama kode dengan template ID dan Template name kamu(baris ke 1&2 Notepad):  

    ```cpp
    #define BLYNK_TEMPLATE_ID "Masukkan TEMPLATE ID disini"
    #define BLYNK_TEMPLATE_NAME "Masukkan TEMPLATE NAME disini"
    ```
    Setelah diubah nanti kurang lebih akan terlihat seperti ini:
    ```cpp
    #define BLYNK_TEMPLATE_ID "TMPL6iBc4WRAE"
    #define BLYNK_TEMPLATE_NAME "BumbleBee"
    ```

13. Ganti bagian `AUTH_TOKEN`:
    ```cpp
    #define AUTH_TOKEN "Paste AUTH TOKEN disini"
    ```
    → ubah `"Paste AUTH TOKEN disini"` ke token yang sudah kamu dapat(Baris ke 3 di Notepad),
    Hasilnya nanti akan mirip seperti ini:
    ```cpp
    #define AUTH_TOKEN "qSrTZTjHB0xKkP3VBRrdWi0C8EhdV3bY"
    ```

15. Masukkan nama dan kata sandi WiFi:
    ```cpp
    #define NAMA_WIFI "Masukkan NAMA WIFI disini"
    #define PASSWORD "Masukkan PASSWORD disini"
    ```
    Ganti dengan nama dan password hotspot HP kamu — *tenang, nggak bakal ngambil kuota.*  

16. Klik tombol **✅ Compile** di kiri atas Arduino IDE.  
17. Apabila sudah tidak ada pesan error, lanjut ke langkah berikutnya!

### Upload Program ke ESP32
16. Hubungkan laptop ke **ESP32-C3** menggunakan kabel **Type-C**.  
17. Buka **Tools > Port**, lalu pilih port COM yang sesuai  
    *(biasanya tertulis seperti: `COMx (ESP32 Family Device)`)*  
18. Klik tombol **Upload (⭱)**.  
19. Tunggu proses upload selesai.  
20. Kalau gagal upload, ulangi langkah ke 9 dan ubah board ke  
    **Adafruit QT Py ESP32-C3**.  
21. Selesai! Robot kamu siap bertugas 💪🤖

*jika terdapat pesan error atau ada kebingungan, silahkan bertanya ke kakak-kakak yang bertugas ;)*

---

> 🧾 **Catatan Tambahan:**
- Pastikan koneksi internet stabil saat pertama kali download **Board Espressif**.  
- Kalau error `Permission denied` muncul di Windows, jalankan Arduino IDE sebagai **Administrator**.  
- Simpan semua file `.ino` dalam satu folder yang sama.  

✨ *Dibuat oleh team Assalaam Robotics Eduplay 2025*

---

## Getting Started (English)
  > ### Download the Arduino IDE
  * Download the Arduino IDE from [ Arduino Website](https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.6_Windows_64bit.exe)
  * Run the .exe file to install it

  > ### Set up the Arduino IDE
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

  > ### Coding
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
  
  > ### Uploading
  16. Connect the laptop to ESP32 C3 using a type C cable
  17. Go to tab `Tools` then `Port`, Choose the existing COM (it depends on your laptop, generally it says COMx(ESP32 Family Device))
  18. Click the Upload button
  19. Wait for the Upload to be done
  20. if it can't be uploaded, go back to step 9, change the board `ESP32C3 Dev Module` to `Adafruit QT Py ESP32-C3`
  21. All's good, Your robot is on duty
    
  *If there is a problem, ask to ur bro to fix it*

---


  ## Download Releases
  * [Program_Utama.zip](https://github.com/izzumhd/Assalaam_Robotics_Eduplay_2025/releases/download/v1.0.1/Program_Utama.zip)  
  * [Program_Joystick.zip](https://github.com/izzumhd/Assalaam_Robotics_Eduplay_2025/releases/download/v1.0.1/Program_Joystick.zip)  
  * [Modul Pembelajaran (pdf)](https://github.com/izzumhd/Assalaam_Robotics_Eduplay_2025/releases/download/v1.0.1/Modul_RobotSoccer.pdf)  
    
  ## Library
  library blynk download dari arduino ide :)  
  atau jika ingin [install manual disini](https://github.com/blynkkk/blynk-library/releases/tag/v1.3.2)
  
  ## About File
  | **Nama file** | **Keterangan** |
  |:----------|:-----------|
  | `Program_Utama` | Program utama dasar dengan button sebagai kontrol utama |
  | `Program_Joystick` | Program dengan joystick sebagai kontrol utama(optional) |
  | `Common File` | Berisi Gambar tutorial |
     
  *October 30th, 2025. Regards*  
  *izzumhdh*


























