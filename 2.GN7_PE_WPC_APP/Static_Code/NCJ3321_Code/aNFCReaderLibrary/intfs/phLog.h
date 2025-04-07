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
*   @file    phLog.h
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

#ifndef PHLOG_H
#define PHLOG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include <ph_TypeDefs.h>
#include <Compiler.h>
#ifdef NXPBUILD__PH_LOG_EX
#include <stdio.h>
#include <string.h>
#endif/* NXPBUILD__PH_LOG_EX */
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phLog.h
* @implements     DESIGN001, DESIGN002
*/
#define PHLOG_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHLOG_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHLOG_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHLOG_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHLOG_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHLOG_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHLOG_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHLOG_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHLOG_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phLog.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHLOG_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHLOG_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phLog.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHLOG_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHLOG_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHLOG_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phLog.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG
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
* \brief Allocate space in memory for a \c pString value. \see phLog_LogEnty_t
*/

#define PH_LOG_ALLOCATE_TEXT(pIdent, pText) P2CONST(char, AUTOMATIC, ANFCRL_APPL_DATA) (pIdent) = (pText) /**< Allocate space in memory for a pText. */

/**
 * end of group phLog Log
 * @}
 */
#endif /* NXPBUILD__PH_LOG */
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG
/** \addtogroup phLog Log
* \ingroup phcommon
*
* \brief This layer provides logging and debug functionality.
* It is different from the other layers in the way it is initialized.
* It stores it's data parameters internally and only once, thus
* there can be only one instance.
* @{
*/

#define PH_LOG_DATATYPE_BUFFER  0x00U    /**< Data type buffer */
#define PH_LOG_DATATYPE_VALUE   0x01U    /**< Data type value */

#define PH_LOG_LOGTYPE_INFO     0x00U    /**< Log Type : Info */
#define PH_LOG_LOGTYPE_ERROR    0x01U    /**< Log Type : Error */
#define PH_LOG_LOGTYPE_WARN     0x02U    /**< Log Type : Warn */
#define PH_LOG_LOGTYPE_DEBUG    0x03U    /**< Log Type : Debug */

#define PH_LOG_OPTION_CATEGORY_ENTER    0x01U    /**< Execute Option: Logging takes place at function entry. */
#define PH_LOG_OPTION_CATEGORY_GEN      0x02U    /**< Execute Option: Logging takes place in the middle of a function. */
#define PH_LOG_OPTION_CATEGORY_LEAVE    0x03U    /**< Execute Option: Logging takes place before leaving the function. */

/**
 * end of group phLog Log
 * @}
 */
#endif /* NXPBUILD__PH_LOG */

#ifdef NXPBUILD__PH_LOG_EX
#define UART_TIMEOUT	100U
#define LOGTYPE 2
#endif /* NXPBUILD__PH_LOG_EX */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG
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
    VAR(uint8, ANFCRL_VAR) bLogType;           /**< Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
    P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pString;    /**< Null-terminated string. */
    P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) pData;         /**< Pointer to the data. */
    VAR(uint16, ANFCRL_VAR) wDataLen;          /**< Length of the data. */
    VAR(uint8, ANFCRL_VAR) bDataType;          /**< Indicates the value type (either #PH_LOG_DATATYPE_BUFFER or #PH_LOG_DATATYPE_VALUE). */
} phLog_LogEntry_t;

/**
* \brief Definition of a Register Entry
*/
typedef struct
{
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams;             /**< Component for which logging shall be performed. */
    P2VAR(phLog_LogEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pLogEntries; /**< An array of \ref phLog_LogEntry_t structures. */
    VAR(uint16, ANFCRL_VAR) wNumLogEntries;        /**< Number of valid entries within the array. */
    VAR(uint16, ANFCRL_VAR) wMaxLogEntries;        /**< Number of log entries the \ref phLog_LogEntry_t array can hold. */
} phLog_RegisterEntry_t;

/** Function definition for log callback function */
typedef void (*pphLog_Callback_t)(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint8, ANFCRL_VAR) bOption,
	P2VAR(phLog_LogEntry_t , AUTOMATIC, ANFCRL_APPL_DATA) pLogEntries,
	VAR(uint16, ANFCRL_VAR) wEntryCount);

