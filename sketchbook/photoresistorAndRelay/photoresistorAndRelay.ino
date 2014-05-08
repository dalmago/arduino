/*
 * photoresistorAndRelay.ino
 * Copyright (C) 2014 Matheus Dal Mago <matheusdalmago10@hotmail.com>
 *
 */

/* "THE BEER-WARE LICENSE" (Revision 42):*/

/* <matheusdalmago10@hotmail.com> wrote this file. As long as you retain this*/
/* notice you can do whatever you want with this stuff. If we meet some day,*/
/* and you think this stuff is worth it, you can buy me a beer in return.*/

/*       by: Matheus Dal Mago*/

int relay = 26;     // The pin that is connected to the transistor
                    // and activate the relay.

int LDR = A8;       // The pin plugged in the LDR

void setup(){
    analogReference(EXTERNAL);  // Set the analogRead from 
                                // external reference (3,3v)
    Serial.begin(9600);
    pinMode (relay, OUTPUT);
    digitalWrite (relay, LOW);
}
int var;
void loop(){
    var = analogRead(LDR);

    if (var > 990){         // Set the "level of the darkness"
        digitalWrite(relay, HIGH);
        delay (500);
    }
    else{
        digitalWrite(relay, LOW);
        delay (500);
    }
}

