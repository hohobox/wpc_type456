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

#include <phhalHw.h>
#include "phDriver.h"

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "App_NFC.h"
// #include "nfc_platform.h"

#else
#include "BoardSelection.h"

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif (defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K1x))
#include <device_registers.h>
#include <interrupt_manager.h>
#include <clock_manager.h>
#include <lpspi_master_driver.h>
#include <lpspi_hw_access.h>
#include <pins_driver.h>
#include <lpspiCom1.h>

#elif defined (PHDRIVER_S32K312)
#include "Lpspi_Ip.h"
#include "Mcal.h"
#include "SchM_Spi.h"

#endif	/* NIDEC_PORTING */

#define PHBAL_REG_S32K_SPI_ID			0x32U		/**< ID for S32K SPI BAL component */
#define SPI_RETRY_COUNT		1000u

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K312)
static LPSPI_Type* const Lpspi_Ip_apxBases[LPSPI_INSTANCE_COUNT] = IP_LPSPI_BASE_PTRS;
extern Lpspi_Ip_StateStructureType* Lpspi_Ip_apxStateStructureArray[LPSPI_INSTANCE_COUNT];

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#else
static FUNC(void, ANFCRL_CODE) LPSPI_SetFramez(LPSPI_Type * base, VAR(uint16, ANFCRL_VAR) framesize);

#endif	/* NIDEC_PORTING */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif (defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K1x))
static FUNC(void, ANFCRL_CODE) phbalReg_SpiInit(void);

#else
static FUNC(void, ANFCRL_CODE) Lpspi_TransmitTxInit(uint8 Instance,
                                      uint8* TxBuffer,
                                      uint16 NumberOfFrames
                                     );
#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(phStatus_t, ANFCRL_CODE) phbalReg_Init(
		P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
		VAR(uint16, ANFCRL_VAR) wSizeOfDataParams)
{
//  VAR(status_t, ANFCRL_VAR) status = STATUS_SUCCESS;
  VAR(phStatus_t, ANFCRL_VAR) status = PH_DRIVER_SUCCESS;

	if ((pDataParams == NULL)
			|| (sizeof(phbalReg_Type_t) != wSizeOfDataParams)) {
		return (PH_DRIVER_ERROR | PH_COMP_DRIVER);
	}

	((phbalReg_Type_t *) pDataParams)->wId = PH_COMP_DRIVER
			| PHBAL_REG_S32K_SPI_ID;
	((phbalReg_Type_t *) pDataParams)->bBalType = PHBAL_REG_TYPE_SPI;

	// /* Set IRQ Priority for LPSPI interrupt */
	// INT_SYS_SetPriority(PHDRIVER_S32K_LPSPI_IRQ, LPSPI_IRQ_PRIORITY);
	// phbalReg_SpiInit();
	// /* Initialize LPSPI as Master */
	// status = LPSPI_DRV_MasterInit(LPSPICOM1, &lpspiCom1State,
	// 		&lpspiCom1_MasterConfig0);

//	if(status != STATUS_SUCCESS)
	if(status != PH_ERR_SUCCESS)
	{
		return PH_ADD_COMPCODE_FIXED(PH_DRIVER_FAILURE,PH_COMP_DRIVER);
	}
	return PH_ERR_SUCCESS;
}

#elif (defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K1x))
FUNC(phStatus_t, ANFCRL_CODE) phbalReg_Init(
		P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
		VAR(uint16, ANFCRL_VAR) wSizeOfDataParams)
{
  VAR(status_t, ANFCRL_VAR) status = STATUS_SUCCESS;
	if ((pDataParams == NULL)
			|| (sizeof(phbalReg_Type_t) != wSizeOfDataParams)) {
		return (PH_DRIVER_ERROR | PH_COMP_DRIVER);
	}

	((phbalReg_Type_t *) pDataParams)->wId = PH_COMP_DRIVER
			| PHBAL_REG_S32K_SPI_ID;
	((phbalReg_Type_t *) pDataParams)->bBalType = PHBAL_REG_TYPE_SPI;

	/* Set IRQ Priority for LPSPI interrupt */
	INT_SYS_SetPriority(PHDRIVER_S32K_LPSPI_IRQ, LPSPI_IRQ_PRIORITY);
	phbalReg_SpiInit();
	/* Initialize LPSPI as Master */
	status = LPSPI_DRV_MasterInit(LPSPICOM1, &lpspiCom1State,
			&lpspiCom1_MasterConfig0);
	if(status != STATUS_SUCCESS)
	{
		return PH_ADD_COMPCODE_FIXED(PH_DRIVER_FAILURE,PH_COMP_DRIVER);
	}
	return PH_ERR_SUCCESS;
}

