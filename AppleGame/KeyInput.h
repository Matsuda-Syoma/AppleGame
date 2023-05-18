#pragma once
#include "variable.h"

gOldKey = gNowKey;
gNowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
gKeyFlg = gNowKey & ~gOldKey;