int referancevalue = 600; // value that distinguishes Black and white surface 
//the reference should be redefined according to the values read from the sensor,because this value varies depending on the environment and the sensor to determine the reference point, the value read on the black surface and the average of the value read on the white surface can be taken

void setup()
{
  Serial.begin(9600); // we started serial communication at 9600 baud rate to send data 

}

void loop()
{
  int sensorvalue1 = digitalRead(A1); // Analog value from Sensor 5 is converted to digital
  int sensorvalue2 = digitalRead(A2); // Analog value from Sensor 4 is converted to digital
  int sensorvalue3 = analogRead(A3);// Analog value from Sensor 3 is converted to digital
  int sensorvalue4 = analogRead(A4);// Analog value from Sensor 2 is converted to digital
  int sensorvalue5 = analogRead(A5);// Analog value from Sensor 1 is converted to digital
 Serial.print("1st. Value read from the sensor= ");
 Serial.print(sensorvalue1); //The value read from Sensor 1 is printed on the screen. This value can be adjusted according to the reference
 Serial.print("2nd. Value read from the sensor=");
 Serial.println(sensorvalue2); //The value read from Sensor 2 is printed on the screen. This value can be adjusted according to the reference
 Serial.print("3th. Value read from the sensor=");
 Serial.println(sensorvalue3); //The value read from Sensor 3 is printed on the screen. This value can be adjusted according to the reference
 Serial.print("4th. Value read from the sensor= ");
 Serial.println(sensorvalue4); //The value read from Sensor 4 is printed on the screen. This value can be adjusted according to the reference
 Serial.print("5th. Value read from the sensor= ");
 Serial.println(sensorvalue5); //The value read from Sensor 5 is printed on the screen. This value can be adjusted according to the reference

}
