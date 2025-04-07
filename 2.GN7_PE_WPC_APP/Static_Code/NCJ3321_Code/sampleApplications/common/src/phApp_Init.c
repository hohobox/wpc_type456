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
#include <phApp_Init.h>
#include "ph_Status.h"
#include <Nfcrdlib_Detect_Card.h>
/* Check for S32K14x controller based boards */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "App_NFC.h"

#elif defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K11x)
#include "clockMan1.h"
#include "device_registers.h"
#include "clock_manager.h"
#include "interrupt_manager.h"
#include "osif.h"
#include "lpspi_master_driver.h"
#include "lpspi_shared_function.h"
#ifdef NXPBUILD__PH_LOG_EX
#include <lpuartLog.h>
#include <lpuart_driver.h>
#include <pins_driver.h>
#endif /*NXPBUILD__PH_LOG_EX*/

#endif  /* NIDEC_PORTING */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */

#elif defined (PHDRIVER_S32K312)
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

#ifdef NXPBUILD__PHHAL_HW_NCX3321
/* HAL specific headers */
#include <phhalHw_Ncx3321_Instr.h>
#endif

CONST(char, ANFCRL_CONST) pCheckStatus[] = "Line: %d   Error - (0x%04X) has occurred : 0xCCEE CC-Component ID, EE-Error code. Refer-ph_Status.h\n";
CONST(char, ANFCRL_CONST) pCheckSuccess[] = "\nLine: %d   Error - (0x%04X) has occurred : 0xCCEE CC-Component ID, EE-Error code. Refer-ph_Status.h\n ";
CONST(char, ANFCRL_CONST) pCheckNfclibStatus[] = "\nLine: %d   Error - (0x%04lX) has occurred in NFCLIB\n ";

/*******************************************************************************
**   Global Variable Declaration
*******************************************************************************/
#ifdef PH_PLATFORM_HAS_ICFRONTEND
    VAR(phbalReg_Type_t, ANFCRL_VAR) sBalParams;
#endif /* PH_PLATFORM_HAS_ICFRONTEND */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pHal;
    static volatile VAR(uint8, ANFCRL_VAR) bAbortRequested = PH_OFF;
#endif

static volatile VAR(uint8, ANFCRL_VAR) bIrqFlag = PH_OFF;
static volatile VAR(phStatus_t, ANFCRL_VAR) gwStatus = PH_ERR_SUCCESS;

#ifdef PHDRIVER_S32K312
    static volatile VAR(uint32, ANFCRL_VAR) sys_tick_cnt = 0u;
#endif /* PHDRIVER_S32K312 */
/*******************************************************************************
**   SECTION: BOARD/PLATFORM Initialization
*******************************************************************************/

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K11x)
    static FUNC(phStatus_t, ANFCRL_CODE) phPlatform_S32K1xx_Init(void);

#else
    static FUNC(phStatus_t, ANFCRL_CODE) phPlatform_S32K3xx_Init(void);

#endif  /* NIDEC_PORTING */

#ifdef NXPBUILD__PH_LOG_EX
    static FUNC(phStatus_t, ANFCRL_CODE) phPlatform_Log_Init(void);
#endif


/**
* This function will initialize Host Controller.
* Any initialization which is not generic across Platforms, should be done here.
*/

FUNC(phStatus_t, ANFCRL_CODE) phPlatform_Init(void)
{
    // gwStatus = PH_ERR_SUCCESS;
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	return PH_ERR_SUCCESS;
/* 사용안함 */

#elif defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K11x)
    return phPlatform_S32K1xx_Init();

#else
    return phPlatform_S32K3xx_Init();

#endif  /* NIDEC_PORTING */
}
/**
* This function will de-initialize the LPUART.
*/

#ifdef NXPBUILD__PH_LOG_EX

FUNC(phStatus_t, ANFCRL_CODE) phPlatform_Log_DeInit(void)
{
#if defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K11x)
	(void)LPUART_DRV_Deinit(INST_LPUARTLOG);
	return PH_ERR_SUCCESS;
#else
	(void) Lpuart_Uart_Ip_Deinit(LPUART_UART_IP_INSTANCE_USING_6);
	return PH_ERR_SUCCESS;
#endif  /*PHDRIVER_S32K14x*/
}


