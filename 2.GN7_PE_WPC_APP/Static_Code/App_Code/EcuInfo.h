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
주의사항
 
1.품번 신규 생성시 App_NvM.c로 이동하여 품번 추가 할것.

2.RxSWIN 정보 변경시 App_Uds.c로 이동하여 정보 추가 할것

****************************************************************/



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

//#define EXTENDED_RXSWIN_USE   // extended rxswin 사용 여부
                                // not defined (주석처리) : 미사용
                                // defined : 사용 (중국 인증)
                                                                
#define EV_OPT_OFF              // 아래 항목 중 선택하여 define
                                // EV_OPT_OFF : ICE, HEV 차종
                                // EV_OPT_ON  : EV 차종  

//#define WCT_REPRO_OTA_USE        // OTA 완료 후 리프로 사용 여부                                
                                // not defined (주석처리) : 미사용
                                // defined :  사용
                                
#define WCT_REPRO_CALIB_USE    // 캘리브레이션 영역 리프로 적용 여부               
                                // not defined (주석처리) : 미적용
                                // defined : 적용
                                                        
/****************************************************************
 APP Version define (날짜 기반 버전 관리)
****************************************************************/
#define cAppSoftVerYear1	'2' // 년도
#define cAppSoftVerYear2	'5' // 년도
#define cAppSoftVerMonth	'6' // 월 (A:10월, B:11월, C:12월)
#define cAppSoftVerOrder	'1' // 해당월의 릴리즈 차수 (월 변경시 초기화 1)
#define cAppSoftVerOption	'0' // 0:release, U:update , R:rollback, F:Fail, T:Test
/****************************************************************
 APP 내부 버전 define, 모든 내부 버전이 중복 되지 않도록 차종 구분자와 순차 증가되는 버전을 통합하여 사용.
****************************************************************/
// hex 파일명 자동 생성을 위해서 직접 define하도록 변경함.
// 차종 증가시마다 순차적으로 증가하여 ascii값으로 define한다.
// 1 : GN7 PE : '0' '1'
// 2 : RX4 PE : '0' '2'
// 3 : MX5 PE : '0' '3'
#define cAppSoftVerCAR1	    '0' // 차종 구분자 (hex) 
#define cAppSoftVerCAR2	    '1' // 차종 구분자 (hex)
#define cAppSoftVerIndex1	'1' // 배포시 순차적으로 증가 (hex)
#define cAppSoftVerIndex2	'1' // 배포시 순차적으로 증가 (hex)

/****************************************************************
 WCT Version define (충전IC 리프로를 위한 Target Ver)
****************************************************************/
#define cWCT_TARGET_VER1_TYPE4        'F'
#define cWCT_TARGET_VER2_TYPE4        '0'
#define cWCT_TARGET_VER3_TYPE4        '1'

#define cWCT_TARGET_VER1_TYPE5        'G'
#define cWCT_TARGET_VER2_TYPE5        '0'
#define cWCT_TARGET_VER3_TYPE5        '9'

#define cWCT_TARGET_VER1_TYPE6        'H'
#define cWCT_TARGET_VER2_TYPE6        '0'
#define cWCT_TARGET_VER3_TYPE6        '9'

