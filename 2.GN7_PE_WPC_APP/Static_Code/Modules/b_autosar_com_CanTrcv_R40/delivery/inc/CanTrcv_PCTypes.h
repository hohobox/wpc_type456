/*******************************************************************************
 **  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
 **  Confidential Proprietary Information. Distribution Limited.               **
 **  Do Not Copy Without Prior Permission                                      **
 **                                                                            **
 **  SRC-MODULE: CanTrcv_PCTypes.h                                             **
 **                                                                            **
 **  TARGET    : General CAN Transceiver                                       **
 **                                                                            **
 **  PRODUCT   : AUTOSAR CAN Transceiver Driver Module                         **
 **                                                                            **
 **  PURPOSE   : Provision of Pre-compile time parameters                      **
 **                                                                            **
 **  PLATFORM DEPENDANT [yes/no]: yes                                          **
 **                                                                            **
 **  TO BE CHANGED BY USER [yes/no]: no                                        **
 **                                                                            **
 *******************************************************************************/

/*******************************************************************************
 **                      Revision History                                      **
 ********************************************************************************
 ** Revision  Date          By             Description                         **
 ********************************************************************************
 ** 2.10.1    19-Apr-2024   Kim Min Uk     #46132                              **
 ** 2.10.0    11-Nov-2023   Song Yu Bin    #42559                              **
 ** 2.9.5     18-Aug-2022   Hojin Seong    #37205                              **
 ** 2.9.3     18-May-2022   Minuk Kim      #35660, #34786                      **
 ** 2.9.2     17-Mar-2022   Jaeho Yamg     #34356                              **
 ** 2.9.1     30-Dec-2021   Lim Jong Sun   #33364                              **
 ** 2.8.0     08-Mar-2021   HieuTM8        #28372,                             **
 ** 2.7.0     10-Feb-2021   Lim Jong Sun   #22922                              **
 ** 2.6.2     20-Nov-2020   Lim Jong Sun   #26689                              ** 
 ** 2.6.1     06-Feb-2020   Lim Jong Sun   #20370                              **
 ** 2.6.0     25-Jun-2018   Lim Jong Sun   #12878                              **
 ** 2.5.6     11-Aug-2017   Lim Jong Sun   #9477                               **
 ** 2.5.5     17-Jul-2017   Lim Jong Sun   #9247                               **
 ** 2.5.4     13-Jul-2017   Lim Jong Sun   #9199                               **
 ** 2.5.2     27-Apr-2017   Lim Jong Sun   #8371, #8358                        **
 ** 2.5.0     27-Dec-2016   Lim Jong Sun   #6921                               **
 ** 2.4.1     11-Nov-2016   Lim Jong Sun   #6332, #6546                        **
 ** 2.4.0     21-Oct-2016   Lim Jong Sun   #6309                               **
 ** 2.3.2     01-Sep-2016   Lim Jong Sun   #5903                               **
 ** 2.3.1     09-Aug-2016   Lim Jong Sun   #4736, #4689, #5655                 **
 ** 2.3.0     15-May-2016   Lim Jong Sun   #4611, #4805, #5270, #5333          **
 ** 2.2.7     24-Feb-2015   Lim Jong Sun   #4252, #3781                        **
 ** 2.0.0     03-Sep-2014   Lim Jong Sun   #1318                               **
 ** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
 *******************************************************************************/

#ifndef CANTRCV_PCTYPES_H
#define CANTRCV_PCTYPES_H

/*******************************************************************************
 **                      Include Section                                      **
 *******************************************************************************/
#include "ComStack_Types.h"        /* ComStack Types header file*/
#include "Can_GeneralTypes.h"      /* Can General Types header file*/
#include "CanTrcv_Driver.h"     /* CAN Transceiver Driver  header file */
#include "Dio.h"                   /* DIO module header file */
#if (STD_ON == CANTRCV_SPI_SUPPORT)
#include "Spi.h"
#endif
#if (STD_OFF == CANTRCV_ARISUCAN_SUPPORT)
#include "CanTrcv_Ram.h"
#endif
/*******************************************************************************
 **                      Version Information                                  **
 *******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANTRCV_PCTYPES_AR_RELEASE_MAJOR_VERSION     4
#define CANTRCV_PCTYPES_AR_RELEASE_MINOR_VERSION     0
#define CANTRCV_PCTYPES_AR_RELEASE_REVISION_VERSION  3

/* File version information */
#define CANTRCV_PCTYPES_SW_MAJOR_VERSION  2
#define CANTRCV_PCTYPES_SW_MINOR_VERSION  10

/*******************************************************************************
 **                      MACRO Definitions                                    **
 *******************************************************************************/
