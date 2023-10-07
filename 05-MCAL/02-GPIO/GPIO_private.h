#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

/* !Comment: RCC registers. */
typedef struct
{
    uint32 MODER;
    uint32 OTYPER;
    uint32 OSPEEDR;
    uint32 PUPDR;
    uint32 IDR;
    uint32 ODR;
    uint32 BSRR;
    uint32 LCKR;
    uint32 AFRL;
    uint32 AFRH;
}GPIO_type;

/* !Comment: Defining GPIO pointer */
#define GPIOA ((volatile GPIO_type*) 0x40020000u)
#define GPIOB ((volatile GPIO_type*) 0x40020400u)
#define GPIOC ((volatile GPIO_type*) 0x40020800u)

#define GPIO_NUM_PORTS      3u
#define GPIO_NUM_PINS       16u
#define GPIO_NUM_MODE       4u
#define GPIO_NUM_OTYPE      2u
#define GPIO_NUM_OSPEED     4u
#define GPIO_NUM_IState     4u

#define NOT_USED            255u

typedef enum
{
    GPIO_INPUT,
    GPIO_OUTPUT.
    GPIO_ALTERNATE_FUNCTION,
    GPIO_ANALOG,
} GPIO_MODE_E;

typedef enum
{
    GPIO_PUSH_PULL,
    GPIO_OPEN_DRAIN,
} GPIO_OTYPE_E;

typedef enum
{
    GPIO_LOW_SPEED,
    GPIO_MEDIUM_SPEED,
    GPIO_HIGH_SPEED,
    GPIO_VERY_HIGH_SPEED,
} GPIO_OSPEED_E;

/* !Comment: GPIO port pull-up/pull-down register (GPIOx_PUPDR)*/
typedef enum
{
    GPIO_FLOATING,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN,
    GPIO_RESERVED,
} GPIO_INPUT_E;

/* !Comment: GPIO Pin Config */
typedef struct
{
    uint8 u8PortId;
    uint8 u8PinId;

    GPIO_MODE_E udtMode;
    GPIO_OTYPE_E udtType;
    GPIO_OSPEED_E udtSpeed;
    GPIO_INPUT_E udtInputState;
} GPIO_PinState;

void GPIO_vidGetGpioPort(uint8 u8PortId, GPIO_type *pudtGPIO);
void GPIO_vidSetMode(GPIO_type *pudtGPIO, uint8 u8PinId, GPIO_MODE_E udtMode);
void GPIO_vidSetOutputType(GPIO_type *pudtGPIO, uint8 u8PinId, GPIO_OTYPE_E udtType);
void GPIO_vidSetOutputSpeed(GPIO_type *pudtGPIO, uint8 u8PinId, GPIO_OSPEED_E udtSpeed);
void GPIO_vidSetInputState(GPIO_type *pudtGPIO, uint8 u8PinId, GPIO_INPUT_E udtInputState);

#endif
