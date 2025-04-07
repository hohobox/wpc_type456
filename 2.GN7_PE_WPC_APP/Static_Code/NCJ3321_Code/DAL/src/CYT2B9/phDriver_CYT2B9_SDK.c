/*******************************************************************************
 * (c) NXP Semiconductors Bangalore / India
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2018-2023
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

/* *****************************************************************************************************************
 * Includes
 * ***************************************************************************************************************** */
#include <phhalHw.h>
#include <phDriver.h>
#include <phDriver_Gpio.h>

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "App_NFC.h"

#else
#include <BoardSelection.h>

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K312)
/* 사용안함 */

#else
#include <device_registers.h>
#include <interrupt_manager.h>
#include <lptmr_driver.h>
#include <pins_driver.h>
#include <clock_manager.h>

#endif	/* NIDEC_PORTING */


/* *****************************************************************************************************************
 * Internal Definitions
 * ***************************************************************************************************************** */
#define PH_DRIVER_S32K_LPIT_CHANNEL_MASK	(1u << PH_DRIVER_S32K_LPIT_CHANNEL)
// #define PH_DRIVER_32BIT_TIMER_MAX_TIME		(S32K_TIMER_MAX_32BIT/(Clock_Ip_GetFreq(PIT0_CLK)/(1000000UL))) /* NIDEC_PORTING */
#ifndef PHDRIVER_S32K312
#define PH_DRIVER_TIMER_MAX_TIME            S32K_TIMER_MAX_32BIT
#else
#define PH_DRIVER_TIMER_MAX_TIME			(PH_DRIVER_32BIT_TIMER_MAX_TIME)
#endif
/* *****************************************************************************************************************
 * Type Definitions
 * ***************************************************************************************************************** */

/* *****************************************************************************************************************
 * Global and Static Variables
 * Total Size: NNNbytes
 * ***************************************************************************************************************** */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K312)
static VAR(pphDriver_TimerCallBck_t, ANFCRL_VAR) pGlTimerCallBack;

#else
static VAR(pphDriver_TimerCallBck_t, ANFCRL_VAR) pGlTimerCallBack_Temp;

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K312)
static VAR(uint16, ANFCRL_VAR) dwH16bitTick = 0u;

#else
static VAR(uint32, ANFCRL_VAR) dwH32bitTick = 0u;

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K312)

#else
#define MSEC_TO_TICK(msec) (msec)

#endif	/* NIDEC_PORTING */


static volatile VAR(uint8, ANFCRL_VAR) bTimerOverflowCounter = 0u;
static VAR(uint8, ANFCRL_VAR) bLastTimerOverflowCounter = 0u;
static VAR(uint8, ANFCRL_VAR) bTempTimerOverflowCounter = 0u;

/*	with 8Mhz PCC input, clock of LPTMR0 after prescaler is 1Mhz (1us)	*/
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K312)
/* 사용안함 */

#else
static VAR(lptmr_config_t, ANFCRL_VAR) slptmr0_config = {
	/* General parameters */
	.dmaRequest      = FALSE,
	.interruptEnable = TRUE,
	.freeRun         = FALSE,
	.workMode        = LPTMR_WORKMODE_TIMER,

	/* Counter parameters */
	.clockSelect     = LPTMR_CLOCKSOURCE_PCC,
	.prescaler       = LPTMR_PRESCALE_8_GLITCHFILTER_4,
	.bypassPrescaler = FALSE,
	.compareValue    = 0u,
	.counterUnits    = LPTMR_COUNTER_UNITS_TICKS,

	/* Pulse Counter specific parameters */
	.pinSelect       = LPTMR_PINSELECT_TRGMUX,
	.pinPolarity     = LPTMR_PINPOLARITY_RISING
};

#endif	/* NIDEC_PORTING */


/* *****************************************************************************************************************
 * Private Functions Prototypes
 * ***************************************************************************************************************** */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K312)
FUNC(void, ANFCRL_VAR) pGlTimerCallBack(VAR(uint8, ANFCRL_VAR) channel);
FUNC(void, ANFCRL_CODE) phDriver_H32bitInc(VAR(uint8, ANFCRL_VAR) chanel);

