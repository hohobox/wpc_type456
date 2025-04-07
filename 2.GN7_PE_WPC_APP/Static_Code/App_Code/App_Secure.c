/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/

// Mdw_BG.c의 BackGround_NonPeriodic로 최초 runnable이 생성되었으나
// 가식성이 떨어지므로 Mdw_ConfigLock.c로 파일명 변경함.
// 다만 runnable 함수명까지 바꾸려면 복잡하므로 runnable 함수명은 그대로 유지함.
/***************************************************************************************************
    INCLUDE FILES
***************************************************************************************************/
#include "EcuInfo.h"
#include "App_Secure.h"
#include "Rte_App_Secure.h"


#include "SecurityApp_SecureBoot.h"
#include "SecurityApp_FwTamperDetection.h"
#include "Hsm_HostAPI.h"

#define App_Secure_START_SEC_CODE
#include "App_Secure_MemMap.h"

//static HSM_SECUREBOOT_STATE_t s_secureBootState;
//static HSM_ERROR_CODE g_ErrorCode;
/* static HSM_SB_CONFIG_t sbConfig = {0}; */	/* WPC_1918_01 */
/* static HSM_SB_DUAL_CONFIG_t sbConfig = {0, }; */	/* WPC_2411_02 3 */		/* WPC_1918_01 */
static HSM_SBM_DUAL_CONFIG_t sbConfig = {0, };	/* WPC_2411_02 3 */

static uint8_t SecureMode_State = cSecure_Init;

uint8_t gs_Get_SecureMode_State(void) {return SecureMode_State;}


