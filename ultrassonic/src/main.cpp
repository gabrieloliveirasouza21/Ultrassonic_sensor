#include <Arduino.h>
#include<Adafruit_Sensor.h>
#include <Servo.h>

const int trig = 2;
const int echo = 3;
const int pinBuzzer = 10;
const int ledVerde = 5;
const int ledVermelho = 6;
const int ledAmarelo = 7;
int distancia;

void setup(){
pinMode(trig, OUTPUT);
pinMode(echo,INPUT);
pinMode(pinBuzzer, OUTPUT);
pinMode(ledAmarelo,OUTPUT);
pinMode(ledVerde,OUTPUT);
pinMode(ledVermelho,OUTPUT);

}

void loop(){
  distancia = sensor(trig,echo);

  if (distancia <= 10){
    tone(10, 2000);
    digitalWrite(ledVermelho,HIGH);
    digitalWrite(ledVerde,HIGH);
    digitalWrite(ledAmarelo,HIGH);
    
  } else if(distancia > 10 && distancia <= 20){
    digitalWrite(ledVermelho,LOW);
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledAmarelo,HIGH);

  } else if(distancia > 20 && distancia <= 30){
    digitalWrite(ledVermelho,LOW);
    digitalWrite(ledVerde,HIGH);
    digitalWrite(ledAmarelo,LOW);
  } else {
    noTone(10);
    digitalWrite(ledVermelho,LOW);
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledAmarelo,LOW);
  }



}

int sensor(int trig,int echo){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  return pulseIn(echo, HIGH)/58;
}