#include "main.h"
#include "Test/UI.h"
#include "Test/EX.h"

#define UI_COLOR_PALETTE_SIZE 29
#define UI_COLOR_CHANGE_MS 75U

static UI_State_t uiState = {0};
static uint32_t uiPhaseStart = 0;
static uint32_t uiColorLastTick = 0;
static uint8_t uiColorIndex = 0;
static bool uiRequestedColorActive = false;
static uint32_t uiRequestedHexColor = 0;
static uint32_t uiLastButtonTick = 0;
static GPIO_PinState uiLastButtonState = GPIO_PIN_SET;
static bool uiLowSideDescending = false;
static uint8_t uiLowSideCount = 0;

static const uint32_t UI_ColorPalette[UI_COLOR_PALETTE_SIZE] = {
    0xFF0000, // 1 Reinrot
    0x00FF00, // 2 Reingrün
    0x0000FF, // 3 Reinblau
    0xFFFF00, // 4 Reingelb
    0x00FFFF, // 5 Cyan / Aqua
    0xFF00FF, // 6 Magenta / Pink
    0xFFFFFF, // 7 Kaltweiß
    0xFFA500, // 8 Klassisch Orange
    0x800080, // 9 Echtes Lila
    0x000040, // 10 Dunkelblau
    0x99FF00, // 11 Limettengrün
    0xFF1493, // 12 Hot Pink
    0x87CEEB, // 13 Himmelblau
    0x400000, // 14 Dunkelrot
    0x00FF7F, // 15 Frühlingsgrün
    0xFFBF00, // 16 Bernstein / Amber
    0x004000, // 17 Dunkelgrün
    0xE6E6FA, // 18 Lavendel
    0x404040, // 19 Gedimmtes Weiß
    0xDDA0DD, // 20 Pflaume
    0x808080, // 21 Mittelgrau
    0x8B0000, // 22 Dunkelkarmin
    0x00FA9A, // 23 Mittelmeergrün
    0xFFD700, // 24 Gold
    0x4682B4, // 25 Stahlblau
    0xFF4500, // 26 Orangerot
    0xADFF2F, // 27 Grünes Gelb
    0x6A5ACD, // 28 Schieferblau
    0xF5DEB3  // 29 Weizengelb
};

static const uint32_t UI_YellowCycleMs = 3000U;
static const uint32_t UI_YellowOnMs = 1000U;
static const uint32_t UI_RedCycleMs = 20000U;
static const uint32_t UI_RedOnMs = 10000U;

static uint16_t UI_ApplyBrightness(uint8_t value)
{
  return (uint16_t)(((uint32_t)value * uiState.brightness + 127U) / 255U * 257U);
}

static void UI_ApplyHexColor(uint32_t hexColor)
{
  uint8_t red = (uint8_t)((hexColor >> 16U) & 0xFFU);
  uint8_t green = (uint8_t)((hexColor >> 8U) & 0xFFU);
  uint8_t blue = (uint8_t)(hexColor & 0xFFU);
  UI_SetRGB(red, green, blue);
}

