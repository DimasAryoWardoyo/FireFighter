#include <Servo.h>

const int pump = 8;            
const int flameSensor = 2;     
const int servoPin = 9;        
const int IN1 = A1;            
const int IN2 = A2;            
const int IN3 = A3;            
const int IN4 = A4;            
const int ENA = A0;            
const int ENB = A5;            
const int trigPin = 4;         
const int echoPin = 5;         

Servo flameServo;

void setup() {
  Serial.begin(9600);
  pinMode(pump, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(flameSensor, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  flameServo.attach(servoPin);
  flameServo.write(90); 
}

void loop() {
  bool flameDetected = digitalRead(flameSensor);

  // Mengukur jarak
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034 / 2;

  Serial.println(distance);

  if (flameDetected == LOW) {
    Serial.println("Api terdeteksi! Mendekati api.");

    // Menggerakkan motor maju hingga jarak 10 cm
    while (distance > 10) {
      analogWrite(ENA, 10);
      analogWrite(ENB, 10);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      // Perbarui jarak
      digitalWrite(trigPin, LOW);  
      delayMicroseconds(2); 
      digitalWrite(trigPin, HIGH); 
      delayMicroseconds(10); 
      digitalWrite(trigPin, LOW); 
      duration = pulseIn(echoPin, HIGH); 
      distance = duration * 0.034 / 2;

      delay(50); // Jeda untuk pembacaan jarak
    }

    // Berhenti setelah mencapai jarak 10 cm
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    Serial.println("Berhenti pada jarak 10 cm.");

    // Hidupkan pompa dan gerakkan servo
    while (flameDetected == LOW) {
      flameDetected = digitalRead(flameSensor); // Perbarui nilai flameDetected

      digitalWrite(pump, LOW); // Hidupkan pompa
      Serial.println("Menyemprotkan air...");

      // Gerakkan servo bolak-balik
      for (int angle = 0; angle <= 180; angle += 10) {
        flameServo.write(angle);
        delay(100);
        flameDetected = digitalRead(flameSensor); // Periksa kembali status api
        if (flameDetected == HIGH) break; // Keluar jika api padam
      }

      for (int angle = 180; angle >= 0; angle -= 10) {
        flameServo.write(angle);
        delay(100);
        flameDetected = digitalRead(flameSensor); // Periksa kembali status api
        if (flameDetected == HIGH) break; // Keluar jika api padam
      }
    }

    // Mematikan pompa jika api padam
    digitalWrite(pump, HIGH);
    Serial.println("Api padam. Pompa dimatikan.");
    flameServo.write(90);

  } else {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(pump, HIGH);
    flameServo.write(90);
    Serial.println("Tidak ada api.");
  }

  delay(100); // Jeda untuk loop berikutnya
}