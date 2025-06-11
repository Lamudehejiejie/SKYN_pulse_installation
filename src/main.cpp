#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>

// Wi-Fi credentials
const char* ssid = "Yan hehehe🫸";
const char* password = "yanheheisgood";

// UDP config
WiFiUDP Udp;
IPAddress outIp(172, 20, 10, 4);  // 🔁 ← your computer's IP
const unsigned int outPort = 6666;  // TD OSC In port

// Pulse sensor pins
const int pulse1Pin = 36;  // VP
const int pulse2Pin = 39;  // VN

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("📡 Sending dual pulse data via OSC...");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi connected. IP address: ");
  Serial.println(WiFi.localIP());

  Udp.begin(8888);  // Local port (not critical)
}

void loop() {
  int pulse1 = analogRead(pulse1Pin);
  int pulse2 = analogRead(pulse2Pin);

  Serial.print("P1: "); Serial.print(pulse1);
  Serial.print(" | P2: "); Serial.println(pulse2);

  // Send OSC: /pulse1
  OSCMessage msg1("/pulse1");
  msg1.add((float)pulse1);
  Udp.beginPacket(outIp, outPort);
  msg1.send(Udp);
  Udp.endPacket();
  msg1.empty();

  // Send OSC: /pulse2
  OSCMessage msg2("/pulse2");
  msg2.add((float)pulse2);
  Udp.beginPacket(outIp, outPort);
  msg2.send(Udp);
  Udp.endPacket();
  msg2.empty();

  delay(50);
}
