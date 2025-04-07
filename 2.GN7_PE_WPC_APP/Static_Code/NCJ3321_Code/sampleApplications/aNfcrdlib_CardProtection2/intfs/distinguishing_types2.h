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

#ifndef DISTINGUISHING_TYPES_H2
#define DISTINGUISHING_TYPES_H2

#include <ph_Status2.h>
#include <phApp_Init2.h>

#include <phNfcLib2.h>
#include <string.h>
#include "phLog2.h"

#define S32K144

#define ANFC_RDLIB_USED2

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
#define PRINT_ERROR_MESSAGES2    /* print error2 messages */

/*############################################################
 *
 *                  FUNCTION-LIKE MACROS
 *
 ###########################################################*/
#ifdef DIST_ASSERTIONS2
#include <assert.h>
#define assert_msg2(condition2, msg2)  assert2(condition2 && msg2)
#define error2(msg2)          assert_msg2(0, msg2) /* always fails and prints msg2 */
#else
#define assert_msg2(condition2, msg2)
#define error2(msg2)
#endif /* DIST_ASSERTIONS2 */

#if defined(DEBUG_MSG2) || defined(PRINT_ERROR_MESSAGES2) || !defined(PRINTING_DISABLED2)
extern VAR(sint8, ANFCRL_VAR) printBuffer2[];
#endif

#ifndef PRINTING_DISABLED2
#include <stdio.h>

#define PRINT_SERIAL2(...)                   \
{                                 \
    (void)snprintf((char *)printBuffer2, 1024, __VA_ARGS__); \
    LOG_PRINTF((char *)printBuffer2);          \
}

#define CONSOLE_MESSAGE2(...)    PRINT_SERIAL2(__VA_ARGS__)
#define CONSOLE_MESSAGE_ARGS2(...) PRINT_SERIAL2(__VA_ARGS__)
#define CONSOLE_MESSAGE_12(...)  PRINT_SERIAL2(__VA_ARGS__)
#ifdef DIST_DEBUG2
#define DEBUG_MESSAGE2(...)    PRINT_SERIAL2(__VA_ARGS__)
#else
#define DEBUG_MESSAGE2(...)
#endif

#define RED2(str2)  (ANSI_COLOR_RED str ANSI_COLOR_RESET)
#define GRN2(str2)  (ANSI_COLOR_GREEN str ANSI_COLOR_RESET)
#define YLW2(str2)  (ANSI_COLOR_YELLOW str ANSI_COLOR_RESET)

#define FLUSH_STDIO2()     fflush(stdout)

#else
#define FLUSH_STDIO2()
#define DEBUG_ERROR_PRINT2(x)
#define PRINT_SERIAL2(...)
#define CONSOLE_MESSAGE2(...)
#define CONSOLE_MESSAGE_12(...)
#ifdef DIST_DEBUG2
#define DEBUG_MESSAGE2(...)    PRINT_SERIAL2(__VA_ARGS__)
#else
#define DEBUG_MESSAGE2(...)
#endif
#endif /* PRINTING_DISABLED2 */

#ifdef PRINT_ERROR_MESSAGES2
#define ERROR_MESSAGE(err)    CONSOLE_MESSAGE2("ERROR: %s\n", err)
#else
#define ERROR_MESSAGE(err)
#endif /* PRINT_ERROR_MESSAGES2 */

#define CHECK_NFC_SUCCESS2(x)                      \
    if ((x) != PH_ERR_SUCCESS2)                \
{                                               \
        CONSOLE_MESSAGE2("Line: %d   Error 0x%X\r\n", __LINE__, x);    \
}

#define CHECK_SUCCESS_RETURN_ERR2(status2)								\
	if ((status2) != PH_ERR_SUCCESS2)                						\
	{                                               					\
		CONSOLE_MESSAGE2("Line: %d   Error 0x%X\r\n", __LINE__, status2);	\
		return (DIST_RESULT_ERROR2);										\
	}

#ifndef min_val2
#   define min_val2(X2,Y2) (((X2) < (Y2)) ? (X2) : (Y2))
#endif

#ifndef max_val2
#   define max_val2(X2,Y2) (((X2) > (Y2)) ? (X2) : (Y2))
#endif

/*############################################################
 *
 *                      CONSTANTS
 *
 ###########################################################*/

#define ANSI_COLOR_RED2     "\x1b" "[31m"
#define ANSI_COLOR_GREEN2   "\x1b" "[32m"
#define ANSI_COLOR_YELLOW2  "\x1b" "[33m"
#define ANSI_COLOR_BLUE2    "\x1b" "[34m"
#define ANSI_COLOR_MAGENTA2 "\x1b" "[35m"
#define ANSI_COLOR_CYAN2    "\x1b" "[36m"
#define ANSI_COLOR_RESET2   "\x1b" "[0m"

