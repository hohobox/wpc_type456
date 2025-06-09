@echo off
pushd %0\..\..
setlocal
IF "%PYTHON_HOME%"=="" set PYTHON_HOME=D:\ts_mirr\python\Portable_Python_2.7.6.1\App
IF "%SCONS_HOME%"=="" set SCONS_HOME=D:\ts_mirr\scons\scons-local-2.3.4
set PATH=%PATH%;%PYTHON_HOME%;%SCONS_HOME%
set gentoolfw_version=1.2.1
rem set FW_PATH=D:\ts_mirr\xml\gentool-fw-%gentoolfw_version%\mobilgene_c_generator
set FW_PATH=D:\ts_mirr\xml\gentool-fw-%gentoolfw_version%\mobilgene_c_generator
set print_gbtime=True

set VALIDATION=false
shift
for %%A in (%*) do (
    if /I "%%A"=="-V" (set VALIDATION=true)
    if /I "%%A"=="-v" (set VALIDATION=true)
)

%PYTHON_HOME%\python Build\site_scons\build.pyc %*
endlocal
popd


:: s19 생성을 위해서 추가함.
::경로 이동
cd .\Build\CRT
::MCRT 를 이용하여 s19 생성 명령 실행
.\mcrt_utip.exe .\e_gn7_pe_wpc_asr_swp_fbl_sf2.0_20240620.utp

exit /B %ERRORLEVEL%
::pause