#else
FUNC(void, ANFCRL_VAR) LPTMR0_IRQHandler(void);
FUNC(void, ANFCRL_CODE) phDriver_H16bitInc(void);

#endif	/* NIDEC_PORTING */


/* *****************************************************************************************************************
 * Public Functions
 * ***************************************************************************************************************** */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(phStatus_t, ANFCRL_CODE) phDriver_TimerStart(VAR(phDriver_Timer_Unit_t, ANFCRL_VAR) eTimerUnit,
    VAR(uint32, ANFCRL_VAR) dwTimePeriod, VAR(pphDriver_TimerCallBck_t, ANFCRL_VAR) pTimerCallBack) {
  VAR(phStatus_t, ANFCRL_VAR) tmpStatus = PH_DRIVER_SUCCESS;

	UNUSED(eTimerUnit);
	UNUSED(dwTimePeriod);
	UNUSED(pTimerCallBack);

	return tmpStatus;
}

#elif defined (PHDRIVER_S32K312)
FUNC(phStatus_t, ANFCRL_CODE) phDriver_TimerStart(VAR(phDriver_Timer_Unit_t, ANFCRL_VAR) eTimerUnit,
    VAR(uint32, ANFCRL_VAR) dwTimePeriod, VAR(pphDriver_TimerCallBck_t, ANFCRL_VAR) pTimerCallBack) {
  VAR(phStatus_t, ANFCRL_VAR) tmpStatus = PH_DRIVER_SUCCESS;

	PH_CHECK_SUCCESS_FCT(tmpStatus,phDriver_TimerStop());

	if (pTimerCallBack == NULL) {
		pGlTimerCallBack_Temp = &phDriver_H32bitInc;
		(void)Pit_Ip_StartChannel(PIT_0_IP_INSTANCE_NUMBER,PIT_0_ChannelConfig_PB[0].hwChannel, S32K_TIMER_MAX_32BIT);
	}
	else
	{ 		/* One-Shot Mode */
		if(dwTimePeriod > (S32K_TIMER_MAX_32BIT/(uint32)eTimerUnit))
		{
			return PH_DRIVER_ERROR | PH_COMP_DRIVER;
		}
		else
		{
			(void)Pit_Ip_StartChannel(PIT_0_IP_INSTANCE_NUMBER,PIT_0_ChannelConfig_PB[0].hwChannel, dwTimePeriod*(uint32)eTimerUnit);
		}
		pGlTimerCallBack_Temp = pTimerCallBack;
	}

	return tmpStatus;
}

#else
FUNC(phStatus_t, ANFCRL_CODE) phDriver_TimerStart(VAR(phDriver_Timer_Unit_t, ANFCRL_VAR) eTimerUnit,
    VAR(uint32, ANFCRL_VAR) dwTimePeriod, VAR(pphDriver_TimerCallBck_t, ANFCRL_VAR) pTimerCallBack) {
  VAR(phStatus_t, ANFCRL_VAR) tmpStatus = PH_DRIVER_SUCCESS;

	dwH16bitTick = 0u;
	bTimerOverflowCounter = 0u;
	bLastTimerOverflowCounter = 0u;

	if (pTimerCallBack == NULL) {
		pGlTimerCallBack = &phDriver_H16bitInc;
		slptmr0_config.compareValue = 0xFFFFu;
		slptmr0_config.freeRun = FALSE;
	}
	else
	{
	    /* One-Shot Mode */
		if(dwTimePeriod > (0xFFFFU/(uint32)eTimerUnit)){
			return PH_DRIVER_ERROR | PH_COMP_DRIVER;
		}
		else
		{
			slptmr0_config.compareValue = dwTimePeriod*(uint32)eTimerUnit;
			slptmr0_config.freeRun = FALSE;
		}
		pGlTimerCallBack = pTimerCallBack;
	}
	PH_CHECK_SUCCESS_FCT(tmpStatus,phDriver_TimerStop());

	LPTMR_DRV_Init(0u, &slptmr0_config, TRUE);

	INT_SYS_EnableIRQ(LPTMR0_IRQn);

	return tmpStatus;
}
#endif	/* NIDEC_PORTING */


