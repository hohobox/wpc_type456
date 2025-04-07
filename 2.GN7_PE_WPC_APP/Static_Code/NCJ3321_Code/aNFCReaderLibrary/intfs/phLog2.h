/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020-2021
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
*   @file    phLog2.h
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

#ifndef PHLOG2_H
#define PHLOG2_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include <ph_TypeDefs2.h>
#include <Compiler.h>
#ifdef NXPBUILD__PH_LOG_EX2
#include <stdio.h>
#include <string.h>
#endif/* NXPBUILD__PH_LOG_EX2 */
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phLog2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHLOG_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHLOG_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHLOG_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHLOG_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHLOG_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHLOG_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHLOG_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHLOG_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHLOG_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phLog2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHLOG_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHLOG_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phLog2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHLOG_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHLOG_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHLOG_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phLog2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG2
/** \defgroup phLog Log
* \ingroup phcommon
*
* \brief This layer provides logging and debug functionality.
* It is different from the other layers in the way it is initialized.
* It stores it's data parameters internally and only once, thus
* there can be only one instance.
* @{
*/

/**
* \brief Allocate space in memory for a \c pString2 value. \see phLog_LogEnty_t
*/

#define PH_LOG_ALLOCATE_TEXT2(pIdent2, pText2) P2CONST(char, AUTOMATIC, ANFCRL_APPL_DATA) (pIdent2) = (pText2) /**< Allocate space in memory for a pText. */

/**
 * end of group phLog Log
 * @}
 */
#endif /* NXPBUILD__PH_LOG2 */
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG2
/** \addtogroup phLog Log
* \ingroup phcommon
*
* \brief This layer provides logging and debug functionality.
* It is different from the other layers in the way it is initialized.
* It stores it's data parameters internally and only once, thus
* there can be only one instance.
* @{
*/

#define PH_LOG_DATATYPE_BUFFER2  0x00U    /**< Data type buffer */
#define PH_LOG_DATATYPE_VALUE2   0x01U    /**< Data type value */

#define PH_LOG_LOGTYPE_INFO2     0x00U    /**< Log Type : Info */
#define PH_LOG_LOGTYPE_ERROR2    0x01U    /**< Log Type : Error */
#define PH_LOG_LOGTYPE_WARN2     0x02U    /**< Log Type : Warn */
#define PH_LOG_LOGTYPE_DEBUG2    0x03U    /**< Log Type : Debug */

#define PH_LOG_OPTION_CATEGORY_ENTER2    0x01U    /**< Execute Option: Logging takes place at function entry. */
#define PH_LOG_OPTION_CATEGORY_GEN2      0x02U    /**< Execute Option: Logging takes place in the middle of a function. */
#define PH_LOG_OPTION_CATEGORY_LEAVE2    0x03U    /**< Execute Option: Logging takes place before leaving the function. */

/**
 * end of group phLog Log
 * @}
 */
#endif /* NXPBUILD__PH_LOG2 */

#ifdef NXPBUILD__PH_LOG_EX2
#define UART_TIMEOUT2	100U
#define LOGTYPE2 2
#endif /* NXPBUILD__PH_LOG_EX2 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG2
/** \addtogroup phLog Log
* \ingroup phcommon
*
* \brief This layer provides logging and debug functionality.
* It is different from the other layers in the way it is initialized.
* It stores it's data parameters internally and only once, thus
* there can be only one instance.
* @{
*/

/**
* \brief Definition of a single Log entry
*/
typedef struct
{
    VAR(uint8, ANFCRL_VAR) bLogType2;           /**< Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
    P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pString2;    /**< Null-terminated string. */
    P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) pData2;         /**< Pointer to the data. */
    VAR(uint16, ANFCRL_VAR) wDataLen2;          /**< Length of the data. */
    VAR(uint8, ANFCRL_VAR) bDataType2;          /**< Indicates the value type (either #PH_LOG_DATATYPE_BUFFER2 or #PH_LOG_DATATYPE_VALUE2). */
} phLog_LogEntry_t2;

