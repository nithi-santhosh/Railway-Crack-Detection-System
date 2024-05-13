void loop()
{
  websockets.loop();
  send_sensor();
ctrl();

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
  
  //Serial.print(inches);
 // Serial.print("in, ");
 // Serial.print(cm);
 // Serial.print("cm");
 // Serial.println();


  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);
 
  // Convert the time into a distance
  cm1 = (duration1/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches1 = (duration1/2) / 74;   // Divide by 74 or multiply by 0.0135

 /* if (digitalRead(Logic1) && digitalRead(Logic2))
  {

    Serial.println("manual - arm");
    remoteCar();
    if (pinLogic != 8)
    {

      digitalWrite(LM1  , LOW);
      digitalWrite(LM2  , LOW);
      digitalWrite(RM1  , LOW);      //STOP
      digitalWrite(RM2  , LOW);

      digitalWrite(pump1, LOW);
      digitalWrite(pump2, LOW);
      myServo.attach(trigPin);  // Attach the servo on GPIO 2

      //pinMode(trigPin, OUTPUT);
      //pinMode(echoPin, INPUT);
      pinLogic = 8;
    }

    modeLogic = 0;
  }

  if (digitalRead(Logic1) && !digitalRead(Logic2))
  {

    Serial.println("Ultrasonic");
    if (pinLogic != 10)
    {
      digitalWrite(LM1  , LOW);
      digitalWrite(LM2  , LOW);
      digitalWrite(RM1  , LOW);      //STOP
      digitalWrite(RM2  , LOW);

      digitalWrite(pump1, LOW);
      digitalWrite(pump2, LOW);
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
      pinLogic = 10;
    }
    UltraSonic();
    modeLogic = 1;
    if (cm > 15)
    {
      Serial.println("going forward ");
      digitalWrite(LM1  , HIGH);
      digitalWrite(LM2  , LOW);
      digitalWrite(RM1  , HIGH);      //STOP
      digitalWrite(RM2  , LOW);

    }
    else
    {
      Serial.println("Stop ");

      digitalWrite(LM1  , LOW);
      digitalWrite(LM2  , LOW);
      digitalWrite(RM1  , LOW);      //STOP
      digitalWrite(RM2  , LOW);

    }
  }

  if (!digitalRead(Logic1) && digitalRead(Logic2))
  {
    modeLogic = 2;
    if (pinLogic != 12)
    {
      Serial.println("line follower");
      pinMode(trigPin, INPUT);
      pinMode(echoPin, INPUT);
      digitalWrite(LM1  , LOW);
      digitalWrite(LM2  , LOW);
      digitalWrite(RM1  , LOW);      //STOP
      digitalWrite(RM2  , LOW);

      digitalWrite(pump1, LOW);
      digitalWrite(pump2, LOW);
      pinLogic = 12;
    }
    Serial.print("l1 = ");
    Serial.println(digitalRead(con1));
    Serial.print("R1 = ");

    Serial.println(digitalRead(con2));


    Serial.println("line follower");

    int con1Value = digitalRead(con1);
    int con2Value = digitalRead(con2);

    // Line following logic
    if (con1Value == LOW && con2Value == LOW) {
      // Both sensors on line (move forward)
      Serial.println("forward");
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
    } else if (con1Value == HIGH && con2Value == LOW) {
      // Left sensor off line (adjust left)
      Serial.println("Left");

      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
    } else if (con1Value == LOW && con2Value == HIGH) {
      // Right sensor off line (adjust right)
      Serial.println("right");

      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
    } else {
      // Both sensors off line (stop)
      Serial.println("stop");

      digitalWrite(LM1, LOW);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, LOW);
    }


  }


  if (!digitalRead(Logic1) && !digitalRead(Logic2))
  {

    Serial.println("Flame");

    if (pinLogic != 13)
    {
      digitalWrite(LM1  , LOW);
      digitalWrite(LM2  , LOW);
      digitalWrite(RM1  , LOW);      //STOP
      digitalWrite(RM2  , LOW);

      digitalWrite(pump1, LOW);
      digitalWrite(pump2, LOW);

      modeLogic = 3;
      Serial.println("Flame");
      pinMode(flame, INPUT);
      pinLogic = 13;

    }



    if (digitalRead(flame) == 0)
    {

      Serial.println("Flame detected");
      digitalWrite(pump1, HIGH);
      digitalWrite(pump2, LOW);

      Serial.println("Stop ");
      digitalWrite(LM1  , LOW);
      digitalWrite(LM2  , LOW);
      digitalWrite(RM1  , LOW);      //STOP
      digitalWrite(RM2  , LOW);


    }
    else
    {
      digitalWrite(pump1, LOW);
      digitalWrite(pump2, LOW);


      Serial.println("going forward ");
      digitalWrite(LM1  , HIGH);
      digitalWrite(LM2  , LOW);
      digitalWrite(RM1  , HIGH);      //STOP
      digitalWrite(RM2  , LOW);


    }
  }
*/
  yield();
}
//delay(100);
