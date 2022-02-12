#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCBundle.h>    
 
//#define FASTLED_ESP8266_RAW_PIN_ORDER

// WIFI VARIABLES
char ssid[] = "FRITZ!Box 7530 SM";                
char pass[] = "70562719883911399360";   
WiFiUDP Udp;                          
const unsigned int localPort = 8000;   


int data = 0;
int ledPin = 6; 

void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(74880);
  digitalWrite(ledPin, HIGH);
  WiFi.config(IPAddress(192, 168, 178, 222), IPAddress(192, 168, 178, 1), IPAddress(255, 255, 0, 0));
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
  Serial.println("waiting...")
  }
  Udp.begin(localPort);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  digitalWrite(ledPin, LOW);
}

void loop() {
  OSCMessage msgIN;
  int size;
  if ((size = Udp.parsePacket()) > 0) {
    while (size--)
      msgIN.fill(Udp.read());
    if (!msgIN.hasError()) {
      msgIN.route("/oscdata", data);
    }
  }
}



void data(OSCMessage &msg, int addrOffset) {
 data = int(msg.getInt(0));
 if(data==1){
  digitalWrite(ledPin, HIGH);
 }
 else if (data ==0){
  digitalWrite(ledPin, LOW);
 }
}
