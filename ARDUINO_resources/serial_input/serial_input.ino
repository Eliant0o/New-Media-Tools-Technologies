int inByte = 0;         // incoming serial byte
int ledPin = 13;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    //Serial.println("received!");
    // get incoming byte:
    inByte = Serial.read();
  }
     //Serial.println(inByte);
     digitalWrite(ledPin, inByte);
}
