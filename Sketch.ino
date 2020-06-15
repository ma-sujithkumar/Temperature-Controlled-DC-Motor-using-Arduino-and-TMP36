
void setup()
{
  pinMode(A0, INPUT); //setting pin A0 as analog input to read data from the sensor
  pinMode(11, OUTPUT); //to control motor's speed
  Serial.begin(9600); //initiate serial communication and set the baud rate to be 9600 Hz
}

void loop()
{
  double sensor=-40 + 0.488155 * (analogRead(A0) - 20); //read input
  double rpm=sensor*2.4; //scaling
  Serial.print("The measured temp. value is ");
  Serial.println(sensor);
  if(sensor>20.00)
  {
    analogWrite(11,rpm);
   
  }
  else
  {
    analogWrite(11,0);
    Serial.println("The motor is now off");

  }
}