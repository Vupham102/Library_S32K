/**
 * @file Port.h
 * @brief PORT driver interface for S32K144.
 */

#ifndef PORT_H
#define PORT_H

#include "PORT_REGISTERS.h"
#include "NVIC_Registers.h"
#include <stdint.h>

/**
 * @brief Pin mode enumeration for PORT configuration.
 */
typedef enum {
    PORT_MODE_GPIO = 0x01,      /*!< GPIO mode */
    PORT_MODE_SPI = 0x02,       /*!< SPI mode */
    PORT_MODE_I2C = 0x03,       /*!< I2C mode */
    PORT_MODE_PWM = 0x04,       /*!< PWM mode */
    PORT_MODE_INTERRUPT = 0x05  /*!< GPIO with interrupt */
} Port_Mode_t;

/**
 * @brief Pull resistor configuration.
 */
typedef enum {
    PORT_PULL_NONE = 0,         /*!< No pull resistor */
    PORT_PULL_UP = 1,           /*!< Pull-up resistor */
    PORT_PULL_DOWN = 2          /*!< Pull-down resistor */
} Port_Pull_t;

/**
 * @brief PORT configuration structure.
 */
typedef struct {
    PORT_Type* base;            /*!< Pointer to PORT base (PORTA, PORTB, etc.) */
    uint8_t pin_number;         /*!< Pin number (0-31) */
    Port_Mode_t mode;           /*!< Pin function mode */
    Port_Pull_t pull;           /*!< Pull resistor configuration */
    uint8_t drive_strength;     /*!< Drive strength (0: low, 1: high) */
} Port_Config_t;

/**
 * @brief Configures a pin's function and characteristics.
 * @param config Pointer to the PORT configuration structure.
 */
void Port_SetPinConfig(const Port_Config_t* config);

/**
 * @brief Enables interrupt for a specific pin.
 * @param base PORT base (PORTA, PORTB, etc.).
 * @param pin_number Pin number (0-31).
 */
void Port_EnableInterrupt(PORT_Type* base, uint8_t pin_number);

#endif /* PORT_H */