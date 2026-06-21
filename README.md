# ESP32-Bluetooth-Controller-Connection
Allows ESP32 to recieve all controller inputs from a bluetooth playstation controller, recognises both joysticks, buttons, and R2 &amp; L2 pressure sensitivity

___
## Setup Instructions
1. Open the Arduino IDE.
2. Navigate to **File -> Preferences**.
3. In the **Additional Boards Manager URLs** field, paste the official Bluepad32 package URL:
   `https://raw.githubusercontent.com/ricardoquesada/esp32-bluepad32/gh-pages/package_esp32_bluepad32_index.json`
4. Go to **Tools -> Board -> Boards Manager...**
5. Search for **Bluepad32** and install the `esp32-bluepad32` platform core package.
6. Go back to **Tools -> Board** and select the esp32_bluepad32 board
<img width="600" alt="image" src="https://github.com/user-attachments/assets/c8f2282b-4342-4342-4f71-bb98deee4de2027" />


___
## Pairing Troubleshooting Instructions
Steps below wipes bluetooth cache and allows board and controller to pair
1. Hold down boot button on ESP32
2. Press EN to restart
3. Use a pin to press down on SD card button on the back of the controller
4. Turn the controller back on
5. Hold PS and Share button to pair
