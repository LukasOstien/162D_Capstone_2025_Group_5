/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: StateflowBlock.c
 *
 * Code generated for Simulink model 'StateflowBlock'.
 *
 * Model version                  : 5.7
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Apr 22 18:09:27 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "StateflowBlock.h"
#include "rtwtypes.h"
#include <math.h>
#include <string.h>

/* Named constants for Chart: '<Root>/Steering Stateflow' */
#define IN_TurningAngleTrajectoryPlanin ((uint8_T)5U)
#define Statefl_IN_WayPointsGeneration2 ((uint8_T)5U)
#define Stateflo_IN_WayPointsGeneration ((uint8_T)4U)
#define StateflowBlo_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define StateflowBloc_IN_SteeringToward ((uint8_T)2U)
#define StateflowBlock_IN_Initialize   ((uint8_T)2U)
#define StateflowBlock_IN_OFF          ((uint8_T)1U)
#define StateflowBlock_IN_Rurning      ((uint8_T)3U)
#define StateflowBlock_IN_Scanning     ((uint8_T)4U)
#define StateflowBlock_IN_WaitForGoing ((uint8_T)3U)
#define Stateflow_IN_GetObjectDirection ((uint8_T)1U)

/* Block signals (default storage) */
B_StateflowBlock_T StateflowBlock_B;

/* Block states (default storage) */
DW_StateflowBlock_T StateflowBlock_DW;

/* External inputs (root inport signals with default storage) */
ExtU_StateflowBlock_T StateflowBlock_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_StateflowBlock_T StateflowBlock_Y;

/* Real-time model */
static RT_MODEL_StateflowBlock_T StateflowBlock_M_;
RT_MODEL_StateflowBlock_T *const StateflowBlock_M = &StateflowBlock_M_;

/* Forward declaration for local functions */
static void StateflowBlock_OFF(void);

