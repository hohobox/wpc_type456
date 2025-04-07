/* polyspace-begin MISRA-C3:D4.10 [Not a defect:Medium] "No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)" */
/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: MemMap.h                                                      **
**                                                                            **
**  TARGET    : MCU(MPC, RH850, ..) using GHS complier                        **
**                                                                            **
**  PRODUCT   : AUTOSAR BSW R4.0.3 Modules                                    **
**                                                                            **
**  PURPOSE   : Provision for sections for memory mapping.                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By     Description                                 **
********************************************************************************
** 1.1.71    28-03-2023    #39808                                             **
** 1.1.70    03-03-2023    #39562                                             **
** 1.1.69    28-09-2022    #37622                                             **
** 1.1.67    30-12-2021    #33607                                             **
** 1.1.65    30-11-2021    #33234                                             **
** 1.1.63    27-05-2021    #29996                                             **
** 1.1.63    03-03-2021    #28566                                             **
** 1.1.61    16-02-2021    #28350                                             **
** 1.1.60    25-01-2021    #27917                                             **
** 1.1.59    21-01-2021    #27872                                             **
** 1.1.58    29-12-2020    #27381                                             **
** 1.1.57    18-11-2020    #26589                                             **
** 1.1.56    04-11-2020    #26411                                             **
** 1.1.55    06-10-2020    #25914, #25933, #25935, #25914                     **
** 1.1.54    29-09-2020    #25890                                             **
** 1.1.52    26-06-2020    #24371                                             **
** 1.1.50    29-05-2020    #16510                                             **
** 1.1.48    18-05-2020    #23452                                             **
** 1.1.45    24-12-2019    #20866                                             **
** 1.1.43    25-04-2019    #17252, #17253                                     **
** 1.1.42    26-03-2019    #16335                                             **
** 1.1.41    15-01-2019    #15432                                             **
** 1.1.40    04-01-2019    #15275                                             **
** 1.1.39    02-01-2018    #14894                                             **
** 1.1.36    04-12-2018    #13737                                             **
** 1.1.35    25-10-2018    #14397                                             **
** 1.1.34    21-09-2018    #14111                                             **
** 1.1.33    17-09-2018    #13924                                             **
** 1.1.32    17-09-2018    #14111                                             **
** 1.1.30    03-09-2018    #13356                                             **
** 1.1.29    11-05-2018    #13649                                             **
** 1.1.27    11-05-2018    #11822                                             **
** 1.1.26    20-02-2018    #11714                                             **
** 1.1.24    31-01-2018    #11097                                             **
** 1.1.22    15-01-2018    #11251                                             **
** 1.1.21    12-01-2018    #11120 Add E2EXf Memmap Section                    **
** 1.1.20    26-10-2017    #10285                                             **
** 1.1.19    26-09-2017    #9885                                              **
** 1.1.18    25-09-2017    #10074                                             **
** 1.1.17    19-09-2017    #9992                                              **
** 1.1.16    30-08-2017    #9878                                              **
** 1.1.15    30-08-2017    #6139                                              **
** 1.1.14    29-08-2017    #9726                                              **
** 1.1.13    11-07-2017    #8576                                              **
** 1.1.11    29-06-2017    #8988                                              **
** 1.1.10    27-06-2017    #8988                                              **
** 1.1.9     23-05-2017    #8599                                              **
** 1.1.8     15-05-2017    #8516                                              **
** 1.1.7     24-04-2017    #7921                                              **
** 1.1.5     04-04-2017    #8062, #8063                                       **
** 1.1.4     23-03-2017    #7406                                              **
** 1.1.3     22-03-2017    #7406                                              **
** 1.1.2     10-02-2017    #7471                                              **
** 1.1.0     23-01-2017    #7229                                              **
** 1.0.6     19-01-2017    #7166                                              **
** 1.0.5     01-12-2016    #6829                                              **
** 1.0.4     29-11-2016    #6781 #6782 #6796                                  **
** 1.0.3     21-11-2016    #5032                                              **
** 1.0.2     15-11-2016    Integrated Memmap for GHS compiler                 **
** 1.0.1     09-11-2016    Integrated Memmap for GHS compiler                 **
** 1.0.0     29-Apr-2014   MJ.Woo Initial Version                             **
*******************************************************************************/

/*******************************************************************************
* PRE-JUSTIFICATION BEGINE SECTION (MISRA-C RULE CHECKER)
* These rules will not be applied for varification based on the MISRA Rule
* in Rte generated source
*******************************************************************************/
/* polyspace:begin<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping) */
/* polyspace-begin MISRA-C3:D1.1 [Not a Defect:Medium] "#pragma is used for assembler" */
/* polyspace-begin MISRA-C3:1.1 [Not a defect:Medium] "No Impact on using macro." */
/* polyspace-begin MISRA-C3:20.5 [Not a defect:Low] "This violation is not impact." */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "HwResource.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define MEMMAP_AR_MAJOR_VERSION   4
#define MEMMAP_AR_MINOR_VERSION   0
#define MEMMAP_AR_PATCH_VERSION   3

/* File version information */
#ifdef ST_MCAL_201
#define MEMMAP_SW_MAJOR_VERSION   2
#define MEMMAP_SW_MINOR_VERSION   0
#else
#define MEMMAP_SW_MAJOR_VERSION   1
#define MEMMAP_SW_MINOR_VERSION   0
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Module section mapping                                **
*******************************************************************************/
/*
 * The symbol 'START_WITH_IF' is undefined.
 *
 * Thus, the preprocessor continues searching for defined symbols.
 * This first #ifdef makes integration of delivered parts of MemMap.h
 * easier because every supplier starts with #elif
 */
#if defined (START_WITH_IF)

/* -------------------------------------------------------------------------- */
/*                                ETHDIAG                                     */
/* -------------------------------------------------------------------------- */
#elif defined (ETHDIAG_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ETHDIAG_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (ETHDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ETHDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_CLEARED_8)
  #undef       ETHDIAG_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (ETHDIAG_STOP_SEC_VAR_CLEARED_8)
  #undef       ETHDIAG_STOP_SEC_VAR_CLEARED_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_CLEARED_16)
  #undef       ETHDIAG_START_SEC_VAR_CLEARED_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (2)

#elif defined (ETHDIAG_STOP_SEC_VAR_CLEARED_16)
  #undef       ETHDIAG_STOP_SEC_VAR_CLEARED_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_CLEARED_32)
  #undef       ETHDIAG_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (ETHDIAG_STOP_SEC_VAR_CLEARED_32)
  #undef       ETHDIAG_STOP_SEC_VAR_CLEARED_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (ETHDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_CONST_BOOLEAN)
  #undef       ETHDIAG_START_SEC_CONST_BOOLEAN
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (ETHDIAG_STOP_SEC_CONST_BOOLEAN)
  #undef       ETHDIAG_STOP_SEC_CONST_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_CONST_8)
  #undef       ETHDIAG_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (ETHDIAG_STOP_SEC_CONST_8)
  #undef       ETHDIAG_STOP_SEC_CONST_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_CONST_16)
  #undef       ETHDIAG_START_SEC_CONST_16
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (2)

#elif defined (ETHDIAG_STOP_SEC_CONST_16)
  #undef       ETHDIAG_STOP_SEC_CONST_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_CONST_32)
  #undef       ETHDIAG_START_SEC_CONST_32
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (ETHDIAG_STOP_SEC_CONST_32)
  #undef       ETHDIAG_STOP_SEC_CONST_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_CONST_UNSPECIFIED)
  #undef       ETHDIAG_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (ETHDIAG_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ETHDIAG_STOP_SEC_CONST_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       ETHDIAG_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (ETHDIAG_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       ETHDIAG_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_NO_INIT_8)
  #undef       ETHDIAG_START_SEC_VAR_NO_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (ETHDIAG_STOP_SEC_VAR_NO_INIT_8)
  #undef       ETHDIAG_STOP_SEC_VAR_NO_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_NO_INIT_16)
  #undef       ETHDIAG_START_SEC_VAR_NO_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (2)

#elif defined (ETHDIAG_STOP_SEC_VAR_NO_INIT_16)
  #undef       ETHDIAG_STOP_SEC_VAR_NO_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_NO_INIT_32)
  #undef       ETHDIAG_START_SEC_VAR_NO_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (ETHDIAG_STOP_SEC_VAR_NO_INIT_32)
  #undef       ETHDIAG_STOP_SEC_VAR_NO_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       ETHDIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (ETHDIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       ETHDIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_INIT_BOOLEAN)
  #undef       ETHDIAG_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (ETHDIAG_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       ETHDIAG_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_INIT_8)
  #undef       ETHDIAG_START_SEC_VAR_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (ETHDIAG_STOP_SEC_VAR_INIT_8)
  #undef       ETHDIAG_STOP_SEC_VAR_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_INIT_16)
  #undef       ETHDIAG_START_SEC_VAR_INIT_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (2)

#elif defined (ETHDIAG_STOP_SEC_VAR_INIT_16)
  #undef       ETHDIAG_STOP_SEC_VAR_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_INIT_32)
  #undef       ETHDIAG_START_SEC_VAR_INIT_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (ETHDIAG_STOP_SEC_VAR_INIT_32)
  #undef       ETHDIAG_STOP_SEC_VAR_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       ETHDIAG_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (ETHDIAG_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       ETHDIAG_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (ETHDIAG_START_SEC_CODE)
  #undef       ETHDIAG_START_SEC_CODE
  #pragma ghs section text=".text.ETHDIAG_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"

#elif defined (ETHDIAG_STOP_SEC_CODE)
  #undef       ETHDIAG_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                ATM                                         */
/* -------------------------------------------------------------------------- */
#elif defined (ATM_START_SEC_CONST_8)
  #undef       ATM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ATM_STOP_SEC_CONST_8)
  #undef       ATM_STOP_SEC_CONST_8

  #pragma ghs section

#elif defined (ATM_START_SEC_CONST_UNSPECIFIED)
  #undef       ATM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (ATM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ATM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (ATM_START_SEC_CODE)
  #undef       ATM_START_SEC_CODE

  #pragma ghs section text=".text.ATM_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.ATM_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ATM_STOP_SEC_CODE)
  #undef       ATM_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                CANTP                                       */
/* -------------------------------------------------------------------------- */
#elif defined (CANTP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTP_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_CLEARED_8)
  #undef       CANTP_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_8)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_CLEARED_16)
  #undef       CANTP_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_16)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (CANTP_START_SEC_CONST_8)
  #undef       CANTP_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTP_STOP_SEC_CONST_8)
  #undef       CANTP_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (CANTP_START_SEC_CONST_16)
  #undef       CANTP_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTP_STOP_SEC_CONST_16)
  #undef       CANTP_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (CANTP_START_SEC_CONST_UNSPECIFIED)
  #undef       CANTP_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTP_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTP_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTP_START_SEC_VAR_INIT_BOOLEAN

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTP_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTP_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_INIT_8)
  #undef       CANTP_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTP_STOP_SEC_VAR_INIT_8)
  #undef       CANTP_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_INIT_16)
  #undef       CANTP_START_SEC_VAR_INIT_16

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTP_STOP_SEC_VAR_INIT_16)
  #undef       CANTP_STOP_SEC_VAR_INIT_16
  #pragma ghs section

#elif defined (CANTP_START_SEC_CODE)
  #undef       CANTP_START_SEC_CODE

  #pragma ghs section text=".text.CANTP_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTP_STOP_SEC_CODE)
  #undef       CANTP_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 DCM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (DCM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       DCM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       DCM_START_SEC_VAR_NO_INIT_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_NO_INIT_8)
  #undef       DCM_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_8)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_NO_INIT_16)
  #undef       DCM_START_SEC_VAR_NO_INIT_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_16)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_NO_INIT_32)
  #undef       DCM_START_SEC_VAR_NO_INIT_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_32)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_32
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DCM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_CLEARED_8)
  #undef       DCM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_8)
  #undef       DCM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_CLEARED_16)
  #undef       DCM_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_16)
  #undef       DCM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_CLEARED_32)
  #undef       DCM_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_32)
  #undef       DCM_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DCM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       DCM_START_SEC_VAR_INIT_BOOLEAN

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_INIT_8)
  #undef       DCM_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_VAR_INIT_8)
  #undef       DCM_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_INIT_16)
  #undef       DCM_START_SEC_VAR_INIT_16

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_VAR_INIT_16)
  #undef       DCM_STOP_SEC_VAR_INIT_16
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_INIT_32)
  #undef       DCM_START_SEC_VAR_INIT_32

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_VAR_INIT_32)
  #undef       DCM_STOP_SEC_VAR_INIT_32
  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DCM_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (DCM_START_SEC_CONST_BOOLEAN)
  #undef       DCM_START_SEC_CONST_BOOLEAN

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DCM_STOP_SEC_CONST_BOOLEAN)
  #undef       DCM_STOP_SEC_CONST_BOOLEAN
  #pragma ghs section

#elif defined (DCM_START_SEC_CONST_8)
  #undef       DCM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DCM_STOP_SEC_CONST_8)
  #undef       DCM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (DCM_START_SEC_CONST_16)
  #undef       DCM_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DCM_STOP_SEC_CONST_16)
  #undef       DCM_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (DCM_START_SEC_CONST_UNSPECIFIED)
  #undef       DCM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DCM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       DCM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (DCM_START_SEC_CODE)
  #undef       DCM_START_SEC_CODE

  #pragma ghs section text=".text.DCM_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_CODE)
  #undef       DCM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (DCM_START_SEC_CALLOUT_CODE)
  #undef       DCM_START_SEC_CALLOUT_CODE

  #pragma ghs section text=".text.DCM_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_CALLOUT_CODE)
  #undef       DCM_STOP_SEC_CALLOUT_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             Dem                                                           */
/* -------------------------------------------------------------------------- */
#elif defined (DEM_START_SEC_CONST_BOOLEAN)
  #undef       DEM_START_SEC_CONST_BOOLEAN

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DEM_STOP_SEC_CONST_BOOLEAN)
  #undef       DEM_STOP_SEC_CONST_BOOLEAN
  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       DEM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       DEM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_CLEARED_8)
  #undef       DEM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_8)
  #undef       DEM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_CLEARED_16)
  #undef       DEM_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_16)
  #undef       DEM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_CLEARED_32)
  #undef       DEM_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_32)
  #undef       DEM_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DEM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DEM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_NO_INIT_8)
  #undef       DEM_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DEM_STOP_SEC_VAR_NO_INIT_8)
  #undef       DEM_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DEM_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DEM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DEM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section
#elif defined (DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section



#elif defined (DEM_START_SEC_CONST_UNSPECIFIED)
  #undef       DEM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DEM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       DEM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (DEM_START_SEC_CODE)
  #undef       DEM_START_SEC_CODE

  #pragma ghs section text=".text.DEM_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DEM_STOP_SEC_CODE)
  #undef       DEM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef DEM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                              Det                                           */
/* -------------------------------------------------------------------------- */
#elif defined (DET_START_SEC_VAR_NO_INIT_16)
  #undef       DET_START_SEC_VAR_NO_INIT_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DET_STOP_SEC_VAR_NO_INIT_16)
  #undef       DET_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section

#elif defined (DET_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DET_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DET_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DET_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (DET_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DET_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (DET_START_SEC_CONST_UNSPECIFIED)
  #undef       DET_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DET_STOP_SEC_CONST_UNSPECIFIED)
  #undef       DET_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (DET_START_SEC_CODE)
  #undef       DET_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DET_STOP_SEC_CODE)
  #undef       DET_STOP_SEC_CODE
  #pragma ghs section


/* -------------------------------------------------------------------------- */
/*                                 E2E                                        */
/* -------------------------------------------------------------------------- */

#elif defined (E2E_START_SEC_CODE)
  #undef       E2E_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (E2E_STOP_SEC_CODE)
  #undef       E2E_STOP_SEC_CODE
  #pragma ghs section

#elif defined (E2E_START_SEC_CODE_ASIL_D)
  #undef       E2E_START_SEC_CODE_ASIL_D

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (E2E_STOP_SEC_CODE_ASIL_D)
  #undef       E2E_STOP_SEC_CODE_ASIL_D
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                             E2EXf                                          */
/* -------------------------------------------------------------------------- */

#elif defined (E2EXF_START_SEC_VAR_INIT_BOOLEAN)
  #undef       E2EXF_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (E2EXF_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       E2EXF_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section

#elif defined (E2EXF_START_SEC_VAR_INIT_ASIL_D_BOOLEAN)
  #undef       E2EXF_START_SEC_VAR_INIT_ASIL_D_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (E2EXF_STOP_SEC_VAR_INIT_ASIL_D_BOOLEAN)
  #undef       E2EXF_STOP_SEC_VAR_INIT_ASIL_D_BOOLEAN
  #pragma ghs section

#elif defined (E2EXF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       E2EXF_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (E2EXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       E2EXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_UNSPECIFIED
  #pragma ghs section

#elif defined (E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_PTR)
  #undef       E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_PTR
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_PTR)
  #undef       E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_PTR
  #pragma ghs section

#elif defined (E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_8)
  #undef       E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_8)
  #undef       E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_8
  #pragma ghs section

#elif defined (E2EXF_START_SEC_CONST_UNSPECIFIED)
  #undef       E2EXF_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (E2EXF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       E2EXF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
  #pragma ghs section

#elif defined (E2EXF_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (E2EXF_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
  #pragma ghs section

#elif defined (E2EXF_START_SEC_CODE)
  #undef       E2EXF_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (E2EXF_STOP_SEC_CODE)
  #undef       E2EXF_STOP_SEC_CODE
  #pragma ghs section

#elif defined (E2EXF_START_SEC_CODE_ASIL_D)
  #undef       E2EXF_START_SEC_CODE_ASIL_D
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (E2EXF_STOP_SEC_CODE_ASIL_D)
  #undef       E2EXF_STOP_SEC_CODE_ASIL_D
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                SD                                          */
/* -------------------------------------------------------------------------- */
#elif defined (SD_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       SD_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (SD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       SD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (SD_START_SEC_VAR_CLEARED_8)
  #undef       SD_START_SEC_VAR_CLEARED_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_8"
#elif defined (SD_STOP_SEC_VAR_CLEARED_8)
  #undef       SD_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (SD_START_SEC_VAR_CLEARED_16)
  #undef       SD_START_SEC_VAR_CLEARED_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_16"
#elif defined (SD_STOP_SEC_VAR_CLEARED_16)
  #undef       SD_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (SD_START_SEC_VAR_CLEARED_32)
  #undef       SD_START_SEC_VAR_CLEARED_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_32"
#elif defined (SD_STOP_SEC_VAR_CLEARED_32)
  #undef       SD_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (SD_START_SEC_CONST_UNSPECIFIED)
  #undef       SD_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
#elif defined (SD_STOP_SEC_CONST_UNSPECIFIED)
  #undef       SD_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (SD_START_SEC_VAR_CONST_UNSPECIFIED)
  #undef       SD_START_SEC_VAR_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
#elif defined (SD_STOP_SEC_VAR_CONST_UNSPECIFIED)
  #undef       SD_STOP_SEC_VAR_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (SD_START_SEC_CODE)
  #undef       SD_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (SD_STOP_SEC_CODE)
  #undef       SD_STOP_SEC_CODE
  #pragma ghs section

/* --------------------------------------------------------------------------*/
/*                               LDCOM                                       */
/* --------------------------------------------------------------------------*/
/* To be used for code section */
#elif defined (LDCOM_START_SEC_CODE)
  #undef LDCOM_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (LDCOM_STOP_SEC_CODE)
  #undef LDCOM_STOP_SEC_CODE
  #pragma ghs section

/* To be used for initializing variables */
#elif defined (LDCOM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef LDCOM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (LDCOM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef LDCOM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

/*To be used for code section */
#elif defined (LDCOM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef LDCOM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (LDCOM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef LDCOM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (LDCOM_START_SEC_CONST_UNSPECIFIED)
  #undef LDCOM_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
#elif defined (LDCOM_STOP_SEC_CONST_UNSPECIFIED)
  #undef LDCOM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                SOMEIPTP                                     */
/* -------------------------------------------------------------------------- */

