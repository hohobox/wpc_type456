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

#include <phhalHw2.h>
#include "phDriver2.h"

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "App_NFC.h"
// #include "nfc_platform.h"

#else
#include "BoardSelection2.h"

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif (defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K1x2))
#include <device_registers.h>
#include <interrupt_manager.h>
#include <clock_manager.h>
#include <lpspi_master_driver.h>
#include <lpspi_hw_access.h>
#include <pins_driver.h>
#include <lpspiCom1.h>

#elif defined (PHDRIVER_S32K3122)
#include "Lpspi_Ip.h"
#include "Mcal.h"
#include "SchM_Spi.h"

#endif	/* NIDEC_PORTING */

#define PHBAL_REG_S32K_SPI_ID2			0x32U		/**< ID for S32K SPI BAL component */
#define SPI_RETRY_COUNT2		1000u

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K3122)
static LPSPI_Type* const Lpspi_Ip_apxBases2[LPSPI_INSTANCE_COUNT] = IP_LPSPI_BASE_PTRS;
extern Lpspi_Ip_StateStructureType* Lpspi_Ip_apxStateStructureArray2[LPSPI_INSTANCE_COUNT];

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#else
static FUNC(void, ANFCRL_CODE) LPSPI_SetFramez2(LPSPI_Type * base2, VAR(uint16, ANFCRL_VAR) framesize2);

#endif	/* NIDEC_PORTING */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif (defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K1x2))
static FUNC(void, ANFCRL_CODE) phbalReg_SpiInit2(void);

#else
static FUNC(void, ANFCRL_CODE) Lpspi_TransmitTxInit2(uint8 Instance2,
                                      uint8* TxBuffer2,
                                      uint16 NumberOfFrames2
                                     );
#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_Init2(
		P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
		VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2)
{
//  VAR(status_t, ANFCRL_VAR) status2 = STATUS_SUCCESS;
  VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_DRIVER_SUCCESS2;

	if ((pDataParams2 == NULL)
			|| (sizeof(phbalReg_Type_t2) != wSizeOfDataParams2)) {
		return (PH_DRIVER_ERROR2 | PH_COMP_DRIVER2);
	}

	((phbalReg_Type_t2 *) pDataParams2)->wId2 = PH_COMP_DRIVER2
			| PHBAL_REG_S32K_SPI_ID2;
	((phbalReg_Type_t2 *) pDataParams2)->bBalType2 = PHBAL_REG_TYPE_SPI2;

	// /* Set IRQ Priority for LPSPI interrupt */
	// INT_SYS_SetPriority2(PHDRIVER_S32K_LPSPI_IRQ, LPSPI_IRQ_PRIORITY2);
	// phbalReg_SpiInit2();
	// /* Initialize LPSPI as Master */
	// status2 = LPSPI_DRV_MasterInit2(LPSPICOM12, &lpspiCom1State2,
	// 		&lpspiCom1_MasterConfig02);

//	if(status2 != STATUS_SUCCESS)
	if(status2 != PH_ERR_SUCCESS2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_DRIVER_FAILURE2,PH_COMP_DRIVER2);
	}
	return PH_ERR_SUCCESS2;
}

#elif (defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K1x2))
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_Init2(
		P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
		VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2)
{
  VAR(status_t, ANFCRL_VAR) status2 = STATUS_SUCCESS;
	if ((pDataParams2 == NULL)
			|| (sizeof(phbalReg_Type_t2) != wSizeOfDataParams2)) {
		return (PH_DRIVER_ERROR2 | PH_COMP_DRIVER2);
	}

	((phbalReg_Type_t2 *) pDataParams2)->wId2 = PH_COMP_DRIVER2
			| PHBAL_REG_S32K_SPI_ID2;
	((phbalReg_Type_t2 *) pDataParams2)->bBalType2 = PHBAL_REG_TYPE_SPI2;

	/* Set IRQ Priority for LPSPI interrupt */
	INT_SYS_SetPriority(PHDRIVER_S32K_LPSPI_IRQ2, LPSPI_IRQ_PRIORITY2);
	phbalReg_SpiInit2();
	/* Initialize LPSPI as Master */
	status2 = LPSPI_DRV_MasterInit(LPSPICOM1, &lpspiCom1State,
			&lpspiCom1_MasterConfig0);
	if(status2 != STATUS_SUCCESS)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_DRIVER_FAILURE2,PH_COMP_DRIVER2);
	}
	return PH_ERR_SUCCESS2;
}

