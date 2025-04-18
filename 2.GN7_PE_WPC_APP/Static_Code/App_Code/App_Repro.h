/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/


#ifndef  APP_REPRO_H
#define  APP_REPRO_H

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"

/***************************************************************************************************
    GLOBAL DEFINES AND MACROS
***************************************************************************************************/
#define cRepro_Disable 	0u
#define cRepro_Enable 	1u



/*! The required first character of an S-record. */
#define SRECORD_START_CHAR  'S'

// "S3 81 00000000 54E1589F54E1589F54E2D92754E2D92754E2D
/*! The minimum length of a S-record. This is the type (2) + count (2) + addr (8) + cksum (2). */
#define SRECORD_MIN_LENGTH  14u

/*! Index of the first character of the address field. */
#define SRECORD_ADDRESS_START_CHAR_INDEX    4u

#define kMinPacketBufferSize 32u
#define kIncomingPacketBufferSize kMinPacketBufferSize
#define kOutgoingPacketBufferSize kMinPacketBufferSize

/*! @brief Construct a status code value from a group and code number. */
#define MAKE_STATUS(group, code) ((((group)*100) + (code)))






/***************************************************************************************************
    GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/

typedef enum 
{
    FLASH_IDLE,          // 대기 상태
	FLASH_PARSING,       // Parsing
    FLASH_ERASING,       // 플래시 지우기 진행 중
    FLASH_PROGRAMMING,   // 플래시 프로그래밍 진행 중
    FLASH_VER_CHECK,     // 버전 비교 중
    FLASH_CALIBRATION,   // 충전 IC 캘리브레이션 대기    
    FLASH_COMPLETE_UNMATCH, // 프로그래밍 완료, 버전 불일치 발생
    FLASH_COMPLETED,     // 프로그래밍 완료
    FLASH_ERROR          // 오류 발생
} FLASH_State;

typedef enum
{
	cReproReq_Default,
	cReproReq_Off,
	cReproReq_On,
    cReproReq_Error,
    cReproReq_Invalid,
} Repro_ENUM_t;


typedef enum
{
	cVerCheck_Default,
	cVerCheck_Unmatch,
	cVerCheck_Match,
	cVerCheck_Error
} VerCheck_ENUM_t;


typedef uint8_t recordStatus_t;

/*! @brief Status group numbers. */
enum _status_groups
{
    kStatusGroup_Generic = 0,                 /*!< Group number for generic status codes. */
    kStatusGroup_FLASH = 1,                   /*!< Group number for FLASH status codes. */
    kStatusGroup_LPSPI = 4,                   /*!< Group number for LPSPI status codes. */
    kStatusGroup_FLEXIO_SPI = 5,              /*!< Group number for FLEXIO SPI status codes. */
    kStatusGroup_DSPI = 6,                    /*!< Group number for DSPI status codes. */
    kStatusGroup_FLEXIO_UART = 7,             /*!< Group number for FLEXIO UART status codes. */
    kStatusGroup_FLEXIO_I2C = 8,              /*!< Group number for FLEXIO I2C status codes. */
    kStatusGroup_LPI2C = 9,                   /*!< Group number for LPI2C status codes. */
    kStatusGroup_UART = 10,                   /*!< Group number for UART status codes. */
    kStatusGroup_I2C = 11,                    /*!< Group number for UART status codes. */
    kStatusGroup_LPSCI = 12,                  /*!< Group number for LPSCI status codes. */
    kStatusGroup_LPUART = 13,                 /*!< Group number for LPUART status codes. */
    kStatusGroup_SPI = 14,                    /*!< Group number for SPI status code.*/
    kStatusGroup_XRDC = 15,                   /*!< Group number for XRDC status code.*/
    kStatusGroup_SEMA42 = 16,                 /*!< Group number for SEMA42 status code.*/
    kStatusGroup_SDHC = 17,                   /*!< Group number for SDHC status code */
    kStatusGroup_SDMMC = 18,                  /*!< Group number for SDMMC status code */
    kStatusGroup_SAI = 19,                    /*!< Group number for SAI status code */
    kStatusGroup_MCG = 20,                    /*!< Group number for MCG status codes. */
    kStatusGroup_SCG = 21,                    /*!< Group number for SCG status codes. */
    kStatusGroup_SDSPI = 22,                  /*!< Group number for SDSPI status codes. */
    kStatusGroup_FLEXIO_I2S = 23,             /*!< Group number for FLEXIO I2S status codes */
    kStatusGroup_SDRAMC = 35,                 /*!< Group number for SDRAMC status codes. */
    kStatusGroup_POWER = 39,                  /*!< Group number for POWER status codes. */
    kStatusGroup_ENET = 40,                   /*!< Group number for ENET status codes. */
    kStatusGroup_PHY = 41,                    /*!< Group number for PHY status codes. */
    kStatusGroup_TRGMUX = 42,                 /*!< Group number for TRGMUX status codes. */
    kStatusGroup_SMARTCARD = 43,              /*!< Group number for SMARTCARD status codes. */
    kStatusGroup_LMEM = 44,                   /*!< Group number for LMEM status codes. */
    kStatusGroup_QSPI = 45,                   /*!< Group number for QSPI status codes. */
    kStatusGroup_DMA = 50,                    /*!< Group number for DMA status codes. */
    kStatusGroup_EDMA = 51,                   /*!< Group number for EDMA status codes. */
    kStatusGroup_DMAMGR = 52,                 /*!< Group number for DMAMGR status codes. */
    kStatusGroup_FLEXCAN = 53,                /*!< Group number for FlexCAN status codes. */
    kStatusGroup_LTC = 54,                    /*!< Group number for LTC status codes. */
    kStatusGroup_FLEXIO_CAMERA = 55,          /*!< Group number for FLEXIO CAMERA status codes. */
    kStatusGroup_NOTIFIER = 98,               /*!< Group number for NOTIFIER status codes. */
    kStatusGroup_DebugConsole = 99,           /*!< Group number for debug console status codes. */
    kStatusGroup_ApplicationRangeStart = 100, /*!< Starting number for application groups. */
};