#else
FUNC(phStatus_t, ANFCRL_CODE) phbalReg_Init(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wSizeOfDataParams)
{
	Lpspi_Ip_StatusType status = LPSPI_IP_STATUS_SUCCESS;
	if ((pDataParams == NULL)
			|| (sizeof(phbalReg_Type_t) != wSizeOfDataParams)) {
		return (PH_DRIVER_ERROR | PH_COMP_DRIVER);
	}

	((phbalReg_Type_t *) pDataParams)->wId = PH_COMP_DRIVER
			| PHBAL_REG_S32K_SPI_ID;
	((phbalReg_Type_t *) pDataParams)->bBalType = PHBAL_REG_TYPE_SPI;

	status = Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_0_Instance_1_BOARD_InitPeripherals);
	if(status != LPSPI_IP_STATUS_SUCCESS)
	{
		return PH_ADD_COMPCODE_FIXED(PH_DRIVER_FAILURE,PH_COMP_DRIVER);
	}
    /* Update Framesize */
	status = Lpspi_Ip_UpdateFrameSize(&Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_1_BOARD_InitPeripherals, 8U);
	if(status != LPSPI_IP_STATUS_SUCCESS)
	{
		return PH_ADD_COMPCODE_FIXED(PH_DRIVER_FAILURE,PH_COMP_DRIVER);
	}
    /* Update Transfered Bit order */
	status = Lpspi_Ip_UpdateLsb(&Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_1_BOARD_InitPeripherals, FALSE);
	if(status != LPSPI_IP_STATUS_SUCCESS)
	{
		return PH_ADD_COMPCODE_FIXED(PH_DRIVER_FAILURE,PH_COMP_DRIVER);
	}
	return PH_ERR_SUCCESS;
}

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#else
static VAR(void, ANFCRL_VAR) LPSPI_SetFramez(LPSPI_Type * base, VAR(uint16, ANFCRL_VAR) framesize) {
	(base->TCR) = ((base->TCR & (~(uint32) LPSPI_TCR_FRAMESZ_MASK))
			| (framesize & LPSPI_TCR_FRAMESZ_MASK));
}

#endif	/* NIDEC_PORTING */


#define RX_BUFFER_SIZE_MAX	272U /* Receive Buffer size while exchange */
static VAR(uint8, ANFCRL_VAR) g_dummyBuffer[RX_BUFFER_SIZE_MAX];

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(phStatus_t, ANFCRL_CODE) phbalReg_Exchange(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint16, ANFCRL_VAR) wOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
	VAR(uint16, ANFCRL_VAR) wTxLength,
	VAR(uint16, ANFCRL_VAR) wRxBufSize,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength) {
  VAR(phStatus_t, ANFCRL_VAR) status = PH_DRIVER_SUCCESS;
//   VAR(uint16, ANFCRL_VAR) byteReceived = 0u, txCnt = 0u, byteCnt;
  /* Instantiate local variable of type lpspi_state_t and point to global state */
// 	LPSPI_Type *base = g_lpspiBase[LPSPICOM1];
//   VAR(uint32, ANFCRL_VAR) tmpWord, iRetryCount = 0u;

	UNUSED(pDataParams);
	UNUSED(wOption);
	UNUSED(wRxBufSize);

	if(pRxBuffer == NULL)
	{
		pRxBuffer = g_dummyBuffer;
	}

	if(pTxBuffer == NULL)
	{
		wTxLength = wRxBufSize;
		g_dummyBuffer[0] = 0xFF;
		pTxBuffer = g_dummyBuffer;
	}

	platformSpiExchange(pTxBuffer, pRxBuffer, wTxLength);

	return status;
}

