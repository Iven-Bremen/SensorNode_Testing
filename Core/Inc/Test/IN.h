#ifndef __IN_H
#define __IN_H

#include "main.h"

void IN_Init(void);
void IN_DefineGpioPins(void);
void IN_DefineAdcChannels(void);
void IN_DefinePwmChannels(void);
void IN_DefineSerialInterfaces(void);

uint32_t IN_ReadAdcValue(void);
GPIO_PinState IN_ReadButton(void);

#endif /* __IN_H */
