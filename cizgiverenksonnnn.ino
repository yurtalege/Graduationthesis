//define sensors and motors pins
int mostrightsensor= A5;
int rightsensor =A4;
int middlesensor =A3;
int leftsensor =A2;
int mostleftsensor =A1;

const int s0 = 51;
const int s1 = 53;
const int s2 = 47;
const int s3 = 49;
const int out = 45;
// Variables
int red = 0;
int green = 0;
int yellow = 0;

#define MotorR1 50
#define MotorR2 48
#define MotorRE 52  
#define MotorL1 46
#define MotorL2 44
#define MotorLE 42

int referancevalue = 600; // value that distinguishes Black and white surface 
//the reference should be redefined according to the values read from the sensor,because this value varies depending on the environment and the sensor to determine the reference point, the value read on the black surface and the average of the value read on the white surface can be taken
void setup()
{
  Serial.begin(9600); // we started serial communication at 9600 baud rate to send data 
  // We indicate input-output information for sensors and motors.
  pinMode(mostrightsensor,INPUT);
  pinMode(rightsensor, INPUT);
  pinMode(middlesensor, INPUT);  
  pinMode(leftsensor, INPUT);
  pinMode(mostleftsensor, INPUT);
  pinMode(MotorR1, OUTPUT); 
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
 digitalWrite(s0, HIGH);
 digitalWrite(s1, HIGH);
}

void loop()
{
  //sensor's analog onutputs convers digital forms
  mostrightsensor = analogRead(A5); // Analog value from Sensor 5 is converted to digital
  rightsensor = analogRead(A4); // Analog value from Sensor 4 is converted to digital
  middlesensor = analogRead(A3);// Analog value from Sensor 3 is converted to digital
  leftsensor = analogRead(A2);// Analog value from Sensor 2 is converted to digital
  mostleftsensor = analogRead(A1);// Analog value from Sensor 1 is converted to digital

   color();//we define colors
 Serial.print("R Intensity:");
 Serial.print(red, DEC);
 Serial.print(" G Intensity: ");
 Serial.print(green, DEC);
 Serial.print(" Y Intensity : ");
 Serial.print(yellow, DEC);
 //Serial.println();

 if (yellow < red && red < green && red < 40 && green > 60)
 {
 Serial.println(" - (Red Color)");
 stopped();//robot stopped in red color
 }
 }
 else if (yellow < red && red < green && yellow < 21 && red < 40 && green < 60)
 {
 Serial.println(" - (Yellow Color)");
 stopped();//robot stopped in yellow color
 }
//robot detects green color
else if (yellow <= green && green < red)
 {
  Serial.println(" - (Green Color)"); 
drive();//continue to line tracking
 }
  else if (yellow < red && red < green && red > 50 && green > 60)
 {
  
 Serial.println(" - (No Color)");
 drive();//continue to line tracking

}
else {
 drive();//continue to line tracking
}
}

void drive() {
      if((mostleftsensor) >= referancevalue && (leftsensor) >= referancevalue && (middlesensor) <= referancevalue && (rightsensor)>= referancevalue && (mostrightsensor) >= referancevalue ){  
  // when the middle sensor  see the line, the robot moves forward.
   goforward();  // go forward 
   }
   
else if((mostleftsensor) >= referancevalue && (leftsensor) >= referancevalue && (middlesensor) >= referancevalue && (rightsensor) <= referancevalue && (mostrightsensor) >=referancevalue   ){  
  // Right when right sensor see the line, the robot turns right.
   turnright();  //turn right 
   }
   
else if((mostleftsensor) >= referancevalue && (leftsensor) >= referancevalue && (middlesensor) >= referancevalue && (rightsensor) >= referancevalue && (mostrightsensor) <=referancevalue   ){  
  // Right when most right sensor see the line, the robot turns right.
  turnright();  //turn right 
   }
    else if((mostleftsensor)  >= referancevalue && (leftsensor)  >= referancevalue && (middlesensor) <= referancevalue && (rightsensor) <= referancevalue && (mostrightsensor) >= referancevalue ){ 
  turnright();  //turn right
 }
  else if((mostleftsensor)  >= referancevalue && (leftsensor)  >= referancevalue && (middlesensor) <= referancevalue && (rightsensor) >= referancevalue && (mostrightsensor) <= referancevalue ){ 
  turnright();  //turn right
 }
  else if((mostleftsensor)  >= referancevalue && (leftsensor)  >= referancevalue && (middlesensor)>= referancevalue && (rightsensor) <= referancevalue && (mostrightsensor)  <= referancevalue ){ 
  turnright();  //turn right
 }
 else if((mostleftsensor) >= referancevalue && (leftsensor) <= referancevalue && (middlesensor) >= referancevalue && (rightsensor) >= referancevalue && (mostrightsensor) >= referancevalue ){  
  // Left when left sensor see the line, the robot turns left.
  turnleft();  //turn left 
  }
else if((mostleftsensor) <= referancevalue && (leftsensor) >= referancevalue && (middlesensor) >= referancevalue && (rightsensor) >= referancevalue && (mostrightsensor) >= referancevalue ){ 
  // Left when most left sensor see the line, the robot turns left.
  turnleft();  //turn left 
  }
 else if((mostleftsensor) >= referancevalue && (leftsensor) <= referancevalue && (middlesensor) <= referancevalue && (rightsensor) >= referancevalue && (mostrightsensor) >= referancevalue ){ 
  turnleft();  //turn left
 }

  else if((mostleftsensor)  <= referancevalue && (leftsensor)  <= referancevalue && (middlesensor)<= referancevalue && (rightsensor)  >= referancevalue && (mostrightsensor) >= referancevalue ){ 
  turnleft();  //turn left
 }
 else if((mostleftsensor) <= referancevalue && (leftsensor) <= referancevalue && (middlesensor) >= referancevalue && (rightsensor) >= referancevalue && (mostrightsensor) >= referancevalue ){ 
  turnleft();  //turn left
 }
 else if((mostleftsensor)  >= referancevalue && (leftsensor)  >= referancevalue && (middlesensor)>= referancevalue && (rightsensor)  >= referancevalue && (mostrightsensor) >= referancevalue ){ 
  turnaroundtillseetheline();  //turn back to line
 
 
 }
}
void color()//we define color function
{
 digitalWrite(s2, LOW);
 digitalWrite(s3, LOW);
 //count OUT, pRed, RED
 red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
 digitalWrite(s2, HIGH);
 digitalWrite(s3, LOW);
 //count OUT, pBLUE, BLUE
 yellow = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
 digitalWrite(s2, HIGH);
 digitalWrite(s3, HIGH);
 //count OUT, pGreen, GREEN
 green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
void goforward(){  // We define a function for the robot's forward motion.

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 130); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 130); 
}


void turnright(){  // We define a function for the robot's right rotation movement.

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 0); 
  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 

  analogWrite(MotorLE, 130); 
  
  
} 

void turnleft(){  // We define a function for the robot's left rotation movement.

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 130); 
  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 0); 
  
}



void stopped(){ // We define the function for the robot's stop motion.

  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, LOW);
  analogWrite(MotorRE, 0); // Right motor speed is 0 (Motor stopped)


  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, LOW);
  analogWrite(MotorRE, 0); // Left motor speed is 0 (Motor stopped)
 }
 void turnaroundtillseetheline(){// We define function for the movement of the robot turn back to the line
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 180); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 0); 
}
