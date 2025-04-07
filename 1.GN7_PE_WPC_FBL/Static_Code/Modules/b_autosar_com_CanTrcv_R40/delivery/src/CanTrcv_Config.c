/*******************************************************************************
 **  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
 **  Confidential Proprietary Information. Distribution Limited.               **
 **  Do Not Copy Without Prior Permission                                      **
 **                                                                            **
 **  SRC-MODULE: CanTrcv_Config.c                                              **
 **                                                                            **
 **  TARGET    : All                                                           **
 **                                                                            **
 **  PRODUCT   : AUTOSAR CAN Transport Protocol                                **
 **                                                                            **
 **  PURPOSE   : CanTrcv Library Relase.                                       **
 **                                                                            **
 **                                                                            **
 **  PLATFORM DEPENDANT [yes/no]: No                                           **
 **                                                                            **
 **  TO BE CHANGED BY USER [yes/no]: No                                        **
 **                                                                            **
 *******************************************************************************/

/*******************************************************************************
 **                      Revision History                                      **
 ********************************************************************************
 ** Revision  Date          By             Description                         **
 ********************************************************************************
 ** 2.7.0     10-Feb-2021   Lim Jong Sun   #22922                              **
 ** 2.6.2     20-Nov-2020   Lim Jong Sun   #26689                              **
 ** 2.6.0     25-Jun-2018   Lim Jong Sun   #12878                              **
 ** 2.4.2     11-May-2017   Lim Jong Sun   #8448                               **
 ** 2.4.1     31-Oct-2016   Lim Jong Sun   #6332, #6459, #6661, #6546          **
 *******************************************************************************/

/*******************************************************************************
 **                      Include Section                                      **
 *******************************************************************************/
#include "Platform_Types.h"
#include "CanTrcv_Cfg.h"
#if (STD_ON == CANTRCV_SPI_SUPPORT)
#include "Spi.h"
#include "CanTrcv_Ram.h"
#endif
/*******************************************************************************
 **            Variable for Library                                           **
 *******************************************************************************/
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)  

#define CANTRCV_START_SEC_CONST_8
#include "MemMap.h"
CONST(uint8, CANTRCV_CONST) CanTrcv_GucArisuCanPwmAuto = CANTRCV_ARISU_PWM_AUTO;
#define CANTRCV_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* STD_ON == CANTRCV_ARISUCAN_SUPPORT */

#if (STD_ON == CANTRCV_SPI_SUPPORT)
#define CANTRCV_START_SEC_CONST_16
#include "MemMap.h"
CONST(Spi_NumberOfDataType, CANTRCV_CONST) CanTrcv_GddSpiType = (Spi_NumberOfDataType)SPI_DATATYPE;
#define CANTRCV_STOP_SEC_CONST_16
#include "MemMap.h"
#endif /* (STD_ON == CANTRCV_SPI_SUPPORT) */
