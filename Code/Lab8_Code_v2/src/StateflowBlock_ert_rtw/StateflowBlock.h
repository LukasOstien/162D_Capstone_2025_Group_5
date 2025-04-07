/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: StateflowBlock.h
 *
 * Code generated for Simulink model 'StateflowBlock'.
 *
 * Model version                  : 3.5
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Feb 25 14:09:04 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_StateflowBlock_h_
#define RTW_HEADER_StateflowBlock_h_
#ifndef StateflowBlock_COMMON_INCLUDES_
#define StateflowBlock_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* StateflowBlock_COMMON_INCLUDES_ */

#include "StateflowBlock_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T speed;                        /* '<Root>/Steering Stateflow' */
  uint8_T is_active_c3_StateflowBlock; /* '<Root>/Steering Stateflow' */
  uint8_T is_c3_StateflowBlock;        /* '<Root>/Steering Stateflow' */
  uint8_T is_ON;                       /* '<Root>/Steering Stateflow' */
} DW_StateflowBlock_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T accel_button_in;           /* '<Root>/accel_button_in' */
  boolean_T off_button_in;             /* '<Root>/off_button_in' */
  boolean_T pause_button_in;           /* '<Root>/pause_button_in' */
  real_T on_button_in;                 /* '<Root>/on_button_in' */
  real_T decel_button_in;              /* '<Root>/decel_button_in' */
  real_T UltrasoundDistanceA;          /* '<Root>/UltrasoundDistanceA' */
  real_T DC_MotorA_SpeedFeedback;      /* '<Root>/DC_MotorA_SpeedFeedback' */
  real_T DC_MotorB_SpeedFeedback;      /* '<Root>/DC_MotorB_SpeedFeedback' */
} ExtU_StateflowBlock_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T DC_MotorA_SpeedCommand;       /* '<Root>/DC_MotorA_SpeedCommand' */
  real_T DC_MotorB_SpeedCommand;       /* '<Root>/DC_MotorB_SpeedCommand' */
  real_T state;                        /* '<Root>/state' */
  real_T DistanceA_command;            /* '<Root>/DistanceA_command' */
  real_T KeepDistanceA_Enable_Bool;    /* '<Root>/KeepDistanceA_Enable_Bool' */
  real_T ServoA_Sweeping_Enable_Bool; /* '<Root>/ServoA_Sweeping_Enable_Bool' */
} ExtY_StateflowBlock_T;

/* Parameters (default storage) */
struct P_StateflowBlock_T_ {
  real_T Wheelradiusin_Value;          /* Expression: 1.5
                                        * Referenced by: '<Root>/Wheel radius (in)'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_StateflowBlock_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_StateflowBlock_T StateflowBlock_P;

/* Block states (default storage) */
extern DW_StateflowBlock_T StateflowBlock_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_StateflowBlock_T StateflowBlock_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_StateflowBlock_T StateflowBlock_Y;

/* Model entry point functions */
extern void StateflowBlock_initialize(void);
extern void StateflowBlock_step(void);
extern void StateflowBlock_terminate(void);

/* Real-time Model object */
extern RT_MODEL_StateflowBlock_T *const StateflowBlock_M;

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
 * '<Root>' : 'StateflowBlock'
 * '<S1>'   : 'StateflowBlock/Steering Stateflow'
 */
#endif                                 /* RTW_HEADER_StateflowBlock_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