#endif /*NXPBUILD__PH_LOG_EX*/

static FUNC(void, ANFCRL_CODE) phSysTick_Init(VAR(uint32, ANFCRL_VAR) x100us)
{
  VAR(uint32, ANFCRL_VAR) core_freq = 0u;

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K11x)
    (void) CLOCK_SYS_GetFreq(CORE_CLK, &core_freq);
    /* For Cortex-M0 devices the systick counter is initialized with an undefined
         value, so make sure to initialize it to 0 before starting */
    S32_SysTick->CSR = S32_SysTick_CSR_ENABLE(0u);
    S32_SysTick->RVR = S32_SysTick_RVR_RELOAD((core_freq / 10000u)*x100us); /*0,1ms*/
    S32_SysTick->CVR = S32_SysTick_CVR_CURRENT(0U);
    S32_SysTick->CSR = S32_SysTick_CSR_ENABLE(1u) | S32_SysTick_CSR_TICKINT(1u) | S32_SysTick_CSR_CLKSOURCE(1u);
#else
    core_freq =  Clock_Ip_GetFreq(CORE_CLK);
    /* For Cortex-M0 devices the systick counter is initialized with an undefined
     value, so make sure to initialize it to 0 before starting */
    S32_SysTick->CSRr = S32_SysTick_CSR_ENABLE(0u);
    S32_SysTick->RVR = S32_SysTick_RVR_RELOAD((core_freq / 10000u)*x100us);
    S32_SysTick->CVR = S32_SysTick_CVR_CURRENT(0U);
    S32_SysTick->CSRr = S32_SysTick_CSR_ENABLE(1u) | S32_SysTick_CSR_TICKINT(1u) | S32_SysTick_CSR_CLKSOURCE(1u);
#endif
}


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K312)
FUNC(void, ANFCRL_CODE) SysTick_Handler(void)
{
    sys_tick_cnt++;
}

FUNC(uint32, ANFCRL_CODE) phGetCurrentTickCount(void){
    return sys_tick_cnt;
}

#else
#if !(FEATURE_OSIF_USE_SYSTICK)
FUNC(void, ANFCRL_CODE) SysTick_Handler(void)
{
    sys_tick_cnt++;
}
#endif

FUNC(uint32, ANFCRL_CODE) phGetCurrentTickCount(void){
#if FEATURE_OSIF_USE_SYSTICK
    return OSIF_GetMilliseconds();
#else
    return sys_tick_cnt;
#endif
}

#endif  /* NIDEC_PORTING */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */
// 아래 참고
/* In case of S32K series, startup file takes care of initializing clock and ports.
 * No initialization is required in Other environment. */

#elif defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K11x)
static FUNC(phStatus_t, ANFCRL_CODE) phPlatform_S32K1xx_Init(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status;
    /* Initialize clock */
    PH_CHECK_SUCCESS_FCT(status,
            (phStatus_t)CLOCK_SYS_Init(g_clockManConfigsArr,
                    CLOCK_MANAGER_CONFIG_CNT,
                    g_clockManCallbacksArr,
                    CLOCK_MANAGER_CALLBACK_CNT)
            );
    PH_CHECK_SUCCESS_FCT(status,
            (phStatus_t)CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT));

    phSysTick_Init(1u);
    /* start a free running timer */
    PH_CHECK_SUCCESS_FCT(status, phDriver_TimerStart(PH_DRIVER_TIMER_USECS, 0, NULL));

    /* Initialize log */
#ifdef NXPBUILD__PH_LOG_EX
    PH_CHECK_SUCCESS_FCT(status, phPlatform_Log_Init());
    phLogEx_Init(&sprintf,&phDriver_UARTPutSTR);
#endif
    return status;
}

