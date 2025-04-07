/*******************************************************************************
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2018 - 2023
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
#include <phApp_Init2.h>
#include "ph_Status2.h"
#include <Nfcrdlib_Detect_Card2.h>
/* Check for S32K14x controller based boards */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "App_NFC.h"

#elif defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K11x2)
#include "clockMan1.h"
#include "device_registers.h"
#include "clock_manager.h"
#include "interrupt_manager.h"
#include "osif.h"
#include "lpspi_master_driver.h"
#include "lpspi_shared_function.h"
#ifdef NXPBUILD__PH_LOG_EX2
#include <lpuartLog.h>
#include <lpuart_driver.h>
#include <pins_driver.h>
#endif /*NXPBUILD__PH_LOG_EX2*/

#endif  /* NIDEC_PORTING */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */

#elif defined (PHDRIVER_S32K3122)
#include "OsIf_Cfg.h"
#include "Siul2_Port_Ip.h"
#include "Siul2_Dio_Ip.h"
#include "Siul2_Icu_Ip.h"
#include "Siul2_Icu_Ip_Irq.h"
#include "IntCtrl_Ip.h"
#include "Clock_Ip.h"
#include "Clock_Ip_Private.h"
#include "Pit_IP.h"
#include "Lpuart_Uart_Ip.h"
#include "OsIf_Timer_System_Internal_Systick.h"

#endif  /* NIDEC_PORTING */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
/* HAL specific headers */
#include <phhalHw_Ncx3321_Instr2.h>
#endif

CONST(char, ANFCRL_CONST) pCheckStatus2[] = "Line: %d   Error - (0x%04X) has occurred : 0xCCEE CC-Component ID, EE-Error code. Refer-ph_Status2.h\n";
CONST(char, ANFCRL_CONST) pCheckSuccess2[] = "\nLine: %d   Error - (0x%04X) has occurred : 0xCCEE CC-Component ID, EE-Error code. Refer-ph_Status2.h\n ";
CONST(char, ANFCRL_CONST) pCheckNfclibStatus2[] = "\nLine: %d   Error - (0x%04lX) has occurred in NFCLIB\n ";

/*******************************************************************************
**   Global Variable Declaration
*******************************************************************************/
#ifdef PH_PLATFORM_HAS_ICFRONTEND2
    VAR(phbalReg_Type_t2, ANFCRL_VAR) sBalParams2;
#endif /* PH_PLATFORM_HAS_ICFRONTEND2 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
    P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pHal2;
    static volatile VAR(uint8, ANFCRL_VAR) bAbortRequested2 = PH_OFF2;
#endif

static volatile VAR(uint8, ANFCRL_VAR) bIrqFlag2 = PH_OFF2;
static volatile VAR(phStatus_t2, ANFCRL_VAR) gwStatus2 = PH_ERR_SUCCESS2;

#ifdef PHDRIVER_S32K3122
    static volatile VAR(uint32, ANFCRL_VAR) sys_tick_cnt2 = 0u;
#endif /* PHDRIVER_S32K3122 */
/*******************************************************************************
**   SECTION: BOARD/PLATFORM Initialization
*******************************************************************************/

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K11x2)
    static FUNC(phStatus_t2, ANFCRL_CODE) phPlatform_S32K1xx_Init2(void);

#else
    static FUNC(phStatus_t2, ANFCRL_CODE) phPlatform_S32K3xx_Init2(void);

#endif  /* NIDEC_PORTING */

#ifdef NXPBUILD__PH_LOG_EX2
    static FUNC(phStatus_t2, ANFCRL_CODE) phPlatform_Log_Init2(void);
#endif


/**
* This function will initialize Host Controller.
* Any initialization which is not generic across Platforms, should be done here.
*/

FUNC(phStatus_t2, ANFCRL_CODE) phPlatform_Init2(void)
{
    // gwStatus = PH_ERR_SUCCESS2;
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	return PH_ERR_SUCCESS2;
/* 사용안함 */

#elif defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K11x2)
    return phPlatform_S32K1xx_Init2();

#else
    return phPlatform_S32K3xx_Init2();

#endif  /* NIDEC_PORTING */
}
/**
* This function will de-initialize the LPUART.
*/

#ifdef NXPBUILD__PH_LOG_EX2

FUNC(phStatus_t2, ANFCRL_CODE) phPlatform_Log_DeInit2(void)
{
#if defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K11x2)
	(void)LPUART_DRV_Deinit(INST_LPUARTLOG);
	return PH_ERR_SUCCESS2;
#else
	(void) Lpuart_Uart_Ip_Deinit(LPUART_UART_IP_INSTANCE_USING_6);
	return PH_ERR_SUCCESS2;
#endif  /*PHDRIVER_S32K14x2*/
}


