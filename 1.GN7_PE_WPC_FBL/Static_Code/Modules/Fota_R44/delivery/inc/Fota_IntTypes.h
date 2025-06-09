/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: FOTA_IntTypes.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   : Provides all of the user type define                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 2.0.0.0   31-Dec-2024   ThanhTVP2      #CP44-12051                         **
** 1.2.0.0   09-Apr-2024   jys            #CP44-7653                          **
** 1.1.1.0   03-Jun-2024   KJShim         #CP44-9249                          **
** 1.0.0.0   30-Mar-2022   jys            Initial version                     **
*******************************************************************************/
#ifndef FOTA_INTTYPES_H
#define FOTA_INTTYPES_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "HwResource.h"
#include "Fota_Cfg.h"
/*******************************************************************************
**                          Macros                                            **
*******************************************************************************/
#define FOTA_ZERO                             ((uint8)0x00)
#define FOTA_ONE                              ((uint8)0x01)
#define FOTA_TWO                              ((uint8)0x02)
#define FOTA_THREE                            ((uint8)0x03)
#define FOTA_FOUR                             ((uint8)0x04)
#define FOTA_FIVE                             ((uint8)0x05)
#define FOTA_SIX                              ((uint8)0x06)
#define FOTA_SEVEN                            ((uint8)0x07)
#define FOTA_EIGHT                            ((uint8)0x08)

#define FOTA_SWUNIT_MARK                      ((uint8)0xF1)

#define FOTA_INVALID_INDEX                                               (0xFFU)
#define FOTA_SAVEDADDR_INIT                                       (0xFFFFFFFFUL)
#define FOTA_TRUE                                                        (0x01U)
#define FOTA_FALSE                                                       (0x00U)
#define NULL_FUNC                                                ((void (*)())0)

#define FOTA_CIPHERKEY_MAC_LENGTH_MAX                                      (64u)
#define FOTA_CIPHERKEY_LENGTH_MAX                                          (64u)
#define FOTA_CIPHERIV_LENGTH_MAX                                           (64u)
#define FOTA_MACKEY_LENGTH_MAX                                             (64u)

#define FOTA_CSM_KE_ID_MAINKEY                                              (1u)
#define FOTA_CSM_KE_ID_IV                                                   (5u)
#define FOTA_CSM_KE_ID_SALT                                                (13u)
#define FOTA_CSM_KE_ID_ITERATION                                           (14u)
#define FOTA_CSM_KE_ID_ALGORITHM                                           (15u)
#define FOTA_CSM_KE_ID_HSMINDEX                                            (1001u)

#define MAX_CRC_AREA                                                        (8u)
#define INIT_CRC_LEN                                                        (16u)

#define PART_SK_CNT                                 15U

/*******************************************************************************
**                     Global Data                                            **
*******************************************************************************/
/* states during the processing of FOTA Images */
typedef enum
{
  /* Initial state of the FOTA Handler after the ECU startup procedure */
  FOTA_IDLE = 0x00U,
  /* The FOTA Handler is initialized and Dcm is set into the correct state
   * (in Dcm FOTA session and security access has been granted).
   */
  FOTA_INIT,
  /* All FOTA data chunks have been installed, activation procedure can be triggered. */
  FOTA_READY,
  /* The FOTA Handler is triggered by the Dcm callout since a new chunk has been
   * received and is processed in the callout context.
   */
  FOTA_VERSION_CHECK_PROCESSING,

  FOTA_PROCESSING,
  /* The FOTA Handler has successfully processed the last received data chunk,
   * returned the Dcm callout function and is waiting for the next data chunk.
   */
  FOTA_WAIT,
  /* Optional and implementer specific step, since the FOTA Target does not
   * specify any details on the verification process.
   */
  FOTA_VERIFY,
  /* Optional and implementer specific. Reserved state for e.g. implementer
   * specific error handling, which is not (yet) covered by the FOTA Target.
   */
  FOTA_ERROR
} Fota_StateType;

/* states during the processing of FOTA Module */
typedef enum
{
  FOTA_MODULEDEINIT = 0x00U,
  FOTA_MODULEINIT
} Fota_InitStatusType;

