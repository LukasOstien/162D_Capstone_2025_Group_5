/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop.h
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

#ifndef ControlLoop_h_
#define ControlLoop_h_
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

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE[20];            /* '<S2>/Delay1' */
  real_T Delay1_DSTATE_m[20];          /* '<S3>/Delay1' */
  real_T Delay_DSTATE;                 /* '<S2>/Delay' */
  real_T Integrator_DSTATE;            /* '<S38>/Integrator' */
  real_T Filter_DSTATE;                /* '<S33>/Filter' */
  real_T Delay_DSTATE_l;               /* '<S3>/Delay' */
  real_T Integrator_DSTATE_e;          /* '<S89>/Integrator' */
  real_T Filter_DSTATE_c;              /* '<S84>/Filter' */
} DW_ControlLoop_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T DC_MotorA_Encoder_Counter;    /* '<Root>/DC_MotorA_Encoder_Counter' */
  real_T DC_MotorB_Encoder_Counter;    /* '<Root>/DC_MotorB_Encoder_Counter' */
  real_T DC_MotorA_SpeedCommand;       /* '<Root>/DC_MotorA_SpeedCommand' */
  real_T DC_MotorB_SpeedCommand;       /* '<Root>/DC_MotorB_SpeedCommand' */
  real_T UltrasoundDistanceA;          /* '<Root>/UltrasoundDistanceA' */
  real_T DistanceA_command;            /* '<Root>/DistanceA_command' */
  real_T KeepDistanceA_Enable_Bool;    /* '<Root>/KeepDistanceA_Enable_Bool' */
} ExtU_ControlLoop_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T DC_MotorA_PWM;                /* '<Root>/DC_MotorA_PWM' */
  real_T DC_MotorB_PWM;                /* '<Root>/DC_MotorB_PWM' */
  real_T ServoMotorA_PWM;              /* '<Root>/ServoMotorA_PWM' */
  real_T ServoMotorB_PWM;              /* '<Root>/ServoMotorB_PWM' */
  real_T ServoMotorC_PWM;              /* '<Root>/ServoMotorC_PWM' */
  real_T DC_MotorA_SpeedFeedback;      /* '<Root>/DC_MotorA_SpeedFeedback' */
  real_T DC_MotorB_SpeedFeedback;      /* '<Root>/DC_MotorB_SpeedFeedback' */
} ExtY_ControlLoop_T;

