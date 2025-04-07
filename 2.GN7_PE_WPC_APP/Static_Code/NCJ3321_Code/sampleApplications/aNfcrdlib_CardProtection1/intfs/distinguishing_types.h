/*******************************************************************************
 * (c) NXP B.V. 2009-2021
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
 * INTELLECTUAL PROPERTY RIGHTS. NXP SHALL HAVE NO LIABILITY TO THE NXP CUS-TOMER, OR ITS
 * SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY FOR ANY DAMAGES, INCLUDING WITHOUT LIMITATION,
 * DAMAGES RESULTING OR ALLEGDED TO HAVE RESULTED FROM ANY DEFECT, ER-ROR OR OMMISSION IN THE NXP
 * SOFTWARE/SOURCE CODE, THIRD PARTY APPLICATION SOFTWARE AND/OR DOCUMENTATION, OR AS A RESULT OF ANY
 * INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHT OF ANY THIRD PARTY. IN NO EVENT SHALL NXP BE LIABLE
 * FOR ANY INCIDENTAL, INDIRECT, SPE-CIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL DAMAGES (INCLUDING
 * LOST PROFITS) SUFFERED BY NXP CUSTOMER OR ITS SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY
 * ARISING OUT OF OR RE-LATED TO THE NXP SOFTWARE/SOURCE CODE EVEN IF NXP HAS BEEN ADVISED OF THE
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

#ifndef DISTINGUISHING_TYPES_H
#define DISTINGUISHING_TYPES_H

#include <ph_Status.h>
#include <phApp_Init.h>

#include <phNfcLib.h>
#include <string.h>
#include "phLog.h"

#define S32K144

#define ANFC_RDLIB_USED

/* Implementation dependent includes */
#if defined(WCT1013A)

#elif defined(WCT1014S)
#include "sample_app_mcal_uart_console.h" /* used for UART printing */
#include "sample_app_mcal_system_timer.h" /* used for tick timer functionality */
#include "Wct_LibFunsExt.h"         /* used to get current tick */
#include "typedefs.h"           /* defined types e.g. uint8 */

#elif defined(WCT1015S)
#include "sample_app_mcal_uart_console.h" /* used for UART printing */
#include "sample_app_mcal_task_nfclib.h"  /* used for UART printing */
#include "sample_app_mcal_system_timer.h" /* used for tick timer functionality */
#include "Wct_LibFunsExt.h"         /* used to get current tick */

#elif defined(S32K144)
/* no additional includes needed */
#else
#warning please select a platform
#endif /* PLATFORM */

/*############################################################
 *
 *                      COMPILER FLAGS
 *
 ###########################################################*/
#define PRINT_ERROR_MESSAGES    /* print error messages */

/*############################################################
 *
 *                  FUNCTION-LIKE MACROS
 *
 ###########################################################*/
#ifdef DIST_ASSERTIONS
#include <assert.h>
#define assert_msg(condition, msg)  assert(condition && msg)
#define error(msg)          assert_msg(0, msg) /* always fails and prints msg */
#else
#define assert_msg(condition, msg)
#define error(msg)
#endif /* DIST_ASSERTIONS */

#if defined(DEBUG_MSG) || defined(PRINT_ERROR_MESSAGES) || !defined(PRINTING_DISABLED)
extern VAR(sint8, ANFCRL_VAR) printBuffer[];
#endif

#ifndef PRINTING_DISABLED
#include <stdio.h>

#define PRINT_SERIAL(...)                   \
{                                 \
    (void)snprintf((char *)printBuffer, 1024, __VA_ARGS__); \
    LOG_PRINTF((char *)printBuffer);          \
}

#define CONSOLE_MESSAGE(...)    PRINT_SERIAL(__VA_ARGS__)
#define CONSOLE_MESSAGE_ARGS(...) PRINT_SERIAL(__VA_ARGS__)
#define CONSOLE_MESSAGE_1(...)  PRINT_SERIAL(__VA_ARGS__)
#ifdef DIST_DEBUG
#define DEBUG_MESSAGE(...)    PRINT_SERIAL(__VA_ARGS__)
#else
#define DEBUG_MESSAGE(...)
#endif

#define RED(str)  (ANSI_COLOR_RED str ANSI_COLOR_RESET)
#define GRN(str)  (ANSI_COLOR_GREEN str ANSI_COLOR_RESET)
#define YLW(str)  (ANSI_COLOR_YELLOW str ANSI_COLOR_RESET)

#define FLUSH_STDIO()     fflush(stdout)

#else
#define FLUSH_STDIO()
#define DEBUG_ERROR_PRINT(x)
#define PRINT_SERIAL(...)
#define CONSOLE_MESSAGE(...)
#define CONSOLE_MESSAGE_1(...)
#ifdef DIST_DEBUG
#define DEBUG_MESSAGE(...)    PRINT_SERIAL(__VA_ARGS__)
#else
#define DEBUG_MESSAGE(...)
#endif
#endif /* PRINTING_DISABLED */

#ifdef PRINT_ERROR_MESSAGES
#define ERROR_MESSAGE(err)    CONSOLE_MESSAGE("ERROR: %s\n", err)
#else
#define ERROR_MESSAGE(err)
#endif /* PRINT_ERROR_MESSAGES */

#define CHECK_NFC_SUCCESS(x)                      \
    if ((x) != PH_ERR_SUCCESS)                \
{                                               \
        CONSOLE_MESSAGE("Line: %d   Error 0x%X\r\n", __LINE__, x);    \
}

