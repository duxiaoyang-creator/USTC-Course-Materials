/*
 * shabishiyan_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&shabishiyan_B.TmpRTBAtSum3Inport1), 0, 0, 30 },

  { (char_T *)(&shabishiyan_B.RelationalOperator1), 8, 0, 2 }
  ,

  { (char_T *)(&shabishiyan_DW.TmpRTBAtSum3Inport1_Buffer0), 0, 0, 12 },

  { (char_T *)(&shabishiyan_DW.GTS400PVsInitialization_PWORK), 11, 0, 13 },

  { (char_T *)(&shabishiyan_DW.RandSeed), 7, 0, 2 },

  { (char_T *)(&shabishiyan_DW.TriggeredSubsystem_SubsysRanBC), 2, 0, 2 },

  { (char_T *)(&shabishiyan_DW.EnabledSubsystem1_MODE), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&shabishiyan_P.BandLimitedWhiteNoise_Cov), 0, 0, 154 },

  { (char_T *)(&shabishiyan_P.ManualSwitch_CurrentSetting), 3, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] shabishiyan_dt.h */
