# Wiring E220 dan ESP32

## Koneksi utama

| Pin E220 | Pin ESP32 | Keterangan |
|---|---|---|
| TXD | GPIO16 (RX2) | Data dari E220 ke ESP32 |
| RXD | GPIO17 (TX2) | Data dari ESP32 ke E220 |
| M0 | GPIO21 | Mode pin |
| M1 | GPIO19 | Mode pin |
| GND | GND | Ground bersama |
| VCC | Supply sesuai modul | Jangan melampaui spesifikasi E220 |

UART2 menggunakan `HardwareSerial(2)` dengan `SERIAL_8N1` pada 115200 baud. TX dan RX harus disilang: TXD E220 ke RX ESP32, dan RXD E220 ke TX ESP32.

## Mode operasi

Firmware mengatur M0 dan M1 ke LOW untuk mode normal/transparent. Pastikan modul sudah memiliki catu daya dan antena yang sesuai sebelum pengujian RF.

## Catatan frekuensi

Pengujian sementara menggunakan E220-900T30D sekitar 915 MHz. Proyek utama menargetkan E220 433 MHz. Antena harus mengikuti frekuensi modul; antena 433 MHz tidak dijadikan acuan pengukuran pada modul 915 MHz.
