/*******************************************************************************
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2018 - 2020
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

#ifndef PH_COMMON_H_
#define PH_COMMON_H_

/* Status header */
#include <ph_Status.h>

/* Driver Header */
#include <phDriver.h>

/* NFCLIB Header */
#include <phNfcLib.h>

/* Discovery Loop Header */
#include <phacDiscLoop.h>

// #include "BoardSelection.h"   /* NIDEC_PORTING */

#ifdef   DEBUG
#include <stdio.h>
#define  DEBUG_PRINTF(...) (void)printf(__VA_ARGS__); (void)fflush(stdout)
#define  DEBUG_SCANF(...) (void)scanf(__VA_ARGS__); (void)fflush(stdin)
#else /* DEBUG */
#define  DEBUG_PRINTF(...)
#define  DEBUG_SCANF(...)
#endif /* DEBUG */

/*******************************************************************************
**   Global Variable Declaration
*******************************************************************************/
extern VAR(phbalReg_Type_t, ANFCRL_VAR) sBalParams;

extern CONST(char, ANFCRL_CONST) pCheckStatus[];
extern CONST(char, ANFCRL_CONST) pCheckSuccess[];
extern CONST(char, ANFCRL_CONST) pCheckNfclibStatus[];

#ifdef NXPBUILD__PHHAL_HW_NCX3321
extern P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pHal;
#endif

/**
 * \brief Sample Application parameter structure
 * \details The structure stores all of pointers, point to components dataparams.
 * \anchor phApp_Sw_DataParams_t
 */
typedef struct
{
    VAR(uint8, ANFCRL_VAR) bLpcdEnabled; /**< Enable/Disable Low Power Card Detection. */

    VAR(uint8, ANFCRL_VAR) bOpeMode; /**< Operation mode of discovery loop. */

    VAR(uint8, ANFCRL_VAR) bNumOfCards; /**< Number of cards detected. */

    VAR(phStatus_t, ANFCRL_VAR) wErrorCode; /**< Hold error received from lower layer */

    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalParams;      /**< Pointer to the BAL data parameter. */

#ifdef NXPBUILD__PH_KEYSTORE_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreParams; /**< Pointer to the KeyStore data parameter. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyEntriesParams; /**< Pointer to the Key Entries data parameter. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKUCEntriesParams; /**< Pointer to the KUC Entries data parameter. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVerPairsParams; /**< Pointer to the Key Version Pairs data parameter. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyArray;      /**< Pointer to the Key array. */
#endif
#ifdef NXPBUILD__PH_CRYPTOSYM
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoSymParams;  /**< Pointer to the CryptoSym data parameter. */
#endif
#ifdef NXPBUILD__PHPAL_I14443P3A_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPal14443p3aParams;  /**< Pointer to the 14443P3A layer PAL data parameter. */
#endif
#ifdef NXPBUILD__PHPAL_I14443P3B_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPal14443p3bParams;  /**< Pointer to the 14443P3B layer PAL data parameter. */
#endif
#ifdef NXPBUILD__PHPAL_I14443P4_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPal14443p4Params;  /**< Pointer to the 14443P4 PAL data parameter. */
#endif
#ifdef NXPBUILD__PHPAL_I14443P4A_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPal14443p4aParams;  /**< Pointer to the 14443P4A PAL data parameter. */
#endif
#ifdef NXPBUILD__PHPAL_MIFARE_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareParams;  /**< Pointer to the PAL MIFARE data parameter. */
#endif
#ifdef NXPBUILD__PHPAL_FELICA_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalFelicaParams;  /**< Pointer to the FELICA PAL data parameter. */
#endif
#ifdef NXPBUILD__PHPAL_SLI15693_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPal15693Params;    /**< Pointer to the 15693 PAL data parameter. */
#endif
#ifdef NXPBUILD__PHAL_FELICA_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pAlFelicaParams;    /**< Pointer to the FELICA AL data parameter. */
#endif
#ifdef NXPBUILD__PHAL_ICODE_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pAlICodeParams;    /**< Pointer to the 15693 AL ICode data parameter. */
#endif
#ifdef NXPBUILD__PHAL_MFDF_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pAlMfdfDataParams;  /**< Pointer to the MIFARE DESFire data parameter.*/
#endif
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) palMfdfEVxParams;  /**< Pointer to the MIFARE DESFire EVx data parameter.*/
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_SW
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoopParams;
#endif

} phApp_Sw_DataParams_t;

