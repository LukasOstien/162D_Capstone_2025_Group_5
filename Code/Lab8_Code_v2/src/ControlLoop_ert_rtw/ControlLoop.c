/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop.c
 *
 * Code generated for Simulink model 'ControlLoop'.
 *
 * Model version                  : 3.19
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Feb 25 17:25:01 2025
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
  real_T rtb_DataStoreRead;
  real_T rtb_Divide;
  real_T rtb_NProdOut;
  real_T rtb_Subtract3;
  int32_T idxDelay;

  /* DataStoreRead: '<S2>/Data Store Read' */
  rtb_DataStoreRead = ControlLoop_DW.ServoA_CurrentAngle;

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<Root>/ServoA Sweeping Speed'
   *  Constant: '<S2>/Constant'
   *  DataStoreRead: '<S2>/Data Store Read'
   *  DataStoreRead: '<S2>/Data Store Read1'
   *  DataStoreWrite: '<S2>/Data Store Write'
   *  Inport: '<Root>/ServoA_Sweeping_Enable_Bool'
   *  Product: '<S2>/Multiple'
   *  Sum: '<S2>/Add'
   */
  if (ControlLoop_U.ServoA_Sweeping_Enable_Bool >
      ControlLoop_P.Switch1_Threshold_o) {
    ControlLoop_DW.ServoA_CurrentAngle +=
      ControlLoop_P.ServoASweepingSpeed_Value *
      ControlLoop_DW.ServoA_CountingDirection;
  } else {
    ControlLoop_DW.ServoA_CurrentAngle = ControlLoop_P.Constant_Value;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* If: '<S2>/If' incorporates:
   *  Constant: '<Root>/ServoA Sweeping Angle Lower Limit'
   *  Constant: '<Root>/ServoA Sweeping Angle Upper Limit'
   */
  if (rtb_DataStoreRead >= ControlLoop_P.ServoASweepingAngleUpperLimit_V) {
    /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    ControlLoop_DW.ServoA_CountingDirection = ControlLoop_P.Constant1_Value_e;
  } else if (rtb_DataStoreRead <= ControlLoop_P.ServoASweepingAngleLowerLimit_V)
  {
    /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
     *  Constant: '<S2>/Constant2'
     */
    ControlLoop_DW.ServoA_CountingDirection = ControlLoop_P.Constant2_Value;
  }

  /* End of If: '<S2>/If' */

  /* Product: '<S3>/Divide1' incorporates:
   *  Constant: '<S3>/Constant A'
   *  Constant: '<S3>/Frequency'
   *  Delay: '<S3>/Delay1'
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   *  Sum: '<S3>/Subtract1'
   */
  ControlLoop_Y.DC_MotorA_SpeedFeedback =
    (ControlLoop_U.DC_MotorA_Encoder_Counter - ControlLoop_DW.Delay1_DSTATE[0]) *
    ControlLoop_P.ConstantA_Value / ControlLoop_P.Frequency_Value;

  /* Product: '<S4>/Divide1' incorporates:
   *  Constant: '<S4>/Constant A'
   *  Constant: '<S4>/Frequency'
   *  Delay: '<S4>/Delay1'
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   *  Sum: '<S4>/Subtract1'
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
      rtb_DataStoreRead = ControlLoop_U.DC_MotorA_SpeedCommand;
    } else {
      /* Sum: '<S1>/Subtract5' incorporates:
       *  Gain: '<S1>/Gain'
       *  Inport: '<Root>/DC_MotorA_SpeedCommand'
       */
      rtb_DataStoreRead = ControlLoop_U.DC_MotorA_SpeedCommand -
        ControlLoop_P.Gain_Gain * rtb_Divide;

      /* Switch: '<S1>/Switch2' incorporates:
       *  Constant: '<S1>/Constant'
       */
      if (!(rtb_DataStoreRead > ControlLoop_P.Switch2_Threshold)) {
        rtb_DataStoreRead = ControlLoop_P.Constant_Value_g;
      }

      /* End of Switch: '<S1>/Switch2' */
    }

    /* End of Switch: '<S1>/Switch' */
  } else {
    rtb_DataStoreRead = ControlLoop_U.DC_MotorA_SpeedCommand;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<S3>/Speed Error' incorporates:
   *  Constant: '<S3>/Constant A'
   *  Delay: '<S3>/Delay'
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   *  Product: '<S3>/Divide'
   *  Sum: '<S3>/Subtract'
   */
  rtb_DataStoreRead -= (ControlLoop_U.DC_MotorA_Encoder_Counter -
                        ControlLoop_DW.Delay_DSTATE) *
    ControlLoop_P.ConstantA_Value;

  /* Product: '<S45>/NProd Out' incorporates:
   *  Constant: '<S3>/Filter Coefficient'
   *  Constant: '<S3>/MotorA_kd'
   *  DiscreteIntegrator: '<S37>/Filter'
   *  Product: '<S35>/DProd Out'
   *  Sum: '<S37>/SumD'
   */
  rtb_NProdOut = (rtb_DataStoreRead * ControlLoop_P.MotorA_kd_Value -
                  ControlLoop_DW.Filter_DSTATE) *
    ControlLoop_P.FilterCoefficient_Value;

  /* Sum: '<S51>/Sum' incorporates:
   *  Constant: '<Root>/MotorA_kp'
   *  DiscreteIntegrator: '<S42>/Integrator'
   *  Product: '<S47>/PProd Out'
   */
  ControlLoop_Y.DC_MotorA_PWM = (rtb_DataStoreRead *
    ControlLoop_P.MotorA_kp_Value + ControlLoop_DW.Integrator_DSTATE) +
    rtb_NProdOut;

  /* Saturate: '<S49>/Saturation' */
  if (ControlLoop_Y.DC_MotorA_PWM >
      ControlLoop_P.PIDController_UpperSaturationLi) {
    /* Sum: '<S51>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorA_PWM'
     */
    ControlLoop_Y.DC_MotorA_PWM = ControlLoop_P.PIDController_UpperSaturationLi;
  } else if (ControlLoop_Y.DC_MotorA_PWM <
             ControlLoop_P.PIDController_LowerSaturationLi) {
    /* Sum: '<S51>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorA_PWM'
     */
    ControlLoop_Y.DC_MotorA_PWM = ControlLoop_P.PIDController_LowerSaturationLi;
  }

  /* End of Saturate: '<S49>/Saturation' */

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

  /* Sum: '<S4>/Speed Error' incorporates:
   *  Constant: '<S4>/Constant A'
   *  Delay: '<S4>/Delay'
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   *  Product: '<S4>/Divide'
   *  Sum: '<S4>/Subtract'
   */
  rtb_Subtract3 -= (ControlLoop_U.DC_MotorB_Encoder_Counter -
                    ControlLoop_DW.Delay_DSTATE_l) *
    ControlLoop_P.ConstantA_Value_b;

  /* Product: '<S96>/NProd Out' incorporates:
   *  Constant: '<S4>/Filter Coefficient'
   *  Constant: '<S4>/Motor_kd'
   *  DiscreteIntegrator: '<S88>/Filter'
   *  Product: '<S86>/DProd Out'
   *  Sum: '<S88>/SumD'
   */
  rtb_Divide = (rtb_Subtract3 * ControlLoop_P.Motor_kd_Value -
                ControlLoop_DW.Filter_DSTATE_c) *
    ControlLoop_P.FilterCoefficient_Value_p;

  /* Sum: '<S102>/Sum' incorporates:
   *  Constant: '<Root>/MotorB_kp'
   *  DiscreteIntegrator: '<S93>/Integrator'
   *  Product: '<S98>/PProd Out'
   */
  ControlLoop_Y.DC_MotorB_PWM = (rtb_Subtract3 * ControlLoop_P.MotorB_kp_Value +
    ControlLoop_DW.Integrator_DSTATE_e) + rtb_Divide;

  /* Saturate: '<S100>/Saturation' */
  if (ControlLoop_Y.DC_MotorB_PWM >
      ControlLoop_P.PIDController_UpperSaturation_e) {
    /* Sum: '<S102>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorB_PWM'
     */
    ControlLoop_Y.DC_MotorB_PWM = ControlLoop_P.PIDController_UpperSaturation_e;
  } else if (ControlLoop_Y.DC_MotorB_PWM <
             ControlLoop_P.PIDController_LowerSaturation_f) {
    /* Sum: '<S102>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorB_PWM'
     */
    ControlLoop_Y.DC_MotorB_PWM = ControlLoop_P.PIDController_LowerSaturation_f;
  }

  /* End of Saturate: '<S100>/Saturation' */

  /* Outport: '<Root>/ServoMotorA_Angle' incorporates:
   *  DataStoreWrite: '<S2>/Data Store Write'
   */
  ControlLoop_Y.ServoMotorA_Angle = ControlLoop_DW.ServoA_CurrentAngle;
  for (idxDelay = 0; idxDelay < 19; idxDelay++) {
    /* Update for Delay: '<S3>/Delay1' */
    ControlLoop_DW.Delay1_DSTATE[idxDelay] =
      ControlLoop_DW.Delay1_DSTATE[idxDelay + 1];

    /* Update for Delay: '<S4>/Delay1' */
    ControlLoop_DW.Delay1_DSTATE_m[idxDelay] =
      ControlLoop_DW.Delay1_DSTATE_m[idxDelay + 1];
  }

  /* Update for Delay: '<S3>/Delay1' incorporates:
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   */
  ControlLoop_DW.Delay1_DSTATE[19] = ControlLoop_U.DC_MotorA_Encoder_Counter;

  /* Update for Delay: '<S4>/Delay1' incorporates:
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   */
  ControlLoop_DW.Delay1_DSTATE_m[19] = ControlLoop_U.DC_MotorB_Encoder_Counter;

  /* Update for Delay: '<S3>/Delay' incorporates:
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   */
  ControlLoop_DW.Delay_DSTATE = ControlLoop_U.DC_MotorA_Encoder_Counter;

  /* Update for DiscreteIntegrator: '<S42>/Integrator' incorporates:
   *  Constant: '<Root>/MotorA_ki'
   *  Product: '<S39>/IProd Out'
   */
  ControlLoop_DW.Integrator_DSTATE += rtb_DataStoreRead *
    ControlLoop_P.MotorA_ki_Value * ControlLoop_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S37>/Filter' */
  ControlLoop_DW.Filter_DSTATE += ControlLoop_P.Filter_gainval * rtb_NProdOut;

  /* Update for Delay: '<S4>/Delay' incorporates:
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   */
  ControlLoop_DW.Delay_DSTATE_l = ControlLoop_U.DC_MotorB_Encoder_Counter;

  /* Update for DiscreteIntegrator: '<S93>/Integrator' incorporates:
   *  Constant: '<Root>/MotorB_ki'
   *  Product: '<S90>/IProd Out'
   */
  ControlLoop_DW.Integrator_DSTATE_e += rtb_Subtract3 *
    ControlLoop_P.MotorB_ki_Value * ControlLoop_P.Integrator_gainval_h;

  /* Update for DiscreteIntegrator: '<S88>/Filter' */
  ControlLoop_DW.Filter_DSTATE_c += ControlLoop_P.Filter_gainval_b * rtb_Divide;
}