/* Parameters (default storage) */
struct P_ControlLoop_T_ {
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S33>/Filter'
                               */
  real_T PIDController_InitialConditio_a;
                              /* Mask Parameter: PIDController_InitialConditio_a
                               * Referenced by: '<S84>/Filter'
                               */
  real_T PIDController_InitialConditio_l;
                              /* Mask Parameter: PIDController_InitialConditio_l
                               * Referenced by: '<S38>/Integrator'
                               */
  real_T PIDController_InitialConditio_j;
                              /* Mask Parameter: PIDController_InitialConditio_j
                               * Referenced by: '<S89>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S45>/Saturation'
                               */
  real_T PIDController_LowerSaturation_f;
                              /* Mask Parameter: PIDController_LowerSaturation_f
                               * Referenced by: '<S96>/Saturation'
                               */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S45>/Saturation'
                               */
  real_T PIDController_UpperSaturation_e;
                              /* Mask Parameter: PIDController_UpperSaturation_e
                               * Referenced by: '<S96>/Saturation'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S1>/Switch3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S1>/Switch1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S1>/Switch2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay1'
                                        */
  real_T ConstantA_Value;              /* Expression: 3.49066
                                        * Referenced by: '<S2>/Constant A'
                                        */
  real_T Frequency_Value;              /* Expression: 20
                                        * Referenced by: '<S2>/Frequency'
                                        */
  real_T Delay1_InitialCondition_l;    /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay1'
                                        */
  real_T ConstantA_Value_b;            /* Expression: 3.49066
                                        * Referenced by: '<S3>/Constant A'
                                        */
  real_T Frequency_Value_f;            /* Expression: 20
                                        * Referenced by: '<S3>/Frequency'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T DistanceControl_kp_Value;     /* Expression: 0.1
                                        * Referenced by: '<Root>/DistanceControl_kp'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay'
                                        */
  real_T MotorA_kp_Value;              /* Expression: 0.11
                                        * Referenced by: '<Root>/MotorA_kp'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S38>/Integrator'
                                        */
  real_T MotorA_kd_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/MotorA_kd'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S33>/Filter'
                                        */
  real_T FilterCoefficient_Value;      /* Expression: 100
                                        * Referenced by: '<S2>/Filter Coefficient'
                                        */
  real_T MotorA_ki_Value;              /* Expression: 0.4
                                        * Referenced by: '<Root>/MotorA_ki'
                                        */
  real_T Switch1_Threshold_i;          /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Delay_InitialCondition_p;     /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T MotorB_kp_Value;              /* Expression: 0.11
                                        * Referenced by: '<Root>/MotorB_kp'
                                        */
  real_T Integrator_gainval_h;       /* Computed Parameter: Integrator_gainval_h
                                      * Referenced by: '<S89>/Integrator'
                                      */
  real_T Motor_kd_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/Motor_kd'
                                        */
  real_T Filter_gainval_b;             /* Computed Parameter: Filter_gainval_b
                                        * Referenced by: '<S84>/Filter'
                                        */
  real_T FilterCoefficient_Value_p;    /* Expression: 100
                                        * Referenced by: '<S3>/Filter Coefficient'
                                        */
  real_T MotorB_ki_Value;              /* Expression: 0.4
                                        * Referenced by: '<Root>/MotorB_ki'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ControlLoop_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_ControlLoop_T ControlLoop_P;

/* Block states (default storage) */
extern DW_ControlLoop_T ControlLoop_DW;

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
 * '<S1>'   : 'ControlLoop/Adaptive Cruise Control Logic'
 * '<S2>'   : 'ControlLoop/Velocity Control Loop Motor A'
 * '<S3>'   : 'ControlLoop/Velocity Control Loop Motor B'
 * '<S4>'   : 'ControlLoop/Velocity Control Loop Motor A/PID Controller'
 * '<S5>'   : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Anti-windup'
 * '<S6>'   : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/D Gain'
 * '<S7>'   : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/External Derivative'
 * '<S8>'   : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter'
 * '<S9>'   : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter ICs'
 * '<S10>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/I Gain'
 * '<S11>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain'
 * '<S12>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain Fdbk'
 * '<S13>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator'
 * '<S14>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator ICs'
 * '<S15>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Copy'
 * '<S16>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Gain'
 * '<S17>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/P Copy'
 * '<S18>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Parallel P Gain'
 * '<S19>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Reset Signal'
 * '<S20>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation'
 * '<S21>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation Fdbk'
 * '<S22>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum'
 * '<S23>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum Fdbk'
 * '<S24>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode'
 * '<S25>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode Sum'
 * '<S26>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Integral'
 * '<S27>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Ngain'
 * '<S28>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/postSat Signal'
 * '<S29>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/preSat Signal'
 * '<S30>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Anti-windup/Passthrough'
 * '<S31>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/D Gain/External Parameters'
 * '<S32>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/External Derivative/Error'
 * '<S33>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S34>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S35>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/I Gain/External Parameters'
 * '<S36>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain/Passthrough'
 * '<S37>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator/Discrete'
 * '<S39>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator ICs/Internal IC'
 * '<S40>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Copy/Disabled'
 * '<S41>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Gain/External Parameters'
 * '<S42>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/P Copy/Disabled'
 * '<S43>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Parallel P Gain/External Parameters'
 * '<S44>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Reset Signal/Disabled'
 * '<S45>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation/Enabled'
 * '<S46>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation Fdbk/Disabled'
 * '<S47>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum/Sum_PID'
 * '<S48>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum Fdbk/Disabled'
 * '<S49>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode/Disabled'
 * '<S50>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S52>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/postSat Signal/Forward_Path'
 * '<S54>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/preSat Signal/Forward_Path'
 * '<S55>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller'
 * '<S56>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Anti-windup'
 * '<S57>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/D Gain'
 * '<S58>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/External Derivative'
 * '<S59>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter'
 * '<S60>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter ICs'
 * '<S61>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/I Gain'
 * '<S62>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain'
 * '<S63>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain Fdbk'
 * '<S64>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator'
 * '<S65>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator ICs'
 * '<S66>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Copy'
 * '<S67>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Gain'
 * '<S68>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/P Copy'
 * '<S69>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Parallel P Gain'
 * '<S70>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Reset Signal'
 * '<S71>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation'
 * '<S72>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation Fdbk'
 * '<S73>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum'
 * '<S74>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum Fdbk'
 * '<S75>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode'
 * '<S76>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode Sum'
 * '<S77>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Integral'
 * '<S78>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Ngain'
 * '<S79>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/postSat Signal'
 * '<S80>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/preSat Signal'
 * '<S81>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Anti-windup/Passthrough'
 * '<S82>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/D Gain/External Parameters'
 * '<S83>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/External Derivative/Error'
 * '<S84>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S85>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S86>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/I Gain/External Parameters'
 * '<S87>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain/Passthrough'
 * '<S88>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S89>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator/Discrete'
 * '<S90>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator ICs/Internal IC'
 * '<S91>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Copy/Disabled'
 * '<S92>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Gain/External Parameters'
 * '<S93>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/P Copy/Disabled'
 * '<S94>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Parallel P Gain/External Parameters'
 * '<S95>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Reset Signal/Disabled'
 * '<S96>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation/Enabled'
 * '<S97>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation Fdbk/Disabled'
 * '<S98>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum/Sum_PID'
 * '<S99>'  : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum Fdbk/Disabled'
 * '<S100>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode/Disabled'
 * '<S101>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S102>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S103>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S104>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/postSat Signal/Forward_Path'
 * '<S105>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* ControlLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
