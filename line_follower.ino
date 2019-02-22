//IR sensors
const int LS = 9;
const int RS = 8;
const int MS = 12;
const int FRS = 3;
const int FLS = 4;
//Motor A
const int LM1  = 5;    // Pin 15 of L293D IC
const int LM2  = 6;    // Pin 10 of L293D IC
//Motor B
const int RM1  = 10;   // Pin  7 of L293D IC
const int RM2  = 11;   // Pin  2 of L293D IC

void fwd()
{
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
}

void right()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
}

void left()
{
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2
    , LOW);
}

void halt()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
}


void setup() 
{
    Serial.begin(9600);
    pinMode(LM1, OUTPUT);
    pinMode(LM2, OUTPUT);
    pinMode(RM1, OUTPUT);
    pinMode(RM2, OUTPUT); 

    pinMode(LS, INPUT);
    pinMode(RS, INPUT);
    pinMode(MS, INPUT);
    pinMode(FLS, INPUT);
    pinMode(FRS, INPUT);
}

void loop() 
{
    int l = digitalRead(LS);
    int r = digitalRead(RS);
    int m = digitalRead(MS);
    int fr = digitalRead(FRS);
    int fl = digitalRead(FLS);
    Serial.print("Left: ");
    Serial.print(l);
    Serial.print("\tRight: ");
    Serial.print(r);
    Serial.print("\tMiddle: ");
    Serial.print(m);
    Serial.print("\tFar Right: ");
    Serial.print(fr);
    Serial.print("\tFar Left: ");
    Serial.print(fl);
    Serial.print("\n");

  /*if(digitalRead(LS) && digitalRead(RS) && !digitalRead(MS)) 
    fwd();
  if((digitalRead(LS)) && !(digitalRead(RS)) && !digitalRead(MS))     // Turn right
    right();
  if(!(digitalRead(LS)) && (digitalRead(RS)) && !digitalRead(MS))     // turn left
    left();
  if(!(digitalRead(LS)) && !(digitalRead(RS)) && !digitalRead(MS))     // stop
    halt();*/

  if(digitalRead(LS) && digitalRead(RS)) 
    halt();
  if((digitalRead(LS)) && !(digitalRead(RS)))     // Turn right
    right();
  if(!(digitalRead(LS)) && (digitalRead(RS)))     // turn left
    left();
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
    fwd();

   
   //fwd();
}
