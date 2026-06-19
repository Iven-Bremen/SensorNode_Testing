#include "main.h"
#include "Test/TMain.h"

static bool tmainInitialized = false;
static uint32_t lastUpdateMs = 0;

void TMain_Init(void)
{
  IN_Init();
  EX_Init();
  ST_Init();
  UI_Init();
  tmainInitialized = true;
}

void TMain(void)
{
  if (!tmainInitialized)
  {
    TMain_Init();
  }

  uint32_t now = HAL_GetTick();
  if (now - lastUpdateMs < 20U)
  {
    return;
  }
  lastUpdateMs = now;

  UI_Update();

  static bool defined = false;
  if (!defined)
  {
    EX_DefineCommunication();
    ST_DefineCanBus();
    IN_DefineSerialInterfaces();
    defined = true;
  }
}
