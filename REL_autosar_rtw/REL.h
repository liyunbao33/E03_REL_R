/*
 * File: REL.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct 12 10:14:46 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REL_h_
#define RTW_HEADER_REL_h_
#ifndef REL_COMMON_INCLUDES_
#define REL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_REL.h"
#endif                                 /* REL_COMMON_INCLUDES_ */

#include "REL_types.h"
#include "Rte_Type.h"

/* Block states (default storage) for system '<S3>/FRDoorRlsDriver' */
typedef struct {
  uint16 temporalCounter_i1;           /* '<S3>/FRDoorRlsDriver' */
  uint8 is_active_c19_DoorRlsDriver;   /* '<S3>/FRDoorRlsDriver' */
  uint8 is_c19_DoorRlsDriver;          /* '<S3>/FRDoorRlsDriver' */
  uint8 is_Normal;                     /* '<S3>/FRDoorRlsDriver' */
  uint8 is_MainProgress;               /* '<S3>/FRDoorRlsDriver' */
  uint8 is_Release;                    /* '<S3>/FRDoorRlsDriver' */
  uint8 is_Step2_Open;                 /* '<S3>/FRDoorRlsDriver' */
  uint8 is_MainProgress_a;             /* '<S3>/FRDoorRlsDriver' */
  uint8 is_Release_h;                  /* '<S3>/FRDoorRlsDriver' */
  uint8 is_Step2_Open_f;               /* '<S3>/FRDoorRlsDriver' */
  uint8 SL_e_CycleCount;               /* '<S3>/FRDoorRlsDriver' */
  uint8 SL_e_DoorRlsDelayTime;         /* '<S3>/FRDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_prev;        /* '<S3>/FRDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_start;       /* '<S3>/FRDoorRlsDriver' */
} DW_FRDoorRlsDriver_REL_T;

/* Block states (default storage) for system '<S3>/FRDoorRlsReq' */
typedef struct {
  uint8 is_active_c5_DoorRlsReq;       /* '<S3>/FRDoorRlsReq' */
  uint8 is_SwValid;                    /* '<S3>/FRDoorRlsReq' */
  uint8 is_RlsReq;                     /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger;                    /* '<S3>/FRDoorRlsReq' */
  uint8 is_DoorLock;                   /* '<S3>/FRDoorRlsReq' */
  uint8 is_RlsReq_i;                   /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger_j;                  /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i1;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i2;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i3;            /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorInBtnValid;         /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid;        /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorInBtnSts_prev;      /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorInBtnSts_start;     /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorInBtnValid_prev;    /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorInBtnValid_start;   /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid_prev;   /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid_start;  /* '<S3>/FRDoorRlsReq' */
} DW_FRDoorRlsReq_REL_T;

