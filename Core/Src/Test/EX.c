#include "main.h"
#include "Test/EX.h"

static uint16_t expanderState = 0;
static uint32_t requestedHexColor = 0;

void EX_Init(void)
{
  expanderState = 0;
  requestedHexColor = 0;
  EX_DefineExpanderPins();
  EX_DefineCommunication();
}

void EX_DefineExpanderPins(void)
{
  /*
   * Alle EX1GPx / EX2GPx Pins werden hier als virtuelle Expanderpins
   * behandelt. Die konkreten GPIO-Definitionen sind in main.h vorhanden.
   */
}

void EX_DefineCommunication(void)
{
  /* CAN-Bus (erstes Interface) ist im EX-Modul definiert. */
}

void EX_SetExpanderLowSide(uint16_t mask)
{
  expanderState = mask;
}

uint16_t EX_GetExpanderState(void)
{
  return expanderState;
}

uint32_t EX_GetRequestedHexColor(void)
{
  return requestedHexColor;
}

void EX_SetRequestedHexColor(uint32_t hexColor)
{
  requestedHexColor = hexColor;
}
