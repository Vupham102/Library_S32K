/**
*   @file    Gpio_Registers.h
*   @brief   Manage Register in GPIO module
*   @details Struct, typedef, address of each register GPIO, pointer
*/

/*==================================================================================================
==================================================================================================*/
#ifndef GPIO_REGISTER_H
#define GPIO_REGISTER_H

/*==================================================================================================
*                                      STRUCT AND TYPEDEF
==================================================================================================*/
/**
* @brief          struct name GPIO_Type
* @details        This structure is for GPIO Register and its offset
*
*/
/** cau truc tat ca cac thanh ghi trong module gpio*/
typedef struct {
    volatile unsigned int PDOR;
	volatile unsigned int PSOR;
	volatile unsigned int PCOR;
	volatile unsigned int PTOR;
	volatile const unsigned int PDIR;
	volatile unsigned int PDDR;
	volatile unsigned int PIDR;
} GPIO_Type;

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** dia chi co so cua tung GPIO */
#define GPIOA_BASE      (0X400FF000u)
#define GPIOB_BASE      (0X400FF040u)
#define GPIOC_BASE      (0X400FF080u)
#define GPIOD_BASE      (0X400FF0C0u)
#define GPIOE_BASE      (0X400FF100u)

/** con tro tro toi dia chi cua tung thanh ghi */
#define GPIOA ((GPIO_Type *)GPIOA_BASE)
#define GPIOB ((GPIO_Type *)GPIOB_BASE)
#define GPIOC ((GPIO_Type *)GPIOC_BASE)
#define GPIOD ((GPIO_Type *)GPIOD_BASE)
#define GPIOE ((GPIO_Type *)GPIOE_BASE)

#endif
