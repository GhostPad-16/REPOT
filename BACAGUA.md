# Kesimpulan Pengujian Awal E220

## Kondisi Saat Ini

- ESP32 yang tersedia ada satu yang rusak, jadi sementara hanya bisa menggunakan **1 ESP32**.
- Modul E220 yang tersedia juga baru **1 buah**, jadi belum bisa melakukan komunikasi point-to-point TX → RX.
- Pengujian sementara hanya memastikan **ESP32 ↔ E220 lewat UART** sudah berjalan.
- Program TX sudah berhasil mengirim data/string ke E220.
- Untuk pengujian RF sebenarnya masih harus menunggu **ESP32 dan E220 kedua**.

## Wiring E220 ke ESP32

| E220 | ESP32 |
|---|---|
| TXD | GPIO 16 (RX2) |
| RXD | GPIO 17 (TX2) |
| M0 | GPIO 21 |
| M1 | GPIO 19 |
| GND | GND |
| VCC | Supply sesuai modul |

## Masalah Antena

Saat ini antena yang tersedia **433 MHz**, sedangkan E220 yang digunakan bekerja di sekitar **915 MHz**.

Jadi antenanya **mismatch** dan belum cocok untuk pengujian RF 915 MHz. Antena 433 MHz sebaiknya tidak dijadikan acuan untuk pengukuran jarak, RSSI, atau kualitas sinyal.

Untuk pengujian E220-900T30D sebaiknya menggunakan antena sekitar **915 MHz**.

Sedangkan untuk proyek utama yang menggunakan E220 **433 MHz**, gunakan antena **433 MHz**.

## Kesimpulan

Untuk sementara, yang sudah terbukti adalah **ESP32 dapat berkomunikasi dengan E220 melalui UART dan program TX dapat berjalan**. Pengujian komunikasi melalui udara, RSSI, PER, jarak, LoS/NLoS, dan polarisasi belum bisa dilakukan karena perangkat belum lengkap dan antena yang tersedia tidak sesuai frekuensi.