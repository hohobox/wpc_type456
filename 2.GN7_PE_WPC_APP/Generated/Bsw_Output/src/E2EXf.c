  /*******************************************************************************
  **                        File Generation Information                         **
  *******************************************************************************/

  /*
  * GENERATED ON : The time-stamp is removed
  */

/*******************************************************************************
**                              Include Section                               **
*******************************************************************************/
/*************Design ID : E2EXf_SDD_0004,E2EXf_SDD_0011************************/
#include "stdio.h"
#include "E2EXf.h"      /* E2EXf header file */
#if (E2EXF_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#if (E2EXF_EXTENDED_DEM == STD_ON)
#include "Dem.h"        /* Dem module header file */
#endif

/*******************************************************************************
**                               Version Check                                **
*******************************************************************************/

#if (E2EXF_VERSION_AR_RELEASE_MAJOR_VERSION != E2EXF_AR_RELEASE_MAJOR_VERSION)
  #error "E2EXF Code : Mismatch in Specification Major Version"
#endif

#if (E2EXF_VERSION_AR_RELEASE_MINOR_VERSION != E2EXF_AR_RELEASE_MINOR_VERSION)
  #error "E2EXF Code : Mismatch in Specification Minor Version"
#endif

#if (E2EXF_VERSION_AR_RELEASE_REVISION_VERSION != E2EXF_AR_RELEASE_REVISION_VERSION)
  #error "E2EXF Code : Mismatch in Specification Revision Version"
#endif

#if (E2EXF_VERSION_SW_MAJOR_VERSION != E2EXF_SW_MAJOR_VERSION)
  #error "E2EXF Code : Mismatch in Software Major Version"
#endif

#if (E2EXF_VERSION_SW_MINOR_VERSION != E2EXF_SW_MINOR_VERSION)
  #error "E2EXF Code : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                                Global Data                                 **
*******************************************************************************/
/*
  SWS_E2EXf_00130: The E2E Transformer shall maintain a boolean information
  (Initialization state) that is only set to TRUE, if the module has been
  successfully initialized via a call to E2EXf_Init(). Otherwise, it is set
  to FALSE.
*/
#define E2EXF_START_SEC_VAR_INIT_BOOLEAN
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

static VAR(boolean, E2EXF_VAR_INIT) E2EXf_GblInitStat =
(boolean)E2EXF_GBLINITSTAT_INITIAL_VALUE;
/*
static VAR(boolean, E2EXF_VAR_INIT) E2EXf_GblInitStat_Data_FS1 = 
(boolean)((boolean)E2EXF_GBLINITSTAT_INITIAL_VALUE ^ (boolean)E2EXF_GBLINITSTAT_XOR1);
static VAR(boolean, E2EXF_VAR_INIT) E2EXf_GblInitStat_Data_FS2 = 
(boolean)((boolean)E2EXF_GBLINITSTAT_INITIAL_VALUE ^ (boolean)E2EXF_GBLINITSTAT_XOR2);
*/

#define E2EXF_STOP_SEC_VAR_INIT_BOOLEAN
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"


#define E2EXF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"


#define E2EXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
/*
  SWS_E2EXf_00023: In all E2E Transformer variants, the generated state
  objects may be left uninitialized
*/
/*
  SWS_E2EXf_00125: The E2E Transformer shall derive the required number
  of independent state data resources of types E2E_PXXProtectStateType,
  E2E_PXXCheckStateType, and E2E_SMCheckStateType to perform E2E Protection
  within the E2E Transformer module from the number of E2E-protected data
  uniquely identified with <transformerId>, protected by profile XX.
*/


/*************** Design ID : E2EXf_SDD_0028 ********************/
static E2E_P05ProtectStateType E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms;

/*************** Design ID : E2EXf_SDD_0028 ********************/
static E2E_P05ProtectStateType E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms;

/*************** Design ID : E2EXf_SDD_0028 ********************/
static E2E_P05ProtectStateType E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms;

/*************** Design ID : E2EXf_SDD_0028 ********************/
static E2E_P05ProtectStateType E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms;



/*************** Design ID : E2EXf_SDD_0028 ********************/
static E2E_P05ProtectStateType E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC2_FD_01_200ms_MsgGr_E2E_BCAN_WPC2_FD_01_200ms;

#define E2EXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

/*************** Design ID : E2EXf_SDD_0025,E2EXf_SDD_0026 ********************/
static E2E_P05CheckStateType E2EXf_GddCS_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms;

/*************** Design ID : E2EXf_SDD_0034,E2EXf_SDD_0036 ********************/
/* polyspace<MISRA-C:5.1:Not a defect:Justify with annotations> Varaible Name is derived from API */
static E2E_SMCheckStateType E2EXf_GddSMCheckStatePtr_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms;

#define E2EXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_CONST_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

/*************** Design ID : E2EXf_SDD_0035 ********************/ 
static const E2E_SMConfigType E2EXf_GddSMCCP_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms =
{
  1U,  /*WindowSize*/

  1U,  /* MinOkStateInit */

  0U,   /* MaxErrorStateInit */

  1U,   /* MinOkStateValid */

  0U,  /* MaxErrorStateValid */

  1U,  /* MinOkStateInvalid */

  0U   /* MaxErrorStateInvalid */
};
#define E2EXF_STOP_SEC_CONST_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

/*************** Design ID : E2EXf_SDD_0025,E2EXf_SDD_0026 ********************/
static E2E_P05CheckStateType E2EXf_GddCS_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms;

/*************** Design ID : E2EXf_SDD_0034,E2EXf_SDD_0036 ********************/
/* polyspace<MISRA-C:5.1:Not a defect:Justify with annotations> Varaible Name is derived from API */
static E2E_SMCheckStateType E2EXf_GddSMCheckStatePtr_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms;

#define E2EXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_CONST_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

/*************** Design ID : E2EXf_SDD_0035 ********************/ 
static const E2E_SMConfigType E2EXf_GddSMCCP_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms =
{
  1U,  /*WindowSize*/

  1U,  /* MinOkStateInit */

  0U,   /* MaxErrorStateInit */

  1U,   /* MinOkStateValid */

  0U,  /* MaxErrorStateValid */

  1U,  /* MinOkStateInvalid */

  0U   /* MaxErrorStateInvalid */
};
#define E2EXF_STOP_SEC_CONST_UNSPECIFIED
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
/*****************************************************************************
** Function Name        : E2EXf_GblInitStat_setData                         **
**                                                                          **
** Service ID           : NA                                                **
**                                                                          **
** Description          : This functions Encrypts safety critical data      **
**                                                                          **
** Sync/Async           : NA                                                **
**                                                                          **
** Re-entrancy          : Re-entrant                                        **
**                                                                          **
** Input Parameters     : blState                                           **
**                                                                          **
** InOut parameter      : None                                              **
**                                                                          **
** Output Parameters    : None                                              **
**                                                                          **
** Return parameter     : None                                              **
**                                                                          **
** Preconditions        : None                                              **
**                                                                          **
** Remarks              : Global Variable(s)     :                          **
**                        E2EXf_GblInitStat                                 **
**                                                                          **
**                        Function(s) invoked    :                          **
**                        None                                              **
**                                                                          **
** Embedded Code ID     : E2EXf_SDD_76                                      **
*****************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE) E2EXf_GblInitStat_setData(
VAR(boolean, E2EXF_APPL_DATA) blState)
{
  E2EXf_GblInitStat = blState;
/*
  E2EXf_GblInitStat_Data_FS1 = (boolean)(blState ^ (boolean)E2EXF_GBLINITSTAT_XOR1);
  E2EXf_GblInitStat_Data_FS2 = (boolean)(blState ^ (boolean)E2EXF_GBLINITSTAT_XOR2);
*/
  return;
}
#define E2EXF_STOP_SEC_CODE  
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

/*******************************************************************************
* E2EXf_memcpy FUNCTION DEFINITIONS
*******************************************************************************/
/*******************************************************************************
** Function Name        : E2EXf_Memcpy                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Custom implementation of memcpy.                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : pDestBuffer, pSrcBuffer, usDataLength               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : E2EXf_SDD_0073                                      **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE) E2EXf_Memcpy(
P2VAR(uint8,AUTOMATIC,E2EXF_APPL_DATA) pDestBuffer,
P2CONST(uint8, AUTOMATIC,E2EXF_APPL_DATA) pSrcBuffer,
VAR(uint16, E2EXF_APPL_DATA) usDataLength);

static FUNC(void, E2EXF_CODE) E2EXf_Memcpy(
P2VAR(uint8,AUTOMATIC,E2EXF_APPL_DATA) pDestBuffer,
P2CONST(uint8, AUTOMATIC,E2EXF_APPL_DATA) pSrcBuffer,
VAR(uint16, E2EXF_APPL_DATA) usDataLength)
{
  VAR(uint16, AUTOMATIC) LucIndex = usDataLength;
  
  for(LucIndex = usDataLength; LucIndex > 0U; LucIndex--) 
  {
/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
    pDestBuffer[usDataLength-LucIndex] = pSrcBuffer[usDataLength-LucIndex];
  }
/*
  while(0U != usDataLength)
  {
    *pDestBuffer = *pSrcBuffer;
    pDestBuffer = pDestBuffer++;
    pSrcBuffer = pSrcBuffer++;
    usDataLength--;
  }
*/
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"



    	
#if (E2EXF_DEV_ERROR_DETECT == STD_ON)
/*******************************************************************************
* E2EXf_DetCheck FUNCTION DEFINITIONS
*******************************************************************************/
/*******************************************************************************
** Function Name        : E2EXf_DetCheck                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks parameters and report DET if   **
                          required.                                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : buffer, bufferLength, inputBufferJ,                 **
**                      : inputBufferLength, usLddUpperHeaderBitsToShift,     **
**                      : blInplace                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            :   E2EXf_SDD_0071                                    **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
static FUNC(boolean, E2EXF_CODE) E2EXf_DetCheck(
P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
P2CONST(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
VAR(uint16, E2EXF_APPL_DATA)inputBufferLength,
VAR(uint16, E2EXF_APPL_DATA)LusUpperHeaderBitsToShift,
VAR(boolean, E2EXF_APPL_DATA)blInplace)
{
  VAR(boolean, E2EXF_DATA) LblDetOccured = E2EXF_FALSE;
  /*
    SWS_E2EXf_00151 :If the configuration parameter E2EXfDevErrorDetect is enabled, 
    the API E2EXf_<transformerId> (see SWS_E2EXf_00032) shall check if the E2E Transformer
    is initialized. In case of an error the routine shall not be executed, the error shall 
    be reported to the Default Error Tracer with the error code E2EXF_E_UNINIT and the routine
    shall return the value E_SAFETY_HARD_RUNTIMEERROR.(SRS_E2E_08538)
  */
  if (E2EXF_FALSE == E2EXf_GblInitStat)
  {
    /* Report to DET*/
    (void) Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
    E2EXF_TRANSFORMERID_SID, E2EXF_E_UNINIT);
    LblDetOccured = E2EXF_TRUE;
  }

  /*
    SWS_E2EXf_00150 :  If the configuration parameter E2EXfDevErrorDetect is enabled, all parameters of 
    API E2EXf_<transformerId> (see SWS_E2EXf_00032) shall be checked for being in the allowed range. 
    In case of an error the mode switch shall not be executed, the error shall be reported to the 
    Development Error Tracer with the value E2EXF_E_PARAM resp. E2EXF_E_PARAM_POINTER in case of a pointer
    argument and the routine shall return the value E_SAFETY_HARD_RUNTIMEERROR.(SRS_E2E_08538)
  */
  /* Check if API service called with invalid pointer */
  if (NULL_PTR == bufferLength)
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    /* Report to DET*/
    (void)Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
    E2EXF_TRANSFORMERID_SID, E2EXF_E_PARAM_POINTER);
    LblDetOccured = E2EXF_TRUE;
  }
  if (blInplace == E2EXF_INPLACE_TRUE)
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    /* Check if API service called with wrong parameter for in-place buffer */
    if (((NULL_PTR == buffer) && (E2EXF_ZERO != inputBufferLength))||
    ((NULL_PTR != buffer) && (inputBufferLength <
    (LusUpperHeaderBitsToShift/E2EXF_EIGHT))))
    {
      /* Report to DET*/
      (void)Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
      E2EXF_TRANSFORMERID_SID, E2EXF_E_PARAM);
      LblDetOccured = E2EXF_TRUE;
    }
  }
  else
  {
    /* Check if API service called with wrong parameter for out-place buffer */
    if (((NULL_PTR == inputBuffer) &&
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
    (E2EXF_ZERO != inputBufferLength)) || ((NULL_PTR != inputBuffer) &&
    (inputBufferLength < (LusUpperHeaderBitsToShift/E2EXF_EIGHT))))
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
    {
      /* Report to DET*/
      (void)Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
      E2EXF_TRANSFORMERID_SID, E2EXF_E_PARAM);
      LblDetOccured = E2EXF_TRUE;
    }
    /* Check if API service called with wrong pointer for out-place buffer */
    if (NULL_PTR == buffer)
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
    {
      /* Report to DET*/
      (void)Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
      E2EXF_TRANSFORMERID_SID, E2EXF_E_PARAM_POINTER);
      LblDetOccured = E2EXF_TRUE;
    }
  }

  return(LblDetOccured);
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
#endif




