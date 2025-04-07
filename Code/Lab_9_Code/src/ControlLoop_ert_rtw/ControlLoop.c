/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop.c
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
  real_T rtb_Filter_m;
  real_T rtb_Integrator_b;
  real_T rtb_NProdOut;
  real_T rtb_NProdOut_e;
  real_T rtb_SpeedError;
  real_T rtb_Subtract_p;
  int32_T idxDelay;

  /* Sum: '<S1>/Subtract3' incorporates:
   *  Constant: '<Root>/Wheels distance (inch)'
   *  Constant: '<S1>/Constant B'
   *  DataStoreRead: '<Root>/Data Store Read'
   *  Delay: '<S1>/Delay'
   *  Delay: '<S1>/Delay1'
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   *  Product: '<S1>/Divide'
   *  Product: '<S1>/Divide1'
   *  Sum: '<S1>/Subtract'
   *  Sum: '<S1>/Subtract1'
   *  Sum: '<S1>/Subtract2'
   */
  ControlLoop_DW.CurrentGlobalDirection +=
    ((ControlLoop_U.DC_MotorA_Encoder_Counter - ControlLoop_DW.Delay_DSTATE) +
     (ControlLoop_U.DC_MotorB_Encoder_Counter - ControlLoop_DW.Delay1_DSTATE)) *
    ControlLoop_P.ConstantB_Value / ControlLoop_P.Wheelsdistanceinch_Value;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Speed_FF'
   *  Inport: '<Root>/KeepDistanceA_Enable_Bool'
   */
  if (ControlLoop_U.KeepDistanceA_Enable_Bool > ControlLoop_P.Switch_Threshold)
  {
    rtb_Filter_m = ControlLoop_P.Speed_FF_Value;
  } else {
    rtb_Filter_m = ControlLoop_P.Constant2_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<S2>/Subtract' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read1'
   *  Inport: '<Root>/DesiredRoverGlobalDirection'
   */
  rtb_Subtract_p = ControlLoop_U.DesiredRoverGlobalDirection -
    ControlLoop_DW.CurrentGlobalDirection;

  /* Product: '<S42>/NProd Out' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Filter Coefficient'
   *  DiscreteIntegrator: '<S34>/Filter'
   *  Product: '<S32>/DProd Out'
   *  Sum: '<S34>/SumD'
   */
  rtb_NProdOut = (rtb_Subtract_p * ControlLoop_P.Constant2_Value_l -
                  ControlLoop_DW.Filter_DSTATE) *
    ControlLoop_P.FilterCoefficient_Value;

  /* Sum: '<S48>/Sum' incorporates:
   *  Constant: '<S2>/Constant'
   *  DiscreteIntegrator: '<S39>/Integrator'
   *  Product: '<S44>/PProd Out'
   */
  rtb_Integrator_b = (rtb_Subtract_p * ControlLoop_P.Constant_Value +
                      ControlLoop_DW.Integrator_DSTATE) + rtb_NProdOut;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Integrator_b > ControlLoop_P.Saturation_UpperSat) {
    rtb_Integrator_b = ControlLoop_P.Saturation_UpperSat;
  } else if (rtb_Integrator_b < ControlLoop_P.Saturation_LowerSat) {
    rtb_Integrator_b = ControlLoop_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Sum: '<S3>/Speed Error' incorporates:
   *  Constant: '<S3>/Constant A'
   *  Delay: '<S3>/Delay'
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   *  Product: '<S3>/Divide'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S3>/Subtract'
   */
  rtb_SpeedError = (rtb_Filter_m + rtb_Integrator_b) -
    (ControlLoop_U.DC_MotorA_Encoder_Counter - ControlLoop_DW.Delay_DSTATE_l) *
    ControlLoop_P.ConstantA_Value;

  /* Product: '<S93>/NProd Out' incorporates:
   *  Constant: '<S3>/Filter Coefficient'
   *  Constant: '<S3>/MotorA_kd'
   *  DiscreteIntegrator: '<S85>/Filter'
   *  Product: '<S83>/DProd Out'
   *  Sum: '<S85>/SumD'
   */
  rtb_NProdOut_e = (rtb_SpeedError * ControlLoop_P.MotorA_kd_Value -
                    ControlLoop_DW.Filter_DSTATE_b) *
    ControlLoop_P.FilterCoefficient_Value_d;

  /* Sum: '<S99>/Sum' incorporates:
   *  Constant: '<Root>/MotorA_kp'
   *  DiscreteIntegrator: '<S90>/Integrator'
   *  Product: '<S95>/PProd Out'
   */
  ControlLoop_Y.DC_MotorA_PWM = (rtb_SpeedError * ControlLoop_P.MotorA_kp_Value
    + ControlLoop_DW.Integrator_DSTATE_h) + rtb_NProdOut_e;

  /* Saturate: '<S97>/Saturation' */
  if (ControlLoop_Y.DC_MotorA_PWM >
      ControlLoop_P.PIDController_UpperSaturationLi) {
    /* Sum: '<S99>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorA_PWM'
     */
    ControlLoop_Y.DC_MotorA_PWM = ControlLoop_P.PIDController_UpperSaturationLi;
  } else if (ControlLoop_Y.DC_MotorA_PWM <
             ControlLoop_P.PIDController_LowerSaturationLi) {
    /* Sum: '<S99>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorA_PWM'
     */
    ControlLoop_Y.DC_MotorA_PWM = ControlLoop_P.PIDController_LowerSaturationLi;
  }

  /* End of Saturate: '<S97>/Saturation' */

  /* Sum: '<S4>/Speed Error' incorporates:
   *  Constant: '<S4>/Constant A'
   *  Delay: '<S4>/Delay'
   *  Gain: '<Root>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   *  Product: '<S4>/Divide'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S4>/Subtract'
   */
  rtb_Filter_m = (ControlLoop_P.Gain_Gain * rtb_Filter_m +
                  ControlLoop_P.Gain1_Gain * rtb_Integrator_b) -
    (ControlLoop_U.DC_MotorB_Encoder_Counter - ControlLoop_DW.Delay_DSTATE_l1) *
    ControlLoop_P.ConstantA_Value_b;

  /* Product: '<S144>/NProd Out' incorporates:
   *  Constant: '<S4>/Filter Coefficient'
   *  Constant: '<S4>/Motor_kd'
   *  DiscreteIntegrator: '<S136>/Filter'
   *  Product: '<S134>/DProd Out'
   *  Sum: '<S136>/SumD'
   */
  rtb_Integrator_b = (rtb_Filter_m * ControlLoop_P.Motor_kd_Value -
                      ControlLoop_DW.Filter_DSTATE_c) *
    ControlLoop_P.FilterCoefficient_Value_p;

  /* Sum: '<S150>/Sum' incorporates:
   *  Constant: '<Root>/MotorB_kp'
   *  DiscreteIntegrator: '<S141>/Integrator'
   *  Product: '<S146>/PProd Out'
   */
  ControlLoop_Y.DC_MotorB_PWM = (rtb_Filter_m * ControlLoop_P.MotorB_kp_Value +
    ControlLoop_DW.Integrator_DSTATE_e) + rtb_Integrator_b;

  /* Saturate: '<S148>/Saturation' */
  if (ControlLoop_Y.DC_MotorB_PWM >
      ControlLoop_P.PIDController_UpperSaturation_e) {
    /* Sum: '<S150>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorB_PWM'
     */
    ControlLoop_Y.DC_MotorB_PWM = ControlLoop_P.PIDController_UpperSaturation_e;
  } else if (ControlLoop_Y.DC_MotorB_PWM <
             ControlLoop_P.PIDController_LowerSaturation_f) {
    /* Sum: '<S150>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorB_PWM'
     */
    ControlLoop_Y.DC_MotorB_PWM = ControlLoop_P.PIDController_LowerSaturation_f;
  }

  /* End of Saturate: '<S148>/Saturation' */

  /* Outport: '<Root>/DC_MotorA_SpeedFeedback' incorporates:
   *  Constant: '<S3>/Constant A'
   *  Constant: '<S3>/Frequency'
   *  Delay: '<S3>/Delay1'
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   *  Product: '<S3>/Divide1'
   *  Sum: '<S3>/Subtract1'
   */
  ControlLoop_Y.DC_MotorA_SpeedFeedback =
    (ControlLoop_U.DC_MotorA_Encoder_Counter - ControlLoop_DW.Delay1_DSTATE_o[0])
    * ControlLoop_P.ConstantA_Value / ControlLoop_P.Frequency_Value;

  /* Outport: '<Root>/DC_MotorB_SpeedFeedback' incorporates:
   *  Constant: '<S4>/Constant A'
   *  Constant: '<S4>/Frequency'
   *  Delay: '<S4>/Delay1'
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   *  Product: '<S4>/Divide1'
   *  Sum: '<S4>/Subtract1'
   */
  ControlLoop_Y.DC_MotorB_SpeedFeedback =
    (ControlLoop_U.DC_MotorB_Encoder_Counter - ControlLoop_DW.Delay1_DSTATE_m[0])
    * ControlLoop_P.ConstantA_Value_b / ControlLoop_P.Frequency_Value_f;

  /* Outport: '<Root>/RoverGlobalDirection' */
  ControlLoop_Y.RoverGlobalDirection = ControlLoop_DW.CurrentGlobalDirection;

  /* Update for Delay: '<S1>/Delay' incorporates:
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   */
  ControlLoop_DW.Delay_DSTATE = ControlLoop_U.DC_MotorA_Encoder_Counter;

  /* Update for Delay: '<S1>/Delay1' incorporates:
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   */
  ControlLoop_DW.Delay1_DSTATE = ControlLoop_U.DC_MotorB_Encoder_Counter;

  /* Update for DiscreteIntegrator: '<S39>/Integrator' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Product: '<S36>/IProd Out'
   */
  ControlLoop_DW.Integrator_DSTATE += rtb_Subtract_p *
    ControlLoop_P.Constant1_Value * ControlLoop_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S34>/Filter' */
  ControlLoop_DW.Filter_DSTATE += ControlLoop_P.Filter_gainval * rtb_NProdOut;

  /* Update for Delay: '<S3>/Delay' incorporates:
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   */
  ControlLoop_DW.Delay_DSTATE_l = ControlLoop_U.DC_MotorA_Encoder_Counter;

  /* Update for DiscreteIntegrator: '<S90>/Integrator' incorporates:
   *  Constant: '<Root>/MotorA_ki'
   *  Product: '<S87>/IProd Out'
   */
  ControlLoop_DW.Integrator_DSTATE_h += rtb_SpeedError *
    ControlLoop_P.MotorA_ki_Value * ControlLoop_P.Integrator_gainval_l;

  /* Update for DiscreteIntegrator: '<S85>/Filter' */
  ControlLoop_DW.Filter_DSTATE_b += ControlLoop_P.Filter_gainval_d *
    rtb_NProdOut_e;

  /* Update for Delay: '<S4>/Delay' incorporates:
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   */
  ControlLoop_DW.Delay_DSTATE_l1 = ControlLoop_U.DC_MotorB_Encoder_Counter;

  /* Update for DiscreteIntegrator: '<S141>/Integrator' incorporates:
   *  Constant: '<Root>/MotorB_ki'
   *  Product: '<S138>/IProd Out'
   */
  ControlLoop_DW.Integrator_DSTATE_e += rtb_Filter_m *
    ControlLoop_P.MotorB_ki_Value * ControlLoop_P.Integrator_gainval_h;

  /* Update for DiscreteIntegrator: '<S136>/Filter' */
  ControlLoop_DW.Filter_DSTATE_c += ControlLoop_P.Filter_gainval_b *
    rtb_Integrator_b;
  for (idxDelay = 0; idxDelay < 19; idxDelay++) {
    /* Update for Delay: '<S3>/Delay1' */
    ControlLoop_DW.Delay1_DSTATE_o[idxDelay] =
      ControlLoop_DW.Delay1_DSTATE_o[idxDelay + 1];

    /* Update for Delay: '<S4>/Delay1' */
    ControlLoop_DW.Delay1_DSTATE_m[idxDelay] =
      ControlLoop_DW.Delay1_DSTATE_m[idxDelay + 1];
  }

  /* Update for Delay: '<S3>/Delay1' incorporates:
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   */
  ControlLoop_DW.Delay1_DSTATE_o[19] = ControlLoop_U.DC_MotorA_Encoder_Counter;

  /* Update for Delay: '<S4>/Delay1' incorporates:
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   */
  ControlLoop_DW.Delay1_DSTATE_m[19] = ControlLoop_U.DC_MotorB_Encoder_Counter;
}