typedef enum
{
  FOTA_ERASE_VERSION_CHECK_REQUEST       = 0,
  FOTA_ERASE_VERSION_CHECK_RESULT,
  FOTA_ERASE_RESYNC_REQUEST,
  FOTA_ERASE_RESYNC_RESULT,
  FOTA_ERASE_CMD,
  FOTA_ERASE_CHK,
  FOTA_ERASE_END,
  FOTA_ERASE_ERR,
  FOTA_ERASE_ERR_VERSION,
  FOTA_ERASE_ERR_SYNC
} Fota_EraseStatType;

typedef enum
{
  FOTA_DOWNLOAD_VERSION_CHECK_REQUEST       = 0,
  FOTA_DOWNLOAD_VERSION_CHECK_RESULT,
  FOTA_DOWNLOAD_NORMAL
} Fota_DownloadStatType;

typedef enum
{
  FOTA_METADATA       = 0,
  FOTA_FIRMWARE       = 1,
  FOTA_SIGNATURE      = 2,
  FOTA_PARTITION_FLAG = 3,
  FOTA_CRC            = 4,
  FOTA_UNKNOWN        = 5
} Fota_BlockType;

typedef enum
{
  FOTA_CRC_VERIFY       = 0U,
  FOTA_SIGNATURE_VERIFY = 1U
} Fota_VerifyMethodType;

typedef enum
{
  FOTA_VERIFY_USE_BUFFER       = 0U,
  FOTA_VERIFY_USE_DIRECT_ADDRESS = 1U
} Fota_VerifyAccessMemoryType;

typedef enum
{
  FOTA_VERIFY_MEM_JOB_NONE            = 0U,
  FOTA_VERIFY_MEM_JOB_READ_SIGN       = 1U,
  FOTA_VERIFY_MEM_JOB_READ_FIRMWARE   = 2U
} Fota_VerifyMemJobType;
/* Asynchronous job result type */
typedef enum
{
  /* The last job has been finished successfully */
  FOTA_JOB_OK = 0x00U,
  /* A job is currently being processed */
  FOTA_JOB_PENDING,
  /* Job failed for some unspecific reason */
  FOTA_JOB_FAILED
} Fota_JobResultType;

typedef uint32 Fota_StartupCommandType;

typedef struct
{
  uint32            StartAddPhy;
  uint32            TotalLen;
  uint32            WriteAddPhy;
  uint32            Writelen;
  uint32            TotalWrittenlen;
  const uint8       *pWriteData;
  Fota_BlockType    BlockType;
} Fota_FlashWriteType;

typedef struct
{
  uint32         SavedAddr;
  uint8          New_Chunk_Received;
} Fota_RetransferType;

typedef enum
{
  FOTA_CPD_CMD = 0,
  FOTA_CPD_INTEGRITY_CHECK,
  FOTA_CPD_VERSION_CHECK_REQUEST,
  FOTA_CPD_VERSION_CHECK_RESULT,
  FOTA_CPD_PARTITION_WRITE,
  FOTA_CPD_PARTITION_WRITE_CHECK,
  FOTA_CPD_CPDKEY_WRITE,
  FOTA_CPD_CPDKEY_WRITE_CHECK,
  FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM,
  FOTA_CPD_ERASE_ROM,
  FOTA_CPD_ERASE_ROM_CHECK,
  FOTA_CPD_END_READY,
  FOTA_CPD_END_ACTIVATE,
  FOTA_CPD_ERR
} Fota_CpdStatType;

typedef struct {
  uint8* FirmwareKeyPtr;
  uint8* MacPtr;
  uint8* MacKeyPtr;
  uint8* DecryptIVPtr;
} Fota_MetaPars_Type;

typedef struct
{
  Fota_BlockType BlockType;
  uint16 BlockIndex;
  uint32 StartAddress;
  uint32 EndAddress;
} Fota_TargetBlockSwUnitType;

typedef struct
{
  uint8 NumOfBlock;
  const Fota_TargetBlockSwUnitType *TargetBlockSwUnitPtr;
} Fota_TargetBlockType;

