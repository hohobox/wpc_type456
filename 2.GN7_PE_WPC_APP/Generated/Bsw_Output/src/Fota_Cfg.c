/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Fota_Cfg.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Firmware Over The Air                                 **
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
**  Framework version : 1.2.1                                                 **
**                                                                            **
**  Module version : 2.0.1.0                                                  **
**                                                                            **
**  Tool Version:                                                        **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
* INPUT FILE:      D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_CryIf.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_Crypto_76_HaeModule.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_Csm.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_Fota.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_Mem_76_Pfls.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_CryIf.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_Crypto_76_HaeModule.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_Csm.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_Fota.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_Fota.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_Mem_76_Pfls.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\swcd\Swcd_Fota.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Static_Code\Modules\CryIf_R44\generator\CryIf_ECU_Configuration_PDF.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Static_Code\Modules\Crypto_76_HaeModule_R44\generator\AUTOSAR_Crypto_76_HaeModule_ECU_Configuration_PDF.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Static_Code\Modules\Csm_R44\generator\Csm_ECU_Configuration_PDF.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Static_Code\Modules\Fota_R44\generator\Fota_ECU_Configuration_PDF.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Static_Code\Modules\Mem_R44\generator\Mem_76_Pfls_ECU_Configuration_PDF.arxml
* GENERATED ON: The time-stamp is removed
*/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fota_Cfg.h"
#include "Fota_IntTypes.h"


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define Fota_START_SEC_CONST_UNSPECIFIED
#include "Fota_MemMap.h"
static CONST(Fota_TargetBlockSwUnitType,FOTA_CONST) Fota_TargetBlockSwUnit_0[FOTA_NUMBER_OF_BLOCK_0] =
{
  {
    /* Block type */
    FOTA_METADATA,
    /* Block Index */
    0x0000u,
    /* Start Address */
    0x1000UL,
    /* End Address */
    0x1047UL
  },
  {
    /* Block type */
    FOTA_FIRMWARE,
    /* Block Index */
    0x0001u,
    /* Start Address */
    0x10058000UL,
    /* End Address */
    0x100588FFUL
  },
  {
    /* Block type */
    FOTA_FIRMWARE,
    /* Block Index */
    0x0002u,
    /* Start Address */
    0x10058C00UL,
    /* End Address */
    0x101F7FFFUL
  },
  {
    /* Block type */
    FOTA_SIGNATURE,
    /* Block Index */
    0x0003u,
    /* Start Address */
    0x10058900UL,
    /* End Address */
    0x10058AFFUL
  },
  {
    /* Block type */
    FOTA_PARTITION_FLAG,
    /* Block Index */
    0x0004u,
    /* Start Address */
    0x10058B00UL,
    /* End Address */
    0x10058BFFUL
  }
};
#define Fota_STOP_SEC_CONST_UNSPECIFIED
#include "Fota_MemMap.h"

#define Fota_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fota_MemMap.h"
static VAR(Fota_VerificationSwUnitType,FOTA_VAR) Fota_VerificationSWUnitInfo_0[FOTA_NUM_OF_VERIFY_0] =
{
  {
    /* Fota_VerifyCsmJobId */
    2u,
    /* Fota_VerifyCsmKeyId */
    2u,
    /* Fota_VerifyCsmKeyElementId */
    1u,
    /* Fota_VerifyCsmKeyLength */
    260u,
    /* Fota_VerifyNumOfBlock */
    2u,
    /* VerifyMaxDataSizeOneCycle */
    0u,
    /* VerifyBufferUsed */
    FOTA_FALSE,
    /* Fota_VerifyTargetBlock */
    &Fota_TargetBlockSwUnit_0[1],
    /* Fota_VerifySignature */
    &Fota_TargetBlockSwUnit_0[3],
    /* Fota_VerifyJobState */
    FOTA_CSM_JOB_IDLE,
    /* Fota_CsmJobResult */
    FOTA_CSM_E_OK
  }
};
#define Fota_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fota_MemMap.h"	
	
#define Fota_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fota_MemMap.h"
static VAR(Fota_SWUnitMetadataType,FOTA_VAR) Fota_SWUnitMetadataInfo_0[FOTA_NUM_OF_METADATA_BLOCK_0] =
{
  /* MetaData Block Number 1 */
  {
    /* IsWriteRequired*/
    FOTA_FALSE,
    /* HeaderLength */
    8u,
    /* SKMetaLength */
    48u,
    /* HashJobId */
    1u,
    /* HashKeyId */
    1u,
    /* HashDigestLength */
    32u,
    /* KDFKeyId */
    5u,
    /* KDFResultKeyId */
    6u,
    /* KDFResultLength */
    32u,
    /* DecryptKeyId */
    3u,
    /* DecryptKeyLength*/
    16u,
    /* DecryptIVLength*/
    16u,
    /* MACJobId */
    3u,
    /* MACKeyId */
    3u,
    /* MACLength */
    16u,
    /* Metadata */
    &Fota_TargetBlockSwUnit_0[0]
  }
};
#define Fota_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fota_MemMap.h"


