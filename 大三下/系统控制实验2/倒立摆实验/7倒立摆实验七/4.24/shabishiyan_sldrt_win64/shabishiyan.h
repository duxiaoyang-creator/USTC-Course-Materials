/*
 * shabishiyan.h
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

#ifndef RTW_HEADER_shabishiyan_h_
#define RTW_HEADER_shabishiyan_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#ifndef shabishiyan_COMMON_INCLUDES_
#define shabishiyan_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                                 /* shabishiyan_COMMON_INCLUDES_ */

#include "shabishiyan_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ()
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ()
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define shabishiyan_rtModel            RT_MODEL_shabishiyan_T

/* Block signals (default storage) */
typedef struct {
  real_T TmpRTBAtSum3Inport1;          /* '<Root>/Manual Switch2' */
  real_T GTSGetPos;                    /* '<S5>/GTS GetPos' */
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T Sum6;                         /* '<Root>/Sum6' */
  real_T Integrator[4];                /* '<Root>/Integrator' */
  real_T C[2];                         /* '<Root>/C' */
  real_T TmpRTBAtSum4Inport1;          /* '<Root>/Manual Switch3' */
  real_T GTSGetPos1;                   /* '<S5>/GTS GetPos1' */
  real_T Sum4;                         /* '<Root>/Sum4' */
  real_T Sum5;                         /* '<Root>/Sum5' */
  real_T pipi2;                        /* '<Root>/ -pi~pi2' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T pipi1;                        /* '<Root>/ -pi~pi1' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T ManualSwitch;                 /* '<Root>/Manual Switch' */
  real_T Add[4];                       /* '<Root>/Add' */
  real_T Sum1_k;                       /* '<S6>/Sum1' */
  real_T pipi;                         /* '<S6>/ -pi~pi' */
  real_T AccCof;                       /* '<S5>/AccCof' */
  real_T VelCof;                       /* '<S5>/VelCof' */
  real_T Constant;                     /* '<S7>/Constant' */
  real_T In1;                          /* '<S4>/In1' */
  real_T In2;                          /* '<S4>/In2' */
  boolean_T RelationalOperator1;       /* '<S6>/Relational Operator1' */
  boolean_T LogicalOperator3;          /* '<S6>/Logical Operator3' */
} B_shabishiyan_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T TmpRTBAtSum3Inport1_Buffer0;  /* synthesized block */
  real_T TmpRTBAtSum4Inport1_Buffer0;  /* synthesized block */
  real_T TimeStampA;                   /* '<Root>/Derivative1' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative1' */
  real_T TimeStampB;                   /* '<Root>/Derivative1' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative1' */
  real_T TimeStampA_i;                 /* '<Root>/Derivative' */
  real_T LastUAtTimeA_f;               /* '<Root>/Derivative' */
  real_T TimeStampB_a;                 /* '<Root>/Derivative' */
  real_T LastUAtTimeB_d;               /* '<Root>/Derivative' */
  real_T NextOutput;                   /* '<S1>/White Noise' */
  real_T NextOutput_j;                 /* '<S2>/White Noise' */
  void *GTS400PVsInitialization_PWORK; /* '<Root>/GTS400-PVs Initialization' */
  void *GTSGetPos_PWORK;               /* '<S5>/GTS GetPos' */
  void *GTSGetPos1_PWORK;              /* '<S5>/GTS GetPos1' */
  struct {
    void *LoggedData[2];
  } AP_PWORK;                          /* '<Root>/A&P' */

  struct {
    void *LoggedData;
  } Angle_PWORK;                       /* '<Root>/Angle' */

  struct {
    void *LoggedData;
  } Pos_PWORK;                         /* '<Root>/Pos' */

  struct {
    void *LoggedData[2];
  } real_PWORK;                        /* '<Root>/real' */

  struct {
    void *LoggedData;
  } state_PWORK;                       /* '<Root>/state' */

  void *GTSSetAccVel_PWORK;            /* '<S5>/GTS SetAccVel' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S6>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S6>/Scope1' */

  uint32_T RandSeed;                   /* '<S1>/White Noise' */
  uint32_T RandSeed_h;                 /* '<S2>/White Noise' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S6>/Triggered Subsystem' */
  int8_T EnabledSubsystem1_SubsysRanBC;/* '<S3>/Enabled Subsystem1' */
  boolean_T EnabledSubsystem1_MODE;    /* '<S3>/Enabled Subsystem1' */
} DW_shabishiyan_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<Root>/Integrator' */
} X_shabishiyan_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<Root>/Integrator' */
} XDot_shabishiyan_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[4];      /* '<Root>/Integrator' */
} XDis_shabishiyan_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S6>/Triggered Subsystem' */
} PrevZCX_shabishiyan_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            shabishiyan_B
#define BlockIO                        B_shabishiyan_T
#define rtX                            shabishiyan_X
#define ContinuousStates               X_shabishiyan_T
#define rtXdot                         shabishiyan_XDot
#define StateDerivatives               XDot_shabishiyan_T
#define tXdis                          shabishiyan_XDis
#define StateDisabled                  XDis_shabishiyan_T
#define rtP                            shabishiyan_P
#define Parameters                     P_shabishiyan_T
#define rtDWork                        shabishiyan_DW
#define D_Work                         DW_shabishiyan_T
#define rtPrevZCSigState               shabishiyan_PrevZCX
#define PrevZCSigStates                PrevZCX_shabishiyan_T

