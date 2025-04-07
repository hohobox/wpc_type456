/* polyspace-begin MISRA-C3:1.1 [Justified:Low] "Dcm shall support various primitive API. For this functionality, it needs a lot of MACRO for optimize source code." */
/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR DCM                                                   **
**                                                                            **
**  PURPOSE   : Provision of Version information                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                   Description                   **
********************************************************************************
** 2.14.0.0  30-Sep-2024   Haewon Seo           #48771 #48600                 **
**                                                                            **
** 2.13.0.0  19-Jun-2024   Jihye Lee            #46792                        **
**                                                                            **
** 2.12.0.0  17-Apr-2024   Suyon Kim            #44568 #44882 #45079          **
**                                                                            **
** 2.11.0.0  31-Jan-2024   Donghee Kwak         #44489                        **
**                                                                            **
** 2.10.0.0  28-Dec-2023   Suyon Kim            #42075                        **
**                                                                            **
** 2.9.0.0   27-11.2023    GS Ryu               #42519 #41445 #43195          **
**                                                                            **
** 2.8.0.0   15-Nov-2023   Suyon Kim            #43348                        **
**                                                                            **
** 2.7.0     25-Jul-2022   Suyon Kim           #40261                         **
**                                                                            **
** 2.6.1.0   13-Jan-2023   DanhTQ1             #35538                         **
**                                                                            **
** 2.6.0.0   30-Sep-2022   LanhLT              #34798                         **
**                                                                            **
** 2.5.0     27-05-2022    LanhLT              #35721                         **
**                                                                            **
** 1.0.4     31-03-2020    EunKyung Kim        #21551, #21905, #22299         **
**                                             #22523, #22622                 **
**                                                                            **
** 1.0.3     11-25-2019    EunKyung Kim        #19580                         **
**                                                                            **
** 1.0.2     02-09-2019    EunKyung Kim        #18790, #17220                 **
**                                                                            **
** 1.0.1     24-01-2019    Jeon    Y.S          #14081 #14326                 **
**                                                                            **
** 1.0.0     09-01-2013    Autron               Initial Version               **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dcm_Version.h"        /* Dcm Version Header File */
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Rte.h"

#if(DCM_DEM_CONFIGURED == STD_ON)  
#include "Dem.h"
#endif

#if(DCM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#include "SchM_Dcm.h"
#include "ComM.h"
#include "PduR.h"
#include "BswM.h"
 
#if(DCM_NVM_CONFIGURED == STD_ON)
#include "NvM.h"
#endif


#if ((DCM_AUTHENTICATION_SUPPORT == STD_ON) && (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF))
#include "Csm.h"
#include "KeyM.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define DCM_VERSION_C_AR_RELEASE_MAJOR_VERSION      4
#define DCM_VERSION_C_AR_RELEASE_MINOR_VERSION      0
#define DCM_VERSION_C_AR_RELEASE_REVISION_VERSION   3

