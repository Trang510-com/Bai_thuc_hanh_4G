
#include <HardwareSerial.h>

HardwareSerial sim(2);

void setup() {
  Serial.begin(115200);

  // RX ESP32 = GPIO16, TX ESP32 = GPIO17
  sim.begin(115200, SERIAL_8N1, 16, 17);

  Serial.println("BAI 2.3 - THUC HIEN CUOC GOI 4G");
  Serial.println("Nhap lenh AT trong Serial Monitor");
}

void loop() {
  // Hien thi log tu module SIM
  while (sim.available()) {
    Serial.write(sim.read());
  }

  // Gui lenh AT tu may tinh den module SIM
  while (Serial.available()) {
    sim.write(Serial.read());
  }
}
