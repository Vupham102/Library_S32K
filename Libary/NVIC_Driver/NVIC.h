/**
*   @file    NVIC.h
*   @brief   declare Declearation of function prototype and parameter use in NVIC module
*   @details function prototype and parameter in NVIC module
*/

/*==================================================================================================
==================================================================================================*/
#ifndef _NVIC_H_
#define _NVIC_H_

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "NVIC_Registers.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
void NVIC_EnableInterrupt( IRQn_Type IRQ_number );
void NVIC_DisableInterrupt( IRQn_Type IRQ_number );
void NVIC_ClearPendingFlag( IRQn_Type IRQ_number );
void NVIC_SetPriority( IRQn_Type IRQ_number,unsigned char priority);

#endif
