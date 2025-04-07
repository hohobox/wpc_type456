/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE:           ComXf_Macros.h                                      **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file defines macro definitions used for ComXf  **
**                                                                            **
**  HARDWARE DEPENDANT [Yes/No]: No                                           **
**                                                                            **
**  AUTOSAR RELEASE:  4.3.0                                                   **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 1.0.0     31-Jan-2018   AUTOEVER    Initial Version                        **
** 1.0.4     13-Jul-2018   Chan Kim    #13396                                 **
*******************************************************************************/
#ifndef COMXF_MACROS_H
#define COMXF_MACROS_H

/*******************************************************************************
**                         Header File Include Section                        **
*******************************************************************************/

/*******************************************************************************
**                             Version Information                            **
*******************************************************************************/

/*******************************************************************************
**                              MACRO Definition                              **
*******************************************************************************/
/* Macro used for module initialization */
#define COMXF_CS_INIT                      0x01

/* Macro used for module deinitialization */
#define COMXF_CS_DEINIT                    0x00

/* Macro used for GetVersionInfo Service Id */
#define COMXF_GETVERSIONINFO_SID           0x00

/* Macro used for API service called without initialization */
#define COMXF_E_UNINIT                     0x01

/* Macro used for an invalid configuration set was selected */
#define COMXF_E_INIT_FAILED                0x02

/* Macro used for API service called with wrong parameter */
#define COMXF_E_PARAM                      0x03

/* Macro used for API service called with invalid pointer */
#define COMXF_E_PARAM_POINTER              0x04

/* Macro used for boolean true value */
#define COMXF_TRUE                         0x01

/* Macro used for boolean false value */
#define COMXF_FALSE                        0x00

/* Macro used for boolean false value */
#define COMXF_BOOLEAN_ZERO                 0x00

/* Macro used for Big Endian CPU */
#define COMXF_BIG_ENDIAN                   0x01

/* Macro used for Little Endian CPU */
#define COMXF_LITTLE_ENDIAN                0x00

/* Macro used for Compatin 1 value */
#define COMXF_HEX_01                       0x01

/* Macro used for Compatin 0 value */
#define COMXF_HEX_00                       0x00

/* Macro used for Checking signed value */
#define COMXF_NOT_SIGNED_SIGNAL            0x00

/* Macro used for error condtion of no data */
#define COMXF_E_NO_DATA                    0x01

/* Macro used for error condtion of generic data */
#define COMXF_E_SER_GENERIC_ERROR          0x81

/* Macro used for transformer API service id */
#define COMXF_TRANSFORMER_SERVICE_ID       0x03

/* Macro used for inverse transformer API service id */
#define COMXF_INVTRANSFORMER_SERVICE_ID    0x04

/* Macro used for GetVersionInfo API service id */
#define COMXF_GETVERSIONINFO_SERVICE_ID    0x00

/* Macro used for ComXf module instance id */
#define COMXF_INSTANCE_ID                  0x00

/* Macro used for 2 bytes */
#define COMXF_TWO_BYTES                    2

/* Macro used for 3 bytes */
#define COMXF_THREE_BYTES                  3

/* Macro used for shifting by 8 */
#define COMXF_SHIFT_BY_EIGHT               8

/* Macro used for array index zero */
#define COMXF_ZEROTH_BYTE                  0

/* Macro used for array index one */
#define COMXF_FIRST_BYTE                   1

/* Macro used for array index two */
#define COMXF_SECOND_BYTE                  2

/* Macro used for array index three */
#define COMXF_THIRD_BYTE                   3

/* Macro used for array index seven */
#define COMXF_SEVENTH_BYTE                 7

/* Macro used for shifting by 32  */
#define COMXF_SHIFT_BY_THIRTYTWO           32

/* Macro used for define zero value  */
#define COMXF_ZERO                         0

/*******************************************************************************
**                              Type Definition                               **
*******************************************************************************/

/*******************************************************************************
**                         Global Variable Declaration                        **
*******************************************************************************/

/*******************************************************************************
**                             Function Declaration                           **
*******************************************************************************/

#endif /* COMXF_MACROS_H */
/*******************************************************************************
**                                 End of file                                **
*******************************************************************************/
