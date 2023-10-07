#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

/* !Comment: Port Definitions */
#define GPIO_PORTA      1u
#define GPIO_PORTB      2u
#define GPIO_PORTC      3u

/* !Comment: PIN Definitions */
#define GPIO_PIN0       0u
#define GPIO_PIN1       1u
#define GPIO_PIN2       2u
#define GPIO_PIN3       3u
#define GPIO_PIN4       4u
#define GPIO_PIN5       5u
#define GPIO_PIN6       6u
#define GPIO_PIN7       7u
#define GPIO_PIN8       8u
#define GPIO_PIN9       9u
#define GPIO_PIN10      10u
#define GPIO_PIN11      11u
#define GPIO_PIN12      12u
#define GPIO_PIN13      13u
#define GPIO_PIN14      14u
#define GPIO_PIN15      15u

/* !Comment: PIN VALUE */
#define PIN_VALUE_LOW   0u
#define PIN_VALUE_HIGH  1u

Std_ReturnType GPIO_udtInit(GPIO_PinState udtArrayOfPins[], uint8 u8NumUsedPins);

Std_ReturnType GPIO_udtSetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 u8PinValue);
Std_ReturnType GPIO_udtGetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 *pu8PinValue);

Std_ReturnType GPIO_udtAtomicSetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 u8PinValue);

Std_ReturnType GPIO_udtLockPinConfig(uint8 u8PortId, uint8 u8PinId);
Std_ReturnType GPIO_udtUnlockPinConfig(uint8 u8PortId, uint8 u8PinId);

#endif
