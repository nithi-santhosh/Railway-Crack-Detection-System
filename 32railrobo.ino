   /*
 * -----------------------------------------Frameware------------------------------------------------                     
 * ---------------------------------------GreenEngine-----------------------------------------------
 * ---------------------------------------------------------------------------------------------------
 */
#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESPAsyncWebServer.h>

#elif defined(ESP32)
#include <WiFi.h>
#include <ESPmDNS.h>
#include <ESP32Servo.h>

#else
#error "Board not found"
#endif
#include <WebSocketsServer.h>
#include <ArduinoJson.h>
#include <Ticker.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80); // server port 80
WebSocketsServer websockets(81);
int trigPin = 5;    // Trigger
int echoPin = 18;    // Echo
int trigPin1 = 25;    // Trigger
int echoPin1 = 26;    // Echo


long duration, cm, inches;
long duration1, cm1, inches1;


/*int con1 = 22;
int con2 = 23;
int flame = 22;
#define LM1 25
#define LM2 26
#define RM1 27
#define RM2 14
#define pump1 32
#define pump2 33
#define pwm1 13
#define pwm2 12

#define Logic1 19
#define Logic2 18
//#define Logic3 21

//
int pinLogic = 0;
int modeLogic = 0;
 /*                              AOO (Abnormal Output Only)
 *                              NIO (Normal Input Output)
 *                              PD  (Pin Direction)
 *                              PDF (Pin Direction Flag)
 *                              PDM (Pin Direction Memory)
 *                              DPF (Demo Program Flag)
 */
  


int PDM1 ,PDM2 ,PDM3 ,PDM4 ,PDM5 ;  //Pin Direction Memory
int DPF , TDPF =0 ;                   //Demo program flag
int sensradar = 0 , senspir = 0 , sensservo = 0;
int fast = 50;
/* 
 *                                  Variables for programs
 *  
 */
int button_flag ,button_flag1 , TWC ,TWC1,SF , TWC2;  // TWC(Test Write Cache) SF(sensor flag)
int MF , ML=111 ; //Memory flag; Memory Location
int p1 ,p2,p3,p4,p5,p6,p7 ,pv1 , pv2 ,pv3 ,pv4 , pv5 ,pv6 ,pv7 ,pv8;// relay 8 button cache
int q1=1 ,q2=2,q3=3,q5=5,q4=4,q6=6 ,q7=7,q8 = 8;
void send_sensor();
int tog = HIGH;

////////////////////////////////////////////////

unsigned long RCWLpreviousMillis = 0;        
// constants won't change:
const long RCWLinterval = 1000;
int rcwlf , rcwlf1;
//////////////////////////////////////////
void send_sensor()
{
   int sens = SF;
   q1 = cm;
   q2 = cm1;
   q3 = 3;
   q4 = 4;
  // JSON_Data = {"temp":t,"hum":h}"
  String JSON_Data = "{\"sens\":";
         JSON_Data += sens;
         JSON_Data += ",\"q1\":";
         JSON_Data += q1 ; 
         JSON_Data += ",\"q2\":";
         JSON_Data += q2 ;
         JSON_Data += ",\"q3\":";
         JSON_Data += q3 ;
         JSON_Data += ",\"q4\":";
         JSON_Data += q4 ;
         JSON_Data += ",\"q5\":";
         JSON_Data += q5 ;
         JSON_Data += ",\"q6\":";
         JSON_Data += q6 ;
         JSON_Data += "}";
   //Serial.println(JSON_Data);     
  websockets.broadcastTXT(JSON_Data);
}
//////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////
char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Robot Controller</title>
<style>
  body {
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
    background-color: #f4f4f4;
    color: #333;
    margin: 0;
    padding: 0;
    display: flex;
    justify-content: center;
    align-items: center;
    min-height: 100vh;
  }
  .container {
    background-color: #fff;
    padding: 20px;
    border-radius: 10px;
    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
    text-align: center;
    max-width: 400px;
    width: 100%;
  }
  h1 {
    color: #007bff;
  }
  .btn {
    padding: 10px 20px;
    margin: 10px;
    font-size: 16px;
    cursor: pointer;
    border: none;
    border-radius: 5px;
    background-color: #007bff;
    color: #fff;
    transition: background-color 0.3s ease;
  }
  .btn:hover {
    background-color: #0056b3;
  }
  .status {
    margin-top: 20px;
    font-size: 24px;
  }
  .value {
    font-size: 36px;
    color: #28a745;
    margin-top: 10px;
  }
  .info-box {
    margin-top: 20px;
    padding: 15px;
    border: 2px solid #333;
    border-radius: 10px;
    background-color: #f0f0f0;
  }
