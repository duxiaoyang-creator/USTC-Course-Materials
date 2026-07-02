/*
 * shabishiyan.c
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
#include "shabishiyan_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 2;
const double SLDRTTimers[4] = {
  0.005, 0.0,
  0.1, 0.0,
};

/* Block signals (default storage) */
B_shabishiyan_T shabishiyan_B;

/* Continuous states */
X_shabishiyan_T shabishiyan_X;

/* Block states (default storage) */
DW_shabishiyan_T shabishiyan_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_shabishiyan_T shabishiyan_PrevZCX;

/* Real-time model */
static RT_MODEL_shabishiyan_T shabishiyan_M_;
RT_MODEL_shabishiyan_T *const shabishiyan_M = &shabishiyan_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(shabishiyan_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(shabishiyan_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (shabishiyan_M->Timing.TaskCounters.TID[1] == 0) {
    shabishiyan_M->Timing.RateInteraction.TID1_2 =
      (shabishiyan_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    shabishiyan_M->Timing.perTaskSampleHits[5] =
      shabishiyan_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (shabishiyan_M->Timing.TaskCounters.TID[2])++;
  if ((shabishiyan_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.1s, 0.0s] */
    shabishiyan_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  shabishiyan_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model output function for TID0 */
void shabishiyan_output0(void)         /* Sample time: [0.0s, 0.0s] */
{
  real_T lastTime;
  real_T rtb_Abs4;
  real_T rtb_AngleEncoder;
  real_T rtb_Saturation;
  real_T tmp;
  real_T *lastU;
  int32_T i;
  if (rtmIsMajorTimeStep(shabishiyan_M)) {
    /* set solver stop time */
    if (!(shabishiyan_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&shabishiyan_M->solverInfo,
                            ((shabishiyan_M->Timing.clockTickH0 + 1) *
        shabishiyan_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&shabishiyan_M->solverInfo,
                            ((shabishiyan_M->Timing.clockTick0 + 1) *
        shabishiyan_M->Timing.stepSize0 + shabishiyan_M->Timing.clockTickH0 *
        shabishiyan_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(shabishiyan_M)) {
    shabishiyan_M->Timing.t[0] = rtsiGetT(&shabishiyan_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(shabishiyan_DW.EnabledSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(shabishiyan_DW.TriggeredSubsystem_SubsysRanBC);

  /* S-Function (gts_initialize_m): '<Root>/GTS400-PVs Initialization' */

  /* Level2 S-Function Block: '<Root>/GTS400-PVs Initialization' (gts_initialize_m) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* RateTransition generated from: '<Root>/Sum3' */
  if (rtmIsMajorTimeStep(shabishiyan_M) &&
      shabishiyan_M->Timing.RateInteraction.TID1_2) {
    /* RateTransition generated from: '<Root>/Sum3' */
    shabishiyan_B.TmpRTBAtSum3Inport1 =
      shabishiyan_DW.TmpRTBAtSum3Inport1_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Sum3' */

  /* S-Function (gts_getpos): '<S5>/GTS GetPos' */

  /* Level2 S-Function Block: '<S5>/GTS GetPos' (gts_getpos) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Sum: '<Root>/Sum3' incorporates:
   *  Gain: '<S5>/Pos Encoder'
   */
  shabishiyan_B.Sum3 = shabishiyan_P.PosEncoder_Gain * shabishiyan_B.GTSGetPos +
    shabishiyan_B.TmpRTBAtSum3Inport1;

  /* Sum: '<Root>/Sum6' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  shabishiyan_B.Sum6 = shabishiyan_P.Constant2_Value + shabishiyan_B.Sum3;

  /* Integrator: '<Root>/Integrator' */
  shabishiyan_B.Integrator[0] = shabishiyan_X.Integrator_CSTATE[0];
  shabishiyan_B.Integrator[1] = shabishiyan_X.Integrator_CSTATE[1];
  shabishiyan_B.Integrator[2] = shabishiyan_X.Integrator_CSTATE[2];
  shabishiyan_B.Integrator[3] = shabishiyan_X.Integrator_CSTATE[3];
  for (i = 0; i < 2; i++) {
    /* Gain: '<Root>/C' */
    shabishiyan_B.C[i] = 0.0;
    shabishiyan_B.C[i] += shabishiyan_P.C_Gain[i] * shabishiyan_B.Integrator[0];
    shabishiyan_B.C[i] += shabishiyan_P.C_Gain[i + 2] *
      shabishiyan_B.Integrator[1];
    shabishiyan_B.C[i] += shabishiyan_P.C_Gain[i + 4] *
      shabishiyan_B.Integrator[2];
    shabishiyan_B.C[i] += shabishiyan_P.C_Gain[i + 6] *
      shabishiyan_B.Integrator[3];
  }

  /* RateTransition generated from: '<Root>/Sum4' */
  if (rtmIsMajorTimeStep(shabishiyan_M) &&
      shabishiyan_M->Timing.RateInteraction.TID1_2) {
    /* RateTransition generated from: '<Root>/Sum4' */
    shabishiyan_B.TmpRTBAtSum4Inport1 =
      shabishiyan_DW.TmpRTBAtSum4Inport1_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Sum4' */

  /* S-Function (gts_getpos): '<S5>/GTS GetPos1' */

  /* Level2 S-Function Block: '<S5>/GTS GetPos1' (gts_getpos) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S5>/Angle Encoder' */
  rtb_AngleEncoder = shabishiyan_P.AngleEncoder_Gain * shabishiyan_B.GTSGetPos1;

  /* Sum: '<Root>/Sum4' */
  shabishiyan_B.Sum4 = shabishiyan_B.TmpRTBAtSum4Inport1 + rtb_AngleEncoder;

  /* Sum: '<Root>/Sum5' incorporates:
   *  Constant: '<Root>/Angle Ref.1'
   */
  shabishiyan_B.Sum5 = shabishiyan_P.AngleRef1_Value + shabishiyan_B.Sum4;

  /* S-Function (gt_change): '<Root>/ -pi~pi2' */
  /* S-Function Block: <Root>/ -pi~pi2 (gt_change) */
  {
    double temp;
    double fPI = 3.14159265;
    temp = shabishiyan_B.Sum5;
    while (temp > fPI) {
      temp -= 2 * fPI;
    }

    while (temp <= -fPI) {
      temp += 2 * fPI;
    }

    shabishiyan_B.pipi2 = temp;
  }

  if (rtmIsMajorTimeStep(shabishiyan_M)) {
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Angle Ref.'
   */
  shabishiyan_B.Sum = shabishiyan_B.Sum4 - shabishiyan_P.AngleRef_Value;

  /* S-Function (gt_change): '<Root>/ -pi~pi1' */
  /* S-Function Block: <Root>/ -pi~pi1 (gt_change) */
  {
    double temp;
    double fPI = 3.14159265;
    temp = shabishiyan_B.Sum;
    while (temp > fPI) {
      temp -= 2 * fPI;
    }

    while (temp <= -fPI) {
      temp += 2 * fPI;
    }

    shabishiyan_B.pipi1 = temp;
  }

  if (rtmIsMajorTimeStep(shabishiyan_M)) {
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Pos Ref.'
   */
  shabishiyan_B.Sum1 = shabishiyan_B.Sum3 - shabishiyan_P.PosRef_Value;
  if (rtmIsMajorTimeStep(shabishiyan_M)) {
    /* ManualSwitch: '<Root>/Manual Switch' */
    if (shabishiyan_P.ManualSwitch_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Constant: '<Root>/Pos Ref.1'
       */
      shabishiyan_B.ManualSwitch = shabishiyan_P.PosRef1_Value;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Constant: '<Root>/Pos Ref.2'
       */
      shabishiyan_B.ManualSwitch = shabishiyan_P.PosRef2_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */
  }

  /* Derivative: '<Root>/Derivative1' incorporates:
   *  Derivative: '<Root>/Derivative'
   */
  rtb_Abs4 = shabishiyan_M->Timing.t[0];
  if ((shabishiyan_DW.TimeStampA >= rtb_Abs4) && (shabishiyan_DW.TimeStampB >=
       rtb_Abs4)) {
    rtb_Saturation = 0.0;
  } else {
    lastTime = shabishiyan_DW.TimeStampA;
    lastU = &shabishiyan_DW.LastUAtTimeA;
    if (shabishiyan_DW.TimeStampA < shabishiyan_DW.TimeStampB) {
      if (shabishiyan_DW.TimeStampB < rtb_Abs4) {
        lastTime = shabishiyan_DW.TimeStampB;
        lastU = &shabishiyan_DW.LastUAtTimeB;
      }
    } else if (shabishiyan_DW.TimeStampA >= rtb_Abs4) {
      lastTime = shabishiyan_DW.TimeStampB;
      lastU = &shabishiyan_DW.LastUAtTimeB;
    }

    rtb_Saturation = (shabishiyan_B.Sum1 - *lastU) / (rtb_Abs4 - lastTime);
  }

  /* End of Derivative: '<Root>/Derivative1' */

  /* Derivative: '<Root>/Derivative' */
  if ((shabishiyan_DW.TimeStampA_i >= rtb_Abs4) && (shabishiyan_DW.TimeStampB_a >=
       rtb_Abs4)) {
    rtb_Abs4 = 0.0;
  } else {
    lastTime = shabishiyan_DW.TimeStampA_i;
    lastU = &shabishiyan_DW.LastUAtTimeA_f;
    if (shabishiyan_DW.TimeStampA_i < shabishiyan_DW.TimeStampB_a) {
      if (shabishiyan_DW.TimeStampB_a < rtb_Abs4) {
        lastTime = shabishiyan_DW.TimeStampB_a;
        lastU = &shabishiyan_DW.LastUAtTimeB_d;
      }
    } else if (shabishiyan_DW.TimeStampA_i >= rtb_Abs4) {
      lastTime = shabishiyan_DW.TimeStampB_a;
      lastU = &shabishiyan_DW.LastUAtTimeB_d;
    }

    rtb_Abs4 = (shabishiyan_B.Sum - *lastU) / (rtb_Abs4 - lastTime);
  }

  /* Gain: '<Root>/K' incorporates:
   *  ManualSwitch: '<Root>/Manual Switch1'
   */
  if (shabishiyan_P.ManualSwitch1_CurrentSetting == 1) {
    lastTime = shabishiyan_B.Sum1;
    tmp = shabishiyan_B.pipi1;
  } else {
    lastTime = shabishiyan_B.Integrator[0];
    rtb_Saturation = shabishiyan_B.Integrator[1];
    tmp = shabishiyan_B.Integrator[2];
    rtb_Abs4 = shabishiyan_B.Integrator[3];
  }

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<Root>/K'
   */
  rtb_Abs4 = shabishiyan_B.ManualSwitch - (((shabishiyan_P.K_Gain[0] * lastTime
    + shabishiyan_P.K_Gain[1] * rtb_Saturation) + shabishiyan_P.K_Gain[2] * tmp)
    + shabishiyan_P.K_Gain[3] * rtb_Abs4);

  /* Sum: '<Root>/Sum7' */
  rtb_Saturation = shabishiyan_B.Sum6 - shabishiyan_B.C[0];
  lastTime = shabishiyan_B.pipi2 - shabishiyan_B.C[1];
  for (i = 0; i < 4; i++) {
    /* Sum: '<Root>/Add' incorporates:
     *  Gain: '<Root>/A'
     *  Gain: '<Root>/B'
     *  Gain: '<Root>/H'
     */
    shabishiyan_B.Add[i] = (((shabishiyan_P.A_Gain[i + 4] *
      shabishiyan_B.Integrator[1] + shabishiyan_P.A_Gain[i] *
      shabishiyan_B.Integrator[0]) + shabishiyan_P.A_Gain[i + 8] *
      shabishiyan_B.Integrator[2]) + shabishiyan_P.A_Gain[i + 12] *
      shabishiyan_B.Integrator[3]) + ((shabishiyan_P.H_Gain[i + 4] * lastTime +
      shabishiyan_P.H_Gain[i] * rtb_Saturation) + shabishiyan_P.B_Gain[i] *
      rtb_Abs4);
  }

  /* Sum: '<S6>/Sum1' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  shabishiyan_B.Sum1_k = shabishiyan_P.Constant1_Value_i - rtb_AngleEncoder;

  /* S-Function (gt_change): '<S6>/ -pi~pi' */
  /* S-Function Block: <S6>/ -pi~pi (gt_change) */
  {
    double temp;
    double fPI = 3.14159265;
    temp = shabishiyan_B.Sum1_k;
    while (temp > fPI) {
      temp -= 2 * fPI;
    }

    while (temp <= -fPI) {
      temp += 2 * fPI;
    }

    shabishiyan_B.pipi = temp;
  }

  /* Abs: '<S6>/Abs' incorporates:
   *  Abs: '<S6>/Abs4'
   */
  rtb_AngleEncoder = fabs(shabishiyan_B.pipi);

  /* RelationalOperator: '<S6>/Relational Operator1' incorporates:
   *  Abs: '<S6>/Abs'
   *  Constant: '<S6>/EntryAngle'
   */
  shabishiyan_B.RelationalOperator1 = (rtb_AngleEncoder <=
    shabishiyan_P.EntryAngle_Value);
  if (rtmIsMajorTimeStep(shabishiyan_M)) {
    /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S4>/Enable'
     */
    /* Outputs for Triggered SubSystem: '<S6>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S7>/Trigger'
     */
    if (rtmIsMajorTimeStep(shabishiyan_M)) {
      if (shabishiyan_B.RelationalOperator1 &&
          (shabishiyan_PrevZCX.TriggeredSubsystem_Trig_ZCE != 1)) {
        /* Constant: '<S7>/Constant' */
        shabishiyan_B.Constant = shabishiyan_P.Constant_Value;
        shabishiyan_DW.TriggeredSubsystem_SubsysRanBC = 4;
      }

      shabishiyan_PrevZCX.TriggeredSubsystem_Trig_ZCE =
        shabishiyan_B.RelationalOperator1;
      if (shabishiyan_B.Constant > 0.0) {
        if (!shabishiyan_DW.EnabledSubsystem1_MODE) {
          shabishiyan_DW.EnabledSubsystem1_MODE = true;
        }
      } else if (shabishiyan_DW.EnabledSubsystem1_MODE) {
        shabishiyan_DW.EnabledSubsystem1_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S6>/Triggered Subsystem' */
    /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem1' */
  }

  /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (shabishiyan_DW.EnabledSubsystem1_MODE) {
    /* Signum: '<S3>/Sign' */
    if (rtb_Abs4 < 0.0) {
      rtb_Saturation = -1.0;
    } else if (rtb_Abs4 > 0.0) {
      rtb_Saturation = 1.0;
    } else if (rtb_Abs4 == 0.0) {
      rtb_Saturation = 0.0;
    } else {
      rtb_Saturation = (rtNaN);
    }

    /* End of Signum: '<S3>/Sign' */

    /* Inport: '<S4>/In1' incorporates:
     *  Gain: '<S3>/Gain'
     */
    shabishiyan_B.In1 = shabishiyan_P.Gain_Gain * rtb_Saturation;

    /* Saturate: '<S3>/Saturation' */
    if (rtb_Abs4 > shabishiyan_P.Saturation_UpperSat) {
      rtb_Abs4 = shabishiyan_P.Saturation_UpperSat;
    } else if (rtb_Abs4 < shabishiyan_P.Saturation_LowerSat) {
      rtb_Abs4 = shabishiyan_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S3>/Saturation' */

    /* Inport: '<S4>/In2' incorporates:
     *  Abs: '<S3>/ 2'
     */
    shabishiyan_B.In2 = fabs(rtb_Abs4);
    if (rtmIsMajorTimeStep(shabishiyan_M)) {
      srUpdateBC(shabishiyan_DW.EnabledSubsystem1_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem1' */

  /* S-Function (gts_setaccvel): '<S5>/GTS SetAccVel' */

  /* Level2 S-Function Block: '<S5>/GTS SetAccVel' (gts_setaccvel) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S5>/AccCof' */
  shabishiyan_B.AccCof = shabishiyan_P.AccCof_Gain * shabishiyan_B.In2;

  /* Gain: '<S5>/VelCof' */
  shabishiyan_B.VelCof = shabishiyan_P.VelCof_Gain * shabishiyan_B.In1;
  if (rtmIsMajorTimeStep(shabishiyan_M)) {
  }

  /* Logic: '<S6>/Logical Operator3' incorporates:
   *  Constant: '<S6>/StopAngle'
   *  RelationalOperator: '<S6>/Relational Operator4'
   */
  shabishiyan_B.LogicalOperator3 = ((rtb_AngleEncoder >=
    shabishiyan_P.StopAngle_Value) && (shabishiyan_B.Constant != 0.0));
  if (rtmIsMajorTimeStep(shabishiyan_M)) {
    /* Stop: '<S6>/Stop Simulation' */
    if (shabishiyan_B.LogicalOperator3) {
      rtmSetStopRequested(shabishiyan_M, 1);
    }

    /* End of Stop: '<S6>/Stop Simulation' */
  }
}

/* Model update function for TID0 */
void shabishiyan_update0(void)         /* Sample time: [0.0s, 0.0s] */
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative1' */
  if (shabishiyan_DW.TimeStampA == (rtInf)) {
    shabishiyan_DW.TimeStampA = shabishiyan_M->Timing.t[0];
    lastU = &shabishiyan_DW.LastUAtTimeA;
  } else if (shabishiyan_DW.TimeStampB == (rtInf)) {
    shabishiyan_DW.TimeStampB = shabishiyan_M->Timing.t[0];
    lastU = &shabishiyan_DW.LastUAtTimeB;
  } else if (shabishiyan_DW.TimeStampA < shabishiyan_DW.TimeStampB) {
    shabishiyan_DW.TimeStampA = shabishiyan_M->Timing.t[0];
    lastU = &shabishiyan_DW.LastUAtTimeA;
  } else {
    shabishiyan_DW.TimeStampB = shabishiyan_M->Timing.t[0];
    lastU = &shabishiyan_DW.LastUAtTimeB;
  }

  *lastU = shabishiyan_B.Sum1;

  /* End of Update for Derivative: '<Root>/Derivative1' */

  /* Update for Derivative: '<Root>/Derivative' */
  if (shabishiyan_DW.TimeStampA_i == (rtInf)) {
    shabishiyan_DW.TimeStampA_i = shabishiyan_M->Timing.t[0];
    lastU = &shabishiyan_DW.LastUAtTimeA_f;
  } else if (shabishiyan_DW.TimeStampB_a == (rtInf)) {
    shabishiyan_DW.TimeStampB_a = shabishiyan_M->Timing.t[0];
    lastU = &shabishiyan_DW.LastUAtTimeB_d;
  } else if (shabishiyan_DW.TimeStampA_i < shabishiyan_DW.TimeStampB_a) {
    shabishiyan_DW.TimeStampA_i = shabishiyan_M->Timing.t[0];
    lastU = &shabishiyan_DW.LastUAtTimeA_f;
  } else {
    shabishiyan_DW.TimeStampB_a = shabishiyan_M->Timing.t[0];
    lastU = &shabishiyan_DW.LastUAtTimeB_d;
  }

  *lastU = shabishiyan_B.Sum;

  /* End of Update for Derivative: '<Root>/Derivative' */
  if (rtmIsMajorTimeStep(shabishiyan_M)) {
    rt_ertODEUpdateContinuousStates(&shabishiyan_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++shabishiyan_M->Timing.clockTick0)) {
    ++shabishiyan_M->Timing.clockTickH0;
  }

  shabishiyan_M->Timing.t[0] = rtsiGetSolverStopTime(&shabishiyan_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++shabishiyan_M->Timing.clockTick1)) {
    ++shabishiyan_M->Timing.clockTickH1;
  }

  shabishiyan_M->Timing.t[1] = shabishiyan_M->Timing.clockTick1 *
    shabishiyan_M->Timing.stepSize1 + shabishiyan_M->Timing.clockTickH1 *
    shabishiyan_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void shabishiyan_derivatives(void)
{
  XDot_shabishiyan_T *_rtXdot;
  _rtXdot = ((XDot_shabishiyan_T *) shabishiyan_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = shabishiyan_B.Add[0];
  _rtXdot->Integrator_CSTATE[1] = shabishiyan_B.Add[1];
  _rtXdot->Integrator_CSTATE[2] = shabishiyan_B.Add[2];
  _rtXdot->Integrator_CSTATE[3] = shabishiyan_B.Add[3];
}

/* Model output function for TID2 */
void shabishiyan_output2(void)         /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_ManualSwitch2;
  real_T rtb_ManualSwitch3;

  /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<S1>/Output'
   *  RandomNumber: '<S1>/White Noise'
   */
  if (shabishiyan_P.ManualSwitch2_CurrentSetting == 1) {
    rtb_ManualSwitch2 = sqrt(shabishiyan_P.BandLimitedWhiteNoise_Cov) /
      0.31622776601683794 * shabishiyan_DW.NextOutput;
  } else {
    rtb_ManualSwitch2 = shabishiyan_P.Constant_Value_o;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch2' */

  /* ManualSwitch: '<Root>/Manual Switch3' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<S2>/Output'
   *  RandomNumber: '<S2>/White Noise'
   */
  if (shabishiyan_P.ManualSwitch3_CurrentSetting == 1) {
    rtb_ManualSwitch3 = sqrt(shabishiyan_P.BandLimitedWhiteNoise1_Cov) /
      0.31622776601683794 * shabishiyan_DW.NextOutput_j;
  } else {
    rtb_ManualSwitch3 = shabishiyan_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch3' */

  /* RateTransition generated from: '<Root>/Sum3' */
  shabishiyan_DW.TmpRTBAtSum3Inport1_Buffer0 = rtb_ManualSwitch2;

  /* RateTransition generated from: '<Root>/Sum4' */
  shabishiyan_DW.TmpRTBAtSum4Inport1_Buffer0 = rtb_ManualSwitch3;
}

/* Model update function for TID2 */
void shabishiyan_update2(void)         /* Sample time: [0.1s, 0.0s] */
{
  /* Update for RandomNumber: '<S1>/White Noise' */
  shabishiyan_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&shabishiyan_DW.RandSeed) * shabishiyan_P.WhiteNoise_StdDev +
    shabishiyan_P.WhiteNoise_Mean;

  /* Update for RandomNumber: '<S2>/White Noise' */
  shabishiyan_DW.NextOutput_j = rt_nrand_Upu32_Yd_f_pw_snf
    (&shabishiyan_DW.RandSeed_h) * shabishiyan_P.WhiteNoise_StdDev_e +
    shabishiyan_P.WhiteNoise_Mean_l;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++shabishiyan_M->Timing.clockTick2)) {
    ++shabishiyan_M->Timing.clockTickH2;
  }

  shabishiyan_M->Timing.t[2] = shabishiyan_M->Timing.clockTick2 *
    shabishiyan_M->Timing.stepSize2 + shabishiyan_M->Timing.clockTickH2 *
    shabishiyan_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void shabishiyan_output(int_T tid)
{
  switch (tid) {
   case 0 :
    shabishiyan_output0();
    break;

   case 2 :
    shabishiyan_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void shabishiyan_update(int_T tid)
{
  switch (tid) {
   case 0 :
    shabishiyan_update0();
    break;

   case 2 :
    shabishiyan_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void shabishiyan_initialize(void)
{
  /* Start for S-Function (gts_initialize_m): '<Root>/GTS400-PVs Initialization' */
  /* Level2 S-Function Block: '<Root>/GTS400-PVs Initialization' (gts_initialize_m) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for RateTransition generated from: '<Root>/Sum3' */
  shabishiyan_B.TmpRTBAtSum3Inport1 =
    shabishiyan_P.TmpRTBAtSum3Inport1_InitialCondition;

  /* Start for S-Function (gts_getpos): '<S5>/GTS GetPos' */
  /* Level2 S-Function Block: '<S5>/GTS GetPos' (gts_getpos) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for RateTransition generated from: '<Root>/Sum4' */
  shabishiyan_B.TmpRTBAtSum4Inport1 =
    shabishiyan_P.TmpRTBAtSum4Inport1_InitialCondition;

  /* Start for S-Function (gts_getpos): '<S5>/GTS GetPos1' */
  /* Level2 S-Function Block: '<S5>/GTS GetPos1' (gts_getpos) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (gt_change): '<Root>/ -pi~pi2' */

  /* S-Function Block: <Root>/ -pi~pi2 (gt_change) */
  {
  }

  /* Start for S-Function (gt_change): '<Root>/ -pi~pi1' */

  /* S-Function Block: <Root>/ -pi~pi1 (gt_change) */
  {
  }

  /* Start for S-Function (gt_change): '<S6>/ -pi~pi' */

  /* S-Function Block: <S6>/ -pi~pi (gt_change) */
  {
  }

  /* Start for Enabled SubSystem: '<S3>/Enabled Subsystem1' */
  shabishiyan_DW.EnabledSubsystem1_MODE = false;

  /* End of Start for SubSystem: '<S3>/Enabled Subsystem1' */

  /* Start for S-Function (gts_setaccvel): '<S5>/GTS SetAccVel' */
  /* Level2 S-Function Block: '<S5>/GTS SetAccVel' (gts_setaccvel) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  shabishiyan_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  {
    real_T tmp;
    int32_T r;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for RateTransition generated from: '<Root>/Sum3' */
    shabishiyan_DW.TmpRTBAtSum3Inport1_Buffer0 =
      shabishiyan_P.TmpRTBAtSum3Inport1_InitialCondition;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    shabishiyan_X.Integrator_CSTATE[0] = shabishiyan_P.Integrator_IC;
    shabishiyan_X.Integrator_CSTATE[1] = shabishiyan_P.Integrator_IC;
    shabishiyan_X.Integrator_CSTATE[2] = shabishiyan_P.Integrator_IC;
    shabishiyan_X.Integrator_CSTATE[3] = shabishiyan_P.Integrator_IC;

    /* InitializeConditions for RateTransition generated from: '<Root>/Sum4' */
    shabishiyan_DW.TmpRTBAtSum4Inport1_Buffer0 =
      shabishiyan_P.TmpRTBAtSum4Inport1_InitialCondition;

    /* InitializeConditions for Derivative: '<Root>/Derivative1' */
    shabishiyan_DW.TimeStampA = (rtInf);
    shabishiyan_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative' */
    shabishiyan_DW.TimeStampA_i = (rtInf);
    shabishiyan_DW.TimeStampB_a = (rtInf);

    /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
    tmp = floor(shabishiyan_P.BandLimitedWhiteNoise_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    shabishiyan_DW.RandSeed = tseed;
    shabishiyan_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&shabishiyan_DW.RandSeed) * shabishiyan_P.WhiteNoise_StdDev +
      shabishiyan_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S1>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S2>/White Noise' */
    tmp = floor(shabishiyan_P.BandLimitedWhiteNoise1_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    shabishiyan_DW.RandSeed_h = tseed;
    shabishiyan_DW.NextOutput_j = rt_nrand_Upu32_Yd_f_pw_snf
      (&shabishiyan_DW.RandSeed_h) * shabishiyan_P.WhiteNoise_StdDev_e +
      shabishiyan_P.WhiteNoise_Mean_l;

    /* End of InitializeConditions for RandomNumber: '<S2>/White Noise' */

    /* SystemInitialize for Triggered SubSystem: '<S6>/Triggered Subsystem' */
    /* SystemInitialize for Outport: '<S7>/Out1' incorporates:
     *  Constant: '<S7>/Constant'
     */
    shabishiyan_B.Constant = shabishiyan_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S6>/Triggered Subsystem' */
  }
}

/* Model terminate function */
void shabishiyan_terminate(void)
{
  /* Terminate for S-Function (gts_initialize_m): '<Root>/GTS400-PVs Initialization' */
  /* Level2 S-Function Block: '<Root>/GTS400-PVs Initialization' (gts_initialize_m) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (gts_getpos): '<S5>/GTS GetPos' */
  /* Level2 S-Function Block: '<S5>/GTS GetPos' (gts_getpos) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (gts_getpos): '<S5>/GTS GetPos1' */
  /* Level2 S-Function Block: '<S5>/GTS GetPos1' (gts_getpos) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (gt_change): '<Root>/ -pi~pi2' */

  /* S-Function Block: <Root>/ -pi~pi2 (gt_change) */
  {
  }

  /* Terminate for S-Function (gt_change): '<Root>/ -pi~pi1' */

  /* S-Function Block: <Root>/ -pi~pi1 (gt_change) */
  {
  }

  /* Terminate for S-Function (gt_change): '<S6>/ -pi~pi' */

  /* S-Function Block: <S6>/ -pi~pi (gt_change) */
  {
  }

  /* Terminate for S-Function (gts_setaccvel): '<S5>/GTS SetAccVel' */
  /* Level2 S-Function Block: '<S5>/GTS SetAccVel' (gts_setaccvel) */
  {
    SimStruct *rts = shabishiyan_M->childSfunctions[3];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  shabishiyan_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  shabishiyan_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  shabishiyan_initialize();
}

void MdlTerminate(void)
{
  shabishiyan_terminate();
}

/* Registration function */
RT_MODEL_shabishiyan_T *shabishiyan(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)shabishiyan_M, 0,
                sizeof(RT_MODEL_shabishiyan_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&shabishiyan_M->solverInfo,
                          &shabishiyan_M->Timing.simTimeStep);
    rtsiSetTPtr(&shabishiyan_M->solverInfo, &rtmGetTPtr(shabishiyan_M));
    rtsiSetStepSizePtr(&shabishiyan_M->solverInfo,
                       &shabishiyan_M->Timing.stepSize0);
    rtsiSetdXPtr(&shabishiyan_M->solverInfo, &shabishiyan_M->derivs);
    rtsiSetContStatesPtr(&shabishiyan_M->solverInfo, (real_T **)
                         &shabishiyan_M->contStates);
    rtsiSetNumContStatesPtr(&shabishiyan_M->solverInfo,
      &shabishiyan_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&shabishiyan_M->solverInfo,
      &shabishiyan_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&shabishiyan_M->solverInfo,
      &shabishiyan_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&shabishiyan_M->solverInfo,
      &shabishiyan_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&shabishiyan_M->solverInfo, (&rtmGetErrorStatus
      (shabishiyan_M)));
    rtsiSetRTModelPtr(&shabishiyan_M->solverInfo, shabishiyan_M);
  }

  rtsiSetSimTimeStep(&shabishiyan_M->solverInfo, MAJOR_TIME_STEP);
  shabishiyan_M->intgData.f[0] = shabishiyan_M->odeF[0];
  shabishiyan_M->contStates = ((real_T *) &shabishiyan_X);
  rtsiSetSolverData(&shabishiyan_M->solverInfo, (void *)&shabishiyan_M->intgData);
  rtsiSetSolverName(&shabishiyan_M->solverInfo,"ode1");
  shabishiyan_M->solverInfoPtr = (&shabishiyan_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = shabishiyan_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "shabishiyan_M points to
       static memory which is guaranteed to be non-NULL" */
    shabishiyan_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    shabishiyan_M->Timing.sampleTimes = (&shabishiyan_M->
      Timing.sampleTimesArray[0]);
    shabishiyan_M->Timing.offsetTimes = (&shabishiyan_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    shabishiyan_M->Timing.sampleTimes[0] = (0.0);
    shabishiyan_M->Timing.sampleTimes[1] = (0.005);
    shabishiyan_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    shabishiyan_M->Timing.offsetTimes[0] = (0.0);
    shabishiyan_M->Timing.offsetTimes[1] = (0.0);
    shabishiyan_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(shabishiyan_M, &shabishiyan_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = shabishiyan_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = shabishiyan_M->Timing.perTaskSampleHitsArray;
    shabishiyan_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    shabishiyan_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(shabishiyan_M, -1);
  shabishiyan_M->Timing.stepSize0 = 0.005;
  shabishiyan_M->Timing.stepSize1 = 0.005;
  shabishiyan_M->Timing.stepSize2 = 0.1;

  /* External mode info */
  shabishiyan_M->Sizes.checksums[0] = (1823205528U);
  shabishiyan_M->Sizes.checksums[1] = (1361776196U);
  shabishiyan_M->Sizes.checksums[2] = (77534385U);
  shabishiyan_M->Sizes.checksums[3] = (4207340635U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    shabishiyan_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&shabishiyan_DW.EnabledSubsystem1_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&shabishiyan_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(shabishiyan_M->extModeInfo,
      &shabishiyan_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(shabishiyan_M->extModeInfo,
                        shabishiyan_M->Sizes.checksums);
    rteiSetTPtr(shabishiyan_M->extModeInfo, rtmGetTPtr(shabishiyan_M));
  }

  shabishiyan_M->solverInfoPtr = (&shabishiyan_M->solverInfo);
  shabishiyan_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&shabishiyan_M->solverInfo, 0.005);
  rtsiSetSolverMode(&shabishiyan_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  shabishiyan_M->blockIO = ((void *) &shabishiyan_B);
  (void) memset(((void *) &shabishiyan_B), 0,
                sizeof(B_shabishiyan_T));

  /* parameters */
  shabishiyan_M->defaultParam = ((real_T *)&shabishiyan_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &shabishiyan_X;
    shabishiyan_M->contStates = (x);
    (void) memset((void *)&shabishiyan_X, 0,
                  sizeof(X_shabishiyan_T));
  }

  /* states (dwork) */
  shabishiyan_M->dwork = ((void *) &shabishiyan_DW);
  (void) memset((void *)&shabishiyan_DW, 0,
                sizeof(DW_shabishiyan_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    shabishiyan_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &shabishiyan_M->NonInlinedSFcns.sfcnInfo;
    shabishiyan_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(shabishiyan_M)));
    shabishiyan_M->Sizes.numSampTimes = (3);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &shabishiyan_M->Sizes.numSampTimes);
    shabishiyan_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(shabishiyan_M)
      [0]);
    shabishiyan_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(shabishiyan_M)
      [1]);
    shabishiyan_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr(shabishiyan_M)
      [2]);
    rtssSetTPtrPtr(sfcnInfo,shabishiyan_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(shabishiyan_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(shabishiyan_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(shabishiyan_M));
    rtssSetStepSizePtr(sfcnInfo, &shabishiyan_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(shabishiyan_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &shabishiyan_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &shabishiyan_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &shabishiyan_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &shabishiyan_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &shabishiyan_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &shabishiyan_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &shabishiyan_M->solverInfoPtr);
  }

  shabishiyan_M->Sizes.numSFcns = (4);

  /* register each child */
  {
    (void) memset((void *)&shabishiyan_M->NonInlinedSFcns.childSFunctions[0], 0,
                  4*sizeof(SimStruct));
    shabishiyan_M->childSfunctions =
      (&shabishiyan_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    shabishiyan_M->childSfunctions[0] =
      (&shabishiyan_M->NonInlinedSFcns.childSFunctions[0]);
    shabishiyan_M->childSfunctions[1] =
      (&shabishiyan_M->NonInlinedSFcns.childSFunctions[1]);
    shabishiyan_M->childSfunctions[2] =
      (&shabishiyan_M->NonInlinedSFcns.childSFunctions[2]);
    shabishiyan_M->childSfunctions[3] =
      (&shabishiyan_M->NonInlinedSFcns.childSFunctions[3]);

    /* Level2 S-Function Block: shabishiyan/<Root>/GTS400-PVs Initialization (gts_initialize_m) */
    {
      SimStruct *rts = shabishiyan_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = shabishiyan_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = shabishiyan_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = shabishiyan_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &shabishiyan_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &shabishiyan_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, shabishiyan_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &shabishiyan_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &shabishiyan_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &shabishiyan_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &shabishiyan_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &shabishiyan_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* path info */
      ssSetModelName(rts, "GTS400-PVs Initialization");
      ssSetPath(rts, "shabishiyan/GTS400-PVs Initialization");
      ssSetRTModel(rts,shabishiyan_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &shabishiyan_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 17);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       shabishiyan_P.GTS400PVsInitialization_P17_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &shabishiyan_DW.GTS400PVsInitialization_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &shabishiyan_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &shabishiyan_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &shabishiyan_DW.GTS400PVsInitialization_PWORK);
      }

      /* registration */
      gts_initialize_m(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: shabishiyan/<S5>/GTS GetPos (gts_getpos) */
    {
      SimStruct *rts = shabishiyan_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = shabishiyan_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = shabishiyan_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = shabishiyan_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &shabishiyan_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &shabishiyan_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, shabishiyan_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &shabishiyan_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &shabishiyan_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &shabishiyan_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &shabishiyan_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &shabishiyan_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &shabishiyan_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &shabishiyan_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &shabishiyan_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &shabishiyan_B.GTSGetPos));
        }
      }

      /* path info */
      ssSetModelName(rts, "GTS GetPos");
      ssSetPath(rts, "shabishiyan/Real Control/Pendulum/GTS GetPos");
      ssSetRTModel(rts,shabishiyan_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &shabishiyan_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)shabishiyan_P.GTSGetPos_P1_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &shabishiyan_DW.GTSGetPos_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &shabishiyan_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &shabishiyan_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &shabishiyan_DW.GTSGetPos_PWORK);
      }

      /* registration */
      gts_getpos(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: shabishiyan/<S5>/GTS GetPos1 (gts_getpos) */
    {
      SimStruct *rts = shabishiyan_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = shabishiyan_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = shabishiyan_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = shabishiyan_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &shabishiyan_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &shabishiyan_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, shabishiyan_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &shabishiyan_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &shabishiyan_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &shabishiyan_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &shabishiyan_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &shabishiyan_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &shabishiyan_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &shabishiyan_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &shabishiyan_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &shabishiyan_B.GTSGetPos1));
        }
      }

      /* path info */
      ssSetModelName(rts, "GTS GetPos1");
      ssSetPath(rts, "shabishiyan/Real Control/Pendulum/GTS GetPos1");
      ssSetRTModel(rts,shabishiyan_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &shabishiyan_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)shabishiyan_P.GTSGetPos1_P1_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &shabishiyan_DW.GTSGetPos1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &shabishiyan_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &shabishiyan_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &shabishiyan_DW.GTSGetPos1_PWORK);
      }

      /* registration */
      gts_getpos(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: shabishiyan/<S5>/GTS SetAccVel (gts_setaccvel) */
    {
      SimStruct *rts = shabishiyan_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = shabishiyan_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = shabishiyan_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = shabishiyan_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &shabishiyan_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &shabishiyan_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, shabishiyan_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &shabishiyan_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &shabishiyan_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &shabishiyan_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &shabishiyan_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &shabishiyan_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &shabishiyan_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &shabishiyan_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &shabishiyan_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &shabishiyan_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &shabishiyan_B.VelCof;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &shabishiyan_M->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &shabishiyan_B.AccCof;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "GTS SetAccVel");
      ssSetPath(rts, "shabishiyan/Real Control/Pendulum/GTS SetAccVel");
      ssSetRTModel(rts,shabishiyan_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &shabishiyan_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)shabishiyan_P.GTSSetAccVel_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)shabishiyan_P.GTSSetAccVel_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)shabishiyan_P.GTSSetAccVel_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)shabishiyan_P.GTSSetAccVel_P4_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &shabishiyan_DW.GTSSetAccVel_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &shabishiyan_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &shabishiyan_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &shabishiyan_DW.GTSSetAccVel_PWORK);
      }

      /* registration */
      gts_setaccvel(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  shabishiyan_M->Sizes.numContStates = (4);/* Number of continuous states */
  shabishiyan_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  shabishiyan_M->Sizes.numY = (0);     /* Number of model outputs */
  shabishiyan_M->Sizes.numU = (0);     /* Number of model inputs */
  shabishiyan_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  shabishiyan_M->Sizes.numSampTimes = (3);/* Number of sample times */
  shabishiyan_M->Sizes.numBlocks = (76);/* Number of blocks */
  shabishiyan_M->Sizes.numBlockIO = (25);/* Number of block outputs */
  shabishiyan_M->Sizes.numBlockPrms = (158);/* Sum of parameter "widths" */
  return shabishiyan_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
