#include "main.h"
#include "Test/ST.h"

void ST_Init(void)
{
  ST_DefineConnectorPins();
  ST_DefinePeripheralPins();
}

void ST_DefineConnectorPins(void)
{
  /* Steckerpins und Statusfunktionen werden hier beschrieben. */
}

void ST_DefineCanBus(void)
{
  /* CAN2 oder weiteres Interface ist im ST-Modul definiert. */
}

void ST_DefinePeripheralPins(void)
{
  /* PWM, ADC, GPIO und weitere Stecker-Funktionen stehen bereit. */
}

void ST_ConfigureControlGPIOs(void)
{
  /* Zusätzliche Steuerpins können hier aktiviert werden. */
}
