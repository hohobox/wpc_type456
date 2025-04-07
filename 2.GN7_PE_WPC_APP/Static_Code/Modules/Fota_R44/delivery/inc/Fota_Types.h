/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Fota_Types.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   : Provides all of the user type define                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                        Description              **
********************************************************************************
** 1.1.1.0   19-Jul-2024   KhanhHC                   #CP44-8128, #CP44-9351   **
** 1.0.0.0   28-Dec-2022   VuPH6                     Initial version          **
*******************************************************************************/
#ifndef FOTA_TYPES_H
#define FOTA_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Error Id for valid check argument of function */
#define FOTA_E_NULL_POINTER                                          ((uint8) 0)
#define FOTA_E_BLOCKID_INVALID                                       ((uint8) 1)
#define FOTA_E_ADDRESS_LENGTH_INVALID                                ((uint8) 2)

/* Error Id for memory function */
#define FOTA_E_ERASE_REQUEST_FAILED                                  ((uint8) 3)
#define FOTA_E_ERASE_JOB_FAILED                                      ((uint8) 4)
#define FOTA_E_WRITE_REQUEST_FAILED                                  ((uint8) 5)
#define FOTA_E_WRITE_JOB_FAILED                                      ((uint8) 6)
#define FOTA_E_WRITE_METADATA_REQUEST_FAILED                        ((uint8) 33)

/* Error Id for verification process */
#define FOTA_E_VERIFY_JOB_FAILED                                     ((uint8) 7)
#define FOTA_E_VERIFY_CSM_START_FAILED                               ((uint8) 8)
#define FOTA_E_VERIFY_CSM_UPDATE_FAILED                              ((uint8) 9)
#define FOTA_E_VERIFY_CSM_FINIISH_FAILED                            ((uint8) 10)
#define FOTA_E_VERIFY_CRC_FAILED                                    ((uint8) 11)

/* Error Id for software version check from Fota.c */
#define FOTA_E_SVC_ERASE_CHECK_FAILED                               ((uint8) 12)
#define FOTA_E_SVC_UPDATE_HEADER_FAILED                             ((uint8) 13)
#define FOTA_E_SVC_UPDATE_TRAILER_FAILED                            ((uint8) 14)
#define FOTA_E_SVC_RECOVERY_TRAILER_FAILED                          ((uint8) 15)
#define FOTA_E_SVC_ERASE_LENGTH_INVALID                             ((uint8) 16)

#define FOTA_E_PFLS_SWAP_BANK_FAILED                                ((uint8) 36)
#define FOTA_E_PFLS_ERASE_REQUEST_FAILED                            ((uint8) 37)
#define FOTA_E_PFLS_GET_ACTIVE_BANK_FAILED                          ((uint8) 38)
#define FOTA_E_PFLS_GET_SECTOR_SIZE_FAILED                          ((uint8) 39)
#define FOTA_E_STD_ALT_PFLS_COMPARE_FAILED                          ((uint8) 40)
#define FOTA_E_MAC_UPDATE_REQUEST_FAILED                            ((uint8) 41)
#define FOTA_E_MAC_UPDATE_RESULT_FAILED                             ((uint8) 42)

#define FOTA_E_SVC_INIT_FAILED                                      ((uint8) 43)
#define FOTA_E_SVC_SW_UNIT_FAILED                                   ((uint8) 44)
#define FOTA_E_PROGRAMING_SW_UNIT_ID_FAILED                         ((uint8) 45)
#define FOTA_E_GET_SW_UNIT_ID_FAILED                                ((uint8) 46)
#define FOTA_E_GET_SW_MODULE_FAILED                                 ((uint8) 47)
#define FOTA_E_MEMORY_ACCESS_TYPE_IMPLEMENTATION_RULE_INVALID       ((uint8) 48)

#define FOTA_E_VERIFY_KEY_SW_UNIT_ID_FAILED                         ((uint8) 49)
#define FOTA_E_SET_ACT_KEY_FAILED                                   ((uint8) 50)
#define FOTA_E_STORAGE_FAILED                                       ((uint8) 51)

#define FOTA_E_VALIDATE_META_FAILED                                 ((uint8) 52)
#define FOTA_E_VALIDATE_MEMORY_EREA_FAILED                          ((uint8) 53)
#define FOTA_E_MEMORY_INSTANCE_FAILED                               ((uint8) 54)
#define FOTA_E_PROCESS_META_FAILED                                  ((uint8) 55)
#define FOTA_E_USER_CALL_OUT_FAILED                                 ((uint8) 56)
#define FOTA_E_TARGET_PARTITION_FAILED                              ((uint8) 57)
#define FOTA_E_SYNC_WAIT_CNT_FAILED                                 ((uint8) 58)
#define FOTA_E_DIAG_CMD_SEQ_FAILED                                  ((uint8) 59)
#define FOTA_E_TRANSFER_DATA_AFTER_REQUEST_OFF                      ((uint8) 60)
#define FOTA_E_CHECK_JOB_FAIL                                       ((uint8) 61)
#define FOTA_E_DOWNLOAD_STATE_INVALID                               ((uint8) 62)
#define FOTA_E_OPSTATUS_INVALID                                     ((uint8) 63)

/* Error Id for software version check from Fota_SoftwareVersionCheck.c */
#define FOTA_E_SVC_ERASE_REQUEST_FAILED                             ((uint8) 17)
#define FOTA_E_SVC_WRITE_REQUEST_FAILED                             ((uint8) 18)
#define FOTA_E_SVC_CRC_CHECK_FAILED                                 ((uint8) 19)
#define FOTA_E_SVC_HEADER_TRAILER_ADDRESS_INVALID                   ((uint8) 20)
#define FOTA_E_SVC_MEM_JOB_FAILED                                   ((uint8) 21)
#define FOTA_E_SVC_DOWNGRADE_DETECT                                 ((uint8) 34)
#define FOTA_E_BLK_UPDATE_FAIL                                      ((uint8) 35)

/* Error Id for secure flash 2.0 */
#define FOTA_E_DECRYPT_START_FAILED                                 ((uint8) 22)
#define FOTA_E_DECRYPT_UPDATE_FAILED                                ((uint8) 23)
#define FOTA_E_DECRYPT_FINISH_FAILED                                ((uint8) 24)
#define FOTA_E_DERIVE_KEY_FAILED                                    ((uint8) 25)

/*Error Id for downgrade check from Fota.c*/
#define FOTA_E_DUALMEM_DOWNGRADE_DETECT                             ((uint8) 64)
#define FOTA_E_SW_UNIT_DEPENDENCY_FAILED                            ((uint8) 65)

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* FOTA_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
