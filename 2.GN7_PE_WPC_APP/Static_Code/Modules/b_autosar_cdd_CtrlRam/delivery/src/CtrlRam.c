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
**  SRC-MODULE: CtrlRam.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CtrlRam Module                                        **
**                                                                            **
**  PURPOSE   : Watchdog Manager API Functionality                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision    Date           By                Description                   **
********************************************************************************
** 1.0.8       04-Aug-2022  YH.Han          Redmine #36978                    **
** 1.0.7       01-Jan-2022  YongHyun Han    Redmine #33626                    **
** 1.0.6       29-Jul-2020  YongHyun Han    Redmine #24918                    **
** 1.0.5       11-Oct-2019  YongHyun Han    Redmine #19624                    **
** 1.0.5       31-Aug-2017  Hyungho Lee     Redmine #9762                     **
** 1.0.4       12-May-2017  Hyungho Lee     Redmine #8431                     **
** 1.0.2       13-Oct-2016  Hyungho Lee     Redmine #6153                     **
** 1.0.0       25-Jan-2013  JongHyun Baek   Porting from XENON Controlled RAM **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE:UNR:Not a defect:Justify with annotations> code can be reachable according to user configuration */
/* polyspace:begin<MISRA-C3:18.4:Not a defect:Justify with annotations> +,-,+=,-= operators for pointer has no side effects */
/* polyspace:begin<DEFECT:PTR_TO_DIFF_ARRAY:Not a defect:Justify with annotations> comparison between pointer and array has no side effects */
/* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> pointer indicates pre-defined address */
/* polyspace:begin<MISRA-C3:18.3:Not a defect:Justify with annotations> comparison with pointer has no side effects */

#include "string.h"
#include "CtrlRam.h"

#include "CtrlRam_Ram.h"           /* Module RAM header file */
#include "CtrlRam_Types.h"       /* Types header file */
#include "Rte_CtrlRam.h"
#include "SchM_CtrlRam.h"          /* SchM CtrlRam Header file */

#if (CTRLRAM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                /* DET header */
#endif

#if (CTRLRAM_DEMERROR_REPORT == STD_ON)
#include "Dem.h"
#endif

/* Remove the warnings regarding the signed values shifting. */
/* All values for CRAM checksum computation are considered of being unsigned */
#define CTRLRAM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
PRIVATE_DATA uint8 rub_CtrlRAM_DataBufSize;
#endif
#define CTRLRAM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

/* Private functions prototypes */
/* ---------------------------- */
static uint16 bsramctl_ChkCalc (void);
/*  TAG  : Covers_SWR_D_MEM_02_040   */
#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
static uint8 bsramctl_Recovery (void);
#endif

/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : bsramctl_ChkCalc
 *  TAG                  : Covers_SWR_D_MEM_02_070
 *  Description          : Computes the checksum on the entire Controlled RAM area.
 *  Parameters           : [Input, Output, Input / output]
 *    None
 *  Return               :  none
 *  Critical/explanation :  No
 **************************************************************/
#define CTRLRAM_START_SEC_CODE
#include "MemMap.h"

static FUNC(uint16, CTRLRAM_CODE) bsramctl_ChkCalc (void)
{
    /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
    /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
    /* Covers_SWR_D_MEM_02_060*/
    uint16 *lpuw_PtrRamCtl;
    uint16 luw_ChkVal;
    uint32 lul_CtrlRAM_Key;
    uint32 lul_CtrlRAM_Checksum;

    /* Checksum  computation */
    luw_ChkVal = 0x0000u;

    /* Pointer is used in a loop to compute a checksum on a memory area. To do this the pointer is
        initialized with the starting address and compared with the ending address of the area */
    /* The checksum is the sum of words of the entire Controlled RAM area (including KEY and CHK) */
    lpuw_PtrRamCtl = &ruw_CtrlRAM_Key;
    lul_CtrlRAM_Key = (uint32) &ruw_CtrlRAM_Key;
    lul_CtrlRAM_Checksum = (uint32) &ruw_CtrlRAM_Checksum;

    while(lul_CtrlRAM_Key <= lul_CtrlRAM_Checksum)
    {
        /* polyspace<RTE:IDP:Not a Defect:Justify with annotations> pointer is in pre-defined array size */
        /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> pointer operation has no side effects */
        luw_ChkVal += *lpuw_PtrRamCtl; 
        lpuw_PtrRamCtl++;
        lul_CtrlRAM_Key = (uint32) lpuw_PtrRamCtl;
    }

    return (luw_ChkVal);
    /* polyspace:end<MISRA-C3:11.4> */
    /* polyspace:end<ISO-17961:intptrconv> */
}
#define CTRLRAM_STOP_SEC_CODE
#include "MemMap.h"
/**************************************************************
 *  Name                 : bsramctl_Recovery
 *  TAG                  : Covers_SWR_D_MEM_02_050
 *  TAG                  : Covers_SWR_D_MEM_02_040   
 *  Description          : Recovery mechanism routine 
 *  Parameters           :  [Input, Output, Input / output]
 *    None
 *  Return               :  none
 *  Critical/explanation :  No
 **************************************************************/
