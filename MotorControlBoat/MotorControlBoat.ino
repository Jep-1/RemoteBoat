#include <ESP32Servo.h>
#include <WiFi.h>

Servo myServo;
int JoyStick_X = 27; //x
int JoyStick_Y = 26; //y 4095
int motorPin = 32; //Motor
int servoPin = 33; //Servo pin
const char *ssid = "Master"; // SSID of the access point to connect to
const char *password = "LigmaLigma"; 

  void setup() 
{
  pinMode(motorPin, OUTPUT);
  myServo.attach(servoPin);
  Serial.begin(115200); // 115200 bps
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
}

void loop() 
{
  int up, heading;
  up =
  heading = 
  if(up == 4095){
    digitalWrite(motorPin, HIGH);
  }
  else{
    digitalWrite(motorPin, LOW);
  }
  if (heading == 4095){
    myServo.write(45);
  }
  else if (heading < 200){
    myServo.write(135);
  }
  else{
    myServo.write(90);
  }
}