/**
* \brief Definition of a Register Entry
*/
typedef struct
{
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2;             /**< Component for which logging shall be performed. */
    P2VAR(phLog_LogEntry_t2, AUTOMATIC, ANFCRL_APPL_DATA) pLogEntries2; /**< An array of \ref phLog_LogEntry_t structures. */
    VAR(uint16, ANFCRL_VAR) wNumLogEntries2;        /**< Number of valid entries within the array. */
    VAR(uint16, ANFCRL_VAR) wMaxLogEntries2;        /**< Number of log entries the \ref phLog_LogEntry_t2 array can hold. */
} phLog_RegisterEntry_t2;

/** Function definition for log callback function */
typedef void (*pphLog_Callback_t2)(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
	VAR(uint8, ANFCRL_VAR) bOption2,
	P2VAR(phLog_LogEntry_t2 , AUTOMATIC, ANFCRL_APPL_DATA) pLogEntries2,
	VAR(uint16, ANFCRL_VAR) wEntryCount2);

/**
* \brief Log parameter structure
*/
typedef struct
{
    VAR(pphLog_Callback_t2, ANFCRL_VAR) pLogCallback2;             /**< Pointer to a log callback function. */
    P2VAR(phLog_RegisterEntry_t2, AUTOMATIC, ANFCRL_APPL_DATA) pRegisterEntries2;   /**< An array of \ref phLog_RegisterEntry_t structures. */
    VAR(uint16, ANFCRL_VAR) wNumRegisterEntries2;               /**< Number of valid entries within the array. */
    VAR(uint16, ANFCRL_VAR) wMaxRegisterEntries2;               /**< Number of log entries the \ref phLog_RegisterEntry_t2 array can hold. */
} phLog_DataParams_t2;

/**
 * end of group phLog Log
 * @}
 */
#endif /* NXPBUILD__PH_LOG2 */

#ifdef NXPBUILD__PH_LOG_EX2
typedef int (*ppLogEx_FmtToStr_t2)(P2VAR(char, AUTOMATIC, ANFCRL_APPL_DATA) pBuff2, P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) format2, ...);
typedef void (*ppLogEx_SendLog_t2)(P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) txBuff2);
#endif /* NXPBUILD__PH_LOG_EX2 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG_EX2
extern VAR(char, ANFCRL_VAR) pLogExMsg2[];
extern VAR(ppLogEx_FmtToStr_t2, ANFCRL_VAR) pLogEx_Sprintf2;
extern VAR(ppLogEx_SendLog_t2, ANFCRL_VAR) pLogEx_SendLog2;
#endif /* NXPBUILD__PH_LOG_EX2 */
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ANFCRL_START_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PH_LOG_EX2
FUNC(void, ANFCRL_CODE) phLogEx_Init2(
		VAR(ppLogEx_FmtToStr_t2, ANFCRL_VAR) pFmtStrFunc2,
		VAR(ppLogEx_SendLog_t2, ANFCRL_VAR) pSendLogFunc2);
#endif

#ifdef NXPBUILD__PH_LOG2
/** \addtogroup phLog Log
* \ingroup phcommon
*
* \brief This layer provides logging and debug functionality.
* It is different from the other layers in the way it is initialized.
* It stores it's data parameters internally and only once, thus
* there can be only one instance.
* @{
*/

/**
* \brief Initialize Logging.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Input parameter combination is invalid.
*/
FUNC(phStatus_t, ANFCRL_CODE) phLog_Init2(
                      VAR(pphLog_Callback_t2, ANFCRL_VAR) pLogCallback2,           /**< [In] Pointer to a log callback function. */
                      P2VAR(phLog_RegisterEntry_t2, AUTOMATIC, ANFCRL_APPL_DATA) pRegisterEntries2, /**< [In] An array of \ref phLog_RegisterEntry_t memory. */
                      VAR(uint16, ANFCRL_VAR) wMaxRegisterEntries2              /**< [In] Number of log entries the \ref phLog_RegisterEntry_t2 array can hold. */
                      );

/**
* \brief Register component for logging.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_USE_CONDITION Logging is not properly initialized.
* \retval #PH_ERR_INVALID_PARAMETER \c wMaxLogEntries2 is invalid.
* \retval #PH_ERR_BUFFER_OVERFLOW The maximum Register Entry count is reached.
*/
FUNC(phStatus_t, ANFCRL_CODE) phLog_Register2(
                          P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,               /**< [In] Component for which logging shall be performed. */
                          P2VAR(phLog_LogEntry_t2, AUTOMATIC, ANFCRL_APPL_DATA) pLogEntries2,   /**< [In] An array of \ref phLog_LogEntry_t structures. */
                          VAR(uint16, ANFCRL_VAR) wMaxLogEntries2           /**< [In] Number of log entries the \ref phLog_LogEntry_t2 array can hold. */
                          );