/*! @brief Generic status return codes. */
enum _generic_status
{
    kStatus_Success = MAKE_STATUS(kStatusGroup_Generic, 0),
    kStatus_Fail = MAKE_STATUS(kStatusGroup_Generic, 1),
    kStatus_ReadOnly = MAKE_STATUS(kStatusGroup_Generic, 2),
    kStatus_OutOfRange = MAKE_STATUS(kStatusGroup_Generic, 3),
    kStatus_InvalidArgument = MAKE_STATUS(kStatusGroup_Generic, 4),
    kStatus_Timeout = MAKE_STATUS(kStatusGroup_Generic, 5),
    kStatus_NoTransferInProgress = MAKE_STATUS(kStatusGroup_Generic, 6),
};

//! @brief Bootloader status group numbers.
//!
//! @ingroup bl_core
enum _bl_status_groups
{
    kStatusGroup_Bootloader = kStatusGroup_ApplicationRangeStart, //!< Bootloader status group number (100).
    kStatusGroup_SBLoader,                                        //!< SB loader status group number (101).
    kStatusGroup_MemoryInterface,                                 //!< Memory interface status group number (102).
    kStatusGroup_PropertyStore,                                   //!< Property store status group number (103).
    kStatusGroup_AppCrcCheck,                                     //!< Application crc check status group number (104).
    kStatusGroup_Packetizer,                                      //!< Packetizer status group number (105).
    kStatusGroup_ReliableUpdate                                   //!< Reliable Update status groupt number (106).
};

//! @brief Bootloader status codes.
//! @ingroup bl_core
enum _bootloader_status
{
    kStatus_UnknownCommand = MAKE_STATUS(kStatusGroup_Bootloader, 0),
    kStatus_SecurityViolation = MAKE_STATUS(kStatusGroup_Bootloader, 1),
    kStatus_AbortDataPhase = MAKE_STATUS(kStatusGroup_Bootloader, 2),
    kStatus_Ping = MAKE_STATUS(kStatusGroup_Bootloader, 3),
    kStatus_NoResponse = MAKE_STATUS(kStatusGroup_Bootloader, 4),
    kStatus_NoResponseExpected = MAKE_STATUS(kStatusGroup_Bootloader, 5)
};

