/*******************************************************************************
 * (c) NXP Semiconductors
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2018 - 2023
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

#include <phApp_Init.h>
#include <Nfcrdlib_Detect_Card.h>
#include <phacDiscLoop.h>
#include <phTools.h>
#include "distinguishing.h"

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
// #include "phhalHw_Ncx3321.h"
#include "App_NFC.h"

#include <Nfcrdlib.h>

// #define RTE_ALLOW_CROSS_HEADER_INCLUSION
// #include "Rte_IoHwAb.h"
// #include "Rte_App_CAN_RX.h"

#elif defined (CPU_S32K144HFT0VLLT)
#include <pcc_hw_access.h>

#endif	/* NIDEC_PORTING */


#define LPCD_ENABLE

#define TASK_DELAY	//WTK 20240905

#define PH_NXPNFCRDLIB_CONFIG_TYPEV_GT                           5200U    /**< Guard time configuration for Type V poll in Micro seconds.*/

typedef enum
{
    ANFC_DISCLOOP_Init = 0,
    ANFC_DISCLOOP_While_Loop = 1,
    ANFC_DISCLOOP_Configure_LPCD = 2,
    ANFC_DISCLOOP_Run = 3,
    ANFC_DISCLOOP_ActivateCard = 4,
    ANFC_DISCLOOP_Sample_Task,
} ANFC_BASIC_DISCLOOP_StateType_t;

//static VAR(uint8, ANFCRL_VAR) led_flag = COLOR_NONE;

#ifdef NXPBUILD__PHAC_DISCLOOP_SW
static P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoop_CardProtection; /* Discovery loop component */
#endif

VAR(uint8, ANFCRL_VAR) bLenUid = 0u;
VAR(uint8, ANFCRL_VAR) bMoreCards = 0u;
VAR(uint8, ANFCRL_VAR) pPupiNum[32] = { 0x00u };

static VAR(phApp_Sw_DataParams_t, ANFCRL_VAR) sSampleApp;
static VAR(DIST_RESULT_t, ANFCRL_VAR) distRet = DIST_RESULT_NO_RESULT;


/******************************************************************************
 **                            End Of File
 ******************************************************************************/
