# Data Pengujian

Dataset hasil pengujian dapat disimpan dalam format CSV dengan header:

```csv
timestamp,jarak_m,kondisi,seq,suhu_c,kelembaban_pct,rssi_dbm,snr_db,diterima
```

Keterangan:

- `timestamp`: waktu pencatatan.
- `jarak_m`: jarak TX-RX dalam meter.
- `kondisi`: misalnya `LoS` atau `NLoS`.
- `seq`: nomor urut packet.
- `suhu_c`, `kelembaban_pct`: nilai telemetri.
- `rssi_dbm`, `snr_db`: parameter kualitas sinyal.
- `diterima`: `1` jika diterima dan `0` jika tidak.

File data lokal diabaikan oleh `.gitignore`. Commit dataset hanya jika sudah disepakati tim dan ukurannya wajar.
