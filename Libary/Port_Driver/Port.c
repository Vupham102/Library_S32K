/**
 * @file Port.c
 * @brief PORT driver implementation for S32K144.
 */

#include "Port.h"

/**
 * @brief Configures a pin's function and characteristics.
 * @param config Pointer to the PORT configuration structure.
 */
void Port_SetPinConfig(const Port_Config_t* config) {
    if (config == NULL || config->base == NULL || config->pin_number > 31) {
        return; // Invalid parameters
    }

    // Clear previous configuration
    config->base->PCR[config->pin_number] = 0;

    // Configure based on mode
    switch (config->mode) {
        case PORT_MODE_GPIO:
            config->base->PCR[config->pin_number] = PORT_PCR_MUX(0x01) |
                                                  (config->drive_strength ? PORT_PCR_DSE(1) : 0) |
                                                  (config->pull == PORT_PULL_UP ? PORT_PCR_PUE(1) | PORT_PCR_PUS(1) :
                                                   config->pull == PORT_PULL_DOWN ? PORT_PCR_PUE(1) : 0);
            break;
        case PORT_MODE_SPI:
            config->base->PCR[config->pin_number] = PORT_PCR_MUX(0x02);
            break;
        case PORT_MODE_I2C:
            config->base->PCR[config->pin_number] = PORT_PCR_MUX(0x03);
            break;
        case PORT_MODE_PWM:
            config->base->PCR[config->pin_number] = PORT_PCR_MUX(0x04);
            break;
        case PORT_MODE_INTERRUPT:
            config->base->PCR[config->pin_number] = PORT_PCR_MUX(0x01) |
                                                  PORT_PCR_PUE(1) | PORT_PCR_PUS(1) |
                                                  PORT_PCR_IRQC(0b1011); // Interrupt on both edges
            break;
        default:
            break;
    }
}

/**
 * @brief Enables interrupt for a specific pin.
 * @param base PORT base (PORTA, PORTB, etc.).
 * @param pin_number Pin number (0-31).
 */
void Port_EnableInterrupt(PORT_Type* base, uint8_t pin_number) {
    if (base == NULL || pin_number > 31) {
        return; // Invalid parameters
    }

    // Enable interrupt in NVIC based on PORT base
    if (base == PORTA) {
        NVIC->ISER[59 / 32] |= (1 << (59 % 32)); // PORTA_IRQn = 59
    } else if (base == PORTB) {
        NVIC->ISER[60 / 32] |= (1 << (60 % 32)); // PORTB_IRQn = 60
    } else if (base == PORTC) {
        NVIC->ISER[61 / 32] |= (1 << (61 % 32)); // PORTC_IRQn = 61
    } else if (base == PORTD) {
        NVIC->ISER[62 / 32] |= (1 << (62 % 32)); // PORTD_IRQn = 62
    } else if (base == PORTE) {
        NVIC->ISER[63 / 32] |= (1 << (63 % 32)); // PORTE_IRQn = 63
    }
}