#include <WiFi.h>

int JoyStick_X = 4; //x
int JoyStick_Y = 2; //y 4095

const char *ssid = "Master"; // SSID of the access point to connect to
const char *password = "LigmaLigma"; 

WiFiServer server(80);

void setup() {

  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  server.begin();
  
  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  int up, heading;
  up=analogRead(JoyStick_Y);
  heading=analogRead(JoyStick_X);
  WiFiClient client = server.available();
  
  //Serial.print(up);
  //Serial.print(", ");
  //Serial.println(heading);

  if (client) { // If a new client connects,
    Serial.println("New Client."); // print a message out in the serial port
    while (client.connected()) { // loop while the client's connected
      // Wait for the client to send data
      if (client.available()) {

      }
    }
  }

  delay(5000);
}
