
#include <HardwareSerial.h>

// Khai bao UART2 cho module SIM A7680C
HardwareSerial sim(2);

// Chan ket noi ESP32 voi SIM A7680C
#define RXD2 16
#define TXD2 17

void setup() {
  // Khoi tao Serial Monitor
  Serial.begin(115200);

  // Khoi tao giao tiep UART voi SIM A7680C
  sim.begin(115200, SERIAL_8N1, RXD2, TXD2);

  Serial.println("===== 4G CALL TEST =====");
  Serial.println("Nhap lenh AT de dieu khien SIM");
  Serial.println("ATD<Sdt>; : Goi dien");
  Serial.println("ATA       : Nhan cuoc goi");
  Serial.println("ATH       : Ket thuc cuoc goi");

  delay(1000);

  // Kiem tra ket noi voi module SIM
  sim.println("AT");
}

void loop() {
  // Doc lenh tu Serial Monitor va gui den SIM
  while (Serial.available()) {
    char c = Serial.read();
    sim.write(c);
  }

  // Doc phan hoi tu SIM va hien thi len Serial Monitor
  while (sim.available()) {
    char c = sim.read();
    Serial.write(c);
  }
}
