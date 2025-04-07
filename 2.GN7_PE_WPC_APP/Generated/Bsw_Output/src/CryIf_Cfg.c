/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: CryIf_Cfg.c                                           **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CRYIF                                                 **
**                                                                            **
**  PURPOSE   : Define configuration data                                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Framework version : 1.1.6.2                                          **
**                                                                            **
**  Module version : 1.0.5.0                                         **
**                                                                            **
**  Tool Version: 4.4.7                                              **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
* INPUT FILE:      Configuration\Definition\ECUConfigurationParameters.arxml
*                  Configuration\ECU\Ecud_CryIf.arxml           
*                  Configuration\ECU\Ecud_Crypto_76_HaeModule.arxml
*                  Generated\Bsw_Output\bswmd\Bswmd_CryIf.arxml 
*                  Generated\Bsw_Output\bswmd\Bswmd_Crypto_76_HaeModule.arxml
*                  Static_Code\Modules\CryIf_R44\generator\CryIf_ECU_Configuration_PDF.arxml
*                  Static_Code\Modules\Crypto_76_HaeModule_R44\generator\AUTOSAR_Crypto_76_HaeModule_ECU_Configuration_PDF.arxml
* GENERATED ON: The time-stamp is removed
*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* For header file */
#include "CryIf_Cfg.h"
/* For configured data declare */
#include "CryIf_Globals.h"
/* For Crypto Driver 0 */
#include "Crypto_76_HaeModule.h"

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* Dependent module files version information */
#define CRYIF_CRYPTO_AR_RELEASE_MAJOR_VERSION              (0x04U)
#define CRYIF_CRYPTO_AR_RELEASE_MINOR_VERSION              (0x04U)
/* Check AUTOSAR version module Crypto_76_HaeModule */
#if (CRYPTO_76_HAEMODULE_AR_RELEASE_MAJOR_VERSION != \
  CRYIF_CRYPTO_AR_RELEASE_MAJOR_VERSION)
  #error "Crypto_76_HaeModule.h : Mismatch in Specification Major Version"
#endif
#if (CRYPTO_76_HAEMODULE_AR_RELEASE_MINOR_VERSION != \
  CRYIF_CRYPTO_AR_RELEASE_MINOR_VERSION)
  #error "Crypto_76_HaeModule.h : Mismatch in Specification Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define CRYIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array provides a list of channel information */
CONST(CryIf_ChannelType, CRYIF_CONFIG_DATA) \
  CryIf_ChannelList[CRYIF_TOTAL_CHANNEL_ID_NUMBER] = \
{
  /* Element 0 */
  {
    /* Crypto interface channel Id */
    (uint32)0,
    /* Crypto Driver object ID */
    (uint32)0,
    /* Index of array Crypto Driver function pointer */
    (uint8)0
  },
  /* Element 1 */
  {
    /* Crypto interface channel Id */
    (uint32)1,
    /* Crypto Driver object ID */
    (uint32)1,
    /* Index of array Crypto Driver function pointer */
    (uint8)0
  }
};

