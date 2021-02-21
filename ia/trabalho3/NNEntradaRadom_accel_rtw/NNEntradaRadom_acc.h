/*
 * NNEntradaRadom_acc.h
 *
 * Real-Time Workshop code generation for Simulink model "NNEntradaRadom_acc.mdl".
 *
 * Model Version              : 1.17
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Dec 16 08:39:45 2009
 */
#ifndef _RTW_HEADER_NNEntradaRadom_acc_h_
#define _RTW_HEADER_NNEntradaRadom_acc_h_
#ifndef _NNEntradaRadom_acc_COMMON_INCLUDES_
# define _NNEntradaRadom_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define S_FUNCTION_NAME                simulink_only_sfcn
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtlibsrc.h"
#include "rt_nonfinite.h"
#endif                                 /* _NNEntradaRadom_acc_COMMON_INCLUDES_ */

#include "NNEntradaRadom_acc_types.h"

/* Block signals (auto storage) */
typedef struct {
  real_T B_3_2_0;                      /* '<S3>/State Space' */
  real_T B_3_3_0;                      /* '<Root>/Sat(2)_0_30' */
  real_T B_3_5_0;                      /* '<S1>/S-Function' */
  real_T B_3_6_0;                      /* '<Root>/Sat(0)_15_-15' */
  real_T B_3_8_0;                      /* '<Root>/Random Number' */
  real_T B_3_18_0;                     /* '<S4>/Switch' */
  real_T B_3_20_0;                     /* '<S4>/Unit Delay1' */
  real_T B_3_36_0;                     /* '<S4>/Switch1' */
  real_T B_3_39_0[13];                 /* 'synthesized block' */
  real_T B_3_40_0;                     /* '<S2>/State Space' */
  real_T B_3_41_0;                     /* '<Root>/Sat(1)_0_30' */
} BlockIO;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction_DSTATE[14];         /* '<S1>/S-Function' */
  real_T DiscreteStateSpace1_DSTATE;   /* '<S4>/Discrete State-Space1' */
  real_T UnitDelay1_DSTATE;            /* '<S4>/Unit Delay1' */
  real_T DiscreteStateSpace2_DSTATE;   /* '<S4>/Discrete State-Space2' */
  struct {
    real_T NextOutput;
  } RandomNumber_RWORK;                /* '<Root>/Random Number' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<Root>/To Workspace2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<Root>/To Workspace3' */

  struct {
    int_T RandSeed;
  } RandomNumber_IWORK;                /* '<Root>/Random Number' */
} D_Work;

/* Continuous states (auto storage) */
typedef struct {
  real_T StateSpace_CSTATE;            /* '<S3>/State Space' */
  real_T StateSpace_CSTATE_m;          /* '<S2>/State Space' */
} ContinuousStates;

/* State derivatives (auto storage) */
typedef struct {
  real_T StateSpace_CSTATE;            /* '<S3>/State Space' */
  real_T StateSpace_CSTATE_m;          /* '<S2>/State Space' */
} StateDerivatives;

/* State disabled  */
typedef struct {
  boolean_T StateSpace_CSTATE;         /* '<S3>/State Space' */
  boolean_T StateSpace_CSTATE_m;       /* '<S2>/State Space' */
} StateDisabled;

