/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Oct 17 18:03:49 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REL.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "REL_types.h"
#include "REL_private.h"

/* Named constants for Chart: '<S3>/FRDoorRlsDriver' */
#define REL_IN_Check                   ((uint8)1U)
#define REL_IN_Delay                   ((uint8)2U)
#define REL_IN_Idle                    ((uint8)1U)
#define REL_IN_LastCheck               ((uint8)2U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8)0U)
#define REL_IN_Normal                  ((uint8)1U)
#define REL_IN_PowerOn                 ((uint8)2U)
#define REL_IN_Release                 ((uint8)2U)
#define REL_IN_Reset                   ((uint8)3U)
#define REL_IN_Stall_Handle            ((uint8)4U)
#define REL_IN_Step1_Ajar              ((uint8)5U)
#define REL_IN_Step2_Open              ((uint8)6U)

/* Named constants for Chart: '<S3>/FRDoorRlsReq' */
#define REL_IN_DoorLock                ((uint8)1U)
#define REL_IN_DoorUnlock              ((uint8)2U)
#define REL_IN_DoorUnlock_o            ((uint8)1U)
#define REL_IN_Error                   ((uint8)3U)
#define REL_IN_Idle_i                  ((uint8)1U)
#define REL_IN_NO_ACTIVE_CHILD_i       ((uint8)0U)
#define REL_IN_Once                    ((uint8)2U)
#define REL_IN_Release_b               ((uint8)4U)
#define REL_IN_Release_bl              ((uint8)2U)
#define REL_IN_Trigger                 ((uint8)2U)
#define REL_IN_Twice                   ((uint8)3U)
#define REL_IN_UnlockFail              ((uint8)1U)
#define REL_IN_UnlockReq               ((uint8)2U)
#define REL_IN_UnlockSuccess           ((uint8)3U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8)1U)
#define REL_IN_NoCrash                 ((uint8)2U)

/* Block signals (default storage) */
B_REL_T REL_B;

/* Block states (default storage) */
DW_REL_T REL_DW;

/* Forward declaration for local functions */
static float64 REL_GetPwm(float64 x, uint8 rtu_SI_e_Volt100mV);

/* Forward declaration for local functions */
static float64 REL_GetDoorRatSts(float64 ajar, float64 open);
static uint8 REL_safe_cast_to_Rat_Sts_E(uint8 input);

/* Function for Chart: '<S3>/FRDoorRlsDriver' */
static float64 REL_GetPwm(float64 x, uint8 rtu_SI_e_Volt100mV)
{
  float64 y;
  y = x * 100.0 / (float64)rtu_SI_e_Volt100mV;

  /*  扩大100倍，浮点转整型  */
  if ((y > 100.0) || (rtu_SI_e_Volt100mV == 0)) {
    y = 100.0;
  }

  return y;
}

/*
 * System initialize for atomic system:
 *    '<S3>/FRDoorRlsDriver'
 *    '<S3>/RRDoorRlsDriver'
 */
void REL_FRDoorRlsDriver_Init(uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm,
  boolean *rty_SO_b_Error)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotorPwm = 0U;
  *rty_SO_b_Error = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FRDoorRlsDriver'
 *    '<S3>/RRDoorRlsDriver'
 */
