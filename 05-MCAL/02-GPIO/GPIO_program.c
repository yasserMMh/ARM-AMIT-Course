#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DET.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


Std_ReturnType GPIO_udtInit(GPIO_PinState udtArrayOfPins[], uint8 u8NumUsedPins);
{
    Std_ReturnType udtReturnType = E_NOT_OK;
    GPIO_type *pudtGPIO = NULL;

    uint8 u8PinsCounter = 0u;

    for(u8PinsCounter = 0; u8PinsCounter < GPIO_NUM_USED_PINS; u8PinsCounter++)
    {
        /* !Comment: Is Valid Input? */
        if( GPIO_udtArrayOfPins[u8PinsCounter].u8PortId      > GPIO_NUM_PORTS  || 
            GPIO_udtArrayOfPins[u8PinsCounter].u8PinId       > GPIO_NUM_PINS   ||
            GPIO_udtArrayOfPins[u8PinsCounter].udtMode       > GPIO_NUM_MODE   ||
           (GPIO_udtArrayOfPins[u8PinsCounter].udtType       > GPIO_NUM_OTYPE  && GPIO_udtArrayOfPins[u8PinsCounter].udtMode == GPIO_OUTPUT) ||
           (GPIO_udtArrayOfPins[u8PinsCounter].udtSpeed      > GPIO_NUM_OSPEED && GPIO_udtArrayOfPins[u8PinsCounter].udtMode == GPIO_OUTPUT) ||
           (GPIO_udtArrayOfPins[u8PinsCounter].udtInputState > GPIO_NUM_IState && GPIO_udtArrayOfPins[u8PinsCounter].udtMode == GPIO_INPUT))
        {
            udtReturnType = E_NOT_OK;
            return udtReturnType;
        }

        GPIO_vidGetGpioPort(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId, pudtGPIO);

        GPIO_vidSetMode(pudtGPIO, GPIO_udtArrayOfPins[u8PinsCounter].u8PinId, GPIO_udtArrayOfPins[u8PinsCounter].udtMode);

        if(GPIO_udtArrayOfPins[u8PinsCounter].udtMode == GPIO_OUTPUT)
        {
            GPIO_vidSetOutputType(pudtGPIO, GPIO_udtArrayOfPins[u8PinsCounter].u8PinId, GPIO_udtArrayOfPins[u8PinsCounter].udtType);
            GPIO_vidSetOutputSpeed(pudtGPIO, GPIO_udtArrayOfPins[u8PinsCounter].u8PinId, GPIO_udtArrayOfPins[u8PinsCounter].udtSpeed);
        }
        else if(GPIO_udtArrayOfPins[u8PinsCounter].udtMode == GPIO_INPUT)
        {
            GPIO_vidSetInputState(pudtGPIO, GPIO_udtArrayOfPins[u8PinsCounter].u8PinId, GPIO_udtArrayOfPins[u8PinsCounter].udtInputState);
        }
        else
        {
            /* !Comment: TODO, adding error state, adding AF and analog handling */
        }
    }

    udtReturnType = E_OK;

    return udtReturnType;
}

Std_ReturnType GPIO_udtSetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 u8PinValue)
{
    Std_ReturnType udtReturnType = E_NOT_OK;
    GPIO_type *pudtGPIO = NULL;

    /* !Comment: Is Valid Input? */
    if(u8PortId > GPIO_NUM_PORTS || u8PinId > GPIO_NUM_PINS)
    {
        return udtReturnType;
    }

    GPIO_vidGetGpioPort(u8PortId, pudtGPIO);

    switch (u8PinValue)
    {
        case PIN_VALUE_LOW:
        {
            CLR_BIT(pudtGPIO->ODR, u8PinId);
            break;
        }
        
        case PIN_VALUE_HIGH:
        {
            SET_BIT(pudtGPIO->ODR, u8PinId);
            break;
        }
        
        default:
        {
            return udtReturnType;
            break;
        }
    }

    udtReturnType = E_OK;

    return udtReturnType;
}