//! @brief Commands codes.
enum _command_tags
{
    kCommandTag_GenericResponse = 0xa0,
    kCommandTag_FlashEraseAll = 0x01,
    kCommandTag_FlashEraseRegion = 0x02,
    kCommandTag_ReadMemory = 0x03,
    kCommandTag_ReadMemoryResponse = 0xa3,
    kCommandTag_WriteMemory = 0x04,
    kCommandTag_FillMemory = 0x05,
    kCommandTag_FlashSecurityDisable = 0x06,
    kCommandTag_GetProperty = 0x07,
    kCommandTag_GetPropertyResponse = 0xa7,
    kCommandTag_ReceiveSbFile = 0x08,
    kCommandTag_Execute = 0x09,
    kCommandTag_Call = 0x0a,
    kCommandTag_Reset = 0x0b,
    kCommandTag_SetProperty = 0x0c,
    kCommandTag_FlashEraseAllUnsecure = 0x0d,
    kCommandTag_FlashProgramOnce = 0x0e,
    kCommandTag_FlashReadOnce = 0x0f,
    kCommandTag_FlashReadOnceResponse = 0xaf,
    kCommandTag_FlashReadResource = 0x10,
    kCommandTag_FlashReadResourceResponse = 0xb0,
    kCommandTag_ConfigureQuadSpi = 0x11,
    kCommandTag_ReliableUpdate = 0x12,

    kCommandTag_ConfigureI2c = 0xc1, //! Reserved command tag for Bus Pal
    kCommandTag_ConfigureSpi = 0xc2, //! Reserved command tag for Bus Pal
    kCommandTag_ConfigureCan = 0xc3, //! Reserved command tag for Bus Pal

    kFirstCommandTag = kCommandTag_FlashEraseAll,

    //! Maximum linearly incrementing command tag value, excluding the response commands and bus pal commands.
    kLastCommandTag = kCommandTag_ReliableUpdate,

    kResponseCommandHighNibbleMask = 0xa0 //!< Mask for the high nibble of a command tag that identifies it as a response command.
};

//! @brief Serial framing packet constants.
enum _framing_packet_constants
{
    kFramingPacketStartByte = 0x5a,
    kFramingPacketType_Ack = 0xa1,
    kFramingPacketType_Nak = 0xa2,
    kFramingPacketType_AckAbort = 0xa3,
    kFramingPacketType_Command = 0xa4,
    kFramingPacketType_Data = 0xa5,
    kFramingPacketType_Ping = 0xa6,
    kFramingPacketType_PingResponse = 0xa7
};


//! @brief State information for the CRC16 algorithm.
typedef struct Crc16Data
{
    uint16_t currentCrc; //!< Current CRC value.
} crc16_data_t;

typedef struct _srecord_t
{
    uint8_t type;      /*!< Record number type, such as 9 for "S9", 3 for "S3" and so on.*/
    uint8_t count;     /*!< Number of character pairs (bytes) from address through checksum.*/
    uint32_t address;  /*!< The address specified as part of the S-record.*/
    uint8_t dataCount; /*!< Number of bytes of data.*/
    uint8_t data[256]; /*!< Pointer to data, or NULL if no data for this record type.*/
    uint8_t checksum;  /*!< The checksum byte present in the S-record.*/
} srecord_t;

//! @brief Command packet format.
typedef struct CommandPacket
{
    uint8_t commandTag;     //!< A command tag.
    uint8_t flags;          //!< Combination of packet flags.
    uint8_t reserved;       //!< Reserved, helpful for alignment, set to zero.
    uint8_t parameterCount; //!< Number of parameters that follow in buffer.
} command_packet_t;


//! @brief Structure of version property.
//!
//! @ingroup bl_core
typedef union StandardVersion
{
    struct
    {
        uint8_t bugfix; //!< bugfix version [7:0]
        uint8_t minor;  //!< minor version [15:8]
        uint8_t major;  //!< major version [23:16]
        char name;      //!< name [31:24]
    };
    uint32_t version; //!< combined version numbers

} standard_version_t;

//! @brief Serial framing header.
typedef struct FramingHeader
{
    uint8_t startByte;  //!< #kFramingPacketStartByte
    uint8_t packetType; //!< Framing packet type
} framing_header_t;


//! @brief Serial framing data packet.
#pragma pack(1)
typedef struct FramingDataPacket
{
    framing_header_t header; //!< Framing packet header
    uint16_t length;         //!< Number of data bytes that follow
    uint16_t crc16;          //!< CRC-16 of data packet header and data
} framing_data_packet_t;
#pragma pack()

