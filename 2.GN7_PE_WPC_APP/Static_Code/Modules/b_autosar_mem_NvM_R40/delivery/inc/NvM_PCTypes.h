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
**  SRC-MODULE: NvM_PCTypes.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NvM Module                                            **
**                                                                            **
**  PURPOSE   : Provision of AUTOSAR NVRAM Manager Type Definitions and       **
**              Block Descriptor structure.                                   **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision    Date          By             Description                       **
********************************************************************************
** 1.6.2       18-Aug-2022   Yun  YJ      Redmine #37103                      **
** 1.6.0       25-Mar-2022   Yun  YJ      Redmine #34586                      **
** 1.5.4       30-Dec-2021   JHLim        Redmine #33331                      **
** 1.5.1       30-Dec-2020   Yun YJ       Redmine #27374                      **
** 1.5.0       26-Jun-2020   Yun YJ       Redmine #9669, #24380               **
** 1.3.5       11-Sep-2017   Yun YJ       Redmine #9669, #11480               **
** 1.3.4       07-Dec-2016   Song CY      Redmine #6889                       **
** 1.3.3       16-Nov-2016   Song CY      Redmine #6680                       **
** 1.3.2       10-Oct-2016   Song CY      Redmine #6215                       **
** 1.3.0       25-Jul-2016   Song CY      Redmine #3883                       **
** 1.2.3       24-Mar-2016   Song CY      Redmine #4276                       **
** 1.2.2       11-Feb-2016   Song CY      Redmine #4183                       **
** 1.1.9       10-Nov-2015   Song CY      Correct MISRA-Rule Violation        **
** 1.1.7       09-Jul-2015   Song CY      Correct MISRA-Rule Violation        **
** 1.1.6       03-Mar-2015   Song CY      As per RedMine 2208, Add states of  **
**                                        ProcessReadblock                    **
**                                        As per RedMine 2216, Remove version **
**                                        Information                         **
** 1.1.4       02-Dec-2014  Song CY       RedMine 1719, Update for PolySpace  **
** 1.0.10      18-Feb-2014  Song CY       RedMine 632, Update for RTRT        **
** 1.0.8       30-Sep-2013  Song CY       Update for Library                  **
** 1.0.0       25-Jan-2013    CY Song     Initial version                     **
*******************************************************************************/

#ifndef NVM_PCTYPES_H
#define NVM_PCTYPES_H

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
  polyspace-begin MISRA-C3:8.12:Not a defect:Justify with annotations> No Impact of this rule violation
  polyspace-begin MISRA-C3:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard-NvM SWS Chap 5.1.2)
  polyspace-begin MISRA-C3:20.1 [Justified:Low] "Implemented according to AUTOSAR specification" 
  polyspace-begin MISRA-C3:8.11 [Not a defect:Low] "Use to avoid optimization of compilation"
  polyspace-begin MISRA-C3:D4.9 [Justified:Low] "Not a defect" 
  polyspace-begin MISRA-C3:D4.8 [Justified:Low] "Not a defect" 
  polyspace-begin MISRA-C3:2.5 [Justified:Low] "Used according to configuration" 
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "NvM.h"

/*******************************************************************************
**                        Global Data                                         **
*******************************************************************************/
/* Bit Order for Block Descriptor Parameters  (ucBlkParams) */
#define NVM_TRUE                          (1U)
#define NVM_FALSE                         (0U)

/* Macros used used for accessing a particular block */
#define NVM_ZERO                          ((uint8)0U)
#define NVM_ONE                           ((uint8)1U)
#define NVM_TWO                           ((uint8)2U)
#define NVM_FOUR                          ((uint8)4U)
#define NVM_SIX                           ((uint8)6U)
#define NVM_EIGHT                         ((uint8)8U)
#define NVM_SIXTEEN                       ((uint8)16U)
#define NVM_TWENTYFOUR                    ((uint8)24U)
#define NVM_100                           ((uint8)100U)
#define NVM_FF                            ((uint8)0xFFU)

#define NVM_RESVD_DEVICEID                ((uint8)255U)

#define NVM_CONFIGURATION_BLOCK_ID        ((uint8)1U)

#define NVM_STD_PRIORITY                  ((uint8)1U)
#define NVM_IMM_PRIORITY                  ((uint8)0U)