#elif defined (SOMEIPTP_START_SEC_CODE)
  #undef       SOMEIPTP_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (SOMEIPTP_STOP_SEC_CODE)
  #undef       SOMEIPTP_STOP_SEC_CODE
  #pragma ghs section

#elif defined (SOMEIPTP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       SOMEIPTP_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (SOMEIPTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       SOMEIPTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (SOMEIPTP_START_SEC_VAR_INIT_BOOLEAN)
  #undef       SOMEIPTP_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_BOOLEAN"
#elif defined (SOMEIPTP_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       SOMEIPTP_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section

#elif defined (SOMEIPTP_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED)
  #undef       SOMEIPTP_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_CONFIG_DATA_PREBUILD_UNSPECIFIED"
#elif defined (SOMEIPTP_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED)
  #undef       SOMEIPTP_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                             SomeIpXf                                       */
/* -------------------------------------------------------------------------- */
#elif defined (SOMEIPXF_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef      SOMEIPXF_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_NO_INIT_BOOLEAN"
#elif defined (SOMEIPXF_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef      SOMEIPXF_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_NO_INIT_8)
  #undef      SOMEIPXF_START_SEC_VAR_NO_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_NO_INIT_8"
#elif defined (SOMEIPXF_STOP_SEC_VAR_NO_INIT_8)
  #undef      SOMEIPXF_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_NO_INIT_16)
  #undef      SOMEIPXF_START_SEC_VAR_NO_INIT_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_NO_INIT_16"
#elif defined (SOMEIPXF_STOP_SEC_VAR_NO_INIT_16)
  #undef      SOMEIPXF_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_NO_INIT_ASIL_D_16)
  #undef      SOMEIPXF_START_SEC_VAR_NO_INIT_ASIL_D_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_NO_INIT_ASIL_D_16"
#elif defined (SOMEIPXF_STOP_SEC_VAR_NO_INIT_ASIL_D_16)
  #undef      SOMEIPXF_STOP_SEC_VAR_NO_INIT_ASIL_D_16
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_NO_INIT_32)
  #undef      SOMEIPXF_START_SEC_VAR_NO_INIT_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_NO_INIT_32"
#elif defined (SOMEIPXF_STOP_SEC_VAR_NO_INIT_32)
  #undef      SOMEIPXF_STOP_SEC_VAR_NO_INIT_32
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      SOMEIPXF_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      SOMEIPXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef      SOMEIPXF_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (SOMEIPXF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef      SOMEIPXF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_CLEARED_8)
  #undef      SOMEIPXF_START_SEC_VAR_CLEARED_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_8"
#elif defined (SOMEIPXF_STOP_SEC_VAR_CLEARED_8)
  #undef      SOMEIPXF_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_CLEARED_16)
  #undef      SOMEIPXF_START_SEC_VAR_CLEARED_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_16"
#elif defined (SOMEIPXF_STOP_SEC_VAR_CLEARED_16)
  #undef      SOMEIPXF_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_CLEARED_32)
  #undef      SOMEIPXF_START_SEC_VAR_CLEARED_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_32"
#elif defined (SOMEIPXF_STOP_SEC_VAR_CLEARED_32)
  #undef      SOMEIPXF_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      SOMEIPXF_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      SOMEIPXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_INIT_BOOLEAN)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_BOOLEAN"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section
  
#elif defined (SOMEIPXF_START_SEC_VAR_INIT_ASIL_D_BOOLEAN)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_ASIL_D_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_ASIL_D_BOOLEAN"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_ASIL_D_BOOLEAN)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_ASIL_D_BOOLEAN
  #pragma ghs section
  
#elif defined (SOMEIPXF_START_SEC_VAR_INIT_8)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_8"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_8)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_INIT_16)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_16"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_16)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_16
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_INIT_ASIL_D_16)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_ASIL_D_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_ASIL_D_16"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_ASIL_D_16)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_ASIL_D_16
  #pragma ghs section
  
#elif defined (SOMEIPXF_START_SEC_VAR_INIT_32)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_32"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_32)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_32
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_CONST_BOOLEAN)
  #undef      SOMEIPXF_START_SEC_CONST_BOOLEAN
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_BOOLEAN"
#elif defined (SOMEIPXF_STOP_SEC_CONST_BOOLEAN)
  #undef      SOMEIPXF_STOP_SEC_CONST_BOOLEAN
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_CONST_8)
  #undef      SOMEIPXF_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_8"
#elif defined (SOMEIPXF_STOP_SEC_CONST_8)
  #undef      SOMEIPXF_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_CONST_16)
  #undef      SOMEIPXF_START_SEC_CONST_16
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_16"
#elif defined (SOMEIPXF_STOP_SEC_CONST_16)
  #undef      SOMEIPXF_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_CONST_UNSPECIFIED)
  #undef      SOMEIPXF_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_CONST_UNSPECIFIED)
  #undef      SOMEIPXF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_CODE)
  #undef      SOMEIPXF_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_CODE)
  #undef      SOMEIPXF_STOP_SEC_CODE
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_CODE_ASIL_D)
  #undef      SOMEIPXF_START_SEC_CODE_ASIL_D
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_CODE_ASIL_D)
  #undef      SOMEIPXF_STOP_SEC_CODE_ASIL_D
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_CALLOUT_CODE)
  #undef      SOMEIPXF_START_SEC_CALLOUT_CODE
  #pragma ghs section text=".text.DEFAULT_CALLOUT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_CALLOUT_CODE)
  #undef      SOMEIPXF_STOP_SEC_CALLOUT_CODE
  #pragma ghs section

#elif defined (SOMEIPXF_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef      SOMEIPXF_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_DBTOC_CONFIG_CONST_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef      SOMEIPXF_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 RegMon                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (REGMON_START_SEC_CODE)
  #undef       REGMON_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (REGMON_STOP_SEC_CODE)
  #undef       REGMON_STOP_SEC_CODE
  #pragma ghs section

#elif defined (REGMON_START_SEC_VAR_UNSPECIFIED)
  #undef       REGMON_START_SEC_VAR_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (REGMON_STOP_SEC_VAR_UNSPECIFIED)
  #undef       REGMON_STOP_SEC_VAR_UNSPECIFIED
  #pragma ghs section

#elif defined (REGMON_START_SEC_CONST_UNSPECIFIED)
  #undef       REGMON_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (REGMON_STOP_SEC_CONST_UNSPECIFIED)
  #undef       REGMON_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 OS                                         */
/* -------------------------------------------------------------------------- */

#elif defined (OS_START_SEC_VAR_NO_INIT_8)
  #undef       OS_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OS_STOP_SEC_VAR_NO_INIT_8)
  #undef       OS_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (OS_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OS_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (OS_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OS_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OS_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OS_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (OS_START_SEC_VAR_CLEARED_8)
  #undef       OS_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OS_STOP_SEC_VAR_CLEARED_8)
  #undef       OS_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (OS_START_SEC_VAR_CLEARED_16)
  #undef       OS_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OS_STOP_SEC_VAR_CLEARED_16)
  #undef       OS_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (OS_START_SEC_VAR_CLEARED_32)
  #undef       OS_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OS_STOP_SEC_VAR_CLEARED_32)
  #undef       OS_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (OS_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OS_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (OS_START_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_SAFETY_VAR_CLEARED"
#elif defined (OS_STOP_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (OS_START_SEC_USER_STACK)
  #undef       OS_START_SEC_USER_STACK

  #pragma ghs section bss=".USR_STACK"
#elif defined (OS_STOP_SEC_USER_STACK)
  #undef       OS_STOP_SEC_USER_STACK
  #pragma ghs section

#elif defined (OS_START_SEC_APP_STACK)
  #undef       OS_START_SEC_APP_STACK
  #pragma ghs section bss=".OSAPP_STACK"
#elif defined (OS_STOP_SEC_APP_STACK)
  #undef       OS_STOP_SEC_APP_STACK
  #pragma ghs section

#elif defined (OS_START_SEC_TASK_STACK)
  #undef       OS_START_SEC_TASK_STACK
  #pragma ghs section bss=".OSTASK_STACK"
#elif defined (OS_STOP_SEC_TASK_STACK)
  #undef       OS_STOP_SEC_TASK_STACK
  #pragma ghs section

#elif defined (OS_START_SEC_STACK_CORE0_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_STACK_CORE0_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.OS_RAM_STACK_CORE0_CLEARED_UNSPECIFIED"
#elif defined (OS_STOP_SEC_STACK_CORE0_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_STACK_CORE0_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (OS_START_SEC_STACK_CORE1_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_STACK_CORE1_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.OS_RAM_STACK_CORE1_CLEARED_UNSPECIFIED"
#elif defined (OS_STOP_SEC_STACK_CORE1_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_STACK_CORE1_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (OS_START_SEC_STACK_CORE2_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_STACK_CORE2_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.OS_RAM_STACK_CORE2_CLEARED_UNSPECIFIED"
#elif defined (OS_STOP_SEC_STACK_CORE2_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_STACK_CORE2_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (OS_START_SEC_VAR_INIT_8)
  #undef       OS_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OS_STOP_SEC_VAR_INIT_8)
  #undef       OS_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (OS_START_SEC_VAR_INIT_16)
  #undef       OS_START_SEC_VAR_INIT_16

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OS_STOP_SEC_VAR_INIT_16)
  #undef       OS_STOP_SEC_VAR_INIT_16
  #pragma ghs section

#elif defined (OS_START_SEC_VAR_INIT_32)
  #undef       OS_START_SEC_VAR_INIT_32

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OS_STOP_SEC_VAR_INIT_32)
  #undef       OS_STOP_SEC_VAR_INIT_32
  #pragma ghs section

#elif defined (OS_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OS_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OS_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (OS_START_SEC_CONST_32)
  #undef       OS_START_SEC_CONST_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OS_STOP_SEC_CONST_32)
  #undef       OS_STOP_SEC_CONST_32
  #pragma ghs section

#elif defined (OS_START_SEC_CONST_UNSPECIFIED)
  #undef       OS_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OS_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OS_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (OS_START_SEC_CODE)
  #undef       OS_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OS_STOP_SEC_CODE)
  #undef       OS_STOP_SEC_CODE
  #pragma ghs section

#elif defined (OS_START_SEC_API_CODE)
  #undef       OS_START_SEC_API_CODE

  #pragma ghs section text=".text.OS_API_CODE"
#elif defined (OS_STOP_SEC_API_CODE)
  #undef       OS_STOP_SEC_API_CODE
  #pragma ghs section

#elif defined (OS_USERIF_START_SEC_CODE)
  #undef       OS_USERIF_START_SEC_CODE

  #pragma ghs section text=".text.OS_API_CODE"
#elif defined (OS_USERIF_STOP_SEC_CODE)
  #undef       OS_USERIF_STOP_SEC_CODE
  #pragma ghs section

#elif defined (OS_START_SEC_EXCEPTION_VECTOR)
  #undef       OS_START_SEC_EXCEPTION_VECTOR
  #if (HWRESOURCE_GET_FAMILY() == HWRESOURCE_S32K14X)
    #pragma ghs section data=".vector.EXCEPTION"
  #elif (HWRESOURCE_FAMILY(HWRESOURCE_CYT2BXX) ||\
         HWRESOURCE_FAMILY(HWRESOURCE_CYT4BXX) ||\
         HWRESOURCE_FAMILY(HWRESOURCE_S32G2X))
    #pragma ghs section rodata=".vector.EXCEPTION"
  #else
    #pragma ghs section text=".vector.EXCEPTION"
  #endif

#elif defined (OS_STOP_SEC_EXCEPTION_VECTOR)
  #undef       OS_STOP_SEC_EXCEPTION_VECTOR
  #pragma ghs section

#elif defined (OS_START_SEC_EXCEPTION_VECTOR_CORE1)
  #undef       OS_START_SEC_EXCEPTION_VECTOR_CORE1
  #if (HWRESOURCE_GET_FAMILY() == HWRESOURCE_S32G2X)
    #pragma ghs section rodata=".vector.CORE1"
  #elif (HWRESOURCE_GET_FAMILY() == HWRESOURCE_CYT4BXX)
    #pragma ghs section rodata=".vector.EXCEPTION_Core1"
  #endif

#elif defined (OS_STOP_SEC_EXCEPTION_VECTOR_CORE1)
  #undef       OS_STOP_SEC_EXCEPTION_VECTOR_CORE1
  #pragma ghs section

#elif defined (OS_START_SEC_EXCEPTION_VECTOR_CORE2)
  #undef       OS_START_SEC_EXCEPTION_VECTOR_CORE2
  #if (HWRESOURCE_GET_FAMILY() == HWRESOURCE_S32G2X)
    #pragma ghs section rodata=".vector.CORE2"
  #endif

#elif defined (OS_STOP_SEC_EXCEPTION_VECTOR_CORE2)
  #undef       OS_STOP_SEC_EXCEPTION_VECTOR_CORE2
  #pragma ghs section

#elif defined (OS_START_SEC_INTERRUPT_VECTOR)
  #undef       OS_START_SEC_INTERRUPT_VECTOR

  #pragma ghs section text=".vector.INTERRUPT"
#elif defined (OS_STOP_SEC_INTERRUPT_VECTOR)
  #undef       OS_STOP_SEC_INTERRUPT_VECTOR
  #pragma ghs section

/* OS IOC - INIT_UNSPECIFIED */
#elif defined (IOC_START_SEC_VAR_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE0_UNSPECIFIED
  #pragma ghs section data=".data.IOC_RAM_VAR_INIT_CORE0_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE0_UNSPECIFIED
  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE1_UNSPECIFIED
  #pragma ghs section data=".data.IOC_RAM_VAR_INIT_CORE1_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE1_UNSPECIFIED
  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE2_UNSPECIFIED
  #pragma ghs section data=".data.IOC_RAM_VAR_INIT_CORE2_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE2_UNSPECIFIED
  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.IOC_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

/* OS IOC - NO_INIT_UNSPECIFIED */
#elif defined (IOC_START_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED
  #pragma ghs section bss=".bss.IOC_RAM_VAR_NO_INIT_CORE0_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED
  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED
  #pragma ghs section bss=".bss.IOC_RAM_VAR_NO_INIT_CORE1_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED
  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED
  #pragma ghs section bss=".bss.IOC_RAM_VAR_NO_INIT_CORE2_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED
  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.IOC_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 LinSM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (LINSM_START_SEC_CONST_UNSPECIFIED)
  #undef       LINSM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (LINSM_START_SEC_CONST_8)
  #undef       LINSM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINSM_STOP_SEC_CONST_8)
  #undef       LINSM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (LINSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       LINSM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       LINSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (LINSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINSM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINSM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (LINSM_START_SEC_VAR_CLEARED_8)
  #undef       LINSM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINSM_STOP_SEC_VAR_CLEARED_8)
  #undef       LINSM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (LINSM_START_SEC_CODE)
  #undef       LINSM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINSM_STOP_SEC_CODE)
  #undef       LINSM_STOP_SEC_CODE
  #pragma ghs section



/* -------------------------------------------------------------------------- */
/*                 LinTrcv                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (LINTRCV_START_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINTRCV_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (LINTRCV_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINTRCV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (LINTRCV_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (LINTRCV_START_SEC_CODE)
  #undef       LINTRCV_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINTRCV_STOP_SEC_CODE)
  #undef       LINTRCV_STOP_SEC_CODE
  #pragma ghs section

#elif defined (LINTRCV_7259GE_START_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_7259GE_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINTRCV_7259GE_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_7259GE_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (LINTRCV_7259GE_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_7259GE_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINTRCV_7259GE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_7259GE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (LINTRCV_7259GE_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_7259GE_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINTRCV_7259GE_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_7259GE_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (LINTRCV_7259GE_START_SEC_CODE)
  #undef       LINTRCV_7259GE_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINTRCV_7259GE_STOP_SEC_CODE)
  #undef       LINTRCV_7259GE_STOP_SEC_CODE
  #pragma ghs section


/* -------------------------------------------------------------------------- */
/*                             LinNm                                          */
/* -------------------------------------------------------------------------- */
#elif defined (LINNM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINNM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINNM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (LINNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINNM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (LINNM_START_SEC_CONST_UNSPECIFIED)
  #undef       LINNM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINNM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINNM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (LINNM_START_SEC_CODE)
  #undef       LINNM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINNM_STOP_SEC_CODE)
  #undef       LINNM_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             FiM                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (FIM_START_SEC_CODE)
  #undef       FIM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (FIM_STOP_SEC_CODE)
  #undef       FIM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (FIM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FIM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FIM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FIM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (FIM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FIM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FIM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FIM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (FIM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FIM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (FIM_START_SEC_CONST_UNSPECIFIED)
  #undef       FIM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (FIM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FIM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section


/* -------------------------------------------------------------------------- */
/*                 FRSM                                                       */
/* -------------------------------------------------------------------------- */
#elif defined (FRSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRSM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FRSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRSM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

  #elif defined (FRSM_START_SEC_VAR_CLEARED_8)
  #undef       FRSM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FRSM_STOP_SEC_VAR_CLEARED_8)
  #undef       FRSM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (FRSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FRSM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FRSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FRSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (FRSM_START_SEC_VAR_NO_INIT_8)
  #undef       FRSM_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FRSM_STOP_SEC_VAR_NO_INIT_8)
  #undef       FRSM_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (FRSM_START_SEC_CONST_UNSPECIFIED)
  #undef       FRSM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (FRSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FRSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (FRSM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRSM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FRSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (FRSM_START_SEC_CODE)
  #undef       FRSM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (FRSM_STOP_SEC_CODE)
  #undef       FRSM_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             FrIf                                                           */
/* -------------------------------------------------------------------------- */
#elif defined (FRIF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRIF_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FRIF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRIF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (FRIF_START_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (FRIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (FRIF_START_SEC_VAR_NO_INIT_8)
  #undef       FRIF_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FRIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       FRIF_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (FRIF_START_SEC_VAR_NO_INIT_8)
  #undef       FRIF_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FRIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       FRIF_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (FRIF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRIF_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FRIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (FRIF_START_SEC_VAR_CLEARED_16)
  #undef       FRIF_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FRIF_STOP_SEC_VAR_CLEARED_16)
  #undef       FRIF_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (FRIF_START_SEC_CONST_8)
  #undef       FRIF_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (FRIF_STOP_SEC_CONST_8)
  #undef       FRIF_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (FRIF_START_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (FRIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (FRIF_START_SEC_CODE)
  #undef       FRIF_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (FRIF_STOP_SEC_CODE)
  #undef       FRIF_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 CANIF                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (CANIF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANIF_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (CANIF_START_SEC_VAR_CLEARED_8)
  #undef       CANIF_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANIF_STOP_SEC_VAR_CLEARED_8)
  #undef       CANIF_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (CANIF_START_SEC_VAR_NO_INIT_8)
  #undef       CANIF_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (CANIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       CANIF_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (CANIF_START_SEC_CONST_8)
  #undef       CANIF_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANIF_STOP_SEC_CONST_8)
  #undef       CANIF_STOP_SEC_CONST_8
  #pragma ghs section

 #elif defined (CANIF_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANIF_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (CANIF_START_SEC_CONST_UNSPECIFIED)
  #undef       CANIF_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

 #elif defined (CANIF_START_SEC_CODE)
  #undef        CANIF_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANIF_STOP_SEC_CODE)
  #undef       CANIF_STOP_SEC_CODE
  #pragma ghs section

  /* -------------------------------------------------------------------------- */
  /*                 CANTRCV                                                    */
  /* -------------------------------------------------------------------------- */
#elif defined (CANTRCV_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_CLEARED_8)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_8)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_CLEARED_16)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_16)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_CLEARED_32)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_32)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_VAR_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTRCV_STOP_SEC_VAR_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_VAR_UNSPECIFIED
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_CONST_8)
  #undef       CANTRCV_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTRCV_STOP_SEC_CONST_8)
  #undef       CANTRCV_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_CONST_16)
  #undef       CANTRCV_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTRCV_STOP_SEC_CONST_16)
  #undef       CANTRCV_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_CONST_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTRCV_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

 #elif defined (CANTRCV_START_SEC_CODE)
  #undef        CANTRCV_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTRCV_STOP_SEC_CODE)
  #undef       CANTRCV_STOP_SEC_CODE
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTRCV_START_SEC_VAR_INIT_BOOLEAN

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_INIT_8)
  #undef       CANTRCV_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_8)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_INIT_16)
  #undef       CANTRCV_START_SEC_VAR_INIT_16

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_16)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_16
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 BswM                                                       */
/* -------------------------------------------------------------------------- */
#elif defined (BSWM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       BSWM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (BSWM_START_SEC_CONST_UNSPECIFIED)
  #undef       BSWM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (BSWM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       BSWM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (BSWM_START_SEC_CODE)
  #undef       BSWM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (BSWM_STOP_SEC_CODE)
  #undef       BSWM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             ComM                                                           */
