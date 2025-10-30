  ﻿# Assalaam Robotics Eduplay 2025 x Robot Research UMS

  ## Getting Started
  ### Set up the Arduino IDE
  1. Download the main zip file.
  2. Extract the `Assalaam_Robotics_Eduplay_2025-main.zip` and open the folder.
  3. There are some subfolders there, open one of these and open the `.ino` file.
  4. From Arduino IDE, open the tab file then preferences
  5. Scroll down until found `Additional board manager URLs`
  6. Add new line with `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
  7. Back to workspace, open the Boards Manager in the left side
  8. Search `esp32` by `Espressif` and download the latest version
  9. Open tab `Tools` above, Choose boards menu > esp32 > ESP32C3 Dev Module (if it doesn't exist, repeat to step 7)

  ### Coding
  10. Get the `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, and `AUTH_TOKEN` from [blynk Website](https://www.blynk.io/)
  11. Paste the text on the website one by one in inside quotation marks, example `"Masukkan TEMPLATE ID disini"`
  12. Get the `NAMA_WIFI` and `PASSWORD` from your mobile hotspot
  13. Paste in inside quotation marks
  14. Click the compile button on the top left Arduino IDE
  15. If there are no existing errors messages, then continue to the uploading section
  
  ### Uploading
  16. Connect the laptop to the ESP using a type C cable
  17. Go to tab `Tools` then `Port`, Choose the existing one(it depends on your laptop, generally it says COMx(ESP32 Family Device))
  18. Click the Upload button
  19. Wait for the Uploading to be done
  20. All's good, Your robot ready to duty
    
  *If there is a problem, ask to ur bro to fix it*
    
  ## Petunjuk Memulai
  ### Menyeting Arduino IDE
  1. arti'no dewe ah, males cok

  ## Library
  gaada libraryne download dari arduino ide :)
  
  ## Penjelasan file
  | Nama file | Keterangan |
  |:----------|:-----------|
  | Program_Utama | Program utama dasar dengan button sebagai kontrol utama |
  | Program_Joystick | Program dengan joystick sebagai kontrol utama(experimental) |
  
  *October 30th, 2025*
  *izzumhdh*