#define Fota_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fota_MemMap.h"
static VAR(Fota_FwBlockProcessingType,FOTA_VAR) Fota_SWUnitBlockProcessingInfo_0[FOTA_NUM_OF_FIRMWARE_BLOCK_0]=
{
  /* Block 1 Processing Option */
  {
    /* IsEnCrypted */
    FOTA_TRUE,
    /* DecryptJobId */
    0u,
    /* DecryptKeyId */
    0u,
    /* DecryptKeyLength*/
    0u,
    /* DecryptIVLength*/
    0u,
    /* NumOfPreProcCallout */
    0u,
    /* pPreProcCallout */
    NULL_PTR,
    /* NumOfPostProcCallout */
    0u,
    /* pPostProcCallout */
    NULL_PTR
  },
  /* Block 2 Processing Option */
  {
    /* IsEnCrypted */
    FOTA_TRUE,
    /* DecryptJobId */
    0u,
    /* DecryptKeyId */
    0u,
    /* DecryptKeyLength*/
    0u,
    /* DecryptIVLength*/
    0u,
    /* NumOfPreProcCallout */
    0u,
    /* pPreProcCallout */
    NULL_PTR,
    /* NumOfPostProcCallout */
    0u,
    /* pPostProcCallout */
    NULL_PTR
  }
};
#define Fota_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fota_MemMap.h"



#define Fota_START_SEC_CONST_UNSPECIFIED
#include "Fota_MemMap.h"
static CONST(Fota_TargetBlockType,FOTA_CONST) Fota_TargetBlockInfo[FOTA_NUM_OF_SWUNIT] =
{
  /* SW Unit RTSW 0 */
  {
    /* NumOfBlock */
    FOTA_NUMBER_OF_BLOCK_0,
    /* TargetBlockInfo */
    &Fota_TargetBlockSwUnit_0[0]
  }
};
#define Fota_STOP_SEC_CONST_UNSPECIFIED
#include "Fota_MemMap.h"
	

#define Fota_START_SEC_CONST_UNSPECIFIED
#include "Fota_MemMap.h"
static CONST(Fota_VerificationType,FOTA_VAR) Fota_VerificationInfo[FOTA_NUM_OF_SWUNIT] =
{
  {
    FOTA_NUM_OF_VERIFY_0,
    /* SW Unit RTSW 0 */
    &Fota_VerificationSWUnitInfo_0[0]
  }
};
#define Fota_STOP_SEC_CONST_UNSPECIFIED
#include "Fota_MemMap.h"
	
#define Fota_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fota_MemMap.h"
static VAR(Fota_MetaDataType,FOTA_VAR) Fota_MetaDataInfo[FOTA_NUM_OF_SWUNIT_META_DATA_CFG] =
{
  /* SW Unit RTSW 0 */
  {
    /* numOfMetaData */
    FOTA_NUM_OF_METADATA_BLOCK_0,
    /* SWUnitMetadata */
    &Fota_SWUnitMetadataInfo_0[0]
  }
};
#define Fota_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fota_MemMap.h"

#define Fota_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fota_MemMap.h"
static VAR(Fota_FirmwareType,FOTA_VAR) Fota_FirmwareInfo[FOTA_NUM_OF_SWUNIT_FIRMWARE_CFG] =
{
  /* SW Unit RTSW 0 */
  {
    /* numOfFirmware */
    FOTA_NUM_OF_FIRMWARE_BLOCK_0,
    /* FwBlockProcessingInfo */
    &Fota_SWUnitBlockProcessingInfo_0[0]
  },
};
#define Fota_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fota_MemMap.h"


#define Fota_START_SEC_CONST_UNSPECIFIED
#include "Fota_MemMap.h"
CONST(Fota_SwModule,FOTA_CONST) Fota_Gast_SwUnitTable[FOTA_NUM_OF_SWUNIT] =
{
	/* SW Unit RTSW 0 */
  {
    /* Fota_MetaDataInfo */
    &Fota_MetaDataInfo[0],

    /* Fota_FirmwareInfo */
    &Fota_FirmwareInfo[0],

    /* Fota_VerificationInfo */
    &Fota_VerificationInfo[0],

    /* TargetBlockInfoPtr */
    &Fota_TargetBlockInfo[0],

    /* partitionFlagAddress */
    &Fota_TargetBlockSwUnit_0[4],

    /* StartAddress */
    0x10058000UL,

    /* EndAddress */
    0x101F7FFFUL,

    /* swModuleInfo */
    0x10058800UL,

    /* BlkHeaderAddress */
    0UL,

    /* BlkTrailerAddress */
    0UL,

    /* logicalID */
    0u,

    /* ECUSWUnit */
    0xF1B1u,

    /* MemInstanceId */
    0u,

    /* SoftwareType */
    FOTA_RTSW_TYPE
  }
};
#define Fota_STOP_SEC_CONST_UNSPECIFIED
#include "Fota_MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
