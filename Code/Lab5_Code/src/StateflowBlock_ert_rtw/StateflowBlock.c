/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: StateflowBlock.c
 *
 * Code generated for Simulink model 'StateflowBlock'.
 *
 * Model version                  : 4.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Feb  5 20:13:58 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "StateflowBlock.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Steering Stateflow' */
#define StateflowBlock_IN_Backward     ((uint8_T)1U)
#define StateflowBlock_IN_Forward      ((uint8_T)2U)
#define StateflowBlock_IN_Idle         ((uint8_T)3U)
#define StateflowBlock_IN_Turn_Left    ((uint8_T)4U)
#define StateflowBlock_IN_Turn_Right   ((uint8_T)5U)

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
   *  Inport: '<Root>/backward_button_in'
   *  Inport: '<Root>/forward_button_in'
   *  Inport: '<Root>/left_button_in'
   *  Inport: '<Root>/right_button_in'
   *  Inport: '<Root>/stop_button_in'
   */
  if (StateflowBlock_DW.is_active_c3_StateflowBlock == 0U) {
    StateflowBlock_DW.is_active_c3_StateflowBlock = 1U;
    StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Idle;

    /* Outport: '<Root>/controlA' */
    StateflowBlock_Y.controlA = 0.0;

    /* Outport: '<Root>/controlB' */
    StateflowBlock_Y.controlB = 0.0;

    /* Outport: '<Root>/state' */
    StateflowBlock_Y.state = 0.0;
  } else {
    switch (StateflowBlock_DW.is_c3_StateflowBlock) {
     case StateflowBlock_IN_Backward:
      if (StateflowBlock_U.forward_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Forward;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = -0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 1.0;
      } else if (StateflowBlock_U.stop_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Idle;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.0;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 0.0;
      } else if (StateflowBlock_U.right_button_in > 0.0) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Turn_Right;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 4.0;
      } else if (StateflowBlock_U.left_button_in > 0.0) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Turn_Left;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = -0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = -0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 3.0;
      } else {
        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = -0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 2.0;
      }
      break;

     case StateflowBlock_IN_Forward:
      if (StateflowBlock_U.stop_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Idle;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.0;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 0.0;
      } else if (StateflowBlock_U.backward_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Backward;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = -0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 2.0;
      } else if (StateflowBlock_U.left_button_in > 0.0) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Turn_Left;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = -0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = -0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 3.0;
      } else if (StateflowBlock_U.right_button_in > 0.0) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Turn_Right;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 4.0;
      } else {
        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = -0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 1.0;
      }
      break;

     case StateflowBlock_IN_Idle:
      if (StateflowBlock_U.forward_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Forward;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = -0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 1.0;
      } else if (StateflowBlock_U.backward_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Backward;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = -0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 2.0;
      } else if (StateflowBlock_U.right_button_in > 0.0) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Turn_Right;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 4.0;
      } else if (StateflowBlock_U.left_button_in > 0.0) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Turn_Left;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = -0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = -0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 3.0;
      } else {
        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.0;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 0.0;
      }
      break;

     case StateflowBlock_IN_Turn_Left:
      if (StateflowBlock_U.stop_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Idle;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.0;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 0.0;
      } else if (StateflowBlock_U.forward_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Forward;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = -0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 1.0;
      } else if (StateflowBlock_U.backward_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Backward;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = -0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 2.0;
      } else if (StateflowBlock_U.right_button_in > 0.0) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Turn_Right;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 4.0;
      } else {
        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = -0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = -0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 3.0;
      }
      break;

     default:
      /* case IN_Turn_Right: */
      if (StateflowBlock_U.stop_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Idle;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.0;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 0.0;
      } else if (StateflowBlock_U.backward_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Backward;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = -0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 2.0;
      } else if (StateflowBlock_U.forward_button_in) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Forward;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = -0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 1.0;
      } else if (StateflowBlock_U.left_button_in > 0.0) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_Turn_Left;

        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = -0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = -0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 3.0;
      } else {
        /* Outport: '<Root>/controlA' */
        StateflowBlock_Y.controlA = 0.5;

        /* Outport: '<Root>/controlB' */
        StateflowBlock_Y.controlB = 0.5;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 4.0;
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