/* Macros for numerical Values */
#define CANTRCV_ZERO                               ((uint8)0x00)
#define CANTRCV_ONE                                ((uint8)0x01)
#define CANTRCV_TWO                                ((uint8)0x02)
#define CANTRCV_THREE                              ((uint8)0x03)
#define CANTRCV_FOUR                               ((uint8)0x04)
#define CANTRCV_FIVE                               ((uint8)0x05)
#define CANTRCV_SIX                                ((uint8)0x06)
#define CANTRCV_TEN                                ((uint8)0x0A)
/* Instance ID */
#define CANTRCV_INSTANCE_ID                        ((uint8)0x00)
/* Macros for boolean Values */
#define CANTRCV_UNINITIALIZED                      ((boolean)0x00)
#define CANTRCV_INITIALIZED                        ((boolean)0x01)
#define CANTRCV_FALSE                              ((boolean)0x00)
#define CANTRCV_ERR                                ((boolean)0x01)
#define CANTRCV_N_ERR                              ((boolean)0x00)
#define CANTRCV_TRUE                               ((boolean)0x01)
#define CANTRCV_UNUSED                             ((uint8)0xFF)
#define CANTRCV_PNCHANNEL_UNUSED                   ((uint16)0xFFFF) /* This Channel does not support Partial Networking */
#define CANTRCV_CAN_DATARATE_INVALID               ((uint16)0xFFFF)

/* 0x01 Mode Control register */
#define TJA1145_SBC_MODE_REG_W                     ((uint16)0x0200)
#define TJA1145_SBC_MODE_REG_R                     ((uint16)0x0300)
#define TJA1145_SBC_MODE_NORMAL                    ((uint16)0x0007)
#define TJA1145_SBC_MODE_STANDBY                   ((uint16)0x0004)
#define TJA1145_SBC_MODE_SLEEP                     ((uint16)0x0001)

/* 0x03 Mode Control register */
#define TJA1145_MAIN_STS_REG_W                     ((uint16)0x0600)
#define TJA1145_MAIN_STS_REG_R                     ((uint16)0x0700)
#define TJA1145_MAIN_FSMS_REG_1_BIT                ((uint16)0x0080)
#define TJA1145_MAIN_OTWS_REG_1_BIT                ((uint16)0x0040)
#define TJA1145_MAIN_NMS_REG_1_BIT                 ((uint16)0x0020)
#define TJA1145_MAIN_STS_CHECK_ERR_BIT             ((uint16)0x00E0)

/* any change in the configuration registers will automatically clear the PNCOK
 bit and disable the selective wake-up function */
/* CFDC = 1 --> CAN-FD Passive feature on, disable CAN-FD WUF */
/* 0x20 CAN control register */
#define TJA1145_CAN_CONTROL_REG_W                  ((uint16)0x4000)
#define TJA1145_CAN_CONTROL_REG_R                  ((uint16)0x4100)
#define TJA1145_CAN_CONTROL_CFDC_1_BIT             ((uint16)0x0040)
#define TJA1145_CAN_CONTROL_PNCOK_1_BIT            ((uint16)0x0020)
#define TJA1145_CAN_CONTROL_CPNC_1_BIT             ((uint16)0x0010)
#define TJA1145_CAN_CONTROL_CMC_1_BIT              ((uint16)0x0001)
#define TJA1145_CAN_CONTROL_REG_R                  ((uint16)0x4100)

/* 0x22 Transceiver status register */
#define TJA1145_TRCV_STS_REG_R                     ((uint16)0x4500)
#define TJA1145_TRCV_STS_CPNERR_1_BITMAKS          ((uint16)0x0040)

/* 0x23 Transceiver event capture enable register */
#define TJA1145_TRCV_EVENT_ENABLE_REG_W            ((uint16)0x4600)
#define TJA1145_TRCV_EVENT_ENABLE_CWE_1_BIT        ((uint16)0x0001)

/* 0x27 ID Regsiters 0 */
#define TJA1145_ID_REGISTER0_REG_W                 ((uint16)0x4E00)

/* 0x28 ID Regsiters 1 */
#define TJA1145_ID_REGISTER1_REG_W                 ((uint16)0x5000)

/* 0x29 ID Regsiters 2 */
#define TJA1145_ID_REGISTER2_REG_W                 ((uint16)0x5200)

/* 0x2A ID Regsiters 3 */
#define TJA1145_ID_REGISTER3_REG_W                 ((uint16)0x5400)

/* Logic '1' bit osition to don't care */
/* 0x2B ID Mask 0*/
#define TJA1145_ID_MASK0_REG_W                     ((uint16)0x5600)

/* 0x2C ID Mask 1*/
#define TJA1145_ID_MASK1_REG_W                     ((uint16)0x5800)

/* 0x2D ID Mask 2*/
#define TJA1145_ID_MASK2_REG_W                     ((uint16)0x5A00)

/* 0x2E ID Mask 3*/
#define TJA1145_ID_MASK3_REG_W                     ((uint16)0x5C00)

