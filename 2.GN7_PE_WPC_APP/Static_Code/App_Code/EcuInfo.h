/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2024 All Rights Reserved

***************************************************************************************************/

#ifndef ECUINFO_H
#define ECUINFO_H

#include "App_Common.h"

/****************************************************************
 CAR TYPE define (신규 차종 추가시 순차적으로 넘버링 할것)
****************************************************************/
// #define cGN7_PE                 0x01u   // 
// #define cRX4_PE                 0x02u   // 개발 차종을 순차적으로 hex로 넘버링

/****************************************************************
 WPC TYPTE 판단을 위한 품번 define
****************************************************************/
// 양산 후 품번 추가 될 경우 소스 코드 변경 없이 적용하기 위해서
// 품번 전체 비교에서 NFC/Non-NFC 규칙 있는 자리수까지 비교하는것으로 변경
// TYPE4 (EPP)     : 95560-xxxxx
// TYPE5 (EPP+MPP) : 95560-N1600
// TYPE6 (EPP+EPP) : 95560-N1500

#define cTYPE4_PartNo1         'N'
#define cTYPE4_PartNo2         '1'
#define cTYPE4_PartNo3         '4'
#define cTYPE4_PartNo4         '0'  // NFC 품번 식별자

#define cTYPE5_PartNo1         'N'
#define cTYPE5_PartNo2         '1'
#define cTYPE5_PartNo3         '6'
#define cTYPE5_PartNo4         '0'  // NFC 품번 식별자

#define cTYPE6_PartNo1         'N'
#define cTYPE6_PartNo2         '1'
#define cTYPE6_PartNo3         '5'
#define cTYPE6_PartNo4         '0'  // NFC 품번 식별자

#define cWPC_TYPE_None          0u
#define cWPC_TYPE4              4u
#define cWPC_TYPE5              5u
#define cWPC_TYPE6              6u
/****************************************************************
 사양 define (차종 사양에 따라 결정되므로 당당자에게 확인 후 설정 할것)
****************************************************************/

#define IND_CONT_TYPE3          // 아래 항목 중 선택하여 define
                                // IND_CONT_TYPE1 : 0u // withDetent : Rheostat Bright Level 21단계
                                // IND_CONT_TYPE2 : 1u // withoutDetent : Rheostat Bright Level 21단계
                                // IND_CONT_TYPE3 : 2u // withAutoBright : AutoBright Level 200단계

#define Var_RheostatOption_ON   // 아래 항목 중 선택하여 define
                                // Var_RheostatOption : Rheostat Option
                                // Var_RheostatOption_OFF : 0, IntTailOn, DetentOut, Rheostat 중 사용 신호가 다름. (Type 별로 사양서 참고)
                                // Var_RheostatOption_ON  : 1, IntTailOn, DetentOut, Rheostat 중 사용 신호가 다름. (Type 별로 사양서 참고)
                                // IND_CONT_TYPE3 사용시는 이 옵션은 on/off 무관함. 적용 안됨.

#define b_IndUSMOption_OFF      // 아래 항목 중 선택하여 define
                                // 사양서에 Var_INDAnimationOption 이 존재하나 사용되지 않고 b_IndUSMOption 이 같은 기능으로 사용됨.
                                // IndUSMOption : Indicator USM Option (애니메이션 동작 선택), Type1:충전시 황색, Type2:충전시 그린 & 애니메이션
                                // b_IndUSMOption_OFF : 0, Type1 only 동작 (클러스터에 선택 메뉴 생성 안됨.)
                                // b_IndUSMOption_ON  : 1, Type1 or Type2 동작 선택 가능 (클러스터에 선택 메뉴 생성됨.)

#define LED_DUTY_TABLE_0        // 아래 항목 중 선택하여 define
                                // 모델에서 LED duty Table을 Spec과 다르게 적용할때 구분자로 사용함. (인덱스 추가시 모델에 추가 요청해야함)
                                // LED_DUTY_TABLE_0 : 0u  // default duty 적용 (사양서의 Duty table 적용)
                                // LED_DUTY_TABLE_1 : 1u  // 별도로 튜닝된 duty table 적용 (실차에서 타 유닛과 조도 차이 줄이기 위해서 변경할 경우 사용.)


