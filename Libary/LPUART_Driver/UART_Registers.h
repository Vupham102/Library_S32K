/**
*   @file    UART_Registers.h
*   @brief   Manage Register in UART module
*   @details Struct, typedef, address of each register UART, pointer
*/

/*==================================================================================================
==================================================================================================*/
#ifndef UART_REGISTER_H
#define UART_REGISTER_H
/*==================================================================================================
*                                      STRUCT AND TYPEDEF
==================================================================================================*/
/**
* @brief          struct name UART_Type
* @details        This structure is for UART Register and its offset
*
*/
typedef struct
{
    volatile const unsigned int VERID; /* offset 0x0h */
    volatile const unsigned int PARAM; /* offset 0x4h */
    volatile unsigned int GLOBA;       /* offset 0x8h */
    volatile unsigned int PINCFG;      /* offset 0xCh */
    volatile unsigned int BAUD;        /* offset 0x10h */
    volatile unsigned int STAT;        /* offset 0x14h */
    volatile unsigned int CTRL;        /* offset 0x18h */
    volatile unsigned int DATA;        /* offset 0x1Ch */
    volatile unsigned int MATCH;       /* offset 0x20h */
    volatile unsigned int MODIR;       /* offset 0x24h */
    volatile unsigned int FIFO;        /* offset 0x28h */
    volatile unsigned int WATER;       /* offset 0x2Ch */
}UART_Type;
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define LPUART0_BASE        (0x4006A000)
#define LPUART1_BASE        (0x4006B000)
#define LPUART2_BASE        (0x4006C000)

#define LPUART0        ((UART_Type*)LPUART0_BASE)
#define LPUART1        ((UART_Type*)LPUART1_BASE)
#define LPUART2        ((UART_Type*)LPUART2_BASE)

#endif