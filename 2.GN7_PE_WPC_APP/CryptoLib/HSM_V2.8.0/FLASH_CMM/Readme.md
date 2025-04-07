# CYT2BLX Trace32 CMM  script

## #0. 이 문서는?

HSM과 같이 배포된 CMM 파일들을 사용하기 쉽도록 안내합니다.



## #1. script 목록 및 요약

- cyt2bLx_HOST_HAE_release.cmm : host 에 fw 다운로드
- cyt2bLx_HOST_HAE_release_dual.cmm : host 에 fw 다운로드(dual bank용)
- cyt2bLx_HSM_HAE_release.cmm : hsm에 fw 다운로드
- cyt2bLx_HSM_HAE_release_dual.cmm : hsm에 fw 다운로드(dual bank용)
- cyt2bLx_flash_erase_all: code/work flash 모두 삭제



## #2. 각 script 사용 방법

### 1. cyt2bLx_HOST_HAE_release(_dual).cmm

- 수행 내용
  code/work flash 영역을 삭제한 다음 펌웨어를 chip에 다운로드 한다.
  dual bank용 스크립트의 경우 bank를 swap 한 다음 기록하는 과정이 추가되어 있다.
  
- 사용 방법
  Do ./cyt2bLx_HOST_HAE_release.cmm HOSTPATH=c:\host_cyt2bL8.elf
  
- 주의 사항
  host의 환경에 맞게 내용을 변경 후 사용하도록 한다.
  
  T32 에서는 2020년 11월 20일 현재 아직 CYT2BL 시리즈를 정식 지원하고 있지 않다.
  
  그렇기 때문에 cpu 선택 목록에서 CYT2BL 시리즈를 선택하여 사용할 수 없으므로 모든 cmm 스크립트에 cpu 타입이 CYT2B98CA 시리즈로 작업되어 있다. 만약 2011년 상반기에 T32에서 CYT2BL 시리즈를 정식으로 지원할 경우 해당 스크립트를 수정하여 사용해야 할 수 있다.
  
  flash에 기록하기 위해 cpu 가 CM0+ core로 지정되어 있다. (CM4의 오타가 아니다)
  
  
  

### 2. cyt2bLx_HSM_HAE_release(_dual).cmm
- 수행 내용
  code/work flash 영역을 삭제한 다음 펌웨어를 chip에 다운로드 한다.
  보안 관련 설정이 포함된 sflash 영역 또한 일부 내용이 기록된다.
  dual bank용 스크립트의 경우 bank를 swap 한 다음 기록하는 과정이 추가되어 있다.
  
- 사용 방법
  Do ./cyt2bLx_HSM_HAE.cmm HSMPATH=c:\HSM_Framework_CYT2BL8_rel.sre
  
- 주의 사항
  사용자의 환경에 맞게 내용을 변경 후 사용하도록 한다. 
  이 스크립트들은 예시 용으로 bugfix나 양산 장애 대응을 하지 않습니다.



## #3. 수정 내역

2020.10.21: 최초 작성

2020.11.20: T32 CYT2BL 시리즈 미지원 안내 추가

2021.02.05: 일부 환경에서 flash 관련 오동작 수정 및 watchdog 스크립트 추가 

2021.02.19: 오타 수정, dual bank 용 추가

2022.10.04: HOST dual bank용 cmm이 B bank의 HSM code flash 영역을 지우는 문제 수정, CPU 기본값을 CYT2BL로 변경
