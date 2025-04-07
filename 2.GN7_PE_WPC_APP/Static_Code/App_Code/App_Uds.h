/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/
#ifndef  APP_UDS_H
#define  APP_UDS_H

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"

#include "Platform_Types.h"	// uint8 선언됨
#include "Std_Types.h"		// Std_ReturnType 선언됨

/***************************************************************************************************
    GLOBAL DEFINES AND MACROS
***************************************************************************************************/
// 동시에 적용 가능하도록 비트플래그 사용함.
#define Tune_Index_Default      0x00u
#define Tune_Index_LED          0x01u
#define Tune_Index_FAN          0x02u
#define Tune_Index_LPCD         0x04u
#define Tune_Index_Reserved1    0x08u

#define Tune_Index_Reserved2    0x10u
#define Tune_Index_Reserved3    0x20u
#define Tune_Index_Reserved4    0x40u
#define Tune_Index_Reserved5    0x80u

#define UDS_RESERVED_VALUE   0u /* WPC_1910_03 */ /* WPC_1908_03 */
/***************************************************************************************************
    GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/
// typedef union
// {
//     uint8_t data[17];

// 	struct
// 	{
//         uint8_t PartNumber[10];
//         uint8_t Date[4];
//         uint8_t HwVersion[3];
// 	};
// } ECU_INFO;

/* WPC_1908_03 Start */
typedef union
{
	uint8 data;

	struct
	{
		uint8 B2CAN : 1;
		uint8 LCAN1 : 1;
		uint8 LCAN2 : 1;
		uint8 ECUSpecData : 1;
		uint8 HWInput : 1;
		uint8 NetworkCondition : 1;
		uint8 Reserved0 : 2;
	};
} NonSleepReasonIndex_t;

typedef union
{
	uint8 data[4];

	struct 
	{
		uint8 ACC : 1;
		uint8 IGN1 : 1;
		uint8 DrvDrSw : 1;
		uint8 AstDrSw : 1;
		uint8 RLDrSw : 1;
		uint8 RRDrSw : 1;
		uint8 AutoBrightValue : 1;	/* WPC_1908_11 */
		uint8 SMKOption : 1;		/* WPC_1908_11 */
		uint8 Reserved0 : 8;
		uint8 ComMModePNC153 : 3;
		uint8 ComMModePNC141 : 3;
		uint8 Reserved1 : 2;
		uint8 Reserved2 : 8;
	};
} NonSleepReasonB2CAN_t;

typedef union
{
	uint8 data[2];

	struct
	{
		uint8 OwnerPhnRegRVal : 1;
		uint8 OPAdv_On_Cmd : 1;
		uint8 WPC_Device_On_Cmd : 1;
		uint8 Reserved0 : 5;
		uint8 ComMModePNC159 : 3;	/* WPC_1912_01 */
		uint8 Reserved1 : 5;
	};
}NonSleepReasonLCAN1_t;

typedef union
{
	uint8 data[2];

	struct
	{
		uint8 Reserved0 : 8;
		uint8 Reserved1 : 8;
	};
}NonSleepReasonLCAN2_t;

typedef union
{
	uint8 data[4];

	struct
	{
		uint8 UDS_LpCondition : 1;
		uint8 WPC_LpCondition : 1;
		uint8 WCT_LpCondition : 1;
		uint8 NFC_LpCondition : 1;
		uint8 Reserved0 : 4;
		uint8 Reserved1 : 8;
		uint8 Reserved2 : 8;
		uint8 Reserved3 : 8;
	};
}NonSleepReasonECUSpec_t;

typedef union
{
	uint8 data;

	struct
	{
		uint8 A_IGN1_IN : 1;
		uint8 Reserved0 : 7;
	};
} NonSleepReasonHWInput_t;

typedef union
{
	uint8 data;

	struct
	{
		uint8 DiagMsg : 1;
		uint8 AutosarNMPNCOn : 1;
		uint8 BCANWakeUp : 1;
		uint8 LCAN1WakeUp : 1;
		uint8 LCAN2WakeUp : 1;
		uint8 Reserved0 : 3;
	};
} NonSleepReasonNetworkCondition_t;

