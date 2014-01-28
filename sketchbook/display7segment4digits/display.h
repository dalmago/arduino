/*display.h - Library for flashing a 7 segments display with 4 digits.
 * Created by Matheus Dal Mago. January 27, 2014. matheusdalmago10@hotmail.com
 * Released into the public domain.
 */
#ifndef display_h
#define display_h

#include "Arduino.h"

class Display
{
    public:
        Display(int *segments, int *digits);
        void show(char *frase, int vezes);
        //void dot();
        //void dash();
    private:
        void _clear();
        void _setup();
        int _decodeCharacter(char c);
        int _segments[8];
        int _digits[4];
        //int _segmentsValues[19][8];
};

#endif