/* Block signals (default storage) */
typedef struct tag_B_REL_T {
  uint8 SO_e_DoorRlsDelayTime;         /* '<S3>/RRDoorRlsReq' */
  uint8 SO_e_DoorRlsDelayTime_d;       /* '<S3>/FRDoorRlsReq' */
  Boolean VbOUT_HWA_FRDoorFullOpen_flg_Vb;
     /* '<S2>/VbOUT_HWA_FRDoorFullOpen_flg_VbOUT_HWA_FRDoorFullOpen_flg_read' */
  Boolean VbINP_HWA_FRDoorAjar_flg_VbINP_;
             /* '<S2>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg_read' */
  Boolean VbOUT_HWA_RRDoorFullOpen_flg_Vb;
     /* '<S2>/VbOUT_HWA_RRDoorFullOpen_flg_VbOUT_HWA_RRDoorFullOpen_flg_read' */
  Boolean VbINP_HWA_RRDoorAjar_flg_VbINP_;
             /* '<S2>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg_read' */
  boolean SO_b_DoorRlsReq;             /* '<S3>/RRDoorRlsReq' */
  boolean SO_b_MotorA;                 /* '<S3>/RRDoorRlsDriver' */
  boolean SO_b_MotorB;                 /* '<S3>/RRDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_i;           /* '<S3>/FRDoorRlsReq' */
  boolean SO_b_MotorA_f;               /* '<S3>/FRDoorRlsDriver' */
  boolean SO_b_MotorB_c;               /* '<S3>/FRDoorRlsDriver' */
  boolean SO_b_FRDoorInBtnSts;         /* '<S3>/DoorSwSts' */
  boolean SO_b_RRDoorInBtnSts;         /* '<S3>/DoorSwSts' */
  boolean SO_b_FRDoorHndBtnSts;        /* '<S3>/DoorSwSts' */
  boolean SO_b_RRDoorHndBtnSts;        /* '<S3>/DoorSwSts' */
  Mot_Cmd_E SO_e_MotorCmd;             /* '<S3>/RRDoorRlsDriver' */
  Mot_Cmd_E SO_e_MotorCmd_m;           /* '<S3>/FRDoorRlsDriver' */
} B_REL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_REL_T {
  uint16 temporalCounter_i1;           /* '<S3>/DoorSwSts' */
  uint8 E03_REL_R;                     /* '<S3>/Data Store Memory' */
  uint8 is_active_c23_REL;             /* '<S3>/DoorSwSts' */
  uint8 is_c23_REL;                    /* '<S3>/DoorSwSts' */
  uint8 is_active_c3_REL;              /* '<S3>/DoorRatSts' */
  boolean SI_b_CrashSts_prev;          /* '<S3>/DoorSwSts' */
  boolean SI_b_CrashSts_start;         /* '<S3>/DoorSwSts' */
  DW_FRDoorRlsReq_REL_T sf_RRDoorRlsReq;/* '<S3>/RRDoorRlsReq' */
  DW_FRDoorRlsDriver_REL_T sf_RRDoorRlsDriver;/* '<S3>/RRDoorRlsDriver' */
  DW_FRDoorRlsReq_REL_T sf_FRDoorRlsReq;/* '<S3>/FRDoorRlsReq' */
  DW_FRDoorRlsDriver_REL_T sf_FRDoorRlsDriver;/* '<S3>/FRDoorRlsDriver' */
} DW_REL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const HndPos_Sts_E DataTypeConversion15;/* '<S3>/Data Type Conversion15' */
  const HndPos_Sts_E DataTypeConversion17;/* '<S3>/Data Type Conversion17' */
  const Gear_Posn_E DataTypeConversion14;/* '<S3>/Data Type Conversion14' */
} ConstB_REL_T;

/* Block signals (default storage) */
extern B_REL_T REL_B;

/* Block states (default storage) */
extern DW_REL_T REL_DW;
extern const ConstB_REL_T REL_ConstB;  /* constant block i/o */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Conversion3' : Unused code path elimination
 * Block '<S3>/Data Type Conversion6' : Unused code path elimination
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
 * '<Root>' : 'REL'
 * '<S1>'   : 'REL/REL_Init'
 * '<S2>'   : 'REL/REL_Step_sys'
 * '<S3>'   : 'REL/REL_Step_sys/REL'
 * '<S4>'   : 'REL/REL_Step_sys/REL/DoorRatSts'
 * '<S5>'   : 'REL/REL_Step_sys/REL/DoorSwSts'
 * '<S6>'   : 'REL/REL_Step_sys/REL/FRDoorRlsDriver'
 * '<S7>'   : 'REL/REL_Step_sys/REL/FRDoorRlsReq'
 * '<S8>'   : 'REL/REL_Step_sys/REL/OFF '
 * '<S9>'   : 'REL/REL_Step_sys/REL/RRDoorRlsDriver'
 * '<S10>'  : 'REL/REL_Step_sys/REL/RRDoorRlsReq'
 * '<S11>'  : 'REL/REL_Step_sys/REL/Recycle Bin'
 */
#endif                                 /* RTW_HEADER_REL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
