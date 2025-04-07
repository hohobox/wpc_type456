/*
 * File: App_Model_types.h
 *
 * Code generated for Simulink model 'App_Model'.
 *
 * Model version                  : 1.649
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Mar 13 10:28:43 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_App_Model_types_h_
#define RTW_HEADER_App_Model_types_h_
#include "rtwtypes.h"
#include "Rte_Type.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_WPCType_
#define DEFINED_TYPEDEF_FOR_WPCType_

/* 0x01:WPCType1(GN7)
   0x02:WPCType2(MX5)
   0x03:WPCType3(SV)
   0x04:WPCType4(Single EPP)
   0x05:WPCType5(Dual EPP+MPP)
   0x06:WPCType6(Dual MPP+MPP) */
typedef uint8 WPCType;

/* enum WPCType */
#define Type_Invalid                   ((WPCType)0U)
#define Type1                          ((WPCType)1U)
#define Type2                          ((WPCType)2U)
#define Type3                          ((WPCType)3U)
#define Type4                          ((WPCType)4U)
#define Type5                          ((WPCType)5U)             /* Default value */
#define Type6                          ((WPCType)6U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_C_WPCOnOffNvalueSet_
#define DEFINED_TYPEDEF_FOR_C_WPCOnOffNvalueSet_

/* Request to set WPC On/Off switch status
   0x00:Default
   0x01:Off (Disable)
   0x02:On (Enable)
   0x03:Invalid */
typedef uint8 C_WPCOnOffNvalueSet;

/* enum C_WPCOnOffNvalueSet */
#define Default                        ((C_WPCOnOffNvalueSet)0U)
#define WPC_Off                        ((C_WPCOnOffNvalueSet)1U)
#define WPC_On                         ((C_WPCOnOffNvalueSet)2U) /* Default value */
#define Invalid                        ((C_WPCOnOffNvalueSet)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_WPCIndUSMState_
#define DEFINED_TYPEDEF_FOR_WPCIndUSMState_

typedef uint8 WPCIndUSMState;

/* enum WPCIndUSMState */
#define WPCIndUSMState__Default        ((WPCIndUSMState)0U)      /* Default value */
#define WPCIndUSMState__Type1          ((WPCIndUSMState)1U)
#define WPCIndUSMState__Type2          ((WPCIndUSMState)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Bool_
#define DEFINED_TYPEDEF_FOR_Bool_

typedef uint8 Bool;

/* enum Bool */
#define Off                            ((Bool)0U)                /* Default value */
#define On                             ((Bool)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_WPC2IndSyncVal_
#define DEFINED_TYPEDEF_FOR_WPC2IndSyncVal_

typedef uint8 WPC2IndSyncVal;

/* enum WPC2IndSyncVal */
#define WPC2IndSyncVal__Default        ((WPC2IndSyncVal)0U)      /* Default value */
#define WPC2IndSyncVal__Off            ((WPC2IndSyncVal)1U)
#define WPC2IndSyncVal__1stSync        ((WPC2IndSyncVal)2U)
#define WPC2IndSyncVal__2ndSync        ((WPC2IndSyncVal)3U)
#define WPC2IndSyncVal__3rdSync        ((WPC2IndSyncVal)4U)
#define WPC2IndSyncVal__ErrorOff       ((WPC2IndSyncVal)5U)
#define WPC2IndSyncVal__ErrorOn        ((WPC2IndSyncVal)6U)
#define WPC2IndSyncVal__Reserved       ((WPC2IndSyncVal)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_RWPCIndSyncVal_
#define DEFINED_TYPEDEF_FOR_RWPCIndSyncVal_

typedef uint8 RWPCIndSyncVal;

/* enum RWPCIndSyncVal */
#define RWPCIndSyncVal__Default        ((RWPCIndSyncVal)0U)      /* Default value */
#define RWPCIndSyncVal__Off            ((RWPCIndSyncVal)1U)
#define RWPCIndSyncVal__1stSync        ((RWPCIndSyncVal)2U)
#define RWPCIndSyncVal__2ndSync        ((RWPCIndSyncVal)3U)
#define RWPCIndSyncVal__3rdSync        ((RWPCIndSyncVal)4U)
#define RWPCIndSyncVal__ErrorOff       ((RWPCIndSyncVal)5U)
#define RWPCIndSyncVal__ErrorOn        ((RWPCIndSyncVal)6U)
#define RWPCIndSyncVal__Reserved       ((RWPCIndSyncVal)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_C_WPCWarning_
#define DEFINED_TYPEDEF_FOR_C_WPCWarning_

/* Warning by WPC for User
   0x0:WPCWarningOff
   0x1:Cellphone on the pad
   0x2:PhoneCharging
   0x3:Charging complete
   0x4:Cellphone reminder
   0x5:error
   0x6:NFCCardDetected
   0x7:Invalid
 */
typedef uint8 C_WPCWarning;

/* enum C_WPCWarning */
#define WPCWarningOff                  ((C_WPCWarning)0U)        /* Default value */
#define Cellphoneonthepad              ((C_WPCWarning)1U)
#define PhoneCharging                  ((C_WPCWarning)2U)
#define Charging_Complete              ((C_WPCWarning)3U)
#define Cellphonereminder              ((C_WPCWarning)4U)
#define Charging_error                 ((C_WPCWarning)5U)
#define NFCCardDetected                ((C_WPCWarning)6U)
#define WarningInvalid                 ((C_WPCWarning)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_PreSyncAct_
#define DEFINED_TYPEDEF_FOR_PreSyncAct_

