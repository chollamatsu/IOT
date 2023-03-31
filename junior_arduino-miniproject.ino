// C++ code
//

const int BUTTON=6;
const int BLED=9;
const int GLED=10;
const int RLED=11;
const int LIGHT = 0;
int ledMode = -1;
const int MIN_LIGHT = 200;
const int MAX_LIGHT = 900;
int val =0;
int press = 0;
//int Relay1Pin = 2;
int Relay2Pin = 3;

void setup()
{
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
  //pinMode(Relay1Pin, OUTPUT);
  pinMode(Relay2Pin, OUTPUT);
  //pinMode(Relay1Pin, INPUT);
  //pinMode(Relay2Pin, INPUT);
  //digitalWrite(Relay1Pin, HIGH);
  digitalWrite(Relay2Pin, HIGH);
  
}



void loop()
{
 	if(digitalRead(BUTTON) == HIGH){
     press = 1;
     if(press == 1){
        digitalWrite(Relay2Pin, HIGH);
     }
      press++;
      val = analogRead(LIGHT);
      //val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);
      //val = constrain(val, 0, 255);
      if(val < 8){
        analogWrite(GLED, val);
        /*
  	    digitalWrite(RLED, HIGH);
        digitalWrite(GLED, LOW);
        digitalWrite(BLED, HIGH);
        */}
      else if(8< val <20)
        analogWrite(RLED, val);
      else
        analogWrite(BLED, val);
      Serial.println(val);
   }
      /*
    if(ledMode == 2)
      ledMode = 0;
      setMode(ledMode);
   }*/
   //setMode(ledMode);
   
   //setMode(ledMode);
    else {
      press = 0;
      if(press == 0)
        digitalWrite(Relay2Pin, LOW);
      digitalWrite(RLED, LOW);
      digitalWrite(GLED, LOW);
      digitalWrite(BLED, HIGH);
  }
  ledMode++;
}