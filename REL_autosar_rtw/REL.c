/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Oct 24 16:04:23 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REL.h"
#include "rtwtypes.h"
#include "REL_types.h"
#include "Rte_Type.h"
#include "REL_private.h"

/* Named constants for Chart: '<S3>/FRDoorRlsReq' */
#define REL_IN_DoorLock                ((uint8)1U)
#define REL_IN_DoorUnlock              ((uint8)2U)
#define REL_IN_DoorUnlock_a            ((uint8)1U)
#define REL_IN_Error                   ((uint8)3U)
#define REL_IN_Idle                    ((uint8)1U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8)0U)
#define REL_IN_Once                    ((uint8)2U)
#define REL_IN_Release                 ((uint8)4U)
#define REL_IN_Release_i               ((uint8)2U)
#define REL_IN_Trigger                 ((uint8)2U)
#define REL_IN_Twice                   ((uint8)3U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8)1U)
#define REL_IN_NoCrash                 ((uint8)2U)

/* Block signals (default storage) */
B_REL_T REL_B;

/* Block states (default storage) */
DW_REL_T REL_DW;

/* Forward declaration for local functions */
static float64 REL_GetDoorRatSts(float64 ajar, float64 open);
static uint8 REL_safe_cast_to_Rat_Sts_E(uint8 input);

/*
 * System initialize for atomic system:
 *    '<S3>/FRDoorRlsReq'
 *    '<S3>/RRDoorRlsReq'
 */
