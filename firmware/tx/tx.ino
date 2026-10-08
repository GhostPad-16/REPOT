#define E220_TX 17
#define E220_RX 16
#define E220_M0 21
#define E220_M1 19

HardwareSerial E220Serial(2);

const unsigned long SEND_INTERVAL_MS = 2000;
unsigned long lastSend = 0;
uint32_t sequence = 1;

void setup() {
  Serial.begin(115200);

  pinMode(E220_M0, OUTPUT);
  pinMode(E220_M1, OUTPUT);
  digitalWrite(E220_M0, LOW);
  digitalWrite(E220_M1, LOW);

  delay(1000);
  E220Serial.begin(115200, SERIAL_8N1, E220_RX, E220_TX);

  Serial.println();
  Serial.println("E220 NODE TX");
  Serial.println("Mode: Transparent | UART: 115200");
  Serial.println("TX siap...");
}

void loop() {
  if (millis() - lastSend < SEND_INTERVAL_MS) {
    return;
  }

  lastSend = millis();

  float suhu = random(280, 301) / 10.0;
  float lembab = random(600, 801) / 10.0;
  String packet = String(sequence) + "," + String(suhu, 1) + "," + String(lembab, 1);

  E220Serial.println(packet);
  Serial.print("TX -> ");
  Serial.println(packet);
  sequence++;
}
