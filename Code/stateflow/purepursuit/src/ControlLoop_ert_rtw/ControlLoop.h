/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop.h
 *
 * Code generated for Simulink model 'ControlLoop'.
 *
 * Model version                  : 5.5
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Apr 22 17:53:52 2025
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
#include "math.h"
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
  real_T Integrator_DSTATE;            /* '<S42>/Integrator' */
  real_T Filter_DSTATE;                /* '<S37>/Filter' */
  real_T Delay_DSTATE_l;               /* '<S5>/Delay' */
  real_T Integrator_DSTATE_h;          /* '<S95>/Integrator' */
  real_T Filter_DSTATE_b;              /* '<S90>/Filter' */
  real_T Delay_DSTATE_l1;              /* '<S6>/Delay' */
  real_T Integrator_DSTATE_e;          /* '<S148>/Integrator' */
  real_T Filter_DSTATE_c;              /* '<S143>/Filter' */
  real_T Delay1_DSTATE_o[20];          /* '<S5>/Delay1' */
  real_T Delay1_DSTATE_m[20];          /* '<S6>/Delay1' */
  real_T CurrentGlobalDirection;       /* '<Root>/Data Store Memory' */
  real_T CurrentGlobalCoordinateX;     /* '<Root>/Data Store Memory1' */
  real_T CurrentGlobalCoordinateY;     /* '<Root>/Data Store Memory2' */
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
  real_T PurePursuitVel;               /* '<Root>/PurePursuitVel' */
  real_T PurePursuitOmega;             /* '<Root>/PurePursuitOmega' */
  real_T PurePursuitEnableBool;        /* '<Root>/PurePursuitEnableBool' */
} ExtU_ControlLoop_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T DC_MotorA_PWM;                /* '<Root>/DC_MotorA_PWM' */
  real_T DC_MotorB_PWM;                /* '<Root>/DC_MotorB_PWM' */
  real_T DC_MotorA_SpeedFeedback;      /* '<Root>/DC_MotorA_SpeedFeedback' */
  real_T DC_MotorB_SpeedFeedback;      /* '<Root>/DC_MotorB_SpeedFeedback' */
  real_T RoverGlobalDirection;         /* '<Root>/RoverGlobalDirection' */
  real_T RoverGlobalCoordX;            /* '<Root>/RoverGlobalCoordX' */
  real_T RoverGlobalCoordY;            /* '<Root>/RoverGlobalCoordY' */
} ExtY_ControlLoop_T;