/* Macros used for CRC offset values */
#define NVM_1BYECRC_STARTVALUE            ((uint8)0xFFU)
#define NVM_2BYECRC_STARTVALUE            ((uint16)0xFFFFU)
#define NVM_4BYECRC_STARTVALUE            (0xFFFFFFFFU)

/* MACROS USED FOR PROCESSING BYTES/BLOCKS IN MULTIPLE CYCLES */

/* MASKS USED TO READ/SET THE SPECIFIC BITS IN NvM_GaaRamStatus */

/* To get the error bits in the error field of RAM */
#define NVM_ERROR_BIT_MASK                ((uint16)0x000FU)

/* To update the error bits in the error field of RAM */
#define NVM_NOT_ERROR_BIT_MASK            ((uint16)0xFFF0U)

/* Mask to set the Write protection bit */
#define NVM_WRITE_PROTECT_MASK            ((uint16)0x0080U)

/* Mask to clear the Write protection bit */
#define NVM_NOT_WRITE_PROTECT_MASK        ((uint16)0xFF7FU)

/* Mask to Set the Lock protection bit */
#define NVM_LOCK_RAM_MASK                 ((uint16)0x0040U)

/* Mask to clear the Lock protection bit */
#define NVM_UNLOCK_RAM_MASK               ((uint16)0xFFBFU)

/* Mask to set RamCrcRequested bit */
#define NVM_CRC_REQUESTED_MASK            ((uint16)0x0100U)


/* in future:  status of the redundant block
 * bit 
 +------+-----+------+
 |  10  |  9  | .... |
 +------+-----+------+
 |
 | 00b : redundan block did not read. 
 | 01b:  NvM read the first block  successfully
 | 10b:  NvM read the second block successfully 
 | 11b:  NvM failed to read both blocks
 +-----------------------------------------------------*
#define NVM_REDUNDANT_BOTH_BLOCKS_UNDEFINED         ((uint16)0x0000U)
#define NVM_REDUNDANT_FIRST_BLOCK_VALID             ((uint16)0x0200U)
#define NVM_REDUNDANT_SECOND_BLOCK_VALID            ((uint16)0x0400U)
#define NVM_REDUNDANT_BOTH_BLOCKS_NOT_VALID         ((uint16)0x0600U)
#define NVM_REDUNDANT_BLOCK_VALID_MASK              ((uint16)0x0600U)
*/

/* Mask to Set the check redundant which block is first write bit */
#define NVM_FIR_REDUNDANT_MASK            ((uint16)0x0200U)

/* Mask to Set the check redundant which block is first write bit */
#define NVM_SEC_REDUNDANT_MASK            ((uint16)0xFDFFU)

/* Mask to Set the need to check redundant bit */
#define NVM_CHECK_NEED_REDUNDANT_MASK     ((uint16)0x0400U)

/* Mask to clear the need to check redundant bit */
#define NVM_CHECK_DONE_REDUNDANT_MASK     ((uint16)0xFBFFU)

/* Mask to Set the need to check invalidated bit */
#define NVM_BLOCK_STATUS_INVALIDATED      ((uint16)0x0800U)


/* MACROS TO READ CONFIGURATION INFORMATION FROM usBlkParams*/

/* Bit 0 - Generation of CRC */
#define NVM_CALC_RAM_BLK_CRC                  ((uint16)0x0001U)
/* Bit 1 - Default Write Protection */
#define NVM_BLOCK_WRITE_PROT                  ((uint16)0x0002U)
/* Bit 2 - Block is of one time Write */
#define NVM_WRITE_BLOCK_ONCE                  ((uint16)0x0004U)
/* Bit 3 - Resistant to changed software */
#define NVM_RESISTANT_TO_CHANGED_SW           ((uint16)0x0008U)
/* Bit 4 - Enables/Disables processing block during readall */
#define NVM_SELECT_BLOCK_FOR_READALL          ((uint16)0x0010U)
/* Bit 6 - Enables/Disables explicit synchronization mechanism*/
#define NVM_BLOCK_USE_SYNC_MECHANISM_ENABLE   ((uint16)0x0040U)
/* Bit 8 - Enables/Disables Write Verification */
#define NVM_WRITE_VERIFICATION_ENABLE         ((uint16)0x0100U)
/* Bit 9 - Enables/Disables Static ID check */
#define NVM_STATIC_BLOCK_ID_CHECK             ((uint16)0x0200U)
/* Bit 10 - If it is set, it intimates to BswM about the current status */
#define NVM_BSWM_BLOCK_STATUS_INFORMATION     ((uint16)0x0400U)
/* Bit 11 - If it is set, it intimates to Calculate CRC on ROM data */
#define NVM_DEFAULT_ROM_CRC_ENABLED           ((uint16)0x0800U)

