/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "NVIC.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Enable interrupt
 *
 *
 * @param[in] IRQ_number The number id of specific device to enable interrupt
 * @return 
 */
void NVIC_EnableInterrupt( IRQn_Type IRQ_number ){
	NVIC->ISER[(unsigned char)IRQ_number / 32] |= (1 << (unsigned char)IRQ_number % 32);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Disable interrupt
 *
 *
 * @param[in] IRQ_number The number id of specific device to disable interrupt
 * @return 
 */
void NVIC_DisableInterrupt( IRQn_Type IRQ_number ){
	NVIC->ICER[(unsigned char)IRQ_number / 32] |= (1 << (unsigned char)IRQ_number % 32);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Clear pending flag of IRQ
 *
 *
 * @param[in] IRQ_number The number id of specific device to clear pending flag
 * @return 
 */
void NVIC_ClearPendingFlag( IRQn_Type IRQ_number ){
	NVIC->ICPR[(unsigned char)IRQ_number / 32] |= (1 << (unsigned char)IRQ_number % 32);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Set level priority of interrupt
 *
 *
 * @param[in] IRQ_number The number id of specific device want to set priority
 * @param[in] priority The priority level want to set
 * @return 
 */
void NVIC_SetPriority( IRQn_Type IRQ_number,unsigned char priority){
	if(priority < 16u){
		NVIC->IPR[(unsigned char)IRQ_number] |= (priority << 4);
	}
	else{
	}
	
}