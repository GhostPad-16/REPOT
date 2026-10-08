# Panduan Kontribusi

Repository ini menggunakan branch sederhana:

- `main`: versi stabil.
- `feature/*`: pengembangan fitur, contoh `feature/tx-program`, `feature/rx-program`, `feature/dashboard`.
- `fix/*`: perbaikan bug.
- `docs/*`: perubahan dokumentasi, contoh `docs/project-update`.

## Alur kerja anggota

### 1. Clone repository

```bash
git clone https://github.com/USERNAME/NAMA-REPOSITORY.git
cd NAMA-REPOSITORY
```

### 2. Buat branch sendiri

Jangan bekerja langsung di `main`.

```bash
git switch main
git pull origin main
git switch -c feature/nama-fitur
```

### 3. Lakukan perubahan dan periksa hasilnya

Edit file yang diperlukan, upload firmware bila perlu, lalu pastikan perubahan tidak merusak bagian lain.

```bash
git status
git diff
```

### 4. Stage perubahan

```bash
git add firmware/tx/tx.ino
```

Atau, setelah memastikan semua perubahan memang relevan:

```bash
git add .
```

### 5. Commit dengan pesan yang jelas

```bash
git commit -m "feat: tambah pengiriman telemetri TX"
```

Gunakan pesan yang menjelaskan perubahan, misalnya `fix: validasi format packet RX` atau `docs: perbarui prosedur pengujian`.

### 6. Push branch

```bash
git push -u origin feature/nama-fitur
```

### 7. Buat Pull Request

Buka repository di GitHub, pilih **Compare & pull request**, lalu buat Pull Request dari branch fitur menuju `main`. Jelaskan tujuan perubahan, file yang diubah, dan cara pengujiannya. Minta anggota lain melakukan review sebelum merge.

## Aturan penting

- Jangan langsung push ke branch `main`.
- Satu branch sebaiknya fokus pada satu fitur atau perbaikan.
- Jangan commit kredensial, token, file build, atau dataset lokal yang besar.
- Sinkronkan branch sebelum mulai pekerjaan baru:

```bash
git switch main
git pull origin main
```
