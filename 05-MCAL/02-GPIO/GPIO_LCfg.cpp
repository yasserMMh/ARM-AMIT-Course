
#include "GPIO_LCfg.h"

GPIO_PinState GPIO_udtArrayOfPins[GPIO_NUM_USED_PINS] = 
{
    [0] = {
        .u8PortId       = GPIO_PORTA,
        .u8PinId        = GPIO_PIN0,
        .udtMode        = GPIO_OUTPUT,
        .udtOType       = GPIO_PUSH_PULL,
        .udtOSpeed      = GPIO_LOW_SPEED,
        .udtInputState  = NOT_USED,
    },
    [1] = {
        .u8PortId       = GPIO_PORTA,
        .u8PinId        = GPIO_PIN5,
        .udtMode        = GPIO_OUTPUT,
        .udtOType       = GPIO_PUSH_PULL,
        .udtOSpeed      = GPIO_LOW_SPEED,
        .udtInputState  = NOT_USED,
    },
    [2] = {
        .u8PortId       = GPIO_PORTA,
        .u8PinId        = GPIO_PIN7,
        .udtMode        = GPIO_OUTPUT,
        .udtOType       = GPIO_PUSH_PULL,
        .udtOSpeed      = GPIO_LOW_SPEED,
        .udtInputState  = NOT_USED,
    },
}