/***************************************************************************************************
@param[in]  void
@return     void
@note       실행시간 500us 초과 함수는 별도로 비주기 함수로 콜한다.
            Rte_Trigger_TriggerInterface_BG_Trigger_BG(); 호출시 call 됨.
			can UDS Pending 송신 주기는 2.5초 이나 여기 호출되는것은 10ms 주기이다. gpio로 확인
			즉 pending 취소 여부확인은 매주기마다 실시함.
			Non-Timming(Nonperiodic) Event Runnable Function
***************************************************************************************************/
// FUNC(void, App_ConfigLock_CODE) BackGround_NonPeriodic_Runnable(void)
FUNC(void, App_Secure_CODE) Secure_NTE_Runnable(void)
{

    static Std_ReturnType SecureBootResult = 0;
	static Std_ReturnType SecureBootEnableResult = 0;
	static Std_ReturnType ConfigLockResult = 0;
	static Std_ReturnType ConfigLockEnableResult = 0;

    static HSM_SECUREBOOT_STATE_t secureBootState = HSM_SECUREBOOT_INIT;
	static HSM_CONFIG_LOCK_STATE_t confLckState = HSM_CONFIG_LOCK_DISABLE;
	//static HSM_ERROR_CODE g_ErrorCode;

 /*
  * [Memory Layout for mobilgene Classic SWP]
  * -----------------------------------------------------------------------------
  * | CM0+ [HSM]      | CM4 or CM7_0 [FBL] | CM4 or CM7_0 [RTSW]                |
  * | RAM : 40KB      | RAM : 40KB         | RAM : End of CM0+ ~ End of MCU     |
  * | ROM : 160KB     | ROM : 192KB        | ROM : End of FBL  ~ End of MCU     |
  * -----------------------------------------------------------------------------
  */

// CYTXXXX_FBL.ld
//  MEMORY
// {
//   // ROM allocations 
//   CM0_ROM_Reserved       : ORIGIN = 0x10000000, LENGTH = 0x28000     // 160KB      - ROM for CM0 Executable 

//   FBL_RESET	             : ORIGIN = 0x10028000, LENGTH = 0x200       // 512 Bytes  - FBL Reset Vector 
//   FBL_CODE               : ORIGIN = 0x10028200, LENGTH = 0x2FDB0     // 191KB      - FBL Executable 
//   BTL_iVERSION           : ORIGIN = 0x10057FB0, LENGTH = 0x40        //64 Bytes   - FBL version info for internal use 
//   BTL_eVERSION           : ORIGIN = 0x10057FF0, LENGTH = 0x10        // 16 Bytes   - FBL version info for external use 


	// bootSize 계산한는 방법
	// FBL map 파일에서
	// .ROM.BTL_RAM_CODE    10039438  00000098          152   0011478
	// 0x10039438 + 152바이트(0x98) = 0x100394D0
	// (0x1002 8000 ~ 0x1003 94D0)로 사용
	// 0x1003 94D0 - 0x1002 8000 + 1 = 0x1 14D1 (70865 byte)
	// 현대오토에버 요소기술개발팀 박재관
	// bootsize의 크기 변화는 실행시간에 큰 영향이 없음
	// 그러므로 매번 fbl 영역을 계산할 필요 없이 전체 영역으로 지정함
	// 설정한 영역은 반드시 모든 영역에 값이 채워졍햔다. (가이드문서)
/* WPC_1918_01 Start */
#if 0 
	sbConfig.bootStartAddr = 0x10028000;
	sbConfig.bootSize = 0x30000; // 전체 영역 size (196608byte) // 실행시간 : ?ms // WPC_1904_04 
	sbConfig.cmacKeyNum = 101;
	sbConfig.signKeyNum = 0x0;		// 미사용
	sbConfig.signStartAddr = 0x0; 	// 미사용
#endif

#if 0 /* WPC_2411_02 3 Start */
	sbConfig.bootStartAddrBankA = 0x10030000;
	sbConfig.bootStartAddrBankB = 0x12030000;
	sbConfig.bootSizeBankA = 0x20000;
	sbConfig.bootSizeBankB = 0x20000;
	sbConfig.cmacKeyNum = 1u;
#endif
/* WPC_1918_01 End */	
	sbConfig.area[0].active.addr = 0x10028000u;
	sbConfig.area[0].active.len  = 0x900u;
	sbConfig.area[1].active.addr = 0x10028C00u;
	sbConfig.area[1].active.len = 0x2F400u;
	sbConfig.area[0].inactive.addr = 0x12028000u;
	sbConfig.area[0].inactive.len  = 0x900u;
	sbConfig.area[1].inactive.addr = 0x12028C00u;
	sbConfig.area[1].inactive.len = 0x2F400u;
/* WPC_2411_02 3 End */
	// 실행 주기는 UDS Pending 송신 주기마다 호출된다.
	switch(SecureMode_State)
	{
		case cSecure_Init:
			SecureBootResult = HSM_SecureBootResult(&secureBootState);

			if((SecureBootResult == E_OK) &&
			(secureBootState == HSM_SECUREBOOT_NOT_PERFORMED))
			{
				/* SecureBootEnableResult = HSM_FactorySecureBootEnable(&sbConfig); */  /* 330ms 소요됨 */
				/* SecureBootEnableResult = HSM_FactorySecureBootEnableDualBank(&sbConfig); */ /* WPC_2411_02 3 Start */ /* WPC_1918_01 1 */
				SecureBootEnableResult = HSM_FactorySecureBootMultiEnableDualBank(&sbConfig);	/* WPC_2411_02 3 Start */

				if (SecureBootEnableResult == E_OK)
				{
					SecureBootResult = HSM_SecureBootResult(&secureBootState);

					if((SecureBootResult == E_OK) &&
					(secureBootState == HSM_SECUREBOOT_ENABLE)) // T32로 라이팅 직후 HSM_SECUREBOOT_ENABLE (return : 2)
					{
						SecureMode_State = cSecure_BootEnable;
					}
				}
			}
			else if((SecureBootResult == E_OK) &&
			((secureBootState == HSM_SECUREBOOT_ENABLE) || (secureBootState == HSM_SECUREBOOT_SUCCESS)))
			{
				SecureMode_State = cSecure_BootEnable; // 이미 boot enable 되어 있으므로 config lock실행해야함.
			}
			else
			{
				SecureMode_State = cSecure_Ng;
			}

		break;


		case cSecure_BootEnable:

			ConfigLockResult = HSM_GetConfigurationLockState(&confLckState);

			if((ConfigLockResult == E_OK) &&
			(confLckState == HSM_CONFIG_LOCK_DISABLE))
			{
				SecureBootResult = HSM_SecureBootResult(&secureBootState);

				if((SecureBootResult == E_OK) &&
				(secureBootState != HSM_SECUREBOOT_NOT_PERFORMED))
				{
					/** CAUTION : MUST SET SECURE BOOT ENABLE or DISABLE BEFORE SETTING HSM CONFIGURATION LOCK
					*  Once the configuration lock setting is performed, it cannot be restored to unlock state..
					*  When calling HSM_Factory* after this setting, E_NOT_OK is returned.
					**/
#if !defined (DEBUG_CONFIG_LOCK_NOT_USE)					
					HSM_FactoryFwTamperDetectionDisable();	/* WPC_1918_01 2 */
				
    				ConfigLockEnableResult = HSM_FactoryHsmConfigurationLock(); // 테스트시 주석처리하여 테스트할것
#endif
					SecureMode_State = cSecure_ConfigLock;


					// Config Lock 설정 활성화 여부는 제어기 리셋 이후 처리 이후
					// 진단기로 All Read로 read 해서 확인해야함.
					// 리셋 하지 않은 상태에서 아래 코드를 실행하면 에러 발생함.

					// 리턴값이 HSM_CONFIG_LOCK_DISABLE (0)이면 config Lock 재실행 해야함
				}
				else // 여기까지 왔는데 Not  Perform이면 securebootenable을 다시 실행해야함.
				     // 근데 여기까지 올때 이미 secureboot가 not perform이여서 온것이다.
					 // 그러므로 여기까지 온것은 이상한 것임. 하지만 일단 다시 처음부터 실행하도록 로직 구성함.
				{
					SecureMode_State = cSecure_Init;
				}
			}
			else if((ConfigLockResult == E_OK) &&
			(confLckState == HSM_CONFIG_LOCK_ENABLE))
			{
				SecureMode_State = cSecure_ConfigLock;
			}
			else
			{
				SecureMode_State = cSecure_Ng;
			}


		break;


		case cSecure_ConfigLock:

			SecureMode_State = cSecure_Init;

		break;

		case cSecure_Ng:
			SecureMode_State = cSecure_Init;
		break;

		default:
			SecureMode_State = cSecure_Init;
		break;

	}
}

