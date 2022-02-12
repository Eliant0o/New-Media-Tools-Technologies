#define HALL_D_PIN 2
#define HALL_A_PIN 0

void setup() {
  pinMode(HALL_D_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(HALL_D_PIN));
  //Serial.println(analogRead(HALL_A_PIN));

}