#else
static FUNC(phStatus_t, ANFCRL_CODE) phPlatform_S32K3xx_Init(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_DRIVER_SUCCESS;
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

    phSysTick_Init(1u);
    /* start a free running timer */
    PH_CHECK_SUCCESS_FCT(status, phDriver_TimerStart(PH_DRIVER_TIMER_USECS, 0, NULL));

    /* Initialize log */
#ifdef NXPBUILD__PH_LOG_EX
    PH_CHECK_SUCCESS_FCT(status, phPlatform_Log_Init());
    phLogEx_Init(&sprintf,&phDriver_UARTPutSTR);
#endif
    return status;
}

#endif /* NIDEC_PORTING */

#ifdef NXPBUILD__PH_LOG_EX
static FUNC(phStatus_t, ANFCRL_CODE) phPlatform_Log_Init(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
#if defined (PHDRIVER_S32K14x)
    /* S32K14x
     * UART configuration for Logging port
     *Channel: LPUART1
     *TX Pin: PTC7
     *RX Pin: PTC6 */
    VAR(pin_settings_config_t, ANFCRL_VAR) g_pin_mux_InitLogArr[2] =
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
    PH_CHECK_SUCCESS_FCT(status, (phStatus_t)PINS_DRV_Init(2, g_pin_mux_InitLogArr));
    /* Initialize LPUART instance */
    PH_CHECK_SUCCESS_FCT(status, (phStatus_t)LPUART_DRV_Init(INST_LPUARTLOG, &lpuartLog_State, &lpuartLog_InitConfig0));
#elif defined (PHDRIVER_S32K11x)
    /* S32K11x
     * UART configuration for Logging port
         *Channel: LPUART1
         *TX Pin: PTB1
         *RX Pin: PTB0 */
    VAR(pin_settings_config_t, ANFCRL_VAR) g_pin_mux_InitLogArr[2] =
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
    PH_CHECK_SUCCESS_FCT(status, (phStatus_t)PINS_DRV_Init(2, g_pin_mux_InitLogArr));
    /* Initialize LPUART instance */
    PH_CHECK_SUCCESS_FCT(status, (phStatus_t)LPUART_DRV_Init(INST_LPUARTLOG, &lpuartLog_State, &lpuartLog_InitConfig0));


#elif defined (PHDRIVER_S32K312)
    /* Initializes an UART driver*/
    Lpuart_Uart_Ip_Init(LPUART_UART_IP_INSTANCE_USING_6, &Lpuart_Uart_Ip_xHwConfigPB_6_BOARD_INITPERIPHERALS);
#endif
    return status;
}
#endif /*NXPBUILD__PH_LOG_EX*/

#ifdef NXPBUILD__PHHAL_HW_NCX3321
FUNC(phStatus_t, ANFCRL_CODE) phApp_Ncx3321_SPIRead(P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
    VAR(uint16, ANFCRL_VAR) wRxLength)
{
  VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) wResponseLen = 0U;

#ifdef PHDRIVER_SOFT_SSEL
    /* Enable chip select connected to reader IC (NSS low). */
    phDriver_PinWrite(PHDRIVER_PIN_SSEL, PH_DRIVER_SET_LOW);
#endif /* PHDRIVER_SOFT_SSEL */

    /* Read back response */
    status =  phbalReg_Exchange(
            &sBalParams,
            PH_EXCHANGE_DEFAULT,
            NULL,
            0U,
            wRxLength,
            pRxBuffer,
            &wResponseLen);

#ifdef PHDRIVER_SOFT_SSEL
    /* Disable chip select connected to reader IC (NSS high). */
    phDriver_PinWrite(PHDRIVER_PIN_SSEL, PH_DRIVER_SET_HIGH);
#endif /* PHDRIVER_SOFT_SSEL */

/* Need Check Point */
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
// phbalReg_Exchange() 함수에서 wResponseLen를 받아가지만
// 내부를 수정하면서 platformSpiExchange() 함수에서 wResponseLen를 return 하지 않음
// 따라서 일단 막아서 사용하고 추가해야 한다고 하면
// platformSpiExchange() 함수에서 wResponseLen를 rerturen 하도록 수정
// WT : wRxLength 로 전달된 Byte수 만큼 Read되는 것이 보장된다면 반드시 적용이 필요하진 않지만
// WT : Read해야하는 갯수만큼 읽었는지 check하는 부분이므로 가능하다면 추가하는 것으로 추천 드립니다.