</style>
</head>
<body>
  <div class="container">
    <h1>Robot Controller</h1>
    <div class="btn-box">
      <button id="no-train-btn" class="btn" onclick= "one()" >No Train</button>
      <button id="train-detected-btn" class="btn"   onclick= "two()">Train Detected</button>
      <button id="normal-btn" class="btn"  onclick= "three()">Normal</button>
      <button id="start-btn" class="btn"  onclick= "four()">Start</button>
      <button id="stop-btn" class="btn"  onclick= "five()">Stop</button>
      
    </div>
    <div class="info-box">
      <h2>Crack Location</h2>
      <p><span id = "Loc"> N/A</span></p>
    </div>
    <div class="value">
      <h3>Status: <span id="statusText">N/A</span></h3>
    </div>
    <div class="status">
      <h3>Distance L: <span id="distanceValue">N/A</span> cm</h3>
      <h3>Distance R: <span id="distanceValueR">N/A</span> cm</h3>
    </div>
  </div>

  <script>
   var connection = new WebSocket('ws://'+location.hostname+':81/');
 var gh = 1,gh1 = 1,gh2 = 1,gh3 = 1,gh4 = 1,gh5 = 1,gh6 = 1,gh7 = 1,gh8 = 1 ;
var tester_status = 0 ;
var TWC4 = 0;
var sf = 0;
var writer_status = 0;
 var pv1 = 0 , pv2 = 50 , pv3 = 0 , pv4 =0 , pv5 = 0 , pv6 = 0 ,pv7 = 0 ,pv8 = 0 , pv =0;
 var sens_data = 0;
 var q1_data =0 , q2_data =0 ,q3_data =0 , q4_data =0,q5_data =0,q6_data =0,q7_data =0 ,q8_data = 0 ;
connection.onmessage = function(event){  //sensor value update functionn

  var full_data = event.data;//
  console.log(full_data);
  var data = JSON.parse(full_data);
  sens_data = data.sens;
  q1_data = data.q1;
  q2_data = data.q2;
  q3_data = data.q3;
  q4_data = data.q4;
  q5_data = data.q5;
  q6_data = data.q6;
  
      if (q1_data > 4 || q2_data > 4 ) {
        document.getElementById("statusText").textContent = "Crack Detected";
        document.getElementById("Loc").textContent = "Latitude = 10.5543 ,longitude = 76.22440" ;

      } else {
        document.getElementById("statusText").textContent = "Normal";
      }

      document.getElementById("distanceValue").textContent = q1_data;
      document.getElementById("distanceValueR").textContent = q2_data;
    }



 function send_data()
{
  var full_data = '{"T" :'+tester_status+',"W":'+writer_status+',"TWC":'+TWC4+',"p1":'+pv1+',"p2":'+pv2+',"p3":'+pv3+',"p4":'+pv4+'}';
  connection.send(full_data);
}


function sli1()
{
    document.getElementById("SPEED").innerHTML=document.getElementById("my1").value;
 
    pv2 = document.getElementById("my1").value;
    send_data();

}

function one()
{
  
pv1 = 1;  
    send_data();
}
function two()
{  
  
  pv1= 2;
  send_data();

}
function three()
{
  pv1=3; 
    send_data();
}
function four()
{
  pv1=4; 
    send_data();
}
function five()
{
  pv1=5; 
    send_data();
}

  </script>

</body >
</html> 
)=====";
///////////////////////////////////////////////
