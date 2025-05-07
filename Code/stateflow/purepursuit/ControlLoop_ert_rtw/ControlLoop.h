/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlLoop.h
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
  real_T Delay_DSTATE;                 /* '<S2>/Delay' */
  real_T Delay1_DSTATE;                /* '<S2>/Delay1' */
  real_T Integrator_DSTATE;            /* '<S148>/Integrator' */
  real_T Filter_DSTATE;                /* '<S143>/Filter' */
  real_T Delay_DSTATE_l;               /* '<S4>/Delay' */
  real_T Integrator_DSTATE_h;          /* '<S42>/Integrator' */
  real_T Filter_DSTATE_b;              /* '<S37>/Filter' */
  real_T Delay_DSTATE_o;               /* '<S5>/Delay' */
  real_T Integrator_DSTATE_b;          /* '<S95>/Integrator' */
  real_T Filter_DSTATE_e;              /* '<S90>/Filter' */
  real_T Delay1_DSTATE_o[20];          /* '<S4>/Delay1' */
  real_T Delay1_DSTATE_b[20];          /* '<S5>/Delay1' */
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
                               * Referenced by: '<S143>/Filter'
                               */
  real_T PIDController_InitialConditio_i;
                              /* Mask Parameter: PIDController_InitialConditio_i
                               * Referenced by: '<S37>/Filter'
                               */
  real_T PIDController_InitialConditio_b;
                              /* Mask Parameter: PIDController_InitialConditio_b
                               * Referenced by: '<S90>/Filter'
                               */
  real_T PIDController_InitialConditio_j;
                              /* Mask Parameter: PIDController_InitialConditio_j
                               * Referenced by: '<S148>/Integrator'
                               */
  real_T PIDController_InitialConditio_l;
                              /* Mask Parameter: PIDController_InitialConditio_l
                               * Referenced by: '<S42>/Integrator'
                               */
  real_T PIDController_InitialConditio_n;
                              /* Mask Parameter: PIDController_InitialConditio_n
                               * Referenced by: '<S95>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S49>/Saturation'
                               */
  real_T PIDController_LowerSaturation_n;
                              /* Mask Parameter: PIDController_LowerSaturation_n
                               * Referenced by: '<S102>/Saturation'
                               */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S49>/Saturation'
                               */
  real_T PIDController_UpperSaturation_p;
                              /* Mask Parameter: PIDController_UpperSaturation_p
                               * Referenced by: '<S102>/Saturation'
                               */
  real_T DistanceControl_kp_Value;     /* Expression: 0
                                        * Referenced by: '<Root>/DistanceControl_kp'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 18
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -4
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch3'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay1'
                                        */
  real_T ConstantB_Value;              /* Expression: 0.02618
                                        * Referenced by: '<S2>/Constant B'
                                        */
  real_T Wheelsdistanceinch_Value;     /* Expression: 12.65
                                        * Referenced by: '<Root>/Wheels distance (inch)'
                                        */
  real_T TakeAverageSpeed_Gain;        /* Expression: 0.5
                                        * Referenced by: '<S2>/TakeAverageSpeed'
                                        */
  real_T ConstantC_Value;              /* Expression: 0.02618
                                        * Referenced by: '<S2>/Constant C'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T WheelRadius_Value;            /* Expression: 3
                                        * Referenced by: '<S3>/Wheel Radius'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S148>/Integrator'
                                        */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S143>/Filter'
                                        */
  real_T FilterCoefficient_Value;      /* Expression: 100
                                        * Referenced by: '<S6>/Filter Coefficient'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch2'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T WheelRadius_Value_a;          /* Expression: 3
                                        * Referenced by: '<S1>/Wheel Radius'
                                        */
  real_T Delay_InitialCondition_g;     /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay'
                                        */
  real_T ConstantA_Value;              /* Expression: 3.49066
                                        * Referenced by: '<S4>/Constant A'
                                        */
  real_T MotorA_kp_Value;              /* Expression: .1
                                        * Referenced by: '<Root>/MotorA_kp'
                                        */
  real_T Integrator_gainval_l;       /* Computed Parameter: Integrator_gainval_l
                                      * Referenced by: '<S42>/Integrator'
                                      */
  real_T MotorA_kd_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/MotorA_kd'
                                        */
  real_T Filter_gainval_d;             /* Computed Parameter: Filter_gainval_d
                                        * Referenced by: '<S37>/Filter'
                                        */
  real_T FilterCoefficient_Value_d;    /* Expression: 100
                                        * Referenced by: '<S4>/Filter Coefficient'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -1
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Delay_InitialCondition_n;     /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay'
                                        */
  real_T ConstantA_Value_o;            /* Expression: 3.49066
                                        * Referenced by: '<S5>/Constant A'
                                        */
  real_T MotorB_kp_Value;              /* Expression: .1
                                        * Referenced by: '<Root>/MotorB_kp'
                                        */
  real_T Integrator_gainval_m;       /* Computed Parameter: Integrator_gainval_m
                                      * Referenced by: '<S95>/Integrator'
                                      */
  real_T MotorA_kd_Value_j;            /* Expression: 0
                                        * Referenced by: '<S5>/MotorA_kd'
                                        */
  real_T Filter_gainval_e;             /* Computed Parameter: Filter_gainval_e
                                        * Referenced by: '<S90>/Filter'
                                        */
  real_T FilterCoefficient_Value_g;    /* Expression: 100
                                        * Referenced by: '<S5>/Filter Coefficient'
                                        */
  real_T Delay1_InitialCondition_l;    /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay1'
                                        */
  real_T Frequency_Value;              /* Expression: 20
                                        * Referenced by: '<S4>/Frequency'
                                        */
  real_T Delay1_InitialCondition_g;    /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay1'
                                        */
  real_T Frequency_Value_i;            /* Expression: 20
                                        * Referenced by: '<S5>/Frequency'
                                        */
  real_T MotorA_ki_Value;              /* Expression: .22
                                        * Referenced by: '<Root>/MotorA_ki'
                                        */
  real_T MotorB_ki_Value;              /* Expression: .22
                                        * Referenced by: '<Root>/MotorB_ki'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
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
 * '<S1>'   : 'ControlLoop/Angular Velocity to Omega'
 * '<S2>'   : 'ControlLoop/CalculateRoverPose'
 * '<S3>'   : 'ControlLoop/Linear Speed to Omega'
 * '<S4>'   : 'ControlLoop/Motor A Velocity Control'
 * '<S5>'   : 'ControlLoop/Motor B Velocity Control'
 * '<S6>'   : 'ControlLoop/Rover Steering'
 * '<S7>'   : 'ControlLoop/Motor A Velocity Control/PID Controller'
 * '<S8>'   : 'ControlLoop/Motor A Velocity Control/PID Controller/Anti-windup'
 * '<S9>'   : 'ControlLoop/Motor A Velocity Control/PID Controller/D Gain'
 * '<S10>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/External Derivative'
 * '<S11>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Filter'
 * '<S12>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Filter ICs'
 * '<S13>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/I Gain'
 * '<S14>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Ideal P Gain'
 * '<S15>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Ideal P Gain Fdbk'
 * '<S16>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Integrator'
 * '<S17>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Integrator ICs'
 * '<S18>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/N Copy'
 * '<S19>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/N Gain'
 * '<S20>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/P Copy'
 * '<S21>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Parallel P Gain'
 * '<S22>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Reset Signal'
 * '<S23>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Saturation'
 * '<S24>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Saturation Fdbk'
 * '<S25>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Sum'
 * '<S26>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Sum Fdbk'
 * '<S27>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Tracking Mode'
 * '<S28>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Tracking Mode Sum'
 * '<S29>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Tsamp - Integral'
 * '<S30>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Tsamp - Ngain'
 * '<S31>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/postSat Signal'
 * '<S32>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/preInt Signal'
 * '<S33>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/preSat Signal'
 * '<S34>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Anti-windup/Passthrough'
 * '<S35>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/D Gain/External Parameters'
 * '<S36>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/External Derivative/Error'
 * '<S37>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S38>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S39>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/I Gain/External Parameters'
 * '<S40>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S41>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S42>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Integrator/Discrete'
 * '<S43>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Integrator ICs/Internal IC'
 * '<S44>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/N Copy/Disabled'
 * '<S45>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/N Gain/External Parameters'
 * '<S46>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/P Copy/Disabled'
 * '<S47>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Parallel P Gain/External Parameters'
 * '<S48>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Reset Signal/Disabled'
 * '<S49>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Saturation/Enabled'
 * '<S50>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S51>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Sum/Sum_PID'
 * '<S52>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Sum Fdbk/Disabled'
 * '<S53>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Tracking Mode/Disabled'
 * '<S54>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S55>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S56>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S57>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/postSat Signal/Forward_Path'
 * '<S58>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/preInt Signal/Internal PreInt'
 * '<S59>'  : 'ControlLoop/Motor A Velocity Control/PID Controller/preSat Signal/Forward_Path'
 * '<S60>'  : 'ControlLoop/Motor B Velocity Control/PID Controller'
 * '<S61>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Anti-windup'
 * '<S62>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/D Gain'
 * '<S63>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/External Derivative'
 * '<S64>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Filter'
 * '<S65>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Filter ICs'
 * '<S66>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/I Gain'
 * '<S67>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Ideal P Gain'
 * '<S68>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Ideal P Gain Fdbk'
 * '<S69>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Integrator'
 * '<S70>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Integrator ICs'
 * '<S71>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/N Copy'
 * '<S72>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/N Gain'
 * '<S73>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/P Copy'
 * '<S74>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Parallel P Gain'
 * '<S75>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Reset Signal'
 * '<S76>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Saturation'
 * '<S77>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Saturation Fdbk'
 * '<S78>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Sum'
 * '<S79>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Sum Fdbk'
 * '<S80>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Tracking Mode'
 * '<S81>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Tracking Mode Sum'
 * '<S82>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Tsamp - Integral'
 * '<S83>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Tsamp - Ngain'
 * '<S84>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/postSat Signal'
 * '<S85>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/preInt Signal'
 * '<S86>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/preSat Signal'
 * '<S87>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Anti-windup/Passthrough'
 * '<S88>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/D Gain/External Parameters'
 * '<S89>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/External Derivative/Error'
 * '<S90>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S91>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S92>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/I Gain/External Parameters'
 * '<S93>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S94>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Integrator/Discrete'
 * '<S96>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/Integrator ICs/Internal IC'
 * '<S97>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/N Copy/Disabled'
 * '<S98>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/N Gain/External Parameters'
 * '<S99>'  : 'ControlLoop/Motor B Velocity Control/PID Controller/P Copy/Disabled'
 * '<S100>' : 'ControlLoop/Motor B Velocity Control/PID Controller/Parallel P Gain/External Parameters'
 * '<S101>' : 'ControlLoop/Motor B Velocity Control/PID Controller/Reset Signal/Disabled'
 * '<S102>' : 'ControlLoop/Motor B Velocity Control/PID Controller/Saturation/Enabled'
 * '<S103>' : 'ControlLoop/Motor B Velocity Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S104>' : 'ControlLoop/Motor B Velocity Control/PID Controller/Sum/Sum_PID'
 * '<S105>' : 'ControlLoop/Motor B Velocity Control/PID Controller/Sum Fdbk/Disabled'
 * '<S106>' : 'ControlLoop/Motor B Velocity Control/PID Controller/Tracking Mode/Disabled'
 * '<S107>' : 'ControlLoop/Motor B Velocity Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'ControlLoop/Motor B Velocity Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S109>' : 'ControlLoop/Motor B Velocity Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'ControlLoop/Motor B Velocity Control/PID Controller/postSat Signal/Forward_Path'
 * '<S111>' : 'ControlLoop/Motor B Velocity Control/PID Controller/preInt Signal/Internal PreInt'
 * '<S112>' : 'ControlLoop/Motor B Velocity Control/PID Controller/preSat Signal/Forward_Path'
 * '<S113>' : 'ControlLoop/Rover Steering/PID Controller'
 * '<S114>' : 'ControlLoop/Rover Steering/PID Controller/Anti-windup'
 * '<S115>' : 'ControlLoop/Rover Steering/PID Controller/D Gain'
 * '<S116>' : 'ControlLoop/Rover Steering/PID Controller/External Derivative'
 * '<S117>' : 'ControlLoop/Rover Steering/PID Controller/Filter'
 * '<S118>' : 'ControlLoop/Rover Steering/PID Controller/Filter ICs'
 * '<S119>' : 'ControlLoop/Rover Steering/PID Controller/I Gain'
 * '<S120>' : 'ControlLoop/Rover Steering/PID Controller/Ideal P Gain'
 * '<S121>' : 'ControlLoop/Rover Steering/PID Controller/Ideal P Gain Fdbk'
 * '<S122>' : 'ControlLoop/Rover Steering/PID Controller/Integrator'
 * '<S123>' : 'ControlLoop/Rover Steering/PID Controller/Integrator ICs'
 * '<S124>' : 'ControlLoop/Rover Steering/PID Controller/N Copy'
 * '<S125>' : 'ControlLoop/Rover Steering/PID Controller/N Gain'
 * '<S126>' : 'ControlLoop/Rover Steering/PID Controller/P Copy'
 * '<S127>' : 'ControlLoop/Rover Steering/PID Controller/Parallel P Gain'
 * '<S128>' : 'ControlLoop/Rover Steering/PID Controller/Reset Signal'
 * '<S129>' : 'ControlLoop/Rover Steering/PID Controller/Saturation'
 * '<S130>' : 'ControlLoop/Rover Steering/PID Controller/Saturation Fdbk'
 * '<S131>' : 'ControlLoop/Rover Steering/PID Controller/Sum'
 * '<S132>' : 'ControlLoop/Rover Steering/PID Controller/Sum Fdbk'
 * '<S133>' : 'ControlLoop/Rover Steering/PID Controller/Tracking Mode'
 * '<S134>' : 'ControlLoop/Rover Steering/PID Controller/Tracking Mode Sum'
 * '<S135>' : 'ControlLoop/Rover Steering/PID Controller/Tsamp - Integral'
 * '<S136>' : 'ControlLoop/Rover Steering/PID Controller/Tsamp - Ngain'
 * '<S137>' : 'ControlLoop/Rover Steering/PID Controller/postSat Signal'
 * '<S138>' : 'ControlLoop/Rover Steering/PID Controller/preInt Signal'
 * '<S139>' : 'ControlLoop/Rover Steering/PID Controller/preSat Signal'
 * '<S140>' : 'ControlLoop/Rover Steering/PID Controller/Anti-windup/Passthrough'
 * '<S141>' : 'ControlLoop/Rover Steering/PID Controller/D Gain/External Parameters'
 * '<S142>' : 'ControlLoop/Rover Steering/PID Controller/External Derivative/Error'
 * '<S143>' : 'ControlLoop/Rover Steering/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S144>' : 'ControlLoop/Rover Steering/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S145>' : 'ControlLoop/Rover Steering/PID Controller/I Gain/External Parameters'
 * '<S146>' : 'ControlLoop/Rover Steering/PID Controller/Ideal P Gain/Passthrough'
 * '<S147>' : 'ControlLoop/Rover Steering/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S148>' : 'ControlLoop/Rover Steering/PID Controller/Integrator/Discrete'
 * '<S149>' : 'ControlLoop/Rover Steering/PID Controller/Integrator ICs/Internal IC'
 * '<S150>' : 'ControlLoop/Rover Steering/PID Controller/N Copy/Disabled'
 * '<S151>' : 'ControlLoop/Rover Steering/PID Controller/N Gain/External Parameters'
 * '<S152>' : 'ControlLoop/Rover Steering/PID Controller/P Copy/Disabled'
 * '<S153>' : 'ControlLoop/Rover Steering/PID Controller/Parallel P Gain/External Parameters'
 * '<S154>' : 'ControlLoop/Rover Steering/PID Controller/Reset Signal/Disabled'
 * '<S155>' : 'ControlLoop/Rover Steering/PID Controller/Saturation/Passthrough'
 * '<S156>' : 'ControlLoop/Rover Steering/PID Controller/Saturation Fdbk/Disabled'
 * '<S157>' : 'ControlLoop/Rover Steering/PID Controller/Sum/Sum_PID'
 * '<S158>' : 'ControlLoop/Rover Steering/PID Controller/Sum Fdbk/Disabled'
 * '<S159>' : 'ControlLoop/Rover Steering/PID Controller/Tracking Mode/Disabled'
 * '<S160>' : 'ControlLoop/Rover Steering/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S161>' : 'ControlLoop/Rover Steering/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S162>' : 'ControlLoop/Rover Steering/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S163>' : 'ControlLoop/Rover Steering/PID Controller/postSat Signal/Forward_Path'
 * '<S164>' : 'ControlLoop/Rover Steering/PID Controller/preInt Signal/Internal PreInt'
 * '<S165>' : 'ControlLoop/Rover Steering/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* ControlLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
