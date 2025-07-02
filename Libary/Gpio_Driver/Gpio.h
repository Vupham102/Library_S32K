/**
*   @file    Gpio.h
*   @brief   declare Declearation of function prototype and parameter use in GPIO module
*   @details typedef struct Gpio_ConfigType, create a struct to initial the pin
*/

/*==================================================================================================
==================================================================================================*/
#ifndef GPIO_H
#define GPIO_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Gpio_Registers.h"

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    GPIO_Type         *      base;                  /*!< Gpio base pointer.  */
    unsigned char            GPIO_PinNumber;        /*!< Pin number.*/
    unsigned char            GPIO_PinMode;          /*!< Pin_mode */
} Gpio_ConfigType;

/*!
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] ConfigPtr:  The configuration structure
 * @return 
 */

 /*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
void Gpio_Init(const Gpio_ConfigType* ConfigPtr);
void GPIO_WriteToOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber, unsigned char value);
void GPIO_SetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
void GPIO_ResetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
void GPIO_ToggleOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
unsigned char GPIO_ReadFromInputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);

void GPIO_configpin(GPIO_Type *base, unsigned char pin_number, unsigned char pin_mode);

#endif