static void UI_UpdateLowSideOutputs(void)
{
  HAL_GPIO_WritePin(GPIOE, LS1_Pin, (uiLowSideCount >= 1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOE, LS2_Pin, (uiLowSideCount >= 2) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOE, LS3_Pin, (uiLowSideCount >= 3) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOE, LS4_Pin, (uiLowSideCount >= 4) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

static void UI_ProcessButton(void)
{
  uint32_t now = HAL_GetTick();
  GPIO_PinState currentState = HAL_GPIO_ReadPin(BTN_U_GPIO_Port, BTN_U_Pin);

  if ((now - uiLastButtonTick) >= 50U)
  {
    if ((uiLastButtonState == GPIO_PIN_SET) && (currentState == GPIO_PIN_RESET))
    {
      if (uiLowSideDescending)
      {
        if (uiLowSideCount > 0)
        {
          uiLowSideCount--;
        }
        if (uiLowSideCount == 0)
        {
          uiLowSideDescending = false;
        }
      }
      else
      {
        if (uiLowSideCount < 4)
        {
          uiLowSideCount++;
        }
        if (uiLowSideCount == 4)
        {
          uiLowSideDescending = true;
        }
      }
      UI_UpdateLowSideOutputs();
      uiLastButtonTick = now;
    }
    uiLastButtonState = currentState;
  }
}

static void UI_UpdateAuxLeds(void)
{
  uint32_t now = HAL_GetTick();
  uint32_t yellowPhase = now % UI_YellowCycleMs;
  uint32_t redPhase = now % UI_RedCycleMs;

  HAL_GPIO_WritePin(GPIOE, Gelb_Pin, (yellowPhase < UI_YellowOnMs) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOE, ROT_Pin, (redPhase < UI_RedOnMs) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

static void UI_UpdateColors(void)
{
  uint32_t requestedColor = uiRequestedColorActive ? uiRequestedHexColor : EX_GetRequestedHexColor();
  if (requestedColor != 0U)
  {
    UI_SetRGB((uint8_t)((requestedColor >> 16U) & 0xFFU),
              (uint8_t)((requestedColor >> 8U) & 0xFFU),
              (uint8_t)(requestedColor & 0xFFU));
    return;
  }

  uint32_t now = HAL_GetTick();
  if ((now - uiColorLastTick) >= UI_COLOR_CHANGE_MS)
  {
    uiColorIndex = (uiColorIndex + 1) % UI_COLOR_PALETTE_SIZE;
    uiColorLastTick = now;
  }

  uint32_t color = UI_ColorPalette[uiColorIndex];
  UI_SetRGB((uint8_t)((color >> 16U) & 0xFFU),
            (uint8_t)((color >> 8U) & 0xFFU),
            (uint8_t)(color & 0xFFU));
}

void UI_Init(void)
{
  uiState.brightness = 255;
  uiState.lowSideEnabled = false;
  uiPhaseStart = HAL_GetTick();
  uiColorLastTick = uiPhaseStart;
  uiLastButtonTick = uiPhaseStart;
  uiLastButtonState = HAL_GPIO_ReadPin(BTN_U_GPIO_Port, BTN_U_Pin);
  uiLowSideCount = 0;
  uiLowSideDescending = false;

  HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3); // Blue on TIM1_CH3N (PE12)
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);   // Red on TIM2_CH4 (PB11)
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);   // Green on TIM3_CH1 (PB4)

  UI_UpdateLowSideOutputs();
  UI_UpdateColors();
  UI_UpdateAuxLeds();
}

void UI_Update(void)
{
  UI_ProcessButton();
  UI_UpdateColors();
  UI_UpdateAuxLeds();
}

void UI_SetRGB(uint8_t red, uint8_t green, uint8_t blue)
{
  uiState.red = red;
  uiState.green = green;
  uiState.blue = blue;

  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, UI_ApplyBrightness(red));
  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, UI_ApplyBrightness(green));
  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, UI_ApplyBrightness(blue));
}

void UI_SetHexColor(uint32_t hexColor)
{
  UI_ApplyHexColor(hexColor);
}

void UI_SetPaletteColor(uint8_t index)
{
  if (index >= UI_COLOR_PALETTE_SIZE)
  {
    return;
  }

  uint32_t color = UI_ColorPalette[index];
  UI_SetRGB((uint8_t)((color >> 16U) & 0xFFU),
            (uint8_t)((color >> 8U) & 0xFFU),
            (uint8_t)(color & 0xFFU));
}

void UI_SetBrightness(uint8_t brightness)
{
  uiState.brightness = brightness;
  UI_SetRGB(uiState.red, uiState.green, uiState.blue);
}

void UI_SetLowSideOutput(bool enabled)
{
  uiState.lowSideEnabled = enabled;
  uint16_t pwmValue = enabled ? UI_ApplyBrightness(255U) : 0U;
  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, pwmValue);
  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, pwmValue);
  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, pwmValue);
}

void UI_SetRequestedHexColor(uint32_t hexColor)
{
  uiRequestedHexColor = hexColor;
  uiRequestedColorActive = (hexColor != 0U);
}