#define TCI_Code_Hyundai        // 아래 항목 중 선택하여 define
                                // TCI_Code_Hyundai : 0
                                // TCI_Code_Kia     : 1
                                // TCI_Code_Genesis : 2

#define DOWNGRADE_PREVENT_ON    // 아래 항목 중 선택하여 define (모빌젠설정은 항상 다운그레이드 방지 사용으로 설정되어 있음)
                                // DOWNGRADE_PREVENT_OFF : 다운그레이드 방지 미사용 (소스 코드 로직상에서 미사용할때 응답값으로 응답하도록 수정함.)
                                // DOWNGRADE_PREVENT_ON : 다운그레이드 방지 사용                                
                                                                
#define WCT_REPROGRAM_OFF       // 아래 항목 중 선택하여 define
                                // WCT_REPROGRAM_OFF : OTA에의한 WCT 리프로그래밍 미사용 (Canoe 요청만 가능)
                                // WCT_REPROGRAM_ALL : WCT 전체 영역 리프로그래밍 사용 (캘리브레이션 + APP)
                                // WCT_REPROGRAM_APP_ONLY : WCT APP 영역 리프로그래밍 사용 (APP), 캘리브레이션 영역 제외
                                
#define EXTENDED_RXSWIN_OFF       // extended rxswin 사용 여부
                                // EXTENDED_RXSWIN_OFF : 기본 인증 번호만 사용
                                // EXTENDED_RXSWIN_ON : 중국 인증 번호 사용
                                                        
/****************************************************************
 RXSWIN define
****************************************************************/
// UNECE R155 : 사이버 보안 법규
// UNECE R156 : SW 업데이트 법규
// 차종명에 PE등은 생략함. 3자리로 입력할것.
#define cRxSWINData1        "R10 GN7/1/0"
#define cRxSWINData2        "R155 GN7/1/0"
#define cRxSWINData3        "R156 GN7/1/0"

#if defined(EXTENDED_RXSWIN_ON)
#define cRxSWINData4        "GB34660 GN7/1/0"
#define cRxSWINData5        "GB44495 GN7/1/0"
#define cRxSWINData6        "GB44496 GN7/1/0"
#define cRxSWINData7        "GBT18387 GN7/1/0"
#endif


/****************************************************************
 APP Version define (날짜 기반 버전 관리)
****************************************************************/
#define cAppSoftVerYear1	'2' // 년도
#define cAppSoftVerYear2	'5' // 년도
#define cAppSoftVerMonth	'2' // 월 (A:10월, B:11월, C:12월)
#define cAppSoftVerOrder	'1' // 해당월의 릴리즈 차수 (월 변경시 초기화 1)
#define cAppSoftVerOption	'T' // 0:release, U:update , R:rollback, F:Fail, T:Test
/****************************************************************
 APP 내부 버전 define, 모든 내부 버전이 중복 되지 않도록 차종 구분자와 순차 증가되는 버전을 통합하여 사용.
****************************************************************/
// hex 파일명 자동 생성을 위해서 직접 define하도록 변경함.
// 차종 증가시마다 순차적으로 증가하여 ascii값으로 define한다.
// GN7 PE : '0' '1'
// RX4 PE : '0' '2'
#define cAppSoftVerCAR1	    '0' // 차종 구분자 (hex) 
#define cAppSoftVerCAR2	    '1' // 차종 구분자 (hex)
#define cAppSoftVerIndex1	'0' // 배포시 순차적으로 증가 (hex)
#define cAppSoftVerIndex2	'D' // 배포시 순차적으로 증가 (hex)

/****************************************************************
 SWP Version define
****************************************************************/
#define cSWP_APP_VER1       '2'
#define cSWP_APP_VER2       '1'
#define cSWP_APP_VER3       '13'
/****************************************************************
 WCT Version define (충전IC 리프로를 위한 Target Ver)
****************************************************************/
#define cWCT_TARGET_VER1_TYPE4        'F'
#define cWCT_TARGET_VER2_TYPE4        '0'
#define cWCT_TARGET_VER3_TYPE4        '0'

#define cWCT_TARGET_VER1_TYPE5        'G'
#define cWCT_TARGET_VER2_TYPE5        '0'
#define cWCT_TARGET_VER3_TYPE5        '8'

