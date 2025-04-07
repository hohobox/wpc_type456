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

/*
 * This file contains the implementation of the distinguishing algorithm.
 * dinstinguishing.h contains some data structures required in this file.
 */

#ifndef CPAL_H_
#define CPAL_H_

#include "distinguishing_types.h"

#define UNUSED(param) (void)(param)
#define ANFCRL_VAS_ENABLED                                                  (STD_OFF)

#if defined(ANFC_RDLIB_USED)
typedef enum
{
    ANFC_RDLIB_ST_ERROR = 0,
    ANFC_RDLIB_ST_IDLE,
    ANFC_RDLIB_ST_RESET_HIGH,
    ANFC_RDLIB_ST_RESET_LOW,
    ANFC_RDLIB_ST_INIT,
    ANFC_RDLIB_ST_SEND_APDU,
    ANFC_RDLIB_ST_RECEIVE_APDU,
    ANFC_RDLIB_ST_START_DISCOVERY,
    ANFC_RDLIB_ST_EXCHANGE_APDU,
    ANFC_RDLIB_ST_CHECK_NTF,
    ANFC_RDLIB_ST_STOP_DISCOVERY
} aNfcRdLibState_t;
#endif

typedef enum
{
	APPLY_PROTOCOL_SETTINGS,
	FIELD_ON,
	WAIT_STABLE_RF,
	GET_HFATT,
	FIELD_OFF
}cleanSurfaceCalibrateState_t;

typedef enum
{
	GET_RSSI_CONFIG,
	GET_RSSI_LPCD,
}cleanSurfaceGetRssiState_t;

/* Functions called from upper layer */
extern FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_reset(void);
extern FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_init(void);
extern FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_scanAllTypes(void);
extern FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_scanTypeBF(void);
extern FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_fieldOff(void);
extern FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_hasPassportAID(void);

/* Internal CPAL functions */

#ifdef ANFC_RDLIB_USED
FUNC(DIST_RESULT_t, ANFCRL_CODE) scanNonBlocking(VAR(DistinguishingState_t, ANFCRL_VAR) DIST_STATE_c);
FUNC(DIST_RESULT_t, ANFCRL_CODE) scanField(VAR(DistinguishingState_t, ANFCRL_VAR) DIST_STATE_c);
FUNC(DIST_RESULT_t, ANFCRL_CODE) getFieldContent(void);

FUNC(DIST_RESULT_t, ANFCRL_CODE) exchangeApdu(
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCommand,
        VAR(uint16, ANFCRL_VAR) CommandSize,
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pAnswer,
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pAnswerSize);
#ifdef NXPBUILD__PHAC_DISCLOOP_SW
FUNC(void, ANFCRL_CODE) printErrorInfo(VAR(uint16, ANFCRL_VAR) wStatus);
FUNC(void, ANFCRL_CODE) printTagInfo(VAR(uint16, ANFCRL_VAR) wTagsDetected);
#endif /* NXPBUILD__PHAC_DISCLOOP_SW */

#endif

#endif /* CPAL_H_ */