/****************************************************************
 BCAN DB 버전 define
************************************************h****************/
// 0.70 : 20240816_STD_DB_CAR_R2.0_2024_FD_B2_v24.08.01W_Dvp_InitVal_Fixed.dbc 적용 (최초 임포트), dvp 추가, 레오스탯 초기값 10으로 수정
// 0.70 : 20240902_STD_DB_CAR_R2.0_2024_FD_B2_v24.08.01_Dvp_InitVal_Fixed.dbc (최신 db 임포트 2024.09.02), dvp 추가, 레오스탯 초기값 10으로 수정
// 0.70 : 20240902_STD_DB_CAR_R2.0_2024_FD_B2_v24.08.01_Dvp_InitVal_Fixed.dbc (db 재임포트 2025.02.14), dvp 추가, 레오스탯 초기값 10으로 수정, USM_Wpc2SetReq 신호 추가함. 동일 DB였으나 기존에 누락되어 있어서 다시 임포트함.
// 1.00 : 20250522_STD_DB_CAR_R2.0_2024_FD_B2_v25.05.01_WPCmsgDvp1_WPC2_IndSyncVal_Remove.dbc (db 수정하여 DVP Msg 추가, 향후 원본 db에 추가 예정, 
                                                                                                // 0.7 버전과 비교해서 tx:WPC_WU_01_500ms Msg 추가, rx 추가:VCU_GearPosSta,WPC2_IndSyncVal,PDC_ResetFuncOpt, rx 삭제 : USM_Wpc2SetReq)
                                                                                                // WPC2 메세지 0x392가 rx에도 있고 tx도 있어서 충돌로 인한 db 임포트 에러 발생함.
                                                                                                // WPC_FD의 rx 신호 WPC2_IndSyncVal 시그널을 db 파일에서 삭제후 임포트 실시함.
#define cBCanDBVersion1		'1'
#define cBCanDBVersion2		'0'
#define cBCanDBVersion3		'0'
/****************************************************************
 LCAN DB 버전 define
****************************************************************/
// 0.10 : 20240816_STD_DB_CAR_R2.0_2024_FD_BDC_Local_v24.08.01W_TpMsg_Fixed.dbc 적용 (최초 임포트), LCAN TP 메세지 설정 수정 없이 원본으로 사용함. 모빌진 프로그램 수정됨. --> 그러나 모빌진에서 miss match 에러 발생해서 설정 수정함.
// 0.40 : 20240902_STD_DB_CAR_R2.0_2024_FD_BDC_Local_v24.08.01.dbc(최신 db 임포트 2024.09.02, db 수정 없이 경고 팝업뜰대 무시하고 진행함.)
// 0.40 : 20240902_STD_DB_CAR_R2.0_2024_FD_BDC_Local_v24.08.01.dbc(TP통신 문제로 최신 모빌젠으로 재임포트 2025.03.11, db 수정 없이 경고 팝업뜰대 무시하고 진행함.)
// 0.40 : 20250522_STD_DB_CAR_R2.0_2024_FD_BDC_Local_v25.05.01.dbc(신규 db 배포됨. 0.40 대비 변경 사항없음. tx 동일, rx NM 노드 2개추가. NM은 변경무관함. db 임포트 없음)
#define cLCanDBVersion1     '0'
#define cLCanDBVersion2     '4'
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
#define cPlatformSoftVer2	'3'

#define cPlatformSoftVer3	cBCanDBVersion1		// CAN (표준) 버전
#define cPlatformSoftVer4	cBCanDBVersion2

#define cPlatformSoftVer5   cLCanDBVersion1     // Local-CAN(표준) 버전
#define cPlatformSoftVer6   cLCanDBVersion2

#define cPlatformSoftVer7	'0'		// OTA 호환성 버전
#define cPlatformSoftVer8	'0'     // A : HSM 2.11.0

#define cPlatformSoftVer9	'0'		// 플랫폼 자체 S/W 문제 개선 업데이트 시
#define cPlatformSoftVer10	'0'		// 플랫폼 사양서(차수)  변경시 초기화 됨


/****************************************************************
 디버그용 define (디버깅을 위한 기능이므로 양산 Hex 배포시에는 모두 주석처리 해야함)
****************************************************************/

#define DEBUG_EXT_WDT_NOT_USE           // exterbal WDT on/ Off 기능
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

// #define DEBUG_CARD_PROTECTION           // NFC Card 프로텍션 디버그&튜닝
                                        // not defined (주석처리) : 미사용
                                        // defined : 사용                    
                                        

                                                                

                                
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


