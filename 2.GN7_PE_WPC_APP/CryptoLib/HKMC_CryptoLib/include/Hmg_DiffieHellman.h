/*-----------------------------------------------------------------------------
* Hyundai-AutoEver Cryptography Library
* Copyright (c) 2015-2016 Hyundai-AutoEver all rights reserved.
------------------------------------------------------------------------------*/
/**
* \file     Hmg_DiffieHellman.h
* \date     Dec. 2016.
* \version  1.6.0
* \author   Hyundai_Autoever Automotive Security Techology Team
* \brief:   PKCS #3 (Diffie-Hellman Key sharing)

* \see
*
*/

/* DEFINE TO PREVENT RECURSIVE INCLUSION -------------------------------------*/
#ifndef HMG_DIFFIE_HELLMAN_H_
#define HMG_DIFFIE_HELLMAN_H_

/* INCLUDES ------------------------------------------------------------------*/
#include "Hmg_HDrbg.h"
#include "Hmg_Rsa.h"

/* EXPORTED DEFINE -----------------------------------------------------------*/
#ifdef  __cplusplus
extern "C" {
#endif

#define HMG_DH_BYTES_SIZE HMG_RSA_BYTES_SIZE

    /* EXPORTED MACRO  -----------------------------------------------------------*/
    /* EXPORTED TYPES  -----------------------------------------------------------*/
    /* EXPORTED VARIABLES  -------------------------------------------------------*/
    /* EXPORTED FUNCTIONS  -------------------------------------------------------*/

#ifdef HMG_ENABLE_DH
    /** \brief  Diffie-Hellman Key generator.
    *
    * calculates modular exponent using prime P and base G
    *   calculate, (public Value) = (base G) ^ (private Value exponent) mod (modular ecc_primeP).
    *       if drbgCtx is NULL, this fuction use input privateValue.
    *       if ecc_baseG is NULL, this fuction use default ecc_baseG.
    *       if ecc_primeP is NULL, this fuction use default prime P.
    *       before call this fuction, drbgCtx must be prepered by Hmg_Hashdrbg_Sha256_Init and Hmg_Hashdrbg_Sha256_Reseed for random private value(key)
    *
    * \param[inout] drbgCtx         DRBG random value context
    * \param[out]   publicValue     diffie-hellman public value(key)
    * \param[out]   privateValue    diffie-hellman private value(key)
    * \param[in]    ecc_baseG           diffie-hellman base G
    * \param[in]    ecc_primeP          diffie-hellman modular prime
    * \return       success or failure
    * \see
    */
    extern uint8 Hmg_DiffieHellmanKeypairGen(
        HMG_INOUT  HmgHdrbgSha256Ctx* drbgCtx,
        HMG_OUT uint8 publicValue[],
        HMG_INOUT uint8 privateValue[],
        HMG_IN  uint8 ecc_baseG[],
        HMG_IN  uint8 ecc_primeP[]
        );

    /** \brief  Diffie-Hellman secret value generator.
    *
    * calculates modular exponent using prime P and other's public value(key)
    *   calculate, (secret value) = (other's public value) ^ (my private Value exponent) mod (modular ecc_primeP).
    *       if prime P is NULL, this fuction use default prime P.
    *
    * \param[out]   secretValue     diffie-hellman secret(result) value
    * \param[in]    publicValue     diffie-hellman other's public value(key)
    * \param[in]    privateValue    diffie-hellman my private value(key)
    * \param[in]    ecc_primeP          diffie-hellman modular prime
    * \return       success or failure
    * \see
    */
    extern uint8 Hmg_DiffieHellmanSharedvalueGen(
        HMG_OUT uint8 secretValue[],
        HMG_IN  uint8 publicValue[],
        HMG_IN  uint8 privateValue[],
        HMG_IN  uint8 ecc_primeP[]
        );

#endif

#ifdef  __cplusplus
}
#endif

#endif //HMG_DIFFIE_HELLMAN_H_
