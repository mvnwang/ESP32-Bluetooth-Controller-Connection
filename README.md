# ESP32-Bluetooth-Controller-Connection
Allows ESP32 to recieve all controller inputs from a bluetooth playstation controller, recognises both joysticks, buttons, and R2 &amp; L2 pressure sensitivity

Setup Instructions
1. Open the Arduino IDE.
2. Navigate to **File -> Preferences**.
3. In the **Additional Boards Manager URLs** field, paste the official Bluepad32 package URL:
   `https://raw.githubusercontent.com/ricardoquesada/esp32-bluepad32/gh-pages/package_esp32_bluepad32_index.json`
4. Go to **Tools -> Board -> Boards Manager...**
5. Search for **Bluepad32** and install the `esp32-bluepad32` platform core package.