#endif /*NXPBUILD__PH_LOG_EX2*/

static FUNC(void, ANFCRL_CODE) phSysTick_Init2(VAR(uint32, ANFCRL_VAR) x100us2)
{
  VAR(uint32, ANFCRL_VAR) core_freq2 = 0u;

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K11x2)
    (void) CLOCK_SYS_GetFreq(CORE_CLK, &core_freq2);
    /* For Cortex-M0 devices the systick counter is initialized with an undefined
         value, so make sure to initialize it to 0 before starting */
    S32_SysTick->CSR = S32_SysTick_CSR_ENABLE(0u);
    S32_SysTick->RVR = S32_SysTick_RVR_RELOAD((core_freq2 / 10000u)*x100us2); /*0,1ms*/
    S32_SysTick->CVR = S32_SysTick_CVR_CURRENT(0U);
    S32_SysTick->CSR = S32_SysTick_CSR_ENABLE(1u) | S32_SysTick_CSR_TICKINT(1u) | S32_SysTick_CSR_CLKSOURCE(1u);
#else
    core_freq2 =  Clock_Ip_GetFreq(CORE_CLK);
    /* For Cortex-M0 devices the systick counter is initialized with an undefined
     value, so make sure to initialize it to 0 before starting */
    S32_SysTick->CSRr = S32_SysTick_CSR_ENABLE(0u);
    S32_SysTick->RVR = S32_SysTick_RVR_RELOAD((core_freq2 / 10000u)*x100us2);
    S32_SysTick->CVR = S32_SysTick_CVR_CURRENT(0U);
    S32_SysTick->CSRr = S32_SysTick_CSR_ENABLE(1u) | S32_SysTick_CSR_TICKINT(1u) | S32_SysTick_CSR_CLKSOURCE(1u);
#endif
}


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K3122)
FUNC(void, ANFCRL_CODE) SysTick_Handler2(void)
{
    sys_tick_cnt2++;
}

FUNC(uint32, ANFCRL_CODE) phGetCurrentTickCount2(void){
    return sys_tick_cnt2;
}

#else
#if !(FEATURE_OSIF_USE_SYSTICK)
FUNC(void, ANFCRL_CODE) SysTick_Handler2(void)
{
    sys_tick_cnt2++;
}
#endif

FUNC(uint32, ANFCRL_CODE) phGetCurrentTickCount2(void){
#if FEATURE_OSIF_USE_SYSTICK
    return OSIF_GetMilliseconds();
#else
    return sys_tick_cnt2;
#endif
}

#endif  /* NIDEC_PORTING */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */
// 아래 참고
/* In case of S32K series, startup file takes care of initializing clock and ports.
 * No initialization is required in Other environment. */

#elif defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K11x2)
static FUNC(phStatus_t2, ANFCRL_CODE) phPlatform_S32K1xx_Init2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2;
    /* Initialize clock */
    PH_CHECK_SUCCESS_FCT2(status2,
            (phStatus_t2)CLOCK_SYS_Init(g_clockManConfigsArr,
                    CLOCK_MANAGER_CONFIG_CNT,
                    g_clockManCallbacksArr,
                    CLOCK_MANAGER_CALLBACK_CNT)
            );
    PH_CHECK_SUCCESS_FCT2(status2,
            (phStatus_t2)CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT));

    phSysTick_Init2(1u);
    /* start a free running timer */
    PH_CHECK_SUCCESS_FCT2(status2, phDriver_TimerStart2(PH_DRIVER_TIMER_USECS2, 0, NULL));

    /* Initialize log */
#ifdef NXPBUILD__PH_LOG_EX2
    PH_CHECK_SUCCESS_FCT2(status2, phPlatform_Log_Init2());
    phLogEx_Init2(&sprintf,&phDriver_UARTPutSTR2);
#endif
    return status2;
}

#else
static FUNC(phStatus_t2, ANFCRL_CODE) phPlatform_S32K3xx_Init2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_DRIVER_SUCCESS2;
    /* Initialize clock */
    (void)Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

    (void)Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Install all ISR */
    (void)IntCtrl_Ip_Init(&IntCtrlConfig_0);
    (void)IntCtrl_Ip_ConfigIrqRouting(&intRouteConfig);

    /*Initial PIT instance 0 - Channel 0*/
    Pit_Ip_Init(PIT_0_IP_INSTANCE_NUMBER, &PIT_0_InitConfig_PB);
    /*Initial channel 0 */
    Pit_Ip_InitChannel(PIT_0_IP_INSTANCE_NUMBER, PIT_0_CH_0);
    /*Enable channel interrupt PIT_0 - CH_0*/
    Pit_Ip_EnableChannelInterrupt(PIT_0_IP_INSTANCE_NUMBER, PIT_0_ChannelConfig_PB[0].hwChannel);

    phSysTick_Init2(1u);
    /* start a free running timer */
    PH_CHECK_SUCCESS_FCT2(status2, phDriver_TimerStart2(PH_DRIVER_TIMER_USECS2, 0, NULL));

    /* Initialize log */