FUNC(phStatus_t, ANFCRL_CODE) phDriver_TimerStop(void) {

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	// platformSpiIRQ_Disable();

#elif defined (PHDRIVER_S32K312)
	dwH32bitTick = 0u;
	bTimerOverflowCounter = 0u;
	bLastTimerOverflowCounter = 0u;
	Pit_Ip_StopChannel(PIT_0_IP_INSTANCE_NUMBER,PIT_0_ChannelConfig_PB[0].hwChannel);

#else
	LPTMR_DRV_Deinit(0u);
	INT_SYS_DisableIRQ(LPTMR0_IRQn);

#endif	/* NIDEC_PORTING */
	return PH_DRIVER_SUCCESS;
}


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(phStatus_t, ANFCRL_CODE) phDriver_PinConfig(VAR(uint32, ANFCRL_VAR) dwPinNumber, VAR(phDriver_Pin_Func_t, ANFCRL_VAR) ePinFunc, P2VAR(phDriver_Pin_Config_t, AUTOMATIC, ANFCRL_APPL_DATA) pPinConfig)
{
	UNUSED(pPinConfig);

	if(dwPinNumber == PHDRIVER_PIN_IRQ)
	{
		if(ePinFunc == PH_DRIVER_PINFUNC_INTERRUPT)
		{
			// platformSpiIRQ_Enable();
		}
	}

	return PH_DRIVER_SUCCESS;
}

#elif defined (PHDRIVER_S32K312)
FUNC(phStatus_t, ANFCRL_CODE) phDriver_PinConfig(VAR(uint32, ANFCRL_VAR) dwPinNumber, VAR(phDriver_Pin_Func_t, ANFCRL_VAR) ePinFunc, P2VAR(phDriver_Pin_Config_t, AUTOMATIC, ANFCRL_APPL_DATA) pPinConfig)
{
	Siul2_Icu_Ip_EdgeType edgeVal = SIUL2_ICU_DISABLE;
  VAR(phStatus_t, ANFCRL_VAR) retVal = PH_DRIVER_FAILURE;
	UNUSED(dwPinNumber);

	if (PH_DRIVER_PINFUNC_BIDIR == ePinFunc)
	{
		retVal = PH_DRIVER_ERROR | PH_COMP_DRIVER;
	}
	else if ((PH_DRIVER_PINFUNC_OUTPUT == ePinFunc) || (PH_DRIVER_PINFUNC_INPUT == ePinFunc))
	{
		/* Status to ignore to config GPIO Pins */
		retVal = PH_DRIVER_SUCCESS;
	}
	else if (PH_DRIVER_PINFUNC_INTERRUPT == ePinFunc)
	{
		/* Set interrupt enable depends on which type of triggering */
		switch (pPinConfig->eInterruptConfig)
		{
			case PH_DRIVER_INTERRUPT_LEVELZERO:
			case PH_DRIVER_INTERRUPT_LEVELONE:
				break;
			case PH_DRIVER_INTERRUPT_RISINGEDGE:
				edgeVal = SIUL2_ICU_RISING_EDGE;
				break;
			case PH_DRIVER_INTERRUPT_FALLINGEDGE:
				edgeVal = SIUL2_ICU_FALLING_EDGE;
				break;
			case PH_DRIVER_INTERRUPT_EITHEREDGE:
				edgeVal = SIUL2_ICU_BOTH_EDGES;
				break;
			default:
				break;
		}
		if (SIUL2_ICU_DISABLE != edgeVal)
		{
		    /* Initialize the Icu driver */
		    (void)Siul2_Icu_Ip_Init(SIUL2_ICU_IP_INSTANCE, &Siul2_Icu_Ip_0_Config_PB_BOARD_InitPeripherals);
			Siul2_Icu_Ip_SetActivationCondition(SIUL2_ICU_IP_INSTANCE, Siul2_Icu_Ip_0_ChannelConfig_PB_BOARD_InitPeripherals[0].hwChannel, edgeVal);
			Siul2_Icu_Ip_EnableInterrupt(SIUL2_ICU_IP_INSTANCE, Siul2_Icu_Ip_0_ChannelConfig_PB_BOARD_InitPeripherals[0].hwChannel);
			Siul2_Icu_Ip_EnableNotification(SIUL2_ICU_IP_INSTANCE, Siul2_Icu_Ip_0_ChannelConfig_PB_BOARD_InitPeripherals[0].hwChannel);
			retVal = PH_DRIVER_SUCCESS;
		}
		else
		{
			/* Return value */
			retVal = PH_DRIVER_FAILURE;
		}
	}
	else
	{
		/* Do Nothing */
	}

	return retVal;
}

