#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/** \brief AUTOSAR Dio DIO Driver
 **
 ** This file defines the common type definition of Dio driver.
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

/*==================[inclusions]=============================================*/
#include <Std_Types.h>          /* AUTOSAR standard types */
#include <Dio_Types_Reg.h>      /* Dio register types */
#include <Dio_Cfg.h>            /* include generated configuration
                                   with all symbolic names */

/*==================[macros]=================================================*/
/** \brief DIO_FALSE for boolean operations */
#define DIO_FALSE                                           0U
/** \brief DIO_TRUE for boolean operations */
#define DIO_TRUE                                            1U

/*------------------[AUTOSAR development error tracing]----------------------*/

#if (defined DIO_E_PARAM_INVALID_CHANNEL_ID) /* to prevent double declaration */
#error DIO_E_PARAM_INVALID_CHANNEL_ID already defined
#endif /* if (defined DIO_E_PARAM_INVALID_CHANNEL_ID) */

/** \brief Definition of the error code for an invalid channel Id */
#define DIO_E_PARAM_INVALID_CHANNEL_ID 10U

#if (defined DIO_E_PARAM_INVALID_LEVEL_VALUE) /* to prevent double declaration */
#error DIO_E_PARAM_INVALID_LEVEL_VALUE already defined
#endif /* if (defined DIO_E_PARAM_INVALID_LEVEL_VALUE) */

/** \brief Level value neither 0 nor 1 */
#define DIO_E_PARAM_INVALID_LEVEL_VALUE 11U

#if (defined DIO_E_PARAM_CONFIG) /* to prevent double declaration */
#error DIO_E_PARAM_CONFIG already defined
#endif /* if (defined DIO_E_PARAM_CONFIG) */

/** \brief Dio_Init called with a null pointer as parameter */
#define DIO_E_PARAM_CONFIG 16U

#if (defined DIO_E_PARAM_INVALID_PORT_ID) /* to prevent double declaration */
#error DIO_E_PARAM_INVALID_PORT_ID already defined
#endif /* if (defined DIO_E_PARAM_INVALID_PORT_ID) */

/** \brief Definition of the error code for an invalid port Id */
#define DIO_E_PARAM_INVALID_PORT_ID 20U

#if (defined DIO_E_PARAM_INVALID_GROUP) /* to prevent double declaration */
#error DIO_E_PARAM_INVALID_GROUP already defined
#endif /* if (defined DIO_E_PARAM_INVALID_GROUP) */

/** \brief Definition of the error code for an invalid group Id */
#define DIO_E_PARAM_INVALID_GROUP 31U

#if (defined DIO_E_PARAM_POINTER) /* to prevent double declaration */
#error DIO_E_PARAM_POINTER already defined
#endif /* if (defined DIO_E_PARAM_POINTER) */

/** \brief Definition of the service Id of the write channel group service */
#define DIO_E_PARAM_POINTER 32U



#if (defined DIO_API_READ_CHANNEL) /* to prevent double declaration */
#error DIO_API_READ_CHANNEL already defined
#endif /* if (defined DIO_API_READ_CHANNEL) */

/** \brief Definition of the service Id of the read channel service */
#define DIO_API_READ_CHANNEL 0U

#if (defined DIO_API_WRITE_CHANNEL) /* to prevent double declaration */
#error DIO_API_WRITE_CHANNEL already defined
#endif /* if (defined DIO_API_WRITE_CHANNEL) */

/** \brief Definition of the service Id of the write channel service */
#define DIO_API_WRITE_CHANNEL 1U

#if (defined DIO_API_READ_PORT) /* to prevent double declaration */
#error DIO_API_READ_PORT already defined
#endif /* if (defined DIO_API_READ_PORT) */

/** \brief Definition of the service Id of the read port service */
#define DIO_API_READ_PORT 2U

#if (defined DIO_API_WRITE_PORT) /* to prevent double declaration */
#error DIO_API_WRITE_PORT already defined
#endif /* if (defined DIO_API_WRITE_PORT) */

/** \brief Definition of the service Id of the write port service */
#define DIO_API_WRITE_PORT 3U

#if (defined DIO_API_READ_CHANNEL_GROUP) /* to prevent double declaration */
#error DIO_API_READ_CHANNEL_GROUP already defined
#endif /* if (defined DIO_API_READ_CHANNEL_GROUP) */

/** \brief Definition of the service Id of the read channel group service */
#define DIO_API_READ_CHANNEL_GROUP 4U

#if (defined DIO_API_WRITE_CHANNEL_GROUP) /* to prevent double declaration */
#error DIO_API_WRITE_CHANNEL_GROUP already defined
#endif /* if (defined DIO_API_WRITE_CHANNEL_GROUP) */

/** \brief Definition of the service Id of the write channel group service */
#define DIO_API_WRITE_CHANNEL_GROUP 5U


