/*
   based on:
        http://www.ajudino.com/2013/05/9-utilizando-display-de-7-segmentos-com.html
        http://arduinoexamples.wordpress.com/2012/10/27/display-de-7-segmentos-4-digitos-12-pinos/
        http://arduino.cc/en/Hacking/LibraryTutorial
 */

#include "display.h"

int botao = 43;

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
    pinMode (39, OUTPUT);   //plug a Led on this pin. 
                            //It will turn on when there is an error.
    digitalWrite (39, LOW); //Case it's another pin, 
                            //you need to change "pinError" on "display.cpp"

    Display.show({"helo"}, 1);  //the word with 4 characters that you wanna "write" and the time,
                                //in seconds, that will be displayed.
                                //It accept spaces and apostrophe  

    while (digitalRead(botao) == 0){
        digitalWrite (39, 1);

        Serial.begin (9600);
    }
    digitalWrite (39, 0);
}

char frase[4] = {48, 48, 48, 48};
int i = 0;

void loop(){
    Display.show(frase, 1);
    frase[3]++;
    if (frase[3] == 58){
        frase[3] = 48;
        frase[2]++;
    }
    if (frase[2] == 54){
        frase[2] = 48;
        frase[1]++;
    }
    if (frase[1] == 58){
        frase[1] = 48;
        frase[0]++;
    }
    if (frase[0] == 54){
        frase[0] = 48;
    }

    if (digitalRead(39) == 1){
        Serial.println(frase);
        Serial.println(frase[2], DEC);
        frase[0] = 48; frase[1] = 48; frase[2] = 48; frase[3] = 48;
        delay(1000);
        digitalWrite(39, 0);
    }
}

