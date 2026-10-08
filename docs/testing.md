# Rencana Pengujian

## Tahap yang tersedia sekarang

Dengan satu ESP32 yang berfungsi dan satu E220, lakukan pemeriksaan:

- board dapat di-upload;
- Serial Monitor berjalan pada 115200 baud;
- UART2 menerima dan mengirim data;
- pin M0 dan M1 dapat diatur LOW;
- TX menghasilkan packet dummy setiap 2 detik.

Tahap ini bukan pengujian komunikasi RF point-to-point.

## Tahap pengujian RF

Sebelum dimulai, siapkan dua ESP32, dua E220, antena sesuai frekuensi, dan catu daya yang memadai.

1. Uji jarak dekat dengan konfigurasi yang sama pada TX dan RX.
2. Tambah jarak secara bertahap dan catat hasil setiap titik.
3. Uji LoS dan NLoS secara terpisah.
4. Catat jumlah packet dikirim, jumlah packet diterima, sequence yang hilang, RSSI, SNR, waktu, dan kondisi.
5. Ulangi pengukuran agar hasil dapat dibandingkan.

Gunakan `data/README.md` sebagai acuan header dataset. Jangan menyimpulkan performa 915 MHz menggunakan antena 433 MHz.
