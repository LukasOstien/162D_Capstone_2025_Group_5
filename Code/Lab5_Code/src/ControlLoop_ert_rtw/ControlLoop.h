/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop.h
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

#ifndef RTW_HEADER_ControlLoop_h_
#define RTW_HEADER_ControlLoop_h_
#ifndef ControlLoop_COMMON_INCLUDES_
#define ControlLoop_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ControlLoop_COMMON_INCLUDES_ */

#include "ControlLoop_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T DC_MotorA_Encoder_Counter;    /* '<Root>/DC_MotorA_Encoder_Counter' */
  real_T DC_MotorB_Encoder_Counter;    /* '<Root>/DC_MotorB_Encoder_Counter' */
  real_T DC_MotorA_command;            /* '<Root>/DC_MotorA_command' */
  real_T DC_MotorB_command;            /* '<Root>/DC_MotorB_command' */
  real_T DC_MotorA_kp;                 /* '<Root>/DC_MotorA_kp' */
  real_T DC_MotorB_kp;                 /* '<Root>/DC_MotorB_kp' */
  real_T DC_MotorA_ki;                 /* '<Root>/DC_MotorA_ki' */
  real_T DC_MotorB_ki;                 /* '<Root>/DC_MotorB_ki' */
  real_T DC_MotorA_kd;                 /* '<Root>/DC_MotorA_kd' */
  real_T DC_MotorB_kd;                 /* '<Root>/DC_MotorB_kd' */
} ExtU_ControlLoop_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T DC_MotorA;                    /* '<Root>/DC_MotorA' */
  real_T DC_MotorB;                    /* '<Root>/DC_MotorB' */
  real_T ServoMotorA;                  /* '<Root>/ServoMotorA' */
  real_T ServoMotorB;                  /* '<Root>/ServoMotorB' */
  real_T ServoMotorC;                  /* '<Root>/ServoMotorC' */
} ExtY_ControlLoop_T;

/* Real-time Model Data Structure */
struct tag_RTM_ControlLoop_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_ControlLoop_T ControlLoop_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ControlLoop_T ControlLoop_Y;

/* Model entry point functions */
extern void ControlLoop_initialize(void);
extern void ControlLoop_step(void);
extern void ControlLoop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ControlLoop_T *const ControlLoop_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ControlLoop'
 */
#endif                                 /* RTW_HEADER_ControlLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
