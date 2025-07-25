/** \brief AUTOSAR SPI Driver
 **
 ** This file declares the architecture functions.
 **
 ** Do not edit this file manually.
 ** Any change might compromise the safety integrity level of
 ** the software partition it is contained in.
 **
 ** Product: SW-MCAL42-DRV
 **
 ** (c) 2017-2022, Cypress Semiconductor Corporation (an Infineon company) or
 ** an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 ** This software, including source code, documentation and related materials
 ** ("Software") is owned by Cypress Semiconductor Corporation or one of
 ** its affiliates ("Cypress") and is protected by and subject to worldwide
 ** patent protection (United States and foreign), United States copyright laws
 ** and international treaty provisions.  Therefore, you may use this Software
 ** only as provided in the license agreement accompanying the software package
 ** from which you obtained this Software ("EULA").
 ** If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 ** non-transferable license to copy, modify,
 ** and compile the Software source code solely for use in connection
 ** with Cypress's integrated circuit products.
 ** Any reproduction, modification, translation, compilation,
 ** or representation of this Software except as specified above is prohibited
 ** without the express written permission of Cypress.
 ** Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 ** EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
 ** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 ** Cypress reserves the right to make changes to the Software without notice.
 ** Cypress does not assume any liability arising out of the application or
 ** use of the Software or any product or circuit described in the Software.
 ** Cypress does not authorize its products for use in any products
 ** where a malfunction or failure of the Cypress product may reasonably be
 ** expected to result in significant property damage,
 ** injury or death ("High Risk Product"). By including Cypress's product
 ** in a High Risk Product, the manufacturer of such system or application
 ** assumes all risk of such use and in doing so agrees to indemnify Cypress
 ** against all liability.
 */

#ifndef SPI_INTERNAL_H_INCLUDED
#define SPI_INTERNAL_H_INCLUDED

/*==================[inclusions]============================================*/
#include <Std_Types.h>
#include <Spi_Internal_Types.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

#define SPI_START_SEC_CODE_ASIL_B
#include <Spi_MemMap.h>

/** \brief Spi_Internal_Cancel
 **
 ** Cancels the specified ongoing sequence transmission.
 **
 ** \return None.
 ** \param [in] Sequence   Id of Sequence.
 **
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_Cancel
(
  VAR( Spi_SequenceType, AUTOMATIC ) Sequence
);

/** \brief Spi_Internal_GetAsyncMode
 **
 ** Gets the asynchronous mode (Polling or Interrupt).
 **
 ** \return Asynchronous mode (Polling or Interrupt).
 **
 */
extern FUNC( Spi_AsyncModeType, SPI_CODE ) Spi_Internal_GetAsyncMode(void);

/** \brief Spi_Internal_SetAsyncMode
 **
 ** Sets the asynchronous mode (Polling or Interrupt).
 **
 ** \return SPI_OK: Setting command has been done.
 **         SPI_NOT_OK: Setting command has not been accepted.
 ** \param [in] Status   Asynchronous mode (Polling or Interrupt).
 **
 */
extern FUNC( Spi_ReturnType, SPI_CODE ) Spi_Internal_SetAsyncMode
(
  VAR( Spi_AsyncModeType, AUTOMATIC ) Status
);

/** \brief Spi_Internal_GetStatus
 **
 ** Returns the driver status.
 **
 ** \return Driver status.
 **
 */
extern FUNC( Spi_StatusType, SPI_CODE ) Spi_Internal_GetStatus(void);

/** \brief Spi_Internal_SetStatus
 **
 ** Sets the driver status.
 **
 ** \return None.
 ** \param [in] Status   Driver status.
 **
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_SetStatus
(
  VAR( Spi_StatusType, AUTOMATIC ) Status
);

/** \brief Spi_Internal_GetJobResult
 **
 ** Returns the last transmission result of the specified Job.
 **
 ** \return Transmission result of Job.
 ** \param [in] Job   Id of Job.
 **
 */
extern FUNC( Spi_JobResultType, SPI_CODE ) Spi_Internal_GetJobResult
(
  VAR( Spi_JobType, AUTOMATIC ) Job
);

/** \brief Spi_Internal_GetSequenceResult
 **
 ** Returns the last transmission result of the specified Sequence.
 **
 ** \return Transmission result of Sequence.
 ** \param [in] Sequence   Id of Sequence.
 **
 */