/* -------------------------------------------------------------------------- */
#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_16
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_CLEARED_8)
  #undef       COMM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_8)
  #undef       COMM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_CLEARED_16)
  #undef       COMM_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_16)
  #undef       COMM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_CLEARED_32)
  #undef       COMM_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_32)
  #undef       COMM_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COMM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_NO_INIT_8)
  #undef       COMM_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_8)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_NO_INIT_16)
  #undef       COMM_START_SEC_VAR_NO_INIT_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_16)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_NO_INIT_32)
  #undef       COMM_START_SEC_VAR_NO_INIT_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_32)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_32
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_SAVED_ZONE_16)
  #undef       COMM_START_SEC_VAR_SAVED_ZONE_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_SAVED_ZONE"
#elif defined (COMM_STOP_SEC_VAR_SAVED_ZONE_16)
  #undef       COMM_STOP_SEC_VAR_SAVED_ZONE_16
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_SAVED_ZONE_8)
  #undef       COMM_START_SEC_VAR_SAVED_ZONE_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_SAVED_ZONE"
#elif defined (COMM_STOP_SEC_VAR_SAVED_ZONE_8)
  #undef       COMM_STOP_SEC_VAR_SAVED_ZONE_8
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_SAVED_ZONE"
#elif defined (COMM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma ghs section

#elif defined (COMM_START_SEC_CONST_8)
  #undef       COMM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COMM_STOP_SEC_CONST_8)
  #undef       COMM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (COMM_START_SEC_CONST_UNSPECIFIED)
  #undef       COMM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COMM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       COMM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (COMM_START_SEC_CODE)
  #undef       COMM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COMM_STOP_SEC_CODE)
  #undef       COMM_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             LINIF                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (LINIF_START_SEC_CODE)
  #undef       LINIF_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINIF_STOP_SEC_CODE)
  #undef       LINIF_STOP_SEC_CODE
  #pragma ghs section

#elif defined (LINIF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINIF_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINIF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINIF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (LINIF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINIF_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (LINIF_START_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (LINIF_START_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINIF_START_SEC_DBTOC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (LINIF_STOP_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_DBTOC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (LINIF_START_SEC_CONST_8)
  #undef       LINIF_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINIF_STOP_SEC_CONST_8)
  #undef       LINIF_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (LINIF_START_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (LINIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (LINIF_START_SEC_VAR_NO_INIT_8)
  #undef       LINIF_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       LINIF_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             LINTP                                                          */
/* -------------------------------------------------------------------------- */

#elif defined (LINTP_START_SEC_CODE)
  #undef       LINTP_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINTP_STOP_SEC_CODE)
  #undef       LINTP_STOP_SEC_CODE
  #pragma ghs section

#elif defined (LINTP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTP_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINTP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (LINTP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTP_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (LINTP_START_SEC_VAR_CLEARED_16)
  #undef       LINTP_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINTP_STOP_SEC_VAR_CLEARED_16)
  #undef       LINTP_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (LINTP_START_SEC_VAR_NO_INIT_8)
  #undef       LINTP_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINTP_STOP_SEC_VAR_NO_INIT_8)
  #undef       LINTP_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (LINTP_START_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINTP_START_SEC_DBTOC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (LINTP_STOP_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINTP_STOP_SEC_DBTOC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (LINTP_START_SEC_CONST_UNSPECIFIED)
  #undef       LINTP_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (LINTP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINTP_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             Com                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_16
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_CLEARED_8)
  #undef       COM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COM_STOP_SEC_VAR_CLEARED_8)
  #undef       COM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_CLEARED_16)
  #undef       COM_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COM_STOP_SEC_VAR_CLEARED_16)
  #undef       COM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (COM_START_SEC_ETH_VAR_CLEARED_16)
  #undef       COM_START_SEC_ETH_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_ETH_VAR_CLEARED"
#elif defined (COM_STOP_SEC_ETH_VAR_CLEARED_16)
  #undef       COM_STOP_SEC_ETH_VAR_CLEARED_16
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (COM_START_SEC_ETH_VAR_CLEARED_UNSPECIFIED)
  #undef       COM_START_SEC_ETH_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_ETH_VAR_CLEARED"
#elif defined (COM_STOP_SEC_ETH_VAR_CLEARED_UNSPECIFIED)
  #undef       COM_STOP_SEC_ETH_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4)
  #undef       COM_START_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4)
  #undef       COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NOINIT_8)
  #undef       COM_START_SEC_VAR_NOINIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NOINIT_8)
  #undef       COM_STOP_SEC_VAR_NOINIT_8
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NOINIT_16)
  #undef       COM_START_SEC_VAR_NOINIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NOINIT_16)
  #undef       COM_STOP_SEC_VAR_NOINIT_16
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NOINIT_32)
  #undef       COM_START_SEC_VAR_NOINIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NOINIT_32)
  #undef       COM_STOP_SEC_VAR_NOINIT_32
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_SAVED_ZONE_16)
  #undef       COM_START_SEC_VAR_SAVED_ZONE_16
  #pragma ghs section bss=".bss.DEFAULT_SAVED_RAM"
#elif defined (COM_STOP_SEC_VAR_SAVED_ZONE_16)
  #undef       COM_STOP_SEC_VAR_SAVED_ZONE_16
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_SAVED_ZONE_8)
  #undef       COM_START_SEC_VAR_SAVED_ZONE_8
  #pragma ghs section bss=".bss.DEFAULT_SAVED_RAM"
#elif defined (COM_STOP_SEC_VAR_SAVED_ZONE_8)
  #undef       COM_STOP_SEC_VAR_SAVED_ZONE_8
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_SAVED_RAM"
#elif defined (COM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma ghs section

#elif defined (COM_START_SEC_CONST_8)
  #undef       COM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COM_STOP_SEC_CONST_8)
  #undef       COM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (COM_START_SEC_CONST_16)
  #undef       COM_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COM_STOP_SEC_CONST_16)
  #undef       COM_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (COM_START_SEC_CONST_32)
  #undef       COM_START_SEC_CONST_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COM_STOP_SEC_CONST_32)
  #undef       COM_STOP_SEC_CONST_32
  #pragma ghs section

#elif defined (COM_START_SEC_CONST_UNSPECIFIED)
  #undef       COM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       COM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (COM_START_SEC_CODE)
  #undef       COM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_CODE)
  #undef       COM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (COM_START_SEC_APPL_CODE)
  #undef       COM_START_SEC_APPL_CODE

  #pragma ghs section text=".text.DEFAULT_APPL_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_APPL_CODE)
  #undef       COM_STOP_SEC_APPL_CODE
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_NOINIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NO_INIT_8)
  #undef       COM_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NO_INIT_8)
  #undef       COM_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_INIT_16)
  #undef       COM_START_SEC_VAR_INIT_16

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_VAR_INIT_16)
  #undef       COM_STOP_SEC_VAR_INIT_16
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NO_INIT_16)
  #undef       COM_START_SEC_VAR_NO_INIT_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NO_INIT_16)
  #undef       COM_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_INIT_32)
  #undef       COM_START_SEC_VAR_INIT_32

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_VAR_INIT_32)
  #undef       COM_STOP_SEC_VAR_INIT_32
  #pragma ghs section

#elif defined (COM_START_SEC_VAR_INIT_8)
  #undef       COM_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_VAR_INIT_8)
  #undef       COM_STOP_SEC_VAR_INIT_8
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                  PduR                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (PDUR_START_SEC_CODE)
  #undef       PDUR_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (PDUR_STOP_SEC_CODE)
  #undef       PDUR_STOP_SEC_CODE
  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       PDUR_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN

#elif defined (PDUR_START_SEC_VAR_INIT_32)
  #undef       PDUR_START_SEC_VAR_INIT_32

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (PDUR_STOP_SEC_VAR_INIT_32)
  #undef       PDUR_STOP_SEC_VAR_INIT_32
  #pragma ghs section

#elif defined (PDUR_START_SEC_CONST_UNSPECIFIED)
  #undef       PDUR_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (PDUR_STOP_SEC_CONST_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       PDUR_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_CLEARED_8)
  #undef       PDUR_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (PDUR_STOP_SEC_VAR_CLEARED_8)
  #undef       PDUR_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_NO_INIT_8)
  #undef       PDUR_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (PDUR_STOP_SEC_VAR_NO_INIT_8)
  #undef       PDUR_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_NO_INIT_16)
  #undef       PDUR_START_SEC_VAR_NO_INIT_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (PDUR_STOP_SEC_VAR_NO_INIT_16)
  #undef       PDUR_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             IpduM                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (IPDUM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_8)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_8)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_16)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_16)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_32)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_32)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_32
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       IPDUM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_CLEARED_8)
  #undef       IPDUM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_8)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_CLEARED_16)
  #undef       IPDUM_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_16)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_CLEARED_32)
  #undef       IPDUM_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_32)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IPDUM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       IPDUM_START_SEC_VAR_INIT_BOOLEAN

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       IPDUM_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_INIT_8)
  #undef       IPDUM_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_8)
  #undef       IPDUM_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_INIT_16)
  #undef       IPDUM_START_SEC_VAR_INIT_16

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_16)
  #undef       IPDUM_STOP_SEC_VAR_INIT_16
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_INIT_32)
  #undef       IPDUM_START_SEC_VAR_INIT_32

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_32)
  #undef       IPDUM_STOP_SEC_VAR_INIT_32
  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IPDUM_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (IPDUM_START_SEC_CONST_BOOLEAN)
  #undef       IPDUM_START_SEC_CONST_BOOLEAN

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IPDUM_STOP_SEC_CONST_BOOLEAN)
  #undef       IPDUM_STOP_SEC_CONST_BOOLEAN
  #pragma ghs section

#elif defined (IPDUM_START_SEC_CONST_8)
  #undef       IPDUM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IPDUM_STOP_SEC_CONST_8)
  #undef       IPDUM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (IPDUM_START_SEC_CONST_16)
  #undef       IPDUM_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IPDUM_STOP_SEC_CONST_16)
  #undef       IPDUM_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (IPDUM_START_SEC_CONST_UNSPECIFIED)
  #undef       IPDUM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IPDUM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (IPDUM_START_SEC_CODE)
  #undef       IPDUM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_CODE)
  #undef       IPDUM_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                  CanSM                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (CANSM_START_SEC_CODE)
  #undef       CANSM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANSM_STOP_SEC_CODE)
  #undef       CANSM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (CANSM_START_SEC_CONST_UNSPECIFIED)
  #undef       CANSM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (CANSM_START_SEC_CONST_8)
  #undef       CANSM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANSM_STOP_SEC_CONST_8)
  #undef       CANSM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (CANSM_START_SEC_CONST_16)
  #undef       CANSM_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANSM_STOP_SEC_CONST_16)
  #undef       CANSM_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANSM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_CLEARED_16)
  #undef       CANSM_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_16)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_CLEARED_8)
  #undef       CANSM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_8)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CANSM_START_SEC_VAR_INIT_BOOLEAN

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANSM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CANSM_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_INIT_8)
  #undef       CANSM_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANSM_STOP_SEC_VAR_INIT_8)
  #undef       CANSM_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_INIT_16)
  #undef       CANSM_START_SEC_VAR_INIT_16

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANSM_STOP_SEC_VAR_INIT_16)
  #undef       CANSM_STOP_SEC_VAR_INIT_16
  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANSM_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANSM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                  CanNM                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (CANNM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANNM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (CANNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANNM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_CLEARED_8)
  #undef       CANNM_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (CANNM_STOP_SEC_VAR_CLEARED_8)
  #undef       CANNM_STOP_SEC_VAR_CLEARED_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_CLEARED_16)
  #undef       CANNM_START_SEC_VAR_CLEARED_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (2)

#elif defined (CANNM_STOP_SEC_VAR_CLEARED_16)
  #undef       CANNM_STOP_SEC_VAR_CLEARED_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_CLEARED_32)
  #undef       CANNM_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (CANNM_STOP_SEC_VAR_CLEARED_32)
  #undef       CANNM_STOP_SEC_VAR_CLEARED_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_CONST_BOOLEAN)
  #undef       CANNM_START_SEC_CONST_BOOLEAN
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (CANNM_STOP_SEC_CONST_BOOLEAN)
  #undef       CANNM_STOP_SEC_CONST_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_CONST_8)
  #undef       CANNM_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (CANNM_STOP_SEC_CONST_8)
  #undef       CANNM_STOP_SEC_CONST_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_CONST_16)
  #undef       CANNM_START_SEC_CONST_16
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (2)

#elif defined (CANNM_STOP_SEC_CONST_16)
  #undef       CANNM_STOP_SEC_CONST_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_CONST_32)
  #undef       CANNM_START_SEC_CONST_32
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (CANNM_STOP_SEC_CONST_32)
  #undef       CANNM_STOP_SEC_CONST_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_CONST_UNSPECIFIED)
  #undef       CANNM_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (CANNM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_CONST_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       CANNM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (CANNM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       CANNM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_NO_INIT_8)
  #undef       CANNM_START_SEC_VAR_NO_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (CANNM_STOP_SEC_VAR_NO_INIT_8)
  #undef       CANNM_STOP_SEC_VAR_NO_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_NO_INIT_16)
  #undef       CANNM_START_SEC_VAR_NO_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (2)

#elif defined (CANNM_STOP_SEC_VAR_NO_INIT_16)
  #undef       CANNM_STOP_SEC_VAR_NO_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_NO_INIT_32)
  #undef       CANNM_START_SEC_VAR_NO_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (CANNM_STOP_SEC_VAR_NO_INIT_32)
  #undef       CANNM_STOP_SEC_VAR_NO_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANNM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (CANNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CANNM_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (CANNM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CANNM_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_INIT_8)
  #undef       CANNM_START_SEC_VAR_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (CANNM_STOP_SEC_VAR_INIT_8)
  #undef       CANNM_STOP_SEC_VAR_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_INIT_16)
  #undef       CANNM_START_SEC_VAR_INIT_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (2)

#elif defined (CANNM_STOP_SEC_VAR_INIT_16)
  #undef       CANNM_STOP_SEC_VAR_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_INIT_32)
  #undef       CANNM_START_SEC_VAR_INIT_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (CANNM_STOP_SEC_VAR_INIT_32)
  #undef       CANNM_STOP_SEC_VAR_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANNM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (CANNM_START_SEC_CODE)
  #undef       CANNM_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"

#elif defined (CANNM_STOP_SEC_CODE)
  #undef       CANNM_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                  CanCM                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (CANCM_START_SEC_CONST_8)
  #undef      CANCM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANCM_STOP_SEC_CONST_8)
  #undef      CANCM_STOP_SEC_CONST_8
  #pragma ghs section
#elif defined (CANCM_START_SEC_CONST_UNSPECIFIED)
  #undef      CANCM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANCM_STOP_SEC_CONST_UNSPECIFIED)
  #undef      CANCM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section
#elif defined (CANCM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      CANCM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      CANCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section
#elif defined (CANCM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      CANCM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (CANCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      CANCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section
#elif defined (CANCM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef      CANCM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANCM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef      CANCM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section
#elif defined (CANCM_START_SEC_CODE)
  #undef      CANCM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANCM_STOP_SEC_CODE)
  #undef      CANCM_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                  OSEKNm                                                    */
/* -------------------------------------------------------------------------- */
#elif defined (OSEKNM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSEKNM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_CLEARED_8)
  #undef       OSEKNM_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_8)
  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_CLEARED_16)
  #undef       OSEKNM_START_SEC_VAR_CLEARED_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (2)

#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_16)
  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_CLEARED_32)
  #undef       OSEKNM_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_32)
  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_CONST_BOOLEAN)
  #undef       OSEKNM_START_SEC_CONST_BOOLEAN
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (OSEKNM_STOP_SEC_CONST_BOOLEAN)
  #undef       OSEKNM_STOP_SEC_CONST_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_CONST_8)
  #undef       OSEKNM_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (OSEKNM_STOP_SEC_CONST_8)
  #undef       OSEKNM_STOP_SEC_CONST_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_CONST_16)
  #undef       OSEKNM_START_SEC_CONST_16
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (2)

#elif defined (OSEKNM_STOP_SEC_CONST_16)
  #undef       OSEKNM_STOP_SEC_CONST_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_CONST_32)
  #undef       OSEKNM_START_SEC_CONST_32
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (OSEKNM_STOP_SEC_CONST_32)
  #undef       OSEKNM_STOP_SEC_CONST_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_CONST_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (OSEKNM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_CONST_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OSEKNM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (OSEKNM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OSEKNM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_NO_INIT_8)
  #undef       OSEKNM_START_SEC_VAR_NO_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (OSEKNM_STOP_SEC_VAR_NO_INIT_8)
  #undef       OSEKNM_STOP_SEC_VAR_NO_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_NO_INIT_16)
  #undef       OSEKNM_START_SEC_VAR_NO_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (2)

#elif defined (OSEKNM_STOP_SEC_VAR_NO_INIT_16)
  #undef       OSEKNM_STOP_SEC_VAR_NO_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_NO_INIT_32)
  #undef       OSEKNM_START_SEC_VAR_NO_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (OSEKNM_STOP_SEC_VAR_NO_INIT_32)
  #undef       OSEKNM_STOP_SEC_VAR_NO_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (OSEKNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       OSEKNM_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (OSEKNM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       OSEKNM_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_INIT_8)
  #undef       OSEKNM_START_SEC_VAR_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (OSEKNM_STOP_SEC_VAR_INIT_8)
  #undef       OSEKNM_STOP_SEC_VAR_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_INIT_16)
  #undef       OSEKNM_START_SEC_VAR_INIT_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (2)

#elif defined (OSEKNM_STOP_SEC_VAR_INIT_16)
  #undef       OSEKNM_STOP_SEC_VAR_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_INIT_32)
  #undef       OSEKNM_START_SEC_VAR_INIT_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (OSEKNM_STOP_SEC_VAR_INIT_32)
  #undef       OSEKNM_STOP_SEC_VAR_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (OSEKNM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_CODE)
  #undef       OSEKNM_START_SEC_CODE
  #pragma ghs section text=".text.OSEKNM_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"

