/***************************************************************************//**
* \file cy_scb_common.c
* \version 1.0
*
* Provides common API implementation of the SCB driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_scb_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Function Name: Cy_SCB_ReadArrayNoCheck
****************************************************************************//**
*
* Reads an array of data out of the SCB receive FIFO without checking if the
* receive FIFO has enough data elements.
* Before calling this function, make sure that the receive FIFO has enough data
* elements to be read.
*
* \param base
* The pointer to the SCB instance.
*
* \param rxBuf
* The pointer to location to place data read from the receive FIFO.
* The size of the data element defined by the configured data width.
*
* \param size
* The number of data elements read from the receive FIFO.
*
*******************************************************************************/
void Cy_SCB_ReadArrayNoCheck(volatile stc_SCB_t const *base, void *rxBuf, uint32_t size)
{
    uint32_t idx;

    if (Cy_SCB_IsRxDataWidthByte(base))
    {
        uint8_t *buf = (uint8_t *) rxBuf;

        /* Get data available in RX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            buf[idx] = (uint8_t) Cy_SCB_ReadRxFifo(base);
        }
    }
    else
    {
        uint16_t *buf = (uint16_t *) rxBuf;

        /* Get data available in RX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            buf[idx] = (uint16_t) Cy_SCB_ReadRxFifo(base);
        }
    }
}


/*******************************************************************************
* Function Name: Cy_SCB_ReadArray
****************************************************************************//**
*
* Reads an array of data out of the SCB receive FIFO.
* This function does not block, it returns how many data elements were
* read from the receive FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param rxBuf
* The pointer to location to place data read from receive FIFO.
* The item size is defined by the data type which depends on the configured
* data width.
*
* \param size
* The number of data elements to read from the receive FIFO.
*
* \return
* The number of data elements read from the receive FIFO.
*
*******************************************************************************/
uint32_t Cy_SCB_ReadArray(volatile stc_SCB_t const *base, void *rxBuf, uint32_t size)
{
    /* Get available items in RX FIFO */
    uint32_t numToCopy = Cy_SCB_GetNumInRxFifo(base);

    /* Adjust items which will be read */
    if (numToCopy > size)
    {
        numToCopy = size;
    }

    /* Get data available in RX FIFO */
    Cy_SCB_ReadArrayNoCheck(base, rxBuf, numToCopy);

    return (numToCopy);
}


/*******************************************************************************
* Function Name: Cy_SCB_ReadArrayBlocking
****************************************************************************//**
*
* Reads an array of data out of the SCB receive FIFO.
* This function blocks until the number of data elements specified by the
* size has been read from the receive FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param rxBuf
* The pointer to location to place data read from receive FIFO.
* The item size is defined by the data type which depends on the configured
* data width.
*
* \param size
* The number of data elements to read from receive FIFO.
*
*******************************************************************************/
void Cy_SCB_ReadArrayBlocking(volatile stc_SCB_t const *base, void *rxBuf, uint32_t size)
{
    uint32_t numCopied;
    uint8_t  *buf = (uint8_t *) rxBuf;

    /* Get data from RX FIFO. Stop when the requested size is read. */
    while (size > 0UL)
    {
        numCopied = Cy_SCB_ReadArray(base, (void *) buf, size);

        buf = &buf[(Cy_SCB_IsRxDataWidthByte(base) ? (numCopied) : (2UL * numCopied))];
        size -= numCopied;
    }
}


/*******************************************************************************
* Function Name: Cy_SCB_Write
****************************************************************************//**
*
* Places a single data element in the SCB transmit FIFO.
* This function does not block and returns how many data elements were placed
* in the transmit FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param data
* Data to put in the transmit FIFO.
* The item size is defined by the data type which depends on the configured
* data width.
*
* \return
* The number of data elements placed in the transmit FIFO: 0 or 1.
*
*******************************************************************************/
uint32_t Cy_SCB_Write(volatile stc_SCB_t *base, uint32_t data)
{
    uint32_t numCopied = 0UL;

    if (Cy_SCB_GetFifoSize(base) != Cy_SCB_GetNumInTxFifo(base))
    {
        Cy_SCB_WriteTxFifo(base, data);

        numCopied = 1UL;
    }

    return (numCopied);
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteArrayNoCheck
****************************************************************************//**
*
* Places an array of data in the SCB transmit FIFO without checking if the
* transmit FIFO has enough space.
* Before calling this function, make sure that the transmit FIFO has enough
* space to put all requested data elements.
*
* \param base
* The pointer to the SCB instance.
*
* \param txBuf
* The pointer to data to place in the transmit FIFO.
* The item size is defined by the data type which depends on the configured
* TX data width.
*
* \param size
* The number of data elements to transmit.
*
* \return
* The number of data elements placed in the transmit FIFO.
*
*******************************************************************************/
void Cy_SCB_WriteArrayNoCheck(volatile stc_SCB_t *base, void *txBuf, uint32_t size)
{
    uint32_t idx;

    if (Cy_SCB_IsTxDataWidthByte(base))
    {
        uint8_t *buf = (uint8_t *) txBuf;

        /* Put data into TX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            Cy_SCB_WriteTxFifo(base, (uint32_t) buf[idx]);
        }
    }
    else
    {
        uint16_t *buf = (uint16_t *) txBuf;

        /* Put data into TX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            Cy_SCB_WriteTxFifo(base, (uint32_t) buf[idx]);
        }
    }
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteArray
****************************************************************************//**
*
* Places an array of data in the SCB transmit FIFO.
* This function does not block and it returns how many data elements were
* placed in the transmit FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param txBuf
* The pointer to data to place in the transmit FIFO.
* The item size is defined by the data type which depends on the configured
* TX data width.
*
* \param size
* The number of data elements to transmit.
*
* \return
* The number of data elements placed in the transmit FIFO.
*
*******************************************************************************/
uint32_t Cy_SCB_WriteArray(volatile stc_SCB_t *base, void *txBuf, uint32_t size)
{
    /* Get free entries in TX FIFO */
    uint32_t numToCopy = Cy_SCB_GetFifoSize(base) - Cy_SCB_GetNumInTxFifo(base);

    /* Adjust the data elements to write */
    if (numToCopy > size)
    {
        numToCopy = size;
    }

    Cy_SCB_WriteArrayNoCheck(base, txBuf, numToCopy);

    return (numToCopy);
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteArrayBlocking
****************************************************************************//**
*
* Places an array of data in the transmit FIFO.
* This function blocks until the number of data elements specified by the size
* is placed in the transmit FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param txBuf
* The pointer to data to place in transmit FIFO.
* The item size is defined by the data type which depends on the configured
* data width.
*
* \param size
* The number of data elements to write into the transmit FIFO.
*
*******************************************************************************/
void Cy_SCB_WriteArrayBlocking(volatile stc_SCB_t *base, void *txBuf, uint32_t size)
{
    uint32_t numCopied;
    uint8_t  *buf = (uint8_t *) txBuf;

    /* Get data from RX FIFO. Stop when the requested size is read. */
    while (size > 0UL)
    {
        numCopied = Cy_SCB_WriteArray(base, (void *) buf, size);

        buf = &buf[(Cy_SCB_IsTxDataWidthByte(base) ? (numCopied) : (2UL * numCopied))];
        size -= numCopied;
    }
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteString
****************************************************************************//**
*
* Places a NULL terminated string in the transmit FIFO.
* This function blocks until the entire string is placed in the transmit FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param string
* The pointer to the null terminated string array.
*
*******************************************************************************/
void Cy_SCB_WriteString(volatile stc_SCB_t *base, char_t const string[])
{
    uint32_t idx = 0UL;
    uint32_t fifoSize = Cy_SCB_GetFifoSize(base);

    /* Put data from TX FIFO. Stop when string is terminated */
    while (((char_t) 0) != string[idx])
    {
        /* Wait for free space to be available */
        while (fifoSize == Cy_SCB_GetNumInTxFifo(base))
        {
        }

        Cy_SCB_WriteTxFifo(base, (uint32_t) string[idx]);
        ++idx;
    }
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteDefaultArrayNoCheck
****************************************************************************//**
*
* Places a number of the same data elements in the SCB transmit FIFO without
* checking if the transmit FIFO has enough space. The data elements is equal
* to txData parameter.
* Before calling this function make sure that transmit FIFO has enough space
* to put all requested data elements.
*
* \param base
* The pointer to the SCB instance.
*
* \param txData
* The data element to transmit repeatedly.
*
* \param size
* The number of data elements to transmit.
*
*******************************************************************************/
void Cy_SCB_WriteDefaultArrayNoCheck(volatile stc_SCB_t *base, uint32_t txData, uint32_t size)
{
    while (size > 0UL)
    {
        Cy_SCB_WriteTxFifo(base, txData);
        --size;
    }
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteDefaultArray
****************************************************************************//**
*
* Places a number of the same data elements in the SCB transmit FIFO.
* The data elements is equal to the txData parameter.
*
* \param base
* The pointer to the SCB instance.
*
* \param txData
* The data element to transmit repeatedly.
*
* \param size
* The number of data elements to transmit.
*
* \return
* The number of data elements placed in the transmit FIFO.
*
*******************************************************************************/
uint32_t Cy_SCB_WriteDefaultArray(volatile stc_SCB_t *base, uint32_t txData, uint32_t size)
{
    /* Get free entries in TX FIFO */
    uint32_t numToCopy = Cy_SCB_GetFifoSize(base) - Cy_SCB_GetNumInTxFifo(base);

    /* Adjust data elements to write */
    if (numToCopy > size)
    {
        numToCopy = size;
    }

    Cy_SCB_WriteDefaultArrayNoCheck(base, txData, numToCopy);

    return (numToCopy);
}

#if defined(__cplusplus)
}
#endif


/* [] END OF FILE */

