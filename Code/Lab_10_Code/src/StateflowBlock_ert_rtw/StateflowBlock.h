/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: StateflowBlock.h
 *
 * Code generated for Simulink model 'StateflowBlock'.
 *
 * Model version                  : 5.1
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Mar 11 18:23:58 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef StateflowBlock_h_
#define StateflowBlock_h_
#ifndef StateflowBlock_COMMON_INCLUDES_
#define StateflowBlock_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* StateflowBlock_COMMON_INCLUDES_ */

#include "StateflowBlock_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T WayPointsToGo[200];           /* '<Root>/Steering Stateflow' */
  real_T ValidWaypointsNumber;         /* '<Root>/Steering Stateflow' */
} B_StateflowBlock_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T CurrentLookaheadX;            /* '<Root>/Data Store Memory1' */
  real_T CurrentLookaheadY;            /* '<Root>/Data Store Memory2' */
  real_T TargetGlobalAngle;            /* '<Root>/Steering Stateflow' */
  real_T TurningAngleTrajectory[20];   /* '<Root>/Steering Stateflow' */
  real_T TurningAngleTrajectoryIndex;  /* '<Root>/Steering Stateflow' */
  real_T ServoASweepDirection;         /* '<Root>/Steering Stateflow' */
  real_T ServoASweepSpeed;             /* '<Root>/Steering Stateflow' */
  real_T ServoASweepUpperLimit;        /* '<Root>/Steering Stateflow' */
  real_T ServoASweepLowerLimit;        /* '<Root>/Steering Stateflow' */
  real_T ServoAStopSweeping;           /* '<Root>/Steering Stateflow' */
  real_T SweepingData[360];            /* '<Root>/Steering Stateflow' */
  real_T SweepingIndex;                /* '<Root>/Steering Stateflow' */
  real_T waypoint_index;               /* '<Root>/MATLAB Function' */
  uint8_T is_active_c3_StateflowBlock; /* '<Root>/Steering Stateflow' */
  uint8_T is_c3_StateflowBlock;        /* '<Root>/Steering Stateflow' */
  uint8_T is_SteeringToward;           /* '<Root>/Steering Stateflow' */
  boolean_T waypoint_index_not_empty;  /* '<Root>/MATLAB Function' */
} DW_StateflowBlock_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T accel_button_in;           /* '<Root>/accel_button_in' */
  boolean_T off_button_in;             /* '<Root>/off_button_in' */
  boolean_T pause_button_in;           /* '<Root>/pause_button_in' */
  real_T on_button_in;                 /* '<Root>/on_button_in' */
  real_T decel_button_in;              /* '<Root>/decel_button_in' */
  real_T UltrasoundDistanceA;          /* '<Root>/UltrasoundDistanceA' */
  real_T DC_MotorA_SpeedFeedback;      /* '<Root>/DC_MotorA_SpeedFeedback' */
  real_T DC_MotorB_SpeedFeedback;      /* '<Root>/DC_MotorB_SpeedFeedback' */
  real_T ServoAngle;                   /* '<Root>/ServoAngle' */
  real_T RoverGlobalDirection;         /* '<Root>/RoverGlobalDirection' */
  real_T RoverGlobalCoordX;            /* '<Root>/RoverGlobalCoordX' */
  real_T RoverGlobalCoordY;            /* '<Root>/RoverGlobalCoordY' */
} ExtU_StateflowBlock_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T DC_MotorA_SpeedCommand;       /* '<Root>/DC_MotorA_SpeedCommand' */
  real_T DC_MotorB_SpeedCommand;       /* '<Root>/DC_MotorB_SpeedCommand' */
  real_T state;                        /* '<Root>/state' */
  real_T DistanceA_command;            /* '<Root>/DistanceA_command' */
  real_T KeepDistanceA_Enable_Bool;    /* '<Root>/KeepDistanceA_Enable_Bool' */
  real_T ServoMotorA_Angle;            /* '<Root>/ServoMotorA_Angle' */
  real_T DesiredRoverGlobalDirection; /* '<Root>/DesiredRoverGlobalDirection' */
  real_T TargetDirection;              /* '<Root>/TargetDirection' */
  real_T ServoMotorB_Angle;            /* '<Root>/ServoMotorB_Angle' */
  real_T PurePursuitOmega;             /* '<Root>/PurePursuitOmega' */
  real_T PurePursuitVel;               /* '<Root>/PurePursuitVel' */
  real_T PurePursuitEnableBool;        /* '<Root>/PurePursuitEnableBool' */
  real_T PointX;                       /* '<Root>/PointX' */
  real_T PointY;                       /* '<Root>/PointY' */
} ExtY_StateflowBlock_T;

/* Parameters (default storage) */
struct P_StateflowBlock_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T InPositionThresholdinch_Value;/* Expression: 0.2
                                        * Referenced by: '<S1>/InPositionThreshold(inch)'
                                        */
  real_T LookaheadDistanceinch_Value;  /* Expression: 5
                                        * Referenced by: '<Root>/LookaheadDistance(inch)'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.8
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Wheelradiusin_Value;          /* Expression: 1.5
                                        * Referenced by: '<Root>/Wheel radius (in)'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T RobotMaxSpeedinchsec_Value;   /* Expression: 4
                                        * Referenced by: '<Root>/RobotMaxSpeed(inch//sec)'
                                        */
  real_T radsec_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/rad//sec'
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
struct tag_RTM_StateflowBlock_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_StateflowBlock_T StateflowBlock_P;

/* Block signals (default storage) */
extern B_StateflowBlock_T StateflowBlock_B;

/* Block states (default storage) */
extern DW_StateflowBlock_T StateflowBlock_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_StateflowBlock_T StateflowBlock_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_StateflowBlock_T StateflowBlock_Y;

/* Model entry point functions */
extern void StateflowBlock_initialize(void);
extern void StateflowBlock_step(void);
extern void StateflowBlock_terminate(void);

/* Real-time Model object */
extern RT_MODEL_StateflowBlock_T *const StateflowBlock_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Divide2' : Unused code path elimination
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
 * '<Root>' : 'StateflowBlock'
 * '<S1>'   : 'StateflowBlock/EndpointSlowDownAndCheck'
 * '<S2>'   : 'StateflowBlock/MATLAB Function'
 * '<S3>'   : 'StateflowBlock/Steering Stateflow'
 */
#endif                                 /* StateflowBlock_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
