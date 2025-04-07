/*******************************************************************************
**                                                                            **
**  (C) 2019 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Hmg_Curve448.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : Dummy Hmg_Curve448.h                                          **
**                                                                            **
**  PURPOSE   : Header file for dummy code                                    **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                             Revision History                               **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.0.0     18-Jul-2019   Sinil        Initial version                       **
*******************************************************************************/

#ifndef HMG_CURVE448_H
#define HMG_CURVE448_H

/*******************************************************************************
**                              Include Section                               **
*******************************************************************************/
#include "Hmg_Common.h"

#define HMG_X448_BYTES 56

#define HMG_ED448_KEY_BYTES 57
#define HMG_ED448_SIGN_BYTES 114

uint8 Hmg_EcckeyGenerate_p448(
    HMG_OUT uint8 publickey[HMG_X448_BYTES],
    HMG_IN uint8 privatekey[HMG_X448_BYTES]
    );
uint8 Hmg_EccEcdh_p448(
    HMG_OUT uint8 secretValue[HMG_X448_BYTES],
    HMG_IN  uint8 privatekeyA[HMG_X448_BYTES],
    HMG_IN  uint8 publickeyB[HMG_X448_BYTES]
    );

uint8 Hmg_EcckeyGenerate_ed448(
    HMG_OUT uint8 publickey[HMG_ED448_KEY_BYTES],
    HMG_IN uint8 privatekey[HMG_ED448_KEY_BYTES]
    );
uint8 Hmg_EccEddsaSign_ed448(
    HMG_OUT uint8 signature[HMG_ED448_SIGN_BYTES],
    HMG_IN  uint8* message,
    HMG_IN  uint32 message_len,
    HMG_IN  uint8* context,
    HMG_IN  uint8 context_len,
    HMG_IN  uint8 privatekey[HMG_ED448_KEY_BYTES]
    );
uint8 Hmg_EccEddsaVerify_ed448(
    HMG_IN uint8 signature[HMG_ED448_SIGN_BYTES],
    HMG_IN uint8* message,
    HMG_IN uint32 message_len,
    HMG_IN uint8* context,
    HMG_IN uint8 context_len,
    HMG_IN uint8 publickey[HMG_ED448_KEY_BYTES]
    );
#endif /* HMG_SHA512_H */

/*******************************************************************************
**                                End of File                                 **
*******************************************************************************/
