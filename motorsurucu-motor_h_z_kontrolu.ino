const int in1 = 6 ; //defines the motion of the left motor in the forward direction.Connects to Arduino's ninth pin
const int in2 = 9;  //defines the motion of the left motor in the reverse direction.Connects to Arduino's tenth pin
const int in3 = 10;//defines the motion of the rigth motor in the reverse direction.Connects to Arduino's twelfth pin
const int in4 = 11;//defines the motion of the rigth motor in the forward direction.Connects to Arduino's eleventh pin
const int enA = 5;  //Enable A define for left engine, and connected to ardiuno's eighth pin
const int enB = 3;//Enable B define for right engine, and connected to ardiuno's thirteenth pin

void setup() 
{
pinMode(in1, OUTPUT); //define in1 pin output
pinMode(in2, OUTPUT); //define in2 pin output 
pinMode(in3, OUTPUT);//define in3 pin output
pinMode(in4, OUTPUT);//define in4 pin output
pinMode(enA, OUTPUT);//define enA pin output
pinMode(enB, OUTPUT);//define enB pin output
}
void loop() 
{
// motor 1
analogWrite(enA,  200);   //enable A sets the first engine speed to 200
digitalWrite(in1, HIGH);//the in1 activates the forward motion of the first engine.
digitalWrite(in2,  LOW);//the in2 passive the movement of the first engine in the reverse direction.
// motor 2
analogWrite(enB,  200);  //enable B sets the second engine speed to 200
digitalWrite(in3, LOW);//the in3 passive the reverse motion of the second engine.
digitalWrite(in4,  HIGH);//the in4 activates the forward motion of the second engine.
}