/* Model initialize function */
void ControlLoop_initialize(void)
{
  {
    int32_T i;

    /* Start for DataStoreMemory: '<S2>/Data Store Memory' */
    ControlLoop_DW.ServoA_CurrentAngle =
      ControlLoop_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S2>/Data Store Memory1' */
    ControlLoop_DW.ServoA_CountingDirection =
      ControlLoop_P.DataStoreMemory1_InitialValue;
    for (i = 0; i < 20; i++) {
      /* InitializeConditions for Delay: '<S3>/Delay1' */
      ControlLoop_DW.Delay1_DSTATE[i] = ControlLoop_P.Delay1_InitialCondition;

      /* InitializeConditions for Delay: '<S4>/Delay1' */
      ControlLoop_DW.Delay1_DSTATE_m[i] =
        ControlLoop_P.Delay1_InitialCondition_l;
    }

    /* InitializeConditions for Delay: '<S3>/Delay' */
    ControlLoop_DW.Delay_DSTATE = ControlLoop_P.Delay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S42>/Integrator' */
    ControlLoop_DW.Integrator_DSTATE =
      ControlLoop_P.PIDController_InitialConditio_l;

    /* InitializeConditions for DiscreteIntegrator: '<S37>/Filter' */
    ControlLoop_DW.Filter_DSTATE = ControlLoop_P.PIDController_InitialConditionF;

    /* InitializeConditions for Delay: '<S4>/Delay' */
    ControlLoop_DW.Delay_DSTATE_l = ControlLoop_P.Delay_InitialCondition_p;

    /* InitializeConditions for DiscreteIntegrator: '<S93>/Integrator' */
    ControlLoop_DW.Integrator_DSTATE_e =
      ControlLoop_P.PIDController_InitialConditio_j;

    /* InitializeConditions for DiscreteIntegrator: '<S88>/Filter' */
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
