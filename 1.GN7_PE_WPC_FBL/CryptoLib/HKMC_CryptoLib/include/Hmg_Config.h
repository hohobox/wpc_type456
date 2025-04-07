/**
* \file     Hmg_Config.h
* \date     Jan. 2023.
* \version  1.7.1
* \author   Hyundai_Autoever Automotive Security Techology Team
* \brief    Autoever Cryptogragh configration
* \see
*/

#ifndef HMG_CONFIG_H_
#define HMG_CONFIG_H_

#ifdef HMG_CUSOM_HEADER
#include HMG_CUSOM_HEADER
#endif


// for Secure Flash 1.0 not support 64-bit datatype
//#define HMG_SUPPORT_NON64BIT


// for Secure Flash 1.0 not support 8-bit datatype
//#define HMG_SUPPORT_NON8BIT



/// endian
#define HMG_LITTLE_ENDIAN   0x01u
#define HMG_BIG_ENDIAN      0x00u

#if defined (__BIG_ENDIAN__)
/* Power PC: MPC5060 */
#define HMG_BYTE_ORDER	HMG_BIG_ENDIAN
#elif defined (__LITTLE_ENDIAN__)
/* intel CPU, RH850, TC1728, TC275, ARM */
#define HMG_BYTE_ORDER	HMG_LITTLE_ENDIAN
#endif

#ifndef HMG_BYTE_ORDER
#define HMG_BYTE_ORDER	HMG_LITTLE_ENDIAN
#endif


/// use crypto
#define HMG_CRYPTO_USE_CYCURLIB 0x00U
#define HMG_CRYPTO_USE_HACLIB   0x01U

#define HMG_CRYPTO_USE HMG_CRYPTO_USE_HACLIB


/// no use standard library
#define HMG_MEMORY_USE  1
#define HMG_RANDOM_USE  1


#if !defined(uint8_defined)
    /** 8 bit unsigned integer. */
#ifndef HMG_SUPPORT_NON8BIT
    typedef unsigned char       uint8;
#else
    typedef unsigned short       uint8;
#endif
    #define uint8_defined
#endif
#ifndef uint16_defined
    /** 16 bit unsigned integer. */
    typedef unsigned short      uint16;
    #define uint16_defined
#endif
#ifndef uint32_defined
    /** 32 bit unsigned integer. */
    typedef unsigned long       uint32;
    #define uint32_defined
#endif
#ifndef uint64_defined
    /** 64 bit unsigned integer. */
    typedef unsigned long long  uint64;
    #define uint64_defined
#endif
#ifndef sint8_defined
    /** 8 bit signed integer. */
#ifndef HMG_SUPPORT_NON8BIT
    typedef signed char         sint8;
#else
    typedef signed short         sint8;
#endif
    #define sint8_defined
#endif
#ifndef sint16_defined
    /** 16 bit signed integer. */
    typedef signed short        sint16;
    #define sint16_defined
#endif
#ifndef sint32_defined
    /** 32 bit signed integer. */
    typedef signed long         sint32;
    #define sint32_defined
#endif
#ifndef sint64_defined
    /** 64 bit signed integer. */
    typedef signed long long    sint64;
    #define sint64_defined
#endif
#ifndef float32_defined
    /** 32 bit floating point number. */
    typedef float               float32;
    #define float32_defined
#endif
#ifndef float64_defined
    /** 64 bit floating point number. */
    typedef double              float64;
    #define float64_defined
#endif


/// Select mode of Crypto Algorithm
#define HMG_ENABLE_AES_ECB
#define HMG_ENABLE_AES_CBC
#define HMG_ENABLE_AES_CTR
#define HMG_ENABLE_AES_OFB
#define HMG_ENABLE_AES_CCM
#define HMG_ENABLE_AES_GCM
#define HMG_ENABLE_AES_XTS
#define HMG_ENABLE_AES_CMAC
#define HMG_ENABLE_AES_CBCMAC

#define HMG_ENABLE_TDES_ECB
#define HMG_ENABLE_TDES_CBC
#define HMG_ENABLE_TDES_CTR
#define HMG_ENABLE_TDES_CMAC

#define HMG_ENABLE_HASH_SHA160
#define HMG_ENABLE_HASH_SHA224
#define HMG_ENABLE_HASH_SHA256
#define HMG_ENABLE_HASH_SHA384
#define HMG_ENABLE_HASH_SHA512
#define HMG_ENABLE_HASH_SHA512_224
#define HMG_ENABLE_HASH_SHA512_256
//#define HMG_ENABLE_HASH_WHIRLPOOL
//#define HMG_ENABLE_HASH_SHAKE256

#define HMG_ENABLE_HMAC_SHA160
#define HMG_ENABLE_HMAC_SHA224
#define HMG_ENABLE_HMAC_SHA256
#define HMG_ENABLE_HMAC_SHA384
#define HMG_ENABLE_HMAC_SHA512

//#define HMG_ENABLE_CHACHA20
//#define HMG_ENABLE_POLY1305
//#define HMG_ENABLE_CHACHA20_POLY1305

// only use PC because oepration time is too long. (about 5 sec in PC)
//#define HMG_ENABLE_RSA_KEYGENERATE

#define HMG_ENABLE_RSA_MODEXP
#define HMG_ENABLE_RSAES_PKCS1V15
#define HMG_ENABLE_RSAES_PKCS1OAEP
#define HMG_ENABLE_RSASSA_PKCS1V15
#define HMG_ENABLE_RSASSA_PKCS1PSS
#define HMG_ENABLE_DH

#define HMG_ENABLE_ECC_KEYGENERATE
#define HMG_ENABLE_ECC_ECDSA
#define HMG_ENABLE_ECC_ECDH
#define HMG_ENABLE_ECC_ECIES
//#define HMG_ENABLE_ECC_X448
//#define HMG_ENABLE_ECC_ED448

#define HMG_ENABLE_PBKDF2
#define HMG_ENABLE_HDRBG
//#define HMG_ENABLE_X509


#define HMG_ENABLE_SLICE
#define HMG_ENABLE_CALLBACK

#define HMG_ENABLE_ECC_ALL


// not implementation: 192U, 384U
#define SECP_CURVE_P160r1   160u
#define NIST_CURVE_P192r1   192u //x
#define NIST_CURVE_P224r1   224u
#define NIST_CURVE_P256r1   256u
#define NIST_CURVE_P384r1   384u //x
#define NIST_CURVE_P521r1   521u

#ifndef ECC_CURVE_TYPE
#define ECC_CURVE_TYPE  NIST_CURVE_P256r1
#endif
#if (ECC_CURVE_TYPE == NIST_CURVE_P521r1)
#define HMG_SLICE_ECC 1u
#ifdef HMG_ENABLE_ECC_ECIES
#undef HMG_ENABLE_ECC_ECIES
#endif
#else
#define HMG_SLICE_ECC 4u //ECC the number of slice: 1, 2, 4, 8 in ECC p-256 point mult
#endif
//#define HMG_ECDSA_CONST_K

//#define HMG_RSA_USE_CRT // rsa algorithm using CRT mode
#define HMG_RSA_BIT_SIZE 2048U // rsa algorithm bit length size
#define HMG_SLICE_PUBLIC 4U // rsa the number of slice: 1, 2, 4 in RSA2048 public key
#define HMG_SLICE_PRIVATE 256U // rsa the number of slice: 1, 2, 4, 8, 16, 32, 64, 128, 256 in RSA2048 private key



#endif // HMG_CONFIG_H_
