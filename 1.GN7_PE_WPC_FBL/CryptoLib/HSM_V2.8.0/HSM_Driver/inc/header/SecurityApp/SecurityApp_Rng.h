/*!
  @file SecurityApp_Rng.h
  @brief Security API header file for Random
  @note Copyright 2020 by HYUNDAI AUTOEVER Corp. All rights reserved.
*/
#ifndef SECURITYAPP_TRNG_H_
#define SECURITYAPP_TRNG_H_

#include "Hsm_Types.h"

/******************************************************************************/
/*                                  Type Define                               */
/******************************************************************************/
typedef struct
{
	UINT16 jobId;
	UINT32 count;
	UINT16 osTask;
} HSMAPI_TRNG_CTX_t;

/******************************************************************************/
/*                                    TRNG		                              */
/******************************************************************************/
/*!
  @brief Request TRNG service
  @details The user inputs the desired length of TRNG in word(4-byte) units when calling Update function. The maximum length is 256 word(1024 bytes). \n
        If the parameter apiObj of the ASync function is NULL, it operates in Sync mode. \n
        If apiObj is not NULL, it operates in Async mode. At this time, "out" parameters including apiObj must be declared as global variables \n 
        to save the result value after the function is completed. Use HSM_WaitObjResp API to check completion for Async mode.
  @param[in, out] apiObj    Handler for Async mode. If it is NULL, it operates in Sync mode. User should not change the contents of this variable.
  @param[out] randValue     generated TRNG value 
  @param[in] len            TRNG value length user want to get
  @return E_OK: This is returned when a function execution is successful. \n
        E_NOT_OK: This is returned when a function execution fails. \n
        HSM_E_BUSY: HSM internal task is busy. \n
        HSM_E_WAIT: HSM is still working with HOST's request. \n
        HSM_E_WRONG_SEQ: API call sequence is incorrect. \n
        HSM_E_NOT_SUPPORTED: Not supported feature in HSM Framework. \n
        HSM_E_LENGTH_NOT_VALID: Invalid parameter length. \n
        HSM_E_VALUE_NOT_VALID: Invalid parameter value. \n
        HSM_E_KEY_NOT_VALID: Invalid key index parameter. \n
        HSM_E_UNINIT: HSM_DriverInitialize is not performed
*/
Std_ReturnType HSM_TrueRandomGenerate(UINT8 *randValue, UINT32 len);
Std_ReturnType HSM_TrueRandomGenerate_ASync(HSMAPI_OBJ_t *apiObj, UINT8 *randValue, UINT32 len);

/*!
  @brief Request PRNG service
  @details The user inputs the desired length of PRNG in word(4-byte) units when calling Update function. The maximum length is 256 word(1024 bytes). \n
        If the parameter apiObj of the ASync function is NULL, it operates in Sync mode. \n
        If apiObj is not NULL, it operates in Async mode. At this time, "out" parameters including apiObj must be declared as global variables \n 
        to save the result value after the function is completed. Use HSM_WaitObjResp API to check completion for Async mode.
  @param[in, out] apiObj    Handler for Async mode. If it is NULL, it operates in Sync mode. User should not change the contents of this variable.
  @param[out] randValue     generated TRNG value 
  @param[in] len            TRNG value length user want to get
  @return E_OK: This is returned when a function execution is successful. \n
        E_NOT_OK: This is returned when a function execution fails. \n
        HSM_E_BUSY: HSM internal task is busy. \n
        HSM_E_WAIT: HSM is still working with HOST's request. \n
        HSM_E_WRONG_SEQ: API call sequence is incorrect. \n
        HSM_E_NOT_SUPPORTED: Not supported feature in HSM Framework. \n
        HSM_E_LENGTH_NOT_VALID: Invalid parameter length. \n
        HSM_E_VALUE_NOT_VALID: Invalid parameter value. \n
        HSM_E_KEY_NOT_VALID: Invalid key index parameter. \n
        HSM_E_UNINIT: HSM_DriverInitialize is not performed
*/
Std_ReturnType HSM_PseudoRandomGenerate(UINT8 *randValue, UINT32 len);
Std_ReturnType HSM_PseudoRandomGenerate_ASync(HSMAPI_OBJ_t *apiObj, UINT8 *randValue, UINT32 len);

#endif /* SECURITYAPP_TRNG_H_ */
