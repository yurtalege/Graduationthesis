
//define sensors and motors pin
#define echoPin_1 31 
#define trigPin_1 33 
#define echoPin_2 35 
#define trigPin_2 37
#define MotorR1 50
#define MotorR2 48
#define MotorRE 52  
#define MotorL1 46
#define MotorL2 44
#define MotorLE 42
int mostrightsensor= A5;
int rightsensor =A4;
int middlesensor =A3;
int leftsensor =A2;
int mostleftsensor =A1;

int referancevalue = 600;
long duration1, distance1, duration2, distance2; 


void setup() {
//sensors and motor pins define input and output
  pinMode(echoPin_1, INPUT);
  pinMode(trigPin_1, OUTPUT);
  delay(10);
  pinMode(echoPin_2, INPUT);
  pinMode(trigPin_2, OUTPUT);

 
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT); 
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);
  
  pinMode(mostrightsensor,INPUT);
  pinMode(rightsensor, INPUT);
  pinMode(middlesensor, INPUT);  
  pinMode(leftsensor, INPUT);
  pinMode(mostleftsensor, INPUT);



  Serial.begin(9600);// we started serial communication at 9600 baud rate to send data 

}

void loop() {
  mostrightsensor = analogRead(A5); // Analog value from Sensor output 5 is converted to digital
  rightsensor = analogRead(A4); // Analog value from Sensor output 4 is converted to digital
  middlesensor = analogRead(A3);// Analog value from Sensor output 3 is converted to digital
  leftsensor = analogRead(A2);// Analog value from Sensor output 2 is converted to digital
  mostleftsensor = analogRead(A1);// Analog value from Sensor output 1 is converted to digital

//for front sensor
  digitalWrite(trigPin_1, LOW);// sensor was deactivated
  delayMicroseconds(2);
  digitalWrite(trigPin_1, HIGH); // Ordered to produce Sensore sound wave
  delayMicroseconds(2);
  digitalWrite(trigPin_1, LOW); // Trig pin was moved to low position so that no new waves could be produced
  delayMicroseconds(2);
  duration1 = pulseIn(echoPin_1, HIGH);// measuring the duration of the sound wave to return
  distance1 = duration1 / 29.1 / 2; // measured time converting to distance
  //for left sensor
  digitalWrite(trigPin_2, LOW);// sensor was deactivated
  delayMicroseconds(2);
  digitalWrite(trigPin_2, HIGH); // Ordered to produce Sensore sound wave
  delayMicroseconds(2);
  digitalWrite(trigPin_2, LOW); // Trig pin was moved to low position so that no new waves could be produced
  delayMicroseconds(2);
  duration2 = pulseIn(echoPin_2, HIGH); // measuring the duration of the sound wave to return
  distance2 = duration2 / 29.1 / 2; // measured time converting to distance

  Serial.println(distance1);//writing distance at serial port screen
  Serial.println(distance2);//writing distance at serial port screen
 
    if (distance1 > 20 && distance2 > 20){//if there are no obstacles
    drive();//line tracking continue
  }
 
  else if (distance1 < 20 && distance2 > 20 ) //if there are obstacles
  
   turnright();// turn right
   delay(100);
   goforward();//goforward
   
  }

  
  else if ( uzaklik1 > 20 && uzaklik2 < 20 )
  {
  
    turnleft();// turn left
    delay(100);
    goforward();//goforward
    
    
  }
  else {
   drive();//line tracking continue
  }
 
}

void drive() {
      if((mostleftsensor) >= referancevalue && (leftsensor) >= referancevalue && (middlesensor) <= referancevalue && (rightsensor)>= referancevalue && (mostrightsensor) >= referancevalue ){  
  // when the middle sensor  see the line, the robot moves forward.
   goforward();  // go forward 
   }
   
else if((mostleftsensor) >= referancevalue && (leftsensor) >= referancevalue && (middlesensor) >= referancevalue && (rightsensor) >= referancevalue && (mostrightsensor) >=referancevalue   ){  
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

void goforward(){  // We define a function for the robot's forward motion.

  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 130); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 130); 
  
}


void turnright(){ // We define a function for the robot's right rotation movement.

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 0); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 130); 
  
} 

void turnleft(){ // We define a function for the robot's left rotation movement.

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
  analogWrite(MotorRE, 0);

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 190); 
}