#if (DIO_FLIP_CHANNEL_API == STD_ON) /* only makes sense if this API is activated */
#if (defined DIO_API_FLIP_CHANNEL) /* to prevent double declaration */
#error DIO_API_FLIP_CHANNEL already defined
#endif /* if (defined DIO_API_FLIP_CHANNEL) */
#endif

/** \brief Definition of the service Id of the flip channel service */
#define DIO_API_FLIP_CHANNEL 0x11U

#if (DIO_GET_VERSION_INFO_API == STD_ON) /* only makes sense if this API is activated */
#if (defined DIO_API_GET_VERSION_INFO) /* to prevent double declaration */
#error DIO_API_GET_VERSION_INFO already defined
#endif /* if (defined DIO_API_GET_VERSION_INFO) */
#endif

/** \brief Definition of the service Id of the get version info service */
#define DIO_API_GET_VERSION_INFO 0x12U


#if (DIO_MASKED_WRITE_PORT_API == STD_ON) /* only makes sense if this API is activated */
#if (defined DIO_API_MASKED_WRITE_PORT) /* to prevent double declaration */
#error DIO_API_MASKED_WRITE_PORT already defined
#endif /* if (defined DIO_API_MASKED_WRITE_PORT) */
#endif

/** \brief Definition of the service Id of the masked write port service */
#define DIO_API_MASKED_WRITE_PORT 0x20U

/*------------------[AUTOSAR vendor identification]--------------------------*/

#if (defined DIO_VENDOR_ID) /* to prevent double declaration */
#error DIO_VENDOR_ID is already defined
#endif /* if (defined DIO_VENDOR_ID) */

/** \brief AUTOSAR vendor identification */
#define DIO_VENDOR_ID 66U

/*------------------[AUTOSAR module identification]--------------------------*/

#if (defined DIO_MODULE_ID) /* to prevent double declaration */
#error DIO_MODULE_ID already defined
#endif /* if (defined DIO_MODULE_ID) */

/** \brief AUTOSAR module identification */
#define DIO_MODULE_ID 120U

/*------------------[AUTOSAR instance identification]------------------------*/
#if (defined DIO_INSTANCE_ID) /* to prevent double declaration */
#error DIO_INSTANCE_ID already defined
#endif /* if (defined DIO_INSTANCE_ID) */

/** \brief AUTOSAR instance identification */
#define DIO_INSTANCE_ID 0U

/*==================[type definitions]=======================================*/

/*------------------[Definition of type Dio_ChannelType]-----------------*/
/** \brief  Type definition for the channel ID
 **
 ** This type stores the channel ID in a uint16.
 */
typedef uint16 Dio_ChannelType;

/*------------------[Definition of type Dio_PortType]-----------------*/
/** \brief  Type definition for the port ID
 **
 ** This type stores the port ID in a uint8.
 */
typedef uint8 Dio_PortType;

/*------------------[Definition of type Dio_LevelType]-----------------*/
/** \brief  Type definition for the level of a channel
 **
 ** This type stores the level of a channel in a uint8.
 */
typedef uint8 Dio_LevelType;

/*------------------[Definition of type Dio_PortLevelType]-----------------*/
/** \brief  Type definition for the level of a port
 **
 ** This type stores the level of a port in a uint32.
 ** This type can be stored level of up to 32 channels.
 */
typedef uint8 Dio_PortLevelType;

/*------------------[Definition of type Dio_ChannelGroupType]-----------------*/
/** \brief  Type definition for channel groups
 **
 ** This type defines a struct describing a channel group.
 ** A channel group consists of serveral adjoining channels of a port.
 */
typedef struct
{
    Dio_PortType port;  /** The port index on which the channel is defined */
    uint8 offset;       /** Position of the channel group counted from the LSB */
    uint8 mask;         /** Bit mask of the channel group */
} Dio_ChannelGroupType;

/*------------------[Definition of type Dio_PortConfigType]-----------------*/
/** \brief  Type definition for the ports
 **
 ** This type defines a struct describing a port.
 */
typedef struct
{
    Dio_PortLevelType portMask;  /** Channel available in the port */
    uint8 HwPortNumber;          /** The number of the port on hardware */
} Dio_PortConfigType;

/*------------------[Definition of type Dio_ConfigType]-----------------*/
/** \brief  Type definition for the DIO driver
 **
 ** This type defines a struct describing the DIO driver.
 */
typedef struct
{
    Dio_PortType numberOfPorts;  /** Channel available in the port */
    P2CONST(Dio_PortConfigType, DIO_CONST, DIO_APPL_CONST) portConfigPtr;
    /* pointer to the port configuration array */
    Dio_IORegisterInfoType IOPortRegisterInfo;
    /* pointer to the register infomartion */
} Dio_ConfigType;

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* DIO_TYPES_H */
/*==================[end of file]============================================*/
