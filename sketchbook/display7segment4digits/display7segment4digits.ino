/*
  based on:
 http://www.ajudino.com/2013/05/9-utilizando-display-de-7-segmentos-com.html
 http://arduinoexamples.wordpress.com/2012/10/27/display-de-7-segmentos-4-digitos-12-pinos/
 http://arduino.cc/en/Hacking/LibraryTutorial
 */

#include "display.h"

/*
  Pins of the 8 segments (a, b, c, d, e, f, g, dp)
*/
int segments[8] = {
  31, 23, 6, 3, 2, 28, 8, 5};


/*
  Pins of the 4 digits
*/
int digits[4] = {
  32, 27, 24, 9};

Display Display (segments, digits);

void setup(){
  
  pinMode (39, OUTPUT); //plug a Led on this pin. 
                        //It will turn on when there is an error.
  digitalWrite (39, LOW);//Case it's another pin, 
                        //you need to change "pinError" on "display.cpp"
  
  Display.show({"helo"}, 5); //the word with 4 characters that you wanna "write" and the time,
                              //in seconds, that will be displayed.
                              //It accept spaces and apostrophe

  
};

void loop(){
};

