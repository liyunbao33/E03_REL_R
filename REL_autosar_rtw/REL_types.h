/*
 * File: REL_types.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct 19 17:38:48 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REL_types_h_
#define RTW_HEADER_REL_types_h_
#include "Rte_Type.h"
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_Door_Sts_E_
#define DEFINED_TYPEDEF_FOR_Door_Sts_E_

typedef uint8 Door_Sts_E;

/* enum Door_Sts_E */
#define Door_Lock                      ((Door_Sts_E)0U)          /* Default value */
#define Door_Unlock                    ((Door_Sts_E)1U)
#define Door_SuperLock                 ((Door_Sts_E)2U)
#define Door_Unknown                   ((Door_Sts_E)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Child_Sts_E_
#define DEFINED_TYPEDEF_FOR_Child_Sts_E_

typedef uint8 Child_Sts_E;

/* enum Child_Sts_E */
#define Child_Unlock                   ((Child_Sts_E)0U)         /* Default value */
#define Child_Lock                     ((Child_Sts_E)1U)
#define Child_SuperLock                ((Child_Sts_E)2U)
#define Child_Unknown                  ((Child_Sts_E)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Rat_Sts_E_
#define DEFINED_TYPEDEF_FOR_Rat_Sts_E_

typedef uint8 Rat_Sts_E;

/* enum Rat_Sts_E */
#define Rat_Invalid                    ((Rat_Sts_E)0U)           /* Default value */
#define Rat_All_Lock                   ((Rat_Sts_E)1U)
#define Rat_Half_Lock                  ((Rat_Sts_E)2U)
#define Rat_Unlock                     ((Rat_Sts_E)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Gear_Posn_E_
#define DEFINED_TYPEDEF_FOR_Gear_Posn_E_

typedef uint8 Gear_Posn_E;

/* enum Gear_Posn_E */
#define Gear_Reserved1                 ((Gear_Posn_E)0U)         /* Default value */
#define Gear_P                         ((Gear_Posn_E)1U)
#define Gear_R                         ((Gear_Posn_E)2U)
#define Gear_N                         ((Gear_Posn_E)3U)
#define Gear_D                         ((Gear_Posn_E)4U)
#define Gear_Reserved2                 ((Gear_Posn_E)5U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_HndPos_Sts_E_
#define DEFINED_TYPEDEF_FOR_HndPos_Sts_E_

typedef uint8 HndPos_Sts_E;

/* enum HndPos_Sts_E */
#define Hnd_Fold                       ((HndPos_Sts_E)0U)        /* Default value */
#define Hnd_Unfold                     ((HndPos_Sts_E)1U)
#define Hnd_Half_Unfold                ((HndPos_Sts_E)2U)
#define Hnd_Error                      ((HndPos_Sts_E)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Unlock_Req_E_
#define DEFINED_TYPEDEF_FOR_Unlock_Req_E_

typedef uint8 Unlock_Req_E;

/* enum Unlock_Req_E */
#define Unlock_Idle                    ((Unlock_Req_E)0U)        /* Default value */
#define Unlock_Req                     ((Unlock_Req_E)1U)
#define Unlock_PE                      ((Unlock_Req_E)2U)
#endif
#endif                                 /* RTW_HEADER_REL_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
