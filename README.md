# Dioxi

<p align="center">
  <img src="assets/dioxi.svg" alt="Dioxi, a small violet robot waving" width="200"><br>
  <em>hi, I'm Dioxi!</em>
</p>

Hi! I'm Dioxi, a little ESP32 that lives in your room and keeps an eye on the air. I measure CO₂, temperature and humidity, and when the air gets stuffy I'll tell you it's time to open a window.

## Setup

1. In `src/dioxi/`, copy `secrets.h.example` to `secrets.h` and fill in your WiFi SSID and password.
2. Open `src/dioxi/dioxi.ino` in the Arduino IDE, select your ESP32 board, and upload.
3. Open the Serial Monitor at 115200 baud.
