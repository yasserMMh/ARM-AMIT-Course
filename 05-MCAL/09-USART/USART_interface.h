#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_

void USART_vidInit(uint8 u8USARTPer);
Std_ReturnType USART_udtSend(uint8 u8USARTPer, uint8 u8Data);
Std_ReturnType USART_udtReceive(uint8 u8USARTPer, uint8* pu8ReceivedData);

/*  */
#define FREQ_CLK_MHZ        (uint8)16u

/* USART Peripherals */
#define USART_PERIPHERAL_1  (uint8)1u
#define USART_PERIPHERAL_2  (uint8)2u
#define USART_PERIPHERAL_6  (uint8)6u

/* USART OVERSAMPLING */
#define USART_OVERSAMPLING_8   (uint8)8u
#define USART_OVERSAMPLING_16  (uint8)16u

/* USART BAUD RATE */
#define USART_BAUD_RATE_1200    (uint16)1200u
#define USART_BAUD_RATE_2400    (uint16)2400u
#define USART_BAUD_RATE_9600    (uint16)9600u
#define USART_BAUD_RATE_19200   (uint16)19200u
#define USART_BAUD_RATE_38400   (uint16)38400u

/* USART DATA WORD */
#define USART_DATA_WORD_8   (uint8)8u
#define USART_DATA_WORD_9   (uint8)9u

/* USART STOP BITS */
#define USART_NUM_STOP_BITS_1   (uint8)1u
#define USART_NUM_STOP_BITS_1   (uint8)2u

typedef enum {

} USART_PARITY_CONTROL_E;

typedef enum {
    USART_CTS_CHANGE,
    USART_LIN_BREAK,
    USART_TRANSMIT_DATA_REGISTER_EMPTY,
    USART_TRANSMISSION_COMPLETE,
    USART_RECEIVE_DATA_REGISTER_FULL,
    USART_IDLE_LINE_RECEIVED,
    USART_OVERRUN_ERROR,
    USART_NOISE_ERROR,
    USART_FRAME_ERROR,
    USART_PARITY_ERROR,

} USART_INTERRUPT_FLAG_E;



// typedef enum {
//     USART_PERIPHERAL_1 = 1,
//     USART_PERIPHERAL_2 = 2,
//     USART_PERIPHERAL_6 = 6,

// } USART_PERIPHERAL_ID_E;

// typedef enum {
//     USART_OVERSAMPLING_8  = 8,
//     USART_OVERSAMPLING_16 = 16,

// } USART_OVERSAMPLING_E;

// typedef enum {
//     USART_BAUD_RATE_1200  = 1200,
//     USART_BAUD_RATE_2400  = 2400,
//     USART_BAUD_RATE_9600  = 9600,
//     USART_BAUD_RATE_19200 = 19200,
//     USART_BAUD_RATE_38400 = 38400,
    
// } USART_BAUD_RATE_E;

// typedef enum {
//     USART_DATA_WORD_8 = 8,
//     USART_DATA_WORD_9 = 9,
    
// } USART_DATA_WORD_E;

// typedef enum {
//     USART_NUM_STOP_BITS_1,
//     USART_NUM_STOP_BITS_2,
    
// } USART_NUM_STOP_BITS_E;

/* !Comment: USART Config */
typedef struct
{
    uint8   u8PerId;
    uint8   u8BaudRate;
    uint8   u8OverSampling;
    uint8   u8WordLength;
    uint16  u16BaudRate;
} USART_PerState;


#end // _USART_INTERFACE_H_
