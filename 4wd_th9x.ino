//I think initially all pins are high so we need to manually have to low them
#include <IBusBM.h>
//#include <Servo.h>
IBusBM ibus;                        // Create iBus Object

#define in1 2                       //Motor1 tb66fng12 H bridge
#define in2 4                       //Motor1 tb66fng12 H bridge
#define in3 6                       //Motor2 tb66fng12 H bridge
#define in4 7                       //Motor2 tb66fng12 H bridge
#define in5 13                      //Motor3 tb66fng12 H bridge
#define in6 12                      //Motor3 tb66fng12 H bridge
#define in7 11                      //Motor4 tb66fng12 H bridge
#define in8 8                       //Motor4 tb66fng12 H bridge

#define spdpin1 3                   //pulse with moudulation enable1 tb66fng12 H bridge
#define spdpin2 5                   //pulse with moudulation enable2 tb66fng12 H bridge
#define spdpin3 10                  //pulse with moudulation enable3 tb66fng12 H bridge
#define spdpin4 9                   //pulse with moudulation enable4 tb66fng12 H bridge

//#define buzzpin 12                //buzzer pin
#define ledpin A5                   //ledpin

#define standby0 A0                 //making this low will put the motor in low power state
#define standby1 A1                 //making this low will put the motor in low power state

#define t 1000                      //Initial time set to 1 second

//bool stdby = false;                //Initalized the standby to false

int CH0 = 0;                        // LeftShift - RightShift
int spd = 0;                        // Speed (Acceleration)
int CH2 = 0;                        // Forward - Reverse
int CH3 = 0;                        // Left - Right 
//boolean CH4 = false;              // Extra
bool CH5 = false;                   //turn switch
//int CH6 = -100;                   //extra pot
//int CH7 = -100;                   //extra pot

int spd1 = 0;                       // To help in calculating stick > 180

void setup(){
  
  Serial.begin(115200);             // Start serial monitor for debugging

  ibus.begin(Serial);               // Attach iBus object to serial port

  pinMode(standby0,OUTPUT);
  pinMode(standby1,OUTPUT);
  
  pinMode(spdpin1,OUTPUT);
  pinMode(spdpin2,OUTPUT);
  pinMode(spdpin3,OUTPUT);
  pinMode(spdpin4,OUTPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(in5,OUTPUT);
  pinMode(in6,OUTPUT);
  pinMode(in7,OUTPUT);
  pinMode(in8,OUTPUT);
  /*
   * pinMode(buzzpin,OUTPUT);
   * buzz();
   */
  pinMode(ledpin,OUTPUT);

  digitalWrite(ledpin,HIGH);

  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  
  Stp();
}

/*void buzz(){
  digitalWrite(buzzpin, HIGH);
  delay(t);
  digitalWrite(buzzpin, LOW);
}
*/
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

void Stp(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,LOW); 
}

void front(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
}

void back(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH);
}

void leftTurn(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
}

void rightTurn(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH);
}

void leftShift(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
}

void rightShift(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH); 
}

void rightDiagonalFront(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);  
}

void leftDiagonalFront(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,LOW);  
}

void rightDiagonalBack(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH);  
}

void leftDiagonalBack(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,LOW);
  digitalWrite(in8,LOW);  
}


void rightBackPivot(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW); 
}

void leftBackPivot(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH); 
}

void loop(){

  // Get RC channel values
  CH0 = readChannel(0, -255, 255, 0);       // Leftshift - Rightshift
  spd = readChannel(1, 0, 255, 0);          // Speed (Acceleration)
  CH2 = readChannel(2, -255, 255, 0);       // Forward - Reverse
  CH3 = readChannel(3, -255, 255, 0);       // Left - Right 
  //CH4 = readSwitch(4, false);
  CH5 = readSwitch(5, false);


  if((CH2 > 40 || CH2 < -40) && (CH0 < 40 && CH0 > -40)){
    
    spd = map(spd,0,255,0,CH2);
    
    if(CH2 > 25){
      front();
      Serial.print("Foreward :");  
    }
    else{
      spd = abs(spd);
      back();
      Serial.print("Back :");
    }
  }

  
  else if((CH2 > 40 || CH2 < -40) && (CH0 > 40 || CH0 < -40)){                 // Checks for CH2 > 40 and CH0 > 40
   
    spd = map(spd,0,255,0,CH2);                        // Speed control mapped to the CH2 pot
    spd1 = map(spd1,0,255,0,CH0);                      // Speed control mapped to the CH0 pot

    if(CH2 > 40 && CH0 > 40){
      spd = spd+spd1;
      leftDiagonalFront();
      Serial.print("LeftDiagonalFront :");
    }
    else if(CH2 > 40 && CH0 < -40){
      spd = spd+abs(spd1);
      rightDiagonalFront();
      Serial.print("RightDiagonalFront :");
    }
    if(CH2 < -40 && CH0 > 40){
      spd = abs(spd)+spd1;
      leftDiagonalBack();
      Serial.print("RightDiagonalBack :");
    }
    else if(CH2 < -40 && CH0 < -40){
      spd = abs(spd)+abs(spd1);
      rightDiagonalBack();
      Serial.print("LeftDiagonalBack :");
    }
  }
  
  
  else if(CH0 > 40 || CH0 < -40){
    
    spd = map(spd,0,255,0,CH0);

    if(CH0 > 40){
      rightShift();
      Serial.print("RightShift :");
    }
    else{
      spd = abs(spd);
      leftShift();
      Serial.print("LeftShift :"); 
    }
  }

  
  else if((CH3 > 25 || CH3 < -25) && CH5 == 0){
    
    spd = map(spd,0,255,0,CH3);

    if(CH3 > 25){
      rightTurn();
      Serial.print("RightTurn :");
    }
    else{
      spd = abs(spd);
      leftTurn();
    Serial.print("LeftTurn :");
    }
  }

  
  else if((CH3 > 25 || CH3 < -25) && CH5){
  
    spd = map(spd,0,255,0,CH3);

    if(CH3 > 25){
      rightBackPivot();
      Serial.print("RightPivot : ");
    }
    else{
      spd = abs(spd);
      leftBackPivot();
      Serial.print("LeftPivot : ");
    }
  }

  
  else
  {
    Stp();
    Serial.print("Stop : ");
  }
  
  Serial.print(" Speed = ");
  Serial.println(spd);

  analogWrite(spdpin1,spd);
  analogWrite(spdpin2,spd);
  analogWrite(spdpin3,spd);
  analogWrite(spdpin4,spd);
  analogWrite(ledpin,spd);
  
  //delay(100);
}