/* CAN-FD frame foramt can never be a WUF, even when PNDM = 0 */
/* 0x2F Frame control register */
#define TJA1145_FRAME_CTRL_REG_W                   ((uint16)0x5E00)
#define TJA1145_FRAME_CTRL_IDE_0_BIT               ((uint16)0x0000)
#define TJA1145_FRAME_CTRL_IDE_1_BIT               ((uint16)0x0080)
#define TJA1145_FRAME_CTRL_PNDM_0_BIT              ((uint16)0x0000)
#define TJA1145_FRAME_CTRL_PNDM_1_BIT              ((uint16)0x0040)

/* 0x4C WAKE pin event capture enable register */
#define TJA1145_WAKE_EVENT_CTRL_REG_W              ((uint16)0x9800)
#define TJA1145_WAKE_PIN_WPR_ENABLE                ((uint16)0x0002)
#define TJA1145_WAKE_PIN_WPF_ENABLE                ((uint16)0x0001)

/* 0x60 System event status register */
#define TJA1145_GBL_EVENT_STS_REG_R                ((uint16)0xC100)
#define TJA1145_GBL_EVENT_STSE_BITMASK             ((uint16)0x0001)
#define TJA1145_GBL_EVENT_STSE_ALLBITMASK          ((uint16)0x0016)

/* 0x61 System event status register */
#define TJA1145_SYS_EVENT_STS_REG_W                ((uint16)0xC200)
#define TJA1145_SYS_EVENT_STS_PO_CLEAR_BIT         ((uint16)0x0010)
#define TJA1145_SYS_EVENT_STS_CLEAR_BIT            ((uint16)0x00FF)

/* 0x63 Transceiver event status register */
#define TJA1145_TRCV_EVENT_STS_REG_W               ((uint16)0xC600)
#define TJA1145_TRCV_EVENT_STS_CW_CLEAR_BIT        ((uint16)0x0001)
#define TJA1145_TRCV_EVENT_STS_CF_CLEAR_BIT        ((uint16)0x0002)
#define TJA1145_TRCV_EVENT_STS_PNFDE_CLEAR_BIT     ((uint16)0x0020)
#define TJA1145_TRCV_EVENT_STS_PNFDE_BIT_MASK      ((uint16)0x0020)
#define TJA1145_TRCV_EVENT_STS_REG_R               ((uint16)0xC700)
#define TJA1145_TRCV_EVENT_STS_CW_BITMAST          ((uint16)0x0001)

/* 0x64 WAKE pin event status register */
#define TJA1145_TRCV_WAKE_PIN_EVENT_STS_REG_W      ((uint16)0xC800)
#define TJA1145_TRCV_WAKE_PIN_WPR_CLEAR_BIT        ((uint16)0x0002)
#define TJA1145_TRCV_WAKE_PIN_WPF_CLEAR_BIT        ((uint16)0x0001)

/* Data mask registers(68h to 6Fh) */
/* 0x6F Data mask registers DM7*/
#define TJA1145_DATA_MASK_DM7_REG_W                ((uint16)0xDE00)
#define TJA1145_DATA_MASK_DM6_REG_W                ((uint16)0xDC00)
#define TJA1145_DATA_MASK_DM5_REG_W                ((uint16)0xDA00)
#define TJA1145_DATA_MASK_DM4_REG_W                ((uint16)0xD800)
#define TJA1145_DATA_MASK_DM3_REG_W                ((uint16)0xD600)
#define TJA1145_DATA_MASK_DM2_REG_W                ((uint16)0xD400)
#define TJA1145_DATA_MASK_DM1_REG_W                ((uint16)0xD200)
#define TJA1145_DATA_MASK_DM0_REG_W                ((uint16)0xD000)

/* TJA1145 PARTIAL NETWROKING */
/* 0x73 Start-up control register */
#define TJA1145_STARTUP_CTRL_REG_W                 ((uint16)0xE600)
#define TJA1145_STARTUP_CTRL_RLC_10_BIT            ((uint16)0x0020)
#define TJA1145_STARTUP_CTRL_V2SUC_VEXTSUC_1_BIT   ((uint16)0x0008)

/* 0x74 SBC configuration control register */
#define TJA1145_SBC_CFG_CTRL_REG_W                 ((uint16)0xE800)
#define TJA1145_SBC_CFG_CTRL_V1RTSUC_1_BIT         ((uint16)0x0010)
#define TJA1145_SBC_CFG_CTRL_FNMC_0_SDMC_1_BIT     ((uint16)0x0004)

/* 0x75 MTPNV CRC control register */
#define TJA1145_MTPNV_CRC_CTRL_REG_W               ((uint16)0xEA00)
#define TJA1145_MTPNV_CRC_BIT                      ((uint16)0x009A)

