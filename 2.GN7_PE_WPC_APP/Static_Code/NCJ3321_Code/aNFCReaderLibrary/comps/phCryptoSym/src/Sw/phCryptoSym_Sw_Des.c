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
*   @file    phCryptoSym_Sw_Des.c
*   @version 1.0.0
*
*   @brief   AUTOSAR CryptoSym - COMMON API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phCryptoSym CryptoSym
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
#include <phCryptoSym.h>

#ifdef NXPBUILD__PH_CRYPTOSYM_SW

#ifdef PH_CRYPTOSYM_SW_DES

#include "phCryptoSym_Sw_Des.h"
#include "phCryptoSym_Sw_Des_Int.h"
#include "../phCryptoSym_Int.h"
#endif /* PH_CRYPTOSYM_SW_DES */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phCryptoSym_Sw_Des.c
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTOSYM_SW_DES_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTOSYM_SW_DES_AR_RELEASE_MAJOR_VERSION_C       4         /**< @brief AUTOSAR release major version*/
#define PHCRYPTOSYM_SW_DES_AR_RELEASE_MINOR_VERSION_C       3         /**< @brief AUTOSAR release minor version*/
#define PHCRYPTOSYM_SW_DES_AR_RELEASE_REVISION_VERSION_C    1         /**< @brief AUTOSAR release revision*/
#define PHCRYPTOSYM_SW_DES_SW_MAJOR_VERSION_C               1              /**< @brief The major version of the SW module*/
#define PHCRYPTOSYM_SW_DES_SW_MINOR_VERSION_C               0              /**< @brief The minor version of the SW module*/
#define PHCRYPTOSYM_SW_DES_SW_PATCH_VERSION_C               0              /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phCryptoSym_Sw_Des.h header file are of the same vendor */
#if (PHCRYPTOSYM_SW_DES_VENDOR_ID_C != PHCRYPTOSYM_SW_DES_VENDOR_ID)
    #error "phCryptoSym_Sw_Des.c and phCryptoSym_Sw_Des.h have different vendor ids"
