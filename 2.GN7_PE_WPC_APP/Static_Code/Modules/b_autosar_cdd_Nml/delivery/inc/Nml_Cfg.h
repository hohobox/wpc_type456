/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI MOTOR GROUP                                              **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: xxxxxxxxxxx.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : Classic Platform Application                                  **
**                                                                            **
**  PURPOSE   : Log application for SWP                                       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** X.X.X     DD-MM-YYYY    name.family name                                   **
** 0.0.1     29-Nov-2022    KC.Lim        xxxxxxxxxxxxxx                      **
*******************************************************************************/
#ifndef NML_CFG_H
#define NML_CFG_H



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nml_UsrCfg.h"
#include "ComM.h"                 /* ComM header file */
#include "ComM_Internal.h"        /* ComM Internal functions header file */
#include "ComM_Ram.h"             /* ComM global Ram variables header file */
#include "ComM_Config.h"          /* ComM Config header file */




/*******************************************************************************
**                      Macro Definition                                      **
*******************************************************************************/

/******************************************************
 ** NML module configuration                         **
 *****************************************************/
/* Always On for index range check for array access */
#define NML_DET          STD_ON

/* Do not set STD_ON for release, This is only for development test */
#define NML_TEST                 STD_OFF  /* Fixed, do not change  */
#define NML_DEBUG                STD_OFF  /* Fixed, do not change  */
#define NML_MEASURE_TIME         STD_OFF  /* Fixed, do not change  */
#define NML_NVM_WRITE_RETRY_MAX  0x05
#define NML_NVM_WRITE_ALLOW_MAX  0x05
#define NML_RVCCM_THRESHOLD_MAX  0x05

/* polyspace-begin MISRA-C3:20.9 [Not a defect:Unset] "No Impact of this rule violation" */
#if (NML_MEASURE_TIME == STD_ON)
/* polyspace-end MISRA-C3:20.9 [Not a defect:Unset] "No Impact of this rule violation" */
	#define NML_MEASURE_TIME_US  NML_CALL_PERIOD /* Fixed. dp mpt cjamge Time tick would be 10ns, Converting 10ns x 100 = 1000ns = 1us, need to divide by 100 */
#endif /* #if (NML_MEASURE_TIME == STD_ON) */

 /* Description : Configuration of Wakeup Source log fixed value  */
#define NML_WAKEUP_SOURCE_ORDER_SIZE         (3u) /* fixed value  3 */

/******************************************************
 ** NML Integration                                  **
 *****************************************************/


/*********************************************************/
/******ComM dependency - All fixed configuration *********/
/*********************************************************/

/*Jira - [NML-2] R44/R40 Compile Macro */
#if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */
  /* Total number of ComM Users in ComM_Cfg.h */
  #define NML_COMM_TOTAL_USERS       (COMM_TOTAL_USERS) /* Fixed : Do not Change */
  /* Total number of ComM physical channels in ComM_Cfg.h */
  #define NML_COMM_TOTAL_CHANNELS     (COMM_TOTAL_CHANNELS) /* Fixed : Do not Change */
  /* CamM Internal variable */
  #define Nml_GaaRequestedComMode     ComM_GaaRequestedComMode     /* Fixed : Do not Change */
  #define Nml_GaaCurComMode           ComM_GaaCurComMode           /* Fixed : Do not Change */
  #define Nml_GaaChannels			        ComM_GaaChannels             /* Fixed : Do not Change */
  #define Nml_GaaChannelToPncMapping  ComM_GaaChannelToPncMapping  /* Fixed : Do not Change */
  #define Nml_GaaPncs                 ComM_GaaPncs                 /* Fixed : Do not Change */
  #define Nml_GaaPncToUserMapping     ComM_GaaPncToUserMapping     /* Fixed : Do not Change */
  #define Nml_GaaChannelToUserMapping ComM_GaaChannelToUserMapping /* Fixed : Do not Change */
  #define NML_PNC_ON                  ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON)) /* Fixed : Do not Change */
  #define NML_CAN_FR_ETH_ON           ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON) || (COMM_ETHNETWORK_PRESENT == STD_ON)) /* Fixed */
  #define NML_DIRECT_CHANNEL_ON       (COMM_DIRECT_CHANNEL == STD_ON) /* Fixed : Do not Change */

#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */

  /* Total number of ComM Users in ComM_Cfg.h */
  #define NML_COMM_TOTAL_USERS       (COMM_TOTAL_USERS) /* Fixed : Do not Change */
  /* Total number of ComM physical channels in ComM_Cfg.h */
  #define NML_COMM_TOTAL_CHANNELS     (COMM_TOTAL_CHANNELS) /* Fixed : Do not Change */
  /* CamM Internal variable */
  #define Nml_GaaRequestedComMode     ComM_RequestedComMode     /* Fixed : Do not Change */
  #define Nml_GaaCurComMode           ComM_CurComMode           /* Fixed : Do not Change */
  #define Nml_GaaChannels			        ComM_Channels             /* Fixed : Do not Change */
  #define Nml_GaaChannelToPncMapping  ComM_ChannelToPncMapping  /* Fixed : Do not Change */
  #define Nml_GaaPncs                 ComM_Pncs                 /* Fixed : Do not Change */
  #define Nml_GaaPncToUserMapping     ComM_PncToUserMapping     /* Fixed : Do not Change */
  #define Nml_GaaChannelToUserMapping ComM_ChannelToUserMapping /* Fixed : Do not Change */
  #define NML_PNC_ON                  ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON)) /* Fixed : Do not Change */
  #define NML_CAN_FR_ETH_ON           ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON) || (COMM_ETHNETWORK_PRESENT == STD_ON)) /* Fixed */
  #define NML_DIRECT_CHANNEL_ON       (COMM_DIRECT_CHANNEL == STD_ON) /* Fixed : Do not Change */

#else /* Other variant */
  #error "No ComM Module R44 or R40"
#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */



#define NML_LCM_DATA_SIZE          (3*NML_COMM_TOTAL_CHANNELS)





/****************************************/
/* NML  function configuration          */
/****************************************/

 /* Description : Configuration of Wakeup Source log
  * Wakeup source variable size(EcuM_WakeupSourceType) : uint32 4 byte --> 32 bit
  * This is used for Max number of bit shifting
  */
#define NML_WAKEUP_SOURCE_VARIALBE_BIT_SIZE  (32)  /* Fixed configuration : Do not change */

 /* Description : Configuration of Wakeup Source log
  * for used bit shifting to get which wakeup source bit set
  */
#define NML_WAKEUP_SOURCE_ORDER              (0x00000001u)  /* Fixed configuration : Do not change */


/****************************************/
/* NML  libarary configuration          */
/****************************************/
#define NML_PATTERN_SIZE (4)

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Fixed configuration */

/* Major version : Mobilgene configuration changes, it shall be required mobilgene confgiruation and NML module patch
   1- NML present Log data by RMBA service
   2- NML present Log data by RDBI service
   3- 
*/
#define NML_VERSION_MAJOR 2 /* Major version : BSW configuration changed - If BSW configuration changed = Mobilgene configuration changed */
#define NML_VERSION_MINOR 2 /* Minor version : App code to be changed    - If Integration code need to changed for Nml module  */
#define NML_VERSION_PATCH 0 /* Patch version : Nml module folder changed - only NML module changes, no need mobiligene config changes */
#define NML_VERSION_ASR   3 /* 1 - only 4.0.3, 2 - only 4.4.0, 3 - Both (4.0.3/4.4.0) 4 - HF 5 - Pre-Release*/
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/



#endif /* NML_CFG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
