@echo off
:: Variables
set MODULES=Mem
set FW_PATH=D:\ts_mirr\xml\gentool-fw-%gentoolfw_version%\mobilgene_c_generator
set XML_GEN=0

set RANDOM_NUMBER=%RANDOM%

:: get path Output Folder
:Loop
	IF [%1]==[-B] set XML_GEN=1
	IF [%1]==[-S] set XML_GEN=2
	IF [%1]==[] GOTO Continue
	IF [%1]==[-O] GOTO GetPath
	IF [%1]==[-o] GOTO GetPath		
	SHIFT
	GOTO Loop
:GetPath
	SHIFT
	SET OUT_FOLDER=%~f1
	ECHO %OUT_FOLDER%
:Continue

:: Check path folder output
IF %OUT_FOLDER%=="" GOTO OUTPUT_PATH_NOT_EXIST

:: get path folder of project
set PRJ_DIR=%OUT_FOLDER%\..\..
:: get abs path
FOR /F %%i IN ("%PRJ_DIR%") DO (set PRJ_DIR=%%~fi)


SET INPUT_FILE_YML=%PRJ_DIR%\Build\input_files.yml
SET BASE_DIR=%PRJ_DIR%
SET MODULE_TOP_PATH=%PRJ_DIR%\Static_Code\Modules
SET BSWMDT=%PRJ_DIR%\Static_Code\Modules\Mem_R44\generator\Bswmdt_Mem_76_Pfls.template

:: Run module
IF %XML_GEN%==0 %FW_PATH%\mobilgene_c_generator.exe -B %BASE_DIR% -M %MODULES% -T %MODULE_TOP_PATH% -O %OUT_FOLDER% -I %INPUT_FILE_YML% -L -V -G -configuration %FW_PATH%\%MODULES%_%RANDOM_NUMBER%

IF %XML_GEN%==1 %FW_PATH%\mobilgene_c_generator.exe -B %BASE_DIR% -M %MODULES% -T %MODULE_TOP_PATH% -O %OUT_FOLDER% -I %INPUT_FILE_YML% -XML -S %BSWMDT% -L -G -configuration %FW_PATH%\%MODULES%_%RANDOM_NUMBER%

rem echo "Remove folder template"
IF EXIST %FW_PATH%\%MODULES%_%RANDOM_NUMBER% RMDIR /q /s %FW_PATH%\%MODULES%_%RANDOM_NUMBER%

IF %ERRORLEVEL% == 1 GOTO ERROR

GOTO FINISH

:OUTPUT_PATH_NOT_EXIST
@echo Error : Output Folder path is not exist.
GOTO ERROR

:ERROR
rem @echo Generate module %MODULES% : error
EXIT 1

:FINISH
rem @echo Generate %MODULES% finished
EXIT 0