// WPC_104_01 stop


#define App_Secure_STOP_SEC_CODE
#include "App_Secure_MemMap.h"

#if 0  // [HSM_2.0spec]HSM_Framework_UserManual_Secure_Application_Guide_KOR.pdf 발췌


typedef enum
{ //HSM-Driver Sync Need
	HSM_SECUREBOOT_INIT = 0,                            /*!< Initialization */
	HSM_SECUREBOOT_DISABLE = 1,                         /*!< Disable */
	HSM_SECUREBOOT_ENABLE = 2,                          /*!< Enable */
	HSM_SECUREBOOT_SUCCESS = 3,                         /*!< Bootloader integrity verification success */
	HSM_SECUREBOOT_HEADER_ERR = 4,                      /*!< Table header, footer error */
	HSM_SECUREBOOT_INVALID_CMAC = 5,                    /*!< Bootloader integrity verification fail */
	HSM_SECUREBOOT_CMAC_GEN_FAIL = 6,                   /*!< MAC generation failure for integrity verification */
	HSM_SECUREBOOT_HASH_GEN_FAIL = 7,                   /*!< Hash generation failed when verifying the firmware signature */
	HSM_SECUREBOOT_DECRYPT_FAIL = 8,                    /*!< Encrypted table decryption failed */
	HSM_SECUREBOOT_XOR_SUM_FAIL = 9,                    /*!< XOR Value Verification fail */
	HSM_SECUREBOOT_SIGN_VERIFY_FAIL = 10,               /*!< Signature verification fail */
	HSM_SECUREBOOT_WR_INFO_FAIL = 11,                   /*!< Table write fail */
	HSM_SECUREBOOT_NOT_PERFORMED = 12,                  /*!< Secure Boot not working */
	HSM_SECUREBOOT_STATE_ENUM_SET_UINT32 = 0x7FFFFFFF,
} HSM_SECUREBOOT_STATE_t;


