/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: StateflowBlock.h
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

#ifndef StateflowBlock_h_
#define StateflowBlock_h_
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
  uint8_T is_active_c3_StateflowBlock; /* '<Root>/Steering Stateflow' */
  uint8_T is_c3_StateflowBlock;        /* '<Root>/Steering Stateflow' */
} DW_StateflowBlock_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T forward_button_in;         /* '<Root>/forward_button_in' */
  boolean_T backward_button_in;        /* '<Root>/backward_button_in' */
  boolean_T stop_button_in;            /* '<Root>/stop_button_in' */
  real_T right_button_in;              /* '<Root>/right_button_in' */
  real_T left_button_in;               /* '<Root>/left_button_in' */
} ExtU_StateflowBlock_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T controlA;                     /* '<Root>/controlA' */
  real_T controlB;                     /* '<Root>/controlB' */
  real_T state;                        /* '<Root>/state' */
} ExtY_StateflowBlock_T;

/* Real-time Model Data Structure */
struct tag_RTM_StateflowBlock_T {
  const char_T * volatile errorStatus;
};

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
#endif                                 /* StateflowBlock_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