#define cWCT_TARGET_VER1_TYPE6        'H'
#define cWCT_TARGET_VER2_TYPE6        '0'
#define cWCT_TARGET_VER3_TYPE6        '9'

/****************************************************************
 BCAN DB 버전 define
************************************************h****************/
// 0.70 : 20240816_STD_DB_CAR_R2.0_2024_FD_B2_v24.08.01W_Dvp_InitVal_Fixed.dbc 적용 (최초 임포트), dvp 추가, 레오스탯 초기값 10으로 수정
// 0.70 : 20240902_STD_DB_CAR_R2.0_2024_FD_B2_v24.08.01_Dvp_InitVal_Fixed.dbc (최신 db 임포트 2024.09.02), dvp 추가, 레오스탯 초기값 10으로 수정
// 0.70 : 20240902_STD_DB_CAR_R2.0_2024_FD_B2_v24.08.01_Dvp_InitVal_Fixed.dbc (db 재임포트 2025.02.14), dvp 추가, 레오스탯 초기값 10으로 수정, USM_Wpc2SetReq 신호 추가함. 동일 DB였으나 기존에 누락되어 있어서 다시 임포트함.
// 0.90 : 20250305_STD_DB_CAR_R2.0_2024_FD_B2_v25.02.01.dbc 배포됨. 0.70대비 변경된 사항 있음. 재db 임포트 필요함.
#define cBCanDBVersion1		'0'
#define cBCanDBVersion2		'7'
#define cBCanDBVersion3		'0'
/****************************************************************
 LCAN DB 버전 define
****************************************************************/
// 0.10 : 20240816_STD_DB_CAR_R2.0_2024_FD_BDC_Local_v24.08.01W_TpMsg_Fixed.dbc 적용 (최초 임포트), LCAN TP 메세지 설정 수정 없이 원본으로 사용함. 모빌진 프로그램 수정됨. --> 그러나 모빌진에서 miss match 에러 발생해서 설정 수정함.
// 0.40 : 20240902_STD_DB_CAR_R2.0_2024_FD_BDC_Local_v24.08.01.dbc(최신 db 임포트 2024.09.02, db 수정 없이 경고 팝업뜰대 무시하고 진행함.)
// 0.40 : 20240902_STD_DB_CAR_R2.0_2024_FD_BDC_Local_v24.08.01.dbc(TP통신 문제로 최신 모빌젠으로 재임포트 2025.03.11, db 수정 없이 경고 팝업뜰대 무시하고 진행함.)
#define cLCanDBVersion1     '0'
#define cLCanDBVersion2     '7' // 아직 0.7 적용은 안한상태이나 도면에 0.7이므로 0.7로 표출함
#define cLCanDBVersion3     '0'
/****************************************************************
 플랫폼 HW 버전 define
****************************************************************/
// 코드 공용화를 위해서 WPC TYPE에 따라 자동으로 변경되어야 하므로 define으로 사용불가. 
// App_Uds.c에서 NvM의 WPC Type에 따라 자동으로 변경되어 리턴하도록 수정함.
//#define cPlatformHardVer1	'0'		// 플랫폼 타입
//#define cPlatformHardVer2	'4'     // Type4
//#define cPlatformHardVer2	'5'     // Type5
//#define cPlatformHardVer2	'6'     // Type6

#define cPlatformHardVer3	'0'		// 능동 소자 변경시
#define cPlatformHardVer4   '0'

#define cPlatformHardVer5	'0'		// 수동 소자 변경시
#define cPlatformHardVer6	'0'

#define cPlatformHardVer7	'0'		// PCB 패턴 변경시
#define cPlatformHardVer8	'0'
/****************************************************************
 플랫폼 SW 버전 define
****************************************************************/
#define cPlatformSoftVer1	'2'		// 플랫폼 사양서(차수) 변경시
#define cPlatformSoftVer2	'1'

#define cPlatformSoftVer3	cBCanDBVersion1		// CAN (표준) 버전
#define cPlatformSoftVer4	cBCanDBVersion2

#define cPlatformSoftVer5   cLCanDBVersion1     // Local-CAN(표준) 버전
#define cPlatformSoftVer6   cLCanDBVersion2