#else
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_Init2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2)
{
	Lpspi_Ip_StatusType status2 = LPSPI_IP_STATUS_SUCCESS;
	if ((pDataParams2 == NULL)
			|| (sizeof(phbalReg_Type_t2) != wSizeOfDataParams2)) {
		return (PH_DRIVER_ERROR2 | PH_COMP_DRIVER2);
	}

	((phbalReg_Type_t2 *) pDataParams2)->wId2 = PH_COMP_DRIVER2
			| PHBAL_REG_S32K_SPI_ID2;
	((phbalReg_Type_t2 *) pDataParams2)->bBalType2 = PHBAL_REG_TYPE_SPI2;

	status2 = Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_0_Instance_1_BOARD_InitPeripherals);
	if(status2 != LPSPI_IP_STATUS_SUCCESS)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_DRIVER_FAILURE2,PH_COMP_DRIVER2);
	}
    /* Update Framesize */
	status2 = Lpspi_Ip_UpdateFrameSize(&Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_1_BOARD_InitPeripherals, 8U);
	if(status2 != LPSPI_IP_STATUS_SUCCESS)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_DRIVER_FAILURE2,PH_COMP_DRIVER2);
	}
    /* Update Transfered Bit order */
	status2 = Lpspi_Ip_UpdateLsb(&Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_1_BOARD_InitPeripherals, FALSE);
	if(status2 != LPSPI_IP_STATUS_SUCCESS)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_DRIVER_FAILURE2,PH_COMP_DRIVER2);
	}
	return PH_ERR_SUCCESS2;
}

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#else
static VAR(void, ANFCRL_VAR) LPSPI_SetFramez2(LPSPI_Type * base2, VAR(uint16, ANFCRL_VAR) framesize2) {
	(base2->TCR) = ((base2->TCR & (~(uint32) LPSPI_TCR_FRAMESZ_MASK))
			| (framesize2 & LPSPI_TCR_FRAMESZ_MASK));
}
#endif	/* NIDEC_PORTING */



#define RX_BUFFER_SIZE_MAX2	272U /* Receive Buffer size while exchange */
static VAR(uint8, ANFCRL_VAR) g_dummyBuffer2[RX_BUFFER_SIZE_MAX2];

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_Exchange2(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
	VAR(uint16, ANFCRL_VAR) wOption2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
	VAR(uint16, ANFCRL_VAR) wTxLength2,
	VAR(uint16, ANFCRL_VAR) wRxBufSize2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2) {
  VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_DRIVER_SUCCESS2;
//   VAR(uint16, ANFCRL_VAR) byteReceived2 = 0u, txCnt2 = 0u, byteCnt2;
  /* Instantiate local variable of type lpspi_state_t and point to global state */
// 	LPSPI_Type *base2 = g_lpspiBase[LPSPICOM1];
//   VAR(uint32, ANFCRL_VAR) tmpWord2, iRetryCount2 = 0u;

	UNUSED2(pDataParams2);
	UNUSED2(wOption2);
	UNUSED2(wRxBufSize2);

	if(pRxBuffer2 == NULL)
	{
		pRxBuffer2 = g_dummyBuffer2;
	}

	if(pTxBuffer2 == NULL)
	{
		wTxLength2 = wRxBufSize2;
		g_dummyBuffer2[0] = 0xFF;
		pTxBuffer2 = g_dummyBuffer2;
	}

	platformSpiExchange2(pTxBuffer2, pRxBuffer2, wTxLength2);

	return status2;
}

