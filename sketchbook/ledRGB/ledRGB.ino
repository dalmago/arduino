int cathode1 = 49;
int r1 = 53;
int g1 = 50;
int b1 = 46;

int cathode2  = 45;
int r2 = 42;
int g2 = 43;
int b2 = 35;

int pins1[4] = {cathode1, r1, g1, b1};
int pins2[4] = {cathode2, r2, g2, b2};

/*int sequency[][4] = {{0, 1, 0, 0}, //red
                     {0, 0, 1, 0}, //green
                     {0, 0, 0, 1}};//blue*/

void setup(){
  int i;
  
  for (i=0; i<4; i++){
    pinMode (pins1[i], OUTPUT);
    pinMode (pins2[i], OUTPUT);
    digitalWrite (pins1[i], 0);
    digitalWrite (pins2[i], 0);
    
  }
  
  digitalWrite (r1, 1);
  digitalWrite (b2, 1);
  delay (1500);
  digitalWrite (r1, 0);
  digitalWrite (b2, 0);
  digitalWrite (g1, 1);
  digitalWrite (r2, 1);
  delay (1500);
  digitalWrite (g1, 0);
  digitalWrite (r2, 0);
  digitalWrite (b1, 1);
  digitalWrite (g2, 1);
  delay (1500);
  digitalWrite (b1, 0);
  digitalWrite (g2, 0);
  digitalWrite (r1, 1);
  digitalWrite (b2, 1);
  delay (1500);
  digitalWrite (r1, 0);
  digitalWrite (b2, 0);
  
  
  
  /*for (i=0; i<4; i++){
    digitalWrite (pins[i%4], sequency[0][i%4]);
    delay (150);
    digitalWrite (pins[i%4], sequency[1][i%4]);
    delay (150);
    digitalWrite (pins[i%4], sequency[2][i%4]);
  }*/
}

void loop(){}
