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
::cd .\Build\CRT
::MCRT 를 이용하여 s19 생성 명령 실행
::박남숙 책임이 만들어준 자동화 툴 사용을 위해서 주석 처리함
::.\mcrt_utip.exe .\e_gn7_pe_wpc_asr_swp_rtsw_sf2.0_20240620.utp

::메모리 사용량 계산
echo Calculate Memroy Usage
call MemoryUsage.bat

:: sre 파일 포맷 길이 변경 (data byte 수 28 --> 32), aSIMS에서 생성되는 s19 파일과 비교를 용이하게 하기 위해서 동일한 바이트수로 변경함
echo Make s19 file
call D:\ts_mirr\gh\ARM.V2017.1.4\comp_201714\gsrec.exe -pad1 0x10058000 0x101f7fff 0xFF -bytes 32 .\Debug\GN7_PE_WPC_APP.elf -o .\Debug\GN7_PE_WPC_APP_Compare.s19


exit /B %ERRORLEVEL%
::pause