#if (E2EXF_DEV_ERROR_DETECT == STD_ON)
/*******************************************************************************
* E2EXf_Inv_DetCheck FUNCTION DEFINITIONS
*******************************************************************************/
/*******************************************************************************
** Function Name        : E2EXf_Inv_DetCheck                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks parameters and report DET if   **
                          required.                                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : buffer, bufferLength, inputBuffer                   **
**                      : inputBufferLength, usLddUpperHeaderBitsToShift,     **
**                      : usLddHeaderLength, blInplace                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            :   E2EXf_SDD_0072                                    **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
static FUNC(boolean, E2EXF_CODE) E2EXf_Inv_DetCheck(
P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
P2CONST(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
VAR(uint16, E2EXF_APPL_DATA)inputBufferLength,
VAR(uint16, E2EXF_APPL_DATA)LusUpperHeaderBitsToShift,
VAR(uint16, E2EXF_APPL_DATA)LusHeaderLength,
VAR(boolean, E2EXF_APPL_DATA)blInplace)
{
  VAR(boolean, E2EXF_DATA) LblDetOccured = E2EXF_FALSE;

  /*
    SWS_E2EXf_00153: If the configuration parameter E2EXfDevErrorDetect is enabled,
    the API E2EXf_Inv_<transformerId> (see SWS_E2EXf_00034) shall check if the 
    E2E Transformer is initialized. In case of an error the routine shall not be 
    executed, the error shall be reported to the Default Error Tracer with the error
    code E2EXF_E_UNINIT and the routine shall return the value E_SAFETY_HARD_RUNTIMEERROR.(SRS_E2E_08538)
  */

  if (E2EXF_FALSE == E2EXf_GblInitStat)
  {
    /* Report to DET*/
    (void)Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
    E2EXF_INV_TRANSFORMERID_SID, E2EXF_E_UNINIT);
    LblDetOccured = E2EXF_TRUE;
  }

  /*
    SWS_E2EXf_00152: If the configuration parameter E2EXfDevErrorDetect is enabled,
    all parameters of API E2EXf_Inv_<transformerId> (see SWS_E2EXf_00034) shall be 
    checked for being in the allowed range. In case of an error the mode switch shall
    not be executed, the error shall be reported to the Development Error Tracer with 
    the value E2EXF_E_PARAM resp. E2EXF_E_PARAM_POINTER in case of a pointer argument 
    and the routine shall return the value E_SAFETY_HARD_RUNTIMEERROR.(SRS_E2E_08538)
  */

  /* Check if API service called with invalid pointer */
  if (NULL_PTR == bufferLength)
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    /* Report to DET*/
    (void)Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
    E2EXF_INV_TRANSFORMERID_SID, E2EXF_E_PARAM_POINTER);
    LblDetOccured = E2EXF_TRUE;
  }

  if (blInplace == E2EXF_INPLACE_TRUE)
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    /* Check if API service called with wrong parameter for in-place buffer */
    if (((NULL_PTR == buffer) && (E2EXF_ZERO != inputBufferLength)) ||
    ((NULL_PTR != buffer) && (inputBufferLength <
    ((LusHeaderLength/E2EXF_EIGHT) +
    (LusUpperHeaderBitsToShift/E2EXF_EIGHT)))))
    {
      /* Report to DET*/
      (void)Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
      E2EXF_INV_TRANSFORMERID_SID, E2EXF_E_PARAM);
      LblDetOccured = E2EXF_TRUE;
    }
  }
  else
  {
    /* Check if API service called with wrong parameter for out-place buffer */
    if (((NULL_PTR == inputBuffer) && 
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
    (E2EXF_ZERO != inputBufferLength )) || ((NULL_PTR != inputBuffer) &&
    (inputBufferLength < ((LusHeaderLength/E2EXF_EIGHT) +
    (LusUpperHeaderBitsToShift/E2EXF_EIGHT)))))
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
    {
      /* Report to DET*/
      (void)Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
      E2EXF_INV_TRANSFORMERID_SID, E2EXF_E_PARAM);

      LblDetOccured = E2EXF_TRUE;
    }
    /* Check if API service called with wrong pointer for out-place buffer */   
    if (NULL_PTR == buffer)
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
    {
      /* Report to DET*/
      (void)Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
      E2EXF_INV_TRANSFORMERID_SID, E2EXF_E_PARAM_POINTER);

      LblDetOccured = E2EXF_TRUE;
    }
  }

  return(LblDetOccured);
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
#endif


/*******************************************************************************
* E2E INIT FUNCTION DEFINITIONS
*******************************************************************************/
/*******************************************************************************
** Function Name        : E2EXf_Init                                          **
**                                                                            **
** Service ID           : 0x01                                                **
**                                                                            **
** Description          : Initializes the state of the E2E Transformer.       **
**                        The main part of it is the initialization of the    **
**                        E2E library state structures, which is done by      **
**                        calling all init-functions from E2E library.        **
**                        (SWS_E2EXf_00035)                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : config                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : E2EXf_GblInitStat             **
**                        Function(s) invoked : Det_ReportError(),            **
                                                E2E_P0XProtectInit(),         **
                                                E2E_P0XCheckInit(),           **
                                                E2E_SMCheckInit()             **
** Design ID            : E2EXf_SDD_0041,E2EXf_SDD_0011                       **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
FUNC(void, E2EXF_CODE) E2EXf_Init(
P2CONST(E2EXf_ConfigType, AUTOMATIC, E2EXF_APPL_DATA) config)
{
  /* Variables to store return value of E2E Init function */
               
  /*******************Design ID : E2EXf_SDD_0037******************************/
  VAR(Std_ReturnType, E2EXF_DATA) LucProtectInitRetVal_01;
               
  /*******************Design ID : E2EXf_SDD_0037******************************/
  VAR(Std_ReturnType, E2EXF_DATA) LucProtectInitRetVal_02;
               
  /*******************Design ID : E2EXf_SDD_0037******************************/
  VAR(Std_ReturnType, E2EXF_DATA) LucProtectInitRetVal_03;
               
  /*******************Design ID : E2EXf_SDD_0037******************************/
  VAR(Std_ReturnType, E2EXF_DATA) LucProtectInitRetVal_04;
  /*******************Design ID : E2EXf_SDD_0037******************************/
  VAR(Std_ReturnType, E2EXF_DATA) LucCheckInitRetVal_01;
  /*******************Design ID : E2EXf_SDD_0037******************************/
  VAR(Std_ReturnType, E2EXF_DATA) LddSMCheckInitRetVal_01;
  /*******************Design ID : E2EXf_SDD_0037******************************/
  VAR(Std_ReturnType, E2EXF_DATA) LucCheckInitRetVal_02;
  /*******************Design ID : E2EXf_SDD_0037******************************/
  VAR(Std_ReturnType, E2EXF_DATA) LddSMCheckInitRetVal_02;
               
  /*******************Design ID : E2EXf_SDD_0037******************************/
  VAR(Std_ReturnType, E2EXF_DATA) LucProtectInitRetVal_05;
  
  /*
    Array in which the ProfileStatus-es of the last E2E-checks are stored.
    Where windowSize = EndToEndTransformationComSpecProps.windowSize or
    EndToEndTransformationDescription.windowSize [SWS_E2EXf_00088]
  */
    static VAR(uint8, E2EXF_APPL_DATA) usPSW_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms[1];
  /*
    Array in which the ProfileStatus-es of the last E2E-checks are stored.
    Where windowSize = EndToEndTransformationComSpecProps.windowSize or
    EndToEndTransformationDescription.windowSize [SWS_E2EXf_00088]
  */
    static VAR(uint8, E2EXF_APPL_DATA) usPSW_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms[1];


  /*
    SWS_E2EXf_00021: The E2EXf_Init() function shall initialize all state structures managed
    by E2E transformer, calling the corresponding E2E_Init() method on each state variable.
  */
  /*******************Design ID : E2EXf_SDD_0063******************************/
  LucProtectInitRetVal_01 = E2E_P05ProtectInit(&E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms);
  /*******************Design ID : E2EXf_SDD_0063******************************/
  LucProtectInitRetVal_02 = E2E_P05ProtectInit(&E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms);
  /*******************Design ID : E2EXf_SDD_0063******************************/
  LucProtectInitRetVal_03 = E2E_P05ProtectInit(&E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms);
  /*******************Design ID : E2EXf_SDD_0063******************************/
  LucProtectInitRetVal_04 = E2E_P05ProtectInit(&E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms);
  
  E2EXf_GddSMCheckStatePtr_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms.ProfileStatusWindow =
  usPSW_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms;
  /*******************Design ID : E2EXf_SDD_0060******************************/
  LucCheckInitRetVal_01 =
  E2E_P05CheckInit(&E2EXf_GddCS_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms);
  
  /*******************Design ID : E2EXf_SDD_0070******************************/
  LddSMCheckInitRetVal_01 = E2E_SMCheckInit(
  &E2EXf_GddSMCheckStatePtr_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms,
  &E2EXf_GddSMCCP_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms);
        
  
  E2EXf_GddSMCheckStatePtr_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms.ProfileStatusWindow =
  usPSW_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms;
  /*******************Design ID : E2EXf_SDD_0060******************************/
  LucCheckInitRetVal_02 =
  E2E_P05CheckInit(&E2EXf_GddCS_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms);
  
  /*******************Design ID : E2EXf_SDD_0070******************************/
  LddSMCheckInitRetVal_02 = E2E_SMCheckInit(
  &E2EXf_GddSMCheckStatePtr_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms,
  &E2EXf_GddSMCCP_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms);
        
  /*******************Design ID : E2EXf_SDD_0063******************************/
  LucProtectInitRetVal_05 = E2E_P05ProtectInit(&E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC2_FD_01_200ms_MsgGr_E2E_BCAN_WPC2_FD_01_200ms);

  /* Check if all E2E init functions returns  E2E_E_OK */
  if ( (E2E_E_OK == LucProtectInitRetVal_01) && (E2E_E_OK == LucProtectInitRetVal_02) && (E2E_E_OK == LucProtectInitRetVal_03) && (E2E_E_OK == LucProtectInitRetVal_04) && (E2E_E_OK == LucCheckInitRetVal_01) && (E2E_E_OK == LddSMCheckInitRetVal_01) && (E2E_E_OK == LucCheckInitRetVal_02) && (E2E_E_OK == LddSMCheckInitRetVal_02) && (E2E_E_OK == LucProtectInitRetVal_05))
  {
    E2EXf_GblInitStat_setData(E2EXF_TRUE);
  }
  else
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
  {
    E2EXf_GblInitStat_setData(E2EXF_FALSE);
  }

  E2EXF_UNUSED_PTR(config); 
  
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"


