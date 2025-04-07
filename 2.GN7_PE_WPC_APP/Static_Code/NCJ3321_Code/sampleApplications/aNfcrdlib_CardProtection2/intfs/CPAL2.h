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

#ifndef CPAL_H_2
#define CPAL_H_2

#include "distinguishing_types2.h"

#define UNUSED(param2) (void)(param2)
#define ANFCRL_VAS_ENABLED2                                                  (STD_OFF)

#if defined(ANFC_RDLIB_USED2)
typedef enum
{
    ANFC_RDLIB_ST_ERROR2 = 0,
    ANFC_RDLIB_ST_IDLE2,
    ANFC_RDLIB_ST_RESET_HIGH2,
    ANFC_RDLIB_ST_RESET_LOW2,
    ANFC_RDLIB_ST_INIT2,
    ANFC_RDLIB_ST_SEND_APDU2,
    ANFC_RDLIB_ST_RECEIVE_APDU2,
    ANFC_RDLIB_ST_START_DISCOVERY2,
    ANFC_RDLIB_ST_EXCHANGE_APDU2,
    ANFC_RDLIB_ST_CHECK_NTF2,
    ANFC_RDLIB_ST_STOP_DISCOVERY2
} aNfcRdLibState_t2;
#endif

typedef enum
{
	APPLY_PROTOCOL_SETTINGS2,
	FIELD_ON2,
	WAIT_STABLE_RF2,
	GET_HFATT2,
	FIELD_OFF2
}cleanSurfaceCalibrateState_t2;

typedef enum
{
	GET_RSSI_CONFIG2,
	GET_RSSI_LPCD2,
}cleanSurfaceGetRssiState_t2;

/* Functions called from upper layer */
extern FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_reset2(void);
extern FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_init2(void);
extern FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_scanAllTypes2(void);
extern FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_scanTypeBF2(void);
extern FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_fieldOff2(void);
extern FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_hasPassportAID2(void);

/* Internal CPAL2 functions */

#ifdef ANFC_RDLIB_USED2
FUNC(DIST_RESULT_t2, ANFCRL_CODE) scanNonBlocking2(VAR(DistinguishingState_t2, ANFCRL_VAR) DIST_STATE_c2);
FUNC(DIST_RESULT_t2, ANFCRL_CODE) scanField2(VAR(DistinguishingState_t2, ANFCRL_VAR) DIST_STATE_c2);
FUNC(DIST_RESULT_t2, ANFCRL_CODE) getFieldContent2(void);

FUNC(DIST_RESULT_t2, ANFCRL_CODE) exchangeApdu2(
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCommand2,
        VAR(uint16, ANFCRL_VAR) CommandSize2,
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pAnswer2,
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pAnswerSize2);
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
FUNC(void, ANFCRL_CODE) printErrorInfo2(VAR(uint16, ANFCRL_VAR) wStatus2);
FUNC(void, ANFCRL_CODE) printTagInfo2(VAR(uint16, ANFCRL_VAR) wTagsDetected2);
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#endif

#endif /* CPAL_H_2 */