typedef uint8 PreSyncAct;

/* enum PreSyncAct */
#define PreSyncAct__Off                ((PreSyncAct)0U)          /* Default value */
#define PreSyncAct__WPC2               ((PreSyncAct)1U)
#define PreSyncAct__RWPC               ((PreSyncAct)2U)
#define PreSyncAct__WPC2RWPC           ((PreSyncAct)3U)
#define PreSyncAct__RWPCWPC2           ((PreSyncAct)4U)
#define PreSyncAct__WPC                ((PreSyncAct)5U)
#define PreSyncAct__WPCRWPC            ((PreSyncAct)6U)
#define PreSyncAct__RWPCWPC            ((PreSyncAct)7U)
#define PreSyncAct__WPC2WPC            ((PreSyncAct)8U)
#define PreSyncAct__WPCWPC2            ((PreSyncAct)9U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_WPC2IndCmdState_
#define DEFINED_TYPEDEF_FOR_WPC2IndCmdState_

/* WPC2IndCmdState
   0x00:WPC2IndCmdState__Default = 0;
   0x01:WPC2IndCmdState__ChrgOff = 1;
   0x02:WPC2IndCmdState__1stChrgFadeIn = 2;
   0x03:WPC2IndCmdState__1stChrgOn = 3;
   0x04:WPC2IndCmdState__2ndChrgFadeIn = 4;
   0x05:WPC2IndCmdState__2ndChrgOn = 5;
   0x06:WPC2IndCmdState__3rdChrgFadeIn = 6;
   0x07:WPC2IndCmdState__3rdChrgOn = 7;
   0x08:WPC2IndCmdState__ChrgFadeOut = 8;
   0x09:WPC2IndCmdState__ErrorFadeIn = 9;
   0x10:WPC2IndCmdState__ErrorOn = 10;
   0x11:WPC2IndCmdState__ErrorFadeOut = 11;
   0x12:WPC2IndCmdState__1stChrgFadeOut = 12;
   0x13:WPC2IndCmdState__2ndChrgFadeOut = 13;
   0x14:WPC2IndCmdState__3rdChrgFadeOut = 14;
   0x15:WPC2IndCmdState__ChrgFadeOut3_2 = 15; */
typedef uint8 WPC2IndCmdState;

/* enum WPC2IndCmdState */
#define WPC2IndCmdState__Default       ((WPC2IndCmdState)0U)     /* Default value */
#define WPC2IndCmdState__ChrgOff       ((WPC2IndCmdState)1U)
#define WPC2IndCmdState__1stChrgFadeIn ((WPC2IndCmdState)2U)
#define WPC2IndCmdState__1stChrgOn     ((WPC2IndCmdState)3U)
#define WPC2IndCmdState__2ndChrgFadeIn ((WPC2IndCmdState)4U)
#define WPC2IndCmdState__2ndChrgOn     ((WPC2IndCmdState)5U)
#define WPC2IndCmdState__3rdChrgFadeIn ((WPC2IndCmdState)6U)
#define WPC2IndCmdState__3rdChrgOn     ((WPC2IndCmdState)7U)
#define WPC2IndCmdState__ChrgFadeOut   ((WPC2IndCmdState)8U)
#define WPC2IndCmdState__ErrorFadeIn   ((WPC2IndCmdState)9U)
#define WPC2IndCmdState__ErrorOn       ((WPC2IndCmdState)10U)
#define WPC2IndCmdState__ErrorFadeOut  ((WPC2IndCmdState)11U)
#define WPC2IndCmdState__1stChrgFadeOut ((WPC2IndCmdState)12U)
#define WPC2IndCmdState__2ndChrgFadeOut ((WPC2IndCmdState)13U)
#define WPC2IndCmdState__3rdChrgFadeOut ((WPC2IndCmdState)14U)
#define WPC2IndCmdState__ChrgFadeOut3_2 ((WPC2IndCmdState)15U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_RWPCIndCmdState_
#define DEFINED_TYPEDEF_FOR_RWPCIndCmdState_

/* RWPCIndCmdState
   0x00:RWPCIndCmdState__Default = 0;
   0x01:RWPCIndCmdState__ChrgOff = 1;
   0x02:RWPCIndCmdState__1stChrgFadeIn = 2;
   0x03:RWPCIndCmdState__1stChrgOn = 3;
   0x04:RWPCIndCmdState__2ndChrgFadeIn = 4;
   0x05:RWPCIndCmdState__2ndChrgOn = 5;
   0x06:RWPCIndCmdState__3rdChrgFadeIn = 6;
   0x07:RWPCIndCmdState__3rdChrgOn = 7;
   0x08:RWPCIndCmdState__ChrgFadeOut = 8;
   0x09:RWPCIndCmdState__ErrorFadeIn = 9;
   0x10:RWPCIndCmdState__ErrorOn = 10;
   0x11:RWPCIndCmdState__ErrorFadeOut = 11;  */
typedef uint8 RWPCIndCmdState;