#define cPlatformSoftVer7	'0'		// OTA 호환성 버전
#define cPlatformSoftVer8	'0'     // A : HSM 2.8.0

#define cPlatformSoftVer9	'0'		// 플랫폼 자체 S/W 문제 개선 업데이트 시
#define cPlatformSoftVer10	'0'		// 플랫폼 사양서(차수)  변경시 초기화 됨

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


/****************************************************************
 디버그용 define (디버깅을 위한 기능이므로 양산 Hex 배포시에는 모두 주석처리 해야함)
****************************************************************/

//#define DEBUG_EXT_WDT_NOT_USE           // exterbal WDT on/ Off 기능
                                        // not defined (주석처리) : wdt enable
                                        // defined : wdt disable

//#define DEBUG_CONFIG_LOCK_NOT_USE       // Secure Config Lock 기능
                                        // not defined (주석처리) : config lock 사용
                                        // defined : config lock 미사용

//#define DEBUG_FIXED_RANDOM_SEED_USE   // OEUK 인증용 Random Seed 사용 여부 선택
                                        // not defined (주석처리) : random Seed 사용(배포시)
                                        // defined : fixed random seed 사용 11 22 33 ~ 88 (Canoe로 이미 계산된 resp로 응답하여 검증 가능)

#define DEBUG_TUNE_MODE_USE             // 튜닝목적으로 LED, FAN, LPCD 파라미터를 변경하는 기능.
                                        // not defined (주석처리) : disable
                                        // defined : enable

//#define DEBUG_ErrM_Module_USE         // cpu load, stack usage, os error monitor
                                        // not defined (주석처리) : disable
                                        // defined : enable

//#define DEBUG_AUTO_TEST_USE           // 검증팀 자동화 테스트시 적용시 임시로 진단 ID 추가됨
                                        // not defined (주석처리) : F1A0 미사용
                                        // defined : F1A0 사용으로 적용됨. (진단사양서에는 삭제됨)

//#define DEBUG_UART_NOT_RESET_USE          // UART 통신 Fault 시 Reset 여부
                                        // not defined (주석처리) : Reset enable
                                        // defined : Reset Disable

#define DEBUG_CARD_PROTECTION_NOT_USE          // NFC Card 프로텍션 사용 여부
                                        // not defined (주석처리) : 사용
                                        // defined : 미사용                    
                                        
//#define DEBUG_OEUK_DEV_KEY_USE          // OEUK 인증용 public key 선택
                                        // not defined (주석처리) : 양산용 key 사용(배포시)
                                        // defined : 개발용 key 사용 (H-OTA평가시 사용)                                        
                                        
/****************************************************************
 Verification the Parameters on Build Time (설정 오류시 컴파일 단계에서 에러 발생시킴)
****************************************************************/
/* WPC_2416_10 Start */
#include "Std_Types.h"

#include "Com_Cfg.h" 
#if defined (COM_MAX_TOTAL_PDU_SIZE)	/* 해당 파라미터는 CAN Message 중 가장 큰 값의 Length로 결정됨 */
	#if (COM_MAX_TOTAL_PDU_SIZE < 512)	/* LCAN TP Length : 512 */
		Error : The COM_MAX_TOTAL_PDU_SIZE be must greater than 512 for CAN TP
	#endif
#else
	Error : Not found the COM_MAX_TOTAL_PDU_SIZE
#endif

#include "Can_PBcfg.h"
#if defined (CAN_CFG_NUMBER_OF_RX_FIFO_FILTERS_0)	/* 해당 파라미터는 FIFO로 설정된 CAN HW 개수로 결정됨 */
	#if (CAN_CFG_NUMBER_OF_RX_FIFO_FILTERS_0 < 3)	/* NM 2개 진단 1개로 총 3개여야 함 */
		Error : The CAN_CFG_NUMBER_OF_RX_FIFO_FILTERS_0 be must greater than 3 for GST_WPC
	#endif
#else
	Error : Not found the CAN_CFG_NUMBER_OF_RX_FIFO_FILTERS_0
#endif

#if defined (DEBUG_EXT_WDT_NOT_USE)
	#define cAppSoftVerYear1 'T'  // 내부버전 형식에 오류를 일으킴.(검증단계에서 발견되어야함.)
        
#endif


#endif
/* WPC_2416_10 End */


