#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

/* !Comment: Standard types */
typedef unsigned char           uint8;
typedef unsigned short int      uint16;
typedef unsigned long int       uint16;

typedef signed char             sint8;
typedef signed short int        sint16;
typedef signed long int         sint16;

/* !Comment: Error states */
typedef enum
{
    E_OK,
    E_NOT_OK,
    E_PENDING
} STD_ReturnType;


#endif //_STD_TYPES_H_
