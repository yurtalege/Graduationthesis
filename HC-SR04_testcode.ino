#define trigPin 37  //the sensor's trig pin connects to Arduino's ninth pin.
#define echoPin 35  //the sensor's echo pin connects to Arduino's eight pin.
 
void setup() {
Serial.begin (9600); // we started serial communication at 9600 baud rate to send data 
pinMode(trigPin, OUTPUT); // define trig pin output
pinMode(echoPin, INPUT);  // define echo pin input
}
void loop() {
long duration, distance; //defines distance and duration variables
//trigger signal sent
digitalWrite(trigPin, LOW); // send to trig pin 0v
delayMicroseconds(2); //delay 2 microseconds
digitalWrite(trigPin, HIGH); // send to trig pin 5v
delayMicroseconds(10); //delay 10 microseconds
digitalWrite(trigPin, LOW);  // send to trig pin 0v

duration = pulseIn(echoPin, HIGH); //the reflection of the trigger signal is taken
distance= (duration/2) / 29.1;  // calculate distance 
   if (distance> 200 || distance < 0){
   Serial.println("Out Of Range");   
   }
   else {
   Serial.print(distance);
   Serial.println(" cm"); // print distance 
   }
delay(500); //delay 500 microseconds
}