typedef struct
{
  boolean IsWriteRequired;
  uint32 HeaderLength;
  uint32 SKMetaLength;
  uint32 HashJobId;
  uint32 HashKeyId;
  uint32 HashDigestLength;
  uint32 KDFKeyId;
  uint32 KDFResultKeyId;
  uint32 KDFResultLength;
  uint32 DecryptKeyId;
  uint32 DecryptKeyLength;
  uint32 DecryptIVLength;
  uint32 MACJobId;
  uint32 MACKeyId;
  uint32 MACLength;
  const Fota_TargetBlockSwUnitType *Metadata;
} Fota_SWUnitMetadataType;

typedef struct
{
  uint8 NumOfMetadata;
  Fota_SWUnitMetadataType *SWUnitMetadata;
} Fota_MetaDataType;

typedef P2FUNC(Std_ReturnType, FOTA_CODE, Fota_CalloutFuncPtrType) (void);

typedef struct
{
  Fota_CalloutFuncPtrType CalloutFuncPtr;
} Fota_UserCalloutType;

typedef struct
{
  boolean IsEncrypted;
  uint32 DecryptJobId;
  uint32 DecryptKeyId;
  uint32 DecryptKeyLength;
  uint32 DecryptIVLength;
  uint8 NumOfPreProcCallout;
  Fota_UserCalloutType *PreProcCalloutPtr;
  uint8 NumOfPostProcCallout;
  Fota_UserCalloutType *PostProcCalloutPtr;
} Fota_FwBlockProcessingType;

typedef struct
{
  uint8 NumOfBlock;
  Fota_FwBlockProcessingType *FwBlockProcessingInfo;
} Fota_FirmwareType;

typedef struct {
  uint8*              SignatureBuffer;
  const uint8*        PublicKeyBuffer;
}Fota_SFSignChk_CmdType;

typedef enum
{
  FOTA_SF_MADEBY_NONE              = 0,
  FOTA_SF_MADEBY_ASIMS             = 1,
  FOTA_SF_MADEBY_FST               = 2,
}Fota_SFSign_MadeBy;

typedef struct
{
  uint32 StartAddress;
  uint32 EndAddress;
} Fota_CrcAreaType;


typedef struct
{
  uint8 InitCrc[INIT_CRC_LEN];
  uint16 CrcValue;
  uint16 NumberOfCrcAreas;
  Fota_CrcAreaType CrcArea[MAX_CRC_AREA];
} Fota_CrcInfoType;

typedef enum
{
  FOTA_STAT_VERIFY_INACTIVE            = 0,
  FOTA_STAT_VERIFY_INIT                = 1,
  FOTA_STAT_VERIFY_INFO_READ           = 2,
  FOTA_STAT_VERIFY_MEM_JOB_CHECK       = 3,
  FOTA_STAT_VERIFY_START               = 4,
  FOTA_STAT_VERIFY_BLOCK_READ          = 5,
  FOTA_STAT_VERIFY_UPDATE              = 6,
  FOTA_STAT_VERIFY_FINISH              = 7,
  FOTA_STAT_VERIFY_CHECK               = 8,
  FOTA_STAT_VERIFY_PARASET             = 9,
  FOTA_STAT_VERIFY_END                 = 10,
  FOTA_STAT_VERIFY_ERR                 = 11
}Fota_Verify_StatType;

typedef enum {
  /* State 0 : INIT State */
  FOTA_VERSION_INIT = 0,
  /* State 1 : Version OK */
  FOTA_VERSION_OK,
  /* State 2 : Version NOT OK */
  FOTA_VERSION_NOT_OK,
} Fota_VerStateType;

/* Asynchronous job result type */
typedef enum
{
  /* The last job has been finished successfully */
  FOTA_CSM_JOB_IDLE = 0x00U,
  /* A job is currently being processed */
  FOTA_CSM_JOB_START,
  /* Job failed for some unspecific reason */
  FOTA_CSM_JOB_UPDATED,

  FOTA_CSM_JOB_FINISHED,
} Fota_CsmJobState;

