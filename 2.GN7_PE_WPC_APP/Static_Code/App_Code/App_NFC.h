/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/

#ifndef  APP_NFC_H
#define  APP_NFC_H

/***************************************************************************************************
    INCLUDE FILES
***************************************************************************************************/
 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"
#include "EcuInfo.h"

#include "Spi.h"

/***************************************************************************************************
    GLOBAL DEFINES AND MACROS
***************************************************************************************************/
#define NIDEC_PORTING /* NIDEC_PORTING */

/****************************************************************
 TCI Code define (변경 불필요. 고정값임.)
****************************************************************/
#define cTCI_Code1          0x6A // VASUP-A (VAS Wakeup A)
#define cTCI_Code2          0x02 // fromat : Data format version ’02’
#define cTCI_Code3          0xC3 // Terminal Info : b8(1):VAS Not Supported, b7(1):User Auto Not Requested, b4~b1(11):Length of Terminal Type Data field(0 ~ 15)
#define cTCI_Code4          0x02 // Terminal Type :
#define cTCI_Code5          0x01 // Terminal Sub-Type :

#if defined (TCI_Code_Hyundai)
    #define cTCI_Code6      0x01
    #define cTCI_Code7      0x03
    #define cTCI_Code8      0x03

#elif defined (TCI_Code_Kia)
    #define cTCI_Code6      0x01
    #define cTCI_Code7      0x00
    #define cTCI_Code8      0x43

#elif defined (TCI_Code_Genesis)
    #define cTCI_Code6      0x01
    #define cTCI_Code7      0x00
    #define cTCI_Code8      0x53
#else
    Error : not defined
#endif

/******************************************************************
 * S32K116Ncx3321 Board Pin/Gpio configurations
 ******************************************************************/
// NXP Board 관련 값이지만 코드 단순화를 위해 define하여 사용
#define PHDRIVER_PIN_RESET  0x11111111u
#define PHDRIVER_PIN_IRQ    0x22222222u
#define PHDRIVER_PIN_SSEL   0x33333333u
#define PHDRIVER_PIN_BUSY   PHDRIVER_PIN_IRQ
#define PHDRIVER_PIN_GPIO 	0x44444444u

#define PHDRIVER_PIN_RESET2  0x11111111u
#define PHDRIVER_PIN_IRQ2    0x22222222u
#define PHDRIVER_PIN_SSEL2   0x33333333u
#define PHDRIVER_PIN_BUSY2   PHDRIVER_PIN_IRQ2
#define PHDRIVER_PIN_GPIO2 	0x44444444u


/******************************************************************
 * PIN Pull-Up/Pull-Down configurations.
 ******************************************************************/
#define PHDRIVER_PIN_RESET_PULL_CFG    PH_DRIVER_PULL_UP
#define PHDRIVER_PIN_IRQ_PULL_CFG      PH_DRIVER_PULL_DOWN
#define PHDRIVER_PIN_NSS_PULL_CFG      PH_DRIVER_PULL_UP

#define PHDRIVER_PIN_WKUP_PULL_CFG     PH_DRIVER_PULL_UP
#define PHDRIVER_PIN_CLK_PULL_CFG      PH_DRIVER_PULL_UP
#define PHDRIVER_PIN_DWL_PULL_CFG      PH_DRIVER_PULL_UP
#define PHDRIVER_PIN_BUSY_PULL_CFG     PH_DRIVER_PULL_UP

#define PHDRIVER_PIN_RESET_PULL_CFG2    PH_DRIVER_PULL_UP2
#define PHDRIVER_PIN_IRQ_PULL_CFG2      PH_DRIVER_PULL_DOWN2
#define PHDRIVER_PIN_NSS_PULL_CFG2      PH_DRIVER_PULL_UP2

#define PHDRIVER_PIN_WKUP_PULL_CFG2     PH_DRIVER_PULL_UP2
#define PHDRIVER_PIN_CLK_PULL_CFG2      PH_DRIVER_PULL_UP2
#define PHDRIVER_PIN_DWL_PULL_CFG2      PH_DRIVER_PULL_UP2
#define PHDRIVER_PIN_BUSY_PULL_CFG2     PH_DRIVER_PULL_UP2

/******************************************************************
 * IRQ PIN NVIC settings
 ******************************************************************/
#define IRQ_TRIGGER_TYPE_RISINGEDGE 	3U
#define IRQ_TRIGGER_TYPE_FALLINGEDGE	4U
#define PIN_IRQ_TRIGGER_TYPE      IRQ_TRIGGER_TYPE_RISINGEDGE