#elif (defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K1x))
FUNC(phStatus_t, ANFCRL_CODE) phbalReg_Exchange(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint16, ANFCRL_VAR) wOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
	VAR(uint16, ANFCRL_VAR) wTxLength,
	VAR(uint16, ANFCRL_VAR) wRxBufSize,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength) {
  VAR(phStatus_t, ANFCRL_VAR) status = PH_DRIVER_SUCCESS;
  VAR(uint16, ANFCRL_VAR) byteReceived = 0u, txCnt = 0u, byteCnt;
  /* Instantiate local variable of type lpspi_state_t and point to global state */
	LPSPI_Type *base = g_lpspiBase[LPSPICOM1];
  VAR(uint32, ANFCRL_VAR) tmpWord, iRetryCount = 0u;

	UNUSED(pDataParams);
	UNUSED(wOption);
	UNUSED(wRxBufSize);

	if(pRxBuffer == NULL)
	{
		pRxBuffer = g_dummyBuffer;
	}

	if(pTxBuffer == NULL)
	{
		wTxLength = wRxBufSize;
		g_dummyBuffer[0] = 0xFF;
		pTxBuffer = g_dummyBuffer;
	}

	if (wTxLength > 0U) {
		LPSPI_SetRxWatermarks(base, 0U);
		LPSPI_SetTxWatermarks(base, 3U);

		LPSPI_SetFlushFifoCmd(base, TRUE, TRUE);
		LPSPI_SetFlushFifoCmd(base, TRUE, TRUE);

		LPSPI_SetFramez(base, (wTxLength << 3U) - 1U);
		do {
			if ((LPSPI_GetStatusFlag(base, LPSPI_TX_DATA_FLAG) == TRUE)
					&& (txCnt < wTxLength)) {
				if ((wTxLength - txCnt) > 4u) {
					byteCnt = 4u;
				}
				else
				{
					byteCnt = (wTxLength - txCnt);
				}
				tmpWord = 0u;
				do {
					tmpWord |= ((uint32) pTxBuffer[txCnt])
							<< ((byteCnt - 1U) << 3U);
					byteCnt--;
					txCnt++;
				} while ((byteCnt > 0U) && (txCnt < wTxLength));
				base->TDR = tmpWord;
			}
			if (LPSPI_GetStatusFlag(base, LPSPI_RX_DATA_FLAG) == TRUE) {
				if ((wTxLength - byteReceived) > 4u) {
					byteCnt = 4u;
				}
				else
				{
					byteCnt = (wTxLength - byteReceived);
				}
				tmpWord = base->RDR;
				do
				{
					pRxBuffer[byteReceived] = (uint8) (tmpWord >> ((byteCnt - 1U) << 3U));
					byteCnt--;
					byteReceived++;
				} while ((byteCnt > 0U) && (byteReceived < wTxLength));
			}
			iRetryCount++;
			if (iRetryCount > SPI_RETRY_COUNT) {
				return (PH_DRIVER_TIMEOUT | PH_COMP_DRIVER);
			}
		} while (byteReceived < wTxLength);
	}

	if (pRxLength != NULL) {
		*pRxLength = byteReceived;
	}
	return status;
}