/* Macro to check CRC configured */
#define NVM_CALC_CRC_BLOCK_CHECK              ((uint16)0x0021U)

/* MACROS RELATED TO CRC CALCULATION */

/* Defines macros for CRC length */
#define NVM_CRC_4BYTE                     0x04
#define NVM_CRC_2BYTE                     0x02
#define NVM_CRC_1BYTE                     0x01

/* MACROS RELATED TO RAM INTERNAL STATES */

/* Macro to define RAM status */
#define NVM_INVALID_UNCHANGED             ((uint8)0x00U)
#define NVM_VALID_UNCHANGED               ((uint8)0x20U)
#define NVM_VALID_CHANGED                 ((uint8)0x30U)

/* MACROS RELATED TO MASK RAM INTERNAL STATES */
#define NVM_CLEAR_RAM_INTERNAL_STATE      ((uint16)0xFFCFU)
#define NVM_RAM_STATUS_MASK               ((uint16)0x0030U)

/* Macro to indicate the status of Redundant block */
typedef enum
{
  NVM_REDUNDANT_NOT_CHECKED_BOTH_BLOCK = 0U,
  NVM_REDUNDANT_CHECKED_FIRST_BLOCK,
  NVM_REDUNDANT_CHECKED_SECOND_BLOCK,
} NvM_RedundantBlockStatusType;

/* Macro to indicate the first write of Redundant block */
typedef enum
{
  NVM_REDUNDANT_FIRST_BLOCK = 0U,
  NVM_REDUNDANT_SECOND_BLOCK,
} NvM_RedundantBlockWriteOrderType;

/* Macro to indicate the status of ReadAll/WriteAll processing */
#define NVM_MULTIBLK_UNREQUESTED          0x00U
#define NVM_MULTIBLK_REQUESTED            0x01U
#define NVM_MULTIBLK_IN_PROGRESS          0x02U

/* MACROS TO DEFINE VARIOUS FUNCTIONAL STATES */
/* Common state values used in all API processing functions */
#define NVM_IDLE                          0x00U
#define NVM_SUB_IDLE                      0x00U

/* Sub states of WriteBlock function */
#define   NVM_WRITE_NVBLOCK               0x01
#define   NVM_WRITE_PROCESS_NV_BLOCK      0x02
#define   NVM_IMMD_WRITE_PENDING          0x03
#define   NVM_PROCESS_WRITE_VERIFY        0x04

/* Sub states of WriteAll function */
#define   NVM_WRITE_ALL_IDLE              0x00U
#define   NVM_WRITE_ALL_BLOCK             0x01U
#define   NVM_WRITE_ALL_PROCESS           0x02U
#define   NVM_WRITE_ALL_INIT              0x03U

/* Sub states of Erase/Invalidate function */
#define NVM_ERASEINVALIDATE_START         0x01
#define NVM_ERASEINVALIDATE_PROCESSING    0x02

/* Sub states of ProcessReadblock function */
#define NVM_READ_START                    0x01
#define NVM_READ_NVBLOCK                  0x02
#define NVM_READ_ROM                      0x03
#define NVM_READ_REDUNDANT_RETRY          0x04
#define NVM_READ_ERROR_STATUS             ((uint8)0xFFU)

/* Sub states of ProcessReadAllBlocks function */
#define NVM_READALL_INIT                  0x01
#define NVM_READALL_PROCESS               0x02
#define NVM_READALL_BLKPROCESS            0x05
#define NVM_READALL_ROMBLK_PROCESS        0x04

#if((NVM_JOB_PRIORITIZATION == STD_ON) && (NVM_API_CONFIG_CLASS != \
      NVM_API_CONFIG_CLASS_1) && (NVM_IMM_JOB_PRIORITY == STD_ON))    
#define NVM_JOB_PRIO                      (STD_ON)
#else
#define NVM_JOB_PRIO                      (STD_OFF)
#endif

/* polyspace-begin MISRA-C3:19.7:Not a defect:Justify with annotations> Not a defect */

#if (NVM_DEV_ERROR_DETECT == STD_ON)
#define NVM_REPORT_ERROR(sid, type)       do{(void)Det_ReportError(NVM_MODULE_ID, NVM_INSTANCE_ID,(sid),(type));} while(0)
#else
#define NVM_REPORT_ERROR(sid, type)       do{}while(0)
#endif