#elif (defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K1x2))
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_Exchange2(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
	VAR(uint16, ANFCRL_VAR) wOption2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
	VAR(uint16, ANFCRL_VAR) wTxLength2,
	VAR(uint16, ANFCRL_VAR) wRxBufSize2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2) {
  VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_DRIVER_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) byteReceived2 = 0u, txCnt2 = 0u, byteCnt2;
  /* Instantiate local variable of type lpspi_state_t and point to global state */
	LPSPI_Type *base2 = g_lpspiBase[LPSPICOM1];
  VAR(uint32, ANFCRL_VAR) tmpWord2, iRetryCount2 = 0u;

	UNUSED2(pDataParams2);
	UNUSED2(wOption2);
	UNUSED2(wRxBufSize2);

	if(pRxBuffer2 == NULL)
	{
		pRxBuffer2 = g_dummyBuffer2;
	}

	if(pTxBuffer2 == NULL)
	{
		wTxLength2 = wRxBufSize2;
		g_dummyBuffer2[0] = 0xFF;
		pTxBuffer2 = g_dummyBuffer2;
	}

	if (wTxLength2 > 0U) {
		LPSPI_SetRxWatermarks(base2, 0U);
		LPSPI_SetTxWatermarks(base2, 3U);

		LPSPI_SetFlushFifoCmd(base2, TRUE, TRUE);
		LPSPI_SetFlushFifoCmd(base2, TRUE, TRUE);

		LPSPI_SetFramez2(base2, (wTxLength2 << 3U) - 1U);
		do {
			if ((LPSPI_GetStatusFlag(base2, LPSPI_TX_DATA_FLAG) == TRUE)
					&& (txCnt2 < wTxLength2)) {
				if ((wTxLength2 - txCnt2) > 4u) {
					byteCnt2 = 4u;
				}
				else
				{
					byteCnt2 = (wTxLength2 - txCnt2);
				}
				tmpWord2 = 0u;
				do {
					tmpWord2 |= ((uint32) pTxBuffer2[txCnt2])
							<< ((byteCnt2 - 1U) << 3U);
					byteCnt2--;
					txCnt2++;
				} while ((byteCnt2 > 0U) && (txCnt2 < wTxLength2));
				base2->TDR = tmpWord2;
			}
			if (LPSPI_GetStatusFlag(base2, LPSPI_RX_DATA_FLAG) == TRUE) {
				if ((wTxLength2 - byteReceived2) > 4u) {
					byteCnt2 = 4u;
				}
				else
				{
					byteCnt2 = (wTxLength2 - byteReceived2);
				}
				tmpWord2 = base2->RDR;
				do
				{
					pRxBuffer2[byteReceived2] = (uint8) (tmpWord2 >> ((byteCnt2 - 1U) << 3U));
					byteCnt2--;
					byteReceived2++;
				} while ((byteCnt2 > 0U) && (byteReceived2 < wTxLength2));
			}
			iRetryCount2++;
			if (iRetryCount2 > SPI_RETRY_COUNT2) {
				return (PH_DRIVER_TIMEOUT2 | PH_COMP_DRIVER2);
			}
		} while (byteReceived2 < wTxLength2);
	}

	if (pRxLength2 != NULL) {
		*pRxLength2 = byteReceived2;
	}
	return status2;
}