#define CTRLRAM_START_SEC_CODE
#include "MemMap.h"
#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
static FUNC(uint8, CTRLRAM_CODE) bsramctl_Recovery (void)
{
    /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
    /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
    uint8 lub_ret = RECOVERY_FAIL;
    uint32 lul_CtrlRAM_Address = (uint32) rpub_CtrlRAM_Address;
    uint32 lul_CtrlRAM_Key = (uint32) &ruw_CtrlRAM_Key;
    uint32 lul_CtrlRAM_Checksum = (uint32) &ruw_CtrlRAM_Checksum;
    
    /* The value of the pointer rpub_CtrlRAM_Address must be between the starting address and 
        the ending address of the RAM area */
    /* Try to recover old data only if the address is OK */
    /* polyspace:begin<DEFECT:USELESS_IF:Not a defect:Justify with annotations> check size to avoid exception */
    /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> check size to avoid exception */
    /* polyspace:begin<CERT-C:MSC12-C:Not a defect:Justify with annotations> check size to avoid exception */
    if( (rub_CtrlRAM_DataBufSize <= cub_CtrlRAM_DataBuffer_MaxSize) && 
        (lul_CtrlRAM_Address > lul_CtrlRAM_Key) &&
        ((lul_CtrlRAM_Address + rub_CtrlRAM_DataBufSize) <= lul_CtrlRAM_Checksum) )
    /* polyspace:end<DEFECT:USELESS_IF> */
    /* polyspace:end<MISRA-C3:14.3> */
    /* polyspace:end<CERT-C:MSC12-C> */
    {
        /* Restore the old data */
        /* polyspace<RTE:STD_LIB:Not a Defect:Justify with annotations> arguments for standard library is checked */
        /* polyspace<MISRA-C3:D4.11:Not a Defect:Justify with annotations> arguments for standard library is checked */
        memcpy(rpub_CtrlRAM_Address, rub_CtrlRAM_DataBuffer, (uint16)rub_CtrlRAM_DataBufSize);

        /* Restore old checksum */
        ruw_CtrlRAM_Checksum = ruw_CtrlRAM_ChkOld;

        /* Reset Recovery Mechanism */
        rpub_CtrlRAM_Address = NULL;

        /* Check the CHK with the recovered data */
        if (bsramctl_ChkCalc() == 0xAA55u)
        {
            /* Data recovered successful */
            lub_ret = RECOVERY_OK;
        }
    }

    return (lub_ret);
    /* polyspace:end<MISRA-C3:11.4> */
    /* polyspace:end<ISO-17961:intptrconv> */
}
#endif
#define CTRLRAM_STOP_SEC_CODE
#include "MemMap.h"
/* Exported functions */
/* ------------------ */

/**************************************************************
 *  Name                 : bsramctl_verify
 *  Name                 : CtrlRam_Init
 *  TAG                  : Covers_SWR_D_MEM_02_010
 *  TAG                  : Covers_SWR_D_MEM_02_011
 *  Description          : This routine initializes the Controlled RAM area.
 *  Parameters           :  [Input, Output, Input / output]
 *    None
 *  Return               :  None
 *  Critical/explanation :  No
 **************************************************************/
#define CTRLRAM_START_SEC_CODE
#include "MemMap.h"
/* void bsramctl_verify (void) */
FUNC(void, CTRLRAM_CODE) CtrlRam_Init (void)
{
    /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
    /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
    /* Covers_SWR_D_MEM_02_011*/
    uint8 lub_Indx;
    uint16 *lpuw_PtrRamCtl;
    uint32 lul_CtrlRAM_Key = (uint32) &ruw_CtrlRAM_Key;
    uint32 lul_CtrlRAM_Checksum = (uint32) &ruw_CtrlRAM_Checksum;

    /* TAG : Covers_SWR_D_MEM_02_040 */

#if (CTRLRAM_VERIFY_AT_INIT == STD_ON)
    rub_CtrlRAM_Status = E_OK;

    /* Check Reset type */
    if ( ruw_CtrlRAM_Key == 0x55AAu)
    {
        /* WARM RESET */
        /* Check controlled RAM area */
        if (bsramctl_ChkCalc() != 0xAA55u)
        {
        #if (CTRLRAM_RECOVERY == STD_ON)
            /* Start recovery mechanism if area is damaged */
            if (bsramctl_Recovery() != RECOVERY_OK )
            {
                rub_CtrlRAM_Status = CRAM_LOST;
            }
            else
            {
                /* rub_CtrlRAM_Status is E_OK */
            }
        #else
            rub_CtrlRAM_Status = CRAM_LOST;
        #endif
        }
        else
        {
            /* rub_CtrlRAM_Status is E_OK */
        }
    }
    else
    {
        /* COLD RESET */
        rub_CtrlRAM_Status = CRAM_LOST;
    }
    /* Covers_SWR_D_MEM_02_060 */
    /* Check if Controlled RAM data initialization is needed */
    if (rub_CtrlRAM_Status != E_OK)
    {
#else
        /* COLD RESET */
        rub_CtrlRAM_Status = CRAM_LOST;
#endif  /* End of "#if (CTRLRAM_VERIFY_AT_INIT == STD_ON)" */

        /* The pointer lpuw_PtrRamCtl is used in a loop to clear the memory area. To do this the pointer is
        initialized with the starting address and compared with the ending address of the RAM area */
        /* Clear Controlled RAM memory area and checksum*/
        lpuw_PtrRamCtl = &ruw_CtrlRAM_Key;
        lul_CtrlRAM_Key = (uint32) &ruw_CtrlRAM_Key;
        lul_CtrlRAM_Checksum = (uint32) &ruw_CtrlRAM_Checksum;

        while(lul_CtrlRAM_Key <= lul_CtrlRAM_Checksum)
        {
            /* polyspace<RTE:IDP:Not a Defect:Justify with annotations> pointer is in pre-defined array size */
            /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> pointer operation has no side effects */
            *lpuw_PtrRamCtl = (uint16)0x0000;
            lpuw_PtrRamCtl++;
            lul_CtrlRAM_Key = (uint32) lpuw_PtrRamCtl;
        }

        /* Initialize Controlled RAM key */
        ruw_CtrlRAM_Key = 0x55AAu;

        /* Call application Controlled RAM area initialization routines */
        lub_Indx = 0u;
        while(cafu_ControlledRamNotify[lub_Indx] != NULL)
        {
            cafu_ControlledRamNotify[lub_Indx]();
            lub_Indx++;
        }
        /* Compute and store new checksum */
        ruw_CtrlRAM_Checksum = 0xAA55u - bsramctl_ChkCalc();

#if (CTRLRAM_VERIFY_AT_INIT == STD_ON)
    }
#endif

#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
    /* Initialize Controlled RAM - Recovered Address */
    /* Reset Recovery Mechanism */
    rpub_CtrlRAM_Address = NULL;
#endif
    /* polyspace:end<MISRA-C3:11.4> */
    /* polyspace:end<ISO-17961:intptrconv> */
}
#define CTRLRAM_STOP_SEC_CODE
#include "MemMap.h"
/**************************************************************
 *  Name                 : bsramctl_security --> CtrlRam_MainFunction
 *  TAG                  : Covers_SWR_D_MEM_02_020
 *  TAG                  : Covers_SWR_D_MEM_02_021
 *  Description          : This routine surveys the Controlled RAM area integrity.
 *                         A reset is performed in case the Controlled RAM area is
 *                         corrupted.        
 *  Parameters           :  [Input, Output, Input / output]
 *    None
 *  Return               :  none
 *  Critical/explanation :  No
 **************************************************************/