/* Asynchronous job result type */
typedef enum
{
  /* The last job has been finished successfully */
  FOTA_CSM_E_OK = 0x00U,
  /* A job is currently being processed */
  FOTA_CSM_E_NOT_OK
} Fota_CsmJobResult;

/* Asynchronous job result type */
typedef enum
{
  /* The last job has been finished successfully */
  FOTA_FBL_TYPE = 0x00U,

  FOTA_RTSW_TYPE,

  FOTA_RTSW_PARTA_TYPE,

  FOTA_RTSW_PARTB_TYPE,

  FOTA_DATA_TYPE,

  FOTA_USER_TYPE
} Fota_SoftwareType;

/* Asynchronous job result type */
typedef enum
{
  /* Erase access */
  FOTA_ERASE_ACCESS_TYPE = 0x00U,
  /* A job is currently being processed */
  FOTA_WRITE_ACCESS_TYPE,
} Fota_AccessMemoryType;

typedef enum
{
  FOTA_AREA_UNKNOWN = 0x00U,
  FOTA_AREA_A       = 0x0AU,
  FOTA_AREA_B       = 0x0BU
} Fota_ActAreaResType;

typedef enum
{
  FOTA_PARTITION_UNKNOWN,
  FOTA_PARTITION_A,
  FOTA_PARTITION_B

} Fota_PartitionType;


typedef enum
{
  FOTA_SWAP_VERSION_CHECK_REQUEST = 0,
  FOTA_SWAP_VERSION_CHECK_RESULT,
  FOTA_SWAP_RECOVERY_TRAILER_ERASE_ROM,
  FOTA_SWAP_DOWNGRADE_CHECK,
  FOTA_SWAP_DEPENDENCY_CHECK,
  FOTA_SWAP_VERIFY_KEY_CHK,
  FOTA_SWAP_ACTIVATE_KEY_WRITE,
  FOTA_SWAP_ACTIVATE_KEY_WRITE_CHK,
  FOTA_SWAP_SECURE_BOOT_MAC_UPDATE,
  FOTA_SWAP_SECURE_BOOT_MAC_UPDATE_CHK,
  FOTA_SWAP_CMD,
  FOTA_SWAP_CMD_CHK,
  FOTA_SWAP_ERASE,
  FOTA_SWAP_ERASE_CHK,
  FOTA_SWAP_END,
  FOTA_SWAP_ERR_CNT_OVER,
  FOTA_SWAP_ERR_VERSION,
  FOTA_SWAP_ERR
} Fota_SwapStatType;

typedef enum
{
  FOTA_VERSION_USED = 0,
  FOTA_VERSION_UNUSED
}Fota_UseVersionCheck;

typedef enum
{
  FOTA_NONE_PROGRAMMING = 0,
  FOTA_PROGRAMMING
}Fota_UseProgramming;

typedef enum
{
  FOTA_CPD_API = 0,
  FOTA_ERASE_API,
  FOTA_INIT_API
}Fota_FunctionType;

typedef enum
{
  FOTA_SVC_CHECK = 0,
  FOTA_VERIFY_KEY_CHECK,
}Fota_SvcOrVerifyKeyType;

typedef enum
{
  FOTA_STATE_DECRYPT_START = 0x00U,
  FOTA_STATE_DECRYPT_UPDATE,
  FOTA_STATE_DECRYPT_FINISH,
  FOTA_STATE_DECRYPT_IDLE,
} Fota_DecryptState;

