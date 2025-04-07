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
#include <phhalHw2.h>
#include <phDriver2.h>
#include <phDriver_Gpio2.h>

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "App_NFC.h"

#else
#include <BoardSelection2.h>

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* ������ */

#elif defined (PHDRIVER_S32K3122)
/* ������ */

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
#define PH_DRIVER_S32K_LPIT_CHANNEL_MASK2	(1u << PH_DRIVER_S32K_LPIT_CHANNEL2)
// #define PH_DRIVER_32BIT_TIMER_MAX_TIME2		(S32K_TIMER_MAX_32BIT2/(Clock_Ip_GetFreq(PIT0_CLK)/(1000000UL)))	/* NIDEC_PORTING */
#ifndef PHDRIVER_S32K3122
#define PH_DRIVER_TIMER_MAX_TIME2            S32K_TIMER_MAX_32BIT2
#else
#define PH_DRIVER_TIMER_MAX_TIME2			(PH_DRIVER_32BIT_TIMER_MAX_TIME2)
#endif
/* *****************************************************************************************************************
 * Type Definitions
 * ***************************************************************************************************************** */

/* *****************************************************************************************************************
 * Global and Static Variables
 * Total Size: NNNbytes
 * ***************************************************************************************************************** */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* ������ */

#elif defined (PHDRIVER_S32K3122)
static VAR(pphDriver_TimerCallBck_t2, ANFCRL_VAR) pGlTimerCallBack2;

#else
static VAR(pphDriver_TimerCallBck_t2, ANFCRL_VAR) pGlTimerCallBack_Temp2;

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* ������ */

#elif defined (PHDRIVER_S32K3122)
static VAR(uint16, ANFCRL_VAR) dwH16bitTick2 = 0u;

#else
static VAR(uint32, ANFCRL_VAR) dwH32bitTick2 = 0u;

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* ������ */

#elif defined (PHDRIVER_S32K3122)

#else
#define MSEC_TO_TICK2(msec2) (msec2)

#endif	/* NIDEC_PORTING */


static volatile VAR(uint8, ANFCRL_VAR) bTimerOverflowCounter2 = 0u;
static VAR(uint8, ANFCRL_VAR) bLastTimerOverflowCounter2 = 0u;
static VAR(uint8, ANFCRL_VAR) bTempTimerOverflowCounter2 = 0u;

/*	with 8Mhz PCC input, clock of LPTMR0 after prescaler is 1Mhz (1us)	*/
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* ������ */

#elif defined (PHDRIVER_S32K3122)
/* ������ */