#if(NVM_DEMERROR_REPORT == STD_ON)

#define NVM_DEM_REPORT_ERROR(EventId)       do{(void)Dem_ReportErrorStatus((EventId), DEM_EVENT_STATUS_FAILED);} while(0)
#else

#define NVM_DEM_REPORT_ERROR(EventId)       do{}while(0)
#endif

#define NVM_RESERVED_BLOCK_ID             (0U)
     
/* polyspace-end MISRA-C3:2.5 [Justified:Low] "Used according to configuration */
#if (                                             \
  (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&     \
  (                                               \
    (NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON) ||   \
    (NVM_RAM_BLOCK_DATA_ADDRESS == STD_ON)        \
  )                                               \
)
#define NVM_RAMBLOCKSTATUS_SUPPORT                                (STD_ON)

#else

#define NVM_RAMBLOCKSTATUS_SUPPORT                                (STD_OFF)

#endif

typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_InitNotificationFnType)(void);

typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_NotificationFnType)
  (uint8 ServiceId, NvM_RequestResultType JobResult);

#if(NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)

typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvMReadMirrorNotification)
  (const void* NvMBuffer);

  typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvMWriteMirrorNotification)
  (void* NvMBuffer);
#endif

/* Typedef of NvM_BlkDescTbl structure */

/* Structure for Block Descriptor Table */
typedef struct 
{
  /* Pointer to permanent RAM block data array */
  /* If NVM_RAM_BLOCK_DATA_ADDRESS is STD_ON and Ram Block address is not
   * configured for a particular block then generate NULL_PTR
   */
#if(NVM_RAM_BLOCK_DATA_ADDRESS == STD_ON)
  P2VAR(void, AUTOMATIC, NVM_DATA) pRamBlkData;
#endif

#if (NVM_DATASET_PRESENT == STD_ON)
  /* Data Index field */
  uint8 DataSetIndexPos; 
#endif

  /* Pointer to ROM Block Data */
  P2CONST(void, AUTOMATIC, NVM_CONST)pRomBlkData;

  /* Pointer to   Init Block callback */
  /* If NVM_INIT_CALLBACK is STD_ON and Notification is not configured then
   * generate NULL_PTR
   */
  #if (NVM_INIT_CALLBACK == STD_ON)
  NvM_InitNotificationFnType pNvMInitNotification_BlockId;
  #endif

  /* Pointer to Single Block callback  */
  /* If NVM_SINGLE_BLOCK_CALLBACK is STD_ON and Notification is not configured
   * then generate NULL_PTR
   */
  #if (NVM_SINGLE_BLOCK_CALLBACK == STD_ON)
  NvM_NotificationFnType pNvMNotification_BlockId;
  #endif

  /* Pointer to ReadRamBlockFromNvm callback */
  /* If NVM_BLOCK_USE_SYNC_MECHANISM is STD_ON and callback is not configured
   * then generate NULL_PTR
   */
  #if(NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)
  NvMReadMirrorNotification pNvMReadRamBlockFromNvm;
  #endif

  /* Pointer to WriteRamBlockToNv callback */
  #if(NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)
  NvMWriteMirrorNotification pNvMWriteRamBlockToNvm;
  #endif

  /* NVRAM Block Identifier */
  NvM_BlockIdType ddBlockId;

  NvM_BlockManagementType enBlkMngmntType;

  /* BlockBase Number */
  uint16 usNvBlkBaseNumber;

  /* Block Data Length */
  uint16 usNvBlkDataLength;

  /* Write Verification Data Size */
  /* If NVM_WRITE_VERIFICATION is STD_OFF & NvMWriteVerificationDataSize is
   * configured then the configured value should not be considered
   */
  #if(NVM_WRITE_VERIFICATION == STD_ON)
  uint16 usWriteVerificationDataSize;
  #endif

  #if(NVM_WRITE_VERIFICATION == STD_ON)
  uint16 usWriteVerificationSteps;
  #endif

  /* Bit 0 - This bit is set if NvMBlockUseCrc parameter in NvMBlockDescriptor
   *         container is configured as true
   * Bit 1 - This bit is set if NvMBlockWriteProt parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 2 - This bit is set if NvMWriteBlockOnce parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 3 - This bit is set if NvMResistantToChangedSw parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 4 - This bit is set if NvMSelectBlockForReadAll parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 5 - This bit is set if NvMCalcRamBlockCrc parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 6 - This bit is set if NvMBlockUseSyncMechanism parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 7 - This bit is set if NvMSelectBlockForWriteAll parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 8 - This bit is set if NvMWriteVerification parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 9 - This bit is set if NvMStaticBlockIDCheck parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 10 - This bit is set if NvMBswMBlockStatusInformation parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 11 - This bit is set if NvMDefaultROMCRCEnabled parameter in
   *          NvMBlockDescriptor container is configured as true
   */
  uint16 usBlkParams;

  /* NVRAM device ID value */
  uint8 ucNvramDeviceId;

  /* = 0 if not configured, = 1 for 8 bit CRC, = 2 for 16 bit and =4 for
   * 32 bit
   */
  #if(NVM_CRC_SUPPORT == STD_ON)
  uint8 ucCrcLength;
  #endif

  /* Number of NV blocks */
  uint8 ucNumOfNvBlks;

  /* Number of ROM blocks */
  uint8 ucNumOfRomBlks;

  /* Max Number of Read Retries */
  uint8 ucMaxNumOfReadRetries;

  /* Max Number of Write Retries */
  uint8 ucMaxNumOfWriteRetries;

  /* Block Priority:0-Immediate other than 0-Standard   */
  #if((NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) && \
      (NVM_JOB_PRIORITIZATION == STD_ON))
  uint8 ucBlkJobPriority;
  #endif

}NvM_BlkDescTbl;

