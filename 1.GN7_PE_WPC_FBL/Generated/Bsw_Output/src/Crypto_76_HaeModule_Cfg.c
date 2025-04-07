/*!
  @file Crypto_76_HaeModule_Cfg.c
  @brief Crypto configuration source file
  @note Copyright 2020 by HYUNDAI AUTOEVER Corp. All rights reserved.
*/
#if 0 /* mobilgene doesn't support this header file */
#include "StandardTypes.h"
#else
#include "Std_Types.h"
#endif
#include "Csm.h"
#include "Crypto_76_HaeModule_Cfg.h"
#include "Crypto_76_HaeModule_Crypto.h"
#include "Crypto_76_HaeModule_Job.h"
#include "Crypto_76_HaeModule_HsmPrimitive.h"
#include "Crypto_76_HaeModule_CryptoLibPrimitive.h"

CryptoKey gHaeModule_CryptoKeys[HAEMODULE_CRYPTOKEYS_NUM];
const CryptoPrimitiveList gHaeModule_CryptoPrimitiveList[HAEMODULE_CRYPTOOBJECTS_NUM];
CryptoDriverObject gHaeModule_CryptoDriverObjects[HAEMODULE_CRYPTOOBJECTS_NUM];

#define CRYPTO_76_HAEMODULE_START_ROM_CONST
#include "Crypto_76_HaeModule_MemMap.h"
static const uint8 CryptoKeyElement_RandomSeed_L9_InitValue[16] = {0x01, };
static const uint8 CryptoKeyElement_RSASSA_PKCS1_v1_5_Asims_Public_Key_InitValue[260] = {0x00, };
static const uint8 CryptoKeyElement_PBKDF2_KeyDerivation_algorism_Fota_InitValue[4] = {0x81, };
static const uint8 CryptoKeyElement_PBKDF2_KeyDerivation_TargetKey_key_Fota_InitValue[32] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const uint8 CryptoKeyElement_Dummy_InitValue[32] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#define CRYPTO_76_HAEMODULE_STOP_ROM_CONST
#include "Crypto_76_HaeModule_MemMap.h"

#define CRYPTO_76_HAEMODULE_START_RAM_VAR_CLEARED
#include "Crypto_76_HaeModule_MemMap.h"
static uint8 CryptoKeyElement_RandomSeed_L9_Value[16];
static uint8 CryptoKeyElement_Hash_Dummy_Fota_Value[32];
static uint8 CryptoKeyElement_RSASSA_PKCS1_v1_5_Asims_Public_Key_Value[260];
static uint8 CryptoKeyElement_Fota_Decrypt0Cipher_Value[16];
static uint8 CryptoKeyElement_Fota_Decrypt0IV_Value[16];
static uint8 CryptoKeyElement_Fota_Mac0Key_Value[16];
static uint8 CryptoKeyElement_PBKDF2_KeyDerivation_iteration_Fota_Value[4];
static uint8 CryptoKeyElement_PBKDF2_KeyDerivation_salt_Fota_Value[48];
static uint8 CryptoKeyElement_PBKDF2_KeyDerivation_algorism_Fota_Value[4];
static uint8 CryptoKeyElement_PBKDF2_KeyDerivation_pw_Fota_Value[16];
static uint8 CryptoKeyElement_PBKDF2_KeyDerivation_HSMKeyIdx_Fota_Value[1];
static uint8 CryptoKeyElement_PBKDF2_KeyDerivation_TargetKey_key_Fota_Value[32];
static uint8 CryptoKeyElement_Dummy_Value[32];
static uint8 CryptoKeyElement_RandomSeed_L10_Value[16];
static uint8 CryptoKeyElement_RSASSA_PKCS1_v1_5_OEUK_Value[260];
#define CRYPTO_76_HAEMODULE_STOP_RAM_VAR_CLEARED
#include "Crypto_76_HaeModule_MemMap.h"

