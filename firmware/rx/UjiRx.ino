
#include <Arduino.h>

#define E220_TX 17
#define E220_RX 16
#define E220_M0 21
#define E220_M1 19

#define E220_BAUD 115200

HardwareSerial E220Serial(2);

const uint8_t readConfig[] = {
  0xC1, 0x00, 0x08
};

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("================================");
  Serial.println("     E220 RAW CONFIG TEST");
  Serial.println("================================");

  pinMode(E220_M0, OUTPUT);
  pinMode(E220_M1, OUTPUT);

  // Mode konfigurasi: M0 HIGH, M1 HIGH
  digitalWrite(E220_M0, HIGH);
  digitalWrite(E220_M1, HIGH);
  delay(100);

  E220Serial.begin(
    E220_BAUD,
    SERIAL_8N1,
    E220_RX,
    E220_TX
  );

  E220Serial.setTimeout(500);

  Serial.println("UART       : 115200");
  Serial.println("M0         : HIGH");
  Serial.println("M1         : HIGH");
  Serial.println("Perintah   : C1 00 08");
  Serial.println("--------------------------------");

  // Bersihkan data lama di buffer
  while (E220Serial.available()) {
    E220Serial.read();
  }

  // Kirim perintah baca konfigurasi
  E220Serial.write(readConfig, sizeof(readConfig));
  E220Serial.flush();

  Serial.println("Perintah baca konfigurasi dikirim.");
  Serial.println("Menunggu respons E220...");

  delay(500);

  Serial.print("Respons HEX: ");

  bool received = false;

  while (E220Serial.available()) {
    uint8_t data = E220Serial.read();

    if (data < 0x10) {
      Serial.print('0');
    }

    Serial.print(data, HEX);
    Serial.print(' ');

    received = true;
  }

  Serial.println();

  if (!received) {
    Serial.println("ERROR: Tidak ada respons.");
  }

  Serial.println("================================");
}

void loop() {
  // Pengujian konfigurasi dilakukan sekali saat startup.
}