typedef enum
{
	HSM_CONFIG_LOCK_DISABLE = 0,
	HSM_CONFIG_LOCK_ENABLE = 1,
	HSM_CONFIG_LOCK_ENUM_SET_UINT32 = 0x7FFFFFFF,
} HSM_CONFIG_LOCK_STATE_t;




Secure Boot 검증 과정은 위 그림의 절차로 진행된다 MCU 전원 인가 후 HSM Core 가 시작되면 HSM 전용
Flash 에 기록되어 있는 Secure Boot 설정정보와 MAC 정보를 읽는다 해당 정보를 바탕으로 H os t Core 의 부트로더
Flash 영역을 Read 하여 MAC 을 계산한다 Secure Boot 활성화 시 저장한 MAC 정보와 부팅 후 계산한 MAC’ 를 비
교하여 동일한 경우 Secure Boot 검증에 성공하며 Host Core 를 Wake Up 한다 만약 비교한 MAC 이 다를 경우 부트
로더의 변조로 판단하여 Host Core 를 Wake up 시키지 않고 Reset 을 진행하여 MCU 의 부팅을 제한한다 MAC 검증
에 소요되는 시간은 설정한 부트로더 크기에 비례하여 증가한다 부팅시간에 민감한 제어기의 경우 부트로더 영역을 최
소화하여 부팅시간을 확보하여야 한다

HSM이 Secure Boot 검증영역으로 설정된 flash 영역 을 Read 할 때 Flash 영역 내 Read 가 불가능 한 영역이 포
함되어 있을 경우 Fault 가 발생할 수 있다 Fault 발생하여 S ecure Boot 동작이 중지될 경우 MCU 의 부팅이 제한될
수있으므로 Secure Boot 로 지정하는 영역은 반드시 빈공간이 포함되지 않도록 임의의 값으로 채워야 한다 사용하지
않는 영역을 임의의 값으로 채우는 설정은 빌드 시 링커스크립트에서 설정이 가능하며 설정 방법은 본 문서의 범위를
벗어나므로 각 컴파일러 가이드 문서를 참조한다 Flash 의 read 가 불가능한 상태 의 정의는 제조사마다 상이하며 , Flash
Bad Sector, Flash bit Error, Flash Erased State, Flash Clear State, Flash Blank state 등 상태로 표현된다


Secure Boot 기능은 양산 공정 지원을 위해 제공되는 FACTORY API 를 통해 활성화 및 비활성화 할 수 있다
Secure Boot 활성화는 아래와 같은 과정으로 진행된다

① HSM_DriverInitialze() HSM API 를 사용하기 위해 호출
② HSM_FactorySecureBootEnable() Secure Boot 설정 및 활성화
③ MCU Reset 이후 부팅 시 Secure Boot 기능 동작

