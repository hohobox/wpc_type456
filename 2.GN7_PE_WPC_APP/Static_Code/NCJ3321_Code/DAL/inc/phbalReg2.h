/*******************************************************************************
 * (c) NXP Semiconductors Bangalore / India
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
 * INTELLECTUAL PROPERTY RIGHTS. NXP SHALL HAVE NO LIABILITY TO THE NXP CUS-TOMER, OR ITS
 * SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY FOR ANY DAMAGES, INCLUDING WITHOUT LIMITATION,
 * DAMAGES RESULTING OR ALLEGDED TO HAVE RESULTED FROM ANY DEFECT, ER-ROR OR OMMISSION IN THE NXP
 * SOFTWARE/SOURCE CODE, THIRD PARTY APPLICATION SOFTWARE AND/OR DOCUMENTATION, OR AS A RESULT OF ANY
 * INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHT OF ANY THIRD PARTY. IN NO EVENT SHALL NXP BE LIABLE
 * FOR ANY INCIDENTAL, INDIRECT, SPE-CIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL DAMAGES (INCLUDING
 * LOST PROFITS) SUFFERED BY NXP CUSTOMER OR ITS SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY
 * ARISING OUT OF OR RE-LATED TO THE NXP SOFTWARE/SOURCE CODE EVEN IF NXP HAS BEEN ADVISED OF THE
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
*   @file    phbalReg2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR BalReg - DAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phbalReg2 Bus Abstraction Layer (BAL)
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
#ifndef PHBALREG2_H
#define PHBALREG2_H

#ifdef __cplusplus
extern "C" {
#endif    /* __cplusplus */
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phbalReg2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHBALREG_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHBALREG_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHBALREG_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHBALREG_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHBALREG_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHBALREG_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHBALREG_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHBALREG_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHBALREG_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phbalReg2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHBALREG_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHBALREG_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHBALREG_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phbalReg2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHBALREG_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHBALREG_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHBALREG_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phbalReg2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/** \defgroup phbalReg2 Bus Abstraction Layer (BAL)
* \brief This component implements bus interface's drivers that are used for lower layer exchange of RdLib software modules.
* @{
*/

/**
* \name Generic BAL configuration parameters
*/
/*@{*/
#define PHBAL_REG_CONFIG_WRITE_TIMEOUT_MS2   0x0000U /**< Configure transmission timeout in milliseconds. */
#define PHBAL_REG_CONFIG_READ_TIMEOUT_MS2    0x0001U /**< Configure reception timeout in milliseconds. */
/*@}*/

/**
* \name BAL types
*/
/*@{*/
#define PHBAL_REG_TYPE_SPI2                  0x0001U /**< SPI communication channel. */
#define PHBAL_REG_TYPE_I2C2                  0x0002U /**< I2C communication channel. */
#define PHBAL_REG_TYPE_SERIAL_WIN2           0x0003U /**< SerialWin communication channel. */
#define PHBAL_REG_TYPE_KERNEL_SPI2           0x0004U /**< Linux kernel space SPI communication channel. */
#define PHBAL_REG_TYPE_USER_SPI2             0x0005U /**< Linux user space SPI communication channel. */
/*@}*/


/**
* \name BAL set/get config commands
*/
/*@{*/
#define PHBAL_KERNEL_SPI_IOCTL_MODE2			(0x0U)
/*@}*/


/**
* \name BAL set/get config values
*/
/*@{*/
#define PHBAL_KERNEL_SPI_MODE_NORMAL2		(0x0U)
#define PHBAL_KERNEL_SPI_MODE_DWL2  			(0x1U)
/*@}*/

/**
 * end of group phbalReg2 Bus Abstraction Layer (BAL)
 * @}
 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** \defgroup phbalReg2 Bus Abstraction Layer (BAL)
* \brief This component implements bus interface's drivers that are used for lower layer exchange of RdLib software modules.
* @{
*/

