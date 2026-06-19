#ifndef __UI_H
#define __UI_H

#include "main.h"

typedef struct
{
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t brightness;
  bool lowSideEnabled;
} UI_State_t;

void UI_Init(void);
void UI_Update(void);
void UI_SetRGB(uint8_t red, uint8_t green, uint8_t blue);
void UI_SetHexColor(uint32_t hexColor);
void UI_SetPaletteColor(uint8_t index);
void UI_SetBrightness(uint8_t brightness);
void UI_SetLowSideOutput(bool enabled);
void UI_SetRequestedHexColor(uint32_t hexColor);

#endif /* __UI_H */
