/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop.h
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
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  real_T Delay1_DSTATE;                /* '<S1>/Delay1' */
  real_T Integrator_DSTATE;            /* '<S39>/Integrator' */
  real_T Filter_DSTATE;                /* '<S34>/Filter' */
  real_T Delay_DSTATE_l;               /* '<S3>/Delay' */
  real_T Integrator_DSTATE_h;          /* '<S90>/Integrator' */
  real_T Filter_DSTATE_b;              /* '<S85>/Filter' */
  real_T Delay_DSTATE_l1;              /* '<S4>/Delay' */
  real_T Integrator_DSTATE_e;          /* '<S141>/Integrator' */
  real_T Filter_DSTATE_c;              /* '<S136>/Filter' */
  real_T Delay1_DSTATE_o[20];          /* '<S3>/Delay1' */
  real_T Delay1_DSTATE_m[20];          /* '<S4>/Delay1' */
  real_T CurrentGlobalDirection;       /* '<Root>/Data Store Memory' */
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
  real_T DesiredRoverGlobalDirection; /* '<Root>/DesiredRoverGlobalDirection' */
} ExtU_ControlLoop_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T DC_MotorA_PWM;                /* '<Root>/DC_MotorA_PWM' */
  real_T DC_MotorB_PWM;                /* '<Root>/DC_MotorB_PWM' */
  real_T DC_MotorA_SpeedFeedback;      /* '<Root>/DC_MotorA_SpeedFeedback' */
  real_T DC_MotorB_SpeedFeedback;      /* '<Root>/DC_MotorB_SpeedFeedback' */
  real_T RoverGlobalDirection;         /* '<Root>/RoverGlobalDirection' */
} ExtY_ControlLoop_T;

