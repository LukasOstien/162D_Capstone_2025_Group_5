/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop.c
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
#include "rtwtypes.h"

/* Block states (default storage) */
DW_ControlLoop_T ControlLoop_DW;

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
  real_T rtb_Divide;
  real_T rtb_NProdOut;
  real_T rtb_Subtract3;
  real_T rtb_Subtract5;
  int32_T idxDelay;

  /* Product: '<S2>/Divide1' incorporates:
   *  Constant: '<S2>/Constant A'
   *  Constant: '<S2>/Frequency'
   *  Delay: '<S2>/Delay1'
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   *  Sum: '<S2>/Subtract1'
   */
  ControlLoop_Y.DC_MotorA_SpeedFeedback =
    (ControlLoop_U.DC_MotorA_Encoder_Counter - ControlLoop_DW.Delay1_DSTATE[0]) *
    ControlLoop_P.ConstantA_Value / ControlLoop_P.Frequency_Value;

  /* Product: '<S3>/Divide1' incorporates:
   *  Constant: '<S3>/Constant A'
   *  Constant: '<S3>/Frequency'
   *  Delay: '<S3>/Delay1'
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   *  Sum: '<S3>/Subtract1'
   */
  ControlLoop_Y.DC_MotorB_SpeedFeedback =
    (ControlLoop_U.DC_MotorB_Encoder_Counter - ControlLoop_DW.Delay1_DSTATE_m[0])
    * ControlLoop_P.ConstantA_Value_b / ControlLoop_P.Frequency_Value_f;

  /* Sum: '<S1>/Subtract3' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain2'
   *  Inport: '<Root>/DC_MotorA_SpeedCommand'
   *  Inport: '<Root>/DC_MotorB_SpeedCommand'
   *  Sum: '<S1>/Subtract1'
   *  Sum: '<S1>/Subtract2'
   */
  rtb_Subtract3 = (ControlLoop_Y.DC_MotorA_SpeedFeedback -
                   ControlLoop_Y.DC_MotorB_SpeedFeedback) *
    ControlLoop_P.Gain1_Gain - (ControlLoop_U.DC_MotorA_SpeedCommand -
    ControlLoop_U.DC_MotorB_SpeedCommand) * ControlLoop_P.Gain2_Gain;

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<Root>/DistanceControl_kp'
   *  Inport: '<Root>/DistanceA_command'
   *  Inport: '<Root>/UltrasoundDistanceA'
   *  Sum: '<S1>/Subtract4'
   */
  rtb_Divide = (ControlLoop_U.DistanceA_command -
                ControlLoop_U.UltrasoundDistanceA) *
    ControlLoop_P.DistanceControl_kp_Value;

  /* Switch: '<Root>/Switch' incorporates:
   *  Inport: '<Root>/DC_MotorA_SpeedCommand'
   *  Inport: '<Root>/KeepDistanceA_Enable_Bool'
   */
  if (ControlLoop_U.KeepDistanceA_Enable_Bool > ControlLoop_P.Switch_Threshold_f)
  {
    /* Switch: '<S1>/Switch' incorporates:
     *  Inport: '<Root>/DC_MotorA_SpeedCommand'
     */
    if (rtb_Subtract3 > ControlLoop_P.Switch_Threshold) {
      rtb_Subtract5 = ControlLoop_U.DC_MotorA_SpeedCommand;
    } else {
      /* Sum: '<S1>/Subtract5' incorporates:
       *  Gain: '<S1>/Gain'
       *  Inport: '<Root>/DC_MotorA_SpeedCommand'
       */
      rtb_Subtract5 = ControlLoop_U.DC_MotorA_SpeedCommand -
        ControlLoop_P.Gain_Gain * rtb_Divide;

      /* Switch: '<S1>/Switch2' incorporates:
       *  Constant: '<S1>/Constant'
       */
      if (!(rtb_Subtract5 > ControlLoop_P.Switch2_Threshold)) {
        rtb_Subtract5 = ControlLoop_P.Constant_Value;
      }

      /* End of Switch: '<S1>/Switch2' */
    }

    /* End of Switch: '<S1>/Switch' */
  } else {
    rtb_Subtract5 = ControlLoop_U.DC_MotorA_SpeedCommand;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<S2>/Speed Error' incorporates:
   *  Constant: '<S2>/Constant A'
   *  Delay: '<S2>/Delay'
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   *  Product: '<S2>/Divide'
   *  Sum: '<S2>/Subtract'
   */
  rtb_Subtract5 -= (ControlLoop_U.DC_MotorA_Encoder_Counter -
                    ControlLoop_DW.Delay_DSTATE) * ControlLoop_P.ConstantA_Value;

  /* Product: '<S41>/NProd Out' incorporates:
   *  Constant: '<S2>/Filter Coefficient'
   *  Constant: '<S2>/MotorA_kd'
   *  DiscreteIntegrator: '<S33>/Filter'
   *  Product: '<S31>/DProd Out'
   *  Sum: '<S33>/SumD'
   */
  rtb_NProdOut = (rtb_Subtract5 * ControlLoop_P.MotorA_kd_Value -
                  ControlLoop_DW.Filter_DSTATE) *
    ControlLoop_P.FilterCoefficient_Value;

  /* Sum: '<S47>/Sum' incorporates:
   *  Constant: '<Root>/MotorA_kp'
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  Product: '<S43>/PProd Out'
   */
  ControlLoop_Y.DC_MotorA_PWM = (rtb_Subtract5 * ControlLoop_P.MotorA_kp_Value +
    ControlLoop_DW.Integrator_DSTATE) + rtb_NProdOut;

  /* Saturate: '<S45>/Saturation' */
  if (ControlLoop_Y.DC_MotorA_PWM >
      ControlLoop_P.PIDController_UpperSaturationLi) {
    /* Sum: '<S47>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorA_PWM'
     */
    ControlLoop_Y.DC_MotorA_PWM = ControlLoop_P.PIDController_UpperSaturationLi;
  } else if (ControlLoop_Y.DC_MotorA_PWM <
             ControlLoop_P.PIDController_LowerSaturationLi) {
    /* Sum: '<S47>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorA_PWM'
     */
    ControlLoop_Y.DC_MotorA_PWM = ControlLoop_P.PIDController_LowerSaturationLi;
  }

  /* End of Saturate: '<S45>/Saturation' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Inport: '<Root>/DC_MotorB_SpeedCommand'
   *  Inport: '<Root>/KeepDistanceA_Enable_Bool'
   */
  if (ControlLoop_U.KeepDistanceA_Enable_Bool >
      ControlLoop_P.Switch1_Threshold_i) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Inport: '<Root>/DC_MotorB_SpeedCommand'
     */
    if (rtb_Subtract3 > ControlLoop_P.Switch1_Threshold) {
      rtb_Subtract3 = ControlLoop_U.DC_MotorB_SpeedCommand;
    } else {
      /* Sum: '<S1>/Subtract6' incorporates:
       *  Gain: '<S1>/Gain3'
       *  Inport: '<Root>/DC_MotorB_SpeedCommand'
       */
      rtb_Subtract3 = ControlLoop_U.DC_MotorB_SpeedCommand -
        ControlLoop_P.Gain3_Gain * rtb_Divide;

      /* Switch: '<S1>/Switch3' incorporates:
       *  Constant: '<S1>/Constant1'
       *  Gain: '<S1>/Gain4'
       */
      if (!(ControlLoop_P.Gain4_Gain * rtb_Subtract3 >
            ControlLoop_P.Switch3_Threshold)) {
        rtb_Subtract3 = ControlLoop_P.Constant1_Value;
      }

      /* End of Switch: '<S1>/Switch3' */
    }

    /* End of Switch: '<S1>/Switch1' */
  } else {
    rtb_Subtract3 = ControlLoop_U.DC_MotorB_SpeedCommand;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<S3>/Speed Error' incorporates:
   *  Constant: '<S3>/Constant A'
   *  Delay: '<S3>/Delay'
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   *  Product: '<S3>/Divide'
   *  Sum: '<S3>/Subtract'
   */
  rtb_Subtract3 -= (ControlLoop_U.DC_MotorB_Encoder_Counter -
                    ControlLoop_DW.Delay_DSTATE_l) *
    ControlLoop_P.ConstantA_Value_b;

  /* Product: '<S92>/NProd Out' incorporates:
   *  Constant: '<S3>/Filter Coefficient'
   *  Constant: '<S3>/Motor_kd'
   *  DiscreteIntegrator: '<S84>/Filter'
   *  Product: '<S82>/DProd Out'
   *  Sum: '<S84>/SumD'
   */
  rtb_Divide = (rtb_Subtract3 * ControlLoop_P.Motor_kd_Value -
                ControlLoop_DW.Filter_DSTATE_c) *
    ControlLoop_P.FilterCoefficient_Value_p;

  /* Sum: '<S98>/Sum' incorporates:
   *  Constant: '<Root>/MotorB_kp'
   *  DiscreteIntegrator: '<S89>/Integrator'
   *  Product: '<S94>/PProd Out'
   */
  ControlLoop_Y.DC_MotorB_PWM = (rtb_Subtract3 * ControlLoop_P.MotorB_kp_Value +
    ControlLoop_DW.Integrator_DSTATE_e) + rtb_Divide;

  /* Saturate: '<S96>/Saturation' */
  if (ControlLoop_Y.DC_MotorB_PWM >
      ControlLoop_P.PIDController_UpperSaturation_e) {
    /* Sum: '<S98>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorB_PWM'
     */
    ControlLoop_Y.DC_MotorB_PWM = ControlLoop_P.PIDController_UpperSaturation_e;
  } else if (ControlLoop_Y.DC_MotorB_PWM <
             ControlLoop_P.PIDController_LowerSaturation_f) {
    /* Sum: '<S98>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorB_PWM'
     */
    ControlLoop_Y.DC_MotorB_PWM = ControlLoop_P.PIDController_LowerSaturation_f;
  }

  /* End of Saturate: '<S96>/Saturation' */
  for (idxDelay = 0; idxDelay < 19; idxDelay++) {
    /* Update for Delay: '<S2>/Delay1' */
    ControlLoop_DW.Delay1_DSTATE[idxDelay] =
      ControlLoop_DW.Delay1_DSTATE[idxDelay + 1];

    /* Update for Delay: '<S3>/Delay1' */
    ControlLoop_DW.Delay1_DSTATE_m[idxDelay] =
      ControlLoop_DW.Delay1_DSTATE_m[idxDelay + 1];
  }

  /* Update for Delay: '<S2>/Delay1' incorporates:
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   */
  ControlLoop_DW.Delay1_DSTATE[19] = ControlLoop_U.DC_MotorA_Encoder_Counter;

  /* Update for Delay: '<S3>/Delay1' incorporates:
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   */
  ControlLoop_DW.Delay1_DSTATE_m[19] = ControlLoop_U.DC_MotorB_Encoder_Counter;

  /* Update for Delay: '<S2>/Delay' incorporates:
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   */
  ControlLoop_DW.Delay_DSTATE = ControlLoop_U.DC_MotorA_Encoder_Counter;

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Constant: '<Root>/MotorA_ki'
   *  Product: '<S35>/IProd Out'
   */
  ControlLoop_DW.Integrator_DSTATE += rtb_Subtract5 *
    ControlLoop_P.MotorA_ki_Value * ControlLoop_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S33>/Filter' */
  ControlLoop_DW.Filter_DSTATE += ControlLoop_P.Filter_gainval * rtb_NProdOut;

  /* Update for Delay: '<S3>/Delay' incorporates:
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   */
  ControlLoop_DW.Delay_DSTATE_l = ControlLoop_U.DC_MotorB_Encoder_Counter;

  /* Update for DiscreteIntegrator: '<S89>/Integrator' incorporates:
   *  Constant: '<Root>/MotorB_ki'
   *  Product: '<S86>/IProd Out'
   */
  ControlLoop_DW.Integrator_DSTATE_e += rtb_Subtract3 *
    ControlLoop_P.MotorB_ki_Value * ControlLoop_P.Integrator_gainval_h;

  /* Update for DiscreteIntegrator: '<S84>/Filter' */
  ControlLoop_DW.Filter_DSTATE_c += ControlLoop_P.Filter_gainval_b * rtb_Divide;
}