#elif defined (OSEKNM_STOP_SEC_CODE)
  #undef       OSEKNM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (OSEKNM_START_SEC_CALLOUT_CODE)
  #undef OSEKNM_START_SEC_CALLOUT_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSEKNM_STOP_SEC_CALLOUT_CODE)
  #undef OSEKNM_STOP_SEC_CALLOUT_CODE
  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                  ECUM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (ECUM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       ECUM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (ECUM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (ECUM_START_SEC_CODE)
  #undef       ECUM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ECUM_STOP_SEC_CODE)
  #undef       ECUM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (ECUM_START_SEC_CONFIG_CONST_32)
  #undef       ECUM_START_SEC_CONFIG_CONST_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG_CONST"
#elif defined (ECUM_STOP_SEC_CONFIG_CONST_32)
  #undef       ECUM_STOP_SEC_CONFIG_CONST_32
  #pragma ghs section

#elif defined (ECUM_START_SEC_CONST_32)
  #undef       ECUM_START_SEC_CONST_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ECUM_STOP_SEC_CONST_32)
  #undef       ECUM_STOP_SEC_CONST_32
  #pragma ghs section

#elif defined (ECUM_START_SEC_CONST_8)
  #undef       ECUM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ECUM_STOP_SEC_CONST_8)
  #undef       ECUM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (ECUM_START_SEC_CONST_UNSPECIFIED)
  #undef       ECUM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ECUM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (ECUM_START_SEC_CALLOUT_CODE)
  #undef       ECUM_START_SEC_CALLOUT_CODE

  #pragma ghs section text=".text.DEFAULT_CALLOUT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ECUM_STOP_SEC_CALLOUT_CODE)
  #undef       ECUM_STOP_SEC_CALLOUT_CODE
  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ECUM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       ECUM_START_SEC_VAR_POWER_ON_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_16
  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_CLEARED_32)
  #undef       ECUM_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_32)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_CLEARED_16)
  #undef       ECUM_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_16)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_16
 #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_CLEARED_8)
  #undef       ECUM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_8)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_NO_INIT_8)
  #undef       ECUM_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (ECUM_STOP_SEC_VAR_NO_INIT_8)
  #undef       ECUM_STOP_SEC_VAR_NO_INIT_8
 #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       ECUM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_SAVED_ZONE"
#elif defined (ECUM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       ECUM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 NM                                                         */
/* -------------------------------------------------------------------------- */

#elif defined (NM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (NM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_CLEARED_8)
  #undef       NM_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (NM_STOP_SEC_VAR_CLEARED_8)
  #undef       NM_STOP_SEC_VAR_CLEARED_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_CLEARED_16)
  #undef       NM_START_SEC_VAR_CLEARED_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (2)

#elif defined (NM_STOP_SEC_VAR_CLEARED_16)
  #undef       NM_STOP_SEC_VAR_CLEARED_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_CLEARED_32)
  #undef       NM_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (NM_STOP_SEC_VAR_CLEARED_32)
  #undef       NM_STOP_SEC_VAR_CLEARED_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (NM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_8)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_8)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_16)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (2)

#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_16)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_32)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_32)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       NM_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (NM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       NM_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_INIT_8)
  #undef       NM_START_SEC_VAR_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (NM_STOP_SEC_VAR_INIT_8)
  #undef       NM_STOP_SEC_VAR_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_INIT_16)
  #undef       NM_START_SEC_VAR_INIT_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (2)

#elif defined (NM_STOP_SEC_VAR_INIT_16)
  #undef       NM_STOP_SEC_VAR_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_INIT_32)
  #undef       NM_START_SEC_VAR_INIT_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (NM_STOP_SEC_VAR_INIT_32)
  #undef       NM_STOP_SEC_VAR_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       NM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (NM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       NM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       NM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (NM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       NM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_NO_INIT_8)
  #undef       NM_START_SEC_VAR_NO_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (NM_STOP_SEC_VAR_NO_INIT_8)
  #undef       NM_STOP_SEC_VAR_NO_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_NO_INIT_16)
  #undef       NM_START_SEC_VAR_NO_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (2)

#elif defined (NM_STOP_SEC_VAR_NO_INIT_16)
  #undef       NM_STOP_SEC_VAR_NO_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_NO_INIT_32)
  #undef       NM_START_SEC_VAR_NO_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (NM_STOP_SEC_VAR_NO_INIT_32)
  #undef       NM_STOP_SEC_VAR_NO_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_CONST_BOOLEAN)
  #undef       NM_START_SEC_CONST_BOOLEAN
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (NM_STOP_SEC_CONST_BOOLEAN)
  #undef       NM_STOP_SEC_CONST_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_CONST_8)
  #undef       NM_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (NM_STOP_SEC_CONST_8)
  #undef       NM_STOP_SEC_CONST_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_CONST_16)
  #undef       NM_START_SEC_CONST_16
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (2)

#elif defined (NM_STOP_SEC_CONST_16)
  #undef       NM_STOP_SEC_CONST_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_CONST_32)
  #undef       NM_START_SEC_CONST_32
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (NM_STOP_SEC_CONST_32)
  #undef       NM_STOP_SEC_CONST_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_CONST_UNSPECIFIED)
  #undef       NM_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (NM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       NM_STOP_SEC_CONST_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NM_START_SEC_CODE)
  #undef       NM_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"

#elif defined (NM_STOP_SEC_CODE)
  #undef       NM_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 MemIf                                      */
/* -------------------------------------------------------------------------- */

#elif defined (MEMIF_START_SEC_CODE)
  #undef       MEMIF_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (MEMIF_STOP_SEC_CODE)
  #undef       MEMIF_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 Crc                                        */
/* -------------------------------------------------------------------------- */

#elif defined (CRC_START_SEC_CODE)
  #undef       CRC_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CRC_STOP_SEC_CODE)
  #undef       CRC_STOP_SEC_CODE
  #pragma ghs section

#elif defined (CRC_START_SEC_CONST_8)
  #undef       CRC_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CRC_STOP_SEC_CONST_8)
  #undef       CRC_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (CRC_START_SEC_CONST_16)
  #undef       CRC_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CRC_STOP_SEC_CONST_16)
  #undef       CRC_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (CRC_START_SEC_CONST_32)
  #undef       CRC_START_SEC_CONST_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CRC_STOP_SEC_CONST_32)
  #undef       CRC_STOP_SEC_CONST_32
  #pragma ghs section

/* For R44 */
#elif defined (CRC_START_SEC_CODE_ASIL_D)
  #undef       CRC_START_SEC_CODE_ASIL_D

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CRC_STOP_SEC_CODE_ASIL_D)
  #undef       CRC_STOP_SEC_CODE_ASIL_D
  #pragma ghs section

#elif defined (CRC_START_SEC_CONST_ASIL_D_8)
  #undef       CRC_START_SEC_CONST_ASIL_D_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CRC_STOP_SEC_CONST_ASIL_D_8)
  #undef       CRC_STOP_SEC_CONST_ASIL_D_8
  #pragma ghs section

#elif defined (CRC_START_SEC_CONST_ASIL_D_16)
  #undef       CRC_START_SEC_CONST_ASIL_D_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CRC_STOP_SEC_CONST_ASIL_D_16)
  #undef       CRC_STOP_SEC_CONST_ASIL_D_16
  #pragma ghs section

#elif defined (CRC_START_SEC_CONST_ASIL_D_32)
  #undef       CRC_START_SEC_CONST_ASIL_D_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CRC_STOP_SEC_CONST_ASIL_D_32)
  #undef       CRC_STOP_SEC_CONST_ASIL_D_32
  #pragma ghs section

#elif defined (CRC_START_SEC_CONST_ASIL_D_UNSPECIFIED)
  #undef       CRC_START_SEC_CONST_ASIL_D_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (CRC_STOP_SEC_CONST_ASIL_D_UNSPECIFIED)
  #undef       CRC_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                 FOTA                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (FOTA_START_SEC_CODE)
  #undef       FOTA_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (FOTA_STOP_SEC_CODE)
  #undef       FOTA_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 MEM_76_PFLS                                                */
/* -------------------------------------------------------------------------- */
#elif defined (MEM_76_PFLS_START_FUNCTION_POINTER_TABLE)
  #undef       MEM_76_PFLS_START_FUNCTION_POINTER_TABLE
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (MEM_76_PFLS_STOP_FUNCTION_POINTER_TABLE)
  #undef       MEM_76_PFLS_STOP_FUNCTION_POINTER_TABLE
  #pragma alignvar (4)

#elif defined (MEM_76_PFLS_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       MEM_76_PFLS_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_CLEARED_8)
  #undef       MEM_76_PFLS_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_CLEARED_8)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_CLEARED_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_CLEARED_16)
  #undef       MEM_76_PFLS_START_SEC_VAR_CLEARED_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (2)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_CLEARED_16)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_CLEARED_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_CLEARED_32)
  #undef       MEM_76_PFLS_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_CLEARED_32)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_CLEARED_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       MEM_76_PFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_CONST_BOOLEAN)
  #undef       MEM_76_PFLS_START_SEC_CONST_BOOLEAN
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)



#elif defined (MEM_76_PFLS_STOP_SEC_CONST_BOOLEAN)
  #undef       MEM_76_PFLS_STOP_SEC_CONST_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_CONST_8)
  #undef       MEM_76_PFLS_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (MEM_76_PFLS_STOP_SEC_CONST_8)
  #undef       MEM_76_PFLS_STOP_SEC_CONST_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_CONST_16)
  #undef       MEM_76_PFLS_START_SEC_CONST_16
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (2)

#elif defined (MEM_76_PFLS_STOP_SEC_CONST_16)
  #undef       MEM_76_PFLS_STOP_SEC_CONST_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_CONST_32)
  #undef       MEM_76_PFLS_START_SEC_CONST_32
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (MEM_76_PFLS_STOP_SEC_CONST_32)
  #undef       MEM_76_PFLS_STOP_SEC_CONST_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       MEM_76_PFLS_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_NO_INIT_8)
  #undef       MEM_76_PFLS_START_SEC_VAR_NO_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_NO_INIT_8)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_NO_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_NO_INIT_16)
  #undef       MEM_76_PFLS_START_SEC_VAR_NO_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (2)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_NO_INIT_16)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_NO_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_NO_INIT_32)
  #undef       MEM_76_PFLS_START_SEC_VAR_NO_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_NO_INIT_32)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_NO_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       MEM_76_PFLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_INIT_BOOLEAN)
  #undef       MEM_76_PFLS_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_INIT_8)
  #undef       MEM_76_PFLS_START_SEC_VAR_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_INIT_8)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_INIT_16)
  #undef       MEM_76_PFLS_START_SEC_VAR_INIT_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (2)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_INIT_16)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_INIT_32)
  #undef       MEM_76_PFLS_START_SEC_VAR_INIT_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_INIT_32)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       MEM_76_PFLS_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (MEM_76_PFLS_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_CODE)
  #undef       MEM_76_PFLS_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"

#elif defined (MEM_76_PFLS_STOP_SEC_CODE)
  #undef       MEM_76_PFLS_STOP_SEC_CODE
  #pragma ghs section

#elif defined (MEM_76_PFLS_START_SEC_CALLOUT_CODE)
  #undef       MEM_76_PFLS_START_SEC_CALLOUT_CODE
  #pragma ghs section text=".text.DEFAULT_CALLOUT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (MEM_76_PFLS_STOP_SEC_CALLOUT_CODE)
  #undef       MEM_76_PFLS_STOP_SEC_CALLOUT_CODE
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       MEM_76_PFLS_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma ghs section bss=".bss.MEM_76_PFLS_RAM_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED"
#elif defined (MEM_76_PFLS_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       MEM_76_PFLS_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_CONST_UNSPECIFIED)
  #undef MEM_76_PFLS_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (MEM_76_PFLS_STOP_SEC_CONST_UNSPECIFIED)
  #undef MEM_76_PFLS_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_RAM_CODE)
  #undef       MEM_76_PFLS_START_SEC_RAM_CODE
  #pragma ghs section text=".BTL_CFLS_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (MEM_76_PFLS_STOP_SEC_RAM_CODE)
  #undef       MEM_76_PFLS_STOP_SEC_RAM_CODE
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_R_FCL)
  #undef       MEM_76_PFLS_START_SEC_R_FCL
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (MEM_76_PFLS_STOP_SEC_R_FCL)
  #undef       MEM_76_PFLS_STOP_SEC_R_FCL
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_R_FCL_DATA)
  #undef       MEM_76_PFLS_START_SEC_R_FCL_DATA
  #pragma ghs section bss=".R_FCL_DATA"
#elif defined (MEM_76_PFLS_STOP_SEC_R_FCL_DATA)
  #undef       MEM_76_PFLS_STOP_SEC_R_FCL_DATA
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_R_FCL_CONST)
  #undef       MEM_76_PFLS_START_SEC_R_FCL_CONST
  #pragma ghs section rodata=".R_FCL_CONST"
#elif defined (MEM_76_PFLS_STOP_SEC_R_FCL_CONST)
  #undef       MEM_76_PFLS_STOP_SEC_R_FCL_CONST
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_R_FCL_CODE_ROM)
  #undef       MEM_76_PFLS_START_SEC_R_FCL_CODE_ROM
  #pragma ghs section text=".R_FCL_CODE_ROM"
#elif defined (MEM_76_PFLS_STOP_SEC_R_FCL_CODE_ROM)
  #undef       MEM_76_PFLS_STOP_SEC_R_FCL_CODE_ROM
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_R_FCL_CODE_USRINT)
  #undef       MEM_76_PFLS_START_SEC_R_FCL_CODE_USRINT
  #pragma ghs section text=".R_FCL_CODE_USRINT"
#elif defined (MEM_76_PFLS_STOP_SEC_R_FCL_CODE_USRINT)
  #undef       MEM_76_PFLS_STOP_SEC_R_FCL_CODE_USRINT
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_R_FCL_CODE_USR)
  #undef       MEM_76_PFLS_START_SEC_R_FCL_CODE_USR
  #pragma ghs section text=".R_FCL_CODE_USR"
#elif defined (MEM_76_PFLS_STOP_SEC_R_FCL_CODE_USR)
  #undef       MEM_76_PFLS_STOP_SEC_R_FCL_CODE_USR
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_R_FCL_CODE_RAM)
  #undef       MEM_76_PFLS_START_SEC_R_FCL_CODE_RAM
  #pragma ghs section text=".R_FCL_CODE_RAM"
#elif defined (MEM_76_PFLS_STOP_SEC_R_FCL_CODE_RAM)
  #undef       MEM_76_PFLS_STOP_SEC_R_FCL_CODE_RAM
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_R_FCL_CODE_ROMRAM)
  #undef       MEM_76_PFLS_START_SEC_R_FCL_CODE_ROMRAM
  #pragma ghs section text=".R_FCL_CODE_ROMRAM"
#elif defined (MEM_76_PFLS_STOP_SEC_R_FCL_CODE_ROMRAM)
  #undef       MEM_76_PFLS_STOP_SEC_R_FCL_CODE_ROMRAM
  #pragma ghs section
#elif defined (MEM_76_PFLS_START_SEC_R_FCL_CODE_RAM_EX_PROT)
  #undef       MEM_76_PFLS_START_SEC_R_FCL_CODE_RAM_EX_PROT
  #pragma ghs section text=".R_FCL_CODE_RAM_EX_PROT"
#elif defined (MEM_76_PFLS_STOP_SEC_R_FCL_CODE_RAM_EX_PROT)
  #undef       MEM_76_PFLS_STOP_SEC_R_FCL_CODE_RAM_EX_PROT
  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                 CryIf                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (CRYIF_START_SEC_CODE)
  #undef      CRYIF_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CRYIF_STOP_SEC_CODE)
  #undef      CRYIF_STOP_SEC_CODE
  #pragma ghs section

#elif defined (CRYIF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef      CRYIF_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (CRYIF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef      CRYIF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (CRYIF_START_SEC_VAR_CLEARED_8)
  #undef      CRYIF_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_8"
#elif defined (CRYIF_STOP_SEC_VAR_CLEARED_8)
  #undef      CRYIF_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (CRYIF_START_SEC_VAR_CLEARED_32)
  #undef      CRYIF_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_32"
#elif defined (CRYIF_STOP_SEC_VAR_CLEARED_32)
  #undef      CRYIF_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (CRYIF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      CRYIF_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (CRYIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      CRYIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (CRYIF_START_SEC_CONST_UNSPECIFIED)
  #undef      CRYIF_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
#elif defined (CRYIF_STOP_SEC_CONST_UNSPECIFIED)
    #undef      CRYIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (CRYIF_START_SEC_CONST_8)
  #undef      CRYIF_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_8"
#elif defined (CRYIF_STOP_SEC_CONST_8)
    #undef      CRYIF_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (CRYIF_START_SEC_CONST_PTR)
  #undef      CRYIF_START_SEC_CONST_PTR
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CRYIF_STOP_SEC_CONST_PTR)
    #undef      CRYIF_STOP_SEC_CONST_PTR
  #pragma ghs section

#elif defined (CRYIF_START_SEC_CONST_32)
  #undef      CRYIF_START_SEC_CONST_32
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_32"
#elif defined (CRYIF_STOP_SEC_CONST_32)
  #undef      CRYIF_STOP_SEC_CONST_32
  #pragma ghs section


/* -------------------------------------------------------------------------- */
/*                 KEYM                                                       */
/* -------------------------------------------------------------------------- */
#elif defined (KEYM_START_SEC_CODE)
  #undef       KEYM_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (KEYM_STOP_SEC_CODE)
  #undef       KEYM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (KEYM_START_SEC_CONST_8)
  #undef       KEYM_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_8"
#elif defined (KEYM_STOP_SEC_CONST_8)
  #undef       KEYM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (KEYM_START_SEC_VAR_CLEARED_8)
  #undef       KEYM_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_8"
#elif defined (KEYM_STOP_SEC_VAR_CLEARED_8)
  #undef       KEYM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (KEYM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       KEYM_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_32"
#elif defined (KEYM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       KEYM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (KEYM_START_SEC_CONST_UNSPECIFIED)
  #undef       KEYM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
#elif defined (KEYM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       KEYM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section

#elif defined (KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section

#elif defined (KEYM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED)
  #undef       KEYM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_CONFIG_DATA_PREBUILD_UNSPECIFIED"
#elif defined (KEYM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED)
  #undef       KEYM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
  #pragma section
/* -------------------------------------------------------------------------- */
/*                 CSM                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (CSM_START_SEC_CODE)
  #undef       CSM_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#else
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#endif
#elif defined (CSM_STOP_SEC_CODE)
  #undef       CSM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (CSM_START_SEC_CONST_8)
  #undef       CSM_START_SEC_CONST_8
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_8"
#else
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#endif
#elif defined (CSM_STOP_SEC_CONST_8)
  #undef       CSM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (CSM_START_SEC_CONST_UNSPECIFIED)
  #undef       CSM_START_SEC_CONST_UNSPECIFIED
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
#else
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#endif
#elif defined (CSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CSM_START_SEC_VAR_CLEARED_BOOLEAN
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_BOOLEAN"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CSM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_8)
  #undef       CSM_START_SEC_VAR_CLEARED_8
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_8"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CSM_STOP_SEC_VAR_CLEARED_8)
  #undef       CSM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_16)
  #undef       CSM_START_SEC_VAR_CLEARED_16
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_16"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CSM_STOP_SEC_VAR_CLEARED_16)
  #undef       CSM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_32)
  #undef       CSM_START_SEC_VAR_CLEARED_32
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_32"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CSM_STOP_SEC_VAR_CLEARED_32)
  #undef       CSM_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#endif
#elif defined (CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_GLOBALB_BOOLEAN)
  #undef       CSM_START_SEC_VAR_CLEARED_GLOBALB_BOOLEAN
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_GLOBALB_BOOLEAN)
  #undef       CSM_STOP_SEC_VAR_CLEARED_GLOBALB_BOOLEAN
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_GLOBALB_8)
  #undef       CSM_START_SEC_VAR_CLEARED_GLOBALB_8
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_GLOBALB_8)
  #undef       CSM_STOP_SEC_VAR_CLEARED_GLOBALB_8
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_GLOBALB_16)
  #undef       CSM_START_SEC_VAR_CLEARED_GLOBALB_16
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_GLOBALB_16)
  #undef       CSM_STOP_SEC_VAR_CLEARED_GLOBALB_16
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_GLOBALB_32)
  #undef       CSM_START_SEC_VAR_CLEARED_GLOBALB_32
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_GLOBALB_32)
  #undef       CSM_STOP_SEC_VAR_CLEARED_GLOBALB_32
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED)
  #undef       CSM_START_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED)
  #undef       CSM_STOP_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED
  #pragma ghs section

#elif defined (CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED)
  #undef       CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_CONFIG_DATA_PREBUILD_UNSPECIFIED"
#elif defined (CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED)
  #undef       CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CSM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 NvM                                        */
/* -------------------------------------------------------------------------- */
#elif defined (NVM_START_SEC_CODE)
  #undef       NVM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (NVM_STOP_SEC_CODE)
  #undef       NVM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_CLEARED_8)
  #undef       NVM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_8)
  #undef       NVM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_CLEARED_16)
  #undef       NVM_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_16)
  #undef       NVM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_16
 #pragma ghs section

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_NO_INIT_8)
  #undef       NVM_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_8)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NVM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       NVM_START_SEC_VAR_NO_INIT_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NVM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NVM_STOP_SEC_VAR_CLEARED_BOOLEAN
 #pragma ghs section

