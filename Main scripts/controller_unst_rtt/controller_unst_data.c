/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_unst_data.c
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

#include "controller_unst.h"
#include "controller_unst_private.h"

/* Block parameters (auto storage) */
P_controller_unst_T controller_unst_P = {
  0.0,                                 /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                                        * Referenced by: '<S5>/UD'
                                        */
  -1.0,                                /* Mask Parameter: Pendulum_dt_enc
                                        * Referenced by: '<S8>/S-Function'
                                        */
  -1.0,                                /* Mask Parameter: Gear_dt_enc
                                        * Referenced by: '<S6>/S-Function'
                                        */
  40U,                                 /* Mask Parameter: DigitalOutput1_pinNumber
                                        * Referenced by: '<S3>/Digital Output1'
                                        */
  11U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S12>/Digital Output'
                                        */
  12U,                                 /* Mask Parameter: DigitalOutput_pinNumber_e
                                        * Referenced by: '<S13>/Digital Output'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  0.0031415926535897933,               /* Expression: 0.18*pi/180
                                        * Referenced by: '<Root>/degrees'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain'
                                        */
  5.3689E-5,                           /* Expression: 5.3689e-05
                                        * Referenced by: '<Root>/meters'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S5>/TSamp'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S10>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Gain'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<S10>/Gain1'
                                        */

  /*  Expression: [-12 -10.90 -10.11 -9.00 -7.84 -6.96 -6.0 -5.02 -4.01 -2.94 -2.0 -1.89 -1.79 -1.70 -1.59 -1.49 -1.39 -1.30 -1.20 -1.09 -0.99 -0.89 -0.80 -0.71 -0.59 -0.50 -0.40 0 0.42 0.52 0.59 0.71 0.80 0.91 1.00 1.11 1.21 1.35 1.44 1.52 1.62 1.70 1.81 1.90 2.00 3.02 4.01 5.06 5.97 6.97 7.97 9.05 10.03 11.01 12.00]
   * Referenced by: '<Root>/Board voltage compensation'
   */
  { -12.0, -10.9, -10.11, -9.0, -7.84, -6.96, -6.0, -5.02, -4.01, -2.94, -2.0,
    -1.89, -1.79, -1.7, -1.59, -1.49, -1.39, -1.3, -1.2, -1.09, -0.99, -0.89,
    -0.8, -0.71, -0.59, -0.5, -0.4, 0.0, 0.42, 0.52, 0.59, 0.71, 0.8, 0.91, 1.0,
    1.11, 1.21, 1.35, 1.44, 1.52, 1.62, 1.7, 1.81, 1.9, 2.0, 3.02, 4.01, 5.06,
    5.97, 6.97, 7.97, 9.05, 10.03, 11.01, 12.0 },

  /*  Expression: [-11.90 -10.89 -10.05 -8.92 -7.80 -6.96 -5.98 -5.01 -3.98 -2.95 -2.02 -1.94 -1.85 -1.75 -1.56 -1.47 -1.37 -1.28 -1.18 -1.08 -0.98 -0.87 -0.77 -0.63 -0.53 -0.35 -0.06 0.0 0.08 0.34 0.51 0.63 0.75 0.88 0.99 1.00 1.19 1.39 1.48 1.58 1.67 1.77 1.86 1.96 2.04 3.07 4.00 5.07 5.96 6.98 7.98 9.03 10.02 10.99 11.93]
   * Referenced by: '<Root>/Board voltage compensation'
   */
  { -11.9, -10.89, -10.05, -8.92, -7.8, -6.96, -5.98, -5.01, -3.98, -2.95, -2.02,
    -1.94, -1.85, -1.75, -1.56, -1.47, -1.37, -1.28, -1.18, -1.08, -0.98, -0.87,
    -0.77, -0.63, -0.53, -0.35, -0.06, 0.0, 0.08, 0.34, 0.51, 0.63, 0.75, 0.88,
    0.99, 1.0, 1.19, 1.39, 1.48, 1.58, 1.67, 1.77, 1.86, 1.96, 2.04, 3.07, 4.0,
    5.07, 5.96, 6.98, 7.98, 9.03, 10.02, 10.99, 11.93 },
  12.0,                                /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.01,                                /* Expression: sample_time
                                        * Referenced by: '<S11>/S-Function'
                                        */
  2.0F,                                /* Expression: single(DC_bus_mask)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  -1.0F,                               /* Expression: single(dt_mot)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  38U,                                 /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S2>/S-Function'
                                        */
  36U,                                 /* Computed Parameter: SFunction_p1_f
                                        * Referenced by: '<S1>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S8>/S-Function'
                                        */
  3U,                                  /* Expression: uint8(EncoderID)
                                        * Referenced by: '<S6>/S-Function'
                                        */
  1U,                                  /* Expression: uint8(MotorID)
                                        * Referenced by: '<S7>/S-Function1'
                                        */
  6U                                   /* Expression: uint8(sig_to_send)
                                        * Referenced by: '<S11>/S-Function'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
