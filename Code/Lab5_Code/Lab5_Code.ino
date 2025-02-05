#define DC_MotorA_Enable_Pin   10   // Don't change this one
#define DC_MotorA_In1_Pin     40  // You can swape this pin with In2 if the motor rotation direction is not what you want
#define DC_MotorA_In2_Pin     41  // You can swape this pin with In1 if the motor rotation direction is not what you want
#define DC_MotorB_Enable_Pin   9 // Don't change this one
#define DC_MotorB_In1_Pin     42  // You can swape this pin with In2 if the motor rotation direction is not what you want
#define DC_MotorB_In2_Pin     43  // You can swape this pin with In1 if the motor rotation direction is not what you want

#define DC_MotorA_Encoder_PinA  14  // PCINT10  DON'T CHANGE THIS ONE unless you set your pin change interrupt yourself 
#define DC_MotorA_Encoder_PinB  15  // PCINT9   DON'T CHANGE THIS ONE unless you set your pin change interrupt yourself 
#define DC_MotorB_Encoder_PinA  A14  // PCINT22  DON'T CHANGE THIS ONE unless you set your pin change interrupt yourself 
#define DC_MotorB_Encoder_PinB  A15  // PCINT23  DON'T CHANGE THIS ONE unless you set your pin change interrupt yourself 


#define FORWARD_BUTTON  22
#define BACKWARD_BUTTON 23
#define STOP_BUTTON     24
#define RIGHT_BUTTON    26
#define LEFT_BUTTON     25
// #define LEFT_BUTTON
// #define RIGHT_BUTTON


#include "InterruptSetup.h"  // Include the timer setting strucure provided by TAs
#include "DC_Motor.h"  // Include the DC_Motor setting strucure provided by TAs


extern  "C"{  // Include the simulink produced files for "control loop"
  #include "src/ControlLoop_ert_rtw/ControlLoop.h"
  #include "src/ControlLoop_ert_rtw/ControlLoop_private.h"
  #include "src/ControlLoop_ert_rtw/ControlLoop_types.h"
// Use ControlLoop_U.XXXX to access all your input signals (XXXX is your varible names)
// Use ControlLoop_Y.ZZZZ to access all your output signals (ZZZZ is your varible names)
}
extern  "C"{  // Include the simulink produced files for "StateflowBlock"
  #include "src/StateflowBlock_ert_rtw/StateflowBlock.h"
  #include "src/StateflowBlock_ert_rtw/StateflowBlock_private.h"
  #include "src/StateflowBlock_ert_rtw/StateflowBlock_types.h"
// Use StateflowBlock_U.XXXX to access all your input signals (XXXX is your varible names)
// Use StateflowBlock_Y.ZZZZ to access all your output signals (ZZZZ is your varible names)
}

float MotorASpeed = 0;
float MotorBSpeed = 0;
int state;

#define ledPin 13

void setup() 
{
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  StateflowBlock_U.forward_button_in = 0;
  StateflowBlock_U.backward_button_in = 0;
  StateflowBlock_U.stop_button_in = 0;
  StateflowBlock_U.left_button_in = 0;
  StateflowBlock_U.right_button_in = 0;
  pinMode(FORWARD_BUTTON, INPUT_PULLUP);
  pinMode(BACKWARD_BUTTON, INPUT_PULLUP);
  pinMode(STOP_BUTTON, INPUT_PULLUP);
  pinMode(STOP_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  TimerAndInterruptSetup();
  DC_MotorInit();
  Serial.begin(115200);
}

void loop() // Nonreal time loop, keep running but will be interrupted anytime
{  
  // put your main code here, to run repeatedly:
  ////============Print a message if either timer timeout (couldn't finish the code before next interrupt)//
  //  100% means the interrupt function will NOT have enough time to execute
  //PrintIfTimerTimeout();   // You can comment out this one during your test. Just print this from time to time to make sure your code doesn't overload the micro processor
  //================================================================================//
  
  Serial.print("\n");
  Serial.print(!digitalRead(FORWARD_BUTTON));
  Serial.print(!digitalRead(BACKWARD_BUTTON));
  Serial.print(!digitalRead(STOP_BUTTON));
  Serial.print(!digitalRead(LEFT_BUTTON));
  Serial.print(!digitalRead(RIGHT_BUTTON));
  Serial.print(" state is: ");
  Serial.println(state);
}


// Try not to print anything in the below function, 
// use the non real time loop above to print stuff because the Serail.print() takes a long time

void InterruptFunction1() // Higher Priority, Called by Timer 1   // Could be used for hardware control
{                         // This function runs at 200 Hz, used for motor control loop
  
  ControlLoop_U.DC_MotorA_command = MotorASpeed; // Send the desired motor speed to the control loop
  ControlLoop_U.DC_MotorB_command = MotorBSpeed; // Send the desired motor speed to the control loop
  
  ControlLoop_step();  // This runs your "ControlLoop" simulink loop
  
  DriveMotorA(ControlLoop_Y.DC_MotorA);  // output the calculated value from -1 to 1 to the motor 
  DriveMotorB(ControlLoop_Y.DC_MotorB);  // output the calculated value from -1 to 1 to the motor 
  
  return;
}
void InterruptFunction2() // Middle Priority, Called by Timer 3  
{                         // This function runs at 100 Hz, used for sensor feedback and communication
  for(int i=0;i<3;i++)
  {
    delay(1);  // Put some dummy load to show timer loading.
  }
  return;
}
void InterruptFunction3() // Lower Priority, Called by Timer 4  // Could be used for state machine, navigation logic, etc
{                         // This function runs at 10 Hz, used for strategy, navigation...
  digitalWrite(ledPin, !digitalRead(ledPin)); // Blinking LED for fun - useless
  //delay(60);
  //========================Feed the input signals==================================//
  StateflowBlock_U.forward_button_in = !digitalRead(FORWARD_BUTTON);
  StateflowBlock_U.backward_button_in = !digitalRead(BACKWARD_BUTTON);
  StateflowBlock_U.stop_button_in = !digitalRead(STOP_BUTTON);
  StateflowBlock_U.left_button_in = !digitalRead(LEFT_BUTTON);
  StateflowBlock_U.right_button_in = !digitalRead(RIGHT_BUTTON);
 
  //================================================================================//

  //==========================Run the simulink program=============================//
  StateflowBlock_step(); 
  //================================================================================//

  //===========================Take out the output signals==========================//
  // put the output desired motor speed to global variables that can be accessed from other funtion
  MotorASpeed = StateflowBlock_Y.controlA; 
  MotorBSpeed = StateflowBlock_Y.controlB;
  state    = StateflowBlock_Y.state;
  //================================================================================//
  return;
}
