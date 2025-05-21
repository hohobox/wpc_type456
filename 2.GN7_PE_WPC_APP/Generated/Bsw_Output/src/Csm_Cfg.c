/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: Csm_Cfg.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Csm                                                   **
**                                                                            **
**  PURPOSE   : Define configuration datas                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Framework version: 1.2.1                                                  **
**  Module version: 1.0.11.0                                                  **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
* INPUT FILE:      D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\Definition\ECUConfigurationParameters.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_CryIf.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_Crypto_76_HaeModule.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_Csm.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_HwResource.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_CryIf.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_Crypto_76_HaeModule.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_Csm.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_Csm.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\swcd\Swcd_Bsw_Csm.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Static_Code\Modules\CryIf_R44\generator\CryIf_ECU_Configuration_PDF.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Static_Code\Modules\Crypto_76_HaeModule_R44\generator\AUTOSAR_Crypto_76_HaeModule_ECU_Configuration_PDF.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Static_Code\Modules\Csm_R44\generator\Csm_ECU_Configuration_PDF.arxml
* GENERATED ON: The time-stamp is removed
*/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:20.1 [Not a defect:Low] "see SWS_MemMap_00003 of AUTOSAR" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Csm_IntTypes.h"
#include "Rte_Csm.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Internal variables                                    **
*******************************************************************************/
#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo_Crypto_SW_Hash_Sha256_Fota =
{
  /* result length */
  32U,
  /* service type */
  CRYPTO_HASH,
  /* algorithm */
  {
    /* first algorithm family */
    CRYPTO_ALGOFAM_SHA2_256,
    /* second algorithm family */
    CRYPTO_ALGOFAM_NOT_SET,
    /* key length (in bits) */
    0U,
    /* algorithm mode */
    CRYPTO_ALGOMODE_NOT_SET
  }
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo_Crypto_SW_CsmMacVerify =
{
  /* result length */
  0U,
  /* service type */
  CRYPTO_MACVERIFY,
  /* algorithm */
  {
    /* first algorithm family */
    CRYPTO_ALGOFAM_AES,
    /* second algorithm family */
    CRYPTO_ALGOFAM_NOT_SET,
    /* key length (in bits) */
    128U,
    /* algorithm mode */
    CRYPTO_ALGOMODE_CMAC
  }
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo_Crypto_SW_CsmDecrypt =
{
  /* result length */
  2048U,
  /* service type */
  CRYPTO_DECRYPT,
  /* algorithm */
  {
    /* first algorithm family */
    CRYPTO_ALGOFAM_AES,
    /* second algorithm family */
    CRYPTO_ALGOFAM_NOT_SET,
    /* key length (in bits) */
    128U,
    /* algorithm mode */
    CRYPTO_ALGOMODE_CTR
  }
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo_Crypto_SW_CsmSignatureVerify_RSASSA_PKCS1_v1_5 =
{
  /* result length */
  256U,
  /* service type */
  CRYPTO_SIGNATUREVERIFY,
  /* algorithm */
  {
    /* first algorithm family */
    CRYPTO_ALGOFAM_RSA,
    /* second algorithm family */
    CRYPTO_ALGOFAM_SHA2_256,
    /* key length (in bits) */
    2048U,
    /* algorithm mode */
    CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5
  }
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo_Crypto_HSM_CsmRandomGenerate =
{
  /* result length */
  8U,
  /* service type */
  CRYPTO_RANDOMGENERATE,
  /* algorithm */
  {
    /* first algorithm family */
    CRYPTO_ALGOFAM_RNG,
    /* second algorithm family */
    CRYPTO_ALGOFAM_NOT_SET,
    /* key length (in bits) */
    0U,
    /* algorithm mode */
    CRYPTO_ALGOMODE_NOT_SET
  }
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo_Crypto_HSM_CsmJobKeyDerive =
{
  /* result length */
  0U,
  /* service type */
  CRYPTO_KEYDERIVE,
  /* algorithm */
  {
    /* first algorithm family */
    CRYPTO_ALGOFAM_PBKDF2,
    /* second algorithm family */
    CRYPTO_ALGOFAM_SHA2_256,
    /* key length (in bits) */
    0U,
    /* algorithm mode */
    CRYPTO_ALGOMODE_HMAC
  }
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo_Crypto_OEUK_CsmSignatureVerify =
{
  /* result length */
  8U,
  /* service type */
  CRYPTO_SIGNATUREVERIFY,
  /* algorithm */
  {
    /* first algorithm family */
    CRYPTO_ALGOFAM_RSA,
    /* second algorithm family */
    CRYPTO_ALGOFAM_SHA2_256,
    /* key length (in bits) */
    2048U,
    /* algorithm mode */
    CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5
  }
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo_Crypto_OEUK_HaeHsmRandomGenerate_L10 =
{
  /* result length */
  8U,
  /* service type */
  CRYPTO_RANDOMGENERATE,
  /* algorithm */
  {
    /* first algorithm family */
    CRYPTO_ALGOFAM_RNG,
    /* second algorithm family */
    CRYPTO_ALGOFAM_NOT_SET,
    /* key length (in bits) */
    0U,
    /* algorithm mode */
    CRYPTO_ALGOMODE_NOT_SET
  }
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo_RandomGenerate_L9 =
{
  /* callback id */
  0U,
  /* primitive info */
  &Csm_PrimitiveInfo_Crypto_HSM_CsmRandomGenerate,
  /* cryIf key id */
  7U,
  /* processing type */
  CRYPTO_PROCESSING_SYNC,
  /* callback update notification */
  FALSE
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo_Hash_Sha256_Fota =
{
  /* callback id */
  0U,
  /* primitive info */
  &Csm_PrimitiveInfo_Crypto_SW_Hash_Sha256_Fota,
  /* cryIf key id */
  1U,
  /* processing type */
  CRYPTO_PROCESSING_SYNC,
  /* callback update notification */
  FALSE
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo_SignatureVerify_RSASSA_PKCS1_v1_5_Fota =
{
  /* callback id */
  0U,
  /* primitive info */
  &Csm_PrimitiveInfo_Crypto_SW_CsmSignatureVerify_RSASSA_PKCS1_v1_5,
  /* cryIf key id */
  2U,
  /* processing type */
  CRYPTO_PROCESSING_SYNC,
  /* callback update notification */
  FALSE
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo_Fota_Decrypt0 =
{
  /* callback id */
  0U,
  /* primitive info */
  &Csm_PrimitiveInfo_Crypto_SW_CsmDecrypt,
  /* cryIf key id */
  3U,
  /* processing type */
  CRYPTO_PROCESSING_SYNC,
  /* callback update notification */
  FALSE
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo_Fota_MacVerify0 =
{
  /* callback id */
  0U,
  /* primitive info */
  &Csm_PrimitiveInfo_Crypto_SW_CsmMacVerify,
  /* cryIf key id */
  4U,
  /* processing type */
  CRYPTO_PROCESSING_SYNC,
  /* callback update notification */
  FALSE
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo_RandomGenerate_L10 =
{
  /* callback id */
  0U,
  /* primitive info */
  &Csm_PrimitiveInfo_Crypto_OEUK_HaeHsmRandomGenerate_L10,
  /* cryIf key id */
  8U,
  /* processing type */
  CRYPTO_PROCESSING_SYNC,
  /* callback update notification */
  FALSE
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo_SignatureVerify_RSASSA_PKCS1_v1_5 =
{
  /* callback id */
  0U,
  /* primitive info */
  &Csm_PrimitiveInfo_Crypto_OEUK_CsmSignatureVerify,
  /* cryIf key id */
  9U,
  /* processing type */
  CRYPTO_PROCESSING_ASYNC,
  /* callback update notification */
  FALSE
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo_RandomGenerate_L9 = 
{
  /* crypto job id */
  0U,
  /* crypto job priority */
  0U
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo_Hash_Sha256_Fota = 
{
  /* crypto job id */
  1U,
  /* crypto job priority */
  1U
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo_SignatureVerify_RSASSA_PKCS1_v1_5_Fota = 
{
  /* crypto job id */
  2U,
  /* crypto job priority */
  1U
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo_Fota_Decrypt0 = 
{
  /* crypto job id */
  3U,
  /* crypto job priority */
  1U
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo_Fota_MacVerify0 = 
{
  /* crypto job id */
  4U,
  /* crypto job priority */
  1U
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo_RandomGenerate_L10 = 
{
  /* crypto job id */
  5U,
  /* crypto job priority */
  0U
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
static CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo_SignatureVerify_RSASSA_PKCS1_v1_5 = 
{
  /* crypto job id */
  6U,
  /* crypto job priority */
  1U
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
static VAR(Crypto_JobType, CSM_VAR_INIT) Csm_CryptoJob_RandomGenerate_L9 = 
{
  /* crypto job id */
  0U,
  /* job state */
  CRYPTO_JOBSTATE_IDLE,
  /* primitive input output */
  CSM_DEFAULT_PRIMITIVE_INPUT_OUTPUT,
  /* job primitive information */
  &Csm_JobPrimitiveInfo_RandomGenerate_L9,
  /* job info */
  &Csm_JobInfo_RandomGenerate_L9,
  /* crypto key id */
  0U,
  /* job redirection */
  NULL_PTR,
  /* target crypto key id*/
  0U
};
#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
static VAR(Crypto_JobType, CSM_VAR_INIT) Csm_CryptoJob_Hash_Sha256_Fota = 
{
  /* crypto job id */
  1U,
  /* job state */
  CRYPTO_JOBSTATE_IDLE,
  /* primitive input output */
  CSM_DEFAULT_PRIMITIVE_INPUT_OUTPUT,
  /* job primitive information */
  &Csm_JobPrimitiveInfo_Hash_Sha256_Fota,
  /* job info */
  &Csm_JobInfo_Hash_Sha256_Fota,
  /* crypto key id */
  0U,
  /* job redirection */
  NULL_PTR,
  /* target crypto key id*/
  0U
};
#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
static VAR(Crypto_JobType, CSM_VAR_INIT) Csm_CryptoJob_SignatureVerify_RSASSA_PKCS1_v1_5_Fota = 
{
  /* crypto job id */
  2U,
  /* job state */
  CRYPTO_JOBSTATE_IDLE,
  /* primitive input output */
  CSM_DEFAULT_PRIMITIVE_INPUT_OUTPUT,
  /* job primitive information */
  &Csm_JobPrimitiveInfo_SignatureVerify_RSASSA_PKCS1_v1_5_Fota,
  /* job info */
  &Csm_JobInfo_SignatureVerify_RSASSA_PKCS1_v1_5_Fota,
  /* crypto key id */
  0U,
  /* job redirection */
  NULL_PTR,
  /* target crypto key id*/
  0U
};
#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
static VAR(Crypto_JobType, CSM_VAR_INIT) Csm_CryptoJob_Fota_Decrypt0 = 
{
  /* crypto job id */
  3U,
  /* job state */
  CRYPTO_JOBSTATE_IDLE,
  /* primitive input output */
  CSM_DEFAULT_PRIMITIVE_INPUT_OUTPUT,
  /* job primitive information */
  &Csm_JobPrimitiveInfo_Fota_Decrypt0,
  /* job info */
  &Csm_JobInfo_Fota_Decrypt0,
  /* crypto key id */
  0U,
  /* job redirection */
  NULL_PTR,
  /* target crypto key id*/
  0U
};
#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
static VAR(Crypto_JobType, CSM_VAR_INIT) Csm_CryptoJob_Fota_MacVerify0 = 
{
  /* crypto job id */
  4U,
  /* job state */
  CRYPTO_JOBSTATE_IDLE,
  /* primitive input output */
  CSM_DEFAULT_PRIMITIVE_INPUT_OUTPUT,
  /* job primitive information */
  &Csm_JobPrimitiveInfo_Fota_MacVerify0,
  /* job info */
  &Csm_JobInfo_Fota_MacVerify0,
  /* crypto key id */
  0U,
  /* job redirection */
  NULL_PTR,
  /* target crypto key id*/
  0U
};
#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
static VAR(Crypto_JobType, CSM_VAR_INIT) Csm_CryptoJob_RandomGenerate_L10 = 
{
  /* crypto job id */
  5U,
  /* job state */
  CRYPTO_JOBSTATE_IDLE,
  /* primitive input output */
  CSM_DEFAULT_PRIMITIVE_INPUT_OUTPUT,
  /* job primitive information */
  &Csm_JobPrimitiveInfo_RandomGenerate_L10,
  /* job info */
  &Csm_JobInfo_RandomGenerate_L10,
  /* crypto key id */
  0U,
  /* job redirection */
  NULL_PTR,
  /* target crypto key id*/
  0U
};
#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
static VAR(Crypto_JobType, CSM_VAR_INIT) Csm_CryptoJob_SignatureVerify_RSASSA_PKCS1_v1_5 = 
{
  /* crypto job id */
  6U,
  /* job state */
  CRYPTO_JOBSTATE_IDLE,
  /* primitive input output */
  CSM_DEFAULT_PRIMITIVE_INPUT_OUTPUT,
  /* job primitive information */
  &Csm_JobPrimitiveInfo_SignatureVerify_RSASSA_PKCS1_v1_5,
  /* job info */
  &Csm_JobInfo_SignatureVerify_RSASSA_PKCS1_v1_5,
  /* crypto key id */
  0U,
  /* job redirection */
  NULL_PTR,
  /* target crypto key id*/
  0U
};
#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
static Csm_QueueSlotType Csm_Queue_Crypto_76_HaeHsm[CSM_QUEUE_CRYPTO_76_HAEHSM_MAX_SIZE];
#define CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
static Csm_QueueSlotType Csm_Queue_Crypto_HaeCryptoLib[CSM_QUEUE_CRYPTO_HAECRYPTOLIB_MAX_SIZE];
#define CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Csm_JobType, CSM_VAR_INIT) Csm_JobList[CSM_TOTAL_CONFIGURED_JOB] = 
{
  {
    /* Respective CryIf channel ID */
    0U,
    /* Pointer to Crypto job */
    &Csm_CryptoJob_RandomGenerate_L9,
    /* inDriver flag */
    FALSE,
    /* CsmJobInterfaceUsePort */
    CRYPTO_USE_PORT,
    /* pointer to Rte callback notification */
    NULL_PTR,
    /* pointer to JobRedirectionInfo located in ROM */
    NULL_PTR
  },
  {
    /* Respective CryIf channel ID */
    1U,
    /* Pointer to Crypto job */
    &Csm_CryptoJob_Hash_Sha256_Fota,
    /* inDriver flag */
    FALSE,
    /* CsmJobInterfaceUsePort */
    CRYPTO_USE_FNC,
    /* pointer to Rte callback notification */
    NULL_PTR,
    /* pointer to JobRedirectionInfo located in ROM */
    NULL_PTR
  },
  {
    /* Respective CryIf channel ID */
    1U,
    /* Pointer to Crypto job */
    &Csm_CryptoJob_SignatureVerify_RSASSA_PKCS1_v1_5_Fota,
    /* inDriver flag */
    FALSE,
    /* CsmJobInterfaceUsePort */
    CRYPTO_USE_FNC,
    /* pointer to Rte callback notification */
    NULL_PTR,
    /* pointer to JobRedirectionInfo located in ROM */
    NULL_PTR
  },
  {
    /* Respective CryIf channel ID */
    1U,
    /* Pointer to Crypto job */
    &Csm_CryptoJob_Fota_Decrypt0,
    /* inDriver flag */
    FALSE,
    /* CsmJobInterfaceUsePort */
    CRYPTO_USE_FNC,
    /* pointer to Rte callback notification */
    NULL_PTR,
    /* pointer to JobRedirectionInfo located in ROM */
    NULL_PTR
  },
  {
    /* Respective CryIf channel ID */
    1U,
    /* Pointer to Crypto job */
    &Csm_CryptoJob_Fota_MacVerify0,
    /* inDriver flag */
    FALSE,
    /* CsmJobInterfaceUsePort */
    CRYPTO_USE_FNC,
    /* pointer to Rte callback notification */
    NULL_PTR,
    /* pointer to JobRedirectionInfo located in ROM */
    NULL_PTR
  },
  {
    /* Respective CryIf channel ID */
    0U,
    /* Pointer to Crypto job */
    &Csm_CryptoJob_RandomGenerate_L10,
    /* inDriver flag */
    FALSE,
    /* CsmJobInterfaceUsePort */
    CRYPTO_USE_PORT,
    /* pointer to Rte callback notification */
    NULL_PTR,
    /* pointer to JobRedirectionInfo located in ROM */
    NULL_PTR
  },
  {
    /* Respective CryIf channel ID */
    1U,
    /* Pointer to Crypto job */
    &Csm_CryptoJob_SignatureVerify_RSASSA_PKCS1_v1_5,
    /* inDriver flag */
    FALSE,
    /* CsmJobInterfaceUsePort */
    CRYPTO_USE_PORT_OPTIMIZED,
    /* pointer to Rte callback notification */
    Rte_Call_SignatureVerify_RSASSA_PKCS1_v1_5_CallbackNotification_CallbackNotification,
    /* pointer to JobRedirectionInfo located in ROM */
    NULL_PTR
  }
};
#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Csm_QueueType, CSM_VAR_INIT) Csm_QueueList[CSM_TOTAL_CONFIGURED_QUEUE] =
{
  {
    /* Respective CryIf channel ID */
    0U,
    /* Csm queue maximum size */
    CSM_QUEUE_CRYPTO_76_HAEHSM_MAX_SIZE,
    /* Csm queue current size */
    0U,
    /* Csm queue counter */
    0U,
    /* Csm buffer */
    Csm_Queue_Crypto_76_HaeHsm
  },
  {
    /* Respective CryIf channel ID */
    1U,
    /* Csm queue maximum size */
    CSM_QUEUE_CRYPTO_HAECRYPTOLIB_MAX_SIZE,
    /* Csm queue current size */
    0U,
    /* Csm queue counter */
    0U,
    /* Csm buffer */
    Csm_Queue_Crypto_HaeCryptoLib
  }
};
#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"
CONST(Csm_KeyType, CSM_CONST) Csm_KeyList[CSM_TOTAL_CONFIGURED_KEY] =
{
  {
    /* Identifier of the Csm key */
    0U,
    /* Identifier of the corresponding CryIf key */
    0U
  },
  {
    /* Identifier of the Csm key */
    1U,
    /* Identifier of the corresponding CryIf key */
    1U
  },
  {
    /* Identifier of the Csm key */
    2U,
    /* Identifier of the corresponding CryIf key */
    2U
  },
  {
    /* Identifier of the Csm key */
    3U,
    /* Identifier of the corresponding CryIf key */
    3U
  },
  {
    /* Identifier of the Csm key */
    4U,
    /* Identifier of the corresponding CryIf key */
    4U
  },
  {
    /* Identifier of the Csm key */
    5U,
    /* Identifier of the corresponding CryIf key */
    5U
  },
  {
    /* Identifier of the Csm key */
    6U,
    /* Identifier of the corresponding CryIf key */
    6U
  },
  {
    /* Identifier of the Csm key */
    7U,
    /* Identifier of the corresponding CryIf key */
    7U
  },
  {
    /* Identifier of the Csm key */
    8U,
    /* Identifier of the corresponding CryIf key */
    8U
  },
  {
    /* Identifier of the Csm key */
    9U,
    /* Identifier of the corresponding CryIf key */
    9U
  }
};
#define CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace-end MISRA-C3:20.1 */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