/* Parameters (default storage) */
struct P_shabishiyan_T_ {
  real_T BandLimitedWhiteNoise_Cov; /* Mask Parameter: BandLimitedWhiteNoise_Cov
                                     * Referenced by: '<S1>/Output'
                                     */
  real_T BandLimitedWhiteNoise1_Cov;
                                   /* Mask Parameter: BandLimitedWhiteNoise1_Cov
                                    * Referenced by: '<S2>/Output'
                                    */
  real_T BandLimitedWhiteNoise_seed;
                                   /* Mask Parameter: BandLimitedWhiteNoise_seed
                                    * Referenced by: '<S1>/White Noise'
                                    */
  real_T BandLimitedWhiteNoise1_seed;
                                  /* Mask Parameter: BandLimitedWhiteNoise1_seed
                                   * Referenced by: '<S2>/White Noise'
                                   */
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S7>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T PosRef1_Value;                /* Expression: 0.0
                                        * Referenced by: '<Root>/Pos Ref.1'
                                        */
  real_T PosRef2_Value;                /* Expression: 0.1
                                        * Referenced by: '<Root>/Pos Ref.2'
                                        */
  real_T GTS400PVsInitialization_P1_Size[2];
                          /* Computed Parameter: GTS400PVsInitialization_P1_Size
                           * Referenced by: '<Root>/GTS400-PVs Initialization'
                           */
  real_T GTS400PVsInitialization_P1;   /* Expression: open
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P2_Size[2];
                          /* Computed Parameter: GTS400PVsInitialization_P2_Size
                           * Referenced by: '<Root>/GTS400-PVs Initialization'
                           */
  real_T GTS400PVsInitialization_P2;   /* Expression: mode
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P3_Size[2];
                          /* Computed Parameter: GTS400PVsInitialization_P3_Size
                           * Referenced by: '<Root>/GTS400-PVs Initialization'
                           */
  real_T GTS400PVsInitialization_P3[4];/* Expression: servo
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P4_Size[2];
                          /* Computed Parameter: GTS400PVsInitialization_P4_Size
                           * Referenced by: '<Root>/GTS400-PVs Initialization'
                           */
  real_T GTS400PVsInitialization_P4[4];/* Expression: aft
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P5_Size[2];
                          /* Computed Parameter: GTS400PVsInitialization_P5_Size
                           * Referenced by: '<Root>/GTS400-PVs Initialization'
                           */
  real_T GTS400PVsInitialization_P5[3];/* Expression: pid1
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P6_Size[2];
                          /* Computed Parameter: GTS400PVsInitialization_P6_Size
                           * Referenced by: '<Root>/GTS400-PVs Initialization'
                           */
  real_T GTS400PVsInitialization_P6[3];/* Expression: pid2
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P7_Size[2];
                          /* Computed Parameter: GTS400PVsInitialization_P7_Size
                           * Referenced by: '<Root>/GTS400-PVs Initialization'
                           */
  real_T GTS400PVsInitialization_P7[3];/* Expression: pid3
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P8_Size[2];
                          /* Computed Parameter: GTS400PVsInitialization_P8_Size
                           * Referenced by: '<Root>/GTS400-PVs Initialization'
                           */
  real_T GTS400PVsInitialization_P8[3];/* Expression: pid4
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P9_Size[2];
                          /* Computed Parameter: GTS400PVsInitialization_P9_Size
                           * Referenced by: '<Root>/GTS400-PVs Initialization'
                           */
  real_T GTS400PVsInitialization_P9;   /* Expression: enc1
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P10_Size[2];
                         /* Computed Parameter: GTS400PVsInitialization_P10_Size
                          * Referenced by: '<Root>/GTS400-PVs Initialization'
                          */
  real_T GTS400PVsInitialization_P10;  /* Expression: enc2
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P11_Size[2];
                         /* Computed Parameter: GTS400PVsInitialization_P11_Size
                          * Referenced by: '<Root>/GTS400-PVs Initialization'
                          */
  real_T GTS400PVsInitialization_P11;  /* Expression: enc3
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P12_Size[2];
                         /* Computed Parameter: GTS400PVsInitialization_P12_Size
                          * Referenced by: '<Root>/GTS400-PVs Initialization'
                          */
  real_T GTS400PVsInitialization_P12;  /* Expression: enc4
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P13_Size[2];
                         /* Computed Parameter: GTS400PVsInitialization_P13_Size
                          * Referenced by: '<Root>/GTS400-PVs Initialization'
                          */
  real_T GTS400PVsInitialization_P13;  /* Expression: lmt1
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P14_Size[2];
                         /* Computed Parameter: GTS400PVsInitialization_P14_Size
                          * Referenced by: '<Root>/GTS400-PVs Initialization'
                          */
  real_T GTS400PVsInitialization_P14;  /* Expression: lmt2
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P15_Size[2];
                         /* Computed Parameter: GTS400PVsInitialization_P15_Size
                          * Referenced by: '<Root>/GTS400-PVs Initialization'
                          */
  real_T GTS400PVsInitialization_P15;  /* Expression: lmt3
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P16_Size[2];
                         /* Computed Parameter: GTS400PVsInitialization_P16_Size
                          * Referenced by: '<Root>/GTS400-PVs Initialization'
                          */
  real_T GTS400PVsInitialization_P16;  /* Expression: lmt4
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T GTS400PVsInitialization_P17_Size[2];
                         /* Computed Parameter: GTS400PVsInitialization_P17_Size
                          * Referenced by: '<Root>/GTS400-PVs Initialization'
                          */
  real_T GTS400PVsInitialization_P17;  /* Expression: cdno
                                        * Referenced by: '<Root>/GTS400-PVs Initialization'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T TmpRTBAtSum3Inport1_InitialCondition;/* Expression: 0
                                               * Referenced by:
                                               */
  real_T GTSGetPos_P1_Size[2];         /* Computed Parameter: GTSGetPos_P1_Size
                                        * Referenced by: '<S5>/GTS GetPos'
                                        */
  real_T GTSGetPos_P1;                 /* Expression: axis
                                        * Referenced by: '<S5>/GTS GetPos'
                                        */
  real_T PosEncoder_Gain;              /* Expression: 0.46 / 37500.0
                                        * Referenced by: '<S5>/Pos Encoder'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T C_Gain[8];                    /* Expression: [1 0 0 0;0 0 1 0]
                                        * Referenced by: '<Root>/C'
                                        */
  real_T AngleRef1_Value;              /* Expression: pi
                                        * Referenced by: '<Root>/Angle Ref.1'
                                        */
  real_T TmpRTBAtSum4Inport1_InitialCondition;/* Expression: 0
                                               * Referenced by:
                                               */
  real_T GTSGetPos1_P1_Size[2];        /* Computed Parameter: GTSGetPos1_P1_Size
                                        * Referenced by: '<S5>/GTS GetPos1'
                                        */
  real_T GTSGetPos1_P1;                /* Expression: axis
                                        * Referenced by: '<S5>/GTS GetPos1'
                                        */
  real_T AngleEncoder_Gain;            /* Expression: -(pi * 2.0 / 2400)
                                        * Referenced by: '<S5>/Angle Encoder'
                                        */
  real_T AngleRef_Value;               /* Expression: pi
                                        * Referenced by: '<Root>/Angle Ref.'
                                        */
  real_T PosRef_Value;                 /* Expression: 0.0
                                        * Referenced by: '<Root>/Pos Ref.'
                                        */
  real_T A_Gain[16];         /* Expression: [0 1 0 0;0 0 0 0;0 0 0 1;0 0 29.4 0]
                              * Referenced by: '<Root>/A'
                              */
  real_T H_Gain[8];
                 /* Expression: [18.06 -3.70;81.37 -29.22;1.87 15.94;9.72 90.20]
                  * Referenced by: '<Root>/H'
                  */
  real_T K_Gain[4];            /* Expression: [-13.8776 -12.1769 53.0925 9.7256]
                                * Referenced by: '<Root>/K'
                                */
  real_T B_Gain[4];                    /* Expression: [0; 1; 0; 3]
                                        * Referenced by: '<Root>/B'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 50
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -50
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Constant1_Value_i;            /* Expression: pi
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T EntryAngle_Value;             /* Expression: 10*pi/180
                                        * Referenced by: '<S6>/EntryAngle'
                                        */
  real_T GTSSetAccVel_P1_Size[2];    /* Computed Parameter: GTSSetAccVel_P1_Size
                                      * Referenced by: '<S5>/GTS SetAccVel'
                                      */
  real_T GTSSetAccVel_P1;              /* Expression: Axis
                                        * Referenced by: '<S5>/GTS SetAccVel'
                                        */
  real_T GTSSetAccVel_P2_Size[2];    /* Computed Parameter: GTSSetAccVel_P2_Size
                                      * Referenced by: '<S5>/GTS SetAccVel'
                                      */
  real_T GTSSetAccVel_P2;              /* Expression: vel
                                        * Referenced by: '<S5>/GTS SetAccVel'
                                        */
  real_T GTSSetAccVel_P3_Size[2];    /* Computed Parameter: GTSSetAccVel_P3_Size
                                      * Referenced by: '<S5>/GTS SetAccVel'
                                      */
  real_T GTSSetAccVel_P3;              /* Expression: pos
                                        * Referenced by: '<S5>/GTS SetAccVel'
                                        */
  real_T GTSSetAccVel_P4_Size[2];    /* Computed Parameter: GTSSetAccVel_P4_Size
                                      * Referenced by: '<S5>/GTS SetAccVel'
                                      */
  real_T GTSSetAccVel_P4;              /* Expression: limit
                                        * Referenced by: '<S5>/GTS SetAccVel'
                                        */
  real_T AccCof_Gain;             /* Expression: 0.001 * 0.001/ (0.46 / 37500.0)
                                   * Referenced by: '<S5>/AccCof'
                                   */
  real_T VelCof_Gain;                  /* Expression: 0.001 / (0.46 / 37500.0)
                                        * Referenced by: '<S5>/VelCof'
                                        */
  real_T StopAngle_Value;              /* Expression: 20*pi/180
                                        * Referenced by: '<S6>/StopAngle'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T WhiteNoise_Mean_l;            /* Expression: 0
                                        * Referenced by: '<S2>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_e;         /* Computed Parameter: WhiteNoise_StdDev_e
                                       * Referenced by: '<S2>/White Noise'
                                       */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
                              */
  uint8_T ManualSwitch2_CurrentSetting;
                             /* Computed Parameter: ManualSwitch2_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch2'
                              */
  uint8_T ManualSwitch3_CurrentSetting;
                             /* Computed Parameter: ManualSwitch3_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch3'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_shabishiyan_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[3];
    SimStruct childSFunctions[4];
    SimStruct *childSFunctionPtrs[4];
    struct _ssBlkInfo2 blkInfo2[4];
    struct _ssSFcnModelMethods2 methods2[4];
    struct _ssSFcnModelMethods3 methods3[4];
    struct _ssSFcnModelMethods4 methods4[4];
    struct _ssStatesInfo2 statesInfo2[4];
    ssPeriodicStatesInfo periodicStatesInfo[4];
    struct _ssPortInfo2 inputOutputPortInfo2[4];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[17];
      mxArray *params[17];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;
  } NonInlinedSFcns;

  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][4];
  ODE1_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_shabishiyan_T shabishiyan_P;

/* Block signals (default storage) */
extern B_shabishiyan_T shabishiyan_B;

/* Continuous states (default storage) */
extern X_shabishiyan_T shabishiyan_X;

/* Block states (default storage) */
extern DW_shabishiyan_T shabishiyan_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_shabishiyan_T shabishiyan_PrevZCX;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void shabishiyan_initialize(void);
extern void shabishiyan_output0(void);
extern void shabishiyan_update0(void);
extern void shabishiyan_output2(void);
extern void shabishiyan_update2(void);
extern void shabishiyan_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern shabishiyan_rtModel *shabishiyan(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_shabishiyan_T *const shabishiyan_M;

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
 * '<Root>' : 'shabishiyan'
 * '<S1>'   : 'shabishiyan/Band-Limited White Noise'
 * '<S2>'   : 'shabishiyan/Band-Limited White Noise1'
 * '<S3>'   : 'shabishiyan/Real Control'
 * '<S4>'   : 'shabishiyan/Real Control/Enabled Subsystem1'
 * '<S5>'   : 'shabishiyan/Real Control/Pendulum'
 * '<S6>'   : 'shabishiyan/Real Control/Trigger and Safty'
 * '<S7>'   : 'shabishiyan/Real Control/Trigger and Safty/Triggered Subsystem'
 */
#endif                                 /* RTW_HEADER_shabishiyan_h_ */
