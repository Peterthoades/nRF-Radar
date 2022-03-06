/*Peter Rhoades:
Saturday 05/03/22:
nRF Transmitter to Laser Range Reciver MEGA®
VL53L0X Address 0x29:
18/02/22 pipe = 0x8675309ABCll changer to const byte address[6] = "00001";:
05/03/22 Servo pulse 0°to60°to30°to90°etc:

°
 nRF Tranciver 
  1 = GRN  Black   
  2 = 3.3v Red
  3 = CE   Pin 7  Blue
  4 = CSN  Pin 8  Breen
  5 = SCK  Pin 52 Yellow
  6 = MOSI Pin 51 White
  7 = MISO Pin 50 Orange
   _______________________
  | 1 | 2 |              |
  | 3 | 4 |              | 
  | 5 | 6 |              |
  |_7_|___|______________|
*/

#include  <SPI.h>
#include "RF24.h"
#include <Servo.h>.   
int distance;//Measurement to Radar Display:
#include <Wire.h>
#include <VL53L0X.h> //Laser ToF
VL53L0X sensor;
Servo myServo; //Creates a servo object for controlling the servo motor  
const byte address[6] = "00001"; //Writing Message Only Pipe:
RF24 radio(7,8);

struct dataStruct
{
  int  angle180;
  int  distanceMM;
} myData; //Holds Payload Data to be Sent:

void setup() {  
  Serial.begin(9600); 
  Wire.begin();
  sensor.init();//Starts Sensor:
  sensor.startContinuous(); //Start continuous back-to-back mode:
  radio.begin();
  radio.openWritingPipe(address); //Writing Message Only:
  radio.enableDynamicPayloads();
  myServo.attach(3);//Defines on which pin is the servo motor attached: 
 }  
  void loop() {     // Set of Functions Covers All Areas:
  OneSix();         //1  -  60
  SixThree();       //60  - 30
  ThreeNine();      //30  - 90
  NineSix ();       //90  - 60
  SixOneTwo();      //60  - 120
  OneTwoNine();     //120 - 90
  NineOneFive();    //90  - 150
  OneFiveOneTwo();  //150 - 120
  OneTwoOneFive();  //120 - 150
  OneFiveOneTwoB(); //150 - 120
  OneTwoOneEight(); //120 - 180
  OneEightOneTwo(); //180 - 120
  OneTwoOneFiveB(); //120 - 150
  OneFiveNine();    //150 - 90
  NineOneTwo();     //90  - 120
  OneTwoSix();      //120 - 60
  SixNine();        //60  - 90
  NineThree();      //90  - 30
  ThreeSix();       //30  - 60
  SixOne();         //60  - 1
  ThreeOneFive();   //30  - 150
  OneFiveThree();   //150 - 30
  SixOneTwoB();     //60  - 120
  OneTwoSixB();     //120 - 60
  FullSweep();      //1   - 180
  FullBackSweep();  //180 - 1
    
  }
  void OneSix()
 {   
  for(int i=1;i<=60;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i; 
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i; //Add angle180 to myData:
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance; //Add distanceMM to myData:
  radio.write( &myData, sizeof(myData) ); //Sent myData:
  }
 }
  void SixThree()
  {
  for(int i=60;i>=30;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
  } 
 void ThreeNine()
 {
 for(int i=30;i<=90;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
 }
 }
 void NineSix ()
 {
   for(int i=90;i>=60;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void SixOneTwo()
 {
  for(int i=60; i<=120;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void OneTwoNine()
 {
  for(int i=120; i>=90;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void NineOneFive()
 {
  for(int i=90; i<=150;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void OneFiveOneTwo()
 { 
  for(int i=150; i>=120;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void OneTwoOneFive()//NineOneFiveB()
 {
  for(int i=120; i>=150;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void OneFiveOneTwoB() 
 {
  for(int i=150; i<=120;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void OneTwoOneEight()
 {
  for(int i=120; i<=180;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
   }
 }
 void OneEightOneTwo()
 {
  for(int i=180; i>=120;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void OneTwoOneFiveB()
 {
    for(int i=120; i<=150;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
  void OneFiveNine()
  {
  for(int i=150; i>=90; i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void NineOneTwo()
 {
  for(int i=90;i<120;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
void OneTwoSix()
{
   for(int i=120;i>60;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void SixNine()
 {
  for(int i=60;i<90;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void NineThree()
 {
  for(int i=90;i>30;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void ThreeSix()
 {
  for(int i=30;i<60;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
  }
 void SixOne()
 {
  for(int i=60;i>1;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
  void ThreeOneFive()
 {
 for(int i=30;i<=150;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
 }
}
 void OneFiveThree()
  {
  for(int i=150; i>=30; i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void SixOneTwoB()
 {
 for(int i=60;i<=120;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
 }
}
void OneTwoSixB()
{
for(int i=120; i>=60; i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
 void FullSweep()
 {   
  for(int i=1;i<=180;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i; 
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i; //Add angle180 to myData:
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance; //Add distanceMM to myData:
  radio.write( &myData, sizeof(myData) ); //Sent myData:
  }
 }
 void FullBackSweep()
 {
  for(int i=180; i>=1;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