#elif defined (NVM_START_SEC_CONST_8)
  #undef       NVM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (NVM_STOP_SEC_CONST_8)
  #undef       NVM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (NVM_START_SEC_CONST_16)
  #undef       NVM_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (NVM_STOP_SEC_CONST_16)
  #undef       NVM_STOP_SEC_CONST_16
  #pragma ghs section


#elif defined (NVM_START_SEC_CONST_UNSPECIFIED)
  #undef       NVM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (NVM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       NVM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_NO_INIT_16)
  #undef       NVM_START_SEC_VAR_NO_INIT_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_16)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_NO_INIT_32)
  #undef       NVM_START_SEC_VAR_NO_INIT_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_32)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_32
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_INIT_8)
  #undef       NVM_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (NVM_STOP_SEC_VAR_INIT_8)
  #undef       NVM_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       NVM_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma ghs section bss=".bss.NVM_RAM_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       NVM_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma ghs section




/* -------------------------------------------------------------------------- */
/*                                 Eep                                        */
/* -------------------------------------------------------------------------- */
#elif defined (EEP_START_SEC_CODE)
  #undef       EEP_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (EEP_STOP_SEC_CODE)
  #undef       EEP_STOP_SEC_CODE
  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       EEP_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       EEP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_CLEARED_8)
  #undef       EEP_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_8)
  #undef       EEP_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_CLEARED_16)
  #undef       EEP_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_16)
  #undef       EEP_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_CLEARED_32)
  #undef       EEP_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_32)
  #undef       EEP_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       EEP_START_SEC_VAR_POWER_ON_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       EEP_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       EEP_START_SEC_VAR_POWER_ON_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       EEP_STOP_SEC_VAR_POWER_ON_CLEARED_16
  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_POWER_ON_CLEARED_32)
  #undef       EEP_START_SEC_VAR_POWER_ON_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_POWER_ON_CLEARED_32)
  #undef       EEP_STOP_SEC_VAR_POWER_ON_CLEARED_32
  #pragma ghs section

#elif defined (EEP_START_SEC_CONST_UNSPECIFIED)
  #undef       EEP_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (EEP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       EEP_STOP_SEC_CONST_UNSPECIFIED
 #pragma ghs section

#elif defined (EEP_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       EEP_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma ghs section bss=".bss.EEP_RAM_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       EEP_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_INIT_8)
  #undef       EEP_START_SEC_VAR_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_8"
#elif defined (EEP_STOP_SEC_VAR_INIT_8)
  #undef       EEP_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       EEP_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (EEP_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       EEP_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       EEP_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       EEP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                                 Ea                                         */
/* -------------------------------------------------------------------------- */
#elif defined (EA_START_SEC_CODE)
  #undef       EA_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (EA_STOP_SEC_CODE)
  #undef       EA_STOP_SEC_CODE
  #pragma ghs section

#elif defined (EA_START_SEC_NO_INIT_VAR_BOOLEAN)
  #undef       EA_START_SEC_NO_INIT_VAR_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (EA_STOP_SEC_NO_INIT_VAR_BOOLEAN)
  #undef       EA_STOP_SEC_NO_INIT_VAR_BOOLEAN
  #pragma ghs section

#elif defined (EA_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       EA_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (EA_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       EA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (EA_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       EA_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma ghs section bss=".bss.EA_RAM_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED"
#elif defined (EA_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       EA_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma ghs section

#elif defined (EA_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       EA_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_SAVED_ZONE"
#elif defined (EA_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       EA_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma ghs section

#elif defined (EA_START_SEC_CONST_16)
  #undef       EA_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (EA_STOP_SEC_CONST_16)
  #undef       EA_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (EA_START_SEC_CONST_UNSPECIFIED)
  #undef       EA_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (EA_STOP_SEC_CONST_UNSPECIFIED)
  #undef       EA_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (EA_START_SEC_NO_INIT_VAR_16)
  #undef       EA_START_SEC_NO_INIT_VAR_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (EA_STOP_SEC_NO_INIT_VAR_16)
  #undef       EA_STOP_SEC_NO_INIT_VAR_16
  #pragma ghs section

#elif defined (EA_START_SEC_NO_INIT_VAR_8)
  #undef       EA_START_SEC_NO_INIT_VAR_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (EA_STOP_SEC_NO_INIT_VAR_8)
  #undef       EA_STOP_SEC_NO_INIT_VAR_8
  #pragma ghs section

#elif defined (EA_START_SEC_NO_INIT_VAR_UNSPECIFIED)
  #undef       EA_START_SEC_NO_INIT_VAR_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (EA_STOP_SEC_NO_INIT_VAR_UNSPECIFIED)
  #undef       EA_STOP_SEC_NO_INIT_VAR_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 RTE                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (BSWMODULEDESCRIPTION_CALIB_START_SEC_CODE)
  #undef       BSWMODULEDESCRIPTION_CALIB_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (BSWMODULEDESCRIPTION_CALIB_STOP_SEC_CODE)
  #undef       BSWMODULEDESCRIPTION_CALIB_STOP_SEC_CODE
  #pragma ghs section

#elif defined (BSWMODULEDESCRIPTION_PERINSTANCEPARAMETER_START_SEC_CODE)
  #undef       BSWMODULEDESCRIPTION_PERINSTANCEPARAMETER_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (BSWMODULEDESCRIPTION_PERINSTANCEPARAMETER_STOP_SEC_CODE)
  #undef       BSWMODULEDESCRIPTION_PERINSTANCEPARAMETER_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 CAL                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (CAL_START_SEC_CODE)
  #undef       CAL_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CAL_STOP_SEC_CODE)
  #undef       CAL_STOP_SEC_CODE
  #pragma ghs section

#elif defined (CAL_START_SEC_CONST_32)
  #undef       CAL_START_SEC_CONST_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CAL_STOP_SEC_CONST_32)
  #undef       CAL_STOP_SEC_CONST_32
  #pragma ghs section

#elif defined (CAL_START_SEC_CONST_UNSPECIFIED)
  #undef       CAL_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CAL_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CAL_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 CSM                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (CSM_START_SEC_CODE)
  #undef       CSM_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#else
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#endif
#elif defined (CSM_STOP_SEC_CODE)
  #undef       CSM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (CSM_START_SEC_CONST_8)
  #undef       CSM_START_SEC_CONST_8
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_8"
#else
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#endif
#elif defined (CSM_STOP_SEC_CONST_8)
  #undef       CSM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (CSM_START_SEC_CONST_UNSPECIFIED)
  #undef       CSM_START_SEC_CONST_UNSPECIFIED
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
#else
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#endif
#elif defined (CSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CSM_START_SEC_VAR_CLEARED_BOOLEAN
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_BOOLEAN"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CSM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_8)
  #undef       CSM_START_SEC_VAR_CLEARED_8
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_8"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CSM_STOP_SEC_VAR_CLEARED_8)
  #undef       CSM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_16)
  #undef       CSM_START_SEC_VAR_CLEARED_16
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_16"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CSM_STOP_SEC_VAR_CLEARED_16)
  #undef       CSM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_32)
  #undef       CSM_START_SEC_VAR_CLEARED_32
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_32"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CSM_STOP_SEC_VAR_CLEARED_32)
  #undef       CSM_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#endif
#elif defined (CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_GLOBALB_BOOLEAN)
  #undef       CSM_START_SEC_VAR_CLEARED_GLOBALB_BOOLEAN
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_GLOBALB_BOOLEAN)
  #undef       CSM_STOP_SEC_VAR_CLEARED_GLOBALB_BOOLEAN
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_GLOBALB_8)
  #undef       CSM_START_SEC_VAR_CLEARED_GLOBALB_8
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_GLOBALB_8)
  #undef       CSM_STOP_SEC_VAR_CLEARED_GLOBALB_8
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_GLOBALB_16)
  #undef       CSM_START_SEC_VAR_CLEARED_GLOBALB_16
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_GLOBALB_16)
  #undef       CSM_STOP_SEC_VAR_CLEARED_GLOBALB_16
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_GLOBALB_32)
  #undef       CSM_START_SEC_VAR_CLEARED_GLOBALB_32
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_GLOBALB_32)
  #undef       CSM_STOP_SEC_VAR_CLEARED_GLOBALB_32
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED)
  #undef       CSM_START_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED)
  #undef       CSM_STOP_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED
  #pragma ghs section

#elif defined (CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED)
  #undef       CSM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_CONFIG_DATA_PREBUILD_UNSPECIFIED"
#elif defined (CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED)
  #undef       CSM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CSM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 CRYPTOLIB                                                  */
/* -------------------------------------------------------------------------- */
#elif defined (CRYPTOLIB_START_SEC_CODE)
  #undef       CRYPTOLIB_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#else
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#endif
#elif defined (CRYPTOLIB_STOP_SEC_CODE)
  #undef       CRYPTOLIB_STOP_SEC_CODE
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CRYPTOLIB_START_SEC_VAR_INIT_BOOLEAN
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_BOOLEAN"
#else
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#endif
#elif defined (CRYPTOLIB_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CRYPTOLIB_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_INIT_8)
  #undef       CRYPTOLIB_START_SEC_VAR_INIT_8
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_8"
#else
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#endif
#elif defined (CRYPTOLIB_STOP_SEC_VAR_INIT_8)
  #undef       CRYPTOLIB_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_INIT_16)
  #undef       CRYPTOLIB_START_SEC_VAR_INIT_16
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_16"
#else
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#endif
#elif defined (CRYPTOLIB_STOP_SEC_VAR_INIT_16)
  #undef       CRYPTOLIB_STOP_SEC_VAR_INIT_16
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_INIT_32)
  #undef       CRYPTOLIB_START_SEC_VAR_INIT_32
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_32"
#else
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#endif
#elif defined (CRYPTOLIB_STOP_SEC_VAR_INIT_32)
  #undef       CRYPTOLIB_STOP_SEC_VAR_INIT_32
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CRYPTOLIB_START_SEC_VAR_INIT_UNSPECIFIED
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#else
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#endif
#elif defined (CRYPTOLIB_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CRYPTOLIB_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_BOOLEAN
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_BOOLEAN"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_8)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_8
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_8"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_8)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_32)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_32
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_32"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_32)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_UNSPECIFIED
#if (HWRESOURCE_GET_MCU() == HWRESOURCE_S32K31X)
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#else
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#endif
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_GLOBALB_BOOLEAN)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_GLOBALB_BOOLEAN
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_GLOBALB_BOOLEAN)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_GLOBALB_BOOLEAN
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_GLOBALB_8)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_GLOBALB_8
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_GLOBALB_8)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_GLOBALB_8
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_GLOBALB_16)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_GLOBALB_16
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_GLOBALB_16)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_GLOBALB_16
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_GLOBALB_32)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_GLOBALB_32
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_GLOBALB_32)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_GLOBALB_32
  #pragma ghs section

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED
  #pragma ghs section bss=".gbbss.DEFAULT_GLOBALB_RAM_VAR_CLEARED"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_GLOBALB_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 CryIf                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (CRYIF_START_SEC_CODE)
  #undef      CRYIF_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CRYIF_STOP_SEC_CODE)
  #undef      CRYIF_STOP_SEC_CODE
  #pragma ghs section

#elif defined (CRYIF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef      CRYIF_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (CRYIF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef      CRYIF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (CRYIF_START_SEC_VAR_CLEARED_8)
  #undef      CRYIF_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_8"
#elif defined (CRYIF_STOP_SEC_VAR_CLEARED_8)
  #undef      CRYIF_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (CRYIF_START_SEC_VAR_CLEARED_32)
  #undef      CRYIF_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_32"
#elif defined (CRYIF_STOP_SEC_VAR_CLEARED_32)
  #undef      CRYIF_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (CRYIF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      CRYIF_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (CRYIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      CRYIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (CRYIF_START_SEC_CONST_UNSPECIFIED)
  #undef      CRYIF_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
#elif defined (CRYIF_STOP_SEC_CONST_UNSPECIFIED)
    #undef      CRYIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (CRYIF_START_SEC_CONST_8)
  #undef      CRYIF_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_8"
#elif defined (CRYIF_STOP_SEC_CONST_8)
    #undef      CRYIF_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (CRYIF_START_SEC_CONST_PTR)
  #undef      CRYIF_START_SEC_CONST_PTR
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CRYIF_STOP_SEC_CONST_PTR)
    #undef      CRYIF_STOP_SEC_CONST_PTR
  #pragma ghs section

#elif defined (CRYIF_START_SEC_CONST_32)
  #undef      CRYIF_START_SEC_CONST_32
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_32"
#elif defined (CRYIF_STOP_SEC_CONST_32)
  #undef      CRYIF_STOP_SEC_CONST_32
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 KEYM                                                       */
/* -------------------------------------------------------------------------- */
#elif defined (KEYM_START_SEC_CODE)
  #undef       KEYM_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (KEYM_STOP_SEC_CODE)
  #undef       KEYM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (KEYM_START_SEC_CONST_8)
  #undef       KEYM_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_8"
#elif defined (KEYM_STOP_SEC_CONST_8)
  #undef       KEYM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (KEYM_START_SEC_VAR_CLEARED_8)
  #undef       KEYM_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_8"
#elif defined (KEYM_STOP_SEC_VAR_CLEARED_8)
  #undef       KEYM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (KEYM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       KEYM_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_32"
#elif defined (KEYM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       KEYM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (KEYM_START_SEC_CONST_UNSPECIFIED)
  #undef       KEYM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
#elif defined (KEYM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       KEYM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section

#elif defined (KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section

#elif defined (KEYM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED)
  #undef       KEYM_START_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_CONFIG_DATA_PREBUILD_UNSPECIFIED"
#elif defined (KEYM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED)
  #undef       KEYM_STOP_SEC_CONFIG_DATA_PREBUILD_UNSPECIFIED
  #pragma section

/* -------------------------------------------------------------------------- */
/*                 WDGIF                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (WDGIF_START_SEC_CODE)
  #undef       WDGIF_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (WDGIF_STOP_SEC_CODE)
  #undef       WDGIF_STOP_SEC_CODE
  #pragma ghs section

#elif defined (WDGIF_START_SEC_CONST_UNSPECIFIED)
  #undef       WDGIF_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDGIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       WDGIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

/* ---------------------------------------------------------------------------*/
/*                           WDG_76_ACW                                       */
/* -------------------------------------------------------------------------- */
#elif defined (WDG_76_ACW_START_SEC_CODE)
  #undef       WDG_76_ACW_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (WDG_76_ACW_STOP_SEC_CODE)
  #undef       WDG_76_ACW_STOP_SEC_CODE
  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_VAR_CLEARED_32)
  #undef       WDG_76_ACW_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDG_76_ACW_STOP_SEC_VAR_CLEARED_32)
  #undef       WDG_76_ACW_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_VAR_UNSPECIFIED)
  #undef       WDG_76_ACW_START_SEC_VAR_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDG_76_ACW_STOP_SEC_VAR_UNSPECIFIED)
  #undef       WDG_76_ACW_STOP_SEC_VAR_UNSPECIFIED
  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_CONST_8)
  #undef       WDG_76_ACW_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_8)
  #undef       WDG_76_ACW_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_CONST_16)
  #undef       WDG_76_ACW_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_16)
  #undef       WDG_76_ACW_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_CONST_32)
  #undef       WDG_76_ACW_START_SEC_CONST_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_32)
  #undef       WDG_76_ACW_STOP_SEC_CONST_32
  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_CONST_UNSPECIFIED)
  #undef       WDG_76_ACW_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED)
  #undef       WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 WDGM                                                       */
/* -------------------------------------------------------------------------- */

#elif defined (WDGM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       WDGM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (WDGM_START_SEC_CONST_UNSPECIFIED)
  #undef       WDGM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDGM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       WDGM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (WDGM_START_SEC_CODE)
  #undef       WDGM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (WDGM_STOP_SEC_CODE)
  #undef       WDGM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (WDGM_START_SEC_PUBLIC_CODE)
  #undef       WDGM_START_SEC_PUBLIC_CODE

  #pragma ghs section text=".text.DEFAULT_PUBLIC_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (WDGM_STOP_SEC_PUBLIC_CODE)
  #undef       WDGM_STOP_SEC_PUBLIC_CODE
  #pragma ghs section

#elif defined (WDGM_START_SEC_VAR_CLEARED_8)
  #undef       WDGM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_8)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (WDGM_START_SEC_VAR_CLEARED_16)
  #undef       WDGM_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_16)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (WDGM_START_SEC_CONST_8)
  #undef       WDGM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDGM_STOP_SEC_CONST_8)
  #undef       WDGM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (WDGM_START_SEC_CONST_16)
  #undef       WDGM_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDGM_STOP_SEC_CONST_16)
  #undef       WDGM_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (WDGM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       WDGM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (WDGM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       WDGM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (WDGM_START_SEC_VAR_CLEARED_32)
  #undef       WDGM_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_32)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (WDGM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       WDGM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "WDGM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (WDGM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       WDGM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (WDGM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       WDGM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "WDGM_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
#elif defined (WDGM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       WDGM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma clear
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*        Xcp                                                                 */
/* -------------------------------------------------------------------------- */
#elif defined (XCP_START_SEC_VAR_CLEARED_8)
  #undef       XCP_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_CLEARED_8)
  #undef       XCP_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CLEARED_16)
  #undef       XCP_START_SEC_VAR_CLEARED_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_CLEARED_16)
  #undef       XCP_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (XCP_START_SEC_CONST_8)
  #undef       XCP_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_CONST_8)
  #undef       XCP_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CLEARED_32)
  #undef       XCP_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_CLEARED_32)
  #undef       XCP_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       XCP_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       XCP_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       XCP_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       XCP_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       XCP_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       XCP_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_NO_INIT_8)
  #undef       XCP_START_SEC_VAR_NO_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_8)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_NO_INIT_32)
  #undef       XCP_START_SEC_VAR_NO_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_32)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_32
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       XCP_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       XCP_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       XCP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (XCP_START_SEC_CONST_UNSPECIFIED)
  #undef       XCP_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       XCP_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (XCP_START_SEC_CODE)
  #undef       XCP_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (XCP_STOP_SEC_CODE)
  #undef       XCP_STOP_SEC_CODE
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       XCP_START_SEC_VAR_POWER_ON_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       XCP_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CALIBRATION_ROM)
  #undef       XCP_START_SEC_VAR_CALIBRATION_ROM
  #pragma alignvar (4)
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CALIBRATION_ROM"
#elif defined (XCP_STOP_SEC_VAR_CALIBRATION_ROM)
  #undef       XCP_STOP_SEC_VAR_CALIBRATION_ROM
  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CALIBRATION_RAM)
  #undef       XCP_START_SEC_VAR_CALIBRATION_RAM
  #pragma alignvar (4)
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CALIBRATION_RAM"
#elif defined (XCP_STOP_SEC_VAR_CALIBRATION_RAM)
  #undef       XCP_STOP_SEC_VAR_CALIBRATION_RAM
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 CoSvAb                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (COSVAB_START_SEC_CODE)
  #undef       COSVAB_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COSVAB_STOP_SEC_CODE)
  #undef       COSVAB_STOP_SEC_CODE
  #pragma ghs section

#elif defined (COSVAB_START_SEC_VAR_INIT_8)
  #undef       COSVAB_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COSVAB_STOP_SEC_VAR_INIT_8)
  #undef       COSVAB_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (COSVAB_START_SEC_VAR_CLEARED_32)
  #undef       COSVAB_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COSVAB_STOP_SEC_VAR_CLEARED_32)
  #undef       COSVAB_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (COSVAB_START_SEC_CONST_32)
  #undef       COSVAB_START_SEC_CONST_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COSVAB_STOP_SEC_CONST_32)
  #undef       COSVAB_STOP_SEC_CONST_32
  #pragma ghs section

#elif defined (COSVAB_START_SEC_CONST_UNSPECIFIED)
  #undef       COSVAB_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COSVAB_STOP_SEC_CONST_UNSPECIFIED)
  #undef       COSVAB_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 IoHwAb                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (IOHWAB_START_SEC_CODE)
  #undef       IOHWAB_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IOHWAB_STOP_SEC_CODE)
  #undef       IOHWAB_STOP_SEC_CODE
  #pragma ghs section

