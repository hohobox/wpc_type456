/*******************************************************************************
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020 - 2021
 * All rights reserved.
 *
 * Disclaimer
 * 1. The NXP Software/Source Code is provided to Licensee "AS IS" without any warranties of any kind.
 * NXP makes no warranties to Licensee and shall not indemnify Licensee or hold it harmless for any
 * reason related to the NXP Software/Source Code or otherwise be liable to the NXP customer. The NXP
 * customer acknowledges and agrees that the NXP Software/Source Code is provided AS-IS and accepts
 * all risks of utilizing the NXP Software under the conditions set forth according to this disclaimer.
 *
 * 2. NXP EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT OF
 * INTELLECTUAL PROPERTY RIGHTS. NXP SHALL HAVE NO LIABILITY TO THE NXP CUSTOMER, OR ITS
 * SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY FOR ANY DAMAGES, INCLUDING WITHOUT LIMITATION,
 * DAMAGES RESULTING OR ALLEGED TO HAVE RESULTED FROM ANY DEFECT, ERROR OR OMISSION IN THE NXP
 * SOFTWARE/SOURCE CODE, THIRD PARTY APPLICATION SOFTWARE AND/OR DOCUMENTATION, OR AS A RESULT OF ANY
 * INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHT OF ANY THIRD PARTY. IN NO EVENT SHALL NXP BE LIABLE
 * FOR ANY INCIDENTAL, INDIRECT, SPECIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL DAMAGES (INCLUDING
 * LOST PROFITS) SUFFERED BY NXP CUSTOMER OR ITS SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY
 * ARISING OUT OF OR RELATED TO THE NXP SOFTWARE/SOURCE CODE EVEN IF NXP HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 *
 * 3. NXP reserves the right to make changes to the NXP Software/Source code any time, also without
 * informing customer.
 *
 * 4. Licensee agrees to indemnify and hold harmless NXP and its affiliated companies from and against
 * any claims, suits, losses, damages, liabilities, costs and expenses (including reasonable
 * attorney's fees) resulting from Licensee's and/or Licensee customer's/licensee's use of the NXP
 * Software/Source Code.
  *******************************************************************************/
 /**
*   @file    NxpNfcRdLib_Ver.h
*   @version 1.0.0
*
*   @brief   AUTOSAR NxpNfcRdLib_Ver - NFC API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup nfc_lib NXP NFC Library Top Level API
*   @ingroup grpsApi
*   @{
*/
/*==================================================================================================
*   Project              : Anfc Reader Library
*   Platform             : ARM
*   Peripheral           : NCX3320
*   Dependencies         : Driver modules
*
*   Build Version        : S32K14X_S32K144_ANFC_Reader_Lib_1_0_20240401
*
*   Copyright 2016-2023 NXP
*
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef NXPNFCRDLIB_VERSION_INFO_H_INCLUDED
#define NXPNFCRDLIB_VERSION_INFO_H_INCLUDED

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           NxpNfcRdLib_Ver.h
* @implements     DESIGN001, DESIGN002
*/
#define NXPNFCRDLIB_VER_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define NXPNFCRDLIB_VER_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define NXPNFCRDLIB_VER_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define NXPNFCRDLIB_VER_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define NXPNFCRDLIB_VER_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define NXPNFCRDLIB_VER_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define NXPNFCRDLIB_VER_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define NXPNFCRDLIB_VER_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (NXPNFCRDLIB_VER_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "NxpNfcRdLib_Ver.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((NXPNFCRDLIB_VER_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (NXPNFCRDLIB_VER_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (NXPNFCRDLIB_VER_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of NxpNfcRdLib_Ver.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((NXPNFCRDLIB_VER_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (NXPNFCRDLIB_VER_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (NXPNFCRDLIB_VER_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of NxpNfcRdLib_Ver.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define NxpNfcRdLib_VER_FILEDESCRIPTION    "NxpNfcRdLib_00.14.00_20180921"
#define NxpNfcRdLib_VER_FILEVERSION         0,14,0,0
#define NxpNfcRdLib_VER_FILEVERSION_STR    "0,14,0,0"
#define NxpNfcRdLib_VER_PRODUCTVERSION      0,14,0,0
#define NxpNfcRdLib_VER_PRODUCTVERSION_STR "0,14,0,0"
#define NxpNfcRdLib_VER_MAJOR  (0)
#define NxpNfcRdLib_VER_MINOR  (14)
#define NxpNfcRdLib_VER_DEV    (0)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/* ______GENERATED_FROM____version_info.txt
 * # _____________________________________________________________________________
 * # Product Description
 * #
 * sw_c_define_name = "NxpNfcRdLib"
 * sw_product_name  = "NxpNfcRdLib" # Product Name
 * sw_cs_namespace  = "NxpNfcRdLibNet" # C# Namespace
 * sw_v_major       = "05"      # Major Release NNX
 * sw_v_minor       = "12"      # SW Minor Version
 * sw_v_dev         = "00"      # SW Development Version
 * sw_maturity      = "B"       # SW Maturity "A" Alpha, "B":Beta, "P": Production
 * sw_metastring    = ""        # Any meta string
 * # _____________________________________________________________________________
 * #
 * # History: Descending
 * # v5.12.00         : NxpNfcRdLib_05.12.00_20171215
 * #                  : - [artf509308] Allow configuration of Q and I value of 0x00h and 0x3Fh from LPCD Calibration cycle in HAL NCx3320.
 * #                  : - [artf387105] Provide Guard Timer callback in HAL DataParams of PN5180.
 * #                  :
 * # v5.11.00         : NxpNfcRdLib_05.11.00_20171127
 * #                  : - [artf272425] New Compliance Example to test EMVCo 2.6b Interoperability as per bulletin No 195.
 * #                  : - [artf264271] MISRA Compliance Fixes.
 * #                  : - [artf245086] Fix in NCx3320 HAL to not turn ON RF Field when Apply Protocol Settings of 18000p3m3.
 * #                  : - [artf265660] HAL PN7462AU SetConfig support for Tx configuration of 1 out of 4 encoding of ISO15693.
 * #                  : - [artf233606] DAL update in LPC1769 to configured supported SPI Baud rate.
 * #                  :
 * # v5.10.00         : NxpNfcRdLib_05.10.00_20171023
 * #                  : - [artf266705] Discovery Loop is updated to support detect/activate of multiple T2T cards.
 * #                  : - [artf263903] Compliance Applications are updated to use common phApp_Init.c and phApp_Init.h files.
 * #                  : - [artf285952] PN5180 Initialization is updated to check FW version rather than reading if TestBus
 * #                  :                is enabled or not while determining if TestBus is enabled or not.
 * #                  : - [artf285846] 18000p3m3ResumeInventory logic in DUT HAL is updated to send correct RxData and length.
 * #                  : - [artf270778] PAL 18092mT Receive API is updated to call phDriver_TimerStop() API correctly based on
 * #                  :                Rx State and also PN7462AU DAL is updated handle Timer Stop when Start is not called before.
 * #                  : - [artf272037] DAL of LPC1769 and K82 is updated to provide HW Timer priority configuration as defined
 * #                  :                in the corresponding board header file.
 * #                  :
 * # v5.09.00         : NxpNfcRdLib_05.09.00_20170925
 * #                  : - [artf264271] Addressed few of the Coverity MISRA warnings.
 * #                  : - [artf264120] ICODE DNA Tag Detection and Activation Should be added in NfcrdlibEx5_ISO15693.
 * #                  : - [artf252642] Check for Software KeyStore Component use in each of the example.
 * #                  : - [artf259688] phceT4T - Writing the NDEF message ( minus 2 bytes of Length) of exact size as NDEF file fails.
 * #                  :
 * # v5.08.00         : NxpNfcRdLib_05.08.00_20170907
 * #                  : - [artf264129] Optimize NCx3320 HAL for WUPA and WUPB transaction time.
 * #                  :
 * # v5.07.00         : NxpNfcRdLib_05.07.00_20170824
 * #                  : - [artf264129] MISRA Compliance Fixes
 * #                  : - [artf265389] HAL PN5180 18000p3m3Inventory API is been updated to clear all interrupts.
 * #                  :
 * # v5.06.00         : NxpNfcRdLib_05.06.00_20170811
 * #                  : - [artf264129] MISRA Compliance Fixes
 * #                  :
 * # v5.05.00         : NxpNfcRdLib_05.05.00_20170804
 * #                  : - [artf260455] Optimization of Poll Guard time with Pn5180 to improve
 * #                  :   Emvco Poll guard time performance
 * #                  :
 * # v5.04.00         : NxpNfcRdLib_05.04.00_20170704
 * #                  : Fixed:
 * #                  : - [artf253094] : HAL Pn5180 reports error in case communication with FW is not reliable.
 * #                  : - [artf240116] : Optimized EMVCo transaction time for customer timing requirements.
 * #                  : - [artf247520] : Updated Readme.txt files in Examples for simplicity by pointing to UM/AN.
 * #
 * # v5.03.00         : NxpNfcRdLib_05.03.00_20170529
 * #                  : Fixed: [artf231388] [artf238247] [artf238354] [artf233747]
 * #                  : [artf229354] [artf250086].
 * #                  :
 * # v5.02.00         : NxpNfcRdLib_05.02.00_20170428
 * #                  : Fixed: [artf244581] [artf245092] [artf246209] [artf222992] [artf246524]
 * #                  : bugs identified in TOP-T5T.
 * #                  : Fixed: [artf246186] [artf247264] in Examples
 * #                  :
 * # v5.01.00         : NxpNfcRdLib_05.01.00_20170414
 * #                  : - SPI NSS Handling moved to HAL
 * #                  : - AL ISO15693 / AL-SLI / AL-ICode DNA merged into single component AL-ICode
 * #                  : - Fix Pn5180 HAL to handle PHHAL_HW_CONFIG_POLL_GUARD_TIME_US==0
 * #                  : - PR Fixes in AL-TOP-T5T
 * #                  : - Updates for Plutus integration/development
 * #                  : - 18000P3M3 updates in HAL 5180 / 7462AU
 * #                  :
 * # v5.00.00         : NxpNfcRdLib_05.00.00_DAL_20170323
 * #                  : Initial internal tag with DAL(phDriver) and phOsal
 * #                  :
 * # v4.06.00         : NxpNfcRdLib_04.06.00_20170209
 * #                  : Fixed:[artf222524] [artf222525] [artf222533] [artf222535] [artf222537]
 * #                  :       [artf222538] [artf224045] [artf221217] [artf223976] [artf221408]
 * #                  :       [artf221407] and [artf173301]
 * #                  :
 * # v4.050.03.011702 : NxpNfcRdLib_v4.050.03.011702
 * #                  : Fixes [artf220074] and [artf222751]
 * #                  :
 * # v4.050.03.001651 : NxpNfcRdLib_v4.050.03.001651
 * #                  : Feedback from internal NXP
 * #                  :
 * # v4.050.02.001650 : NxpNfcRdLib_v4.050.02.001650
 * #                  : Fixed: [artf218286] [artf218337] [artf203532] [artf217665] [artf219615]
 * #                  :        [artf203969] [artf219481] [artf217069]
 * #                  : Open:  [artf219908] [artf219913]
 * #                  :
 * #                  :
 * # v4.050.01.001650 : NxpNfcRdLib_v4.050.01.001650_20161214
 * #                  : Release from GIT
 * #				   : [artf218286] [artf218337] [artf203532] [artf217665]
 * #                  :
 * # v4.050.00.001649 : NxpNfcRdLib_v4.050.00.001649_20161205
 * #                  : Release from GIT
 * #                  :
 * # v4.040.05.011646 > NxpNfcRdLib_v4.040.05.011646_20161115
 * #                  > [artf212345] : Linux Porting updates for phOsal_ThreadDelay
 * #                  > [artf212238] : Enable On-Board Pull Up by SW for IRQ pin used for RC523.
 * #                  >
 * # v4.040.05.001642 > NxpNfcRdLib_v4.040.05.001642_20161017
 * #                  > Fixed [artf200311] #FRDM
 * # v4.040.04.001641 > NxpNfcRdLib_v4.040.04.001641_20161010
 * #                  > Fixed for artifacts : [artf205559] [artf205886] [artf205966]
 * #                  :
 * # v4.040.03.001640 : NxpNfcRdLib_v4.040.03.001640_20161005
 * #                  : Linux support
 * # V4.040.02.001638 : NxpNfcRdLib_v4.040.02.001638_20160923
 * #				   : Release of Simplified API - EMVCo profile and beta code of ISO Profile.
 * #				   : Fixed for artifacts : artf193863 artf191954 artf199412
 * # v4.040.01.001637 : NxpNfcRdLib_v4.040.01.001637_20160916
 * # v4.040.00.001636 : NxpNfcRdLib_v4.040.00.001636_20160907
 * # v4.031.00.001631 : NxpNfcRdLib_v4.031.00.001631_SmplAPI_20160801
 * # v4.030.00.011627 : PN7462AU_04.03.01_20160706 / NxpNfcRdLib_v4.030.00.011627_20160706
 * # 06.4010.01.02    : Based on NFCRDLIB_V4.010.01.021604
 * # 06.4010.01.02    : Based on NFCRDLIB_V4.010.01.021604
 * # 06.4010.05.00    : Based on NFCRDLIB_V4.010.01.011604
 * # 06.4010.04.00    : Based on NFCRDLIB_V4.010.01.001603
 * # 06.4010.03.00    : Based on NxpRdLib_4.010.00.001601_ExC
 * #                  : Based on @r4100 - 2016.01.07 of
 * #                  :    /branch/NxpNfcRdLib_Branch_R_Gate_V4.010.00.001601
 * #                  :
 * # 06.4010.02.00    : Based on NxpRdLib_4.010.00.001551_ExC
 * # 06.4010.01.00    : Based on NfcRdLib_V_Gate_RC3_V4.010.01.001550
 * # 06.092.11.04     : Based on NfcRdLib_V_Gate_PN5180_V3.092.12.001547
 * #                  : +Fix for artf126517 Frame Delay Time Listen -> Poll is not
 * #                  : being changed based on the minimum TR2 value received in sensb
 * #                  : res
 * # 06.092.11.03     : PN7462AU_02_07_00_MRA2_20151113
 * # 06.092.11.00     : Based on NfcRdLib_V_Gate_RC3_V3.092.11.001546
 * # 06.092.11.00     : Based on branch/NfcRdLib_V_Gate_RC2_V3.092.11.001541 (V3.092.11.001545)
 * # 06.092.11.00     : Based on NfcRdLib_V_Gate_RC2_V3.092.11.001541_TempWk45
 * # 06.092.10.00     : Based on V3.092.10.001539 of NxpRdLib
 * # 06.092.07.01     : Corresponding to PN7462AU_02_06_00_MRA2_20150911 Drop
 * # 06.092.07.00     : Based on V3.092.07.001537 of NxpRdLib
 * # 06.092.05.00     : Based on v1.092.05.001534 of NxpRdLib
 * # 06.090.00.00     : Based on v1.092.00.001529 of NxpRdLib
 * # 06.080.06.00     : Based on v1.082.06.001528 of NxpRdLib
 * # 06.080.05.00     : Based on v1.082.05.001526 of NxpRdLib
 * # 06.080.04.00     : Based on v1.082.04.001524 of NxpRdLib
 * # 06.080.03.01     : Fixes for artifacts : artf631092, artf631750, artf631751
 * # 06.080.03.00     : Based on v1.082.03.001522 of NxpRdLib
 * # 06.080.01.00     : Based on V3.082.01.001518 of NxpRdLib
 * # 06.080.00.00     : Based on V3.082.00.001516 of NxpRdLib
 * # 06.010.04.00     : Release PN640FLASH_00_08_00_20150227 with NxpRdLib
 * # 06.010.03.00     : Updated with the fix of DUT Handling Mode and
 * #                    HIF Frame mode for compatibility between LPC and DUT.
 * # 06.010.02.02     : UHost::DUT_Switch Renamed to UHost_HIF_Switch
 * # 06.010.02.01     : HIF Related changes
 * # 06.010.02.00     : Corresponding to pn640Flash_00.03.00_DEV_20140905
 * # 06.010.01.02     : phhalHw_UHost_GetVersion returns 32bit Dev Value
 * # 06.010.01.01     : Corresponding to pn640Flash_00.02.01_CES_TST_20140904
 * # 06.010.01.00     : Corresponding to pn640Flash_00.02.00_Dev_20140808
 * # 06.010.00.00     : Migrated to UHost/DUT based NxpRdLib
 * # 06.000.01.00     : Initial Release
 * # _____________________________________________________________________________
 */


#ifdef __cplusplus
}
#endif
#endif /* NXPNFCRDLIB_VERSION_INFO_H_INCLUDED */
