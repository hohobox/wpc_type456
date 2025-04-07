/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
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
**  SRC-MODULE: Wdg_76_Acw_Cbk.c                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR AUTOEVER CUSTOM WDG                                   **
**                                                                            **
**  PURPOSE   : AUTOEVER Custom Watchdog GPT callback function definition     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.8.6     04-Jul-2023   JH.Kim       Redmine #41888                        **
** 1.8.5     20-Jul-2022   YH.Han       Redmine #36711                        **
** 1.8.2     18-Oct-2021   YH.Han       Redmine #32698                        **
** 1.0.1     28-Apr-2016   Sinil        Redmine #4744                         **
** 1.0.0     02-Feb-2015   Sinil        Initial version                       **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:20.1 [Not a Defect] "see MEMMAP003 of AUTOSAR" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Wdg_76_Acw_Cbk.h"

/*******************************************************************************
**                       Function Definitions                                 **
*******************************************************************************/
#define WDG_76_ACW_START_SEC_CODE
#include "MemMap.h"
FUNC(void, WDG_76_ACW_CODE) WDG_76_ACW_GPT_CBK(void)
{
  Wdg_76_Acw_Gpt_Cbk();
}
#define WDG_76_ACW_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace-end MISRA-C3:20.1 */
/* polyspace:end<MISRA-C3:1.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
