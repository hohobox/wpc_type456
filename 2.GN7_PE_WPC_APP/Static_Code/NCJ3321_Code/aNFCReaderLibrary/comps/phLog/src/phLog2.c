/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020-2023
 * All rights reserved.
 *
 * Disclaimer
 * 1. The NXP Software/Source Code is provided to Licensee "AS IS" without any warranties of any kind.
 * NXP makes no warranties to Licensee and shall not indemnify Licensee or hold it harmless for any
 * reason related to the NXP Software/Source Code or otherwise be liable to the NXP customer. The NXP
 * customer acknowledges and agrees that the NXP Software/Source Code is provided AS-IS and accepts
 * all risks of utilizing the NXP Software under the conditions set forth according to this disclaimer.
 *
 * 2. NXP EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT OF
 * INTELLECTUAL PROPERTY RIGHTS. NXP SHALL HAVE NO LIABILITY TO THE NXP CUSTOMER, OR ITS
 * SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY FOR ANY DAMAGES, INCLUDING WITHOUT LIMITATION,
 * DAMAGES RESULTING OR ALLEGED TO HAVE RESULTED FROM ANY DEFECT, ERROR OR OMISSION IN THE NXP
 * SOFTWARE/SOURCE CODE, THIRD PARTY APPLICATION SOFTWARE AND/OR DOCUMENTATION, OR AS A RESULT OF ANY
 * INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHT OF ANY THIRD PARTY. IN NO EVENT SHALL NXP BE LIABLE
 * FOR ANY INCIDENTAL, INDIRECT, SPECIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL DAMAGES (INCLUDING
 * LOST PROFITS) SUFFERED BY NXP CUSTOMER OR ITS SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY
 * ARISING OUT OF OR RELATED TO THE NXP SOFTWARE/SOURCE CODE EVEN IF NXP HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 *
 * 3. NXP reserves the right to make changes to the NXP Software/Source code any time, also without
 * informing customer.
 *
 * 4. Licensee agrees to indemnify and hold harmless NXP and its affiliated companies from and against
 * any claims, suits, losses, damages, liabilities, costs and expenses (including reasonable
 * attorney's fees) resulting from Licensee's and/or Licensee customer's/licensee's use of the NXP
 * Software/Source Code.
 *******************************************************************************/
 /**
*   @file    phLog2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Log - API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phLog Log
*   @ingroup phcommon
*   @{
*/
/*==================================================================================================
*   Project              : Anfc Reader Library
*   Platform             : ARM
*   Peripheral           : NCX3320
*   Dependencies         : Driver modules
*
*   Build Version        : S32K14X_S32K144_ANFC_Reader_Lib_1_0_20240401
*
*   Copyright 2016-2023 NXP
*
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include <ph_Status2.h>

#ifdef NXPBUILD__PH_LOG2
#include <ph_RefDefs2.h>
#include "phLog_Int2.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phLog2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHLOG_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHLOG_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHLOG_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHLOG_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHLOG_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHLOG_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHLOG_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phLog.h header file are of the same vendor */
#if (PHLOG_VENDOR_ID_C2 != PHLOG_VENDOR_ID2)
    #error "phLog2.c and phLog.h have different vendor ids"
#endif
/* Check if current file and phLog.h header file are of the same Autosar version */
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C2    != PHLOG_AR_RELEASE_MAJOR_VERSION2) || \
     (PHLOG_AR_RELEASE_MINOR_VERSION_C2    != PHLOG_AR_RELEASE_MINOR_VERSION2) || \
     (PHLOG_AR_RELEASE_REVISION_VERSION_C2 != PHLOG_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phLog2.c and phLog.h are different"
#endif
/* Check if current file and phLog.h header file are of the same Software version */
#if ((PHLOG_SW_MAJOR_VERSION_C2 != PHLOG_SW_MAJOR_VERSION2) || \
     (PHLOG_SW_MINOR_VERSION_C2 != PHLOG_SW_MINOR_VERSION2) || \
     (PHLOG_SW_PATCH_VERSION_C2 != PHLOG_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phLog2.c and phLog.h are different"
#endif
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG2

#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) PH_MEMLOC_CONST_ROM2 gpkphLog_String_BufferOverflow2 = "OVERFLOW2";

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_LOG2 */
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG2

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(phLog_DataParams_t2, ANFCRL_VAR) PH_MEMLOC_REM2 gphLog_LogDataParams2 = {NULL, NULL, 0U, 0U};

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_LOG2 */
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG_EX2

#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

VAR(ppLogEx_FmtToStr_t2, ANFCRL_VAR) pLogEx_Sprintf2;
VAR(ppLogEx_SendLog_t2, ANFCRL_VAR) pLogEx_SendLog2;
VAR(char, ANFCRL_VAR) pLogExMsg2[256*3];

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_LOG_EX2 */
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG2
#define ANFCRL_START_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
FUNC(phStatus_t2, ANFCRL_CODE) phLog_Init2(
                      VAR(pphLog_Callback_t2, ANFCRL_VAR) pLogCallback2,
                      P2VAR(phLog_RegisterEntry_t2, AUTOMATIC, ANFCRL_APPL_DATA) pRegisterEntries2,
                      VAR(uint16, ANFCRL_VAR) wMaxRegisterEntries2
                      )
{
    /* Check parameters */
    if (pLogCallback2 != NULL)
    {
        if (wMaxRegisterEntries2 == 0U)
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_LOG2);
        }
        if (pRegisterEntries2 == NULL)
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_LOG2);
        }
    }

    gphLog_LogDataParams2.pLogCallback2           = pLogCallback2;
    gphLog_LogDataParams2.pRegisterEntries2       = pRegisterEntries2;
    gphLog_LogDataParams2.wNumRegisterEntries2    = 0;
    gphLog_LogDataParams2.wMaxRegisterEntries2    = wMaxRegisterEntries2;

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phLog_Register2(
                          P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                          P2VAR(phLog_LogEntry_t2, AUTOMATIC, ANFCRL_APPL_DATA) pLogEntries2,
                          VAR(uint16, ANFCRL_VAR) wMaxLogEntries2
                          )
{
    /* Parameter check */
    if ((pDataParams2 == NULL) || (pLogEntries2 == NULL) || (wMaxLogEntries2 == 0U))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_LOG2);
    }

    /* Logging has to be initialized */
    if (gphLog_LogDataParams2.pLogCallback2 == NULL)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_LOG2);
    }

    /* Check for buffer overflow */
    if (gphLog_LogDataParams2.wMaxRegisterEntries2 < (gphLog_LogDataParams2.wNumRegisterEntries2 + 1U))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_LOG2);
    }

    /* Add Register Entry */
    gphLog_LogDataParams2.pRegisterEntries2[gphLog_LogDataParams2.wNumRegisterEntries2].pDataParams2 = pDataParams2;
    gphLog_LogDataParams2.pRegisterEntries2[gphLog_LogDataParams2.wNumRegisterEntries2].pLogEntries2 = pLogEntries2;
    gphLog_LogDataParams2.pRegisterEntries2[gphLog_LogDataParams2.wNumRegisterEntries2].wNumLogEntries2 = 0;
    gphLog_LogDataParams2.pRegisterEntries2[gphLog_LogDataParams2.wNumRegisterEntries2].wMaxLogEntries2 = wMaxLogEntries2;

    /* Increment number of registered entry pairs */
    ++gphLog_LogDataParams2.wNumRegisterEntries2;

    return PH_ERR_SUCCESS2;
}

