/** \brief AUTOSAR Fee Flash EEPROM Emulation
 **
 ** This file defines the interface of the AUTOSAR module Fee.
 **
 ** Do not edit this file manually.
 ** Any change might compromise the safety integrity level of
 ** the software partition it is contained in.
 **
 ** Product: SW-FEE42-DRV
 **
 ** (c) 2017-2022, Cypress Semiconductor Corporation (an Infineon company) or
 ** an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 ** This software, including source code, documentation and related materials
 ** ("Software") is owned by Cypress Semiconductor Corporation or one of
 ** its affiliates ("Cypress") and is protected by and subject to worldwide
 ** patent protection (United States and foreign), United States copyright laws
 ** and international treaty provisions.  Therefore, you may use this Software
 ** only as provided in the license agreement accompanying the software package
 ** from which you obtained this Software ("EULA").
 ** If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 ** non-transferable license to copy, modify,
 ** and compile the Software source code solely for use in connection
 ** with Cypress's integrated circuit products.
 ** Any reproduction, modification, translation, compilation,
 ** or representation of this Software except as specified above is prohibited
 ** without the express written permission of Cypress.
 ** Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 ** EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
 ** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 ** Cypress reserves the right to make changes to the Software without notice.
 ** Cypress does not assume any liability arising out of the application or
 ** use of the Software or any product or circuit described in the Software.
 ** Cypress does not authorize its products for use in any products
 ** where a malfunction or failure of the Cypress product may reasonably be
 ** expected to result in significant property damage,
 ** injury or death ("High Risk Product"). By including Cypress's product
 ** in a High Risk Product, the manufacturer of such system or application
 ** assumes all risk of such use and in doing so agrees to indemnify Cypress
 ** against all liability.
*/

#ifndef FEE_DATA_H_INCLUDED
#define FEE_DATA_H_INCLUDED


/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "Fee_Pub.h"
#include "SchM_Fee.h"

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
#define FEE_STACK_SIZE         (100U)      /* size of var stack */
#define FEE_PROC_SIZE          (20U)       /* size of proc stack */

#define FEE_CONFIG_MAX_NUM     (2U)        /* max number of configuration for internal use */

#define FEE_OLD_EFFECTIVE_MAX  (3U)        /* max number of effective sector in old config*/

#define FEE_FLAG_MAX_NUM       (6U)       /* size of buffer to hold flags  */


/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/
/* typedef of job information format */
/* Deviation from MISRA-C:2004 rule 18.4, MISRA-C:2012 Rule-19.2
   Justification: For saving space, this union is necessary. And after analysis, the alignment, endian of union member is no problem. */
/* PRQA S 750 12 */
typedef struct
{
    VAR(uint8, AUTOMATIC) ConfigSetNumber;                /* Number of config set */
    VAR(uint16, AUTOMATIC) BlockIndex;                     /* Index to block definition array */
    VAR(uint16, AUTOMATIC) BlockNumber;                    /* Block Number */
    VAR(uint16, AUTOMATIC) BlockOffset;                    /* Read offset in read API */
    union{
        P2CONST(uint8, AUTOMATIC, AUTOMATIC) WriteBufferPtr;       /* Data buffer pointer in write API */
        P2VAR(uint8, AUTOMATIC, AUTOMATIC) ReadBufferPtr;              /* Data buffer pointer in read API */
    }DataBufferPtr;
    VAR(uint16, AUTOMATIC) Length;                         /* Read length in read API */
} Fee_JobDataType;

/* typedef of periodic information format */
typedef struct
{
    VAR(MemIf_JobResultType, AUTOMATIC)  Fee_MainError;    /* Error for periodic processing */
    VAR(uint16, AUTOMATIC) Fee_MainState;                  /* State of periodic processing */
    VAR(uint8, AUTOMATIC)  Fee_MainDepth;                  /* Depth of stack position */
    VAR(uint8, AUTOMATIC)  Fee_MainStackPos;               /* Position of stack */
    VAR(uint8, AUTOMATIC)  Fee_RecycleSrc;                 /* Source sector number for recycle */
} Fee_PeriodicInfoType;