/**
* \brief Add a new log entry containing just a string. \see phLog_LogEnty_t
*/
FUNC(void, ANFCRL_CODE) phLog_AddString2(
                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,    /**< [In] The DataParams of the calling function. */
                     VAR(uint8, ANFCRL_VAR) bLogType2,      /**< [In] Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
                     P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pString2   /**< [In] The Null-terminated string to add. */
                     );

/**
* \brief Add a new log entry containing an #uint8 parameter. \see phLog_LogEnty_t
*/
FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint82(
                          P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] The DataParams of the calling function. */
                          VAR(uint8, ANFCRL_VAR) bLogType2,     /**< [In] Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
                          P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName2,   /**< [In] The Null-terminated name of the parameter. */
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pParam2      /**< [In] Pointer to the memory where the parameter resides. */
                          );

/**
* \brief Add a new log entry containing an #uint16 parameter. \see phLog_LogEnty_t
*/
FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint162(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] The DataParams of the calling function. */
                           VAR(uint8, ANFCRL_VAR) bLogType2,    /**< [In] Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName2,  /**< [In] The Null-terminated name of the parameter. */
                           P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pParam2    /**< [In] Pointer to the memory where the parameter resides. */
                           );

/**
* \brief Add a new log entry containing an #uint32 parameter. \see phLog_LogEnty_t
*/
FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint322(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] The DataParams of the calling function. */
                           VAR(uint8, ANFCRL_VAR) bLogType2,    /**< [In] Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName2,  /**< [In] The Null-terminated name of the parameter. */
                           P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pParam2    /**< [In] Pointer to the memory where the parameter resides. */
                           );

/**
* \brief Add a new log entry containing a byte-buffer of variable length. \see phLog_LogEnty_t
*/
FUNC(void, ANFCRL_CODE) phLog_AddParam_Buffer2(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] The DataParams of the calling function. */
                           VAR(uint8, ANFCRL_VAR) bLogType2,    /**< [In] Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName2,  /**< [In] The Null-terminated name of the parameter. */
                           P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) pParam2, /**< [In] Pointer to the memory where the parameter resides. */
                           VAR(uint16, ANFCRL_VAR) wLength2     /**< [In] The length in bytes to the supplied buffer. */
                           );

/**
* \brief Execute the callback function to process the log buffer.
*/
FUNC(void, ANFCRL_CODE) phLog_Execute2(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] The DataParams of the calling function. */
                   VAR(uint8, ANFCRL_VAR) bOption2      /**< [In] Option byte (one of the PH_LOG_OPTION* defines). */
                   );

/**
 * end of group phLog Log
 * @}
 */
#endif /* NXPBUILD__PH_LOG2 */

#ifdef NXPBUILD__PH_LOG_EX2

FUNC(void, ANFCRL_CODE) phLogEx_MsgBuffer2(P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) logmod2, P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) msg2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuff2, VAR(uint8, ANFCRL_VAR) num2);

#ifdef CHECK_LOG2
FUNC(sint16, ANFCRL_CODE) checkLog2(P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) logMsg2);
#define CHECK_LOG_MSG2(msg2) checkLog2(msg2)
#else
#define CHECK_LOG_MSG2(msg2)
#endif

#if (defined (LOGTYPE2)) && (LOGTYPE2 == 1)
#define  LOG_PRINTF2(msg2) printf(msg2)
#elif (defined (LOGTYPE2)) && (LOGTYPE2 == 2)
#define LOG_PRINTF2(msg2)  (void)(*pLogEx_SendLog2)(msg2)
#else
#define LOG_PRINTF2(msg2)
#endif

#define APPL_LOG2(fmt2, args2...)				(void)memcpy(pLogExMsg2,"  APPL2  | ",9U);	(void)(*pLogEx_Sprintf2)(pLogExMsg2+9U, fmt2, ## args2 ); LOG_PRINTF2(pLogExMsg2); CHECK_LOG_MSG2(pLogExMsg2)
#define APPL_LOG_BUF2(msg2, pBuf2, bLen2)			phLogEx_MsgBuffer2("APPL_LOG2|", msg2, pBuf2, bLen2 );