/* Array provides a list of crypto interface key information */
CONST(CryIf_KeyType, CRYIF_CONFIG_DATA) \
  CryIf_CryIfKeyList[CRYIF_TOTAL_CRYIF_KEY_ID_NUMBER] = \
{
  /* Element 0 */
  {
    /* Crypto Interface key ID */
    (uint32)0,
    /* Crypto Driver key ID */
    (uint32)0,
    /* Index of array Crypto Driver function pointer */
    (uint8)0,
    /* Index of array Crypto driver key element holds start value of a key */
    (uint32)0
  },
  /* Element 1 */
  {
    /* Crypto Interface key ID */
    (uint32)1,
    /* Crypto Driver key ID */
    (uint32)1,
    /* Index of array Crypto Driver function pointer */
    (uint8)0,
    /* Index of array Crypto driver key element holds start value of a key */
    (uint32)1
  },
  /* Element 2 */
  {
    /* Crypto Interface key ID */
    (uint32)2,
    /* Crypto Driver key ID */
    (uint32)2,
    /* Index of array Crypto Driver function pointer */
    (uint8)0,
    /* Index of array Crypto driver key element holds start value of a key */
    (uint32)2
  },
  /* Element 3 */
  {
    /* Crypto Interface key ID */
    (uint32)3,
    /* Crypto Driver key ID */
    (uint32)3,
    /* Index of array Crypto Driver function pointer */
    (uint8)0,
    /* Index of array Crypto driver key element holds start value of a key */
    (uint32)3
  },
  /* Element 4 */
  {
    /* Crypto Interface key ID */
    (uint32)4,
    /* Crypto Driver key ID */
    (uint32)4,
    /* Index of array Crypto Driver function pointer */
    (uint8)0,
    /* Index of array Crypto driver key element holds start value of a key */
    (uint32)5
  },
  /* Element 5 */
  {
    /* Crypto Interface key ID */
    (uint32)5,
    /* Crypto Driver key ID */
    (uint32)5,
    /* Index of array Crypto Driver function pointer */
    (uint8)0,
    /* Index of array Crypto driver key element holds start value of a key */
    (uint32)6
  },
  /* Element 6 */
  {
    /* Crypto Interface key ID */
    (uint32)6,
    /* Crypto Driver key ID */
    (uint32)6,
    /* Index of array Crypto Driver function pointer */
    (uint8)0,
    /* Index of array Crypto driver key element holds start value of a key */
    (uint32)11
  },
  /* Element 7 */
  {
    /* Crypto Interface key ID */
    (uint32)7,
    /* Crypto Driver key ID */
    (uint32)7,
    /* Index of array Crypto Driver function pointer */
    (uint8)0,
    /* Index of array Crypto driver key element holds start value of a key */
    (uint32)12
  },
  /* Element 8 */
  {
    /* Crypto Interface key ID */
    (uint32)8,
    /* Crypto Driver key ID */
    (uint32)8,
    /* Index of array Crypto Driver function pointer */
    (uint8)0,
    /* Index of array Crypto driver key element holds start value of a key */
    (uint32)13
  },
  /* Element 9 */
  {
    /* Crypto Interface key ID */
    (uint32)9,
    /* Crypto Driver key ID */
    (uint32)9,
    /* Index of array Crypto Driver function pointer */
    (uint8)0,
    /* Index of array Crypto driver key element holds start value of a key */
    (uint32)14
  }
};