#define CHECK_SUCCESS_RETURN_ERR(status)								\
	if ((status) != PH_ERR_SUCCESS)                						\
	{                                               					\
		CONSOLE_MESSAGE("Line: %d   Error 0x%X\r\n", __LINE__, status);	\
		return (DIST_RESULT_ERROR);										\
	}

#ifndef min_val
#   define min_val(X,Y) (((X) < (Y)) ? (X) : (Y))
#endif

#ifndef max_val
#   define max_val(X,Y) (((X) > (Y)) ? (X) : (Y))
#endif

/*############################################################
 *
 *                      CONSTANTS
 *
 ###########################################################*/

#define ANSI_COLOR_RED     "\x1b" "[31m"
#define ANSI_COLOR_GREEN   "\x1b" "[32m"
#define ANSI_COLOR_YELLOW  "\x1b" "[33m"
#define ANSI_COLOR_BLUE    "\x1b" "[34m"
#define ANSI_COLOR_MAGENTA "\x1b" "[35m"
#define ANSI_COLOR_CYAN    "\x1b" "[36m"
#define ANSI_COLOR_RESET   "\x1b" "[0m"

/* Note: Execution depends on order */
typedef enum
{
    DIST_ST_ERROR = 0,
    DIST_ST_RESET,
    DIST_ST_INIT,
    DIST_ST_SCAN_ALL,
    DIST_ST_ANALYZE_ALL,
    DIST_ST_SCAN_BF,
    DIST_ST_SCAN_AID,
    DIST_ST_FIELD_OFF,
    DIST_ST_LMD
} DistinguishingState_t;

typedef enum
{
	DIST_LMD_INIT = 0,
	DIST_LMD_APPLY_PROTOCOL,
	DIST_LMD_FIELD_OFF,
	DIST_LMD_WAIT_FIELD_OFF,
	DIST_LMD_FIELD_ON,
	DIST_LMD_SET_VDDPA,
	DIST_LMD_WAIT_GT,
	DIST_LMD_SEND_WUPA,
	DIST_LMD_CTS_INIT,
	DIST_LMD_UPDATE_VDDPA,
	DIST_LMD_SEND_ANTICOLLISION,
	DIST_LMD_CTS_RETRIEVE,
	DIST_LMD_FINISH
} DistinguishingLmdState_t;

typedef enum
{
	DIST_LMD_CTS_INIT_INITILIAZE = 0,
	DIST_LMD_CTS_INIT_CONFIGURE,
	DIST_LMD_CTS_INIT_ENABLE
} DistinguishingLmdCtsInitState_t;

typedef enum
{
	DIST_LMD_CTS_RETRIEVE_INIT = 0,
	DIST_LMD_CTS_CHECK_EVT,
	DIST_LMD_CTS_RETRIEVE_HEADER,
	DIST_LMD_CTS_RETRIEVE_DATA,
	DIST_LMD_CTS_PARSE_CHUNK,
	DIST_LMD_CTS_FIND_PERIODIC,
	DIST_LMD_CTS_ANALYZE_DATA
} DistinguishingLmdCtsRetrieveState_t;

typedef enum
{
    DIST_RESULT_ERROR = 0,
    DIST_RESULT_RESUME,
    DIST_RESULT_ALLOW,
    DIST_RESULT_PROHIBIT,
    DIST_RESULT_NO_RESULT,
    DIST_RESULT_IN_PROGRESS = 0xE000U
} DIST_RESULT_t;

typedef enum {
    NFC_INTF_UNDETERMINED = 0,
    NFC_INTF_FRAME,
    NFC_INTF_ISODEP,
    NFC_INTF_NFC_DEP,
    NFC_INTF_TAGCMD = 0x80
} NFC_INTF_t;

typedef enum
{
    NFC_PROT_UNDETERMINED = 0,
    NFC_PROT_T1T,
    NFC_PROT_T2T,
    NFC_PROT_T3T,
    NFC_PROT_ISODEP,
    NFC_PROT_NFCDEP,
    NFC_PROT_ISO15693,
    NFC_PROT_MIFARE = 0x80
} NFC_PROT_t;

typedef enum
{
    NFC_TECH_UNKNOWN = 0,
    NFC_TECH_A,
    NFC_TECH_B,
    NFC_TECH_F,
    NFC_TECH_15693
} NFC_TECH_t;

typedef struct
{
    VAR(uint8, ANFCRL_VAR) Uid[25];
    VAR(uint8, ANFCRL_VAR) UidLen;
    VAR(NFC_INTF_t, ANFCRL_VAR) Interface;
    VAR(NFC_PROT_t, ANFCRL_VAR) Protocol;
    VAR(NFC_TECH_t, ANFCRL_VAR) ModeTech;
} NFC_DEVICE_t;

typedef struct
{
    VAR(uint8, ANFCRL_VAR) Uid[25];
    VAR(uint8, ANFCRL_VAR) UidLen;
} NFC_STORED_UID_t;

typedef enum
{
    DIST_SUCCESS = 0,
    DIST_ERROR,
    DIST_IN_PROGRESS
} DIST_STATUS_t;

typedef enum
{
    ANALYSIS_ERROR = 0,
    ANALYZE_PASSPORT,
    ANALYZE_PATTERNS
} analyzeIndex_t;

extern VAR(NFC_DEVICE_t, ANFCRL_VAR) nfcDevice;

extern VAR(DistinguishingState_t, ANFCRL_VAR) DIST_STATE_s;

#endif /*DISTINGUISHING_TYPES_H*/
