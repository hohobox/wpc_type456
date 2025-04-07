/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "EcuInfo.h" /* WPC_1902 */
#include "App_Version.h"

/*******************************************************************************
**                             Macro Definition                               **
*******************************************************************************/
/* 0108_14 */
// typedef struct
// {
//   /* offset of Address
//    *
//    *   +----------------+-------------------+---------------+---------------------------------------------------+
//    *   | magicNumber(4) | currentVersion(5) | reserved(247) |                 Reserved for FBL                  |
//    *   +----------------+-------------------+---------------+---------------------------------------------------+
//    *   |<------------0x100 (App Data)---------------------->|<---------------0x100 (FBL Note)------------------>|
//    */
//   /* Magic Number 4-byte*/
//   uint32 magicNumber;
//   /* Current Version 4-byte */
//   /* uint32 currentVersion; */	/* WPC_2418_04 */
//   uint8 currentVersion[5];		/* WPC_2418_04 */
//   /* Reserved for write unit 248-byte */
//   /* uint8 reserved_1[248]; */	/* WPC_2418_04 */
//   uint8 reserved_1[247];		/* WPC_2418_04 */
//   /* Magic Number 4-byte*/
//   uint32 previousVersion; /* This is reserved area, not including the App*/
//   /* crcInit 2-byte */
//   uint16 crcInit; /* This is reserved area, not including the App*/
//   /* crcVal 2-byte */
//   uint16 crcVal; /* This is reserved area, not including the App*/
//   /* Reserved for write unit 248-byte */
//   uint8 reserved_2[248]; /* This is reserved area, not including the App*/
// } SW_BlkFlashInfo;

/* 0108_14 */
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/* Header Magic Number */
#define MAGIC_NUMBER_HEADER                                              (0x6D6F6269U)
/* Trailer Magic Number */
#define MAGIC_NUMBER_TRAILER                                             (0x6C67656EU)
/* Current Version Number */
/* #define PRODUCT_CURRENT_VERSION (((uint32)cAppSoftVerYear1 << 24)|((uint32)cAppSoftVerYear2 << 16)|((uint32) << 8)|((uint32)cAppSoftVerOrder)) */	/* WPC_2418_04 */	/* WPC_2416_07 */	/* WPC_1910_03 */

#define VERSION_START_BLK_HEADER
#include "MemMap.h"

const SW_BlkFlashInfo App_SoftwareVersionHeader =
{
  /* Magic Number */
  .magicNumber = (uint32)MAGIC_NUMBER_HEADER,
  /* Version Info */
  /* .currentVersion = (uint32)PRODUCT_CURRENT_VERSION, */	/* WPC_2418_04 */
  .currentVersion[0] = (uint8)cAppSoftVerYear1,	/* WPC_2418_04 */
  .currentVersion[1] = (uint8)cAppSoftVerYear2,	/* WPC_2418_04 */
  .currentVersion[2] = (uint8)cAppSoftVerMonth,	/* WPC_2418_04 */
  .currentVersion[3] = (uint8)cAppSoftVerOrder,	/* WPC_2418_04 */
  .currentVersion[4] = (uint8)cAppSoftVerOption,	/* WPC_2418_04 */
};

#define VERSION_STOP_BLK_HEADER
#include "MemMap.h"

#if 0 /* WPC_1913_01 FBL3.0 적용으로 헤더/트레일러 적용 필요가 사라짐 하지만 다운그레이드 방지를 위해서 일부 필요하므로 트레일러만 주석처리 */
#define VERSION_START_BLK_TRAILER
#include "MemMap.h"

const SW_BlkFlashInfo App_SoftwareVersionTrailer =
{
  /* Magic Number */
  .magicNumber = (uint32)MAGIC_NUMBER_TRAILER,
  /* Version Info */
  .currentVersion = (uint32)PRODUCT_CURRENT_VERSION,
};

#define VERSION_STOP_BLK_TRAILER
#include "MemMap.h"
#endif
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

