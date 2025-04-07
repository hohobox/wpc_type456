/*******************************************************************************
**                                                                            **
**  (C) 2019 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Hmg_Keccak.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : Dummy Hmg_Keccak                                              **
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

#ifndef HMG_KECCAK_H_
#define HMG_KECCAK_H_

/*******************************************************************************
**                              Include Section                               **
*******************************************************************************/

#include "Hmg_Common.h"

typedef struct
{
    uint64 A[25];
    uint8 a[200];
    uint32 i;
} HmgKeccakCtx;

/** \brief  Shake256 start.
*
* initializes shake values
* \param[inout] ctx   context of Shake256
*/
extern void Hmg_Shake256Start(
    HMG_INOUT HmgKeccakCtx *ctx
    );


/** \brief  Shake256 update.
*
* updates hash context for a block of data
* \param[inout] ctx     context of Shake256
* \param[in]    M       input data
* \param[in]    mlen    input data length
*/
extern void Hmg_Shake256Update(
    HMG_INOUT HmgKeccakCtx *ctx,
    HMG_IN uint8 *M,
    HMG_IN int mlen
    );

/** \brief  Shake256 finish.
*
* updates hash context for a block of data
* \param[inout] ctx     context of Shake256
* \param[out]   D       output hash value
* \param[in]    dlen    output hash value length
*/
extern void Hmg_Shake256Finish(
    HMG_INOUT HmgKeccakCtx *ctx,
    HMG_OUT uint8 *D,
    HMG_IN int dlen
    );

/** \brief  Shake256 calculation.
*
* calculate shake256 for the input data
* \param[out]   D       output hash value
* \param[in]    dlen    output hash value length
* \param[in]    M       input data
* \param[in]    mlen    input data length
*/
extern void Hmg_Shake256(
    HMG_OUT uint8* D,
    HMG_IN int dlen,
    HMG_IN uint8* M,
    HMG_IN int mlen
    );


#endif /* HMG_SHA512_H */

/*******************************************************************************
**                                End of File                                 **
*******************************************************************************/