#define IRQ_TRIGGER_TYPE_RISINGEDGE2 	3U
#define IRQ_TRIGGER_TYPE_FALLINGEDGE2	4U
#define PIN_IRQ_TRIGGER_TYPE2      IRQ_TRIGGER_TYPE_RISINGEDGE2

/*****************************************************************
 * Front End Reset logic level settings
 ****************************************************************/
#define PH_DRIVER_SET_HIGH            1          /**< Logic High. */
#define PH_DRIVER_SET_LOW             0          /**< Logic Low. */
#define RESET_POWERDOWN_LEVEL         PH_DRIVER_SET_LOW
#define RESET_POWERUP_LEVEL           PH_DRIVER_SET_HIGH

#define PH_DRIVER_SET_HIGH2            1          /**< Logic High. */
#define PH_DRIVER_SET_LOW2             0          /**< Logic Low. */
#define RESET_POWERDOWN_LEVEL2         PH_DRIVER_SET_LOW2
#define RESET_POWERUP_LEVEL2           PH_DRIVER_SET_HIGH2


// SPI 통신 관련
// MPP : WCT1 : NFC2
// EPP : WCT2 : NFC1

/* phbalReg_Exchange */
#define platformSpiExchange(pTxBuffer, pRxBuffer, wTxLength)    do{gs_SPI_TxRx(SpiChannel_NFC1, pTxBuffer, pRxBuffer, wTxLength); }while(0) // WPC_429_03
#define platformSpiExchange2(pTxBuffer, pRxBuffer, wTxLength)   do{gs_SPI_TxRx(SpiChannel_NFC2, pTxBuffer, pRxBuffer, wTxLength); }while(0) // WPC_429_03
// #endif

/* phDriver_PinRead */
#define platformSpiIRQ_ReadDirect()                             gs_NFC_IRQ_ReadDirect()
#define platformSpiIRQ_ReadDirect2()                            gs_NFC_IRQ_ReadDirect2()

/* phDriver_PinWrite */
#define platformSpiWAKEUP_WriteDirect(level)                    gs_NFC_WAKEUP_WriteDirect(level)
#define platformSpiWAKEUP_WriteDirect2(level)                   gs_NFC_WAKEUP_WriteDirect2(level)

/* phDriver_PinConfig */
// #define platformSpiIRQ_Enable()                                 gs_NFC_IRQ_Enable() // WPC_429_03
// #define platformSpiIRQ_Enable2()                                gs_NFC_IRQ_Enable() // WPC_429_03

/* phDriver_TimerStop */
// #define platformSpiIRQ_Disable()                                gs_NFC_IRQ_Disable() // WPC_429_03
// #define platformSpiIRQ_Disable2()                               gs_NFC_IRQ_Disable() // WPC_429_03


typedef enum
{
	cIAUWPCNFC_Default,
	cIAUWPCNFC_Polling,
	cIAUWPCNFC_Deselect,
	cIAUWPCNFC_Invalid = 7
} IAUWPCNFCcmd_ENUM_t;


typedef enum
{
	cIAUStatus_Idle,
	cIAUStatus_ProcessWPC,
	cIAUStatus_Invalid = 7
} IAUStatus_ENUM_t;

typedef enum
{
	cNFCDetect_Off,
	cNFCDetect_Detected,
	cNFCDetect_NotDetected
} NFCDetection_ENUM_t;

typedef enum
{
	cNFCReset_Default,
	cNFCReset_Complete
} NFCReset_ENUM_t;



typedef enum
{
	cCardProtectionResult_Default,
	cCardProtectionResult_ProhibitCharging,
    cCardProtectionResult_AllowCharging
} CardProtectionResult_ENUM_t;

/***************************************************************************************************
    GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/



/***************************************************************************************************
    GLOBAL VARIABLE AND CONSTANTS DECLARATIONS
***************************************************************************************************/
//extern uint32_t	GptCounter_1ms; // GN7.0D_08
//extern uint32_t	GptCounter_10ms;

#if defined (DEBUG_TUNE_MODE_USE)
extern uint16_t Tune_LPCD_RSSI_TARGET;
extern uint8_t Tune_LPCD_AVG_SAMPLE_NUM;
extern uint8_t Tune_LPCD_VDDPA;
extern uint8_t Tune_LPCD_PULSE_WIDTH;
extern uint8_t Tune_LPCD_THRESHOLD_I;
extern uint8_t Tune_LPCD_THRESHOLD_Q;
extern uint8_t Tune_VDDPA_HIGH_VALUE;
#endif

