/*
 * NNEntradaRadom_acc_data.c
 *
 * Real-Time Workshop code generation for Simulink model "NNEntradaRadom_acc.mdl".
 *
 * Model Version              : 1.17
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Dec 16 08:39:45 2009
 */

#include "NNEntradaRadom_acc.h"
#include "NNEntradaRadom_acc_private.h"

/* Block parameters (auto storage) */
Parameters rtDefaultParameters = {
  -0.0656,                             /* P_0 : '<S3>/State Space'
                                        */
  1.0,                                 /* P_1 : '<S3>/State Space'
                                        */
  0.0656,                              /* P_2 : '<S3>/State Space'
                                        */
  0.0,                                 /* P_4 : '<S3>/State Space'
                                        */
  30.0,                                /* P_5 : '<Root>/Sat(2)_0_30'
                                        */
  0.0,                                 /* P_6 : '<Root>/Sat(2)_0_30'
                                        */

  /*  P_7 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  7.0,                                 /* P_8 : '<S1>/S-Function'
                                        */

  /*  P_9 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  0.2,                                 /* P_10 : '<S1>/S-Function'
                                        */

  /*  P_11 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  2.0,                                 /* P_12 : '<S1>/S-Function'
                                        */

  /*  P_13 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  2.0,                                 /* P_14 : '<S1>/S-Function'
                                        */

  /*  P_15 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  2.0,                                 /* P_16 : '<S1>/S-Function'
                                        */

  /*  P_17 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  0.5,                                 /* P_18 : '<S1>/S-Function'
                                        */

  /*  P_19 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  0.001,                               /* P_20 : '<S1>/S-Function'
                                        */

  /*  P_21 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  10.0,                                /* P_22 : '<S1>/S-Function'
                                        */

  /*  P_23 : '<S1>/S-Function'
   */
  { 10.0, 2.0 },

  /*  P_24 : '<S1>/S-Function'
   */
  { -5.8740658872423568E+000, -8.6938379460829182E+001, 1.5801799843307578E+000,
    -2.4131203621998863E-005, 2.5151355123276860E+000, 1.5922398567132245E+001,
    4.2902203341120562E-002, -1.9336241405133276E+001, 4.4395106547057822E-005,
    -1.8794589837663619E-001, 4.1456775573800930E-001, 1.0298684528703046E+002,
    1.8708284517991609E+000, 3.8630767203857666E-004, 1.8581013476656116E+000,
    7.5632830317208672E+001, 9.6363121776743577E-001, -2.4233564962295784E+001,
    3.7710848101609791E-005, 1.3067590124869697E+000 },

  /*  P_25 : '<S1>/S-Function'
   */
  { 10.0, 2.0 },

  /*  P_26 : '<S1>/S-Function'
   */
  { -2.2508381849002443E+000, 4.0587187096241131E+001, 4.2848833864325961E+001,
    -2.3185318607251615E-001, 1.1915245089247175E+002, -2.6418378788138810E+001,
    -3.9149055879741472E+000, 3.6660257436192412E+000, 1.0762169822384848E-001,
    8.1088985824571260E+000, 8.2579760499188879E+000, -3.8425821112352203E+001,
    3.2767855419124729E+001, 1.3100028923863505E-001, -1.2341724349157298E+002,
    -2.9627884221619176E+001, 2.2000522913808451E+000, 1.2124681596375069E+001,
    -5.0529881545989641E-002, -8.3090523637894034E+000 },

  /*  P_27 : '<S1>/S-Function'
   */
  { 1.0, 10.0 },

  /*  P_28 : '<S1>/S-Function'
   */
  { 3.0070864251908248E-003, 2.0347342160162030E-003, 8.4998326825764536E+000,
    -5.9185475189954246E+000, 3.2849017128997091E-003, -1.3595405962451694E-003,
    -9.5791100017979212E-003, 4.0638138718096528E-004, 1.6707432299027499E+001,
    5.0587657493928002E-003 },

  /*  P_29 : '<S1>/S-Function'
   */
  { 10.0, 1.0 },

  /*  P_30 : '<S1>/S-Function'
   */
  { 1.8743167997767440E+001, -8.4436870570993563E+001, 1.5319276044323482E+000,
    2.5010876882731474E+000, 5.6165240396193639E+001, 4.8562242628238046E+001,
    2.3377567366769803E+001, 1.7678955047242933E+001, -3.3810877585722210E-001,
    -8.8822843092517854E+000 },

  /*  P_31 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  3.0208208523985518E+000,             /* P_32 : '<S1>/S-Function'
                                        */

  /*  P_33 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  2.0,                                 /* P_34 : '<S1>/S-Function'
                                        */

  /*  P_35 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  2.0,                                 /* P_36 : '<S1>/S-Function'
                                        */

  /*  P_37 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  0.0,                                 /* P_38 : '<S1>/S-Function'
                                        */

  /*  P_39 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  0.0,                                 /* P_40 : '<S1>/S-Function'
                                        */

  /*  P_41 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  -15.0,                               /* P_42 : '<S1>/S-Function'
                                        */

  /*  P_43 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  15.0,                                /* P_44 : '<S1>/S-Function'
                                        */

  /*  P_45 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  0.0,                                 /* P_46 : '<S1>/S-Function'
                                        */

  /*  P_47 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  15.0,                                /* P_48 : '<S1>/S-Function'
                                        */

  /*  P_49 : '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  0.0,                                 /* P_50 : '<S1>/S-Function'
                                        */
  15.0,                                /* P_51 : '<Root>/Sat(0)_15_-15'
                                        */
  -15.0,                               /* P_52 : '<Root>/Sat(0)_15_-15'
                                        */
  15.0,                                /* P_53 : '<Root>/Random Number'
                                        */
  3.8729833462074170E+000,             /* P_54 : '<Root>/Random Number'
                                        */
  734123.0,                            /* P_55 : '<Root>/Random Number'
                                        */

  /*  P_56 : '<S4>/Constant'
   */
  { 1.8743167997767440E+001, -8.4436870570993563E+001, 1.5319276044323482E+000,
    2.5010876882731474E+000, 5.6165240396193639E+001, 4.8562242628238046E+001,
    2.3377567366769803E+001, 1.7678955047242933E+001, -3.3810877585722210E-001,
    -8.8822843092517854E+000 },
  3.0208208523985518E+000,             /* P_57 : '<S4>/Constant1'
                                        */
  0.0,                                 /* P_58 : '<S4>/Constant2'
                                        */
  0.0,                                 /* P_59 : '<S4>/Constant3'
                                        */
  0.0,                                 /* P_60 : '<S4>/Constant4'
                                        */
  0.5,                                 /* P_61 : '<S4>/Switch'
                                        */
  1.0,                                 /* P_63 : '<S4>/Discrete State-Space1'
                                        */
  1.0,                                 /* P_64 : '<S4>/Discrete State-Space1'
                                        */
  1.0,                                 /* P_65 : '<S4>/Discrete State-Space1'
                                        */
  0.0,                                 /* P_66 : '<S4>/Discrete State-Space1'
                                        */
  0.0,                                 /* P_67 : '<S4>/Unit Delay1'
                                        */
  1.0,                                 /* P_69 : '<S4>/Discrete State-Space2'
                                        */
  1.0,                                 /* P_70 : '<S4>/Discrete State-Space2'
                                        */
  1.0,                                 /* P_71 : '<S4>/Discrete State-Space2'
                                        */
  0.0,                                 /* P_72 : '<S4>/Discrete State-Space2'
                                        */

  /*  P_73 : '<S4>/Matrix Gain1'
   */
  { -2.2508381849002443E+000, 4.0587187096241131E+001, 4.2848833864325961E+001,
    -2.3185318607251615E-001, 1.1915245089247175E+002, -2.6418378788138810E+001,
    -3.9149055879741472E+000, 3.6660257436192412E+000, 1.0762169822384848E-001,
    8.1088985824571260E+000, 8.2579760499188879E+000, -3.8425821112352203E+001,
    3.2767855419124729E+001, 1.3100028923863505E-001, -1.2341724349157298E+002,
    -2.9627884221619176E+001, 2.2000522913808451E+000, 1.2124681596375069E+001,
    -5.0529881545989641E-002, -8.3090523637894034E+000 },

  /*  P_74 : '<S4>/Matrix Gain'
   */
  { -5.8740658872423568E+000, -8.6938379460829182E+001, 1.5801799843307578E+000,
    -2.4131203621998863E-005, 2.5151355123276860E+000, 1.5922398567132245E+001,
    4.2902203341120562E-002, -1.9336241405133276E+001, 4.4395106547057822E-005,
    -1.8794589837663619E-001, 4.1456775573800930E-001, 1.0298684528703046E+002,
    1.8708284517991609E+000, 3.8630767203857666E-004, 1.8581013476656116E+000,
    7.5632830317208672E+001, 9.6363121776743577E-001, -2.4233564962295784E+001,
    3.7710848101609791E-005, 1.3067590124869697E+000 },
  -2.0,                                /* P_75 : '<S8>/Gain'
                                        */
  1.0,                                 /* P_76 : '<S8>/one'
                                        */
  2.0,                                 /* P_77 : '<S8>/Gain1'
                                        */
  1.0,                                 /* P_78 : '<S8>/one1'
                                        */

  /*  P_79 : '<S4>/Matrix Gain2'
   */
  { 3.0070864251908248E-003, 2.0347342160162030E-003, 8.4998326825764536E+000,
    -5.9185475189954246E+000, 3.2849017128997091E-003, -1.3595405962451694E-003,
    -9.5791100017979212E-003, 4.0638138718096528E-004, 1.6707432299027499E+001,
    5.0587657493928002E-003 },
  0.5,                                 /* P_80 : '<S4>/Switch1'
                                        */
  0.5,                                 /* P_81 : '<S4>/Switch2'
                                        */
  -0.0656,                             /* P_82 : '<S2>/State Space'
                                        */
  1.0,                                 /* P_83 : '<S2>/State Space'
                                        */
  0.2964,                              /* P_84 : '<S2>/State Space'
                                        */
  0.0,                                 /* P_86 : '<S2>/State Space'
                                        */
  30.0,                                /* P_87 : '<Root>/Sat(1)_0_30'
                                        */
  0.0                                  /* P_88 : '<Root>/Sat(1)_0_30'
                                        */
};