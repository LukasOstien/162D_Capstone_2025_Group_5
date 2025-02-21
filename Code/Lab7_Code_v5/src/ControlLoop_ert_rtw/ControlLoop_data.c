/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop_data.c
 *
 * Code generated for Simulink model 'ControlLoop'.
 *
 * Model version                  : 4.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Feb 18 18:14:40 2025
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
   * Referenced by: '<S33>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_a
   * Referenced by: '<S84>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_l
   * Referenced by: '<S38>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_j
   * Referenced by: '<S89>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S45>/Saturation'
   */
  -1.0,

  /* Mask Parameter: PIDController_LowerSaturation_f
   * Referenced by: '<S96>/Saturation'
   */
  -1.0,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S45>/Saturation'
   */
  1.0,

  /* Mask Parameter: PIDController_UpperSaturation_e
   * Referenced by: '<S96>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain3'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain4'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay1'
   */
  0.0,

  /* Expression: 3.49066
   * Referenced by: '<S2>/Constant A'
   */
  3.49066,

  /* Expression: 20
   * Referenced by: '<S2>/Frequency'
   */
  20.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay1'
   */
  0.0,

  /* Expression: 3.49066
   * Referenced by: '<S3>/Constant A'
   */
  3.49066,

  /* Expression: 20
   * Referenced by: '<S3>/Frequency'
   */
  20.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Gain1'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S1>/Gain2'
   */
  0.5,

  /* Expression: 0.1
   * Referenced by: '<Root>/DistanceControl_kp'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay'
   */
  0.0,

  /* Expression: 0.11
   * Referenced by: '<Root>/MotorA_kp'
   */
  0.11,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S38>/Integrator'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S2>/MotorA_kd'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S33>/Filter'
   */
  0.005,

  /* Expression: 100
   * Referenced by: '<S2>/Filter Coefficient'
   */
  100.0,

  /* Expression: 0.4
   * Referenced by: '<Root>/MotorA_ki'
   */
  0.4,

  /* Expression: 0
   * Referenced by: '<Root>/Switch1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay'
   */
  0.0,

  /* Expression: 0.11
   * Referenced by: '<Root>/MotorB_kp'
   */
  0.11,

  /* Computed Parameter: Integrator_gainval_h
   * Referenced by: '<S89>/Integrator'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S3>/Motor_kd'
   */
  0.0,

  /* Computed Parameter: Filter_gainval_b
   * Referenced by: '<S84>/Filter'
   */
  0.005,

  /* Expression: 100
   * Referenced by: '<S3>/Filter Coefficient'
   */
  100.0,

  /* Expression: 0.4
   * Referenced by: '<Root>/MotorB_ki'
   */
  0.4
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