/* Function for Chart: '<Root>/Steering Stateflow' */
static void StateflowBlock_OFF(void)
{
  /* Inport: '<Root>/decel_button_in' incorporates:
   *  Inport: '<Root>/accel_button_in'
   */
  if (StateflowBlock_U.decel_button_in > 0.0) {
    StateflowBlock_DW.is_c3_StateflowBlock = Statefl_IN_WayPointsGeneration2;
    StateflowBlock_B.WayPointsToGo[0] = 0.0;
    StateflowBlock_B.WayPointsToGo[1] = 3.0;
    StateflowBlock_B.WayPointsToGo[2] = 6.0;
    StateflowBlock_B.WayPointsToGo[3] = 9.0;
    StateflowBlock_B.WayPointsToGo[4] = 12.0;
    StateflowBlock_B.WayPointsToGo[5] = 15.0;
    StateflowBlock_B.WayPointsToGo[6] = 18.0;
    StateflowBlock_B.WayPointsToGo[7] = 21.0;
    StateflowBlock_B.WayPointsToGo[8] = 24.0;
    StateflowBlock_B.WayPointsToGo[9] = 27.0;
    StateflowBlock_B.WayPointsToGo[10] = 30.0;
    StateflowBlock_B.WayPointsToGo[11] = 33.0;
    StateflowBlock_B.WayPointsToGo[12] = 36.0;
    StateflowBlock_B.WayPointsToGo[13] = 39.0;
    StateflowBlock_B.WayPointsToGo[14] = 42.0;
    StateflowBlock_B.WayPointsToGo[15] = 45.0;
    StateflowBlock_B.WayPointsToGo[16] = 48.0;
    StateflowBlock_B.WayPointsToGo[17] = 51.0;
    StateflowBlock_B.WayPointsToGo[18] = 54.0;
    StateflowBlock_B.WayPointsToGo[19] = 57.0;
    StateflowBlock_B.WayPointsToGo[20] = 60.0;
    StateflowBlock_B.WayPointsToGo[21] = 63.0;
    StateflowBlock_B.WayPointsToGo[22] = 66.0;
    StateflowBlock_B.WayPointsToGo[23] = 69.0;
    StateflowBlock_B.WayPointsToGo[24] = 72.0;
    StateflowBlock_B.WayPointsToGo[25] = 75.0;
    StateflowBlock_B.WayPointsToGo[26] = 78.0;
    StateflowBlock_B.WayPointsToGo[27] = 81.0;
    StateflowBlock_B.WayPointsToGo[28] = 84.0;
    StateflowBlock_B.WayPointsToGo[29] = 87.0;
    StateflowBlock_B.WayPointsToGo[30] = 90.0;
    StateflowBlock_B.WayPointsToGo[31] = 93.0;
    StateflowBlock_B.WayPointsToGo[32] = 96.0;
    StateflowBlock_B.WayPointsToGo[33] = 96.0;
    StateflowBlock_B.WayPointsToGo[34] = 96.0;
    StateflowBlock_B.WayPointsToGo[35] = 96.0;
    StateflowBlock_B.WayPointsToGo[36] = 96.0;
    StateflowBlock_B.WayPointsToGo[37] = 96.0;
    StateflowBlock_B.WayPointsToGo[38] = 96.0;
    StateflowBlock_B.WayPointsToGo[39] = 96.0;
    StateflowBlock_B.WayPointsToGo[40] = 96.0;
    StateflowBlock_B.WayPointsToGo[41] = 93.0;
    StateflowBlock_B.WayPointsToGo[42] = 90.0;
    StateflowBlock_B.WayPointsToGo[43] = 87.0;
    StateflowBlock_B.WayPointsToGo[44] = 84.0;
    StateflowBlock_B.WayPointsToGo[45] = 81.0;
    StateflowBlock_B.WayPointsToGo[46] = 78.0;
    StateflowBlock_B.WayPointsToGo[47] = 75.0;
    StateflowBlock_B.WayPointsToGo[48] = 72.0;
    StateflowBlock_B.WayPointsToGo[49] = 69.0;
    StateflowBlock_B.WayPointsToGo[50] = 66.0;
    StateflowBlock_B.WayPointsToGo[51] = 63.0;
    StateflowBlock_B.WayPointsToGo[52] = 60.0;
    StateflowBlock_B.WayPointsToGo[53] = 57.0;
    StateflowBlock_B.WayPointsToGo[54] = 54.0;
    StateflowBlock_B.WayPointsToGo[55] = 51.0;
    StateflowBlock_B.WayPointsToGo[56] = 48.0;
    StateflowBlock_B.WayPointsToGo[57] = 45.0;
    StateflowBlock_B.WayPointsToGo[58] = 42.0;
    StateflowBlock_B.WayPointsToGo[59] = 39.0;
    StateflowBlock_B.WayPointsToGo[60] = 36.0;
    StateflowBlock_B.WayPointsToGo[61] = 33.0;
    StateflowBlock_B.WayPointsToGo[62] = 30.0;
    StateflowBlock_B.WayPointsToGo[63] = 27.0;
    StateflowBlock_B.WayPointsToGo[64] = 24.0;
    StateflowBlock_B.WayPointsToGo[65] = 24.0;
    StateflowBlock_B.WayPointsToGo[66] = 24.0;
    StateflowBlock_B.WayPointsToGo[67] = 24.0;
    StateflowBlock_B.WayPointsToGo[68] = 24.0;
    StateflowBlock_B.WayPointsToGo[69] = 24.0;
    StateflowBlock_B.WayPointsToGo[70] = 24.0;
    StateflowBlock_B.WayPointsToGo[71] = 24.0;
    StateflowBlock_B.WayPointsToGo[72] = 24.0;
    memset(&StateflowBlock_B.WayPointsToGo[100], 0, 33U * sizeof(real_T));
    StateflowBlock_B.WayPointsToGo[133] = 3.0;
    StateflowBlock_B.WayPointsToGo[134] = 6.0;
    StateflowBlock_B.WayPointsToGo[135] = 9.0;
    StateflowBlock_B.WayPointsToGo[136] = 12.0;
    StateflowBlock_B.WayPointsToGo[137] = 15.0;
    StateflowBlock_B.WayPointsToGo[138] = 18.0;
    StateflowBlock_B.WayPointsToGo[139] = 21.0;
    StateflowBlock_B.WayPointsToGo[140] = 24.0;
    StateflowBlock_B.WayPointsToGo[141] = 24.0;
    StateflowBlock_B.WayPointsToGo[142] = 24.0;
    StateflowBlock_B.WayPointsToGo[143] = 24.0;
    StateflowBlock_B.WayPointsToGo[144] = 24.0;
    StateflowBlock_B.WayPointsToGo[145] = 24.0;
    StateflowBlock_B.WayPointsToGo[146] = 24.0;
    StateflowBlock_B.WayPointsToGo[147] = 24.0;
    StateflowBlock_B.WayPointsToGo[148] = 24.0;
    StateflowBlock_B.WayPointsToGo[149] = 24.0;
    StateflowBlock_B.WayPointsToGo[150] = 24.0;
    StateflowBlock_B.WayPointsToGo[151] = 24.0;
    StateflowBlock_B.WayPointsToGo[152] = 24.0;
    StateflowBlock_B.WayPointsToGo[153] = 24.0;
    StateflowBlock_B.WayPointsToGo[154] = 24.0;
    StateflowBlock_B.WayPointsToGo[155] = 24.0;
    StateflowBlock_B.WayPointsToGo[156] = 24.0;
    StateflowBlock_B.WayPointsToGo[157] = 24.0;
    StateflowBlock_B.WayPointsToGo[158] = 24.0;
    StateflowBlock_B.WayPointsToGo[159] = 24.0;
    StateflowBlock_B.WayPointsToGo[160] = 24.0;
    StateflowBlock_B.WayPointsToGo[161] = 24.0;
    StateflowBlock_B.WayPointsToGo[162] = 24.0;
    StateflowBlock_B.WayPointsToGo[163] = 24.0;
    StateflowBlock_B.WayPointsToGo[164] = 24.0;
    StateflowBlock_B.WayPointsToGo[165] = 27.0;
    StateflowBlock_B.WayPointsToGo[166] = 30.0;
    StateflowBlock_B.WayPointsToGo[167] = 33.0;
    StateflowBlock_B.WayPointsToGo[168] = 36.0;
    StateflowBlock_B.WayPointsToGo[169] = 39.0;
    StateflowBlock_B.WayPointsToGo[170] = 42.0;
    StateflowBlock_B.WayPointsToGo[171] = 45.0;
    StateflowBlock_B.WayPointsToGo[172] = 48.0;
    StateflowBlock_B.ValidWaypointsNumber = 73.0;

    /* Outport: '<Root>/state' */
    StateflowBlock_Y.state = 12.0;
  } else if (StateflowBlock_U.accel_button_in) {
    StateflowBlock_DW.is_c3_StateflowBlock = Stateflo_IN_WayPointsGeneration;
    StateflowBlock_B.WayPointsToGo[0] = 0.0;
    StateflowBlock_B.WayPointsToGo[1] = 24.0;
    StateflowBlock_B.WayPointsToGo[2] = 48.0;
    StateflowBlock_B.WayPointsToGo[3] = 72.0;
    StateflowBlock_B.WayPointsToGo[4] = 96.0;
    StateflowBlock_B.WayPointsToGo[5] = 96.0;
    StateflowBlock_B.WayPointsToGo[6] = 72.0;
    StateflowBlock_B.WayPointsToGo[7] = 48.0;
    StateflowBlock_B.WayPointsToGo[8] = 24.0;
    StateflowBlock_B.WayPointsToGo[9] = 24.0;
    StateflowBlock_B.WayPointsToGo[100] = 0.0;
    StateflowBlock_B.WayPointsToGo[101] = 0.0;
    StateflowBlock_B.WayPointsToGo[102] = 0.0;
    StateflowBlock_B.WayPointsToGo[103] = 0.0;
    StateflowBlock_B.WayPointsToGo[104] = 0.0;
    StateflowBlock_B.WayPointsToGo[105] = 24.0;
    StateflowBlock_B.WayPointsToGo[106] = 24.0;
    StateflowBlock_B.WayPointsToGo[107] = 24.0;
    StateflowBlock_B.WayPointsToGo[108] = 24.0;
    StateflowBlock_B.WayPointsToGo[109] = 48.0;
    StateflowBlock_B.ValidWaypointsNumber = 10.0;

    /* Outport: '<Root>/state' */
    StateflowBlock_Y.state = 11.0;
  } else {
    /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
    StateflowBlock_Y.DC_MotorA_SpeedCommand = 0.0;

    /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
    StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

    /* Outport: '<Root>/state' */
    StateflowBlock_Y.state = 0.0;

    /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
    StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;

    /* Outport: '<Root>/DistanceA_command' */
    StateflowBlock_Y.DistanceA_command = 250.0;

    /* Outport: '<Root>/DesiredRoverGlobalDirection' incorporates:
     *  Inport: '<Root>/RoverGlobalDirection'
     */
    StateflowBlock_Y.DesiredRoverGlobalDirection =
      StateflowBlock_U.RoverGlobalDirection;

    /* Outport: '<Root>/ServoMotorA_Angle' */
    StateflowBlock_Y.ServoMotorA_Angle = 90.0;

    /* Outport: '<Root>/PurePursuitEnableBool' */
    StateflowBlock_Y.PurePursuitEnableBool = 0.0;
    memset(&StateflowBlock_B.WayPointsToGo[0], 0, 200U * sizeof(real_T));
  }

  /* End of Inport: '<Root>/decel_button_in' */
}