/* Parameters (auto storage) */
struct Parameters {
  real_T P_0;                          /* Computed Parameter: A
                                        * '<S3>/State Space'
                                        */
  real_T P_1;                          /* Computed Parameter: B
                                        * '<S3>/State Space'
                                        */
  real_T P_2;                          /* Computed Parameter: C
                                        * '<S3>/State Space'
                                        */
  real_T P_4;                          /* Expression: X0
                                        * '<S3>/State Space'
                                        */
  real_T P_5;                          /* Expression: 30
                                        * '<Root>/Sat(2)_0_30'
                                        */
  real_T P_6;                          /* Expression: 0
                                        * '<Root>/Sat(2)_0_30'
                                        */
  real_T P_7[2];                       /* Computed Parameter: P1Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_8;                          /* Expression: N2
                                        * '<S1>/S-Function'
                                        */
  real_T P_9[2];                       /* Computed Parameter: P2Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_10;                         /* Expression: Ts
                                        * '<S1>/S-Function'
                                        */
  real_T P_11[2];                      /* Computed Parameter: P3Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_12;                         /* Expression: Nu
                                        * '<S1>/S-Function'
                                        */
  real_T P_13[2];                      /* Computed Parameter: P4Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_14;                         /* Expression: maxiter
                                        * '<S1>/S-Function'
                                        */
  real_T P_15[2];                      /* Computed Parameter: P5Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_16;                         /* Expression: csrchfun
                                        * '<S1>/S-Function'
                                        */
  real_T P_17[2];                      /* Computed Parameter: P6Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_18;                         /* Expression: rho
                                        * '<S1>/S-Function'
                                        */
  real_T P_19[2];                      /* Computed Parameter: P7Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_20;                         /* Expression: alpha
                                        * '<S1>/S-Function'
                                        */
  real_T P_21[2];                      /* Computed Parameter: P8Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_22;                         /* Expression: S1
                                        * '<S1>/S-Function'
                                        */
  real_T P_23[2];                      /* Computed Parameter: P9Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_24[20];                     /* Expression: IW
                                        * '<S1>/S-Function'
                                        */
  real_T P_25[2];                      /* Computed Parameter: P10Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_26[20];                     /* Expression: LW1_2
                                        * '<S1>/S-Function'
                                        */
  real_T P_27[2];                      /* Computed Parameter: P11Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_28[10];                     /* Expression: LW2_1
                                        * '<S1>/S-Function'
                                        */
  real_T P_29[2];                      /* Computed Parameter: P12Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_30[10];                     /* Expression: B1
                                        * '<S1>/S-Function'
                                        */
  real_T P_31[2];                      /* Computed Parameter: P13Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_32;                         /* Expression: B2
                                        * '<S1>/S-Function'
                                        */
  real_T P_33[2];                      /* Computed Parameter: P14Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_34;                         /* Expression: Ni
                                        * '<S1>/S-Function'
                                        */
  real_T P_35[2];                      /* Computed Parameter: P15Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_36;                         /* Expression: Nj
                                        * '<S1>/S-Function'
                                        */
  real_T P_37[2];                      /* Computed Parameter: P16Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_38;                         /* Expression: min_i
                                        * '<S1>/S-Function'
                                        */
  real_T P_39[2];                      /* Computed Parameter: P17Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_40;                         /* Expression: max_i
                                        * '<S1>/S-Function'
                                        */
  real_T P_41[2];                      /* Computed Parameter: P18Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_42;                         /* Expression: minp
                                        * '<S1>/S-Function'
                                        */
  real_T P_43[2];                      /* Computed Parameter: P19Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_44;                         /* Expression: maxp
                                        * '<S1>/S-Function'
                                        */
  real_T P_45[2];                      /* Computed Parameter: P20Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_46;                         /* Expression: mint
                                        * '<S1>/S-Function'
                                        */
  real_T P_47[2];                      /* Computed Parameter: P21Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_48;                         /* Expression: maxt
                                        * '<S1>/S-Function'
                                        */
  real_T P_49[2];                      /* Computed Parameter: P22Size
                                        * '<S1>/S-Function'
                                        */
  real_T P_50;                         /* Expression: Normalize
                                        * '<S1>/S-Function'
                                        */
  real_T P_51;                         /* Expression: 15
                                        * '<Root>/Sat(0)_15_-15'
                                        */
  real_T P_52;                         /* Expression: -15
                                        * '<Root>/Sat(0)_15_-15'
                                        */
  real_T P_53;                         /* Expression: 15
                                        * '<Root>/Random Number'
                                        */
  real_T P_54;                         /* Computed Parameter: StdDev
                                        * '<Root>/Random Number'
                                        */
  real_T P_55;                         /* Expression: round(now)
                                        * '<Root>/Random Number'
                                        */
  real_T P_56[10];                     /* Expression: B1
                                        * '<S4>/Constant'
                                        */
  real_T P_57;                         /* Expression: B2
                                        * '<S4>/Constant1'
                                        */
  real_T P_58;                         /* Expression: Normalize
                                        * '<S4>/Constant2'
                                        */
  real_T P_59;                         /* Expression: Normalize
                                        * '<S4>/Constant3'
                                        */
  real_T P_60;                         /* Expression: Normalize
                                        * '<S4>/Constant4'
                                        */
  real_T P_61;                         /* Expression: 0.5
                                        * '<S4>/Switch'
                                        */
  real_T P_63;                         /* Computed Parameter: B
                                        * '<S4>/Discrete State-Space1'
                                        */
  real_T P_64;                         /* Computed Parameter: C
                                        * '<S4>/Discrete State-Space1'
                                        */
  real_T P_65;                         /* Computed Parameter: D
                                        * '<S4>/Discrete State-Space1'
                                        */
  real_T P_66;                         /* Expression: 0
                                        * '<S4>/Discrete State-Space1'
                                        */
  real_T P_67;                         /* Expression: 0
                                        * '<S4>/Unit Delay1'
                                        */
  real_T P_69;                         /* Computed Parameter: B
                                        * '<S4>/Discrete State-Space2'
                                        */
  real_T P_70;                         /* Computed Parameter: C
                                        * '<S4>/Discrete State-Space2'
                                        */
  real_T P_71;                         /* Computed Parameter: D
                                        * '<S4>/Discrete State-Space2'
                                        */
  real_T P_72;                         /* Expression: 0
                                        * '<S4>/Discrete State-Space2'
                                        */
  real_T P_73[20];                     /* Expression: LW1_2
                                        * '<S4>/Matrix Gain1'
                                        */
  real_T P_74[20];                     /* Expression: IW
                                        * '<S4>/Matrix Gain'
                                        */
  real_T P_75;                         /* Expression: -2
                                        * '<S8>/Gain'
                                        */
  real_T P_76;                         /* Expression: 1
                                        * '<S8>/one'
                                        */
  real_T P_77;                         /* Expression: 2
                                        * '<S8>/Gain1'
                                        */
  real_T P_78;                         /* Expression: 1
                                        * '<S8>/one1'
                                        */
  real_T P_79[10];                     /* Expression: LW2_1
                                        * '<S4>/Matrix Gain2'
                                        */
  real_T P_80;                         /* Expression: 0.5
                                        * '<S4>/Switch1'
                                        */
  real_T P_81;                         /* Expression: 0.5
                                        * '<S4>/Switch2'
                                        */
  real_T P_82;                         /* Computed Parameter: A
                                        * '<S2>/State Space'
                                        */
  real_T P_83;                         /* Computed Parameter: B
                                        * '<S2>/State Space'
                                        */
  real_T P_84;                         /* Computed Parameter: C
                                        * '<S2>/State Space'
                                        */
  real_T P_86;                         /* Expression: X0
                                        * '<S2>/State Space'
                                        */
  real_T P_87;                         /* Expression: 30
                                        * '<Root>/Sat(1)_0_30'
                                        */
  real_T P_88;                         /* Expression: 0
                                        * '<Root>/Sat(1)_0_30'
                                        */
};

extern Parameters rtDefaultParameters; /* parameters */

#endif                                 /* _RTW_HEADER_NNEntradaRadom_acc_h_ */