HSM Core 가 Enable 된 후 HSM Core 와의 통신을 설정하기 위하여 HSM_DriverInitialzie API 를 수행한다 해당
API 에서 E_OK 를 리턴하면 HSM API 사용이 가능해진다 Secure Boot 활성화는 HSM_FactorySecureBootEnable()
API 를 호출하여 설정할 수 있다 API 호출 시 입력 파라미터로 부트로더의 정보를 입력하면 HSM Core 에서 해당 정보
를 바탕으로 MAC 을 생성하여 저장한다 이후 MCU 를 재부팅 하면 HSM Core 부팅 시 Secure Boot 검증을 진행한다
Secure Boot 를 사용하지 않는 MCU 의 경우 HSM_FactorySecureBootDIsable() API 를 호출하여 설정할 수 있다 .
Secure Boot Enable/Disable API 들은 HSM Configuration Lock 설정 전 까지만 사용이 가능하다 . 만약
Enable/Disable 중 하나라도 설정하지 않고 HSM Configuration Lock 을 적용하였을 HSM 은 비정상적인 상태로 간
주하여 부팅을 차단한다 . HSM Configuration Lock 에 대해서는 3.7 HSM Configuration Lock 절에서 상세히 설명한
다
HMC 보안정책에 따라 HSM 이 적용된 제어기의 경우 반드시 Secure Boot 기능을 사 용해야 한다 . 단 해킹이 탐지된
상황이라도 부팅이 필요한 제어기의 경우 Secure Boot 대신 반드시 Firmware Tamper Detection(HMC 실시간 개조
감지 ) 보안 기능에 부트로더 영역을 설정하여 부트로더의 무결성을 검증하여야 한다 . 단 Secure Boot 를 대신하여
Firmware Tamper Detection 기능을 사용하는 경우 HMC 전자기반기술개발팀과 협의가 필요하다

Secure Boot 기능을 활성화한 이후 부트로더의 변경이 발생하면 이후 부팅 시 변조를 감지하여 부팅을 제한한다 부
트로더를 변경할 경우 반드시 아래의 절차대로 수행하여 변경된 부트로더의 정보를 HSM 에 갱신하여야 한다

① H SM_DriverInitialze H SM API 를 사용하기 위해 호출
② H SM_TempStop Host Core 와 HSM Core 가 동일한 Flash 모듈을 사용하고 있을 경우 HSM C ore
에서 Code Flash 영역을 Read 하는 중 Host Core 에서 Flash Erase/Write 를 수행 시 충돌이 발생할 수
있다
본 AP I 수행 후 모든 HSM API 는 사용이 제한된다
③ Bootloader reprogramming 신규 부트로더 프로그래밍
④ HSM_Restart HSM API 를 사용할 수 있도록 정지상태를 해제
⑤ HSM_SecureBootMacUpdate 변경된 부트로더의 정보로 갱신
⑥ MCU Reset 이후 부팅부터 변경된 Secure Boot 설정 적용

Secure Boot 설정의 임의변경을 방지하기 위하여 부트로더의 MAC 정보를 Update 할 때에는 서명검증 이 추가로
진행된 다 H SM_SecureBootMacUpdate () API 의 입력파라미터에 서명정보를 포함 하여 호출하면 HSM 에서는 부트로
더의 서명을 검증한다 검증에 성공한 경우 신규 부트로더의 MAC 정보로 갱신되며 , 이후 부팅부터 신규 부트로더의 정
보로 Secure Boot 검증절차를 진행한다 서명생성 절차 및 주의사항은 3.6 펌웨어 서명 사양 및 서명 방법 주의 사항
에서 상세히 설명한다



[HSM_2.0spec]HSM_Framework_UserManual_Target_Guide_CYPRESS_TRAVEO2_KOR.pdf 발췌

HSM Flash Memory 설정
본HSM Framework 버전에서는 HSM 사용 하는 영역은 다음과 같다 .
◆Code F lash 0x1000_0000 0x1002_7FFF (160 KB)
CYT2BX 시리즈
◆Work Flash: 0x1401_C000 0x1401_FFFF (16 KB)
◆SRAM0 : 0x0800_0000 0x0800_9FFF (40 KB)