/* Model step function */
void StateflowBlock_step(void)
{
  real_T lookahead_point_data[2];
  real_T SweepingData;
  real_T a;
  real_T b_a;
  real_T b_a_tmp;
  real_T rtb_Saturation;
  real_T rtb_Square;
  int32_T b;
  int32_T b_i;
  int32_T i;
  int32_T lookahead_point_size_idx_1;
  boolean_T exitg1;

  /* Sum: '<S1>/Sum' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read1'
   *  Inport: '<Root>/RoverGlobalCoordX'
   */
  rtb_Saturation = StateflowBlock_DW.CurrentLookaheadX -
    StateflowBlock_U.RoverGlobalCoordX;

  /* Math: '<S1>/Square' */
  rtb_Square = rtb_Saturation * rtb_Saturation;

  /* Sum: '<S1>/Sum1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read2'
   *  Inport: '<Root>/RoverGlobalCoordY'
   */
  rtb_Saturation = StateflowBlock_DW.CurrentLookaheadY -
    StateflowBlock_U.RoverGlobalCoordY;

  /* Sqrt: '<S1>/Square Root' incorporates:
   *  Math: '<S1>/Square1'
   *  Sum: '<S1>/Sum2'
   */
  rtb_Saturation = sqrt(rtb_Saturation * rtb_Saturation + rtb_Square);

  /* Chart: '<Root>/Steering Stateflow' incorporates:
   *  Inport: '<Root>/RoverGlobalDirection'
   *  Inport: '<Root>/UltrasoundDistanceA'
   *  Inport: '<Root>/off_button_in'
   *  Outport: '<Root>/ServoMotorA_Angle'
   *  Switch: '<S1>/Switch'
   */
  if (StateflowBlock_DW.is_active_c3_StateflowBlock == 0) {
    StateflowBlock_DW.is_active_c3_StateflowBlock = 1U;
    StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_OFF;

    /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
    StateflowBlock_Y.DC_MotorA_SpeedCommand = 0.0;

    /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
    StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

    /* Outport: '<Root>/state' */
    StateflowBlock_Y.state = 0.0;

    /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
    StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;

    /* Outport: '<Root>/DistanceA_command' */
    StateflowBlock_Y.DistanceA_command = 250.0;

    /* Outport: '<Root>/DesiredRoverGlobalDirection' incorporates:
     *  Inport: '<Root>/RoverGlobalDirection'
     */
    StateflowBlock_Y.DesiredRoverGlobalDirection =
      StateflowBlock_U.RoverGlobalDirection;

    /* Outport: '<Root>/ServoMotorA_Angle' */
    StateflowBlock_Y.ServoMotorA_Angle = 90.0;

    /* Outport: '<Root>/PurePursuitEnableBool' */
    StateflowBlock_Y.PurePursuitEnableBool = 0.0;
    memset(&StateflowBlock_B.WayPointsToGo[0], 0, 200U * sizeof(real_T));
  } else {
    switch (StateflowBlock_DW.is_c3_StateflowBlock) {
     case StateflowBlock_IN_OFF:
      StateflowBlock_OFF();
      break;

     case StateflowBloc_IN_SteeringToward:
      if (StateflowBlock_U.off_button_in) {
        StateflowBlock_DW.is_SteeringToward = StateflowBlo_IN_NO_ACTIVE_CHILD;
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_OFF;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = 0.0;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 0.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;

        /* Outport: '<Root>/DistanceA_command' */
        StateflowBlock_Y.DistanceA_command = 250.0;

        /* Outport: '<Root>/DesiredRoverGlobalDirection' incorporates:
         *  Inport: '<Root>/RoverGlobalDirection'
         */
        StateflowBlock_Y.DesiredRoverGlobalDirection =
          StateflowBlock_U.RoverGlobalDirection;

        /* Outport: '<Root>/ServoMotorA_Angle' */
        StateflowBlock_Y.ServoMotorA_Angle = 90.0;

        /* Outport: '<Root>/PurePursuitEnableBool' */
        StateflowBlock_Y.PurePursuitEnableBool = 0.0;
        memset(&StateflowBlock_B.WayPointsToGo[0], 0, 200U * sizeof(real_T));
      } else {
        switch (StateflowBlock_DW.is_SteeringToward) {
         case Stateflow_IN_GetObjectDirection:
          StateflowBlock_DW.is_SteeringToward = IN_TurningAngleTrajectoryPlanin;
          for (i = 0; i < 20; i++) {
            StateflowBlock_DW.TurningAngleTrajectory[i] =
              StateflowBlock_DW.TargetGlobalAngle;
          }

          StateflowBlock_DW.TurningAngleTrajectoryIndex = 1.0;

          /* Outport: '<Root>/state' */
          StateflowBlock_Y.state = 5.0;
          break;

         case StateflowBlock_IN_Initialize:
          StateflowBlock_DW.is_SteeringToward = StateflowBlock_IN_Rurning;

          /* Outport: '<Root>/DesiredRoverGlobalDirection' */
          StateflowBlock_Y.DesiredRoverGlobalDirection =
            StateflowBlock_DW.TurningAngleTrajectory[(int32_T)
            StateflowBlock_DW.TurningAngleTrajectoryIndex - 1];
          if (StateflowBlock_DW.TurningAngleTrajectoryIndex < 20.0) {
            StateflowBlock_DW.TurningAngleTrajectoryIndex++;
          }

          /* Outport: '<Root>/state' */
          StateflowBlock_Y.state = 2.0;
          break;

         case StateflowBlock_IN_Rurning:
          if (fabs(StateflowBlock_DW.TargetGlobalAngle -
                   StateflowBlock_U.RoverGlobalDirection) < 0.1) {
            StateflowBlock_DW.is_SteeringToward = StateflowBlock_IN_Scanning;
            StateflowBlock_DW.SweepingIndex++;
            i = ((int32_T)StateflowBlock_DW.SweepingIndex - 1) << 1;
            StateflowBlock_DW.SweepingData[i] =
              StateflowBlock_Y.ServoMotorA_Angle;
            StateflowBlock_DW.SweepingData[i + 1] =
              StateflowBlock_U.UltrasoundDistanceA;

            /* Outport: '<Root>/ServoMotorA_Angle' incorporates:
             *  Inport: '<Root>/UltrasoundDistanceA'
             */
            StateflowBlock_Y.ServoMotorA_Angle +=
              StateflowBlock_DW.ServoASweepDirection *
              StateflowBlock_DW.ServoASweepSpeed;
            if (StateflowBlock_DW.ServoASweepDirection > 0.0) {
              if (StateflowBlock_Y.ServoMotorA_Angle >=
                  StateflowBlock_DW.ServoASweepUpperLimit) {
                StateflowBlock_Y.ServoMotorA_Angle =
                  StateflowBlock_DW.ServoASweepUpperLimit;
                StateflowBlock_DW.ServoAStopSweeping = 1.0;
              }
            } else if (StateflowBlock_Y.ServoMotorA_Angle <=
                       StateflowBlock_DW.ServoASweepLowerLimit) {
              /* Outport: '<Root>/ServoMotorA_Angle' */
              StateflowBlock_Y.ServoMotorA_Angle =
                StateflowBlock_DW.ServoASweepLowerLimit;
              StateflowBlock_DW.ServoAStopSweeping = 1.0;
            }

            /* Outport: '<Root>/state' incorporates:
             *  Outport: '<Root>/ServoMotorA_Angle'
             */
            StateflowBlock_Y.state = 3.0;
          } else {
            /* Outport: '<Root>/DesiredRoverGlobalDirection' */
            StateflowBlock_Y.DesiredRoverGlobalDirection =
              StateflowBlock_DW.TurningAngleTrajectory[(int32_T)
              StateflowBlock_DW.TurningAngleTrajectoryIndex - 1];
            if (StateflowBlock_DW.TurningAngleTrajectoryIndex < 20.0) {
              StateflowBlock_DW.TurningAngleTrajectoryIndex++;
            }

            /* Outport: '<Root>/state' */
            StateflowBlock_Y.state = 2.0;
          }
          break;

         case StateflowBlock_IN_Scanning:
          if (StateflowBlock_DW.ServoAStopSweeping > 0.0) {
            StateflowBlock_DW.is_SteeringToward =
              Stateflow_IN_GetObjectDirection;
            rtb_Square = 1500.0;
            StateflowBlock_Y.TargetDirection = 90.0;
            b = (int32_T)StateflowBlock_DW.SweepingIndex;
            for (b_i = 0; b_i < b; b_i++) {
              i = b_i << 1;
              SweepingData = StateflowBlock_DW.SweepingData[i + 1];
              if (SweepingData < rtb_Square) {
                rtb_Square = SweepingData;
                StateflowBlock_Y.TargetDirection =
                  StateflowBlock_DW.SweepingData[i];
              }
            }

            StateflowBlock_Y.TargetDirection -=
              StateflowBlock_DW.ServoASweepDirection *
              StateflowBlock_DW.ServoASweepSpeed * 2.0;
            if (rtb_Square < 600.0) {
              StateflowBlock_DW.TargetGlobalAngle =
                (StateflowBlock_Y.TargetDirection - 90.0) * 3.1415926535897931 /
                180.0 + StateflowBlock_U.RoverGlobalDirection;
            } else {
              StateflowBlock_DW.TargetGlobalAngle =
                StateflowBlock_U.RoverGlobalDirection;
            }

            StateflowBlock_DW.ServoAStopSweeping = 0.0;
            StateflowBlock_DW.ServoASweepDirection =
              -StateflowBlock_DW.ServoASweepDirection;
            StateflowBlock_DW.SweepingIndex = 0.0;
            for (b = 0; b < 180; b++) {
              i = b << 1;
              StateflowBlock_DW.SweepingData[i] = 90.0;
              StateflowBlock_DW.SweepingData[i + 1] = 1500.0;
            }

            /* Outport: '<Root>/state' incorporates:
             *  Inport: '<Root>/RoverGlobalDirection'
             */
            StateflowBlock_Y.state = 4.0;
          } else {
            StateflowBlock_DW.SweepingIndex++;
            i = ((int32_T)StateflowBlock_DW.SweepingIndex - 1) << 1;
            StateflowBlock_DW.SweepingData[i] =
              StateflowBlock_Y.ServoMotorA_Angle;
            StateflowBlock_DW.SweepingData[i + 1] =
              StateflowBlock_U.UltrasoundDistanceA;

            /* Outport: '<Root>/ServoMotorA_Angle' incorporates:
             *  Inport: '<Root>/UltrasoundDistanceA'
             */
            StateflowBlock_Y.ServoMotorA_Angle +=
              StateflowBlock_DW.ServoASweepDirection *
              StateflowBlock_DW.ServoASweepSpeed;
            if (StateflowBlock_DW.ServoASweepDirection > 0.0) {
              if (StateflowBlock_Y.ServoMotorA_Angle >=
                  StateflowBlock_DW.ServoASweepUpperLimit) {
                StateflowBlock_Y.ServoMotorA_Angle =
                  StateflowBlock_DW.ServoASweepUpperLimit;
                StateflowBlock_DW.ServoAStopSweeping = 1.0;
              }
            } else if (StateflowBlock_Y.ServoMotorA_Angle <=
                       StateflowBlock_DW.ServoASweepLowerLimit) {
              /* Outport: '<Root>/ServoMotorA_Angle' */
              StateflowBlock_Y.ServoMotorA_Angle =
                StateflowBlock_DW.ServoASweepLowerLimit;
              StateflowBlock_DW.ServoAStopSweeping = 1.0;
            }

            /* Outport: '<Root>/state' incorporates:
             *  Outport: '<Root>/ServoMotorA_Angle'
             */
            StateflowBlock_Y.state = 3.0;
          }
          break;

         default:
          /* case IN_TurningAngleTrajectoryPlaning1: */
          StateflowBlock_DW.is_SteeringToward = StateflowBlock_IN_Rurning;

          /* Outport: '<Root>/DesiredRoverGlobalDirection' */
          StateflowBlock_Y.DesiredRoverGlobalDirection =
            StateflowBlock_DW.TurningAngleTrajectory[(int32_T)
            StateflowBlock_DW.TurningAngleTrajectoryIndex - 1];
          if (StateflowBlock_DW.TurningAngleTrajectoryIndex < 20.0) {
            StateflowBlock_DW.TurningAngleTrajectoryIndex++;
          }

          /* Outport: '<Root>/state' */
          StateflowBlock_Y.state = 2.0;
          break;
        }
      }
      break;

     case StateflowBlock_IN_WaitForGoing:
      /* Switch: '<S1>/Switch' incorporates:
       *  Constant: '<Root>/LookaheadDistance(inch)'
       *  Constant: '<S1>/Constant'
       *  Constant: '<S1>/Constant1'
       *  Constant: '<S1>/InPositionThreshold(inch)'
       *  Gain: '<S1>/Gain'
       *  MinMax: '<S1>/Min'
       *  Sum: '<S1>/Sum3'
       */
      if (rtb_Saturation - fmin(StateflowBlock_P.InPositionThresholdinch_Value,
           StateflowBlock_P.Gain_Gain *
           StateflowBlock_P.LookaheadDistanceinch_Value) >
          StateflowBlock_P.Switch_Threshold) {
        rtb_Square = StateflowBlock_P.Constant_Value;
      } else {
        rtb_Square = StateflowBlock_P.Constant1_Value;
      }

      if (rtb_Square == 1.0) {
        StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_OFF;

        /* Outport: '<Root>/DC_MotorA_SpeedCommand' */
        StateflowBlock_Y.DC_MotorA_SpeedCommand = 0.0;

        /* Outport: '<Root>/DC_MotorB_SpeedCommand' */
        StateflowBlock_Y.DC_MotorB_SpeedCommand = 0.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 0.0;

        /* Outport: '<Root>/KeepDistanceA_Enable_Bool' */
        StateflowBlock_Y.KeepDistanceA_Enable_Bool = 0.0;

        /* Outport: '<Root>/DistanceA_command' */
        StateflowBlock_Y.DistanceA_command = 250.0;

        /* Outport: '<Root>/DesiredRoverGlobalDirection' incorporates:
         *  Inport: '<Root>/RoverGlobalDirection'
         */
        StateflowBlock_Y.DesiredRoverGlobalDirection =
          StateflowBlock_U.RoverGlobalDirection;

        /* Outport: '<Root>/ServoMotorA_Angle' */
        StateflowBlock_Y.ServoMotorA_Angle = 90.0;

        /* Outport: '<Root>/PurePursuitEnableBool' */
        StateflowBlock_Y.PurePursuitEnableBool = 0.0;
        memset(&StateflowBlock_B.WayPointsToGo[0], 0, 200U * sizeof(real_T));
      } else {
        /* Outport: '<Root>/PurePursuitEnableBool' */
        StateflowBlock_Y.PurePursuitEnableBool = 1.0;

        /* Outport: '<Root>/state' */
        StateflowBlock_Y.state = 13.0;
      }
      break;

     case Stateflo_IN_WayPointsGeneration:
      StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_WaitForGoing;

      /* Outport: '<Root>/PurePursuitEnableBool' */
      StateflowBlock_Y.PurePursuitEnableBool = 1.0;

      /* Outport: '<Root>/state' */
      StateflowBlock_Y.state = 13.0;
      break;

     default:
      /* case IN_WayPointsGeneration2: */
      StateflowBlock_DW.is_c3_StateflowBlock = StateflowBlock_IN_WaitForGoing;

      /* Outport: '<Root>/PurePursuitEnableBool' */
      StateflowBlock_Y.PurePursuitEnableBool = 1.0;

      /* Outport: '<Root>/state' */
      StateflowBlock_Y.state = 13.0;
      break;
    }
  }

  /* End of Chart: '<Root>/Steering Stateflow' */

  /* Product: '<S1>/Divide1' incorporates:
   *  Constant: '<Root>/LookaheadDistance(inch)'
   */
  rtb_Saturation /= StateflowBlock_P.LookaheadDistanceinch_Value;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Saturation > StateflowBlock_P.Saturation_UpperSat) {
    rtb_Saturation = StateflowBlock_P.Saturation_UpperSat;
  } else if (rtb_Saturation < StateflowBlock_P.Saturation_LowerSat) {
    rtb_Saturation = StateflowBlock_P.Saturation_LowerSat;
  }

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<Root>/RobotMaxSpeed(inch//sec)'
   *  Saturate: '<S1>/Saturation'
   */
  StateflowBlock_Y.PurePursuitVel = rtb_Saturation *
    StateflowBlock_P.RobotMaxSpeedinchsec_Value;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/LookaheadDistance(inch)'
   *  DataStoreWrite: '<Root>/Data Store Write1'
   *  DataStoreWrite: '<Root>/Data Store Write2'
   *  Inport: '<Root>/RoverGlobalCoordX'
   *  Inport: '<Root>/RoverGlobalCoordY'
   *  Outport: '<Root>/PurePursuitEnableBool'
   */
  StateflowBlock_DW.CurrentLookaheadX = 99999.0;
  StateflowBlock_DW.CurrentLookaheadY = 99999.0;
  rtb_Saturation = StateflowBlock_P.LookaheadDistanceinch_Value *
    StateflowBlock_P.LookaheadDistanceinch_Value;
  if (StateflowBlock_Y.PurePursuitEnableBool == 0.0) {
    /* Product: '<S1>/Divide' incorporates:
     *  Outport: '<Root>/PurePursuitVel'
     */
    StateflowBlock_Y.PurePursuitVel = 0.0;

    /* Outport: '<Root>/PurePursuitOmega' */
    StateflowBlock_Y.PurePursuitOmega = 0.0;
    StateflowBlock_DW.waypoint_index = 1.0;
    StateflowBlock_DW.waypoint_index_not_empty = true;
  } else {
    if (!StateflowBlock_DW.waypoint_index_not_empty) {
      StateflowBlock_DW.waypoint_index = 1.0;
      StateflowBlock_DW.waypoint_index_not_empty = true;
    }

    if (StateflowBlock_DW.waypoint_index > StateflowBlock_B.ValidWaypointsNumber)
    {
      StateflowBlock_DW.waypoint_index = StateflowBlock_B.ValidWaypointsNumber;
    }

    i = 0;
    lookahead_point_size_idx_1 = 0;
    if (StateflowBlock_DW.waypoint_index ==
        StateflowBlock_B.ValidWaypointsNumber) {
      i = 1;
      lookahead_point_size_idx_1 = 2;
      lookahead_point_data[0] = StateflowBlock_B.WayPointsToGo[(int32_T)
        StateflowBlock_B.ValidWaypointsNumber - 1];
      lookahead_point_data[1] = StateflowBlock_B.WayPointsToGo[(int32_T)
        StateflowBlock_B.ValidWaypointsNumber + 99];
    } else {
      b = (int32_T)((1.0 - StateflowBlock_DW.waypoint_index) +
                    StateflowBlock_B.ValidWaypointsNumber);
      b_i = 0;
      exitg1 = false;
      while ((!exitg1) && (b_i <= b - 1)) {
        rtb_Square = StateflowBlock_DW.waypoint_index + (real_T)b_i;
        SweepingData = StateflowBlock_B.WayPointsToGo[(int32_T)rtb_Square - 1];
        a = SweepingData - StateflowBlock_U.RoverGlobalCoordX;
        b_a_tmp = StateflowBlock_B.WayPointsToGo[(int32_T)rtb_Square + 99];
        b_a = b_a_tmp - StateflowBlock_U.RoverGlobalCoordY;
        if (a * a + b_a * b_a >= rtb_Saturation) {
          i = 1;
          lookahead_point_size_idx_1 = 2;
          lookahead_point_data[0] = SweepingData;
          lookahead_point_data[1] = b_a_tmp;
          StateflowBlock_DW.waypoint_index = rtb_Square;
          exitg1 = true;
        } else {
          b_i++;
        }
      }
    }

    if ((i == 0) || (lookahead_point_size_idx_1 == 0)) {
      StateflowBlock_DW.waypoint_index = StateflowBlock_B.ValidWaypointsNumber;
      lookahead_point_data[0] = StateflowBlock_B.WayPointsToGo[(int32_T)
        StateflowBlock_B.ValidWaypointsNumber - 1];
      lookahead_point_data[1] = StateflowBlock_B.WayPointsToGo[(int32_T)
        StateflowBlock_B.ValidWaypointsNumber + 99];
    }

    rtb_Saturation = lookahead_point_data[0] -
      StateflowBlock_U.RoverGlobalCoordX;
    rtb_Square = lookahead_point_data[1] - StateflowBlock_U.RoverGlobalCoordY;
    StateflowBlock_DW.CurrentLookaheadX = lookahead_point_data[0];
    StateflowBlock_DW.CurrentLookaheadY = lookahead_point_data[1];

    /* Outport: '<Root>/PurePursuitOmega' incorporates:
     *  Constant: '<Root>/rad//sec'
     *  Inport: '<Root>/RoverGlobalCoordX'
     *  Inport: '<Root>/RoverGlobalCoordY'
     *  Inport: '<Root>/RoverGlobalDirection'
     */
    StateflowBlock_Y.PurePursuitOmega = fmax(fmin((-sin
      (StateflowBlock_U.RoverGlobalDirection) * rtb_Saturation + cos
      (StateflowBlock_U.RoverGlobalDirection) * rtb_Square) * 2.0 /
      (rtb_Saturation * rtb_Saturation + rtb_Square * rtb_Square) *
      StateflowBlock_Y.PurePursuitVel, StateflowBlock_P.radsec_Value),
      -StateflowBlock_P.radsec_Value);
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Outport: '<Root>/PointX' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write1'
   */
  StateflowBlock_Y.PointX = StateflowBlock_DW.CurrentLookaheadX;

  /* Outport: '<Root>/PointY' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write2'
   */
  StateflowBlock_Y.PointY = StateflowBlock_DW.CurrentLookaheadY;
}

/* Model initialize function */
void StateflowBlock_initialize(void)
{
  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  StateflowBlock_DW.CurrentLookaheadX =
    StateflowBlock_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  StateflowBlock_DW.CurrentLookaheadY =
    StateflowBlock_P.DataStoreMemory2_InitialValue;
}

/* Model terminate function */
void StateflowBlock_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
