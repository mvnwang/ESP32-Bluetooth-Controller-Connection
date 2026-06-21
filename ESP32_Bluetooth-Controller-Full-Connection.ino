#include <bluepad32.h>

ControllerPtr myControllers[BP32_MAX_GAMEPADS];

void onConnectedController(ControllerPtr ctl) {
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myControllers[i] == nullptr) {
      myControllers[i] = ctl;
      Serial.printf("\n--- DUALSHOCK 4 LINKED TO SYSTEM: SLOT %d ---\n", i);
      break;
    }
  }
}

void onDisconnectedController(ControllerPtr ctl) {
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myControllers[i] == ctl) {
      myControllers[i] = nullptr;
      Serial.println("\n--- Controller Disconnected ---");
    }
  }
}

void processGamepad(ControllerPtr ctl) {
  // 1. DIGITAL BUTTON LABELS
  uint16_t buttons = ctl->buttons();
  if (buttons != 0) {
    Serial.print("Pressed: ");
    if (buttons & BUTTON_A)          Serial.print("[Cross X] ");
    if (buttons & BUTTON_B)          Serial.print("[Circle O] ");
    if (buttons & BUTTON_X)          Serial.print("[Square ▢] ");
    if (buttons & BUTTON_Y)          Serial.print("[Triangle △] ");
    if (buttons & BUTTON_SHOULDER_L) Serial.print("[L1 Bumper] ");
    if (buttons & BUTTON_SHOULDER_R) Serial.print("[R1 Bumper] ");
    Serial.println();
  }

  // 2. D-PAD DIRECTIONS
  uint8_t dpad = ctl->dpad();
  if (dpad != 0) {
    Serial.print("D-Pad: ");
    if (dpad & DPAD_UP)    Serial.print("[UP] ");
    if (dpad & DPAD_DOWN)  Serial.print("[DOWN] ");
    if (dpad & DPAD_LEFT)  Serial.print("[LEFT] ");
    if (dpad & DPAD_RIGHT) Serial.print("[RIGHT] ");
    Serial.println();
  }

  // 3. COMPLETE ANALOG STRUCTURAL MAPPING
  int32_t lx = ctl->axisX();    // Left Stick Horizontal (Fixed)
  int32_t ly = ctl->axisY();    // Left Stick Vertical (Fixed)
  int32_t rx = ctl->axisRX();   // Right Stick Horizontal
  int32_t ry = ctl->axisRY();   // Right Stick Vertical
  int32_t l2 = ctl->brake();    // L2 Trigger Pressure
  int32_t r2 = ctl->throttle(); // R2 Trigger Pressure

  // Left Stick Stream Output
  if (abs(lx) > 30 || abs(ly) > 30) {
    Serial.printf("Left Stick -> X: %d | Y: %d\n", lx, ly);
  }

  // Right Stick Stream Output 
  if (abs(rx) > 30 || abs(ry) > 30) {
    Serial.printf("Right Stick -> X: %d | Y: %d\n", rx, ry);
  }

  // L2 and R2 Trigger Outputs
  if (l2 > 20) {
    Serial.printf("[L2 Trigger Pressure]: %d / 1023\n", l2);
  }
  if (r2 > 20) {
    Serial.printf("[R2 Trigger Pressure]: %d / 1023\n", r2);
  }
}

void setup() {
  Serial.begin(115200);
  delay(500);
  
  BP32.forgetBluetoothKeys(); 
  BP32.setup(&onConnectedController, &onDisconnectedController);
  
  Serial.println("System Active. Turn on your DualShock 4!");
}

void loop() {
  BP32.update();
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    ControllerPtr ctl = myControllers[i];
    if (ctl && ctl->isConnected()) {
      processGamepad(ctl);
    }
  }
  delay(15); 
}