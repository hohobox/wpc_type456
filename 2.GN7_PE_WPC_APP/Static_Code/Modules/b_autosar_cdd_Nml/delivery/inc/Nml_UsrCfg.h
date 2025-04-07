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
#ifndef NML_USRCFG_H
#define NML_USRCFG_H



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "ComM_Version.h"         /* Jira - [NML-2] R44/R40 Compile Macro */
#include "NvM_Cfg.h"
#include "Rte_NvM_Type.h"
/*******************************************************************************
**                      Macro Definition                                      **
*******************************************************************************/

/******************************************************
 ** NML module configuration                         **
 *****************************************************/

/* NML component configuration */
#define NML_USE          STD_ON
/* Unit : ms. - To be configured which task periodically calls Nml_Main(), ex) 100 --> it's is mapped to 100ms task */
#define NML_CALL_PERIOD  100 /* uint-ms, it should be same as mapped task period, ex) if 100ms task --> set this value to 100 */


/*****************************************************/
/******Nm configuration - User configuration ********/
/*****************************************************/
/* If you use CanNm module set to STD_ON, others STD_OFF */
#define NML_CANNM_USED     STD_ON

/* If you use UdpNm module set to STD_ON, others STD_OFF -JW */
#define NML_UDPNM_USED     STD_OFF

/* [NML-7] NvM Run-time Write feature
   - If STD_ON, Nml shall write NvM - No need to adding Application code for Nml NvM Write
   - If STD_OFF, Application need to add code writing Nml Block of NvM before Sleep in Application code
   - Suggestion - Keep NML_NVM_WRITE_USED STD_ON to reduce adding application code
*/
#define NML_NVM_WRITE_USED STD_OFF // modify nidec // [수평전개][NML][R40/R44] Flash Write 요청 처리 중 선점상황 발생 시 Flash 삭제 또는 Pending 이슈 및 조치 방법 공유 (STD_ON --> STD_OFF로 변경함)
/*****************************************************/
/******Nm Auto configuration - Integrated ASR Ver*****/
/*****************************************************/
/*Jira - [NML-2] R44/R40 Compile Macro */
#define NML_REQUIRED_AR_RELEASE_MAJOR_VERSION_4 (4)
#define NML_REQUIRED_AR_RELEASE_MINOR_VERSION_4 (4)
#define NML_REQUIRED_AR_RELEASE_MINOR_VERSION_1 (1)
#define NML_REQUIRED_AR_RELEASE_MINOR_VERSION_0 (0)

#define NML_AR_VERSION_44 (44)
#define NML_AR_VERSION_40 (40)

#if (COMM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_0)
   /* if R40 */
  #define NML_INTEGRATED_AR_VERSION   NML_AR_VERSION_40
#elif (COMM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_4)
   /* if R44 */
  #define NML_INTEGRATED_AR_VERSION   NML_AR_VERSION_44
#else
  /* Other variant */
  #error "Nml only support R44 or R40"
#endif /* #if (COMM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_0) */



/*****************************************************/
/******NvM configuration - User configuration ********/
/*****************************************************/
/* NvM Block Id Macro wrapper which is defined in NvM_Cfg.h */
#if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */
  #define NML_NVM_BLOCK_ID          NvMConf_NvMBlockDescriptor_NvMBlock_NmlLog /* User configuration */
  #define NML_NVM_NOTI_READ_ALL     NVM_READALL_SID
  #define NML_NVM_NOTI_WRITE_BLOCK  NVM_WRITEBLOCK_SID
#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
  #define NML_NVM_BLOCK_ID NvMBlock_NmlLog /* User configuration */
  #define NML_NVM_NOTI_READ_ALL     NVM_READ_ALL_BLOCK
  #define NML_NVM_NOTI_WRITE_BLOCK  NVM_WRITE_BLOCK
#else /* Other variant */
  #error "No NvM Module R44 or R40"
#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */  
/* NvM Ram buffer Macro wrapper which is defined in NvM_Cfg.c */
#define NML_NVM_BUFFER   Nml_LogData /* Fixed configuration : this variable name should be configured in NvM RAM Buffer */

/****************************************/
/* NML  function configuration          */
/****************************************/

 /* Description : Configuration of CMC detection
  * Detection time - unit : second, current configuration - NML_CALL_PERIOD(100ms) * NML_FUNC_CMC_DETECTION_TIMECNT(100) = 10000ms = 10sec
  * example : CMC shall monitor ComM mode changes for 10 second
  */
#define NML_FUNC_CMC_DETECTION_TIMECNT   (100) /* User configuration */

 /* Detection count -  unit : number of ComM mode changes
  * example : CMC shall detect if ComM mode changes more than 20 times for NML_FUNC_CMC_DETECTION_TIME time period
  */
#define NML_FUNC_CMC_DETECTION_COUNT  (20) /* User configuration */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/



#endif /* NML_USRCFG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
