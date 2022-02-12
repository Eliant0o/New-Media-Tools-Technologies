// Arduino Sketch Begin -

// Defining Constants (constants are things that will not change, you'll get a compile error if you try to change the value of a constant within the sketch)

const int triggerPin = 7; 
const int echoPin = 8; 
int duration = 0; 
int distance = 0;

void setup(){
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}


void loop(){
  digitalWrite(triggerPin, HIGH); 
  delay(5); 
  digitalWrite(triggerPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  delay(10); 
  distance = (duration / 2) / 74; 
  delay(500); 
  Serial.println(distance); 
}
