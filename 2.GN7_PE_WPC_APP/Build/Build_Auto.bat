@echo off
pushd %0\..\..
setlocal
IF "%PYTHON_HOME%"=="" set PYTHON_HOME=D:\ts_mirr\python\Portable_Python_2.7.6.1\App
IF "%SCONS_HOME%"=="" set SCONS_HOME=D:\ts_mirr\scons\scons-local-2.3.4
set PATH=%PATH%;%PYTHON_HOME%;%SCONS_HOME%
set gentoolfw_version=1.1.6.2
%PYTHON_HOME%\python Build\site_scons\build.pyc %*
endlocal
popd

:: s19 생성을 위해서 추가함.
::경로 이동
cd .\CRT
::MCRT 를 이용하여 s19 생성 명령 실행
.\mcrt_utip.exe .\e_gn7_pe_wpc_asr_swp_rtsw_sf2.0_20240620.utp

::메모리 사용량 계산
call MemoryUsage.bat

::배포 파일명 자동 변경 및 이동
cd ..\
powershell -ExecutionPolicy Bypass -File .\Release_Auto.ps1

exit /B %ERRORLEVEL%
::pause