#ifdef NXPBUILD__PH_LOG_EX2
    PH_CHECK_SUCCESS_FCT2(status2, phPlatform_Log_Init2());
    phLogEx_Init2(&sprintf,&phDriver_UARTPutSTR2);
#endif
    return status2;
}

#endif /* NIDEC_PORTING */

#ifdef NXPBUILD__PH_LOG_EX2
static FUNC(phStatus_t2, ANFCRL_CODE) phPlatform_Log_Init2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
#if defined (PHDRIVER_S32K14x2)
    /* S32K14x
     * UART configuration for Logging port
     *Channel: LPUART1
     *TX Pin: PTC7
     *RX Pin: PTC6 */
    VAR(pin_settings_config_t, ANFCRL_VAR) g_pin_mux_InitLogArr2[2] =
    {
        {
            .base          = PORTC,
            .pinPortIdx    = 7u,
            .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
            .passiveFilter = FALSE,
            .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
            .mux           = PORT_MUX_ALT2,
            .pinLock       = FALSE,
            .intConfig     = PORT_DMA_INT_DISABLED,
            .clearIntFlag  = FALSE,
            .gpioBase      = NULL,
            .digitalFilter = FALSE,
        },
        {
            .base          = PORTC,
            .pinPortIdx    = 6u,
            .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
            .passiveFilter = FALSE,
            .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
            .mux           = PORT_MUX_ALT2,
            .pinLock       = FALSE,
            .intConfig     = PORT_DMA_INT_DISABLED,
            .clearIntFlag  = FALSE,
            .gpioBase      = NULL,
            .digitalFilter = FALSE,
        }
    };
    PH_CHECK_SUCCESS_FCT2(status2, (phStatus_t2)PINS_DRV_Init(2, g_pin_mux_InitLogArr2));
    /* Initialize LPUART instance */
    PH_CHECK_SUCCESS_FCT2(status2, (phStatus_t2)LPUART_DRV_Init(INST_LPUARTLOG, &lpuartLog_State, &lpuartLog_InitConfig0));
#elif defined (PHDRIVER_S32K11x2)
    /* S32K11x
     * UART configuration for Logging port
         *Channel: LPUART1
         *TX Pin: PTB1
         *RX Pin: PTB0 */
    VAR(pin_settings_config_t, ANFCRL_VAR) g_pin_mux_InitLogArr2[2] =
    {
        {
            .base          = PORTB,
            .pinPortIdx    = 0u,
            .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
            .passiveFilter = FALSE,
            .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
            .mux           = PORT_MUX_ALT2,
            .pinLock       = FALSE,
            .intConfig     = PORT_DMA_INT_DISABLED,
            .clearIntFlag  = FALSE,
            .gpioBase      = NULL,
            .digitalFilter = FALSE,
        },
        {
            .base          = PORTB,
            .pinPortIdx    = 1u,
            .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
            .passiveFilter = FALSE,
            .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
            .mux           = PORT_MUX_ALT2,
            .pinLock       = FALSE,
            .intConfig     = PORT_DMA_INT_DISABLED,
            .clearIntFlag  = FALSE,
            .gpioBase      = NULL,
            .digitalFilter = FALSE,
        }
    };
    PH_CHECK_SUCCESS_FCT2(status2, (phStatus_t2)PINS_DRV_Init(2, g_pin_mux_InitLogArr2));
    /* Initialize LPUART instance */
    PH_CHECK_SUCCESS_FCT2(status2, (phStatus_t2)LPUART_DRV_Init(INST_LPUARTLOG, &lpuartLog_State, &lpuartLog_InitConfig0));


#elif defined (PHDRIVER_S32K3122)
    /* Initializes an UART driver*/
    Lpuart_Uart_Ip_Init(LPUART_UART_IP_INSTANCE_USING_6, &Lpuart_Uart_Ip_xHwConfigPB_6_BOARD_INITPERIPHERALS);
#endif
    return status2;
}
#endif /*NXPBUILD__PH_LOG_EX2*/

#ifdef NXPBUILD__PHHAL_HW_NCX33212
FUNC(phStatus_t2, ANFCRL_CODE) phApp_Ncx3321_SPIRead2(P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
    VAR(uint16, ANFCRL_VAR) wRxLength2)
{
  VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) wResponseLen2 = 0U;

