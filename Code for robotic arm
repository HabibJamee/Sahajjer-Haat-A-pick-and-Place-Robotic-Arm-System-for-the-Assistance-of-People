#include <PS2X_lib.h> 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN0  
#define SERVOMAX0  
#define SERVOMIN1  
#define SERVOMAX1  
#define SERVOMIN2  
#define SERVOMAX2  
#define SERVOMIN3  
#define SERVOMAX3  
#define SERVOMIN4  
#define SERVOMAX4  
#define SERVOMIN5  
#define SERVOMAX5  
#define SERVO     0x40
uint8_t servonum0 = 0, servonum1 = 1, servonum2 = 2, servonum3 = 3, servonum4 = 4, servonum5 = 5;
uint8_t RY_Value=127, RX_Value=127, LY_Value=127, LX_Value=127;
int pulselen0= , pulselen1=  , pulselen2=   , pulselen3=   , pulselen4=   , pulselen5=  ;
uint8_t Flag_SERVO0=0, Flag_SERVO1=0, Flag_SERVO2=0, Flag_SERVO3=0,  Flag_SERVO4=0, Flag_SERVO5=0; 
uint8_t delay_time=15;
#define PS2_DAT        13  
#define PS2_CMD        11  
#define PS2_SEL        10  
#define PS2_CLK        12  

#define pressures   false
#define rumble      false

PS2X ps2x; 
int error = 0;
byte type = 0;
byte vibrate = 0;

void Flag_SERVO_Init()
{
  Flag_SERVO0=0;Flag_SERVO1=0;Flag_SERVO2=0;Flag_SERVO3=0;Flag_SERVO4=0;Flag_SERVO5=0;
  }
void setup(){
 Serial.begin(115200);
  pwm.begin(SERVO);
  pwm.setPWMFreq(60,SERVO);  
  delay(300);  
  Flag_SERVO_Init();
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  
 if(error == 0){
    Serial.print("Found Controller, successfully configured");
    Serial.print("pressures = ");
  if (pressures)
    Serial.println("true ");
  else
    Serial.println("false");
  Serial.print("rumble = ");
  if (rumble)
Serial.println("true)");
  else
    Serial.println("false");
    Serial.println("Try all the buttons, X will vibrate the controller more quickly as you push harder.;");
    Serial.println("The analog stick values will be printed by keeping L1 or R1.");
  }  
  else if(error == 1)
    Serial.println("No controller discovered, check cable, see readme.txt to allow debugging ");
   
  else if(error == 2)
    Serial.println("Controller found but did not accept commands. ");

  else if(error == 3)
    Serial.println("Controller who refuses to join mode Pressures may not support it. ");
  
  
  type = ps2x.readType(); 
  switch(type) {
    case 0:
      Serial.print("Unknown sort of controller discovered ");
      break;
    case 1:
      Serial.print("Controller DualShock discovered ");
      break;
    case 2:
      Serial.print("Controller GuitarHero discovered ");
      break;
  case 3:
      Serial.print("Sony DualShock wireless controller discovered ");
      break;
   }
}

