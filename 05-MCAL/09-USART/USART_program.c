#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DET.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void USART_vidInit(USART_PerState *pudtUSARTPerState) {

    USART_type *pudtUSARTPer = NULL;
    pudtUSARTPer = USART_vidGetUSARTPer(pudtUSARTPerState->u8PerId, pudtUSARTPer);

    /* USART enable */
    pudtUSARTPer->CR1.B.UE = SET;

    /* Oversampling mode */
    switch (pudtUSARTPerState->u8OverSampling) {
        case USART_OVERSAMPLING_8 : pudtUSARTPer->CR1.B.OVER8  = SET;   break;
        case USART_OVERSAMPLING_16: pudtUSARTPer->CR1.B.OVER16 = RESET; break;
        default: /*void DET_vidReportError(uint8 u8ModuleId, uint8 u8ErrorId, uint8 u8FunctionId);*/ break;
    }

    /* Set Baud Rate */
    USART_vidSetBaudRate(pudtUSARTPer, pudtUSARTPerState->u16BaudRate, pudtUSARTPer->CR1.B.OVER8);

    /* Word length */
    switch (pudtUSARTPerState->u8WordLength) {
        case USART_DATA_WORD_8: pudtUSARTPer->CR1.B.M = RESET; break; /* 0: 1 Start bit, 8 Data bits, n Stop bit */
        case USART_DATA_WORD_9: pudtUSARTPer->CR1.B.M = SET;   break; /* 1: 1 Start bit, 9 Data bits, n Stop bit */
        default: /*void DET_vidReportError(uint8 u8ModuleId, uint8 u8ErrorId, uint8 u8FunctionId);*/ break;
    }

    /* Wakeup method: Idle Line*/
    pudtUSARTPer->CR1.B.WAKE = SET;

    /* Parity control enable: enable */
    pudtUSARTPer->CR1.B.PCE  = SET;

    /* Parity selection: Even parity */
    pudtUSARTPer->CR1.B.PS   = RESET;

    /* PE interrupt: disable */
    pudtUSARTPer->CR1.B.PEIE = RESET;

    /* TXE interrupt: enable */
    pudtUSARTPer->CR1.B.TXEIE = SET;

    /* Transmission complete interrupt: enable */
    pudtUSARTPer->CR1.B.TCIE = SET;

    /* STOP bits: 1 */
    pudtUSARTPer->CR2.B.STOP = 0b00;

    /*Prescaler value: In normal IrDA mode: PSC must be set to 00000001*/
    pudtUSARTPer->GTPR.B.PSC = 0b00000001;


}

/* Synchronous mechanism */
/* TODO: Impelement asynchronous mechanism */
Std_ReturnType USART_udtSend(uint8 u8USARTPer, uint8 u8Data) {
    Std_ReturnType udtReturnType = E_NOT_OK;

    if(pu8ReceivedData == NULL) {
        return udtReturnType;
    }

    USART_type *pudtUSARTPer = NULL;
    pudtUSARTPer = USART_vidGetUSARTPer(pudtUSARTPerState->u8PerId, pudtUSARTPer);

    uint8  u8LocalFlag     = (uint8)0u;
    uint32 u32LocalCounter = (uint32)0u;

    pudtUSARTPer->DR = u8Data;
	
	while(pudtUSARTPer->SR.TXE == RESET)
	{
		u32LocalCounter++;
		
		if(u32LocalCounter == USART_USER_TIMEOUT)
		{
			u8LocalFlag = (uint8)1u;
			break;
		}
	}

    if(u8LocalFlag == (uint8)0u) {
        /* Transmitter is enabled */
        pudtUSARTPer->CR1.TE = SET;

        u8LocalFlag     = (uint8)0u;
        u32LocalCounter = (uint32)0u;

        while(pudtUSARTPer->SR.TC == RESET) {
            u32LocalCounter++;
		
            if(u32LocalCounter == USART_USER_TIMEOUT)
            {
                u8LocalFlag = (uint8)1u;
                break;
            }
        }
    }

    /* Transmitter is disabled */
    pudtUSARTPer->CR1.TE = RESET;

    udtReturnType = u8LocalFlag == (uint8)0u ? E_OK : E_NOT_OK;

    return udtReturnType;
}

/* Synchronous mechanism */
/* TODO: Impelement asynchronous mechanism */
Std_ReturnType USART_udtReceive(uint8 u8USARTPer, uint8* pu8ReceivedData) {
    Std_ReturnType udtReturnType = E_NOT_OK;

    if(pu8ReceivedData == NULL) {
        return udtReturnType;
    }

    USART_type *pudtUSARTPer = NULL;
    pudtUSARTPer = USART_vidGetUSARTPer(pudtUSARTPerState->u8PerId, pudtUSARTPer);

    uint8 u8LocalFlag      = (uint8)0u;
    uint32 u32LocalCounter = (uint32)0u;

    /* Receiver is enabled and begins searching for a start bit */
    pudtUSARTPer->CR1.RE = SET;
	
	while(pudtUSARTPer->SR.RXNE == RESET)
	{
		u32LocalCounter++;
		
		if(u32LocalCounter == USART_USER_TIMEOUT)
		{
			u8LocalFlag = (uint8)1u;
			break;
		}
	}
	
	if(u8LocalFlag == (uint8)0u)
	{
		*pu8ReceivedData = pudtUSARTPer->DR;
		
		udtReturnType = E_OK;
	}

    /* Receiver is disabled */
    pudtUSARTPer->CR1.RE = RESET;

    return udtReturnType;
}

/* !Comment: Impelement Private Functions */

static void USART_vidGetUSARTPer(uint8 u8PerId, USART_type *pudtUSARTPer) {
    switch (u8PerId) {
        case USART_PERIPHERAL_1: pudtUSARTPer = USART1; break;
        case USART_PERIPHERAL_2: pudtUSARTPer = USART2; break;
        case USART_PERIPHERAL_6: pudtUSARTPer = USART6; break;
        default: /*void DET_vidReportError(uint8 u8ModuleId, uint8 u8ErrorId, uint8 u8FunctionId);*/ break;
    }
}

static void USART_vidSetBaudRate(USART_type *pudtUSARTPer, uint16 u16BaudRate, uint8 u8Over8) {
    float USARTDIV = (FREQ_CLK * 1000 * 1000) / (8.0 * (2 - u8Over8) * u16BaudRate);
    float fraction = USARTDIV - (uint16)USARTDIV;

    float DIV_Fraction = 8.0 * (2 - u8Over8) * fraction;
    uint8 DIV_Fraction_Int = (uint8) (DIV_Fraction + 0.5);

    uint8 is_overflow = DIV_Fraction_Int > ( (8 * (2 - u8Over8)) - 1);

    pudtUSARTPer->CR1.B.DIV_fraction = is_overflow ? 0b0 : DIV_Fraction_Int;
    pudtUSARTPer->CR1.B.DIV_Mantissa = is_overflow ? (uint16)USARTDIV + 1 : (uint16)USARTDIV;
}