#else
FUNC(phStatus_t, ANFCRL_CODE) phDriver_PinConfig(VAR(uint32, ANFCRL_VAR) dwPinNumber,
    VAR(phDriver_Pin_Func_t, ANFCRL_VAR) ePinFunc, P2VAR(phDriver_Pin_Config_t, AUTOMATIC, ANFCRL_APPL_DATA) pPinConfig) {
  VAR(uint8, ANFCRL_VAR) bPinNum;
	PORT_Type * dwPortBaseAddress;
	GPIO_Type * dwGpioBaseAddress;
  VAR(uint32, ANFCRL_VAR) pinCount = 1;
  VAR(pin_settings_config_t, ANFCRL_VAR) config[1];

  VAR(pin_settings_config_t, ANFCRL_VAR) sPinConfig;
	sPinConfig.pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED;
	sPinConfig.passiveFilter = FALSE;
	sPinConfig.driveSelect = PORT_LOW_DRIVE_STRENGTH;
	sPinConfig.mux = PORT_MUX_AS_GPIO;
	sPinConfig.pinLock = FALSE;
	sPinConfig.intConfig = PORT_DMA_INT_DISABLED;
	sPinConfig.clearIntFlag = FALSE;
	sPinConfig.gpioBase = NULL;
	sPinConfig.digitalFilter = FALSE;

	if ((ePinFunc == PH_DRIVER_PINFUNC_BIDIR) || (pPinConfig == NULL)) {
		return PH_DRIVER_ERROR | PH_COMP_DRIVER;
	}

	/* Extract the Pin, GPIO, Port details from dwPinNumber */
	bPinNum = (uint8) ((dwPinNumber & 0xFF00000u) >> 20u);
	dwPortBaseAddress = (PORT_Type *) ((dwPinNumber & 0x000FF000u)
			| PORT_BASE_ADDR);
	dwGpioBaseAddress = (GPIO_Type *) ((dwPinNumber & 0x00000FFFu)
			| GPIO_BASE_ADDR);

	sPinConfig.base = dwPortBaseAddress;
	sPinConfig.pinPortIdx = bPinNum;
	if (PHDRIVER_PIN_SSEL == dwPinNumber) {
		sPinConfig.pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED;
	}
	else
	{
		sPinConfig.pullConfig =
				(pPinConfig->bPullSelect == PH_DRIVER_PULL_DOWN) ?
						PORT_INTERNAL_PULL_DOWN_ENABLED :
						PORT_INTERNAL_PULL_UP_ENABLED;
	}
	sPinConfig.gpioBase = dwGpioBaseAddress;
	sPinConfig.direction =
			(ePinFunc == PH_DRIVER_PINFUNC_OUTPUT) ?
					GPIO_OUTPUT_DIRECTION : GPIO_INPUT_DIRECTION;
	sPinConfig.initValue = pPinConfig->bOutputLogic;
	/* Configure for interrupt pin */
	if (ePinFunc == PH_DRIVER_PINFUNC_INTERRUPT) {
		/* Clear any pending interrupts before enabling interrupt */
		PINS_DRV_ClearPinIntFlagCmd(sPinConfig.base, bPinNum);
		/* Set interrupt enable depends on which type of triggering */
		switch (pPinConfig->eInterruptConfig) {
		case PH_DRIVER_INTERRUPT_LEVELZERO:
			sPinConfig.intConfig = PORT_INT_LOGIC_ZERO;
			break;
		case PH_DRIVER_INTERRUPT_LEVELONE:
			sPinConfig.intConfig = PORT_INT_LOGIC_ONE;
			break;
		case PH_DRIVER_INTERRUPT_RISINGEDGE:
			sPinConfig.intConfig = PORT_INT_RISING_EDGE;
			break;
		case PH_DRIVER_INTERRUPT_FALLINGEDGE:
			sPinConfig.intConfig = PORT_INT_FALLING_EDGE;
			break;
		case PH_DRIVER_INTERRUPT_EITHEREDGE:
			sPinConfig.intConfig = PORT_INT_EITHER_EDGE;
			break;
		default:
			break;
		}
	}
	config[0] = sPinConfig;
	(void) PINS_DRV_Init(pinCount, config);

	return PH_DRIVER_SUCCESS;
}

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(uint8, ANFCRL_CODE) phDriver_PinRead(VAR(uint32, ANFCRL_VAR) dwPinNumber, VAR(phDriver_Pin_Func_t, ANFCRL_VAR) ePinFunc) {
  VAR(uint8, ANFCRL_VAR) bValue = 0u;

	if(dwPinNumber == PHDRIVER_PIN_IRQ)
	{
		// CLIF_IRQHandler() 함수를 사용하지 않기 때문에
		// INPUT || INTERRUPT로 읽는 경우 Read 값 return하도록 조치 함.
		// PH_DRIVER_PINFUNC_INTERRUPT는 확인을 안해도 될 것 같긴 한데 일단 추가 해 놓음
//		if(ePinFunc == PH_DRIVER_PINFUNC_INPUT)
		if((ePinFunc == PH_DRIVER_PINFUNC_INPUT) || (ePinFunc == PH_DRIVER_PINFUNC_INTERRUPT))
		{
			bValue = platformSpiIRQ_ReadDirect();
		}
	}

	return bValue;
}