#else
	if(wResponseLen != wRxLength)
	{
		status = PH_ERR_INTERNAL_ERROR;
	}

#endif	/* NIDEC_PORTING */
    return status;
}

static volatile VAR(uint8, ANFCRL_VAR) bSkipEventPost = 0x0U;
/* Application callback to handle Asynchronous events which cannot be processed by RdLib */
FUNC(void, ANFCRL_CODE) phApp_CallBack(void)
{
    VAR(uint32, ANFCRL_VAR) dwEventStatusReg = 0x0U;
    VAR(uint32,ANFCRL_VAR) dwEventData = 0x0U;
    VAR(uint16, ANFCRL_VAR) wEventLen = 0x0U;
    VAR(uint8, ANFCRL_VAR) bBackUp = 0U;
    VAR(uint8, ANFCRL_VAR) bSPIReadLen = 0U;
    VAR(uint16,ANFCRL_VAR) EventDataSize = 0U;
    VAR(uint16,ANFCRL_VAR) bIndex = 0U;

    /* Event length is of 2 byte @bIndex  2 and 3 */
    wEventLen = (uint16) pHal->sIrqResp.pIsrEvtBuffPtr[2];
    wEventLen <<= 8;
    wEventLen |= ((uint16) pHal->sIrqResp.pIsrEvtBuffPtr[3]);

    /* Event Status is of 4 byte#bIndex 4, 5, 6 and 7 */
    dwEventStatusReg = (uint32) pHal->sIrqResp.pIsrEvtBuffPtr[4];
    dwEventStatusReg |= ((uint32) pHal->sIrqResp.pIsrEvtBuffPtr[5]) << 8U ;
    dwEventStatusReg |= ((uint32) pHal->sIrqResp.pIsrEvtBuffPtr[6]) << 16U;
    dwEventStatusReg |= ((uint32) pHal->sIrqResp.pIsrEvtBuffPtr[7]) << 24U;

    /* Event data size = Length of Data - 4*/
    if (wEventLen > 4U )
    {
        EventDataSize = wEventLen - 4U ;
        for (bIndex = 0U; bIndex < EventDataSize ; bIndex++ )
        {
            dwEventData |= ((uint32) pHal->sIrqResp.pIsrEvtBuffPtr[8U+bIndex]) << (8U*bIndex);
        }
    }
    else
    {
        /* Do nothing , no event data for the corresponding event */
    }
    /* Received Current Error Event */
    if ((dwEventStatusReg & PH_NCX3321_EVT_TX_OVERCURRENT_ERROR) != 0U)
    {
        pHal->HwEventObj.dEventStatus = PH_ERR_ABORTED;
        DEBUG_PRINTF ("\n\tReceived TX Over Current Event... \n");
        return;
    }
    /* Received Boot Event */
    else if ((dwEventStatusReg & PH_NCX3321_EVT_BOOT) != 0U)
    {
        if ((dwEventData & PH_NCX3321_BOOT_TEMP) != 0U)
        {
            /* Boot up Reason due to IC temperature is more than the configured threshold limit*/
            /*  Return Aborted status */
            pHal->HwEventObj.dEventStatus = PH_ERR_ABORTED;
            DEBUG_PRINTF ("\n\tBoot event due to overtemperature... \n");
        }
        else
        {
            /* Do nothing */
        }
        return;
    }
    /* Received CTS Event */
    else if ((dwEventStatusReg & PH_NCX3321_EVT_CTS) != 0U)
    {
        DEBUG_PRINTF ("\n\tReceived CTS Event... \n");
        gwStatus = phhalHw_SetConfig(pHal, PHHAL_HW_NCX3321_CONFIG_CTS_EVENT_STATUS, PH_ON);
        if(gwStatus != PH_ERR_SUCCESS)
        {
            CHECK_STATUS(gwStatus);
            pHal->HwEventObj.dEventStatus = PH_ERR_ABORTED;
            DEBUG_PRINTF("\n\tphApp_CallBack phhalHw_SetConfig failed, aborting... \n");
            return;
        }
        else
        {
            /* Do nothing */
        }
    }
    /* Received RF ON Event */
    else if ((dwEventStatusReg & PH_NCX3321_EVT_RFON_DETECT) != 0U)
    {
        DEBUG_PRINTF ("\n\tReceived RF ON Event... \n");
        gwStatus = phhalHw_SetConfig(pHal, PHHAL_HW_NCX3321_CONFIG_RF_ON_EVENT_STATUS, PH_ON);
        if(gwStatus != PH_ERR_SUCCESS)
        {
            CHECK_STATUS(gwStatus);
            pHal->HwEventObj.dEventStatus = PH_ERR_ABORTED;
            DEBUG_PRINTF("\n\tphApp_CallBack phhalHw_SetConfig failed, aborting... \n");
            return;
        }
        else
        {
            bSkipEventPost = 0x1U;
        }

        bSPIReadLen = (pHal->sIrqResp.bIsrBytesRead -
                (PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN + PHHAL_HW_NCX3321_TYPE_FIELD_LEN +
                PHHAL_HW_NCX3321_LENGTH_FIELD_LEN));

        if (wEventLen > bSPIReadLen)
        {
            bBackUp = pHal->sIrqResp.pIsrEvtBuffPtr[wEventLen - 1u];

            gwStatus = phApp_Ncx3321_SPIRead(&pHal->sIrqResp.pIsrEvtBuffPtr[wEventLen - 1u],
                    (uint16) (wEventLen - bSPIReadLen + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN));
            if(gwStatus != PH_ERR_SUCCESS)
            {
                CHECK_STATUS(gwStatus);
                pHal->HwEventObj.dEventStatus = PH_ERR_ABORTED;
                DEBUG_PRINTF("\n\tSPI read failed, aborting... \n");
                return;
            }

            pHal->sIrqResp.pIsrEvtBuffPtr[wEventLen - 1u] = bBackUp;
        }
    }
    /* Received Unexpected Event */
    else if ((dwEventStatusReg & PH_NCX3321_EVT_UNEXPECTED) != 0U)
    {
        pHal->HwEventObj.dEventStatus = PH_ERR_ABORTED;
        DEBUG_PRINTF ("\n\tReceived Unexpected Event... \n");
        return;
    }
    else
    {
        /* Do nothing */
    }
}

