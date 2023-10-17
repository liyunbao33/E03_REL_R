/*
 * File: REL_private.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Oct 17 17:36:49 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REL_private_h_
#define RTW_HEADER_REL_private_h_
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "REL.h"
#include "REL_types.h"

extern void REL_FRDoorRlsDriver_Init(uint8 *rty_SO_e_MotorCmd, uint8
  *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error);
extern void REL_FRDoorRlsDriver(uint8 rtu_SI_e_Volt100mV, boolean
  rtu_SO_b_DoorRlsReq, Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen,
  uint8 rtu_SI_e_DoorRlsDelayTime, uint8 *rty_SO_e_MotorCmd, uint8
  *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error, DW_FRDoorRlsDriver_REL_T *localDW);
extern void REL_FRDoorRlsReq_Init(boolean *rty_SO_b_DoorRlsReq, Unlock_Req_E
  *rty_SO_m_UnlockReq);
extern void REL_FRDoorRlsReq(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, Door_Sts_E rtu_SI_m_DoorLockSts, Rat_Sts_E
  rtu_SI_m_DoorRatSts, boolean rtu_SI_b_DoorInBtnSts, boolean
  rtu_SI_b_DoorHndBtnSts, Child_Sts_E rtu_SI_m_ChildLckSts, boolean
  *rty_SO_b_DoorRlsReq, Unlock_Req_E *rty_SO_m_UnlockReq, DW_FRDoorRlsReq_REL_T *
  localDW);

#endif                                 /* RTW_HEADER_REL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
