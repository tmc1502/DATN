#include <Arduino.h>

#define trigPin1 13 // Chân Trig cho cảm biến 1
#define echoPin1 12 // Chân Echo cho cảm biến 1
#define trigPin2 11 // Chân Trig cho cảm biến 2
#define echoPin2 10 // Chân Echo cho cảm biến 2

#define ledPin1 2 // Chân điều khiển LED 1
#define ledPin2 3 // Chân điều khiển LED 2

#define ledPin3 4 // Chân điều khiển LED 1
#define ledPin4 5 // Chân điều khiển LED 2

void setup()
{
  Serial.begin(9600); // Khởi động cổng Serial
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledPin1, OUTPUT); // LED 1 là OUTPUT
  pinMode(ledPin2, OUTPUT); // LED 2 là OUTPUT
}

void loop()
{
  long duration1, distance1; // Biến lưu trữ thời gian và khoảng cách cho cảm biến 1
  long duration2, distance2; // Biến lưu trữ thời gian và khoảng cách cho cảm biến 2

  // Đo khoảng cách từ cảm biến 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  // Đo khoảng cách từ cảm biến 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  // In ra Serial Monitor
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Kiểm tra điều kiện và bật đèn LED tương ứng
  if (distance1 < 30 && distance2 < 30)
  {
    digitalWrite(ledPin1, HIGH); // Bật LED 1
    digitalWrite(ledPin2, LOW);  // Tắt LED 2
  }
  else if (distance1 >= 30 && distance2 >= 30)
  {
    digitalWrite(ledPin1, LOW);  // Tắt LED 1
    digitalWrite(ledPin2, HIGH); // Bật LED 2
  }
  else
  {
    digitalWrite(ledPin1, LOW); // Tắt LED 1
    digitalWrite(ledPin2, LOW); // Tắt LED 2
  }

  if (distance2 < 30 && distance2 < 30)
  {
    digitalWrite(ledPin3, HIGH); // Bật LED 1
    digitalWrite(ledPin4, LOW);  // Tắt LED 2
  }
  else if (distance2 >= 30 && distance2 >= 30)
  {
    digitalWrite(ledPin3, LOW);  // Tắt LED 1
    digitalWrite(ledPin4, HIGH); // Bật LED 2
  }
  else
  {
    digitalWrite(ledPin3, LOW); // Tắt LED 1
    digitalWrite(ledPin4, LOW); // Tắt LED 2
  }

  delay(100); // Chờ 0.1 giây trước khi lặp lại
}
