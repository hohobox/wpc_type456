@echo off

SET GEN_OPTION=%1
IF NOT "-O" == "%GEN_OPTION:~0,2%" GOTO SET_GEN_BASIC
GOTO GEN_BASIC_CONFIG_NOT_EXIST

:SET_GEN_BASIC
SET GEN_BASIC=%GEN_OPTION:~1%
echo Set generator path : %GEN_BASIC%
SHIFT
IF NOT EXIST %GEN_BASIC% GOTO GEN_BASIC_CONFIG_NOT_EXIST

:PROCESS
REM SET GEN_HOME=%~dp0
SET GEN_HOME=%GEN_BASIC%\E2EXf_1.1.9
SET JAVA_HOME=%GEN_BASIC%\jre1.8.0_121
SET OUTPUT=%~f2
SHIFT
SHIFT
SHIFT

:BEGIN
IF "" == "%0" GOTO END
SET INPUT=%INPUT%%~f0,
SHIFT
GOTO BEGIN
:END
REM SET VMARGS=-Duser.language=en -Duser.country=US -Dosgi.requiredJavaVersion=1.8 -Dorg.osgi.framework.os.name=win32 -Xms256m -Xss4m -Xmx1024m
rem SET VMARGS=-Duser.language=en -Dosgi.requiredJavaVersion=1.8 -Dorg.osgi.framework.os.name=win32 -Xms256m -Xss4m -Xmx1024m
SET VMARGS=-Duser.language=en -Dosgi.requiredJavaVersion=1.8 -Dorg.osgi.framework.os.name=win32 -Xms256m -Xss4m -Xmx1024m

IF NOT EXIST %GEN_HOME% GOTO GEN_HOME_NOT_EXIST 
IF NOT EXIST %JAVA_HOME% GOTO JAVA_HOME_NOT_EXIST 

%JAVA_HOME%\bin\java.exe %VMARGS% -jar %GEN_HOME%\plugins\org.eclipse.equinox.launcher_1.3.0.v20140415-2008.jar -application com.kpit.c4k.core.workflow.runner -WComponent=E2EXf.GenerateE2EXf -Winput=%INPUT% -Woutputinc=%OUTPUT%\inc -Woutputsrc=%OUTPUT%\src

DIR "%OUTPUT%\..\..\null\Validation.txt" > NUL
IF %ERRORLEVEL% == 1 GOTO NEXT

TYPE %OUTPUT%\..\..\null\Validation.txt
 RMDIR /S /Q %OUTPUT%\..\..\null
GOTO NEXT

:NEXT
DIR "%OUTPUT%\inc\E2EXf.h" > NUL
IF %ERRORLEVEL% == 1 GOTO ERROR

DIR "%OUTPUT%\inc\E2EXf_Cfg.h" > NUL
IF %ERRORLEVEL% == 1 GOTO ERROR

DIR "%OUTPUT%\src\E2EXf.c" > NUL
IF %ERRORLEVEL% == 1 GOTO ERROR

GOTO OK

:GEN_BASIC_CONFIG_NOT_EXIST
echo ERR_E2EXF_0039 : 'Transformer Generator Path' in SCons.arxml or 'TransformerGenerator' in SConstruct file should be configured.
GOTO ERROR

:GEN_HOME_NOT_EXIST
echo GEN_HOME = %GEN_HOME%
echo ERR_E2EXF_0040 : GEN_HOME is not exist.
GOTO ERROR

:JAVA_HOME_NOT_EXIST
echo JAVA_HOME = %JAVA_HOME%
echo ERR_E2EXF_0041: JAVA_HOME path is not exist.
GOTO ERROR

:ERROR
@ECHO Build Failed
EXIT 1

:OK
@ECHO Build Completed
EXIT 0