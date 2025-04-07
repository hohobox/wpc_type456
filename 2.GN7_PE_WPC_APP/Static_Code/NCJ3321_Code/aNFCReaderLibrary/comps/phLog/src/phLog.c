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
*   @file    phLog.c
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

#include <ph_Status.h>

#ifdef NXPBUILD__PH_LOG
#include <ph_RefDefs.h>
#include "phLog_Int.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phLog.c
* @implements     DESIGN001, DESIGN002
*/
#define PHLOG_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHLOG_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHLOG_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHLOG_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHLOG_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHLOG_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHLOG_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phLog.h header file are of the same vendor */
#if (PHLOG_VENDOR_ID_C != PHLOG_VENDOR_ID)
    #error "phLog.c and phLog.h have different vendor ids"
#endif
/* Check if current file and phLog.h header file are of the same Autosar version */
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C    != PHLOG_AR_RELEASE_MAJOR_VERSION) || \
     (PHLOG_AR_RELEASE_MINOR_VERSION_C    != PHLOG_AR_RELEASE_MINOR_VERSION) || \
     (PHLOG_AR_RELEASE_REVISION_VERSION_C != PHLOG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phLog.c and phLog.h are different"
#endif
/* Check if current file and phLog.h header file are of the same Software version */
#if ((PHLOG_SW_MAJOR_VERSION_C != PHLOG_SW_MAJOR_VERSION) || \
     (PHLOG_SW_MINOR_VERSION_C != PHLOG_SW_MINOR_VERSION) || \
     (PHLOG_SW_PATCH_VERSION_C != PHLOG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phLog.c and phLog.h are different"
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
#ifdef NXPBUILD__PH_LOG

#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) PH_MEMLOC_CONST_ROM gpkphLog_String_BufferOverflow = "OVERFLOW";

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_LOG */
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(phLog_DataParams_t, ANFCRL_VAR) PH_MEMLOC_REM gphLog_LogDataParams = {NULL, NULL, 0U, 0U};

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_LOG */
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG_EX

#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

VAR(ppLogEx_FmtToStr_t, ANFCRL_VAR) pLogEx_Sprintf;
VAR(ppLogEx_SendLog_t, ANFCRL_VAR) pLogEx_SendLog;
VAR(char, ANFCRL_VAR) pLogExMsg[256*3];

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_LOG_EX */
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG
#define ANFCRL_START_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
FUNC(phStatus_t, ANFCRL_CODE) phLog_Init(
                      VAR(pphLog_Callback_t, ANFCRL_VAR) pLogCallback,
                      P2VAR(phLog_RegisterEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pRegisterEntries,
                      VAR(uint16, ANFCRL_VAR) wMaxRegisterEntries
                      )
{
    /* Check parameters */
    if (pLogCallback != NULL)
    {
        if (wMaxRegisterEntries == 0U)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_LOG);
        }
        if (pRegisterEntries == NULL)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_LOG);
        }
    }

    gphLog_LogDataParams.pLogCallback           = pLogCallback;
    gphLog_LogDataParams.pRegisterEntries       = pRegisterEntries;
    gphLog_LogDataParams.wNumRegisterEntries    = 0;
    gphLog_LogDataParams.wMaxRegisterEntries    = wMaxRegisterEntries;

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phLog_Register(
                          P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                          P2VAR(phLog_LogEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pLogEntries,
                          VAR(uint16, ANFCRL_VAR) wMaxLogEntries
                          )
{
    /* Parameter check */
    if ((pDataParams == NULL) || (pLogEntries == NULL) || (wMaxLogEntries == 0U))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_LOG);
    }

    /* Logging has to be initialized */
    if (gphLog_LogDataParams.pLogCallback == NULL)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_LOG);
    }

    /* Check for buffer overflow */
    if (gphLog_LogDataParams.wMaxRegisterEntries < (gphLog_LogDataParams.wNumRegisterEntries + 1U))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_LOG);
    }

    /* Add Register Entry */
    gphLog_LogDataParams.pRegisterEntries[gphLog_LogDataParams.wNumRegisterEntries].pDataParams = pDataParams;
    gphLog_LogDataParams.pRegisterEntries[gphLog_LogDataParams.wNumRegisterEntries].pLogEntries = pLogEntries;
    gphLog_LogDataParams.pRegisterEntries[gphLog_LogDataParams.wNumRegisterEntries].wNumLogEntries = 0;
    gphLog_LogDataParams.pRegisterEntries[gphLog_LogDataParams.wNumRegisterEntries].wMaxLogEntries = wMaxLogEntries;

    /* Increment number of registered entry pairs */
    ++gphLog_LogDataParams.wNumRegisterEntries;

    return PH_ERR_SUCCESS;
}