typedef enum
{
  FOTA_SYNC_IDLE=0,
  FOTA_SYNC_START,
  FOTA_SYNC_SET_SWUNIT,
  FOTA_SYNC_ERASE_SWUNIT_REQ,
  FOTA_SYNC_ERASE_SWUNIT_CHK,
  FOTA_SYNC_SET_VERIFY_UNIT,
  FOTA_SYNC_SET_VERIFY_UNIT_MODULE,
  FOTA_SYNC_WRITE_FW_REQ,
  FOTA_SYNC_WRITE_FW_CHK,
  FOTA_SYNC_SET_VERIFY_UNIT_MODULE_END,
  FOTA_SYNC_SET_VERIFY_UNIT_END,
  FOTA_SYNC_WRITE_SIG_REQ,
  FOTA_SYNC_WRITE_SIG_CHK,
  FOTA_SYNC_VERIFY_REQ,
  FOTA_SYNC_VERIFY_CHK,
  FOTA_SYNC_WRITE_VFYKEY_REQ,
  FOTA_SYNC_WRITE_VFYKEY_CHK,
  FOTA_SYNC_SET_SWUNIT_END,
  FOTA_SYNC_END,
  FOTA_SYNC_ERR
} Fota_SyncStatType;

typedef struct
{
  uint32 VerifyCsmJobId;
  uint32 VerifyCsmKeyId;
  uint32 VerifyCsmKeyElementId;
  uint32 VerifyCsmKeyLength;
  uint8  VerifyNumberOfBlock;
  uint32 VerifyMaxDataSizeOneCycle;
  uint8 VerifyBufferUsed;
  const Fota_TargetBlockSwUnitType *VerifyTargetBlock;
  const Fota_TargetBlockSwUnitType *VerifySignature;
  Fota_CsmJobState VerifyJobState;
  Fota_CsmJobResult VerifyJobResult;
} Fota_VerificationSwUnitType;

typedef struct
{
  uint8 NumOfVerification;
  Fota_VerificationSwUnitType *VerificationSWUnit;
} Fota_VerificationType;

typedef struct
{
  Fota_MetaDataType                   *MetaDataInfoPtr;
  Fota_FirmwareType                   *FirmwareInfoPtr;
  const Fota_VerificationType         *VerificationInfoPtr;
  const Fota_TargetBlockType          *TargetBlockInfoPtr;
  const Fota_TargetBlockSwUnitType    *PartitionInfoPtr;
  const uint32                         StartAddress;
  const uint32                         EndAddress;
  const uint32                         ModuleInfo;
  const uint32                         BlkHeaderAddress;
  const uint32                         BlkTrailerAddress;
  const uint8                          LogicalID;
  const uint16                         ECUSWUnit;
  const uint8                          PflsInstanceId;
  const Fota_SoftwareType              SoftwareType;
} Fota_SwModule;

typedef struct
{
  uint8 *Data;
  uint8 Length;
} Fota_VersionInfoType;

typedef struct
{
  Fota_UseProgramming UseProgramming;
  Std_ReturnType VerifyKeyResult;
} Fota_BackgroundResultType;

typedef struct
{
  Fota_UseVersionCheck CheckVersion;
  Std_ReturnType VersionCheckResult;
  uint8 *CurrentVersion;
  uint8 LengthCurrentVersion;
  uint8 *NewVersion;
  uint8 LengthNewVersion;
} Fota_CheckSwUnitResultType;

typedef enum
{
  FOTA_CMD_IDLE,
  FOTA_CMD_ERASE,
  FOTA_CMD_PROCESS,
  FOTA_CMD_VERIFY
} Fota_CmdStatType;

#define Fota_START_SEC_CONST_UNSPECIFIED
#include "Fota_MemMap.h"
extern CONST(Fota_SwModule,FOTA_CONST) Fota_Gast_SwUnitTable[FOTA_NUM_OF_SWUNIT];
#define Fota_STOP_SEC_CONST_UNSPECIFIED
#include "Fota_MemMap.h"

#if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
  (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02))
#define Fota_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fota_MemMap.h"
/* Array for multicast tx confirmation count */
extern VAR(Fota_CheckSwUnitResultType, FOTA_VAR) Fota_SvcResultAllSwUnit[FOTA_NUM_OF_SWUNIT];
#define Fota_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fota_MemMap.h"
#endif

#if ((FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
#define Fota_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fota_MemMap.h"
/* Array for multicast tx confirmation count */
extern VAR(Fota_BackgroundResultType, FOTA_VAR) Fota_BackgroundResult[FOTA_NUM_OF_SWUNIT];
#define Fota_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fota_MemMap.h"
#endif

#endif /* FOTA_INTTYPES_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