FUNC(void, ANFCRL_CODE) phLog_AddString2(
                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                     VAR(uint8, ANFCRL_VAR) bLogType2,
                     P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pString2
                     )
{
    phLog_AddParam_Raw2(pDataParams2, bLogType2, pString2, NULL, 0, PH_LOG_DATATYPE_BUFFER2);
}

FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint82(
                          P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                          VAR(uint8, ANFCRL_VAR) bLogType2,
                          P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName2,
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pParam2
                          )
{
    phLog_AddParam_Raw2(pDataParams2, bLogType2, pName2, pParam2, (uint16)sizeof(uint8), PH_LOG_DATATYPE_VALUE2);
}

FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint162(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                           VAR(uint8, ANFCRL_VAR) bLogType2,
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName2,
                           P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pParam2
                           )
{
    phLog_AddParam_Raw2(pDataParams2, bLogType2, pName2, pParam2, (uint16)sizeof(uint16), PH_LOG_DATATYPE_VALUE2);
}

FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint322(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                           VAR(uint8, ANFCRL_VAR) bLogType2,
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName2,
                           P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pParam2
                           )
{
    phLog_AddParam_Raw2(pDataParams2, bLogType2, pName2, pParam2, (uint16)sizeof(uint32), PH_LOG_DATATYPE_VALUE2);
}