/* Model initialize function */
void ControlLoop_initialize(void)
{
  {
    int32_T i;

    /* Start for Sum: '<S1>/Subtract3' incorporates:
     *  DataStoreMemory: '<Root>/Data Store Memory'
     */
    ControlLoop_DW.CurrentGlobalDirection =
      ControlLoop_P.DataStoreMemory_InitialValue;

    /* InitializeConditions for Delay: '<S1>/Delay' */
    ControlLoop_DW.Delay_DSTATE = ControlLoop_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S1>/Delay1' */
    ControlLoop_DW.Delay1_DSTATE = ControlLoop_P.Delay1_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S39>/Integrator' */
    ControlLoop_DW.Integrator_DSTATE =
      ControlLoop_P.PIDController_InitialConditio_j;

    /* InitializeConditions for DiscreteIntegrator: '<S34>/Filter' */
    ControlLoop_DW.Filter_DSTATE = ControlLoop_P.PIDController_InitialConditionF;

    /* InitializeConditions for Delay: '<S3>/Delay' */
    ControlLoop_DW.Delay_DSTATE_l = ControlLoop_P.Delay_InitialCondition_g;

    /* InitializeConditions for DiscreteIntegrator: '<S90>/Integrator' */
    ControlLoop_DW.Integrator_DSTATE_h =
      ControlLoop_P.PIDController_InitialConditio_l;

    /* InitializeConditions for DiscreteIntegrator: '<S85>/Filter' */
    ControlLoop_DW.Filter_DSTATE_b =
      ControlLoop_P.PIDController_InitialConditio_i;

    /* InitializeConditions for Delay: '<S4>/Delay' */
    ControlLoop_DW.Delay_DSTATE_l1 = ControlLoop_P.Delay_InitialCondition_p;

    /* InitializeConditions for DiscreteIntegrator: '<S141>/Integrator' */
    ControlLoop_DW.Integrator_DSTATE_e =
      ControlLoop_P.PIDController_InitialConditi_jq;

    /* InitializeConditions for DiscreteIntegrator: '<S136>/Filter' */
    ControlLoop_DW.Filter_DSTATE_c =
      ControlLoop_P.PIDController_InitialConditio_a;
    for (i = 0; i < 20; i++) {
      /* InitializeConditions for Delay: '<S3>/Delay1' */
      ControlLoop_DW.Delay1_DSTATE_o[i] =
        ControlLoop_P.Delay1_InitialCondition_l;

      /* InitializeConditions for Delay: '<S4>/Delay1' */
      ControlLoop_DW.Delay1_DSTATE_m[i] =
        ControlLoop_P.Delay1_InitialCondition_lq;
    }
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
