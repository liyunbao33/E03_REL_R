/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Oct 24 15:14:32 2023
 *
 * Target selection: ert.tlc
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
#define REL_IN_DoorLock                ((uint8_T)1U)
#define REL_IN_DoorUnlock              ((uint8_T)2U)
#define REL_IN_DoorUnlock_a            ((uint8_T)1U)
#define REL_IN_Error                   ((uint8_T)3U)
#define REL_IN_Idle                    ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define REL_IN_Once                    ((uint8_T)2U)
#define REL_IN_Release                 ((uint8_T)4U)
#define REL_IN_Release_i               ((uint8_T)2U)
#define REL_IN_Trigger                 ((uint8_T)2U)
#define REL_IN_Twice                   ((uint8_T)3U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8_T)1U)
#define REL_IN_NoCrash                 ((uint8_T)2U)

/* Block states (default storage) */
DW_REL_T REL_DW;

/* External inputs (root inport signals with default storage) */
ExtU_REL_T REL_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_REL_T REL_Y;

/* Real-time model */
static RT_MODEL_REL_T REL_M_;
RT_MODEL_REL_T *const REL_M = &REL_M_;

/* Forward declaration for local functions */
static real_T REL_GetDoorRatSts(real_T ajar, real_T open);
static uint8_T REL_safe_cast_to_Rat_Sts_E(uint8_T input);

/*
 * System initialize for atomic system:
 *    '<S3>/FRDoorRlsReq'
 *    '<S3>/RRDoorRlsReq'
 */