//! @brief Framing packet with data area.
typedef struct SerialFramingPacket
{
    framing_data_packet_t dataPacket;        //!< Packet header.
    uint8_t data[kOutgoingPacketBufferSize]; //!< Payload.
} serial_framing_packet_t;


//! @brief Serial ping response format.
//!
//! This is the format of the response to a Ping packet.
typedef struct PingResponse
{
    standard_version_t version; //!< Serial framing protocol version
    uint16_t options;           //!< Serial framing protocol options bitfield
    uint16_t crc16;             //!< CRC-16 of other fields
} ping_response_t;

#pragma pack(1)
/*! @brief command packet */
typedef struct _command_frame_packet
{
    framing_data_packet_t framing_data;
    command_packet_t command_data;
    uint32_t param[7];
} command_frame_packet_t;
#pragma pack()


#pragma pack(1)
/*! @brief command packet */
typedef struct _ping_response_frame_packet_t
{
    framing_header_t header; //!< Framing packet header
    ping_response_t ping_response_data;
} ping_response_frame_packet_t;
#pragma pack()

#if 0 // 에러 플래그 모음

/*! @brief Status return code descriptions. */
struct StatusMessageTableEntry
{
    int32_t status;      /*!< Status code value. */
    const char *message; /*!< Description of the status. */
};
struct StatusMessageTableEntry g_statusCodes[] = {
    /* Generic statuses. */
    { kStatus_Success, "Success." },
    { kStatus_Fail, "Failure." },
    { kStatus_ReadOnly, "kStatus_ReadOnly" },
    { kStatus_OutOfRange, "kStatus_OutOfRange" },
    { kStatus_InvalidArgument, "kStatus_InvalidArgument" },

    /* Flash driver errors. */
    { 100 /*kStatus_FlashSizeError*/, "kStatus_FlashSizeError" },
    { 101 /*kStatus_FlashAlignmentError*/, "kStatus_FlashAlignmentError" },
    { 102 /*kStatus_FlashAddressError*/, "kStatus_FlashAddressError" },
    { 103 /*kStatus_FlashAccessError*/, "kStatus_FlashAccessError" },
    { 104 /*kStatus_FlashProtectionViolation*/, "kStatus_FlashProtectionViolation" },
    { 105 /*kStatus_FlashCommandFailure*/, "kStatus_FlashCommandFailure" },
    { 106 /*kStatus_FlashUnknownProperty*/, "kStatus_FlashUnknownProperty" },
    { 108 /*kStatus_FlashRegionExecuteOnly*/, "kStatus_FlashRegionExecuteOnly" },
    { 109 /*kStatus_FlashExecuteInRamFunctionNotReady*/, "kStatus_FlashExecuteInRamFunctionNotReady" },

    /* I2C driver errors. */
    { 200 /*kStatus_I2C_SlaveTxUnderrun*/, "I2C Slave TX Underrun error." },
    { 201 /*kStatus_I2C_SlaveRxOverrun*/, "I2C Slave RX Overrun error." },
    { 202 /*kStatus_I2C_AribtrationLost*/, "I2C Arbitration Lost error." },

    /* SPI driver errors. */
    { 300 /*kStatus_SPI_SlaveTxUnderrun*/, "SPI Slave TX Underrun error." },
    { 301 /*kStatus_SPI_SlaveRxOverrun*/, "SPI Slave RX Overrun error." },

    /* QSPI driver errors. */
    { 400 /*kStatus_QspiFlashSizeError*/, "QSPI Flash Size error." },
    { 401 /*kStatus_QspiFlashAlignmentError*/, "QSPI Flash Alignment error." },
    { 402 /*kStatus_QspiFlashAddressError*/, "QSPI Flash Address error." },
    { 403 /*kStatus_QspiFlashCommandFailure*/, "QSPI Flash Command Failure." },
    { 404 /*kStatus_QspiFlashUnknownProperty*/, "QSPI Flash Unknown Property." },
    { 405 /*kStatus_QspiNotConfigured*/, "QSPI Not Configured." },
    { 406 /*kStatus_QspiCommandNotSupported*/, "QSPI Command Not Supported." },
    { 407 /*kStatus_QspiCommandTimeout*/, "QSPI Command Timeout" },
    { 408 /*kStatus_QspiWriteFailure*/, "QSPI Write Failure." },

