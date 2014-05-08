int entradaSerial = 47;

int shiftClk = 51;
int registerClk = 48;

int clearNotReg = 53;

int pin[4] = {entradaSerial, shiftClk, registerClk, clearNotReg};

void setup(){
  int i;
  
  for (i=0; i<4; i++){
    pinMode (pin[i], OUTPUT);
    digitalWrite (pin[i], 0);
  }
  delay (100);
  digitalWrite (clearNotReg, 1);
}

int i = 0;

void loop(){
  if (digitalRead(shiftClk) == 0){
    digitalWrite(shiftClk, 1);
    digitalWrite(registerClk, 1);
  } else {
    digitalWrite(shiftClk, 0);
    digitalWrite(registerClk, 0);
  }
  
  if (i == 0 || i == 1 || i == 5 || i == 6){
    digitalWrite(entradaSerial, 1);
  }
  else {
    digitalWrite (entradaSerial, 0);
  }
  
 delay(400);
 i++; 
}
  
  