void REL_FRDoorRlsReq_Init(boolean *rty_SO_b_DoorRlsReq, Unlock_Req_E
  *rty_SO_m_UnlockReq)
{
  *rty_SO_b_DoorRlsReq = false;
  *rty_SO_m_UnlockReq = Unlock_Idle;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FRDoorRlsReq'
 *    '<S3>/RRDoorRlsReq'
 */
void REL_FRDoorRlsReq(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
                      Door_Sts_E rtu_SI_m_DoorLockSts, Rat_Sts_E
                      rtu_SI_m_DoorRatSts, boolean rtu_SI_b_DoorInBtnSts,
                      boolean rtu_SI_b_DoorHndBtnSts, Child_Sts_E
                      rtu_SI_m_ChildLckSts, boolean *rty_SO_b_DoorRlsReq,
                      DW_FRDoorRlsReq_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 7U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->temporalCounter_i3 < 7U) {
    localDW->temporalCounter_i3++;
  }

  localDW->SI_b_DoorInBtnSts_prev = localDW->SI_b_DoorInBtnSts_start;
  localDW->SI_b_DoorInBtnSts_start = rtu_SI_b_DoorInBtnSts;
  localDW->SL_b_DoorInBtnValid_prev = localDW->SL_b_DoorInBtnValid_start;
  localDW->SL_b_DoorInBtnValid_start = localDW->SL_b_DoorInBtnValid;
  localDW->SL_b_DoorHndBtnValid_prev = localDW->SL_b_DoorHndBtnValid_start;
  localDW->SL_b_DoorHndBtnValid_start = localDW->SL_b_DoorHndBtnValid;

  /* Chart: '<S3>/FRDoorRlsReq' */
  if (localDW->is_active_c5_DoorRlsReq == 0U) {
    localDW->SI_b_DoorInBtnSts_prev = rtu_SI_b_DoorInBtnSts;
    localDW->is_active_c5_DoorRlsReq = 1U;
    localDW->is_SwValid = REL_IN_Idle;
    localDW->SL_b_DoorInBtnValid = false;
    localDW->is_RlsReq = REL_IN_Idle;
    localDW->is_RlsReq_g = REL_IN_Idle;
    localDW->SL_b_DoorHndBtnValid = rtu_SI_b_DoorHndBtnSts;
  } else {
    switch (localDW->is_SwValid) {
     case REL_IN_Idle:
      if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
          localDW->SI_b_DoorInBtnSts_start) {
        localDW->is_SwValid = REL_IN_Once;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case REL_IN_Once:
      if ((localDW->temporalCounter_i1 >= 20) &&
          ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start)
           && localDW->SI_b_DoorInBtnSts_start)) {
        localDW->is_SwValid = REL_IN_Twice;
        localDW->temporalCounter_i1 = 0U;
        localDW->SL_b_DoorInBtnValid = true;
      } else if (localDW->temporalCounter_i1 >= 200) {
        localDW->is_SwValid = REL_IN_Idle;
        localDW->SL_b_DoorInBtnValid = false;
      }
      break;

     default:
      /* case IN_Twice: */
      if (localDW->temporalCounter_i1 >= 3) {
        localDW->is_SwValid = REL_IN_Idle;
        localDW->SL_b_DoorInBtnValid = false;
      }
      break;
    }

    if (localDW->is_RlsReq == REL_IN_Idle) {
      Boolean tmp;
      tmp = !rtu_SI_b_EspVehSpdVld;
      if (((rtu_SI_e_EspVehSpd < 5) && tmp && (rtu_SI_m_ChildLckSts ==
            Child_Unlock) && ((localDW->SL_b_DoorInBtnValid_prev !=
             localDW->SL_b_DoorInBtnValid_start) &&
                              localDW->SL_b_DoorInBtnValid_start)) ||
          ((rtu_SI_e_EspVehSpd < 5) && tmp && (rtu_SI_m_ChildLckSts ==
            Child_Unlock) && (rtu_SI_m_DoorLockSts == Door_Unlock) &&
           ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start)
            && localDW->SI_b_DoorInBtnSts_start))) {
        localDW->is_RlsReq = REL_IN_Trigger;
        switch (rtu_SI_m_DoorLockSts) {
         case Door_Lock:
          localDW->is_Trigger = REL_IN_DoorLock;
          break;

         case Door_Unlock:
          localDW->is_Trigger = REL_IN_DoorUnlock;
          break;

         default:
          localDW->is_Trigger = REL_IN_Error;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((rtu_SI_e_EspVehSpd >= 5) && (!rtu_SI_b_EspVehSpdVld)) ||
               (rtu_SI_m_ChildLckSts != Child_Unlock) || ((rtu_SI_m_DoorLockSts ==
      Door_Unlock) && (rtu_SI_m_DoorRatSts == Rat_Unlock))) {
      localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD;
      localDW->is_RlsReq = REL_IN_Idle;
    } else {
      switch (localDW->is_Trigger) {
       case REL_IN_DoorLock:
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_Trigger = REL_IN_Release;
          localDW->temporalCounter_i2 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_Trigger = REL_IN_Release;
          localDW->temporalCounter_i2 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;

       case REL_IN_Error:
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_RlsReq = REL_IN_Idle;
        break;

       default:
        /* case IN_Release: */
        if (localDW->temporalCounter_i2 >= 5) {
          *rty_SO_b_DoorRlsReq = false;
          localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_RlsReq = REL_IN_Idle;
        }
        break;
      }
    }

    if (localDW->is_RlsReq_g == REL_IN_Idle) {
      if ((rtu_SI_e_EspVehSpd < 5) && (!rtu_SI_b_EspVehSpdVld) &&
          (rtu_SI_m_DoorLockSts == Door_Unlock) &&
          ((localDW->SL_b_DoorHndBtnValid_prev !=
            localDW->SL_b_DoorHndBtnValid_start) &&
           localDW->SL_b_DoorHndBtnValid_start)) {
        localDW->is_RlsReq_g = REL_IN_Trigger;
        localDW->is_Trigger_d = REL_IN_DoorUnlock_a;
      }

      /* case IN_Trigger: */
    } else if (((rtu_SI_e_EspVehSpd >= 5) && (!rtu_SI_b_EspVehSpdVld)) ||
               (rtu_SI_m_DoorLockSts != Door_Unlock) || (rtu_SI_m_DoorRatSts ==
                Rat_Unlock)) {
      localDW->is_Trigger_d = REL_IN_NO_ACTIVE_CHILD;
      localDW->is_RlsReq_g = REL_IN_Idle;
    } else if (localDW->is_Trigger_d == REL_IN_DoorUnlock_a) {
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_d = REL_IN_Release_i;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }

      /* case IN_Release: */
    } else if (localDW->temporalCounter_i3 >= 5) {
      *rty_SO_b_DoorRlsReq = false;
      localDW->is_Trigger_d = REL_IN_NO_ACTIVE_CHILD;
      localDW->is_RlsReq_g = REL_IN_Idle;
    }

    localDW->SL_b_DoorHndBtnValid = rtu_SI_b_DoorHndBtnSts;
  }

  /* End of Chart: '<S3>/FRDoorRlsReq' */
}

/* Function for Chart: '<S3>/DoorRatSts' */
static float64 REL_GetDoorRatSts(float64 ajar, float64 open)
{
  float64 status;
  if ((ajar == 0.0) && (open == 0.0)) {
    status = 1.0;
  } else if ((ajar == 1.0) && (open == 0.0)) {
    status = 2.0;
  } else if ((ajar == 1.0) && (open == 1.0)) {
    status = 3.0;
  } else {
    status = 0.0;
  }

  return status;
}

