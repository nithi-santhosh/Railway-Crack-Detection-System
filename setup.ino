void setup()


{
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  WiFi.softAP("ROVER","wifirover");
  delay(500);
  Serial.println("");
  Serial.println(WiFi.softAPIP());
   if (MDNS.begin("ESP")) { //esp.local/
    Serial.println("MDNS responder started");
  }
  server.on("/", [](AsyncWebServerRequest * request)
  { 
   
  request->send_P(200, "text/html", webpage);
  });
  server.begin();  // it will start webserver
  websockets.begin();
  websockets.onEvent(webSocketEvent); 
  //BS();

 // remoteCar();
  send_sensor();
}