/*******************************************************************************
* E2E DEINIT FUNCTION DEFINITIONS
*******************************************************************************/
/*******************************************************************************
** Function Name        : E2EXf_DeInit                                        **
**                                                                            **
** Service ID           : 0x02                                                **
**                                                                            **
** Description          : Deinitializes the E2E transformer. (SWS_E2EXf_00138)**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : E2EXf_GblInitStat             **
**                        Function(s) invoked : Det_ReportError()             **
** Design ID            : E2EXf_SDD_0042                                      **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
FUNC(void, E2EXF_CODE) E2EXf_DeInit(void)
{
  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  /*
    SWS_E2EXf_00146:If the E2EXfDevErrorDetect switch is enabled and the configuration 
    variant is VARIANT-POST-BUILD, the function E2EXf_Init shall check the contents of 
    the given configuration set for being within the allowed boundaries. If the function
    E2EXf_Init detects an error, then it shall skip the initialization of the E2E Transformer,
    keep the module internal state as uninitialized and it shall report development error code
    E2EXF_E_INIT_FAILED to the Det_ReportError service of the Default Error Tracer. (SRS_E2E_08538)
  */
  if (E2EXF_FALSE == E2EXf_GblInitStat)
  {
    /* Report to DET*/
    (void)Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
    E2EXF_DEINIT_SID, E2EXF_E_UNINIT);
  }
  else
  #endif
  {
    /*
      SWS_E2EXf_00132: In case of deinitialization
      (invocation of E2EXf_DeInit()), the module
      initialization state shall be set to FALSE.
    */
    /*
      SWS_E2EXf_00148: E2EXf_DeInit() shall check shall set the
      module initialization  state to FALSE.
    */
    /*
      SWS_E2EXf_00138e: API E2EXf_DeInit deinitializes the E2E transformer.
      Return value: None
    */
    E2EXf_GblInitStat_setData(E2EXF_FALSE);
  }
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

/*******************************************************************************
* E2EXF GET VERSION FUNCTION DEFINITIONS
*******************************************************************************/
/*******************************************************************************
** Function Name        : E2EXf_GetVersionInfo                                **
**                                                                            **
** Service ID           : 0x05                                                **
**                                                                            **
** Description          : Returns the version information of this module.     **
**                        (SWS_E2EXf_00036)                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : versioninfo                                         **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : E2EXf_GblInitStat             **
**                        Function(s) invoked : Det_ReportError()             **
** Design ID            : E2EXf_SDD_0043,E2EXf_SDD_0037,E2EXf_SDD_0075        **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
FUNC(void, E2EXF_CODE) E2EXf_GetVersionInfo(
P2VAR(Std_VersionInfoType,AUTOMATIC,E2EXF_APPL_DATA)VersionInfo)
{
  /*
    SWS_E2EXf_00149: If the E2EXfDevErrorDetect switch is enabled, the function 
    E2EXf_GetVersionInfo shall check if a NULL pointer is passed for the 
    VersionInfo parameter. In case of an error the remaining function 
    E2EXf_GetVersionInfo shall not be executed and the function 
    E2EXf_GetVersionInfo shall report development error code E2EXF_E_PARAM_POINTER
    to the Det_ReportError service of the Default Error Tracer.(SRS_E2E_08538)
  */
  if (NULL_PTR == VersionInfo)
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET*/
    (void)Det_ReportError(E2EXF_MODULE_ID, E2EXF_INSTANCE_ID,
    E2EXF_GETVERSIONINFO_SID, E2EXF_E_PARAM_POINTER);
    #endif /* (E2EXF_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
/* polyspace<MISRA2012:14.3:Not a defect:Justify with annotations> Argument is passed from caller  */
/* polyspace<MISRA2012:2.1:Not a defect:Justify with annotations> Argument is passed from caller  */
/* polyspace<DEFECT:DEAD_CODE:Not a defect:Justify with annotations> Argument is passed from caller */
    /* Copy the vendor Id */
/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
    VersionInfo->vendorID = E2EXF_VENDOR_ID;
    /* Copy the module Id*/
    VersionInfo->moduleID = E2EXF_MODULE_ID;
    /* Copy Software Major Version */
    VersionInfo->sw_major_version = (uint8)E2EXF_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    VersionInfo->sw_minor_version =(uint8) E2EXF_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    VersionInfo->sw_patch_version = (uint8)E2EXF_SW_PATCH_VERSION;
  }
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

/*******************************************************************************
** Function Name        : E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms                                           **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : Protects the array/buffer to be transmitted,        **
**                        using the in-place transformation.(SWS_E2EXf_00032) **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : inputBuffer, inputBufferLength                      **
**                                                                            **
** InOut parameter      : buffer                                              **
**                                                                            **
** Output Parameters    : bufferLength                                        **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : E2EXf_Init is invoked successfully.                 **
**                                                                            **
** Remarks              : Global Variable(s)  : E2EXf_GblInitStat             **
**                        Function(s) invoked : Det_ReportError(),            **
**                                              E2E_P0XProtect(),             **
**                                              E2EXf_memcpy(),               **
**                                                                            **
** Design ID            : E2EXf_SDD_0001,E2EXf_SDD_0038                       **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
/*
SWS_E2EXf_00020:The function E2EXf_<transformerId> shall be generated for
each E2E-protected data element.
*/
/* polyspace<MISRA-C:5.1:Not a defect:Justify with annotations> Function Name is following AUTOSAR Standard  */
FUNC(uint8, E2EXF_CODE)  E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms(
P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
VAR(uint16, E2EXF_APPL_DATA)inputBufferLength)
{
  VAR(uint8, AUTOMATIC) LucRet = E_SAFETY_HARD_RUNTIMEERROR;
  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, E2EXF_DATA) LblDetOccured = E2EXF_FALSE;
  #endif

    /*******************Design ID : E2EXf_SDD_0037******************************/
  Std_ReturnType LucProtectRet = E2E_E_INTERR;

  /* <END-TO-END-TRANSFORMATION-DESCRIPTION>.<UPPER-HEADER-BITS-TO-SHIFT> */
  uint16 LusUpperHeaderBitsToShift = 0U;

  /* <BUFFER-PROPERTIES>.<HEADER-LENGTH> */
  uint16 LusHeaderLength = 0U;

  /*
    SWS_E2EXf_00134: The configuration options in
    EndToEndTransformationComSpecProps shall have
    precedence over the options in EndToEndTransformationDescription and
    EndToEndTransformationISignalProps.
  */
  /*
    SWS_E2EXf_00126: The E2E Transformer shall derive the required number of
    independent statically initialized configuration objects of types
    E2E_PXXConfigType and E2E_SMConfigType to perform  E2E Protection within
    the E2E Transformer, from:
    1. the number of E2E-protected data uniquely identified with
       <transformerId>, protected by profile XX, and
       <transformerId>, protected by profile XX, and
    2. the number of configuration variants (post-build selectable only).
  */
  /*
    UC_E2E_00206:  During its initialization, the Receiver shall instantiate
    the structures PXXConfigType and PXXReceiverType.
    Note: PXXReceiverType is initilized in E2EXf_Init API
  */
  /*
    UC_E2E_00207  During its initialization, the Receiver shall initialize
    the PXXConfigType  with the required configured settings, for each Data.
  */
  /*******************Design ID : E2EXf_SDD_0027******************************/
  /*
    SWS_E2EXf_00119: The generated configuration object of type E2E_P05ConfigType 
    shall be initialized according to the following (one-to-one mapping):
    DataID = EndToEndTransformationISignalProps.dataID
    DataLength = EndToEndTransformationISignalProps.dataLength
    Offset = EndToEndTransformationDescription.offset
    MaxDeltaCounter = EndToEndTransformationComSpecProps.maxDeltaCounter or EndToEndTransformationDescription.maxDeltaCounter (SRS_E2E_08538)
  */
  CONST(E2E_P05ConfigType,E2EXf_DATA)LstE2EProtectConfig = 
  {
    0U,    /* offset */
    128U,   /* DataLength */
    64401U,    /* dataID */
    10U   /*  maxDeltaCounter */
  };


  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  LblDetOccured = E2EXf_DetCheck(
  buffer, bufferLength, inputBuffer, inputBufferLength,
  LusUpperHeaderBitsToShift, INPLACE_E2EXF_APP_CAN_TX_GR_MSGGR_E2E_BCAN_WPC_FD_01_200MS_MSGGR_E2E_BCAN_WPC_FD_01_200MS);
  if (E2EXF_FALSE == LblDetOccured)
  #endif
  {
    /*
      SWS_E2EXf_00133: If the E2E Transformer has not been correctly initialized
      (which means that E2EXf_Init() was not successfully called before),
      then all generated E2E Transformer APIs shall immediately return
      E_SAFETY_HARD_RUNTIMEERROR.
    */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
    if (E2EXF_TRUE == E2EXf_GblInitStat)
    {
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
      if (E2EXF_OUTPLACE_PRECONDITIONS) /* E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms OUTPLACE Pre conditions check */
      {
      /*
        SWS_E2EXf_00109 : If (inputBuffer != NULL && EndToEndTransformation
        Description.upperHeaderBitsToShift > 0),out-of-place
        E2EXf_<transformerId> shall copy the first upperHeaderBitsToShift
        bits from inputBuffer to buffer, and then copy the remaining part of
        inputBuffer(i.e. starting with offset upperHeaderBitsToShift)
        to parameter buffer starting with the destination offset of
        (upperHeaderBitsToShift+ BufferProperties.headerLength).
      */

        if (NULL_PTR != inputBuffer)
/* polyspace<MISRA-C:13.7:Not a defect:Justify with annotations> Condition value is invariant because it is generated from arxml  */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
          /*
            copy inputBuffer starting with the offset of
            BufferProperties.headerLength, to buffer
          */
/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
          E2EXf_Memcpy(&buffer[LusHeaderLength/E2EXF_EIGHT], inputBuffer, inputBufferLength);
        }
        else
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
        }

        /*
          SWS_E2EXf_00111:E2EXf_<transformerId> shall set *bufferLength =
          inputBufferLength + BufferProperties.headerLength.
        */
        *bufferLength = inputBufferLength + (LusHeaderLength/E2EXF_EIGHT);

        /*
          SWS_E2EXf_00139 : For PXX = 01 or 02, the functionE2EXf_<transformerId>() shall perform a check of the
          *bufferLength (after the computation of *bufferLength):
          If (*bufferLength != config->DataLength), then the function shall
          return immediately E_SAFETY_HARD_RUNTIMEERROR, i.e. without calling
          an E2E Library function.(SRS_E2E_08538)
        */

        /*
          SWS_E2EXf_00107 : The function E2EXf_<transformerId>() shall invoke
          E2E_PXXProtect(), passing to that function the appropriate Config and State
          structures (see [SWS_E2EXf_00125] and [SWS_E2EXf_00126]) that are associated
          with <transformerId>, as well as buffer and bufferLength (only for P04, P05, P06,
          P07, P11 and P22) that were updated in above requirements SWS_E2EXf_00108,
          SWS_E2EXf_00109, SWS_E2EXf_00115, SWS_E2EXf_00111.
        */
                    
        /**********Design ID : E2EXf_SDD_0057,E2EXf_SDD_0062,E2EXf_SDD_0067*******************/ 
        LucProtectRet = E2E_P05Protect(&LstE2EProtectConfig,
        &E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms, buffer, *bufferLength);
        /*
          SWS_E2EXf_00018 : In case E2E_PXXProtect() returns E2E_E_OK, then
          E2EXf_<transformerId> shall return E_OK, otherwise E2EXf_<transformerId>
          shall return E_SAFETY_HARD_RUNTIMEERROR.
        */
                   
        if (E2E_E_OK == LucProtectRet)
        {
          LucRet = E_OK;
        }
      }/*End of if (E2EXF_OUTPLACE_PRECONDITIONS)*/
    }/*End of if (E2EXF_TRUE == E2EXf_GblInitStat)*/
  }
  return(LucRet);
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

