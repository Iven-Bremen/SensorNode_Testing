#ifndef __ST_H
#define __ST_H

#include "main.h"

void ST_Init(void);
void ST_DefineConnectorPins(void);
void ST_DefineCanBus(void);
void ST_DefinePeripheralPins(void);
void ST_ConfigureControlGPIOs(void);

#endif /* __ST_H */