FUNC(void, ANFCRL_CODE) phLog_AddParam_Buffer2(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                           VAR(uint8, ANFCRL_VAR) bLogType2,
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName2,
                           P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) pParam2,
                           VAR(uint16, ANFCRL_VAR) wLength2
                           )
{
    phLog_AddParam_Raw2(pDataParams2, bLogType2, pName2, pParam2, wLength2, PH_LOG_DATATYPE_BUFFER2);
}

FUNC(void, ANFCRL_CODE) phLog_Execute2(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                   VAR(uint8, ANFCRL_VAR) bOption2
                   )
{
    P2VAR(phLog_RegisterEntry_t2, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRegisterEntry2 = NULL;

    /* Don't do anything if no callback has been registered */
    if (gphLog_LogDataParams2.pLogCallback2 == NULL)
    {
        return;
    }

    /* Retrieve corresponding Register Entry */
    pRegisterEntry2 = phLog_GetRegisteredEntry2(pDataParams2);
    if (pRegisterEntry2 == NULL)
    {
        return;
    }

    /* Invoke the external callback */
    (*(gphLog_LogDataParams2.pLogCallback2))(pDataParams2, bOption2, pRegisterEntry2->pLogEntries2, pRegisterEntry2->wNumLogEntries2);

    /* Reset entries */
    pRegisterEntry2->wNumLogEntries2 = 0;
}

FUNC(phLog_RegisterEntry_t2*, ANFCRL_CODE) phLog_GetRegisteredEntry2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
    )
{
    P2VAR(phLog_RegisterEntry_t2, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRegisterEntry2 = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_COUNT2 wIndex2;

    /* Init. return value to NULL */
    pRegisterEntry2 = NULL;

    /* Iterate through all Register Entries to find given one */
    for (wIndex2 = 0; wIndex2 < gphLog_LogDataParams2.wNumRegisterEntries2; ++wIndex2)
    {
        if (pDataParams2 == gphLog_LogDataParams2.pRegisterEntries2[wIndex2].pDataParams2)
        {
            pRegisterEntry2 = &gphLog_LogDataParams2.pRegisterEntries2[wIndex2];
        }
    }

    return pRegisterEntry2;
}

FUNC(void, ANFCRL_CODE) phLog_AddParam_Raw2(
                        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                        VAR(uint8, ANFCRL_VAR) bLogType2,
                        P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName2,
                        P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) pParam2,
                        VAR(uint16, ANFCRL_VAR) wLength2,
                        VAR(uint8, ANFCRL_VAR) bDataType2
                        )
{
    P2VAR(phLog_RegisterEntry_t2, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRegisterEntry2 = NULL;

    /* Don't do anything if no callback has been registered */
    if (gphLog_LogDataParams2.pLogCallback2 == NULL)
    {
        return;
    }

    /* Retrieve corresponding Register Entry */
    pRegisterEntry2 = phLog_GetRegisteredEntry2(pDataParams2);
    if (pRegisterEntry2 == NULL)
    {
        return;
    }

    /* check if entry is available */
    if (pRegisterEntry2->wMaxLogEntries2 <= pRegisterEntry2->wNumLogEntries2)
    {
        return;
    }

    /* Build up the parameter */
    if (pRegisterEntry2->wMaxLogEntries2 > (pRegisterEntry2->wNumLogEntries2 + 1U))
    {
        pRegisterEntry2->pLogEntries2[pRegisterEntry2->wNumLogEntries2].bLogType2 = bLogType2;
        pRegisterEntry2->pLogEntries2[pRegisterEntry2->wNumLogEntries2].pString2 = pName2;
        pRegisterEntry2->pLogEntries2[pRegisterEntry2->wNumLogEntries2].pData2 = pParam2;
        pRegisterEntry2->pLogEntries2[pRegisterEntry2->wNumLogEntries2].wDataLen2 = wLength2;
    }
    /* Else return buffer overflow error */
    else
    {
        pRegisterEntry2->pLogEntries2[pRegisterEntry2->wNumLogEntries2].bLogType2 = PH_LOG_LOGTYPE_ERROR2;
        pRegisterEntry2->pLogEntries2[pRegisterEntry2->wNumLogEntries2].pString2 = gpkphLog_String_BufferOverflow2;
        pRegisterEntry2->pLogEntries2[pRegisterEntry2->wNumLogEntries2].pData2 = NULL;
        pRegisterEntry2->pLogEntries2[pRegisterEntry2->wNumLogEntries2].wDataLen2 = 0;
    }

    /* Also store the endianness of the data */
    pRegisterEntry2->pLogEntries2[pRegisterEntry2->wNumLogEntries2].bDataType2 = bDataType2;

    /* Increment buffer entries */
    ++pRegisterEntry2->wNumLogEntries2;
}
#define ANFCRL_STOP_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PH_LOG2 */

#ifdef NXPBUILD__PH_LOG_EX2
#define ANFCRL_START_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif
FUNC(void, ANFCRL_CODE) phLogEx_MsgBuffer2(P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) logmod2, P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) msg2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuff2, VAR(uint8, ANFCRL_VAR) num2) {

	VAR(uint8, ANFCRL_VAR) i2;
	P2VAR(char, AUTOMATIC, ANFCRL_APPL_DATA) ptr2 = pLogExMsg2;

	/* Parameter check */
	if((logmod2 == NULL) || (msg2 == NULL) || (pBuff2 == NULL))
	{
		return;
	}

	i2= (uint8)(*pLogEx_Sprintf2)(ptr2, "%s%s",logmod2,msg2);
	ptr2 += i2;
	for(i2 = 0; i2 < num2; i2++)
	{
		(void)(*pLogEx_Sprintf2)(ptr2, " %02X",pBuff2[i2]);
		ptr2 +=3;
	}
	LOG_PRINTF2(pLogExMsg2);
	LOG_PRINTF2("\r\n");
	CHECK_LOG_MSG2(pLogExMsg2);
}

FUNC(void, ANFCRL_CODE) phLogEx_Init2(VAR(ppLogEx_FmtToStr_t2, ANFCRL_VAR) pFmtStrFunc2, VAR(ppLogEx_SendLog_t2, ANFCRL_VAR) pSendLogFunc2)
{
	/* Parameter check */
	if((pFmtStrFunc2 == NULL) || (pSendLogFunc2 == NULL))
	{
		return;
	}
	pLogEx_Sprintf2 = pFmtStrFunc2;
	pLogEx_SendLog2 = pSendLogFunc2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PH_LOG_EX2 */

#ifdef __cplusplus
}
#endif