#elif defined (PHDRIVER_S32K312)
FUNC(uint8, ANFCRL_CODE) phDriver_PinRead(VAR(uint32, ANFCRL_VAR) dwPinNumber, VAR(phDriver_Pin_Func_t, ANFCRL_VAR) ePinFunc) {
  VAR(uint8, ANFCRL_VAR) bValue = 1u;
	Siul2_Dio_Ip_GpioType * dwGpioBaseAddress;
	Siul2_Dio_Ip_PinsChannelType bPinNum;
	/* Extract the Pin, Gpio details from dwPinNumber */
	bPinNum = (uint8) ((dwPinNumber & 0xFF00000u) >> 20u);
	dwGpioBaseAddress = (Siul2_Dio_Ip_GpioType *) ((dwPinNumber & 0x0000FFFFu)
			| GPIO_BASE_ADDR);

	if (PH_DRIVER_PINFUNC_INTERRUPT != ePinFunc)
	{
		bValue = (uint8)(Siul2_Dio_Ip_ReadPin(dwGpioBaseAddress, bPinNum));
	}

	return bValue;
}

#else
FUNC(uint8, ANFCRL_CODE) phDriver_PinRead(VAR(uint32, ANFCRL_VAR) dwPinNumber, VAR(phDriver_Pin_Func_t, ANFCRL_VAR) ePinFunc) {
  VAR(uint8, ANFCRL_VAR) bValue;
  VAR(uint8, ANFCRL_VAR) bPinNum;
	PORT_Type * dwPortBaseAddress;
	GPIO_Type * dwGpioBaseAddress;
	/* Extract the Pin, Gpio details from dwPinNumber */
	bPinNum = (uint8) ((dwPinNumber & 0xFF00000u) >> 20u);
	dwGpioBaseAddress = (GPIO_Type *) ((dwPinNumber & 0x00000FFFu)
			| GPIO_BASE_ADDR);
	dwPortBaseAddress = (PORT_Type *) ((dwPinNumber & 0x000FF000u)
			| PORT_BASE_ADDR);
	if (ePinFunc == PH_DRIVER_PINFUNC_INTERRUPT) {
		bValue = (uint8) ((PINS_DRV_GetPortIntFlag(dwPortBaseAddress)
				>> bPinNum) & 0x01u);
	}
	else
	{
		bValue = (uint8) ((PINS_DRV_ReadPins(dwGpioBaseAddress) >> bPinNum)
				& 0x01u);
	}

	return bValue;
}


