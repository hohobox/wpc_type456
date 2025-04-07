/*******************************************************************************
**                                                                            **
**  (C) 2019 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Hmg_Curve448.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : Dummy Hmg_Curve448                                            **
**                                                                            **
**  PURPOSE   : Source file for dummy code                                    **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                             Revision History                               **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.0.0     18-Jul-2019   Sinil        Initial version                       **
*******************************************************************************/

/*******************************************************************************
**                              Include Section                               **
*******************************************************************************/
/* CryptoLib library dummy header file */
#include "Hmg_Curve448.h"

uint8 Hmg_EcckeyGenerate_ed448(
    HMG_OUT uint8 publickey[HMG_ED448_KEY_BYTES],
    HMG_IN uint8 privatekey[HMG_ED448_KEY_BYTES]
    )
{ 

	//nothing to do. just for the Dummy code to avoid the compile error. 

}

uint8 Hmg_EcckeyGenerate_p448(
    HMG_OUT uint8 publickey[HMG_X448_BYTES],
    HMG_IN uint8 privatekey[HMG_X448_BYTES]
    )
{
	//nothing to do. just for the Dummy code to avoid the compile error. 
}

uint8 Hmg_EccEcdh_p448(
    HMG_OUT uint8 secretValue[HMG_X448_BYTES],
    HMG_IN  uint8 privatekeyA[HMG_X448_BYTES],
    HMG_IN  uint8 publickeyB[HMG_X448_BYTES]
    )
{
	//nothing to do. just for the Dummy code to avoid the compile error. 
}
/*******************************************************************************
**                        Global Function Definitions                         **
*******************************************************************************/