/* Parameters (default storage) */
struct P_ControlLoop_T_ {
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S37>/Filter'
                               */
  real_T PIDController_InitialConditio_i;
                              /* Mask Parameter: PIDController_InitialConditio_i
                               * Referenced by: '<S90>/Filter'
                               */
  real_T PIDController_InitialConditio_a;
                              /* Mask Parameter: PIDController_InitialConditio_a
                               * Referenced by: '<S143>/Filter'
                               */
  real_T PIDController_InitialConditio_j;
                              /* Mask Parameter: PIDController_InitialConditio_j
                               * Referenced by: '<S42>/Integrator'
                               */
  real_T PIDController_InitialConditio_l;
                              /* Mask Parameter: PIDController_InitialConditio_l
                               * Referenced by: '<S95>/Integrator'
                               */
  real_T PIDController_InitialConditi_jq;
                              /* Mask Parameter: PIDController_InitialConditi_jq
                               * Referenced by: '<S148>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S102>/Saturation'
                               */
  real_T PIDController_LowerSaturation_f;
                              /* Mask Parameter: PIDController_LowerSaturation_f
                               * Referenced by: '<S155>/Saturation'
                               */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S102>/Saturation'
                               */
  real_T PIDController_UpperSaturation_e;
                              /* Mask Parameter: PIDController_UpperSaturation_e
                               * Referenced by: '<S155>/Saturation'
                               */
  real_T DistanceControl_kp_Value;     /* Expression: 0.3
                                        * Referenced by: '<Root>/DistanceControl_kp'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 20
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -4
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch3'
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
  real_T TakeAverageSpeed_Gain;        /* Expression: 0.5
                                        * Referenced by: '<S1>/TakeAverageSpeed'
                                        */
  real_T ConstantC_Value;              /* Expression: 0.02618
                                        * Referenced by: '<S1>/Constant C'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T WheelRadius_Value;            /* Expression: 3
                                        * Referenced by: '<S4>/Wheel Radius'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S42>/Integrator'
                                        */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S37>/Filter'
                                        */
  real_T FilterCoefficient_Value;      /* Expression: 100
                                        * Referenced by: '<S3>/Filter Coefficient'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch2'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T WheelRadius_Value_a;          /* Expression: 3
                                        * Referenced by: '<S2>/Wheel Radius'
                                        */
  real_T Delay_InitialCondition_g;     /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay'
                                        */
  real_T ConstantA_Value;              /* Expression: 3.49066
                                        * Referenced by: '<S5>/Constant A'
                                        */
  real_T MotorA_kp_Value;              /* Expression: 0.12
                                        * Referenced by: '<Root>/MotorA_kp'
                                        */
  real_T Integrator_gainval_l;       /* Computed Parameter: Integrator_gainval_l
                                      * Referenced by: '<S95>/Integrator'
                                      */
  real_T MotorA_kd_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/MotorA_kd'
                                        */
  real_T Filter_gainval_d;             /* Computed Parameter: Filter_gainval_d
                                        * Referenced by: '<S90>/Filter'
                                        */
  real_T FilterCoefficient_Value_d;    /* Expression: 100
                                        * Referenced by: '<S5>/Filter Coefficient'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -1
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Delay_InitialCondition_p;     /* Expression: 0.0
                                        * Referenced by: '<S6>/Delay'
                                        */
  real_T ConstantA_Value_b;            /* Expression: 3.49066
                                        * Referenced by: '<S6>/Constant A'
                                        */
  real_T MotorB_kp_Value;              /* Expression: 0.12
                                        * Referenced by: '<Root>/MotorB_kp'
                                        */
  real_T Integrator_gainval_h;       /* Computed Parameter: Integrator_gainval_h
                                      * Referenced by: '<S148>/Integrator'
                                      */
  real_T Motor_kd_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/Motor_kd'
                                        */
  real_T Filter_gainval_b;             /* Computed Parameter: Filter_gainval_b
                                        * Referenced by: '<S143>/Filter'
                                        */
  real_T FilterCoefficient_Value_p;    /* Expression: 100
                                        * Referenced by: '<S6>/Filter Coefficient'
                                        */
  real_T Delay1_InitialCondition_l;    /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay1'
                                        */
  real_T Frequency_Value;              /* Expression: 20
                                        * Referenced by: '<S5>/Frequency'
                                        */
  real_T Delay1_InitialCondition_lq;   /* Expression: 0.0
                                        * Referenced by: '<S6>/Delay1'
                                        */
  real_T Frequency_Value_f;            /* Expression: 20
                                        * Referenced by: '<S6>/Frequency'
                                        */
  real_T MotorA_ki_Value;              /* Expression: .3
                                        * Referenced by: '<Root>/MotorA_ki'
                                        */
  real_T MotorB_ki_Value;              /* Expression: .3
                                        * Referenced by: '<Root>/MotorB_ki'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  real_T DataStoreMemory1_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory1'
                                        */
  real_T DataStoreMemory2_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory2'
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
 * '<S1>'   : 'ControlLoop/Global Pos Calculation'
 * '<S2>'   : 'ControlLoop/Rover Angular Velocity To Motor Speeds'
 * '<S3>'   : 'ControlLoop/Rover Steering2'
 * '<S4>'   : 'ControlLoop/Rover Translational Speed To Motor Speeds'
 * '<S5>'   : 'ControlLoop/Velocity Control Loop Motor A'
 * '<S6>'   : 'ControlLoop/Velocity Control Loop Motor B'
 * '<S7>'   : 'ControlLoop/Rover Steering2/PID Controller'
 * '<S8>'   : 'ControlLoop/Rover Steering2/PID Controller/Anti-windup'
 * '<S9>'   : 'ControlLoop/Rover Steering2/PID Controller/D Gain'
 * '<S10>'  : 'ControlLoop/Rover Steering2/PID Controller/External Derivative'
 * '<S11>'  : 'ControlLoop/Rover Steering2/PID Controller/Filter'
 * '<S12>'  : 'ControlLoop/Rover Steering2/PID Controller/Filter ICs'
 * '<S13>'  : 'ControlLoop/Rover Steering2/PID Controller/I Gain'
 * '<S14>'  : 'ControlLoop/Rover Steering2/PID Controller/Ideal P Gain'
 * '<S15>'  : 'ControlLoop/Rover Steering2/PID Controller/Ideal P Gain Fdbk'
 * '<S16>'  : 'ControlLoop/Rover Steering2/PID Controller/Integrator'
 * '<S17>'  : 'ControlLoop/Rover Steering2/PID Controller/Integrator ICs'
 * '<S18>'  : 'ControlLoop/Rover Steering2/PID Controller/N Copy'
 * '<S19>'  : 'ControlLoop/Rover Steering2/PID Controller/N Gain'
 * '<S20>'  : 'ControlLoop/Rover Steering2/PID Controller/P Copy'
 * '<S21>'  : 'ControlLoop/Rover Steering2/PID Controller/Parallel P Gain'
 * '<S22>'  : 'ControlLoop/Rover Steering2/PID Controller/Reset Signal'
 * '<S23>'  : 'ControlLoop/Rover Steering2/PID Controller/Saturation'
 * '<S24>'  : 'ControlLoop/Rover Steering2/PID Controller/Saturation Fdbk'
 * '<S25>'  : 'ControlLoop/Rover Steering2/PID Controller/Sum'
 * '<S26>'  : 'ControlLoop/Rover Steering2/PID Controller/Sum Fdbk'
 * '<S27>'  : 'ControlLoop/Rover Steering2/PID Controller/Tracking Mode'
 * '<S28>'  : 'ControlLoop/Rover Steering2/PID Controller/Tracking Mode Sum'
 * '<S29>'  : 'ControlLoop/Rover Steering2/PID Controller/Tsamp - Integral'
 * '<S30>'  : 'ControlLoop/Rover Steering2/PID Controller/Tsamp - Ngain'
 * '<S31>'  : 'ControlLoop/Rover Steering2/PID Controller/postSat Signal'
 * '<S32>'  : 'ControlLoop/Rover Steering2/PID Controller/preInt Signal'
 * '<S33>'  : 'ControlLoop/Rover Steering2/PID Controller/preSat Signal'
 * '<S34>'  : 'ControlLoop/Rover Steering2/PID Controller/Anti-windup/Passthrough'
 * '<S35>'  : 'ControlLoop/Rover Steering2/PID Controller/D Gain/External Parameters'
 * '<S36>'  : 'ControlLoop/Rover Steering2/PID Controller/External Derivative/Error'
 * '<S37>'  : 'ControlLoop/Rover Steering2/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S38>'  : 'ControlLoop/Rover Steering2/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S39>'  : 'ControlLoop/Rover Steering2/PID Controller/I Gain/External Parameters'
 * '<S40>'  : 'ControlLoop/Rover Steering2/PID Controller/Ideal P Gain/Passthrough'
 * '<S41>'  : 'ControlLoop/Rover Steering2/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S42>'  : 'ControlLoop/Rover Steering2/PID Controller/Integrator/Discrete'
 * '<S43>'  : 'ControlLoop/Rover Steering2/PID Controller/Integrator ICs/Internal IC'
 * '<S44>'  : 'ControlLoop/Rover Steering2/PID Controller/N Copy/Disabled'
 * '<S45>'  : 'ControlLoop/Rover Steering2/PID Controller/N Gain/External Parameters'
 * '<S46>'  : 'ControlLoop/Rover Steering2/PID Controller/P Copy/Disabled'
 * '<S47>'  : 'ControlLoop/Rover Steering2/PID Controller/Parallel P Gain/External Parameters'
 * '<S48>'  : 'ControlLoop/Rover Steering2/PID Controller/Reset Signal/Disabled'
 * '<S49>'  : 'ControlLoop/Rover Steering2/PID Controller/Saturation/Passthrough'
 * '<S50>'  : 'ControlLoop/Rover Steering2/PID Controller/Saturation Fdbk/Disabled'
 * '<S51>'  : 'ControlLoop/Rover Steering2/PID Controller/Sum/Sum_PID'
 * '<S52>'  : 'ControlLoop/Rover Steering2/PID Controller/Sum Fdbk/Disabled'
 * '<S53>'  : 'ControlLoop/Rover Steering2/PID Controller/Tracking Mode/Disabled'
 * '<S54>'  : 'ControlLoop/Rover Steering2/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S55>'  : 'ControlLoop/Rover Steering2/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S56>'  : 'ControlLoop/Rover Steering2/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S57>'  : 'ControlLoop/Rover Steering2/PID Controller/postSat Signal/Forward_Path'
 * '<S58>'  : 'ControlLoop/Rover Steering2/PID Controller/preInt Signal/Internal PreInt'
 * '<S59>'  : 'ControlLoop/Rover Steering2/PID Controller/preSat Signal/Forward_Path'
 * '<S60>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller'
 * '<S61>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Anti-windup'
 * '<S62>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/D Gain'
 * '<S63>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/External Derivative'
 * '<S64>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter'
 * '<S65>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter ICs'
 * '<S66>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/I Gain'
 * '<S67>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain'
 * '<S68>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain Fdbk'
 * '<S69>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator'
 * '<S70>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator ICs'
 * '<S71>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Copy'
 * '<S72>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Gain'
 * '<S73>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/P Copy'
 * '<S74>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Parallel P Gain'
 * '<S75>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Reset Signal'
 * '<S76>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation'
 * '<S77>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation Fdbk'
 * '<S78>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum'
 * '<S79>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum Fdbk'
 * '<S80>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode'
 * '<S81>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode Sum'
 * '<S82>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Integral'
 * '<S83>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Ngain'
 * '<S84>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/postSat Signal'
 * '<S85>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/preInt Signal'
 * '<S86>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/preSat Signal'
 * '<S87>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Anti-windup/Passthrough'
 * '<S88>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/D Gain/External Parameters'
 * '<S89>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/External Derivative/Error'
 * '<S90>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S91>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S92>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/I Gain/External Parameters'
 * '<S93>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain/Passthrough'
 * '<S94>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator/Discrete'
 * '<S96>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Integrator ICs/Internal IC'
 * '<S97>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Copy/Disabled'
 * '<S98>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/N Gain/External Parameters'
 * '<S99>'  : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/P Copy/Disabled'
 * '<S100>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Parallel P Gain/External Parameters'
 * '<S101>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Reset Signal/Disabled'
 * '<S102>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation/Enabled'
 * '<S103>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Saturation Fdbk/Disabled'
 * '<S104>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum/Sum_PID'
 * '<S105>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Sum Fdbk/Disabled'
 * '<S106>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode/Disabled'
 * '<S107>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S109>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/postSat Signal/Forward_Path'
 * '<S111>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/preInt Signal/Internal PreInt'
 * '<S112>' : 'ControlLoop/Velocity Control Loop Motor A/PID Controller/preSat Signal/Forward_Path'
 * '<S113>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller'
 * '<S114>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Anti-windup'
 * '<S115>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/D Gain'
 * '<S116>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/External Derivative'
 * '<S117>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter'
 * '<S118>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter ICs'
 * '<S119>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/I Gain'
 * '<S120>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain'
 * '<S121>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain Fdbk'
 * '<S122>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator'
 * '<S123>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator ICs'
 * '<S124>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Copy'
 * '<S125>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Gain'
 * '<S126>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/P Copy'
 * '<S127>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Parallel P Gain'
 * '<S128>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Reset Signal'
 * '<S129>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation'
 * '<S130>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation Fdbk'
 * '<S131>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum'
 * '<S132>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum Fdbk'
 * '<S133>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode'
 * '<S134>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode Sum'
 * '<S135>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Integral'
 * '<S136>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Ngain'
 * '<S137>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/postSat Signal'
 * '<S138>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/preInt Signal'
 * '<S139>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/preSat Signal'
 * '<S140>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Anti-windup/Passthrough'
 * '<S141>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/D Gain/External Parameters'
 * '<S142>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/External Derivative/Error'
 * '<S143>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S144>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S145>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/I Gain/External Parameters'
 * '<S146>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain/Passthrough'
 * '<S147>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S148>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator/Discrete'
 * '<S149>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Integrator ICs/Internal IC'
 * '<S150>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Copy/Disabled'
 * '<S151>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/N Gain/External Parameters'
 * '<S152>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/P Copy/Disabled'
 * '<S153>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Parallel P Gain/External Parameters'
 * '<S154>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Reset Signal/Disabled'
 * '<S155>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation/Enabled'
 * '<S156>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Saturation Fdbk/Disabled'
 * '<S157>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum/Sum_PID'
 * '<S158>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Sum Fdbk/Disabled'
 * '<S159>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode/Disabled'
 * '<S160>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S161>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S162>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S163>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/postSat Signal/Forward_Path'
 * '<S164>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/preInt Signal/Internal PreInt'
 * '<S165>' : 'ControlLoop/Velocity Control Loop Motor B/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* ControlLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
