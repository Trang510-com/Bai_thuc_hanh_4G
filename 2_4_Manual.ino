/*
  Bai 2.4 - Nhap lenh AT thu cong (module A7680C)
  Sketch KHONG tu gui lenh nao. Chi chuyen tiep du lieu 2 chieu:
    Serial Monitor  <->  module A7680C

  Serial Monitor: 115200 baud, chon "Both NL & CR" (de moi lenh co \r\n).

  Cac lenh go tay theo thu tu:
    AT+CREG?
    AT+CGATT?              (neu +CGATT: 0 thi AT+CGATT=1)
    AT+CPING="www.google.com",1
    AT+NETOPEN             (cho +NETOPEN: 0)
    AT+IPADDR
    AT+CIPOPEN=1,"TCP","test.mosquitto.org",1883   (cho +CIPOPEN: 1,0)
    AT+CIPOPEN?

  Noi day:
  - ESP32 : module TXD -> GPIO16 (RX2), module RXD -> GPIO17 (TX2)
  - Mega  : module TXD -> chan 19 (RX1), module RXD -> chan 18 (TX1)
  - Noi chung GND. Kiem tra muc logic cua module truoc khi noi.
*/

#if defined(ESP32)
  #define SIM Serial2
  #define SIM_RX_PIN 16
  #define SIM_TX_PIN 17
#else
  #define SIM Serial1
#endif

#define SIM_BAUD 115200

void setup() {
  Serial.begin(115200);
#if defined(ESP32)
  SIM.begin(SIM_BAUD, SERIAL_8N1, SIM_RX_PIN, SIM_TX_PIN);
#else
  SIM.begin(SIM_BAUD);
#endif
  Serial.println("San sang. Go lenh AT va nhan Enter.");
}

void loop() {
  while (SIM.available())    Serial.write(SIM.read());   // module -> may tinh
  while (Serial.available()) SIM.write(Serial.read());   // may tinh -> module
}
