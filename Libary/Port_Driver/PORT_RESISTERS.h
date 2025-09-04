/**
 * @file PORT_REGISTERS.h
 * @brief Defines the PORT module registers and base addresses for S32K144.
 */

#ifndef PORT_REGISTERS_H
#define PORT_REGISTERS_H

#include <stdint.h>

/**
 * @brief Structure for PORT module registers.
 */
typedef struct {
    volatile uint32_t PCR[32];  /*!< Pin Control Registers (PCR0-PCR31) */
    volatile uint32_t GPCLR;    /*!< Global Pin Control Low Register */
    volatile uint32_t GPCHR;    /*!< Global Pin Control High Register */
    volatile uint32_t ISFR;     /*!< Interrupt Status Flag Register */
    volatile uint32_t DFER;     /*!< Digital Filter Enable Register */
    volatile uint32_t DFCR;     /*!< Digital Filter Control Register */
    volatile uint32_t DFWR;     /*!< Digital Filter Width Register */
} PORT_Type;

/* Base addresses for PORT modules */
#define PORTA_BASE  (0x40049000u)
#define PORTB_BASE  (0x4004A000u)
#define PORTC_BASE  (0x4004B000u)
#define PORTD_BASE  (0x4004C000u)
#define PORTE_BASE  (0x4004D000u)

/* Pointers to PORT modules */
#define PORTA  ((PORT_Type*)PORTA_BASE)
#define PORTB  ((PORT_Type*)PORTB_BASE)
#define PORTC  ((PORT_Type*)PORTC_BASE)
#define PORTD  ((PORT_Type*)PORTD_BASE)
#define PORTE  ((PORT_Type*)PORTE_BASE)

/* PCR bit fields */
/* PCR bit fields */
#define PORT_PCR_PS(x)       ((uint32_t)(((x) & 0x01) << 0))   /*!< Pull Select: 0=Down, 1=Up */
#define PORT_PCR_PE(x)       ((uint32_t)(((x) & 0x01) << 1))   /*!< Pull Enable */
#define PORT_PCR_PFE(x)      ((uint32_t)(((x) & 0x01) << 4))   /*!< Passive Filter Enable */
#define PORT_PCR_DSE(x)      ((uint32_t)(((x) & 0x01) << 6))   /*!< Drive Strength Enable */
#define PORT_PCR_MUX(x)      ((uint32_t)(((x) & 0x07) << 8))   /*!< Pin Mux Control */
#define PORT_PCR_LK(x)       ((uint32_t)(((x) & 0x01) << 15))  /*!< Lock Register */
#define PORT_PCR_IRQC(x)     ((uint32_t)(((x) & 0x0F) << 16))  /*!< Interrupt Configuration */
#define PORT_PCR_ISF(x)      ((uint32_t)(((x) & 0x01) << 24))  /*!< Interrupt Status Flag */


#endif /* PORT_REGISTERS_H */