//Arduino Connections:
const int s0 = 51;
const int s1 = 53;
const int s2 = 47;
const int s3 = 49;
const int out = 45;

int red = 0;
int green = 0;
int yellow = 0;

int mostrightsensor= A5;
int rightsensor =A4;
int middlesensor =A3;
int leftsensor =A2;
int mostleftsensor =A1;
int referancevalue = 600;

int enA = 30;
int in1 = 32;
int in2 = 34;
int enB = 22;
int in3 = 26;
int in4 = 24;

int echoPin_1 = 31;
int trigPin_1 = 33;
int echoPin_2 = 35; 
int trigPin_2 = 37;


long time1, distance1, time2, distance2; // defined variables for ultrasonik sensor


void setup()
{
 Serial.begin(9600);
 
  pinMode(mostrightsensor,INPUT);
  pinMode(rightsensor, INPUT);
  pinMode(middlesensor, INPUT);  
  pinMode(leftsensor, INPUT);
  pinMode(mostleftsensor, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  pinMode(echoPin_1, INPUT);
  pinMode(trigPin_1, OUTPUT);
  delay(10);
  pinMode(echoPin_2, INPUT);
  pinMode(trigPin_2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}
void loop()
{
 color();
 Serial.print("R Intensity:");
 Serial.print(red, DEC);
 Serial.print(" G Intensity: ");
 Serial.print(green, DEC);
 Serial.print(" Y Intensity : ");
 Serial.print(yellow, DEC);
 mostrightsensor = analogRead(A5); // Analog value from Sensor 5 is converted to digital
  rightsensor = analogRead(A4); // Analog value from Sensor 4 is converted to digital
  middlesensor = analogRead(A3);// Analog value from Sensor 3 is converted to digital
  leftsensor = analogRead(A2);// Analog value from Sensor 2 is converted to digital
  mostleftsensor = analogRead(A1);// Analog value from Sensor 1 is converted to digital
if (yellow < red && red < green && red < 60 && green > 80) // (With the lighting these conditions are changing.)
 {
  Stop();
 
 }
 else if (yellow < red && red < green && yellow < 24 && red > 10 && green < 80)
 {
  Stop();
  delay(300);
 Serial.println(" - (Yellow Color)");
 
 }
 else if (yellow <= green && green < red)
 {

 Serial.println(" - (Green Color)"); 
 if((mostleftsensor) >= referancevalue && (leftsensor) >= referancevalue && (middlesensor) <= referancevalue && (rightsensor)>= referancevalue && (mostrightsensor) >= referancevalue ){  
  // when the middle sensor  see the line, the robot moves forward.
   forward();  // go forward 
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
 else 
 { 
  turnaroundtillseetheline();  
 }
}
 else if (yellow < red && red < green && red > 65 && green > 75)
 {
  
 Serial.println(" - (No Color)");
 if((mostleftsensor) >= referancevalue && (leftsensor) >= referancevalue && (middlesensor) <= referancevalue && (rightsensor)>= referancevalue && (mostrightsensor) >= referancevalue ){  
  // when the middle sensor  see the line, the robot moves forward.
   forward();  // go forward 
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
 else { 
  turnaroundtillseetheline();  //turn left
 }
}
 else{

 Serial.println();
 if((mostleftsensor) >= referancevalue && (leftsensor) >= referancevalue && (middlesensor) <= referancevalue && (rightsensor)>= referancevalue && (mostrightsensor) >= referancevalue ){  
  // when the middle sensor  see the line, the robot moves forward.
   forward();  // go forward 
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
 else { 
  turnaroundtillseetheline();  //turn left
 }
 }
 delay(300);
 
  digitalWrite(trigPin_1, LOW);//sensör pasif hale getirildi
  delayMicroseconds(2);
  digitalWrite(trigPin_1, HIGH); //Sensore ses dalgasının üretmesi için emir verildi
  delayMicroseconds(2);
  digitalWrite(trigPin_1, LOW); //Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi
  delayMicroseconds(2);
  time1 = pulseIn(echoPin_1, HIGH); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
  distance1 = time1 / 29.1 / 2; //ölçülen süre uzaklığa çevriliyor
  
  digitalWrite(trigPin_2, LOW);//sensör pasif hale getirildi
  delayMicroseconds(2);
  digitalWrite(trigPin_2, HIGH); //Sensore ses dalgasının üretmesi için emir verildi
  delayMicroseconds(2);
  digitalWrite(trigPin_2, LOW); //Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi
  delayMicroseconds(2);
  time2 = pulseIn(echoPin_2, HIGH); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
  distance2 = time2 / 29.1 / 2; //ölçülen süre uzaklığa çevriliyor


  Serial.println(distance1);
  Serial.println(distance2);
       
    if (distance1 > 25 && distance2 > 20){
    forward(); // ileri git
  } 
  else if (distance1 < 25 && distance2 > 20 ) // Uzaklık 15'den küçük ise,
  {
    turnright();// 500 ms sağa dön
   delay(100);
   forward();
  }
  else if ( distance1 > 25 && distance2 < 20 )
  {
    turnleft();// 700 ms sola dön
    delay(100);
    forward(); 
  }
  else {
    forward();
  }

 }

 
void color()
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
void forward(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 130);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 130);  
  
}
void turnright(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(in1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(in2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(enA, 0); // Sağ motorun hızı 0 (Motor duruyor)

  digitalWrite(in3, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(in4, LOW); // Sol motorun geri hareketi pasif
  analogWrite(enB, 130); // Sol motorun hızı 150
  
} 

void turnleft(){ // Robotun sola dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(in1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(in2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(enA, 130); // Sağ motorun hızı 150

  digitalWrite(in3, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(in4, LOW); // Sol motorun geri hareketi pasif
  analogWrite(enB, 0); // Sol motorun hızı 0 (Motor duruyor)
  
}
 void turnaroundtillseetheline(){
  digitalWrite(in1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(in2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(enA, 0); // Sağ motorun hızı 0 (Motor duruyor)

  digitalWrite(in3, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(in4, LOW); // Sol motorun geri hareketi pasif
  analogWrite(enB, 190); // Sol motorun hızı 150
}
  

void Stop(){ // Robotun durma hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}
