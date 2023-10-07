#ifndef _USART_PRIVATE_H_
#define _USART_PRIVATE_H_

typedef struct {

    union {
        uint32 R;

        struct {
            uint32 PE:1;
            uint32 FE:1;
            uint32 NF:1;
            uint32 ORE:1;
            uint32 IDLE:1;
            uint32 RXNE:1;
            uint32 TC:1;
            uint32 TXE:1;
            uint32 LBD:1;
            uint32 CTS:1;
            uint32 Reserved:22;
        }B;
    }SR;

    uint32 DR;

    union {
        uint32 R;

        struct {
            uint32 DIV_Fraction:4;
            uint32 DIV_Mantissa:12;
            uint32 Reserved:16;
        }B;
    }BRR;

    union {
        uint32 R;

        struct {
            uint32 SBK:1;
            uint32 RWU:1;
            uint32 RE:1;
            uint32 TE:1;
            uint32 IDLEIE:1;
            uint32 RXNEIE:1;
            uint32 TCIE:1;
            uint32 TXEIE:1;
            uint32 PEIE:1;
            uint32 PS:1;
            uint32 PCE:1;
            uint32 WAKE:1;
            uint32 M:1;
            uint32 UE:1;
            uint32 Reserved1:1;
            uint32 OVER8:1;
            uint32 Reserved2:16;
        }B;
    }CR1;

    union {
        uint32 R;

        struct {
            uint32 ADD:3;
            uint32 Reserved1:1;
            uint32 LBDL:1;
            uint32 LBDIE:1;
            uint32 Reserved2:1;
            uint32 LBCL:1;
            uint32 CPHA:1;
            uint32 CPOL:1;
            uint32 CLKEN:1;
            uint32 STOP:2;
            uint32 LINEN:1;
            uint32 Reserved3:17;
        }B;
    }CR2;

    union {
        uint32 R;

        struct {
            uint32 EIE:1;
            uint32 IREN:1;
            uint32 IRLP:1;
            uint32 HDSEL:1;
            uint32 NACK:1;
            uint32 SCEN:1;
            uint32 DMAR:1;
            uint32 DMAT:1;
            uint32 RTSE:1;
            uint32 CTSE:1;
            uint32 CTSIE:1;
            uint32 ONEBIT:1;
            uint32 Reserved:20;
        }B;
    }CR3;

    union {
        uint32 R;

        struct {
            uint32 PSC:8;
            uint32 GT:8;
            uint32 Reserved:16;
        }B;
    }GTPR;

}USART_type;

#define USART1 ((volatile USART_type *)0x40011000u)
#define USART2 ((volatile USART_type *)0x40004400u)
#define USART6 ((volatile USART_type *)0x40011400u)

#define SET    0b1;
#define RESET  0b0;



#end // _USART_PRIVATE_H_