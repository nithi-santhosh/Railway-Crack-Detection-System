/*
 * This arduino code for Railway Crack Detection System Phase 01
 *
 * Includes crack detection, obtaining location and alert system
 */
#include <TinyGPS++.h>
#include <SoftwareSerial.h>


#define TRIG_PIN 6 // Arduino pin 3 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN 5 // Arduino pin 2 connected to Ultrasonic Sensor's ECHO pin
#define BUZZER 8 //initialize digital IO pin that controls the buzzer


const int RXPin = 2, TXPin = 3;
const int GPSBaud = 9600; //Default baud of NEO-6M is 9600


TinyGPSPlus gps; // The TinyGPS++ object


SoftwareSerial ss(RXPin, TXPin); // The serial connection to the GPS device


float distance_cm;


void setup() {
  Serial.begin(9600); // Start the Arduino hardware serial port at 9600 baud

  ss.begin(GPSBaud); // Start the software serial port at the GPS's default baud
  
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


void location() {
  while (ss.available() > 0){
    //Serial.print("E");
    gps.encode(ss.read());
    //if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
      break;
  
  }
}


void crack_detection(float distance) {
  if(distance > 6) {
    digitalWrite(BUZZER, HIGH);// produce sound
    Serial.println("CRACK DETECTED");
    location();
    
  }
  else {
    digitalWrite(BUZZER, LOW);
    
  }
}


void loop() {

  
  distance_cm = calculate_distance();
  crack_detection(distance_cm);
  
  
  delay(1000);
  
  // print the value to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(1000);

  


}
