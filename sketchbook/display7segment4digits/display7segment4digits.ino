/*
  based on:
 http://www.ajudino.com/2013/05/9-utilizando-display-de-7-segmentos-com.html
 http://arduinoexamples.wordpress.com/2012/10/27/display-de-7-segmentos-4-digitos-12-pinos/
 */

#include "display.h"

int segments[8] = {
  31, 23, 6, 3, 2, 28, 8, 5};
int digits[4] = {
  32, 27, 24, 9};

Display Display (segments, digits);

void setup(){
  
  Serial.begin(9600);
  
  pinMode (39, OUTPUT); //pino erro
  digitalWrite (39, LOW);
  
  char frase[5] = {"helo"};
  Display.show(frase, 5);
  
};

void loop(){
};