#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(void, ANFCRL_CODE) phDriver_PinWrite(VAR(uint32, ANFCRL_VAR) dwPinNumber, VAR(uint8, ANFCRL_VAR) bValue) {
  VAR(uint8, ANFCRL_VAR) bPinNum;

	if(dwPinNumber == PHDRIVER_PIN_RESET)
	{
		if((bValue == RESET_POWERDOWN_LEVEL) || (bValue == RESET_POWERUP_LEVEL))
		{
			platformSpiWAKEUP_WriteDirect(bValue);
		}
	}
}
#elif defined (PHDRIVER_S32K312)
FUNC(void, ANFCRL_CODE) phDriver_PinWrite(VAR(uint32, ANFCRL_VAR) dwPinNumber, VAR(uint8, ANFCRL_VAR) bValue) {
	Siul2_Dio_Ip_GpioType * dwGpioBaseAddress;
	Siul2_Dio_Ip_PinsChannelType bPinNum;
	/* Extract the Pin, Gpio details from dwPinNumber */
	bPinNum = (uint8) ((dwPinNumber & 0xFF00000u) >> 20u);
	dwGpioBaseAddress = (Siul2_Dio_Ip_GpioType *) ((dwPinNumber & 0x0000FFFFu)
			| GPIO_BASE_ADDR);

	Siul2_Dio_Ip_WritePin(dwGpioBaseAddress, bPinNum, bValue);
}

#else
FUNC(void, ANFCRL_CODE) phDriver_PinWrite(VAR(uint32, ANFCRL_VAR) dwPinNumber, VAR(uint8, ANFCRL_VAR) bValue) {
  VAR(uint8, ANFCRL_VAR) bPinNum;
	GPIO_Type * dwGpioBaseAddress;

	/* Extract the Pin, Gpio details from dwPinNumber */
	bPinNum = (uint8) ((dwPinNumber & 0xFF00000u) >> 20u);
	dwGpioBaseAddress = (GPIO_Type *) ((dwPinNumber & 0x00000FFFu)
			| GPIO_BASE_ADDR);

	PINS_DRV_WritePin(dwGpioBaseAddress, (pins_channel_type_t) bPinNum,
			(pins_level_type_t) bValue);
}

#endif	/* NIDEC_PORTING */


FUNC(void, ANFCRL_CODE) phDriver_PinClearIntStatus(VAR(uint32, ANFCRL_VAR) dwPinNumber) {

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	UNUSED(dwPinNumber);
/* 사용안함 */

#elif defined (PHDRIVER_S32K312)
	UNUSED(dwPinNumber);

#else
  VAR(uint8, ANFCRL_VAR) bPinNum;
	PORT_Type * dwPortBaseAddress;

	/* Extract the Pin, Gpio details from dwPinNumber */
	bPinNum = (uint8) ((dwPinNumber & 0xFF00000u) >> 20u);
	dwPortBaseAddress = (PORT_Type *) ((dwPinNumber & 0x000FF000u)
			| PORT_BASE_ADDR);

	PINS_DRV_ClearPinIntFlagCmd(dwPortBaseAddress, bPinNum);

#endif	/* NIDEC_PORTING */
}


