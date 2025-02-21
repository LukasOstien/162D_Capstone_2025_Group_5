/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: StateflowBlock.c
 *
 * Code generated for Simulink model 'StateflowBlock'.
 *
 * Model version                  : 4.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Feb 18 18:17:41 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "StateflowBlock.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Steering Stateflow' */
#define StateflowBlo_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define StateflowBlock_IN_Acceleration ((uint8_T)1U)
#define StateflowBlock_IN_Ada          ((uint8_T)2U)
#define StateflowBlock_IN_Deceleration ((uint8_T)3U)
#define StateflowBlock_IN_OFF          ((uint8_T)1U)
#define StateflowBlock_IN_ON           ((uint8_T)2U)
#define StateflowBlock_IN_Pause        ((uint8_T)4U)
#define StateflowBlock_IN_Running      ((uint8_T)5U)

/* Block states (default storage) */
DW_StateflowBlock_T StateflowBlock_DW;

/* External inputs (root inport signals with default storage) */
ExtU_StateflowBlock_T StateflowBlock_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_StateflowBlock_T StateflowBlock_Y;

/* Real-time model */
static RT_MODEL_StateflowBlock_T StateflowBlock_M_;
RT_MODEL_StateflowBlock_T *const StateflowBlock_M = &StateflowBlock_M_;

