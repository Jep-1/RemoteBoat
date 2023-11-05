#include <BluetoothSerial.h>

int JoyStick_X = 4; //x
int JoyStick_Y = 2; //y 4095
bool check = false;

BluetoothSerial SerialBT;
void connectToSlave() {
  // This should be the name or address of the Slave ESP32
  SerialBT.connect("Boat");
}
void setup() {

  Serial.begin(115200);
  Serial.print("Starting Bluetooth For Controller... \n");

  SerialBT.begin("Controller");
  while (!SerialBT.connect("Boat")) {
    Serial.println("Attempting to connect to Boat...");
    delay(2000); // Wait for 2 seconds before retrying
  }
  Serial.println("Connected to Boat!");
  delay(5000);

}

void loop() {
  int up, heading;
  up=analogRead(JoyStick_Y);
  heading=analogRead(JoyStick_X);
  Serial.print(up);
  Serial.print(", ");
  Serial.println(heading);
  

  String joystickData = String(heading) + "," + String(up) + "\n";
  SerialBT.print(joystickData);
  delay(5000);
}