/**
* \brief BAL type structure
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId2;              /**< Layer ID for this BAL component, NEVER MODIFY! */
    VAR(uint8, ANFCRL_VAR) bBalType2;         /**< BAL type used by HAL to configure the BAL configured at runtime. */
} phbalReg_Type_t2;

/**
 * end of group phbalReg2 Bus Abstraction Layer (BAL)
 * @}
 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ANFCRL_START_SEC_CODE
#if ((PHBALREG_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHBALREG_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif


/** \defgroup phbalReg2 Bus Abstraction Layer (BAL)
* \brief This component implements bus interface's drivers that are used for lower layer exchange of RdLib software modules.
* @{
*/

/**
* \brief Initialize the BAL.
*
* \return Status code
* \retval #PH_DRIVER_SUCCESS2 Operation successful.
* \retval #PH_DRIVER_ERROR2   Parameter structure size is invalid.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_Init2(
		P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,    /**< [In] Pointer to this layer's parameter structure phbalReg_Type_t2. */
        VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2              /**< [In] Size of this layer's parameter structure. */
        );

/**
* \brief Perform data Transmit/Receive/Exchange on the bus. This API is used for command exchange between front-end CLIF
* and HOST.
* SPI : This API will also perform required flow control for particular front-end (Hardware specific).
*
* \return Status code
* \retval #PH_DRIVER_SUCCESS2 Operation successful.
* \retval #PH_DRIVER_ERROR2   \b wOption2 is invalid or Response is too big for either given receive buffer or internal buffer.
* \retval #PH_DRIVER_TIMEOUT2 No response received within given time frame.
* \retval #PH_DRIVER_FAILURE2 Communication error.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_Exchange2(
                             P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,    /**< [In] Pointer to this layer's parameter structure. */
                             VAR(uint16, ANFCRL_VAR) wOption2,      /**< [In] Option parameter, for future use. */
                             P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,   /**< [In] Data to transmit. */
                             VAR(uint16, ANFCRL_VAR) wTxLength2,    /**< [In] Number of bytes to transmit, if 0 Tx is not performed. */
                             VAR(uint16, ANFCRL_VAR) wRxBufSize2,   /**< [In] Size of receive buffer / Number of bytes to receive (depending on implementation). If 0 Rx is not performed.  */
                             P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,   /**< [Out] Received data. */
                             P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2   /**< [Out] Number of received data bytes. */
                             );

/**
* \brief Set configuration parameter.
* \return Status code
* \retval #PH_DRIVER_SUCCESS2 Operation successful.
* \retval #PH_DRIVER_ERROR2   Parameter/Configuration is not supported or invalid.
* \retval #PH_DRIVER_FAILURE2 Communication error.
*/

#ifndef AUTOSAR_VER
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_SetConfig2(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] Pointer to this layer's parameter structure. */
                              VAR(uint16, ANFCRL_VAR) wConfig2,     /**< [In] Configuration identifier, for future use. */
                              VAR(uint16, ANFCRL_VAR) wValue2       /**< [In] Configuration value. */
                              );
#endif /* AUTOSAR_VER */
/**
* \brief Get configuration parameter.
* \return Status code
* \retval #PH_DRIVER_SUCCESS2 Operation successful.
* \retval #PH_DRIVER_ERROR2 Configuration is not supported or invalid.
* \retval #PH_DRIVER_FAILURE2 Communication error.
*/
#ifndef AUTOSAR_VER
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_GetConfig2(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] Pointer to this layer's parameter structure. */
                              VAR(uint16, ANFCRL_VAR) wConfig2,     /**< [In] Configuration identifier, for future use. */
                              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2     /**< [Out] Configuration value. */
                              );
#endif /* AUTOSAR_VER */
/**
 * end of group phbalReg2 Bus Abstraction Layer (BAL)
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHBALREG_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHBALREG_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHBALREG2_H */