#ifdef PHDRIVER_SOFT_SSEL2
    /* Enable chip select connected to reader IC (NSS low). */
    phDriver_PinWrite2(PHDRIVER_PIN_SSEL2, PH_DRIVER_SET_LOW2);
#endif /* PHDRIVER_SOFT_SSEL2 */

    /* Read back response */
    status2 =  phbalReg_Exchange2(
            &sBalParams2,
            PH_EXCHANGE_DEFAULT2,
            NULL,
            0U,
            wRxLength2,
            pRxBuffer2,
            &wResponseLen2);

#ifdef PHDRIVER_SOFT_SSEL2
    /* Disable chip select connected to reader IC (NSS high). */
    phDriver_PinWrite2(PHDRIVER_PIN_SSEL2, PH_DRIVER_SET_HIGH2);
#endif /* PHDRIVER_SOFT_SSEL2 */

/* Need Check Point */
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
// phbalReg_Exchange() 함수에서 wResponseLen를 받아가지만
// 내부를 수정하면서 platformSpiExchange() 함수에서 wResponseLen를 return 하지 않음
// 따라서 일단 막아서 사용하고 추가해야 한다고 하면
// platformSpiExchange() 함수에서 wResponseLen를 rerturen 하도록 수정
// WT : wRxLength 로 전달된 Byte수 만큼 Read되는 것이 보장된다면 반드시 적용이 필요하진 않지만
// WT : Read해야하는 갯수만큼 읽었는지 check하는 부분이므로 가능하다면 추가하는 것으로 추천 드립니다.

#else
	if(wResponseLen2 != wRxLength2)
	{
		status2 = PH_ERR_INTERNAL_ERROR2;
	}

#endif	/* NIDEC_PORTING */
    return status2;
}