#define CRYPTO_76_HAEMODULE_START_RAM_VAR_INIT
#include "Crypto_76_HaeModule_MemMap.h"
static CryptoKeyElement CryptoKeyElement_RandomSeed_L9 = {4, 16, CryptoKeyElement_RandomSeed_L9_InitValue, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_RandomSeed_L9_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_Hash_Dummy_Fota = {1, 32, NULL, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_Hash_Dummy_Fota_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_RSASSA_PKCS1_v1_5_Asims_Public_Key = {1, 260, CryptoKeyElement_RSASSA_PKCS1_v1_5_Asims_Public_Key_InitValue, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_RSASSA_PKCS1_v1_5_Asims_Public_Key_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_Fota_Decrypt0Cipher = {1, 16, NULL, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_Fota_Decrypt0Cipher_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_Fota_Decrypt0IV = {5, 16, NULL, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_Fota_Decrypt0IV_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_Fota_Mac0Key = {1, 16, NULL, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_Fota_Mac0Key_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_PBKDF2_KeyDerivation_iteration_Fota = {14, 4, NULL, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_PBKDF2_KeyDerivation_iteration_Fota_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_PBKDF2_KeyDerivation_salt_Fota = {13, 48, NULL, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_PBKDF2_KeyDerivation_salt_Fota_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_PBKDF2_KeyDerivation_algorism_Fota = {15, 4, CryptoKeyElement_PBKDF2_KeyDerivation_algorism_Fota_InitValue, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_PBKDF2_KeyDerivation_algorism_Fota_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_PBKDF2_KeyDerivation_pw_Fota = {1, 16, NULL, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_PBKDF2_KeyDerivation_pw_Fota_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_PBKDF2_KeyDerivation_HSMKeyIdx_Fota = {1001, 1, NULL, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_PBKDF2_KeyDerivation_HSMKeyIdx_Fota_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_PBKDF2_KeyDerivation_TargetKey_key_Fota = {1, 32, CryptoKeyElement_PBKDF2_KeyDerivation_TargetKey_key_Fota_InitValue, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_PBKDF2_KeyDerivation_TargetKey_key_Fota_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_Dummy = {1, 32, CryptoKeyElement_Dummy_InitValue, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_Dummy_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_RandomSeed_L10 = {0, 16, NULL, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_RandomSeed_L10_Value, HAEHSM_KEY_TYPE_NONE, 0};
static CryptoKeyElement CryptoKeyElement_RSASSA_PKCS1_v1_5_OEUK = {1, 260, NULL, CRYPTO_RA_ALLOWED, FALSE, FALSE, CRYPTO_WA_ALLOWED, CRYPTO_KE_FORMAT_BIN_OCTET, FALSE, 0, CryptoKeyElement_RSASSA_PKCS1_v1_5_OEUK_Value, HAEHSM_KEY_TYPE_NONE, 0};
#define CRYPTO_76_HAEMODULE_STOP_RAM_VAR_INIT
#include "Crypto_76_HaeModule_MemMap.h"

#define CRYPTO_76_HAEMODULE_START_RAM_VAR_INIT
#include "Crypto_76_HaeModule_MemMap.h"
static CryptoKeyElement* CryptoKeyType_RandomSeed_L9_Elements[] = {&CryptoKeyElement_RandomSeed_L9};
static CryptoKeyElement* CryptoKeyType_Hash_Dummy_Fota_Elements[] = {&CryptoKeyElement_Hash_Dummy_Fota};
static CryptoKeyElement* CryptoKeyType_RSASSA_PKCS1_v1_5_Asims_Public_Key_Elements[] = {&CryptoKeyElement_RSASSA_PKCS1_v1_5_Asims_Public_Key};
static CryptoKeyElement* CryptoKeyType_Fota_Decrypt0Key_Type_Elements[] = {&CryptoKeyElement_Fota_Decrypt0Cipher, &CryptoKeyElement_Fota_Decrypt0IV};
static CryptoKeyElement* CryptoKeyType_Fota_MacVerify0Key_Type_Elements[] = {&CryptoKeyElement_Fota_Mac0Key};
static CryptoKeyElement* CryptoKeyType_PBKDF2_KeyDerivation_Key_Fota_Elements[] = {&CryptoKeyElement_PBKDF2_KeyDerivation_iteration_Fota, &CryptoKeyElement_PBKDF2_KeyDerivation_salt_Fota, &CryptoKeyElement_PBKDF2_KeyDerivation_algorism_Fota, &CryptoKeyElement_PBKDF2_KeyDerivation_pw_Fota, &CryptoKeyElement_PBKDF2_KeyDerivation_HSMKeyIdx_Fota};
static CryptoKeyElement* CryptoKeyType_PBKDF2_KeyDerivation_TargetKey_Fota_Elements[] = {&CryptoKeyElement_PBKDF2_KeyDerivation_TargetKey_key_Fota};
static CryptoKeyElement* CryptoKeyType_Dummy_Elements[] = {&CryptoKeyElement_Dummy};
static CryptoKeyElement* CryptoKeyType_RandomSeed_L10_Elements[] = {&CryptoKeyElement_RandomSeed_L10};
static CryptoKeyElement* CryptoKeyType_RSASSA_PKCS1_v1_5_OEUK_Elements[] = {&CryptoKeyElement_RSASSA_PKCS1_v1_5_OEUK};
#define CRYPTO_76_HAEMODULE_STOP_RAM_VAR_INIT
#include "Crypto_76_HaeModule_MemMap.h"

#define CRYPTO_76_HAEMODULE_START_RAM_VAR_INIT
#include "Crypto_76_HaeModule_MemMap.h"
static CryptoKeyType CryptoKeyType_RandomSeed_L9 = {CryptoKeyType_RandomSeed_L9_Elements, 1};
static CryptoKeyType CryptoKeyType_Hash_Dummy_Fota = {CryptoKeyType_Hash_Dummy_Fota_Elements, 1};
static CryptoKeyType CryptoKeyType_RSASSA_PKCS1_v1_5_Asims_Public_Key = {CryptoKeyType_RSASSA_PKCS1_v1_5_Asims_Public_Key_Elements, 1};
static CryptoKeyType CryptoKeyType_Fota_Decrypt0Key_Type = {CryptoKeyType_Fota_Decrypt0Key_Type_Elements, 2};
static CryptoKeyType CryptoKeyType_Fota_MacVerify0Key_Type = {CryptoKeyType_Fota_MacVerify0Key_Type_Elements, 1};
static CryptoKeyType CryptoKeyType_PBKDF2_KeyDerivation_Key_Fota = {CryptoKeyType_PBKDF2_KeyDerivation_Key_Fota_Elements, 5};
static CryptoKeyType CryptoKeyType_PBKDF2_KeyDerivation_TargetKey_Fota = {CryptoKeyType_PBKDF2_KeyDerivation_TargetKey_Fota_Elements, 1};
static CryptoKeyType CryptoKeyType_Dummy = {CryptoKeyType_Dummy_Elements, 1};
static CryptoKeyType CryptoKeyType_RandomSeed_L10 = {CryptoKeyType_RandomSeed_L10_Elements, 1};
static CryptoKeyType CryptoKeyType_RSASSA_PKCS1_v1_5_OEUK = {CryptoKeyType_RSASSA_PKCS1_v1_5_OEUK_Elements, 1};
#define CRYPTO_76_HAEMODULE_STOP_RAM_VAR_INIT
#include "Crypto_76_HaeModule_MemMap.h"

#define CRYPTO_76_HAEMODULE_START_RAM_VAR_INIT
#include "Crypto_76_HaeModule_MemMap.h"
CryptoKey gHaeModule_CryptoKeys[HAEMODULE_CRYPTOKEYS_NUM] = {
	{CRYPTOKEY_RANDOMSEED_L9, &CryptoKeyType_RandomSeed_L9, FALSE},
	{CRYPTOKEY_HASH_DUMMY_FOTA, &CryptoKeyType_Hash_Dummy_Fota, FALSE},
	{CRYPTOKEY_RSASSA_PKCS1_V1_5_ASIMS_PUBLIC_KEY, &CryptoKeyType_RSASSA_PKCS1_v1_5_Asims_Public_Key, FALSE},
	{CRYPTOKEY_FOTA_DECRYPT0KEY, &CryptoKeyType_Fota_Decrypt0Key_Type, FALSE},
	{CRYPTOKEY_FOTA_MACVERIFY0KEY, &CryptoKeyType_Fota_MacVerify0Key_Type, FALSE},
	{CRYPTOKEY_PBKDF2_KEYDERIVATION_KEY_FOTA, &CryptoKeyType_PBKDF2_KeyDerivation_Key_Fota, FALSE},
	{CRYPTOKEY_PBKDF2_KEYDERIVATION_TARGETKEY_FOTA, &CryptoKeyType_PBKDF2_KeyDerivation_TargetKey_Fota, FALSE},
	{CRYPTOKEY_DUMMY, &CryptoKeyType_Dummy, FALSE},
	{CRYPTOKEY_RANDOMSEED_L10, &CryptoKeyType_RandomSeed_L10, FALSE},
	{CRYPTOKEY_RSASSA_PKCS1_V1_5_OEUK, &CryptoKeyType_RSASSA_PKCS1_v1_5_OEUK, FALSE},
};
#define CRYPTO_76_HAEMODULE_STOP_RAM_VAR_INIT
#include "Crypto_76_HaeModule_MemMap.h"

#define CRYPTO_76_HAEMODULE_START_ROM_CONST
#include "Crypto_76_HaeModule_MemMap.h"
static const CryptoPrimitive HaeHsm_CryptoPrimtives[] = {
	{CRYPTO_KEYDERIVE, CRYPTO_ALGOFAM_PBKDF2, CRYPTO_ALGOFAM_SHA2_256, CRYPTO_ALGOMODE_HMAC, (Crypto_PrimitiveProcess)HaeHsm_Primitive_KeyDerive},
	{CRYPTO_RANDOMGENERATE, CRYPTO_ALGOFAM_RNG, CRYPTO_ALGOFAM_NOT_SET, CRYPTO_ALGOMODE_NOT_SET, (Crypto_PrimitiveProcess)HaeHsm_Primitive_PseudoRandomGenerate},
	{CRYPTO_RANDOMGENERATE, CRYPTO_ALGOFAM_RNG, CRYPTO_ALGOFAM_NOT_SET, CRYPTO_ALGOMODE_CUSTOM, (Crypto_PrimitiveProcess)HaeHsm_Primitive_TrueRandomGenerate},
};
static const CryptoPrimitive HaeCryptoLib_CryptoPrimtives[] = {
	{CRYPTO_MACVERIFY, CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, CRYPTO_ALGOMODE_CMAC, (Crypto_PrimitiveProcess)HaeCryptoLib_Primitive_AesCmac_Verify},
	{CRYPTO_DECRYPT, CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, CRYPTO_ALGOMODE_CTR, (Crypto_PrimitiveProcess)HaeCryptoLib_Primitive_AesCtr_Decrypt},
	{CRYPTO_RANDOMGENERATE, CRYPTO_ALGOFAM_DRBG, CRYPTO_ALGOFAM_SHA2_256, CRYPTO_ALGOMODE_NOT_SET, (Crypto_PrimitiveProcess)HaeCryptoLib_Primitive_HashDrbgSha256_Generate},
	{CRYPTO_RANDOMSEED, CRYPTO_ALGOFAM_DRBG, CRYPTO_ALGOFAM_SHA2_256, CRYPTO_ALGOMODE_NOT_SET, (Crypto_PrimitiveProcess)HaeCryptoLib_Primitive_HashDrbgSha256_Seed},
	{CRYPTO_SIGNATUREVERIFY, CRYPTO_ALGOFAM_RSA, CRYPTO_ALGOFAM_SHA2_256, CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5, (Crypto_PrimitiveProcess)HaeCryptoLib_Primitive_RsassaPkcs15Sha256_Verify},
	{CRYPTO_HASH, CRYPTO_ALGOFAM_SHA2_256, CRYPTO_ALGOFAM_NOT_SET, CRYPTO_ALGOMODE_NOT_SET, (Crypto_PrimitiveProcess)HaeCryptoLib_Primitive_Sha256},
};
#define CRYPTO_76_HAEMODULE_STOP_ROM_CONST
#include "Crypto_76_HaeModule_MemMap.h"

#define CRYPTO_76_HAEMODULE_START_ROM_CONST
#include "Crypto_76_HaeModule_MemMap.h"
const CryptoPrimitiveList gHaeModule_CryptoPrimitiveList[HAEMODULE_CRYPTOOBJECTS_NUM] = {
    {
        0,
        (Crypto_PrimitiveInit)HaeHsm_Primtive_Init,
        (Crypto_PrimitiveProcess)HaeHsm_Primtive_CancelJob,
        (Crypto_PrimitiveGetState)HaeHsm_Primitive_GetState,
        (Crypto_PrimitiveSetState)HaeHsm_Primitive_SetState,
    },
    {
        1,
        (Crypto_PrimitiveInit)HaeCryptoLib_Primtive_Init,
        (Crypto_PrimitiveProcess)HaeCryptoLib_Primtive_CancelJob,
        (Crypto_PrimitiveGetState)HaeCryptoLib_Primitive_GetState,
        (Crypto_PrimitiveSetState)HaeCryptoLib_Primitive_SetState,
    },
};
#define CRYPTO_76_HAEMODULE_STOP_ROM_CONST
#include "Crypto_76_HaeModule_MemMap.h"

#define CRYPTO_76_HAEMODULE_START_RAM_VAR_CLEARED
#include "Crypto_76_HaeModule_MemMap.h"
static CryptoObjectQueue HaeHsm_Queue[10];
static CryptoObjectQueue HaeCryptoLib_Queue[10];
#define CRYPTO_76_HAEMODULE_STOP_RAM_VAR_CLEARED
#include "Crypto_76_HaeModule_MemMap.h"

#define CRYPTO_76_HAEMODULE_START_RAM_VAR_INIT
#include "Crypto_76_HaeModule_MemMap.h"
CryptoDriverObject gHaeModule_CryptoDriverObjects[HAEMODULE_CRYPTOOBJECTS_NUM] = {
	{0, 10, HaeHsm_CryptoPrimtives, 3, NULL, HaeHsm_Queue, NULL, {(uint32)HAEMODULE_JOBSTATE_IDLE,0,NULL,0,NULL,0,0,0}, NULL, 0},
	{1, 10, HaeCryptoLib_CryptoPrimtives, 6, NULL, HaeCryptoLib_Queue, NULL, {(uint32)HAEMODULE_JOBSTATE_IDLE,0,NULL,0,NULL,0,0,0}, NULL, 0},
};
#define CRYPTO_76_HAEMODULE_STOP_RAM_VAR_INIT
#include "Crypto_76_HaeModule_MemMap.h"

#define CRYPTO_76_HAEMODULE_START_SEC_CODE
#include "Crypto_76_HaeModule_MemMap.h"
/*!
  @brief If asynchronous job processing is configured and there are job queues, the function is called cyclically to process queued jobs.
  @details Service ID[hex]: 0x0C \n
        It is necessary for asynchronous job processing. For synchronous job processing providing the main function is optional.
  @param[in] None
  @return None
*/
void Crypto_76_HaeModule_HaeHsm_MainFunction( void )
{
    HaeModule_Crypto_MainFunction(0);
}
void Crypto_76_HaeModule_HaeCryptoLib_MainFunction( void )
{
    HaeModule_Crypto_MainFunction(1);
}
#define CRYPTO_76_HAEMODULE_STOP_SEC_CODE
#include "Crypto_76_HaeModule_MemMap.h"

