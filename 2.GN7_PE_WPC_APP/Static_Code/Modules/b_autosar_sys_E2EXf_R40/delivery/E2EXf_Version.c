/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2EXf_Version.c                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : Provision of Version Information                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision Date           By              Description                        **
********************************************************************************
** 1.1.8    20-Dec-2021    Gongbin Lim     #33503                             **
** 1.0.2    22-Mar-2018    Gongbin Lim     #11719                             **
** 1.0.0    30-Nov-2017    Gongbin Lim     Initial Version                    **
*******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "E2EXf.h"                 /* E2EXf module header file */
#include "E2EXf_Version.h"         /* E2EXf version header file */
#include "E2E.h"                   /* E2E module header file */

#if(E2EXF_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                   /* Det module header file */
#endif

#if (E2EXF_EXTENDED_DEM == STD_ON)
#include "Dem.h"                   /* Dem module header file */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if(E2EXF_AR_RELEASE_MAJOR_VERSION != E2EXF_VERSION_AR_RELEASE_MAJOR_VERSION)
  #error "E2EXf Static Code : Mismatch in E2EXf Specification Major Version"
#endif

#if(E2EXF_AR_RELEASE_MINOR_VERSION != E2EXF_VERSION_AR_RELEASE_MINOR_VERSION)
  #error "E2EXf Static Code : Mismatch in E2EXf Specification Minor Version"
#endif

#if(E2EXF_AR_RELEASE_REVISION_VERSION != \
  E2EXF_VERSION_AR_RELEASE_REVISION_VERSION)
  #error "E2EXf Static Code : Mismatch in E2EXf Specification Revision Version"
#endif

#if(E2EXF_SW_MAJOR_VERSION != E2EXF_VERSION_SW_MAJOR_VERSION)
  #error "E2EXf Static Code : Mismatch in E2EXf Software Major Version"
#endif

#if(E2EXF_SW_MINOR_VERSION != E2EXF_VERSION_SW_MINOR_VERSION)
  #error "E2EXf Static Code : Mismatch in E2EXf Software Minor Version"
#endif


#if(E2EXF_DEV_ERROR_DETECT == STD_ON)
  #if(DET_AR_RELEASE_MAJOR_VERSION != E2EXF_DET_AR_RELEASE_MAJOR_VERSION)
    #error "Det.h : Mismatch in Det Specification Major Version"
  #endif

  #if(DET_AR_RELEASE_MINOR_VERSION != E2EXF_DET_AR_RELEASE_MINOR_VERSION)
    #error "Det.h : Mismatch in Det Specification Minor Version"
  #endif
#endif /* E2EXF_DEV_ERROR_DETECT */

#if(E2EXF_EXTENDED_DEM == STD_ON)
  #if(DEM_AR_RELEASE_MAJOR_VERSION != E2EXF_DEM_AR_RELEASE_MAJOR_VERSION)
    #error "Dem.h : Mismatch in DEM Specification Major Version"
  #endif

  #if(DEM_AR_RELEASE_MINOR_VERSION != E2EXF_DEM_AR_RELEASE_MINOR_VERSION)
    #error "Dem.h : Mismatch in DEM Specification Minor Version"
  #endif
#endif /* E2EXF_EXTENDED_DEM */

#if(E2E_AR_RELEASE_MAJOR_VERSION != E2EXF_E2E_AR_RELEASE_MAJOR_VERSION)
  #error "E2E.h : Mismatch in E2E Specification Major Version"
#endif

#if(E2E_AR_RELEASE_MINOR_VERSION != E2EXF_E2E_AR_RELEASE_MINOR_VERSION)
  #error "E2E.h : Mismatch in E2E Specification Minor Version"
#endif
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