extern FUNC( Spi_SeqResultType, SPI_CODE ) Spi_Internal_GetSequenceResult
(
  VAR( Spi_SequenceType, AUTOMATIC ) Sequence
);

/** \brief Spi_Internal_GetVersionInfo
 **
 ** Returns the version information.
 **
 ** \return None.
 ** \param [out] versionInfoPtr   Pointer to where to store the version 
 **                               information.
 **
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_GetVersionInfo
(
  P2VAR( Std_VersionInfoType, AUTOMATIC, AUTOMATIC ) versionInfoPtr
);

/** \brief Spi_Internal_Init
 **
 ** Initializes the driver.
 **
 ** \return None.
 ** \param [in] ConfigPtr   Pointer to driver configuration set
 **
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_Init
(
  P2CONST( Spi_ConfigType, AUTOMATIC, AUTOMATIC ) ConfigPtr
);

/** \brief Spi_Internal_DeInit
 **
 ** De-initializes the driver.
 **
 ** \return None.
 **
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_DeInit(void);

/** \brief Spi_Internal_WriteIB
 **
 ** Writing one or more data to an IB channel.
 **
 ** \return None.
 ** \param [in] Channel   Id of Channel.
 ** \param [in] DataBufferPtr   Pointer to source data buffer.
 **
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_WriteIB
(
  VAR( Spi_ChannelType, AUTOMATIC ) Channel,
  P2CONST( Spi_DataBufferType, AUTOMATIC, AUTOMATIC ) DataBufferPtr
);

/** \brief Spi_Internal_ReadIB
 **
 ** Reading synchronously one or more data from an IB channel.
 **
 ** \return None.
 ** \param [in]  Channel         Id of Channel.
 ** \param [out] DataBufferPtr   Pointer to destination data buffer in RAM.
 **
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_ReadIB
(
  VAR( Spi_ChannelType, AUTOMATIC ) Channel,
  P2VAR( Spi_DataBufferType, AUTOMATIC, AUTOMATIC ) DataBufferPtr
);

/** \brief Spi_Internal_SetupEB
 **
 ** Sets the buffers and the length of data for the EB channel.
 **
 ** \return None.
 **
 ** \param [in] Channel
 **                 Channel ID
 ** \param [in] SrcDataBufferPtr
 **                 Pointer to source data buffer
 ** \param [in] DesDataBufferPtr
 **                 Pointer to destination data buffer in RAM
 ** \param [in] Length
 *                  Length (in number of data elements) of the data to be  
 **                 transmitted from SrcdataBufferPtr a nd/or received 
 **                 from DesDataBufferPtr.
 **                   Min.: 1
 **                   Max.: Maximum of data specified at configuration
 **                         for this channel
 **
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_SetupEB
(
  VAR( Spi_ChannelType, AUTOMATIC ) Channel,
  P2CONST( Spi_DataBufferType, AUTOMATIC, AUTOMATIC ) SrcDataBufferPtr,
  P2VAR( Spi_DataBufferType, AUTOMATIC, AUTOMATIC ) DesDataBufferPtr,
  VAR( Spi_NumberOfDataType, AUTOMATIC ) Length
);

/** \brief Spi_Internal_CheckSetupEB
 **
 ** Internal implementation of service to setup the buffers and the length of 
 ** data for the EB channel specified.
 **
 ** \return SPI_OK: Accept request.
 **         SPI_NOT_OK: Not accept request.
 **
 ** \param [in] Channel           
 **                 Channel ID
 ** \param [in] SrcDataBufferPtr
 **                 Pointer to source data buffer
 ** \param [in] DesDataBufferPtr
 **                 Pointer to destination data buffer in RAM
 ** \param [in] Length
 **                 Length (in number of data elements) of the data to be 
 **                 transmitted from SrcdataBufferPtr and/or received 
 **                 from DesDataBufferPtr.
 **                   Min.:  1
 **                   Max.: Maximum of data specified at configuration
 **                       for this channel
 ** \param [out] ErrorIdPtr
 **                 Pointer to error code id.
 **
 */
