/*
 * File: REL_private.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.88
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Sep 25 21:47:23 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REL_private_h_
#define RTW_HEADER_REL_private_h_
#include "rtwtypes.h"
#include "REL_types.h"
#include "Rte_Type.h"
#include "REL.h"

extern void REL_FRDoorRlsDriver_Init(boolean *rty_SO_b_MotorA, boolean
  *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd, boolean *rty_SO_b_Error, uint8
  *rty_SO_e_MotorPwm);
extern void REL_FRDoorRlsDriver(boolean rtu_SO_b_DoorRlsReq, Boolean
  rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen, boolean rtu_SI_b_CinchHome,
  boolean rtu_SI_b_ElecDoorCfg, uint8 rtu_SI_e_DoorRlsDelayTime, boolean
  *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd,
  boolean *rty_SO_b_Error, uint8 *rty_SO_e_MotorPwm, DW_FRDoorRlsDriver_REL_T
  *localDW);
extern void REL_FRDoorRlsReq_Init(boolean *rty_SO_b_DoorRlsReq, uint8
  *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E *rty_SO_m_UnlockReq);
extern void REL_FRDoorRlsReq(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, Door_Sts_E rtu_SI_m_DoorLockSts, Rat_Sts_E
  rtu_SI_m_DoorRatSts, boolean rtu_SI_b_DoorInBtnSts, boolean
  rtu_SI_b_DoorHndBtnSts, Child_Sts_E rtu_SI_m_ChildLckSts, boolean
  *rty_SO_b_DoorRlsReq, uint8 *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E
  *rty_SO_m_UnlockReq, DW_FRDoorRlsReq_REL_T *localDW);

#endif                                 /* RTW_HEADER_REL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