/*0x10 Mode Control Register*/
#define TCAN1145_MODE_CNTRL_REG_W                  ((uint16)0x2100)
#define TCAN1145_MODE_CNTRL_REG_R                  ((uint16)0x2000)
#define TCAN1145_MODE_CNTRL_SW_EN_1_BIT            ((uint16)0x0080)
#define TCAN1145_MODE_CNTRL_SW_EN_CLEAR_BIT        ((uint16)0x007F)
#define TCAN1145_MODE_CNTRL_DTO_DIS_1_BIT          ((uint16)0x0040)
#define TCAN1145_MODE_CNTRL_FD_EN_REG_1_BIT        ((uint16)0x0020)
#define TCAN1145_MODE_CNTRL_RSVD_R                 ((uint16)0x0018)
#define TCAN1145_MODE_CNTRL_NORMAL                 ((uint16)0x0007)
#define TCAN1145_MODE_CNTRL_STANDBY                ((uint16)0x0004)
#define TCAN1145_MODE_CNTRL_SLEEP                  ((uint16)0x0001)
#define TCAN1145_MODE_CNTRL_BITMASKS               ((uint16)0x00F8)
#define TCAN1145_REG_BITMASKS                      ((uint16)0x00FF)

/* 0x11 Wake Pin configuration */ 
#define TCAN1145_WAKE_PIN_CONFIG_REG_W             ((uint16)0x2300)
#define TCAN1145_WAKE_PIN_CONFIG_REG_R             ((uint16)0x2200)
#define TCAN1145_WAKE_PIN_CONFIG_RE_CLEAR_BIT      ((uint16)0x0010)
#define TCAN1145_WAKE_PIN_CONFIG_FE_CLEAR_BIT      ((uint16)0x0020)
#define TCAN1145_WAKE_PIN_CONFIG_CLEAR_BIT         ((uint16)0x00CF)

/* 0x19 Device Reset */
#define TCNA1145_DEVICE_SF_RST_ENABLE              ((uint16)0x0002)
#define TCNA1145_DEVICE_HD_RST_ENABLE              ((uint16)0x0001)

/* 0x1C Sleep Wake error timer disable */
#define TCAN1145_SWE_DIS_REG_W                     ((uint16)0x3900)
#define TCAN1145_SWE_DIS_CANSLNT_DISABLE           ((uint16)0x0004)

/* 0x30 ID Regsiters 0 */
#define TCAN1145_ID_REG1_REG_W                     ((uint16)0x6100)


/* 0x31 ID Regsiters 1 */
#define TCAN1145_ID_REG2_REG_W                     ((uint16)0x6300)


/* 0x32 ID Regsiters 2 */
#define TCAN1145_ID_REG3_REG_W                     ((uint16)0x6500)
#define TCAN1145_ID_REG3_REG_R                     ((uint16)0x6400)
#define TCAN1145_ID_REG3_IDE_0_BIT                 ((uint16)0x00DF)
#define TCAN1145_ID_REG3_IDE_1_BIT                 ((uint16)0x0020)
#define TCAN1145_ID_REG3_REG_BITMASK               ((uint16)0x00E0)
#define TCAN1145_ID_REG3_REG_EX_ID_BITMASK         ((uint16)0x003F)

/* 0x33 ID Regsiters 3 */
#define TCAN1145_ID_REG4_REG_W                     ((uint16)0x6700)
#define TCAN1145_ID_REG4_REG_R                     ((uint16)0x6600)
#define TCAN1145_ID_REG4_REG_BITMASK               ((uint16)0x0003)

/* 0x34 ID Mask 0*/
#define TCAN1145_ID_MASK1_REG_W                    ((uint16)0x6900)
#define TCAN1145_ID_MASK1_REG_R                    ((uint16)0x6800)
#define TCAN1145_ID_MASK1_REG_BITMASK              ((uint16)0x00FC)

/* 0x35 ID Mask 1*/
#define TCAN1145_ID_MASK2_REG_W                    ((uint16)0x6B00)


/* 0x36 ID Mask 2*/
#define TCAN1145_ID_MASK3_REG_W                    ((uint16)0x6D00)


/* 0x37 ID Mask 3*/
#define TCAN1145_ID_MASK4_REG_W                    ((uint16)0x6F00)


/* 0x38 ID Make,DLC,Data mask En */
#define TCAN1145_ID_MASK_DLC_REG_W                 ((uint16)0x7100)
#define TCAN1145_ID_MASK_DLC_REG_R                 ((uint16)0x7000)
#define TCAN1145_ID_MASK_DLC_MASK_ENABLE           ((uint16)0x0001)
#define TCAN1145_ID_MASK_DLC_MASK_DISABLE          ((uint16)0x00FE)
#define TCAN1145_ID_MASK_DLC_BITMASK               ((uint16)0x001F)

/* 0x39 ID Make,DLC,Data mask En */
#define TCAN1145_DATA_y_REG_W                      ((uint16)0x7300)