/* enum RWPCIndCmdState */
#define RWPCIndCmdState__Default       ((RWPCIndCmdState)0U)     /* Default value */
#define RWPCIndCmdState__ChrgOff       ((RWPCIndCmdState)1U)
#define RWPCIndCmdState__1stChrgFadeIn ((RWPCIndCmdState)2U)
#define RWPCIndCmdState__1stChrgOn     ((RWPCIndCmdState)3U)
#define RWPCIndCmdState__2ndChrgFadeIn ((RWPCIndCmdState)4U)
#define RWPCIndCmdState__2ndChrgOn     ((RWPCIndCmdState)5U)
#define RWPCIndCmdState__3rdChrgFadeIn ((RWPCIndCmdState)6U)
#define RWPCIndCmdState__3rdChrgOn     ((RWPCIndCmdState)7U)
#define RWPCIndCmdState__ChrgFadeOut   ((RWPCIndCmdState)8U)
#define RWPCIndCmdState__ErrorFadeIn   ((RWPCIndCmdState)9U)
#define RWPCIndCmdState__ErrorOn       ((RWPCIndCmdState)10U)
#define RWPCIndCmdState__ErrorFadeOut  ((RWPCIndCmdState)11U)
#define RWPCIndCmdState__1stChrgFadeOut ((RWPCIndCmdState)12U)
#define RWPCIndCmdState__2ndChrgFadeOut ((RWPCIndCmdState)13U)
#define RWPCIndCmdState__3rdChrgFadeOut ((RWPCIndCmdState)14U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_C_WPCIndSyncVal_
#define DEFINED_TYPEDEF_FOR_C_WPCIndSyncVal_

typedef uint8 C_WPCIndSyncVal;

/* enum C_WPCIndSyncVal */
#define WPCIndSyncVal__Default         ((C_WPCIndSyncVal)0U)     /* Default value */
#define WPCIndSyncVal__Off             ((C_WPCIndSyncVal)1U)
#define WPCIndSyncVal__1stSync         ((C_WPCIndSyncVal)2U)
#define WPCIndSyncVal__2ndSync         ((C_WPCIndSyncVal)3U)
#define WPCIndSyncVal__3rdSync         ((C_WPCIndSyncVal)4U)
#define WPCIndSyncVal__ErrorOff        ((C_WPCIndSyncVal)5U)
#define WPCIndSyncVal__ErrorOn         ((C_WPCIndSyncVal)6U)
#define WPCIndSyncVal__Reserved        ((C_WPCIndSyncVal)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_WPCIndCmdState_
#define DEFINED_TYPEDEF_FOR_WPCIndCmdState_

/* WPCIndCmdState
   0x00:WPCIndCmdState__Default = 0;
   0x01:WPCIndCmdState__ChrgOff = 1;
   0x02:WPCIndCmdState__1stChrgFadeIn = 2;
   0x03:WPCIndCmdState__1stChrgOn = 3;
   0x04:WPCIndCmdState__2ndChrgFadeIn = 4;
   0x05:WPCIndCmdState__2ndChrgOn = 5;
   0x06:WPCIndCmdState__3rdChrgFadeIn = 6;
   0x07:WPCIndCmdState__3rdChrgOn = 7;
   0x08:WPCIndCmdState__ChrgFadeOut = 8;
   0x09:WPCIndCmdState__ErrorFadeIn = 9;
   0x10:WPCIndCmdState__ErrorOn = 10;
   0x11:WPCIndCmdState__ErrorFadeOut = 11;
   0x12:WPCIndCmdState__1stChrgFadeOut = 12;
   0x13:WPCIndCmdState__2ndChrgFadeOut = 13;
   0x14:WPCIndCmdState__3rdChrgFadeOut = 14;
   0x15:WPCIndCmdState__ChrgFadeOut3_2 = 15;
 */
typedef uint8 WPCIndCmdState;

/* enum WPCIndCmdState */
#define WPCIndCmdState__Default        ((WPCIndCmdState)0U)      /* Default value */
#define WPCIndCmdState__ChrgOff        ((WPCIndCmdState)1U)
#define WPCIndCmdState__1stChrgFadeIn  ((WPCIndCmdState)2U)
#define WPCIndCmdState__1stChrgOn      ((WPCIndCmdState)3U)
#define WPCIndCmdState__2ndChrgFadeIn  ((WPCIndCmdState)4U)
#define WPCIndCmdState__2ndChrgOn      ((WPCIndCmdState)5U)
#define WPCIndCmdState__3rdChrgFadeIn  ((WPCIndCmdState)6U)
#define WPCIndCmdState__3rdChrgOn      ((WPCIndCmdState)7U)
#define WPCIndCmdState__ChrgFadeOut    ((WPCIndCmdState)8U)
#define WPCIndCmdState__ErrorFadeIn    ((WPCIndCmdState)9U)
#define WPCIndCmdState__ErrorOn        ((WPCIndCmdState)10U)
#define WPCIndCmdState__ErrorFadeOut   ((WPCIndCmdState)11U)
#define WPCIndCmdState__1stChrgFadeOut ((WPCIndCmdState)12U)
#define WPCIndCmdState__2ndChrgFadeOut ((WPCIndCmdState)13U)
#define WPCIndCmdState__3rdChrgFadeOut ((WPCIndCmdState)14U)
#define WPCIndCmdState__ChrgFadeOut3_2 ((WPCIndCmdState)15U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_C_ProfileIDRValue_
#define DEFINED_TYPEDEF_FOR_C_ProfileIDRValue_

/*
   Request to set user select WPC On/Off switch status
   0x00:Default
   0x01:Guest
   0x02:Profile1
   0x03:Profile2
   0x04~0x0E:Reserved
   0x0F:Invalid
 */
typedef uint8 C_ProfileIDRValue;

/* enum C_ProfileIDRValue */
#define ProfileC_ProfileIDRValueDefault ((C_ProfileIDRValue)0U)  /* Default value */
#define Guest                          ((C_ProfileIDRValue)1U)
#define Profile1                       ((C_ProfileIDRValue)2U)
#define Profile2                       ((C_ProfileIDRValue)3U)
#define ProfileInvalid                 ((C_ProfileIDRValue)15U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_WPCAnimationNvalueSet_
#define DEFINED_TYPEDEF_FOR_WPCAnimationNvalueSet_

typedef uint8 WPCAnimationNvalueSet;

/* enum WPCAnimationNvalueSet */
#define WPCAnimationNvalueSet__Default ((WPCAnimationNvalueSet)0U)
#define WPCAnimationNvalueSet__Type1   ((WPCAnimationNvalueSet)1U) /* Default value */
#define WPCAnimationNvalueSet__Type2   ((WPCAnimationNvalueSet)2U)
#define WPCAnimationNvalueSet__Reserved1 ((WPCAnimationNvalueSet)3U)
#define WPCAnimationNvalueSet__Reserved2 ((WPCAnimationNvalueSet)4U)
#define WPCAnimationNvalueSet__Reserved3 ((WPCAnimationNvalueSet)5U)
#define WPCAnimationNvalueSet__Reserved4 ((WPCAnimationNvalueSet)6U)
#define WPCAnimationNvalueSet__Invalid ((WPCAnimationNvalueSet)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_C_USMReset_
#define DEFINED_TYPEDEF_FOR_C_USMReset_

/*
   This signal is used for a request to reset the value of USM menus
   0x0:Default
   0x1:Reset
 */
typedef uint8 C_USMReset;

/* enum C_USMReset */
#define USMDefault                     ((C_USMReset)0U)          /* Default value */
#define USMReset                       ((C_USMReset)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_C_AutoBrightLevel_
#define DEFINED_TYPEDEF_FOR_C_AutoBrightLevel_

typedef uint8 C_AutoBrightLevel;

/* enum C_AutoBrightLevel */
#define NotUsed                        ((C_AutoBrightLevel)0U)
#define Step1                          ((C_AutoBrightLevel)1U)
#define Step2                          ((C_AutoBrightLevel)2U)
#define Step3                          ((C_AutoBrightLevel)3U)
#define Step4                          ((C_AutoBrightLevel)4U)
#define Step5                          ((C_AutoBrightLevel)5U)
#define Step6                          ((C_AutoBrightLevel)6U)
#define Step7                          ((C_AutoBrightLevel)7U)
#define Step8                          ((C_AutoBrightLevel)8U)
#define Step9                          ((C_AutoBrightLevel)9U)
#define Step10                         ((C_AutoBrightLevel)10U)
#define Step11                         ((C_AutoBrightLevel)11U)
#define Step12                         ((C_AutoBrightLevel)12U)
#define Step13                         ((C_AutoBrightLevel)13U)  /* Default value */
#define Step14                         ((C_AutoBrightLevel)14U)
#define Step15                         ((C_AutoBrightLevel)15U)
#define Step16                         ((C_AutoBrightLevel)16U)
#define Step17                         ((C_AutoBrightLevel)17U)
#define Step18                         ((C_AutoBrightLevel)18U)
#define Step19                         ((C_AutoBrightLevel)19U)
#define Step20                         ((C_AutoBrightLevel)20U)
#define Step21                         ((C_AutoBrightLevel)21U)
#define Step22                         ((C_AutoBrightLevel)22U)
#define Step23                         ((C_AutoBrightLevel)23U)
#define Step24                         ((C_AutoBrightLevel)24U)
#define Step25                         ((C_AutoBrightLevel)25U)
#define Step26                         ((C_AutoBrightLevel)26U)
#define Step27                         ((C_AutoBrightLevel)27U)
#define Step28                         ((C_AutoBrightLevel)28U)
#define Step29                         ((C_AutoBrightLevel)29U)
#define Step30                         ((C_AutoBrightLevel)30U)
#define Step31                         ((C_AutoBrightLevel)31U)
#define Step32                         ((C_AutoBrightLevel)32U)
#define Step33                         ((C_AutoBrightLevel)33U)
#define Step34                         ((C_AutoBrightLevel)34U)
#define Step35                         ((C_AutoBrightLevel)35U)
#define Step36                         ((C_AutoBrightLevel)36U)
#define Step37                         ((C_AutoBrightLevel)37U)
#define Step38                         ((C_AutoBrightLevel)38U)
#define Step39                         ((C_AutoBrightLevel)39U)
#define Step40                         ((C_AutoBrightLevel)40U)
#define Step41                         ((C_AutoBrightLevel)41U)
#define Step42                         ((C_AutoBrightLevel)42U)
#define Step43                         ((C_AutoBrightLevel)43U)
#define Step44                         ((C_AutoBrightLevel)44U)
#define Step45                         ((C_AutoBrightLevel)45U)
#define Step46                         ((C_AutoBrightLevel)46U)
#define Step47                         ((C_AutoBrightLevel)47U)
#define Step48                         ((C_AutoBrightLevel)48U)
#define Step49                         ((C_AutoBrightLevel)49U)
#define Step50                         ((C_AutoBrightLevel)50U)
#define Step51                         ((C_AutoBrightLevel)51U)
#define Step52                         ((C_AutoBrightLevel)52U)
#define Step53                         ((C_AutoBrightLevel)53U)
#define Step54                         ((C_AutoBrightLevel)54U)
#define Step55                         ((C_AutoBrightLevel)55U)
#define Step56                         ((C_AutoBrightLevel)56U)
#define Step57                         ((C_AutoBrightLevel)57U)
#define Step58                         ((C_AutoBrightLevel)58U)
#define Step59                         ((C_AutoBrightLevel)59U)
#define Step60                         ((C_AutoBrightLevel)60U)
#define Step61                         ((C_AutoBrightLevel)61U)
#define Step62                         ((C_AutoBrightLevel)62U)
#define Step63                         ((C_AutoBrightLevel)63U)
#define Step64                         ((C_AutoBrightLevel)64U)
#define Step65                         ((C_AutoBrightLevel)65U)
#define Step66                         ((C_AutoBrightLevel)66U)
#define Step67                         ((C_AutoBrightLevel)67U)
#define Step68                         ((C_AutoBrightLevel)68U)
#define Step69                         ((C_AutoBrightLevel)69U)
#define Step70                         ((C_AutoBrightLevel)70U)
#define Step71                         ((C_AutoBrightLevel)71U)
#define Step72                         ((C_AutoBrightLevel)72U)
#define Step73                         ((C_AutoBrightLevel)73U)
#define Step74                         ((C_AutoBrightLevel)74U)
#define Step75                         ((C_AutoBrightLevel)75U)
#define Step76                         ((C_AutoBrightLevel)76U)
#define Step77                         ((C_AutoBrightLevel)77U)
#define Step78                         ((C_AutoBrightLevel)78U)
#define Step79                         ((C_AutoBrightLevel)79U)
#define Step80                         ((C_AutoBrightLevel)80U)
#define Step81                         ((C_AutoBrightLevel)81U)
#define Step82                         ((C_AutoBrightLevel)82U)
#define Step83                         ((C_AutoBrightLevel)83U)
#define Step84                         ((C_AutoBrightLevel)84U)
#define Step85                         ((C_AutoBrightLevel)85U)
#define Step86                         ((C_AutoBrightLevel)86U)
#define Step87                         ((C_AutoBrightLevel)87U)
#define Step88                         ((C_AutoBrightLevel)88U)
#define Step89                         ((C_AutoBrightLevel)89U)
#define Step90                         ((C_AutoBrightLevel)90U)
#define Step91                         ((C_AutoBrightLevel)91U)
#define Step92                         ((C_AutoBrightLevel)92U)
#define Step93                         ((C_AutoBrightLevel)93U)
#define Step94                         ((C_AutoBrightLevel)94U)
#define Step95                         ((C_AutoBrightLevel)95U)
#define Step96                         ((C_AutoBrightLevel)96U)
#define Step97                         ((C_AutoBrightLevel)97U)
#define Step98                         ((C_AutoBrightLevel)98U)
#define Step99                         ((C_AutoBrightLevel)99U)
#define Step100                        ((C_AutoBrightLevel)100U)
#define Step101                        ((C_AutoBrightLevel)101U)
#define Step102                        ((C_AutoBrightLevel)102U)
#define Step103                        ((C_AutoBrightLevel)103U)
#define Step104                        ((C_AutoBrightLevel)104U)
#define Step105                        ((C_AutoBrightLevel)105U)
#define Step106                        ((C_AutoBrightLevel)106U)
#define Step107                        ((C_AutoBrightLevel)107U)
#define Step108                        ((C_AutoBrightLevel)108U)
#define Step109                        ((C_AutoBrightLevel)109U)
#define Step110                        ((C_AutoBrightLevel)110U)
#define Step111                        ((C_AutoBrightLevel)111U)
#define Step112                        ((C_AutoBrightLevel)112U)
#define Step113                        ((C_AutoBrightLevel)113U)
#define Step114                        ((C_AutoBrightLevel)114U)
#define Step115                        ((C_AutoBrightLevel)115U)
#define Step116                        ((C_AutoBrightLevel)116U)
#define Step117                        ((C_AutoBrightLevel)117U)
#define Step118                        ((C_AutoBrightLevel)118U)
#define Step119                        ((C_AutoBrightLevel)119U)
#define Step120                        ((C_AutoBrightLevel)120U)
#define Step121                        ((C_AutoBrightLevel)121U)
#define Step122                        ((C_AutoBrightLevel)123U)
#define Step123                        ((C_AutoBrightLevel)124U)
#define Step124                        ((C_AutoBrightLevel)124U)
#define Step125                        ((C_AutoBrightLevel)125U)
#define Step126                        ((C_AutoBrightLevel)126U)
#define Step127                        ((C_AutoBrightLevel)127U)
#define Step128                        ((C_AutoBrightLevel)128U)
#define Step129                        ((C_AutoBrightLevel)129U)
#define Step130                        ((C_AutoBrightLevel)130U)
#define Step131                        ((C_AutoBrightLevel)131U)
#define Step132                        ((C_AutoBrightLevel)132U)
#define Step133                        ((C_AutoBrightLevel)133U)
#define Step134                        ((C_AutoBrightLevel)134U)
#define Step135                        ((C_AutoBrightLevel)135U)
#define Step136                        ((C_AutoBrightLevel)136U)
#define Step137                        ((C_AutoBrightLevel)137U)
#define Step138                        ((C_AutoBrightLevel)138U)
#define Step139                        ((C_AutoBrightLevel)139U)
#define Step140                        ((C_AutoBrightLevel)140U)
#define Step141                        ((C_AutoBrightLevel)141U)
#define Step142                        ((C_AutoBrightLevel)142U)
#define Step143                        ((C_AutoBrightLevel)143U)
#define Step144                        ((C_AutoBrightLevel)144U)
#define Step145                        ((C_AutoBrightLevel)145U)
#define Step146                        ((C_AutoBrightLevel)146U)
#define Step147                        ((C_AutoBrightLevel)147U)
#define Step148                        ((C_AutoBrightLevel)148U)
#define Step149                        ((C_AutoBrightLevel)149U)
#define Step150                        ((C_AutoBrightLevel)150U)
#define Step151                        ((C_AutoBrightLevel)151U)
#define Step152                        ((C_AutoBrightLevel)152U)
#define Step153                        ((C_AutoBrightLevel)153U)
#define Step154                        ((C_AutoBrightLevel)154U)
#define Step155                        ((C_AutoBrightLevel)155U)
#define Step156                        ((C_AutoBrightLevel)156U)
#define Step157                        ((C_AutoBrightLevel)157U)
#define Step158                        ((C_AutoBrightLevel)158U)
#define Step159                        ((C_AutoBrightLevel)159U)
#define Step160                        ((C_AutoBrightLevel)160U)
#define Step161                        ((C_AutoBrightLevel)161U)
#define Step162                        ((C_AutoBrightLevel)162U)
#define Step163                        ((C_AutoBrightLevel)163U)
#define Step164                        ((C_AutoBrightLevel)164U)
#define Step165                        ((C_AutoBrightLevel)165U)
#define Step166                        ((C_AutoBrightLevel)166U)
#define Step167                        ((C_AutoBrightLevel)167U)
#define Step168                        ((C_AutoBrightLevel)168U)
#define Step169                        ((C_AutoBrightLevel)169U)
#define Step170                        ((C_AutoBrightLevel)170U)
#define Step171                        ((C_AutoBrightLevel)171U)
#define Step172                        ((C_AutoBrightLevel)172U)
#define Step173                        ((C_AutoBrightLevel)173U)
#define Step174                        ((C_AutoBrightLevel)174U)
#define Step175                        ((C_AutoBrightLevel)175U)
#define Step176                        ((C_AutoBrightLevel)176U)
#define Step177                        ((C_AutoBrightLevel)177U)
#define Step178                        ((C_AutoBrightLevel)178U)
#define Step179                        ((C_AutoBrightLevel)179U)
#define Step180                        ((C_AutoBrightLevel)180U)
#define Step181                        ((C_AutoBrightLevel)181U)
#define Step182                        ((C_AutoBrightLevel)182U)
#define Step183                        ((C_AutoBrightLevel)183U)
#define Step184                        ((C_AutoBrightLevel)184U)
#define Step185                        ((C_AutoBrightLevel)185U)
#define Step186                        ((C_AutoBrightLevel)186U)
#define Step187                        ((C_AutoBrightLevel)187U)
#define Step188                        ((C_AutoBrightLevel)188U)
#define Step189                        ((C_AutoBrightLevel)189U)
#define Step190                        ((C_AutoBrightLevel)190U)
#define Step191                        ((C_AutoBrightLevel)191U)
#define Step192                        ((C_AutoBrightLevel)192U)
#define Step193                        ((C_AutoBrightLevel)193U)
#define Step194                        ((C_AutoBrightLevel)194U)
#define Step195                        ((C_AutoBrightLevel)195U)
#define Step196                        ((C_AutoBrightLevel)196U)
#define Step197                        ((C_AutoBrightLevel)197U)
#define Step198                        ((C_AutoBrightLevel)198U)
#define Step199                        ((C_AutoBrightLevel)199U)
#define Step200                        ((C_AutoBrightLevel)200U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_C_RheoStatLevel_
#define DEFINED_TYPEDEF_FOR_C_RheoStatLevel_

/* Rheostat Bright Level (Unit: Step)(From ICU)
   0x00:Reserved
   0x01:Step 1
   0x02:Step 2
   0x03:Step 3
   0x04:Step 4
   0x05:Step 5
   0x06:Step 6
   0x07:Step 7
   0x08:Step 8
   0x09:Step 9
   0x0A:Step 10
   0x0B:Step 11
   0x0C:Step 12
   0x0D:Step 13
   0x0E:Step 14
   0x0F:Step 15
   0x10:Step 16
   0x11:Step 17
   0x12:Step 18
   0x13:Step 19
   0x14:Step 20
   0x15:Step 21 (Detent)
 */
typedef uint8 C_RheoStatLevel;

/* enum C_RheoStatLevel */
#define RheoReserved                   ((C_RheoStatLevel)0U)     /* Default value */
#define RheoStep1                      ((C_RheoStatLevel)1U)
#define RheoStep2                      ((C_RheoStatLevel)2U)
#define RheoStep3                      ((C_RheoStatLevel)3U)
#define RheoStep4                      ((C_RheoStatLevel)4U)
#define RheoStep5                      ((C_RheoStatLevel)5U)
#define RheoStep6                      ((C_RheoStatLevel)6U)
#define RheoStep7                      ((C_RheoStatLevel)7U)
#define RheoStep8                      ((C_RheoStatLevel)8U)
#define RheoStep9                      ((C_RheoStatLevel)9U)
#define RheoStep10                     ((C_RheoStatLevel)10U)
#define RheoStep11                     ((C_RheoStatLevel)11U)
#define RheoStep12                     ((C_RheoStatLevel)12U)
#define RheoStep13                     ((C_RheoStatLevel)13U)
#define RheoStep14                     ((C_RheoStatLevel)14U)
#define RheoStep15                     ((C_RheoStatLevel)15U)
#define RheoStep16                     ((C_RheoStatLevel)16U)
#define RheoStep17                     ((C_RheoStatLevel)17U)
#define RheoStep18                     ((C_RheoStatLevel)18U)
#define RheoStep19                     ((C_RheoStatLevel)19U)
#define RheoStep20                     ((C_RheoStatLevel)20U)
#define RheoStep21                     ((C_RheoStatLevel)21U)
#define RheoelseStep                   ((C_RheoStatLevel)22U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_RheostatOption_
#define DEFINED_TYPEDEF_FOR_RheostatOption_

/* Rheostat Option */
typedef uint8 RheostatOption;

/* enum RheostatOption */
#define RheostatOption_Off             ((RheostatOption)0U)      /* Default value */
#define RheostatOption_On              ((RheostatOption)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_INDContType_
#define DEFINED_TYPEDEF_FOR_INDContType_

/* 0x00:WithDetent
   0x01:WithoutDetent
   0x02:AutoBright */
typedef uint8 INDContType;

/* enum INDContType */
#define INDConType1                    ((INDContType)0U)
#define INDConType2                    ((INDContType)1U)
#define INDConType3                    ((INDContType)2U)         /* Default value */
#endif

#ifndef DEFINED_TYPEDEF_FOR_WPCStatus_
#define DEFINED_TYPEDEF_FOR_WPCStatus_

typedef uint8 WPCStatus;

/* enum WPCStatus */
#define ModeOff                        ((WPCStatus)0U)           /* Default value */
#define WPCMode                        ((WPCStatus)1U)
#define Invalild                       ((WPCStatus)2U)
#define NFCMode                        ((WPCStatus)3U)
#define LPCDMode                       ((WPCStatus)4U)
#define PICCMode                       ((WPCStatus)5U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_LC_IAUWPCNFCcmd_
#define DEFINED_TYPEDEF_FOR_LC_IAUWPCNFCcmd_

/* NFC Searching Start/Stop command to WPC (Digital Key 2.0)
   0x0: Default
   0x1: WPC NFC Polling(Search)
   0x2: WPC NFC Deselect(Stop)
   0x3: Invalid

 */
typedef uint8 LC_IAUWPCNFCcmd;

/* enum LC_IAUWPCNFCcmd */
#define IAUWPCNFCcmdDefault            ((LC_IAUWPCNFCcmd)0U)     /* Default value */
#define WPCNFCPolling_Search           ((LC_IAUWPCNFCcmd)1U)
#define WPCNFCDeselect_Stop            ((LC_IAUWPCNFCcmd)2U)
#define IAUWPCNFCCmdInvalid            ((LC_IAUWPCNFCcmd)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_IAU_OwnerPhnRegRVal_
#define DEFINED_TYPEDEF_FOR_IAU_OwnerPhnRegRVal_

/* 0x00:Default
   0x01:Disable
   0x02:Enable
   0x03:Invalid

 */
typedef uint8 IAU_OwnerPhnRegRVal;

/* enum IAU_OwnerPhnRegRVal */
#define OwnerPhnReg__Default           ((IAU_OwnerPhnRegRVal)0U) /* Default value */
#define OwnerPhnReg__Disable           ((IAU_OwnerPhnRegRVal)1U)
#define OwnerPhnReg__Enable            ((IAU_OwnerPhnRegRVal)2U)
#define OwnerPhnReg__Invalid           ((IAU_OwnerPhnRegRVal)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_OwnerPairingAdvertisingReq_
#define DEFINED_TYPEDEF_FOR_OwnerPairingAdvertisingReq_

typedef uint8 OwnerPairingAdvertisingReq;

/* enum OwnerPairingAdvertisingReq */
#define OwnerPairingAdvertisingReq__Off ((OwnerPairingAdvertisingReq)0U) /* Default value */
#define OwnerPairingAdvertisingReq__StartEnable ((OwnerPairingAdvertisingReq)1U)
#define OwnerPairingAdvertisingReq__Reserve ((OwnerPairingAdvertisingReq)2U)
#define OwnerPairingAdvertisingReq__Invalid ((OwnerPairingAdvertisingReq)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_OnThePad_
#define DEFINED_TYPEDEF_FOR_OnThePad_

/* 0x00:Dafault
   0x01:OnthePad_Off
   0x02:OnthePad_On */
typedef uint8 OnThePad;

/* enum OnThePad */
#define OnThePad_Default               ((OnThePad)0U)
#define OnThePad_Off                   ((OnThePad)1U)            /* Default value */
#define OnThePad_On                    ((OnThePad)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_LC_WPC_NFCDetection_
#define DEFINED_TYPEDEF_FOR_LC_WPC_NFCDetection_

typedef uint8 LC_WPC_NFCDetection;

/* enum LC_WPC_NFCDetection */
#define NFCDetection_Off               ((LC_WPC_NFCDetection)0U) /* Default value */
#define NFCDetection_Detected          ((LC_WPC_NFCDetection)1U)
#define NFCDetection_NotDetected       ((LC_WPC_NFCDetection)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_DeviceState_
#define DEFINED_TYPEDEF_FOR_DeviceState_

/*
   WPC Device Status
   0x0: Init
   0x1: Reserved
   0x2: Standby
   0x3: Charging
   0x4: Full_Charge
   0x5: FODError
   0x6: DeviceError
   0x7: SystemError
   0x8: NVMError
   0x9: APPError
   0x10: ErrorComm


 */
typedef uint8 DeviceState;

/* enum DeviceState */
#define Init                           ((DeviceState)0U)         /* Default value */
#define DeviceStatReserved             ((DeviceState)1U)
#define Standby                        ((DeviceState)2U)
#define Charging                       ((DeviceState)3U)
#define Full_Charge                    ((DeviceState)4U)
#define FODError                       ((DeviceState)5U)
#define DeviceError                    ((DeviceState)6U)
#define SystemError                    ((DeviceState)7U)
#define NVMError                       ((DeviceState)8U)
#define APPError                       ((DeviceState)9U)
#define ErrorComm                      ((DeviceState)10U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_CardProtection_
#define DEFINED_TYPEDEF_FOR_CardProtection_

/* 0x0:Default
   0x1:Prohibit [ChargingOff]
   0x2:Allow [ChargingOn] */
typedef uint8 CardProtection;

/* enum CardProtection */
#define CardPro_Default                ((CardProtection)0U)      /* Default value */
#define CardPro_Prohibit               ((CardProtection)1U)
#define CardPro_Allow                  ((CardProtection)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_BlinkState_
#define DEFINED_TYPEDEF_FOR_BlinkState_

/* This signal is used for a request to reset the value
   of USM menus
   0x0:Default/0x1:Reset */
typedef uint8 BlinkState;

/* enum BlinkState */
#define BlinkOff                       ((BlinkState)0U)          /* Default value */
#define BlinkOn                        ((BlinkState)1U)
#define BlinkComplete                  ((BlinkState)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_WPC2PreSyncAct_
#define DEFINED_TYPEDEF_FOR_WPC2PreSyncAct_

typedef uint8 WPC2PreSyncAct;

/* enum WPC2PreSyncAct */
#define WPC2PreSyncAct_Off             ((WPC2PreSyncAct)0U)      /* Default value */
#define WPC2PreSyncAct_On              ((WPC2PreSyncAct)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_RWPCPreSyncAct_
#define DEFINED_TYPEDEF_FOR_RWPCPreSyncAct_

typedef uint8 RWPCPreSyncAct;

/* enum RWPCPreSyncAct */
#define RWPCPreSyncAct_Off             ((RWPCPreSyncAct)0U)      /* Default value */
#define RWPCPreSyncAct_On              ((RWPCPreSyncAct)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_WPCPreSyncAct_
#define DEFINED_TYPEDEF_FOR_WPCPreSyncAct_

typedef uint8 WPCPreSyncAct;

/* enum WPCPreSyncAct */
#define WPCPreSyncAct_Off              ((WPCPreSyncAct)0U)       /* Default value */
#define WPCPreSyncAct_On               ((WPCPreSyncAct)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_C_EngineState_
#define DEFINED_TYPEDEF_FOR_C_EngineState_

/*
   Engine Running State for Vehicle
   0x0:Engine Stop
   0x1:Cranking
   0x2:Stalled
   0x3:Engine Running
   0x4:Reserved
   0x5:Auto Stopping
   0x6:Reserved
   0x7:Fault
 */
typedef uint8 C_EngineState;

/* enum C_EngineState */
#define EngineStop                     ((C_EngineState)0U)       /* Default value */
#define Cranking                       ((C_EngineState)1U)
#define Stalled                        ((C_EngineState)2U)
#define EngineRunning                  ((C_EngineState)3U)
#define AutoStopping                   ((C_EngineState)5U)
#define Fault                          ((C_EngineState)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_C_HEVEngOnState_
#define DEFINED_TYPEDEF_FOR_C_HEVEngOnState_

/* Engine Running State for HEV/PHEV Vehicle
   0x0: ES(Engine Stop)
   0x1: ST(Start)
   0x2: IS(Idel speed)
   0x3: PL(Part Load)
   0x4: PU(Pull)
   0x5: PUC(Fuel Cut off) */
typedef uint8 C_HEVEngOnState;

/* enum C_HEVEngOnState */
#define HEVEngineStop                  ((C_HEVEngOnState)0U)     /* Default value */
#define HEVengineStart                 ((C_HEVEngOnState)1U)
#define IdelSpeed                      ((C_HEVEngOnState)2U)
#define PartLoad                       ((C_HEVEngOnState)3U)
#define Pull                           ((C_HEVEngOnState)4U)
#define FuelCutOff                     ((C_HEVEngOnState)5U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_LatchTypeOption_
#define DEFINED_TYPEDEF_FOR_LatchTypeOption_

/* This signal is used for a E-Latch Option
   0x0: off
   0x1: on
   0x2: Reserved
   0x3: Error Indicator */
typedef uint8 LatchTypeOption;

/* enum LatchTypeOption */
#define Latch_Off                      ((LatchTypeOption)0U)     /* Default value */
#define Latch_On                       ((LatchTypeOption)1U)
#define Latch_Reserved                 ((LatchTypeOption)2U)
#define Latch_Error_Indicator          ((LatchTypeOption)3U)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_App_Model_T RT_MODEL_App_Model_T;

#endif                                 /* RTW_HEADER_App_Model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
