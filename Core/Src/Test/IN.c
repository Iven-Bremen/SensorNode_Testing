#include "main.h"
#include "Test/IN.h"

void IN_Init(void)
{
  IN_DefineGpioPins();
  IN_DefineAdcChannels();
  IN_DefinePwmChannels();
  IN_DefineSerialInterfaces();
}

void IN_DefineGpioPins(void)
{
  /* Alle allgemeinen GPIO-Eingänge und Schalter werden hier definiert. */
}

void IN_DefineAdcChannels(void)
{
  /* ADC-Kanäle für analoge Sensorwerte stehen bereit. */
}

void IN_DefinePwmChannels(void)
{
  /* PWM-Ausgänge werden vom System bereits initialisiert. */
}

void IN_DefineSerialInterfaces(void)
{
  /* UART, USART, I2C, SPI und weitere Busschnittstellen sind vorbereitet. */
}

uint32_t IN_ReadAdcValue(void)
{
  uint32_t value = 0;
  if (HAL_ADC_Start(&hadc1) == HAL_OK)
  {
    if (HAL_ADC_PollForConversion(&hadc1, 10U) == HAL_OK)
    {
      value = HAL_ADC_GetValue(&hadc1);
    }
    HAL_ADC_Stop(&hadc1);
  }
  return value;
}

GPIO_PinState IN_ReadButton(void)
{
  return HAL_GPIO_ReadPin(BTN_U_GPIO_Port, BTN_U_Pin);
}
