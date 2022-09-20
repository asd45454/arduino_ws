#include <DynamixelSerial1.h>
DynamixelClass Dxl(Serial3);
#include <ros.h>
#include <ard_test/motor.h>
/*
 Setup your scale and start the sketch WITHOUT a weight on the scale
 Once readings are displayed place the weight on the scale
 Press +/- or a/z to adjust the calibration_factor until the output readings match the known weight
 Arduino pin 6 -> HX711 CLK
 Arduino pin 5 -> HX711 DOUT
 Arduino pin 5V -> HX711 VCC
 Arduino pin GND -> HX711 GND 
*/
class NewHardware : public ArduinoHardware
{
  public:
  NewHardware():ArduinoHardware(&Serial, 57600){};
};

ros::NodeHandle_<NewHardware>  nh;
//ros::NodeHandle  nh;

#include "HX711.h"
const int DT_PIN = 6;
const int SCK_PIN = 5;

HX711 scale(5, 6);

double calibration_factor = 2230; // this calibration factor is adjusted according to my load cell
double units;
double ounces;
double kilogram;
double newton;
double a;
double kilogram2;
double newton2;
double b;
double T;

int state_flag = 0;
ard_test::motor state_msg;

void statemessage(const ard_test::motor& state_msg){
  if(state_msg.state){
    state_flag = 1;
  }else{
    state_flag = 0;
  }
}

ros::Subscriber<ard_test::motor> sub("state_pub", &statemessage);

void setup() {
  nh.initNode();
  nh.subscribe(sub);
  Dxl.begin(1000000, 2);
  delay(1000);
  Serial.begin(57600);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");
  Serial.println("CLEARDATA");
  Serial.println("LABEL,TIME,KB,N");
 
  scale.set_scale();
  scale.tare();  //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading
//  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
//  Serial.println(zero_factor);
}

void loop() {

  scale.set_scale(calibration_factor); //Adjust to this calibration factor

//  Serial.print("Reading: ");
  units = scale.get_units(), 10;
  if (units < 0)
  {
    units = 0.00;
  }
  //ounces = units * 0.035274;
  kilogram = units;
  if(state_flag == 1){  
    if(kilogram >= 10)
    {
    Dxl.setEndless(2, ON);
    Dxl.turn(2, LEFT, 1000);
    }
    if(kilogram <= 10)
    {
    Dxl.setEndless(2, OFF);
    }
  }
  else if(state_flag == 0){
    Dxl.setEndless(2, OFF);
    }
  Serial.println();
  Serial.print("DATA,TIMER,");
  Serial.print(kilogram);
  Serial.print(" , ");
  delay(100 ); 

  if(Serial.available())
  {
    char temp = Seriale2.read();
    if(temp == '+' || tmp == 'a')
      calibration_factor += 1;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 1;
  }
  
  nh.spinOnce();
  delay(1000);
}