FUNC(uint32, ANFCRL_CODE) phDriver_GetTimeElapsed(
VAR(phDriver_Timer_Unit_t, ANFCRL_VAR) eTimerUnit,VAR(uint32, ANFCRL_VAR) dwStartTime)
{
    VAR(uint32, ANFCRL_VAR) wTimeCurrent = 0U;
    VAR(uint32, ANFCRL_VAR) wElapsedTime = 0U;
    VAR(uint64, ANFCRL_VAR) dwTemp = 0U;

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

    return wElapsedTime;

#elif defined (PHDRIVER_S32K312)
    VAR(uint32, ANFCRL_VAR) frequency = 0U;
    frequency = Clock_Ip_GetFreq(PIT0_CLK)/(1000000UL);
    wTimeCurrent = ((S32K_TIMER_MAX_32BIT - (uint32)Pit_Ip_GetCurrentTimer(PIT_0_IP_INSTANCE_NUMBER,PIT_0_ChannelConfig_PB[0].hwChannel))/frequency)/(uint32)eTimerUnit;

    if (bLastTimerOverflowCounter != bTempTimerOverflowCounter)
    {
        /* Record total overflow time and add to wElapsedTime when timer overflow happens */
        if (bLastTimerOverflowCounter < bTempTimerOverflowCounter)
        {
            dwTemp = ((uint64) bTempTimerOverflowCounter - bLastTimerOverflowCounter)
                    * PH_DRIVER_TIMER_MAX_TIME;
        }
        else
        {
            dwTemp = ((uint64) OVERFLOW_MAX_COUNT - bLastTimerOverflowCounter
                    + bTempTimerOverflowCounter) * PH_DRIVER_TIMER_MAX_TIME;
        }

        /* Calculate elapsed time value and make sure it does not exceed the return type size */
        dwTemp = (dwTemp / (uint64) eTimerUnit)
                + ((uint64) wTimeCurrent - (uint64) dwStartTime);

        if (S32K_TIMER_MAX_32BIT <= dwTemp)
        {
            return S32K_TIMER_MAX_32BIT;
        }
        else
        {
        	wElapsedTime = (uint32) dwTemp;
        }
    }
    else
    {
        wElapsedTime = wTimeCurrent - dwStartTime;
    }

    return wElapsedTime;

#else
    VAR(uint32, ANFCRL_VAR) wValueByCount = 0U;
    VAR(uint16, ANFCRL_VAR) w16bitTickCurrent = 0U;
    /* In case value received from function LPTMR_DRV_GetCounterValueByCount gets overflowed,
     * and LPTMR0_IRQHandler does not synchronize with LPTMR_DRV_GetCounterValueByCount,
     * use local variable to make sure the calculation is correct. */
    w16bitTickCurrent = dwH16bitTick;
    wValueByCount = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
    bTempTimerOverflowCounter = bTimerOverflowCounter;

    /*In case the timer overflow happens during setting value for temporary variables,
     * the compatibility of temporary variables should be maintained.*/
    if (w16bitTickCurrent != dwH16bitTick)
    {
        w16bitTickCurrent = dwH16bitTick;
        wValueByCount = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
        bTempTimerOverflowCounter = bTimerOverflowCounter;
    }
    else if (wValueByCount
            > (uint32) LPTMR_DRV_GetCounterValueByCount(0u))
    {
        w16bitTickCurrent = dwH16bitTick;
        wValueByCount = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
        bTempTimerOverflowCounter = bTimerOverflowCounter;
    }
    else
    {
        /*Do nothing*/
    }
    /* In case value received from function LPTMR_DRV_GetCounterValueByCount has overflowed
     * but timer interrupt was too slow to update timer overflow counter,
     * bTempTimerOverflowCounter will be updated to make sure the calculation is correct. */
    if ((wValueByCount > (uint32) LPTMR_DRV_GetCounterValueByCount(0u))
            && (w16bitTickCurrent == dwH16bitTick))
    {
        if (w16bitTickCurrent == S32K_TIMER_MAX_16BIT)
        {
            bTempTimerOverflowCounter++;
            w16bitTickCurrent = 0u;
        }
        else
        {
            w16bitTickCurrent++;
        }
    }
    wTimeCurrent = (wValueByCount | ((uint32) w16bitTickCurrent << 16u))
            / (uint32) eTimerUnit;

    if (bLastTimerOverflowCounter != bTempTimerOverflowCounter)
    {
        /* Record total overflow time and add to wElapsedTime when timer overflow happens */
        if (bLastTimerOverflowCounter < bTempTimerOverflowCounter)
        {
            dwTemp = ((uint64) bTempTimerOverflowCounter - bLastTimerOverflowCounter)
                    * PH_DRIVER_TIMER_MAX_TIME;
        }
        else
        {
            dwTemp = ((uint64) OVERFLOW_MAX_COUNT - bLastTimerOverflowCounter
                    + bTempTimerOverflowCounter) * PH_DRIVER_TIMER_MAX_TIME;
        }

        /* Calculate elapsed time value and make sure it does not exceed the return type size */
        dwTemp = (dwTemp / (uint64) eTimerUnit)
                + ((uint64) wTimeCurrent - (uint64) dwStartTime);

        if (S32K_TIMER_MAX_32BIT <= dwTemp)
        {
            return S32K_TIMER_MAX_32BIT;
        }
        else
        {
        	wElapsedTime = (uint32) dwTemp;
        }
    }
    else
    {
        wElapsedTime = wTimeCurrent - dwStartTime;
    }

    return wElapsedTime;

#endif	 /* NIDEC_PORTING */
}