#define CTRLRAM_START_SEC_CODE
#include "MemMap.h"
/*void bsramctl_security (void)*/
FUNC(void, CTRLRAM_CODE) CtrlRam_MainFunction(void)
{
  /* Covers_SWR_D_MEM_02_021 */
  SchM_Enter_CtrlRam_SECURITY_CHECK_PROTECTION();

  /* Function bsramctl_ChkCalc() has no side effects */
  /*lint --e{960} suppress "side effects on right hand of logical operator: '||'" */
  /* polyspace:begin<MISRA-C3:13.5:Not a defect:Justify with annotations> right side operend has no side effects */
  if ((ruw_CtrlRAM_Key != 0x55AAu) || (bsramctl_ChkCalc() != 0xAA55u))
  /* polyspace:end<MISRA-C3:13.5> */
  {
    /* If the Controlled RAM area is not valid, leave the section */
    SchM_Exit_CtrlRam_SECURITY_CHECK_PROTECTION();

    /* FIXME : Modify the parameter */
    #if (CTRLRAM_DEV_ERROR_DETECT == STD_ON)
    /* polyspace:begin<MISRA-C3:17.7:Not a defect:Justify with annotations> return value has no side effects */
    Det_ReportError((uint16)CTRLRAM_MODULE_ID, (uint8)1,
      CTRLRAM_MAINFUNCTION_SID, CTRLRAM_INSTANCE_ID);
    /* polyspace:end<MISRA-C3:17.7> */
    #endif /* (CTRLRAM_DEV_ERROR_DETECT == STD_ON) */

    #if (CTRLRAM_DEMERROR_REPORT == STD_ON)
    Dem_ReportErrorStatus(CtrlRam_GusWrongState, 1);
    #endif /* (CTRLRAM_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
    SchM_Exit_CtrlRam_SECURITY_CHECK_PROTECTION();
  }

}
#define CTRLRAM_STOP_SEC_CODE
#include "MemMap.h"
/**************************************************************
 *  Name                 : bsramctl_ByteWrite
 *  TAG                  : Covers_SWR_D_MEM_02_036
 *  Description          : Controlled RAM byte update routine
 *  Parameters           :  [Input, Output, Input / output]
 *    Input: lpub_PtrByte - Pointer to the destination data byte
 *    Input: lub_Value    - New value of the byte
 *  Return               :  E_OK or E_NOT_OK
 *  Critical/explanation :  No
 **************************************************************/