FUNC(phStatus_t, ANFCRL_CODE) phApp_CheckAbort(void)
{
    VAR(phNfcLib_Status_t, ANFCRL_VAR) dwStatus = PH_NFCLIB_STATUS_SUCCESS;
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
    static VAR(uint8, ANFCRL_VAR) bState = 0U;
#ifdef PH_PLATFORM_HAS_ICFRONTEND
    VAR(phNfcLib_AppContext_t, ANFCRL_VAR) AppContext = { 0x00U };
#endif

    if (PH_ON == bAbortRequested)
    {
        if (bState == 0U)
        {
            /* Reset library */
            dwStatus = phNfcLib_DeInit();
            CHECK_NFCLIB_STATUS(dwStatus);

            status = phPlatform_Init();
            CHECK_STATUS(status);

#ifdef PH_PLATFORM_HAS_ICFRONTEND
            status = phbalReg_Init(&sBalParams, (uint16) sizeof(phbalReg_Type_t));
            CHECK_STATUS(status);

            AppContext.pBalDataparams = &sBalParams;
#ifdef NXPBUILD__PHHAL_HW_NCX3321
            AppContext.pHalPollFunc = &phApp_IrqPolling;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
            dwStatus = phNfcLib_SetContext(&AppContext);
            CHECK_NFCLIB_STATUS(dwStatus);
#endif /* PH_PLATFORM_HAS_ICFRONTEND */
            bState = 1U;
        }

        if (bState == 1U)
        {
#if 0 // CAS_KR
            dwStatus = phNfcLib_Init();
#else
            do
            {
                dwStatus = aNfcRdLib_Init_Ncx3321_Init();
            }while(PH_STATUS_INPROCESS == dwStatus);
	        dwStatus = aNfcRdLib_Init_Component_Init();
#endif
            if((uint32) PH_STATUS_INPROCESS == dwStatus)
            {
                return PH_STATUS_INPROCESS;
            }
            CHECK_NFCLIB_STATUS(dwStatus);
            bState = 0U;
        }

        /* Consume abort event */
        (void) phTools_EventClear(&pHal->HwEventObj, E_EVENT_OPT_NONE,
                (E_EVENT_RF | E_EVENT_ABORT),
                NULL);

        /* Set the generic pointer */
        pHal = phNfcLib_GetDataParams(PH_COMP_HAL);

        status = phApp_Configure_IRQ();
        CHECK_STATUS(status);

        bAbortRequested = PH_OFF;

        return PH_ERR_SUCCESS;
    }
    bState = 0U;
    /* Abort action is not requested, do nothing. */
    return PH_STATUS_IDLE;
}