/* Parameters (default storage) */
struct P_ControlLoop_T_ {
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S34>/Filter'
                               */
  real_T PIDController_InitialConditio_i;
                              /* Mask Parameter: PIDController_InitialConditio_i
                               * Referenced by: '<S85>/Filter'
                               */
  real_T PIDController_InitialConditio_a;
                              /* Mask Parameter: PIDController_InitialConditio_a
                               * Referenced by: '<S136>/Filter'
                               */
  real_T PIDController_InitialConditio_j;
                              /* Mask Parameter: PIDController_InitialConditio_j
                               * Referenced by: '<S39>/Integrator'
                               */
  real_T PIDController_InitialConditio_l;
                              /* Mask Parameter: PIDController_InitialConditio_l
                               * Referenced by: '<S90>/Integrator'
                               */
  real_T PIDController_InitialConditi_jq;
                              /* Mask Parameter: PIDController_InitialConditi_jq
                               * Referenced by: '<S141>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S97>/Saturation'
                               */
  real_T PIDController_LowerSaturation_f;
                              /* Mask Parameter: PIDController_LowerSaturation_f
                               * Referenced by: '<S148>/Saturation'
                               */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S97>/Saturation'
                               */
  real_T PIDController_UpperSaturation_e;
                              /* Mask Parameter: PIDController_UpperSaturation_e
                               * Referenced by: '<S148>/Saturation'
                               */
  real_T Speed_FF_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Speed_FF'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay1'
                                        */
  real_T ConstantB_Value;              /* Expression: 0.02618
                                        * Referenced by: '<S1>/Constant B'
                                        */
  real_T Wheelsdistanceinch_Value;     /* Expression: 12.65
                                        * Referenced by: '<Root>/Wheels distance (inch)'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S39>/Integrator'
                                        */
  real_T Constant2_Value_l;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S34>/Filter'
                                        */
  real_T FilterCoefficient_Value;      /* Expression: 100
                                        * Referenced by: '<S2>/Filter Coefficient'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 2
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -2
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Delay_InitialCondition_g;     /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T ConstantA_Value;              /* Expression: 3.49066
                                        * Referenced by: '<S3>/Constant A'
                                        */
  real_T MotorA_kp_Value;              /* Expression: 0.12
                                        * Referenced by: '<Root>/MotorA_kp'
                                        */
  real_T Integrator_gainval_l;       /* Computed Parameter: Integrator_gainval_l
                                      * Referenced by: '<S90>/Integrator'
                                      */
  real_T MotorA_kd_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/MotorA_kd'
                                        */
  real_T Filter_gainval_d;             /* Computed Parameter: Filter_gainval_d
                                        * Referenced by: '<S85>/Filter'
                                        */
  real_T FilterCoefficient_Value_d;    /* Expression: 100
                                        * Referenced by: '<S3>/Filter Coefficient'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Delay_InitialCondition_p;     /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay'
                                        */
  real_T ConstantA_Value_b;            /* Expression: 3.49066
                                        * Referenced by: '<S4>/Constant A'
                                        */
  real_T MotorB_kp_Value;              /* Expression: 0.12
                                        * Referenced by: '<Root>/MotorB_kp'
                                        */
  real_T Integrator_gainval_h;       /* Computed Parameter: Integrator_gainval_h
                                      * Referenced by: '<S141>/Integrator'
                                      */
  real_T Motor_kd_Value;               /* Expression: 0
                                        * Referenced by: '<S4>/Motor_kd'
                                        */
  real_T Filter_gainval_b;             /* Computed Parameter: Filter_gainval_b
                                        * Referenced by: '<S136>/Filter'
                                        */
  real_T FilterCoefficient_Value_p;    /* Expression: 100
                                        * Referenced by: '<S4>/Filter Coefficient'
                                        */
  real_T Delay1_InitialCondition_l;    /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay1'
                                        */
  real_T Frequency_Value;              /* Expression: 20
                                        * Referenced by: '<S3>/Frequency'
                                        */
  real_T Delay1_InitialCondition_lq;   /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay1'
                                        */
  real_T Frequency_Value_f;            /* Expression: 20
                                        * Referenced by: '<S4>/Frequency'
                                        */
  real_T MotorA_ki_Value;              /* Expression: 0.35
                                        * Referenced by: '<Root>/MotorA_ki'
                                        */
  real_T MotorB_ki_Value;              /* Expression: 0.35
                                        * Referenced by: '<Root>/MotorB_ki'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory'
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
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/DistanceControl_kp' : Unused code path elimination
 */

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
 * '<S1>'   : 'ControlLoop/Global Direction Calculation'
 * '<S2>'   : 'ControlLoop/Rover Steering'
 * '<S3>'   : 'ControlLoop/Velocity Control Loop Motor A'
 * '<S4>'   : 'ControlLoop/Velocity Control Loop Motor B'
 * '<S5>'   : 'ControlLoop/Rover Steering/PID Controller'
 * '<S6>'   : 'ControlLoop/Rover Steering/PID Controller/Anti-windup'
 * '<S7>'   : 'ControlLoop/Rover Steering/PID Controller/D Gain'
 * '<S8>'   : 'ControlLoop/Rover Steering/PID Controller/External Derivative'
 * '<S9>'   : 'ControlLoop/Rover Steering/PID Controller/Filter'
 * '<S10>'  : 'ControlLoop/Rover Steering/PID Controller/Filter ICs'
 * '<S11>'  : 'ControlLoop/Rover Steering/PID Controller/I Gain'
 * '<S12>'  : 'ControlLoop/Rover Steering/PID Controller/Ideal P Gain'
 * '<S13>'  : 'ControlLoop/Rover Steering/PID Controller/Ideal P Gain Fdbk'
 * '<S14>'  : 'ControlLoop/Rover Steering/PID Controller/Integrator'
 * '<S15>'  : 'ControlLoop/Rover Steering/PID Controller/Integrator ICs'
 * '<S16>'  : 'ControlLoop/Rover Steering/PID Controller/N Copy'
 * '<S17>'  : 'ControlLoop/Rover Steering/PID Controller/N Gain'
 * '<S18>'  : 'ControlLoop/Rover Steering/PID Controller/P Copy'
 * '<S19>'  : 'ControlLoop/Rover Steering/PID Controller/Parallel P Gain'
 * '<S20>'  : 'ControlLoop/Rover Steering/PID Controller/Reset Signal'
 * '<S21>'  : 'ControlLoop/Rover Steering/PID Controller/Saturation'
 * '<S22>'  : 'ControlLoop/Rover Steering/PID Controller/Saturation Fdbk'
 * '<S23>'  : 'ControlLoop/Rover Steering/PID Controller/Sum'
 * '<S24>'  : 'ControlLoop/Rover Steering/PID Controller/Sum Fdbk'
 * '<S25>'  : 'ControlLoop/Rover Steering/PID Controller/Tracking Mode'
 * '<S26>'  : 'ControlLoop/Rover Steering/PID Controller/Tracking Mode Sum'
 * '<S27>'  : 'ControlLoop/Rover Steering/PID Controller/Tsamp - Integral'
 * '<S28>'  : 'ControlLoop/Rover Steering/PID Controller/Tsamp - Ngain'
 * '<S29>'  : 'ControlLoop/Rover Steering/PID Controller/postSat Signal'
 * '<S30>'  : 'ControlLoop/Rover Steering/PID Controller/preSat Signal'
 * '<S31>'  : 'ControlLoop/Rover Steering/PID Controller/Anti-windup/Passthrough'
 * '<S32>'  : 'ControlLoop/Rover Steering/PID Controller/D Gain/External Parameters'
 * '<S33>'  : 'ControlLoop/Rover Steering/PID Controller/External Derivative/Error'
 * '<S34>'  : 'ControlLoop/Rover Steering/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S35>'  : 'ControlLoop/Rover Steering/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S36>'  : 'ControlLoop/Rover Steering/PID Controller/I Gain/External Parameters'
 * '<S37>'  : 'ControlLoop/Rover Steering/PID Controller/Ideal P Gain/Passthrough'
 * '<S38>'  : 'ControlLoop/Rover Steering/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S39>'  : 'ControlLoop/Rover Steering/PID Controller/Integrator/Discrete'
 * '<S40>'  : 'ControlLoop/Rover Steering/PID Controller/Integrator ICs/Internal IC'
 * '<S41>'  : 'ControlLoop/Rover Steering/PID Controller/N Copy/Disabled'
 * '<S42>'  : 'ControlLoop/Rover Steering/PID Controller/N Gain/External Parameters'
 * '<S43>'  : 'ControlLoop/Rover Steering/PID Controller/P Copy/Disabled'
 * '<S44>'  : 'ControlLoop/Rover Steering/PID Controller/Parallel P Gain/External Parameters'
 * '<S45>'  : 'ControlLoop/Rover Steering/PID Controller/Reset Signal/Disabled'
 * '<S46>'  : 'ControlLoop/Rover Steering/PID Controller/Saturation/Passthrough'
 * '<S47>'  : 'ControlLoop/Rover Steering/PID Controller/Saturation Fdbk/Disabled'
 * '<S48>'  : 'ControlLoop/Rover Steering/PID Controller/Sum/Sum_PID'
 * '<S49>'  : 'ControlLoop/Rover Steering/PID Controller/Sum Fdbk/Disabled'
 * '<S50>'  : 'ControlLoop/Rover Steering/PID Controller/Tracking Mode/Disabled'
 * '<S51>'  : 'ControlLoop/Rover Steering/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'ControlLoop/Rover Steering/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S53>'  : 'ControlLoop/Rover Steering/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'ControlLoop/Rover Steering/PID Controller/postSat Signal/Forward_Path'
 * '<S55>'  : 'ControlLoop/Rover Steering/PID Controller/preSat Signal/Forward_Path'
 * '<S56>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller'
 * '<S57>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Anti-windup'
 * '<S58>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/D Gain'
 * '<S59>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/External Derivative'
 * '<S60>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter'
 * '<S61>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter ICs'
 * '<S62>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/I Gain'
 * '<S63>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain'
 * '<S64>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain Fdbk'
 * '<S65>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator'
 * '<S66>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator ICs'
 * '<S67>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Copy'
 * '<S68>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Gain'
 * '<S69>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/P Copy'
 * '<S70>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Parallel P Gain'
 * '<S71>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Reset Signal'
 * '<S72>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation'
 * '<S73>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation Fdbk'
 * '<S74>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum'
 * '<S75>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum Fdbk'
 * '<S76>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode'
 * '<S77>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode Sum'
 * '<S78>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Integral'
 * '<S79>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Ngain'
 * '<S80>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/postSat Signal'
 * '<S81>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/preSat Signal'
 * '<S82>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Anti-windup/Passthrough'
 * '<S83>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/D Gain/External Parameters'
 * '<S84>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/External Derivative/Error'
 * '<S85>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S86>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S87>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/I Gain/External Parameters'
 * '<S88>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain/Passthrough'
 * '<S89>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S90>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator/Discrete'
 * '<S91>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator ICs/Internal IC'
 * '<S92>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Copy/Disabled'
 * '<S93>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Gain/External Parameters'
 * '<S94>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/P Copy/Disabled'
 * '<S95>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Parallel P Gain/External Parameters'
 * '<S96>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Reset Signal/Disabled'
 * '<S97>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation/Enabled'
 * '<S98>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation Fdbk/Disabled'
 * '<S99>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum/Sum_PID'
 * '<S100>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum Fdbk/Disabled'
 * '<S101>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode/Disabled'
 * '<S102>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S103>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S104>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S105>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/postSat Signal/Forward_Path'
 * '<S106>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/preSat Signal/Forward_Path'
 * '<S107>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller'
 * '<S108>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Anti-windup'
 * '<S109>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/D Gain'
 * '<S110>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/External Derivative'
 * '<S111>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter'
 * '<S112>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter ICs'
 * '<S113>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/I Gain'
 * '<S114>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain'
 * '<S115>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain Fdbk'
 * '<S116>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator'
 * '<S117>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator ICs'
 * '<S118>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Copy'
 * '<S119>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Gain'
 * '<S120>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/P Copy'
 * '<S121>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Parallel P Gain'
 * '<S122>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Reset Signal'
 * '<S123>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation'
 * '<S124>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation Fdbk'
 * '<S125>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum'
 * '<S126>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum Fdbk'
 * '<S127>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode'
 * '<S128>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode Sum'
 * '<S129>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Integral'
 * '<S130>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Ngain'
 * '<S131>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/postSat Signal'
 * '<S132>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/preSat Signal'
 * '<S133>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Anti-windup/Passthrough'
 * '<S134>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/D Gain/External Parameters'
 * '<S135>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/External Derivative/Error'
 * '<S136>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S137>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S138>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/I Gain/External Parameters'
 * '<S139>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain/Passthrough'
 * '<S140>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S141>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator/Discrete'
 * '<S142>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator ICs/Internal IC'
 * '<S143>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Copy/Disabled'
 * '<S144>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Gain/External Parameters'
 * '<S145>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/P Copy/Disabled'
 * '<S146>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Parallel P Gain/External Parameters'
 * '<S147>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Reset Signal/Disabled'
 * '<S148>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation/Enabled'
 * '<S149>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation Fdbk/Disabled'
 * '<S150>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum/Sum_PID'
 * '<S151>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum Fdbk/Disabled'
 * '<S152>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode/Disabled'
 * '<S153>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S154>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S155>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S156>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/postSat Signal/Forward_Path'
 * '<S157>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* ControlLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