#else
static VAR(lptmr_config_t, ANFCRL_VAR) slptmr0_config2 = {
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
/* ������ */

#elif defined (PHDRIVER_S32K3122)
FUNC(void, ANFCRL_VAR) pGlTimerCallBack2(VAR(uint8, ANFCRL_VAR) channel2);
FUNC(void, ANFCRL_CODE) phDriver_H32bitInc2(VAR(uint8, ANFCRL_VAR) chanel2);

#else
FUNC(void, ANFCRL_VAR) LPTMR0_IRQHandler2(void);
FUNC(void, ANFCRL_CODE) phDriver_H16bitInc2(void);

#endif	/* NIDEC_PORTING */


/* *****************************************************************************************************************
 * Public Functions
 * ***************************************************************************************************************** */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(phStatus_t2, ANFCRL_CODE) phDriver_TimerStart2(VAR(phDriver_Timer_Unit_t2, ANFCRL_VAR) eTimerUnit2,
    VAR(uint32, ANFCRL_VAR) dwTimePeriod2, VAR(pphDriver_TimerCallBck_t2, ANFCRL_VAR) pTimerCallBack2) {
  VAR(phStatus_t2, ANFCRL_VAR) tmpStatus2 = PH_DRIVER_SUCCESS2;

	UNUSED2(eTimerUnit2);
	UNUSED2(dwTimePeriod2);
	UNUSED2(pTimerCallBack2);

	return tmpStatus2;
}

#elif defined (PHDRIVER_S32K3122)
FUNC(phStatus_t2, ANFCRL_CODE) phDriver_TimerStart2(VAR(phDriver_Timer_Unit_t2, ANFCRL_VAR) eTimerUnit2,
    VAR(uint32, ANFCRL_VAR) dwTimePeriod2, VAR(pphDriver_TimerCallBck_t2, ANFCRL_VAR) pTimerCallBack2) {
  VAR(phStatus_t2, ANFCRL_VAR) tmpStatus2 = PH_DRIVER_SUCCESS2;

	PH_CHECK_SUCCESS_FCT(tmpStatus2,phDriver_TimerStop2());

	if (pTimerCallBack2 == NULL) {
		pGlTimerCallBack_Temp2 = &phDriver_H32bitInc2;
		(void)Pit_Ip_StartChannel(PIT_0_IP_INSTANCE_NUMBER,PIT_0_ChannelConfig_PB[0].hwChannel, S32K_TIMER_MAX_32BIT2);
	}
	else
	{ 		/* One-Shot Mode */
		if(dwTimePeriod2 > (S32K_TIMER_MAX_32BIT2/(uint32)eTimerUnit2))
		{
			return PH_DRIVER_ERROR2 | PH_COMP_DRIVER2;
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
FUNC(phStatus_t2, ANFCRL_CODE) phDriver_TimerStart2(VAR(phDriver_Timer_Unit_t2, ANFCRL_VAR) eTimerUnit2,
    VAR(uint32, ANFCRL_VAR) dwTimePeriod2, VAR(pphDriver_TimerCallBck_t2, ANFCRL_VAR) pTimerCallBack2) {
  VAR(phStatus_t2, ANFCRL_VAR) tmpStatus2 = PH_DRIVER_SUCCESS2;

	dwH16bitTick2 = 0u;
	bTimerOverflowCounter2 = 0u;
	bLastTimerOverflowCounter2 = 0u;

	if (pTimerCallBack2 == NULL) {
		pGlTimerCallBack2 = &phDriver_H16bitInc2;
		slptmr0_config2.compareValue = 0xFFFFu;
		slptmr0_config2.freeRun = FALSE;
	}
	else
	{
	    /* One-Shot Mode */
		if(dwTimePeriod2 > (0xFFFFU/(uint32)eTimerUnit2)){
			return PH_DRIVER_ERROR2 | PH_COMP_DRIVER2;
		}
		else
		{
			slptmr0_config2.compareValue = dwTimePeriod2*(uint32)eTimerUnit2;
			slptmr0_config2.freeRun = FALSE;
		}
		pGlTimerCallBack2 = pTimerCallBack2;
	}
	PH_CHECK_SUCCESS_FCT2(tmpStatus2,phDriver_TimerStop2());

	LPTMR_DRV_Init(0u, &slptmr0_config2, TRUE);

	INT_SYS_EnableIRQ(LPTMR0_IRQn);

	return tmpStatus2;
}
#endif	/* NIDEC_PORTING */


FUNC(phStatus_t2, ANFCRL_CODE) phDriver_TimerStop2(void) {

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	// platformSpiIRQ_Disable();

#elif defined (PHDRIVER_S32K3122)
	dwH32bitTick2 = 0u;
	bTimerOverflowCounter2 = 0u;
	bLastTimerOverflowCounter2 = 0u;
	Pit_Ip_StopChannel(PIT_0_IP_INSTANCE_NUMBER,PIT_0_ChannelConfig_PB[0].hwChannel);

#else
	LPTMR_DRV_Deinit(0u);
	INT_SYS_DisableIRQ(LPTMR0_IRQn);

#endif	/* NIDEC_PORTING */
	return PH_DRIVER_SUCCESS2;
}


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(phStatus_t2, ANFCRL_CODE) phDriver_PinConfig2(VAR(uint32, ANFCRL_VAR) dwPinNumber2, VAR(phDriver_Pin_Func_t2, ANFCRL_VAR) ePinFunc2, P2VAR(phDriver_Pin_Config_t2, AUTOMATIC, ANFCRL_APPL_DATA) pPinConfig2)
{
	UNUSED2(pPinConfig2);

	if(dwPinNumber2 == PHDRIVER_PIN_IRQ)
	{
		if(ePinFunc2 == PH_DRIVER_PINFUNC_INTERRUPT2)
		{
			// platformSpiIRQ_Enable2();
		}
	}

	return PH_DRIVER_SUCCESS2;
}

#elif defined (PHDRIVER_S32K3122)
FUNC(phStatus_t2, ANFCRL_CODE) phDriver_PinConfig2(VAR(uint32, ANFCRL_VAR) dwPinNumber2, VAR(phDriver_Pin_Func_t2, ANFCRL_VAR) ePinFunc2, P2VAR(phDriver_Pin_Config_t2, AUTOMATIC, ANFCRL_APPL_DATA) pPinConfig2)
{
	Siul2_Icu_Ip_EdgeType edgeVal2 = SIUL2_ICU_DISABLE;
  VAR(phStatus_t2, ANFCRL_VAR) retVal2 = PH_DRIVER_FAILURE2;
	UNUSED2(dwPinNumber2);

	if (PH_DRIVER_PINFUNC_BIDIR2 == ePinFunc2)
	{
		retVal2 = PH_DRIVER_ERROR2 | PH_COMP_DRIVER2;
	}
	else if ((PH_DRIVER_PINFUNC_OUTPUT2 == ePinFunc2) || (PH_DRIVER_PINFUNC_INPUT2 == ePinFunc2))
	{
		/* Status to ignore to config GPIO Pins */
		retVal2 = PH_DRIVER_SUCCESS2;
	}
	else if (PH_DRIVER_PINFUNC_INTERRUPT2 == ePinFunc2)
	{
		/* Set interrupt enable depends on which type of triggering */
		switch (pPinConfig2->eInterruptConfig2)
		{
			case PH_DRIVER_INTERRUPT_LEVELZERO2:
			case PH_DRIVER_INTERRUPT_LEVELONE2:
				break;
			case PH_DRIVER_INTERRUPT_RISINGEDGE2:
				edgeVal2 = SIUL2_ICU_RISING_EDGE;
				break;
			case PH_DRIVER_INTERRUPT_FALLINGEDGE2:
				edgeVal2 = SIUL2_ICU_FALLING_EDGE;
				break;
			case PH_DRIVER_INTERRUPT_EITHEREDGE2:
				edgeVal2 = SIUL2_ICU_BOTH_EDGES;
				break;
			default:
				break;
		}
		if (SIUL2_ICU_DISABLE != edgeVal2)
		{
		    /* Initialize the Icu driver */
		    (void)Siul2_Icu_Ip_Init(SIUL2_ICU_IP_INSTANCE, &Siul2_Icu_Ip_0_Config_PB_BOARD_InitPeripherals);
			Siul2_Icu_Ip_SetActivationCondition(SIUL2_ICU_IP_INSTANCE, Siul2_Icu_Ip_0_ChannelConfig_PB_BOARD_InitPeripherals[0].hwChannel, edgeVal2);
			Siul2_Icu_Ip_EnableInterrupt(SIUL2_ICU_IP_INSTANCE, Siul2_Icu_Ip_0_ChannelConfig_PB_BOARD_InitPeripherals[0].hwChannel);
			Siul2_Icu_Ip_EnableNotification(SIUL2_ICU_IP_INSTANCE, Siul2_Icu_Ip_0_ChannelConfig_PB_BOARD_InitPeripherals[0].hwChannel);
			retVal2 = PH_DRIVER_SUCCESS2;
		}
		else
		{
			/* Return value */
			retVal2 = PH_DRIVER_FAILURE2;
		}
	}
	else
	{
		/* Do Nothing */
	}

	return retVal2;
}

#else
FUNC(phStatus_t2, ANFCRL_CODE) phDriver_PinConfig2(VAR(uint32, ANFCRL_VAR) dwPinNumber2,
    VAR(phDriver_Pin_Func_t2, ANFCRL_VAR) ePinFunc2, P2VAR(phDriver_Pin_Config_t2, AUTOMATIC, ANFCRL_APPL_DATA) pPinConfig2) {
  VAR(uint8, ANFCRL_VAR) bPinNum2;
	PORT_Type * dwPortBaseAddress2;
	GPIO_Type * dwGpioBaseAddress2;
  VAR(uint32, ANFCRL_VAR) pinCount2 = 1;
  VAR(pin_settings_config_t, ANFCRL_VAR) config2[1];

  VAR(pin_settings_config_t, ANFCRL_VAR) sPinConfig2;
	sPinConfig2.pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED;
	sPinConfig2.passiveFilter = FALSE;
	sPinConfig2.driveSelect = PORT_LOW_DRIVE_STRENGTH;
	sPinConfig2.mux = PORT_MUX_AS_GPIO;
	sPinConfig2.pinLock = FALSE;
	sPinConfig2.intConfig = PORT_DMA_INT_DISABLED;
	sPinConfig2.clearIntFlag = FALSE;
	sPinConfig2.gpioBase = NULL;
	sPinConfig2.digitalFilter = FALSE;

	if ((ePinFunc2 == PH_DRIVER_PINFUNC_BIDIR2) || (pPinConfig2 == NULL)) {
		return PH_DRIVER_ERROR2 | PH_COMP_DRIVER2;
	}

	/* Extract the Pin, GPIO, Port details from dwPinNumber2 */
	bPinNum2 = (uint8) ((dwPinNumber2 & 0xFF00000u) >> 20u);
	dwPortBaseAddress2 = (PORT_Type *) ((dwPinNumber2 & 0x000FF000u)
			| PORT_BASE_ADDR2);
	dwGpioBaseAddress2 = (GPIO_Type *) ((dwPinNumber2 & 0x00000FFFu)
			| GPIO_BASE_ADDR2);

	sPinConfig2.base = dwPortBaseAddress2;
	sPinConfig2.pinPortIdx = bPinNum2;
	if (PHDRIVER_PIN_SSEL2 == dwPinNumber2) {
		sPinConfig2.pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED;
	}
	else
	{
		sPinConfig2.pullConfig =
				(pPinConfig2->bPullSelect2 == PH_DRIVER_PULL_DOWN2) ?
						PORT_INTERNAL_PULL_DOWN_ENABLED :
						PORT_INTERNAL_PULL_UP_ENABLED;
	}
	sPinConfig2.gpioBase = dwGpioBaseAddress2;
	sPinConfig2.direction =
			(ePinFunc2 == PH_DRIVER_PINFUNC_OUTPUT2) ?
					GPIO_OUTPUT_DIRECTION : GPIO_INPUT_DIRECTION;
	sPinConfig2.initValue = pPinConfig2->bOutputLogic2;
	/* Configure for interrupt pin */
	if (ePinFunc2 == PH_DRIVER_PINFUNC_INTERRUPT2) {
		/* Clear any pending interrupts before enabling interrupt */
		PINS_DRV_ClearPinIntFlagCmd(sPinConfig2.base, bPinNum2);
		/* Set interrupt enable depends on which type of triggering */
		switch (pPinConfig2->eInterruptConfig2) {
		case PH_DRIVER_INTERRUPT_LEVELZERO2:
			sPinConfig2.intConfig = PORT_INT_LOGIC_ZERO;
			break;
		case PH_DRIVER_INTERRUPT_LEVELONE2:
			sPinConfig2.intConfig = PORT_INT_LOGIC_ONE;
			break;
		case PH_DRIVER_INTERRUPT_RISINGEDGE2:
			sPinConfig2.intConfig = PORT_INT_RISING_EDGE;
			break;
		case PH_DRIVER_INTERRUPT_FALLINGEDGE2:
			sPinConfig2.intConfig = PORT_INT_FALLING_EDGE;
			break;
		case PH_DRIVER_INTERRUPT_EITHEREDGE2:
			sPinConfig2.intConfig = PORT_INT_EITHER_EDGE;
			break;
		default:
			break;
		}
	}
	config2[0] = sPinConfig2;
	(void) PINS_DRV_Init(pinCount2, config2);

	return PH_DRIVER_SUCCESS2;
}

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(uint8, ANFCRL_CODE) phDriver_PinRead2(VAR(uint32, ANFCRL_VAR) dwPinNumber2, VAR(phDriver_Pin_Func_t2, ANFCRL_VAR) ePinFunc2) {
  VAR(uint8, ANFCRL_VAR) bValue2 = 0u;

	if(dwPinNumber2 == PHDRIVER_PIN_IRQ2)
	{
		// CLIF_IRQHandler() �Լ��� ������� �ʱ� ������
		// INPUT || INTERRUPT�� �д� ��� Read �� return�ϵ��� ��ġ ��.
		// PH_DRIVER_PINFUNC_INTERRUPT�� Ȯ���� ���ص� �� �� ���� �ѵ� �ϴ� �߰� �� ����
//		if(ePinFunc == PH_DRIVER_PINFUNC_INPUT)
		if((ePinFunc2 == PH_DRIVER_PINFUNC_INPUT2) || (ePinFunc2 == PH_DRIVER_PINFUNC_INTERRUPT2))
		{
			bValue2 = platformSpiIRQ_ReadDirect2();
		}
	}

	return bValue2;
}

#elif defined (PHDRIVER_S32K3122)
FUNC(uint8, ANFCRL_CODE) phDriver_PinRead2(VAR(uint32, ANFCRL_VAR) dwPinNumber2, VAR(phDriver_Pin_Func_t2, ANFCRL_VAR) ePinFunc2) {
  VAR(uint8, ANFCRL_VAR) bValue2 = 1u;
	Siul2_Dio_Ip_GpioType * dwGpioBaseAddress2;
	Siul2_Dio_Ip_PinsChannelType bPinNum2;
	/* Extract the Pin, Gpio details from dwPinNumber2 */
	bPinNum2 = (uint8) ((dwPinNumber2 & 0xFF00000u) >> 20u);
	dwGpioBaseAddress2 = (Siul2_Dio_Ip_GpioType *) ((dwPinNumber2 & 0x0000FFFFu)
			| GPIO_BASE_ADDR2);

	if (PH_DRIVER_PINFUNC_INTERRUPT2 != ePinFunc2)
	{
		bValue2 = (uint8)(Siul2_Dio_Ip_ReadPin(dwGpioBaseAddress2, bPinNum2));
	}

	return bValue2;
}

#else
FUNC(uint8, ANFCRL_CODE) phDriver_PinRead2(VAR(uint32, ANFCRL_VAR) dwPinNumber2, VAR(phDriver_Pin_Func_t2, ANFCRL_VAR) ePinFunc2) {
  VAR(uint8, ANFCRL_VAR) bValue2;
  VAR(uint8, ANFCRL_VAR) bPinNum2;
	PORT_Type * dwPortBaseAddress2;
	GPIO_Type * dwGpioBaseAddress2;
	/* Extract the Pin, Gpio details from dwPinNumber2 */
	bPinNum2 = (uint8) ((dwPinNumber2 & 0xFF00000u) >> 20u);
	dwGpioBaseAddress2 = (GPIO_Type *) ((dwPinNumber2 & 0x00000FFFu)
			| GPIO_BASE_ADDR2);
	dwPortBaseAddress2 = (PORT_Type *) ((dwPinNumber2 & 0x000FF000u)
			| PORT_BASE_ADDR2);
	if (ePinFunc2 == PH_DRIVER_PINFUNC_INTERRUPT2) {
		bValue2 = (uint8) ((PINS_DRV_GetPortIntFlag(dwPortBaseAddress2)
				>> bPinNum2) & 0x01u);
	}
	else
	{
		bValue2 = (uint8) ((PINS_DRV_ReadPins(dwGpioBaseAddress2) >> bPinNum2)
				& 0x01u);
	}

	return bValue2;
}


#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(void, ANFCRL_CODE) phDriver_PinWrite2(VAR(uint32, ANFCRL_VAR) dwPinNumber2, VAR(uint8, ANFCRL_VAR) bValue2) {
  VAR(uint8, ANFCRL_VAR) bPinNum2;

	if(dwPinNumber2 == PHDRIVER_PIN_RESET)
	{
		if((bValue2 == RESET_POWERDOWN_LEVEL) || (bValue2 == RESET_POWERUP_LEVEL))
		{
			platformSpiWAKEUP_WriteDirect2(bValue2);
		}
	}
}
#elif defined (PHDRIVER_S32K3122)
FUNC(void, ANFCRL_CODE) phDriver_PinWrite2(VAR(uint32, ANFCRL_VAR) dwPinNumber2, VAR(uint8, ANFCRL_VAR) bValue2) {
	Siul2_Dio_Ip_GpioType * dwGpioBaseAddress2;
	Siul2_Dio_Ip_PinsChannelType bPinNum2;
	/* Extract the Pin, Gpio details from dwPinNumber2 */
	bPinNum2 = (uint8) ((dwPinNumber2 & 0xFF00000u) >> 20u);
	dwGpioBaseAddress2 = (Siul2_Dio_Ip_GpioType *) ((dwPinNumber2 & 0x0000FFFFu)
			| GPIO_BASE_ADDR2);

	Siul2_Dio_Ip_WritePin(dwGpioBaseAddress2, bPinNum2, bValue2);
}

#else
FUNC(void, ANFCRL_CODE) phDriver_PinWrite2(VAR(uint32, ANFCRL_VAR) dwPinNumber2, VAR(uint8, ANFCRL_VAR) bValue2) {
  VAR(uint8, ANFCRL_VAR) bPinNum2;
	GPIO_Type * dwGpioBaseAddress2;

	/* Extract the Pin, Gpio details from dwPinNumber2 */
	bPinNum2 = (uint8) ((dwPinNumber2 & 0xFF00000u) >> 20u);
	dwGpioBaseAddress2 = (GPIO_Type *) ((dwPinNumber2 & 0x00000FFFu)
			| GPIO_BASE_ADDR2);

	PINS_DRV_WritePin(dwGpioBaseAddress2, (pins_channel_type_t) bPinNum2,
			(pins_level_type_t) bValue2);
}

#endif	/* NIDEC_PORTING */


FUNC(void, ANFCRL_CODE) phDriver_PinClearIntStatus2(VAR(uint32, ANFCRL_VAR) dwPinNumber2) {

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	UNUSED2(dwPinNumber2);
/* ������ */

#elif defined (PHDRIVER_S32K3122)
	UNUSED2(dwPinNumber2);

#else
  VAR(uint8, ANFCRL_VAR) bPinNum2;
	PORT_Type * dwPortBaseAddress2;

	/* Extract the Pin, Gpio details from dwPinNumber2 */
	bPinNum2 = (uint8) ((dwPinNumber2 & 0xFF00000u) >> 20u);
	dwPortBaseAddress2 = (PORT_Type *) ((dwPinNumber2 & 0x000FF000u)
			| PORT_BASE_ADDR2);

	PINS_DRV_ClearPinIntFlagCmd(dwPortBaseAddress2, bPinNum2);

#endif	/* NIDEC_PORTING */
}


FUNC(uint32, ANFCRL_CODE) phDriver_GetTimeElapsed2(
VAR(phDriver_Timer_Unit_t2, ANFCRL_VAR) eTimerUnit2,VAR(uint32, ANFCRL_VAR) dwStartTime2)
{
    VAR(uint32, ANFCRL_VAR) wTimeCurrent2 = 0U;
    VAR(uint32, ANFCRL_VAR) wElapsedTime2 = 0U;
    VAR(uint64, ANFCRL_VAR) dwTemp2 = 0U;

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* ������ */

    return wElapsedTime2;

#elif defined (PHDRIVER_S32K3122)
    VAR(uint32, ANFCRL_VAR) frequency2 = 0U;
    frequency2 = Clock_Ip_GetFreq(PIT0_CLK)/(1000000UL);
    wTimeCurrent2 = ((S32K_TIMER_MAX_32BIT2 - (uint32)Pit_Ip_GetCurrentTimer(PIT_0_IP_INSTANCE_NUMBER,PIT_0_ChannelConfig_PB[0].hwChannel))/frequency2)/(uint32)eTimerUnit2;

    if (bLastTimerOverflowCounter2 != bTempTimerOverflowCounter2)
    {
        /* Record total overflow time and add to wElapsedTime2 when timer overflow happens */
        if (bLastTimerOverflowCounter2 < bTempTimerOverflowCounter2)
        {
            dwTemp2 = ((uint64) bTempTimerOverflowCounter2 - bLastTimerOverflowCounter2)
                    * PH_DRIVER_TIMER_MAX_TIME2;
        }
        else
        {
            dwTemp2 = ((uint64) OVERFLOW_MAX_COUNT2 - bLastTimerOverflowCounter2
                    + bTempTimerOverflowCounter2) * PH_DRIVER_TIMER_MAX_TIME2;
        }

        /* Calculate elapsed time value and make sure it does not exceed the return type size */
        dwTemp2 = (dwTemp2 / (uint64) eTimerUnit2)
                + ((uint64) wTimeCurrent2 - (uint64) dwStartTime2);

        if (S32K_TIMER_MAX_32BIT2 <= dwTemp2)
        {
            return S32K_TIMER_MAX_32BIT2;
        }
        else
        {
        	wElapsedTime2 = (uint32) dwTemp2;
        }
    }
    else
    {
        wElapsedTime2 = wTimeCurrent2 - dwStartTime2;
    }

    return wElapsedTime2;

#else
    VAR(uint32, ANFCRL_VAR) wValueByCount2 = 0U;
    VAR(uint16, ANFCRL_VAR) w16bitTickCurrent2 = 0U;
    /* In case value received from function LPTMR_DRV_GetCounterValueByCount gets overflowed,
     * and LPTMR0_IRQHandler2 does not synchronize with LPTMR_DRV_GetCounterValueByCount,
     * use local variable to make sure the calculation is correct. */
    w16bitTickCurrent2 = dwH16bitTick2;
    wValueByCount2 = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
    bTempTimerOverflowCounter2 = bTimerOverflowCounter2;

    /*In case the timer overflow happens during setting value for temporary variables,
     * the compatibility of temporary variables should be maintained.*/
    if (w16bitTickCurrent2 != dwH16bitTick2)
    {
        w16bitTickCurrent2 = dwH16bitTick2;
        wValueByCount2 = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
        bTempTimerOverflowCounter2 = bTimerOverflowCounter2;
    }
    else if (wValueByCount2
            > (uint32) LPTMR_DRV_GetCounterValueByCount(0u))
    {
        w16bitTickCurrent2 = dwH16bitTick2;
        wValueByCount2 = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
        bTempTimerOverflowCounter2 = bTimerOverflowCounter2;
    }
    else
    {
        /*Do nothing*/
    }
    /* In case value received from function LPTMR_DRV_GetCounterValueByCount has overflowed
     * but timer interrupt was too slow to update timer overflow counter,
     * bTempTimerOverflowCounter2 will be updated to make sure the calculation is correct. */
    if ((wValueByCount2 > (uint32) LPTMR_DRV_GetCounterValueByCount(0u))
            && (w16bitTickCurrent2 == dwH16bitTick2))
    {
        if (w16bitTickCurrent2 == S32K_TIMER_MAX_16BIT2)
        {
            bTempTimerOverflowCounter2++;
            w16bitTickCurrent2 = 0u;
        }
        else
        {
            w16bitTickCurrent2++;
        }
    }
    wTimeCurrent2 = (wValueByCount2 | ((uint32) w16bitTickCurrent2 << 16u))
            / (uint32) eTimerUnit2;

    if (bLastTimerOverflowCounter2 != bTempTimerOverflowCounter2)
    {
        /* Record total overflow time and add to wElapsedTime2 when timer overflow happens */
        if (bLastTimerOverflowCounter2 < bTempTimerOverflowCounter2)
        {
            dwTemp2 = ((uint64) bTempTimerOverflowCounter2 - bLastTimerOverflowCounter2)
                    * PH_DRIVER_TIMER_MAX_TIME2;
        }
        else
        {
            dwTemp2 = ((uint64) OVERFLOW_MAX_COUNT2 - bLastTimerOverflowCounter2
                    + bTempTimerOverflowCounter2) * PH_DRIVER_TIMER_MAX_TIME2;
        }

        /* Calculate elapsed time value and make sure it does not exceed the return type size */
        dwTemp2 = (dwTemp2 / (uint64) eTimerUnit2)
                + ((uint64) wTimeCurrent2 - (uint64) dwStartTime2);

        if (S32K_TIMER_MAX_32BIT2 <= dwTemp2)
        {
            return S32K_TIMER_MAX_32BIT2;
        }
        else
        {
        	wElapsedTime2 = (uint32) dwTemp2;
        }
    }
    else
    {
        wElapsedTime2 = wTimeCurrent2 - dwStartTime2;
    }

    return wElapsedTime2;

#endif	 /* NIDEC_PORTING */
}

FUNC(uint32, ANFCRL_CODE) phDriver_GetTimeCurrent2(
VAR(phDriver_Timer_Unit_t2, ANFCRL_VAR) eTimerUnit2)
{
    VAR(uint32, ANFCRL_VAR) wTimeCurrent2 = 0U;

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	UNUSED2(eTimerUnit2);

    return wTimeCurrent2;

#elif defined (PHDRIVER_S32K3122)
    VAR(uint32, ANFCRL_VAR) frequency2 = 0U;
    frequency2 = Clock_Ip_GetFreq(PIT0_CLK)/(1000000UL);
    wTimeCurrent2 = ((S32K_TIMER_MAX_32BIT2 - (uint32)Pit_Ip_GetCurrentTimer(PIT_0_IP_INSTANCE_NUMBER,PIT_0_ChannelConfig_PB[0].hwChannel))/frequency2)/(uint32)eTimerUnit2;
    bLastTimerOverflowCounter2 = bTimerOverflowCounter2;
    return wTimeCurrent2;

#else
    /* In case the value received from function LPTMR_DRV_GetCounterValueByCount gets overflowed,
     * and LPTMR0_IRQHandler2 does not synchronize with LPTMR_DRV_GetCounterValueByCount,
     * use local variables to make sure the calculation is correct. */
    uint16_t w16bitTickCurrent2 = 0U;
    w16bitTickCurrent2 = dwH16bitTick2;
    wTimeCurrent2 = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
    bLastTimerOverflowCounter2 = bTimerOverflowCounter2;

    /*In case the timer overflow happens during setting value for temporary variables,
     * the compatibility of temporary variables should be maintained.*/
    if (w16bitTickCurrent2 != dwH16bitTick2)
    {
        w16bitTickCurrent2 = dwH16bitTick2;
        wTimeCurrent2 = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
        bLastTimerOverflowCounter2 = bTimerOverflowCounter2;
    }
    else if (wTimeCurrent2 > (uint32) LPTMR_DRV_GetCounterValueByCount(0u))
    {
        w16bitTickCurrent2 = dwH16bitTick2;
        wTimeCurrent2 = (uint32) LPTMR_DRV_GetCounterValueByCount(0u);
        bLastTimerOverflowCounter2 = bTimerOverflowCounter2;
    }
    else
    {
        /*Do nothing*/
    }

    wTimeCurrent2 = (wTimeCurrent2 | ((uint32) w16bitTickCurrent2 << 16u)) / (uint32) eTimerUnit2;

    return wTimeCurrent2;

#endif	/* NIDEC_PORTING */

}

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* ������ */

#elif defined (PHDRIVER_S32K312)
FUNC(void, ANFCRL_CODE) phDriver_H32bitInc2(VAR(uint8, ANFCRL_VAR) chanel2){
	UNUSED2(chanel2);
	if(dwH32bitTick2 == S32K_TIMER_MAX_32BIT2)
	{
		bTimerOverflowCounter2++;
		dwH32bitTick2 = 0u;
	}
	else
	{
		dwH32bitTick2++;
	}
}
FUNC(void, ANFCRL_VAR) pGlTimerCallBack2(VAR(uint8, ANFCRL_VAR) channel2){
	pGlTimerCallBack_Temp2(channel2);
}

#else
FUNC(void, ANFCRL_VAR) LPTMR0_IRQHandler2(void){
	pGlTimerCallBack2();
	LPTMR_DRV_ClearCompareFlag(0u);
}
FUNC(void, ANFCRL_CODE) phDriver_H16bitInc2(void)
{
    if (dwH16bitTick2 == S32K_TIMER_MAX_16BIT2)
    {
        bTimerOverflowCounter2++;
        dwH16bitTick2 = 0u;
    }
    else
    {
        dwH16bitTick2++;
    }
}

#endif	/* NIDEC_PORTING */