/* Note: Execution depends on order */
typedef enum
{
    DIST_ST_ERROR2 = 0,
    DIST_ST_RESET2,
    DIST_ST_INIT2,
    DIST_ST_SCAN_ALL2,
    DIST_ST_ANALYZE_ALL2,
    DIST_ST_SCAN_BF2,
    DIST_ST_SCAN_AID2,
    DIST_ST_FIELD_OFF2,
    DIST_ST_LMD2
} DistinguishingState_t2;

typedef enum
{
	DIST_LMD_INIT2 = 0,
	DIST_LMD_APPLY_PROTOCOL2,
	DIST_LMD_FIELD_OFF2,
	DIST_LMD_WAIT_FIELD_OFF2,
	DIST_LMD_FIELD_ON2,
	DIST_LMD_SET_VDDPA2,
	DIST_LMD_WAIT_GT2,
	DIST_LMD_SEND_WUPA2,
	DIST_LMD_CTS_INIT2,
	DIST_LMD_UPDATE_VDDPA2,
	DIST_LMD_SEND_ANTICOLLISION2,
	DIST_LMD_CTS_RETRIEVE2,
	DIST_LMD_FINISH2
} DistinguishingLmdState_t2;

typedef enum
{
	DIST_LMD_CTS_INIT_INITILIAZE2 = 0,
	DIST_LMD_CTS_INIT_CONFIGURE2,
	DIST_LMD_CTS_INIT_ENABLE2
} DistinguishingLmdCtsInitState_t2;

typedef enum
{
	DIST_LMD_CTS_RETRIEVE_INIT2 = 0,
	DIST_LMD_CTS_CHECK_EVT2,
	DIST_LMD_CTS_RETRIEVE_HEADER2,
	DIST_LMD_CTS_RETRIEVE_DATA2,
	DIST_LMD_CTS_PARSE_CHUNK2,
	DIST_LMD_CTS_FIND_PERIODIC2,
	DIST_LMD_CTS_ANALYZE_DATA2
} DistinguishingLmdCtsRetrieveState_t2;

typedef enum
{
    DIST_RESULT_ERROR2 = 0,
    DIST_RESULT_RESUME2,
    DIST_RESULT_ALLOW2,
    DIST_RESULT_PROHIBIT2,
    DIST_RESULT_NO_RESULT2,
    DIST_RESULT_IN_PROGRESS2 = 0xE000U
} DIST_RESULT_t2;

typedef enum {
    NFC_INTF_UNDETERMINED2 = 0,
    NFC_INTF_FRAME2,
    NFC_INTF_ISODEP2,
    NFC_INTF_NFC_DEP2,
    NFC_INTF_TAGCMD2 = 0x80
} NFC_INTF_t2;

typedef enum
{
    NFC_PROT_UNDETERMINED2 = 0,
    NFC_PROT_T1T2,
    NFC_PROT_T2T2,
    NFC_PROT_T3T2,
    NFC_PROT_ISODEP2,
    NFC_PROT_NFCDEP2,
    NFC_PROT_ISO156932,
    NFC_PROT_MIFARE2 = 0x80
} NFC_PROT_t2;

typedef enum
{
    NFC_TECH_UNKNOWN2 = 0,
    NFC_TECH_A2,
    NFC_TECH_B2,
    NFC_TECH_F2,
    NFC_TECH_156932
} NFC_TECH_t2;

typedef struct
{
    VAR(uint8, ANFCRL_VAR) Uid2[25];
    VAR(uint8, ANFCRL_VAR) UidLen2;
    VAR(NFC_INTF_t2, ANFCRL_VAR) Interface2;
    VAR(NFC_PROT_t2, ANFCRL_VAR) Protocol2;
    VAR(NFC_TECH_t2, ANFCRL_VAR) ModeTech2;
} NFC_DEVICE_t2;

typedef struct
{
    VAR(uint8, ANFCRL_VAR) Uid2[25];
    VAR(uint8, ANFCRL_VAR) UidLen2;
} NFC_STORED_UID_t2;

typedef enum
{
    DIST_SUCCESS2 = 0,
    DIST_ERROR2,
    DIST_IN_PROGRESS2
} DIST_STATUS_t2;

typedef enum
{
    ANALYSIS_ERROR2 = 0,
    ANALYZE_PASSPORT2,
    ANALYZE_PATTERNS2
} analyzeIndex_t2;

extern VAR(NFC_DEVICE_t2, ANFCRL_VAR) nfcDevice2;

extern VAR(DistinguishingState_t2, ANFCRL_VAR) DIST_STATE_s2;

#endif /*DISTINGUISHING_TYPES_H2*/
