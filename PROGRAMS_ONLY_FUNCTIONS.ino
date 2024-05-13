void ctrl()
{
  if(pv1 == 1)
  {
    Serial.println("8");

    pv1 = 0;
  }if(pv1 == 2)
  {
    Serial.println("7");
        pv1 = 0;

  }if(pv1 == 3)
  {
    Serial.println("9");
        pv1 = 0;

  }

  if(pv1 == 4)
  {
    Serial.println("5");
    delay(100);
     Serial.println("5");

        pv1 = 0;

  }

  if(pv1 == 5)
  {
    Serial.println("6");
        pv1 = 0;

  }
}



/*int UltraSonic()
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(50);
return cm;
}
void remoteCar()
{

if(pv1 == 6 ||pv1 == 5)
{
  digitalWrite(LM1  ,LOW);
  digitalWrite(LM2  ,LOW);
  digitalWrite(RM1  ,LOW);       //STOP
  digitalWrite(RM2  ,LOW);

}
if(pv1 ==1||pv1 ==2)
{
  
 digitalWrite(LM1  ,HIGH);
  digitalWrite(LM2  ,LOW);
  digitalWrite(RM1  ,HIGH);       //STOP
  digitalWrite(RM2  ,LOW);
}
if(pv1 ==9||pv1 ==10)
{
   digitalWrite(LM1  ,LOW);
  digitalWrite(LM2  ,HIGH);
  digitalWrite(RM1  ,LOW);       //STOP
  digitalWrite(RM2  ,HIGH);      //REVERSE
}



if(pv1 ==3||pv1 ==4)
{
   digitalWrite(LM1  ,LOW);
  digitalWrite(LM2  ,HIGH);
  digitalWrite(RM1  ,HIGH);       //STOP
  digitalWrite(RM2  ,LOW);
}
if(pv1 ==7||pv1 ==8)
{
   digitalWrite(LM1  ,HIGH);
  digitalWrite(LM2  ,LOW);
  digitalWrite(RM1  ,LOW);       //STOP
  digitalWrite(RM2  ,HIGH);
}



if(pv1 ==11||pv1 ==12)
{
    myServo.write(10);  // Rotate servo to the specified angle

  Serial.println("arm open");
}

if(pv1 ==13||pv1 ==14)
{
    myServo.write(90);  // Rotate servo to the specified angle

  Serial.println("arm close");
  
}

}*/