/**
* \brief Log parameter structure
*/
typedef struct
{
    VAR(pphLog_Callback_t, ANFCRL_VAR) pLogCallback;             /**< Pointer to a log callback function. */
    P2VAR(phLog_RegisterEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pRegisterEntries;   /**< An array of \ref phLog_RegisterEntry_t structures. */
    VAR(uint16, ANFCRL_VAR) wNumRegisterEntries;               /**< Number of valid entries within the array. */
    VAR(uint16, ANFCRL_VAR) wMaxRegisterEntries;               /**< Number of log entries the \ref phLog_RegisterEntry_t array can hold. */
} phLog_DataParams_t;

/**
 * end of group phLog Log
 * @}
 */
#endif /* NXPBUILD__PH_LOG */

#ifdef NXPBUILD__PH_LOG_EX
typedef int (*ppLogEx_FmtToStr_t)(P2VAR(char, AUTOMATIC, ANFCRL_APPL_DATA) pBuff, P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) format, ...);
typedef void (*ppLogEx_SendLog_t)(P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) txBuff);
#endif /* NXPBUILD__PH_LOG_EX */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifdef NXPBUILD__PH_LOG_EX
extern VAR(char, ANFCRL_VAR) pLogExMsg[];
extern VAR(ppLogEx_FmtToStr_t, ANFCRL_VAR) pLogEx_Sprintf;
extern VAR(ppLogEx_SendLog_t, ANFCRL_VAR) pLogEx_SendLog;
#endif /* NXPBUILD__PH_LOG_EX */
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ANFCRL_START_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PH_LOG_EX
FUNC(void, ANFCRL_CODE) phLogEx_Init(
		VAR(ppLogEx_FmtToStr_t, ANFCRL_VAR) pFmtStrFunc,
		VAR(ppLogEx_SendLog_t, ANFCRL_VAR) pSendLogFunc);
#endif

#ifdef NXPBUILD__PH_LOG
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
FUNC(phStatus_t, ANFCRL_CODE) phLog_Init(
                      VAR(pphLog_Callback_t, ANFCRL_VAR) pLogCallback,           /**< [In] Pointer to a log callback function. */
                      P2VAR(phLog_RegisterEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pRegisterEntries, /**< [In] An array of \ref phLog_RegisterEntry_t memory. */
                      VAR(uint16, ANFCRL_VAR) wMaxRegisterEntries              /**< [In] Number of log entries the \ref phLog_RegisterEntry_t array can hold. */
                      );

/**
* \brief Register component for logging.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_USE_CONDITION Logging is not properly initialized.
* \retval #PH_ERR_INVALID_PARAMETER \c wMaxLogEntries is invalid.
* \retval #PH_ERR_BUFFER_OVERFLOW The maximum Register Entry count is reached.
*/
FUNC(phStatus_t, ANFCRL_CODE) phLog_Register(
                          P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,               /**< [In] Component for which logging shall be performed. */
                          P2VAR(phLog_LogEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pLogEntries,   /**< [In] An array of \ref phLog_LogEntry_t structures. */
                          VAR(uint16, ANFCRL_VAR) wMaxLogEntries           /**< [In] Number of log entries the \ref phLog_LogEntry_t array can hold. */
                          );

/**
* \brief Add a new log entry containing just a string. \see phLog_LogEnty_t
*/
FUNC(void, ANFCRL_CODE) phLog_AddString(
                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] The DataParams of the calling function. */
                     VAR(uint8, ANFCRL_VAR) bLogType,      /**< [In] Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
                     P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pString   /**< [In] The Null-terminated string to add. */
                     );

/**
* \brief Add a new log entry containing an #uint8 parameter. \see phLog_LogEnty_t
*/
FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint8(
                          P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] The DataParams of the calling function. */
                          VAR(uint8, ANFCRL_VAR) bLogType,     /**< [In] Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
                          P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName,   /**< [In] The Null-terminated name of the parameter. */
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pParam      /**< [In] Pointer to the memory where the parameter resides. */
                          );

/**
* \brief Add a new log entry containing an #uint16 parameter. \see phLog_LogEnty_t
*/
FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint16(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] The DataParams of the calling function. */
                           VAR(uint8, ANFCRL_VAR) bLogType,    /**< [In] Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName,  /**< [In] The Null-terminated name of the parameter. */
                           P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pParam    /**< [In] Pointer to the memory where the parameter resides. */
                           );

/**
* \brief Add a new log entry containing an #uint32 parameter. \see phLog_LogEnty_t
*/
FUNC(void, ANFCRL_CODE) phLog_AddParam_Uint32(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] The DataParams of the calling function. */
                           VAR(uint8, ANFCRL_VAR) bLogType,    /**< [In] Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName,  /**< [In] The Null-terminated name of the parameter. */
                           P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pParam    /**< [In] Pointer to the memory where the parameter resides. */
                           );

/**
* \brief Add a new log entry containing a byte-buffer of variable length. \see phLog_LogEnty_t
*/
FUNC(void, ANFCRL_CODE) phLog_AddParam_Buffer(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] The DataParams of the calling function. */
                           VAR(uint8, ANFCRL_VAR) bLogType,    /**< [In] Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
                           P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName,  /**< [In] The Null-terminated name of the parameter. */
                           P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) pParam, /**< [In] Pointer to the memory where the parameter resides. */
                           VAR(uint16, ANFCRL_VAR) wLength     /**< [In] The length in bytes to the supplied buffer. */
                           );

/**
* \brief Execute the callback function to process the log buffer.
*/
FUNC(void, ANFCRL_CODE) phLog_Execute(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] The DataParams of the calling function. */
                   VAR(uint8, ANFCRL_VAR) bOption      /**< [In] Option byte (one of the PH_LOG_OPTION* defines). */
                   );

/**
 * end of group phLog Log
 * @}
 */
#endif /* NXPBUILD__PH_LOG */

