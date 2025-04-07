/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: RomTst_api.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR ROMTST                                                **
**                                                                            **
**  PURPOSE   : Rom Test API Functionality                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By       Description                               **
********************************************************************************
** 1.0.0     16-May-2016   JS Park    RedMine #5149                           **
********************************************************************************
** 1.2.3     30-Dec-2020   YJ Yun     RedMine #27410                          **
********************************************************************************
** 1.4.0     22-Nov-2021   JH Lim     RedMine #31510, #33116                  **
*******************************************************************************/
#ifndef ROMTST_API_H
#define ROMTST_API_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* ROM Test uninitial/Not test */
#define E_MEM_CHK_NA        ((RomTst_StatusType)0U)
/* At least one section is invalid */
#define E_MEM_CHK_ERROR     ((RomTst_StatusType)1U)
/* All sections is valid */
#define E_MEM_CHK_OK        ((RomTst_StatusType)2U)
/* Service is Activated */
#define E_MEM_CHK_SRV_OK    ((RomTst_StartResultType)3U)
/* Service is not Activated */
#define E_MEM_CHK_SRV_BUSY  ((RomTst_StartResultType)4U)
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
#endif /* __ROMTST_API_H__ */