#else
FUNC(phStatus_t, ANFCRL_CODE) phbalReg_Exchange(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer, VAR(uint16, ANFCRL_VAR) wTxLength, VAR(uint16, ANFCRL_VAR) wRxBufSize,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength)
{
  VAR(phStatus_t, ANFCRL_VAR) status = PH_DRIVER_SUCCESS;
  VAR(uint16, ANFCRL_VAR) byteReceived = 0u, txCnt = 0u, byteCnt;
  /* Instantiate local variable of type lpspi_state_t and point to global state */
	Lpspi_Ip_StatusType statusTmp = LPSPI_IP_STATUS_SUCCESS;
	LPSPI_Type *Base;
	Lpspi_Ip_StateStructureType *State;
	const Lpspi_Ip_ExternalDeviceType *ExternalDevice = &Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_1_BOARD_InitPeripherals;
  VAR(uint8, ANFCRL_VAR) Instance = 0u;
  VAR(uint32, ANFCRL_VAR) tmpWord, iRetryCount = 0u;

	UNUSED(pDataParams);
	UNUSED(wOption);
	UNUSED(wRxBufSize);

	Instance = Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_1_BOARD_InitPeripherals.Instance;
	Base = Lpspi_Ip_apxBases[Instance];
	State = Lpspi_Ip_apxStateStructureArray[Instance];
	State->ExternalDevice = ExternalDevice;

	if(pRxBuffer == NULL)
	{
		pRxBuffer = g_dummyBuffer;
	}

	if(pTxBuffer == NULL)
	{
		wTxLength = wRxBufSize;
		g_dummyBuffer[0] = 0xFF;
		pTxBuffer = g_dummyBuffer;
	}

	if (wTxLength > 0U) {

	    /* Update Framesize */
		statusTmp = Lpspi_Ip_UpdateFrameSize(State->ExternalDevice,((uint8)wTxLength << 3U));
    	if(statusTmp != LPSPI_IP_STATUS_SUCCESS)
    	{
    		return PH_ADD_COMPCODE_FIXED(PH_DRIVER_FAILURE,PH_COMP_DRIVER);
    	}
    	/* Disable DMA requests and all interrupts */
	    Base->DER = 0u;
	    Base->IER = 0u;
	    State->CurrentTxFifoSlot = LPSPI_IP_FIFO_SIZE_U8;
	    /* Repair before transmit*/
		Lpspi_TransmitTxInit(Instance, pTxBuffer, wTxLength);
		LPSPI_SetFramez(Base, (wTxLength << 3U) - 1U);

		do {
			/*Check for Tx is available*/
			if ((0u != (Base->SR & LPSPI_SR_TDF_MASK)) && ( txCnt < wTxLength)) {
				if ((wTxLength - txCnt) > 4U) {
					byteCnt = 4u;
				}
				else
				{
					byteCnt = (wTxLength - txCnt);
				}
				tmpWord = 0u;
				do {
					tmpWord |= ((uint32) pTxBuffer[txCnt])
							<< ((byteCnt - 1U) << 3U);
					byteCnt--;
					txCnt++;
				} while ((byteCnt > 0U) && (txCnt < wTxLength));
				/*Push data to FIFO*/
				Base->TDR = tmpWord;
			}

			/*Check for Rx is available*/
			if (0u != (Base->SR & LPSPI_SR_RDF_MASK))
			{
				if ((wTxLength - byteReceived) > 4U) {
						byteCnt = 4u;
				}
				else
				{
					byteCnt = (wTxLength - byteReceived);
				}
				/*Raed data from FIFO*/
				tmpWord = Base->RDR;
				do
				{
					pRxBuffer[byteReceived] = (uint8) (tmpWord >> ((byteCnt - 1U) << 3U));
					byteCnt--;
					byteReceived++;
				} while ((byteCnt > 0U) && (byteReceived < wTxLength));
			}
			iRetryCount++;
			if (iRetryCount > SPI_RETRY_COUNT) {
				return (PH_DRIVER_TIMEOUT | PH_COMP_DRIVER);
			}
		} while (byteReceived < wTxLength);
	}

	if (pRxLength != NULL) {
		*pRxLength = byteReceived;
	}
	return status;
}

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K11x)
/* 사용안함 */

