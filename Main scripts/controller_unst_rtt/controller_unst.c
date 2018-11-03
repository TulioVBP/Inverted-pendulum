/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_unst.c
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

const boolean_T controller_unst_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
B_controller_unst_T controller_unst_B;

/* Block states (auto storage) */
DW_controller_unst_T controller_unst_DW;

/* Real-time model */
RT_MODEL_controller_unst_T controller_unst_M_;
RT_MODEL_controller_unst_T *const controller_unst_M = &controller_unst_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/* Model output function */
void controller_unst_output(void)
{
  boolean_T rtb_SFunction_0;
  real_T rtb_Saturation;
  real_T rtb_Sum2;
  uint8_T tmp;

  /* S-Function (arduinodigitalinput_sfcn): '<S2>/S-Function' */
  rtb_SFunction_0 = MW_digitalRead(controller_unst_P.SFunction_p1);

  /* S-Function (signals): '<S9>/S-Function2' */
  signals_Outputs_wrapper( &controller_unst_B.SFunction2_o1,
    &controller_unst_B.SFunction2_o2, &controller_unst_DW.SFunction2_DSTATE);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  S-Function (arduinodigitalinput_sfcn): '<S2>/S-Function'
   */
  if (controller_unst_B.SFunction2_o1) {
    rtb_Saturation = rtb_SFunction_0;
  } else {
    rtb_Saturation = controller_unst_P.Constant_Value;
  }

  /* End of Switch: '<S3>/Switch' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  if (rtb_Saturation < 256.0) {
    if (rtb_Saturation >= 0.0) {
      tmp = (uint8_T)rtb_Saturation;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S3>/Digital Output1' */
  MW_digitalWrite(controller_unst_P.DigitalOutput1_pinNumber, tmp);

  /* S-Function (arduinodigitalinput_sfcn): '<S1>/S-Function' */
  controller_unst_B.SFunction_b = MW_digitalRead
    (controller_unst_P.SFunction_p1_f);

  /* DataTypeConversion: '<S11>/conversion3' */
  controller_unst_B.conversion3 = false;

  /* DataTypeConversion: '<S11>/conversion9' */
  controller_unst_B.conversion9 = false;

  /* DataTypeConversion: '<S11>/conversion10' */
  controller_unst_B.conversion10 = false;

  /* S-Function (sfcn_encoder): '<S8>/S-Function' */
  sfcn_encoder_Outputs_wrapper(&controller_unst_B.SFunction_b,
    &controller_unst_B.SFunction, &controller_unst_DW.SFunction_DSTATE,
    &controller_unst_P.SFunction_P1_h, 1, &controller_unst_P.Pendulum_dt_enc, 1);

  /* Gain: '<Root>/degrees' */
  rtb_Saturation = controller_unst_P.degrees_Gain * (real_T)
    controller_unst_B.SFunction;

  /* DataTypeConversion: '<S11>/conversion13' incorporates:
   *  Gain: '<Root>/Gain'
   */
  controller_unst_B.conversion13 = (real32_T)(controller_unst_P.Gain_Gain *
    rtb_Saturation);

  /* S-Function (sfcn_encoder): '<S6>/S-Function' */
  sfcn_encoder_Outputs_wrapper(&controller_unst_B.SFunction_b,
    &controller_unst_B.SFunction_l, &controller_unst_DW.SFunction_DSTATE_p,
    &controller_unst_P.SFunction_P1_hv, 1, &controller_unst_P.Gear_dt_enc, 1);

  /* DataTypeConversion: '<S11>/conversion2' incorporates:
   *  Gain: '<Root>/meters'
   */
  controller_unst_B.conversion2 = (real32_T)(controller_unst_P.meters_Gain *
    (real_T)controller_unst_B.SFunction_l);

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  controller_unst_B.TSamp = rtb_Saturation * controller_unst_P.TSamp_WtEt;

  /* Sum: '<S10>/Sum2' incorporates:
   *  Constant: '<S10>/Constant'
   *  Gain: '<S10>/Gain'
   *  Gain: '<S10>/Gain1'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S10>/Sum1'
   *  Sum: '<S5>/Diff'
   *  UnitDelay: '<S5>/UD'
   */
  rtb_Sum2 = (controller_unst_P.Constant_Value_m - (controller_unst_B.TSamp -
    controller_unst_DW.UD_DSTATE)) * controller_unst_P.Gain_Gain_m +
    (controller_unst_P.Constant_Value_m - rtb_Saturation) *
    controller_unst_P.Gain1_Gain;

  /* Lookup_n-D: '<Root>/Board voltage compensation' */
  rtb_Saturation = look1_binlxpw(rtb_Sum2,
    controller_unst_P.Boardvoltagecompensation_bp01Da,
    controller_unst_P.Boardvoltagecompensation_tableD, 54U);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation > controller_unst_P.Saturation_UpperSat) {
    rtb_Saturation = controller_unst_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation < controller_unst_P.Saturation_LowerSat) {
      rtb_Saturation = controller_unst_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* DataTypeConversion: '<S11>/conversion4' */
  controller_unst_B.conversion4 = (real32_T)rtb_Saturation;

  /* DataTypeConversion: '<S11>/conversion5' */
  controller_unst_B.conversion5 = (real32_T)rtb_Sum2;

  /* DataTypeConversion: '<S7>/conversion8' */
  controller_unst_B.conversion8 = (real32_T)rtb_Saturation;

  /* Logic: '<S7>/Logical Operator' incorporates:
   *  S-Function (arduinodigitalinput_sfcn): '<S2>/S-Function'
   */
  controller_unst_B.LogicalOperator = (rtb_SFunction_0 &&
    controller_unst_B.SFunction2_o1);

  /* S-Function (sfcn_motor_new): '<S7>/S-Function1' */
  sfcn_motor_new_Outputs_wrapper(&controller_unst_B.conversion8,
    &controller_unst_B.LogicalOperator, &controller_unst_B.SFunction1_o1,
    &controller_unst_B.SFunction1_o2, &controller_unst_B.SFunction1_o3,
    &controller_unst_DW.SFunction1_DSTATE, &controller_unst_P.SFunction1_P1, 1,
    &controller_unst_P.SFunction1_P2, 1, &controller_unst_P.SFunction1_P3, 1);

  /* DataTypeConversion: '<S11>/conversion7' */
  controller_unst_B.conversion7 = 0.0F;

  /* S-Function (SerialTx): '<S11>/S-Function' */
  SerialTx_Outputs_wrapper(&controller_unst_B.SFunction2_o1, (boolean_T*)
    &controller_unst_BGND, (boolean_T*)&controller_unst_BGND, (boolean_T*)
    &controller_unst_BGND, &controller_unst_B.SFunction_b,
    &controller_unst_B.conversion3, &controller_unst_B.conversion9,
    &controller_unst_B.conversion10, &controller_unst_B.conversion13,
    &controller_unst_B.conversion2, &controller_unst_B.conversion4,
    &controller_unst_B.conversion5, &controller_unst_B.SFunction1_o1,
    &controller_unst_B.conversion7, &controller_unst_DW.SFunction_DSTATE_l,
    &controller_unst_P.SFunction_P1, 1, &controller_unst_P.SFunction_P2, 1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   */
  MW_digitalWrite(controller_unst_P.DigitalOutput_pinNumber, (uint8_T)
                  controller_unst_B.SFunction2_o1);

  /* S-Function (arduinodigitaloutput_sfcn): '<S13>/Digital Output' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   */
  MW_digitalWrite(controller_unst_P.DigitalOutput_pinNumber_e, (uint8_T)
                  controller_unst_B.SFunction2_o2);

  /* S-Function (data_struct_init): '<S9>/S-Function1' */
  data_struct_init_Outputs_wrapper( &controller_unst_DW.SFunction1_DSTATE_f);
}

/* Model update function */
void controller_unst_update(void)
{
  /* S-Function "signals_wrapper" Block: <S9>/S-Function2 */
  signals_Update_wrapper( &controller_unst_B.SFunction2_o1,
    &controller_unst_B.SFunction2_o2, &controller_unst_DW.SFunction2_DSTATE);

  /* S-Function "sfcn_encoder_wrapper" Block: <S8>/S-Function */
  sfcn_encoder_Update_wrapper(&controller_unst_B.SFunction_b,
    &controller_unst_B.SFunction, &controller_unst_DW.SFunction_DSTATE,
    &controller_unst_P.SFunction_P1_h, 1, &controller_unst_P.Pendulum_dt_enc, 1);

  /* S-Function "sfcn_encoder_wrapper" Block: <S6>/S-Function */
  sfcn_encoder_Update_wrapper(&controller_unst_B.SFunction_b,
    &controller_unst_B.SFunction_l, &controller_unst_DW.SFunction_DSTATE_p,
    &controller_unst_P.SFunction_P1_hv, 1, &controller_unst_P.Gear_dt_enc, 1);

  /* Update for UnitDelay: '<S5>/UD' */
  controller_unst_DW.UD_DSTATE = controller_unst_B.TSamp;

  /* S-Function "sfcn_motor_new_wrapper" Block: <S7>/S-Function1 */
  sfcn_motor_new_Update_wrapper(&controller_unst_B.conversion8,
    &controller_unst_B.LogicalOperator, &controller_unst_B.SFunction1_o1,
    &controller_unst_B.SFunction1_o2, &controller_unst_B.SFunction1_o3,
    &controller_unst_DW.SFunction1_DSTATE, &controller_unst_P.SFunction1_P1, 1,
    &controller_unst_P.SFunction1_P2, 1, &controller_unst_P.SFunction1_P3, 1);

  /* S-Function "SerialTx_wrapper" Block: <S11>/S-Function */
  SerialTx_Update_wrapper(&controller_unst_B.SFunction2_o1, (boolean_T*)
    &controller_unst_BGND, (boolean_T*)&controller_unst_BGND, (boolean_T*)
    &controller_unst_BGND, &controller_unst_B.SFunction_b,
    &controller_unst_B.conversion3, &controller_unst_B.conversion9,
    &controller_unst_B.conversion10, &controller_unst_B.conversion13,
    &controller_unst_B.conversion2, &controller_unst_B.conversion4,
    &controller_unst_B.conversion5, &controller_unst_B.SFunction1_o1,
    &controller_unst_B.conversion7, &controller_unst_DW.SFunction_DSTATE_l,
    &controller_unst_P.SFunction_P1, 1, &controller_unst_P.SFunction_P2, 1);

  /* S-Function "data_struct_init_wrapper" Block: <S9>/S-Function1 */
  data_struct_init_Update_wrapper(&controller_unst_DW.SFunction1_DSTATE_f);
}

/* Model initialize function */
void controller_unst_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(controller_unst_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &controller_unst_B), 0,
                sizeof(B_controller_unst_T));

  /* states (dwork) */
  (void) memset((void *)&controller_unst_DW, 0,
                sizeof(DW_controller_unst_T));

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S2>/S-Function' */
  MW_pinModeInput(controller_unst_P.SFunction_p1);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S3>/Digital Output1' */
  MW_pinModeOutput(controller_unst_P.DigitalOutput1_pinNumber);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S1>/S-Function' */
  MW_pinModeInput(controller_unst_P.SFunction_p1_f);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' */
  MW_pinModeOutput(controller_unst_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S13>/Digital Output' */
  MW_pinModeOutput(controller_unst_P.DigitalOutput_pinNumber_e);

  /* S-Function Block: <S9>/S-Function2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        controller_unst_DW.SFunction2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S8>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        controller_unst_DW.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S6>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        controller_unst_DW.SFunction_DSTATE_p = initVector[0];
      }
    }
  }

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  controller_unst_DW.UD_DSTATE =
    controller_unst_P.DiscreteDerivative1_ICPrevScale;

  /* S-Function Block: <S7>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        controller_unst_DW.SFunction1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S11>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        controller_unst_DW.SFunction_DSTATE_l = initVector[0];
      }
    }
  }

  /* S-Function Block: <S9>/S-Function1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        controller_unst_DW.SFunction1_DSTATE_f = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void controller_unst_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