/*******************************************************************************
** Function Name        : E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms                                           **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : Protects the array/buffer to be transmitted,        **
**                        using the in-place transformation.(SWS_E2EXf_00032) **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : inputBuffer, inputBufferLength                      **
**                                                                            **
** InOut parameter      : buffer                                              **
**                                                                            **
** Output Parameters    : bufferLength                                        **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : E2EXf_Init is invoked successfully.                 **
**                                                                            **
** Remarks              : Global Variable(s)  : E2EXf_GblInitStat             **
**                        Function(s) invoked : Det_ReportError(),            **
**                                              E2E_P0XProtect(),             **
**                                              E2EXf_memcpy(),               **
**                                                                            **
** Design ID            : E2EXf_SDD_0001,E2EXf_SDD_0038                       **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
/*
SWS_E2EXf_00020:The function E2EXf_<transformerId> shall be generated for
each E2E-protected data element.
*/
/* polyspace<MISRA-C:5.1:Not a defect:Justify with annotations> Function Name is following AUTOSAR Standard  */
FUNC(uint8, E2EXF_CODE)  E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms(
P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
VAR(uint16, E2EXF_APPL_DATA)inputBufferLength)
{
  VAR(uint8, AUTOMATIC) LucRet = E_SAFETY_HARD_RUNTIMEERROR;
  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, E2EXF_DATA) LblDetOccured = E2EXF_FALSE;
  #endif

    /*******************Design ID : E2EXf_SDD_0037******************************/
  Std_ReturnType LucProtectRet = E2E_E_INTERR;

  /* <END-TO-END-TRANSFORMATION-DESCRIPTION>.<UPPER-HEADER-BITS-TO-SHIFT> */
  uint16 LusUpperHeaderBitsToShift = 0U;

  /* <BUFFER-PROPERTIES>.<HEADER-LENGTH> */
  uint16 LusHeaderLength = 0U;

  /*
    SWS_E2EXf_00134: The configuration options in
    EndToEndTransformationComSpecProps shall have
    precedence over the options in EndToEndTransformationDescription and
    EndToEndTransformationISignalProps.
  */
  /*
    SWS_E2EXf_00126: The E2E Transformer shall derive the required number of
    independent statically initialized configuration objects of types
    E2E_PXXConfigType and E2E_SMConfigType to perform  E2E Protection within
    the E2E Transformer, from:
    1. the number of E2E-protected data uniquely identified with
       <transformerId>, protected by profile XX, and
       <transformerId>, protected by profile XX, and
    2. the number of configuration variants (post-build selectable only).
  */
  /*
    UC_E2E_00206:  During its initialization, the Receiver shall instantiate
    the structures PXXConfigType and PXXReceiverType.
    Note: PXXReceiverType is initilized in E2EXf_Init API
  */
  /*
    UC_E2E_00207  During its initialization, the Receiver shall initialize
    the PXXConfigType  with the required configured settings, for each Data.
  */
  /*******************Design ID : E2EXf_SDD_0027******************************/
  /*
    SWS_E2EXf_00119: The generated configuration object of type E2E_P05ConfigType 
    shall be initialized according to the following (one-to-one mapping):
    DataID = EndToEndTransformationISignalProps.dataID
    DataLength = EndToEndTransformationISignalProps.dataLength
    Offset = EndToEndTransformationDescription.offset
    MaxDeltaCounter = EndToEndTransformationComSpecProps.maxDeltaCounter or EndToEndTransformationDescription.maxDeltaCounter (SRS_E2E_08538)
  */
  CONST(E2E_P05ConfigType,E2EXf_DATA)LstE2EProtectConfig = 
  {
    0U,    /* offset */
    128U,   /* DataLength */
    64031U,    /* dataID */
    10U   /*  maxDeltaCounter */
  };


  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  LblDetOccured = E2EXf_DetCheck(
  buffer, bufferLength, inputBuffer, inputBufferLength,
  LusUpperHeaderBitsToShift, INPLACE_E2EXF_APP_CAN_TX_GR_MSGGR_E2E_BCAN_WPC_FD_VCRM_01_00MS_MSGGR_E2E_BCAN_WPC_FD_VCRM_01_00MS);
  if (E2EXF_FALSE == LblDetOccured)
  #endif
  {
    /*
      SWS_E2EXf_00133: If the E2E Transformer has not been correctly initialized
      (which means that E2EXf_Init() was not successfully called before),
      then all generated E2E Transformer APIs shall immediately return
      E_SAFETY_HARD_RUNTIMEERROR.
    */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
    if (E2EXF_TRUE == E2EXf_GblInitStat)
    {
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
      if (E2EXF_OUTPLACE_PRECONDITIONS) /* E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms OUTPLACE Pre conditions check */
      {
      /*
        SWS_E2EXf_00109 : If (inputBuffer != NULL && EndToEndTransformation
        Description.upperHeaderBitsToShift > 0),out-of-place
        E2EXf_<transformerId> shall copy the first upperHeaderBitsToShift
        bits from inputBuffer to buffer, and then copy the remaining part of
        inputBuffer(i.e. starting with offset upperHeaderBitsToShift)
        to parameter buffer starting with the destination offset of
        (upperHeaderBitsToShift+ BufferProperties.headerLength).
      */

        if (NULL_PTR != inputBuffer)
/* polyspace<MISRA-C:13.7:Not a defect:Justify with annotations> Condition value is invariant because it is generated from arxml  */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
          /*
            copy inputBuffer starting with the offset of
            BufferProperties.headerLength, to buffer
          */
/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
          E2EXf_Memcpy(&buffer[LusHeaderLength/E2EXF_EIGHT], inputBuffer, inputBufferLength);
        }
        else
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
        }

        /*
          SWS_E2EXf_00111:E2EXf_<transformerId> shall set *bufferLength =
          inputBufferLength + BufferProperties.headerLength.
        */
        *bufferLength = inputBufferLength + (LusHeaderLength/E2EXF_EIGHT);

        /*
          SWS_E2EXf_00139 : For PXX = 01 or 02, the functionE2EXf_<transformerId>() shall perform a check of the
          *bufferLength (after the computation of *bufferLength):
          If (*bufferLength != config->DataLength), then the function shall
          return immediately E_SAFETY_HARD_RUNTIMEERROR, i.e. without calling
          an E2E Library function.(SRS_E2E_08538)
        */

        /*
          SWS_E2EXf_00107 : The function E2EXf_<transformerId>() shall invoke
          E2E_PXXProtect(), passing to that function the appropriate Config and State
          structures (see [SWS_E2EXf_00125] and [SWS_E2EXf_00126]) that are associated
          with <transformerId>, as well as buffer and bufferLength (only for P04, P05, P06,
          P07, P11 and P22) that were updated in above requirements SWS_E2EXf_00108,
          SWS_E2EXf_00109, SWS_E2EXf_00115, SWS_E2EXf_00111.
        */
                    
        /**********Design ID : E2EXf_SDD_0057,E2EXf_SDD_0062,E2EXf_SDD_0067*******************/ 
        LucProtectRet = E2E_P05Protect(&LstE2EProtectConfig,
        &E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms, buffer, *bufferLength);
        /*
          SWS_E2EXf_00018 : In case E2E_PXXProtect() returns E2E_E_OK, then
          E2EXf_<transformerId> shall return E_OK, otherwise E2EXf_<transformerId>
          shall return E_SAFETY_HARD_RUNTIMEERROR.
        */
                   
        if (E2E_E_OK == LucProtectRet)
        {
          LucRet = E_OK;
        }
      }/*End of if (E2EXF_OUTPLACE_PRECONDITIONS)*/
    }/*End of if (E2EXF_TRUE == E2EXf_GblInitStat)*/
  }
  return(LucRet);
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