#else
static FUNC(void, ANFCRL_CODE) Lpspi_TransmitTxInit(uint8 Instance,
                                      uint8* TxBuffer,
                                      uint16 NumberOfFrames
                                     )
{
	UNUSED(TxBuffer);
	UNUSED(NumberOfFrames);
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 TransferCommand = 0u;
    uint32 Cfgr1 = 0u;
    uint32 Lsbf = State->ExternalDevice->DeviceParams->Lsb ? 1U : 0U;

    /* Set clock configuration */
    if (TRUE == State->FirstCmd)
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_11();
        /* Disable module before configure CCR */
        Base->CR &= ~LPSPI_CR_MEN_MASK;
        /* Make sure that FIFOs will be empty before start new transfer session */
        #ifdef ERR_IPV_LPSPIV2_0001
            /* ERR050456 workaround: Reset FIFOs using CR[RST] bit */
            /* store CFGR1 and restore after all registers are reset */
            Cfgr1 = Base->CFGR1;
            Base->CR |= LPSPI_CR_RST_MASK;
            Base->CR &= ~LPSPI_CR_RST_MASK;
            /* restore CFGR1 */
            Base->CFGR1 = Cfgr1;
        #else
            Base->CR |= LPSPI_CR_RTF_MASK|LPSPI_CR_RRF_MASK;
        #endif
        /* clear all flags */
        Base->SR &= (uint32)0xFFFFFFFFu;
        /* Does not use the Clock Configuration Register (CCR) for Slave mode */
        #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
        if (FALSE == State->PhyUnitConfig->SlaveMode)
        #endif
        {
            #if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
                Base->CCR = State->ExternalDevice->Ccr[State->ClockMode];
            #else
                Base->CCR = State->ExternalDevice->Ccr;
            #endif
            /* Enable module after configure CCR completed. For Slave mode, it will be enabled after finish configuring TCR regiter */
            Base->CR |= LPSPI_CR_MEN_MASK;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11();
        }
    }
    /* Get transfer command */
    #if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
        TransferCommand = State->ExternalDevice->Tcr[State->ClockMode] | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(Lsbf);
    #else
        TransferCommand = State->ExternalDevice->Tcr | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(Lsbf);
    #endif

    #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
    /* In RX only mode, TX FIFO will be masked, Push CMD to TX FIFO to transfer and pushing CMD will be done in transfer time. Push nothing to TCR register here */
    if (LPSPI_IP_HALF_DUPLEX_RECEIVE != State->ExternalDevice->DeviceParams->TransferType)
    #endif
    {
        #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
        if (LPSPI_IP_HALF_DUPLEX_TRANSMIT == State->ExternalDevice->DeviceParams->TransferType)
        {
            /* Mask RX FIFO in Transmit only mode */
            TransferCommand |= LPSPI_TCR_RXMSK_MASK;
        }
        #endif
        /* In Slave mode, CONT bit should be cleared */
        #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
        if (TRUE == State->PhyUnitConfig->SlaveMode)
        {
            TransferCommand &= ~LPSPI_TCR_CONT_MASK;
        }
        #endif

        if (TRUE == State->FirstCmd)
        {
            /* Set transfer command */
            Base->TCR = TransferCommand;
        }
        else
        {
            if (0u != (TransferCommand & LPSPI_TCR_CONT_MASK))
            {
                Base->TCR = TransferCommand | LPSPI_TCR_CONTC_MASK;
            }
            else
            {
                Base->TCR = TransferCommand;
            }
        }
        /* Enable module after write to TCR in slave mode completed */
        #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
        if (TRUE == State->PhyUnitConfig->SlaveMode)
        {
            Base->CR |= LPSPI_CR_MEN_MASK;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11();
        }
        #endif
        #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
        if (LPSPI_IP_FULL_DUPLEX == State->ExternalDevice->DeviceParams->TransferType)
        #endif
        {
            /* CMD will take 1 slot in TXFIFO, update current TX FIFO slot. it will be plus 1 when the first frames of channel have recieved */
            State->CurrentTxFifoSlot -= 1u;
        }
    }
    #if ((STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT) && (STD_ON == LPSPI_IP_SLAVE_SUPPORT))
    else
    {
        /* In Receive only mode of Slave, a CMD with TXMSK should be push here */
        if (TRUE == State->PhyUnitConfig->SlaveMode)
        {
            /* Mask TX in Transmit only mode */
            TransferCommand |= LPSPI_TCR_TXMSK_MASK;
            TransferCommand &= ~LPSPI_TCR_CONT_MASK;
            Base->TCR = TransferCommand;
            /* Enable module after write to TCR in slave mode completed */
            Base->CR |= LPSPI_CR_MEN_MASK;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11();
        }
    }
    #endif
    /* Update State structure. */
    State->TxIndex = 0u;
    /* In half duplex mode, TX buffer have updated */
    #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
    if (LPSPI_IP_FULL_DUPLEX != State->ExternalDevice->DeviceParams->TransferType)
    {
        /* Avoid misra and compiler warning violation */
        (void)TxBuffer;
    }
    else
    #endif
}

