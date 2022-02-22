#include <DigiMouse.h>


#define PI 3.14159

double radius = 3;
double tau = 2.0*PI;
int ledPin = 1;


void setup() {
  DigiMouse.begin();
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int randint = random(300, 2000);
  DigiMouse.moveX(-radius); 
  DigiMouse.delay(20);
  DigiMouse.update();
  digitalWrite(ledPin, HIGH);
  DigiMouse.setButtons(1<<0);
  DigiMouse.delay(150);
  DigiMouse.setButtons(0);
  DigiMouse.update();
  digitalWrite(ledPin, LOW);
  DigiMouse.delay(800);
  for (double i = 0.00; i < tau; i += 0.1)
  {
  
    DigiMouse.moveY(radius * sin(i));
    DigiMouse.moveX(radius * cos(i));
    DigiMouse.delay(20);
  } 
}
