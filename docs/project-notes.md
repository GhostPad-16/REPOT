# Catatan Proyek

- Kelas: 3 D4 Teknik Telekomunikasi A.
- Mikrokontroler: ESP32.
- Modul RF: EBYTE E220.
- Target: komunikasi point-to-point TX -> RF -> RX.
- Data: sequence, suhu, dan kelembaban.
- Serial Monitor: 115200 baud.
- Target utama: E220 433 MHz.
- Pengujian sementara: E220-900T30D sekitar 915 MHz.

Saat ini satu ESP32 rusak dan baru tersedia satu E220. Karena itu, komunikasi RF point-to-point belum dapat diuji. Antena 433 MHz yang tersedia juga mismatch dengan modul 915 MHz dan tidak digunakan sebagai acuan pengujian.

Komunikasi UART ESP32 dengan E220 dan pengiriman string dari program TX sudah menjadi hasil awal yang tersedia. RSSI, SNR, packet error rate, jarak, LoS/NLoS, dan polarisasi akan diuji setelah perangkat lengkap.
