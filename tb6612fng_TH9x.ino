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
//boolean CH4 = false;              // Extra
bool CH5 = false;                   //turn switch
//int CH6 = -100;                   //extra pot
//int CH7 = -100;                   //extra pot

int spd = 0;                       // To help in calculating stick > 180

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

  if((CH2 > 40 || CH2 < -40) && (CH0 < 40 && CH0 > -40)){
    
    car.Speed = map(car.Speed,0,255,0,CH2);
    
    if(CH2 > 25){
      car.front();
      Serial.print("Foreward :");  
    }
    else{
      car.Speed = abs(car.Speed);
      car.back();
      Serial.print("Back :");
    }
  }

  
  else if((CH2 > 40 || CH2 < -40) && (CH0 > 40 || CH0 < -40)){                 // Checks for CH2 > 40 and CH0 > 40
   
    car.Speed = map(car.Speed,0,255,0,CH2);                        // car.Speed control mapped to the CH2 pot
    spd = map(spd,0,255,0,CH0);                      // car.Speed control mapped to the CH0 pot

    if(CH2 > 40 && CH0 > 40){
      car.Speed = car.Speed+spd;
      car.leftDiagonalFront();
      Serial.print("LeftDiagonalFront :");
    }
    else if(CH2 > 40 && CH0 < -40){
      car.Speed = car.Speed+abs(spd);
      car.rightDiagonalFront();
      Serial.print("RightDiagonalFront :");
    }
    if(CH2 < -40 && CH0 > 40){
      car.Speed = abs(car.Speed)+spd;
      car.leftDiagonalBack();
      Serial.print("RightDiagonalBack :");
    }
    else if(CH2 < -40 && CH0 < -40){
      car.Speed = abs(car.Speed)+abs(spd);
      car.rightDiagonalBack();
      Serial.print("LeftDiagonalBack :");
    }
  }
  
  
  else if(CH0 > 40 || CH0 < -40){
    
    car.Speed = map(car.Speed,0,255,0,CH0);

    if(CH0 > 40){
      car.rightShift();
      Serial.print("RightShift :");
    }
    else{
      car.Speed = abs(car.Speed);
      car.leftShift();
      Serial.print("LeftShift :"); 
    }
  }

  
  else if((CH3 > 25 || CH3 < -25) && CH5 == 0){
    
    car.Speed = map(car.Speed,0,255,0,CH3);

    if(CH3 > 25){
      car.rightTurn();
      Serial.print("RightTurn :");
    }
    else{
      car.Speed = abs(car.Speed);
      car.leftTurn();
    Serial.print("LeftTurn :");
    }
  }

  
  else if((CH3 > 25 || CH3 < -25) && CH5){
  
    car.Speed = map(car.Speed,0,255,0,CH3);

    if(CH3 > 25){
      car.rightBackPivot();
      Serial.print("RightPivot : ");
    }
    else{
      car.Speed = abs(car.Speed);
      car.leftBackPivot();
      Serial.print("LeftPivot : ");
    }
  }

  
  else
  {
    car.Stp();
    Serial.print("Stop : ");
  }
  
  Serial.print(" car.Speed = ");
  Serial.println(car.Speed);
  //delay(100);
}