#elif defined (IOHWAB_START_SEC_VAR_CLEARED_8)
  #undef       IOHWAB_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IOHWAB_STOP_SEC_VAR_CLEARED_8)
  #undef       IOHWAB_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (IOHWAB_START_SEC_VAR_CLEARED_16)
  #undef       IOHWAB_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IOHWAB_STOP_SEC_VAR_CLEARED_16)
  #undef       IOHWAB_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (IOHWAB_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IOHWAB_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IOHWAB_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IOHWAB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (IOHWAB_START_SEC_CONST_8)
  #undef       IOHWAB_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IOHWAB_STOP_SEC_CONST_8)
  #undef       IOHWAB_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (IOHWAB_START_SEC_CONST_16)
  #undef       IOHWAB_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IOHWAB_STOP_SEC_CONST_16)
  #undef       IOHWAB_STOP_SEC_CONST_16
 #pragma ghs section

#elif defined (IOHWAB_START_SEC_CONST_UNSPECIFIED)
  #undef       IOHWAB_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IOHWAB_STOP_SEC_CONST_UNSPECIFIED)
  #undef       IOHWAB_STOP_SEC_CONST_UNSPECIFIED
 #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                               J1939TP                                      */
/* -------------------------------------------------------------------------- */
#elif defined (J1939TP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939TP_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939TP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939TP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (J1939TP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939TP_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939TP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939TP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (J1939TP_START_SEC_CONST_8)
  #undef       J1939TP_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939TP_STOP_SEC_CONST_8)
  #undef       J1939TP_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (J1939TP_START_SEC_CONST_16)
  #undef       J1939TP_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939TP_STOP_SEC_CONST_16)
  #undef       J1939TP_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (J1939TP_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939TP_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939TP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939TP_STOP_SEC_CONST_UNSPECIFIED
 #pragma ghs section

#elif defined (J1939TP_START_SEC_CODE)
  #undef       J1939TP_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939TP_STOP_SEC_CODE)
  #undef       J1939TP_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                               J1939Rm                                      */
/* -------------------------------------------------------------------------- */
#elif defined (J1939RM_START_SEC_VAR_NO_INIT_8)
  #undef       J1939RM_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939RM_STOP_SEC_VAR_NO_INIT_8)
  #undef       J1939RM_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939RM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939RM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939RM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939RM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939RM_STOP_SEC_VAR_CLEARED_BOOLEAN
 #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_CLEARED_8)
  #undef       J1939RM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939RM_STOP_SEC_VAR_CLEARED_8)
  #undef       J1939RM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_CLEARED_16)
  #undef       J1939RM_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939RM_STOP_SEC_VAR_CLEARED_16)
  #undef       J1939RM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_INIT_8)
  #undef       J1939RM_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939RM_STOP_SEC_VAR_INIT_8)
  #undef       J1939RM_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_INIT_32)
  #undef       J1939RM_START_SEC_VAR_INIT_32

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939RM_STOP_SEC_VAR_INIT_32)
  #undef       J1939RM_STOP_SEC_VAR_INIT_32
  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939RM_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939RM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (J1939RM_START_SEC_CONST_8)
  #undef       J1939RM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (J1939RM_STOP_SEC_CONST_8)
  #undef       J1939RM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (J1939RM_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939RM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (J1939RM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (J1939RM_START_SEC_CODE)
  #undef       J1939RM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939RM_STOP_SEC_CODE)
  #undef       J1939RM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (J1939RM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       J1939RM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (J1939RM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                               J1939Nm                                      */
/* -------------------------------------------------------------------------- */
#elif defined (J1939NM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939NM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939NM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939NM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (J1939NM_START_SEC_VAR_CLEARED_8)
  #undef       J1939NM_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939NM_STOP_SEC_VAR_CLEARED_8)
  #undef       J1939NM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (J1939NM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939NM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (J1939NM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939NM_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939NM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939NM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (J1939NM_START_SEC_CONST_8)
  #undef       J1939NM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939NM_STOP_SEC_CONST_8)
  #undef       J1939NM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (J1939NM_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939NM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939NM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939NM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (J1939NM_START_SEC_CODE)
  #undef       J1939NM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939NM_STOP_SEC_CODE)
  #undef       J1939NM_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                               J1939Dcm                                     */
/* -------------------------------------------------------------------------- */
#elif defined (J1939DCM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939DCM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939DCM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (J1939DCM_START_SEC_VAR_NO_INIT_8)
  #undef       J1939DCM_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939DCM_STOP_SEC_VAR_NO_INIT_8)
  #undef       J1939DCM_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (J1939DCM_START_SEC_VAR_NO_INIT_32)
  #undef       J1939DCM_START_SEC_VAR_NO_INIT_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939DCM_STOP_SEC_VAR_NO_INIT_32)
  #undef       J1939DCM_STOP_SEC_VAR_NO_INIT_32
  #pragma ghs section

#elif defined (J1939DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (J1939DCM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939DCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (J1939DCM_START_SEC_CONST_INIT_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_CONST_INIT_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_INIT"
#elif defined (J1939DCM_STOP_SEC_CONST_INIT_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_CONST_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (J1939DCM_START_SEC_CONST_8)
  #undef       J1939DCM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939DCM_STOP_SEC_CONST_8)
  #undef       J1939DCM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (J1939DCM_START_SEC_CONST_32)
  #undef       J1939DCM_START_SEC_CONST_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939DCM_STOP_SEC_CONST_32)
  #undef       J1939DCM_STOP_SEC_CONST_32
  #pragma ghs section

#elif defined (J1939DCM_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939DCM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (J1939DCM_START_SEC_CODE)
  #undef       J1939DCM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939DCM_STOP_SEC_CODE)
  #undef       J1939DCM_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                             OS Profiler                                    */
/* -------------------------------------------------------------------------- */
#elif defined (OPF_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OPF_START_SEC_VAR_NO_INIT_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_NO_INIT_8)
  #undef       OPF_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_8)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_8

  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_NO_INIT_16)
  #undef       OPF_START_SEC_VAR_NO_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_16)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_NO_INIT_32)
  #undef       OPF_START_SEC_VAR_NO_INIT_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_32)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_32
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OPF_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_CLEARED_8)
  #undef       OPF_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_8)
  #undef       OPF_STOP_SEC_VAR_CLEARED_8
 #pragma ghs section

#elif defined (OPF_START_SEC_VAR_CLEARED_16)
  #undef       OPF_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_16)
  #undef       OPF_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_CLEARED_32)
  #undef       OPF_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_32)
  #undef       OPF_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_INIT_BOOLEAN)
  #undef       OPF_START_SEC_VAR_INIT_BOOLEAN

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       OPF_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_INIT_8)
  #undef       OPF_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_VAR_INIT_8)
  #undef       OPF_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_INIT_16)
  #undef       OPF_START_SEC_VAR_INIT_16

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_VAR_INIT_16)
  #undef       OPF_STOP_SEC_VAR_INIT_16
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_INIT_32)
  #undef       OPF_START_SEC_VAR_INIT_32

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_VAR_INIT_32)
  #undef       OPF_STOP_SEC_VAR_INIT_32
  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OPF_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OPF_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (OPF_START_SEC_CONST_BOOLEAN)
  #undef       OPF_START_SEC_CONST_BOOLEAN

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OPF_STOP_SEC_CONST_BOOLEAN)
  #undef       OPF_STOP_SEC_CONST_BOOLEAN
  #pragma ghs section

#elif defined (OPF_START_SEC_CONST_8)
  #undef       OPF_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OPF_STOP_SEC_CONST_8)
  #undef       OPF_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (OPF_START_SEC_CONST_16)
  #undef       OPF_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (OPF_STOP_SEC_CONST_16)
  #undef       OPF_STOP_SEC_CONST_16

  #pragma ghs section

#elif defined (OPF_START_SEC_CONST_32)
  #undef       OPF_START_SEC_CONST_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (OPF_STOP_SEC_CONST_32)
  #undef       OPF_STOP_SEC_CONST_32
  #pragma ghs section

#elif defined (OPF_START_SEC_CONST_UNSPECIFIED)
  #undef       OPF_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OPF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OPF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (OPF_START_SEC_CODE)
  #undef       OPF_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_CODE)
  #undef       OPF_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                             OS Profiler CDD                                */
/* -------------------------------------------------------------------------- */

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_8)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_8)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_16)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_16)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_32)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_32)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_32
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_8)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_8)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_16)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_16)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_32)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_32

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_32)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_BOOLEAN

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_BOOLEAN

  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_8)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_8

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_8)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_8
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_16)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_16

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_16)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_16
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_32)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_32

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_32)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_32
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CONST_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_CONST_BOOLEAN

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_BOOLEAN
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CONST_8)
  #undef       OSPROFILERCDD_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_8)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CONST_16)
  #undef       OSPROFILERCDD_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_16)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CONST_32)
  #undef       OSPROFILERCDD_START_SEC_CONST_32

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_32)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_32
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CONST_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CODE)
  #undef       OSPROFILERCDD_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_CODE)
  #undef       OSPROFILERCDD_STOP_SEC_CODE
  #pragma ghs section


/* -------------------------------------------------------------------------- */
/*                                 RamTst                                     */
/* -------------------------------------------------------------------------- */
#elif defined (RAMTST_START_SEC_CODE)
  #undef       RAMTST_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (RAMTST_STOP_SEC_CODE)
  #undef       RAMTST_STOP_SEC_CODE
  #pragma ghs section

#elif defined (RAMTST_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       RAMTST_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (RAMTST_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       RAMTST_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (RAMTST_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       RAMTST_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (RAMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       RAMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (RAMTST_START_SEC_CONST_UNSPECIFIED)
  #undef       RAMTST_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (RAMTST_STOP_SEC_CONST_UNSPECIFIED)
  #undef       RAMTST_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (RAMTST_START_SEC_VAR_CLEARED_8)
  #undef      RAMTST_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (RAMTST_STOP_SEC_VAR_CLEARED_8)
  #undef      RAMTST_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 ETHIF                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (ETHIF_START_SEC_CODE)
  #undef       ETHIF_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHIF_STOP_SEC_CODE)
  #undef       ETHIF_STOP_SEC_CODE
  #pragma ghs section

#elif defined (ETHIF_START_SEC_VAR_CLEARED_8)
  #undef       ETHIF_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHIF_STOP_SEC_VAR_CLEARED_8)
  #undef       ETHIF_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (ETHIF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHIF_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (ETHIF_START_SEC_CONST_8)
  #undef       ETHIF_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ETHIF_STOP_SEC_CONST_8)
  #undef       ETHIF_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (ETHIF_START_SEC_CONST_UNSPECIFIED)
  #undef       ETHIF_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ETHIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ETHIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                 ETHSM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (ETHSM_START_SEC_CODE)
  #undef       ETHSM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHSM_STOP_SEC_CODE)
  #undef       ETHSM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (ETHSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ETHSM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ETHSM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (ETHSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       ETHSM_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (ETHSM_START_SEC_CONST_8)
  #undef       ETHSM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ETHSM_STOP_SEC_CONST_8)
  #undef       ETHSM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (ETHSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHSM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (ETHSM_START_SEC_CONST_UNSPECIFIED)
  #undef       ETHSM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ETHSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ETHSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 ETHTRCV                                                    */
/* -------------------------------------------------------------------------- */
#elif defined (ETHTRCV_START_SEC_CODE)
  #undef      ETHTRCV_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHTRCV_STOP_SEC_CODE)
  #undef      ETHTRCV_STOP_SEC_CODE
  #pragma ghs section

#elif defined (ETHTRCV_PEF7071_START_SEC_CODE)
   #undef      ETHTRCV_PEF7071_START_SEC_CODE
   #pragma ghs section text=".text.DEFAULT_CODE"
   #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
   #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
   #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHTRCV_PEF7071_STOP_SEC_CODE)
   #undef      ETHTRCV_PEF7071_STOP_SEC_CODE
   #pragma ghs section

#elif defined (ETHTRCV_PEF7071_START_SEC_CONST_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_START_SEC_CONST_UNSPECIFIED
   #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ETHTRCV_PEF7071_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_STOP_SEC_CONST_UNSPECIFIED
   #pragma ghs section

#elif defined (ETHTRCV_PEF7071_START_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_START_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHTRCV_PEF7071_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_STOP_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma ghs section

#elif defined (ETHTRCV_PEF7071_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (ETHTRCV_PEF7071_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma ghs section

#elif defined (ETHTRCV_BCM89811_START_SEC_CODE)
  #undef      ETHTRCV_BCM89811_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_CODE)
  #undef      ETHTRCV_BCM89811_STOP_SEC_CODE
  #pragma ghs section

#elif defined (ETHTRCV_BCM89811_START_SEC_CONST_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_CONST_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (ETHTRCV_BCM89811_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (ETHTRCV_BCM89811_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 ETHSWT                                                    */
/* -------------------------------------------------------------------------- */
#elif defined (ETHSWT_START_SEC_CODE)
  #undef      ETHSWT_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHSWT_STOP_SEC_CODE)
  #undef      ETHSWT_STOP_SEC_CODE
  #pragma ghs section

#elif defined (ETHSWT_BCM89531_START_SEC_CODE)
  #undef      ETHSWT_BCM89531_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHSWT_BCM89531_STOP_SEC_CODE)
  #undef      ETHSWT_BCM89531_STOP_SEC_CODE
  #pragma ghs section

#elif defined (ETHSWT_BCM89531_START_SEC_CONST_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHSWT_BCM89531_STOP_SEC_CONST_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (ETHSWT_BCM89531_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHSWT_BCM89531_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (ETHSWT_BCM89531_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (ETHSWT_BCM89531_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             DOIP                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (DOIP_START_SEC_CODE)
  #undef       DOIP_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DOIP_STOP_SEC_CODE)
  #undef       DOIP_STOP_SEC_CODE
  #pragma ghs section

#elif defined (DOIP_START_SEC_CONST_UNSPECIFIED)
  #undef       DOIP_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DOIP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       DOIP_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (DOIP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DOIP_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DOIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DOIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (DOIP_START_SEC_VAR_NO_INIT_8)
  #undef       DOIP_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DOIP_STOP_SEC_VAR_NO_INIT_8)
  #undef       DOIP_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (DOIP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DOIP_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DOIP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DOIP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (DOIP_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DOIP_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DOIP_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DOIP_STOP_SEC_VAR_INIT_UNSPECIFIED
 #pragma ghs section

#elif defined (DOIP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DOIP_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DOIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DOIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             UDPNM                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (UDPNM_START_SEC_CODE)
  #undef       UDPNM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (UDPNM_STOP_SEC_CODE)
  #undef       UDPNM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (UDPNM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       UDPNM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (UDPNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       UDPNM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (UDPNM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       UDPNM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (UDPNM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       UDPNM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (UDPNM_START_SEC_VAR_NO_INIT_8)
  #undef       UDPNM_START_SEC_VAR_NO_INIT_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (UDPNM_STOP_SEC_VAR_NO_INIT_8)
  #undef       UDPNM_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section

#elif defined (UDPNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       UDPNM_START_SEC_VAR_NO_INIT_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (UDPNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       UDPNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (UDPNM_START_SEC_CONST_8)
  #undef       UDPNM_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (UDPNM_STOP_SEC_CONST_8)
  #undef       UDPNM_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (UDPNM_START_SEC_CONST_UNSPECIFIED)
  #undef       UDPNM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (UDPNM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       UDPNM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (UDPNM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       UDPNM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (UDPNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       UDPNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

/* ---------------------------------------------------------------------- */
/*                               SOAD                                     */
/* ---------------------------------------------------------------------- */
#elif defined (SOAD_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       SOAD_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma alignvar (1)
#elif defined (SOAD_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       SOAD_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_NO_INIT_8)
  #undef       SOAD_START_SEC_VAR_NO_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT_8"
  #pragma alignvar (1)
#elif defined (SOAD_STOP_SEC_VAR_NO_INIT_8)
  #undef       SOAD_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_NO_INIT_16)
  #undef       SOAD_START_SEC_VAR_NO_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT_16"
  #pragma alignvar (2)
#elif defined (SOAD_STOP_SEC_VAR_NO_INIT_16)
  #undef       SOAD_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_NO_INIT_32)
  #undef       SOAD_START_SEC_VAR_NO_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT_32"
  #pragma alignvar (4)
#elif defined (SOAD_STOP_SEC_VAR_NO_INIT_32)
  #undef       SOAD_STOP_SEC_VAR_NO_INIT_32
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma alignvar (4)
#elif defined (SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       SOAD_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_BOOLEAN"
  #pragma alignvar (1)
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       SOAD_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_CLEARED_8)
  #undef       SOAD_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_8"
  #pragma alignvar (1)
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_8)
  #undef       SOAD_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_CLEARED_16)
  #undef       SOAD_START_SEC_VAR_CLEARED_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_16"
  #pragma alignvar (2)
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_16)
  #undef       SOAD_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_CLEARED_32)
  #undef       SOAD_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_32"
  #pragma alignvar (4)
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_32)
  #undef       SOAD_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       SOAD_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma alignvar (4)
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       SOAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_INIT_BOOLEAN)
  #undef       SOAD_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_BOOLEAN"
  #pragma alignvar (1)
#elif defined (SOAD_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       SOAD_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_INIT_8)
  #undef       SOAD_START_SEC_VAR_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_8"
  #pragma alignvar (1)
#elif defined (SOAD_STOP_SEC_VAR_INIT_8)
  #undef       SOAD_STOP_SEC_VAR_INIT_8
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_INIT_16)
  #undef       SOAD_START_SEC_VAR_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_16"
  #pragma alignvar (2)
#elif defined (SOAD_STOP_SEC_VAR_INIT_16)
  #undef       SOAD_STOP_SEC_VAR_INIT_16
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_INIT_32)
  #undef       SOAD_START_SEC_VAR_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_32"
  #pragma alignvar (4)
#elif defined (SOAD_STOP_SEC_VAR_INIT_32)
  #undef       SOAD_STOP_SEC_VAR_INIT_32
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       SOAD_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
  #pragma alignvar (4)
#elif defined (SOAD_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       SOAD_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_CONST_BOOLEAN)
  #undef       SOAD_START_SEC_CONST_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_CONST_BOOLEAN"
  #pragma alignvar (1)
#elif defined (SOAD_STOP_SEC_CONST_BOOLEAN)
  #undef       SOAD_STOP_SEC_CONST_BOOLEAN
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_CONST_8)
  #undef       SOAD_START_SEC_CONST_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_CONST_8"
  #pragma alignvar (1)
#elif defined (SOAD_STOP_SEC_CONST_8)
  #undef       SOAD_STOP_SEC_CONST_8
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_CONST_16)
  #undef       SOAD_START_SEC_CONST_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_CONST_16"
  #pragma alignvar (2)
#elif defined (SOAD_STOP_SEC_CONST_16)
  #undef       SOAD_STOP_SEC_CONST_16
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_CONST_32)
  #undef       SOAD_START_SEC_CONST_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_CONST_32"
  #pragma alignvar (4)
#elif defined (SOAD_STOP_SEC_CONST_32)
  #undef       SOAD_STOP_SEC_CONST_32
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_CONST_UNSPECIFIED)
  #undef       SOAD_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma alignvar (4)
#elif defined (SOAD_STOP_SEC_CONST_UNSPECIFIED)
  #undef       SOAD_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (SOAD_START_SEC_CODE)
  #undef       SOAD_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (SOAD_STOP_SEC_CODE)
  #undef       SOAD_STOP_SEC_CODE
  #pragma ghs section

/* ---------------------------------------------------------------- */
/*                              TCPIP                               */
/* ---------------------------------------------------------------- */
#elif defined (TCPIP_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef      TCPIP_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma alignvar (1)
#elif defined (TCPIP_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef      TCPIP_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_NO_INIT_8)
  #undef      TCPIP_START_SEC_VAR_NO_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT_8"
  #pragma alignvar (1)
#elif defined (TCPIP_STOP_SEC_VAR_NO_INIT_8)
  #undef      TCPIP_STOP_SEC_VAR_NO_INIT_8
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_NO_INIT_16)
  #undef      TCPIP_START_SEC_VAR_NO_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT_16"
  #pragma alignvar (2)
#elif defined (TCPIP_STOP_SEC_VAR_NO_INIT_16)
  #undef      TCPIP_STOP_SEC_VAR_NO_INIT_16
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_NO_INIT_32)
  #undef      TCPIP_START_SEC_VAR_NO_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT_32"
  #pragma alignvar (4)
