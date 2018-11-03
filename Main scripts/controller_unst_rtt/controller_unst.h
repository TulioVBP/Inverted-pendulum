/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_unst.h
 *
 * Code generated for Simulink model 'controller_unst'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Wed Oct 31 09:58:26 2018
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_unst_h_
#define RTW_HEADER_controller_unst_h_
#include <stddef.h>
#include <string.h>
#ifndef controller_unst_COMMON_INCLUDES_
# define controller_unst_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitalinput_lct.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* controller_unst_COMMON_INCLUDES_ */

#include "controller_unst_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T TSamp;                        /* '<S5>/TSamp' */
  real32_T conversion13;               /* '<S11>/conversion13' */
  real32_T conversion2;                /* '<S11>/conversion2' */
  real32_T conversion4;                /* '<S11>/conversion4' */
  real32_T conversion5;                /* '<S11>/conversion5' */
  real32_T conversion8;                /* '<S7>/conversion8' */
  real32_T SFunction1_o1;              /* '<S7>/S-Function1' */
  real32_T SFunction1_o2;              /* '<S7>/S-Function1' */
  real32_T SFunction1_o3;              /* '<S7>/S-Function1' */
  real32_T conversion7;                /* '<S11>/conversion7' */
  int32_T SFunction;                   /* '<S8>/S-Function' */
  int32_T SFunction_l;                 /* '<S6>/S-Function' */
  boolean_T SFunction2_o1;             /* '<S9>/S-Function2' */
  boolean_T SFunction2_o2;             /* '<S9>/S-Function2' */
  boolean_T SFunction_b;               /* '<S1>/S-Function' */
  boolean_T conversion3;               /* '<S11>/conversion3' */
  boolean_T conversion9;               /* '<S11>/conversion9' */
  boolean_T conversion10;              /* '<S11>/conversion10' */
  boolean_T LogicalOperator;           /* '<S7>/Logical Operator' */
} B_controller_unst_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction2_DSTATE;            /* '<S9>/S-Function2' */
  real_T SFunction_DSTATE;             /* '<S8>/S-Function' */
  real_T SFunction_DSTATE_p;           /* '<S6>/S-Function' */
  real_T UD_DSTATE;                    /* '<S5>/UD' */
  real_T SFunction1_DSTATE;            /* '<S7>/S-Function1' */
  real_T SFunction_DSTATE_l;           /* '<S11>/S-Function' */
  real_T SFunction1_DSTATE_f;          /* '<S9>/S-Function1' */
} DW_controller_unst_T;

/* Parameters (auto storage) */
struct P_controller_unst_T_ {
  real_T DiscreteDerivative1_ICPrevScale;/* Mask Parameter: DiscreteDerivative1_ICPrevScale
                                          * Referenced by: '<S5>/UD'
                                          */
  real_T Pendulum_dt_enc;              /* Mask Parameter: Pendulum_dt_enc
                                        * Referenced by: '<S8>/S-Function'
                                        */
  real_T Gear_dt_enc;                  /* Mask Parameter: Gear_dt_enc
                                        * Referenced by: '<S6>/S-Function'
                                        */
  uint32_T DigitalOutput1_pinNumber;   /* Mask Parameter: DigitalOutput1_pinNumber
                                        * Referenced by: '<S3>/Digital Output1'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S12>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_e;  /* Mask Parameter: DigitalOutput_pinNumber_e
                                        * Referenced by: '<S13>/Digital Output'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T degrees_Gain;                 /* Expression: 0.18*pi/180
                                        * Referenced by: '<Root>/degrees'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T meters_Gain;                  /* Expression: 5.3689e-05
                                        * Referenced by: '<Root>/meters'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S5>/TSamp'
                                        */
  real_T Constant_Value_m;             /* Expression: pi
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 1
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 20
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Boardvoltagecompensation_tableD[55];/* Expression: [-12 -10.90 -10.11 -9.00 -7.84 -6.96 -6.0 -5.02 -4.01 -2.94 -2.0 -1.89 -1.79 -1.70 -1.59 -1.49 -1.39 -1.30 -1.20 -1.09 -0.99 -0.89 -0.80 -0.71 -0.59 -0.50 -0.40 0 0.42 0.52 0.59 0.71 0.80 0.91 1.00 1.11 1.21 1.35 1.44 1.52 1.62 1.70 1.81 1.90 2.00 3.02 4.01 5.06 5.97 6.97 7.97 9.05 10.03 11.01 12.00]
                                              * Referenced by: '<Root>/Board voltage compensation'
                                              */
  real_T Boardvoltagecompensation_bp01Da[55];/* Expression: [-11.90 -10.89 -10.05 -8.92 -7.80 -6.96 -5.98 -5.01 -3.98 -2.95 -2.02 -1.94 -1.85 -1.75 -1.56 -1.47 -1.37 -1.28 -1.18 -1.08 -0.98 -0.87 -0.77 -0.63 -0.53 -0.35 -0.06 0.0 0.08 0.34 0.51 0.63 0.75 0.88 0.99 1.00 1.19 1.39 1.48 1.58 1.67 1.77 1.86 1.96 2.04 3.07 4.00 5.07 5.96 6.98 7.98 9.03 10.02 10.99 11.93]
                                              * Referenced by: '<Root>/Board voltage compensation'
                                              */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T SFunction_P1;                 /* Expression: sample_time
                                        * Referenced by: '<S11>/S-Function'
                                        */
  real32_T SFunction1_P2;              /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  real32_T SFunction1_P3;              /* Expression: single(dt_mot)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  uint32_T SFunction_p1;               /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint32_T SFunction_p1_f;             /* Computed Parameter: SFunction_p1_f
                                        * Referenced by: '<S1>/S-Function'
                                        */
  uint8_T SFunction_P1_h;              /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S8>/S-Function'
                                        */
  uint8_T SFunction_P1_hv;             /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S6>/S-Function'
                                        */
  uint8_T SFunction1_P1;               /* Expression: uint8(MotorID)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  uint8_T SFunction_P2;                /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S11>/S-Function'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_controller_unst_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_controller_unst_T controller_unst_P;

/* Block signals (auto storage) */
extern B_controller_unst_T controller_unst_B;

/* Block states (auto storage) */
extern DW_controller_unst_T controller_unst_DW;

/* External data declarations for dependent source files */
extern const boolean_T controller_unst_BGND;/* boolean_T ground */

/* Model entry point functions */
extern void controller_unst_initialize(void);
extern void controller_unst_output(void);
extern void controller_unst_update(void);
extern void controller_unst_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_unst_T *const controller_unst_M;

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
 * '<Root>' : 'controller_unst'
 * '<S1>'   : 'controller_unst/Digital Input'
 * '<S2>'   : 'controller_unst/Digital Input1'
 * '<S3>'   : 'controller_unst/Digital Output'
 * '<S4>'   : 'controller_unst/Discrete Derivative'
 * '<S5>'   : 'controller_unst/Discrete Derivative1'
 * '<S6>'   : 'controller_unst/Gear'
 * '<S7>'   : 'controller_unst/Motor'
 * '<S8>'   : 'controller_unst/Pendulum '
 * '<S9>'   : 'controller_unst/PoliArd Init'
 * '<S10>'  : 'controller_unst/Subsystem'
 * '<S11>'  : 'controller_unst/Transmission'
 * '<S12>'  : 'controller_unst/PoliArd Init/Digital Output1'
 * '<S13>'  : 'controller_unst/PoliArd Init/Digital Output3'
 */
#endif                                 /* RTW_HEADER_controller_unst_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