static volatile VAR(uint8, ANFCRL_VAR) bSkipEventPost2 = 0x0U;
/* Application callback to handle Asynchronous events which cannot be processed by RdLib */
FUNC(void, ANFCRL_CODE) phApp_CallBack2(void)
{
    VAR(uint32, ANFCRL_VAR) dwEventStatusReg2 = 0x0U;
    VAR(uint32,ANFCRL_VAR) dwEventData2 = 0x0U;
    VAR(uint16, ANFCRL_VAR) wEventLen2 = 0x0U;
    VAR(uint8, ANFCRL_VAR) bBackUp2 = 0U;
    VAR(uint8, ANFCRL_VAR) bSPIReadLen2 = 0U;
    VAR(uint16,ANFCRL_VAR) EventDataSize2 = 0U;
    VAR(uint16,ANFCRL_VAR) bIndex2 = 0U;

    /* Event length is of 2 byte @bIndex2  2 and 3 */
    wEventLen2 = (uint16) pHal2->sIrqResp2.pIsrEvtBuffPtr2[2];
    wEventLen2 <<= 8;
    wEventLen2 |= ((uint16) pHal2->sIrqResp2.pIsrEvtBuffPtr2[3]);

    /* Event Status is of 4 byte#bIndex2 4, 5, 6 and 7 */
    dwEventStatusReg2 = (uint32) pHal2->sIrqResp2.pIsrEvtBuffPtr2[4];
    dwEventStatusReg2 |= ((uint32) pHal2->sIrqResp2.pIsrEvtBuffPtr2[5]) << 8U ;
    dwEventStatusReg2 |= ((uint32) pHal2->sIrqResp2.pIsrEvtBuffPtr2[6]) << 16U;
    dwEventStatusReg2 |= ((uint32) pHal2->sIrqResp2.pIsrEvtBuffPtr2[7]) << 24U;

    /* Event data size = Length of Data - 4*/
    if (wEventLen2 > 4U )
    {
        EventDataSize2 = wEventLen2 - 4U ;
        for (bIndex2 = 0U; bIndex2 < EventDataSize2 ; bIndex2++ )
        {
            dwEventData2 |= ((uint32) pHal2->sIrqResp2.pIsrEvtBuffPtr2[8U+bIndex2]) << (8U*bIndex2);
        }
    }
    else
    {
        /* Do nothing , no event data for the corresponding event */
    }
    /* Received Current Error Event */
    if ((dwEventStatusReg2 & PH_NCX3321_EVT_TX_OVERCURRENT_ERROR2) != 0U)
    {
        pHal2->HwEventObj2.dEventStatus2 = PH_ERR_ABORTED2;
        DEBUG_PRINTF2 ("\n\tReceived TX Over Current Event... \n");
        return;
    }
    /* Received Boot Event */
    else if ((dwEventStatusReg2 & PH_NCX3321_EVT_BOOT2) != 0U)
    {
        if ((dwEventData2 & PH_NCX3321_BOOT_TEMP2) != 0U)
        {
            /* Boot up Reason due to IC temperature is more than the configured threshold limit*/
            /*  Return Aborted status2 */
            pHal2->HwEventObj2.dEventStatus2 = PH_ERR_ABORTED2;
            DEBUG_PRINTF2 ("\n\tBoot event due to overtemperature... \n");
        }
        else
        {
            /* Do nothing */
        }
        return;
    }
    /* Received CTS Event */
    else if ((dwEventStatusReg2 & PH_NCX3321_EVT_CTS2) != 0U)
    {
        DEBUG_PRINTF2 ("\n\tReceived CTS Event... \n");
        gwStatus2 = phhalHw_SetConfig2(pHal2, PHHAL_HW_NCX3321_CONFIG_CTS_EVENT_STATUS2, PH_ON2);
        if(gwStatus2 != PH_ERR_SUCCESS2)
        {
            CHECK_STATUS2(gwStatus2);
            pHal2->HwEventObj2.dEventStatus2 = PH_ERR_ABORTED2;
            DEBUG_PRINTF2("\n\tphApp_CallBack phhalHw_SetConfig2 failed, aborting... \n");
            return;
        }
        else
        {
            /* Do nothing */
        }
    }
    /* Received RF ON Event */
    else if ((dwEventStatusReg2 & PH_NCX3321_EVT_RFON_DETECT2) != 0U)
    {
        DEBUG_PRINTF2 ("\n\tReceived RF ON Event... \n");
        gwStatus2 = phhalHw_SetConfig2(pHal2, PHHAL_HW_NCX3321_CONFIG_RF_ON_EVENT_STATUS2, PH_ON2);
        if(gwStatus2 != PH_ERR_SUCCESS2)
        {
            CHECK_STATUS2(gwStatus2);
            pHal2->HwEventObj2.dEventStatus2 = PH_ERR_ABORTED2;
            DEBUG_PRINTF2("\n\tphApp_CallBack phhalHw_SetConfig2 failed, aborting... \n");
            return;
        }
        else
        {
            bSkipEventPost2 = 0x1U;
        }

        bSPIReadLen2 = (pHal2->sIrqResp2.bIsrBytesRead2 -
                (PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN2 + PHHAL_HW_NCX3321_TYPE_FIELD_LEN2 +
                PHHAL_HW_NCX3321_LENGTH_FIELD_LEN2));

        if (wEventLen2 > bSPIReadLen2)
        {
            bBackUp2 = pHal2->sIrqResp2.pIsrEvtBuffPtr2[wEventLen2 - 1u];

            gwStatus2 = phApp_Ncx3321_SPIRead2(&pHal2->sIrqResp2.pIsrEvtBuffPtr2[wEventLen2 - 1u],
                    (uint16) (wEventLen2 - bSPIReadLen2 + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN2));
            if(gwStatus2 != PH_ERR_SUCCESS2)
            {
                CHECK_STATUS2(gwStatus2);
                pHal2->HwEventObj2.dEventStatus2 = PH_ERR_ABORTED2;
                DEBUG_PRINTF2("\n\tSPI read failed, aborting... \n");
                return;
            }

            pHal2->sIrqResp2.pIsrEvtBuffPtr2[wEventLen2 - 1u] = bBackUp2;
        }
    }
    /* Received Unexpected Event */
    else if ((dwEventStatusReg2 & PH_NCX3321_EVT_UNEXPECTED2) != 0U)
    {
        pHal2->HwEventObj2.dEventStatus2 = PH_ERR_ABORTED2;
        DEBUG_PRINTF2 ("\n\tReceived Unexpected Event... \n");
        return;
    }
    else
    {
        /* Do nothing */
    }
}