/* 0x44 CAN and CAN FD DR and behavior */
#define TCAN1145_CONFIG1_REG_W                     ((uint16)0x8900)
#define TCAN1145_CONFIG1_REG_R                     ((uint16)0x8800)
#define TCAN1145_CONFIG1_SW_FD_PASSIVE             ((uint16)0x0080)
#define TCAN1145_CONFIG1_CAN_DR_BITMASK            ((uint16)0x008F)
#define TCAN1145_CONFIG1_CAN_DR_50_BIT             ((uint16)0x0000)
#define TCAN1145_CONFIG1_CAN_DR_100_BIT            ((uint16)0x0010)
#define TCAN1145_CONFIG1_CAN_DR_125_BIT            ((uint16)0x0020)
#define TCAN1145_CONFIG1_CAN_DR_250_BIT            ((uint16)0x0030)
#define TCAN1145_CONFIG1_CAN_DR_500_BIT            ((uint16)0x0050)
#define TCAN1145_CONFIG1_CAN_DR_1000_BIT           ((uint16)0x0070)
#define TCAN1145_CONFIG1_FD_DR_BITMASK             ((uint16)0x00F3)
#define TCAN1145_CONFIG1_FD_DR_4X_BIT              ((uint16)0x0004)

/* 0x44 Check Can baudrate*/
#define TCAN1145_CAN_DATARATE_50                   ((uint16)50)
#define TCAN1145_CAN_DATARATE_100                  ((uint16)100)
#define TCAN1145_CAN_DATARATE_125                  ((uint16)125)
#define TCAN1145_CAN_DATARATE_250                  ((uint16)250)
#define TCAN1145_CAN_DATARATE_1000                 ((uint16)1000)

/* 0x46 Frame Counter thershold */
#define TCAN1145_CONFIG3_REG_W                     ((uint16)0x8D00)


/* 0x47 Mode Configuration */
#define TCAN1145_CONFIG4_REG_W                     ((uint16)0x8F00)
#define TCAN1145_CONFIG4_REG_R                     ((uint16)0x8E00)
#define TCAN1145_CONFIG4_SWCFG_REG_BIT             ((uint16)0x0080)


/* 0x51 selective wakeup interrupt*/
#define TCAN1145_INT_1_REG_W                       ((uint16)0xA300)
#define TCAN1145_INT_1_REG_R                       ((uint16)0xA200)
#define TCAN1145_INT_1_CANINT_CLEAR_BIT            ((uint16)0x0040) 
#define TCAN1145_INT_1_CANINT_REG                  ((uint16)0x0040)
#define TCAN1145_INT_1_LWU_REG                     ((uint16)0x0020)
#define TCAN1145_INT_1_WKERR_REG                   ((uint16)0x0010)
#define TCAN1145_INT_1_CLEAR_FRAME_OVF_BIT         ((uint16)0x0008) 
#define TCAN1145_INT_1_CLEAR_FLAG_BITMASK          ((uint16)0x0078) 
#define TCAN1145_INT_1_CANSLNT_REG                 ((uint16)0x0004)


/* 0x52 selective wakeup interrupt*/
#define TCAN1145_INT_2_REG_W                       ((uint16)0xA500)
#define TCAN1145_INT_2_REG_R                       ((uint16)0xA400)
#define TCAN1145_INT_2_PWRON_BIT                   ((uint16)0x0040) 
#define TCAN1145_INT_2_SMS_REG_CLEAR_BIT           ((uint16)0x0080) 
#define TCAN1145_INT_2_UVSUP_BIT                   ((uint16)0x0010)
#define TCAN1145_INT_2_UVIO_BIT                    ((uint16)0x0008)
#define TCAN1145_INT_2_UVCC_BIT                    ((uint16)0x0004)
#define TCAN1145_INT_2_BITMASKS                    ((uint16)0x00FF)
  
/* 0x53 selective wakeup interrupt*/
#define TCAN1145_INT_3_REG_W                       ((uint16)0xA700)
#define TCAN1145_INT_3_REG_R                       ((uint16)0xA600)
#define TCAN1145_INT_3_SPIERR_BIT                  ((uint16)0x0080)
#define TCAN1145_INT_3_SWERR_BIT                   ((uint16)0x0040)