#elif defined (TCPIP_STOP_SEC_VAR_NO_INIT_32)
  #undef      TCPIP_STOP_SEC_VAR_NO_INIT_32
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma alignvar (4)
#elif defined (TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef      TCPIP_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_BOOLEAN"
  #pragma alignvar (1)
#elif defined (TCPIP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef      TCPIP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_CLEARED_8)
  #undef      TCPIP_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_8"
  #pragma alignvar (1)
#elif defined (TCPIP_STOP_SEC_VAR_CLEARED_8)
  #undef      TCPIP_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_CLEARED_16)
  #undef      TCPIP_START_SEC_VAR_CLEARED_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_16"
  #pragma alignvar (2)
#elif defined (TCPIP_STOP_SEC_VAR_CLEARED_16)
  #undef      TCPIP_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_CLEARED_32)
  #undef      TCPIP_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_32"
  #pragma alignvar (4)
#elif defined (TCPIP_STOP_SEC_VAR_CLEARED_32)
  #undef      TCPIP_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma alignvar (4)
#elif defined (TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_INIT_BOOLEAN)
  #undef      TCPIP_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_BOOLEAN"
  #pragma alignvar (1)
#elif defined (TCPIP_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef      TCPIP_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_INIT_8)
  #undef      TCPIP_START_SEC_VAR_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_8"
  #pragma alignvar (1)
#elif defined (TCPIP_STOP_SEC_VAR_INIT_8)
  #undef      TCPIP_STOP_SEC_VAR_INIT_8
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_INIT_16)
  #undef      TCPIP_START_SEC_VAR_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_16"
  #pragma alignvar (2)
#elif defined (TCPIP_STOP_SEC_VAR_INIT_16)
  #undef      TCPIP_STOP_SEC_VAR_INIT_16
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_INIT_32)
  #undef      TCPIP_START_SEC_VAR_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_32"
  #pragma alignvar (4)
#elif defined (TCPIP_STOP_SEC_VAR_INIT_32)
  #undef      TCPIP_STOP_SEC_VAR_INIT_32
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef      TCPIP_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_INIT_UNSPECIFIED"
  #pragma alignvar (4)
#elif defined (TCPIP_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef      TCPIP_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_CONST_BOOLEAN)
  #undef      TCPIP_START_SEC_CONST_BOOLEAN
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_BOOLEAN"
  #pragma alignvar (1)
#elif defined (TCPIP_STOP_SEC_CONST_BOOLEAN)
  #undef      TCPIP_STOP_SEC_CONST_BOOLEAN
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_CONST_8)
  #undef      TCPIP_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_8"
  #pragma alignvar (1)
#elif defined (TCPIP_STOP_SEC_CONST_8)
  #undef      TCPIP_STOP_SEC_CONST_8
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_CONST_16)
  #undef      TCPIP_START_SEC_CONST_16
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_16"
  #pragma alignvar (2)
#elif defined (TCPIP_STOP_SEC_CONST_16)
  #undef      TCPIP_STOP_SEC_CONST_16
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_CONST_32)
  #undef      TCPIP_START_SEC_CONST_32
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_32"
  #pragma alignvar (4)
#elif defined (TCPIP_STOP_SEC_CONST_32)
  #undef      TCPIP_STOP_SEC_CONST_32
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_CONST_UNSPECIFIED)
  #undef      TCPIP_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_UNSPECIFIED"
  #pragma alignvar (4)
#elif defined (TCPIP_STOP_SEC_CONST_UNSPECIFIED)
  #undef      TCPIP_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef      TCPIP_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_DBTOC_CONFIG_CONST_UNSPECIFIED"
  #pragma alignvar (4)
#elif defined (TCPIP_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef      TCPIP_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma ghs section
  #pragma alignvar (4)

#elif defined (TCPIP_START_SEC_CODE)
  #undef       TCPIP_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (TCPIP_STOP_SEC_CODE)
  #undef       TCPIP_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 CtrlRam                                    */
/* -------------------------------------------------------------------------- */
#elif defined (CTRLRAM_START_SEC_CODE)
  #undef       CTRLRAM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CTRLRAM_STOP_SEC_CODE)
  #undef       CTRLRAM_STOP_SEC_CODE
 #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CTRLRAM_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CTRLRAM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CTRLRAM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CTRLRAM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CTRLRAM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CTRLRAM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_CONST_UNSPECIFIED)
  #undef       CTRLRAM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CTRLRAM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CTRLRAM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_8)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_8

  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_8"
#elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_8)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_8
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_16)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_16

  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_16"
#elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_16)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_16
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_32)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_32

  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_32"
#elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_32)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_32
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_UNSPECIFIED

  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
 #pragma ghs section

/* Controlled RAM Section : This is considered by NO INIT or POWER_ON_CLEARED */

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_BEGIN)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_BEGIN

  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_BEGIN"
 #elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_BEGIN)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_BEGIN
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_END)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_END

  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_END"
#elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_END)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_END
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_8

  #pragma ghs section bss=".CTRLRAM_RAM_VAR_POWER_ON_CLEARED_8"
#elif defined (CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_16

  #pragma ghs section bss=".CTRLRAM_RAM_VAR_POWER_ON_CLEARED_16"
#elif defined (CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_16
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_32)
  #undef       CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_32

  #pragma ghs section bss=".CTRLRAM_RAM_VAR_POWER_ON_CLEARED_32"
#elif defined (CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_32)
  #undef       CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_32
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".CTRLRAM_RAM_VAR_POWER_ON_CLEARED_UNSPECIFIED"
#elif defined (CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_CONST_UNSPECIFIED)
  #undef       CTRLRAM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.CTRLRAM_ROM_CONST"
#elif defined (CTRLRAM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CTRLRAM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section


/* -------------------------------------------------------------------------- */
/*                                 Ocu                                        */
/* -------------------------------------------------------------------------- */
#elif defined (OCU_START_SEC_CODE)
  #undef       OCU_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
#elif defined (OCU_STOP_SEC_CODE)
  #undef       OCU_STOP_SEC_CODE
  #pragma ghs section

#elif defined (OCU_START_SEC_CODE_FAST)
  #undef       OCU_START_SEC_CODE_FAST

  #pragma ghs section text=".text.DEFAULT_CODE"
#elif defined (OCU_STOP_SEC_CODE_FAST)
  #undef       OCU_STOP_SEC_CODE_FAST
  #pragma ghs section

#elif defined (OCU_START_SEC_VAR_CLEARED_8)
  #undef       OCU_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OCU_STOP_SEC_VAR_CLEARED_8)
  #undef       OCU_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section

#elif defined (OCU_START_SEC_VAR_CLEARED_16)
  #undef       OCU_START_SEC_VAR_CLEARED_16

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OCU_STOP_SEC_VAR_CLEARED_16)
  #undef       OCU_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section

#elif defined (OCU_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OCU_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (OCU_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OCU_START_SEC_VAR_INIT_UNSPECIFIED

  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OCU_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OCU_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section

#elif defined (OCU_START_SEC_CONST_8)
  #undef       OCU_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OCU_STOP_SEC_CONST_8)
  #undef       OCU_STOP_SEC_CONST_8
  #pragma ghs section

#elif defined (OCU_START_SEC_CONST_16)
  #undef       OCU_START_SEC_CONST_16

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OCU_STOP_SEC_CONST_16)
  #undef       OCU_STOP_SEC_CONST_16
  #pragma ghs section

#elif defined (OCU_START_SEC_CONST_UNSPECIFIED)
  #undef       OCU_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OCU_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OCU_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                                 Pm                                         */
/* -------------------------------------------------------------------------- */
#elif defined (PM_START_SEC_CODE)
  #undef       PM_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (PM_STOP_SEC_CODE)
  #undef       PM_STOP_SEC_CODE
  #pragma ghs section

#elif defined (PM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PM_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (PM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (PM_START_SEC_CONST_UNSPECIFIED)
  #undef       PM_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (PM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       PM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 RomTst                                     */
/* -------------------------------------------------------------------------- */
#elif defined (ROMTST_START_SEC_CODE)
  #undef       ROMTST_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ROMTST_STOP_SEC_CODE)
  #undef       ROMTST_STOP_SEC_CODE
  #pragma ghs section

#elif defined (ROMTST_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ROMTST_START_SEC_VAR_CLEARED_BOOLEAN

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ROMTST_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ROMTST_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section

#elif defined (ROMTST_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ROMTST_START_SEC_VAR_CLEARED_UNSPECIFIED

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ROMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ROMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section

#elif defined (ROMTST_START_SEC_CONST_UNSPECIFIED)
  #undef       ROMTST_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ROMTST_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ROMTST_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section

#elif defined (ROMTST_START_SEC_VAR_CLEARED_8)
  #undef      ROMTST_START_SEC_VAR_CLEARED_8

  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ROMTST_STOP_SEC_VAR_CLEARED_8)
   #undef      ROMTST_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section
#elif defined (ROMTST_START_SEC_MEM_CHK_ID)
  #undef       ROMTST_START_SEC_MEM_CHK_ID

  #pragma ghs section rodata=".MEM_CHK_ID"
#elif defined (ROMTST_STOP_SEC_MEM_CHK_ID)
  #undef      ROMTST_STOP_SEC_MEM_CHK_ID
  #pragma ghs section
#elif defined (ROMTST_START_SEC_MEM_CHK_CRC)
  #undef       ROMTST_START_SEC_MEM_CHK_CRC

  #pragma ghs section rodata=".MEM_CHK_CRC"
#elif defined (ROMTST_STOP_SEC_MEM_CHK_CRC)
  #undef      ROMTST_STOP_SEC_MEM_CHK_CRC
  #pragma ghs section
#elif defined (ROMTST_START_SEC_MEM_CHECK)
  #undef       ROMTST_START_SEC_MEM_CHECK

  #pragma ghs section text=".MEM_CHECK"
#elif defined (ROMTST_STOP_SEC_MEM_CHECK)
  #undef      ROMTST_STOP_SEC_MEM_CHECK
  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                                 UART                                       */
/* -------------------------------------------------------------------------- */
#elif defined (UART_START_SEC_CODE)
  #undef       UART_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (UART_STOP_SEC_CODE)
  #undef       UART_STOP_SEC_CODE
  #pragma ghs section

/* --------------------------------------------------------------------------*/
/*                                  EOL                                      */
/* --------------------------------------------------------------------------*/
#elif defined (EOL_START_SEC_CODE)
  #undef EOL_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (EOL_STOP_SEC_CODE)
  #undef EOL_STOP_SEC_CODE
  #pragma ghs section

/* --------------------------------------------------------------------------*/
/*                               CDD_ROUTER                                  */
/* --------------------------------------------------------------------------*/
#elif defined (CDD_ROUTER_START_SEC_CONST_8)
  #undef CDD_ROUTER_START_SEC_CONST_8

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CDD_ROUTER_STOP_SEC_CONST_8)
  #undef CDD_ROUTER_STOP_SEC_CONST_8
  #pragma ghs section
#elif defined (CDD_ROUTER_START_SEC_CONST_UNSPECIFIED)
  #undef CDD_ROUTER_START_SEC_CONST_UNSPECIFIED

  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CDD_ROUTER_STOP_SEC_CONST_UNSPECIFIED)
  #undef CDD_ROUTER_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section
#elif defined (CDD_ROUTER_START_SEC_CODE)
  #undef CDD_ROUTER_START_SEC_CODE

  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CDD_ROUTER_STOP_SEC_CODE)
  #undef CDD_ROUTER_STOP_SEC_CODE
  #pragma ghs section

/* --------------------------------------------------------------------------*/
/*                               IDSM                                        */
/* --------------------------------------------------------------------------*/
#elif defined (IDSM_START_SEC_CONST_8)
  #undef IDSM_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IDSM_STOP_SEC_CONST_8)
  #undef IDSM_STOP_SEC_CONST_8
  #pragma ghs section
#elif defined (IDSM_START_SEC_CONST_16)
  #undef       IDSM_START_SEC_CONST_16
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IDSM_STOP_SEC_CONST_16)
  #undef       IDSM_STOP_SEC_CONST_16
  #pragma ghs section
#elif defined (IDSM_START_SEC_CONST_32)
  #undef       IDSM_START_SEC_CONST_32
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IDSM_STOP_SEC_CONST_32)
  #undef       IDSM_STOP_SEC_CONST_32
  #pragma ghs section
#elif defined (IDSM_START_SEC_CONST_UNSPECIFIED)
  #undef IDSM_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IDSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef IDSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_CLEARED_8)
  #undef       IDSM_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_8)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_8
  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_CLEARED_16)
  #undef       IDSM_START_SEC_VAR_CLEARED_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_16)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_16
  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_CLEARED_32)
  #undef       IDSM_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_32)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_32
  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IDSM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_INIT_8)
  #undef       IDSM_START_SEC_VAR_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IDSM_STOP_SEC_VAR_INIT_8)
  #undef       IDSM_STOP_SEC_VAR_INIT_8
  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_INIT_16)
  #undef       IDSM_START_SEC_VAR_INIT_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IDSM_STOP_SEC_VAR_INIT_16)
  #undef       IDSM_STOP_SEC_VAR_INIT_16
  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_INIT_32)
  #undef       IDSM_START_SEC_VAR_INIT_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IDSM_STOP_SEC_VAR_INIT_32)
  #undef       IDSM_STOP_SEC_VAR_INIT_32
  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IDSM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IDSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IDSM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section
#elif defined (IDSM_START_SEC_CODE)
  #undef IDSM_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IDSM_STOP_SEC_CODE)
  #undef IDSM_STOP_SEC_CODE
  #pragma ghs section
/* --------------------------------------------------------------------------*/
/*                               COMXF                                       */
/* --------------------------------------------------------------------------*/
#elif defined (COMXF_START_SEC_CODE)
  #undef COMXF_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COMXF_STOP_SEC_CODE)
  #undef COMXF_STOP_SEC_CODE
  #pragma ghs section
#elif defined (COMXF_START_APPL_SEC_CODE)
  #undef COMXF_START_APPL_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COMXF_STOP_APPL_SEC_CODE)
  #undef COMXF_STOP_APPL_SEC_CODE
  #pragma ghs section
#elif defined (COMXF_START_SEC_VAR_INIT_BOOLEAN)
  #undef COMXF_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COMXF_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef COMXF_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section
#elif defined (COMXF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef COMXF_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef COMXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section
#elif defined (COMXF_START_SEC_LCONFIG_DATA_UNSPECIFIED)
  #undef COMXF_START_SEC_LCONFIG_DATA_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMXF_STOP_SEC_LCONFIG_DATA_UNSPECIFIED)
  #undef COMXF_STOP_SEC_LCONFIG_DATA_UNSPECIFIED
  #pragma ghs section
#elif defined (COMXF_START_SEC_PBCONFIG_DATA_UNSPECIFIED)
  #undef COMXF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMXF_STOP_SEC_PB_CONFIG_DATA_UNSPECIFIED)
  #undef COMXF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
  #pragma ghs section
#elif defined (COMXF_START_SEC_DBTOCCONFIG_DATA_UNSPECIFIED)
  #undef COMXF_START_SEC_DBTOCCONFIG_DATA_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMXF_STOP_SEC_DBTOCCONFIG_DATA_UNSPECIFIED)
  #undef COMXF_STOP_SEC_DBTOCCONFIG_DATA_UNSPECIFIED
  #pragma ghs section
#elif defined (COMXF_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef COMXF_START_SEC_CONFIG_DATA_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COMXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef COMXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #pragma ghs section
#elif defined (COMXF_START_SEC_CODE_ASIL_D)
  #undef COMXF_START_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COMXF_STOP_SEC_CODE_ASIL_D)
  #undef COMXF_STOP_SEC_CODE
  #pragma ghs section
#elif defined (COMXF_START_APPL_SEC_CODE_ASIL_D)
  #undef COMXF_START_APPL_SEC_CODE
  #pragma ghs section text=".text.DEFAULT_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COMXF_STOP_APPL_SEC_CODE_ASIL_D)
  #undef COMXF_STOP_APPL_SEC_CODE
  #pragma ghs section
#elif defined (COMXF_START_SEC_VAR_INIT_ASIL_D_BOOLEAN)
  #undef COMXF_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COMXF_STOP_SEC_VAR_INIT_ASIL_D_BOOLEAN)
  #undef COMXF_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section
#elif defined (COMXF_START_SEC_CONFIG_DATA_ASIL_D_UNSPECIFIED)
  #undef COMXF_START_SEC_CONFIG_DATA_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COMXF_STOP_SEC_CONFIG_DATA_ASIL_D_UNSPECIFIED)
  #undef COMXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                                T1AD                                        */
/* -------------------------------------------------------------------------- */
#elif defined (T1AD_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       T1AD_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (T1AD_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       T1AD_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_CLEARED_8)
  #undef       T1AD_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (T1AD_STOP_SEC_VAR_CLEARED_8)
  #undef       T1AD_STOP_SEC_VAR_CLEARED_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_CLEARED_16)
  #undef       T1AD_START_SEC_VAR_CLEARED_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (2)

#elif defined (T1AD_STOP_SEC_VAR_CLEARED_16)
  #undef       T1AD_STOP_SEC_VAR_CLEARED_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_CLEARED_32)
  #undef       T1AD_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (T1AD_STOP_SEC_VAR_CLEARED_32)
  #undef       T1AD_STOP_SEC_VAR_CLEARED_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       T1AD_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (T1AD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       T1AD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_CONST_BOOLEAN)
  #undef       T1AD_START_SEC_CONST_BOOLEAN
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (T1AD_STOP_SEC_CONST_BOOLEAN)
  #undef       T1AD_STOP_SEC_CONST_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_CONST_8)
  #undef       T1AD_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (T1AD_STOP_SEC_CONST_8)
  #undef       T1AD_STOP_SEC_CONST_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_CONST_16)
  #undef       T1AD_START_SEC_CONST_16
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (2)

#elif defined (T1AD_STOP_SEC_CONST_16)
  #undef       T1AD_STOP_SEC_CONST_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_CONST_32)
  #undef       T1AD_START_SEC_CONST_32
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (T1AD_STOP_SEC_CONST_32)
  #undef       T1AD_STOP_SEC_CONST_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_CONST_UNSPECIFIED)
  #undef       T1AD_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (T1AD_STOP_SEC_CONST_UNSPECIFIED)
  #undef       T1AD_STOP_SEC_CONST_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       T1AD_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (T1AD_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       T1AD_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_NO_INIT_8)
  #undef       T1AD_START_SEC_VAR_NO_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (T1AD_STOP_SEC_VAR_NO_INIT_8)
  #undef       T1AD_STOP_SEC_VAR_NO_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_NO_INIT_16)
  #undef       T1AD_START_SEC_VAR_NO_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (2)

#elif defined (T1AD_STOP_SEC_VAR_NO_INIT_16)
  #undef       T1AD_STOP_SEC_VAR_NO_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_NO_INIT_32)
  #undef       T1AD_START_SEC_VAR_NO_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (T1AD_STOP_SEC_VAR_NO_INIT_32)
  #undef       T1AD_STOP_SEC_VAR_NO_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       T1AD_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (T1AD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       T1AD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_INIT_BOOLEAN)
  #undef       T1AD_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (T1AD_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       T1AD_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_INIT_8)
  #undef       T1AD_START_SEC_VAR_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (T1AD_STOP_SEC_VAR_INIT_8)
  #undef       T1AD_STOP_SEC_VAR_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_INIT_16)
  #undef       T1AD_START_SEC_VAR_INIT_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (2)

#elif defined (T1AD_STOP_SEC_VAR_INIT_16)
  #undef       T1AD_STOP_SEC_VAR_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_INIT_32)
  #undef       T1AD_START_SEC_VAR_INIT_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (T1AD_STOP_SEC_VAR_INIT_32)
  #undef       T1AD_STOP_SEC_VAR_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       T1AD_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (T1AD_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       T1AD_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (T1AD_START_SEC_CODE)
  #undef       T1AD_START_SEC_CODE
  #pragma ghs section text=".text.T1AD_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"