static uint8 REL_safe_cast_to_Rat_Sts_E(uint8 input)
{
  uint8 output;

  /* Initialize output value to default value for Rat_Sts_E (Rat_Invalid) */
  output = 0U;
  if (input <= 3) {
    /* Set output value to input value if it is a member of Rat_Sts_E */
    output = input;
  }

  return output;
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  /* local block i/o variables */
  UInt8 rtb_TmpSignalConversionAtVeOUT_;
  Boolean rtb_TmpSignalConversionAtVbINP_;
  Rat_Sts_E rtb_SO_m_FRDoorRatSts;
  Rat_Sts_E rtb_SO_m_RRDoorRatSts;
  UInt8 tmpRead;
  UInt8 tmpRead_2;
  UInt8 tmpRead_3;
  UInt8 tmpRead_6;
  UInt8 tmpRead_7;
  Boolean tmpRead_0;
  Boolean tmpRead_1;
  Boolean tmpRead_4;
  Boolean tmpRead_5;

  /* Inport: '<Root>/VeOUT_DLK_RRDoorLockSts_sig_VeOUT_DLK_RRDoorLockSts_sig' */
  (void)Rte_Read_VeOUT_DLK_RRDoorLockSts_sig_VeOUT_DLK_RRDoorLockSts_sig
    (&tmpRead_7);

  /* Inport: '<Root>/VeOUT_DLK_FRDoorLockSts_sig_VeOUT_DLK_FRDoorLockSts_sig' */
  (void)Rte_Read_VeOUT_DLK_FRDoorLockSts_sig_VeOUT_DLK_FRDoorLockSts_sig
    (&tmpRead_6);

  /* Inport: '<Root>/VbOUT_HWA_RRDoorFullOpen_flg_VbOUT_HWA_RRDoorFullOpen_flg' */
  (void)Rte_Read_VbOUT_HWA_RRDoorFullOpen_flg_VbOUT_HWA_RRDoorFullOpen_flg
    (&tmpRead_5);

  /* Inport: '<Root>/VbOUT_HWA_FRDoorFullOpen_flg_VbOUT_HWA_FRDoorFullOpen_flg' */
  (void)Rte_Read_VbOUT_HWA_FRDoorFullOpen_flg_VbOUT_HWA_FRDoorFullOpen_flg
    (&tmpRead_4);

  /* Inport: '<Root>/VeINP_HWA_RRChildrenProtectSwitch_sig_VeINP_HWA_RRChildrenProtectSwitch_sig' */
  (void)
    Rte_Read_VeINP_HWA_RRChildrenProtectSwitch_sig_VeINP_HWA_RRChildrenProtectSwitch_sig
    (&tmpRead_3);

  /* Inport: '<Root>/VeINP_CAN_ACU3CrashOutputSts_sig_VeINP_CAN_ACU3CrashOutputSts_sig' */
  (void)
    Rte_Read_VeINP_CAN_ACU3CrashOutputSts_sig_VeINP_CAN_ACU3CrashOutputSts_sig
    (&tmpRead_2);

  /* Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg' */
  (void)Rte_Read_VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg(&tmpRead_1);

  /* Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg' */
  (void)Rte_Read_VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
   *  Constant: '<S3>/Constant'
   */
  REL_DW.E03_REL_R = 2U;

  /* Outport: '<Root>/VeOUT_REL_RRChildrenProtectSwitch_sig_VeOUT_REL_RRChildrenProtectSwitch_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  (void)
    Rte_Write_VeOUT_REL_RRChildrenProtectSwitch_sig_VeOUT_REL_RRChildrenProtectSwitch_sig
    (tmpRead_3);

  /* Chart: '<S3>/DoorRatSts' incorporates:
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg_read'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg_read'
   *  SignalConversion generated from: '<S2>/VbOUT_HWA_FRDoorFullOpen_flg_VbOUT_HWA_FRDoorFullOpen_flg_read'
   *  SignalConversion generated from: '<S2>/VbOUT_HWA_RRDoorFullOpen_flg_VbOUT_HWA_RRDoorFullOpen_flg_read'
   */
  if (REL_DW.is_active_c3_REL == 0U) {
    float64 tmp;
    REL_DW.is_active_c3_REL = 1U;
    tmp = REL_GetDoorRatSts((float64)tmpRead_0, (float64)tmpRead_4);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)tmpRead_1, (float64)tmpRead_5);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        rtb_SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }
  } else {
    float64 tmp;
    tmp = REL_GetDoorRatSts((float64)tmpRead_0, (float64)tmpRead_4);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)tmpRead_1, (float64)tmpRead_5);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        rtb_SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }
  }

  /* End of Chart: '<S3>/DoorRatSts' */

  /* Chart: '<S3>/DoorSwSts' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  if (REL_DW.temporalCounter_i1 < 1023U) {
    REL_DW.temporalCounter_i1++;
  }

  REL_DW.SI_b_CrashSts_prev = REL_DW.SI_b_CrashSts_start;
  REL_DW.SI_b_CrashSts_start = (tmpRead_2 != 0);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg
    (&REL_B.SO_b_FRDoorInBtnSts);

  /* Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg
    (&REL_B.SO_b_RRDoorInBtnSts);

  /* Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg
    (&REL_B.SO_b_FRDoorHndBtnSts);

  /* Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg
    (&REL_B.SO_b_RRDoorHndBtnSts);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/DoorSwSts' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg'
   */
  if (REL_DW.is_active_c23_REL == 0U) {
    REL_DW.SI_b_CrashSts_prev = (tmpRead_2 != 0);
    REL_DW.is_active_c23_REL = 1U;
    REL_DW.is_c23_REL = REL_IN_NoCrash;
  } else if (REL_DW.is_c23_REL == REL_IN_Crash) {
    if (REL_DW.temporalCounter_i1 >= 600) {
      REL_DW.is_c23_REL = REL_IN_NoCrash;
    } else {
      REL_B.SO_b_FRDoorInBtnSts = false;
      REL_B.SO_b_RRDoorInBtnSts = false;
      REL_B.SO_b_FRDoorHndBtnSts = false;
      REL_B.SO_b_RRDoorHndBtnSts = false;
    }

    /* case IN_NoCrash: */
  } else if ((REL_DW.SI_b_CrashSts_prev != REL_DW.SI_b_CrashSts_start) &&
             REL_DW.SI_b_CrashSts_start) {
    REL_DW.is_c23_REL = REL_IN_Crash;
    REL_DW.temporalCounter_i1 = 0U;
    REL_B.SO_b_FRDoorInBtnSts = false;
    REL_B.SO_b_RRDoorInBtnSts = false;
    REL_B.SO_b_FRDoorHndBtnSts = false;
    REL_B.SO_b_RRDoorHndBtnSts = false;
  }

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VeOUT_PDU_PowerMode_sig_VeOUT_PDU_PowerMode_sig' */
  (void)Rte_Read_VeOUT_PDU_PowerMode_sig_VeOUT_PDU_PowerMode_sig(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* SignalConversion generated from: '<S2>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh_read' incorporates:
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  (void)Rte_Read_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh
    (&rtb_TmpSignalConversionAtVeOUT_);

  /* SignalConversion generated from: '<S2>/VbINP_CAN_VehicleSpeedVSOSigValidData_flg_VbINP_CAN_VehicleSpeedVSOSigValidData_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CAN_VehicleSpeedVSOSigValidData_flg_VbINP_CAN_VehicleSpeedVSOSigValidData_flg'
   */
  (void)
    Rte_Read_VbINP_CAN_VehicleSpeedVSOSigValidData_flg_VbINP_CAN_VehicleSpeedVSOSigValidData_flg
    (&rtb_TmpSignalConversionAtVbINP_);

  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion12'
   */
  REL_FRDoorRlsReq(rtb_TmpSignalConversionAtVeOUT_,
                   rtb_TmpSignalConversionAtVbINP_, tmpRead_6,
                   rtb_SO_m_FRDoorRatSts, REL_B.SO_b_FRDoorInBtnSts,
                   REL_B.SO_b_FRDoorHndBtnSts, Child_Unlock,
                   &REL_B.SO_b_DoorRlsReq_j, &REL_DW.sf_FRDoorRlsReq);

  /* Chart: '<S3>/RRDoorRlsReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  REL_FRDoorRlsReq(rtb_TmpSignalConversionAtVeOUT_,
                   rtb_TmpSignalConversionAtVbINP_, tmpRead_7,
                   rtb_SO_m_RRDoorRatSts, REL_B.SO_b_RRDoorInBtnSts,
                   REL_B.SO_b_RRDoorHndBtnSts, tmpRead_3, &REL_B.SO_b_DoorRlsReq,
                   &REL_DW.sf_RRDoorRlsReq);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VbOUT_REL_FRLockReleaseInsdSW_flg_VbOUT_REL_FRLockReleaseInsdSW_flg' */
  (void)
    Rte_Write_VbOUT_REL_FRLockReleaseInsdSW_flg_VbOUT_REL_FRLockReleaseInsdSW_flg
    (REL_B.SO_b_FRDoorInBtnSts);

  /* Outport: '<Root>/VbOUT_REL_FRLockReleaseOutsdSW_flg_VbOUT_REL_FRLockReleaseOutsdSW_flg' */
  (void)
    Rte_Write_VbOUT_REL_FRLockReleaseOutsdSW_flg_VbOUT_REL_FRLockReleaseOutsdSW_flg
    (REL_B.SO_b_FRDoorHndBtnSts);

  /* Outport: '<Root>/VbOUT_REL_RRLockReleaseInsdSW_flg_VbOUT_REL_RRLockReleaseInsdSW_flg' */
  (void)
    Rte_Write_VbOUT_REL_RRLockReleaseInsdSW_flg_VbOUT_REL_RRLockReleaseInsdSW_flg
    (REL_B.SO_b_RRDoorInBtnSts);

  /* Outport: '<Root>/VbOUT_REL_RRLockReleaseOutsdSW_flg_VbOUT_REL_RRLockReleaseOutsdSW_flg' */
  (void)
    Rte_Write_VbOUT_REL_RRLockReleaseOutsdSW_flg_VbOUT_REL_RRLockReleaseOutsdSW_flg
    (REL_B.SO_b_RRDoorHndBtnSts);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Outport: '<Root>/VbOUT_REL_FRDoorOpenSwitch_flg_VbOUT_REL_FRDoorOpenSwitch_flg' incorporates:
   *  SignalConversion generated from: '<S2>/VbOUT_HWA_FRDoorFullOpen_flg_VbOUT_HWA_FRDoorFullOpen_flg_read'
   */
  (void)Rte_Write_VbOUT_REL_FRDoorOpenSwitch_flg_VbOUT_REL_FRDoorOpenSwitch_flg
    (tmpRead_4);

  /* Outport: '<Root>/VbOUT_REL_FRDoorAjarSwitch_flg_VbOUT_REL_FRDoorAjarSwitch_flg' incorporates:
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg_read'
   */
  (void)Rte_Write_VbOUT_REL_FRDoorAjarSwitch_flg_VbOUT_REL_FRDoorAjarSwitch_flg
    (tmpRead_0);

  /* Outport: '<Root>/VbOUT_REL_RRDoorOpenSwitch_flg_VbOUT_REL_RRDoorOpenSwitch_flg' incorporates:
   *  SignalConversion generated from: '<S2>/VbOUT_HWA_RRDoorFullOpen_flg_VbOUT_HWA_RRDoorFullOpen_flg_read'
   */
  (void)Rte_Write_VbOUT_REL_RRDoorOpenSwitch_flg_VbOUT_REL_RRDoorOpenSwitch_flg
    (tmpRead_5);

  /* Outport: '<Root>/VbOUT_REL_RRDoorAjarSwitch_flg_VbOUT_REL_RRDoorAjarSwitch_flg' incorporates:
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg_read'
   */
  (void)Rte_Write_VbOUT_REL_RRDoorAjarSwitch_flg_VbOUT_REL_RRDoorAjarSwitch_flg
    (tmpRead_1);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VeOUT_REL_HandleSwitchStsFR_sig_VeOUT_REL_HandleSwitchStsFR_sig' */
  (void)
    Rte_Write_VeOUT_REL_HandleSwitchStsFR_sig_VeOUT_REL_HandleSwitchStsFR_sig(0U);

  /* Outport: '<Root>/VeOUT_REL_HandleSwitchStsRL_sig_VeOUT_REL_HandleSwitchStsRL_sig' */
  (void)
    Rte_Write_VeOUT_REL_HandleSwitchStsRL_sig_VeOUT_REL_HandleSwitchStsRL_sig(0U);

  /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq_j);

  /* Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq);
}

/* Model initialize function */
void REL_Init(void)
{
  {
    Unlock_Req_E SO_m_UnlockReq_o;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FRDoorRlsReq' */
    REL_FRDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq_j, &SO_m_UnlockReq_o);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsReq' */
    REL_FRDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq, &SO_m_UnlockReq_o);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
    (void)Rte_Write_VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg
      (REL_B.SO_b_DoorRlsReq_j);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg' */
    (void)Rte_Write_VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg
      (REL_B.SO_b_DoorRlsReq);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