#define CTRLRAM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CTRLRAM_CODE)
bsramctl_ByteWrite (uint8 *lpub_PtrByte, uint8 lub_Value)
{
    /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
    /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
    Std_ReturnType lub_ret = E_NOT_OK;
    uint32 lul_PtrByte = (uint32) lpub_PtrByte;
    uint32 lul_CtrlRAM_Key = (uint32) &ruw_CtrlRAM_Key;
    uint32 lul_CtrlRAM_Checksum = (uint32) &ruw_CtrlRAM_Checksum;
    
    /* polyspace:begin<DEFECT:USELESS_IF:Not a defect:Justify with annotations> check size to avoid exception */
    /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> check size to avoid exception */
    /* polyspace:begin<CERT-C:MSC12-C:Not a defect:Justify with annotations> check size to avoid exception */
    if( (lul_PtrByte > lul_CtrlRAM_Key) &&
        (lul_PtrByte < lul_CtrlRAM_Checksum) )
    /* polyspace:end<DEFECT:USELESS_IF> */
    /* polyspace:end<MISRA-C3:14.3> */
    /* polyspace:end<CERT-C:MSC12-C> */
    {
        /* Disable preemption Covers_SWR_D_MEM_02_061 */
    SchM_Enter_CtrlRam_WRITE_PROTECTION();
    /* ENTER_PROTECTED_SECTION(); */

        /* TAG : Covers_SWR_D_MEM_02_040 */

    #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
        /* Recovery mechanism initialization */
        ruw_CtrlRAM_ChkOld = ruw_CtrlRAM_Checksum;
        rub_CtrlRAM_DataBuffer[0] = *lpub_PtrByte;
        rub_CtrlRAM_DataBufSize = 1u;
        rpub_CtrlRAM_Address = lpub_PtrByte;
    #endif
        /* Bitwise and is done to check byte or word alignment */
        /*lint --e{923} suppress "cast from pointer to unsigned char" */
        /*lint --e{507} suppress "Size incompatibility, converting 4 byte pointer to 1 byte integral" */
        /* Update checksum */
  /* polyspace:begin<MISRA-C3:10.8:Not a defect:Justify with annotations> type conversion is not affected the result */
  /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
  #if (CTRLRAM_PLATFORM_ARCHITECTURE == LITTLE_ENDIAN_PLATFORM)
    #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
        if ( ((uint32)rpub_CtrlRAM_Address & (uint8)0x01) == (uint8)0x01 )
    #else  
        if ( ((uint32)lpub_PtrByte & (uint8)0x01) == (uint8)0x01 )
    #endif
    #else
    #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
        if ( ((uint32)rpub_CtrlRAM_Address & (uint8)0x01) != (uint8)0x01 )
    #else  
        if ( ((uint32)lpub_PtrByte & (uint8)0x01) != (uint8)0x01 )
    #endif
    #endif
        {
            ruw_CtrlRAM_Checksum = ruw_CtrlRAM_Checksum +
                    ((uint16)((uint8)((*lpub_PtrByte) - lub_Value)) << 8);
        }
        else
        {
            ruw_CtrlRAM_Checksum = ruw_CtrlRAM_Checksum + 
                    (uint16)((*lpub_PtrByte) - lub_Value);
        }
        /* polyspace:end<MISRA-C3:10.8> */
        /* polyspace:end<MISRA-C3:11.4> */
        /* polyspace:end<ISO-17961:intptrconv> */

        /* Update data */
        *lpub_PtrByte = lub_Value;

    #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
        /* Reset recovery mechanism */
        rpub_CtrlRAM_Address = NULL;
    #endif

    SchM_Exit_CtrlRam_WRITE_PROTECTION();
    /* LEAVE_PROTECTED_SECTION(); */
        
        lub_ret = E_OK;
    }

    return(lub_ret);
    /* polyspace:end<MISRA-C3:11.4> */
    /* polyspace:end<ISO-17961:intptrconv> */
}
#define CTRLRAM_STOP_SEC_CODE
#include "MemMap.h"
/**************************************************************
 *  Name                 : bsramctl_WordWrite
 *  TAG                  : Covers_SWR_D_MEM_02_037
 *  Description          : Controlled RAM word update routine
 *  Parameters           :  [Input, Output, Input / output]
 *    Input: lpuw_PtrWord - Pointer to the destination data word
 *    Input: luw_Value  - New value of the word
 *  Return               :  E_OK or E_NOT_OK
 *  Critical/explanation :  No
 **************************************************************/