#elif defined (T1AD_STOP_SEC_CODE)
  #undef       T1AD_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                PROVAD                                      */
/* -------------------------------------------------------------------------- */
#elif defined (PROVAD_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       PROVAD_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (PROVAD_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       PROVAD_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_CLEARED_8)
  #undef       PROVAD_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (PROVAD_STOP_SEC_VAR_CLEARED_8)
  #undef       PROVAD_STOP_SEC_VAR_CLEARED_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_CLEARED_16)
  #undef       PROVAD_START_SEC_VAR_CLEARED_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (2)

#elif defined (PROVAD_STOP_SEC_VAR_CLEARED_16)
  #undef       PROVAD_STOP_SEC_VAR_CLEARED_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_CLEARED_32)
  #undef       PROVAD_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (PROVAD_STOP_SEC_VAR_CLEARED_32)
  #undef       PROVAD_STOP_SEC_VAR_CLEARED_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PROVAD_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (PROVAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PROVAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_CONST_BOOLEAN)
  #undef       PROVAD_START_SEC_CONST_BOOLEAN
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (PROVAD_STOP_SEC_CONST_BOOLEAN)
  #undef       PROVAD_STOP_SEC_CONST_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_CONST_8)
  #undef       PROVAD_START_SEC_CONST_8
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (1)

#elif defined (PROVAD_STOP_SEC_CONST_8)
  #undef       PROVAD_STOP_SEC_CONST_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_CONST_16)
  #undef       PROVAD_START_SEC_CONST_16
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (2)

#elif defined (PROVAD_STOP_SEC_CONST_16)
  #undef       PROVAD_STOP_SEC_CONST_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_CONST_32)
  #undef       PROVAD_START_SEC_CONST_32
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (PROVAD_STOP_SEC_CONST_32)
  #undef       PROVAD_STOP_SEC_CONST_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_CONST_UNSPECIFIED)
  #undef       PROVAD_START_SEC_CONST_UNSPECIFIED
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)

#elif defined (PROVAD_STOP_SEC_CONST_UNSPECIFIED)
  #undef       PROVAD_STOP_SEC_CONST_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       PROVAD_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (PROVAD_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       PROVAD_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_NO_INIT_8)
  #undef       PROVAD_START_SEC_VAR_NO_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (PROVAD_STOP_SEC_VAR_NO_INIT_8)
  #undef       PROVAD_STOP_SEC_VAR_NO_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_NO_INIT_16)
  #undef       PROVAD_START_SEC_VAR_NO_INIT_16
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (2)

#elif defined (PROVAD_STOP_SEC_VAR_NO_INIT_16)
  #undef       PROVAD_STOP_SEC_VAR_NO_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_NO_INIT_32)
  #undef       PROVAD_START_SEC_VAR_NO_INIT_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (PROVAD_STOP_SEC_VAR_NO_INIT_32)
  #undef       PROVAD_STOP_SEC_VAR_NO_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       PROVAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (PROVAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       PROVAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_INIT_BOOLEAN)
  #undef       PROVAD_START_SEC_VAR_INIT_BOOLEAN
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (PROVAD_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       PROVAD_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_INIT_8)
  #undef       PROVAD_START_SEC_VAR_INIT_8
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (1)

#elif defined (PROVAD_STOP_SEC_VAR_INIT_8)
  #undef       PROVAD_STOP_SEC_VAR_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_INIT_16)
  #undef       PROVAD_START_SEC_VAR_INIT_16
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (2)

#elif defined (PROVAD_STOP_SEC_VAR_INIT_16)
  #undef       PROVAD_STOP_SEC_VAR_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_INIT_32)
  #undef       PROVAD_START_SEC_VAR_INIT_32
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (PROVAD_STOP_SEC_VAR_INIT_32)
  #undef       PROVAD_STOP_SEC_VAR_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       PROVAD_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (PROVAD_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       PROVAD_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (PROVAD_START_SEC_CODE)
  #undef       PROVAD_START_SEC_CODE
  #pragma ghs section text=".text.PROVAD_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"

#elif defined (PROVAD_STOP_SEC_CODE)
  #undef       PROVAD_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- /
/ MuxDemuxIf /
/ -------------------------------------------------------------------------- */
#elif defined (MuxDemuxIf_START_SEC_CODE)
#undef MuxDemuxIf_START_SEC_CODE
#pragma ghs section text=".text.DEFAULT_CODE"
#pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (MuxDemuxIf_STOP_SEC_CODE)
#undef MuxDemuxIf_STOP_SEC_CODE
#pragma ghs section
#elif defined (MuxDemuxIf_START_SEC_CONST_8)
#undef MuxDemuxIf_START_SEC_CONST_8
#pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (MuxDemuxIf_STOP_SEC_CONST_8)
#undef MuxDemuxIf_STOP_SEC_CONST_8
#pragma ghs section

#elif defined (MuxDemuxIf_START_SEC_VAR_CLEARED_UNSPECIFIED)
 #undef MuxDemuxIf_START_SEC_VAR_CLEARED_UNSPECIFIED

#pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (MuxDemuxIf_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
 #undef MuxDemuxIf_STOP_SEC_VAR_CLEARED_UNSPECIFIED
 #pragma ghs section


#elif defined (MuxDemuxIf_START_SEC_CONST_UNSPECIFIED)
 #undef MuxDemuxIf_START_SEC_CONST_UNSPECIFIED

#pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (MuxDemuxIf_STOP_SEC_CONST_UNSPECIFIED)
 #undef MuxDemuxIf_STOP_SEC_CONST_UNSPECIFIED
 #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                DATALOG                                     */
/* -------------------------------------------------------------------------- */
#elif defined (DATALOG_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DATALOG_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (DATALOG_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DATALOG_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (DATALOG_START_SEC_VAR_CLEARED_8)
  #undef       DATALOG_START_SEC_VAR_CLEARED_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (1)

#elif defined (DATALOG_STOP_SEC_VAR_CLEARED_8)
  #undef       DATALOG_STOP_SEC_VAR_CLEARED_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (DATALOG_START_SEC_VAR_CLEARED_32)
  #undef       DATALOG_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (DATALOG_STOP_SEC_VAR_CLEARED_32)
  #undef       DATALOG_STOP_SEC_VAR_CLEARED_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (DATALOG_RMBA_START_SEC_VAR_CLEARED_32)
  #undef       DATALOG_RMBA_START_SEC_VAR_CLEARED_32
  #pragma ghs section bss=".bss.DATALOG_RMBA_VAR_CLEARED"
  #pragma alignvar (4)

#elif defined (DATALOG_RMBA_STOP_SEC_VAR_CLEARED_32)
  #undef       DATALOG_RMBA_STOP_SEC_VAR_CLEARED_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (DATALOG_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DATALOG_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"

#elif defined (DATALOG_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DATALOG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (DATALOG_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       DATALOG_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (DATALOG_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       DATALOG_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (DATALOG_START_SEC_VAR_NO_INIT_8)
  #undef       DATALOG_START_SEC_VAR_NO_INIT_8
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (1)

#elif defined (DATALOG_STOP_SEC_VAR_NO_INIT_8)
  #undef       DATALOG_STOP_SEC_VAR_NO_INIT_8
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (DATALOG_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DATALOG_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)

#elif defined (DATALOG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DATALOG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (DATALOG_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DATALOG_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
  #pragma alignvar (4)

#elif defined (DATALOG_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DATALOG_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (DATALOG_START_SEC_CODE)
  #undef       DATALOG_START_SEC_CODE
  #pragma ghs section text=".text.DATALOG_CODE"
  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DATALOG_STOP_SEC_CODE)
  #undef       DATALOG_STOP_SEC_CODE
  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 Nml                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (NML_START_SEC_VAR_CLEARED_8)
  #undef       NML_START_SEC_VAR_CLEARED_8
  #pragma section all "NML_RAM_VAR_CLEARED_8"
  #pragma noclear

#elif defined (NML_STOP_SEC_VAR_CLEARED_8)
  #undef       NML_STOP_SEC_VAR_CLEARED_8
  #pragma clear
  #pragma section all restore

#elif defined (NML_RMBA_START_SEC_VAR_CLEARED_8)
  #undef       NML_RMBA_START_SEC_VAR_CLEARED_8
  #pragma section all "NML_RMBA_START_SEC_VAR_CLEARED_8"
  #pragma clear

#elif defined (NML_RMBA_STOP_SEC_VAR_CLEARED_8)
  #undef       NML_RMBA_STOP_SEC_VAR_CLEARED_8
  #pragma clear
  #pragma section all restore

#elif defined (NML_START_SEC_VAR_CLEARED_16)
  #undef       NML_START_SEC_VAR_CLEARED_16
  #pragma section all "NML_RAM_VAR_CLEARED_16"
  #pragma noclear

#elif defined (NML_STOP_SEC_VAR_CLEARED_16)
  #undef       NML_STOP_SEC_VAR_CLEARED_16
  #pragma clear
  #pragma section all restore

#elif defined (NML_START_SEC_VAR_CLEARED_32)
  #undef       NML_START_SEC_VAR_CLEARED_32
  #pragma section all "NML_RAM_VAR_CLEARED_32"
  #pragma noclear

#elif defined (NML_STOP_SEC_VAR_CLEARED_32)
  #undef       NML_STOP_SEC_VAR_CLEARED_32
  #pragma clear
  #pragma section all restore

#elif defined (NML_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NML_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "NML_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma noclear

#elif defined (NML_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NML_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (NML_RMBA_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NML_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "NML_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma clear
  #pragma align 4

#elif defined (NML_RMBA_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NML_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore


#elif defined (NML_START_SEC_VAR_INIT_8)
  #undef       NML_START_SEC_VAR_INIT_8
  #pragma section all "NML_RAM_VAR_INIT_8"
  #pragma noclear
  #pragma align 2

#elif defined (NML_STOP_SEC_VAR_INIT_8)
  #undef       NML_STOP_SEC_VAR_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NML_START_SEC_VAR_INIT_16)
  #undef       NML_START_SEC_VAR_INIT_16
  #pragma section all "NML_RAM_VAR_INIT_16"
  #pragma noclear

#elif defined (NML_STOP_SEC_VAR_INIT_16)
  #undef       NML_STOP_SEC_VAR_INIT_16
  #pragma clear
  #pragma section all restore

#elif defined (NML_START_SEC_VAR_INIT_32)
  #undef       NML_START_SEC_VAR_INIT_32
  #pragma section all "NML_RAM_VAR_INIT_32"
  #pragma noclear

#elif defined (NML_STOP_SEC_VAR_INIT_32)
  #undef       NML_STOP_SEC_VAR_INIT_32
  #pragma clear
  #pragma section all restore

#elif defined (NML_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       NML_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "NML_RAM_VAR_INIT_UNSPECIFIED"
  #pragma noclear

#elif defined (NML_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       NML_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (NML_START_SEC_VAR_NO_INIT_8)
  #undef       NML_START_SEC_VAR_NO_INIT_8
  #pragma ghs section data=".data.NML_RAM_VAR_NO_INIT_8"
  #pragma alignvar (1)

#elif defined (NML_STOP_SEC_VAR_NO_INIT_8)
  #undef       NML_STOP_SEC_VAR_NO_INIT_8
  #pragma alignvar (4)
  #pragma ghs section


#elif defined (NML_START_SEC_VAR_NO_INIT_16)
  #undef       NML_START_SEC_VAR_NO_INIT_16
  #pragma ghs section data=".data.NML_RAM_VAR_NO_INIT_16"
  #pragma alignvar (2)

#elif defined (NML_STOP_SEC_VAR_NO_INIT_16)
  #undef       NML_STOP_SEC_VAR_NO_INIT_16
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NML_START_SEC_VAR_NO_INIT_32)
  #undef       NML_START_SEC_VAR_NO_INIT_32
  #pragma ghs section data=".data.NML_RAM_VAR_NO_INIT_32"
  #pragma alignvar (4)

#elif defined (NML_STOP_SEC_VAR_NO_INIT_32)
  #undef       NML_STOP_SEC_VAR_NO_INIT_32
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NML_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NML_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma ghs section data=".data.NML_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma alignvar (2)

#elif defined (NML_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NML_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma alignvar (4)
  #pragma ghs section

#elif defined (NML_START_SEC_CODE)
  #undef       NML_START_SEC_CODE
  #pragma section code "NML_CODE"
  #pragma section farrom "NML_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "NML_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "NML_RAM_VAR_INIT_UNSPECIFIED"

#elif defined (NML_STOP_SEC_CODE)
  #undef       NML_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                                VERSION                                     */
/* -------------------------------------------------------------------------- */
#elif defined (VERSION_START_BLK_HEADER)
  #undef       VERSION_START_BLK_HEADER
  #pragma ghs section rodata="VERSION_BLK_HEADER"
#elif defined (VERSION_STOP_BLK_HEADER)
  #undef      VERSION_STOP_BLK_HEADER
  #pragma ghs section

#elif defined (VERSION_START_BLK_TRAILER)
  #undef       VERSION_START_BLK_TRAILER
  #pragma ghs section rodata="VERSION_BLK_TRAILER"
#elif defined (VERSION_STOP_BLK_TRAILER)
  #undef      VERSION_STOP_BLK_TRAILER
  #pragma ghs section

/******************************END*********************************************/

#else
  #define SECTION_NOT_FOUND

  #if (HWRESOURCE_VENDOR(HWRESOURCE_RENESAS))
    #undef SECTION_NOT_FOUND

    #if (HWRESOURCE_GET_MCU() == HWRESOURCE_RH850F1L)
      /*************************** MCAL Code Define**********************************/
      #if defined (CAN_START_SEC_CODE)
        #undef CAN_START_SEC_CODE
        #define CAN_RSCAN_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (CAN_STOP_SEC_CODE)
        #undef CAN_STOP_SEC_CODE
        #define CAN_RSCAN_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (SPI_START_SEC_CODE)
        #undef SPI_START_SEC_CODE
        #define SPI_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (SPI_STOP_SEC_CODE)
        #undef SPI_STOP_SEC_CODE
        #define SPI_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (FEE_START_SEC_CODE)
        #undef FEE_START_SEC_CODE
        #define FEE_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (FEE_STOP_SEC_CODE)
        #undef FEE_STOP_SEC_CODE
        #define FEE_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (GPT_START_SEC_CODE)
        #undef GPT_START_SEC_CODE
        #define GPT_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (GPT_STOP_SEC_CODE)
        #undef GPT_STOP_SEC_CODE
        #define GPT_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (ICU_START_SEC_CODE)
        #undef ICU_START_SEC_CODE
        #define ICU_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (ICU_STOP_SEC_CODE)
        #undef ICU_STOP_SEC_CODE
        #define ICU_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (PWM_START_SEC_CODE)
        #undef PWM_START_SEC_CODE
        #define PWM_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (PWM_STOP_SEC_CODE)
        #undef PWM_STOP_SEC_CODE
        #define PWM_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (ETH_START_SEC_CODE)
        #undef ETH_START_SEC_CODE
        #define ETH_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (ETH_STOP_SEC_CODE)
        #undef ETH_STOP_SEC_CODE
        #define ETH_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (CORTST_START_SEC_CODE)
        #undef CORTST_START_SEC_CODE
      #elif defined (CORTST_STOP_SEC_CODE)
        #undef CORTST_STOP_SEC_CODE
      #else
        #define SECTION_NOT_FOUND
      #endif
      /*************************** Stack section ************************************/
    #elif (HWRESOURCE_GET_MCU() == HWRESOURCE_RH850F1K)
      #if defined (SPI_START_SEC_CODE)
        #undef SPI_START_SEC_CODE
        #define SPI_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (SPI_STOP_SEC_CODE)
        #undef SPI_STOP_SEC_CODE
        #define SPI_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (CAN_START_SEC_CODE)
        #undef CAN_START_SEC_CODE
        #define CAN_RSCAN_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (CAN_STOP_SEC_CODE)
        #undef CAN_STOP_SEC_CODE
        #define CAN_RSCAN_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (FEE_START_SEC_CODE)
        #undef FEE_START_SEC_CODE
        #define FEE_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (FEE_STOP_SEC_CODE)
        #undef FEE_STOP_SEC_CODE
        #define FEE_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (ICU_START_SEC_CODE)
        #undef ICU_START_SEC_CODE
        #define ICU_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (ICU_STOP_SEC_CODE)
        #undef ICU_STOP_SEC_CODE
        #define ICU_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (PWM_START_SEC_CODE)
        #undef PWM_START_SEC_CODE
        #define PWM_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (PWM_STOP_SEC_CODE)
        #undef PWM_STOP_SEC_CODE
        #define PWM_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (CORTST_START_SEC_CODE)
        #undef CORTST_START_SEC_CODE
      #elif defined (CORTST_STOP_SEC_CODE)
        #undef CORTST_STOP_SEC_CODE
      #else
        #define SECTION_NOT_FOUND
      #endif
  #elif (HWRESOURCE_GET_MCU() == HWRESOURCE_RH850F1KM)
      #if defined (SPI_START_SEC_CODE)
        #undef SPI_START_SEC_CODE
        #define SPI_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (SPI_STOP_SEC_CODE)
        #undef SPI_STOP_SEC_CODE
        #define SPI_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (CAN_START_SEC_CODE)
        #undef CAN_START_SEC_CODE
        #define CAN_RSCAN_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (CAN_STOP_SEC_CODE)
        #undef CAN_STOP_SEC_CODE
        #define CAN_RSCAN_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (FEE_START_SEC_CODE)
        #undef FEE_START_SEC_CODE
        #define FEE_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (FEE_STOP_SEC_CODE)
        #undef FEE_STOP_SEC_CODE
        #define FEE_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (ICU_START_SEC_CODE)
        #undef ICU_START_SEC_CODE
        #define ICU_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (ICU_STOP_SEC_CODE)
        #undef ICU_STOP_SEC_CODE
        #define ICU_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (PWM_START_SEC_CODE)
        #undef PWM_START_SEC_CODE
        #define PWM_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (PWM_STOP_SEC_CODE)
        #undef PWM_STOP_SEC_CODE
        #define PWM_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (ETH_START_SEC_CODE)
        #undef ETH_START_SEC_CODE
        #define ETH_59_START_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (ETH_STOP_SEC_CODE)
        #undef ETH_STOP_SEC_CODE
        #define ETH_59_STOP_SEC_PUBLIC_CODE
        #include "Mcal_MemMap.h"
      #elif defined (CORTST_START_SEC_CODE)
        #undef CORTST_START_SEC_CODE
      #elif defined (CORTST_STOP_SEC_CODE)
        #undef CORTST_STOP_SEC_CODE
      #else
        #define SECTION_NOT_FOUND
      #endif

    #else
      #define SECTION_NOT_FOUND
    #endif
  #endif

  #if defined (USE_OS_MEMMAP)
    #define OS_DO_NOT_RAISE_ERROR

    #if defined (SECTION_NOT_FOUND)
      #undef SECTION_NOT_FOUND
      #include "Os_MemMap.h"
    #endif

    #undef OS_DO_NOT_RAISE_ERROR
  #endif

  #if defined (SECTION_NOT_FOUND)
    #undef SECTION_NOT_FOUND
    #include "Rte_MemMap.h"
  #endif

  #if defined (SECTION_NOT_FOUND)
    #undef SECTION_NOT_FOUND
    #include "Mcal_MemMap.h"
  #endif

/* -------------------------------------------------------------------------- */
/* CRYPTO_76_HAEMODULE */
/* -------------------------------------------------------------------------- */

#if defined (SECTION_NOT_FOUND)
  #undef SECTION_NOT_FOUND
  #include "Crypto_76_HaeModule_MemMap.h"
#endif

  #if defined (SECTION_NOT_FOUND)
    #error "MemMap.h: No valid section define found"
  #endif
#endif  /* START_WITH_IF */


/* -------------------------------------------------------------------------- */
/* End of module section mapping                                              */
/* -------------------------------------------------------------------------- */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
* PRE-JUSTIFICATION END SECTION (MISRA-C RULE CHECKER)
*******************************************************************************/

/* polyspace:end<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping) */
/* polyspace-end MISRA-C3:D1.1 */
/* polyspace-end MISRA-C3:1.1 */
/* polyspace-end MISRA-C3:20.5 */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