#endif	/* NIDEC_PORTING */


/* 사용안함 */
FUNC(phStatus_t, ANFCRL_CODE) phbalReg_SetConfig(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint16, ANFCRL_VAR) wConfig,
    VAR(uint16, ANFCRL_VAR) wValue)
{
	UNUSED(pDataParams);
	UNUSED(wConfig);
	UNUSED(wValue);
	return PH_DRIVER_SUCCESS;
}

/* 사용안함 */
FUNC(phStatus_t, ANFCRL_CODE) phbalReg_GetConfig(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue) {
	UNUSED(pDataParams);
	UNUSED(wConfig);
	UNUSED(pValue);
	return PH_DRIVER_SUCCESS;
}


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */
// SPI 초기화는 자체적으로 하기 떄문에 사용하지 않음.

#elif (defined (PHDRIVER_S32K14x) || defined (PHDRIVER_S32K1x))
static FUNC(void, ANFCRL_CODE) phbalReg_SpiInit(void) {
  VAR(uint32, ANFCRL_VAR) pinCount = 1;
  VAR(pin_settings_config_t, ANFCRL_VAR) config[1];
  VAR(pin_settings_config_t, ANFCRL_VAR) sPinSpiConfig = { .base = PORTB, .pinPortIdx = 0u,
			.pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
			.passiveFilter = FALSE, .driveSelect = PORT_LOW_DRIVE_STRENGTH,
			.mux = PORT_PIN_DISABLED, .pinLock = FALSE, .intConfig =
					PORT_DMA_INT_DISABLED, .clearIntFlag = FALSE, .gpioBase =
					NULL, .digitalFilter = FALSE, };

	config[0] = sPinSpiConfig;

	/* Configure SCK pin */
	sPinSpiConfig.base = PORT_LPSPI_SCK;
	sPinSpiConfig.pinPortIdx = PIN_NUM_SCK;
	sPinSpiConfig.mux = PIN_MUX_ALT_SCK;
	config[0] = sPinSpiConfig;
	(void) PINS_DRV_Init(pinCount, config);

	/* Configure MISO pin */
	sPinSpiConfig.base = PORT_LPSPI_MISO;
	sPinSpiConfig.pinPortIdx = PIN_NUM_MISO;
	sPinSpiConfig.pullConfig = PORT_INTERNAL_PULL_DOWN_ENABLED;
	sPinSpiConfig.mux = PIN_MUX_ALT_MISO;
	config[0] = sPinSpiConfig;
	(void) PINS_DRV_Init(pinCount, config);

	/* Configure MOSI pin */
	sPinSpiConfig.base = PORT_LPSPI_MOSI;
	sPinSpiConfig.pinPortIdx = PIN_NUM_MOSI;
	sPinSpiConfig.pullConfig = PORT_INTERNAL_PULL_DOWN_ENABLED;
	sPinSpiConfig.mux = PIN_MUX_ALT_MOSI;
	config[0] = sPinSpiConfig;
	(void) PINS_DRV_Init(pinCount, config);
#ifndef PHDRIVER_SOFT_SSEL
	/* Configure PCS pin */
	sPinSpiConfig.base = PORT_LPSPI_PCS;
	sPinSpiConfig.pinPortIdx = PIN_NUM_PCS;
	sPinSpiConfig.mux = PIN_MUX_ALT_PCS;
	config[0] = sPinSpiConfig;
	(void) PINS_DRV_Init(pinCount, config);
#endif /* PHDRIVER_SOFT_SSEL*/
}

#endif	/* NIDEC_PORTING */