#else
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_Exchange2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint16, ANFCRL_VAR) wOption2,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2, VAR(uint16, ANFCRL_VAR) wTxLength2, VAR(uint16, ANFCRL_VAR) wRxBufSize2,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2)
{
  VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_DRIVER_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) byteReceived2 = 0u, txCnt2 = 0u, byteCnt2;
  /* Instantiate local variable of type lpspi_state_t and point to global state */
	Lpspi_Ip_StatusType statusTmp2 = LPSPI_IP_STATUS_SUCCESS;
	LPSPI_Type *Base2;
	Lpspi_Ip_StateStructureType *State2;
	const Lpspi_Ip_ExternalDeviceType *ExternalDevice2 = &Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_1_BOARD_InitPeripherals;
  VAR(uint8, ANFCRL_VAR) Instance2 = 0u;
  VAR(uint32, ANFCRL_VAR) tmpWord2, iRetryCount2 = 0u;

	UNUSED2(pDataParams2);
	UNUSED2(wOption2);
	UNUSED2(wRxBufSize2);

	Instance2 = Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_1_BOARD_InitPeripherals.Instance2;
	Base2 = Lpspi_Ip_apxBases2[Instance2];
	State2 = Lpspi_Ip_apxStateStructureArray2[Instance2];
	State2->ExternalDevice = ExternalDevice2;

	if(pRxBuffer2 == NULL)
	{
		pRxBuffer2 = g_dummyBuffer2;
	}

	if(pTxBuffer2 == NULL)
	{
		wTxLength2 = wRxBufSize2;
		g_dummyBuffer2[0] = 0xFF;
		pTxBuffer2 = g_dummyBuffer2;
	}

	if (wTxLength2 > 0U) {

	    /* Update Framesize */
		statusTmp2 = Lpspi_Ip_UpdateFrameSize(State2->ExternalDevice,((uint8)wTxLength2 << 3U));
    	if(statusTmp2 != LPSPI_IP_STATUS_SUCCESS)
    	{
    		return PH_ADD_COMPCODE_FIXED2(PH_DRIVER_FAILURE2,PH_COMP_DRIVER2);
    	}
    	/* Disable DMA requests and all interrupts */
	    Base2->DER = 0u;
	    Base2->IER = 0u;
	    State2->CurrentTxFifoSlot = LPSPI_IP_FIFO_SIZE_U8;
	    /* Repair before transmit*/
		Lpspi_TransmitTxInit2(Instance2, pTxBuffer2, wTxLength2);
		LPSPI_SetFramez2(Base2, (wTxLength2 << 3U) - 1U);

		do {
			/*Check for Tx is available*/
			if ((0u != (Base2->SR & LPSPI_SR_TDF_MASK)) && ( txCnt2 < wTxLength2)) {
				if ((wTxLength2 - txCnt2) > 4U) {
					byteCnt2 = 4u;
				}
				else
				{
					byteCnt2 = (wTxLength2 - txCnt2);
				}
				tmpWord2 = 0u;
				do {
					tmpWord2 |= ((uint32) pTxBuffer2[txCnt2])
							<< ((byteCnt2 - 1U) << 3U);
					byteCnt2--;
					txCnt2++;
				} while ((byteCnt2 > 0U) && (txCnt2 < wTxLength2));
				/*Push data to FIFO*/
				Base2->TDR = tmpWord2;
			}

			/*Check for Rx is available*/
			if (0u != (Base2->SR & LPSPI_SR_RDF_MASK))
			{
				if ((wTxLength2 - byteReceived2) > 4U) {
						byteCnt2 = 4u;
				}
				else
				{
					byteCnt2 = (wTxLength2 - byteReceived2);
				}
				/*Raed data from FIFO*/
				tmpWord2 = Base2->RDR;
				do
				{
					pRxBuffer2[byteReceived2] = (uint8) (tmpWord2 >> ((byteCnt2 - 1U) << 3U));
					byteCnt2--;
					byteReceived2++;
				} while ((byteCnt2 > 0U) && (byteReceived2 < wTxLength2));
			}
			iRetryCount2++;
			if (iRetryCount2 > SPI_RETRY_COUNT2) {
				return (PH_DRIVER_TIMEOUT2 | PH_COMP_DRIVER2);
			}
		} while (byteReceived2 < wTxLength2);
	}

	if (pRxLength2 != NULL) {
		*pRxLength2 = byteReceived2;
	}
	return status2;
}

#endif	/* NIDEC_PORTING */


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */

#elif defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K11x2)
/* 사용안함 */