FUNC(uint32, ANFCRL_CODE) phDriver_GetTimeCurrent(
VAR(phDriver_Timer_Unit_t, ANFCRL_VAR) eTimerUnit)
{
    VAR(uint32, ANFCRL_VAR) wTimeCurrent = 0U;

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	UNUSED(eTimerUnit);

    return wTimeCurrent;

#elif defined (PHDRIVER_S32K312)
    VAR(uint32, ANFCRL_VAR) frequency = 0U;
    frequency = Clock_Ip_GetFreq(PIT0_CLK)/(1000000UL);
    wTimeCurrent = ((S32K_TIMER_MAX_32BIT - (uint32)Pit_Ip_GetCurrentTimer(PIT_0_IP_INSTANCE_NUMBER,PIT_0_ChannelConfig_PB[0].hwChannel))/frequency)/(uint32)eTimerUnit;
    bLastTimerOverflowCounter = bTimerOverflowCounter;
    return wTimeCurrent;

#else
    /* In case the value received from function LPTMR_DRV_GetCounterValueByCount gets overflowed,
     * and LPTMR0_IRQHandler does not synchronize with LPTMR_DRV_GetCounterValueByCount,
     * use local variables to make sure the calculation is correct. */
    uint16_t w16bitTickCurrent = 0U;
    w16bitTickCurrent = dwH16bitTick;
    wTimeCurrent = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
    bLastTimerOverflowCounter = bTimerOverflowCounter;

    /*In case the timer overflow happens during setting value for temporary variables,
     * the compatibility of temporary variables should be maintained.*/
    if (w16bitTickCurrent != dwH16bitTick)
    {
        w16bitTickCurrent = dwH16bitTick;
        wTimeCurrent = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
        bLastTimerOverflowCounter = bTimerOverflowCounter;
    }
    else if (wTimeCurrent > (uint32) LPTMR_DRV_GetCounterValueByCount(0u))
    {
        w16bitTickCurrent = dwH16bitTick;
        wTimeCurrent = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
        bLastTimerOverflowCounter = bTimerOverflowCounter;
    }
    else
    {
        /*Do nothing*/
    }

    wTimeCurrent = (wTimeCurrent | ((uint32) w16bitTickCurrent << 16u)) / (uint32) eTimerUnit;

    return wTimeCurrent;

#endif	/* NIDEC_PORTING */

}

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K312)
FUNC(void, ANFCRL_CODE) phDriver_H32bitInc(VAR(uint8, ANFCRL_VAR) chanel){
	UNUSED(chanel);
	if(dwH32bitTick == S32K_TIMER_MAX_32BIT)
	{
		bTimerOverflowCounter++;
		dwH32bitTick = 0u;
	}
	else
	{
		dwH32bitTick++;
	}
}
FUNC(void, ANFCRL_VAR) pGlTimerCallBack(VAR(uint8, ANFCRL_VAR) channel){
	pGlTimerCallBack_Temp(channel);
}

#else
FUNC(void, ANFCRL_VAR) LPTMR0_IRQHandler(void){
	pGlTimerCallBack();
	LPTMR_DRV_ClearCompareFlag(0u);
}
FUNC(void, ANFCRL_CODE) phDriver_H16bitInc(void)
{
    if (dwH16bitTick == S32K_TIMER_MAX_16BIT)
    {
        bTimerOverflowCounter++;
        dwH16bitTick = 0u;
    }
    else
    {
        dwH16bitTick++;
    }
}

#endif