#ifdef NXPBUILD__PH_LOG_EX

FUNC(void, ANFCRL_CODE) phLogEx_MsgBuffer(P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) logmod, P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) msg, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuff, VAR(uint8, ANFCRL_VAR) num);

#ifdef CHECK_LOG
FUNC(sint16, ANFCRL_CODE) checkLog(P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) logMsg);
#define CHECK_LOG_MSG(msg) checkLog(msg)
#else
#define CHECK_LOG_MSG(msg)
#endif

#if (defined (LOGTYPE)) && (LOGTYPE == 1)
#define  LOG_PRINTF(msg) printf(msg)
#elif (defined (LOGTYPE)) && (LOGTYPE == 2)
#define LOG_PRINTF(msg)  (void)(*pLogEx_SendLog)(msg)
#else
#define LOG_PRINTF(msg)
#endif

#define APPL_LOG(fmt, args...)				(void)memcpy(pLogExMsg,"  APPL  | ",9U);	(void)(*pLogEx_Sprintf)(pLogExMsg+9U, fmt, ## args ); LOG_PRINTF(pLogExMsg); CHECK_LOG_MSG(pLogExMsg)
#define APPL_LOG_BUF(msg, pBuf, bLen)			phLogEx_MsgBuffer("APPL_LOG|", msg, pBuf, bLen );

/* Disable log message in library */
#ifndef PH_LIB_LOG_DISABLE

#define I14443P3_LOG(fmt, args...) 			(void)memcpy(pLogExMsg,"I14443P3|",9U);	(void)(*pLogEx_Sprintf)(pLogExMsg+9U, fmt, ## args ); LOG_PRINTF(pLogExMsg); CHECK_LOG_MSG(pLogExMsg)
#define I14443P3_LOG_BUF(msg, pBuf, bLen) 	phLogEx_MsgBuffer("I14443P3|", msg, pBuf, bLen )
#define I14443P4_LOG(fmt, args...) 			(void)memcpy(pLogExMsg,"I14443P4|",9U);	(void)(*pLogEx_Sprintf)(pLogExMsg+9U, fmt, ## args ); LOG_PRINTF(pLogExMsg); CHECK_LOG_MSG(pLogExMsg)
#define I14443P4_LOG_BUF(msg, pBuf, bLen) 	phLogEx_MsgBuffer("I14443P4|", msg, pBuf, bLen )
#define NCX3320_LOG(fmt, args...) 			(void)memcpy(pLogExMsg," NCX3320|",9U);	(void)(*pLogEx_Sprintf)(pLogExMsg+9U, fmt, ## args ); LOG_PRINTF(pLogExMsg); CHECK_LOG_MSG(pLogExMsg)
#define NCX3320_LOG_BUF(msg, pBuf, bLen) 	phLogEx_MsgBuffer(" NCX3320|", msg, pBuf, bLen )
#define MSG_LOG(tag, fmt, args...)			(void)memcpy(pLogExMsg,	tag	   ,9U);	(void)(*pLogEx_Sprintf)(pLogExMsg+9U, fmt, ## args ); LOG_PRINTF(pLogExMsg); CHECK_LOG_MSG(pLogExMsg)
#define MSG_LOG_BUF(tag, msg, pBuf, bLen)	phLogEx_MsgBuffer(tag, msg, pBuf, bLen )
#define DEBUG_LOG(args...)					(void)(*pLogEx_Sprintf)(pLogExMsg,## args ); LOG_PRINTF(pLogExMsg);

#else /* PH_LIB_LOG_DISABLE */

#define I14443P3_LOG(fmt, args...)
#define I14443P3_LOG_BUF(msg, pBuf, bLen)
#define I14443P4_LOG(fmt, args...)
#define I14443P4_LOG_BUF(msg, pBuf, bLen)
#define NCX3320_LOG(fmt, args...)
#define NCX3320_LOG_BUF(msg, pBuf, bLen)
#define MSG_LOG(tag, fmt, args...)
#define MSG_LOG_BUF(tag, msg, pBuf, bLen)
#define DEBUG_LOG(args...)
#endif /* PH_LIB_LOG_DISABLE */

#else /* NXPBUILD__PH_LOG_EX */

#define APPL_LOG(fmt, args...)
#define APPL_LOG_BUF(msg, pBuf, bLen)
#define I14443P3_LOG(fmt, args...) /*Dummy */
#define I14443P3_LOG_BUF(msg, pBuf, bLen)
#define I14443P4_LOG(fmt, args...)
#define I14443P4_LOG_BUF(msg, pBuf, bLen)
#define NCX3320_LOG(fmt, args...)
#define NCX3320_LOG_BUF(msg, pBuf, bLen)
#define MSG_LOG(tag, fmt, args...)
#define MSG_LOG_BUF(tag, msg, pBuf, bLen)
#define DEBUG_LOG(args...)
#endif /* NXPBUILD__PH_LOG_EX */

#define ANFCRL_STOP_SEC_CODE
#if ((PHLOG_AR_RELEASE_MAJOR_VERSION == 4) && (PHLOG_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif  /* PHLOG_H */