typedef union
{
	uint8 data[15];

	struct
	{
		NonSleepReasonIndex_t Index;
		NonSleepReasonB2CAN_t B2CAN;
		NonSleepReasonLCAN1_t LCAN1;
		NonSleepReasonLCAN2_t LCAN2;
		NonSleepReasonECUSpec_t ECUSpec;
		NonSleepReasonHWInput_t HWInput;
		NonSleepReasonNetworkCondition_t NetState;
	};
}NonSleepReason_t;
/* WPC_1908_03 End */
/***************************************************************************************************
    GLOBAL VARIABLE AND CONSTANTS DECLARATIONS
***************************************************************************************************/


/***************************************************************************************************
    GLOBAL FUNCTION PROTOTYPES
***************************************************************************************************/
//extern ECU_INFO gs_Get_EcuInfo(void);

extern void gs_App_Uds_L2H_Set(void);
extern void gs_App_Uds_H2L_Set(void);

extern Std_ReturnType CANDataBaseVersionNumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType CANDataBaseVersionNumberDataIdentifier_Read(uint8* Data);

extern Std_ReturnType ChallengeRequest_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType ChallengeRequest_Read(uint8* Data);

extern Std_ReturnType ChallengeRequest_Write(const uint8* Data, uint8* ErrorCode);

extern Std_ReturnType ECUManufacturingDateDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType ECUManufacturingDateDataIdentifier_Read(uint8* Data);

extern Std_ReturnType ECUSerialNumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType ECUSerialNumberDataIdentifier_Read(uint8* Data);

extern Std_ReturnType ECUSoftwareUNIT1VersionDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType ECUSoftwareUNIT1VersionDataIdentifier_Read(uint8* Data);

extern Std_ReturnType ECUSoftwareUNITnumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType ECUSoftwareUNITnumberDataIdentifier_Read(uint8* Data);

extern Std_ReturnType ECUSoftwareUnit1IVDDataIdentifier_ConditionCheckRead(uint8 OpStatus, uint8* ErrorCode);

extern Std_ReturnType ECUSoftwareUnit1IVDDataIdentifier_Read(uint8 OpStatus, uint8* Data);

extern Std_ReturnType ECUSupplierCodeDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType ECUSupplierCodeDataIdentifier_Read(uint8* Data);

extern Std_ReturnType EcuInfoRead_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType EcuInfoRead_Read(uint8* Data);