/* Model initialize function */
void ControlLoop_initialize(void)
{
  {
    int32_T i;
    for (i = 0; i < 20; i++) {
      /* InitializeConditions for Delay: '<S2>/Delay1' */
      ControlLoop_DW.Delay1_DSTATE[i] = ControlLoop_P.Delay1_InitialCondition;

      /* InitializeConditions for Delay: '<S3>/Delay1' */
      ControlLoop_DW.Delay1_DSTATE_m[i] =
        ControlLoop_P.Delay1_InitialCondition_l;
    }

    /* InitializeConditions for Delay: '<S2>/Delay' */
    ControlLoop_DW.Delay_DSTATE = ControlLoop_P.Delay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator' */
    ControlLoop_DW.Integrator_DSTATE =
      ControlLoop_P.PIDController_InitialConditio_l;

    /* InitializeConditions for DiscreteIntegrator: '<S33>/Filter' */
    ControlLoop_DW.Filter_DSTATE = ControlLoop_P.PIDController_InitialConditionF;

    /* InitializeConditions for Delay: '<S3>/Delay' */
    ControlLoop_DW.Delay_DSTATE_l = ControlLoop_P.Delay_InitialCondition_p;

    /* InitializeConditions for DiscreteIntegrator: '<S89>/Integrator' */
    ControlLoop_DW.Integrator_DSTATE_e =
      ControlLoop_P.PIDController_InitialConditio_j;

    /* InitializeConditions for DiscreteIntegrator: '<S84>/Filter' */
    ControlLoop_DW.Filter_DSTATE_c =
      ControlLoop_P.PIDController_InitialConditio_a;
  }
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