FUNC(phStatus_t2, ANFCRL_CODE) phApp_CheckAbort2(void)
{
    VAR(phNfcLib_Status_t2, ANFCRL_VAR) dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
    static VAR(uint8, ANFCRL_VAR) bState2 = 0U;
#ifdef PH_PLATFORM_HAS_ICFRONTEND2
    VAR(phNfcLib_AppContext_t2, ANFCRL_VAR) AppContext2 = { 0x00U };
#endif

    if (PH_ON2 == bAbortRequested2)
    {
        if (bState2 == 0U)
        {
            /* Reset library */
            dwStatus2 = phNfcLib_DeInit2();
            CHECK_NFCLIB_STATUS2(dwStatus2);

            status2 = phPlatform_Init2();
            CHECK_STATUS2(status2);

#ifdef PH_PLATFORM_HAS_ICFRONTEND2
            status2 = phbalReg_Init2(&sBalParams2, (uint16) sizeof(phbalReg_Type_t2));
            CHECK_STATUS2(status2);

            AppContext2.pBalDataparams2 = &sBalParams2;
#ifdef NXPBUILD__PHHAL_HW_NCX33212
            AppContext2.pHalPollFunc2 = &phApp_IrqPolling2;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */
            dwStatus2 = phNfcLib_SetContext2(&AppContext2);
            CHECK_NFCLIB_STATUS2(dwStatus2);
#endif /* PH_PLATFORM_HAS_ICFRONTEND2 */
            bState2 = 1U;
        }

        if (bState2 == 1U)
        {
#if 0 // CAS_KR
            dwStatus2 = phNfcLib_Init2();
#else
            do
            {
                dwStatus2 = aNfcRdLib_Init_Ncx3321_Init2();
            }while(PH_STATUS_INPROCESS2 == dwStatus2);
	        dwStatus2 = aNfcRdLib_Init_Component_Init2();
#endif
            if((uint32) PH_STATUS_INPROCESS2 == dwStatus2)
            {
                return PH_STATUS_INPROCESS2;
            }
            CHECK_NFCLIB_STATUS2(dwStatus2);
            bState2 = 0U;
        }

        /* Consume abort event */
        (void) phTools_EventClear2(&pHal2->HwEventObj2, E_EVENT_OPT_NONE2,
                (E_EVENT_RF2 | E_EVENT_ABORT2),
                NULL);

        /* Set the generic pointer */
        pHal2 = phNfcLib_GetDataParams2(PH_COMP_HAL2);

        status2 = phApp_Configure_IRQ2();
        CHECK_STATUS2(status2);

        bAbortRequested2 = PH_OFF2;

        return PH_ERR_SUCCESS2;
    }
    bState2 = 0U;
    /* Abort action is not requested, do nothing. */
    return PH_STATUS_IDLE2;
}

FUNC(void, ANFCRL_CODE) phApp_IrqPolling2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
    VAR(uint32, ANFCRL_VAR) dwElapsedTime2 = 0U;

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	bIrqFlag2 = platformSpiIRQ_ReadDirect2();
#endif	/* NIDEC_PORTING */

    (void)(pDataParams2);
    /* Read the interrupt status2 of external interrupt attached to the reader IC IRQ pin */
    if (bIrqFlag2 != PH_OFF2)
    {
        /* Clear interrupt status2 to avoid missing IRQ raised again */
        bIrqFlag2 = PH_OFF2;
        /* Call application registered callback. */
        if ((pHal2->wId2 == (PH_COMP_HAL2 | PHHAL_HW_NCX3321_ID2)) && (pHal2->pRFISRCallback2 != NULL))
        {
            /* Read the data over SPI */
            gwStatus2 = phApp_Ncx3321_SPIRead2(pHal2->sIrqResp2.pHandlerModeBuffPtr2,
                    (uint16) pHal2->sIrqResp2.bIsrBytesRead2);
            if(gwStatus2 != PH_ERR_SUCCESS2)
            {
                CHECK_STATUS2(gwStatus2);
                pHal2->HwEventObj2.dEventStatus2 = PH_ERR_ABORTED2;
                DEBUG_PRINTF2 ("\n\tSPI read failed, aborting... \n");
                return;
            }
            else
            {
                /* Do nothing */
            }

            /* Handle events triggered by NCX3321 for previous command execution */
            if( pHal2->sIrqResp2.pHandlerModeBuffPtr2[1] == PH_NCX3321_EVT_RSP2 )
            {
                pHal2->sIrqResp2.pIsrEvtBuffPtr2 = pHal2->sIrqResp2.pHandlerModeBuffPtr2;

                /* Call application registered callback to handle NCX3321 Asynchronous events  */
                phApp_CallBack2();
                if(gwStatus2 != PH_ERR_SUCCESS2)
                {
                    CHECK_STATUS2(gwStatus2);
                    pHal2->HwEventObj2.dEventStatus2 = PH_ERR_ABORTED2;
                    DEBUG_PRINTF2 ("\n\tphApp_CallBack failed, aborting... \n");
                    return;
                }

                if (bSkipEventPost2 == 0x0U)
                {
                    /* Call application RF callback to handle NCX3321 synchronous events  */
                    pHal2->pRFISRCallback2(pHal2);
                }
                bSkipEventPost2 = 0x0U;
            }
            else
            {
                pHal2->sIrqResp2.pIsrBuffPtr2 = pHal2->sIrqResp2.pHandlerModeBuffPtr2;

                pHal2->pRFISRCallback2(pHal2);
            }

            if (pHal2->sIrqResp2.pHandlerModeBuffPtr2 == &pHal2->sIrqResp2.aISRReadBuf2[0])
            {
                pHal2->sIrqResp2.pHandlerModeBuffPtr2 = &pHal2->sIrqResp2.aISRReadBuf2[0];
            }
            else
            {
                pHal2->sIrqResp2.pHandlerModeBuffPtr2 = &pHal2->sIrqResp2.aISRReadBuf2[0];
            }
        }
    }
    if (pHal2->bPollGuardTimeFlag2 == PH_ON2)
    {
/* Need Check Point */
	// 현재 타이머 셋팅때문에 계속 무한 루프 돌고 있어서
	// 임시로 조건 변경하여 pTimerISRCallBack() 함수가 실행되게 하였음.
	// 차후 phDriver_GetTimeCurrent() 함수를 수정하여 동작할 수 있도록 해야 함.

/* 10MS_TASK_Check */
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
		if (1)	// 230102. 임시로 무조건 참으로 동작. JJH.
		{
			pHal2->HwEventObj2.dEventStatus2 = PH_ERR_SUCCESS2;
			pHal2->pTimerISRCallBack2();
		}

#else
        dwElapsedTime2 = phDriver_GetTimeElapsed2(PH_DRIVER_TIMER_USECS2, pHal2->wGuardTimeStart2);

        /* Check for timer overflow, abort if timer overflow happens */
        if (S32K_TIMER_MAX_32BIT2 == dwElapsedTime2)
        {
            pHal2->HwEventObj2.dEventStatus2 = PH_ERR_ABORTED2;
        }
        else
        {
            /* GuardTime's Event */
            if (pHal2->wGuardTimePeriod2 < dwElapsedTime2)
            {
                pHal2->HwEventObj2.dEventStatus2 = PH_ERR_SUCCESS2;
                pHal2->pTimerISRCallBack2();
            }
            else
            {
                /* Do nothing */
            }
        }

#endif  /* NIDEC_PORTING */
    }
}

