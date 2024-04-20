#include <Servo.h>
const int servoPin = 9; 
const int trigPin = 10; 
const int echoPin = 11; 
Servo servoMotor;
void setup() {
  servoMotor.attach(servoPin);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  int servoAngle = map(distance, 0, 100, 0, 180);
  servoMotor.write(servoAngle);
  delay(100);
}