FUNC(void, ANFCRL_CODE) phApp_IrqPolling(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(uint32, ANFCRL_VAR) dwElapsedTime = 0U;

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	bIrqFlag = platformSpiIRQ_ReadDirect();
#endif	/* NIDEC_PORTING */

    (void)(pDataParams);
    /* Read the interrupt status of external interrupt attached to the reader IC IRQ pin */
    if (bIrqFlag != PH_OFF)
    {
        /* Clear interrupt status to avoid missing IRQ raised again */
        bIrqFlag = PH_OFF;
        /* Call application registered callback. */
        if ((pHal->wId == (PH_COMP_HAL | PHHAL_HW_NCX3321_ID)) && (pHal->pRFISRCallback != NULL))
        {
            /* Read the data over SPI */
            gwStatus = phApp_Ncx3321_SPIRead(pHal->sIrqResp.pHandlerModeBuffPtr,
                    (uint16) pHal->sIrqResp.bIsrBytesRead);
            if(gwStatus != PH_ERR_SUCCESS)
            {
                CHECK_STATUS(gwStatus);
                pHal->HwEventObj.dEventStatus = PH_ERR_ABORTED;
                DEBUG_PRINTF ("\n\tSPI read failed, aborting... \n");
                return;
            }
            else
            {
                /* Do nothing */
            }

            /* Handle events triggered by NCX3321 for previous command execution */
            if( pHal->sIrqResp.pHandlerModeBuffPtr[1] == PH_NCX3321_EVT_RSP )
            {
                pHal->sIrqResp.pIsrEvtBuffPtr = pHal->sIrqResp.pHandlerModeBuffPtr;

                /* Call application registered callback to handle NCX3321 Asynchronous events  */
                phApp_CallBack();
                if(gwStatus != PH_ERR_SUCCESS)
                {
                    CHECK_STATUS(gwStatus);
                    pHal->HwEventObj.dEventStatus = PH_ERR_ABORTED;
                    DEBUG_PRINTF ("\n\tphApp_CallBack failed, aborting... \n");
                    return;
                }

                if (bSkipEventPost == 0x0U)
                {
                    /* Call application RF callback to handle NCX3321 synchronous events  */
                    pHal->pRFISRCallback(pHal);
                }
                bSkipEventPost = 0x0U;
            }
            else
            {
                pHal->sIrqResp.pIsrBuffPtr = pHal->sIrqResp.pHandlerModeBuffPtr;

                pHal->pRFISRCallback(pHal);
            }

            if (pHal->sIrqResp.pHandlerModeBuffPtr == &pHal->sIrqResp.aISRReadBuf[0])
            {
                pHal->sIrqResp.pHandlerModeBuffPtr = &pHal->sIrqResp.aISRReadBuf2[0];
            }
            else
            {
                pHal->sIrqResp.pHandlerModeBuffPtr = &pHal->sIrqResp.aISRReadBuf[0];
            }
        }
    }
    if (pHal->bPollGuardTimeFlag == PH_ON)
    {
/* Need Check Point */
	// 현재 타이머 셋팅때문에 계속 무한 루프 돌고 있어서
	// 임시로 조건 변경하여 pTimerISRCallBack() 함수가 실행되게 하였음.
	// 차후 phDriver_GetTimeCurrent() 함수를 수정하여 동작할 수 있도록 해야 함.

/* 10MS_TASK_Check */
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
		if (1)	// 230102. 임시로 무조건 참으로 동작. JJH.
		{
			pHal->HwEventObj.dEventStatus = PH_ERR_SUCCESS;
			pHal->pTimerISRCallBack();
		}

#else
        dwElapsedTime = phDriver_GetTimeElapsed(PH_DRIVER_TIMER_USECS, pHal->wGuardTimeStart);

        /* Check for timer overflow, abort if timer overflow happens */
        if (S32K_TIMER_MAX_32BIT == dwElapsedTime)
        {
            pHal->HwEventObj.dEventStatus = PH_ERR_ABORTED;
        }
        else
        {
            /* GuardTime's Event */
            if (pHal->wGuardTimePeriod < dwElapsedTime)
            {
                pHal->HwEventObj.dEventStatus = PH_ERR_SUCCESS;
                pHal->pTimerISRCallBack();
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
FUNC(phStatus_t, ANFCRL_CODE) phApp_ConfigureLPCD(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
    static VAR(uint8, ANFCRL_VAR) bState = 0;
    if (bState == 0U)
    {
        PH_CHECK_SUCCESS_FCT(status, phhalHw_Ncx3321_Instr_LPCD_SetConfig(pHal,
                PHHAL_HW_CONFIG_SET_LPCD_WAKEUPTIME_MS, PH_NFCRDLIB_LPCD_WAKEUP_CALIB));

        PH_CHECK_SUCCESS_FCT(status, phhalHw_Ncx3321_Instr_LPCD_SetConfig(pHal,
                PHHAL_HW_CONFIG_LPCD_MODE, PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT));

/* LPCD Function Patch */
        PH_CHECK_SUCCESS_FCT(status, phhalHw_Ncx3321_Instr_LPCD_SetConfig(pHal,
                // PHHAL_HW_CONFIG_LPCD_CONFIG, PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD_CALIB));
                PHHAL_HW_CONFIG_LPCD_CONFIG, PHHAL_HW_NCX3321_LPCD_CTRL_LPCD_CALIB));
/* LPCD Function Patch */
        bState = 1U;
    }
    PH_CHECK_INPROCESS_FCT(status, phhalHw_Lpcd(pHal));
    bState = 0U;
    PH_CHECK_SUCCESS(status);

    PH_CHECK_SUCCESS_FCT(status, phhalHw_Ncx3321_Instr_LPCD_SetConfig(pHal,
            PHHAL_HW_CONFIG_SET_LPCD_WAKEUPTIME_MS, PH_NFCRDLIB_LPCD_WAKEUP_PW_DOWN));

    PH_CHECK_SUCCESS_FCT(status, phhalHw_Ncx3321_Instr_LPCD_SetConfig(pHal,
            PHHAL_HW_CONFIG_LPCD_MODE, PHHAL_HW_NCX3321_LPCD_MODE_POWERDOWN));

/* LPCD Function Patch */
    PH_CHECK_SUCCESS_FCT(status, phhalHw_Ncx3321_Instr_LPCD_SetConfig(pHal,
            // PHHAL_HW_CONFIG_LPCD_CONFIG, PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD));
            PHHAL_HW_CONFIG_LPCD_CONFIG, PHHAL_HW_NCX3321_LPCD_CTRL_LPCD));
/* LPCD Function Patch */

    PH_CHECK_SUCCESS_FCT(status, phhalHw_Ncx3321_Instr_LPCD_SetConfig(pHal,
            PHHAL_HW_CONFIG_LPCD_WAKEUP_CTRL, PH_NFCRDLIB_LPCD_EXT_RF_WAKEUP));


    return status;
}

#endif /*NXPBUILD__PHHAL_HW_NCx3320*/

// 아래 함수에서 IRQ Interrupt를 Enable 하는 것으로 보임
// phDriver_PinConfig() 함수 내에서 해당 동작 수행하도록 변경
FUNC(phStatus_t, ANFCRL_CODE) phApp_Configure_IRQ(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status;
    VAR(phDriver_Pin_Config_t, ANFCRL_VAR) pinCfg;
    VAR(phDriver_Interrupt_Config_t, ANFCRL_VAR) irqCfg;

    pinCfg.bOutputLogic = PH_DRIVER_SET_LOW;
    pinCfg.bPullSelect = PHDRIVER_PIN_IRQ_PULL_CFG;

#ifdef NXPBUILD__PHHAL_HW_NCx3320
#if (PIN_IRQ_TRIGGER_TYPE == IRQ_TRIGGER_TYPE_RISINGEDGE)
    irqCfg = (phDriver_Interrupt_Config_t) PH_DRIVER_INTERRUPT_RISINGEDGE;
#else
    irqCfg = (phDriver_Interrupt_Config_t) PH_DRIVER_INTERRUPT_FALLINGEDGE;
#endif /* PIN_IRQ_TRIGGER_TYPE */
#else
    irqCfg = (phDriver_Interrupt_Config_t) PH_DRIVER_INTERRUPT_RISINGEDGE;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

    pinCfg.eInterruptConfig = irqCfg;

    status = phDriver_PinConfig(PHDRIVER_PIN_IRQ, PH_DRIVER_PINFUNC_INTERRUPT, &pinCfg);
    bIrqFlag = PH_OFF;
    gwStatus = PH_ERR_SUCCESS;

#if defined(PHDRIVER_S32K11x) || defined(PHDRIVER_S32K14x)
    INT_SYS_SetPriority(EINT_IRQn, EINT_PRIORITY);
    INT_SYS_ClearPending(EINT_IRQn);
    INT_SYS_EnableIRQ(EINT_IRQn);
#endif /* defined(PHDRIVER_S32Kxxx) */

    if (status == PH_DRIVER_SUCCESS)
    {
        return PH_ERR_SUCCESS;
    }
    else
    {
        return status;
    }
}

/* IRQ Line routine */
FUNC(void, ANFCRL_CODE) CLIF_IRQHandler(void)
{
    /* Read the interrupt status of external interrupt attached to the reader IC IRQ pin */
    if (phDriver_PinRead(PHDRIVER_PIN_IRQ, PH_DRIVER_PINFUNC_INTERRUPT) != 0u)
    {
        bIrqFlag = PH_ON;
    }
    phDriver_PinClearIntStatus(PHDRIVER_PIN_IRQ);
}

/*******************************************************************************
 **   SECTION: HELPER functions
 *******************************************************************************/
/**
 * This function will print buffer content
 * \param   *pBuff   Buffer Reference
 * \param   num      data size to be print
 */
FUNC(void, ANFCRL_CODE) phApp_Print_Buff(
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuff, VAR(uint8, ANFCRL_VAR) num)
{
#ifdef DEBUG
  VAR(uint32, ANFCRL_VAR) i;
    for (i = 0u; i < num; i++)
    {
        DEBUG_PRINTF("%02X", pBuff[i]);
    }
#else /* DEBUG */
    PH_UNUSED_VARIABLE(num);
    PH_UNUSED_VARIABLE(pBuff);
#endif /* DEBUG */
}
#ifdef NXPBUILD__PH_LOG_EX
FUNC(void, ANFCRL_CODE) phDriver_UARTPutSTR(P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) msg)
{
#if defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K11x)
    (void)LPUART_DRV_SendDataPolling(INST_LPUARTLOG, (const uint8 *)msg, strlen(msg));
#endif
#ifdef PHDRIVER_S32K312
    Lpuart_Uart_Ip_StatusType status = LPUART_UART_IP_STATUS_ERROR;
    status = Lpuart_Uart_Ip_SyncSend(LPUART_UART_IP_INSTANCE_USING_6, (const uint8 *)msg, strlen(msg), 10000UL);
    while (LPUART_UART_IP_STATUS_SUCCESS != status);

#endif
}
#endif

