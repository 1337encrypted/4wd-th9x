//I think initially all pins are high so we need to manually have to low them
#include <IBusBM.h>
#include "tb6612fng.h"              //include the tb6612fng functions
IBusBM ibus;                        // Create iBus Object
tb6612fng car;

#define t 1000                      //Initial time set to 1 second
//bool stdby = false;                //Initalized the standby to false

int CH0 = 0;                        // LeftShift - RightShift
//int car.Speed = 0;                  // car.Speed (Acceleration)
int CH2 = 0;                        // Forward - Reverse
int CH3 = 0;                        // Left - Right 
//bool CH4 = false;                   // Extra
bool CH5 = false;                   //turn switch
//int CH6 = -100;                     //extra pot
//int CH7 = -100;                     //extra pot

int spd = 0;                        // To help in calculating stick > 180

void setup(){
  
  Serial.begin(115200);             // Start serial monitor for debugging
  ibus.begin(Serial);               // Attach iBus object to serial port
  car.Stp();
}

int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue){
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) 
    return defaultValue;
  return constrain(map(ch, 1000, 2000, minLimit, maxLimit), minLimit, maxLimit);
}

bool readSwitch(byte channelInput, bool defaultValue) {
 int intDefaultValue = (defaultValue) ? 100 : 0;
 int ch = readChannel(channelInput, 0, 100, intDefaultValue);
 return (ch > 50);
}

void loop()
{

  // Get RC channel values
  CH0 = readChannel(0, -255, 255, 0);       // Leftshift - Rightshift
  car.Speed = readChannel(1, 0, 255, 0);    // car.Speed (Acceleration)
  CH2 = readChannel(2, -255, 255, 0);       // Forward - Reverse
  CH3 = readChannel(3, -255, 255, 0);       // Left - Right 
  //CH4 = readSwitch(4, false);
  CH5 = readSwitch(5, false);

  //Buzzer for low speed
  car.buzz();

  if(CH2 > 20)
  {
      //spd = (float)(spd*CH2)/255;
      car.front();
      Serial.println("Foreward: ");
      Serial.println(car.Speed);
  }
  else if(CH2 < -20)
  {
      //spd = abs((float)(spd*CH2)/255);
      car.back();
      Serial.println("Reverse: ");
      Serial.println(car.Speed);
  }
  else if(CH3 > 20)
  {    
      //spd = (float)(spd*CH3)/255;
      car.rightTurn();
      Serial.println("Right Turn: ");
      Serial.println(car.Speed);
  }
  else if(CH3 < -20)
  {
      //spd = abs((float)(spd*CH3)/255);
      car.leftTurn();
      Serial.println("Left Turn: ");
      Serial.println(car.Speed);
  }
  else if(CH0 > 20 && CH5 == false)
  {
      //spd = abs((float)(spd*CH0)/255);
      car.sharpRightTurnFront();
      Serial.println("Sharp Right Turn Front: ");
      Serial.println(car.Speed);
  }
  else if(CH0 < -20 && CH5 == false)
  {
      //spd = abs((float)(spd*CH0)/255);
      car.sharpLeftTurnFront();
      Serial.println("Sharp Left Turn Front: ");
      Serial.println(car.Speed);
  }
  else if(CH0 > 20 && CH5 == true)
  {
      //spd = abs((float)(spd*CH0)/255);
      car.sharpRightTurnBack();
      Serial.println("Sharp Right Turn Back: ");
      Serial.println(car.Speed);
  }
  else if(CH0 < -20 && CH5 == true)
  {
      //spd = abs((float)(spd*CH0)/255);
      car.sharpLeftTurnBack();
      Serial.print("Sharp Left Turn Back: ");
      Serial.println(car.Speed);
  }
  else 
  {
      car.Stp();
      Serial.print("Stop: ");
      Serial.println(car.Speed);
  }
}