#else
static FUNC(void, ANFCRL_CODE) Lpspi_TransmitTxInit2(uint8 Instance2,
                                      uint8* TxBuffer2,
                                      uint16 NumberOfFrames2
                                     )
{
	UNUSED2(TxBuffer2);
	UNUSED2(NumberOfFrames2);
    LPSPI_Type* Base2 = Lpspi_Ip_apxBases2[Instance2];
    Lpspi_Ip_StateStructureType* State2 = Lpspi_Ip_apxStateStructureArray2[Instance2];
    uint32 TransferCommand = 0u;
    uint32 Cfgr1 = 0u;
    uint32 Lsbf = State2->ExternalDevice->DeviceParams->Lsb ? 1U : 0U;

    /* Set clock configuration */
    if (TRUE == State2->FirstCmd)
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_11();
        /* Disable module before configure CCR */
        Base2->CR &= ~LPSPI_CR_MEN_MASK;
        /* Make sure that FIFOs will be empty before start new transfer session */
        #ifdef ERR_IPV_LPSPIV2_0001
            /* ERR050456 workaround: Reset FIFOs using CR[RST] bit */
            /* store CFGR1 and restore after all registers are reset */
            Cfgr1 = Base2->CFGR1;
            Base2->CR |= LPSPI_CR_RST_MASK;
            Base2->CR &= ~LPSPI_CR_RST_MASK;
            /* restore CFGR1 */
            Base2->CFGR1 = Cfgr1;
        #else
            Base2->CR |= LPSPI_CR_RTF_MASK|LPSPI_CR_RRF_MASK;
        #endif
        /* clear all flags */
        Base2->SR &= (uint32)0xFFFFFFFFu;
        /* Does not use the Clock Configuration Register (CCR) for Slave mode */
        #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
        if (FALSE == State2->PhyUnitConfig->SlaveMode)
        #endif
        {
            #if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
                Base2->CCR = State2->ExternalDevice->Ccr[State2->ClockMode];
            #else
                Base2->CCR = State2->ExternalDevice->Ccr;
            #endif
            /* Enable module after configure CCR completed. For Slave mode, it will be enabled after finish configuring TCR regiter */
            Base2->CR |= LPSPI_CR_MEN_MASK;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11();
        }
    }
    /* Get transfer command */
    #if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
        TransferCommand = State2->ExternalDevice->Tcr[State2->ClockMode] | LPSPI_TCR_FRAMESZ((uint32)State2->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(Lsbf);
    #else
        TransferCommand = State2->ExternalDevice->Tcr | LPSPI_TCR_FRAMESZ((uint32)State2->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(Lsbf);
    #endif

    #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
    /* In RX only mode, TX FIFO will be masked, Push CMD to TX FIFO to transfer and pushing CMD will be done in transfer time. Push nothing to TCR register here */
    if (LPSPI_IP_HALF_DUPLEX_RECEIVE != State2->ExternalDevice->DeviceParams->TransferType)
    #endif
    {
        #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
        if (LPSPI_IP_HALF_DUPLEX_TRANSMIT == State2->ExternalDevice->DeviceParams->TransferType)
        {
            /* Mask RX FIFO in Transmit only mode */
            TransferCommand |= LPSPI_TCR_RXMSK_MASK;
        }
        #endif
        /* In Slave mode, CONT bit should be cleared */
        #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
        if (TRUE == State2->PhyUnitConfig->SlaveMode)
        {
            TransferCommand &= ~LPSPI_TCR_CONT_MASK;
        }
        #endif

        if (TRUE == State2->FirstCmd)
        {
            /* Set transfer command */
            Base2->TCR = TransferCommand;
        }
        else
        {
            if (0u != (TransferCommand & LPSPI_TCR_CONT_MASK))
            {
                Base2->TCR = TransferCommand | LPSPI_TCR_CONTC_MASK;
            }
            else
            {
                Base2->TCR = TransferCommand;
            }
        }
        /* Enable module after write to TCR in slave mode completed */
        #if (STD_ON == LPSPI_IP_SLAVE_SUPPORT)
        if (TRUE == State2->PhyUnitConfig->SlaveMode)
        {
            Base2->CR |= LPSPI_CR_MEN_MASK;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11();
        }
        #endif
        #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
        if (LPSPI_IP_FULL_DUPLEX == State2->ExternalDevice->DeviceParams->TransferType)
        #endif
        {
            /* CMD will take 1 slot in TXFIFO, update current TX FIFO slot. it will be plus 1 when the first frames of channel have recieved */
            State2->CurrentTxFifoSlot -= 1u;
        }
    }
    #if ((STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT) && (STD_ON == LPSPI_IP_SLAVE_SUPPORT))
    else
    {
        /* In Receive only mode of Slave, a CMD with TXMSK should be push here */
        if (TRUE == State2->PhyUnitConfig->SlaveMode)
        {
            /* Mask TX in Transmit only mode */
            TransferCommand |= LPSPI_TCR_TXMSK_MASK;
            TransferCommand &= ~LPSPI_TCR_CONT_MASK;
            Base2->TCR = TransferCommand;
            /* Enable module after write to TCR in slave mode completed */
            Base2->CR |= LPSPI_CR_MEN_MASK;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11();
        }
    }
    #endif
    /* Update State2 structure. */
    State2->TxIndex = 0u;
    /* In half duplex mode, TX buffer have updated */
    #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
    if (LPSPI_IP_FULL_DUPLEX != State2->ExternalDevice->DeviceParams->TransferType)
    {
        /* Avoid misra and compiler warning violation */
        (void)TxBuffer2;
    }
    else
    #endif
}

#endif	/* NIDEC_PORTING */


/* 사용안함 */
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_SetConfig2(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
	VAR(uint16, ANFCRL_VAR) wConfig2,
    VAR(uint16, ANFCRL_VAR) wValue2)
{
	UNUSED2(pDataParams2);
	UNUSED2(wConfig2);
	UNUSED2(wValue2);
	return PH_DRIVER_SUCCESS2;
}

/* 사용안함 */
FUNC(phStatus_t2, ANFCRL_CODE) phbalReg_GetConfig2(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint16, ANFCRL_VAR) wConfig2,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2) {
	UNUSED2(pDataParams2);
	UNUSED2(wConfig2);
	UNUSED2(pValue2);
	return PH_DRIVER_SUCCESS2;
}


