#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>

const char* ssid = "USNGHz";
const char* password = "USNgallery";

WiFiUDP Udp;
IPAddress outIp(192, 168, 0, 152); // ← Your laptop IP (from the screenshot)
const unsigned int outPort = 8000;
// const unsigned int localPort = 9001; 
// const unsigned int localPort = 9002;
// const unsigned int localPort = 9003;
// const unsigned int localPort = 9004;
// const unsigned int localPort = 9005;
// const unsigned int localPort = 9006;
// const unsigned int localPort = 9007;
// const unsigned int localPort = 9008;
// const unsigned int localPort = 9009;   
// const unsigned int localPort = 9010;
// const unsigned int localPort = 9011;
// const unsigned int localPort = 9012;
// const unsigned int localPort = 9013;
const unsigned int localPort = 9014;
// const unsigned int localPort = 9015;
const int ledPin = 2;  // or replace with SSR/DMX control pin

void blinkLED() {
  digitalWrite(ledPin, HIGH);
  delay(20);
  digitalWrite(ledPin, LOW);
}

void onLamp(OSCMessage &msg) {
  int value = msg.getInt(0);
  Serial.print("Received lamp signal: "); Serial.println(value);
  blinkLED();
  // Add control logic here (SSR, dimmer, etc.)
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected. IP: ");
  Serial.println(WiFi.localIP());

  Udp.begin(localPort);
}

void loop() {
  OSCMessage msg;
  int size = Udp.parsePacket();
  if (size > 0) {
    while (size--) msg.fill(Udp.read());
    if (!msg.hasError()) {
    //   msg.dispatch("/lamp1", onLamp);
    //   msg.dispatch("/lamp2", onLamp);
    //   msg.dispatch("/lamp3", onLamp);
    //   msg.dispatch("/lamp4", onLamp);
    //   msg.dispatch("/lamp5", onLamp);
    //   msg.dispatch("/lamp6", onLamp);
    //   msg.dispatch("/lamp7", onLamp);
    //   msg.dispatch("/lamp8", onLamp);   
    //   msg.dispatch("/lamp9", onLamp);
    //   msg.dispatch("/lamp10", onLamp);
    //   msg.dispatch("/lamp11", onLamp);
    //   msg.dispatch("/lamp12", onLamp);
    //   msg.dispatch("/lamp13", onLamp);
      msg.dispatch("/lamp14", onLamp);
    //   msg.dispatch("/lamp15", onLamp);
    }
  }
}
