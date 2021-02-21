/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) Accelerator product.
 */

/*
 * NNEntradaRadom_acc.c
 *
 * Real-Time Workshop code generation for Simulink model "NNEntradaRadom_acc.mdl".
 *
 * Model Version              : 1.17
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Dec 16 08:39:45 2009
 */
#include <math.h>
#include "NNEntradaRadom_acc.h"
#include "NNEntradaRadom_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /* local block i/o variables */
  real_T B_3_15_0;
  real_T B_3_34_0;
  real_T B_3_12_0[10];
  real_T B_3_13_0;
  real_T B_3_16_0;
  real_T B_3_19_0[2];
  real_T B_3_21_0[2];
  real_T B_3_22_0[10];
  real_T B_3_23_0[10];
  real_T B_3_32_0[10];
  real_T B_3_27_0;
  real_T B_3_38_0;
  if (ssIsSampleHit(S, 2, 0)) {        /* Sample time: [0.1s, 0.0s] */
    /* ToWorkspace: '<Root>/To Workspace2' */
    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 3, 0, SS_CALL_MDL_OUTPUTS);
  }

  if (ssIsSampleHit(S, 1, 0)) {        /* Sample time: [0.0s, 1.0s] */
    /* Scope: '<Root>/Scope1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 3, 1, SS_CALL_MDL_OUTPUTS);
  }

  /* StateSpace Block: '<S3>/B_3_2' */
  {
    ((BlockIO *) _ssGetBlockIO(S))->B_3_2_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_2*((ContinuousStates *) ssGetContStates(S))->StateSpace_CSTATE;
  }

  if (ssIsSampleHit(S, 2, 0)) {        /* Sample time: [0.1s, 0.0s] */
    ((BlockIO *) _ssGetBlockIO(S))->B_3_3_0 = rt_SATURATE(((BlockIO *)
      _ssGetBlockIO(S))->B_3_2_0, ((Parameters *) ssGetDefaultParam(S))->P_6,
      ((Parameters *) ssGetDefaultParam(S))->P_5);

    /* Scope: '<Root>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 3, 4, SS_CALL_MDL_OUTPUTS);
  }

  if (ssIsSampleHit(S, 3, 0)) {        /* Sample time: [0.2s, 0.0s] */
    /* Level1 S-Function Block: '<S1>/B_3_5' (predopt) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 3, 5, SS_CALL_MDL_OUTPUTS);
  }

  if (ssIsSampleHit(S, 2, 0)) {        /* Sample time: [0.1s, 0.0s] */
    ((BlockIO *) _ssGetBlockIO(S))->B_3_6_0 = rt_SATURATE(((BlockIO *)
      _ssGetBlockIO(S))->B_3_5_0, ((Parameters *) ssGetDefaultParam(S))->P_52,
      ((Parameters *) ssGetDefaultParam(S))->P_51);

    /* Scope: '<Root>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 3, 7, SS_CALL_MDL_OUTPUTS);
  }

  if (ssIsSampleHit(S, 4, 0)) {        /* Sample time: [500.0s, 0.0s] */
    /* RandomNumber: '<Root>/Random Number' */
    ((BlockIO *) _ssGetBlockIO(S))->B_3_8_0 = ((D_Work *) ssGetRootDWork(S))
      ->RandomNumber_RWORK.NextOutput;
  }

  if (ssIsSampleHit(S, 2, 0)) {        /* Sample time: [0.1s, 0.0s] */
    /* ToWorkspace: '<Root>/To Workspace' */
    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 3, 9, SS_CALL_MDL_OUTPUTS);

    /* ToWorkspace: '<Root>/To Workspace1' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 3, 10, SS_CALL_MDL_OUTPUTS);

    /* ToWorkspace: '<Root>/To Workspace3' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 3, 11, SS_CALL_MDL_OUTPUTS);
  }

  {
    int32_T i;
    if (ssIsSampleHit(S, 3, 0)) {
      for (i = 0; i < 10; i++) {
        B_3_12_0[i] = ((Parameters *) ssGetDefaultParam(S))->P_56[i];
      }

      B_3_13_0 = ((Parameters *) ssGetDefaultParam(S))->P_57;
      B_3_27_0 = ((Parameters *) ssGetDefaultParam(S))->P_58;
    }

    if (ssIsSampleHit(S, 2, 0)) {
      B_3_15_0 = ((Parameters *) ssGetDefaultParam(S))->P_59;
    }
  }

  if (ssIsSampleHit(S, 3, 0)) {        /* Sample time: [0.2s, 0.0s] */
    B_3_16_0 = ((Parameters *) ssGetDefaultParam(S))->P_60;
    if (B_3_27_0 >= ((Parameters *) ssGetDefaultParam(S))->P_61) {
      ((BlockIO *) _ssGetBlockIO(S))->B_3_18_0 = (((BlockIO *) _ssGetBlockIO(S)
        )->B_3_5_0 - -15.0) * 2.0 / 30.0 - 1.0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_3_18_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_3_5_0;
    }

    /* DiscreteStateSpace: '<S4>/Discrete State-Space1' */

    /* DiscreteStateSpace Block: '<S4>/B_3_15' */
    {
      B_3_19_0[0] = ((Parameters *) ssGetDefaultParam(S))->P_65*((BlockIO *)
        _ssGetBlockIO(S))->B_3_18_0;
      B_3_19_0[1] = ((Parameters *) ssGetDefaultParam(S))->P_64*((D_Work *)
        ssGetRootDWork(S))->DiscreteStateSpace1_DSTATE;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_3_20_0 = ((D_Work *) ssGetRootDWork(S))
      ->UnitDelay1_DSTATE;

    /* DiscreteStateSpace: '<S4>/Discrete State-Space2' */

    /* DiscreteStateSpace Block: '<S4>/B_3_17' */
    {
      B_3_21_0[0] = ((Parameters *) ssGetDefaultParam(S))->P_71*((BlockIO *)
        _ssGetBlockIO(S))->B_3_20_0;
      B_3_21_0[1] = ((Parameters *) ssGetDefaultParam(S))->P_70*((D_Work *)
        ssGetRootDWork(S))->DiscreteStateSpace2_DSTATE;
    }

    /* Gain Block: '<S4>/Matrix Gain1'
     * About '<S4>/Matrix Gain1 :'
     *   Gain value: LW1_2


     */
    {
      static const int_T dims[3] = { 10, 2, 1 };

      rt_MatMultRR_Dbl((real_T *)B_3_22_0, (real_T *)&((Parameters *)
        ssGetDefaultParam(S))->P_73[0],
                       (real_T *)B_3_21_0, &dims[0]);
    }

    /* Gain Block: '<S4>/Matrix Gain'
     * About '<S4>/Matrix Gain :'
     *   Gain value: IW


     */
    {
      static const int_T dims[3] = { 10, 2, 1 };

      rt_MatMultRR_Dbl((real_T *)B_3_23_0, (real_T *)&((Parameters *)
        ssGetDefaultParam(S))->P_74[0],
                       (real_T *)B_3_19_0, &dims[0]);
    }

    {
      int32_T i;
      for (i = 0; i < 10; i++) {
        B_3_32_0[i] = 1.0 / (exp(((B_3_22_0[i] + B_3_23_0[i]) + B_3_12_0[i]) *
                              ((Parameters *) ssGetDefaultParam(S))->P_75) +
                             ((Parameters *) ssGetDefaultParam(S))->P_76) *
          ((Parameters *) ssGetDefaultParam(S))->P_77 - ((Parameters *)
          ssGetDefaultParam(S))->P_78;
      }
    }

    /* Gain Block: '<S4>/Matrix Gain2'
     * About '<S4>/Matrix Gain2 :'
     *   Gain value: LW2_1


     */
    {
      static const int_T dims[3] = { 1, 10, 1 };

      rt_MatMultRR_Dbl((real_T *)&B_3_38_0, (real_T *)&((Parameters *)
        ssGetDefaultParam(S))->P_79[0],
                       (real_T *)B_3_32_0, &dims[0]);
    }
  }

  if (ssIsSampleHit(S, 3, 0)) {
    B_3_34_0 = B_3_38_0 + B_3_13_0;
  }

  if (ssIsSampleHit(S, 2, 0)) {
    if (B_3_15_0 >= ((Parameters *) ssGetDefaultParam(S))->P_80) {
      ((BlockIO *) _ssGetBlockIO(S))->B_3_36_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_3_3_0 * 2.0 / 15.0 - 1.0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_3_36_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_3_3_0;
    }
  }

  if (ssIsSampleHit(S, 3, 0)) {        /* Sample time: [0.2s, 0.0s] */
    {
      int32_T i;
      if (B_3_16_0 >= ((Parameters *) ssGetDefaultParam(S))->P_81) {
        B_3_38_0 = (B_3_34_0 + 1.0) * 15.0 / 2.0;
      } else {
        B_3_38_0 = B_3_34_0;
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_3_39_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_3_8_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_3_39_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_3_3_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_3_39_0[2] = B_3_38_0;
      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_3_39_0[i + 3] = B_3_32_0[i];
      }
    }
  }

  /* StateSpace Block: '<S2>/B_3_26' */
  {
    ((BlockIO *) _ssGetBlockIO(S))->B_3_40_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_84*((ContinuousStates *) ssGetContStates(S))->StateSpace_CSTATE_m;
  }

  if (ssIsSampleHit(S, 2, 0)) {        /* Sample time: [0.1s, 0.0s] */
    ((BlockIO *) _ssGetBlockIO(S))->B_3_41_0 = rt_SATURATE(((BlockIO *)
      _ssGetBlockIO(S))->B_3_40_0, ((Parameters *) ssGetDefaultParam(S))->P_88,
      ((Parameters *) ssGetDefaultParam(S))->P_87);
  }

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  if (ssIsSampleHit(S, 3, 0)) {        /* Sample time: [0.2s, 0.0s] */
    /* Level1 S-Function Block: '<S1>/B_3_5' (predopt) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 3, 5, SS_CALL_MDL_UPDATE);
  }

  if (ssIsSampleHit(S, 4, 0)) {        /* Sample time: [500.0s, 0.0s] */
    /* RandomNumber Block: '<Root>/B_3_8' */
    ((D_Work *) ssGetRootDWork(S))->RandomNumber_RWORK.NextOutput =
      rt_NormalRand((uint32_T *)&((D_Work *) ssGetRootDWork(S))
                    ->RandomNumber_IWORK.RandSeed)*((Parameters *)
      ssGetDefaultParam(S))->P_54+((Parameters *) ssGetDefaultParam(S))->P_53;
  }

  if (ssIsSampleHit(S, 3, 0)) {
  }

  if (ssIsSampleHit(S, 2, 0)) {
  }

  if (ssIsSampleHit(S, 3, 0)) {        /* Sample time: [0.2s, 0.0s] */
    /* DiscreteStateSpace Block: '<S4>/B_3_15' */
    {
      static real_T xnew[1];
      xnew[0] = ((Parameters *) ssGetDefaultParam(S))->P_63*((BlockIO *)
        _ssGetBlockIO(S))->B_3_18_0;
      (void) memcpy(&((D_Work *) ssGetRootDWork(S))->DiscreteStateSpace1_DSTATE,
                    xnew,
                    sizeof(real_T)*1);
    }

    ((D_Work *) ssGetRootDWork(S))->UnitDelay1_DSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_3_36_0;

    /* DiscreteStateSpace Block: '<S4>/B_3_17' */
    {
      static real_T xnew[1];
      xnew[0] = ((Parameters *) ssGetDefaultParam(S))->P_69*((BlockIO *)
        _ssGetBlockIO(S))->B_3_20_0;
      (void) memcpy(&((D_Work *) ssGetRootDWork(S))->DiscreteStateSpace2_DSTATE,
                    xnew,
                    sizeof(real_T)*1);
    }
  }

  if (ssIsSampleHit(S, 3, 0)) {
  }

  if (ssIsSampleHit(S, 2, 0)) {
  }

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  /* StateSpace Block: '<S3>/B_3_2' */
  {
    ((StateDerivatives *) ssGetdX(S))->StateSpace_CSTATE = ((Parameters *)
      ssGetDefaultParam(S))->P_1*((BlockIO *) _ssGetBlockIO(S))->B_3_41_0;
    ((StateDerivatives *) ssGetdX(S))->StateSpace_CSTATE += (((Parameters *)
      ssGetDefaultParam(S))->P_0)*((ContinuousStates *) ssGetContStates(S))
      ->StateSpace_CSTATE;
  }

  /* StateSpace Block: '<S2>/B_3_26' */
  {
    ((StateDerivatives *) ssGetdX(S))->StateSpace_CSTATE_m = ((Parameters *)
      ssGetDefaultParam(S))->P_83*((BlockIO *) _ssGetBlockIO(S))->B_3_6_0;
    ((StateDerivatives *) ssGetdX(S))->StateSpace_CSTATE_m += (((Parameters *)
      ssGetDefaultParam(S))->P_82)*((ContinuousStates *) ssGetContStates(S))
      ->StateSpace_CSTATE_m;
  }
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 1697521306U);
  ssSetChecksumVal(S, 1, 3332912331U);
  ssSetChecksumVal(S, 2, 133997593U);
  ssSetChecksumVal(S, 3, 1657924326U);

  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

  /* Accelerator check memory map size match for DWork */
  if (ssGetSizeofDWork(S) != sizeof(D_Work)) {
    ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
                     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for BlockIO */
  if (ssGetSizeofGlobalBlockIO(S) != sizeof(BlockIO)) {
    ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
                     "not match for accelerator mex file.");
  }

  /* model parameters */
  _ssSetDefaultParam(S, (real_T *) &rtDefaultParameters);

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Empty mdlInitializeSampleTimes function (never called) */
static void mdlInitializeSampleTimes(SimStruct *S)
{
}

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S)
{
}

/* MATLAB MEX Glue */
#include "simulink.c"
