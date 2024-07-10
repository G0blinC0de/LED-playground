#include <Arduino.h>
#include <FastLED.h>
#define pin_button 5
#define NUM_LEDS 21
#define DATA_PIN 3
CRGB leds[NUM_LEDS];

int brightValue = 0;

// int counter = 0;
bool increasing = true;

// int inPin = 5;
// int ledPin = 13;
// int val = 0;
// put function declarations here:
// int myFunction(int, int);
// String getUserInput();

void setup()
{

  // LED_BUILTIN = pin 13, built in LED
  pinMode(LED_BUILTIN, OUTPUT);
  FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);

  // pinMode(pin_button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{

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

  leds[0] = CHSV(HUE_RED, 255, brightValue);
  leds[1] = CHSV(HUE_GREEN, 255, brightValue);
  leds[2] = CHSV(HUE_BLUE, 255, brightValue);
  leds[3] = CHSV(HUE_RED, 255, brightValue);
  leds[4] = CHSV(HUE_GREEN, 255, brightValue);
  leds[4] = CHSV(HUE_BLUE, 255, brightValue);
  FastLED.show();
  delay(100);

  if (increasing)
  {
    brightValue++;
    if (brightValue == 150)
    {
      increasing = false;
    }
  }
  else
  {
    brightValue--;
    if (brightValue == 0)
    {
      increasing = true;
    }
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

// String getUserInput(){
//   String teststr = String();  //read until timeout
//   while (true) {
//     if (Serial.available() >0){
//       char userPressed = char(Serial.read());

//       if(userPressed == '\n') {
//         break;
//       } else {
//        teststr += userPressed;
//       }
//     }
//   }
//     teststr.trim();                        // remove any \r \n whitespace at the end of the String
//   Serial.println(teststr);
//   return teststr;
// }

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }
