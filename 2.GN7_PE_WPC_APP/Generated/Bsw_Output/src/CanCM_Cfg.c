/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/******************************************************************************
* R E V I S I O N   H I S T O R Y
*
********************************************************************************
* Date         Revision         By                  Description
********************************************************************************
*
* 06/26/2013   1.0          Kt.Kim                Creation of CanCM_Cfg.c module
* 22/Dec/2017  1.5.12       Kyungtae Kim          Fixed memory section mismatch  
*
*******************************************************************************/

/*******************************************************************************
**                   CanCM  Generation Tool Version                           **
*******************************************************************************/
/*
 * TOOL VERSION:    1.5.21
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\configuration\ecu\ecud_cancm.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\configuration\ecu\ecud_canif.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\configuration\ecu\ecud_cansm.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\configuration\ecu\ecud_comm.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\configuration\ecu\ecud_dem.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\configuration\ecu\ecud_ecum.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\configuration\ecu\ecud_iohwab.arxml
 * GENERATED ON: The time-stamp is removed
 */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "CanCM.h"
#include "CanCM_InitTypes.h"
#include "CanCM_PCTypes.h"
#include "CanCM_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define CANCM_PCCFG_C_AR_MAJOR_VERSION  (4)
#define CANCM_PCCFG_C_AR_MINOR_VERSION  (0)
#define CANCM_PCCFG_C_AR_PATCH_VERSION  (3)

/* FILE VERSION INFORMATION */
#define CANCM_PCCFG_C_SW_MAJOR_VERSION  (1)
#define CANCM_PCCFG_C_SW_MINOR_VERSION  (5)

/*******************************************************************************
*                        Version Check                                        **
*******************************************************************************/
#if (CANCM_PCTYPES_AR_MAJOR_VERSION != CANCM_PCCFG_C_AR_MAJOR_VERSION)
  #error "CanCM_Cfg.c : Mismatch in Specification Major Version"
#endif

#if (CANCM_PCTYPES_AR_MINOR_VERSION != CANCM_PCCFG_C_AR_MINOR_VERSION)
  #error "CanCM_Cfg.c : Mismatch in Specification Minor Version"
#endif

#if (CANCM_PCTYPES_AR_PATCH_VERSION != CANCM_PCCFG_C_AR_PATCH_VERSION)
  #error "CanCM_Cfg.c : Mismatch in Specification Patch Version"
#endif

#if (CANCM_PCTYPES_SW_MAJOR_VERSION != CANCM_PCCFG_C_SW_MAJOR_VERSION)
  #error "CanCM_Cfg.c : Mismatch in Software Major Version"
#endif

#if (CANCM_PCTYPES_SW_MINOR_VERSION != CANCM_PCCFG_C_SW_MINOR_VERSION)
  #error "CanCM_Cfg.c : Mismatch in Software Minor Version"
#endif
/******************************************************************************/
#define CANCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array saving previous battery voltage value */
VAR(uint16, CANCM_VAR_NOINIT) CanCM_GaaCanCMAdcGroupVal[] = 
{
  500
};
#define CANCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define CANCM_START_SEC_CONST_8
#include "MemMap.h"

#define CANCM_STOP_SEC_CONST_8
#include "MemMap.h"

#define CANCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Global Array for Adc group Ids */
CONST(IoHwAb_IndexType, CANCM_CONST)CanCM_GaaCanCMAdcGroup[] = 
{
  VBAT_ADC
};

/* Global Array for Channel index mapping with ComM Channel Id */
CONST(NetworkHandleType, CANCM_CONST)CanCM_GaaCanCMComMChannelMap[] = 
{
  0,
  1
};

/* Global Structure Array for Channel Configuration */
CONST(Tdd_CanCM_ChannelConfig, CANCM_CONST) CanCM_GaaChannelConfig[] =
{
  /*  CANCM_Channel 0 - 0 */
  {
    /* ddAbnormalUpper */
    0x0C04,                                      

    /* ddAbnormalLower */
    0x06C2,                                      

    /* ddCriticalUpper */
    0x0DAB,                                      

    /* ddCriticalLower */
    0x051B,                                      

    /* ddHysteresis */
    0x0026,                                      

    /* ddActivationTime */
    0x0016,                                      

    /* ddDelayTimeCritical */
    0x0024,                                      

    /* ddTimeoutStartTime */
    0x00C8,                                      

    /* ucComMChannelId */
    0x00,                                        

    /* ucChannelId */
    0x00,                                        

    /* ddEventId */
    0x002A,                                      

    /* ucCanIfCtrlId */
    0x00,                                        

    /* ddWakSrc */                        
    ECUM_WKSOURCE_BCAN_RX_POLL,                  

    /* ddWakPin */                        
    BCAN_RX                                      
  },

  /*  CANCM_Channel 1 - 1 */
  {
    /* ddAbnormalUpper */
    0x0C04,                                      

    /* ddAbnormalLower */
    0x06C2,                                      

    /* ddCriticalUpper */
    0x0DAB,                                      

    /* ddCriticalLower */
    0x051B,                                      

    /* ddHysteresis */
    0x0026,                                      

    /* ddActivationTime */
    0x0016,                                      

    /* ddDelayTimeCritical */
    0x0024,                                      

    /* ddTimeoutStartTime */
    0x00C8,                                      

    /* ucComMChannelId */
    0x01,                                        

    /* ucChannelId */
    0x01,                                        

    /* ddEventId */
    0x002A,                                      

    /* ucCanIfCtrlId */
    0x01,                                        

    /* ddWakSrc */                        
    ECUM_WKSOURCE_LCAN_RX_POLL,                  

    /* ddWakPin */                        
    LCAN_RX                                      
  }
};



#define CANCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* polyspace:end<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