void REL_FRDoorRlsDriver(uint8 rtu_SI_e_Volt100mV, boolean rtu_SO_b_DoorRlsReq,
  Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen, uint8
  rtu_SI_e_DoorRlsDelayTime, uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm,
  boolean *rty_SO_b_Error, DW_FRDoorRlsDriver_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S3>/FRDoorRlsDriver' */
  if (localDW->is_active_c19_DoorRlsDriver == 0U) {
    localDW->is_active_c19_DoorRlsDriver = 1U;
    localDW->is_c19_DoorRlsDriver = REL_IN_PowerOn;
    localDW->temporalCounter_i1 = 0U;

    /*  上电释放电机执行一次复位  */
    *rty_SO_e_MotorCmd = 2U;
    *rty_SO_e_MotorPwm = 100U;
  } else if (localDW->is_c19_DoorRlsDriver == REL_IN_Normal) {
    if (localDW->is_MainProgress == REL_IN_Idle) {
      if (rtu_SO_b_DoorRlsReq) {
        localDW->SL_e_DoorRlsDelayTime = rtu_SI_e_DoorRlsDelayTime;
        localDW->is_MainProgress = REL_IN_Release;
        localDW->SL_e_CycleCount = 0U;
        localDW->is_Release = REL_IN_Delay;
        localDW->temporalCounter_i1 = 0U;

        /*  无框车门电释放延时  */
      }
    } else {
      /* case IN_Release: */
      switch (localDW->is_Release) {
       case REL_IN_Check:
        {
          if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar) {
            localDW->is_Release = REL_IN_Step2_Open;
            localDW->is_Step2_Open = REL_IN_Idle;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
          } else {
            Boolean tmp_0;
            tmp_0 = !rtu_SI_b_DoorAjar;
            if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                (localDW->SL_e_CycleCount < 3)) {
              localDW->is_Release = REL_IN_Stall_Handle;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_e_MotorCmd = 1U;
              *rty_SO_e_MotorPwm = 100U;
              localDW->SL_e_CycleCount++;
            } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                       (localDW->SL_e_CycleCount >= 3)) {
              float64 tmp;
              *rty_SO_b_Error = true;
              localDW->is_Release = REL_IN_Reset;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_e_MotorCmd = 2U;
              tmp = REL_GetPwm(70.0, rtu_SI_e_Volt100mV);
              if (tmp < 256.0) {
                if (tmp >= 0.0) {
                  *rty_SO_e_MotorPwm = (uint8)tmp;
                } else {
                  *rty_SO_e_MotorPwm = 0U;
                }
              } else {
                *rty_SO_e_MotorPwm = MAX_uint8_T;
              }
            }
          }
        }
        break;

       case REL_IN_Delay:
        {
          if (localDW->temporalCounter_i1 >= localDW->SL_e_DoorRlsDelayTime) {
            float64 tmp;
            localDW->is_Release = REL_IN_Step1_Ajar;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 1U;
            tmp = REL_GetPwm(105.0, rtu_SI_e_Volt100mV);
            if (tmp < 256.0) {
              if (tmp >= 0.0) {
                *rty_SO_e_MotorPwm = (uint8)tmp;
              } else {
                *rty_SO_e_MotorPwm = 0U;
              }
            } else {
              *rty_SO_e_MotorPwm = MAX_uint8_T;
            }
          }
        }
        break;

       case REL_IN_Reset:
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_MainProgress = REL_IN_Idle;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       case REL_IN_Stall_Handle:
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release = REL_IN_Check;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       case REL_IN_Step1_Ajar:
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release = REL_IN_Check;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       default:
        {
          /* case IN_Step2_Open: */
          if (localDW->is_Step2_Open == REL_IN_Idle) {
            if ((localDW->temporalCounter_i1 < 270) && rtu_SI_b_DoorOpen) {
              float64 tmp;
              *rty_SO_b_Error = false;
              localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
              localDW->is_Release = REL_IN_Reset;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_e_MotorCmd = 2U;
              tmp = REL_GetPwm(70.0, rtu_SI_e_Volt100mV);
              if (tmp < 256.0) {
                if (tmp >= 0.0) {
                  *rty_SO_e_MotorPwm = (uint8)tmp;
                } else {
                  *rty_SO_e_MotorPwm = 0U;
                }
              } else {
                *rty_SO_e_MotorPwm = MAX_uint8_T;
              }
            } else if (localDW->temporalCounter_i1 >= 300) {
              localDW->is_Step2_Open = REL_IN_LastCheck;
            }
          } else {
            float64 tmp;

            /* case IN_LastCheck: */
            localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
            localDW->is_Release = REL_IN_Reset;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 2U;
            tmp = REL_GetPwm(70.0, rtu_SI_e_Volt100mV);
            if (tmp < 256.0) {
              if (tmp >= 0.0) {
                *rty_SO_e_MotorPwm = (uint8)tmp;
              } else {
                *rty_SO_e_MotorPwm = 0U;
              }
            } else {
              *rty_SO_e_MotorPwm = MAX_uint8_T;
            }
          }
        }
        break;
      }
    }

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 30) {
    localDW->is_c19_DoorRlsDriver = REL_IN_Normal;
    localDW->is_MainProgress = REL_IN_Idle;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  }

  /* End of Chart: '<S3>/FRDoorRlsDriver' */
}

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
                      Unlock_Req_E *rty_SO_m_UnlockReq, DW_FRDoorRlsReq_REL_T
                      *localDW)
{
  if (localDW->temporalCounter_i1 < 63U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 255U) {
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
    localDW->is_SwValid = REL_IN_Idle_i;
    localDW->SL_b_DoorInBtnValid = false;
    localDW->is_RlsReq = REL_IN_Idle_i;
    localDW->is_RlsReq_m = REL_IN_Idle_i;
    localDW->SL_b_DoorHndBtnValid = rtu_SI_b_DoorHndBtnSts;
  } else {
    switch (localDW->is_SwValid) {
     case REL_IN_Idle_i:
      if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
          localDW->SI_b_DoorInBtnSts_start) {
        localDW->is_SwValid = REL_IN_Once;
        localDW->temporalCounter_i2 = 0U;
      }
      break;

     case REL_IN_Once:
      if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
          localDW->SI_b_DoorInBtnSts_start) {
        localDW->is_SwValid = REL_IN_Twice;
        localDW->temporalCounter_i2 = 0U;
        localDW->SL_b_DoorInBtnValid = true;
      } else if (localDW->temporalCounter_i2 >= 200) {
        localDW->is_SwValid = REL_IN_Idle_i;
        localDW->SL_b_DoorInBtnValid = false;
      }
      break;

     default:
      /* case IN_Twice: */
      if (localDW->temporalCounter_i2 >= 3) {
        localDW->is_SwValid = REL_IN_Idle_i;
        localDW->SL_b_DoorInBtnValid = false;
      }
      break;
    }

    if (localDW->is_RlsReq == REL_IN_Idle_i) {
      if ((rtu_SI_e_EspVehSpd < 5) && (!rtu_SI_b_EspVehSpdVld) &&
          (rtu_SI_m_ChildLckSts == Child_Unlock) &&
          ((localDW->SL_b_DoorInBtnValid_prev !=
            localDW->SL_b_DoorInBtnValid_start) &&
           localDW->SL_b_DoorInBtnValid_start)) {
        localDW->is_RlsReq = REL_IN_Trigger;
        switch (rtu_SI_m_DoorLockSts) {
         case Door_Lock:
          localDW->is_Trigger = REL_IN_DoorLock;
          localDW->is_DoorLock = REL_IN_UnlockReq;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_m_UnlockReq = Unlock_Req;
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
      localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_i;
      localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_i;
      localDW->is_RlsReq = REL_IN_Idle_i;
    } else {
      switch (localDW->is_Trigger) {
       case REL_IN_DoorLock:
        switch (localDW->is_DoorLock) {
         case REL_IN_UnlockFail:
          localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_i;
          localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_i;
          localDW->is_RlsReq = REL_IN_Idle_i;
          break;

         case REL_IN_UnlockReq:
          if (rtu_SI_m_DoorLockSts == Door_Unlock) {
            localDW->is_DoorLock = REL_IN_UnlockSuccess;
          } else if ((localDW->temporalCounter_i1 >= 50) &&
                     (rtu_SI_m_DoorLockSts == Door_Lock)) {
            localDW->is_DoorLock = REL_IN_UnlockFail;
          } else if (localDW->temporalCounter_i1 == 5) {
            *rty_SO_m_UnlockReq = Unlock_Idle;
          }
          break;

         default:
          /* case IN_UnlockSuccess: */
          if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
            localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_i;
            localDW->is_Trigger = REL_IN_Release_b;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_DoorRlsReq = true;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_Trigger = REL_IN_Release_b;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;

       case REL_IN_Error:
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_RlsReq = REL_IN_Idle_i;
        break;

       default:
        /* case IN_Release: */
        if (localDW->temporalCounter_i1 >= 5) {
          *rty_SO_b_DoorRlsReq = false;
          localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_i;
          localDW->is_RlsReq = REL_IN_Idle_i;
        }
        break;
      }
    }

    if (localDW->is_RlsReq_m == REL_IN_Idle_i) {
      if ((rtu_SI_e_EspVehSpd < 5) && (!rtu_SI_b_EspVehSpdVld) &&
          (rtu_SI_m_DoorLockSts == Door_Unlock) &&
          ((localDW->SL_b_DoorHndBtnValid_prev !=
            localDW->SL_b_DoorHndBtnValid_start) &&
           localDW->SL_b_DoorHndBtnValid_start)) {
        localDW->is_RlsReq_m = REL_IN_Trigger;
        localDW->is_Trigger_h = REL_IN_DoorUnlock_o;
      }

      /* case IN_Trigger: */
    } else if (((rtu_SI_e_EspVehSpd >= 5) && (!rtu_SI_b_EspVehSpdVld)) ||
               (rtu_SI_m_DoorLockSts != Door_Unlock) || (rtu_SI_m_DoorRatSts ==
                Rat_Unlock)) {
      localDW->is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_i;
      localDW->is_RlsReq_m = REL_IN_Idle_i;
    } else if (localDW->is_Trigger_h == REL_IN_DoorUnlock_o) {
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_h = REL_IN_Release_bl;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }

      /* case IN_Release: */
    } else if (localDW->temporalCounter_i3 >= 5) {
      *rty_SO_b_DoorRlsReq = false;
      localDW->is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_i;
      localDW->is_RlsReq_m = REL_IN_Idle_i;
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
  UInt8 tmpRead_0;
  UInt8 tmpRead_1;
  Unlock_Req_E SO_m_UnlockReq_a;
  uint8 SO_e_MotorPwm;
  uint8 SO_e_MotorPwm_m;
  boolean SO_b_Error_a;

  /* Inport: '<Root>/VeOUT_DLK_FRDoorLockSts_sig_VeOUT_DLK_FRDoorLockSts_sig' */
  (void)Rte_Read_VeOUT_DLK_FRDoorLockSts_sig_VeOUT_DLK_FRDoorLockSts_sig
    (&SO_e_MotorPwm_m);

  /* SignalConversion generated from: '<S2>/VbOUT_HWA_RRDoorFullOpen_flg_VbOUT_HWA_RRDoorFullOpen_flg_read' incorporates:
   *  Inport: '<Root>/VbOUT_HWA_RRDoorFullOpen_flg_VbOUT_HWA_RRDoorFullOpen_flg'
   */
  (void)Rte_Read_VbOUT_HWA_RRDoorFullOpen_flg_VbOUT_HWA_RRDoorFullOpen_flg
    (&REL_B.VbOUT_HWA_RRDoorFullOpen_flg_Vb);

  /* SignalConversion generated from: '<S2>/VbOUT_HWA_FRDoorFullOpen_flg_VbOUT_HWA_FRDoorFullOpen_flg_read' incorporates:
   *  Inport: '<Root>/VbOUT_HWA_FRDoorFullOpen_flg_VbOUT_HWA_FRDoorFullOpen_flg'
   */
  (void)Rte_Read_VbOUT_HWA_FRDoorFullOpen_flg_VbOUT_HWA_FRDoorFullOpen_flg
    (&REL_B.VbOUT_HWA_FRDoorFullOpen_flg_Vb);

  /* SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg
    (&REL_B.VbINP_HWA_RRDoorAjar_flg_VbINP_);

  /* SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg
    (&REL_B.VbINP_HWA_FRDoorAjar_flg_VbINP_);

  /* Inport: '<Root>/VeOUT_PDU_PowerMode_sig_VeOUT_PDU_PowerMode_sig' */
  (void)Rte_Read_VeOUT_PDU_PowerMode_sig_VeOUT_PDU_PowerMode_sig(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
   *  Constant: '<S3>/Constant'
   */
  REL_DW.E03_REL_R = 0U;

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

  /* Chart: '<S3>/DoorRatSts' */
  if (REL_DW.is_active_c3_REL == 0U) {
    float64 tmp;
    REL_DW.is_active_c3_REL = 1U;
    tmp = REL_GetDoorRatSts((float64)REL_B.VbINP_HWA_FRDoorAjar_flg_VbINP_,
      (float64)REL_B.VbOUT_HWA_FRDoorFullOpen_flg_Vb);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)REL_B.VbINP_HWA_RRDoorAjar_flg_VbINP_,
      (float64)REL_B.VbOUT_HWA_RRDoorFullOpen_flg_Vb);
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
    tmp = REL_GetDoorRatSts((float64)REL_B.VbINP_HWA_FRDoorAjar_flg_VbINP_,
      (float64)REL_B.VbOUT_HWA_FRDoorFullOpen_flg_Vb);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)REL_B.VbINP_HWA_RRDoorAjar_flg_VbINP_,
      (float64)REL_B.VbOUT_HWA_RRDoorFullOpen_flg_Vb);
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
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VeINP_CAN_ACU3CrashOutputSts_sig_VeINP_CAN_ACU3CrashOutputSts_sig' */
  (void)
    Rte_Read_VeINP_CAN_ACU3CrashOutputSts_sig_VeINP_CAN_ACU3CrashOutputSts_sig
    (&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/DoorSwSts' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  if (REL_DW.temporalCounter_i1 < 1023U) {
    REL_DW.temporalCounter_i1++;
  }

  REL_DW.SI_b_CrashSts_prev = REL_DW.SI_b_CrashSts_start;
  REL_DW.SI_b_CrashSts_start = (tmpRead_0 != 0);

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
    REL_DW.SI_b_CrashSts_prev = (tmpRead_0 != 0);
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

  /* Inport: '<Root>/VeOUT_DLK_RRDoorLockSts_sig_VeOUT_DLK_RRDoorLockSts_sig' */
  (void)Rte_Read_VeOUT_DLK_RRDoorLockSts_sig_VeOUT_DLK_RRDoorLockSts_sig
    (&SO_e_MotorPwm);

  /* Inport: '<Root>/VeINP_HWA_RRChildrenProtectSwitch_sig_VeINP_HWA_RRChildrenProtectSwitch_sig' */
  (void)
    Rte_Read_VeINP_HWA_RRChildrenProtectSwitch_sig_VeINP_HWA_RRChildrenProtectSwitch_sig
    (&tmpRead_1);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion12'
   */
  REL_FRDoorRlsReq(rtb_TmpSignalConversionAtVeOUT_,
                   rtb_TmpSignalConversionAtVbINP_, SO_e_MotorPwm_m,
                   rtb_SO_m_FRDoorRatSts, REL_B.SO_b_FRDoorInBtnSts,
                   REL_B.SO_b_FRDoorHndBtnSts, Child_Unlock,
                   &REL_B.SO_b_DoorRlsReq_i, &SO_m_UnlockReq_a,
                   &REL_DW.sf_FRDoorRlsReq);

  /* Chart: '<S3>/FRDoorRlsDriver' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  REL_FRDoorRlsDriver(0U, REL_B.SO_b_DoorRlsReq_i,
                      REL_B.VbINP_HWA_FRDoorAjar_flg_VbINP_,
                      REL_B.VbOUT_HWA_FRDoorFullOpen_flg_Vb, 50,
                      &REL_B.SO_e_MotorCmd_h, &SO_e_MotorPwm_m, &SO_b_Error_a,
                      &REL_DW.sf_FRDoorRlsDriver);

  /* Chart: '<S3>/RRDoorRlsReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  REL_FRDoorRlsReq(rtb_TmpSignalConversionAtVeOUT_,
                   rtb_TmpSignalConversionAtVbINP_, SO_e_MotorPwm,
                   rtb_SO_m_RRDoorRatSts, REL_B.SO_b_RRDoorInBtnSts,
                   REL_B.SO_b_RRDoorHndBtnSts, tmpRead_1, &REL_B.SO_b_DoorRlsReq,
                   &SO_m_UnlockReq_a, &REL_DW.sf_RRDoorRlsReq);

  /* Chart: '<S3>/RRDoorRlsDriver' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  REL_FRDoorRlsDriver(0U, REL_B.SO_b_DoorRlsReq,
                      REL_B.VbINP_HWA_RRDoorAjar_flg_VbINP_,
                      REL_B.VbOUT_HWA_RRDoorFullOpen_flg_Vb, 50,
                      &REL_B.SO_e_MotorCmd, &SO_e_MotorPwm, &SO_b_Error_a,
                      &REL_DW.sf_RRDoorRlsDriver);

  /* Outport: '<Root>/VeOUT_REL_RRChildrenProtectSwitch_sig_VeOUT_REL_RRChildrenProtectSwitch_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  (void)
    Rte_Write_VeOUT_REL_RRChildrenProtectSwitch_sig_VeOUT_REL_RRChildrenProtectSwitch_sig
    (tmpRead_1);

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

  /* Outport: '<Root>/VbOUT_REL_FRDoorOpenSwitch_flg_VbOUT_REL_FRDoorOpenSwitch_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorOpenSwitch_flg_VbOUT_REL_FRDoorOpenSwitch_flg
    (REL_B.VbOUT_HWA_FRDoorFullOpen_flg_Vb);

  /* Outport: '<Root>/VbOUT_REL_FRDoorAjarSwitch_flg_VbOUT_REL_FRDoorAjarSwitch_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorAjarSwitch_flg_VbOUT_REL_FRDoorAjarSwitch_flg
    (REL_B.VbINP_HWA_FRDoorAjar_flg_VbINP_);

  /* Outport: '<Root>/VbOUT_REL_RRDoorOpenSwitch_flg_VbOUT_REL_RRDoorOpenSwitch_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorOpenSwitch_flg_VbOUT_REL_RRDoorOpenSwitch_flg
    (REL_B.VbOUT_HWA_RRDoorFullOpen_flg_Vb);

  /* Outport: '<Root>/VbOUT_REL_RRDoorAjarSwitch_flg_VbOUT_REL_RRDoorAjarSwitch_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorAjarSwitch_flg_VbOUT_REL_RRDoorAjarSwitch_flg
    (REL_B.VbINP_HWA_RRDoorAjar_flg_VbINP_);

  /* Outport: '<Root>/VeOUT_REL_FRReleaseLatchStatus_sig_VeOUT_REL_FRReleaseLatchStatus_sig' */
  (void)
    Rte_Write_VeOUT_REL_FRReleaseLatchStatus_sig_VeOUT_REL_FRReleaseLatchStatus_sig
    (REL_B.SO_e_MotorCmd_h);

  /* Outport: '<Root>/VeOUT_REL_RRReleaseLatchStatus_sig_VeOUT_REL_RRReleaseLatchStatus_sig' */
  (void)
    Rte_Write_VeOUT_REL_RRReleaseLatchStatus_sig_VeOUT_REL_RRReleaseLatchStatus_sig
    (REL_B.SO_e_MotorCmd);

  /* Outport: '<Root>/VeOUT_REL_HandleSwitchStsFR_sig_VeOUT_REL_HandleSwitchStsFR_sig' */
  (void)
    Rte_Write_VeOUT_REL_HandleSwitchStsFR_sig_VeOUT_REL_HandleSwitchStsFR_sig(0U);

  /* Outport: '<Root>/VeOUT_REL_HandleSwitchStsRL_sig_VeOUT_REL_HandleSwitchStsRL_sig' */
  (void)
    Rte_Write_VeOUT_REL_HandleSwitchStsRL_sig_VeOUT_REL_HandleSwitchStsRL_sig(0U);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  (void)Rte_Write_VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg
    (REL_B.SO_e_MotorCmd_h == 1);

  /* Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg' incorporates:
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   */
  (void)Rte_Write_VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg
    (REL_B.SO_e_MotorCmd_h == 2);

  /* Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg' incorporates:
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S6>/Compare'
   */
  (void)Rte_Write_VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg
    (REL_B.SO_e_MotorCmd == 1);

  /* Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  (void)Rte_Write_VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg
    (REL_B.SO_e_MotorCmd == 2);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq_i);

  /* Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq);
}

/* Model initialize function */
void REL_Init(void)
{
  {
    Unlock_Req_E SO_m_UnlockReq_a;
    uint8 SO_e_MotorPwm_m;
    boolean SO_b_Error_a;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FRDoorRlsDriver' */
    REL_FRDoorRlsDriver_Init(&REL_B.SO_e_MotorCmd_h, &SO_e_MotorPwm_m,
      &SO_b_Error_a);

    /* SystemInitialize for Chart: '<S3>/FRDoorRlsReq' */
    REL_FRDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq_i, &SO_m_UnlockReq_a);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsDriver' */
    REL_FRDoorRlsDriver_Init(&REL_B.SO_e_MotorCmd, &SO_e_MotorPwm_m,
      &SO_b_Error_a);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsReq' */
    REL_FRDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq, &SO_m_UnlockReq_a);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
    (void)Rte_Write_VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg
      (REL_B.SO_b_DoorRlsReq_i);

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