#define CTRLRAM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CTRLRAM_CODE)
bsramctl_WordWrite (uint16 * lpuw_PtrWord, uint16 luw_Value)
{
    /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
    /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
    uint8 *lpub_SrcPtr;
    Std_ReturnType lub_ret = E_NOT_OK;
    uint32 lul_PtrWord = (uint32) lpuw_PtrWord;
    uint32 lul_PtrWord_plus_1 = (uint32) (lpuw_PtrWord + 1u);
    uint32 lul_CtrlRAM_Key = (uint32) &ruw_CtrlRAM_Key;
    uint32 lul_CtrlRAM_Checksum = (uint32) &ruw_CtrlRAM_Checksum;

#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
    /* polyspace:begin<DEFECT:USELESS_IF:Not a defect:Justify with annotations> check size to avoid exception */
    /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> check size to avoid exception */
    /* polyspace:begin<CERT-C:MSC12-C:Not a defect:Justify with annotations> check size to avoid exception */
    if(cub_CtrlRAM_DataBuffer_MaxSize >= 2u)
    /* polyspace:end<DEFECT:USELESS_IF> */
    /* polyspace:end<MISRA-C3:14.3> */
    /* polyspace:end<CERT-C:MSC12-C> */
    {
#endif
        /* polyspace:begin<DEFECT:USELESS_IF:Not a defect:Justify with annotations> check size to avoid exception */
        /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> check size to avoid exception */
        /* polyspace:begin<CERT-C:MSC12-C:Not a defect:Justify with annotations> check size to avoid exception */
        if( (lul_PtrWord > lul_CtrlRAM_Key) &&
            (lul_PtrWord_plus_1 <= lul_CtrlRAM_Checksum) )
        /* polyspace:end<DEFECT:USELESS_IF> */
        /* polyspace:end<MISRA-C3:14.3> */
        /* polyspace:end<CERT-C:MSC12-C> */
        {
            /* Disable preemption Covers_SWR_D_MEM_02_061*/
      SchM_Enter_CtrlRam_WRITE_PROTECTION();
      /* ENTER_PROTECTED_SECTION(); */

            /* TAG  : Covers_SWR_D_MEM_02_040 */
            lpub_SrcPtr = (uint8 *)lpuw_PtrWord;

        #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
            /* Recovery mechanism initialization */
            ruw_CtrlRAM_ChkOld = ruw_CtrlRAM_Checksum;

            /* The size of rub_CtrlRAM_DataBuffer array is 4 bytes */
            /*lint --e{826} suppress "Suspicious pointer-to-pointer conversion (area too small)" for complete block */
            /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
            /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
            if ( ((uint32)lpub_SrcPtr & (uint8)0x01) == (uint8)0x01 )
            /* polyspace:end<MISRA-C3:11.4> */
            /* polyspace:end<ISO-17961:intptrconv> */
            {
      /* polyspace:begin<MISRA-C3:10.8:Not a defect:Justify with annotations> type conversion is not affected the result */
      /* polyspace:begin<MISRA-C3:11.3:Not a defect:Justify with annotations> type casting is not affected the result */
      /* polyspace:begin<MISRA-C3:12.2:Not a defect:Justify with annotations> shift operation result is in pre-defined size */
      #if (CTRLRAM_PLATFORM_ARCHITECTURE == LITTLE_ENDIAN_PLATFORM)
                *(rub_CtrlRAM_DataBuffer + 0) = (*(lpub_SrcPtr + 0));
                *(rub_CtrlRAM_DataBuffer + 1) = (*(lpub_SrcPtr + 1));
            #else
                *(rub_CtrlRAM_DataBuffer + 0) = (*(lpub_SrcPtr + 1));
                *(rub_CtrlRAM_DataBuffer + 1) = (*(lpub_SrcPtr + 0));
            #endif
            /* polyspace:end<MISRA-C3:10.8> */
            /* polyspace:end<MISRA-C3:11.3> */
            /* polyspace:end<MISRA-C3:12.2> */
            }
            else
            {
                memcpy((uint8*) rub_CtrlRAM_DataBuffer, (uint8*) lpuw_PtrWord, 2u);
            }

            rub_CtrlRAM_DataBufSize = 2u;
            rpub_CtrlRAM_Address = (uint8 *)lpuw_PtrWord;
        #endif

            /* Bitwise and is done to check byte or word alignment */
            /*lint --e{923} suppress "cast from pointer to unsigned char" */
            /*lint --e{507} suppress "Size incompatibility, converting 4 byte pointer to 1 byte integral" */
            /* Update checksum */
        /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
        /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
        #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
            if ( ((uint32)rpub_CtrlRAM_Address & (uint8)0x01) == (uint8)0x01 )
        #else  
            if ( ((uint32)lpuw_PtrWord & (uint8)0x01) == (uint8)0x01 )
        #endif
        /* polyspace:end<MISRA-C3:11.4> */
        /* polyspace:end<ISO-17961:intptrconv> */
            {
      /* polyspace:begin<MISRA-C3:10.8:Not a defect:Justify with annotations> type conversion is not affected the result */
      /* polyspace:begin<MISRA-C3:12.2:Not a defect:Justify with annotations> shift operation result is in pre-defined size */
      #if (CTRLRAM_PLATFORM_ARCHITECTURE == LITTLE_ENDIAN_PLATFORM)
                ruw_CtrlRAM_Checksum = ruw_CtrlRAM_Checksum \
                        + ( ((uint16)((*lpub_SrcPtr) << 8) + (uint16)((uint8)(*(lpub_SrcPtr + 1)))) \
                        - ((uint16)(luw_Value << 8) + (uint16)((uint8)(luw_Value >> 8))) );
                *lpub_SrcPtr = (uint8)luw_Value;
                *(lpub_SrcPtr + 1) = (uint8)(luw_Value >> 8);
            #else
                ruw_CtrlRAM_Checksum = ruw_CtrlRAM_Checksum \
                        + ( ((uint16)(*(lpub_SrcPtr + 1)) << 8) + (uint16)((uint8)(*lpub_SrcPtr))) \
                        - ((uint16)(luw_Value << 8) + (uint16)((uint8)(luw_Value >> 8)));
                *lpub_SrcPtr = (uint8)(luw_Value >> 8);
                *(lpub_SrcPtr + 1) = (uint8)luw_Value;
            #endif  /* End of  #if (CTRLRAM_PLATFORM_ARCHITECTURE == LITTLE_ENDIAN_PLATFORM) */
            /* polyspace:end<MISRA-C3:10.8> */
            /* polyspace:end<MISRA-C3:12.2> */
            }
            else
            {
                ruw_CtrlRAM_Checksum = ruw_CtrlRAM_Checksum + (uint16)((*lpuw_PtrWord) - luw_Value);
                /* Update data */
                *lpuw_PtrWord = luw_Value;
            }

            /* Reset recovery mechanism */
        #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
            rpub_CtrlRAM_Address = NULL;
        #endif

      SchM_Exit_CtrlRam_WRITE_PROTECTION();
            /* LEAVE_PROTECTED_SECTION(); */

            lub_ret = E_OK;
        }

#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
    }
#endif

    return(lub_ret);
    /* polyspace:end<MISRA-C3:11.4> */
    /* polyspace:end<ISO-17961:intptrconv> */
}
#define CTRLRAM_STOP_SEC_CODE
#include "MemMap.h"
/**************************************************************
 *  Name                 : bsramctl_LongWrite
 *  TAG                  : Covers_SWR_D_MEM_02_038
 *  Description          : Controlled RAM long update routine
 *  Parameters           :  [Input, Output, Input / output]
 *    Input: lpul_PtrLong - Pointer to the destination data long
 *    Input: lul_Value    - New value of the long
 *  Return               :  E_OK or E_NOT_OK
 *  Critical/explanation :  No
 **************************************************************/
