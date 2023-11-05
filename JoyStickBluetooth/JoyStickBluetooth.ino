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
  WiFiClient client = server.available();
  int up, heading;
  up=analogRead(JoyStick_Y);
  heading=analogRead(JoyStick_X);

  if (client){
    Serial.println("New Client.");          
    while (client.connected()) {
      client.println("Hello Client!");
      delay(1000);  // Delay to avoid flooding the client with messages
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }

  delay(5000);
}
