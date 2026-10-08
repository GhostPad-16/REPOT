#include <math.h>

#define E220_TX 17
#define E220_RX 16
#define E220_M0 21
#define E220_M1 19

HardwareSerial E220Serial(2);

bool isUnsignedInteger(const String &value) {
  if (value.length() == 0) {
    return false;
  }

  for (unsigned int i = 0; i < value.length(); i++) {
    if (!isDigit(value[i])) {
      return false;
    }
  }

  return true;
}

bool isDecimalNumber(const String &value) {
  bool hasDigit = false;
  bool hasDecimalPoint = false;

  if (value.length() == 0) {
    return false;
  }

  for (unsigned int i = 0; i < value.length(); i++) {
    char character = value[i];
    if (isDigit(character)) {
      hasDigit = true;
    } else if ((character == '-' || character == '+') && i == 0) {
      continue;
    } else if (character == '.' && !hasDecimalPoint) {
      hasDecimalPoint = true;
    } else {
      return false;
    }
  }

  return hasDigit;
  return false;
}

bool parsePacket(const String &packet, uint32_t &sequence, float &suhu, float &lembab) {
  int comma1 = packet.indexOf(',');
  int comma2 = packet.indexOf(',', comma1 + 1);

  if (comma1 <= 0 || comma2 <= comma1 || packet.indexOf(',', comma2 + 1) != -1) {
    return false;
  }

  String seqText = packet.substring(0, comma1);
  String suhuText = packet.substring(comma1 + 1, comma2);
  String lembabText = packet.substring(comma2 + 1);
  seqText.trim();
  suhuText.trim();
  lembabText.trim();

  if (!isUnsignedInteger(seqText) || !isDecimalNumber(suhuText) || !isDecimalNumber(lembabText)) {
    return false;
  }

  sequence = strtoul(seqText.c_str(), nullptr, 10);
  suhu = suhuText.toFloat();
  lembab = lembabText.toFloat();

  return isfinite(suhu) && isfinite(lembab);
}

void setup() {
  Serial.begin(115200);

  pinMode(E220_M0, OUTPUT);
  pinMode(E220_M1, OUTPUT);
  digitalWrite(E220_M0, LOW);
  digitalWrite(E220_M1, LOW);

  delay(1000);
  E220Serial.begin(115200, SERIAL_8N1, E220_RX, E220_TX);

  Serial.println();
  Serial.println("E220 NODE RX");
  Serial.println("Mode: Transparent | UART: 115200");
  Serial.println("Menunggu paket...");
}

void loop() {
  if (!E220Serial.available()) {
    return;
  }

  String packet = E220Serial.readStringUntil('\n');
  packet.trim();

  if (packet.length() == 0) {
    return;
  }

  Serial.print("RX -> ");
  Serial.println(packet);

  uint32_t sequence;
  float suhu;
  float lembab;

  if (!parsePacket(packet, sequence, suhu, lembab)) {
    Serial.println("ERROR: format paket tidak valid");
    return;
  }

  Serial.print("Parsed: ");
  Serial.print(sequence);
  Serial.print(",");
  Serial.print(suhu, 1);
  Serial.print(",");
  Serial.println(lembab, 1);

  // RSSI dan SNR ditambahkan di sini saat hardware/metode pembacaan tersedia.
}
