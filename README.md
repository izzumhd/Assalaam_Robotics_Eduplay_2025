
  # Assalaam Robotics Eduplay 2025 x Robot Research UMS
    
  <a href="https://ibb.co.com/Kj2XXzsV"><img src="https://i.ibb.co.com/Kj2XXzsV/pamflet1.jpg" alt="pamflet1" border="0"></a>
    
  ## Getting Started
  #### Download the Arduino IDE
  * Download the Arduino IDE from [ Arduino Website](https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.6_Windows_64bit.exe)
  * Run the .exe file to install it

  #### Set up the Arduino IDE
  1. Download the main zip file(Links below).
  2. Extract the `Assalaam_Robotics_Eduplay_2025-main.zip` and open the folder.
  3. There are some subfolders there, open one of these and open the `.ino` file.
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

  ## Petunjuk Memulai
  #### Menyeting Arduino IDE
  1. arti'no dewe ah, males cok

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

  *October 30th, 2025*  
  *izzumhdh*