    /* OTFAD driver errors. */
    { 500 /*kStatus_OtfadSecurityViolation*/, "OTFAD Security Violation." },
    { 501 /*kStatus_OtfadLogicallyDisabled*/, "OTFAD Logically Disabled." },
    { 502 /*kStatus_OtfadInvalidKey*/, "OTFAD Invalid Key." },
    { 503 /*Kstatus_OtfadInvalidKeyBlob*/, "OTFAD Invalid KeyBlob." },

    /* Bootloader errors. */
    { kStatus_UnknownCommand, "kStatus_UnknownCommand" },
    { kStatus_SecurityViolation, "Command disallowed when security is enabled." },
    { kStatus_AbortDataPhase, "kStatus_AbortDataPhase" },
    { kStatus_Ping, "kStatus_Ping" },
    { kStatus_NoResponse, "No response packet from target device." },
    { kStatus_NoResponseExpected, "No response packet from target device was expected." },

    /* SB loader errors. */
    { kStatusRomLdrSectionOverrun, "kStatusRomLdrSectionOverrun" },
    { kStatusRomLdrSignature, "kStatusRomLdrSignature" },
    { kStatusRomLdrSectionLength, "kStatusRomLdrSectionLength" },
    { kStatusRomLdrUnencryptedOnly, "kStatusRomLdrUnencryptedOnly" },
    { kStatusRomLdrEOFReached, "kStatusRomLdrEOFReached" },
    { kStatusRomLdrChecksum, "kStatusRomLdrChecksum" },
    { kStatusRomLdrCrc32Error, "kStatusRomLdrCrc32Error" },
    { kStatusRomLdrUnknownCommand, "kStatusRomLdrUnknownCommand" },
    { kStatusRomLdrIdNotFound, "kStatusRomLdrIdNotFound" },
    { kStatusRomLdrDataUnderrun, "kStatusRomLdrDataUnderrun" },
    { kStatusRomLdrJumpReturned, "kStatusRomLdrJumpReturned" },
    { kStatusRomLdrCallFailed, "kStatusRomLdrCallFailed" },
    { kStatusRomLdrKeyNotFound, "kStatusRomLdrKeyNotFound" },
    { kStatusRomLdrSecureOnly, "kStatusRomLdrSecureOnly" },

    /* Memory interface errors. */
    { kStatusMemoryRangeInvalid, "kStatusMemoryRangeInvalid" },
    { kStatusMemoryReadFailed, "kStatusMemoryReadFailed" },
    { kStatusMemoryWriteFailed, "kStatusMemoryWriteFailed" },

    /* Property store errors. */
    { kStatus_UnknownProperty, "Unknown property." },
    { kStatus_ReadOnlyProperty, "Property is read-only." },
    { kStatus_InvalidPropertyValue, "Invalid property value." },

    /* Application crc check statuses. */
    { 10400, "kStatus_AppCrcCheckPassed" },
    { 10401, "kStatus_AppCrcCheckFailed" },
    { 10402, "kStatus_AppCrcCheckInactive" },
    { 10403, "kStatus_AppCrcCheckInvalid" },
    { 10404, "kStatus_AppCrcCheckOutOfRange" },

    /* Packetizer errors. */
    { kStatus_NoPingResponse, "No response received for ping command." },
    { kStatus_InvalidPacketType, "Invalid packet type." },
    { kStatus_InvalidCRC, "Invalid CRC value." },
    { kStatus_NoCommandResponse, "No response received for command." },

    /* Reliable Update statuses. */
    { 10600, "kStatus_ReliableUpdateSuccess" },
    { 10601, "kStatus_ReliableUpdateFail" },
    { 10602, "kStatus_ReliableUpdateImageInvalid" },
    { 10603, "kStatus_ReliableUpdateInactive" },

    /* Terminator */
    { kStatusMessageTableTerminatorValue, "" }
};
#endif

/***************************************************************************************************
    GLOBAL VARIABLE AND CONSTANTS DECLARATIONS
***************************************************************************************************/


/***************************************************************************************************
    GLOBAL FUNCTION PROTOTYPES
***************************************************************************************************/
extern void ISR_Scb_Isr_Vector_94_Cat2(void);
extern void gs_App_Repro_L2H_Set(void);
extern void gs_App_Repro_H2L_Set(void);



#endif
