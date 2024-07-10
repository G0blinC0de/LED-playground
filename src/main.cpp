#include <Arduino.h>
#include <FastLED.h>
#define pin_button 5
#define NUM_LEDS 21
#define DATA_PIN 3
CRGB leds[NUM_LEDS];

int redValue = 0;
int inPin = 5;
int ledPin = 13;
int val = 0;
// put function declarations here:
int myFunction(int, int);
String getUserInput();

void setup() {
  // put your setup code here, to run once:

  // LED_BUILTIN = pin 13, built in LED
  pinMode(LED_BUILTIN, OUTPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); 

  pinMode(pin_button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(1000);
  // digitalWrite(13, LOW);
  // delay(1000);

// val = digitalRead(inPin);
// digitalWrite(ledPin, val);

    // leds[0] = CRGB( 50, 100, 150); 
    // leds[1] = CRGB::Red;
    // FastLED.show(); 
    // delay(2000);
    // leds[0] = CRGB::Black;
    // leds[1] = CRGB::Black; 
    // FastLED.show(); 
    // delay(2000);

  leds[0] = CRGB( redValue, 0, 0);
  FastLED.show();
  delay(100);

  redValue ++;

  if(redValue > 150){
    redValue = 0;
  }


//   Serial.println("Enter data:");

//   while (Serial.available() == 0) {}     //wait for data available

// String teststr = getUserInput();

//   if (teststr == "red" || teststr == "blue" || teststr == "yellow") {

//     Serial.println("A primary color");

//   } else {

//     Serial.println("Something else");

//   }

    
  // Serial.print("Feelin Lucky");
  // Serial.println(" Punk?");

}

String getUserInput(){
  String teststr = String();  //read until timeout
  while (true) {
    if (Serial.available() >0){
      char userPressed = char(Serial.read());

      if(userPressed == '\n') {
        break;
      } else {
       teststr += userPressed;
      }
    }
  }
    teststr.trim();                        // remove any \r \n whitespace at the end of the String
  Serial.println(teststr);
  return teststr;
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}