/* enumeration of the status of the FEE */
typedef enum
{
    FEE_STAT_UNINIT,            /* uninitialize */
    FEE_STAT_INIT,              /* initializing */
    FEE_STAT_NOP,               /* no-operation */
    FEE_STAT_WRITE_WAIT,        /* waiting for writing */
    FEE_STAT_WRITE,             /* writing */
    FEE_STAT_WRITE_CANCEL,      /* cancel write (Data Flash Controller active) */
    FEE_STAT_WRITE_WAIT_WRITE,  /* waiting write (canceling write) */
    FEE_STAT_READ_WAIT_WRITE,   /* waiting read  (canceling write) */
    FEE_STAT_INVAL_WAIT_WRITE,  /* waiting invalidate (canceling write) */
    FEE_STAT_RECYC_WAIT_WRITE,  /* waiting sector recycling (canceling write) */
    FEE_STAT_READ_WAIT,         /* waiting for reading */
    FEE_STAT_READ,              /* reading */
    FEE_STAT_INVAL_WAIT,        /* waiting for invalidating */
    FEE_STAT_INVAL,             /* invalidating */
    FEE_STAT_CLEAR,             /* clearing all sector */
    FEE_STAT_RECYC_WAIT,        /* waiting for recycling */
    FEE_STAT_RECYC,             /* recycling */
    FEE_STAT_MAX                /* state number */
} Fee_ModuleStateType;

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/
#define FEE_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#include "Fee_MemMap.h"

extern VAR(Fee_ModuleStateType, FEE_INTERNAL_VAR_CLEARED)          Fee_ModuleState;             /* state of FEE */
extern VAR(Fee_ModuleStateType, FEE_INTERNAL_VAR_CLEARED)          Fee_ModuleStateMirror;       /* mirror of Fee_ModuleState for fail-safe */
extern VAR(uint32, FEE_INTERNAL_VAR_CLEARED)                       Fee_Counter;                 /* counter for periodic processing */
extern VAR(MemIf_JobResultType, FEE_INTERNAL_VAR_CLEARED)          Fee_JobResult;               /* result of operation */
extern VAR(Fee_JobDataType, FEE_INTERNAL_VAR_CLEARED)              Fee_Job;                     /* job information of operation */

extern VAR(Fee_BlockManagementInfoType, FEE_INTERNAL_VAR_CLEARED)  Fee_BlkMgtInfoBuffer;        /* block management information buffer for write block */

extern VAR(uint32, FEE_INTERNAL_VAR_CLEARED)                       Fee_InfoDataBuffer;          /* short data buffer for write block status */

extern VAR(uint16, FEE_INTERNAL_VAR_CLEARED)                       Fee_ImmDataReserveSize[FEE_CONFIG_MAX_NUM];   /* array of immediate date reserve size */

extern VAR(uint8, FEE_INTERNAL_VAR_CLEARED)                        Fee_CurrentConfigNo;         /* current configuration number, value is 1 or 2. */

extern VAR(Fee_PeriodicInfoType, FEE_INTERNAL_VAR_CLEARED)         Fee_PeriInfo;                /* informations of periodic */

extern VAR(uint8, FEE_INTERNAL_VAR_CLEARED)                        Fee_MainProc[FEE_PROC_SIZE];    /* Stack for position of the processing */

extern VAR(uint8, FEE_INTERNAL_VAR_CLEARED)                        Fee_MainStack[FEE_STACK_SIZE];  /* Stack for periodic processing */

extern VAR(uint8, FEE_INTERNAL_VAR_CLEARED)                        Fee_RecycleFlag;                /* recycle flag is ON or OFF */

extern VAR(uint8, FEE_INTERNAL_VAR_CLEARED)                        Fee_RecycleImmediateFlag;       /* recycle immediate flag is ON or OFF */

extern VAR(uint8, FEE_INTERNAL_VAR_CLEARED)                        Fee_ConfigUnmatchFlag;          /* Fee_ConfigUnmatchFlag is ON or OFF */

extern VAR(Fee_ConfigurationInfoType, FEE_INTERNAL_VAR_CLEARED)    Fee_ConfigInfoOld[FEE_CONFIG_MAX_NUM];            /* old config infomation */

extern VAR(Fee_OldSectorStatusType, FEE_INTERNAL_VAR_CLEARED)      Fee_OldSectorStatusArray[FEE_OLD_EFFECTIVE_MAX];  /* old effective sector infomation*/

extern VAR(uint16,FEE_INTERNAL_VAR_CLEARED)                        Fee_PageNoFront;                                  /* Page No of front */

extern VAR(Fee_BlockManagementInfoType,FEE_INTERNAL_VAR_CLEARED)   Fee_BlkMgtInfoForReadBlockNoPageNo;               /* block management information buffer for write block to read block no and page no */

extern VAR(uint32, FEE_INTERNAL_VAR_CLEARED)                       Fee_InfoDataBufferArray[FEE_FLAG_MAX_NUM];        /* data buffer for readout flags */

