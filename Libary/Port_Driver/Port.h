#ifndef PORT_H
#define PORT_H
#include "PORT_RESISTERS.h"

typedef struct
{
    PORT_Type * base;
    unsigned char            PORT_PinNumber;        /*!< Pin number.*/
    unsigned char            PORT_mode; 

}Port_config;

void setting_port(const Port_config* Config, unsigned char pin_number, unsigned char port_mode);

#endif
