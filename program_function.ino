
//////////////////////////////////////////////////
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

  switch (type) 
  {
    case WStype_DISCONNECTED:
     // Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {
        IPAddress ip = websockets.remoteIP(num);
      //  Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
      }
      break;
    case WStype_TEXT:
     // Serial.printf("[%u] get Text: %s\n", num, payload);
      String message = String((char*)( payload));
     // Serial.println(message);

      
     DynamicJsonDocument doc(200);
    // deserialize the data
    DeserializationError error = deserializeJson(doc, message);
    // parse the parameters we expect to receive (TO-DO: error handling)
      // Test if parsing succeeds.
  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }

 int LED1_status = doc["T"];
  int LED2_status = doc["W"];
  int TWCF = doc["TWC"];
   pv1 = doc["p1"];
   pv2 = doc["p2"];
   pv3 = doc["p3"];
   pv4 = doc["p4"];
   
 // digitalWrite(LED1,LED1_status);
  //digitalWrite(LED2,LED2_status);
  //Serial.println(LED1_status);
  button_flag= LED1_status;
  button_flag1= LED2_status;
  p1  = pv1 ;p2  = pv2 ;p3  = pv3 ;p4  = pv4 ;p5  = pv5 ;p6  = pv6 ;p7  = pv7 ;
  TWC = TWCF; //TESTER WRITER CACHE FLAG (TWCF)
  }
}

////////////////////////////////////////////////////