Std_ReturnType GPIO_udtGetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 *pu8PinValue)
{
    Std_ReturnType udtReturnType = E_NOT_OK;
    GPIO_type *pudtGPIO = NULL;

    /* !Comment: Is Valid Input? */
    if(u8PortId > GPIO_NUM_PORTS || u8PinId > GPIO_NUM_PINS || pu8PinValue == NULL)
    {
        udtReturnType = E_NOT_OK;
        return udtReturnType;
    }

    GPIO_vidGetGpioPort(u8PortId, pudtGPIO);

    *pu8PinValue = GET_BIT(pudtGPIO->IDR, u8PinId);

    udtReturnType = E_OK;

    return udtReturnType;
}

Std_ReturnType GPIO_udtAtomicSetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 u8PinValue)
{
    Std_ReturnType udtReturnType = E_NOT_OK;
    GPIO_type *pudtGPIO = NULL;

    /* !Comment: Is Valid Input? */
    if(u8PortId > GPIO_NUM_PORTS || u8PinId > GPIO_NUM_PINS)
    {
        return udtReturnType;
    }

    GPIO_vidGetGpioPort(u8PortId, pudtGPIO);

    switch (u8PinValue)
    {
        case PIN_VALUE_LOW:
        {
            /* !Comment: Reset IDR via BSRR */
            pudtGPIO->BSRR = (0b1) << (u8PinId + GPIO_NUM_PINS);
            break;
        }
        
        case PIN_VALUE_HIGH:
        {
            /* !Comment: Set IDR via BSRR */
            pudtGPIO->BSRR = (0b1) << (u8PinId);
            break;
        }
        
        default:
        {
            return udtReturnType;
            break;
        }
    }

    udtReturnType = E_OK;

    return udtReturnType;
}



/* !Comment: Impelement Private Functions */
static void GPIO_vidGetGpioPort(uint8 u8PortId, GPIO_type *pudtGPIO)
{
    switch (u8PortId)
    {
        case GPIO_PORTA:
        {
            pudtGPIO = GPIOA;
            break;
        }
        case GPIO_PORTB:
        {
            pudtGPIO = GPIOB;
            break;
        }
        case GPIO_PORTC:
        {
            pudtGPIO = GPIOC;
            break;
        }
    
        default:
        {
            pudtGPIO = NULL;
            break;
        }
    }
}

static void GPIO_vidSetMode(GPIO_type *pudtGPIO, uint8 u8PinId, GPIO_MODE_E udtMode)
{
    pudtGPIO->MODER &= ~((0b11) << (u8PinId * 2));
    pudtGPIO->MODER |= (udtMode << (u8PinId * 2));
}

static void GPIO_vidSetOutputType(GPIO_type *pudtGPIO, uint8 u8PinId, GPIO_OTYPE_E udtType)
{
    /* !Comment: Set Pin Output Type */
    switch (udtType)
    {
        case GPIO_PUSH_PULL:
            CLR_BIT(pudtGPIO->OTYPER, u8PinId);
            break;

        case GPIO_OPEN_DRAIN:
            SET_BIT(pudtGPIO->OTYPER, u8PinId);
            break;
    
        default:
            break;
    }
}

static void GPIO_vidSetOutputSpeed(GPIO_type *pudtGPIO, uint8 u8PinId, GPIO_OSPEED_E udtSpeed)
{
    /* !Comment: Set Pin Speed */
    pudtGPIO->OSPEEDR &=  ~((0b11) << (u8PinId * 2));
    pudtGPIO->OSPEEDR |= (udtSpeed << (u8PinId * 2));
}

static void GPIO_vidSetInputState(GPIO_type *pudtGPIO, uint8 u8PinId, GPIO_INPUT_E udtInputState)
{
    pudtGPIO->PUPDR &=       ~((0b11) << (u8PinId * 2));
    pudtGPIO->PUPDR |= (udtInputState << (u8PinId * 2)); 
}
