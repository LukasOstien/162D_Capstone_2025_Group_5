/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop_data.c
 *
 * Code generated for Simulink model 'ControlLoop'.
 *
 * Model version                  : 5.2
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Mar 11 18:00:52 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ControlLoop.h"

/* Block parameters (default storage) */
P_ControlLoop_T ControlLoop_P = {
  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S37>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_i
   * Referenced by: '<S90>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_a
   * Referenced by: '<S143>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_j
   * Referenced by: '<S42>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_l
   * Referenced by: '<S95>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditi_jq
   * Referenced by: '<S148>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S102>/Saturation'
   */
  -1.0,

  /* Mask Parameter: PIDController_LowerSaturation_f
   * Referenced by: '<S155>/Saturation'
   */
  -1.0,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S102>/Saturation'
   */
  1.0,

  /* Mask Parameter: PIDController_UpperSaturation_e
   * Referenced by: '<S155>/Saturation'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<Root>/DistanceControl_kp'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S3>/Constant'
   */
  20.0,

  /* Expression: 4
   * Referenced by: '<S3>/Saturation'
   */
  4.0,

  /* Expression: -4
   * Referenced by: '<S3>/Saturation'
   */
  -4.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch3'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay1'
   */
  0.0,

  /* Expression: 0.02618
   * Referenced by: '<S1>/Constant B'
   */
  0.02618,

  /* Expression: 12.65
   * Referenced by: '<Root>/Wheels distance (inch)'
   */
  12.65,

  /* Expression: 0.5
   * Referenced by: '<S1>/TakeAverageSpeed'
   */
  0.5,

  /* Expression: 0.02618
   * Referenced by: '<S1>/Constant C'
   */
  0.02618,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch1'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S4>/Wheel Radius'
   */
  3.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S42>/Integrator'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S3>/Constant2'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S37>/Filter'
   */
  0.005,

  /* Expression: 100
   * Referenced by: '<S3>/Filter Coefficient'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch2'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S2>/Gain'
   */
  0.5,

  /* Expression: 3
   * Referenced by: '<S2>/Wheel Radius'
   */
  3.0,

  /* Expression: 0.0
   * Referenced by: '<S5>/Delay'
   */
  0.0,

  /* Expression: 3.49066
   * Referenced by: '<S5>/Constant A'
   */
  3.49066,

  /* Expression: 0.12
   * Referenced by: '<Root>/MotorA_kp'
   */
  0.12,

  /* Computed Parameter: Integrator_gainval_l
   * Referenced by: '<S95>/Integrator'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S5>/MotorA_kd'
   */
  0.0,

  /* Computed Parameter: Filter_gainval_d
   * Referenced by: '<S90>/Filter'
   */
  0.005,

  /* Expression: 100
   * Referenced by: '<S5>/Filter Coefficient'
   */
  100.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain'
   */
  -1.0,

  /* Expression: 0.0
   * Referenced by: '<S6>/Delay'
   */
  0.0,

  /* Expression: 3.49066
   * Referenced by: '<S6>/Constant A'
   */
  3.49066,

  /* Expression: 0.12
   * Referenced by: '<Root>/MotorB_kp'
   */
  0.12,

  /* Computed Parameter: Integrator_gainval_h
   * Referenced by: '<S148>/Integrator'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S6>/Motor_kd'
   */
  0.0,

  /* Computed Parameter: Filter_gainval_b
   * Referenced by: '<S143>/Filter'
   */
  0.005,

  /* Expression: 100
   * Referenced by: '<S6>/Filter Coefficient'
   */
  100.0,

  /* Expression: 0.0
   * Referenced by: '<S5>/Delay1'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S5>/Frequency'
   */
  20.0,

  /* Expression: 0.0
   * Referenced by: '<S6>/Delay1'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S6>/Frequency'
   */
  20.0,

  /* Expression: 0.35
   * Referenced by: '<Root>/MotorA_ki'
   */
  0.35,

  /* Expression: 0.35
   * Referenced by: '<Root>/MotorB_ki'
   */
  0.35,

  /* Expression: 0
   * Referenced by: '<S3>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory2'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
