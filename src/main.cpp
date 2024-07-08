#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  Serial.print("Feelin Lucky");
  Serial.println(" Punk?");
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}