#define CTRLRAM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CTRLRAM_CODE)
bsramctl_LongWrite (uint32 * lpul_PtrLong, uint32 lul_Value)
{
    /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
    /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
    uint8 *lpub_SrcPtr;
    Std_ReturnType lub_ret = E_NOT_OK;
    uint32 lul_PtrLong = (uint32) lpul_PtrLong;
    uint32 lul_PtrLong_plus_1 = (uint32) (lpul_PtrLong + 1u);
    uint32 lul_CtrlRAM_Key = (uint32) &ruw_CtrlRAM_Key;
    uint32 lul_CtrlRAM_Checksum = (uint32) &ruw_CtrlRAM_Checksum;

#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
    /* polyspace:begin<DEFECT:USELESS_IF:Not a defect:Justify with annotations> check size to avoid exception */
    /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> check size to avoid exception */
    /* polyspace:begin<CERT-C:MSC12-C:Not a defect:Justify with annotations> check size to avoid exception */
    if(cub_CtrlRAM_DataBuffer_MaxSize >= 4u)
    /* polyspace:end<DEFECT:USELESS_IF> */
    /* polyspace:end<MISRA-C3:14.3> */
    /* polyspace:end<CERT-C:MSC12-C> */
    {
#endif
        /* polyspace:begin<DEFECT:USELESS_IF:Not a defect:Justify with annotations> check size to avoid exception */
        /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> check size to avoid exception */
        /* polyspace:begin<CERT-C:MSC12-C:Not a defect:Justify with annotations> check size to avoid exception */
        /* polyspace:begin<MISRA-C3:11.3:Not a defect:Justify with annotations> type casting is not affected the result */
        if( (lul_PtrLong > lul_CtrlRAM_Key ) &&
            (lul_PtrLong_plus_1 <= lul_CtrlRAM_Checksum) )
        /* polyspace:end<DEFECT:USELESS_IF> */
        /* polyspace:end<MISRA-C3:14.3> */
        /* polyspace:end<CERT-C:MSC12-C> */
        /* polyspace:end<MISRA-C3:11.3> */
        {
            /* Disable preemption Covers_SWR_D_MEM_02_061 */
          SchM_Enter_CtrlRam_WRITE_PROTECTION();
          /* ENTER_PROTECTED_SECTION(); */

            /* TAG  : Covers_SWR_D_MEM_02_040 */
            lpub_SrcPtr = (uint8 *)lpul_PtrLong;

        #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
            /* Recovery mechanism initialization */
            ruw_CtrlRAM_ChkOld = ruw_CtrlRAM_Checksum;

            /* The size of rub_CtrlRAM_DataBuffer array is 4 bytes */
            /*lint --e{826} suppress "Suspicious pointer-to-pointer conversion (area too small)" for complete block*/
            /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
            /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
            if ( ((uint32)lpub_SrcPtr & (uint8)0x01) == (uint8)0x01 )
            /* polyspace:end<MISRA-C3:11.4> */
            /* polyspace:end<ISO-17961:intptrconv> */
            {
              /* polyspace:begin<RTE:OVFL:Not a Defect:Justify with annotations> operation result is in pre-defined size */
              /* polyspace:begin<MISRA-C3:10.8:Not a defect:Justify with annotations> type conversion is not affected the result */
              /* polyspace:begin<MISRA-C3:11.3:Not a defect:Justify with annotations> type casting is not affected the result */
              /* polyspace:begin<MISRA-C3:12.2:Not a defect:Justify with annotations> shift operation result is in pre-defined size */
              #if (CTRLRAM_PLATFORM_ARCHITECTURE == LITTLE_ENDIAN_PLATFORM)
                *(rub_CtrlRAM_DataBuffer + 0) = (*(lpub_SrcPtr + 0));
                *(rub_CtrlRAM_DataBuffer + 1) = (*(lpub_SrcPtr + 1));
                *(rub_CtrlRAM_DataBuffer + 2) = (*(lpub_SrcPtr + 2));
                *(rub_CtrlRAM_DataBuffer + 3) = (*(lpub_SrcPtr + 3));
              #else
                *(rub_CtrlRAM_DataBuffer + 0) = (*(lpub_SrcPtr + 3));
                *(rub_CtrlRAM_DataBuffer + 1) = (*(lpub_SrcPtr + 2));
                *(rub_CtrlRAM_DataBuffer + 2) = (*(lpub_SrcPtr + 1));
                *(rub_CtrlRAM_DataBuffer + 3) = (*(lpub_SrcPtr + 0));
              #endif
              /* polyspace:end<RTE:OVFL> */
              /* polyspace:end<MISRA-C3:10.8> */
              /* polyspace:end<MISRA-C3:11.3> */
              /* polyspace:end<MISRA-C3:12.2> */
            }
            else
            {
                memcpy((uint8*) rub_CtrlRAM_DataBuffer, (uint8*) lpul_PtrLong, 4u);
            }
            rub_CtrlRAM_DataBufSize = 4u;
            rpub_CtrlRAM_Address = (uint8 *)lpul_PtrLong;
        #endif  /* End of "#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))" */

            /* Bitwise and is done to check byte or word alignment */
            /*lint --e{923} suppress "cast from pointer to unsigned char" */
            /*lint --e{507} suppress "Size incompatibility, converting 4 byte pointer to 1 byte integral" */
            /* The long values are shifted in order to obtain the values to calculate the CRAM checksum */
            /*lint --e{572} suppress "Excessive shift value (precision 16 shifted right by 24) [MISRA Rule 38]"*/
        /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
        /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
        #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
            if ( ((uint32)rpub_CtrlRAM_Address & (uint8)0x01) == (uint8)0x01 )
        #else
            if ( ((uint32)lpul_PtrLong & (uint8)0x01) == (uint8)0x01 )
        #endif
        /* polyspace:end<MISRA-C3:11.4> */
        /* polyspace:end<ISO-17961:intptrconv> */
            {
        /* polyspace:begin<MISRA-C3:10.8:Not a defect:Justify with annotations> type conversion is not affected the result */
        /* polyspace:begin<MISRA-C3:11.3:Not a defect:Justify with annotations> type conversion is not affected the result */
        /* polyspace:begin<MISRA-C3:12.2:Not a defect:Justify with annotations> shift operation result is in pre-defined size */
        #if (CTRLRAM_PLATFORM_ARCHITECTURE == LITTLE_ENDIAN_PLATFORM)
                ruw_CtrlRAM_Checksum = ruw_CtrlRAM_Checksum \
                        + ( ((uint16)((*lpub_SrcPtr) << 8) + (uint16)((uint8)(*(lpub_SrcPtr + 3))) \
                                + (uint16)(*(lpub_SrcPtr + 2))) \
                        - ((uint16)(lul_Value << 8) + (uint16)(lul_Value >> 8) \
                                + (uint16)((uint8)(lul_Value >> 24))) );
                *lpub_SrcPtr = (uint8)(lul_Value);
                *(lpub_SrcPtr + 1u) = (uint8)(lul_Value >> 8);
                *(lpub_SrcPtr + 2u) = (uint8)(lul_Value >> 16);
                *(lpub_SrcPtr + 3u) = (uint8)(lul_Value >> 24);
            #else
                ruw_CtrlRAM_Checksum = ruw_CtrlRAM_Checksum \
                        + ( (((uint16)(*(lpub_SrcPtr + 3)) << 8) + (uint16)((uint8)(*lpub_SrcPtr)) \
                                + (uint16)(*(lpub_SrcPtr + 2))) \
                        - ((uint16)(lul_Value << 8) + (uint16)(lul_Value >> 8) \
                                + (uint16)((uint8)(lul_Value >> 24))) );
                *lpub_SrcPtr = (uint8)(lul_Value >> 24);
                *(lpub_SrcPtr + 1) = (uint8)(lul_Value >> 16);
                *(lpub_SrcPtr + 2) = (uint8)(lul_Value >> 8);
                *(lpub_SrcPtr + 3) = (uint8)(lul_Value);
            #endif  /* End of "#if (CTRLRAM_PLATFORM_ARCHITECTURE == LITTLE_ENDIAN_PLATFORM) */
            /* polyspace:end<MISRA-C3:10.8> */
            /* polyspace:end<MISRA-C3:11.3> */
            /* polyspace:end<MISRA-C3:12.2> */
            }
            else
            {
                ruw_CtrlRAM_Checksum = ruw_CtrlRAM_Checksum \
                        + ( ((uint16 )(*lpul_PtrLong) + (uint16)((*lpul_PtrLong) >> 16)) \
                        - ((uint16)lul_Value + (uint16)(lul_Value >> 16)) );
                /* Update data */
                *lpul_PtrLong = lul_Value;
            }

        #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
            /* Reset recovery mechanism */
            rpub_CtrlRAM_Address = NULL;
        #endif

      SchM_Exit_CtrlRam_WRITE_PROTECTION();
      /* LEAVE_PROTECTED_SECTION(); */

      lub_ret = E_OK;
        }

#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
    }
#endif

    return(lub_ret);
    /* polyspace:end<MISRA-C3:11.4> */
    /* polyspace:end<ISO-17961:intptrconv> */
}
#define CTRLRAM_STOP_SEC_CODE
#include "MemMap.h"
/**************************************************************
 *  Name                 : bsramctl_StructWrite
 *  TAG                  : Covers_SWR_D_MEM_02_039
 *  Description          : Controlled RAM long update routine
 *  Parameters           :  [Input, Output, Input / output]
 *    Input: lpub_Struct - Pointer to the destination structure
 *    Input: lpub_Src    - Pointer to the source data 
 *    Input: lub_Size    - Structure size
 *  Return               :  E_OK or E_NOT_OK
 *  Critical/explanation :  No
 **************************************************************/