/* Model step function */
void StateflowBlock_step(void)
{
  /* Chart: '<Root>/Steering Stateflow' incorporates:
   *  Constant: '<Root>/Wheel radius (in)'
   *  Inport: '<Root>/UltrasoundDistanceA'
   *  Inport: '<Root>/accel_button_in'
   *  Inport: '<Root>/decel_button_in'
   *  Inport: '<Root>/off_button_in'
   *  Inport: '<Root>/on_button_in'
   *  Inport: '<Root>/pause_button_in'
   */
  if (StateflowBlock_DW.is_active_c3_StateflowBlock == 0U) {
    StateflowBlock_DW.is_active_c3_StateflowBlock = 1U;
    StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_OFF;
    StateflowBlock_DW.speed = 0.0;

    /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
    StateflowBlock_Y.DC_MotorA_SpeedCommand = -0.0;

    /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
    StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

    /* Outport: '<Root>/state' */
    StateflowBlock_Y.state = 0.0;

    /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
    StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
  } else if (StateflowBlock_DW.is_c3_StateflowBlock == StateflowBlock_IN_OFF) {
    if (StateflowBlock_U.on_button_in > 0.0) {
      StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_ON;
      StateflowBlock_DW.is_ON = StateflowBlock_IN_Running;

      /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
      StateflowBlock_Y.DC_MotorA_SpeedCommand = StateflowBlock_DW.speed;

      /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
      StateflowBlock_Y.DC_MotorB_SpeedCommand = -StateflowBlock_DW.speed;

      /* Outport: '<Root>/state' */
      StateflowBlock_Y.state = 1.0;

      /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
      StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
    } else {
      StateflowBlock_DW.speed = 0.0;

      /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
      StateflowBlock_Y.DC_MotorA_SpeedCommand = -0.0;

      /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
      StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

      /* Outport: '<Root>/state' */
      StateflowBlock_Y.state = 0.0;

      /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
      StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
    }

    /* case IN_ON: */
  } else if (StateflowBlock_U.off_button_in) {
    StateflowBlock_DW.is_ON = StateflowBlo_IN_NO_ACTIVE_CHILD;
    StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_OFF;
    StateflowBlock_DW.speed = 0.0;

    /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
    StateflowBlock_Y.DC_MotorA_SpeedCommand = -0.0;

    /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
    StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

    /* Outport: '<Root>/state' */
    StateflowBlock_Y.state = 0.0;

    /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
    StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
  } else {
    switch (StateflowBlock_DW.is_ON) {
     case StateflowBlock_IN_Acceleration:
      if (StateflowBlock_U.pause_button_in) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Pause;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = 0.0;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 4.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
      } else if (!StateflowBlock_U.accel_button_in) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Running;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = StateflowBlock_DW.speed;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = -StateflowBlock_DW.speed;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 1.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
      } else {
        StateflowBlock_DW.speed += 3.0 / StateflowBlock_P.Wheelradiusin_Value;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' incorporates:
         *  Constant: '<Root>/Wheel radius (in)'
         */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = StateflowBlock_DW.speed;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = -StateflowBlock_DW.speed;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 2.0;
      }
      break;

     case StateflowBlock_IN_Ada:
      if (StateflowBlock_U.pause_button_in ||
          (StateflowBlock_U.UltrasoundDistanceA > 250.0)) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Pause;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = 0.0;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 4.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
      } else {
        /* Outport: '<Root>/DistanceA_command' */
        StateflowBlock_Y.DistanceA_command = 100.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 5.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 1.0;
      }
      break;

     case StateflowBlock_IN_Deceleration:
      if (StateflowBlock_U.decel_button_in == 0.0) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Running;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = StateflowBlock_DW.speed;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = -StateflowBlock_DW.speed;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 1.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
      } else if (StateflowBlock_U.pause_button_in) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Pause;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = 0.0;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 4.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
      } else {
        StateflowBlock_DW.speed -= 3.0 / StateflowBlock_P.Wheelradiusin_Value;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' incorporates:
         *  Constant: '<Root>/Wheel radius (in)'
         */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = StateflowBlock_DW.speed;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = -StateflowBlock_DW.speed;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 3.0;
      }
      break;

     case StateflowBlock_IN_Pause:
      if (StateflowBlock_U.on_button_in > 0.0) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Acceleration;
        StateflowBlock_DW.speed += 3.0 / StateflowBlock_P.Wheelradiusin_Value;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' incorporates:
         *  Constant: '<Root>/Wheel radius (in)'
         */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = StateflowBlock_DW.speed;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = -StateflowBlock_DW.speed;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 2.0;
      } else if (StateflowBlock_U.on_button_in > 0.0) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Running;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = StateflowBlock_DW.speed;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = -StateflowBlock_DW.speed;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 1.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
      } else if (StateflowBlock_U.on_button_in > 0.0) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Deceleration;
        StateflowBlock_DW.speed -= 3.0 / StateflowBlock_P.Wheelradiusin_Value;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' incorporates:
         *  Constant: '<Root>/Wheel radius (in)'
         */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = StateflowBlock_DW.speed;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = -StateflowBlock_DW.speed;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 3.0;
      } else {
        /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = 0.0;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 4.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
      }
      break;

     default:
      /* case IN_Running: */
      if (StateflowBlock_U.decel_button_in > 0.0) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Deceleration;
        StateflowBlock_DW.speed -= 3.0 / StateflowBlock_P.Wheelradiusin_Value;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' incorporates:
         *  Constant: '<Root>/Wheel radius (in)'
         */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = StateflowBlock_DW.speed;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = -StateflowBlock_DW.speed;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 3.0;
      } else if (StateflowBlock_U.accel_button_in) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Acceleration;
        StateflowBlock_DW.speed += 3.0 / StateflowBlock_P.Wheelradiusin_Value;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' incorporates:
         *  Constant: '<Root>/Wheel radius (in)'
         */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = StateflowBlock_DW.speed;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = -StateflowBlock_DW.speed;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 2.0;
      } else if (StateflowBlock_U.pause_button_in) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Pause;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = 0.0;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 4.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
      } else if (StateflowBlock_U.UltrasoundDistanceA < 200.0) {
        StateflowBlock_DW.is_ON = StateflowBlock_IN_Ada;

        /* Outport: '<Root>/DistanceA_command' */
        StateflowBlock_Y.DistanceA_command = 100.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 5.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 1.0;
      } else {
        /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = StateflowBlock_DW.speed;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = -StateflowBlock_DW.speed;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 1.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Steering Stateflow' */
}

/* Model initialize function */
void StateflowBlock_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void StateflowBlock_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
