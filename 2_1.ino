
#define MODEM_RX 16  // ESP32 RX2 <- TXD cua A7680C
#define MODEM_TX 17  // ESP32 TX2 -> RXD cua A7680C

#define PC_BAUD 115200
#define MODEM_BAUD 115200

String inputPC = "";
String inputModem = "";

void setup() {
  Serial.begin(PC_BAUD);
  Serial2.begin(MODEM_BAUD, SERIAL_8N1,
                MODEM_RX, MODEM_TX);

  delay(1000);

  Serial.println();
  Serial.println("================================");
  Serial.println(" KIEM TRA MANG DI DONG A7680C");
  Serial.println("================================");
  Serial.println("Nhap lenh AT vao Serial Monitor.");
  Serial.println("Vi du: AT, ATI, AT+CPIN?");
  Serial.println("Chon baud 115200, Both NL & CR.");
  Serial.println("--------------------------------");
}

void loop() {
  // Nhan lenh tu Serial Monitor
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\r' || c == '\n') {
      if (inputPC.length() > 0) {
        Serial2.println(inputPC);
        Serial.print("GUI: ");
        Serial.println(inputPC);
        inputPC = "";
      }
    } else {
      inputPC += c;
    }
  }

  // Doc phan hoi tu A7680C
  while (Serial2.available()) {
    char c = Serial2.read();
    Serial.write(c);
  }
}
