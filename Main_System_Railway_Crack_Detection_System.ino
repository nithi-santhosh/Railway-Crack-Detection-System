#define BUZZER 21 //initialize digital IO pin that controls the buzzer
#define TRIG_PIN 23 // ESP-32 GPIO pin 23 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN 22 // ESP-32 GPIO pin 22 connected to Ultrasonic Sensor's ECHO pin

float distance_cm;


void setup() {
  Serial.begin(9600); // Start the Arduino hardware serial port at 9600 baud
  
  pinMode(TRIG_PIN, OUTPUT); // configure the trigger pin to output mode
  pinMode(ECHO_PIN, INPUT); // configure the echo pin to input mode

  pinMode(BUZZER, OUTPUT);// configure buzzer pin to output mode

}


float calculate_distance() {
  float  duration_us, temperature_K, distance_cm, sound_speed_air;
  
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration_us = pulseIn(ECHO_PIN, HIGH); // measure duration of pulse from ECHO pin
  temperature_K = 273.16 + 30; // Surrounding temperature in Kelvin
  sound_speed_air = 20.05* sqrt(temperature_K); // Speed of sound in air
  distance_cm = (sound_speed_air*duration_us)/20000;
  
  return distance_cm;
}


void crack_detection(float distance) {
  if(distance > 6) {
    digitalWrite(BUZZER, HIGH);// produce sound
    Serial.println("CRACK DETECTED");
       
  }
  else {
    digitalWrite(BUZZER, LOW);
    
  }
}


void loop() {
  distance_cm = calculate_distance();
  crack_detection(distance_cm);

  // print the value to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(1000);

}
