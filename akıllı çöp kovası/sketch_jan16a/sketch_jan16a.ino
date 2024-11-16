#include <Servo.h>
#include <Arduino.h>
Servo servo;
int triggerPin = D1;
int echoPin = D2;
int servoPin = D3;
long zaman;
int mesafe;
int sinir = 10;
void setup()
{
  servo.attach(servoPin);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop(){ 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  zaman= pulseIn(echoPin, HIGH);
  mesafe = zaman* 0.034 / 2;  
  
  if ( mesafe <= sinir && mesafe > 0){
    Serial.print("Mesafe:")
    Serial.println(mesafe);
    servo.write(180);
    delay(7000);
  }else{
    servo.write(90);
  }