/***************************************************************************************************
    GLOBAL FUNCTION PROTOTYPES
***************************************************************************************************/
extern void gs_App_NFC_L2H_Set(void);
extern void gs_App_NFC_H2L_Set(void);

extern uint8_t gs_NFC_IRQ_ReadDirect(void);
extern uint8_t gs_NFC_IRQ_ReadDirect2(void);

// void gs_NFC_IRQ_Enable(void); // WPC_429_03 // GN7.0D_05
// void gs_NFC_IRQ_Disable(void);// WPC_429_03 // GN7.0D_05

extern uint8_t gs_SPI_TxRx(uint8_t Channel, const uint8_t * TxBuf, uint8_t* RxBuf, uint16_t TxRxLength);

extern void gs_NFC_WAKEUP_WriteDirect(uint8_t level);
extern void gs_NFC_WAKEUP_WriteDirect2(uint8_t level);

//extern uint8_t gs_Get_NFC_PollState(uint8_t Device);// GN7.14_02
//extern uint8_t gs_Get_NfcStateCurr(uint8_t Device); // GN7.17_08
extern uint8_t Get_CanTpRxComplete(void);
extern uint8_t* Get_CanTpRxBuf(void);
//extern uint8_t Get_CanTpRxSize(void);

extern void NXP_LPCD_MainControl(void);
extern void NXP_LPCD_MainControl_Init(void);

extern uint16_t NXP_NFC_MainControl(uint8_t dataExchange, uint8_t* pTxBuff, uint16_t length);	/* NXP Module 230215 */
extern void NXP_NFC_MainControl_Init(void);

extern uint16_t NXP_PICC_MainControl(void);
extern void NXP_PICC_MainControl_Init(void);

extern uint8_t Get_NXP_NFC_DetectCheck(void);
extern uint8_t Get_NXP_NFC_DataExchangeCheck(void);
extern uint8_t * Get_NXP_NFC_CanTpTxBuf(void);
extern uint8_t Get_NXP_NFC_CanTpTxSize(void);
extern uint8_t Get_NXP_LPCD_WakeupCheck(void);
extern uint8_t Get_NXP_PICC_OnThePad(void);
extern uint8_t Get_NXP_NfcModeExitReady(void);		// 230509

extern uint8_t Get_NXP_NFC_CommunicationErrorsCheck(void);		// 230503. JJH. NFC Communication Error
extern uint16_t Get_NXP_NFC_CommunicationErrorsStatus(void);   // 230503. JJH. NFC Communication Error
extern void Reset_NXP_NFC_CommunicationErrors(void);       	// 230503. JJH

// extern uint16_t NXP_CardProtection_MainControl_Init(void);
// extern uint8_t NXP_CardProtection_MainControl(void);
extern uint16_t NXP_CardProtection_MainControl(void);

/***************************************************************************************************
    Dual NFC Function Set
***************************************************************************************************/
extern void NXP_LPCD_MainControl2(void);
extern void NXP_LPCD_MainControl_Init2(void);

extern uint16_t NXP_NFC_MainControl2(uint8_t dataExchange, uint8_t* pTxBuff, uint16_t length);	/* NXP Module 230215 */
extern void NXP_NFC_MainControl_Init2(void);

extern uint16_t NXP_PICC_MainControl2(void);
extern void NXP_PICC_MainControl_Init2(void);

extern uint8_t Get_NXP_NFC_DetectCheck2(void);
extern uint8_t Get_NXP_NFC_DataExchangeCheck2(void);
extern uint8_t * Get_NXP_NFC_CanTpTxBuf2(void);
extern uint8_t Get_NXP_NFC_CanTpTxSize2(void);
extern uint8_t Get_NXP_LPCD_WakeupCheck2(void);
extern uint8_t Get_NXP_PICC_OnThePad2(void);
extern uint8_t Get_NXP_NfcModeExitReady2(void);		// 230509

extern uint8_t Get_NXP_NFC_CommunicationErrorsCheck2(void);		// 230503. JJH. NFC Communication Error
extern uint16_t Get_NXP_NFC_CommunicationErrorsStatus2(void);   // 230503. JJH. NFC Communication Error
extern void Reset_NXP_NFC_CommunicationErrors2(void);       	// 230503. JJH

// extern uint16_t NXP_CardProtection_MainControl_Init2(void);
extern uint16_t NXP_CardProtection_MainControl2(void);

extern uint16_t NXP_NfcRdLib_Init2(void);
extern uint16_t NXP_NfcRdLib_Init(void);

#endif  /* APP_NFC_H */
