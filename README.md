# Sistem Komunikasi Point-to-Point ESP32 dan E220

Proyek kelas **3 D4 Teknik Telekomunikasi A** ini merancang sistem komunikasi point-to-point untuk transmisi teks/telemetri menggunakan ESP32 dan modul RF EBYTE E220. Node TX mengirim data telemetri melalui UART dalam mode transparent, kemudian node RX menerima dan menampilkan data tersebut.

## 1. Tujuan proyek

- Membangun jalur komunikasi TX -> RF E220 -> RX.
- Mengirim telemetri sederhana berupa sequence, suhu, dan kelembaban.
- Mengukur performa komunikasi RF pada beberapa kondisi jarak dan lingkungan.
- Menyediakan repository yang rapi agar pekerjaan anggota mudah digabung melalui GitHub.

## 2. Arsitektur sistem

```text
Sensor/data dummy
       |
       v
ESP32 TX --UART2--> E220 TX -- RF link --> E220 RX --UART2--> ESP32 RX
                                                                    |
                                                                    v
                                                        Serial Monitor / logger
```

Firmware saat ini menggunakan data dummy. Integrasi sensor dan dashboard dapat dikerjakan sebagai pengembangan terpisah.

## 3. Hardware yang digunakan

- ESP32 (minimal dua unit untuk pengujian point-to-point).
- EBYTE E220-900T30D sekitar 915 MHz untuk pengujian sementara.
- EBYTE E220 433 MHz untuk target utama proyek.
- Antena yang sesuai dengan frekuensi modul.
- Kabel jumper dan catu daya sesuai kebutuhan modul.
- Komputer dengan Arduino IDE atau VS Code + PlatformIO.

> Antena harus sesuai frekuensi modul. Antena 433 MHz tidak digunakan sebagai acuan pengujian E220 915 MHz.

## 4. Wiring E220 ke ESP32

| E220 | ESP32 |
|---|---|
| TXD | GPIO16 (RX2) |
| RXD | GPIO17 (TX2) |
| M0 | GPIO21 |
| M1 | GPIO19 |
| GND | GND |
| VCC | Supply sesuai spesifikasi modul |

Detail dan catatan keselamatan pengkabelan ada di [`docs/wiring.md`](docs/wiring.md).

## 5. Format data

Packet dari TX menggunakan format:

```text
seq,suhu,lembab
```

Contoh:

```text
12,29.5,68.0
```

Output RX yang direncanakan untuk logger/dataset:

```text
seq,suhu,lembab,rssi,snr
```

RSSI dan SNR belum dibaca oleh firmware saat ini karena hardware dan metode pembacaannya belum lengkap. RX menampilkan data yang sudah diparse dan menyediakan lokasi integrasi untuk dua nilai tersebut.

## 6. Kondisi pengujian saat ini

- Baru tersedia satu ESP32 yang berfungsi dan satu E220.
- Komunikasi RF point-to-point belum dapat diuji.
- Komunikasi UART ESP32 <-> E220 dan pengiriman string dari TX sudah dapat dijalankan.
- E220 sementara bekerja sekitar 915 MHz, sedangkan antena yang tersedia 433 MHz sehingga belum digunakan sebagai acuan pengujian RF.
- Pengujian jarak, RSSI, SNR, packet error rate, LoS/NLoS, dan polarisasi menunggu perangkat lengkap serta antena yang sesuai.

## 7. Menjalankan program TX

1. Buka `firmware/tx/tx.ino` di Arduino IDE.
2. Pilih board ESP32 dan port ESP32 TX.
3. Pastikan wiring mengikuti tabel di atas.
4. Upload program.
5. Buka Serial Monitor pada **115200 baud**.
6. TX mengirim data dummy setiap 2 detik dan menampilkan baris `TX -> ...`.

## 8. Menjalankan program RX

1. Buka `firmware/rx/rx.ino` di Arduino IDE.
2. Pilih board ESP32 dan port ESP32 RX.
3. Pastikan wiring mengikuti tabel di atas.
4. Upload program.
5. Buka Serial Monitor pada **115200 baud**.
6. RX menunggu packet, memvalidasi tiga field, lalu menampilkan hasil parsing.

## 9. Rencana pengujian RF

Setelah tersedia dua ESP32, dua E220, dan antena yang sesuai:

1. Uji komunikasi jarak dekat sebagai baseline.
2. Uji jarak bertahap pada kondisi line-of-sight.
3. Uji kondisi NLoS atau penghalang yang disepakati.
4. Catat sequence yang terkirim, diterima, hilang, RSSI, SNR, jarak, dan kondisi lingkungan.
5. Bandingkan hasil E220 433 MHz sebagai konfigurasi utama dan E220 915 MHz sebagai konfigurasi sementara bila perangkat/antena mendukung.

Format rencana pencatatan dijelaskan di [`docs/testing.md`](docs/testing.md).

## 10. Format dataset hasil pengujian

Gunakan CSV dengan header:

```csv
timestamp,jarak_m,kondisi,seq,suhu_c,kelembaban_pct,rssi_dbm,snr_db,diterima
```

Contoh:

```csv
2026-10-09T10:00:00,10,LoS,12,29.5,68.0,-70,10.0,1
```

File hasil pengujian lokal diletakkan di `data/` dan tidak ikut di-commit secara default. Commit hanya dataset yang memang sudah disepakati tim.

## 11. Pembagian pekerjaan anggota

Contoh pembagian:

- Anggota 1: firmware TX dan format packet.
- Anggota 2: firmware RX dan validasi packet.
- Anggota 3: wiring, konfigurasi E220, dan pengujian RF.
- Anggota 4: logger, dataset, dan analisis hasil.
- Anggota 5: dashboard dan dokumentasi.

Sesuaikan pembagian dengan jumlah anggota. Setiap perubahan dikerjakan di branch sendiri dan diajukan melalui Pull Request.

## Struktur repository

- `firmware/tx/`: program pengirim.
- `firmware/rx/`: program penerima.
- `docs/`: wiring, metode pengujian, dan catatan proyek.
- `logger/`: rencana pencatatan data.
- `dashboard/`: rencana visualisasi.
- `data/`: format dan aturan penyimpanan dataset.

Panduan kontribusi ada di [`CONTRIBUTING.md`](CONTRIBUTING.md).
