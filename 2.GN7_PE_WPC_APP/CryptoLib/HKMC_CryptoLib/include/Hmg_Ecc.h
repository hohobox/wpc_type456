/*-----------------------------------------------------------------------------
* Hyundai-AutoEver Cryptography Library
* Copyright (c) 2015-2016 Hyundai-AutoEver all rights reserved.
------------------------------------------------------------------------------*/
/**
* \file     Hmg_Ecc.h
* \date     Jan. 2016.
* \version  1.6.0
* \author   Hyundai_Autoever Automotive Security Techology Team
* \brief    Ecc Nist p256 Curve(secp256r1) implementation
* \see      SEC 1: Elliptic Curve Cryptography(Version 2.0, May 21, 2009)
*           SEC 2: Recommended Elliptic Curve Domain Parameters(Version 1.0, September 20, 2000)
*/

/* DEFINE TO PREVENT RECURSIVE INCLUSION -------------------------------------*/
#ifndef HMG_ECC_H_
#define HMG_ECC_H_

/* INCLUDES ------------------------------------------------------------------*/
#include "Hmg_Common.h"

#ifdef  __cplusplus
extern "C" {
#endif

    /* EXPORTED DEFINE -----------------------------------------------------------*/


    /** Size of WORD and BYTE of Eecc curve */
#if (ECC_CURVE_TYPE == NIST_CURVE_P521r1)
#   define HMG_ECC_BYTES_SIZE        68U
#   define HMG_ECC_WORDS_SIZE        17U
#elif (ECC_CURVE_TYPE == NIST_CURVE_P384r1)
#   define HMG_ECC_BYTES_SIZE        48U
#   define HMG_ECC_WORDS_SIZE        12U
#elif (ECC_CURVE_TYPE == NIST_CURVE_P256r1)
#   define HMG_ECC_BYTES_SIZE        32U
#   define HMG_ECC_WORDS_SIZE         8U
#elif (ECC_CURVE_TYPE == NIST_CURVE_P224r1)
#   define HMG_ECC_BYTES_SIZE        28U
#   define HMG_ECC_WORDS_SIZE         7U
#elif (ECC_CURVE_TYPE == NIST_CURVE_P192r1)
#   define HMG_ECC_BYTES_SIZE        24U
#   define HMG_ECC_WORDS_SIZE         6U
#elif (ECC_CURVE_TYPE == SECP_CURVE_P160r1)
#   define HMG_ECC_BYTES_SIZE        20U
#   define HMG_ECC_WORDS_SIZE         5U
#endif
#   define HMG_ECC_MAX_BYTES_SIZE        68U
#   define HMG_ECC_MAX_WORDS_SIZE        17U

    /* EXPORTED MACRO  -----------------------------------------------------------*/
    /* EXPORTED TYPES  -----------------------------------------------------------*/

    typedef struct ctEcPoint{
        uint32 x[HMG_ECC_WORDS_SIZE + 1U];
        uint32 y[HMG_ECC_WORDS_SIZE + 1U];
        uint32 z[HMG_ECC_WORDS_SIZE + 1U];
    } HmgEcPoint;

    typedef struct ctEcPoint_Sum {
        uint32 x[HMG_ECC_MAX_WORDS_SIZE + 1U];
        uint32 y[HMG_ECC_MAX_WORDS_SIZE + 1U];
        uint32 z[HMG_ECC_MAX_WORDS_SIZE + 1U];
    } HmgEcPoint_All;


    /** \brief Publickey for Ecc */
    typedef struct ctEcPublickey{
        uint8 *x;   /**<  Pointer to x */
        uint8 *y;   /**<  Pointer to y */
    } HmgEcPublickey;

    /** \brief signature for ECDSA */
    typedef struct ctEcdsaSign{
        uint8 *r;   /**<  Bytes to r */
        uint8 *s;   /**<  Bytes to s */
    } HmgEcdsaSign;

    /* EXPORTED VARIABLES  -------------------------------------------------------*/
    /* EXPORTED FUNCTIONS  -------------------------------------------------------*/
    /* EXPORTED VARIABLES  -------------------------------------------------------*/
    /* EXPORTED FUNCTIONS  -------------------------------------------------------*/

#ifdef HMG_ENABLE_ECC_KEYGENERATE
    /** \brief  ECC key generation.
    *
    * Generates ecc public key form private key
    *   - Q : publickey
    *   - d : privatekey
    *   - G : basepoint
    *   - Q = d * G
    * \param[out]   publickey       Ecc public key point (affine).
    * \param[in]    privatekey      Ecc private key of length HMG_ECC_BYTES_SIZE
    * \return       HMG_SUCCESS on HMG_FAIULE
    * \see
    */
    extern uint8 Hmg_EcckeyGenerate(
        HMG_OUT HmgEcPublickey* publickey,
        HMG_IN  uint8           privatekey[]
        );

    /** \brief  ECC key validation check.
    *
    * validates the public key Point
    *   Check, that: Q(publickey)
    *   - Q != (0)
    *   - Q(x,y) are properly represented elements in GF(p)
    *   - Q lies on elliptic curve defined by a & b
    *   - Q * n = (0)
    * \param[in]    publickey       Ecc public key point (affine).
    * \return       HMG_SUCCESS or HMG_FAIULE.
    * \see
    */
    extern uint8 Hmg_EcckeyValidationCheck(
        HMG_IN HmgEcPublickey*      publickey
        );


#ifdef HMG_ENABLE_ECC_ALL

    extern uint8 Hmg_EcckeyGenerate_p160r1(
        HMG_OUT HmgEcPublickey* publickey,
        HMG_IN  uint8           privatekey[]
        );
    extern uint8 Hmg_EcckeyValidationCheck_p160r1(
        HMG_IN HmgEcPublickey*      publickey
        );
    extern uint8 Hmg_EcckeyGenerate_p224r1(
        HMG_OUT HmgEcPublickey* publickey,
        HMG_IN  uint8           privatekey[]
        );
    extern uint8 Hmg_EcckeyValidationCheck_p224r1(
        HMG_IN HmgEcPublickey*      publickey
        );
    extern uint8 Hmg_EcckeyGenerate_p256r1(
        HMG_OUT HmgEcPublickey* publickey,
        HMG_IN  uint8           privatekey[]
        );
    extern uint8 Hmg_EcckeyValidationCheck_p256r1(
        HMG_IN HmgEcPublickey*      publickey
        );
    extern uint8 Hmg_EcckeyGenerate_p521r1(
        HMG_OUT HmgEcPublickey* publickey,
        HMG_IN  uint8           privatekey[]
        );
    extern uint8 Hmg_EcckeyValidationCheck_p521r1(
        HMG_IN HmgEcPublickey*      publickey
        );

#endif //HMG_ENABLE_ECC_ALL

#endif


#ifdef HMG_ENABLE_ECC_ECDH
    /** \brief  ECDH(Compute shared value).
    *
    * computes the shared secretValue based on ECDH
    *   - SharedPoint = privatekeyA * publickeyB
    *   - secretValue = SharedPoint->x
    *   - publickey of B : publickeyB
    *   - privatekey of A: privatekeyA
    * \param[out]   secretValue     Shared secretValue of length HMG_ECC_BYTES_SIZE.
    * \param[in]    privatekeyA     Privatekey of A of length HMG_ECC_BYTES_SIZE.
    * \param[in]    publickeyB      publickey point of B (affine).
    * \return       HMG_SUCCESS or HMG_FAIULE.
    * \see
    */
    extern uint8 Hmg_EccEcdh(
        HMG_OUT uint8           secretValue[],
        HMG_IN  uint8           privatekeyA[],
        HMG_IN  HmgEcPublickey* publickeyB
        );

#ifdef HMG_ENABLE_ECC_ALL

    extern uint8 Hmg_EccEcdh_p160r1(
        HMG_OUT uint8           secretValue[],
        HMG_IN  uint8           privatekeyA[],
        HMG_IN  HmgEcPublickey* publickeyB
        );
    extern uint8 Hmg_EccEcdh_p224r1(
        HMG_OUT uint8           secretValue[],
        HMG_IN  uint8           privatekeyA[],
        HMG_IN  HmgEcPublickey* publickeyB
        );
    extern uint8 Hmg_EccEcdh_p256r1(
        HMG_OUT uint8           secretValue[],
        HMG_IN  uint8           privatekeyA[],
        HMG_IN  HmgEcPublickey* publickeyB
        );
    extern uint8 Hmg_EccEcdh_p521r1(
        HMG_OUT uint8           secretValue[],
        HMG_IN  uint8           privatekeyA[],
        HMG_IN  HmgEcPublickey* publickeyB
        );

#endif //HMG_ENABLE_ECC_ALL

#endif


#ifdef HMG_ENABLE_ECC_ECDSA
    /** \brief  ECDSA sign generation.
    *
    * generates the signature for a hashed message
    * \param[out]   signature       ECDSA Signature.
    * \param[in]    hashedMessage   Hash of signing message of length HMG_ECC_BYTES_SIZE.
    * \param[in]    privatekeyA     Privatekey of A of length HMG_ECC_BYTES_SIZE.
    * \param[in]    secretNumber    unpredictable data of length HMG_ECC_BYTES_SIZE.
    * \return       HMG_SUCCESS or HMG_INVALID_VALUE.
    * \see
    */
    extern uint8 Hmg_EccEcdsaSign(
        HMG_OUT HmgEcdsaSign*       signature,
        HMG_IN  uint8           hashedMessage[],
        HMG_IN  uint8           secretNumber[],
        HMG_IN  uint8           privatekey[]
        );

    /** \brief  ECDSA sign verify.
    *
    * verifies the signature for a hashed message
    * \param[in]    signature       ECDSA Signature.
    * \param[in]    hashedMessage   Hash of signing message of length HMG_ECC_BYTES_SIZE.
    * \param[in]    publickeyB      Ecc public key point (affine).
    * \return       HMG_SUCCESS or HMG_FAIULE or HMG_INVALID_VALUE.
    * \see
    */
    extern uint8 Hmg_EccEcdsaVerify(
        HMG_IN HmgEcdsaSign*    signature,
        HMG_IN uint8            hashedMessage[],
        HMG_IN HmgEcPublickey*  publickey
        );

#ifdef HMG_ENABLE_ECC_ALL

    extern uint8 Hmg_EccEcdsaSign_p160r1(
        HMG_OUT HmgEcdsaSign*       signature,
        HMG_IN  uint8           hashedMessage[],
        HMG_IN  uint8           secretNumber[],
        HMG_IN  uint8           privatekey[]
        );
    extern uint8 Hmg_EccEcdsaVerify_p160r1(
        HMG_IN HmgEcdsaSign*    signature,
        HMG_IN uint8            hashedMessage[],
        HMG_IN HmgEcPublickey*  publickey
        );

    extern uint8 Hmg_EccEcdsaSign_p224r1(
        HMG_OUT HmgEcdsaSign*       signature,
        HMG_IN  uint8           hashedMessage[],
        HMG_IN  uint8           secretNumber[],
        HMG_IN  uint8           privatekey[]
        );
    extern uint8 Hmg_EccEcdsaVerify_p224r1(
        HMG_IN HmgEcdsaSign*    signature,
        HMG_IN uint8            hashedMessage[],
        HMG_IN HmgEcPublickey*  publickey
        );

    extern uint8 Hmg_EccEcdsaSign_p256r1(
        HMG_OUT HmgEcdsaSign*       signature,
        HMG_IN  uint8           hashedMessage[],
        HMG_IN  uint8           secretNumber[],
        HMG_IN  uint8           privatekey[]
        );
    extern uint8 Hmg_EccEcdsaVerify_p256r1(
        HMG_IN HmgEcdsaSign*    signature,
        HMG_IN uint8            hashedMessage[],
        HMG_IN HmgEcPublickey*  publickey
        );

    extern uint8 Hmg_EccEcdsaSign_p521r1(
        HMG_OUT HmgEcdsaSign*       signature,
        HMG_IN  uint8           hashedMessage[],
        HMG_IN  uint8           secretNumber[],
        HMG_IN  uint8           privatekey[]
        );
    extern uint8 Hmg_EccEcdsaVerify_p521r1(
        HMG_IN HmgEcdsaSign*    signature,
        HMG_IN uint8            hashedMessage[],
        HMG_IN HmgEcPublickey*  publickey
        );

#endif //HMG_ENABLE_ECC_ALL

#ifdef HMG_ECDSA_CONST_K

    typedef struct ctHmgEcdsaExCtx{
        uint32 sigR[HMG_ECC_WORDS_SIZE + 1U];
        uint32 invk[HMG_ECC_WORDS_SIZE + 1U];
    } HmgEcdsaExCtx;

    extern uint8 Hmg_EccEcdsaSign_Setup(
        HMG_OUT HmgEcdsaExCtx* signEx,
        HMG_IN  uint8 secretNumber[]
        );
    extern uint8 Hmg_EccEcdsaSign_ex(
        HMG_OUT HmgEcdsaSign* signature,
        HMG_IN  uint8* hashedMessage,
        HMG_IN HmgEcdsaExCtx* signEx,
        HMG_IN  uint8* privatekey
        );
#endif


#endif

#ifdef HMG_ENABLE_SLICE

    /** \brief Ecc buffer struct for SLICE */
    typedef struct ctEccSliceCtx{
        uint32  buff_c1[HMG_ECC_WORDS_SIZE + 1U];
        uint32  buff_c2[HMG_ECC_WORDS_SIZE + 1U];
        uint32  buff_c3[HMG_ECC_WORDS_SIZE + 1U];
        HmgEcPoint buff_dst;
        HmgEcPoint buff_src;
        HmgEcPoint buff_tmp;
        uint32 counter;
    } HmgEccSliceCtx;

    extern uint8 Hmg_EcckeyGenerateStart(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx,
        HMG_IN  uint8* privatekey
        );
    extern uint8 Hmg_EcckeyGenerateUpdate(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx
        );
    extern uint8 Hmg_EcckeyGenerateFinish(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx,
        HMG_OUT HmgEcPublickey* publickey
        );

    extern uint8 Hmg_EcckeyValidationCheckStart(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx,
        HMG_IN HmgEcPublickey* publickey
        );
    extern uint8 Hmg_EcckeyValidationCheckUpdate(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx
        );
    extern uint8 Hmg_EcckeyValidationCheckFinish(
        HMG_IN HmgEccSliceCtx* Ecc_ctx
        );

    extern uint8 Hmg_EccEcdhStart(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx,
        HMG_IN uint8* privatekeyA,
        HMG_IN HmgEcPublickey* publickeyB
        );
    extern uint8 Hmg_EccEcdhUpdate(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdhFinish(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx,
        HMG_OUT uint8* secretValue
        );

    extern uint8 Hmg_EccEcdsaSignStart(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx,
        HMG_IN  uint8* secretNumber
        );
    extern uint8 Hmg_EccEcdsaSignUpdate(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdsaSignFinish(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx,
        HMG_OUT HmgEcdsaSign* signature,
        HMG_IN  uint8* hashedMessage,
        HMG_IN  uint8* privatekey
        );

    extern uint8 Hmg_EccEcdsaVerifyStart(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx,
        HMG_IN HmgEcdsaSign* signature,
        HMG_IN uint8* hashedMessage,
        HMG_IN HmgEcPublickey* publickey
        );
    extern uint8 Hmg_EccEcdsaVerifyUpdate(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdsaVerifyFinish(
        HMG_INOUT HmgEccSliceCtx* Ecc_ctx
        );

#ifdef HMG_ENABLE_ECC_ALL

    typedef struct {
        uint32  buff_c1[HMG_ECC_MAX_WORDS_SIZE + 1U];
        uint32  buff_c2[HMG_ECC_MAX_WORDS_SIZE + 1U];
        uint32  buff_c3[HMG_ECC_MAX_WORDS_SIZE + 1U];
        HmgEcPoint_All buff_dst;
        HmgEcPoint_All buff_src;
        HmgEcPoint_All buff_tmp;
        uint32 counter;
    } HmgEccSliceCtx_All;

    extern uint8 Hmg_EcckeyGenerateStart_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN  uint8* privatekey
        );
    extern uint8 Hmg_EcckeyGenerateUpdate_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EcckeyGenerateFinish_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT HmgEcPublickey* publickey
        );

    extern uint8 Hmg_EcckeyGenerateStart_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN  uint8* privatekey
        );
    extern uint8 Hmg_EcckeyGenerateUpdate_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EcckeyGenerateFinish_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT HmgEcPublickey* publickey
        );

    extern uint8 Hmg_EcckeyGenerateStart_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN  uint8* privatekey
        );
    extern uint8 Hmg_EcckeyGenerateUpdate_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EcckeyGenerateFinish_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT HmgEcPublickey* publickey
        );

    extern uint8 Hmg_EcckeyGenerateStart_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN  uint8* privatekey
        );
    extern uint8 Hmg_EcckeyGenerateUpdate_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EcckeyGenerateFinish_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT HmgEcPublickey* publickey
        );

    extern uint8 Hmg_EcckeyValidationCheckStart_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN HmgEcPublickey* publickey
        );
    extern uint8 Hmg_EcckeyValidationCheckUpdate_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EcckeyValidationCheckFinish_p160r1(
        HMG_IN HmgEccSliceCtx_All* Ecc_ctx
        );

    extern uint8 Hmg_EcckeyValidationCheckStart_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN HmgEcPublickey* publickey
        );
    extern uint8 Hmg_EcckeyValidationCheckUpdate_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EcckeyValidationCheckFinish_p224r1(
        HMG_IN HmgEccSliceCtx_All* Ecc_ctx
        );

    extern uint8 Hmg_EcckeyValidationCheckStart_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN HmgEcPublickey* publickey
        );
    extern uint8 Hmg_EcckeyValidationCheckUpdate_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EcckeyValidationCheckFinish_p256r1(
        HMG_IN HmgEccSliceCtx_All* Ecc_ctx
        );

    extern uint8 Hmg_EcckeyValidationCheckStart_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN HmgEcPublickey* publickey
        );
    extern uint8 Hmg_EcckeyValidationCheckUpdate_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EcckeyValidationCheckFinish_p521r1(
        HMG_IN HmgEccSliceCtx_All* Ecc_ctx
        );

    extern uint8 Hmg_EccEcdhStart_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN uint8* privatekeyA,
        HMG_IN HmgEcPublickey* publickeyB
        );
    extern uint8 Hmg_EccEcdhUpdate_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdhFinish_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT uint8* secretValue
        );

    extern uint8 Hmg_EccEcdhStart_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN uint8* privatekeyA,
        HMG_IN HmgEcPublickey* publickeyB
        );
    extern uint8 Hmg_EccEcdhUpdate_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdhFinish_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT uint8* secretValue
        );

    extern uint8 Hmg_EccEcdhStart_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN uint8* privatekeyA,
        HMG_IN HmgEcPublickey* publickeyB
        );
    extern uint8 Hmg_EccEcdhUpdate_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdhFinish_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT uint8* secretValue
        );

    extern uint8 Hmg_EccEcdhStart_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN uint8* privatekeyA,
        HMG_IN HmgEcPublickey* publickeyB
        );
    extern uint8 Hmg_EccEcdhUpdate_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdhFinish_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT uint8* secretValue
        );

    extern uint8 Hmg_EccEcdsaSignStart_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN  uint8* secretNumber
        );
    extern uint8 Hmg_EccEcdsaSignUpdate_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdsaSignFinish_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT HmgEcdsaSign* signature,
        HMG_IN  uint8* hashedMessage,
        HMG_IN  uint8* privatekey
        );

    extern uint8 Hmg_EccEcdsaSignStart_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN  uint8* secretNumber
        );
    extern uint8 Hmg_EccEcdsaSignUpdate_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdsaSignFinish_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT HmgEcdsaSign* signature,
        HMG_IN  uint8* hashedMessage,
        HMG_IN  uint8* privatekey
        );

    extern uint8 Hmg_EccEcdsaSignStart_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN  uint8* secretNumber
        );
    extern uint8 Hmg_EccEcdsaSignUpdate_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdsaSignFinish_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT HmgEcdsaSign* signature,
        HMG_IN  uint8* hashedMessage,
        HMG_IN  uint8* privatekey
        );

    extern uint8 Hmg_EccEcdsaSignStart_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN  uint8* secretNumber
        );
    extern uint8 Hmg_EccEcdsaSignUpdate_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdsaSignFinish_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_OUT HmgEcdsaSign* signature,
        HMG_IN  uint8* hashedMessage,
        HMG_IN  uint8* privatekey
        );

    extern uint8 Hmg_EccEcdsaVerifyStart_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN HmgEcdsaSign* signature,
        HMG_IN uint8* hashedMessage,
        HMG_IN HmgEcPublickey* publickey
        );
    extern uint8 Hmg_EccEcdsaVerifyUpdate_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdsaVerifyFinish_p160r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );

    extern uint8 Hmg_EccEcdsaVerifyStart_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN HmgEcdsaSign* signature,
        HMG_IN uint8* hashedMessage,
        HMG_IN HmgEcPublickey* publickey
        );
    extern uint8 Hmg_EccEcdsaVerifyUpdate_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdsaVerifyFinish_p224r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );

    extern uint8 Hmg_EccEcdsaVerifyStart_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN HmgEcdsaSign* signature,
        HMG_IN uint8* hashedMessage,
        HMG_IN HmgEcPublickey* publickey
        );
    extern uint8 Hmg_EccEcdsaVerifyUpdate_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdsaVerifyFinish_p256r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );

    extern uint8 Hmg_EccEcdsaVerifyStart_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx,
        HMG_IN HmgEcdsaSign* signature,
        HMG_IN uint8* hashedMessage,
        HMG_IN HmgEcPublickey* publickey
        );
    extern uint8 Hmg_EccEcdsaVerifyUpdate_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );
    extern uint8 Hmg_EccEcdsaVerifyFinish_p521r1(
        HMG_INOUT HmgEccSliceCtx_All* Ecc_ctx
        );

#endif //HMG_ENABLE_ECC_ALL

#endif //HMG_ENABLE_SLICE

#ifdef  __cplusplus
}
#endif

#endif
