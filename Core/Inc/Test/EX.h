#ifndef __EX_H
#define __EX_H

#include "main.h"

void EX_Init(void);
void EX_DefineExpanderPins(void);
void EX_DefineCommunication(void);
void EX_SetExpanderLowSide(uint16_t mask);
uint16_t EX_GetExpanderState(void);
uint32_t EX_GetRequestedHexColor(void);
void EX_SetRequestedHexColor(uint32_t hexColor);

#endif /* __EX_H */