/* Configure LPCD (for NCX3321) */
FUNC(phStatus_t2, ANFCRL_CODE) phApp_ConfigureLPCD2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
    static VAR(uint8, ANFCRL_VAR) bState2 = 0;
    if (bState2 == 0U)
    {
        PH_CHECK_SUCCESS_FCT2(status2, phhalHw_Ncx3321_Instr_LPCD_SetConfig2(pHal2,
                PHHAL_HW_CONFIG_SET_LPCD_WAKEUPTIME_MS2, PH_NFCRDLIB_LPCD_WAKEUP_CALIB2));

        PH_CHECK_SUCCESS_FCT2(status2, phhalHw_Ncx3321_Instr_LPCD_SetConfig2(pHal2,
                PHHAL_HW_CONFIG_LPCD_MODE2, PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT2));

/* LPCD Function Patch */
        PH_CHECK_SUCCESS_FCT2(status2, phhalHw_Ncx3321_Instr_LPCD_SetConfig2(pHal2,
                // PHHAL_HW_CONFIG_LPCD_CONFIG2, PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD_CALIB2));
                PHHAL_HW_CONFIG_LPCD_CONFIG2, PHHAL_HW_NCX3321_LPCD_CTRL_LPCD_CALIB2));
/* LPCD Function Patch */
        bState2 = 1U;
    }
    PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Lpcd2(pHal2));
    bState2 = 0U;
    PH_CHECK_SUCCESS2(status2);

    PH_CHECK_SUCCESS_FCT2(status2, phhalHw_Ncx3321_Instr_LPCD_SetConfig2(pHal2,
            PHHAL_HW_CONFIG_SET_LPCD_WAKEUPTIME_MS2, PH_NFCRDLIB_LPCD_WAKEUP_PW_DOWN2));

    PH_CHECK_SUCCESS_FCT2(status2, phhalHw_Ncx3321_Instr_LPCD_SetConfig2(pHal2,
            PHHAL_HW_CONFIG_LPCD_MODE2, PHHAL_HW_NCX3321_LPCD_MODE_POWERDOWN2));

/* LPCD Function Patch */
    PH_CHECK_SUCCESS_FCT2(status2, phhalHw_Ncx3321_Instr_LPCD_SetConfig2(pHal2,
            // PHHAL_HW_CONFIG_LPCD_CONFIG2, PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD2));
            PHHAL_HW_CONFIG_LPCD_CONFIG2, PHHAL_HW_NCX3321_LPCD_CTRL_LPCD2));
/* LPCD Function Patch */

    PH_CHECK_SUCCESS_FCT2(status2, phhalHw_Ncx3321_Instr_LPCD_SetConfig2(pHal2,
            PHHAL_HW_CONFIG_LPCD_WAKEUP_CTRL2, PH_NFCRDLIB_LPCD_EXT_RF_WAKEUP2));


    return status2;
}

