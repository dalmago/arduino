#include <SD.h>

//SD myCard = SD



void setup () {
   Serial.begin (9600);
   if (SD.begin()){
      Serial.println("aberto\n");
      if (!SD.exists ("teste")){
        SD.mkdir ("teste");
        Serial.println("criado\n");
      }
      else {
        SD.rmdir ("teste");
        Serial.println ("apagado\n");
      }
        
   }
}

void loop () {
  
}
