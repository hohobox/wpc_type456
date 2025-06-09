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

/****************************************************************
 FBL Version define (날짜 기반 버전 관리)
****************************************************************/
// FBL 고객 버전은 관리 대상이 아니므로 기능 구현만 한 상태임. (배포시트에 기재하지 않음)
#define cFblSoftVerYear1	'2'
#define cFblSoftVerYear2	'5'
#define cFblSoftVerMonth	'5'
#define cFblSoftVerOrder	'1'
#define cFblSoftVerUsage	'0' // 0:release, U:update , R:rollback, F:Fail, T:Test
/****************************************************************
 APP 내부 버전 define, 모든 내부 버전이 중복 되지 않도록 차종 구분자와 순차 증가되는 버전을 통합하여 사용.
****************************************************************/
// cAppSoftVerCAR1는 const 로 해서 초기화 하면서 값을 할당해야 해서 상수가 아니면 초기화 에러가 발생한다.
// 차종 증가시마다 순차적으로 증가하여 ascii값으로 define한다.
// GN7 PE : '0' '1'
// RX4 PE : '0' '2'

#define cAppSoftVerCAR1	    '0' // 차종 구분자 (hex)
#define cAppSoftVerCAR2	    '1' // 차종 구분자 (hex)
#define cAppSoftVerIndex1	'0' // 배포시 순차적으로 증가 (hex)
#define cAppSoftVerIndex2	'5' // 배포시 순차적으로 증가 (hex)
/****************************************************************
 SWP Version define
****************************************************************/
#define cSWP_FBL_VER1       '2'
#define cSWP_FBL_VER2       '1'
#define cSWP_FBL_VER3       '11'


/****************************************************************
 사양 define (차종 사양에 따라 결정되므로 당당자에게 확인 후 설정 할것)
****************************************************************/
#define DOWNGRADE_PREVENT_ON    // 아래 항목 중 선택하여 define
                                // DOWNGRADE_PREVENT_OFF : 다운그레이드 방지 미사용
                                // DOWNGRADE_PREVENT_ON : 다운그레이드 방지 사용



/****************************************************************
 디버그용 define (디버깅을 위한 기능이므로 양산 Hex 배포시에는 모두 주석처리 해야함)
****************************************************************/

                                        
// #define DEBUG_FIXED_RANDOM_SEED_USE     // OEUK 인증용 Random Seed 사용 여부 선택
                                        // not defined (주석처리) : random Seed 사용(배포시)
                                        // defined : fixed random seed 사용 11 22 33 ~ 88 (Canoe로 임시 테스트시)
                                        
#endif