#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
/* ARISUCAN SBC SPI REGISTER */
#define ARISUCAN_M_S_CTRL_REG_W                    ((uint16)0x0081)
#define ARISUCAN_M_S_CTRL_REG_R                    ((uint16)0x0001)
#define ARISUCAN_HW_CTRL_0_REG_W                   ((uint16)0x0082)
#define ARISUCAN_HW_CTRL_0_REG_R                   ((uint16)0x0002)
#define ARISUCAN_WD_CTRL_REG_W                     ((uint16)0x0083)
#define ARISUCAN_WD_CTRL_REG_R                     ((uint16)0x0003)
#define ARISUCAN_BUS_CTRL_0_REG_W                  ((uint16)0x0084)
#define ARISUCAN_BUS_CTRL_0_REG_R                  ((uint16)0x0004)
#define ARISUCAN_WK_CTRL_0_REG_W                   ((uint16)0x0086)
#define ARISUCAN_WK_CTRL_0_REG_R                   ((uint16)0x0006)
#define ARISUCAN_WK_CTRL_1_REG_W                   ((uint16)0x0087)
#define ARISUCAN_WK_CTRL_1_REG_R                   ((uint16)0x0007)
#define ARISUCAN_WK_PUPD_CTRL_REG_W                ((uint16)0x0088)
#define ARISUCAN_WK_PUPD_CTRL_REG_R                ((uint16)0x0008)
#define ARISUCAN_BUS_CTRL_2_REG_W                  ((uint16)0x008A)
#define ARISUCAN_BUS_CTRL_2_REG_R                  ((uint16)0x000A)
#define ARISUCAN_BUS_CTRL_3_REG_W                  ((uint16)0x008B)
#define ARISUCAN_BUS_CTRL_3_REG_R                  ((uint16)0x000B)
#define ARISUCAN_TIMER_CTRL_0_REG_W                ((uint16)0x008C)
#define ARISUCAN_TIMER_CTRL_0_REG_R                ((uint16)0x000C)
#define ARISUCAN_SYS_STATUS_CTRL_REG_W             ((uint16)0x008D)
#define ARISUCAN_SYS_STATUS_CTRL_REG_R             ((uint16)0x000D)
#define ARISUCAN_SUP_STAT_1_REG_W                  ((uint16)0x00C0)
#define ARISUCAN_SUP_STAT_1_REG_R                  ((uint16)0x0040)
#define ARISUCAN_SUP_STAT_0_REG_W                  ((uint16)0x00C1)
#define ARISUCAN_SUP_STAT_0_REG_R                  ((uint16)0x0041)
#define ARISUCAN_THERM_STAT_REG_W                  ((uint16)0x00C2)
#define ARISUCAN_THERM_STAT_REG_R                  ((uint16)0x0042)
#define ARISUCAN_DEV_STAT_REG_W                    ((uint16)0x00C3)
#define ARISUCAN_DEV_STAT_REG_R                    ((uint16)0x0043)
#define ARISUCAN_BUS_STAT_0_REG_W                  ((uint16)0x00C4)
#define ARISUCAN_BUS_STAT_0_REG_R                  ((uint16)0x0044)
#define ARISUCAN_WK_STAT_0_REG_W                   ((uint16)0x00C6)
#define ARISUCAN_WK_STAT_0_REG_R                   ((uint16)0x0046)
#define ARISUCAN_WK_LVL_STAT_REG_W                 ((uint16)0x00C8)
#define ARISUCAN_WK_LVL_STAT_REG_R                 ((uint16)0x0048)
#define ARISUCAN_WK_STAT_2_REG_W                   ((uint16)0x00C9)
#define ARISUCAN_WK_STAT_2_REG_R                   ((uint16)0x0049)
#define ARISUCAN_BUS_STAT_2_REG_W                  ((uint16)0x00CA)
#define ARISUCAN_BUS_STAT_2_REG_R                  ((uint16)0x004A)
#define ARISUCAN_BUS_STAT_3_REG_W                  ((uint16)0x00CB)
#define ARISUCAN_BUS_STAT_3_REG_R                  ((uint16)0x004B)
#define ARISUCAN_SMPS_STAT_REG_W                   ((uint16)0x00CC)
#define ARISUCAN_SMPS_STAT_REG_R                   ((uint16)0x004C)
#define ARISUCAN_FAM_PROD_STAT_R                   ((uint16)0x007E)

#define ARISUCAN_Read_Reg_Filter                   ((uint8)0xFE)
#define ARISUCAN_DATAMASK                          ((uint16)0xFF00)
#define ARISUCAN_CAN_0_1_3_MASK                    ((uint16)0x7)
#define ARISUCAN_CAN_2_MASK                        ((uint16)0x38)

/* M_S_CTRL */
/* Registor bit
 NIDE_1      :7 - SBC Mode Control
 MODE_0      :6 - SBC Mode Control
 VEXT_ON     :5 - If PCFG is left open, VEXT Mode Control
 VIO_OV_RST  :2 - VIO Over Voltage Reset / Fail-Safe enable
 VIO_RT_1    :1 - Limit number of resets due to a Watchdog failure
 VIO_RT_0    :0 - VIO Reset Threshold Control
 */
