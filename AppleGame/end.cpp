#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

extern mode gGameMode;

int gWaitTime = 0;

void DrawEnd(void)
{

	if (++gWaitTime > 300) gGameMode = CLOSE;
}