extern Std_ReturnType EcuInfoWrite_Write(const uint8* Data, uint16 DataLength, uint8 OpStatus, uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_11_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_11_ReadDataLength(uint16* DataLength);

extern Std_ReturnType InputOutputControlbyIdentifier_11_Read(uint8* Data);

extern Std_ReturnType InputOutputControlbyIdentifier_11_ReturnControlToECU(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_11_ShortTermAdjustment(uint8* ControlStateInfo, uint16 DataLength, uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_12_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_12_ReadDataLength(uint16* DataLength);

extern Std_ReturnType InputOutputControlbyIdentifier_12_Read(uint8* Data);

extern Std_ReturnType InputOutputControlbyIdentifier_12_ReturnControlToECU(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_12_ShortTermAdjustment(uint8* ControlStateInfo, uint16 DataLength, uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_13_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_13_ReadDataLength(uint16* DataLength);

extern Std_ReturnType InputOutputControlbyIdentifier_13_Read(uint8* Data);

extern Std_ReturnType InputOutputControlbyIdentifier_13_ReturnControlToECU(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_13_ShortTermAdjustment(uint8* ControlStateInfo, uint16 DataLength, uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_16_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_16_ReadDataLength(uint16* DataLength);

extern Std_ReturnType InputOutputControlbyIdentifier_16_Read(uint8* Data);

extern Std_ReturnType InputOutputControlbyIdentifier_16_ReturnControlToECU(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_16_ShortTermAdjustment(uint8* ControlStateInfo, uint16 DataLength, uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_17_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_17_ReadDataLength(uint16* DataLength);

extern Std_ReturnType InputOutputControlbyIdentifier_17_Read(uint8* Data);

extern Std_ReturnType InputOutputControlbyIdentifier_17_ReturnControlToECU(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_17_ShortTermAdjustment(uint8* ControlStateInfo, uint16 DataLength, uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_18_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_18_ReadDataLength(uint16* DataLength);

extern Std_ReturnType InputOutputControlbyIdentifier_18_Read(uint8* Data);

extern Std_ReturnType InputOutputControlbyIdentifier_18_ReturnControlToECU(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_18_ShortTermAdjustment(const uint8* ControlStateInfo, uint16 DataLength, uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_Supportedcheck_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_Supportedcheck_FreezeCurrentState(uint8* ErrorCode);

extern Std_ReturnType InputOutputControlbyIdentifier_Supportedcheck_Read(uint8* Data);

extern Std_ReturnType LocalRXSWINDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType LocalRXSWINDataIdentifier_Read(uint8* Data);

extern Std_ReturnType NonSleepCollectedEachEcuDataDataIdentifier_ConditionCheckRead(uint8 OpStatus, uint8* ErrorCode);

extern Std_ReturnType NonSleepCollectedEachEcuDataDataIdentifier_Read(uint8 OpStatus, uint8* Data);



extern Std_ReturnType PlatformHardwareVersion_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType PlatformHardwareVersion_Read(uint8* Data);

extern Std_ReturnType PlatformSoftwareVersion_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType PlatformSoftwareVersion_Read(uint8* Data);

extern Std_ReturnType PubllicKeyForOEUK_ConditionCheckRead(uint8 OpStatus, uint8* ErrorCode);

extern Std_ReturnType PubllicKeyForOEUK_Read(uint8 OpStatus, uint8* Data);

extern Std_ReturnType PubllicKeyForOEUK_Write(const uint8* Data, uint8 OpStatus, uint8* ErrorCode);

extern Std_ReturnType QRCodeWrite_Write(const uint8* Data, uint8 OpStatus, uint8* ErrorCode);



extern Std_ReturnType SecureBootEnable_ConditionCheckRead(uint8 OpStatus, uint8* ErrorCode);

extern Std_ReturnType SecureBootEnable_Read(uint8 OpStatus, uint8* Data);

extern Std_ReturnType SoftwareVersionforHKMCVehiclemanufactureDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType SoftwareVersionforHKMCVehiclemanufactureDataIdentifier_Read(uint8* Data);

extern Std_ReturnType SystemName_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType SystemName_Read(uint8* Data);

extern Std_ReturnType SystemSupplierECUHardwareVersionNumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType SystemSupplierECUHardwareVersionNumberDataIdentifier_Read(uint8* Data);

extern Std_ReturnType InputOutputRecordLocalIdentifier1_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType InputOutputRecordLocalIdentifier1_Read(uint8* Data);

extern Std_ReturnType InputOutputRecordLocalIdentifier2_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType InputOutputRecordLocalIdentifier2_Read(uint8* Data);

extern Std_ReturnType VehicleManufacturerECUHardwareNumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType VehicleManufacturerECUHardwareNumberDataIdentifier_Read(uint8* Data);

extern Std_ReturnType VehicleManufacturerSparePartNumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType VehicleManufacturerSparePartNumberDataIdentifier_Read(uint8* Data);

extern Std_ReturnType OTAReady_Start(uint8 OpStatus, uint8* DataOut_OutSignal, uint8* ErrorCode);

extern Std_ReturnType ECUSecurityInformationDataIdentifier_ConditionCheckRead(uint8* ErrorCode);

extern Std_ReturnType ECUSecurityInformationDataIdentifier_Read(uint8* Data);

#endif