/*******************************************************************************
** Function Name        : E2EXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms                                           **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : Protects the array/buffer to be transmitted,        **
**                        using the in-place transformation.(SWS_E2EXf_00032) **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : inputBuffer, inputBufferLength                      **
**                                                                            **
** InOut parameter      : buffer                                              **
**                                                                            **
** Output Parameters    : bufferLength                                        **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : E2EXf_Init is invoked successfully.                 **
**                                                                            **
** Remarks              : Global Variable(s)  : E2EXf_GblInitStat             **
**                        Function(s) invoked : Det_ReportError(),            **
**                                              E2E_P0XProtect(),             **
**                                              E2EXf_memcpy(),               **
**                                                                            **
** Design ID            : E2EXf_SDD_0001,E2EXf_SDD_0038                       **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
/*
SWS_E2EXf_00020:The function E2EXf_<transformerId> shall be generated for
each E2E-protected data element.
*/
/* polyspace<MISRA-C:5.1:Not a defect:Justify with annotations> Function Name is following AUTOSAR Standard  */
FUNC(uint8, E2EXF_CODE)  E2EXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms(
P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
VAR(uint16, E2EXF_APPL_DATA)inputBufferLength)
{
  VAR(uint8, AUTOMATIC) LucRet = E_SAFETY_HARD_RUNTIMEERROR;
  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, E2EXF_DATA) LblDetOccured = E2EXF_FALSE;
  #endif

    /*******************Design ID : E2EXf_SDD_0037******************************/
  Std_ReturnType LucProtectRet = E2E_E_INTERR;

  /* <END-TO-END-TRANSFORMATION-DESCRIPTION>.<UPPER-HEADER-BITS-TO-SHIFT> */
  uint16 LusUpperHeaderBitsToShift = 0U;

  /* <BUFFER-PROPERTIES>.<HEADER-LENGTH> */
  uint16 LusHeaderLength = 0U;

  /*
    SWS_E2EXf_00134: The configuration options in
    EndToEndTransformationComSpecProps shall have
    precedence over the options in EndToEndTransformationDescription and
    EndToEndTransformationISignalProps.
  */
  /*
    SWS_E2EXf_00126: The E2E Transformer shall derive the required number of
    independent statically initialized configuration objects of types
    E2E_PXXConfigType and E2E_SMConfigType to perform  E2E Protection within
    the E2E Transformer, from:
    1. the number of E2E-protected data uniquely identified with
       <transformerId>, protected by profile XX, and
       <transformerId>, protected by profile XX, and
    2. the number of configuration variants (post-build selectable only).
  */
  /*
    UC_E2E_00206:  During its initialization, the Receiver shall instantiate
    the structures PXXConfigType and PXXReceiverType.
    Note: PXXReceiverType is initilized in E2EXf_Init API
  */
  /*
    UC_E2E_00207  During its initialization, the Receiver shall initialize
    the PXXConfigType  with the required configured settings, for each Data.
  */
  /*******************Design ID : E2EXf_SDD_0027******************************/
  /*
    SWS_E2EXf_00119: The generated configuration object of type E2E_P05ConfigType 
    shall be initialized according to the following (one-to-one mapping):
    DataID = EndToEndTransformationISignalProps.dataID
    DataLength = EndToEndTransformationISignalProps.dataLength
    Offset = EndToEndTransformationDescription.offset
    MaxDeltaCounter = EndToEndTransformationComSpecProps.maxDeltaCounter or EndToEndTransformationDescription.maxDeltaCounter (SRS_E2E_08538)
  */
  CONST(E2E_P05ConfigType,E2EXf_DATA)LstE2EProtectConfig = 
  {
    0U,    /* offset */
    64U,   /* DataLength */
    67172464U,    /* dataID */
    10U   /*  maxDeltaCounter */
  };


  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  LblDetOccured = E2EXf_DetCheck(
  buffer, bufferLength, inputBuffer, inputBufferLength,
  LusUpperHeaderBitsToShift, INPLACE_E2EXF_APP_CAN_TX_GR_MSGGR_E2E_LCAN_L_WPC_FD_01_00MS_MSGGR_E2E_LCAN_L_WPC_FD_01_00MS);
  if (E2EXF_FALSE == LblDetOccured)
  #endif
  {
    /*
      SWS_E2EXf_00133: If the E2E Transformer has not been correctly initialized
      (which means that E2EXf_Init() was not successfully called before),
      then all generated E2E Transformer APIs shall immediately return
      E_SAFETY_HARD_RUNTIMEERROR.
    */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
    if (E2EXF_TRUE == E2EXf_GblInitStat)
    {
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
      if (E2EXF_OUTPLACE_PRECONDITIONS) /* E2EXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms OUTPLACE Pre conditions check */
      {
      /*
        SWS_E2EXf_00109 : If (inputBuffer != NULL && EndToEndTransformation
        Description.upperHeaderBitsToShift > 0),out-of-place
        E2EXf_<transformerId> shall copy the first upperHeaderBitsToShift
        bits from inputBuffer to buffer, and then copy the remaining part of
        inputBuffer(i.e. starting with offset upperHeaderBitsToShift)
        to parameter buffer starting with the destination offset of
        (upperHeaderBitsToShift+ BufferProperties.headerLength).
      */

        if (NULL_PTR != inputBuffer)
/* polyspace<MISRA-C:13.7:Not a defect:Justify with annotations> Condition value is invariant because it is generated from arxml  */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
          /*
            copy inputBuffer starting with the offset of
            BufferProperties.headerLength, to buffer
          */
/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
          E2EXf_Memcpy(&buffer[LusHeaderLength/E2EXF_EIGHT], inputBuffer, inputBufferLength);
        }
        else
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
        }

        /*
          SWS_E2EXf_00111:E2EXf_<transformerId> shall set *bufferLength =
          inputBufferLength + BufferProperties.headerLength.
        */
        *bufferLength = inputBufferLength + (LusHeaderLength/E2EXF_EIGHT);

        /*
          SWS_E2EXf_00139 : For PXX = 01 or 02, the functionE2EXf_<transformerId>() shall perform a check of the
          *bufferLength (after the computation of *bufferLength):
          If (*bufferLength != config->DataLength), then the function shall
          return immediately E_SAFETY_HARD_RUNTIMEERROR, i.e. without calling
          an E2E Library function.(SRS_E2E_08538)
        */

        /*
          SWS_E2EXf_00107 : The function E2EXf_<transformerId>() shall invoke
          E2E_PXXProtect(), passing to that function the appropriate Config and State
          structures (see [SWS_E2EXf_00125] and [SWS_E2EXf_00126]) that are associated
          with <transformerId>, as well as buffer and bufferLength (only for P04, P05, P06,
          P07, P11 and P22) that were updated in above requirements SWS_E2EXf_00108,
          SWS_E2EXf_00109, SWS_E2EXf_00115, SWS_E2EXf_00111.
        */
                    
        /**********Design ID : E2EXf_SDD_0057,E2EXf_SDD_0062,E2EXf_SDD_0067*******************/ 
        LucProtectRet = E2E_P05Protect(&LstE2EProtectConfig,
        &E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms, buffer, *bufferLength);
        /*
          SWS_E2EXf_00018 : In case E2E_PXXProtect() returns E2E_E_OK, then
          E2EXf_<transformerId> shall return E_OK, otherwise E2EXf_<transformerId>
          shall return E_SAFETY_HARD_RUNTIMEERROR.
        */
                   
        if (E2E_E_OK == LucProtectRet)
        {
          LucRet = E_OK;
        }
      }/*End of if (E2EXF_OUTPLACE_PRECONDITIONS)*/
    }/*End of if (E2EXF_TRUE == E2EXf_GblInitStat)*/
  }
  return(LucRet);
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

/*******************************************************************************
** Function Name        : E2EXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms                                           **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : Protects the array/buffer to be transmitted,        **
**                        using the in-place transformation.(SWS_E2EXf_00032) **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : inputBuffer, inputBufferLength                      **
**                                                                            **
** InOut parameter      : buffer                                              **
**                                                                            **
** Output Parameters    : bufferLength                                        **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : E2EXf_Init is invoked successfully.                 **
**                                                                            **
** Remarks              : Global Variable(s)  : E2EXf_GblInitStat             **
**                        Function(s) invoked : Det_ReportError(),            **
**                                              E2E_P0XProtect(),             **
**                                              E2EXf_memcpy(),               **
**                                                                            **
** Design ID            : E2EXf_SDD_0001,E2EXf_SDD_0038                       **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
/*
SWS_E2EXf_00020:The function E2EXf_<transformerId> shall be generated for
each E2E-protected data element.
*/
/* polyspace<MISRA-C:5.1:Not a defect:Justify with annotations> Function Name is following AUTOSAR Standard  */
FUNC(uint8, E2EXF_CODE)  E2EXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms(
P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
VAR(uint16, E2EXF_APPL_DATA)inputBufferLength)
{
  VAR(uint8, AUTOMATIC) LucRet = E_SAFETY_HARD_RUNTIMEERROR;
  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, E2EXF_DATA) LblDetOccured = E2EXF_FALSE;
  #endif

    /*******************Design ID : E2EXf_SDD_0037******************************/
  Std_ReturnType LucProtectRet = E2E_E_INTERR;

  /* <END-TO-END-TRANSFORMATION-DESCRIPTION>.<UPPER-HEADER-BITS-TO-SHIFT> */
  uint16 LusUpperHeaderBitsToShift = 0U;

  /* <BUFFER-PROPERTIES>.<HEADER-LENGTH> */
  uint16 LusHeaderLength = 0U;

  /*
    SWS_E2EXf_00134: The configuration options in
    EndToEndTransformationComSpecProps shall have
    precedence over the options in EndToEndTransformationDescription and
    EndToEndTransformationISignalProps.
  */
  /*
    SWS_E2EXf_00126: The E2E Transformer shall derive the required number of
    independent statically initialized configuration objects of types
    E2E_PXXConfigType and E2E_SMConfigType to perform  E2E Protection within
    the E2E Transformer, from:
    1. the number of E2E-protected data uniquely identified with
       <transformerId>, protected by profile XX, and
       <transformerId>, protected by profile XX, and
    2. the number of configuration variants (post-build selectable only).
  */
  /*
    UC_E2E_00206:  During its initialization, the Receiver shall instantiate
    the structures PXXConfigType and PXXReceiverType.
    Note: PXXReceiverType is initilized in E2EXf_Init API
  */
  /*
    UC_E2E_00207  During its initialization, the Receiver shall initialize
    the PXXConfigType  with the required configured settings, for each Data.
  */
  /*******************Design ID : E2EXf_SDD_0027******************************/
  /*
    SWS_E2EXf_00119: The generated configuration object of type E2E_P05ConfigType 
    shall be initialized according to the following (one-to-one mapping):
    DataID = EndToEndTransformationISignalProps.dataID
    DataLength = EndToEndTransformationISignalProps.dataLength
    Offset = EndToEndTransformationDescription.offset
    MaxDeltaCounter = EndToEndTransformationComSpecProps.maxDeltaCounter or EndToEndTransformationDescription.maxDeltaCounter (SRS_E2E_08538)
  */
  CONST(E2E_P05ConfigType,E2EXf_DATA)LstE2EProtectConfig = 
  {
    0U,    /* offset */
    64U,   /* DataLength */
    134281328U,    /* dataID */
    10U   /*  maxDeltaCounter */
  };


  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  LblDetOccured = E2EXf_DetCheck(
  buffer, bufferLength, inputBuffer, inputBufferLength,
  LusUpperHeaderBitsToShift, INPLACE_E2EXF_APP_CAN_TX_GR_MSGGR_E2E_LCAN_L_WPC_FD_20_200MS_MSGGR_E2E_LCAN_L_WPC_FD_20_200MS);
  if (E2EXF_FALSE == LblDetOccured)
  #endif
  {
    /*
      SWS_E2EXf_00133: If the E2E Transformer has not been correctly initialized
      (which means that E2EXf_Init() was not successfully called before),
      then all generated E2E Transformer APIs shall immediately return
      E_SAFETY_HARD_RUNTIMEERROR.
    */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
    if (E2EXF_TRUE == E2EXf_GblInitStat)
    {
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
      if (E2EXF_OUTPLACE_PRECONDITIONS) /* E2EXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms OUTPLACE Pre conditions check */
      {
      /*
        SWS_E2EXf_00109 : If (inputBuffer != NULL && EndToEndTransformation
        Description.upperHeaderBitsToShift > 0),out-of-place
        E2EXf_<transformerId> shall copy the first upperHeaderBitsToShift
        bits from inputBuffer to buffer, and then copy the remaining part of
        inputBuffer(i.e. starting with offset upperHeaderBitsToShift)
        to parameter buffer starting with the destination offset of
        (upperHeaderBitsToShift+ BufferProperties.headerLength).
      */

        if (NULL_PTR != inputBuffer)
/* polyspace<MISRA-C:13.7:Not a defect:Justify with annotations> Condition value is invariant because it is generated from arxml  */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
          /*
            copy inputBuffer starting with the offset of
            BufferProperties.headerLength, to buffer
          */
/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
          E2EXf_Memcpy(&buffer[LusHeaderLength/E2EXF_EIGHT], inputBuffer, inputBufferLength);
        }
        else
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
        }

        /*
          SWS_E2EXf_00111:E2EXf_<transformerId> shall set *bufferLength =
          inputBufferLength + BufferProperties.headerLength.
        */
        *bufferLength = inputBufferLength + (LusHeaderLength/E2EXF_EIGHT);

        /*
          SWS_E2EXf_00139 : For PXX = 01 or 02, the functionE2EXf_<transformerId>() shall perform a check of the
          *bufferLength (after the computation of *bufferLength):
          If (*bufferLength != config->DataLength), then the function shall
          return immediately E_SAFETY_HARD_RUNTIMEERROR, i.e. without calling
          an E2E Library function.(SRS_E2E_08538)
        */

        /*
          SWS_E2EXf_00107 : The function E2EXf_<transformerId>() shall invoke
          E2E_PXXProtect(), passing to that function the appropriate Config and State
          structures (see [SWS_E2EXf_00125] and [SWS_E2EXf_00126]) that are associated
          with <transformerId>, as well as buffer and bufferLength (only for P04, P05, P06,
          P07, P11 and P22) that were updated in above requirements SWS_E2EXf_00108,
          SWS_E2EXf_00109, SWS_E2EXf_00115, SWS_E2EXf_00111.
        */
                    
        /**********Design ID : E2EXf_SDD_0057,E2EXf_SDD_0062,E2EXf_SDD_0067*******************/ 
        LucProtectRet = E2E_P05Protect(&LstE2EProtectConfig,
        &E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms, buffer, *bufferLength);
        /*
          SWS_E2EXf_00018 : In case E2E_PXXProtect() returns E2E_E_OK, then
          E2EXf_<transformerId> shall return E_OK, otherwise E2EXf_<transformerId>
          shall return E_SAFETY_HARD_RUNTIMEERROR.
        */
                   
        if (E2E_E_OK == LucProtectRet)
        {
          LucRet = E_OK;
        }
      }/*End of if (E2EXF_OUTPLACE_PRECONDITIONS)*/
    }/*End of if (E2EXF_TRUE == E2EXf_GblInitStat)*/
  }
  return(LucRet);
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"

