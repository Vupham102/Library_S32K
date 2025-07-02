/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Gpio.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] pinCount The number of configured pins in structure
 * @param[in] config The configuration structure
 * @return 
 */
void Gpio_Init(const Gpio_ConfigType* ConfigPtr)
{
    /* Check parameter */
    if (ConfigPtr == 0 || ConfigPtr->base == 0 || ConfigPtr ->GPIO_PinNumber >= 32)
    {
        return;
    }

    switch (ConfigPtr -> GPIO_PinMode)
    {
    case 0:
        ConfigPtr ->base->PDDR &= ~(1u << ConfigPtr ->GPIO_PinNumber);
        break;
    case 1:
        ConfigPtr ->base->PDDR |= (1u << ConfigPtr ->GPIO_PinNumber);
        break;
    default:
        return;
    }
    

}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Set logic status to output pin
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] pGPIOx The pointer point to base address of GPIO
 * @param[in] PinNumber the pin used (0-31)
 * @param[in] value logic level write to pin
 * @return 
 */
void GPIO_WriteToOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber, unsigned char value)
{
    /* Check parameter */
    if (value == 1)
    {
        pGPIOx ->PDOR |= (1u << PinNumber);
    }
    else if (value == 0)
    {
        pGPIOx ->PDOR &= ~(1u << PinNumber);
    }
    else return;    
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Set logic high to output pin
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] pGPIOx The pointer point to base address of GPIO
 * @param[in] PinNumber the pin used (0-31)
 * @return 
 */
void GPIO_SetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */
    pGPIOx ->PDOR |= (1u << PinNumber);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Set logic low to output pin
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] pGPIOx The pointer point to base address of GPIO
 * @param[in] PinNumber the pin used (0-31)
 * @return 
 */
void GPIO_ResetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */
    pGPIOx ->PDOR &= ~(1u << PinNumber);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Set output logic toggle
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] pGPIOx The pointer point to base address of GPIO
 * @param[in] PinNumber the pin used (0-31)
 * @return 
 */
void GPIO_ToggleOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */
    pGPIOx->PDOR ^= (1u << PinNumber);

}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Read logic status from input pin
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] pGPIOx The pointer point to base address of GPIO
 * @param[in] PinNumber the pin used (0-31)
 * @return 
 */
unsigned char GPIO_ReadFromInputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */
    return((pGPIOx->PIDR >> PinNumber) & 0x01);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief To Config and initial GPIO quickly
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] base The pointer point to base address of GPIO
 * @param[in] pin_number the pin used (0-31)
 * @param[in] pin_mode set pin output or input
 * @return 
 */
void GPIO_configpin(GPIO_Type *base, unsigned char pin_number, unsigned char pin_mode)
{
    Gpio_ConfigType config;
    config.base = base;
    config.GPIO_PinNumber = pin_number;
    config.GPIO_PinMode = pin_mode;
    Gpio_Init(&config);
}