#define ARISUCAN_M_S_CTRL_MODE_1_BIT               ((uint16)0x0001 << 15)
#define ARISUCAN_M_S_CTRL_MODE_0_BIT               ((uint16)0x0001 << 14)
#define ARISUCAN_M_S_CTRL_VEXT_ON_BIT              ((uint16)0x0001 << 13)
#define ARISUCAN_M_S_CTRL_VIO_OV_RST_BIT           ((uint16)0x0001 << 10)
#define ARISUCAN_M_S_CTRL_VIO_RT_1_BIT             ((uint16)0x0001 << 9)
#define ARISUCAN_M_S_CTRL_VIO_RT_0_BIT             ((uint16)0x0001 << 8)
#define ARISUCAN_SUP_STAT_1_VS_UV_NOT_OK_BIT       ((uint16)0x0001 << 6)
#define ARISUCAN_W_K_LVL_STAT_UV_STATE_NOT_OK_BIT  ((uint16)0x0001 << 3)
#define ARISUCAN_W_K_STAT_2_UV_LATCH_NOT_OK_BIT    ((uint16)0x0001 << 7)

/* #6309 */
#define ARISUCAN_H_W_CTRL_0_PWM_AUTO_1_BIT         ((uint16)0x0001 << 3)
#define ARISUCAN_H_W_CTRL_0_PWM_AUTO_0_BIT         ((uint16)0x00F7)
#define ARISUCAN_W_K_CTRL_0_VBSENSE01_CFG_BIT      ((uint16)0x0001 << 4)
#define ARISUCAN_W_K_CTRL_0_VBSENSE01_CFG_CHECK_BIT ((uint16)0x0003 << 4)
#define ARISUCAN_W_K_CTRL_0_VBSENSE_EN_BIT         ((uint16)0x0001)
#define ARISUCAN_W_K_CTRL_0_VBSENSE_DISABLE_BIT    ((uint16)0xFFFE)

#define ARISUCAN_M_S_CTRL_MODE_POS                 ((uint8)14)
#define ARISUCAN_BUS_CTRL_MODE_POS                 ((uint8)8)
#define ARISUCAN_BUS_CTRL_CANTRCV_3_MODE_POS       ((uint8)3)
#define ARISUCAN_M_S_CTRL_MODE_MASK                ((uint16)0x00C0)
#define ARISUCAN_VBSENSE_CFG_MASK                  ((uint8)4)
#define ARISUCAN_VBAT_UV_STATE_MASK                ((uint8)3)
#define ARISUCAN_VS_UV_MASK                        ((uint8)6)
#define ARISUCAN_WK_STAT_MASK                      ((uint8)7)
#define ARISUCAN_M_S_CTRL_MASK                     ((uint8)6)

/* ARISU_CAN_DEFINE */
#define ARISUCAN_OK                            ((uint8) 0x00)
#define ARISUCAN_BUSY                          ((uint8) 0x01)
#define ARISUCAN_FIVE                          ((uint8) 0x05)
#define ARISUCAN_EIGHT                         ((uint8) 0x08)
#define ARISUCAN_CONFIGURE                     ((uint8) 0x01)
#define ARISUCAN_UNCONFIGURE                   ((uint8) 0x00)
#define ARISU_SPI_MAX_COUNT                     ((uint8) 5)

#define ARISUCAN_E_NOT_OK_SBCSTOP                        ((uint8) 0x02)
#define ARISUCAN_E_NOT_OK_CANMODE                        ((uint8) 0x03)

#endif

/* polyspace-begin MISRA-C3:D4.9 [Not a defect:Justified] "Use function like-macro for removing unused argument compiler warning" */
#define CANTRCV_UNUSED_PTR(x)                  do { \
                                                    if((x) != NULL_PTR) {} \
                                                  } while(0)


#define CANTRCV_UNUSED_VAL(x)                 do { \
                                                    if((uint32)(x) != \
                                                    (uint32)CANTRCV_ZERO) {} \
                                                  } while(0)


/* polyspace-end MISRA-C3:D4.9 [Not a defect:Justified] "Use function like-macro for removing unused argument compiler warning" */																										

/*******************************************************************************
 **                      Global Data                                          **
 *******************************************************************************/
/* Transceiver Devices that are used for the implementation */
typedef enum {
  CANTRCV_TJA1050 = 0,
  CANTRCV_TJA1051,
  CANTRCV_TJA1041A,
  CANTRCV_TJA1042,
  CANTRCV_TJA1043,
  CANTRCV_TJA1054,
  CANTRCV_TJA1055,
  CANTRCV_TLE6251DS,
  CANTRCV_TLE6251G,
  CANTRCV_TLE6254G,
  CANTRCV_TLE6250G,
  CANTRCV_TLE7250G,
  CANTRCV_TJA1044,
  CANTRCV_NCV7342,
  CANTRCV_TJA1145,
  CANTRCV_TJA1059,
  CANTRCV_TCAN1043A,
  CANTRCV_TCAN1044,
  CANTRCV_TCAN1057,
  CANTRCV_ARISU_CAN0,
  CANTRCV_ARISU_CAN1,
  CANTRCV_ARISU_CAN2,
  CANTRCV_ARISU_CAN3,
  CANTRCV_TJA1463,
  CANTRCV_TCAN1145
} CanTrcv_HwType;

