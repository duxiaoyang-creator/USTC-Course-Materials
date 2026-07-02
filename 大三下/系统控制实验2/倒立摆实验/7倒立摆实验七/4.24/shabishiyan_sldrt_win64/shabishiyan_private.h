/*
 * shabishiyan_private.h
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

#ifndef RTW_HEADER_shabishiyan_private_h_
#define RTW_HEADER_shabishiyan_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern void gts_initialize_m(SimStruct *rts);
extern void gts_getpos(SimStruct *rts);
extern void gts_setaccvel(SimStruct *rts);

/* private model entry point functions */
extern void shabishiyan_derivatives(void);

#endif                                 /* RTW_HEADER_shabishiyan_private_h_ */