5.1. Secure Boot 활성화 및 유의사항
Secure Boot기능은 MCU 에 전원인가 시 부트로더 영역에 대한 무결성 검사를 통해 위변조를 검사하는 보안기능이다
따라서 기본적으로 본 기능 활성화 후 제어기의 부트로더가 변경된다면 부트로더의 MAC 값이 달라지기 때문에 HSM 이 호
스트의 부팅을 허용하지 않는다 만약 Secure Boot 의 사용을 원하지 않는 경우 공정 단계에서 꼭 Secure Boot 기능을
Di s able 처리해야 한다
HAE는 개발 단계에서 Secure Boot 로 인한 불편을 최소화하기 위해 MCU Lifecycle 이 “Normal_Provisioned” 단계
에서 Secure Boot 가 활성화되지 않았을 경우 임시적으로 호스트의 부팅을 허용한다 그러나 Secure Boot 기능이 활성화
된 이후 MCU Lifecycle 이 “Normal_Provisioned” 단계라 할 지라도 부트로더의 MAC 값에 대한 무결성 검 증에 실패할
경우 MC U 를 리셋한다 따라서 Secure Boot 를 활성화한 이후에는 어떠한 경우 및 조건에서 부트로더를 업데이트한 경우
리셋하기 전에 필수적으로 Secure Boot Mac Update 절차를 진행해야 한다 그리고 Cypress 에서는 Code Flas h 영역에
대해 Dual Bank Mode 를 지원하고 있다 Bank Mode 에 따라 Fla sh 영역의 구조가 달라지기 때문에 아래의 상태 별
Secure Boot 절차에 대해 숙지 후 테스트를 하여야 한다 그리고 Secure Boot 기능과 관련된 API 는 HSM Framework
2.0 User Manual Security Application 을 참고한다



. HAE HSM 공장 양산 프로세스 API 사용 순서
<주의사항>
❖ 공장에서 양산 시 아래 API 사용 순서에 따라 API 를 호출하여야 한다 .
❖ 본 API 를 올바르게 사용하지 않아 발생하는 보안 기능 오동작은 고객사의 책임으로 한정한다 .
❖ 본 API 는 양산 시 사용되는 테스트 소프트웨어로 적용하거나 양산 소프트웨어에 탑재되어 공정 중 1 회만 호출되어야 한다
❖ Optional 의 경우 HKMC 필수 사양은 아니므로 선택적으로 적용 가능하다 .
<전제 조건>
❖ HSM 펌웨어와 호스트 펌웨어 프로그래밍 완료
❖ 여기서 호스트 펌 웨어는 호스트 영역에 설치되어 있으며 HSM 드라이버가 포팅 된 프로그램을 의미한다 .
<사용 순서>
1. HOST 펌웨어 프로그래밍 // dual bank mode 사용시 A/B bank 양측 모두 기록 필수
2. HSM 펌웨어 프로그래밍 // dual bank mode 사용시 A/B bank 양측 모두 기록 필수
3. HSM_DriverInitialize ( Mandatory
호스트 프로그램 실제 어플리케이션 or 테스트 프로그램 이 HSM 을 초기화 하는 과정
호스트 환경에 따라 인터럽트 등록이 필요할 수 있다 . 매뉴얼 내 HSM 드라이버 포팅 가이드 참고

4. HSM_FactorySecureBoot Enable Mandatory
부트로더 Secure Boot 최초 MAC 생성
기능 미적용 시 HSM_FactorySecureBootDisable 호출 HMC 설계팀 협의

5. HSM_FactoryFwTamperDetectionEnable (
실시간 개조 감지 영역 설정 및 최초 MAC 생성
설정된 영역 의 크기 및 개수에 따라 다른 API 보다 다소 시간이 걸림
기능 미적용 시 HSM_FactoryFwTamperDetection Disable 호출 Mandatory)

6. HSM_FactoryDebuggerProtectionEnable Mandatory (삭제됨. pdf 복사시 취소선은 복사 안됨)
Traveo2 시리즈는 Configuration Lock 진행 시 자동으로 Secure Debug 활성화되기 때문에 별도 API 호출이 필요 없음

7. Configuration Lock 실행 Mandatory
HSM 배포 패키지에 포함된 LifecycleManager CMM 스크립트를 사용 하거나 HSM Driver API 로 진행
상세내용 5.6 HSM Configuration Lock 챕터 확인
HSM Protection 활성화
HSM Code OTP, HSM Exclusive 설정
Factory API 비활성화

8. MCU Reset
Power reset 시 모든 보안기능 활성화


#endif