void REL_FRDoorRlsReq_Init(boolean_T *rty_SO_b_DoorRlsReq, Unlock_Req_E
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
                      rtu_SI_m_DoorRatSts, boolean_T rtu_SI_b_DoorInBtnSts,
                      boolean_T rtu_SI_b_DoorHndBtnSts, Child_Sts_E
                      rtu_SI_m_ChildLckSts, boolean_T *rty_SO_b_DoorRlsReq,
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
static real_T REL_GetDoorRatSts(real_T ajar, real_T open)
{
  real_T status;
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

static uint8_T REL_safe_cast_to_Rat_Sts_E(uint8_T input)
{
  uint8_T output;

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
  Child_Sts_E rtb_DataTypeConversion2;
  Rat_Sts_E rtb_SO_m_FRDoorRatSts;
  Rat_Sts_E rtb_SO_m_RRDoorRatSts;
  boolean_T SI_b_CrashSts_prev;

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/VeINP_HWA_RRChildrenProtectSwitch_sig_VeINP_HWA_RRChildrenProtectSwitch_sig'
   */
  rtb_DataTypeConversion2 = REL_U.VeINP_HWA_RRChildrenProtectSwit;

  /* Outport: '<Root>/VeOUT_REL_RRChildrenProtectSwitch_sig_VeOUT_REL_RRChildrenProtectSwitch_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  REL_Y.VeOUT_REL_RRChildrenProtectSwit = rtb_DataTypeConversion2;

  /* Outport: '<Root>/VbOUT_REL_FRDoorOpenSwitch_flg_VbOUT_REL_FRDoorOpenSwitch_flg' incorporates:
   *  Inport: '<Root>/VbOUT_HWA_FRDoorFullOpen_flg_VbOUT_HWA_FRDoorFullOpen_flg'
   *  SignalConversion generated from: '<S2>/VbOUT_HWA_FRDoorFullOpen_flg_VbOUT_HWA_FRDoorFullOpen_flg_read'
   */
  REL_Y.VbOUT_REL_FRDoorOpenSwitch_flg_ = REL_U.VbOUT_HWA_FRDoorFullOpen_flg_Vb;

  /* Outport: '<Root>/VbOUT_REL_FRDoorAjarSwitch_flg_VbOUT_REL_FRDoorAjarSwitch_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg_read'
   */
  REL_Y.VbOUT_REL_FRDoorAjarSwitch_flg_ = REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_;

  /* Outport: '<Root>/VbOUT_REL_RRDoorOpenSwitch_flg_VbOUT_REL_RRDoorOpenSwitch_flg' incorporates:
   *  Inport: '<Root>/VbOUT_HWA_RRDoorFullOpen_flg_VbOUT_HWA_RRDoorFullOpen_flg'
   *  SignalConversion generated from: '<S2>/VbOUT_HWA_RRDoorFullOpen_flg_VbOUT_HWA_RRDoorFullOpen_flg_read'
   */
  REL_Y.VbOUT_REL_RRDoorOpenSwitch_flg_ = REL_U.VbOUT_HWA_RRDoorFullOpen_flg_Vb;

  /* Outport: '<Root>/VbOUT_REL_RRDoorAjarSwitch_flg_VbOUT_REL_RRDoorAjarSwitch_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg_read'
   */
  REL_Y.VbOUT_REL_RRDoorAjarSwitch_flg_ = REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_;

  /* Chart: '<S3>/DoorRatSts' incorporates:
   *  Outport: '<Root>/VbOUT_REL_FRDoorAjarSwitch_flg_VbOUT_REL_FRDoorAjarSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorOpenSwitch_flg_VbOUT_REL_FRDoorOpenSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorAjarSwitch_flg_VbOUT_REL_RRDoorAjarSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorOpenSwitch_flg_VbOUT_REL_RRDoorOpenSwitch_flg'
   */
  if (REL_DW.is_active_c3_REL == 0U) {
    real_T tmp;
    REL_DW.is_active_c3_REL = 1U;
    tmp = REL_GetDoorRatSts((real_T)REL_Y.VbOUT_REL_FRDoorAjarSwitch_flg_,
      (real_T)REL_Y.VbOUT_REL_FRDoorOpenSwitch_flg_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_Y.VbOUT_REL_RRDoorAjarSwitch_flg_,
      (real_T)REL_Y.VbOUT_REL_RRDoorOpenSwitch_flg_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        rtb_SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }
  } else {
    real_T tmp;
    tmp = REL_GetDoorRatSts((real_T)REL_Y.VbOUT_REL_FRDoorAjarSwitch_flg_,
      (real_T)REL_Y.VbOUT_REL_FRDoorOpenSwitch_flg_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_Y.VbOUT_REL_RRDoorAjarSwitch_flg_,
      (real_T)REL_Y.VbOUT_REL_RRDoorOpenSwitch_flg_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
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
   *  Inport: '<Root>/VeINP_CAN_ACU3CrashOutputSts_sig_VeINP_CAN_ACU3CrashOutputSts_sig'
   */
  if (REL_DW.temporalCounter_i1 < 1023U) {
    REL_DW.temporalCounter_i1++;
  }

  SI_b_CrashSts_prev = REL_DW.SI_b_CrashSts_start;
  REL_DW.SI_b_CrashSts_start = (REL_U.VeINP_CAN_ACU3CrashOutputSts_si != 0);
  if (REL_DW.is_active_c23_REL == 0U) {
    REL_DW.is_active_c23_REL = 1U;
    REL_DW.is_c23_REL = REL_IN_NoCrash;

    /* Outport: '<Root>/VbOUT_REL_FRLockReleaseInsdSW_flg_VbOUT_REL_FRLockReleaseInsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
     */
    REL_Y.VbOUT_REL_FRLockReleaseInsdSW_f =
      REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;

    /* Outport: '<Root>/VbOUT_REL_RRLockReleaseInsdSW_flg_VbOUT_REL_RRLockReleaseInsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg'
     */
    REL_Y.VbOUT_REL_RRLockReleaseInsdSW_f =
      REL_U.VbINP_HWA_RRDoorButton_flg_VbIN;

    /* Outport: '<Root>/VbOUT_REL_FRLockReleaseOutsdSW_flg_VbOUT_REL_FRLockReleaseOutsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg'
     */
    REL_Y.VbOUT_REL_FRLockReleaseOutsdSW_ =
      REL_U.VbINP_HWA_FRDoorOutButton_flg_V;

    /* Outport: '<Root>/VbOUT_REL_RRLockReleaseOutsdSW_flg_VbOUT_REL_RRLockReleaseOutsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg'
     */
    REL_Y.VbOUT_REL_RRLockReleaseOutsdSW_ =
      REL_U.VbINP_HWA_RRDoorOutButton_flg_V;
  } else if (REL_DW.is_c23_REL == REL_IN_Crash) {
    if (REL_DW.temporalCounter_i1 >= 600) {
      REL_DW.is_c23_REL = REL_IN_NoCrash;

      /* Outport: '<Root>/VbOUT_REL_FRLockReleaseInsdSW_flg_VbOUT_REL_FRLockReleaseInsdSW_flg' incorporates:
       *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
       */
      REL_Y.VbOUT_REL_FRLockReleaseInsdSW_f =
        REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;

      /* Outport: '<Root>/VbOUT_REL_RRLockReleaseInsdSW_flg_VbOUT_REL_RRLockReleaseInsdSW_flg' incorporates:
       *  Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg'
       */
      REL_Y.VbOUT_REL_RRLockReleaseInsdSW_f =
        REL_U.VbINP_HWA_RRDoorButton_flg_VbIN;

      /* Outport: '<Root>/VbOUT_REL_FRLockReleaseOutsdSW_flg_VbOUT_REL_FRLockReleaseOutsdSW_flg' incorporates:
       *  Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg'
       */
      REL_Y.VbOUT_REL_FRLockReleaseOutsdSW_ =
        REL_U.VbINP_HWA_FRDoorOutButton_flg_V;

      /* Outport: '<Root>/VbOUT_REL_RRLockReleaseOutsdSW_flg_VbOUT_REL_RRLockReleaseOutsdSW_flg' incorporates:
       *  Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg'
       */
      REL_Y.VbOUT_REL_RRLockReleaseOutsdSW_ =
        REL_U.VbINP_HWA_RRDoorOutButton_flg_V;
    } else {
      /* Outport: '<Root>/VbOUT_REL_FRLockReleaseInsdSW_flg_VbOUT_REL_FRLockReleaseInsdSW_flg' */
      REL_Y.VbOUT_REL_FRLockReleaseInsdSW_f = false;

      /* Outport: '<Root>/VbOUT_REL_RRLockReleaseInsdSW_flg_VbOUT_REL_RRLockReleaseInsdSW_flg' */
      REL_Y.VbOUT_REL_RRLockReleaseInsdSW_f = false;

      /* Outport: '<Root>/VbOUT_REL_FRLockReleaseOutsdSW_flg_VbOUT_REL_FRLockReleaseOutsdSW_flg' */
      REL_Y.VbOUT_REL_FRLockReleaseOutsdSW_ = false;

      /* Outport: '<Root>/VbOUT_REL_RRLockReleaseOutsdSW_flg_VbOUT_REL_RRLockReleaseOutsdSW_flg' */
      REL_Y.VbOUT_REL_RRLockReleaseOutsdSW_ = false;
    }

    /* case IN_NoCrash: */
  } else if ((SI_b_CrashSts_prev != REL_DW.SI_b_CrashSts_start) &&
             REL_DW.SI_b_CrashSts_start) {
    REL_DW.is_c23_REL = REL_IN_Crash;
    REL_DW.temporalCounter_i1 = 0U;

    /* Outport: '<Root>/VbOUT_REL_FRLockReleaseInsdSW_flg_VbOUT_REL_FRLockReleaseInsdSW_flg' */
    REL_Y.VbOUT_REL_FRLockReleaseInsdSW_f = false;

    /* Outport: '<Root>/VbOUT_REL_RRLockReleaseInsdSW_flg_VbOUT_REL_RRLockReleaseInsdSW_flg' */
    REL_Y.VbOUT_REL_RRLockReleaseInsdSW_f = false;

    /* Outport: '<Root>/VbOUT_REL_FRLockReleaseOutsdSW_flg_VbOUT_REL_FRLockReleaseOutsdSW_flg' */
    REL_Y.VbOUT_REL_FRLockReleaseOutsdSW_ = false;

    /* Outport: '<Root>/VbOUT_REL_RRLockReleaseOutsdSW_flg_VbOUT_REL_RRLockReleaseOutsdSW_flg' */
    REL_Y.VbOUT_REL_RRLockReleaseOutsdSW_ = false;
  } else {
    /* Outport: '<Root>/VbOUT_REL_FRLockReleaseInsdSW_flg_VbOUT_REL_FRLockReleaseInsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
     */
    REL_Y.VbOUT_REL_FRLockReleaseInsdSW_f =
      REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;

    /* Outport: '<Root>/VbOUT_REL_RRLockReleaseInsdSW_flg_VbOUT_REL_RRLockReleaseInsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg'
     */
    REL_Y.VbOUT_REL_RRLockReleaseInsdSW_f =
      REL_U.VbINP_HWA_RRDoorButton_flg_VbIN;

    /* Outport: '<Root>/VbOUT_REL_FRLockReleaseOutsdSW_flg_VbOUT_REL_FRLockReleaseOutsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg'
     */
    REL_Y.VbOUT_REL_FRLockReleaseOutsdSW_ =
      REL_U.VbINP_HWA_FRDoorOutButton_flg_V;

    /* Outport: '<Root>/VbOUT_REL_RRLockReleaseOutsdSW_flg_VbOUT_REL_RRLockReleaseOutsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg'
     */
    REL_Y.VbOUT_REL_RRLockReleaseOutsdSW_ =
      REL_U.VbINP_HWA_RRDoorOutButton_flg_V;
  }

  /* End of Chart: '<S3>/DoorSwSts' */

  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_VehicleSpeedVSOSigValidData_flg_VbINP_CAN_VehicleSpeedVSOSigValidData_flg'
   *  Inport: '<Root>/VeOUT_DLK_FRDoorLockSts_sig_VeOUT_DLK_FRDoorLockSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
   *  Outport: '<Root>/VbOUT_REL_FRLockReleaseInsdSW_flg_VbOUT_REL_FRLockReleaseInsdSW_flg'
   *  Outport: '<Root>/VbOUT_REL_FRLockReleaseOutsdSW_flg_VbOUT_REL_FRLockReleaseOutsdSW_flg'
   */
  REL_FRDoorRlsReq(REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_VehicleSpeedVSOSigVal,
                   REL_U.VeOUT_DLK_FRDoorLockSts_sig_VeO, rtb_SO_m_FRDoorRatSts,
                   REL_Y.VbOUT_REL_FRLockReleaseInsdSW_f,
                   REL_Y.VbOUT_REL_FRLockReleaseOutsdSW_, Child_Unlock,
                   &REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU,
                   &REL_DW.sf_FRDoorRlsReq);

  /* Chart: '<S3>/RRDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_VehicleSpeedVSOSigValidData_flg_VbINP_CAN_VehicleSpeedVSOSigValidData_flg'
   *  Inport: '<Root>/VeOUT_DLK_RRDoorLockSts_sig_VeOUT_DLK_RRDoorLockSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   *  Outport: '<Root>/VbOUT_REL_RRLockReleaseInsdSW_flg_VbOUT_REL_RRLockReleaseInsdSW_flg'
   *  Outport: '<Root>/VbOUT_REL_RRLockReleaseOutsdSW_flg_VbOUT_REL_RRLockReleaseOutsdSW_flg'
   */
  REL_FRDoorRlsReq(REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_VehicleSpeedVSOSigVal,
                   REL_U.VeOUT_DLK_RRDoorLockSts_sig_VeO, rtb_SO_m_RRDoorRatSts,
                   REL_Y.VbOUT_REL_RRLockReleaseInsdSW_f,
                   REL_Y.VbOUT_REL_RRLockReleaseOutsdSW_,
                   rtb_DataTypeConversion2,
                   &REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                   &REL_DW.sf_RRDoorRlsReq);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VeOUT_REL_HandleSwitchStsFR_sig_VeOUT_REL_HandleSwitchStsFR_sig' */
  REL_Y.VeOUT_REL_HandleSwitchStsFR_sig = 0U;

  /* Outport: '<Root>/VeOUT_REL_HandleSwitchStsRL_sig_VeOUT_REL_HandleSwitchStsRL_sig' */
  REL_Y.VeOUT_REL_HandleSwitchStsRL_sig = 0U;
}

/* Model initialize function */
void REL_initialize(void)
{
  {
    Unlock_Req_E SO_m_UnlockReq_o;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FRDoorRlsReq' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
     */
    REL_FRDoorRlsReq_Init(&REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU,
                          &SO_m_UnlockReq_o);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsReq' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
     */
    REL_FRDoorRlsReq_Init(&REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                          &SO_m_UnlockReq_o);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */
  }
}

/* Model terminate function */
void REL_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