/* Structure of Job queue */
typedef struct 
{
  P2CONST(uint8, AUTOMATIC, NVM_CONST) pBufferToWrite;
  P2VAR(uint8, AUTOMATIC, NVM_DATA) pBufferToRead;
    
  NvM_BlockIdType ddBlock_Idx;
  uint8 ucService_Id;
  uint8 ucNextIndex;
  uint8 ucPreviousIndex;
  #if((NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) && \
      (NVM_JOB_PRIORITIZATION == STD_ON))
  uint8 ucPriority;
  #endif
}NvM_JobQueue;

/* Define struct for direct manipulation of 16 bit data */
typedef struct 
{
  uint16 usWordReg16;
}NvM_Word16;


/* Define struct for direct manipulation of 32 bit register */
typedef struct 
{
 uint32 ulLongReg32;
}NvM_DWord32;


typedef P2VAR(NvM_JobQueue, AUTOMATIC, NVM_APPL_DATA) NvM_JobQueuePtrType;

/*
 * This array defines the structure for each NVRAM block configured
 * in input XML file
 */
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(NvM_BlkDescTbl, NVM_CONST) NvM_GaaBlkDescTbl[NVM_TOTAL_NUM_OF_NVRAM_BLOCKS];

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Size of the array should be the total number of blocks configure for
 * Static ID and CRC
 * Eg: Block 2 = SID ON, CRC 8 ON    = 2+1
 *    Block 3 = SID ON, CRC 16 ON   = 2+2
 *   Block 4 = SID OFF, CRC 32 ON  = 0+4
 *    Then total of NvM_GaaCrcSID should be 11
 */
#if((NVM_STATIC_ID_CHECK == STD_ON) || (NVM_CRC_SUPPORT == STD_ON))
#define NVM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, NVM_VAR) NvM_GaaCrcSID[];
#define NVM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
#endif

#if(NVM_DATASET_PRESENT == STD_ON)
#define NVM_START_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"

extern VAR(uint8, NVM_VAR_POWER_ON_INIT) NvM_GaaDataSetIndex[];

#define NVM_STOP_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"
#endif  

#endif /* NVM_PCTYPES_H */
/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
  polyspace-end MISRA-C3:2.5 [Justified:Low] "Used according to configuration" 
  polyspace-end MISRA-C3:D4.8 [Justified:Low] "Not a defect"
  polyspace-end MISRA-C3:D4.9 [Justified:Low] "Not a defect" 
  polyspace-end MISRA-C3:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard-NvM SWS Chap 5.1.2) 
  polyspace-end MISRA-C3:8.12:Not a defect:Justify with annotations> No Impact of this rule violation
  polyspace-end MISRA-C3:20.1 [Justified:Low] "Implemented according to AUTOSAR specification"
  polyspace-end MISRA-C3:8.11 [Not a defect:Low] "Use to avoid optimization of compilation"
*/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