void loop() {
  if(error == 1) 
    return; 
  
  if(type == 2){ 
    ps2x.read_gamepad();          
   
    if(ps2x.ButtonPressed(GREEN_FRET))
      Serial.println("Green Fret pushed");
    if(ps2x.ButtonPressed(RED_FRET))
      Serial.println("Red Fret pushed ");
    if(ps2x.ButtonPressed(YELLOW_FRET))
      Serial.println("Yellow Fret pushed ");
    if(ps2x.ButtonPressed(BLUE_FRET))
      Serial.println("Blue Fret pushed ");
    if(ps2x.ButtonPressed(ORANGE_FRET))
      Serial.println("Orange Fret pushed "); 

    if(ps2x.ButtonPressed(STAR_POWER))
      Serial.println("Command of Star Power ");
    
    if(ps2x.Button(UP_STRUM))          
      Serial.println("Strum up");
    if(ps2x.Button(DOWN_STRUM))
      Serial.println("Strum down");
 
    if(ps2x.Button(PSB_START))         
      Serial.println("The start will take place ");
    if(ps2x.Button(PSB_SELECT))
      Serial.println("The start will take place ");
    
    if(ps2x.Button(ORANGE_FRET)) {    
      Serial.print("Position of the Wammy Bar:");
      Serial.println(ps2x.Analog(WHAMMY_BAR), DEC); 
    } 
  }
  else { 
    ps2x.read_gamepad(false, vibrate); 
    
    if(ps2x.Button(PSB_START))         
      Serial.println("The start will take place ");
    if(ps2x.Button(PSB_SELECT))
      Serial.println("Select is being held");      

    if(ps2x.Button(PSB_PAD_UP)) {      
      Serial.print("Select is being held: ");
      Flag_SERVO4=2;
      pulselen4++;
    }
    if(ps2x.Button(PSB_PAD_RIGHT)){
      Serial.print("That was difficult on the right: ");
     
      Flag_SERVO5=2;
      pulselen5++;
    }
    if(ps2x.Button(PSB_PAD_LEFT)){
      Serial.print("LEFT kept this tough: ");
      Flag_SERVO5=1;
      pulselen5--;
    }
    if(ps2x.Button(PSB_PAD_DOWN)){
      Serial.print("DOWN kept this tough: ");
      
      Flag_SERVO4=1;
      pulselen4--;
    }   

      if(ps2x.Button(PSB_L3))
        Serial.println("pushed L3");
      if(ps2x.Button(PSB_R3))
        Serial.println("pushed R3");
      if(ps2x.Button(PSB_L2))
       {
        Serial.println("pushed L2");
        Flag_SERVO0=1;
        pulselen0--;
       }
      if(ps2x.Button(PSB_R2))
      {
        Serial.println("pushed R2");
        Flag_SERVO0=2;
        pulselen0++;
      }
      if(ps2x.Button(PSB_TRIANGLE))
      {
        Serial.println("Pressed triangle "); 
        Flag_SERVO3=1;
        pulselen3--;
      }       
    if(ps2x.Button(PSB_CIRCLE))               
    {
      Serial.println("Just pushed the circle ");
      Flag_SERVO2=2;
      pulselen2++;
    }
    if(ps2x.Button(PSB_CROSS))              
    {
      Serial.println("X has just been altered ");
      Flag_SERVO3=2;
      pulselen3++;
    }
    if(ps2x.Button(PSB_SQUARE))              
    {
      Serial.println("Just released Square ");
      Flag_SERVO2=1;
      pulselen2--;
    }    
    if(ps2x.Button(PSB_L1))
    {
      Serial.println("pushed L1");
      Flag_SERVO1=1;
      pulselen1--;
      }
    if(ps2x.Button(PSB_R1))
    {
      Serial.println("pushed R2");
      Flag_SERVO1=2;
      pulselen1++;
      }

      RY_Value=ps2x.Analog(PSS_RY);
      LY_Value=ps2x.Analog(PSS_LY);
      
      if(LY_Value<=RY_Value)
      delay_time=map(LY_Value,0,127,0,15);
      if(LY_Value>=RY_Value)
      delay_time=map(RY_Value,0,127,0,15);
      if(pulselen0>SERVOMAX0) 
      {pulselen0=SERVOMAX0;}
      if(pulselen0<SERVOMIN0) 
      {pulselen0=SERVOMIN0;}
      
      if(pulselen1>SERVOMAX1) 
      {pulselen1=SERVOMAX1;}
      if(pulselen1<SERVOMIN1) 
      {pulselen1=SERVOMIN1;}
    
     if(pulselen2>SERVOMAX2) 
      {pulselen2=SERVOMAX2;}
      if(pulselen2<SERVOMIN2) 
      {pulselen2=SERVOMIN2;}
      
      if(pulselen3>SERVOMAX3) 
      {pulselen3=SERVOMAX3;}
      if(pulselen3<SERVOMIN3) 
      {pulselen3=SERVOMIN3;}
  
      pwm.setPWM(servonum0, 0, pulselen0,SERVO);
      pwm.setPWM(servonum1, 0, pulselen1,SERVO);
      pwm.setPWM(servonum2, 0, pulselen2,SERVO);
      pwm.setPWM(servonum3, 0, pulselen3,SERVO);
      pwm.setPWM(servonum4, 0, pulselen4,SERVO);
      pwm.setPWM(servonum5, 0, pulselen5,SERVO);
  }
   delay(delay_time);
}
