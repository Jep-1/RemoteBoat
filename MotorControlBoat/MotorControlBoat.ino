#include <ESP32Servo.h>
#include <BluetoothSerial.h>

Servo myServo;
BluetoothSerial SerialBT;
int JoyStick_X = 27; //x
int JoyStick_Y = 26; //y 4095
int motorPin = 32; //Motor
int servoPin = 33; //Servo pin

  void setup() 
{
  pinMode(motorPin, OUTPUT);
  myServo.attach(servoPin);
  Serial.begin(115200); // 115200 bps
  Serial.print("Starting Bluetooth For Boat... \n");
  SerialBT.begin("Boat");
  delay(1000);
}
void loop() 
{
  int up, heading;
  //up=analogRead(JoyStick_Y);
  //heading=analogRead(JoyStick_X);
  //Serial.print(up);
  //Serial.print(", ");
  //Serial.print(heading);
  //Serial.print("\n");
  if (SerialBT.available()) {
    // Read the incoming string until newline character
    String data = SerialBT.readStringUntil('\n');
    Serial.print(data);
    
    // Split the data into two parts based on the comma
    int commaIndex = data.indexOf(',');
    if (commaIndex != -1) {
      // Parse the up value from the part before the comma
      up = data.substring(0, commaIndex).toInt();
      
      // Parse the heading value from the part after the comma
      heading = data.substring(commaIndex + 1).toInt();
      
      // Now you can use `up` and `heading` as the joystick values
    }
  }
  if(up == 4095){
    digitalWrite(motorPin, HIGH);
  }
  else{
    digitalWrite(motorPin, LOW);
  }
  if (heading == 4095){
    //servoAngle = map(heading, 0, 4095, 0, 0);
    myServo.write(45);
  }
  else if (heading < 200){
    //servoAngle = map(heading, 0, 4095, 0, 180);
    myServo.write(135);
  }
  else{
    myServo.write(90);
  }
}