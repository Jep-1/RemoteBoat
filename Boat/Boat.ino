#include <esp_now.h>
#include <ESP32Servo.h>
#include <WiFi.h>

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
  int a;
  int b;
} struct_message;

// Create a struct_message called myData
struct_message myData;
int motorPin = 32;
int servoPin = 33;
Servo myServo;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Int a: ");
  Serial.println(myData.a);
  Serial.print("Int b: ");
  Serial.println(myData.b);
  Serial.println();
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  pinMode(motorPin, OUTPUT);
  myServo.attach(servoPin);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {
  int x = myData.a;
  int heading = myData.b;
  if (x == 4095){
    digitalWrite(motorPin, HIGH);
    //Serial.println("HIGH");
  }
  else{
    digitalWrite(motorPin, LOW);
    //Serial.println("LOW");
  }
  if (heading == 4095){
    myServo.write(45);
  }
  else if (heading == 0){
    myServo.write(135);
  }
  else{
    myServo.write(90);
  }
  //delay(2000); // 2 second delay
}