extern FUNC( Spi_ReturnType, SPI_CODE ) Spi_Internal_CheckSetupEB
(
  VAR( Spi_ChannelType, AUTOMATIC ) Channel,
  P2CONST( Spi_DataBufferType, AUTOMATIC, AUTOMATIC ) SrcDataBufferPtr,
  P2CONST( Spi_DataBufferType, AUTOMATIC, AUTOMATIC ) DesDataBufferPtr,
  VAR( Spi_NumberOfDataType, AUTOMATIC ) Length,
  P2VAR( Spi_ErrorType, AUTOMATIC, AUTOMATIC ) ErrorIdPtr
);

/** \brief Spi_Internal_GetBufferStatus
 **
 ** This function reads back the buffer status and the remaining length of 
 ** data for the SPI Handler/Driver Channel specified.
 ** The calling function shall assure correct parameters.
 **
 ** \param [in]  Channel
 **                 Channel ID of the channel that is polled for the status.
 ** \param [out] SrcDataBufferPtrPtr
 **                 Pointer to pointer that will be filled with pointer to 
 **                 source data buffer.
 ** \param [out] DesDataBufferPtrPtr
 **                 Pointer to pointer that will be filled with pointer to 
 **                 destination data buffer.
 ** \param [out] SrcRemainingLengthPtr
 **                 Pointer to variable that will be filled with the remaining
 **                 length (in number of data elements) of the source data yet 
 **                 to be transmitted from the source data buffer.
 ** \param [out] DesRemainingLengthPtr
 **                 Pointer to variable that will be filled with the remaining 
 **                 length (in number of data elements) of the destination  
 **                 data yet to be received to destination data buffer.
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_GetBufferStatus
(
  VAR( Spi_ChannelType, AUTOMATIC ) Channel,
  P2VAR( P2CONST(Spi_DataBufferType, AUTOMATIC, AUTOMATIC ), AUTOMATIC, AUTOMATIC) SrcDataBufferPtrPtr,
  P2VAR( P2VAR(Spi_DataBufferType, AUTOMATIC, AUTOMATIC ), AUTOMATIC, AUTOMATIC) DesDataBufferPtrPtr,
  P2VAR( Spi_NumberOfDataType, AUTOMATIC, AUTOMATIC ) SrcRemainingLengthPtr,
  P2VAR( Spi_NumberOfDataType, AUTOMATIC, AUTOMATIC ) DesRemainingLengthPtr
);

/** \brief Spi_Internal_AsyncTransmit
 **
 ** Starts asynchronous transmission.
 **
 ** \return None.
 ** \param [in]  Sequence   Id of Sequence.
 **
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_AsyncTransmit
(
  VAR( Spi_SequenceType, AUTOMATIC ) Sequence
);

/** \brief Spi_Internal_SyncTransmit
 **
 ** Starts synchronous transmission.
 **
 ** \return None.
 ** \param [in]  Sequence     Id of Sequence.
 **
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_SyncTransmit
(
  VAR( Spi_SequenceType, AUTOMATIC ) Sequence
);

/** \brief Spi_Internal_GetSyncStatus
 **
 ** Returns the synchronous transmission status.
 **
 ** \return Synchronous transmission status.
 **
 */
extern FUNC( Spi_StatusType, SPI_CODE ) Spi_Internal_GetSyncStatus(void);

/** \brief Spi_Internal_CheckSyncJob
 **
 ** Checks whether synchronous mode of jobs in the sequence is correct.
 **
 ** \return SPI_OK: Synchronous mode is correct.
 **         SPI_NOT_OK: Synchronous mode is not correct.
 **
 ** \param [in] HwUnitSync   SPI_HWUNIT_SYNC: Synchronous mode.
 **                          SPI_HWUNIT_ASYNC: Asynchronous mode.
 ** \param [in] SequenceConfPtr   Pointer to Sequence configuration.
 **
 */
extern FUNC(Spi_ReturnType, SPI_CODE) Spi_Internal_CheckSyncJob
(
  VAR( Spi_HWUnitSyncType, AUTOMATIC ) HwUnitSync,
  P2CONST( Spi_SequenceConfigType, AUTOMATIC, AUTOMATIC ) SequenceConfPtr
);

/** \brief Spi_Internal_CheckChannelType
 **
 ** Checks whether channel buffer type is correct.
 **
 ** \return SPI_OK: Channel buffer type is correct.
 **         SPI_NOT_OK: Channel buffer type is not correct.
 ** \param [in] Channel         Id of Channel.
 ** \param [in] ChannelBuffer   Buffer type (internal or external) of Channel.
 **
 */