/* Array provides a list of crypto driver key elements */
CONST(CryIf_KeyElementType, CRYIF_CONFIG_DATA) \
  CryIf_KeyElementList[CRYIF_TOTAL_KEY_ELEMENT_NUMBER] = \
{
  /* Element 0 */
  {
    /* Crypto key element ID */
    (uint32)4,
    /* Crypto key element maximum size */
    (uint32)16
  },
  /* Element 1 */
  {
    /* Crypto key element ID */
    (uint32)1,
    /* Crypto key element maximum size */
    (uint32)32
  },
  /* Element 2 */
  {
    /* Crypto key element ID */
    (uint32)1,
    /* Crypto key element maximum size */
    (uint32)260
  },
  /* Element 3 */
  {
    /* Crypto key element ID */
    (uint32)1,
    /* Crypto key element maximum size */
    (uint32)16
  },
  /* Element 4 */
  {
    /* Crypto key element ID */
    (uint32)5,
    /* Crypto key element maximum size */
    (uint32)16
  },
  /* Element 5 */
  {
    /* Crypto key element ID */
    (uint32)1,
    /* Crypto key element maximum size */
    (uint32)16
  },
  /* Element 6 */
  {
    /* Crypto key element ID */
    (uint32)1,
    /* Crypto key element maximum size */
    (uint32)16
  },
  /* Element 7 */
  {
    /* Crypto key element ID */
    (uint32)13,
    /* Crypto key element maximum size */
    (uint32)48
  },
  /* Element 8 */
  {
    /* Crypto key element ID */
    (uint32)14,
    /* Crypto key element maximum size */
    (uint32)4
  },
  /* Element 9 */
  {
    /* Crypto key element ID */
    (uint32)15,
    /* Crypto key element maximum size */
    (uint32)4
  },
  /* Element 10 */
  {
    /* Crypto key element ID */
    (uint32)1001,
    /* Crypto key element maximum size */
    (uint32)1
  },
  /* Element 11 */
  {
    /* Crypto key element ID */
    (uint32)1,
    /* Crypto key element maximum size */
    (uint32)32
  },
  /* Element 12 */
  {
    /* Crypto key element ID */
    (uint32)1,
    /* Crypto key element maximum size */
    (uint32)32
  },
  /* Element 13 */
  {
    /* Crypto key element ID */
    (uint32)0,
    /* Crypto key element maximum size */
    (uint32)16
  },
  /* Element 14 */
  {
    /* Crypto key element ID */
    (uint32)1,
    /* Crypto key element maximum size */
    (uint32)260
  }
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CRYIF_START_SEC_CONST_PTR
#include "MemMap.h"

/* Array provides a list of Crypto_ProcessJob() function pointers */
CONST(CryIf_ProcessJobFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_ProcessJobPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_ProcessJob
};
/* Array provides a list of Crypto_CancelJob() function pointers */
CONST(CryIf_CancelJobFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_CancelJobPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_CancelJob
};
/* Array provides a list of Crypto_KeyElementSet() function pointers */
CONST(CryIf_KeyElementSetFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_KeyElementSetPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_KeyElementSet
};
/* Array provides a list of Crypto_KeySetValid() function pointers */
CONST(CryIf_KeySetValidFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_KeySetValidPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_KeySetValid
};
/* Array provides a list of Crypto_KeyElementGet() function pointers */
CONST(CryIf_KeyElementGetFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_KeyElementGetPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_KeyElementGet
};
/* Array provides a list of Crypto_KeyElementCopy() function pointers */
CONST(CryIf_KeyElementCopyFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_KeyElementCopyPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_KeyElementCopy
};
/* Array provides a list of Crypto_KeyElementCopyPartial() function pointers */
CONST(CryIf_KeyElementCopyPartialFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_KeyElementCopyPartialPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_KeyElementPartialCopy
};
/* Array provides a list of Crypto_KeyCopy() function pointers */
CONST(CryIf_KeyCopyFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_KeyCopyPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_KeyCopy
};
/* Array provides a list of Crypto_KeyElementIdsGet() function pointers */
CONST(CryIf_KeyElementIdsGetFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_KeyElementIdsGetPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_KeyElementIdsGet
};
/* Array provides a list of Crypto_RandomSeed() function pointers */
CONST(CryIf_RandomSeedFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_RandomSeedPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_RandomSeed
};
/* Array provides a list of Crypto_KeyGenerate() function pointers */
CONST(CryIf_KeyGenerateFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_KeyGeneratePtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_KeyGenerate
};
/* Array provides a list of Crypto_KeyDerive() function pointers */
CONST(CryIf_KeyDeriveFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_KeyDerivePtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_KeyDerive
};
/* Array provides a list of Crypto_KeyExchangeCalcPubVal() function pointers */
CONST(CryIf_KeyExchangeCalcPubValFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_KeyExchangeCalcPubValPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_KeyExchangePubValCalc
};
/* Array provides a list of Crypto_KeyExchangeCalcSecret() function pointers */
CONST(CryIf_KeyExchangeCalcSecretFncPtrType, CRYIF_CONFIG_DATA) \
  CryIf_KeyExchangeCalcSecretPtr[CRYIF_TOTAL_CRYPTO_DRIVER] = \
{
  /* Function pointer of Crypto Driver 0 */
  Crypto_76_HaeModule_KeyExchangeSecretCalc
};

#define CRYIF_STOP_SEC_CONST_PTR
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
