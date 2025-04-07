/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Mem_76_Pfls_IntFunc.h                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Memory Driver                                         **
**                                                                            **
**  PURPOSE   :                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                        Description              **
********************************************************************************
*******************************************************************************/
#ifndef MEM_76_PFLS_INTFUNC_H
#define MEM_76_PFLS_INTFUNC_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Mem_76_Pfls_Cfg.h"

/*******************************************************************************
**                           Macros                                           **
*******************************************************************************/
#define MEM_76_PFLS_GET_SECTOR_ADDRESS(sectorIndex)\
                   ((Mem_76_Pfls_AddressType)0x00400000 + ((sectorIndex)*8*1024))
/* Maximum number of bytes in program data register DATA0->DATA31 */
#define MEM_76_PFLS_DATA_SIZE_BYTES_U32                                     128u
/* get the sector index by address */
#define MEM_76_PFLS_GET_SECTOR_INDEX_BY_ADDR(address) \
     (((address) - Mem_76_Pfls_BlockInfor[(MEM_76_PFLS_ZERO)].BlockStartAddress)/(MEM_76_PFLS_SECTOR_SIZE))

#define MEM_76_PFLS_MAX_WAIT_CNT  1000UL

/*******************************************************************************
**                     Global Data Types                                      **
*******************************************************************************/
typedef enum
{
  MEM_76_PFLS_SWAP_INACTIVE        = 0x00,
  MEM_76_PFLS_SWAP_GET_ACTIVE_BANK,
  MEM_76_PFLS_SWAP_GET_ACTIVE_BANK_CHK,
  MEM_76_PFLS_SWAP_SET_ACTIVE_BANK,
  MEM_76_PFLS_SWAP_SET_ACTIVE_BANK_CHK,
  MEM_76_PFLS_SWAP_NEXT_BANK_VERIFY,
  MEM_76_PFLS_SWAP_NEXT_BANK_VERIFY_CHK,
  MEM_76_PFLS_SWAP_END,
  MEM_76_PFLS_SWAP_ERR
} Mem_76_Pfls_SwapStateType;

typedef enum
{
  MEM_76_PFLS_SWAP_MAP_STD                   = 0,
  MEM_76_PFLS_SWAP_MAP_ALT                   = 1,
}Mem_76_Pfls_SwapRequestType;

typedef enum
{
  MEM_76_PFLS_SWAP_DISABLED                  = 0,
  MEM_76_PFLS_SWAP_ENALBED                   = 1,
}Mem_76_Pfls_SwapEnableType;

/* Memory Block type */
typedef enum
{
  MEM_76_PFLS_STD_BLOCK = 0x0AU,
  MEM_76_PFLS_ALT_BLOCK = 0x0BU
} Mem_76_Pfls_MemoryBlockType;

/* struct contains information of a Flash memory block */
typedef struct
{
  /* start address of block */
  Mem_76_Pfls_AddressType BlockStartAddress;
  /* size of block */
  Mem_76_Pfls_LengthType BlockSize;
  /* block mask */
  Mem_76_Pfls_AddressType BlockMask;
  /* lock Register */
  Mem_76_Pfls_AddressType LockRegAddress[2];
  /* select Register */
  Mem_76_Pfls_AddressType SelectRegAddress;

} Mem_76_Pfls_BlockInformationType;

/*******************************************************************************
**                     Global Data                                            **
*******************************************************************************/
#define MEM_76_PFLS_START_SEC_CONST_32
#include "MemMap.h"

/* Note: Linker scripts symbol declarations must be accessed by the use of the '&' operators */
#if (MEM_76_PFLS_RAMCODE_USED == STD_ON)
/* Start Position of Pflash driver code in flash */
extern CONST(uint32, MEM_76_PFLS_CONST) __Mem_76_Pfls_RomStart;
/* Size of Pflash driver code in flash */
extern CONST(uint32, MEM_76_PFLS_CONST) __Mem_76_Pfls_RomSize;
/* Start Position of Pflash driver code in Ram */
extern CONST(uint32, MEM_76_PFLS_CONST) __Mem_76_Pfls_RamCode;
#endif

