# 버전 정보가 정의된 파일 경로
$versionFile = "..\Static_Code\App_Code\EcuInfo.h"

# 버전 정보를 담을 해시테이블 생성
$versionDefines = @{
    "cAppSoftVerYear1"  = ''
    "cAppSoftVerYear2"  = ''
    "cAppSoftVerMonth"  = ''
    "cAppSoftVerOrder"  = ''
    "cAppSoftVerOption" = ''
    "cAppSoftVerCAR1"   = ''
    "cAppSoftVerCAR2"   = ''
    "cAppSoftVerIndex1" = ''
    "cAppSoftVerIndex2" = ''
}

# 키 목록을 별도의 배열로 복사하여 사용 (중요!)
$keysArray = @($versionDefines.Keys)

# versionFile에서 define 값을 읽어옵니다.
foreach ($key in $keysArray) {
    $pattern = "#define\s+$key\s+'(.+)'"
    $matchResult = Select-String -Path $versionFile -Pattern $pattern | Select-Object -First 1

    if ($matchResult -and ($matchResult.Line -match $pattern)) {
        # 이제 안전하게 값을 변경할 수 있습니다.
        $versionDefines[$key] = $matches[1]
        Write-Host "DEBUG: $key = $($versionDefines[$key])"
    } else {
        Write-Error "Error: 버전 정보 [$key]를 찾을 수 없습니다."
        exit 1
    }
}

# 읽어온 버전 정보를 조합하여 전체 버전 문자열 구성
$fullVersion = "$($versionDefines.cAppSoftVerYear1)$($versionDefines.cAppSoftVerYear2)" +
               "$($versionDefines.cAppSoftVerMonth)" +
               "$($versionDefines.cAppSoftVerOrder)" +
               "$($versionDefines.cAppSoftVerOption)" +
               "_$($versionDefines.cAppSoftVerCAR1)$($versionDefines.cAppSoftVerCAR2)" +
               "$($versionDefines.cAppSoftVerIndex1)$($versionDefines.cAppSoftVerIndex2)"

Write-Host "DEBUG: Full Version = $fullVersion"

# 복사할 파일 목록
$sourceFiles = @(
    "..\Debug\GN7_PE_WPC_APP.hex",
    "..\Debug\GN7_PE_WPC_APP.elf",
    "..\Debug\GN7_PE_WPC_APP.s19"
)

# 대상 폴더 경로
$destinationFolder = "..\Release"

# 현재 날짜 가져오기 (형식: YYYYMMDD)
$currentDate = Get-Date -Format "yyyyMMdd"

# 파일 복사 작업
foreach ($sourceFile in $sourceFiles) {
    if (Test-Path $sourceFile) {
        # 원본 파일명 추출
        $fileName = Split-Path -Path $sourceFile -Leaf  # 전체 파일명 (예: GN7_PE_WPC_APP.hex)
        Write-Host "DEBUG: Original File Name = $fileName"

        # 확장자 제외한 파일명 추출
        $baseName = [System.IO.Path]::GetFileNameWithoutExtension($fileName)
        Write-Host "DEBUG: Base Name = $baseName"

        # 확장자 추출
        $extension = [System.IO.Path]::GetExtension($fileName).TrimStart('.')
        Write-Host "DEBUG: Extension = $extension"

        # 새 파일명 생성 (원본 파일명 + 버전 정보 + 날짜)
        if (-not [string]::IsNullOrEmpty($baseName) -and -not [string]::IsNullOrEmpty($extension)) {
            $newFileName = "$baseName" + "_$fullVersion" + "_$currentDate" + ".$extension"
            Write-Host "DEBUG: New File Name = $newFileName"
        } else {
            Write-Error "Error: Base Name or Extension is empty for file: $fileName"
            exit 1
        }

        # 대상 경로 생성
        $destinationFile = Join-Path -Path $destinationFolder -ChildPath $newFileName

        # 파일 복사
        Copy-Item -Path $sourceFile -Destination $destinationFile -Force
        Write-Host "File has been copied.: $destinationFile"
    } else {
        Write-Error "Error: File does not exist.: $sourceFile"
        exit 1
    }
}



# 릴리즈 노트 파일 경로 생성 (HEX 파일명과 동일하게 구성하고 뒤에 "_Release_Note.txt" 추가)
$releaseNotesFileName = "$baseName" + "_$fullVersion" + "_$currentDate" + "_Release_Note.txt"
$releaseNotesPath = Join-Path -Path $destinationFolder -ChildPath $releaseNotesFileName

# 릴리즈 노트 내용 작성
$releaseNotesContent = @"
Release Notes
=============
Customer Ver: $($versionDefines.cAppSoftVerYear1)$($versionDefines.cAppSoftVerYear2)$($versionDefines.cAppSoftVerMonth)$($versionDefines.cAppSoftVerOrder)$($versionDefines.cAppSoftVerOption)
Nidec Ver: $($versionDefines.cAppSoftVerCAR1)$($versionDefines.cAppSoftVerCAR2)$($versionDefines.cAppSoftVerIndex1)$($versionDefines.cAppSoftVerIndex2)
Build Date: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')
Changes:
- Proto Release 
-
-
"@

# 릴리즈 노트를 파일로 저장
Set-Content -Path $releaseNotesPath -Value $releaseNotesContent -Encoding UTF8

# 성공 메시지 출력
Write-Host "Release notes have been generated.: $releaseNotesPath"