#endif /*NXPBUILD__PHHAL_HW_NCx33202*/

// 아래 함수에서 IRQ Interrupt를 Enable 하는 것으로 보임
// phDriver_PinConfig() 함수 내에서 해당 동작 수행하도록 변경
FUNC(phStatus_t2, ANFCRL_CODE) phApp_Configure_IRQ2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2;
    VAR(phDriver_Pin_Config_t2, ANFCRL_VAR) pinCfg2;
    VAR(phDriver_Interrupt_Config_t2, ANFCRL_VAR) irqCfg2;

    pinCfg2.bOutputLogic2 = PH_DRIVER_SET_LOW2;
    pinCfg2.bPullSelect2 = PHDRIVER_PIN_IRQ_PULL_CFG2;

#ifdef NXPBUILD__PHHAL_HW_NCx33202
#if (PIN_IRQ_TRIGGER_TYPE2 == IRQ_TRIGGER_TYPE_RISINGEDGE2)
    irqCfg2 = (phDriver_Interrupt_Config_t2) PH_DRIVER_INTERRUPT_RISINGEDGE2;
#else
    irqCfg2 = (phDriver_Interrupt_Config_t2) PH_DRIVER_INTERRUPT_FALLINGEDGE2;
#endif /* PIN_IRQ_TRIGGER_TYPE2 */
#else
    irqCfg2 = (phDriver_Interrupt_Config_t2) PH_DRIVER_INTERRUPT_RISINGEDGE2;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

    pinCfg2.eInterruptConfig2 = irqCfg2;

    status2 = phDriver_PinConfig2(PHDRIVER_PIN_IRQ2, PH_DRIVER_PINFUNC_INTERRUPT2, &pinCfg2);
    bIrqFlag2 = PH_OFF2;
    gwStatus2 = PH_ERR_SUCCESS2;

#if defined(PHDRIVER_S32K11x2) || defined(PHDRIVER_S32K14x2)
    INT_SYS_SetPriority(EINT_IRQn2, EINT_PRIORITY2);
    INT_SYS_ClearPending(EINT_IRQn2);
    INT_SYS_EnableIRQ(EINT_IRQn2);
#endif /* defined(PHDRIVER_S32Kxxx) */

    if (status2 == PH_DRIVER_SUCCESS2)
    {
        return PH_ERR_SUCCESS2;
    }
    else
    {
        return status2;
    }
}

/* IRQ Line routine */
FUNC(void, ANFCRL_CODE) CLIF_IRQHandler2(void)
{
    /* Read the interrupt status2 of external interrupt attached to the reader IC IRQ pin */
    if (phDriver_PinRead2(PHDRIVER_PIN_IRQ2, PH_DRIVER_PINFUNC_INTERRUPT2) != 0u)
    {
        bIrqFlag2 = PH_ON2;
    }
    phDriver_PinClearIntStatus2(PHDRIVER_PIN_IRQ2);
}

/*******************************************************************************
 **   SECTION: HELPER functions
 *******************************************************************************/
/**
 * This function will print buffer content
 * \param   *pBuff2   Buffer Reference
 * \param   num2      data size to be print
 */
FUNC(void, ANFCRL_CODE) phApp_Print_Buff2(
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuff2, VAR(uint8, ANFCRL_VAR) num2)
{
#ifdef DEBUG2
  VAR(uint32, ANFCRL_VAR) i2;
    for (i2 = 0u; i2 < num2; i2++)
    {
        DEBUG_PRINTF2("%02X", pBuff2[i2]);
    }
#else /* DEBUG2 */
    PH_UNUSED_VARIABLE2(num2);
    PH_UNUSED_VARIABLE2(pBuff2);
#endif /* DEBUG2 */
}
#ifdef NXPBUILD__PH_LOG_EX2
FUNC(void, ANFCRL_CODE) phDriver_UARTPutSTR2(P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) msg2)
{
#if defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K11x2)
    (void)LPUART_DRV_SendDataPolling(INST_LPUARTLOG, (const uint8 *)msg2, strlen(msg2));
#endif
#ifdef PHDRIVER_S32K3122
    Lpuart_Uart_Ip_StatusType status2 = LPUART_UART_IP_STATUS_ERROR;
    status2 = Lpuart_Uart_Ip_SyncSend(LPUART_UART_IP_INSTANCE_USING_6, (const uint8 *)msg2, strlen(msg2), 10000UL);
    while (LPUART_UART_IP_STATUS_SUCCESS != status2);

#endif
}
#endif