FUNC(void, ANFCRL_CODE) phLog_AddString(
                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                     VAR(uint8, ANFCRL_VAR) bLogType,
                     P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pString
                     )
{
    phLog_AddParam_Raw(pDataParams, bLogType, pString, NULL, 0, PH_LOG_DATATYPE_BUFFER);
}

FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint8(
                          P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                          VAR(uint8, ANFCRL_VAR) bLogType,
                          P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName,
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pParam
                          )
{
    phLog_AddParam_Raw(pDataParams, bLogType, pName, pParam, (uint16)sizeof(uint8), PH_LOG_DATATYPE_VALUE);
}

FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint16(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                           VAR(uint8, ANFCRL_VAR) bLogType,
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName,
                           P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pParam
                           )
{
    phLog_AddParam_Raw(pDataParams, bLogType, pName, pParam, (uint16)sizeof(uint16), PH_LOG_DATATYPE_VALUE);
}

FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint32(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                           VAR(uint8, ANFCRL_VAR) bLogType,
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName,
                           P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pParam
                           )
{
    phLog_AddParam_Raw(pDataParams, bLogType, pName, pParam, (uint16)sizeof(uint32), PH_LOG_DATATYPE_VALUE);
}

FUNC(void, ANFCRL_CODE) phLog_AddParam_Buffer(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                           VAR(uint8, ANFCRL_VAR) bLogType,
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName,
                           P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) pParam,
                           VAR(uint16, ANFCRL_VAR) wLength
                           )
{
    phLog_AddParam_Raw(pDataParams, bLogType, pName, pParam, wLength, PH_LOG_DATATYPE_BUFFER);
}