#endif
/* Check if current file and phCryptoSym_Sw_Des.h header file are of the same Autosar version */
#if ((PHCRYPTOSYM_SW_DES_AR_RELEASE_MAJOR_VERSION_C    != PHCRYPTOSYM_SW_DES_AR_RELEASE_MAJOR_VERSION) || \
     (PHCRYPTOSYM_SW_DES_AR_RELEASE_MINOR_VERSION_C    != PHCRYPTOSYM_SW_DES_AR_RELEASE_MINOR_VERSION) || \
     (PHCRYPTOSYM_SW_DES_AR_RELEASE_REVISION_VERSION_C != PHCRYPTOSYM_SW_DES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoSym_Sw_Des.c and phCryptoSym_Sw_Des.h are different"
#endif
/* Check if current file and phCryptoSym_Sw_Des.h header file are of the same Software version */
#if ((PHCRYPTOSYM_SW_DES_SW_MAJOR_VERSION_C != PHCRYPTOSYM_SW_DES_SW_MAJOR_VERSION) || \
     (PHCRYPTOSYM_SW_DES_SW_MINOR_VERSION_C != PHCRYPTOSYM_SW_DES_SW_MINOR_VERSION) || \
     (PHCRYPTOSYM_SW_DES_SW_PATCH_VERSION_C != PHCRYPTOSYM_SW_DES_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoSym_Sw_Des.c and phCryptoSym_Sw_Des.h are different"
#endif
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
#ifdef PH_CRYPTOSYM_SW_DES

#define MASK6       0x3FU

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHCRYPTOSYM_SW_DES_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCRYPTOSYM_SW_DES_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static CONST(uint8, ANFCRL_CONST) PH_CRYPTOSYM_SW_CONST_ROM key_rotation[16] =
{
    1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

static CONST(uint8, ANFCRL_CONST) PH_CRYPTOSYM_SW_CONST_ROM SBOX[8][64] =
{
    {   14, 4,13, 1, 2,15,11, 8, 3,10, 6,12, 5, 9, 0, 7,
    0,15, 7, 4,14, 2,13, 1,10, 6,12,11, 9, 5, 3, 8,
    4, 1,14, 8,13, 6, 2,11,15,12, 9, 7, 3,10, 5, 0,
    15,12, 8, 2, 4, 9, 1, 7, 5,11, 3,14,10, 0, 6,13
    },
    {   15, 1, 8,14, 6,11, 3, 4, 9, 7, 2,13,12, 0, 5,10,
    3,13, 4, 7,15, 2, 8,14,12, 0, 1,10, 6, 9,11, 5,
    0,14, 7,11,10, 4,13, 1, 5, 8,12, 6, 9, 3, 2,15,
    13, 8,10, 1, 3,15, 4, 2,11, 6, 7,12, 0, 5,14, 9
    },
    {   10, 0, 9,14, 6, 3,15, 5, 1,13,12, 7,11, 4, 2, 8,
    13, 7, 0, 9, 3, 4, 6,10, 2, 8, 5,14,12,11,15, 1,
    13, 6, 4, 9, 8,15, 3, 0,11, 1, 2,12, 5,10,14, 7,
    1,10,13, 0, 6, 9, 8, 7, 4,15,14, 3,11, 5, 2,12
    },
    {    7,13,14, 3, 0, 6, 9,10, 1, 2, 8, 5,11,12, 4,15,
    13, 8,11, 5, 6,15, 0, 3, 4, 7, 2,12, 1,10,14, 9,
    10, 6, 9, 0,12,11, 7,13,15, 1, 3,14, 5, 2, 8, 4,
    3,15, 0, 6,10, 1,13, 8, 9, 4, 5,11,12, 7, 2,14
    },
    {    2,12, 4, 1, 7,10,11, 6, 8, 5, 3,15,13, 0,14, 9,
    14,11, 2,12, 4, 7,13, 1, 5, 0,15,10, 3, 9, 8, 6,
    4, 2, 1,11,10,13, 7, 8,15, 9,12, 5, 6, 3, 0,14,
    11, 8,12, 7, 1,14, 2,13, 6,15, 0, 9,10, 4, 5, 3
    },
    {   12, 1,10,15, 9, 2, 6, 8, 0,13, 3, 4,14, 7, 5,11,
    10,15, 4, 2, 7,12, 9, 5, 6, 1,13,14, 0,11, 3, 8,
    9,14,15, 5, 2, 8,12, 3, 7, 0, 4,10, 1,13,11, 6,
    4, 3, 2,12, 9, 5,15,10,11,14, 1, 7, 6, 0, 8,13,
    },
    {    4,11, 2,14,15, 0, 8,13, 3,12, 9, 7, 5,10, 6, 1,
    13, 0,11, 7, 4, 9, 1,10,14, 3, 5,12, 2,15, 8, 6,
    1, 4,11,13,12, 3, 7,14,10,15, 6, 8, 0, 5, 9, 2,
    6,11,13, 8, 1, 4,10, 7, 9, 5, 0,15,14, 2, 3,12
    },
    {   13, 2, 8, 4, 6,15,11, 1,10, 9, 3,14, 5, 0,12, 7,
    1,15,13, 8,10, 3, 7, 4,12, 5, 6,11, 0,14, 9, 2,
    7,11, 4, 1, 9,12,14, 2, 0, 6,10,13,15, 3, 5, 8,
    2, 1,14, 7, 4,10, 8,13,15,12, 9, 0, 3, 5, 6,11
    }
};

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHCRYPTOSYM_SW_DES_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCRYPTOSYM_SW_DES_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHCRYPTOSYM_SW_DES_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCRYPTOSYM_SW_DES_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE)  phCryptoSym_Sw_Des_KeyInit(
                                       P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pKey,
                                       VAR(uint8, ANFCRL_VAR) bNumKeys
                                       )
{

#ifndef  PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
    VAR(uint8, ANFCRL_VAR) i;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDestinationKey = NULL;
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM bTmpKey[PH_CRYPTOSYM_DES_KEY_SIZE];

    /* Set the pKey to the end of the potential Secret key as in this array the key expansion is performed */
    while(bNumKeys--)
    {
        /* take the key, starting with the last one */

        /* Set base address of key array to the correct offset within the round key array, which is 16*8*bNumKeys =  */
        pDestinationKey = &pDataParams->pKey[bNumKeys << 7U];
        phCryptoSym_Sw_Des_PC1_Permutation(&pKey[bNumKeys << 3U], bTmpKey);

        for (i = 0; i < 16U; i++)
        {
            phCryptoSym_Sw_Des_RotateLeft28(bTmpKey, key_rotation[i]);
            phCryptoSym_Sw_Des_RotateLeft28(&bTmpKey[4], key_rotation[i]);
            phCryptoSym_Sw_Des_PC2_Permutation(bTmpKey , &pDestinationKey[i<<3U]);
        }
    }

    /* Clear TmpKey */
    (void)memset(bTmpKey, 0x00, (size_t)sizeof(bTmpKey));
#else
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM bTmpKey[PH_CRYPTOSYM_DES_KEY_SIZE];
#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */

    /* In case of online key expansion we only calculate P1 in this step*/
    while(0u != bNumKeys--)
    {
        /* take the key, starting with the last one and write the result to the internal keybuffer. */
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
        phCryptoSym_Sw_Des_PC1_Permutation(&pKey[bNumKeys << 3U], bTmpKey);
        (void)memcpy(&pDataParams->pKey[bNumKeys << 3U], bTmpKey, PH_CRYPTOSYM_DES_KEY_SIZE);
#else
        phCryptoSym_Sw_Des_PC1_Permutation(&pKey[bNumKeys << 3U], &pDataParams->pKey[bNumKeys << 3U]);
#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */
    }

#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
    /* Clear TmpKey */
    (void)memset(bTmpKey, 0x00, (size_t)sizeof(bTmpKey));
#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE)  phCryptoSym_Sw_Des_EncryptBlock(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pBlock,
    VAR(uint8, ANFCRL_VAR) bKeyNumber
    )
{
    VAR(uint8, ANFCRL_VAR) i;
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM pTmp[PH_CRYPTOSYM_DES_BLOCK_SIZE];
#ifdef  PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pKey;
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM pTmpKey[PH_CRYPTOSYM_DES_KEY_SIZE];
#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */
#else
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey = NULL;
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */

    /* Set the pKey to the correct position according to the key number provided */
#ifndef  PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
    pKey = &pDataParams->pKey[bKeyNumber << 7U];
#else
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
    (void)memcpy(pTmpKey, &pDataParams->pKey[(bKeyNumber << 3U)], PH_CRYPTOSYM_DES_KEY_SIZE);
    pKey = pTmpKey;
#else
    pKey = &pDataParams->pKey[(bKeyNumber << 3U)];
#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */

    phCryptoSym_Sw_Des_Permutate_IP(pBlock, pTmp);

    for (i = 0; i < 16U; i++)
    {
#ifdef  PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
        phCryptoSym_Sw_Des_RotateLeft28(pKey, key_rotation[i]);
        phCryptoSym_Sw_Des_RotateLeft28(&pKey[4], key_rotation[i]);
        phCryptoSym_Sw_Des_PC2_Permutation(pKey , &pDataParams->pKey[PH_CRYPTOSYM_3K3DES_KEY_SIZE]);
        phCryptoSym_Sw_Des_ComputeRound(pTmp, &pDataParams->pKey[PH_CRYPTOSYM_3K3DES_KEY_SIZE]);
#else
        phCryptoSym_Sw_Des_ComputeRound(pTmp, &pKey[i << 3U]);
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */
    }

    phCryptoSym_Sw_Des_Swap(pTmp);

    phCryptoSym_Sw_Des_Permutate_IP_Inv(pTmp, pBlock);

#ifdef  PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
    /* Clear TmpKey */
    (void)memset(pTmpKey, 0x00, (size_t)sizeof(pTmpKey));
#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */
    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE)  phCryptoSym_Sw_Des_DecryptBlock(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pBlock,
    VAR(uint8, ANFCRL_VAR) bKeyNumber
    )
{
    VAR(uint8, ANFCRL_VAR) i;
#ifdef  PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pKey;
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM pTmpKey[PH_CRYPTOSYM_DES_KEY_SIZE];
#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */
#else
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey = NULL;
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM pTmpBlock[PH_CRYPTOSYM_DES_BLOCK_SIZE];
    /* Set the pKey to the correct position according to the key number provided */
#ifndef  PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
    pKey = &pDataParams->pKey[bKeyNumber << 7U];
#else
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
    (void)memcpy(pTmpKey, &pDataParams->pKey[(bKeyNumber << 3U)], PH_CRYPTOSYM_DES_KEY_SIZE);
    pKey = pTmpKey;
#else
    pKey = &pDataParams->pKey[(bKeyNumber << 3U)];
#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */

    phCryptoSym_Sw_Des_Permutate_IP(pBlock, pTmpBlock);

    i = 15;
    do
    {
#ifdef  PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
        phCryptoSym_Sw_Des_PC2_Permutation(pKey , &pDataParams->pKey[PH_CRYPTOSYM_3K3DES_KEY_SIZE]);
        phCryptoSym_Sw_Des_RotateRight28(pKey, key_rotation[i]);
        phCryptoSym_Sw_Des_RotateRight28(&pKey[4], key_rotation[i]);
        phCryptoSym_Sw_Des_ComputeRound(pTmpBlock, &pDataParams->pKey[PH_CRYPTOSYM_3K3DES_KEY_SIZE]);
#else
        phCryptoSym_Sw_Des_ComputeRound(pTmpBlock, &pKey[i << 3U]);
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */
    }while(i-- > 0U);

    phCryptoSym_Sw_Des_Swap(pTmpBlock);

    phCryptoSym_Sw_Des_Permutate_IP_Inv(pTmpBlock, pBlock);

    return PH_ERR_SUCCESS;
}

FUNC(void, ANFCRL_CODE)  phCryptoSym_Sw_Des_Permutate_IP(
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pStateIn,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pStateOut
                                      )
{
    /* The following implementation choice has been performed: */
    /* - The output bytes are chosen in a given regular sequence: 4,0, 5,1, 6,2, 7,2 */
    /* - For each iteration, the next significant bit of each of the inputs is unused. */
    /* - - e.g.: output byte 4 uses all MSBits of all input bits, output byte 0 the bit 7 of all input bits and so on. */
    /* The algorithm is defined as follows: */
    /* 1. Use base pointer, set it to out. */
    /* 2. In each iteration, for the output bytes perform the following operation: */
    /* -- Use base[4], base[0] and then increment base (to gain 5-1 in next iteration) */
    /* 3. Use MSBit of each input byte, OR it into the output byte */
    /* 4. Shift output byte to the right, such that after 8 iterations all bits are set*/
    /* 3. Shift input byte to the left to have the next bit of the input as most significant input bit. */

    /* Within this loop, all bytes from the IP-Table are calculated */
    /* The following input bits are used in the corresponding rounds: */
    /* round 0: pStateOut[4]: 57 49 41 33 25 17 9 1 */
    /* round 0: pStateOut[0]: 58 50 42 34 26 18 10 2 */
    /* round 1: pStateOut[5]: 59 51 43 35 27 19 11 3 */
    /* round 1: pStateOut[1]: 60 52 44 36 28 20 12 4 */
    /* round 2: pStateOut[6]: 61 53 45 37 29 21 13 5 */
    /* round 2: pStateOut[2]: 62 54 46 38 30 22 14 6 */
    /* round 3: pStateOut[7]: 63 55 47 39 31 23 15 7 */
    /* round 3: pStateOut[3]: 64 56 48 40 32 24 16 8 */

    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM i;
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM j;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM outTmp = pStateOut;

    /* Outer loop to iterate over output byte pairs 4,0, 5,1, 6,2, 7,2 */
    for (i=0;i<4U;i++)
    {
        /* Set output bytes to 0x00 to be able to OR in the loop */
        outTmp[0]=0x00;
        outTmp[4]=0x00;

        /* Inner loop to iterate over input bytes */
        for (j=0;j<7U;j++)
        {
            /* Take MSBit of input, shift output to right to make space for next input bit
            and input to left to get next bit at the bit position 7.*/
            outTmp[4] |= (uint8)(pStateIn[j] & 0x80U);
            outTmp[4] >>= 1U;
            pStateIn[j] <<= 1U;
            /* Take MSBit of input, shift output to right to make space for next input bit
            and input to left to get next bit at the bit position 7.*/
            outTmp[0] |= (uint8)(pStateIn[j] & 0x80U);
            outTmp[0] >>= 1U;
            pStateIn[j] <<= 1U;
        }
        /* Take MSBit of input, do not shift output, as the byte is already full.
        and input to left to get next bit at the bit position 7.*/
        outTmp[4] |= (uint8)(pStateIn[7] & 0x80U);
        pStateIn[7] <<= 1U;
        outTmp[0] |= (uint8)(pStateIn[7] & 0x80U);
        pStateIn[7] <<= 1U;
        /* Increment base pointer to get next output byte pair. */
        outTmp++;
    }
}

FUNC(void, ANFCRL_CODE)  phCryptoSym_Sw_Des_Permutate_IP_Inv(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pStateIn,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pStateOut
    )
{
    /* The following implementation choice has been performed: */
    /* - The input bytes are chosen in a given regular sequence: 4,0, 5,1, 6,2, 7,2 */
    /* - For each iteration, the next significant bit of each of the inputs is unused. */
    /* - - e.g.: output byte 0 uses all LSBits of all input bits (in the sequence described above), output byte 1 the bit 2 of all input bits and so on. */
    /* The algorithm is defined as follows: */
    /* 1. Use base pointer, set it to pStateIn for each iteration of the output byte. */
    /* 2. In each iteration, for the input bytes perform the following operation: */
    /* -- Use base[4], base[0] and then increment base (to gain 5-1 pStateIn next iteration) */
    /* 3. Use LSBit of each input byte, OR it into the output byte */
    /* 4. Shift output byte to the left, such that after 8 iterations all bits are set*/
    /* 3. Shift input byte to the right to have the next bit of the input as least significant input bit. */

    /* Within this loop, all bytes from the IP-1-Table are calculated */
    /* The following input bits are used pStateIn the corresponding rounds: */
    /* round 0: pStateOut[0]: 40 8 48 16 56 24 64 32 */
    /* round 1: pStateOut[1]: 39 7 47 15 55 23 63 31 */
    /* round 2: pStateOut[2]: 38 6 46 14 54 22 62 30 */
    /* round 3: pStateOut[3]: 37 5 45 13 53 21 61 29 */
    /* round 4: pStateOut[4]: 36 4 44 12 52 20 60 28 */
    /* round 5: pStateOut[5]: 35 3 43 11 51 19 59 27 */
    /* round 6: pStateOut[6]: 34 2 42 10 50 18 58 26 */
    /* round 7: pStateOut[7]: 33 1 41 9 49 17 57 25 */

    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM inTmp;
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM i;
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM j;

    /* Outer loop to iterate over all output bytes */
    for (i=0;i<8U;i++)
    {
        pStateOut[i]=0x00;
        inTmp = pStateIn;
        /* Inner loop to iterate over input byte pairs 4,0, 5,1, 6,2, */
        for (j=0;j<3U;j++)
        {
            /* Take LSBit of input bytes base[4] and base[0], shift output to left
            to make space for next input bit and input to right to get next bit at
            the bit position 1.*/
            pStateOut[i] |= (uint8)(inTmp[4] & 0x01U);
            pStateOut[i] <<= 1U;
            pStateOut[i] |= (uint8)(inTmp[0] & 0x01U);
            pStateOut[i] <<= 1U;
            inTmp[0] >>= 1U;
            inTmp[4] >>= 1U;
            inTmp++;
        }
        /* Use input byte pair 7,2 without shifting the output byte in the final iteration
        as it is already complete */
        pStateOut[i] |= (uint8)(inTmp[4] & 0x01U);
        pStateOut[i] <<= 1U;
        pStateOut[i] |= (uint8)(inTmp[0] & 0x01U);
        inTmp[0] >>= 1U;
        inTmp[4] >>= 1U;
    }
}

FUNC(void, ANFCRL_CODE)  phCryptoSym_Sw_Des_PC1_Permutation(
    P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pKeyIn,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pKeyOut
    )
{
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM i;
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM j;
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM pKeyInTmp[PH_CRYPTOSYM_DES_KEY_SIZE];

    /* Re-copy the key */
    (void)memcpy(pKeyInTmp, pKeyIn, PH_CRYPTOSYM_DES_KEY_SIZE);

    /* The following implementation choice has been performed: */
    /* - There are 3 output groups, namely bytes 0-2, bytes 4-6, byte 3 and 7*/
    /* - Each output group has in common, that the same bit index of each input byte is used to compute the output. */
    /* Thus, the algorithm can be defined as follows: */
    /* 1. Use MSBit of each input byte, OR it into the output byte */
    /* 2. Shift output byte to the right, such that after 8 iterations all bits are set*/
    /* 3. Shift input byte to the left to have the next bit of the input as most significant input bit. */

    /* Within this loop, bytes 0-2 from the PC1-Table are calculated */
    /* The following input bits are used in the corresponding rounds: */
    /* round 0: 1, 9, 17, 25, 33, 41, 49, 57 */
    /* round 1: 2, 10, 18, 26, 34, 42, 50, 58 */
    /* round 2: 3, 11, 19, 27, 35, 43, 51, 59 */
    /* round 3: 4, 12, 20, 28, 36, 44, 52, 60 */
    /* round 4: 5, 13, 21, 29, 37, 45, 53, 61 */
    /* round 5: 6, 14, 22, 30, 38, 46, 54, 62 */
    /* round 6: 7, 15, 23, 31, 39, 47, 55, 63 */
    for (i=0;i<7U;i++)
    {
        pKeyOut[i] = 0x00;
        for (j = 0; j<7U; j++)
        {
            pKeyOut[i] |= (uint8)(pKeyInTmp[j] & 0x80U);
            pKeyOut[i] >>= 1U;
            pKeyInTmp[j] <<= 1U;
        }
        pKeyOut[i] |= (uint8)(pKeyInTmp[7] & 0x80U);
        pKeyInTmp[7] <<= 1U;
    }

    /* Now the output bytes 3 and 7 are calculated by taking the correct subsets of the pKeyOut[3] byte */
    pKeyOut[7] = pKeyOut[3] <<4U;
    pKeyOut[3] &= 0xF0U;

    /* Also byte 4 and 6 need to change the position. */
    i = pKeyOut[6];
    pKeyOut[6] = pKeyOut[4];
    pKeyOut[4] = i;

}

FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Des_PC2_Permutation(
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pKeyIn,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeyOut
                                        )
{
    /* As the input bit sequence can not be mapped easily to the output bits,
    the implementation simply extracts the required bit out of the input and shifts it
    into the correct position of the output. */

    pKeyOut[0] = (uint8)((pKeyIn[1] & 0x04U) << 3U); /* Input bit 14 */
    pKeyOut[0] |= (uint8)((pKeyIn[2] & 0x80U) >> 3U); /* Input bit 17 */
    pKeyOut[0] |= (uint8)((pKeyIn[1] & 0x20U) >> 2U); /* Input bit 11 */
    pKeyOut[0] |= (uint8)((pKeyIn[2] & 0x01U) << 2U); /* Input bit 24 */
    pKeyOut[0] |= (uint8)((pKeyIn[0] & 0x80U) >> 6U); /* Input bit 1 */
    pKeyOut[0] |= (uint8)((pKeyIn[0] & 0x08U) >> 3U); /* Input bit 5 */

    pKeyOut[1] = (uint8)((pKeyIn[0] & 0x20U)); /* Input bit 3 */
    pKeyOut[1] |= (uint8)((pKeyIn[3] & 0x10U)); /* Input bit 28 */
    pKeyOut[1] |= (uint8)((pKeyIn[1] & 0x02U) << 2U); /* Input bit 15 */
    pKeyOut[1] |= (uint8)((pKeyIn[0] & 0x04U)); /* Input bit 6 */
    pKeyOut[1] |= (uint8)((pKeyIn[2] & 0x08U) >> 2U); /* Input bit 21 */
    pKeyOut[1] |= (uint8)((pKeyIn[1] & 0x40U) >> 6U); /* Input bit 10 */

    pKeyOut[2] = (uint8)((pKeyIn[2] & 0x02U) << 4U); /* Input bit 23 */
    pKeyOut[2] |= (uint8)((pKeyIn[2] & 0x20U) >> 1U); /* Input bit 19 */
    pKeyOut[2] |= (uint8)((pKeyIn[1] & 0x10U) >> 1U); /* Input bit 12 */
    pKeyOut[2] |= (uint8)((pKeyIn[0] & 0x10U) >> 2U); /* Input bit 4 */
    pKeyOut[2] |= (uint8)((pKeyIn[3] & 0x40U) >> 5U); /* Input bit 26 */
    pKeyOut[2] |= (uint8)((pKeyIn[0] & 0x01U)); /* Input bit 8 */

    pKeyOut[3] = (uint8)((pKeyIn[1] & 0x01U) << 5U); /* Input bit 16 */
    pKeyOut[3] |= (uint8)((pKeyIn[0] & 0x02U) << 3U); /* Input bit 7 */
    pKeyOut[3] |= (uint8)((pKeyIn[3] & 0x20U) >> 2U); /* Input bit 27 */
    pKeyOut[3] |= (uint8)((pKeyIn[2] & 0x10U) >> 2U); /* Input bit 20 */
    pKeyOut[3] |= (uint8)((pKeyIn[1] & 0x08U) >> 2U); /* Input bit 13 */
    pKeyOut[3] |= (uint8)((pKeyIn[0] & 0x40U) >> 6U); /* Input bit 2 */

    pKeyOut[4] = (uint8)((pKeyIn[5] & 0x08U) << 2U); /* Input bit 41 */
    pKeyOut[4] |= (uint8)((pKeyIn[6] & 0x01U) << 4U); /* Input bit 52 */
    pKeyOut[4] |= (uint8)((pKeyIn[4] & 0x20U) >> 2U); /* Input bit 31 */
    pKeyOut[4] |= (uint8)((pKeyIn[5] & 0x80U) >> 5U); /* Input bit 37 */
    pKeyOut[4] |= (uint8)((pKeyIn[6] & 0x20U) >> 4U); /* Input bit 47 */
    pKeyOut[4] |= (uint8)((pKeyIn[7] & 0x20U) >> 5U); /* Input bit 55 */

    pKeyOut[5] = (uint8)((pKeyIn[4] & 0x40U) >> 1U); /* Input bit 30 */
    pKeyOut[5] |= (uint8)((pKeyIn[5] & 0x10U)); /* Input bit 40 */
    pKeyOut[5] |= (uint8)((pKeyIn[6] & 0x02U) << 2U); /* Input bit 51 */
    pKeyOut[5] |= (uint8)((pKeyIn[6] & 0x80U) >> 5U); /* Input bit 45 */
    pKeyOut[5] |= (uint8)((pKeyIn[4] & 0x08U) >> 2U); /* Input bit 33 */
    pKeyOut[5] |= (uint8)((pKeyIn[6] & 0x10U) >> 4U); /* Input bit 48 */

    pKeyOut[6] = (uint8)((pKeyIn[5] & 0x01U) << 5U); /* Input bit 44 */
    pKeyOut[6] |= (uint8)((pKeyIn[6] & 0x08U) << 1U); /* Input bit 49 */
    pKeyOut[6] |= (uint8)((pKeyIn[5] & 0x20U) >> 2U); /* Input bit 39 */
    pKeyOut[6] |= (uint8)((pKeyIn[7] & 0x10U) >> 2U); /* Input bit 56 */
    pKeyOut[6] |= (uint8)((pKeyIn[4] & 0x04U) >> 1U); /* Input bit 34 */
    pKeyOut[6] |= (uint8)((pKeyIn[7] & 0x80U) >> 7U); /* Input bit 53 */

    pKeyOut[7] = (uint8)((pKeyIn[6] & 0x40U) >> 1U); /* Input bit 46 */
    pKeyOut[7] |= (uint8)((pKeyIn[5] & 0x04U) << 2U); /* Input bit 42 */
    pKeyOut[7] |= (uint8)((pKeyIn[6] & 0x04U) << 1U); /* Input bit 50 */
    pKeyOut[7] |= (uint8)((pKeyIn[4] & 0x01U) << 2U); /* Input bit 36 */
    pKeyOut[7] |= (uint8)((pKeyIn[4] & 0x80U)>> 6U); /* Input bit 29 */
    pKeyOut[7] |= (uint8)((pKeyIn[4] & 0x10U) >> 4U); /* Input bit 32 */
}

#ifdef  PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
FUNC(void, ANFCRL_CODE)  phCryptoSym_Sw_Des_RotateRight28(
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pArray,
                                       VAR(uint8, ANFCRL_VAR) bNumPos
                                       )
{
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM i;
    VAR(uint8, ANFCRL_VAR) bOverflow = 0;
    VAR(uint8, ANFCRL_VAR) bOverflowNew = 0;

    /* Iterate over all positions in outer loop */
    while(0U != bNumPos)
    {
        /* Start at lowest index because we need to rotate to right */
        for (i=0;i<4U;i++)
        {
            /* Calculate, if there is an overflow generated by the currently shifted byte */
            bOverflowNew = (uint8) (((pArray[i] & 0x01U) != 0U) ? 0x80U : 0x00U);
            /* Shift the byte */
            pArray[i] = pArray[i] >> 1U;
            /* Mask the overflow of the previous byte into the current byte */
            pArray[i] |= bOverflow;
            /* Remember current overflow */
            bOverflow = bOverflowNew;
        }

        /* In case of overflow of the highest byte, the bit needs to be fed in back at position 0 of the array */
        if (0U != (pArray[3] & 0x08U))
        {
            pArray[0] |= 0x80U;
            pArray[3] &= 0xF0U;
        }
        bOverflow = 0;
        bNumPos--;
    }
}
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */

FUNC(void, ANFCRL_CODE)  phCryptoSym_Sw_Des_RotateLeft28(
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pArray,
                                      VAR(uint8, ANFCRL_VAR) bNumPos
                                      )
{
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM i;
    VAR(uint8, ANFCRL_VAR) bOverflow = 0;
    VAR(uint8, ANFCRL_VAR) bOverflowNew = 0;

    /* Iterate over all positions in outer loop */
    while(0U != (bNumPos))
    {
        /* Start at highest index because we need to rotate to left */
        i = 4;
        do
        {
            i--;
            /* Calculate, if there is an overflow generated by the currently shifted byte */
            bOverflowNew = (uint8) (((pArray[i] & 0x80U) != 0U) ? 0x01U : 0x00U);
            /* Shift the byte */
            pArray[i] = pArray[i] << 1U;
            /* Mask the overflow of the previous byte into the current byte */
            pArray[i] |= bOverflow;
            /* Remember current overflow */
            bOverflow = bOverflowNew;
        }while(0U != i);

        /* In case of overflow of the first byte, the bit needs to be fed in back at position 28 of the array */
        if (0U != (bOverflow))
        {
            pArray[3] |= 0x10U;
        }
        bOverflow = 0;
        bNumPos--;
    }
}

FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Des_ComputeRound(
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pState,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRoundKey
                                     )
{
    VAR(uint8, ANFCRL_VAR) temp[4];
    (void)memcpy(temp, pState, 4);
    (void)memcpy(pState, &pState[4], 4);
    phCryptoSym_Sw_Des_F(&pState[4], pRoundKey);
    pState[4] ^= temp[0] ;
    pState[5] ^= temp[1];
    pState[6] ^= temp[2];
    pState[7] ^= temp[3];
}

FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Des_Swap(P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM bState)
{
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM tmp[4];

    (void)memcpy(tmp, bState, 4);
    (void)memcpy(bState, &bState[4], 4);
    (void)memcpy(&bState[4], tmp, 4);
}

FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Des_F(
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pR,
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRoundKey
                          )
{
    VAR(uint8, ANFCRL_VAR) j;
    VAR(uint8, ANFCRL_VAR) rc;
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM bArray[PH_CRYPTOSYM_DES_BLOCK_SIZE];

    /* First expand the input array pR such that an 8 byte output array containing 6 bits in each byte is generated */
    phCryptoSym_Sw_Des_Expand(pR, bArray);

    /* Iterate over all 8 bytes */
    for (j = 0; j < 4U; j++)
    {
        /* Calculate the XORing of the key and the input to find the correct SBOX lookup index. */
        rc = bArray[(2U*j)] ^ pRoundKey[(2U*j)];
        rc = (uint8)((rc & 0x20U) | ((rc << 4U) & 0x10U) | ((rc >> 1U) & 0x0FU));
        /* Lookup the result in the SBOX and write back. */
        bArray[j] = (uint8)(SBOX[2U*j][rc] << 4U);
        /* Calculate the XORing of the key and the input to find the correct SBOX lookup index for the next byte. */
        rc = bArray[(2U*j) + 1U] ^ pRoundKey[(2U*j) + 1U];
        rc = (uint8)((rc & 0x20U) | ((rc << 4U) & 0x10U) | ((rc >> 1U) & 0x0FU));
        /* Lookup the result in the SBOX and OR it to the result of the previous byte. */
        bArray[j] |= (uint8)(SBOX[(2U*j)+1U][rc]);
    }

    /* Finally perform the permutation P.
    As there is no regular mapping from input to output the relevant input bits are looked up in bArray and written back to pR.
    When designing this function, the goal was to minimize the shift operations. */
    pR[1] = (uint8)((bArray[0] & 0x88U));        /* Input bits 1, 5 */
    bArray[0] <<=1U;
    pR[2] = (uint8)(bArray[0] & 0x80U);          /* Input bit 2 */
    pR[2] |= (uint8)((bArray[0]& 0x02U ) << 5U);  /* Input bit 8 */
    pR[0] = (uint8)((bArray[0]& 0x04U ) << 4U);   /* Input bit 7 */
    pR[3] = (uint8)((bArray[0] & 0x08U) << 1U);   /* Input bit 6 */
    bArray[0] >>= 4U;
    pR[3] |= (uint8)(bArray[0] & 0x02U);         /* Input bit 4 */
    bArray[0] >>= 1U;
    pR[2] |= (uint8)(bArray[0] & 0x02U);         /* Input bit 3 */
    pR[0]|= (uint8)((bArray[1] & 0x01U) << 7U);   /* Input bit 16 */
    pR[1]|= (uint8)((bArray[1] & 0x02U) << 5U);   /* Input bit 15 */
    pR[2]|= (uint8)((bArray[1] & 0x04U) << 2U);   /* Input bit 14 */
    pR[3]|= (uint8)((bArray[1] & 0x08U) << 3U);   /* Input bit 13 */
    bArray[1] >>= 2U;
    pR[0] |= (uint8)(bArray[1]& 0x04U);          /* Input bit 12 */
    bArray[1] >>= 1U;
    pR[3] |= (uint8)(bArray[1]& 0x04U);          /* Input bit 11 */
    bArray[1] >>= 3U;
    pR[1] |= (uint8)(bArray[1]& 0x01U);          /* Input bit 10 */
    bArray[1] >>= 1U;
    pR[2] |= (uint8)(bArray[1]& 0x01U);          /* Input bit 9 */

    pR[0] |= (uint8)((bArray[2] & 0x80U) >> 7U);  /* Input bit 17  */
    pR[1] |= (uint8)((bArray[2] & 0x40U) >> 4U);  /* Input bit 18 */
    pR[3] |= (uint8)((bArray[2] & 0x20U) << 2U);  /* Input bit 19 */
    bArray[2]<<=1U;
    pR[0] |= (uint8)(bArray[2] & 0x20U);         /* Input bit 20 */
    pR[0] |= (uint8)(bArray[2] & 0x10U);         /* Input bit 21 */
    pR[3] |= (uint8)(bArray[2] & 0x08U);         /* Input bit 22 */
    bArray[2]<<=3U;
    pR[1]|= (uint8)(bArray[2] & 0x20U);          /* Input bit 23 */
    pR[2]|= (uint8)((bArray[2] & 0x10U) << 1U);   /* Input bit 24 */

    pR[0] |= (uint8)(bArray[3] & 0x08U);         /* Input bit 29 */
    pR[1] |= (uint8)(bArray[3] & 0x02U);         /* Input bit 31 */
    pR[3] |= (uint8)((bArray[3] & 0x80U) >> 7U);  /* Input bit 25 */
    pR[2] |= (uint8)((bArray[3] & 0x01U) << 3U);  /* Input bit 32 */
    pR[3] |= (uint8)((bArray[3] & 0x04U) << 3U);  /* Input bit 30 */
    bArray[3]>>=2U;
    pR[1] |= (uint8)((bArray[3] & 0x10U));       /* Input bit 26 */
    bArray[3]>>=1U;
    pR[2] |= (uint8)((bArray[3] & 0x04U));       /* Input bit 27 */
    pR[0] |= (uint8)((bArray[3] & 0x02U));       /* Input bit 28 */

}

FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Des_Expand(
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pR,
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pRexp
                               )
{
    pRexp[0] = (uint8)((uint8)(((pR[3] & 0x01U) << 5U) | (pR[0] >> 3U)) & MASK6); /* Input bits 32 1 2 3 4 5 */
    pRexp[1] = (uint8)((uint8)((pR[0] << 1U) | ((pR[1] & 0x80U) >> 7U)) & MASK6); /* Input bits 4 5 6 7 8 9 */
    pRexp[2] = (uint8)((uint8)(((pR[0] & 0x01U) << 5U) | (pR[1] >> 3U)) & MASK6); /* Input bits 8 9 10 11 12 13 */
    pRexp[3] = (uint8)((uint8)((pR[1] << 1U) | ((pR[2] & 0x80U) >> 7U)) & MASK6); /* Input bits 12 13 14 15 16 17 */
    pRexp[4] = (uint8)((uint8)(((pR[1] & 0x01U) << 5U) | (pR[2] >> 3U)) & MASK6); /* Input bits 16 17 18 19 20 21 */
    pRexp[5] = (uint8)((uint8)((pR[2] << 1U) | ((pR[3] & 0x80U) >> 7U)) & MASK6); /* Input bits 20 21 22 23 24 25*/
    pRexp[6] = (uint8)((uint8)(((pR[2] & 0x01U) << 5U) | (pR[3] >> 3U)) & MASK6); /* Input bits 24 25 26 27 28 29*/
    pRexp[7] = (uint8)((uint8)((pR[3] << 1U) | ((pR[0] & 0x80U) >> 7U)) & MASK6); /* Input bits 28 29 30 31 32 1 */
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Des_DecodeVersion(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion
    )
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex;

    /* Init. KeyVersion */
    *pKeyVersion = 0x00;

    /* Parse KeyVersion */
    for (bIndex = 0; bIndex < PH_CRYPTOSYM_DES_KEY_SIZE; ++bIndex)
    {
        *pKeyVersion |= (((uint16)(pKey[bIndex])) & 0x01U) << (7U - bIndex);
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Des_EncodeVersion(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
    VAR(uint16, ANFCRL_VAR) wKeyVersion,
    VAR(uint16, ANFCRL_VAR) wKeyType,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncodedKey
    )
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bKeySize;

    /* Parameter check */
    if ((wKeyType != PH_CRYPTOSYM_KEY_TYPE_DES) &&
        (wKeyType != PH_CRYPTOSYM_KEY_TYPE_2K3DES) &&
        (wKeyType != PH_CRYPTOSYM_KEY_TYPE_3K3DES))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    /* Retrieve KeySize */
    bKeySize = (uint8)phCryptoSym_GetKeySize(wKeyType);

    /* Insert KeyVersion */
    for (bIndex = 0; bIndex < bKeySize; ++bIndex)
    {
        pEncodedKey[bIndex] = (uint8)((((uint16)pKey[bIndex]) & 0xFEU)
            | ((wKeyVersion >> (7U - (bIndex % 8U))) & 0x01U));
    }

    return PH_ERR_SUCCESS;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTOSYM_SW_DES_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCRYPTOSYM_SW_DES_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* PH_CRYPTOSYM_SW_DES */

#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
#ifdef __cplusplus
}
#endif /* __cplusplus */