#define CTRLRAM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CTRLRAM_CODE)
bsramctl_StructWrite (uint8 * lpub_Struct, const uint8 * lpub_Src, uint8 lub_Size)
{
    /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
    /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
    const uint8 check_lub_Size = 2u;
    uint16 luw_Chk;
    Std_ReturnType lub_ret = E_NOT_OK;
    uint32 lul_PtrStruct = (uint32) lpub_Struct;
    uint32 lul_PtrStruct_plus_Size = (uint32) (lpub_Struct + lub_Size);
    uint32 lul_CtrlRAM_Key = (uint32) &ruw_CtrlRAM_Key;
    uint32 lul_CtrlRAM_Checksum = (uint32) &ruw_CtrlRAM_Checksum;

#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
    if(cub_CtrlRAM_DataBuffer_MaxSize >= lub_Size)
    {
#endif
        /* polyspace:begin<DEFECT:USELESS_IF:Not a defect:Justify with annotations> check size to avoid exception */
        /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> check size to avoid exception */
        /* polyspace:begin<CERT-C:MSC12-C:Not a defect:Justify with annotations> check size to avoid exception */
        if( (lul_PtrStruct > lul_CtrlRAM_Key) &&
            (lul_PtrStruct_plus_Size <= lul_CtrlRAM_Checksum) )
        /* polyspace:end<DEFECT:USELESS_IF> */
        /* polyspace:end<MISRA-C3:14.3> */
        /* polyspace:end<CERT-C:MSC12-C> */
        {
            /* Disable preemption Covers_SWR_D_MEM_02_061*/
            /* GetResource (RES_SCHEDULER); */
        SchM_Enter_CtrlRam_STRUCT_WRITE_PROTECTION();

            /*  TAG  : Covers_SWR_D_MEM_02_040   */

        #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
            /* Recovery mechanism initialization */
            ruw_CtrlRAM_ChkOld = ruw_CtrlRAM_Checksum;
            memcpy(rub_CtrlRAM_DataBuffer, lpub_Struct, (uint16)lub_Size);
            rub_CtrlRAM_DataBufSize = lub_Size;
            rpub_CtrlRAM_Address = lpub_Struct;
        #endif

            luw_Chk = ruw_CtrlRAM_Checksum;

            /* Bitwise and is done to check byte or word alignment */
            /*lint --e{923} suppress "cast from pointer to unsigned char" */
            /*lint --e{507} suppress "Size incompatibility, converting 4 byte pointer to 1 byte integral" */
            /* Check first byte is byte alignment */
        /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> type casting is not affected the result */
        /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> type casting is not affected the result */
        #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
            if (((uint32)rpub_CtrlRAM_Address & (uint8)0x01) != (uint8)0x00)
        #else  
            if (((uint32)lpub_Struct & (uint8)0x01) != (uint8)0x00)
        #endif
        /* polyspace:end<MISRA-C3:11.4> */
        /* polyspace:end<ISO-17961:intptrconv> */
            {
      /* polyspace:begin<MISRA-C3:10.8:Not a defect:Justify with annotations> type conversion is not affected the result */
      #if (CTRLRAM_PLATFORM_ARCHITECTURE == LITTLE_ENDIAN_PLATFORM)
              luw_Chk += ((uint16)((uint8)(*lpub_Struct - *lpub_Src)) << 8);
            #else
                luw_Chk += (uint16)(*lpub_Struct - *lpub_Src);
            #endif
            /* polyspace:end<MISRA-C3:10.8> */
                /* polyspace:begin<MISRA-C3:17.8:Not a defect:Justify with annotations> function parameter has no side effects */
                *lpub_Struct = *lpub_Src;
                lpub_Struct++;
                lpub_Src++;
                lub_Size--;
                /* polyspace:end<MISRA-C3:17.8> */
            }

            /* Update data and compute checksum */
            while (lub_Size >= check_lub_Size)
            {
                /* Source and destination memory areas size is checked to be higher or equal to 2 */
                /*lint --e{826} suppress "Suspicious pointer-to-pointer conversion (area too small)" for complete block*/
                /* INFINEON_XC2K can generate the Illegal word Access TRAP error */
                /* RENESAS_RH850 can generate the Illegal word Access MAE error */
                /* Above operation is changed from WORD into BYTE operation  */
              /* polyspace:begin<RTE:SHF:Not a Defect:Justify with annotations> shift operation is in pre-defined type size */
              /* polyspace:begin<MISRA-C3:10.8:Not a defect:Justify with annotations> type conversion is not affected the result */
              /* polyspace:begin<MISRA-C3:9.1:Not a defect:Justify with annotations> type conversion is not affected the result */
              #if (CTRLRAM_PLATFORM_ARCHITECTURE == LITTLE_ENDIAN_PLATFORM)
              luw_Chk +=(uint16) ((*lpub_Struct - *lpub_Src)  + ((*(lpub_Struct + 1) - *(lpub_Src + 1)) << 8));
                *lpub_Struct = *lpub_Src;
                *(lpub_Struct + 1) = *(lpub_Src + 1);
              #else
                luw_Chk +=(uint16) (((*lpub_Struct - *lpub_Src) << 8) + (*(lpub_Struct + 1) - *(lpub_Src + 1)));
                *lpub_Struct = *lpub_Src;
                *(lpub_Struct + 1) = *(lpub_Src + 1);
              #endif
              /* polyspace:end<RTE:SHF> */
              /* polyspace:end<MISRA-C3:10.8> */
              /* polyspace:end<MISRA-C3:9.1> */

                /* polyspace:begin<MISRA-C3:17.8:Not a defect:Justify with annotations> function parameter has no side effects */
                lpub_Struct += 2u;
                lpub_Src += 2u;
                lub_Size -= 2u;
                /* polyspace:end<MISRA-C3:17.8> */
            }
            
            /* Check if last struct byte is word aligned*/
            if (lub_Size != 0u)
            {
            /* polyspace:begin<MISRA-C3:10.7:Not a defect:Justify with annotations> type conversion is not affected the result */
            /* polyspace:begin<MISRA-C3:10.8:Not a defect:Justify with annotations> type conversion is not affected the result */
            /* polyspace:begin<MISRA-C3:9.1:Not a defect:Justify with annotations> type conversion is not affected the result */
            #if (CTRLRAM_PLATFORM_ARCHITECTURE == LITTLE_ENDIAN_PLATFORM)
                luw_Chk += *lpub_Struct - *lpub_Src;
            #else
                luw_Chk += (uint16)((*lpub_Struct - *lpub_Src)<<8);
            #endif
            /* polyspace:end<MISRA-C3:10.7> */
            /* polyspace:end<MISRA-C3:10.8> */
            /* polyspace:end<MISRA-C3:9.1> */
                *lpub_Struct = *lpub_Src;
            }

            /* Validate storage */
            ruw_CtrlRAM_Checksum = luw_Chk;

        #if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
            /* Reset recovery mechanism */
            rpub_CtrlRAM_Address = NULL;
        #endif

            /*ReleaseResource (RES_SCHEDULER); */
        SchM_Exit_CtrlRam_STRUCT_WRITE_PROTECTION();

            lub_ret = E_OK;
        }

#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
    }
#endif

    return(lub_ret);
    /* polyspace:end<MISRA-C3:11.4> */
    /* polyspace:end<ISO-17961:intptrconv> */
}
#define CTRLRAM_STOP_SEC_CODE
#include "MemMap.h"


