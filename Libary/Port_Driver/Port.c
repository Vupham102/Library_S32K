#include "Port.h"
void setting_port(const PORT_Type* base, unsigned char pin_number, unsigned char port_mode)
{
    Port_config setting;
    setting.base = base;
    setting.PORT_PinNumber = pin_number;
    setting.PORT_mode = port_mode;
}