/* FILE VERSION INFORMATION */
#define DCM_VERSION_C_SW_MAJOR_VERSION  2
#define DCM_VERSION_C_SW_MINOR_VERSION  14

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (DCM_VERSION_AR_RELEASE_MAJOR_VERSION != \
                                         DCM_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "Dcm_Version : Mismatch in Specification Major Version"
#endif

#if (DCM_VERSION_AR_RELEASE_MINOR_VERSION != \
                                         DCM_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "Dcm_Version : Mismatch in Specification Minor Version"
#endif

#if (DCM_VERSION_AR_RELEASE_REVISION_VERSION != \
                                      DCM_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "Dcm_Version : Mismatch in Specification Patch Version"
#endif

#if (DCM_VERSION_SW_MAJOR_VERSION != DCM_VERSION_C_SW_MAJOR_VERSION)
  #error "Dcm_Version : Mismatch in Major Version"
#endif

#if (DCM_VERSION_SW_MINOR_VERSION != DCM_VERSION_C_SW_MINOR_VERSION)
  #error "Dcm_Version : Mismatch in Minor Version"
#endif

#if (DCM_DEV_ERROR_DETECT == STD_ON)
#if (DET_AR_RELEASE_MAJOR_VERSION != DCM_DET_AR_RELEASE_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif

#if (DET_AR_RELEASE_MINOR_VERSION != DCM_DET_AR_RELEASE_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif

#if (RTE_AR_RELEASE_MAJOR_VERSION != DCM_RTE_AR_RELEASE_MAJOR_VERSION)
  #error "Rte.h : Mismatch in Specification Major Version"
#endif

#if (RTE_AR_RELEASE_MINOR_VERSION != DCM_RTE_AR_RELEASE_MINOR_VERSION)
  #error "Rte.h : Mismatch in Specification Minor Version"
#endif

#if(DCM_DEM_CONFIGURED == STD_ON)
#if (DEM_AR_RELEASE_MAJOR_VERSION != DCM_DEM_AR_RELEASE_MAJOR_VERSION)
  #error "Dem.h : Mismatch in Specification Major Version"
#endif

#if (DEM_AR_RELEASE_MINOR_VERSION != DCM_DEM_AR_RELEASE_MINOR_VERSION)
  #error "Dem.h : Mismatch in Specification Minor Version"
#endif
#endif

#if (COMM_AR_RELEASE_MAJOR_VERSION != DCM_COMM_AR_RELEASE_MAJOR_VERSION)
  #error "ComM.h : Mismatch in Specification Major Version"
#endif

#if (COMM_AR_RELEASE_MINOR_VERSION != DCM_COMM_AR_RELEASE_MINOR_VERSION)
  #error "ComM.h : Mismatch in Specification Minor Version"
#endif

#if (PDUR_AR_RELEASE_MAJOR_VERSION != DCM_PDUR_AR_RELEASE_MAJOR_VERSION)
  #error "PduR.h : Mismatch in Specification Major Version"
#endif

#if (PDUR_AR_RELEASE_MINOR_VERSION != DCM_PDUR_AR_RELEASE_MINOR_VERSION)
  #error "PduR.h : Mismatch in Specification Minor Version"
#endif

#if (BSWM_AR_RELEASE_MAJOR_VERSION != DCM_BSWM_AR_RELEASE_MAJOR_VERSION)
  #error "BswM.h : Mismatch in Specification Major Version"
#endif

#if (BSWM_AR_RELEASE_MINOR_VERSION != DCM_BSWM_AR_RELEASE_MINOR_VERSION)
  #error "BswM.h : Mismatch in Specification Minor Version"
#endif

#if(DCM_NVM_CONFIGURED == STD_ON)
#if (NVM_AR_RELEASE_MAJOR_VERSION != DCM_NVM_AR_RELEASE_MAJOR_VERSION)
  #error "NvM.h : Mismatch in Specification Major Version"
#endif

#if (NVM_AR_RELEASE_MINOR_VERSION != DCM_NVM_AR_RELEASE_MINOR_VERSION)
  #error "NvM.h : Mismatch in Specification Minor Version"
#endif
#endif /* DCM_NVM_CONFIGURED == STD_ON */

#if 0
#if (IOHWAB_AR_RELEASE_MAJOR_VERSION != DCM_IOHWAB_AR_RELEASE_MAJOR_VERSION)
  #error "IoHwAb.h : Mismatch in Specification Major Version"
#endif

#if (IOHWAB_AR_RELEASE_MINOR_VERSION != DCM_IOHWAB_AR_RELEASE_MINOR_VERSION)
  #error "IoHwAb.h : Mismatch in Specification Minor Version"
#endif
#endif

#if (DCM_AUTHENTICATION_SUPPORT == STD_ON) && (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
/* When Authenticaion available, KeyM and Csm module should be R44 */
#if (KEYM_AR_RELEASE_MAJOR_VERSION != DCM_KEYM_AR_RELEASE_MAJOR_VERSION)
  #error "KeyM.h : Mismatch in Specification Major Version"
#endif

#if (KEYM_AR_RELEASE_MINOR_VERSION != DCM_KEYM_AR_RELEASE_MINOR_VERSION)
  #error "KeyM.h : Mismatch in Specification Minor Version"
#endif

#if (CSM_AR_RELEASE_MAJOR_VERSION != DCM_CSM_AR_RELEASE_MAJOR_VERSION)
  #error "Csm.h : Mismatch in Specification Major Version"
#endif

#if (CSM_AR_RELEASE_MINOR_VERSION != DCM_CSM_AR_RELEASE_MINOR_VERSION)
  #error "Csm.h : Mismatch in Specification Minor Version"
#endif

#endif /* DCM_AUTHENTICATION_SUPPORT == STD_ON && DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* polyspace-end MISRA-C3:1.1 [Justified:Low] "Dcm shall support various primitive API. For this functionality, it needs a lot of MACRO for optimize source code." */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
