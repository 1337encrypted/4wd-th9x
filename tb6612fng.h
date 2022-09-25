#ifndef TB6612FNG
#define TB6612FNG

class tb6612fng
{
    private:
    #define in1 A5                      //Motor1 tb66fng12 H bridge
    #define in2 A4                      //Motor1 tb66fng12 H bridge
    #define in3 A3                      //Motor2 tb66fng12 H bridge
    #define in4 A2                      //Motor2 tb66fng12 H bridge
    #define in5 2                       //Motor3 tb66fng12 H bridge
    #define in6 4                       //Motor3 tb66fng12 H bridge
    #define in7 7                      //Motor4 tb66fng12 H bridge
    #define in8 8                       //Motor4 tb66fng12 H bridge
    
    #define Speedpin1 3                 //pulse with moudulation enable1 tb66fng12 H bridge
    #define Speedpin2 5                 //pulse with moudulation enable2 tb66fng12 H bridge
    #define Speedpin3 6                 //pulse with moudulation enable3 tb66fng12 H bridge
    #define Speedpin4 9                 //pulse with moudulation enable4 tb66fng12 H bridge

    //LED's and buzzer pins
    #define buzzpin A0                  //Buzzer pin
    #define redLed 10                   //Red led
    #define blueLed 11                  //Blue led
    
    #define standby0 A0                 //making this low will put the motor in low power state
    #define standby1 A1                 //making this low will put the motor in low power state

    public:

    volatile int Speed;
    
    inline tb6612fng() __attribute__((always_inline));
    inline void __initSystem() __attribute__((always_inline));    //internal functions starts with __initSystem()
    inline void buzz() __attribute__((always_inline));
    inline void Stp() __attribute__((always_inline));
    inline void front() __attribute__((always_inline));
    inline void back() __attribute__((always_inline));
    inline void leftTurn() __attribute__((always_inline));
    inline void rightTurn() __attribute__((always_inline));
    inline void leftShift() __attribute__((always_inline));
    inline void rightShift() __attribute__((always_inline));
    inline void sharpRightTurnFront() __attribute__((always_inline));
    inline void sharpRightTurnBack() __attribute__((always_inline));
    inline void sharpLeftTurnFront() __attribute__((always_inline));
    inline void sharpLeftTurnBack() __attribute__((always_inline));
    inline void rightDiagonalFront() __attribute__((always_inline));
    inline void rightDiagonalBack() __attribute__((always_inline));
    inline void leftDiagonalFront() __attribute__((always_inline));
    inline void leftDiagonalBack() __attribute__((always_inline));
    inline void rightBackPivot() __attribute__((always_inline));
    inline void leftBackPivot() __attribute__((always_inline));
};

tb6612fng::tb6612fng()
{
  //Motor functions
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(in5,OUTPUT);
  pinMode(in6,OUTPUT);
  pinMode(in7,OUTPUT);
  pinMode(in8,OUTPUT);

  //PWM pins set as output
  pinMode(Speedpin1,OUTPUT);
  pinMode(Speedpin2,OUTPUT);
  pinMode(Speedpin3,OUTPUT);
  pinMode(Speedpin4,OUTPUT);

  //Standby pins if set to low will shutdown the tb6612fng motor driver
  pinMode(standby0,OUTPUT);
  pinMode(standby1,OUTPUT);

  //LED's and Buzzer
  pinMode(buzzpin,OUTPUT);
  pinMode(redLed,OUTPUT);
  pinMode(blueLed,OUTPUT);    

  this->Speed=0;
}

void tb6612fng::buzz()
{
  if(Speed < 25)
  {
    digitalWrite(buzzpin, HIGH); 
  }  
  if(Speed >= 25)
  {
      digitalWrite(buzzpin, LOW); 
  }
}

void tb6612fng::__initSystem()
{
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  digitalWrite(buzzpin, HIGH);
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, HIGH);
  delay(2);
  digitalWrite(buzzpin, LOW);
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, LOW);
}

void tb6612fng::Stp(){
  //LED's
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, LOW);
  //OFF the motor driver
  digitalWrite(standby0, LOW);
  digitalWrite(standby1, LOW);
//  //Motors
//  digitalWrite(in1,LOW);
//  digitalWrite(in2,LOW);
//  digitalWrite(in3,LOW);
//  digitalWrite(in4,LOW);
//  digitalWrite(in5,LOW);
//  digitalWrite(in6,LOW);
//  digitalWrite(in7,LOW);
//  digitalWrite(in8,LOW); 
//  analogWrite(Speedpin1,Speed);
//  analogWrite(Speedpin2,Speed);
//  analogWrite(Speedpin3,Speed);
//  analogWrite(Speedpin4,Speed);
}

void tb6612fng::front(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

void tb6612fng::back(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH);
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

void tb6612fng::leftTurn(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

void tb6612fng::rightTurn(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH);
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

void tb6612fng::leftShift(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

void tb6612fng::rightShift(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH); 
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

 void tb6612fng::sharpRightTurnFront()
{
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW); 
  analogWrite(Speedpin1,0);
  analogWrite(Speedpin2,0);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

void tb6612fng::sharpLeftTurnFront()
{
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,LOW); 
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,0);
  analogWrite(Speedpin4,0);
}

void tb6612fng::sharpRightTurnBack()
{
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH); 
  analogWrite(Speedpin1,0);
  analogWrite(Speedpin2,0);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

void tb6612fng::sharpLeftTurnBack()
{
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,LOW); 
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,0);
  analogWrite(Speedpin4,0);
}

void tb6612fng::rightDiagonalFront(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);  
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

void tb6612fng::leftDiagonalFront(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,LOW); 
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

void tb6612fng::rightDiagonalBack(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH); 
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

void tb6612fng::leftDiagonalBack(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,LOW);
  digitalWrite(in8,LOW);
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}


void tb6612fng::rightBackPivot(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW); 
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

void tb6612fng::leftBackPivot(){
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
  //Motor driver ON
  digitalWrite(standby0, HIGH);
  digitalWrite(standby1, HIGH);
  //Motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH); 
  analogWrite(Speedpin1,Speed);
  analogWrite(Speedpin2,Speed);
  analogWrite(Speedpin3,Speed);
  analogWrite(Speedpin4,Speed);
}

#endif  //END TB6612FNG
