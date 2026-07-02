/*
 * shabishiyan_data.c
 *
 * Code generation for model "shabishiyan".
 *
 * Model version              : 19.2
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Fri Apr 24 16:00:30 2026
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "shabishiyan.h"
#include "shabishiyan_private.h"

/* Block parameters (default storage) */
P_shabishiyan_T shabishiyan_P = {
  /* Mask Parameter: BandLimitedWhiteNoise_Cov
   * Referenced by: '<S1>/Output'
   */
  0.0001,

  /* Mask Parameter: BandLimitedWhiteNoise1_Cov
   * Referenced by: '<S2>/Output'
   */
  0.0001,

  /* Mask Parameter: BandLimitedWhiteNoise_seed
   * Referenced by: '<S1>/White Noise'
   */
  23341.0,

  /* Mask Parameter: BandLimitedWhiteNoise1_seed
   * Referenced by: '<S2>/White Noise'
   */
  23341.0,

  /* Expression: 0
   * Referenced by: '<S7>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Pos Ref.1'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Pos Ref.2'
   */
  0.1,

  /* Computed Parameter: GTS400PVsInitialization_P1_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: open
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P2_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: mode
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P3_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 4.0 },

  /* Expression: servo
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: GTS400PVsInitialization_P4_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 4.0 },

  /* Expression: aft
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: GTS400PVsInitialization_P5_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 3.0 },

  /* Expression: pid1
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 4.5, 0.0, 10.0 },

  /* Computed Parameter: GTS400PVsInitialization_P6_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 3.0 },

  /* Expression: pid2
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 0.0, 0.0 },

  /* Computed Parameter: GTS400PVsInitialization_P7_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 3.0 },

  /* Expression: pid3
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 0.0, 0.0 },

  /* Computed Parameter: GTS400PVsInitialization_P8_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 3.0 },

  /* Expression: pid4
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 0.0, 0.0 },

  /* Computed Parameter: GTS400PVsInitialization_P9_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: enc1
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  1.0,

  /* Computed Parameter: GTS400PVsInitialization_P10_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: enc2
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  1.0,

  /* Computed Parameter: GTS400PVsInitialization_P11_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: enc3
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  1.0,

  /* Computed Parameter: GTS400PVsInitialization_P12_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: enc4
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  1.0,

  /* Computed Parameter: GTS400PVsInitialization_P13_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: lmt1
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P14_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: lmt2
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P15_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: lmt3
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P16_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: lmt4
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P17_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: cdno
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Computed Parameter: GTSGetPos_P1_Size
   * Referenced by: '<S5>/GTS GetPos'
   */
  { 1.0, 1.0 },

  /* Expression: axis
   * Referenced by: '<S5>/GTS GetPos'
   */
  1.0,

  /* Expression: 0.46 / 37500.0
   * Referenced by: '<S5>/Pos Encoder'
   */
  1.2266666666666667E-5,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: [1 0 0 0;0 0 1 0]
   * Referenced by: '<Root>/C'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: pi
   * Referenced by: '<Root>/Angle Ref.1'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Computed Parameter: GTSGetPos1_P1_Size
   * Referenced by: '<S5>/GTS GetPos1'
   */
  { 1.0, 1.0 },

  /* Expression: axis
   * Referenced by: '<S5>/GTS GetPos1'
   */
  2.0,

  /* Expression: -(pi * 2.0 / 2400)
   * Referenced by: '<S5>/Angle Encoder'
   */
  -0.0026179938779914941,

  /* Expression: pi
   * Referenced by: '<Root>/Angle Ref.'
   */
  3.1415926535897931,

  /* Expression: 0.0
   * Referenced by: '<Root>/Pos Ref.'
   */
  0.0,

  /* Expression: [0 1 0 0;0 0 0 0;0 0 0 1;0 0 29.4 0]
   * Referenced by: '<Root>/A'
   */
  { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 29.4, 0.0, 0.0, 1.0,
    0.0 },

  /* Expression: [18.06 -3.70;81.37 -29.22;1.87 15.94;9.72 90.20]
   * Referenced by: '<Root>/H'
   */
  { 18.06, 81.37, 1.87, 9.72, -3.7, -29.22, 15.94, 90.2 },

  /* Expression: [-13.8776 -12.1769 53.0925 9.7256]
   * Referenced by: '<Root>/K'
   */
  { -13.8776, -12.1769, 53.0925, 9.7256 },

  /* Expression: [0; 1; 0; 3]
   * Referenced by: '<Root>/B'
   */
  { 0.0, 1.0, 0.0, 3.0 },

  /* Expression: 50
   * Referenced by: '<S3>/Saturation'
   */
  50.0,

  /* Expression: -50
   * Referenced by: '<S3>/Saturation'
   */
  -50.0,

  /* Expression: 2
   * Referenced by: '<S3>/Gain'
   */
  2.0,

  /* Expression: pi
   * Referenced by: '<S6>/Constant1'
   */
  3.1415926535897931,

  /* Expression: 10*pi/180
   * Referenced by: '<S6>/EntryAngle'
   */
  0.17453292519943295,

  /* Computed Parameter: GTSSetAccVel_P1_Size
   * Referenced by: '<S5>/GTS SetAccVel'
   */
  { 1.0, 1.0 },

  /* Expression: Axis
   * Referenced by: '<S5>/GTS SetAccVel'
   */
  1.0,

  /* Computed Parameter: GTSSetAccVel_P2_Size
   * Referenced by: '<S5>/GTS SetAccVel'
   */
  { 1.0, 1.0 },

  /* Expression: vel
   * Referenced by: '<S5>/GTS SetAccVel'
   */
  0.1,

  /* Computed Parameter: GTSSetAccVel_P3_Size
   * Referenced by: '<S5>/GTS SetAccVel'
   */
  { 1.0, 1.0 },

  /* Expression: pos
   * Referenced by: '<S5>/GTS SetAccVel'
   */
  50000.0,

  /* Computed Parameter: GTSSetAccVel_P4_Size
   * Referenced by: '<S5>/GTS SetAccVel'
   */
  { 1.0, 1.0 },

  /* Expression: limit
   * Referenced by: '<S5>/GTS SetAccVel'
   */
  0.0,

  /* Expression: 0.001 * 0.001/ (0.46 / 37500.0)
   * Referenced by: '<S5>/AccCof'
   */
  0.08152173913043477,

  /* Expression: 0.001 / (0.46 / 37500.0)
   * Referenced by: '<S5>/VelCof'
   */
  81.521739130434781,

  /* Expression: 20*pi/180
   * Referenced by: '<S6>/StopAngle'
   */
  0.3490658503988659,

  /* Expression: 0
   * Referenced by: '<S1>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev
   * Referenced by: '<S1>/White Noise'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev_e
   * Referenced by: '<S2>/White Noise'
   */
  1.0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  1U,

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  1U
};
