/*
  based on:
 http://www.ajudino.com/2013/05/9-utilizando-display-de-7-segmentos-com.html
 http://arduinoexamples.wordpress.com/2012/10/27/display-de-7-segmentos-4-digitos-12-pinos/
 http://arduino.cc/en/Hacking/LibraryTutorial
 */

#include "display.h"

int botao = 12;

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
  
  pinMode (botao, INPUT);  
  pinMode (39, OUTPUT); //plug a Led on this pin. 
                        //It will turn on when there is an error.
  digitalWrite (39, LOW);//Case it's another pin, 
                        //you need to change "pinError" on "display.cpp"
  
  Display.show({"helo"}, 1); //the word with 4 characters that you wanna "write" and the time,
                              //in seconds, that will be displayed.
                              //It accept spaces and apostrophe  
 
 //int x = 0;
 while (digitalRead(botao) == 0){
   digitalWrite (39, 1);
   //x = digitalRead(botao);
 }
 digitalWrite (39, 0);
};

char frase[4] = {'0', '0', '0', '0'};
int i = 0;

void loop(){
  Display.show(frase, 1);
  frase[3]++;
  if (frase[3] == '9'+1){
    frase[3] = '0';
    frase[2]++;
  }
  if (frase[2] == '5'+1){
    frase[2] = '0';
    frase[1]++;
  }
  if (frase[1] == '9'+1){
    frase[1] = '0';
    frase[0]++;
  }
  if (frase[0] == '5'+1){
    frase[0] = '0';
  }  
}