FUNC(void, ANFCRL_CODE) phLog_Execute(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                   VAR(uint8, ANFCRL_VAR) bOption
                   )
{
    P2VAR(phLog_RegisterEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRegisterEntry = NULL;

    /* Don't do anything if no callback has been registered */
    if (gphLog_LogDataParams.pLogCallback == NULL)
    {
        return;
    }

    /* Retrieve corresponding Register Entry */
    pRegisterEntry = phLog_GetRegisteredEntry(pDataParams);
    if (pRegisterEntry == NULL)
    {
        return;
    }

    /* Invoke the external callback */
    (*(gphLog_LogDataParams.pLogCallback))(pDataParams, bOption, pRegisterEntry->pLogEntries, pRegisterEntry->wNumLogEntries);

    /* Reset entries */
    pRegisterEntry->wNumLogEntries = 0;
}

FUNC(phLog_RegisterEntry_t*, ANFCRL_CODE) phLog_GetRegisteredEntry(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
    )
{
    P2VAR(phLog_RegisterEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRegisterEntry = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_COUNT wIndex;

    /* Init. return value to NULL */
    pRegisterEntry = NULL;

    /* Iterate through all Register Entries to find given one */
    for (wIndex = 0; wIndex < gphLog_LogDataParams.wNumRegisterEntries; ++wIndex)
    {
        if (pDataParams == gphLog_LogDataParams.pRegisterEntries[wIndex].pDataParams)
        {
            pRegisterEntry = &gphLog_LogDataParams.pRegisterEntries[wIndex];
        }
    }

    return pRegisterEntry;
}

FUNC(void, ANFCRL_CODE) phLog_AddParam_Raw(
                        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        VAR(uint8, ANFCRL_VAR) bLogType,
                        P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName,
                        P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) pParam,
                        VAR(uint16, ANFCRL_VAR) wLength,
                        VAR(uint8, ANFCRL_VAR) bDataType
                        )
{
    P2VAR(phLog_RegisterEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRegisterEntry = NULL;

    /* Don't do anything if no callback has been registered */
    if (gphLog_LogDataParams.pLogCallback == NULL)
    {
        return;
    }

    /* Retrieve corresponding Register Entry */
    pRegisterEntry = phLog_GetRegisteredEntry(pDataParams);
    if (pRegisterEntry == NULL)
    {
        return;
    }

    /* check if entry is available */
    if (pRegisterEntry->wMaxLogEntries <= pRegisterEntry->wNumLogEntries)
    {
        return;
    }

    /* Build up the parameter */
    if (pRegisterEntry->wMaxLogEntries > (pRegisterEntry->wNumLogEntries + 1U))
    {
        pRegisterEntry->pLogEntries[pRegisterEntry->wNumLogEntries].bLogType = bLogType;
        pRegisterEntry->pLogEntries[pRegisterEntry->wNumLogEntries].pString = pName;
        pRegisterEntry->pLogEntries[pRegisterEntry->wNumLogEntries].pData = pParam;
        pRegisterEntry->pLogEntries[pRegisterEntry->wNumLogEntries].wDataLen = wLength;
    }
    /* Else return buffer overflow error */
    else
    {
        pRegisterEntry->pLogEntries[pRegisterEntry->wNumLogEntries].bLogType = PH_LOG_LOGTYPE_ERROR;
        pRegisterEntry->pLogEntries[pRegisterEntry->wNumLogEntries].pString = gpkphLog_String_BufferOverflow;
        pRegisterEntry->pLogEntries[pRegisterEntry->wNumLogEntries].pData = NULL;
        pRegisterEntry->pLogEntries[pRegisterEntry->wNumLogEntries].wDataLen = 0;
    }

    /* Also store the endianness of the data */
    pRegisterEntry->pLogEntries[pRegisterEntry->wNumLogEntries].bDataType = bDataType;

    /* Increment buffer entries */
    ++pRegisterEntry->wNumLogEntries;
}
#define ANFCRL_STOP_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PH_LOG */

#ifdef NXPBUILD__PH_LOG_EX
#define ANFCRL_START_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif
FUNC(void, ANFCRL_CODE) phLogEx_MsgBuffer(P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) logmod, P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) msg, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuff, VAR(uint8, ANFCRL_VAR) num) {

	VAR(uint8, ANFCRL_VAR) i;
	P2VAR(char, AUTOMATIC, ANFCRL_APPL_DATA) ptr = pLogExMsg;

	/* Parameter check */
	if((logmod == NULL) || (msg == NULL) || (pBuff == NULL))
	{
		return;
	}

	i= (uint8)(*pLogEx_Sprintf)(ptr, "%s%s",logmod,msg);
	ptr += i;
	for(i = 0; i < num; i++)
	{
		(void)(*pLogEx_Sprintf)(ptr, " %02X",pBuff[i]);
		ptr +=3;
	}
	LOG_PRINTF(pLogExMsg);
	LOG_PRINTF("\r\n");
	CHECK_LOG_MSG(pLogExMsg);
}

FUNC(void, ANFCRL_CODE) phLogEx_Init(VAR(ppLogEx_FmtToStr_t, ANFCRL_VAR) pFmtStrFunc, VAR(ppLogEx_SendLog_t, ANFCRL_VAR) pSendLogFunc)
{
	/* Parameter check */
	if((pFmtStrFunc == NULL) || (pSendLogFunc == NULL))
	{
		return;
	}
	pLogEx_Sprintf = pFmtStrFunc;
	pLogEx_SendLog = pSendLogFunc;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PH_LOG_EX */

#ifdef __cplusplus
}
#endif