typedef enum {
  CANTRCV_SLEEPMODE_UNUSED = 0, 
	CANTRCV_SLEEPMODE_USED
} CanTrcv_SleepModeType;

#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
typedef enum 
{
  ARISU_CANTRCV_OFF = 0,
  ARISU_CANTRCV_WAKECAPABLE,
  ARISU_CANTRCV_RECEIVEONLY,
  ARISU_CANTRCV_NORMAL
}ArisuCan_CANModeType;

#define ARISUCAN_START_OFFSET (CANTRCV_ARISU_CAN0)
#define ARISUCAN_END_OFFSET   (CANTRCV_ARISU_CAN3)
#endif
/*******************************************************************************
 **                      Global Type Definitions                              **
 *******************************************************************************/
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
typedef uint16 ArisuCan_DataType;
#endif

typedef struct  {
  /* Init State */
  CanTrcv_TrcvModeType ddInitState;
  /* Cantrcv Hardware */
  CanTrcv_HwType ddCanTrcvHwDev;
  /* Input Pin */
  Dio_ChannelType ddSelectPin1;
  /* Input Pin */
  Dio_ChannelType ddSelectPin2;
  /* Input Pin */
  Dio_ChannelType ddSelectPin3;
  /* Channel Used*/
  boolean blChannelUsed;
  /* Channel Used*/
  CanTrcv_SleepModeType ddSleepModeUsed;
  /* blCanTrcvHwPnSupport */
  boolean blCanTrcvHwPnSupport;
  /* usCanTrcvPnChannel */
  uint16 usCanTrcvPnChannel;
  /* usCanTrcvCanBaudRate */
  uint16 usCanTrcvCanBaudRate;
  /* usCanTrcvCanFdBaudRate */
  uint16 usCanTrcvCanFdBaudRate;
} CanTrcv_Network;

#if (STD_ON == CANTRCV_PN_SUPPORTED)
typedef struct  {
  /* blBusErrFlag */
  boolean blBusErrFlag;
  /* blPnCanIdExtended */
  boolean blPnCanIdExtended;
  /* blPnEnabled */
  boolean blPnEnabled;
  /* blPowerOnFlag */
  boolean blPowerOnFlag;
  /* ddPnFrameCanId Pin */
  Can_IdType ddPnFrameCanId;
  /* ddPnFrameCanIdMask Used*/
  Can_IdType ddPnFrameCanIdMask;
  /* ucPnFrameDlc Length*/
  uint8 ucPnFrameDlc;
  /* ucPnFrameDlc Check */
  boolean blPnDlcMatchingCondition;
  /* ucCanTrcvPnFrameDataMask */
  uint8 ucCanTrcvPnFrameDataMaskIndex;
  /* ucCanTrcvPnFrameDataMask */
  uint8 ucCanTrcvPnFrameDataMaskNm;
} CanTrcv_PnNetwork;

typedef struct  {
  /* ddPnFrameCanId Pin */
  uint8 ucCanTrcvPnFrameDataMaskInd;
  /* ddPnFrameCanIdMask Used*/
  uint8 ucCanTrcvPnFrmaeDataMask;
} CanTrcv_PnDataMask;
#endif

#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
typedef struct 
{
  uint8 ddArisu_Can0_mode;

  uint8 ddArisu_Can1_mode;

  uint8 ddArisu_Can2_mode;

  uint8 ddArisu_Can3_mode;
}ArisuCan_CanConfigType;
#endif

#define CANTRCV_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation(Array size will fixed in linking time) */
extern CONST(CanTrcv_Network, CANTRCV_CONST) CanTrcv_GaaCanTrcvNetwork[];
#define CANTRCV_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"   

#if (STD_ON == CANTRCV_PN_SUPPORTED)
#define CANTRCV_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation(Array size will fixed in linking time) */
extern CONST(CanTrcv_PnNetwork, CANTRCV_CONST) CanTrcv_GaaCanTrcvPnNetwork[];
#define CANTRCV_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  

#define CANTRCV_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation(Array size will fixed in linking time) */
extern CONST(CanTrcv_PnDataMask, CANTRCV_CONST) CanTrcv_GaaCanTrcvPnFrameDataMask[];
#define CANTRCV_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation(Array size will fixed in linking time) */
extern CONST(ArisuCan_CanConfigType, CANTRCV_CONST) CanTrcv_GaaArisuCan[];
#define CANTRCV_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" 
#endif

#endif /* CANTRCV_PCTYPES_H */
/*******************************************************************************
 **                      End of File                                          **
 *******************************************************************************/
