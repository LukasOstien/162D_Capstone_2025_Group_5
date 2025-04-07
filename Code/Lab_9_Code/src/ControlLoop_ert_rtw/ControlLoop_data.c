/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop_data.c
 *
 * Code generated for Simulink model 'ControlLoop'.
 *
 * Model version                  : 4.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Mar  4 17:14:23 2025
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
   * Referenced by: '<S34>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_i
   * Referenced by: '<S85>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_a
   * Referenced by: '<S136>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_j
   * Referenced by: '<S39>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_l
   * Referenced by: '<S90>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditi_jq
   * Referenced by: '<S141>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S97>/Saturation'
   */
  -1.0,

  /* Mask Parameter: PIDController_LowerSaturation_f
   * Referenced by: '<S148>/Saturation'
   */
  -1.0,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S97>/Saturation'
   */
  1.0,

  /* Mask Parameter: PIDController_UpperSaturation_e
   * Referenced by: '<S148>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Speed_FF'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
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

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S2>/Constant'
   */
  10.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S39>/Integrator'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S2>/Constant2'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S34>/Filter'
   */
  0.005,

  /* Expression: 100
   * Referenced by: '<S2>/Filter Coefficient'
   */
  100.0,

  /* Expression: 2
   * Referenced by: '<S2>/Saturation'
   */
  2.0,

  /* Expression: -2
   * Referenced by: '<S2>/Saturation'
   */
  -2.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay'
   */
  0.0,

  /* Expression: 3.49066
   * Referenced by: '<S3>/Constant A'
   */
  3.49066,

  /* Expression: 0.12
   * Referenced by: '<Root>/MotorA_kp'
   */
  0.12,

  /* Computed Parameter: Integrator_gainval_l
   * Referenced by: '<S90>/Integrator'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S3>/MotorA_kd'
   */
  0.0,

  /* Computed Parameter: Filter_gainval_d
   * Referenced by: '<S85>/Filter'
   */
  0.005,

  /* Expression: 100
   * Referenced by: '<S3>/Filter Coefficient'
   */
  100.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S2>/Gain1'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay'
   */
  0.0,

  /* Expression: 3.49066
   * Referenced by: '<S4>/Constant A'
   */
  3.49066,

  /* Expression: 0.12
   * Referenced by: '<Root>/MotorB_kp'
   */
  0.12,

  /* Computed Parameter: Integrator_gainval_h
   * Referenced by: '<S141>/Integrator'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S4>/Motor_kd'
   */
  0.0,

  /* Computed Parameter: Filter_gainval_b
   * Referenced by: '<S136>/Filter'
   */
  0.005,

  /* Expression: 100
   * Referenced by: '<S4>/Filter Coefficient'
   */
  100.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay1'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S3>/Frequency'
   */
  20.0,

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay1'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S4>/Frequency'
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
   * Referenced by: '<S2>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
