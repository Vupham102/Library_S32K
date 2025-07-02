#include "Pcc.h"

void PCC_ENA(const PCC_Config* configptr)
{
    switch (configptr->index)
    {
    case 0:
        PCC->PCC_PORTA |= (1u<<30u);
        break;
    case 1:
        PCC->PCC_PORTB |= (1u<<30u);
        break;
    case 2:
        PCC->PCC_PORTC |= (1u<<30u);
        break;
    case 3:
        PCC->PCC_PORTD |= (1u<<30u);
        break;
    case 4:
        PCC->PCC_PORTE |= (1u<<30u);
        break;
    default:
        return;
    }
}

void PCC_DIS(const PCC_Config* configptr)
{
    switch (configptr->index)
    {
    case 0:
        PCC->PCC_PORTA &= ~(1u<<30u);
        break;
    case 1:
        PCC->PCC_PORTB &= ~(1u<<30u);
        break;
    case 2:
        PCC->PCC_PORTC &= ~(1u<<30u);
        break;
    case 3:
        PCC->PCC_PORTD &= ~(1u<<30u);
        break;
    case 4:
        PCC->PCC_PORTE &= ~(1u<<30u);
        break;
    default:
        return;
    }   
}