/**************************************************************
 *  Name                 : Ctrlram_GetStatus
 *  TAG                  : Covers_SWR_D_MEM_02_035
 *  TAG                  : Covers_SWR_D_MEM_02_041
**************************************************************/

#define CTRLRAM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CTRLRAM_CODE) Ctrlram_GetStatus
    (P2VAR(CtrlRam_StatusType, AUTOMATIC , CTRLRAM_APPL_DATA) StatusPtr)
{
    Std_ReturnType LddReturnValue;
    LddReturnValue = E_OK;

    /* If passed pointer is NULL, report error to DET */
    if(StatusPtr == NULL_PTR)
    {
      #if (CTRLRAM_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError((uint16)CTRLRAM_MODULE_ID, (uint8)1,
      CTRLRAM_GETSTATUS_SID, CTRLRAM_INSTANCE_ID);
      #endif /* (CTRLRAM_DEV_ERROR_DETECT == STD_ON) */
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      *StatusPtr = rub_CtrlRAM_Status;
    }
    
     return(LddReturnValue);
}
#define CTRLRAM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace:end<RTE : UNR> */
/* polyspace:end<MISRA-C3:18.4> */
/* polyspace:end<DEFECT:PTR_TO_DIFF_ARRAY> */
/* polyspace:end<MISRA-C3:D4.14> */
/* polyspace:end<MISRA-C3:18.3> */