/*******************************************************************************
 **   SECTION: PLATFORM Definition
 *******************************************************************************/

FUNC(phStatus_t, ANFCRL_CODE) phPlatform_Init(void);
#ifdef NXPBUILD__PH_LOG_EX
FUNC(phStatus_t, ANFCRL_CODE) phPlatform_Log_DeInit(void);
#endif /* NXPBUILD__PH_LOG_EX */

/*******************************************************************************
**   SECTION: SYSTEM TICK functions
*******************************************************************************/

#ifdef PHDRIVER_S32K312
FUNC(void, ANFCRL_CODE) SysTick_Handler(void);
#endif
FUNC(uint32, ANFCRL_CODE) phGetCurrentTickCount(void);
FUNC(phStatus_t, ANFCRL_CODE) phApp_ConfigureLPCD(void);
FUNC(phStatus_t, ANFCRL_CODE) phApp_Configure_IRQ(void);
FUNC(void, ANFCRL_CODE) CLIF_IRQHandler(void);

#ifdef NXPBUILD__PHHAL_HW_NCX3321
FUNC(void, ANFCRL_CODE) phApp_IrqPolling(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);
FUNC(phStatus_t, ANFCRL_CODE) phApp_CheckAbort(void);
FUNC(void, ANFCRL_CODE) phApp_CallBack(void);
FUNC(phStatus_t, ANFCRL_CODE) phApp_Ncx3321_SPIRead(
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer, VAR(uint16, ANFCRL_VAR) wRxLength);
#endif
/*******************************************************************************
 **   SECTION: HELPER definitions
 *******************************************************************************/
FUNC(void, ANFCRL_CODE) phApp_Print_Buff(
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuff, VAR(uint8, ANFCRL_VAR) num);
#ifdef NXPBUILD__PH_LOG_EX
FUNC(void, ANFCRL_CODE) phDriver_UARTPutSTR(P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) msg);
#endif  /*NXPBUILD__PH_LOG_EX*/
/**************************************************Prints if error is detected**************************************************************/
/* Enable(1) / Disable(0) printing error/info */
#define DETECT_ERROR 0

#if DETECT_ERROR
#define DEBUG_ERROR_PRINT(x) x
#define PRINT_INFO(...) DEBUG_PRINTF(__VA_ARGS__)
#else
#define DEBUG_ERROR_PRINT(x)
#define PRINT_INFO(...)
#endif

/**< This macro end function by return if the return value is equal PH_STATUS_INPROCESS .*/ /**
*/
#define CHECK_INPROCESS_FCT(status,fct)         {(status) = (fct); if ((status) == PH_STATUS_INPROCESS) {return;}}
/**< This macro check if status is not equal PH_ERR_SUCCES then call 'break' statement. */ /**
 */
#define CHECK_BREAK_ON_FAILURE(status)     {if (((status) & PH_ERR_MASK) != PH_ERR_SUCCESS) {break;}}

#define CHECK_STATUS(x)                                      \
    if ((x) != PH_ERR_SUCCESS)                               \
{                                                            \
    DEBUG_PRINTF(pCheckStatus, __LINE__, (x));    \
}

/* prints if error is detected */
#define CHECK_SUCCESS(x)              \
    if ((x) != PH_ERR_SUCCESS)        \
{                                     \
    DEBUG_PRINTF(pCheckSuccess, __LINE__, (x)); \
}

/* prints if error is detected */
#define CHECK_NFCLIB_STATUS(x)                               \
    if ((x) != PH_NFCLIB_STATUS_SUCCESS)                     \
{                                                            \
    DEBUG_PRINTF(pCheckNfclibStatus, __LINE__, (x)); \
}

#endif /* PH_COMMON_H_ */