extern FUNC( Spi_ReturnType, SPI_CODE ) Spi_Internal_CheckChannelType
(
  VAR( Spi_ChannelType, AUTOMATIC ) Channel,
  VAR( uint8, AUTOMATIC ) ChannelBuffer
);

/** \brief Spi_Internal_SetSyncStatus
 **
 ** Sets the synchronous transmission status.
 **
 ** \return None.
 ** \param [in] Status   Synchronous transmission status.
 **
 */
extern FUNC( void, SPI_CODE ) Spi_Internal_SetSyncStatus
(
  VAR( Spi_StatusType, AUTOMATIC ) Status
);

/** \brief Spi_Internal_CheckRelatedStatus
 **
 ** Checks the status of related sequences and the Jobs.
 **
 ** \return SPI_OK: The sequence is available.
 **         SPI_NOT_OK: The sequence is not available.
 ** \param [in] SequenceConfPtr   Pointer to Sequence configuration.
 ** \param [in] HwUnitSync        SPI_HWUNIT_SYNC: Synchronous mode.
 ** SPI_HWUNIT_ASYNC: Asynchronous mode.
 **
 */
extern FUNC( Spi_ReturnType, SPI_CODE ) Spi_Internal_CheckRelatedStatus
(
  P2CONST( Spi_SequenceConfigType, AUTOMATIC, AUTOMATIC ) SequenceConfPtr,
  VAR( Spi_HWUnitSyncType, AUTOMATIC ) HwUnitSync
);

/** \brief Spi_Internal_SetRelatedStatus
 **
 ** Sets the status of related sequences and the Jobs.
 **
 ** \return SPI_OK: The sequence is available.
 **         SPI_NOT_OK: The sequence is not available.
 ** \param [in] SequenceConfPtr   Pointer to Sequence configuration.
 ** \param [in] HwUnitSync        SPI_HWUNIT_SYNC: Synchronous mode.
 ** SPI_HWUNIT_ASYNC: Asynchronous mode.
 **
 */
extern FUNC( Spi_ReturnType, SPI_CODE ) Spi_Internal_SetRelatedStatus
(
  P2CONST( Spi_SequenceConfigType, AUTOMATIC, AUTOMATIC ) SequenceConfPtr,
  VAR( Spi_HWUnitSyncType, AUTOMATIC ) HwUnitSync
);

/** \brief Spi_Internal_InterruptHandler
 **
 ** Common functions for interrupt.
 **
 ** \return SPI_OK: Factor was cleared in interruption.
 **         SPI_NOT_OK: Factor is not cleared in interruption.
 ** \param [in] Factor   Specify the factor of the transmission or reception.
 ** \param [in] HWUnit   Id of hardware unit.
 **
 */
extern FUNC(Spi_ReturnType, SPI_CODE ) Spi_Internal_InterruptHandler
(
  VAR( Spi_HwFactorType, AUTOMATIC ) Factor,
  VAR( Spi_HWUnitType, AUTOMATIC )   HwUnit
);

/** \brief Spi_Internal_Terminate
 **
 ** Terminates the specified sequence.
 **
 ** \return SPI_OK:     Terminate command has been accepted
 **         SPI_NOT_OK: Terminate command has not been accepted
 ** \param [in] Sequence Id of sequence.
 **
 */
extern FUNC(Spi_ReturnType, SPI_CODE) Spi_Internal_Terminate
(
  VAR( Spi_SequenceType, AUTOMATIC ) Sequence
);

/** \brief Spi_Internal_ChangeOvsSetting
 **
 ** Change over sampling setting of external device.
 **
 ** \return None.
 ** \param [in] ExtDev      Id of external device.
 ** \param [in] ScbOvsValue Value of OVS bits in SCB CTRL register.
 **
 */
extern FUNC(void, SPI_CODE) Spi_Internal_ChangeOvsSetting
(
  CONST( Spi_ExtDeviceType, AUTOMATIC ) ExtDev,
  VAR( Spi_OvsValueType, AUTOMATIC ) ScbOvsValue
);

#define SPI_STOP_SEC_CODE_ASIL_B
#include <Spi_MemMap.h>

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#endif /*!defined(SPI_INTERNAL_H_INCLUDED)*/

/*==================[end of file]===========================================*/