#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
/* 사용안함 */
// SPI 초기화는 자체적으로 하기 떄문에 사용하지 않음.

#elif (defined (PHDRIVER_S32K14x2) || defined (PHDRIVER_S32K1x2))
static FUNC(void, ANFCRL_CODE) phbalReg_SpiInit2(void) {
  VAR(uint32, ANFCRL_VAR) pinCount2 = 1;
  VAR(pin_settings_config_t, ANFCRL_VAR) config2[1];
  VAR(pin_settings_config_t, ANFCRL_VAR) sPinSpiConfig2 = { .base = PORTB, .pinPortIdx = 0u,
			.pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
			.passiveFilter = FALSE, .driveSelect = PORT_LOW_DRIVE_STRENGTH,
			.mux = PORT_PIN_DISABLED, .pinLock = FALSE, .intConfig =
					PORT_DMA_INT_DISABLED, .clearIntFlag = FALSE, .gpioBase =
					NULL, .digitalFilter = FALSE, };

	config2[0] = sPinSpiConfig2;

	/* Configure SCK pin */
	sPinSpiConfig2.base = PORT_LPSPI_SCK2;
	sPinSpiConfig2.pinPortIdx = PIN_NUM_SCK2;
	sPinSpiConfig2.mux = PIN_MUX_ALT_SCK2;
	config2[0] = sPinSpiConfig2;
	(void) PINS_DRV_Init(pinCount2, config2);

	/* Configure MISO pin */
	sPinSpiConfig2.base = PORT_LPSPI_MISO2;
	sPinSpiConfig2.pinPortIdx = PIN_NUM_MISO2;
	sPinSpiConfig2.pullConfig = PORT_INTERNAL_PULL_DOWN_ENABLED;
	sPinSpiConfig2.mux = PIN_MUX_ALT_MISO2;
	config2[0] = sPinSpiConfig2;
	(void) PINS_DRV_Init(pinCount2, config2);

	/* Configure MOSI pin */
	sPinSpiConfig2.base = PORT_LPSPI_MOSI2;
	sPinSpiConfig2.pinPortIdx = PIN_NUM_MOSI2;
	sPinSpiConfig2.pullConfig = PORT_INTERNAL_PULL_DOWN_ENABLED;
	sPinSpiConfig2.mux = PIN_MUX_ALT_MOSI2;
	config2[0] = sPinSpiConfig2;
	(void) PINS_DRV_Init(pinCount2, config2);
#ifndef PHDRIVER_SOFT_SSEL2
	/* Configure PCS pin */
	sPinSpiConfig2.base = PORT_LPSPI_PCS2;
	sPinSpiConfig2.pinPortIdx = PIN_NUM_PCS2;
	sPinSpiConfig2.mux = PIN_MUX_ALT_PCS2;
	config2[0] = sPinSpiConfig2;
	(void) PINS_DRV_Init(pinCount2, config2);
#endif /* PHDRIVER_SOFT_SSEL2*/
}

#endif	/* NIDEC_PORTING */
