@echo off

setlocal Enabledelayedexpansion

@REM 수정할곳 : 컴파일러 주소
IF "%GHS_HOME%"=="" set GHS_HOME=C:\GHS\comp_201714
set PATH=%PATH%;%GHS_HOME%

REM Calculate memory usage
@REM 수정할곳 : max 값 수정 ROM , RAM size 단위 bytes (data sheet 참고)
set /a MAX_RAM=512 * 1024
:: 이중화로 ROM 4M의 절반인 2M 사용.
set /a MAX_ROM=2112 * 1024 

set i=0

@REM 수정할곳 : 계산 대상이 되는 elf 파일, elf는 app와 swp 영역에 대해서만 계산된다.
for /f "tokens=2 delims= " %%a IN ('%GHS_HOME%\gsize.exe -ram -rom ..\..\Debug\GN7_PE_WPC_APP.elf') do (
	set result[!i!]=%%a
	set /a i=i+1
)

::  /*
::   * [Memory Layout for mobilgene Classic SWP] 
::   * -----------------------------------------------------------------------------
::   * | CM0+ [HSM]      | CM4 or CM7_0 [FBL] | CM4 or CM7_0 [RTSW]                |
::   * | RAM : 40KB      | RAM : 40KB         | RAM : End of CM0+ ~ End of MCU     |
::   * | ROM : 160KB     | ROM : 192KB        | ROM : End of FBL  ~ End of MCU     |
::   * -----------------------------------------------------------------------------
::   */
::  * {CYT2BLXX_4M}
::  *  - SRAM0             : 0x0800_0000--0x0803_FFFF  (256KB) 
::  *  - SRAM1             : 0x0804_0000--0x0807_FFFF  (256KB) 
::  *  - CODE_SB_LS[32KB]  : 0x1000_0000--0x103E_FFFF (4032KB) 
::  *  - CODE_SB_SS[8KB]   : 0x103F_0000--0x1040_FFFF  (128KB) 
::  *  - CODE_DB_LS[32KB]  : 0x1000_0000--0x101F_7FFF (2016KB) 
::  *  - CODE_DB_SS[8KB]   : 0x101F_8000--0x1020_7FFF   (64KB)   

@REM FBL, HSM의 rom ram 사용 또는 할당된 size 입력.(배포 문서 또는 ld 파일 참고)
:: FBL 실제 사용량
::set /a FBL_ROM=70 * 1024
:: fbl ram은 실제로는 해당 안됨. fbl과 app이 동시에 사용되지 않으므로 적용 안됨. 사용량이 더 큰 app쪽만 계산함
::set /a FBL_RAM=

:: FBL 할당된 MAX 값
set /a FBL_ROM=192 * 1024
::set /a FBL_RAM=40 * 1024

:: HSM 실제 사용량
::set /a HSM_ROM=145 * 1024
::set /a HSM_RAM=38 * 1024

:: HSM 할당된 MAX 값
set /a HSM_ROM=160 * 1024
set /a HSM_RAM=40 * 1024


@REM 수정할 곳 : app 및 swp에서 사용하는 메모리(gsize.exe로 자동 계산), result[0]:ram, result[1]:rom
set /a APP_RAM=result[0]
set /a APP_ROM=result[1]


set /a SUM_RAM=HSM_RAM + APP_RAM
set /a RAM_Rate=SUM_RAM*100/MAX_RAM
set /a RAM_Remainder=SUM_RAM-(RAM_Rate*MAX_RAM/100)
set /a RAM_Ratefp=((RAM_Remainder*10000/MAX_RAM+5))/10

set /a SUM_ROM=FBL_ROM + HSM_ROM + APP_ROM
set /a ROM_Rate=SUM_ROM*100/MAX_ROM
set /a ROM_Remainder=SUM_ROM-(ROM_Rate*MAX_ROM/100)
set /a ROM_Ratefp=((ROM_Remainder*10000)/MAX_ROM+5)/10


echo.
echo ===========================================
::echo FBL_RAM (byte) : %FBL_RAM%
::echo HSM_RAM (byte) : %HSM_RAM%
::echo APP_RAM (byte) : %APP_RAM%
::echo SUM_RAM (byte) : %SUM_RAM%
::echo MAX_RAM (byte) : %MAX_RAM%
::echo.
::echo FBL_ROM (byte) : %FBL_ROM%
::echo HSM_ROM (byte) : %HSM_ROM%
::echo APP_ROM (byte) : %APP_ROM%
::echo SUM_ROM (byte) : %SUM_ROM%
::echo MAX_ROM (byte) : %MAX_ROM%
echo.
echo RAM Usage (byte) : %SUM_RAM% / %MAX_RAM% (%RAM_Rate%.%RAM_Ratefp% %%)
echo ROM Usage (byte) : %SUM_ROM% / %MAX_ROM% (%ROM_Rate%.%ROM_Ratefp% %%)
echo ===========================================

::pause

::팝업 메세지 미표시
::set message=RAM_Size : %result[0]% bytes or %SUM_ROM% KB (%RAM_Usage_Per%.%RAM_Ratefp% %%)				ROM_Size : %result[1]% bytes or %SUM_RAM% KB (%ROM_Usage_Per%.%ROM_Ratefp% %%)
::start msg /w * "%message%"


endlocal
exit /B %ERRORLEVEL%
