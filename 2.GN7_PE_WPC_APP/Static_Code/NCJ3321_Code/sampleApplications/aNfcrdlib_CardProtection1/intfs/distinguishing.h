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

#ifndef DISTINGUISHING_H
#define DISTINGUISHING_H

#include <ph_Status.h>
#include <phApp_Init.h>

#include "distinguishing_types.h"
#include "CPAL.h"

/*********** Card Protection with LMD Configuration ***********/

/* If defined, the software will add a delay after each execution to analyze UART output */
#define DEBUG_DELAY_NEXT_LOOP				(STD_ON)

/* If defined, the software will print the received CTS data on UART */
#define DEBUG_PRINT_CTS_DATA				(STD_OFF)

/* Clean surface - in case of prohibit check if device was removed before running card protection again */
#define CLEAN_SURFACE_CHECK					(STD_OFF)
#define CLEAN_SURFACE_CALIBRATE				(STD_OFF)
#define CLEAN_SURFACE_HFATT_THRESHOLD		2

/* Check if there are devices emulating multiple technologies with conclusion that this is a phone */
#define CHECK_MULTI_TECH_SUPPORT			(STD_OFF)   // Type A Detect Only

/* Enable fast CTS command if supported in firmware */
#define FAST_CTS_EXECUTION					(STD_OFF)

/* Load Modulation Detection algorithm */
#define PAGE_SIZE 							1024 /* Number of bytes acquired from the CTS log */

/* Threshold for the peak to peak amplitude ratio to be used to distinguish between card and phone */
#define AMPLITUDE_CHANGE_THRESHOLD  		15

/* Phase shift detection thresholds */
#define PHASE_DIFFERENT_THRESHOLD 			60

/* Check for saturated I and Q values */
#define CHECK_SATURATED_IQ					(STD_ON)
#define NUM_SATURATED_IQ_THRESHOLD			30

/* Low and high value for the VDDPA used during LMD analysis */
#define LMD_VDDPA_HIGH 						0x20
#define LMD_VDDPA_LOW 						0x00

/*********** Card Protection with LMD Configuration ***********/

#define NUM_SAMPLES 						PAGE_SIZE / 4 /* Number of I and Q samples, 2 bytes per I sample + 2 bytes per Q sample */
#define CHUNK_SIZE 							128

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_run(void);
FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_run_CleanSurface(void);

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_analyzeResults(void);
FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_analyzeTypeA(void);
FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_analyzeTypeF(void);

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_recoverDigitalTypeA(void);

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_CheckPAD0(CONST(uint8, ANFCRL_CONST) pad0_1);

#ifdef HISTBYTES
FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_Helper_CheckHistBytes_NFCA_T4(void);
#endif

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_Assume_NoPatterns(void);
FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_FindPatterns(CONST(uint8, ANFCRL_CONST) ID[], CONST(uint8, ANFCRL_CONST) ID_LEN);

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_LMD(void);
FUNC(DIST_RESULT_t, ANFCRL_CODE) CtsRetrieve(int32_t * peak_to_peak, int32_t * phase, uint8_t vddpa);
FUNC(phStatus_t, ANFCRL_CODE) CtsInit(void);

void RemoveDcValue(sint16 *originals);
int32_t FindDcValue(sint16 diffdata[], sint16 original[]);
void FindPeriodicalSignal(sint16 raw_values[], uint32_t length, uint32_t *start, uint32_t *end, int32_t *peak_to_peak_value);

FUNC(phStatus_t, ANFCRL_CODE) Dist_cleanSurfaceGetHfAtt(uint8 *hfAtt);

/* Helper functions */
int32_t FindMax(sint16 array[], uint32_t start, uint32_t end);
int32_t FindMaxIndex(sint16 array[], uint32_t start, uint32_t end);
int32_t FindMin(sint16 array[], uint32_t start, uint32_t end);

#endif /*DISTINGUISHING_H*/
