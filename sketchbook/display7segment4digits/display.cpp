#include "Arduino.h"
#include "display.h"

#define pinError 39

Display::Display(int *segments, int *digits){
  int i;
  for (i=0; i<8; i++)
    _segments[i] = segments[i];

  for (i=0; i<4; i++)
    _digits[i] = digits[i];

  _setup();
}

void Display::_setup(){
  int i;
  for (i=0; i<8; i++)
    pinMode (_segments[i], OUTPUT);
  for (i=0; i<4; i++)
    pinMode (_digits[i], OUTPUT);

}

int _segmentsValues[20][8] = {{0, 0, 0, 0, 0, 0, 1, 1 }, //0, O
                              {1, 0, 0, 1, 1, 1, 1, 1 }, //1, I
                              {0, 0, 1, 0, 0, 1, 0, 1 }, //2
                              {0, 0, 0, 0, 1, 1, 0, 1 }, //3
                              {1, 0, 0, 1, 1, 0, 0, 1 }, //4
                              {0, 1, 0, 0, 1, 0, 0, 1 }, //5, S
                              {0, 1, 0, 0, 0, 0, 0, 1 }, //6
                              {0, 0, 0, 1, 1, 1, 1, 1 }, //7
                              {0, 0, 0, 0, 0, 0, 0, 1 }, //8
                              {0, 0, 0, 0, 1, 0, 0, 1 }, //9
                              {0, 0, 0, 1, 0, 0, 0, 1 }, //A
                              {0, 1, 1, 0, 0, 0, 1, 1 }, //C
                              {0, 1, 1, 0, 0, 0, 0, 1 }, //E
                              {0, 1, 1, 1, 0, 0, 0, 1 }, //F
                              {1, 0, 0, 1, 0, 0, 0, 1 }, //H
                              {1, 0, 0, 0, 0, 1, 1, 1 }, //J
                              {1, 1, 1, 0, 0, 0, 1, 1 }, //L
                              {0, 0, 1, 1, 0, 0, 0, 1 }, //P
                              {1, 0, 0, 0, 0, 0, 1, 1 }, //U
                              {1, 0, 1, 1, 1, 1, 1, 1 }};//'

int Display::_decodeCharacter(char c){
  if (c == '0' || c == 'o' || c == 'O') return 0;
  else if (c == '1' || c == 'i' || c == 'I') return 1;
  else if (c == '2') return 2;
  else if (c == '3') return 3;
  else if (c == '4') return 4;
  else if (c == '5' || c == 's' || c == 'S') return 5;
  else if (c == '6') return 6;
  else if (c == '7') return 7;
  else if (c == '8') return 8;
  else if (c == '9') return 9;
  else if (c == 'a' || c == 'A') return 10;
  else if (c == 'c' || c=='C') return 11;
  else if (c == 'e' || c=='E') return 12;
  else if (c == 'f' || c=='F') return 13;
  else if (c == 'h' || c=='H') return 14;
  else if (c == 'j' || c=='J') return 15;
  else if (c == 'l' || c=='L') return 16;
  else if (c == 'p' || c=='P') return 17;
  else if (c == 'u' || c=='U') return 18;
  else if (c == '\'') return 19;
  else if (c == ' ') return 20;
  else return 99;
}

void Display::show(char *frase, int vezes){
  int i, j, k, index;
  _clear();

   for (k=0; k<vezes*125; k++){
      for (i=0; i<4; i++){
          index = _decodeCharacter(frase[i]);

          if (index != 99 and index != 20){

            digitalWrite (_digits[i], HIGH);
            for (j=0; j<8; j++){
              digitalWrite (_segments[j], _segmentsValues[index][j]);
            }
            //delay (2);
          } else {
              //delay(2);
              if (index == 99){
                if (digitalRead(pinError) == 0){
              digitalWrite (pinError, HIGH); //erro
                  }
              }
          }
          delay(2);
          //_clear();
          digitalWrite (_digits[i], LOW);
      }
   }
}

void Display:: _clear(){
  int i;
  for (i=0; i<8; i++)
    digitalWrite (_digits[i], LOW);
   for (i=0; i<4; i++)
     digitalWrite (_segments[i], LOW);

}