extern VAR(uint8, FEE_INTERNAL_VAR_CLEARED)                        Fee_BlockIndexAlreadyUpdated;          /* it indicates that block index has already been updated or not */

#define FEE_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#include "Fee_MemMap.h"
/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/
#define FEE_START_SEC_CODE_ASIL_B
#include "Fee_MemMap.h"

extern FUNC(void, FEE_CODE) Fee_SetCurrentConfigNo(
  VAR(uint8, AUTOMATIC) current_config_no);

extern FUNC(uint32, FEE_CODE) Fee_GetSecTopAddr(void);

extern FUNC(uint8, FEE_CODE) Fee_GetNoOfSec(void);

extern FUNC(uint16, FEE_CODE) Fee_GetNoOfBlocks(void);

extern FUNC(uint32, FEE_CODE) Fee_GetSectorSize(void);

extern FUNC(uint32, FEE_CODE) Fee_GetRemainSize(void);

extern FUNC(uint32, FEE_CODE) Fee_GetSecEndAddr(void);

extern FUNC(uint8, FEE_CODE) Fee_GetNormalSectorCount(void);

extern FUNC(uint8, FEE_CODE) Fee_GetLastSectorCount(void);

extern FUNC(uint32, FEE_CODE) Fee_GetPSCChecksum(void);

extern FUNC(Fee_BlockConfigType, FEE_CODE) Fee_GetBlkCfg(
  VAR(uint16, AUTOMATIC) index);

extern FUNC(uint8, FEE_CODE) Fee_GetSectorStatus(
  VAR(uint8, AUTOMATIC) index);

extern FUNC(void, FEE_CODE) Fee_SetSectorStatus(
  VAR(uint8, AUTOMATIC) index,
  VAR(uint8, AUTOMATIC) sector_status);

extern FUNC(uint8, FEE_CODE) Fee_GetSectorStatusMirror(
  VAR(uint8, AUTOMATIC) index);

extern FUNC(void, FEE_CODE) Fee_SetSectorStatusMirror(
  VAR(uint8, AUTOMATIC) index,
  VAR(uint8, AUTOMATIC) sector_status_mirror);

extern FUNC_P2VAR(Fee_BlockManagementInfoType, AUTOMATIC, FEE_CODE) Fee_GetBlkMgtAreaEmptyAddr(void);

extern FUNC(void, FEE_CODE) Fee_SetBlkMgtAreaEmptyAddr(
  P2VAR(Fee_BlockManagementInfoType, AUTOMATIC, FEE_APPL_DATA) blk_mgt_area_empty_addr_ptr);

extern FUNC_P2VAR(uint32, AUTOMATIC, FEE_CODE) Fee_GetBlkPageAreaEmptyAddr(void);

extern FUNC(void, FEE_CODE) Fee_SetBlkPageAreaEmptyAddr(
  P2VAR(uint32, AUTOMATIC, FEE_APPL_DATA) blk_page_area_empty_addr_ptr);

extern FUNC(uint16, FEE_CODE) Fee_GetBlkEmptySize(void);

extern FUNC(void, FEE_CODE) Fee_SetBlkEmptySize(
  VAR(uint16, AUTOMATIC) blk_empty_size);

extern FUNC(Fee_BlockAddrIndexType, FEE_CODE) Fee_GetBlockAddrIndex(
  VAR(uint16, AUTOMATIC) index);

extern FUNC(void, FEE_CODE) Fee_SetBlockAddrIndex(
  VAR(uint16, AUTOMATIC) index,
  VAR(Fee_BlockAddrIndexType, AUTOMATIC) block_addr_index);

extern FUNC(Fee_BlockAddrIndexType, FEE_CODE) Fee_GetBlockAddrIndexMirror(
  VAR(uint16, AUTOMATIC) index);

extern FUNC(void,FEE_CODE) Fee_SetConfigInfoOld(
  VAR(uint16, AUTOMATIC) fee_normalsectorcount,
  VAR(uint16, AUTOMATIC) fee_lastsectorcount,
  VAR(uint32, AUTOMATIC) fee_checksum);

extern FUNC(void, FEE_CODE) Fee_InitOldSectorStatusArray(void);

extern FUNC(uint16, FEE_CODE) Fee_GetSectorSizeLessThan800(void);


#define FEE_STOP_SEC_CODE_ASIL_B
#include "Fee_MemMap.h"

#endif /*!defined(FEE_READ_H_INCLUDED)*/

