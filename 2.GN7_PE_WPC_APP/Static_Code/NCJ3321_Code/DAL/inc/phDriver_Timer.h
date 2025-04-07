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
*   @file    phDriver_Timer.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Driver_Timer - DAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phDriver Driver Abstraction Layer (DAL)
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
#ifndef PHDRIVER_TIMER_H
#define PHDRIVER_TIMER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#ifndef AUTOSAR_VER
// #include <BoardSelection.h>   /* NIDEC_PORTING */
#endif /* AUTOSAR_VER */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phDriver_Timer.h
* @implements     DESIGN001, DESIGN002
*/
#define PHDRIVER_TIMER_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHDRIVER_TIMER_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHDRIVER_TIMER_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHDRIVER_TIMER_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHDRIVER_TIMER_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHDRIVER_TIMER_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHDRIVER_TIMER_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHDRIVER_TIMER_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHDRIVER_TIMER_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phDriver_Timer.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHDRIVER_TIMER_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHDRIVER_TIMER_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHDRIVER_TIMER_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phDriver_Timer.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHDRIVER_TIMER_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHDRIVER_TIMER_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHDRIVER_TIMER_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phDriver_Timer.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define OVERFLOW_MAX_COUNT				(256U)
#define S32K_TIMER_MAX_16BIT            (0xFFFFU)
#define S32K_TIMER_MAX_32BIT            (0xFFFFFFFFU)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/** \defgroup phDriver Driver Abstraction Layer (DAL)
*
* \brief This component implements hardware drivers that are necessary for RdLib software modules
* @{
*/

/**
* \brief Timer units.
*/
#ifndef AUTOSAR_VER
typedef enum{
    PH_DRIVER_TIMER_USECS	= 1u,       /**< Microseconds timer. */
	PH_DRIVER_TIMER_MSECS	= 1000u,	/**<  Miliseconds timer. */
} phDriver_Timer_Unit_t;
#else
typedef enum{
	PH_DRIVER_TIMER_MSECS = 1000u,          /**< Milliseconds timer. */
	PH_DRIVER_TIMER_USECS = 1000000u        /**< Microseconds timer. */
} phDriver_Timer_Unit_t;
#endif

/**
 * end of group phDriver Driver Abstraction Layer (DAL)
 * @}
 */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** \defgroup phDriver Driver Abstraction Layer (DAL)
*
* \brief This component implements hardware drivers that are necessary for RdLib software modules
* @{
*/

/**
*
* \brief Timer callback interface which will be called when timer expires.
* \retval  None
*/
#ifndef PHDRIVER_S32K312
typedef void (*pphDriver_TimerCallBck_t) (void);
#else
typedef void (*pphDriver_TimerCallBck_t)(VAR(uint8, ANFCRL_VAR) chanel);
#endif

/**
 * end of group phDriver Driver Abstraction Layer (DAL)
 * @}
 */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ANFCRL_START_SEC_CODE
#if ((PHDRIVER_TIMER_AR_RELEASE_MAJOR_VERSION == 4) && (PHDRIVER_TIMER_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \defgroup phDriver Driver Abstraction Layer (DAL)
*
* \brief This component implements hardware drivers that are necessary for RdLib software modules
* @{
*/

/********************************************************************************
 * TIMER API's
 *******************************************************************************/

/**
 * \brief      phDriver_TimerOverflowCount - Notification function called from Gpt driver
 * \details    This notification function is called by Gpt driver after the timer expire.
 *
 * @return     none
 * @retval     none
 */
#ifdef AUTOSAR_VER
FUNC(void, SAMPLE_APP_CODE) phDriver_TimerOverflowCount(void);
#endif

/**
 * \brief Creates and triggers a single shot Timer for the specified time.
 *
 * @param[in] eTimerUnit      Represents timer unit i.e. ticks or microseconds..
 * @param[in] dwTimePeriod    Timer Timeout in units
 * @param[in] pTimerCallBack  Timer callback function in case of timeout. If pTimerCallBack is NULL then phDriver_TimerStart
 *                            will be a blocking call and will return upon Timer Timeout.
 *
 * @return Status of the API
 * @retval #PH_DRIVER_SUCCESS Operation successful.
 */
#ifndef AUTOSAR_VER
FUNC(phStatus_t, ANFCRL_CODE) phDriver_TimerStart(VAR(phDriver_Timer_Unit_t, ANFCRL_VAR) eTimerUnit, VAR(uint32, ANFCRL_VAR) dwTimePeriod, VAR(pphDriver_TimerCallBck_t, ANFCRL_VAR) pTimerCallBack);
#else
FUNC(phStatus_t,ANFCRL_API) phDriver_TimerStart(VAR(uint8_t,ANFCRL_VAR) bChannel, VAR(uint32_t,ANFCRL_VAR) dwTick);
#endif

/**
 * \brief Stops the running Timer.
 *
 * @return Status of the API
 * @retval #PH_DRIVER_SUCCESS Operation successful.
 */
#ifndef AUTOSAR_VER
FUNC(phStatus_t, ANFCRL_CODE) phDriver_TimerStop(void);
#else
FUNC(phStatus_t,ANFCRL_API) phDriver_TimerStop(VAR(uint8_t,ANFCRL_VAR) bChannel);
#endif

/**
 * \brief Get period time that elapsed from phDriver_TimerStart was called.\n
 *
 * Note: Timer overflow is handled inside this function.\n
 *
 * Example of recommended usage:\n
 *
 * start_time = phDriver_GetTimeCurrent()\n
 * elapsed_time = phDriver_GetTimeElapsed(start_time) -> Timer overflow is handled inside phDriver_GetTimeElapsed function\n
 * 
 * In case the elapsed time value exceeds the return type size (uint32), 
 * this function will return S32K_TIMER_MAX_32BIT (0xFFFFFFFF) value.
 *
 * @param[in] eTimerUnit      Represents timer unit i.e. milliseconds or microseconds..
 * @param[in] dwStartTime     Elapsed Time will be calculate from this point to the current time when call this function
 *
 * @return Elapsed Time
 * @retval uint32
 */

FUNC(uint32, ANFCRL_CODE) phDriver_GetTimeElapsed(VAR(phDriver_Timer_Unit_t, ANFCRL_VAR) eTimerUnit, VAR(uint32, ANFCRL_VAR) dwStartTime);

/**
 * \brief Get the Current Time of the timer at the time this function was called.\n
 *
 * Note: Using this function to get period time that elapsed between two time points may
 * lead to unexpected behavior when timer becomes overflow.\n
 *
 * Example of not recommended usage:\n
 *
 * start_time = phDriver_GetTimeCurrent()\n
 * end_time = phDriver_GetTimeCurrent()\n
 * elapsed_time = end_time - start_time -> Unexpected behavior when timer becomes overflow\n
 *
 * @param[in] eTimerUnit      Represents timer unit i.e. milliseconds or microseconds..
 *
 * @return Remaining Time
 * @retval uint32
 */

FUNC(uint32, ANFCRL_CODE) phDriver_GetTimeCurrent(VAR(phDriver_Timer_Unit_t, ANFCRL_VAR) eTimerUnit);

/**
 * end of group phDriver Driver Abstraction Layer (DAL)
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHDRIVER_TIMER_AR_RELEASE_MAJOR_VERSION == 4) && (PHDRIVER_TIMER_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHDRIVER_TIMER_H */