/*******************************************************************************
** Function Name        : E2EXf_Inv_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms **
**                                                                            **
** Service ID           : 0x04                                                **
**                                                                            **
** Description          : Checks the received data. If the data can be used   **
**                        by the caller, then the function returns E_OK.      **
**                        (SWS_E2EXf_00034)                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : inputBuffer, inputBufferLength                      **
**                                                                            **
** InOut parameter      : buffer                                              **
**                                                                            **
** Output Parameters    : bufferLength                                        **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : E2EXf_Init is invoked successfully.                 **
**                                                                            **
** Remarks              : Global Variable(s)  : E2EXf_GblInitStat             **
**                        Function(s) invoked : Det_ReportError(),            **
**                                              E2E_PXXCheck(),               **
**                                              E2E_PXXMapStatusToSM(),       **
**                                              E2E_SMCheck()                 **
**                                                                            **
** Design ID            : E2EXf_SDD_0002,E2EXf_SDD_0039,E2EXf_SDD_0040,       **
**                                                                            **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
/*
SWS_E2EXf_00025: The function E2EXf_Inv_<transformerId> shall be generated for
each E2E-protected data element (<transformerId>).
*/
/* polyspace<MISRA-C:5.1:Not a defect:Justify with annotations> Function Name is following AUTOSAR Standard  */
FUNC(uint8, E2EXF_CODE) E2EXf_Inv_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms(
P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
VAR(uint16, E2EXF_APPL_DATA)inputBufferLength)
{
  VAR(uint8, AUTOMATIC) LucRet = E_SAFETY_HARD_RUNTIMEERROR;

  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, E2EXF_DATA) LblDetOccured = E2EXF_FALSE;
  #endif


  /* <END-TO-END-TRANSFORMATION-DESCRIPTION>.<UPPER-HEADER-BITS-TO-SHIFT> */
  uint16 LusUpperHeaderBitsToShift = 0U;
                  
  /* <BUFFER-PROPERTIES>.<HEADER-LENGTH> */
  uint16 LusHeaderLength = 0U;
  /*******************Design ID : E2EXf_SDD_0037******************************/
  Std_ReturnType LucSMCheckRet = E2E_E_INTERR;
  /*******************Design ID : E2EXf_SDD_0037******************************/
  Std_ReturnType LucCheckReturn = E2E_E_INTERR;
  /*******************Design ID : E2EXf_SDD_0033******************************/
  E2E_PCheckStatusType LucCheckStatus = E2E_P_ERROR;
  /*
    SWS_E2EXf_00134: The configuration options in
    EndToEndTransformationComSpecProps shall have
    precedence over the options in EndToEndTransformationDescription and
    EndToEndTransformationISignalProps.
  */
  /*
    SWS_E2EXf_00126: The E2E Transformer shall derive the required number of
    independent statically initialized configuration objects of types
    E2E_PXXConfigType and E2E_SMConfigType to perform  E2E Protection within
    the E2E Transformer, from:
    1. the number of E2E-protected data uniquely identified with
    <transformerId>, protected by profile XX, and
    <transformerId>, protected by profile XX, and
    2. the number of configuration variants (post-build selectable only).
  */
  /*
    UC_E2E_00206:  During its initialization, the Receiver shall instantiate
    the structures PXXConfigType and PXXReceiverType.
    Note: PXXReceiverType is initilized in E2EXf_Init API
  */
  /*
    UC_E2E_00207  During its initialization, the Receiver shall initialize
    the PXXConfigType  with the required configured settings, for each Data.
  */
  /*
    Case 5: 
    SWS_E2EXf_00119: The generated configuration object of type E2E_P05ConfigType 
    shall be initialized according to the following (one-to-one mapping):
    DataID = EndToEndTransformationISignalProps.dataID
    DataLength = EndToEndTransformationISignalProps.dataLength
    Offset = EndToEndTransformationDescription.offset
    MaxDeltaCounter = EndToEndTransformationComSpecProps.maxDeltaCounter or EndToEndTransformationDescription.maxDeltaCounter (SRS_E2E_08538)
  */
  CONST (E2E_P05ConfigType,E2EXf_DATA) LstE2ECheckConfig = 
  {
    0U,    /* offset */
    256U,   /* DataLength */
    64233U,    /* dataID */
    10U   /*  MaxDeltaCounter */
  };

  /*
    SWS_E2EXf_00120: The generated configuration object of type E2E_P06ConfigType
    shall be initialized according to the following (one-to-one mapping):
    DataID = EndToEndTransformationISignalProps.dataID
    MinDataLength = EndToEndTransformationISignalProps.minDataLength
    MaxDataLength = EndToEndTransformationISignalProps.maxDataLength
    Offset = EndToEndTransformationDescription.offset
    MaxDeltaCounter = EndToEndTransformationComSpecProps.maxDeltaCounter or EndToEndTransformationDescription.maxDeltaCounter (SRS_E2E_08538)
  */

  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  LblDetOccured = E2EXf_Inv_DetCheck(
  buffer, bufferLength, inputBuffer, inputBufferLength,
  LusUpperHeaderBitsToShift, LusHeaderLength,
  INPLACE_E2EXF_INV_COM_COMISIGNALGROUP_MSGGR_E2E_LCAN_PDC_FD_15_300MS);
  if (E2EXF_FALSE == LblDetOccured)
  #endif
  {
    /*
      SWS_E2EXf_00133: If the E2E Transformer has not been correctly initialized
      (which means that E2EXf_Init() was not successfully called before),
      then all generated E2E Transformer APIs shall immediately return
      E_SAFETY_HARD_RUNTIMEERROR.
    */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
    if (E2EXF_TRUE == E2EXf_GblInitStat)
    {
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
      if (E2EXF_INV_OUTPLACE_PRECONDITIONS) /* E2EXf_Inv_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms OUTPLACE Pre condition checks */
      {

        /*
          SWS_E2EXf_00140: For PXX = 01 or 02 (i.e. for profile 1 and 2),
          the out-of-place function E2EXf_Inv_<transformerId> shall
          1. if (inputBuffer == NULL and inputBufferLength == 0), then
          - variable NewDataAvailable of state object of type
          E2E_PXXCheckStateType (see [SWS_E2EXf_00125]) associated with
          <transformerId> shall be set to FALSE
          2. else if (inputBufferLength == config->DataLength), then
          - variable NewDataAvailable of state object of type
          E2E_PXXCheckState Type (see [SWS_E2EXf_00125]) associated with
          <transformerId> shall be set to TRUE.
          else return E_SAFETY_HARD_RUNTIMEERROR.
        */

        /*
          SWS_E2EXf_00154: If configuration option
          EndToEndTransformationComSpecProps.disableEndToEndCheck
          is set for a given <transformerId>, then E2E Transformer shall skip
          the invocation of the  E2E Library – it shall only perform buffer
          processing (e.g. copying from inputBuffer to buffer).
        */
        
        /*
          SWS_E2EXf_00123: For PXX = 01 or 02 (i.e. for profiles 1 and 2),
          the out-of-place function E2EXf_Inv_<transformerId> shall invoke
          E2E_PXXCheck(), passing to that function:
          - config,
          - state,
          - pointer to data
            pointer to data: if (inputBuffer == NULL and
            inputBufferLength == 0), then it shall pass a pointer to a 1-byte
            static variable of E2E transformer, otherwise it shall pass buffer
            (out-of-place) respectively inputBuffer (in-place).
            Please refer RfC  70069
        */

        /* 
          SWS_E2EXf_00104:
          For PXX = 04, 05, 06, 07, 11, 22: the function
          E2EXf_Inv_<transformerId> shall invoke E2E_PXXCheck(), passing to that function:
          - config,
          - state,
          - data length: inputBufferLength
          pointer to data: inputBuffer (out-of-place version) or buffer (in-place
          version).
        */
        /*************Design ID : E2EXf_SDD_0054,E2EXf_SDD_0059,E2EXf_SDD_0064*****************/ 
        LucCheckReturn = E2E_P05Check(&LstE2ECheckConfig,
        &E2EXf_GddCS_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms,inputBuffer, inputBufferLength);

        /*
          SWS_E2EXf_00029: The function E2EXf_Inv_<transformerId> shall
          invoke E2E_MapPXXToSM(), passing to that function the return value
          of E2E_PXXCheck and the profile’s check Status
          (variable Status of state object of type E2E_PXXCheckStateType,
          see [SWS_E2EXf_00125]),  to obtain the profile-independent check
          status. For P1/P2 mapping functions, there is an additional call
          parameter profileBehavior:
          - if configuration parameter profileBehavior is R4_2, then
            E2E_MapPXXToSM() shall be invoked with the call parameter
            profileBehavior = 1
          - if configuration parameter profileBehavior is PRE_R4_2, then
            E2E_MapPXXToSM() shall be invoked with call parameter
            profileBehavior = 0
        */
        /*******************Design ID : E2EXf_SDD_0056,E2EXf_SDD_0061,E2EXf_SDD_0066******************************/ 
        LucCheckStatus = E2E_P05MapStatusToSM(LucCheckReturn,
        E2EXf_GddCS_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms.Status);
        /*
          SWS_E2EXf_00028: The function E2EXf_Inv_<transformerId> shall
          invoke the E2E_SMCheck() function, passing to that function the
          configuration object of type E2E_SMConfigType
          (see [SWS_E2EXf_00126] and [SWS_E2EXf_00088]) and
          state object of type E2E_SMCheckStateType (see [SWS_E2EXf_00125])
          that are associated with <transformerId>, plus the
          profile-independent check status that was computed by
          E2E_MapPXXToSM() in SWS_E2EXf_00029.
        */

        /*******************Design ID : E2EXf_SDD_0069******************************/  
        LucSMCheckRet = E2E_SMCheck(LucCheckStatus,
        &E2EXf_GddSMCCP_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms,
        &E2EXf_GddSMCheckStatePtr_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms);
        
        /*
          SWS_E2EXf_00027: If E2E_SMCheck() returns E2E_E_OK, then:
          - the high nibble of the return of the function
            E2EXf_Inv_<transformerId> shall  be set to the low nibble of the
            state of the state machine (member SMState of object of type
            E2E_SMStateType that is associated with <transformerId>,
            see [SWS_E2EXf_00125]).
          - The low nibble of the return of the function
            E2EXf_Inv_<transformerId> shall  be set to the low nibble of the
            profile-independent check status of type E2E_PCheckStatusType.
          - If E2E_SMCheck() does not return E2E_E_OK, the return value
            shall  be E_SAFETY_SOFT_RUNTIMEERROR.
        */

        if (E2E_E_OK == LucSMCheckRet)
        {
          LucRet = (uint8) E2EXF_INV_RET_VALUE(E2EXf_GddSMCheckStatePtr_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms.SMState, LucCheckStatus);
        }
        else
        {
          LucRet = E_SAFETY_SOFT_RUNTIMEERROR;
        }
        /*
          SWS_E2EXf_00113: If (inputBuffer != NULL &&
          EndToEndTransformationDescription.upperHeaderBitsToShift > 0),
          out-of-place E2EXf_Inv_<transformerId> shall copy the first
          upperHeaderBitsToShift bits from inputBuffer to buffer, and then
          copy the remaining part of inputBuffer skipping E2E header
          (i.e. starting with offset
          upperHeaderBitsToShift+BufferProperties.headerLength)
          to parameter buffer starting with the destination offset of
          (upperHeaderBitsToShift).
        */

        if (NULL_PTR != inputBuffer)
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
          /*
            copy inputBuffer starting with the offset of
            BufferProperties.headerLength, to buffer
          */
/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
          E2EXf_Memcpy(buffer,&inputBuffer[LusHeaderLength/E2EXF_EIGHT],
          inputBufferLength -(LusHeaderLength/E2EXF_EIGHT));
        }
        else
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
        {
        }
        if (E2EXF_ZERO == inputBufferLength)
        {
          *bufferLength = 0U;
        }
        else
        {
          *bufferLength = inputBufferLength -
          (LusHeaderLength/E2EXF_EIGHT);
        }
      }/*End of if (E2EXF_INV_OUTPLACE_PRECONDITIONS)*/
    }/*End of if (E2EXF_TRUE == E2EXf_GblInitStat)*/
  }

  /*
    SWS_Xfrm_00051  If a transformer returns a hard error, it shall leave the
    output buffer unchanged (SRS_Xfrm_00004)
  */
  return(LucRet);
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
/*******************************************************************************
** Function Name        : E2EXf_Inv_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms **
**                                                                            **
** Service ID           : 0x04                                                **
**                                                                            **
** Description          : Checks the received data. If the data can be used   **
**                        by the caller, then the function returns E_OK.      **
**                        (SWS_E2EXf_00034)                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : inputBuffer, inputBufferLength                      **
**                                                                            **
** InOut parameter      : buffer                                              **
**                                                                            **
** Output Parameters    : bufferLength                                        **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : E2EXf_Init is invoked successfully.                 **
**                                                                            **
** Remarks              : Global Variable(s)  : E2EXf_GblInitStat             **
**                        Function(s) invoked : Det_ReportError(),            **
**                                              E2E_PXXCheck(),               **
**                                              E2E_PXXMapStatusToSM(),       **
**                                              E2E_SMCheck()                 **
**                                                                            **
** Design ID            : E2EXf_SDD_0002,E2EXf_SDD_0039,E2EXf_SDD_0040,       **
**                                                                            **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
/*
SWS_E2EXf_00025: The function E2EXf_Inv_<transformerId> shall be generated for
each E2E-protected data element (<transformerId>).
*/
/* polyspace<MISRA-C:5.1:Not a defect:Justify with annotations> Function Name is following AUTOSAR Standard  */
FUNC(uint8, E2EXF_CODE) E2EXf_Inv_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms(
P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
VAR(uint16, E2EXF_APPL_DATA)inputBufferLength)
{
  VAR(uint8, AUTOMATIC) LucRet = E_SAFETY_HARD_RUNTIMEERROR;

  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, E2EXF_DATA) LblDetOccured = E2EXF_FALSE;
  #endif


  /* <END-TO-END-TRANSFORMATION-DESCRIPTION>.<UPPER-HEADER-BITS-TO-SHIFT> */
  uint16 LusUpperHeaderBitsToShift = 0U;
                  
  /* <BUFFER-PROPERTIES>.<HEADER-LENGTH> */
  uint16 LusHeaderLength = 0U;
  /*******************Design ID : E2EXf_SDD_0037******************************/
  Std_ReturnType LucSMCheckRet = E2E_E_INTERR;
  /*******************Design ID : E2EXf_SDD_0037******************************/
  Std_ReturnType LucCheckReturn = E2E_E_INTERR;
  /*******************Design ID : E2EXf_SDD_0033******************************/
  E2E_PCheckStatusType LucCheckStatus = E2E_P_ERROR;
  /*
    SWS_E2EXf_00134: The configuration options in
    EndToEndTransformationComSpecProps shall have
    precedence over the options in EndToEndTransformationDescription and
    EndToEndTransformationISignalProps.
  */
  /*
    SWS_E2EXf_00126: The E2E Transformer shall derive the required number of
    independent statically initialized configuration objects of types
    E2E_PXXConfigType and E2E_SMConfigType to perform  E2E Protection within
    the E2E Transformer, from:
    1. the number of E2E-protected data uniquely identified with
    <transformerId>, protected by profile XX, and
    <transformerId>, protected by profile XX, and
    2. the number of configuration variants (post-build selectable only).
  */
  /*
    UC_E2E_00206:  During its initialization, the Receiver shall instantiate
    the structures PXXConfigType and PXXReceiverType.
    Note: PXXReceiverType is initilized in E2EXf_Init API
  */
  /*
    UC_E2E_00207  During its initialization, the Receiver shall initialize
    the PXXConfigType  with the required configured settings, for each Data.
  */
  /*
    Case 5: 
    SWS_E2EXf_00119: The generated configuration object of type E2E_P05ConfigType 
    shall be initialized according to the following (one-to-one mapping):
    DataID = EndToEndTransformationISignalProps.dataID
    DataLength = EndToEndTransformationISignalProps.dataLength
    Offset = EndToEndTransformationDescription.offset
    MaxDeltaCounter = EndToEndTransformationComSpecProps.maxDeltaCounter or EndToEndTransformationDescription.maxDeltaCounter (SRS_E2E_08538)
  */
  CONST (E2E_P05ConfigType,E2EXf_DATA) LstE2ECheckConfig = 
  {
    0U,    /* offset */
    256U,   /* DataLength */
    64233U,    /* dataID */
    10U   /*  MaxDeltaCounter */
  };

  /*
    SWS_E2EXf_00120: The generated configuration object of type E2E_P06ConfigType
    shall be initialized according to the following (one-to-one mapping):
    DataID = EndToEndTransformationISignalProps.dataID
    MinDataLength = EndToEndTransformationISignalProps.minDataLength
    MaxDataLength = EndToEndTransformationISignalProps.maxDataLength
    Offset = EndToEndTransformationDescription.offset
    MaxDeltaCounter = EndToEndTransformationComSpecProps.maxDeltaCounter or EndToEndTransformationDescription.maxDeltaCounter (SRS_E2E_08538)
  */

  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  LblDetOccured = E2EXf_Inv_DetCheck(
  buffer, bufferLength, inputBuffer, inputBufferLength,
  LusUpperHeaderBitsToShift, LusHeaderLength,
  INPLACE_E2EXF_INV_APP_CAN_RX_GR_MSGGR_E2E_BCAN_PDC_FD_15_300MS_MSGGR_E2E_BCAN_PDC_FD_15_300MS);
  if (E2EXF_FALSE == LblDetOccured)
  #endif
  {
    /*
      SWS_E2EXf_00133: If the E2E Transformer has not been correctly initialized
      (which means that E2EXf_Init() was not successfully called before),
      then all generated E2E Transformer APIs shall immediately return
      E_SAFETY_HARD_RUNTIMEERROR.
    */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
    if (E2EXF_TRUE == E2EXf_GblInitStat)
    {
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
      if (E2EXF_INV_OUTPLACE_PRECONDITIONS) /* E2EXf_Inv_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms OUTPLACE Pre condition checks */
      {

        /*
          SWS_E2EXf_00140: For PXX = 01 or 02 (i.e. for profile 1 and 2),
          the out-of-place function E2EXf_Inv_<transformerId> shall
          1. if (inputBuffer == NULL and inputBufferLength == 0), then
          - variable NewDataAvailable of state object of type
          E2E_PXXCheckStateType (see [SWS_E2EXf_00125]) associated with
          <transformerId> shall be set to FALSE
          2. else if (inputBufferLength == config->DataLength), then
          - variable NewDataAvailable of state object of type
          E2E_PXXCheckState Type (see [SWS_E2EXf_00125]) associated with
          <transformerId> shall be set to TRUE.
          else return E_SAFETY_HARD_RUNTIMEERROR.
        */

        /*
          SWS_E2EXf_00154: If configuration option
          EndToEndTransformationComSpecProps.disableEndToEndCheck
          is set for a given <transformerId>, then E2E Transformer shall skip
          the invocation of the  E2E Library – it shall only perform buffer
          processing (e.g. copying from inputBuffer to buffer).
        */
        
        /*
          SWS_E2EXf_00123: For PXX = 01 or 02 (i.e. for profiles 1 and 2),
          the out-of-place function E2EXf_Inv_<transformerId> shall invoke
          E2E_PXXCheck(), passing to that function:
          - config,
          - state,
          - pointer to data
            pointer to data: if (inputBuffer == NULL and
            inputBufferLength == 0), then it shall pass a pointer to a 1-byte
            static variable of E2E transformer, otherwise it shall pass buffer
            (out-of-place) respectively inputBuffer (in-place).
            Please refer RfC  70069
        */

        /* 
          SWS_E2EXf_00104:
          For PXX = 04, 05, 06, 07, 11, 22: the function
          E2EXf_Inv_<transformerId> shall invoke E2E_PXXCheck(), passing to that function:
          - config,
          - state,
          - data length: inputBufferLength
          pointer to data: inputBuffer (out-of-place version) or buffer (in-place
          version).
        */
        /*************Design ID : E2EXf_SDD_0054,E2EXf_SDD_0059,E2EXf_SDD_0064*****************/ 
        LucCheckReturn = E2E_P05Check(&LstE2ECheckConfig,
        &E2EXf_GddCS_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms,inputBuffer, inputBufferLength);

        /*
          SWS_E2EXf_00029: The function E2EXf_Inv_<transformerId> shall
          invoke E2E_MapPXXToSM(), passing to that function the return value
          of E2E_PXXCheck and the profile’s check Status
          (variable Status of state object of type E2E_PXXCheckStateType,
          see [SWS_E2EXf_00125]),  to obtain the profile-independent check
          status. For P1/P2 mapping functions, there is an additional call
          parameter profileBehavior:
          - if configuration parameter profileBehavior is R4_2, then
            E2E_MapPXXToSM() shall be invoked with the call parameter
            profileBehavior = 1
          - if configuration parameter profileBehavior is PRE_R4_2, then
            E2E_MapPXXToSM() shall be invoked with call parameter
            profileBehavior = 0
        */
        /*******************Design ID : E2EXf_SDD_0056,E2EXf_SDD_0061,E2EXf_SDD_0066******************************/ 
        LucCheckStatus = E2E_P05MapStatusToSM(LucCheckReturn,
        E2EXf_GddCS_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms.Status);
        /*
          SWS_E2EXf_00028: The function E2EXf_Inv_<transformerId> shall
          invoke the E2E_SMCheck() function, passing to that function the
          configuration object of type E2E_SMConfigType
          (see [SWS_E2EXf_00126] and [SWS_E2EXf_00088]) and
          state object of type E2E_SMCheckStateType (see [SWS_E2EXf_00125])
          that are associated with <transformerId>, plus the
          profile-independent check status that was computed by
          E2E_MapPXXToSM() in SWS_E2EXf_00029.
        */

        /*******************Design ID : E2EXf_SDD_0069******************************/  
        LucSMCheckRet = E2E_SMCheck(LucCheckStatus,
        &E2EXf_GddSMCCP_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms,
        &E2EXf_GddSMCheckStatePtr_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms);
        
        /*
          SWS_E2EXf_00027: If E2E_SMCheck() returns E2E_E_OK, then:
          - the high nibble of the return of the function
            E2EXf_Inv_<transformerId> shall  be set to the low nibble of the
            state of the state machine (member SMState of object of type
            E2E_SMStateType that is associated with <transformerId>,
            see [SWS_E2EXf_00125]).
          - The low nibble of the return of the function
            E2EXf_Inv_<transformerId> shall  be set to the low nibble of the
            profile-independent check status of type E2E_PCheckStatusType.
          - If E2E_SMCheck() does not return E2E_E_OK, the return value
            shall  be E_SAFETY_SOFT_RUNTIMEERROR.
        */

        if (E2E_E_OK == LucSMCheckRet)
        {
          LucRet = (uint8) E2EXF_INV_RET_VALUE(E2EXf_GddSMCheckStatePtr_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms.SMState, LucCheckStatus);
        }
        else
        {
          LucRet = E_SAFETY_SOFT_RUNTIMEERROR;
        }
        /*
          SWS_E2EXf_00113: If (inputBuffer != NULL &&
          EndToEndTransformationDescription.upperHeaderBitsToShift > 0),
          out-of-place E2EXf_Inv_<transformerId> shall copy the first
          upperHeaderBitsToShift bits from inputBuffer to buffer, and then
          copy the remaining part of inputBuffer skipping E2E header
          (i.e. starting with offset
          upperHeaderBitsToShift+BufferProperties.headerLength)
          to parameter buffer starting with the destination offset of
          (upperHeaderBitsToShift).
        */

        if (NULL_PTR != inputBuffer)
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
          /*
            copy inputBuffer starting with the offset of
            BufferProperties.headerLength, to buffer
          */
/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
          E2EXf_Memcpy(buffer,&inputBuffer[LusHeaderLength/E2EXF_EIGHT],
          inputBufferLength -(LusHeaderLength/E2EXF_EIGHT));
        }
        else
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
        {
        }
        if (E2EXF_ZERO == inputBufferLength)
        {
          *bufferLength = 0U;
        }
        else
        {
          *bufferLength = inputBufferLength -
          (LusHeaderLength/E2EXF_EIGHT);
        }
      }/*End of if (E2EXF_INV_OUTPLACE_PRECONDITIONS)*/
    }/*End of if (E2EXF_TRUE == E2EXf_GblInitStat)*/
  }

  /*
    SWS_Xfrm_00051  If a transformer returns a hard error, it shall leave the
    output buffer unchanged (SRS_Xfrm_00004)
  */
  return(LucRet);
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
/*******************************************************************************
** Function Name        : E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC2_FD_01_200ms_MsgGr_E2E_BCAN_WPC2_FD_01_200ms                                           **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : Protects the array/buffer to be transmitted,        **
**                        using the in-place transformation.(SWS_E2EXf_00032) **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : inputBuffer, inputBufferLength                      **
**                                                                            **
** InOut parameter      : buffer                                              **
**                                                                            **
** Output Parameters    : bufferLength                                        **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : E2EXf_Init is invoked successfully.                 **
**                                                                            **
** Remarks              : Global Variable(s)  : E2EXf_GblInitStat             **
**                        Function(s) invoked : Det_ReportError(),            **
**                                              E2E_P0XProtect(),             **
**                                              E2EXf_memcpy(),               **
**                                                                            **
** Design ID            : E2EXf_SDD_0001,E2EXf_SDD_0038                       **
*******************************************************************************/
#define E2EXF_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"
/*
SWS_E2EXf_00020:The function E2EXf_<transformerId> shall be generated for
each E2E-protected data element.
*/
/* polyspace<MISRA-C:5.1:Not a defect:Justify with annotations> Function Name is following AUTOSAR Standard  */
FUNC(uint8, E2EXF_CODE)  E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC2_FD_01_200ms_MsgGr_E2E_BCAN_WPC2_FD_01_200ms(
P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
VAR(uint16, E2EXF_APPL_DATA)inputBufferLength)
{
  VAR(uint8, AUTOMATIC) LucRet = E_SAFETY_HARD_RUNTIMEERROR;
  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, E2EXF_DATA) LblDetOccured = E2EXF_FALSE;
  #endif

    /*******************Design ID : E2EXf_SDD_0037******************************/
  Std_ReturnType LucProtectRet = E2E_E_INTERR;

  /* <END-TO-END-TRANSFORMATION-DESCRIPTION>.<UPPER-HEADER-BITS-TO-SHIFT> */
  uint16 LusUpperHeaderBitsToShift = 0U;

  /* <BUFFER-PROPERTIES>.<HEADER-LENGTH> */
  uint16 LusHeaderLength = 0U;

  /*
    SWS_E2EXf_00134: The configuration options in
    EndToEndTransformationComSpecProps shall have
    precedence over the options in EndToEndTransformationDescription and
    EndToEndTransformationISignalProps.
  */
  /*
    SWS_E2EXf_00126: The E2E Transformer shall derive the required number of
    independent statically initialized configuration objects of types
    E2E_PXXConfigType and E2E_SMConfigType to perform  E2E Protection within
    the E2E Transformer, from:
    1. the number of E2E-protected data uniquely identified with
       <transformerId>, protected by profile XX, and
       <transformerId>, protected by profile XX, and
    2. the number of configuration variants (post-build selectable only).
  */
  /*
    UC_E2E_00206:  During its initialization, the Receiver shall instantiate
    the structures PXXConfigType and PXXReceiverType.
    Note: PXXReceiverType is initilized in E2EXf_Init API
  */
  /*
    UC_E2E_00207  During its initialization, the Receiver shall initialize
    the PXXConfigType  with the required configured settings, for each Data.
  */
  /*******************Design ID : E2EXf_SDD_0027******************************/
  /*
    SWS_E2EXf_00119: The generated configuration object of type E2E_P05ConfigType 
    shall be initialized according to the following (one-to-one mapping):
    DataID = EndToEndTransformationISignalProps.dataID
    DataLength = EndToEndTransformationISignalProps.dataLength
    Offset = EndToEndTransformationDescription.offset
    MaxDeltaCounter = EndToEndTransformationComSpecProps.maxDeltaCounter or EndToEndTransformationDescription.maxDeltaCounter (SRS_E2E_08538)
  */
  CONST(E2E_P05ConfigType,E2EXf_DATA)LstE2EProtectConfig = 
  {
    0U,    /* offset */
    128U,   /* DataLength */
    64402U,    /* dataID */
    10U   /*  maxDeltaCounter */
  };


  #if (E2EXF_DEV_ERROR_DETECT == STD_ON)
  LblDetOccured = E2EXf_DetCheck(
  buffer, bufferLength, inputBuffer, inputBufferLength,
  LusUpperHeaderBitsToShift, INPLACE_E2EXF_APP_CAN_TX_GR_MSGGR_E2E_BCAN_WPC2_FD_01_200MS_MSGGR_E2E_BCAN_WPC2_FD_01_200MS);
  if (E2EXF_FALSE == LblDetOccured)
  #endif
  {
    /*
      SWS_E2EXf_00133: If the E2E Transformer has not been correctly initialized
      (which means that E2EXf_Init() was not successfully called before),
      then all generated E2E Transformer APIs shall immediately return
      E_SAFETY_HARD_RUNTIMEERROR.
    */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
    if (E2EXF_TRUE == E2EXf_GblInitStat)
    {
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
      if (E2EXF_OUTPLACE_PRECONDITIONS) /* E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC2_FD_01_200ms_MsgGr_E2E_BCAN_WPC2_FD_01_200ms OUTPLACE Pre conditions check */
      {
      /*
        SWS_E2EXf_00109 : If (inputBuffer != NULL && EndToEndTransformation
        Description.upperHeaderBitsToShift > 0),out-of-place
        E2EXf_<transformerId> shall copy the first upperHeaderBitsToShift
        bits from inputBuffer to buffer, and then copy the remaining part of
        inputBuffer(i.e. starting with offset upperHeaderBitsToShift)
        to parameter buffer starting with the destination offset of
        (upperHeaderBitsToShift+ BufferProperties.headerLength).
      */

        if (NULL_PTR != inputBuffer)
/* polyspace<MISRA-C:13.7:Not a defect:Justify with annotations> Condition value is invariant because it is generated from arxml  */
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
          /*
            copy inputBuffer starting with the offset of
            BufferProperties.headerLength, to buffer
          */
/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
          E2EXf_Memcpy(&buffer[LusHeaderLength/E2EXF_EIGHT], inputBuffer, inputBufferLength);
        }
        else
/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Condition value is generated from arxml  */
        {
        }

        /*
          SWS_E2EXf_00111:E2EXf_<transformerId> shall set *bufferLength =
          inputBufferLength + BufferProperties.headerLength.
        */
        *bufferLength = inputBufferLength + (LusHeaderLength/E2EXF_EIGHT);

        /*
          SWS_E2EXf_00139 : For PXX = 01 or 02, the functionE2EXf_<transformerId>() shall perform a check of the
          *bufferLength (after the computation of *bufferLength):
          If (*bufferLength != config->DataLength), then the function shall
          return immediately E_SAFETY_HARD_RUNTIMEERROR, i.e. without calling
          an E2E Library function.(SRS_E2E_08538)
        */

        /*
          SWS_E2EXf_00107 : The function E2EXf_<transformerId>() shall invoke
          E2E_PXXProtect(), passing to that function the appropriate Config and State
          structures (see [SWS_E2EXf_00125] and [SWS_E2EXf_00126]) that are associated
          with <transformerId>, as well as buffer and bufferLength (only for P04, P05, P06,
          P07, P11 and P22) that were updated in above requirements SWS_E2EXf_00108,
          SWS_E2EXf_00109, SWS_E2EXf_00115, SWS_E2EXf_00111.
        */
                    
        /**********Design ID : E2EXf_SDD_0057,E2EXf_SDD_0062,E2EXf_SDD_0067*******************/ 
        LucProtectRet = E2E_P05Protect(&LstE2EProtectConfig,
        &E2EXf_GddPS_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC2_FD_01_200ms_MsgGr_E2E_BCAN_WPC2_FD_01_200ms, buffer, *bufferLength);
        /*
          SWS_E2EXf_00018 : In case E2E_PXXProtect() returns E2E_E_OK, then
          E2EXf_<transformerId> shall return E_OK, otherwise E2EXf_<transformerId>
          shall return E_SAFETY_HARD_RUNTIMEERROR.
        */
                   
        if (E2E_E_OK == LucProtectRet)
        {
          LucRet = E_OK;
        }
      }/*End of if (E2EXF_OUTPLACE_PRECONDITIONS)*/
    }/*End of if (E2EXF_TRUE == E2EXf_GblInitStat)*/
  }
  return(LucRet);
}
#define E2EXF_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "E2EXf_MemMap.h"


/*******************************************************************************
**                          Initialization Structure                          **
*******************************************************************************/

/*******************************************************************************
**                                End of File                                 **
*******************************************************************************/
