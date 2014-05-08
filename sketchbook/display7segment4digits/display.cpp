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
  if (c == 48 || c == 79 || c == 111) return 0;
  else if (c == 49 || c == 105 || c == 73) return 1;
  else if (c == 50) return 2;
  else if (c == 51) return 3;
  else if (c == 52) return 4;
  else if (c == 53 || c == 83 || c == 115) return 5;
  else if (c == 54) return 6;
  else if (c == 55) return 7;
  else if (c == 56) return 8;
  else if (c == 57) return 9;
  else if (c == 65 || c == 97) return 10;
  else if (c == 67 || c==99) return 11;
  else if (c == 69 || c==101) return 12;
  else if (c == 70 || c==102) return 13;
  else if (c == 72 || c==104) return 14;
  else if (c == 74 || c==106) return 15;
  else if (c == 76 || c==108) return 16;
  else if (c == 80 || c==112) return 17;
  else if (c == 85 || c==117) return 18;
  else if (c == 39) return 19;
  else if (c == 32) return 20;
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


