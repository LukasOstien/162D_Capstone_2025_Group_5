/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop.c
 *
 * Code generated for Simulink model 'ControlLoop'.
 *
 * Model version                  : 3.14
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb  3 20:57:24 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ControlLoop.h"

/* External inputs (root inport signals with default storage) */
ExtU_ControlLoop_T ControlLoop_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ControlLoop_T ControlLoop_Y;

/* Real-time model */
static RT_MODEL_ControlLoop_T ControlLoop_M_;
RT_MODEL_ControlLoop_T *const ControlLoop_M = &ControlLoop_M_;

/* Model step function */
void ControlLoop_step(void)
{
  /* Outport: '<Root>/DC_MotorA' incorporates:
   *  Inport: '<Root>/DC_MotorA_command'
   */
  ControlLoop_Y.DC_MotorA = ControlLoop_U.DC_MotorA_command;

  /* Outport: '<Root>/DC_MotorB' incorporates:
   *  Inport: '<Root>/DC_MotorB_command'
   */
  ControlLoop_Y.DC_MotorB = ControlLoop_U.DC_MotorB_command;
}

/* Model initialize function */
void ControlLoop_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void ControlLoop_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