/* Disable log message in library */
#ifndef PH_LIB_LOG_DISABLE2

#define I14443P3_LOG2(fmt2, args2...) 			(void)memcpy(pLogExMsg2,"I14443P32|",9U);	(void)(*pLogEx_Sprintf2)(pLogExMsg2+9U, fmt2, ## args2 ); LOG_PRINTF2(pLogExMsg2); CHECK_LOG_MSG2(pLogExMsg2)
#define I14443P3_LOG_BUF2(msg2, pBuf2, bLen2) 	phLogEx_MsgBuffer2("I14443P32|", msg2, pBuf2, bLen2 )
#define I14443P4_LOG2(fmt2, args2...) 			(void)memcpy(pLogExMsg2,"I14443P42|",9U);	(void)(*pLogEx_Sprintf2)(pLogExMsg2+9U, fmt2, ## args2 ); LOG_PRINTF2(pLogExMsg2); CHECK_LOG_MSG2(pLogExMsg2)
#define I14443P4_LOG_BUF2(msg2, pBuf2, bLen2) 	phLogEx_MsgBuffer2("I14443P42|", msg2, pBuf2, bLen2 )
#define NCX3320_LOG2(fmt2, args2...) 			(void)memcpy(pLogExMsg2," NCX33202|",9U);	(void)(*pLogEx_Sprintf2)(pLogExMsg2+9U, fmt2, ## args2 ); LOG_PRINTF2(pLogExMsg2); CHECK_LOG_MSG2(pLogExMsg2)
#define NCX3320_LOG_BUFW(msg2, pBuf2, bLen2) 	phLogEx_MsgBuffer2(" NCX33202|", msg2, pBuf2, bLen2 )
#define MSG_LOG2(tag2, fmt2, args2...)			(void)memcpy(pLogExMsg2,	tag2	   ,9U);	(void)(*pLogEx_Sprintf2)(pLogExMsg2+9U, fmt2, ## args2 ); LOG_PRINTF2(pLogExMsg2); CHECK_LOG_MSG2(pLogExMsg2)
#define MSG_LOG_BUF2(tag2, msg2, pBuf2, bLen2)	phLogEx_MsgBuffer2(tag2, msg2, pBuf2, bLen2 )
#define DEBUG_LOG2(args2...)					(void)(*pLogEx_Sprintf2)(pLogExMsg2,## args2 ); LOG_PRINTF2(pLogExMsg2);

#else /* PH_LIB_LOG_DISABLE2 */

#define I14443P3_LOG2(fmt2, args2...)
#define I14443P3_LOG_BUF2(msg2, pBuf2, bLen2)
#define I14443P4_LOG2(fmt2, args2...)
#define I14443P4_LOG_BUF2(msg2, pBuf2, bLen2)
#define NCX3320_LOG2(fmt2, args2...)
#define NCX3320_LOG_BUFW(msg2, pBuf2, bLen2)
#define MSG_LOG2(tag2, fmt2, args2...)
#define MSG_LOG_BUF2(tag2, msg2, pBuf2, bLen2)
#define DEBUG_LOG2(args2...)
#endif /* PH_LIB_LOG_DISABLE2 */

#else /* NXPBUILD__PH_LOG_EX2 */

#define APPL_LOG2(fmt2, args2...)
#define APPL_LOG_BUF2(msg2, pBuf2, bLen2)
#define I14443P3_LOG2(fmt2, args2...) /*Dummy */
#define I14443P3_LOG_BUF2(msg2, pBuf2, bLen2)
#define I14443P4_LOG2(fmt2, args2...)
#define I14443P4_LOG_BUF2(msg2, pBuf2, bLen2)
#define NCX3320_LOG2(fmt2, args2...)
#define NCX3320_LOG_BUFW(msg2, pBuf2, bLen2)
#define MSG_LOG2(tag2, fmt2, args2...)
#define MSG_LOG_BUF2(tag2, msg2, pBuf2, bLen2)
#define DEBUG_LOG2(args2...)
#endif /* NXPBUILD__PH_LOG_EX2 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif  /* PHLOG2_H */
