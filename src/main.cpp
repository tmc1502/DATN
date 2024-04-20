#include <Arduino.h>

#define trigPin1 13
#define echoPin1 12

#define trigPin2 11
#define echoPin2 10

#define ledPin1 2
#define ledPin2 3

#define ledPin3 4
#define ledPin4 5

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop()
{
  long duration1, distance1;
  long duration2, distance2;

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  if (distance1 < 30 && distance2 < 30)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  }
  else if (distance1 >= 30 && distance2 >= 30)
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
  }
  else
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }

  if (distance2 < 30 && distance2 < 30)
  {
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
  }
  else if (distance2 >= 30 && distance2 >= 30)
  {
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH); // Bật LED 2
  }
  else
  {
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }

  delay(100);
}
