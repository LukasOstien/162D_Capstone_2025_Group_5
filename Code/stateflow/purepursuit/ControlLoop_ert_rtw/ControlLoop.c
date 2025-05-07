/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop.c
 *
 * Code generated for Simulink model 'ControlLoop'.
 *
 * Model version                  : 5.63
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue May  6 17:42:40 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ControlLoop.h"
#include <math.h>
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
  real_T rtb_Filter_k;
  real_T rtb_Integrator_e;
  real_T rtb_NProdOut;
  real_T rtb_NProdOut_e;
  real_T rtb_SpeedError;
  real_T rtb_Subtract_d;
  int32_T idxDelay;

  /* Sum: '<S2>/Subtract5' incorporates:
   *  Delay: '<S2>/Delay'
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   *  Sum: '<S2>/Subtract1'
   */
  ControlLoop_Y.RoverGlobalCoordX = ControlLoop_U.DC_MotorA_Encoder_Counter -
    ControlLoop_DW.Delay_DSTATE;

  /* Sum: '<S2>/Subtract2' incorporates:
   *  Delay: '<S2>/Delay1'
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   */
  rtb_Filter_k = ControlLoop_U.DC_MotorB_Encoder_Counter -
    ControlLoop_DW.Delay1_DSTATE;

  /* Sum: '<S2>/Subtract6' incorporates:
   *  DataStoreRead: '<S2>/Data Store Read'
   */
  ControlLoop_Y.RoverGlobalCoordY = ControlLoop_DW.CurrentGlobalDirection;

  /* Sum: '<S2>/Subtract3' incorporates:
   *  Constant: '<Root>/Wheels distance (inch)'
   *  Constant: '<S2>/Constant B'
   *  DataStoreRead: '<S2>/Data Store Read'
   *  DataStoreWrite: '<S2>/Data Store Write'
   *  Product: '<S2>/Divide'
   *  Product: '<S2>/Divide1'
   *  Sum: '<S2>/Subtract'
   */
  ControlLoop_DW.CurrentGlobalDirection += (ControlLoop_Y.RoverGlobalCoordX +
    rtb_Filter_k) * ControlLoop_P.ConstantB_Value /
    ControlLoop_P.Wheelsdistanceinch_Value;

  /* Product: '<S2>/Divide2' incorporates:
   *  Constant: '<S2>/Constant C'
   *  Gain: '<S2>/TakeAverageSpeed'
   *  Sum: '<S2>/Subtract4'
   */
  rtb_Filter_k = (ControlLoop_Y.RoverGlobalCoordX - rtb_Filter_k) *
    ControlLoop_P.TakeAverageSpeed_Gain * ControlLoop_P.ConstantC_Value;

  /* Sum: '<S2>/Subtract5' incorporates:
   *  DataStoreRead: '<S2>/Data Store Read1'
   *  Product: '<S2>/Divide3'
   *  Trigonometry: '<S2>/Cos'
   */
  ControlLoop_Y.RoverGlobalCoordX = rtb_Filter_k * cos
    (ControlLoop_Y.RoverGlobalCoordY) + ControlLoop_DW.CurrentGlobalCoordinateX;

  /* DataStoreWrite: '<S2>/Data Store Write1' */
  ControlLoop_DW.CurrentGlobalCoordinateX = ControlLoop_Y.RoverGlobalCoordX;

  /* Sum: '<S2>/Subtract6' incorporates:
   *  DataStoreRead: '<S2>/Data Store Read2'
   *  Product: '<S2>/Divide4'
   *  Trigonometry: '<S2>/Sin'
   */
  ControlLoop_Y.RoverGlobalCoordY = rtb_Filter_k * sin
    (ControlLoop_Y.RoverGlobalCoordY) + ControlLoop_DW.CurrentGlobalCoordinateY;

  /* DataStoreWrite: '<S2>/Data Store Write2' */
  ControlLoop_DW.CurrentGlobalCoordinateY = ControlLoop_Y.RoverGlobalCoordY;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Inport: '<Root>/KeepDistanceA_Enable_Bool'
   *  Inport: '<Root>/PurePursuitEnableBool'
   *  Inport: '<Root>/PurePursuitVel'
   *  Switch: '<Root>/Switch'
   */
  if (ControlLoop_U.PurePursuitEnableBool > ControlLoop_P.Switch1_Threshold) {
    rtb_Subtract_d = ControlLoop_U.PurePursuitVel;
  } else if (ControlLoop_U.KeepDistanceA_Enable_Bool >
             ControlLoop_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/DistanceControl_kp'
     *  Inport: '<Root>/DistanceA_command'
     *  Inport: '<Root>/UltrasoundDistanceA'
     *  Product: '<Root>/Multiple'
     *  Sum: '<Root>/Subtract'
     */
    rtb_Subtract_d = (ControlLoop_U.DistanceA_command -
                      ControlLoop_U.UltrasoundDistanceA) *
      ControlLoop_P.DistanceControl_kp_Value;
  } else {
    rtb_Subtract_d = ControlLoop_P.Constant2_Value;
  }

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/Wheel Radius'
   *  Switch: '<Root>/Switch1'
   */
  rtb_Filter_k = rtb_Subtract_d / ControlLoop_P.WheelRadius_Value;

  /* Sum: '<S6>/Subtract' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read2'
   *  Inport: '<Root>/DesiredRoverGlobalDirection'
   */
  rtb_Subtract_d = ControlLoop_U.DesiredRoverGlobalDirection -
    ControlLoop_DW.CurrentGlobalDirection;

  /* Product: '<S151>/NProd Out' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Filter Coefficient'
   *  DiscreteIntegrator: '<S143>/Filter'
   *  Product: '<S141>/DProd Out'
   *  Sum: '<S143>/SumD'
   */
  rtb_NProdOut = (rtb_Subtract_d * ControlLoop_P.Constant2_Value_i -
                  ControlLoop_DW.Filter_DSTATE) *
    ControlLoop_P.FilterCoefficient_Value;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Inport: '<Root>/KeepDistanceA_Enable_Bool'
   *  Inport: '<Root>/PurePursuitEnableBool'
   *  Inport: '<Root>/PurePursuitOmega'
   *  Switch: '<Root>/Switch3'
   */
  if (ControlLoop_U.PurePursuitEnableBool > ControlLoop_P.Switch2_Threshold) {
    rtb_Integrator_e = ControlLoop_U.PurePursuitOmega;
  } else if (ControlLoop_U.KeepDistanceA_Enable_Bool >
             ControlLoop_P.Switch3_Threshold) {
    /* Sum: '<S157>/Sum' incorporates:
     *  Constant: '<S6>/Constant'
     *  DiscreteIntegrator: '<S148>/Integrator'
     *  Product: '<S153>/PProd Out'
     *  Switch: '<Root>/Switch3'
     */
    rtb_Integrator_e = (rtb_Subtract_d * ControlLoop_P.Constant_Value +
                        ControlLoop_DW.Integrator_DSTATE) + rtb_NProdOut;

    /* Saturate: '<S6>/Saturation' incorporates:
     *  Switch: '<Root>/Switch3'
     */
    if (rtb_Integrator_e > ControlLoop_P.Saturation_UpperSat) {
      rtb_Integrator_e = ControlLoop_P.Saturation_UpperSat;
    } else if (rtb_Integrator_e < ControlLoop_P.Saturation_LowerSat) {
      rtb_Integrator_e = ControlLoop_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S6>/Saturation' */
  } else {
    /* Switch: '<Root>/Switch3' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    rtb_Integrator_e = ControlLoop_P.Constant2_Value;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Product: '<S1>/Divide1' incorporates:
   *  Constant: '<Root>/Wheels distance (inch)'
   *  Constant: '<S1>/Wheel Radius'
   *  Gain: '<S1>/Gain'
   *  Product: '<S1>/Multiple'
   */
  rtb_Integrator_e = ControlLoop_P.Gain_Gain *
    ControlLoop_P.Wheelsdistanceinch_Value * rtb_Integrator_e /
    ControlLoop_P.WheelRadius_Value_a;

  /* Sum: '<S4>/Speed Error' incorporates:
   *  Constant: '<S4>/Constant A'
   *  Delay: '<S4>/Delay'
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   *  Product: '<S4>/Divide'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<S4>/Subtract'
   */
  rtb_SpeedError = (rtb_Filter_k + rtb_Integrator_e) -
    (ControlLoop_U.DC_MotorA_Encoder_Counter - ControlLoop_DW.Delay_DSTATE_l) *
    ControlLoop_P.ConstantA_Value;

  /* Product: '<S45>/NProd Out' incorporates:
   *  Constant: '<S4>/Filter Coefficient'
   *  Constant: '<S4>/MotorA_kd'
   *  DiscreteIntegrator: '<S37>/Filter'
   *  Product: '<S35>/DProd Out'
   *  Sum: '<S37>/SumD'
   */
  rtb_NProdOut_e = (rtb_SpeedError * ControlLoop_P.MotorA_kd_Value -
                    ControlLoop_DW.Filter_DSTATE_b) *
    ControlLoop_P.FilterCoefficient_Value_d;

  /* Sum: '<S51>/Sum' incorporates:
   *  Constant: '<Root>/MotorA_kp'
   *  DiscreteIntegrator: '<S42>/Integrator'
   *  Product: '<S47>/PProd Out'
   */
  ControlLoop_Y.DC_MotorA_PWM = (rtb_SpeedError * ControlLoop_P.MotorA_kp_Value
    + ControlLoop_DW.Integrator_DSTATE_h) + rtb_NProdOut_e;

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

  /* Sum: '<S5>/Speed Error' incorporates:
   *  Constant: '<S5>/Constant A'
   *  Delay: '<S5>/Delay'
   *  Gain: '<S3>/Gain'
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   *  Product: '<S5>/Divide'
   *  Sum: '<Root>/Sum3'
   *  Sum: '<S5>/Subtract'
   */
  rtb_Filter_k = (ControlLoop_P.Gain_Gain_o * rtb_Filter_k + rtb_Integrator_e) -
    (ControlLoop_U.DC_MotorB_Encoder_Counter - ControlLoop_DW.Delay_DSTATE_o) *
    ControlLoop_P.ConstantA_Value_o;

  /* Product: '<S98>/NProd Out' incorporates:
   *  Constant: '<S5>/Filter Coefficient'
   *  Constant: '<S5>/MotorA_kd'
   *  DiscreteIntegrator: '<S90>/Filter'
   *  Product: '<S88>/DProd Out'
   *  Sum: '<S90>/SumD'
   */
  rtb_Integrator_e = (rtb_Filter_k * ControlLoop_P.MotorA_kd_Value_j -
                      ControlLoop_DW.Filter_DSTATE_e) *
    ControlLoop_P.FilterCoefficient_Value_g;

  /* Sum: '<S104>/Sum' incorporates:
   *  Constant: '<Root>/MotorB_kp'
   *  DiscreteIntegrator: '<S95>/Integrator'
   *  Product: '<S100>/PProd Out'
   */
  ControlLoop_Y.DC_MotorB_PWM = (rtb_Filter_k * ControlLoop_P.MotorB_kp_Value +
    ControlLoop_DW.Integrator_DSTATE_b) + rtb_Integrator_e;

  /* Saturate: '<S102>/Saturation' */
  if (ControlLoop_Y.DC_MotorB_PWM >
      ControlLoop_P.PIDController_UpperSaturation_p) {
    /* Sum: '<S104>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorB_PWM'
     */
    ControlLoop_Y.DC_MotorB_PWM = ControlLoop_P.PIDController_UpperSaturation_p;
  } else if (ControlLoop_Y.DC_MotorB_PWM <
             ControlLoop_P.PIDController_LowerSaturation_n) {
    /* Sum: '<S104>/Sum' incorporates:
     *  Outport: '<Root>/DC_MotorB_PWM'
     */
    ControlLoop_Y.DC_MotorB_PWM = ControlLoop_P.PIDController_LowerSaturation_n;
  }

  /* End of Saturate: '<S102>/Saturation' */

  /* Outport: '<Root>/DC_MotorA_SpeedFeedback' incorporates:
   *  Constant: '<S4>/Constant A'
   *  Constant: '<S4>/Frequency'
   *  Delay: '<S4>/Delay1'
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   *  Product: '<S4>/Divide1'
   *  Sum: '<S4>/Subtract1'
   */
  ControlLoop_Y.DC_MotorA_SpeedFeedback =
    (ControlLoop_U.DC_MotorA_Encoder_Counter - ControlLoop_DW.Delay1_DSTATE_o[0])
    * ControlLoop_P.ConstantA_Value / ControlLoop_P.Frequency_Value;

  /* Outport: '<Root>/DC_MotorB_SpeedFeedback' incorporates:
   *  Constant: '<S5>/Constant A'
   *  Constant: '<S5>/Frequency'
   *  Delay: '<S5>/Delay1'
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   *  Product: '<S5>/Divide1'
   *  Sum: '<S5>/Subtract1'
   */
  ControlLoop_Y.DC_MotorB_SpeedFeedback =
    (ControlLoop_U.DC_MotorB_Encoder_Counter - ControlLoop_DW.Delay1_DSTATE_b[0])
    * ControlLoop_P.ConstantA_Value_o / ControlLoop_P.Frequency_Value_i;

  /* Outport: '<Root>/RoverGlobalDirection' incorporates:
   *  DataStoreWrite: '<S2>/Data Store Write'
   */
  ControlLoop_Y.RoverGlobalDirection = ControlLoop_DW.CurrentGlobalDirection;

  /* Update for Delay: '<S2>/Delay' incorporates:
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   */
  ControlLoop_DW.Delay_DSTATE = ControlLoop_U.DC_MotorA_Encoder_Counter;

  /* Update for Delay: '<S2>/Delay1' incorporates:
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   */
  ControlLoop_DW.Delay1_DSTATE = ControlLoop_U.DC_MotorB_Encoder_Counter;

  /* Update for DiscreteIntegrator: '<S148>/Integrator' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Product: '<S145>/IProd Out'
   */
  ControlLoop_DW.Integrator_DSTATE += rtb_Subtract_d *
    ControlLoop_P.Constant1_Value * ControlLoop_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S143>/Filter' */
  ControlLoop_DW.Filter_DSTATE += ControlLoop_P.Filter_gainval * rtb_NProdOut;

  /* Update for Delay: '<S4>/Delay' incorporates:
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   */
  ControlLoop_DW.Delay_DSTATE_l = ControlLoop_U.DC_MotorA_Encoder_Counter;

  /* Update for DiscreteIntegrator: '<S42>/Integrator' incorporates:
   *  Constant: '<Root>/MotorA_ki'
   *  Product: '<S39>/IProd Out'
   */
  ControlLoop_DW.Integrator_DSTATE_h += rtb_SpeedError *
    ControlLoop_P.MotorA_ki_Value * ControlLoop_P.Integrator_gainval_l;

  /* Update for DiscreteIntegrator: '<S37>/Filter' */
  ControlLoop_DW.Filter_DSTATE_b += ControlLoop_P.Filter_gainval_d *
    rtb_NProdOut_e;

  /* Update for Delay: '<S5>/Delay' incorporates:
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   */
  ControlLoop_DW.Delay_DSTATE_o = ControlLoop_U.DC_MotorB_Encoder_Counter;

  /* Update for DiscreteIntegrator: '<S95>/Integrator' incorporates:
   *  Constant: '<Root>/MotorB_ki'
   *  Product: '<S92>/IProd Out'
   */
  ControlLoop_DW.Integrator_DSTATE_b += rtb_Filter_k *
    ControlLoop_P.MotorB_ki_Value * ControlLoop_P.Integrator_gainval_m;

  /* Update for DiscreteIntegrator: '<S90>/Filter' */
  ControlLoop_DW.Filter_DSTATE_e += ControlLoop_P.Filter_gainval_e *
    rtb_Integrator_e;
  for (idxDelay = 0; idxDelay < 19; idxDelay++) {
    /* Update for Delay: '<S4>/Delay1' */
    ControlLoop_DW.Delay1_DSTATE_o[idxDelay] =
      ControlLoop_DW.Delay1_DSTATE_o[idxDelay + 1];

    /* Update for Delay: '<S5>/Delay1' */
    ControlLoop_DW.Delay1_DSTATE_b[idxDelay] =
      ControlLoop_DW.Delay1_DSTATE_b[idxDelay + 1];
  }

  /* Update for Delay: '<S4>/Delay1' incorporates:
   *  Inport: '<Root>/DC_MotorA_Encoder_Counter'
   */
  ControlLoop_DW.Delay1_DSTATE_o[19] = ControlLoop_U.DC_MotorA_Encoder_Counter;

  /* Update for Delay: '<S5>/Delay1' incorporates:
   *  Inport: '<Root>/DC_MotorB_Encoder_Counter'
   */
  ControlLoop_DW.Delay1_DSTATE_b[19] = ControlLoop_U.DC_MotorB_Encoder_Counter;
}

/* Model initialize function */
void ControlLoop_initialize(void)
{
  {
    int32_T i;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    ControlLoop_DW.CurrentGlobalDirection =
      ControlLoop_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    ControlLoop_DW.CurrentGlobalCoordinateX =
      ControlLoop_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    ControlLoop_DW.CurrentGlobalCoordinateY =
      ControlLoop_P.DataStoreMemory2_InitialValue;

    /* InitializeConditions for Delay: '<S2>/Delay' */
    ControlLoop_DW.Delay_DSTATE = ControlLoop_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S2>/Delay1' */
    ControlLoop_DW.Delay1_DSTATE = ControlLoop_P.Delay1_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S148>/Integrator' */
    ControlLoop_DW.Integrator_DSTATE =
      ControlLoop_P.PIDController_InitialConditio_j;

    /* InitializeConditions for DiscreteIntegrator: '<S143>/Filter' */
    ControlLoop_DW.Filter_DSTATE = ControlLoop_P.PIDController_InitialConditionF;

    /* InitializeConditions for Delay: '<S4>/Delay' */
    ControlLoop_DW.Delay_DSTATE_l = ControlLoop_P.Delay_InitialCondition_g;

    /* InitializeConditions for DiscreteIntegrator: '<S42>/Integrator' */
    ControlLoop_DW.Integrator_DSTATE_h =
      ControlLoop_P.PIDController_InitialConditio_l;

    /* InitializeConditions for DiscreteIntegrator: '<S37>/Filter' */
    ControlLoop_DW.Filter_DSTATE_b =
      ControlLoop_P.PIDController_InitialConditio_i;

    /* InitializeConditions for Delay: '<S5>/Delay' */
    ControlLoop_DW.Delay_DSTATE_o = ControlLoop_P.Delay_InitialCondition_n;

    /* InitializeConditions for DiscreteIntegrator: '<S95>/Integrator' */
    ControlLoop_DW.Integrator_DSTATE_b =
      ControlLoop_P.PIDController_InitialConditio_n;

    /* InitializeConditions for DiscreteIntegrator: '<S90>/Filter' */
    ControlLoop_DW.Filter_DSTATE_e =
      ControlLoop_P.PIDController_InitialConditio_b;
    for (i = 0; i < 20; i++) {
      /* InitializeConditions for Delay: '<S4>/Delay1' */
      ControlLoop_DW.Delay1_DSTATE_o[i] =
        ControlLoop_P.Delay1_InitialCondition_l;

      /* InitializeConditions for Delay: '<S5>/Delay1' */
      ControlLoop_DW.Delay1_DSTATE_b[i] =
        ControlLoop_P.Delay1_InitialCondition_g;
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
