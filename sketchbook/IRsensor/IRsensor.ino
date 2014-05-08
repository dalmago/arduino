int analogPin = 15;     // the IR transistor

int IRled = 35;
int sensorLED = 39;

int val = 0;           // variable to store the value read

void setup()

{
  pinMode (sensorLED, OUTPUT);
  pinMode (IRled, OUTPUT);
  digitalWrite (sensorLED, 0);
  digitalWrite (IRled, 0);

  //Serial.begin(9600);          //  setup serial

}


int i = 0;
void loop()

{
   
  val = analogRead(analogPin);    // read the input pin

  //Serial.println(val);             // debug value
  delay (10);
  
  if (val > 16)
    digitalWrite (sensorLED, 1);
   else
     digitalWrite (sensorLED, 0);
  
  i++;

}