#define MEM_76_PFLS_STOP_SEC_CONST_32
#include "MemMap.h"

/*******************************************************************************
**                     Function Prototypes                                    **
*******************************************************************************/
#define MEM_76_PFLS_START_SEC_CODE
#include "MemMap.h"

/* Function to Copy Flash driver from ROM to RAM  */
#if (MEM_76_PFLS_RAMCODE_USED == STD_ON)
extern FUNC(void, MEM_76_PFLS_CODE) Mem_76_Pfls_ToolBox_InternalActive(void);
#endif

extern FUNC(Mem_76_Pfls_JobResultType, MEM_76_PFLS_CODE) Mem_76_Pfls_InternalRead(\
  VAR(Mem_76_Pfls_AddressType, AUTOMATIC) Address, \
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) DataPtr, \
  VAR(Mem_76_Pfls_LengthType, AUTOMATIC) Length, \
  CONST(uint8, MEM_76_PFLS_CONST) BurstEnable);

extern FUNC(Mem_76_Pfls_JobResultType, MEM_76_PFLS_CODE) Mem_76_Pfls_InternalErase(\
  VAR(Mem_76_Pfls_AddressType, AUTOMATIC) Address, \
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) DataPtr, \
  VAR(Mem_76_Pfls_LengthType, AUTOMATIC) Length, \
  CONST(uint8, MEM_76_PFLS_CONST) BurstEnable);

extern FUNC(Mem_76_Pfls_JobResultType, MEM_76_PFLS_CODE) Mem_76_Pfls_InternalWrite(\
  VAR(Mem_76_Pfls_AddressType, AUTOMATIC) Address, \
  P2CONST(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_CONST) DataPtr, \
  VAR(Mem_76_Pfls_LengthType, AUTOMATIC) WriteNormalSize, \
  VAR(Mem_76_Pfls_LengthType, AUTOMATIC) WriteBurstSize, \
  CONST(uint8, MEM_76_PFLS_CONST) BurstEnable);

extern FUNC(void, MEM_76_PFLS_CODE) Mem_76_Pfls_InternalInitialize(void);

extern FUNC(Mem_76_Pfls_AddressType, MEM_76_PFLS_CODE) Mem_76_Pfls_CalBankAddress(
  VAR(Mem_76_Pfls_InstanceIdType, AUTOMATIC) instanceId,
  VAR(Mem_76_Pfls_AddressType, AUTOMATIC) Address);

extern FUNC(Std_ReturnType, MEM_76_PFLS_CODE) Mem_76_Pfls_ActiveBankCheck(\
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) dataPtr, \
  P2VAR(Mem_76_Pfls_LengthType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) lengthPtr);

extern FUNC(Std_ReturnType, MEM_76_PFLS_CODE) Mem_76_Pfls_DirectAddressAccess(\
  VAR(Mem_76_Pfls_InstanceIdType, AUTOMATIC) instanceId, \
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) dataPtr, \
  P2VAR(Mem_76_Pfls_LengthType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) lengthPtr);

extern FUNC(Std_ReturnType, MEM_76_PFLS_CODE) Mem_76_Pfls_AltAddressAccess(\
  VAR(Mem_76_Pfls_InstanceIdType, AUTOMATIC) instanceId, \
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) dataPtr, \
  P2VAR(Mem_76_Pfls_LengthType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) lengthPtr);

extern FUNC(Std_ReturnType, MEM_76_PFLS_CODE) Mem_76_Pfls_SwapActive(\
  VAR(Mem_76_Pfls_InstanceIdType, AUTOMATIC) instanceId, \
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) dataPtr, \
  P2VAR(Mem_76_Pfls_LengthType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) lengthPtr);

extern FUNC(Mem_76_Pfls_JobResultType, MEM_76_PFLS_CODE) Mem_76_Pfls_JobSwapProcess(\
  VAR(Mem_76_Pfls_InstanceIdType, AUTOMATIC) InstanceId);

#define MEM_76_PFLS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* MEM_76_PFLS_INTFUNC_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
